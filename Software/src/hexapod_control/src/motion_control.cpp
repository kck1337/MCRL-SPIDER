// ROS2 Hexapod Motion Control
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

#include <hexapod_control/motion_control.hpp>

//==============================================================================
//  Initialize Parameters
//==============================================================================

void MotionControl::init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer)
{
  hex_state = Idle;
  next_hex_state = Idle;

  // Init for testing, parameters cannot be accessed. Used standard values...
  if (param_pointer == NULL) {
    RCLCPP_WARN(
      rclcpp::get_logger("Motion Control"),
      "Parameter pointer is Null. Ignore if testing");

    inverse_kinematics.init(NULL);
    gait.init(NULL);
    servo_driver.init(NULL);

    SERVO_NAMES = servo_names_test;
    NUMBER_OF_LEGS = 6;
    servo_count = NUMBER_OF_LEGS * 3;

    neutral_foot_pos_x = neutral_foot_pos_x_test;
    neutral_foot_pos_y = neutral_foot_pos_y_test;
    walking_height = walking_height_test;

  } else {
    neutral_foot_pos_x = param_pointer->get_parameter("INIT_FOOT_POS_X").as_double_array();
    neutral_foot_pos_y = param_pointer->get_parameter("INIT_FOOT_POS_Y").as_double_array();
    walking_height = param_pointer->get_parameter("INIT_FOOT_POS_Z").as_double();

    servo_driver.init(param_pointer);
    inverse_kinematics.init(param_pointer);
    gait.init(param_pointer);

    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Init done");
    servo_driver.get_servo_positions();

    SERVO_NAMES = param_pointer->get_parameter("SERVO_NAMES").as_string_array();
    NUMBER_OF_LEGS = param_pointer->get_parameter("NUMBER_OF_LEGS").as_int();
    servo_count = end(SERVO_NAMES) - begin(SERVO_NAMES);
  }

  joint_state_.name.resize(servo_count);
  joint_state_.position.resize(servo_count);
  test_joint_state_.name.resize(servo_count);
  test_joint_state_.position.resize(servo_count);

  for (int i = 0; i < servo_count; i++) {
    joint_state_.name[i] = SERVO_NAMES[i];
    joint_state_.position[i] = 0.0;
    test_joint_state_.name[i] = SERVO_NAMES[i];
    test_joint_state_.position[i] = 0.0;
  }

  body.position.x = 0;
  body.position.y = 0;
  body.position.z = 0;

  servo_driver.set_servo_speed(0.2);  // reduce speed to prevent jerking motion
}

void MotionControl::set_servo(float angle0, float angle1, float angle2)
{
  joint_state_.position[0] = angle0;
  joint_state_.position[1] = angle1;
  joint_state_.position[2] = angle2;
  servo_driver.transmit_servo_positions(joint_state_);
}

void MotionControl::update_vel(geometry_msgs::msg::Twist cmd_vel)
{
  // if the sitdown commands arrives the velocity is set to 0.
  // So the Hexapod can enter a standing state
  if (stand_up_cmd) {
    cmd_vel_ = cmd_vel;
  } else {
    cmd_vel_.linear.x = 0;
    cmd_vel_.linear.y = 0;
    cmd_vel_.angular.z = 0;
  }
}

void MotionControl::iterate_step(geometry_msgs::msg::Twist cmd_vel)
{
  gait.gait_cycle(cmd_vel, &feet);
  inverse_kinematics.calculate_ik(feet, body, &legs);
  int i = 0;
  for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
    joint_state_.position[i] = legs.leg[leg_index].coxa;
    i++;
    joint_state_.position[i] = legs.leg[leg_index].femur;
    i++;
    joint_state_.position[i] = legs.leg[leg_index].tibia;
    i++;
  }
  servo_driver.transmit_servo_positions(joint_state_);
}

void MotionControl::get_joint_state(sensor_msgs::msg::JointState & joint_state)
{
  joint_state = joint_state_;
}

void MotionControl::stand_up(void)
{
  if (start_cmd) {
    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Stand up");
    stand_up_cmd = true;
  }
}

void MotionControl::sit_down(void)
{
  if (start_cmd) {
    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Sit down");
    stand_up_cmd = false;
  }
}

void MotionControl::start_stop(void)
{
  if (stand_up_cmd) {return;}
  if (start_cmd) {
    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Stop");
    start_cmd = false;
  } else {
    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Start");
    start_cmd = true;
  }
}

