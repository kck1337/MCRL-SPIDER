// ROS2 Servo Driver
//
// Copyright (c) 2020 Pascal Voser
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: Pascal Voser

// Check for reference & help:
// https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/...
// ...sample_code/cpp_read_write_protocol_1_0/#cpp-protocol-10

#include <hexapod_control/servo_driver.hpp>
#include <hexapod_control/dynamixel.hpp>  // Contains Dynamixel register definitions
#include <vector>
#include <string>

//==============================================================================
//  Initialize Parameters
//==============================================================================

void ServoDriver::init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer)
{
  rclcpp::Logger logger = rclcpp::get_logger("Servo_Driver");

  // Init for testing, parameters cannot be accessed. Used standard values...
  if (param_pointer == NULL) {
    RCLCPP_WARN(logger, "Parameter pointer is Null. Ignore if testing");
    port_open = false;

    SERVO_NAMES = servo_names_test;
    servo_count = end(SERVO_NAMES) - begin(SERVO_NAMES);

    ID.resize(servo_count);
    TICKS.resize(servo_count);
    CENTER.resize(servo_count);
    SIGN.resize(servo_count);
    OFFSET.resize(servo_count);
    RAD_TO_SERVO_RESOLUTION.resize(servo_count);

    LIMIT_COXA = limit_coxa_test;
    LIMIT_FEMUR = limit_femur_test;
    LIMIT_TIBIA = limit_tibia_test;

    ID = id_test;
    TICKS = ticks_test;
    CENTER = center_test;
    SIGN = sign_test;
    OFFSET = offset_test;
    for (int i = 0; i < servo_count; i++) {
      RAD_TO_SERVO_RESOLUTION[i] = static_cast<float>(TICKS[i]) /
        (static_cast<float>(max_degree_test) / 180.0 * M_PI);
    }
  } else {
    // Open port
    if (portHandler->openPort()) {
      RCLCPP_INFO(logger, "Succeeded to open the port!");
      // Set port baudrate
      if (portHandler->setBaudRate(BAUDRATE)) {
        RCLCPP_INFO(logger, "Succeeded to change the baudrate!");
      } else {
        RCLCPP_WARN(logger, "Failed to change the baudrate!");
      }
      port_open = true;
    } else {
      RCLCPP_WARN(logger, "Failed to open the USB port! Ignore if using Rviz or Gazbebo");
    }
    servos_free_ = true;

    // Load the parameters from the YAML file
    SERVO_NAMES = param_pointer->get_parameter("SERVO_NAMES").as_string_array();
    servo_count = end(SERVO_NAMES) - begin(SERVO_NAMES);

    ID.resize(servo_count);
    TICKS.resize(servo_count);
    CENTER.resize(servo_count);
    SIGN.resize(servo_count);
    OFFSET.resize(servo_count);
    RAD_TO_SERVO_RESOLUTION.resize(servo_count);

    LIMIT_COXA = param_pointer->get_parameter("LIMIT_COXA").as_integer_array();
    LIMIT_FEMUR = param_pointer->get_parameter("LIMIT_FEMUR").as_integer_array();
    LIMIT_TIBIA = param_pointer->get_parameter("LIMIT_TIBIA").as_integer_array();


    std::vector<int64_t> temp;
    for (int i = 0; i < servo_count; i++) {
      param_pointer->declare_parameter(SERVO_NAMES[i]);
      temp = param_pointer->get_parameter(SERVO_NAMES[i]).as_integer_array();
      ID[i] = temp[1];
      TICKS[i] = temp[2];
      CENTER[i] = temp[3];
      SIGN[i] = temp[5];
      OFFSET[i] = temp[6];
      RAD_TO_SERVO_RESOLUTION[i] = static_cast<float>(TICKS[i]) /
        (static_cast<float>(temp[4]) / 180.0 * M_PI);
    }
  }
  // RCLCPP_DEBUG(logger, "RAD_TO_SERVO_RESOLUTION: %f", RAD_TO_SERVO_RESOLUTION[i]);
  // Fill vector containers with default value

  cur_pos_.resize(servo_count);
  goal_pos_.resize(servo_count);
  write_pos_.resize(servo_count);

  for (int i = 0; i < servo_count; i++) {
    cur_pos_[i] = CENTER[i];
    goal_pos_[i] = CENTER[i];
    write_pos_[i] = CENTER[i];
  }
}

