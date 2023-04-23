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

#include <hexapod_control/gait.hpp>
#include <../params/test_params.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"

/* Things to be checked:
  1. Gait sequence is continuous --> does not have large jumps between steps
  2. Gait is stable --> if v is constant the positions are repeated each cycle
  3. Feet positions do not overlap --> no collisions (TODO)
  4. One feet has always ground contact
  5. Feet positions are always within possible ranges (TODO)
  6. Test if standing will be reached after vel = 0
  7. Feet at ground move at equal speed

  Walk a few steps, reach stability
  Stop, reach standing position
*/
TEST(test_hexapod_control, test_gait_turning) {
  std::cerr << "[x-x-x-x-x-] Test Gait Turning" << std::endl;

  // Setup plot of foot trajectory
  std::ofstream out("../plotout_turning.m");
  std::streambuf * coutbuf = std::cout.rdbuf();  // save old buf

  std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file
  std::cout << "figure, hold on" << std::endl;
  std::cout << "title('Feet x/y'); xlabel('x'), ylabel('y')" << std::endl;
  std::cout << "axis ('square')" << std::endl;

  int Plot_Start = 400;
  int Plot_Stop = 600;
  int Plot_Steps = Plot_Stop - Plot_Start;

  Gait gait;
  gait.init(NULL);

  std::cerr << "[x-x-x-x-x-] Scaling: " << gait.scaling_factor << std::endl;


  auto feet = hexapod_msgs::msg::FeetPositions();
  auto old_feet = hexapod_msgs::msg::FeetPositions();
  auto cmd_vel = geometry_msgs::msg::Twist();
  std::vector<int> sub_step_counter = {0, 0, 0, 0, 0, 0};

  // start with turning on the spot
  cmd_vel.linear.x = 0;
  cmd_vel.linear.y = 0;
  cmd_vel.angular.z = 0;

  for (int count = 1; count < 1000; count++) {
    if (count == 200) {
      // stop moving
      cmd_vel.linear.x = 1;
      cmd_vel.linear.y = 0;
      cmd_vel.angular.z = -0.5;
      std::cerr << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" <<
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
      std::cerr << "[x-x-x-x-x-] Stop" << std::endl;
    }
    if (count == 400) {
      cmd_vel.linear.x = 1;
      cmd_vel.linear.y = 0;
      cmd_vel.angular.z = 0.5;
      std::cerr << "[x-x-x-x-x-] Turning" << std::endl;
    }

    gait.gait_cycle(cmd_vel, &feet);

    if (count == 1) {
      old_feet = feet;
      std::cout << "plot([" <<
        feet.foot[0].position.x << "], [" << feet.foot[0].position.y <<
        "],'r*')" << std::endl;
      for (int leg_index = 1; leg_index < 6; leg_index++) {
        std::cout << "plot([" <<
          feet.foot[leg_index].position.x << "], [" << feet.foot[leg_index].position.y <<
          "],'ro')" << std::endl;
      }
    }

    std::cerr << "[          ] (x,y,z) RF: (" <<
      feet.foot[2].position.x << ", " <<
      feet.foot[2].position.y << ", " <<
      feet.foot[2].position.z << ")" <<
      std::endl;
    std::cerr << "[          ] (x,y,z) LR: (" <<
      feet.foot[3].position.x << ", " <<
      feet.foot[3].position.y << ", " <<
      feet.foot[3].position.z << ")" <<
      std::endl;
    std::cerr << "[          ] delta (x,y,z) RF: (" <<
      feet.foot[2].position.x - old_feet.foot[2].position.x << ", " <<
      feet.foot[2].position.y - old_feet.foot[2].position.y << ", " <<
      feet.foot[2].position.z - old_feet.foot[2].position.z << ")" <<
      std::endl;
    std::cerr << "[          ] delta (x,y,z) LR: (" <<
      feet.foot[3].position.x - old_feet.foot[3].position.x << ", " <<
      feet.foot[3].position.y - old_feet.foot[3].position.y << ", " <<
      feet.foot[3].position.z - old_feet.foot[3].position.z << ")" <<
      std::endl;

    // check if the delta per step is not too large
    for (int leg_index = 0; leg_index < number_of_legs_test; leg_index++) {
      // Test if movement per steps is smaller than max possible
      EXPECT_LT(
        abs(feet.foot[leg_index].position.x - old_feet.foot[leg_index].position.x),
        gait.distance_per_step * gait.scaling_factor) <<
        "Step distance x too large. Interation nr: " << count;
      EXPECT_LT(
        abs(feet.foot[leg_index].position.y - old_feet.foot[leg_index].position.y),
        gait.distance_per_step * gait.scaling_factor) <<
        "Step distance y too large. Interation nr: " << count;
      EXPECT_LT(
        abs(feet.foot[leg_index].position.z - old_feet.foot[leg_index].position.z),
        gait.height_per_step * 1.01) << "Step distance z too large. Interation nr: " << count;
    }

    // The feet on the ground should have the same rotation origin x0/y0
    for (int leg_index = 0; leg_index < number_of_legs_test; leg_index++) {
      if (feet.foot[leg_index].position.z == -walking_height_test) {
        // For feet on the ground check if the radius stayed the same during the last step
        // Checks also if the turning origin for the legs is the same
        EXPECT_NEAR(
          sqrt(
            pow(feet.foot[leg_index].position.x - gait.x0, 2) +
            pow(feet.foot[leg_index].position.y - gait.y0, 2)),
          sqrt(
            pow(old_feet.foot[leg_index].position.x - gait.x0, 2) +
            pow(old_feet.foot[leg_index].position.y - gait.y0, 2)),
          1e-9
        );
      }
    }

    // TODO(voserp): check if vz = -1 results in the same movement direction as vz = 1
    // TODO(voserp): the distance between the feet on the ground should stay the same
    for (int leg_index = 0; leg_index < number_of_legs_test; leg_index++) {
      if (feet.foot[leg_index].position.z == -walking_height_test) {
        std::cerr << "";
      }
    }
    // Check if each foot reaches neutral point within a cycle
    for (int leg_index = 0; leg_index < number_of_legs_test; leg_index++) {
      if (feet.foot[leg_index].position.z == -walking_height_test) {
        if (sub_step_counter[leg_index] >= 1000) {
          sub_step_counter[leg_index] = 0;  // every thing is good
        } else if (sub_step_counter[leg_index] != 0) {
          FAIL() << "Leg " << leg_index << " did not reach the neutral point at count " << count;
        }
      } else {
        sub_step_counter[leg_index] += 1;
        if (abs(feet.foot[leg_index].position.x - neutral_foot_pos_x_test[leg_index]) <
          gait.stability_radius &&
          abs(feet.foot[leg_index].position.y - neutral_foot_pos_y_test[leg_index]) <
          gait.stability_radius)
        {
          sub_step_counter[leg_index] = 1000;  // above 1k means the leg reached the neutral point
        }
      }
      if (sub_step_counter[leg_index] > sub_steps_test && sub_step_counter[leg_index] < 1000) {
        FAIL() << "Leg " << leg_index << " has performed " << sub_steps_test << " substeps";
      }
    }

    // Output the foot trajectory to octave plot .m file
    if (count >= Plot_Start && count < Plot_Stop) {
      std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file
      // print the foot movement
      for (int leg_index = 0; leg_index < 6; leg_index++) {
        std::cout << "plot([" <<
          old_feet.foot[leg_index].position.x << ", " <<
          feet.foot[leg_index].position.x << "], [" <<
          old_feet.foot[leg_index].position.y << ", " <<
          feet.foot[leg_index].position.y << "], " <<
          "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          "])" <<
          std::endl;
      }
    }
    old_feet = feet;
  }

  std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file
  std::cout << "pause" << std::endl;
  std::cout.rdbuf(coutbuf);   // reset to standard output again

  // Provoke error in order to display output
  // FAIL();
}
