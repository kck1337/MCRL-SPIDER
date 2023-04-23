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

#ifndef HEXAPOD_CONTROL__SERVO_DRIVER_HPP_
#define HEXAPOD_CONTROL__SERVO_DRIVER_HPP_

#include <sensor_msgs/msg/joint_state.hpp>
#include <rclcpp/rclcpp.hpp>
#include <dynamixel_sdk/dynamixel_sdk.h>
#include <../params/test_params.hpp>
#include <vector>
#include <string>
#include <cmath>

#define BAUDRATE    1000000
#define DEVICENAME  "/dev/ttyUSB0"      // Default Linux USB port
#define PROTOCOL_VERSION   1.0          // Protocol 1 required for AX-12A
#define TORQUE_ON   1
#define TORQUE_OFF  0
#define LEN_GOAL_POSITION  2

class ServoDriver
{
public:
  // Functions
  bool convert_angles(const sensor_msgs::msg::JointState & joint_state, bool write = true);
  void init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer);
  ~ServoDriver(void);
  void turn_on_servos(void);
  void set_servo_speed(double speed);
  void set_servo_parameter(
    int * parameter, int param_number, uint16_t register_nr, uint16_t register_length);
  void transmit_servo_positions(const sensor_msgs::msg::JointState & joint_state);
  void get_servo_positions(void);
  void free_servos(void);

private:
  // Handlers
  dynamixel::PortHandler * portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);
  dynamixel::PacketHandler * packetHandler = dynamixel::PacketHandler::getPacketHandler(
    PROTOCOL_VERSION);  // Set the protocol version

  // Varaibles
  uint8_t dynamixel_error = 0;  // Dynamixel error
  bool port_open = false;
  bool servos_free_;
  int servo_count;

  std::vector<std::string> SERVO_NAMES;
  std::vector<int> ID;        // Servo IDs
  std::vector<int> TICKS;     // Total number of ticks, meaning resolution of dynamixel servo
  std::vector<int> CENTER;    // Center value of dynamixel servo
  std::vector<int> SIGN;      // Side of the servo
  std::vector<int> OFFSET;    // Offset of the servo
  std::vector<double> RAD_TO_SERVO_RESOLUTION;  // Radians to servo conversion

  std::vector<int> cur_pos_;     // Current position of servos
  std::vector<int> goal_pos_;    // Goal position of servos
  std::vector<int> write_pos_;   // Position of each servo for sync_write packet
  std::vector<int> write_speed_;

  std::vector<int64_t> LIMIT_COXA;
  std::vector<int64_t> LIMIT_FEMUR;
  std::vector<int64_t> LIMIT_TIBIA;
};

#endif  // HEXAPOD_CONTROL__SERVO_DRIVER_HPP_