void MotionControl::stand_walk(void)
{
  if (!stand_up_cmd) {return;}
  if (walking_cmd) {
    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Stand");
    walking_cmd = false;
  } else {
    RCLCPP_INFO(rclcpp::get_logger("Motion Control"), "Walk");
    walking_cmd = true;
  }
}

// Loop in which the motions are coordinated
void MotionControl::motion_loop(void)
{
  switch (hex_state) {
    case Unknown:   // check in which state the robot is and go to idle
      servo_driver.free_servos();
      break;

    case Idle:
      if (start_cmd) {
        next_hex_state = Sitting;
        servo_driver.turn_on_servos();
      }
      break;

    case Sitting:
      current_height = sitting_height;
      servo_driver.set_servo_speed(0.2);  // reduce speed to prevent jerking motion
      for (int c = 0; c < NUMBER_OF_LEGS; c++) {
        feet.foot[c].position.x = neutral_foot_pos_x[c];
        feet.foot[c].position.y = neutral_foot_pos_y[c];
        feet.foot[c].position.z = current_height;
      }

      if (stand_up_cmd) {
        servo_driver.set_servo_speed(0);  // max speed
        next_hex_state = Standing_up;
      } else if (!start_cmd) {
        next_hex_state = Idle;
        servo_driver.free_servos();
      }
      break;

    case Standing_up:
      current_height -= sit_step_height;
      if (current_height <= -walking_height) {
        next_hex_state = Walking;
        current_height = -walking_height;
      }

      for (int c = 0; c < NUMBER_OF_LEGS; c++) {
        // feet.foot[c].position.x = neutral_foot_pos_x[c];
        // feet.foot[c].position.y = neutral_foot_pos_y[c];
        feet.foot[c].position.z = current_height;
      }
      break;

    case Standing:
      body.orientation.pitch = 0.4 * cmd_vel_.linear.x;
      body.orientation.roll = 0.5 * cmd_vel_.linear.y;
      body.orientation.yaw = 0.5 * cmd_vel_.angular.z;

      if (!stand_up_cmd) {
        if (gait.is_standing()) {
          next_hex_state = Sitting_down;
        }
      }

      if (walking_cmd) {
        next_hex_state = Walking;
      }
      break;

    case Walking:
      gait.gait_cycle(cmd_vel_, &feet);
      /*
      std::cerr << "[          ]      feet(x,y,z) G1: (" <<
        feet.foot[0].position.x << ", " <<
        feet.foot[0].position.y << ", " <<
        feet.foot[0].position.z << ")" <<
        std::endl;
      */

      if (!stand_up_cmd) {
        if (gait.is_standing()) {
          next_hex_state = Sitting_down;
        }
      }
      if (!walking_cmd) {
        if (gait.is_standing()) {
          next_hex_state = Standing;
        }
      }
      break;

    case Sitting_down:
      current_height += sit_step_height;
      if (current_height >= sitting_height) {
        current_height = sitting_height;
        next_hex_state = Sitting;
      }

      for (int c = 0; c < NUMBER_OF_LEGS; c++) {
        // feet.foot[c].position.x = neutral_foot_pos_x[c];
        // feet.foot[c].position.y = neutral_foot_pos_y[c];
        feet.foot[c].position.z = current_height;
      }
      break;

    default:  // Should never be reached. Goto safe state
      hex_state = Unknown;
      break;
  }

  hex_state = next_hex_state;


  // transmit the servo positions
  if (hex_state != Idle) {
    if (inverse_kinematics.calculate_ik(feet, body, &legs)) {
      int i = 0;
      for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
        joint_state_.position[i] = legs.leg[leg_index].coxa;
        i++;
        joint_state_.position[i] = legs.leg[leg_index].femur;
        i++;
        joint_state_.position[i] = legs.leg[leg_index].tibia;
        i++;
      }
      servo_driver.transmit_servo_positions(joint_state_);
    } else {
      RCLCPP_WARN(rclcpp::get_logger("Motion Control"), "Out of Range");
      feet = old_feet;  // Do not move any foot if one is out of range
    }
  }

  old_feet = feet;
}

void MotionControl::publish_joint_state(rclcpp::Time time)
{
  // publish the joint_states for RVIZ
  joint_state_.header.stamp = time;

  joint_state_publisher_->publish(joint_state_);
}
