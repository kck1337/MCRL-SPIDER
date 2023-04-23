// Copyright 2020 The Autoware Foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <hexapod_control/motion_control.hpp>
#include <../params/test_params.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include "gtest/gtest.h"

using namespace std::chrono_literals;

TEST(test_hexapod_control, test_motion) {
  sensor_msgs::msg::JointState joint_state_, old_joint_state_;
  geometry_msgs::msg::Twist cmd_vel_;
  cmd_vel_.linear.x = 0.8;
  cmd_vel_.linear.y = 0.0;
  cmd_vel_.linear.z = 0.0;

  MotionControl motion_control;
  motion_control.init(NULL);

  motion_control.motion_loop();
  motion_control.get_joint_state(joint_state_);

  for (int count = 0; count < 1000; count++) {
    // RCLCPP_INFO(rclcpp::get_logger("Motion Test"), "Iteration nr.: %i", count);

    old_joint_state_ = joint_state_;
    motion_control.motion_loop();
    motion_control.get_joint_state(joint_state_);

    switch (count) {
      case 1:
        motion_control.start_stop();
        break;
      case 30:
        motion_control.stand_up();
        break;
      case 200:
        motion_control.update_vel(cmd_vel_);
        break;
      case 700:
        motion_control.sit_down();
        break;
      default:  // other cases, do nothing
        break;
    }

    // Test if the angle change is feasible
    // Skip the setup because this is a jump
    if (count > 3) {
      for (int i = 0; i < number_of_legs_test * 3; i++) {
        EXPECT_NEAR(
          joint_state_.position[i],
          old_joint_state_.position[i], 0.1) <<
          joint_state_.name[i] << " angle change at interation " << count;
      }
    }
  }

  /*
  RCLCPP_INFO(
    rclcpp::get_logger("MC Test"), "coxa:  %.2f",
    joint_state_.position[0] / M_PI * 180);
  RCLCPP_INFO(
    rclcpp::get_logger("MC Test"), "femur: %.2f",
    joint_state_.position[1] / M_PI * 180);
  RCLCPP_INFO(
    rclcpp::get_logger("MC Test"), "tibia: %.2f",
    joint_state_.position[2] / M_PI * 180);
  RCLCPP_INFO(
    rclcpp::get_logger("MC Test"), "coxa:  %.2f",
    joint_state_.position[3] / M_PI * 180);
  RCLCPP_INFO(
    rclcpp::get_logger("MC Test"), "femur: %.2f",
    joint_state_.position[4] / M_PI * 180);
  RCLCPP_INFO(
    rclcpp::get_logger("MC Test"), "tibia: %.2f",
    joint_state_.position[5] / M_PI * 180);

  */
  // FAIL();   // Always shows the output for debugging
}