//==============================================================================
//  Destructor: Close serial Port
//==============================================================================
ServoDriver::~ServoDriver(void)
{
  free_servos();
  portHandler->closePort();
}

//==============================================================================
// Convert angles to servo position
//==============================================================================
bool ServoDriver::convert_angles(const sensor_msgs::msg::JointState & joint_state, bool write)
{
  bool in_range = true;
  for (int i = 0; i < servo_count; i++) {
    int temp = CENTER[i] + round(
      SIGN[i] * (joint_state.position[i] - OFFSET[i]) * RAD_TO_SERVO_RESOLUTION[i]);

    // Check if the position is in range of the servo
    if (joint_state.name[i].find("COXA") != std::string::npos) {
      if (temp > LIMIT_COXA[0] && temp < LIMIT_COXA[1]) {
        if (write) {goal_pos_[i] = temp;}
      } else {
        RCLCPP_DEBUG(rclcpp::get_logger("Servo_Driver"), "COXA  Angle %i out of range", i / 3);
        in_range = false;
      }
    } else if (joint_state.name[i].find("FEMUR") != std::string::npos) {
      if (temp > LIMIT_FEMUR[0] && temp < LIMIT_FEMUR[1]) {
        if (write) {goal_pos_[i] = temp;}
      } else {
        RCLCPP_DEBUG(rclcpp::get_logger("Servo_Driver"), "FEMUR Angle %i out of range", i / 3);
        in_range = false;
      }
    } else if (joint_state.name[i].find("TIBIA") != std::string::npos) {
      if (temp > LIMIT_TIBIA[0] && temp < LIMIT_TIBIA[1]) {
        if (write) {goal_pos_[i] = temp;}
      } else {
        RCLCPP_DEBUG(rclcpp::get_logger("Servo_Driver"), "TIBIA Angle %i out of range", i / 3);
        in_range = false;
      }
    } else {
      RCLCPP_WARN(rclcpp::get_logger("Servo_Driver"), "Limit not found");
    }
    // RCLCPP_INFO(rclcpp::get_logger("Servo"), "Pos %i: %f", i, goal_pos_[i]);
  }
  return in_range;
}

//==============================================================================
// Turn torque off to all servos
//==============================================================================
void ServoDriver::free_servos(void)
{
  bool torque_off = true;
  // Turn off torque
  for (int i = 0; i < servo_count; i++) {
    if (packetHandler->write1ByteTxRx(
        portHandler, ID[i], TORQUE_ENABLE, TORQUE_OFF,
        &dynamixel_error) != COMM_SUCCESS && port_open)
    {
      RCLCPP_WARN(
        rclcpp::get_logger("Servo_Driver"), "TURN TORQUE OFF FAILED ON SERVO [ID:%02d]", ID[i]);
      torque_off = false;
    }
  }
  if (torque_off) {
    RCLCPP_INFO(rclcpp::get_logger("Servo_Driver"), "Hexapod servos torque is now OFF.");
    servos_free_ = true;
  }
}

//==============================================================================
// Read positions of Servos
//==============================================================================
void ServoDriver::get_servo_positions()
{
  uint16_t currentPos;
  RCLCPP_DEBUG(rclcpp::get_logger("Servo_Driver"), "get servo pos");
  // Initialize current position as cur since values would be 0 for all servos
  // (Possibly servos are off till now)
  for (int i = 0; i < servo_count; i++) {
    // Read present position
    if (packetHandler->read2ByteTxRx(
        portHandler, ID[i], PRESENT_POSITION_L, &currentPos,
        &dynamixel_error) == COMM_SUCCESS)
    {
      cur_pos_[i] = currentPos;
      RCLCPP_DEBUG(
        rclcpp::get_logger("Servo_Driver"), "[ID:%02d]  Present Pos:%02d", ID[i], cur_pos_[i]);
    } else {
      if (port_open) {
        RCLCPP_WARN(rclcpp::get_logger("Servo_Driver"), "Read error on [ID:%02d]", ID[i]);
      }
    }
  }
}

