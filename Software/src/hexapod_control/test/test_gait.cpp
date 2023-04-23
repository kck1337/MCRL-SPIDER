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
TEST(test_hexapod_control, test_gait) {
  std::cerr << "[x-x-x-x-x-] Test Gait" << std::endl;

  // Setup plot of foot trajectory
  std::ofstream out("../plotout.m");
  std::ofstream out3d("../plotout3D.m");
  std::streambuf * coutbuf = std::cout.rdbuf();  // save old buf
  std::cout.rdbuf(out3d.rdbuf());   // redirect std::cout to file
  std::cout << "plot3([0, 0], [0, 0], [0, 0]); hold on;" << std::endl;

  std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file
  std::cout << "subplot(2,2,1), hold on" << std::endl;
  std::cout << "title('Foot 0 x'); xlabel('x'), ylabel('z')" << std::endl;

  std::cout << "subplot(2,2,3), hold on" << std::endl;
  std::cout << "title('Foot 1 x'); xlabel('x'), ylabel('z')" << std::endl;

  std::cout << "subplot(2,2,2), hold on" << std::endl;
  std::cout << "title('Foot 0 y'); xlabel('y'), ylabel('z')" << std::endl;

  std::cout << "subplot(2,2,4), hold on" << std::endl;
  std::cout << "title('Foot 1 y'); xlabel('y'), ylabel('z')" << std::endl;

  int Plot_Start = 00;
  int Plot_Stop = 400;
  int Plot_Steps = Plot_Stop - Plot_Start;

  Gait gait;
  gait.init(NULL);

  auto feet = hexapod_msgs::msg::FeetPositions();
  auto old_feet = hexapod_msgs::msg::FeetPositions();
  auto last_feet = hexapod_msgs::msg::FeetPositions();
  auto cmd_vel = geometry_msgs::msg::Twist();

  int counter = 0;

  cmd_vel.linear.x = 1;
  cmd_vel.linear.y = 0.5;
  cmd_vel.angular.z = 0;

  for (int count = 1; count < 1200; count++) {
    if (count == 800) {
      cmd_vel.linear.x = 0;
      cmd_vel.linear.y = 0;
      std::cerr << "[x-x-x-x-x-] Stop" << std::endl;
    }

    gait.gait_cycle(cmd_vel, &feet);

    if (count == 1) {
      old_feet = feet;

      // mark the neutral point
      std::cout.rdbuf(out3d.rdbuf());   // redirect std::cout to file
      std::cout << "plot3([" << feet.foot[0].position.x << "," << feet.foot[0].position.x <<
        "], [" << feet.foot[0].position.y << "," << feet.foot[0].position.y << "], [" <<
        feet.foot[0].position.z << ",0], 'r'); hold on;" << std::endl;
      std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file

      for (double z_value = -0.14; z_value < -0.05; z_value += 0.02) {
        std::cout << "subplot(2,2,1), plot([" <<
          feet.foot[0].position.x << "], [" << z_value << "],'ro')" <<
          std::endl;
        std::cout << "subplot(2,2,3), plot([" <<
          feet.foot[1].position.x << "], [" << z_value << "],'ro')" <<
          std::endl;
        std::cout << "subplot(2,2,2), plot([" <<
          feet.foot[0].position.y << "], [" << z_value << "],'ro')" <<
          std::endl;
        std::cout << "subplot(2,2,4), plot([" <<
          feet.foot[1].position.y << "], [" << z_value << "],'ro')" <<
          std::endl;
      }
    }
    /*
    std::cerr << "[          ] (x,y,z) F1: (" <<
      feet.foot[1].position.x << ", " <<
      feet.foot[1].position.y << ", " <<
      feet.foot[1].position.z << ")" <<
      std::endl;
    std::cerr << "[          ] (x,y,z) F4: (" <<
      feet.foot[4].position.x << ", " <<
      feet.foot[4].position.y << ", " <<
      feet.foot[4].position.z << ")" <<
      std::endl;
    std::cerr << "[          ] delta (x,y,z) F1: (" <<
      feet.foot[1].position.x - old_feet.foot[1].position.x << ", " <<
      feet.foot[1].position.y - old_feet.foot[1].position.y << ", " <<
      feet.foot[1].position.z - old_feet.foot[1].position.z << ")" <<
      std::endl;
    std::cerr << "[          ] delta (x,y,z) F4: (" <<
      feet.foot[4].position.x - old_feet.foot[4].position.x << ", " <<
      feet.foot[4].position.y - old_feet.foot[4].position.y << ", " <<
      feet.foot[4].position.z - old_feet.foot[4].position.z << ")" <<
      std::endl;
*/
    // continuity check
    for (int leg_index = 0; leg_index < number_of_legs_test; leg_index++) {
      // Test if movement per steps is smaller than max possible
      EXPECT_LT(
        abs(feet.foot[leg_index].position.x - old_feet.foot[leg_index].position.x),
        max_distance_per_step);
      EXPECT_LT(
        abs(feet.foot[leg_index].position.y - old_feet.foot[leg_index].position.y),
        max_distance_per_step);
      EXPECT_LT(
        abs(feet.foot[leg_index].position.z - old_feet.foot[leg_index].position.z),
        max_height_per_step);
    }

    // Stability check
    if (
      feet.foot[0].position.z == -walking_height_test &&
      feet.foot[1].position.z == -walking_height_test)
    {
      counter++;

      // If both feet are on the ground the speed has to be equal
      EXPECT_NEAR(
        feet.foot[0].position.x - old_feet.foot[0].position.x,
        feet.foot[1].position.x - old_feet.foot[1].position.x, 1e-9);
      EXPECT_NEAR(
        feet.foot[0].position.y - old_feet.foot[0].position.y,
        feet.foot[1].position.y - old_feet.foot[1].position.y, 1e-9);

      last_feet = feet;
    }

    /*
    if (abs(feet.foot[0].position.x) <= 0.00001 || abs(feet.foot[1].position.x) <= 0.00001) {
      std::cerr << "[          ] (x,y,z) g1: (" <<
        feet.foot[0].position.x << ", " <<
        feet.foot[0].position.y << ", " <<
        feet.foot[0].position.z << ")" <<
        std::endl;
      std::cerr << "[          ] (x,y,z) g2: (" <<
        feet.foot[1].position.x << ", " <<
        feet.foot[1].position.y << ", " <<
        feet.foot[1].position.z << ")" <<
        std::endl;
    }
    */

    // Output the foot trajectory to octave plot .m file
    if (count >= Plot_Start && count < Plot_Stop) {
      std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file
      // mark every 10th steps with an '*'
      if (count % 10 == 0) {
        std::cout << "subplot(2,2,1), plot([" <<
          feet.foot[0].position.x << "], [" <<
          feet.foot[0].position.z << "], " <<
          "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          "],'*')" <<
          std::endl;
        std::cout << "subplot(2,2,3), plot([" <<
          feet.foot[1].position.x << "], [" <<
          feet.foot[1].position.z << "], " <<
          "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          "],'*')" <<
          std::endl;
        std::cout << "subplot(2,2,2), plot([" <<
          feet.foot[0].position.y << "], [" <<
          feet.foot[0].position.z << "], " <<
          "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          "],'*')" <<
          std::endl;
        std::cout << "subplot(2,2,4), plot([" <<
          feet.foot[1].position.y << "], [" <<
          feet.foot[1].position.z << "], " <<
          "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
          ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
          "],'*')" <<
          std::endl;
      }

      // print the foot movement
      std::cout << "subplot(2,2,1), plot([" <<
        old_feet.foot[0].position.x << ", " <<
        feet.foot[0].position.x << "], [" <<
        old_feet.foot[0].position.z << ", " <<
        feet.foot[0].position.z << "], " <<
        "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        "])" <<
        std::endl;
      std::cout << "subplot(2,2,3), plot([" <<
        old_feet.foot[1].position.x << ", " <<
        feet.foot[1].position.x << "], [" <<
        old_feet.foot[1].position.z << ", " <<
        feet.foot[1].position.z << "], " <<
        "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        "])" <<
        std::endl;
      std::cout << "subplot(2,2,2), plot([" <<
        old_feet.foot[0].position.y << ", " <<
        feet.foot[0].position.y << "], [" <<
        old_feet.foot[0].position.z << ", " <<
        feet.foot[0].position.z << "], " <<
        "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        "])" <<
        std::endl;
      std::cout << "subplot(2,2,4), plot([" <<
        old_feet.foot[1].position.y << ", " <<
        feet.foot[1].position.y << "], [" <<
        old_feet.foot[1].position.z << ", " <<
        feet.foot[1].position.z << "], " <<
        "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        "])" <<
        std::endl;

      // Plot 3D graph
      std::cout.rdbuf(out3d.rdbuf());   // redirect std::cout to file
      std::cout << "plot3([" <<
        old_feet.foot[0].position.x << ", " <<
        feet.foot[0].position.x << "], [" <<
        old_feet.foot[0].position.y << ", " <<
        feet.foot[0].position.y << "], [" <<
        old_feet.foot[0].position.z << ", " <<
        feet.foot[0].position.z << "], " <<
        "'Color', [" << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << static_cast<float>(count - Plot_Start) / Plot_Steps <<
        ", " << 1 - static_cast<float>(count - Plot_Start) / Plot_Steps <<
        "])" <<
        std::endl;
    }

    // Test if one foot always touches ground.
    // z should be walking_height for one footgroup at all time
    EXPECT_NEAR(
      std::min(
        feet.foot[0].position.z + walking_height_test,
        feet.foot[1].position.z + walking_height_test), 0, 1e-4);

    // Test if feet on ground do not move if cmd_vel = 0
    if (feet.foot[0].position.z == -walking_height_test &&
      old_feet.foot[0].position.z == -walking_height_test)
    {
      if (cmd_vel.linear.x == 0) {
        EXPECT_EQ(old_feet.foot[0].position.x - feet.foot[0].position.x, 0);
      }
      if (cmd_vel.linear.y == 0) {
        EXPECT_EQ(old_feet.foot[0].position.y - feet.foot[0].position.y, 0);
      }
    }

    old_feet = feet;
  }

  // Both leg groups start at z=0, both legs should be at the ground each cycle
  EXPECT_GT(counter, 1);

  // Test if feet are standing on exit
  EXPECT_EQ(feet.foot[0].position.x, last_feet.foot[0].position.x);
  EXPECT_EQ(feet.foot[0].position.y, last_feet.foot[0].position.y);
  EXPECT_EQ(feet.foot[0].position.z, -walking_height_test);
  EXPECT_EQ(feet.foot[1].position.x, last_feet.foot[1].position.x);
  EXPECT_EQ(feet.foot[1].position.y, last_feet.foot[1].position.y);
  EXPECT_EQ(feet.foot[1].position.z, -walking_height_test);

  // Finishes the plot files and sets everything back to normal
  std::cout.rdbuf(out3d.rdbuf());   // redirect std::cout to file
  std::cout << "pause" << std::endl;
  std::cout.rdbuf(out.rdbuf());   // redirect std::cout to file
  std::cout << "pause" << std::endl;
  std::cout.rdbuf(coutbuf);   // reset to standard output again

  // Provoke error in order to display output
  // FAIL();
}
