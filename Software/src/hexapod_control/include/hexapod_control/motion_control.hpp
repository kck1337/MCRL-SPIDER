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

#ifndef HEXAPOD_CONTROL__MOTION_CONTROL_HPP_
#define HEXAPOD_CONTROL__MOTION_CONTROL_HPP_

#include <std_msgs/msg/string.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <hexapod_control/servo_driver.hpp>
#include <hexapod_control/ik.hpp>
#include <hexapod_control/gait.hpp>
#include <vector>
#include <string>

class MotionControl
{
public:
  void init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer);
  void set_servo(float angle0, float angle1, float angle2);
  void iterate_step(geometry_msgs::msg::Twist cmd_vel);
  void update_vel(geometry_msgs::msg::Twist cmd_vel);
  void get_joint_state(sensor_msgs::msg::JointState & joint_state);
  void stand_up(void);
  void sit_down(void);
  void start_stop(void);
  void stand_walk();
  void motion_loop();
  void publish_joint_state(rclcpp::Time time);

  sensor_msgs::msg::JointState joint_state_, test_joint_state_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_publisher_;

private:
  int servo_count;
  int NUMBER_OF_LEGS;
  double current_height;
  bool stand_up_cmd = false;
  bool start_cmd = false;
  bool walking_cmd = true;

  hexapod_msgs::msg::FeetPositions old_feet, feet;
  hexapod_msgs::msg::LegsJoints test_legs, legs;
  hexapod_msgs::msg::Pose body;

  std::vector<std::string> SERVO_NAMES;
  std::vector<double> neutral_foot_pos_x, neutral_foot_pos_y;
  double walking_height;

  ServoDriver servo_driver;
  IK inverse_kinematics;
  Gait gait;

  geometry_msgs::msg::Twist cmd_vel_;

  typedef enum
  {
    Unknown,
    Idle,
    Sitting,  // Sitting, torque off
    Standing_up,
    Standing,
    Walking,
    Sitting_down
  } tState;
  tState hex_state, next_hex_state;

  double sit_step_height = 0.002;
  double sitting_height = 0.05;
};

#endif  // HEXAPOD_CONTROL__MOTION_CONTROL_HPP_