//==============================================================================
// Turn torque on and read current positions
//==============================================================================
void ServoDriver::turn_on_servos()
{
  bool torque_on = true;
  if (!servos_free_) {
    // Servos are on so return
    return;
  } else {
    get_servo_positions();
    rclcpp::sleep_for(std::chrono::milliseconds(100));

    // Turn torque on
    for (int i = 0; i < servo_count; i++) {
      if (packetHandler->write1ByteTxRx(
          portHandler, ID[i], TORQUE_ENABLE, TORQUE_ON,
          &dynamixel_error) != COMM_SUCCESS && port_open)
      {
        RCLCPP_WARN(
          rclcpp::get_logger("Servo_Driver"), "TURN TORQUE ON SERVO FAILED [ID:%02d]",
          ID[i]);
        torque_on = false;
        free_servos();  // Disable all servos again to be save
      }
    }
    if (torque_on) {
      RCLCPP_INFO(rclcpp::get_logger("Servo_Driver"), "Hexapod servos torque is now ON.");
      servos_free_ = false;
    }
  }
}

//==============================================================================
// set servo speed
//==============================================================================
void ServoDriver::set_servo_speed(double speed)
{
  int parameters[18];
  for (int i = 0; i < servo_count; i++) {
    parameters[i] = 532 * speed;  // 532 is the max speed value
  }
  set_servo_parameter(
    parameters,
    servo_count,
    GOAL_SPEED_L,
    LEN_GOAL_POSITION);
}

//==============================================================================
// set servo parameters
//==============================================================================
void ServoDriver::set_servo_parameter(
  int * parameter,
  int param_number,
  uint16_t register_nr,
  uint16_t register_length)
{
  if (param_number > servo_count) {
    RCLCPP_ERROR(rclcpp::get_logger("Servo_Driver"), "too many Parameters");
    return;
  }
  bool writeParamSuccess = true;

  dynamixel::GroupSyncWrite groupSyncWrite(portHandler, packetHandler, register_nr,
    register_length);

  // Prepare packet for broadcast
  for (int i = 0; i < param_number; i++) {
    // add all servos to groupSyncWrite
    uint8_t param[2];
    param[0] = DXL_LOBYTE(parameter[i]);
    param[1] = DXL_HIBYTE(parameter[i]);
    if (!groupSyncWrite.addParam(ID[i], param) && port_open) {
      RCLCPP_WARN(
        rclcpp::get_logger("Servo_Driver"),
        "Parameter write failed on [ID:%02d]", ID[i]);
      writeParamSuccess = false;
    }
  }
  // Broadcast packet over U2D2
  if (writeParamSuccess) {
    if (groupSyncWrite.txPacket() != COMM_SUCCESS && port_open) {
      RCLCPP_WARN(rclcpp::get_logger("Servo_Driver"), "Parameter write not successfull!!");
    }
  }
  groupSyncWrite.clearParam();
}

//==============================================================================
// Updates the positions of the servos and sends USB2AX broadcast packet
// Reach the position of each servo individually as fast as possible
// Will result in unintended behaviour for the feet with ground contact as some servos will reach
// their goal before others
//==============================================================================
void ServoDriver::transmit_servo_positions(const sensor_msgs::msg::JointState & joint_state)
{
  bool writeParamSuccess = true;

  dynamixel::GroupSyncWrite groupSyncWrite(portHandler, packetHandler, GOAL_POSITION_L,
    LEN_GOAL_POSITION);
  convert_angles(joint_state);  // Convert angles to servo resolution
  turn_on_servos();

  // Prepare packet for broadcast
  for (int i = 0; i < servo_count; i++) {
    write_pos_[i] = goal_pos_[i];
    // add all servos to groupSyncWrite
    uint8_t param_goal_position[2];
    param_goal_position[0] = DXL_LOBYTE(write_pos_[i]);
    param_goal_position[1] = DXL_HIBYTE(write_pos_[i]);
    if (!groupSyncWrite.addParam(ID[i], param_goal_position) && port_open) {
      RCLCPP_WARN(
        rclcpp::get_logger("Servo_Driver"),
        "Goal position param write failed on [ID:%02d]", ID[i]);
      writeParamSuccess = false;
    }
  }
  // Broadcast packet over U2D2
  if (writeParamSuccess) {
    if (groupSyncWrite.txPacket() != COMM_SUCCESS && port_open) {
      RCLCPP_WARN(rclcpp::get_logger("Servo_Driver"), "Position write not successfull!!");
    }
  } else {
    // Store write pose as current pose (goal) since we are now done
    for (int i = 0; i < servo_count; i++) {
      cur_pos_[i] = write_pos_[i];
    }
  }
  groupSyncWrite.clearParam();
}
