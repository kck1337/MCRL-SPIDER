// ROS2 Hexapod Inverse Kinematics
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


#ifndef HEXAPOD_CONTROL__IK_HPP_
#define HEXAPOD_CONTROL__IK_HPP_

#include <rclcpp/rclcpp.hpp>
#include <hexapod_msgs/msg/feet_positions.hpp>
#include <hexapod_msgs/msg/leg_joints.hpp>
#include <hexapod_msgs/msg/legs_joints.hpp>
#include <hexapod_msgs/msg/pose.hpp>
#include <hexapod_msgs/msg/rpy.hpp>
#include <../params/test_params.hpp>
#include <cmath>  // acos atan
#include <vector>
#include <memory>

class IK
{
public:
  void init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer);
  bool calculate_ik(
    const hexapod_msgs::msg::FeetPositions & feet,
    const hexapod_msgs::msg::Pose & body, hexapod_msgs::msg::LegsJoints * legs
  );

private:
  // Distance from coxa joint to the center pivot
  std::vector<double> COXA_TO_CENTER_X, COXA_TO_CENTER_Y;

  // Initial coxa offsets in radians
  std::vector<double> INIT_COXA_ANGLE;

  // Leg segment measurements
  double COXA_LENGTH, FEMUR_LENGTH, TIBIA_LENGTH, TARSUS_LENGTH;

  // Number of legs
  int NUMBER_OF_LEGS;
};

#endif  // HEXAPOD_CONTROL__IK_HPP_
