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

#include <hexapod_control/ik.hpp>
#include <../params/test_params.hpp>
#include <vector>
#include "gtest/gtest.h"

// Returns the sign, fast. Modified behaviour for 0 --> sgn(0)= +1
// Source: https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
template<typename T>
int sgn(T val)
{
  return (T(0) <= val) - (val < T(0));
}

TEST(test_hexapod_control, test_inverse_kinematics) {
  IK inversekinematics;
  inversekinematics.init(NULL);

  auto feet = hexapod_msgs::msg::FeetPositions();
  auto body = hexapod_msgs::msg::Pose();
  auto legs = hexapod_msgs::msg::LegsJoints();
  auto legs1 = hexapod_msgs::msg::LegsJoints();

  std::vector<double> testx;
  std::vector<double> testy;
  std::vector<double> testz;

  //=============================================================================
  // Example 1 generated with octave
  //=============================================================================
  body.position.x = 0;
  body.position.y = 0;
  body.position.z = tibia_length_test;

  body.orientation.roll = -20 * M_PI / 180;
  body.orientation.pitch = -30 * M_PI / 180;
  body.orientation.yaw = 25 * M_PI / 180;

  testx = {-0.34661, -0.0750269, 0.242413, -0.156004, 0.17528, 0.316754};
  testy = {-0.156849, -0.325198, -0.173883, 0.324315, 0.306675, 0.0137814};
  testz = {0.263972, 0.0358366, -0.104126, 0.321992, 0.11203, -0.0814964};

  for (int leg_index = 0; leg_index < 6; leg_index++) {
    feet.foot[leg_index].position.x = testx[leg_index];
    feet.foot[leg_index].position.y = testy[leg_index];
    feet.foot[leg_index].position.z = testz[leg_index];
  }

  // Feet test Positions
  inversekinematics.calculate_ik(feet, body, &legs);

  for (int leg_index = 0; leg_index < 6; leg_index++) {
    EXPECT_NEAR(20 * M_PI / 180, legs.leg[leg_index].coxa, 1e-4);
    EXPECT_NEAR(45 * M_PI / 180, legs.leg[leg_index].femur, 1e-4);
    EXPECT_NEAR(-90 * M_PI / 180, legs.leg[leg_index].tibia, 1e-4);
  }

  //=============================================================================
  // Example 2 generated with octave
  //=============================================================================
  body.position.x = 0;
  body.position.y = 0;
  body.position.z = 0;

  body.orientation.roll = 11 * M_PI / 180;
  body.orientation.pitch = -21 * M_PI / 180;
  body.orientation.yaw = 32 * M_PI / 180;

  testx = {-0.345518, -0.206464, 0.121869, -0.218188, 0.113376, 0.334167};
  testy = {0.0944148, -0.232342, -0.346305, 0.299347, 0.282424, -0.00462273};
  testz = {0.0945615, 0.103699, -0.00254242, 0.00493425, -0.121434, -0.151977};

  for (int leg_index = 0; leg_index < 6; leg_index++) {
    feet.foot[leg_index].position.x = testx[leg_index];
    feet.foot[leg_index].position.y = testy[leg_index];
    feet.foot[leg_index].position.z = testz[leg_index];
  }

  // Feet test Positions
  inversekinematics.calculate_ik(feet, body, &legs);

  for (int leg_index = 0; leg_index < 6; leg_index++) {
    EXPECT_NEAR(-12 * M_PI / 180, legs.leg[leg_index].coxa, 1e-4);
    EXPECT_NEAR(67 * M_PI / 180, legs.leg[leg_index].femur, 1e-4);
    EXPECT_NEAR(-111 * M_PI / 180, legs.leg[leg_index].tibia, 1e-4);
  }

  //=============================================================================
  // Example 3 out of range values
  //=============================================================================
  body.position.x = 0;
  body.position.y = 0;
  body.position.z = 0;

  body.orientation.roll = 11 * M_PI / 180;
  body.orientation.pitch = -21 * M_PI / 180;
  body.orientation.yaw = 32 * M_PI / 180;

  testx = {-1.345518, -1.206464, 1.121869, -1.218188, 1.113376, 1.334167};
  testy = {0.0944148, -0.232342, -0.346305, 0.299347, 0.282424, -0.00462273};
  testz = {0.0945615, 0.103699, -0.00254242, 0.00493425, -0.121434, -0.151977};

  for (int leg_index = 0; leg_index < 6; leg_index++) {
    feet.foot[leg_index].position.x = testx[leg_index];
    feet.foot[leg_index].position.y = testy[leg_index];
    feet.foot[leg_index].position.z = testz[leg_index];
  }

  // Feet test Positions
  if (inversekinematics.calculate_ik(feet, body, &legs1)) {
    FAIL() << "Failed IK, returned a value while the input is out of reach";
  }
}
