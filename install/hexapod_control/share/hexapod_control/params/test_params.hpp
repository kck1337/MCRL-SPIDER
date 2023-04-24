// ROS2 Test parameters
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
#ifndef HEXAPOD_CONTROL__PARAMS__TEST_PARAMS_HPP_
#define HEXAPOD_CONTROL__PARAMS__TEST_PARAMS_HPP_

#include <vector>
#include <string>

// Inline is required to prevent linker errors due to muitple includes
inline double sub_steps_test = 50.0;
inline double leg_lift_height_test = 0.05;

// ['RR', 'RM', 'RF', 'LR', 'LM', 'LF']
inline std::vector<double> neutral_foot_pos_x_test =
{-0.25, 0, 0.25, -0.25, 0, 0.25};
inline std::vector<double> neutral_foot_pos_y_test =
{-0.23, -0.308, -0.23, 0.23, 0.308, 0.23};

inline std::vector<double> coxa_to_center_x_test = {-0.120, 0.0, 0.120, -0.120, 0.0, 0.120};
inline std::vector<double> coxa_to_center_y_test = {-0.055, -0.090, -0.055, 0.055, 0.090, 0.055};
inline std::vector<double> init_coxa_angle_test = {-60.0, 0.0, 60.0, -60.0, 0.0, 60.0};

inline int number_of_legs_test = 6;
inline double walking_height_test = 0.1350;

inline double coxa_length_test = 0.083;
inline double femur_length_test = 0.100;
inline double tibia_length_test = 0.1618;

inline std::vector<int64_t> limit_coxa_test = {227, 796};
inline std::vector<int64_t> limit_femur_test = {39, 988};
inline std::vector<int64_t> limit_tibia_test = {54, 960};

inline double max_distance_per_step = 0.015;
inline double max_height_per_step = 0.012;

// NR, ID, Ticks, Center, Max_Degree, Sign, Offset
inline std::vector<std::string> servo_names_test =
{"COXA_RR", "FEMUR_RR", "TIBIA_RR", "COXA_RM", "FEMUR_RM", "TIBIA_RM", "COXA_RF", "FEMUR_RF",
  "TIBIA_RF", "COXA_LR", "FEMUR_LR", "TIBIA_LR", "COXA_LM", "FEMUR_LM", "TIBIA_LM", "COXA_LF",
  "FEMUR_LF", "TIBIA_LF"};

inline std::vector<int32_t> id_test =
{8, 10, 12, 14, 16, 18, 2, 4, 6, 9, 11, 13, 15, 17, 19, 3, 5, 7};
inline std::vector<int32_t> ticks_test =
{1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024,
  1024};
inline std::vector<int32_t> center_test =
{512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
inline std::vector<int32_t> sign_test =
{-1, 1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1};
inline std::vector<int32_t> offset_test =
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
inline double max_degree_test = 300;  // 300 Degree


#endif  // HEXAPOD_CONTROL__PARAMS__TEST_PARAMS_HPP_
