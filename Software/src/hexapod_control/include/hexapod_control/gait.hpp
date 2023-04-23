// ROS2 Hexapod Gait Control
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

#ifndef HEXAPOD_CONTROL__GAIT_HPP_
#define HEXAPOD_CONTROL__GAIT_HPP_

#include <rclcpp/rclcpp.hpp>
#include <hexapod_msgs/msg/feet_positions.hpp>
#include <geometry_msgs/msg/pose2_d.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <../params/test_params.hpp>
#include <cmath>  // acos atan
#include <vector>

class Gait
{
public:
  void init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer);
  void gait_cycle(
    const geometry_msgs::msg::Twist & cmd_vel,
    hexapod_msgs::msg::FeetPositions * feet);
  bool is_standing(void);
  double scaling_factor;

  const double stability_radius = 0.001;  // 1 mm
  const double height_per_step = 0.005;
  const double distance_per_step = 0.003;
  double x0, y0;

private:
  // walking parameters
  std::vector<double> neutral_foot_pos_x, neutral_foot_pos_y;
  std::vector<double> foot_pos_x, foot_pos_y, foot_pos_z;
  std::vector<double> next_foot_pos_x, next_foot_pos_y, next_foot_pos_z;
  std::vector<double> dx, dy, dz, rho, phi;
  double walking_height;

  double LEG_LIFT_HEIGHT;
  bool new_gait_interval;
  bool below0, switch_state, standing, reached_neutral;
  double SUB_STEPS;  // double to prevent numerous conversions
  double nr_steps_to_transition;
  int leg_group_index, leg_group_index1;  // either 0 or 1, switched betweenj group1 and group2
  uint transition_index;
  int sub_step_index;

  std::vector<std::vector<int>> leg_groups =
  {
    {1, 3, 5},
    {0, 2, 4}
  };

  int NUMBER_OF_LEGS;   // Number of legs
  double dphi, step_nr;
  double dphi_max_standing = 0.01;   //  Turning speed while standiung

  uint transition_steps = 3;
  std::vector<std::vector<double>> transition_factor =
  {
    {1, 1, 0},  // x/y movement
    {0, 0.5, 1}   // z movement
  };
  double sum_of_steps =
    std::accumulate(transition_factor[1].begin(), transition_factor[1].end(), 0);

  typedef enum
  {
    Standing,
    Stance_to_swing,
    Swing_lift,
    Swing_plateau,
    Swing_lower,
    Swing_to_stance
  } t_gait_state;

  t_gait_state gait_state = Standing;
  t_gait_state next_gait_state = Standing;
};

#endif  // HEXAPOD_CONTROL__GAIT_HPP_
