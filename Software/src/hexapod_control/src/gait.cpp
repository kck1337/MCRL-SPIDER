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

#include <hexapod_control/gait.hpp>
#include <algorithm>
#include <iomanip>

template<typename T>
int sgn(T val)
{
  return (T(0) < val) - (val < T(0));
}

void Gait::init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer)
{
  sub_step_index = 0;
  leg_group_index = 0;
  leg_group_index1 = 1;

  if (param_pointer == NULL) {
    // Init for testing, parameters cannot be accessed. Used standard values...
    RCLCPP_WARN(rclcpp::get_logger("Gait"), "Parameter pointer is Null. Ignore if testing");

    NUMBER_OF_LEGS = number_of_legs_test;
    SUB_STEPS = sub_steps_test;
    LEG_LIFT_HEIGHT = leg_lift_height_test;
    neutral_foot_pos_x = neutral_foot_pos_x_test;
    neutral_foot_pos_y = neutral_foot_pos_y_test;
    walking_height = walking_height_test;
  } else {
    NUMBER_OF_LEGS = param_pointer->get_parameter("NUMBER_OF_LEGS").as_int();
    SUB_STEPS = param_pointer->get_parameter("SUB_STEPS").as_double();
    LEG_LIFT_HEIGHT = param_pointer->get_parameter("LEG_LIFT_HEIGHT").as_double();
    neutral_foot_pos_x = param_pointer->get_parameter("INIT_FOOT_POS_X").as_double_array();
    neutral_foot_pos_y = param_pointer->get_parameter("INIT_FOOT_POS_Y").as_double_array();
    walking_height = param_pointer->get_parameter("INIT_FOOT_POS_Z").as_double();
  }

  foot_pos_x = neutral_foot_pos_x;
  foot_pos_y = neutral_foot_pos_y;
  next_foot_pos_x = neutral_foot_pos_x;
  next_foot_pos_y = neutral_foot_pos_y;
  rho.resize(NUMBER_OF_LEGS);
  phi.resize(NUMBER_OF_LEGS);
  dx.resize(NUMBER_OF_LEGS);
  dy.resize(NUMBER_OF_LEGS);
  dz.resize(NUMBER_OF_LEGS);
  foot_pos_z.resize(NUMBER_OF_LEGS);
  next_foot_pos_z.resize(NUMBER_OF_LEGS);
  for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
    foot_pos_z[leg_index] = 0;
    next_foot_pos_z[leg_index] = 0;
  }

  gait_state = Standing;
  next_gait_state = Standing;

  // factor to correct the speed to compensate for the missing steps
  scaling_factor = (SUB_STEPS + 2 * transition_steps) / (SUB_STEPS - 2 * transition_steps) + 0.2;
}

// Gets called for every substep
void Gait::gait_cycle(
  const geometry_msgs::msg::Twist & cmd_vel,
  hexapod_msgs::msg::FeetPositions * feet)
{
  new_gait_interval = false;
  standing = false;

  double vx = cmd_vel.linear.x * distance_per_step;
  double vy = cmd_vel.linear.y * distance_per_step;

  // std::cerr << "[ " << std::setfill('0') << std::setw(2) << sub_step_index << "       ] ";
  /* Stance defines the movement of the body, as pushing the legs on the ground backwards moves
  the body forwards. Movement is in the reverse direction of the body movement. Scale down the
  speed to enable the swing to reach the required position.*/

  // Calculations required for all legs
  if (gait_state != Standing) {
    vx /= sqrt(2);  // scaling, because if both vx and vy == 1 the step length can get too big
    vy /= sqrt(2);  // in case of turning. Scale normals steps for consistency
    if (cmd_vel.angular.z != 0) {
      if (vx == 0 && vy == 0) {
        x0 = 0;
        y0 = 0;
      } else {
        // 2.5/exp(vz) linearizes the input and scales it to a radius from approx. 0.22m to 1.8m
        x0 = -vy / sqrt(pow(vy, 2) + pow(vx, 2)) *
          sgn(cmd_vel.angular.z) * (2.5 / exp(abs(cmd_vel.angular.z)) - 0.7);
        y0 = vx / sqrt(pow(vy, 2) + pow(vx, 2)) *
          sgn(cmd_vel.angular.z) * (2.5 / exp(abs(cmd_vel.angular.z)) - 0.7);
        // std::cerr << "x0/y0 = " << x0 << "/" << y0 << std::endl;
      }

      double max_rho = 0;   // max rho of all legs
      for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
        rho[leg_index] = sqrt(
          pow(foot_pos_x[leg_index] - x0, 2) +
          pow(foot_pos_y[leg_index] - y0, 2)
        );
        max_rho = std::max(max_rho, rho[leg_index]);

        if ((foot_pos_x[leg_index] - x0) < 0) {
          phi[leg_index] = M_PI - asin((foot_pos_y[leg_index] - y0) / rho[leg_index]);
        } else {
          phi[leg_index] = asin((foot_pos_y[leg_index] - y0) / rho[leg_index]);
        }

        /*
        if (leg_index == 0) {
          std::cerr << "rho = " << rho[leg_index] << std::endl;
          std::cerr << "max_rho = " << max_rho << std::endl;

          std::cerr << "phi = " << phi[leg_index] << std::endl;


          std::cerr << "x0 = " << x0 << std::endl;
          std::cerr << "y0 = " << y0 << std::endl;
        }
        */
      }

      if (vx == 0 && vy == 0) {
        dphi = cmd_vel.angular.z * dphi_max_standing;
      } else {
        dphi = sgn(cmd_vel.angular.z) * atan(sqrt(pow(vx, 2) + pow(vy, 2)) / max_rho);
        // dphi has to be limited so that the fastest foot is not faster than the allowed limit
      }
      // std::cerr << "dphi = " << dphi << std::endl;
    }

    for (int leg_index : leg_groups[leg_group_index1]) {
      if (cmd_vel.angular.z == 0) {
        dx[leg_index] = -vx;
        dy[leg_index] = -vy;
      } else {
        dx[leg_index] = -foot_pos_x[leg_index] +
          rho[leg_index] * cos(phi[leg_index] - dphi) + x0;
        dy[leg_index] = -foot_pos_y[leg_index] +
          rho[leg_index] * sin(phi[leg_index] - dphi) + y0;
      }

      dz[leg_index] = 0;  // feet stay on the ground
    }
  }

  switch (gait_state) {
    case Standing:
      // std::cerr << "Standing" << std::endl;
      sub_step_index = 0;
      transition_index = 0;

      // standing means not moving, next = current pos
      for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
        dx[leg_index] = 0;
        dy[leg_index] = 0;
        dz[leg_index] = 0;
      }

      if (abs(vx) > 0 || abs(vy) > 0 || abs(cmd_vel.angular.z) > 0) {
        next_gait_state = Stance_to_swing;
      } else {
        next_gait_state = Standing;
        standing = true;  // standing is only true if the vel = 0 in standing state
      }
      break;

    case Stance_to_swing:
      reached_neutral = false;

      // std::cerr << "Stance_to_swing" << std::endl;
      for (int leg_index : leg_groups[leg_group_index]) {
        if (cmd_vel.angular.z == 0) {
          dx[leg_index] = -transition_factor[0][transition_index] * vx;
          dy[leg_index] = -transition_factor[0][transition_index] * vy;
        } else {
          dx[leg_index] = -foot_pos_x[leg_index] + rho[leg_index] *
            cos(phi[leg_index] - transition_factor[0][transition_index] * dphi) + x0;
          dy[leg_index] = -foot_pos_y[leg_index] + rho[leg_index] *
            sin(phi[leg_index] - transition_factor[0][transition_index] * dphi) + y0;
        }

        dz[leg_index] = transition_factor[1][transition_index] * height_per_step;
      }

      transition_index++;

      if (transition_index >= transition_steps) {
        next_gait_state = Swing_lift;
        transition_index = 0;
      }
      break;

    case Swing_lift:
      // std::cerr << "Swing_lift" << std::endl;
      switch_state = false;

      for (int leg_index : leg_groups[leg_group_index]) {
        dz[leg_index] = height_per_step;
        // state transition check, if one leg is high enough. Should be the same for all legs
        if (foot_pos_z[leg_index] + dz[leg_index] >= LEG_LIFT_HEIGHT) {switch_state = true;}
      }

      // if stepheight is reached goto next state
      if (switch_state) {
        next_gait_state = Swing_plateau;
      }
      break;

    case Swing_plateau:
      // std::cerr << "Swing_plateau" << std::endl;

      // x,y reach neutral point withing half the sub steps
      for (int leg_index : leg_groups[leg_group_index]) {
        dz[leg_index] = 0;
      }

      if (sub_step_index >= SUB_STEPS - LEG_LIFT_HEIGHT / height_per_step - transition_steps) {
        next_gait_state = Swing_lower;
      }
      break;

    case Swing_lower:
      // std::cerr << "Swing_lower" << std::endl;
      switch_state = false;
      for (int leg_index : leg_groups[leg_group_index]) {
        dz[leg_index] = -height_per_step;

        if (foot_pos_z[leg_index] + dz[leg_index] <= (sum_of_steps + 1) * height_per_step) {
          switch_state = true;
        }
      }

      if (switch_state) {
        next_gait_state = Swing_to_stance;
        transition_index = transition_steps;
      }
      break;

    case Swing_to_stance:
      // std::cerr << "Swing_to_stance" << std::endl;
      switch_state = false;
      for (int leg_index : leg_groups[leg_group_index]) {
        if (cmd_vel.angular.z == 0) {
          dx[leg_index] = -transition_factor[0][transition_index] * vx;
          dy[leg_index] = -transition_factor[0][transition_index] * vy;
        } else {
          dx[leg_index] = -foot_pos_x[leg_index] + rho[leg_index] *
            cos(phi[leg_index] - transition_factor[0][transition_index] * dphi) + x0;
          dy[leg_index] = -foot_pos_y[leg_index] + rho[leg_index] *
            sin(phi[leg_index] - transition_factor[0][transition_index] * dphi) + y0;
        }

        dz[leg_index] = -transition_factor[1][transition_index] * height_per_step;
      }

      transition_index--;

      // if leg on floor change leggroup
      if (transition_index == 0) {
        transition_index = 0;
        new_gait_interval = true;

        // If both feet are-foot_pos_x[leg_index] +  close to neutral position and vel_cmd < limit
        // goto standing
        if (vx == 0 && vy == 0 && cmd_vel.angular.z == 0) {
          bool near_neutral = true;
          // check if all legs are close to the neutral point
          // if yes, standing. if no, make another step
          for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
            if (abs(foot_pos_x[leg_index] + dx[leg_index] - neutral_foot_pos_x[leg_index]) >
              stability_radius ||
              abs(foot_pos_y[leg_index] + dy[leg_index] - neutral_foot_pos_y[leg_index]) >
              stability_radius)
            {
              near_neutral = false;
            }
          }

          if (near_neutral) {
            next_gait_state = Standing;
          } else {
            next_gait_state = Stance_to_swing;
          }
        } else {
          next_gait_state = Stance_to_swing;
        }
      }
      break;

    default:  // Should never be reached. Goto safe state
      std::cerr << "Default state" << std::endl;
      next_gait_state = Standing;
      break;
  }   // end switch

  // dx/dy movement to/from neutral, only for these 3 states.
  // 1. Reach neutral point
  // 1a if neutral point reached before steps/2 goto steps/2 to shorten the walking period
  // 2. move from neutral to good starting point for next step
  if (gait_state == Swing_lift ||
    gait_state == Swing_plateau ||
    gait_state == Swing_lower)
  {
    if (!reached_neutral) {
      bool close_neutral = true;
      // check if we are close to the neutral point
      for (int leg_index : leg_groups[leg_group_index]) {
        if (std::abs(foot_pos_x[leg_index] - neutral_foot_pos_x[leg_index]) > stability_radius ||
          std::abs(foot_pos_y[leg_index] - neutral_foot_pos_y[leg_index]) > stability_radius)
        {
          close_neutral = false;
        }
      }
      // Skip a few steps if we are already close to the neutral point
      if (close_neutral) {
        // std::cerr << "Reached neutral point" << std::endl;
        reached_neutral = true;
        if (sub_step_index < SUB_STEPS / 2) {
          sub_step_index = SUB_STEPS / 2;
        }
      }
    }

    if (!reached_neutral) {
      // move to neutral point, try to do so before reaching mid cycle
      step_nr = 0;
      // find max nr of steps required to reach neutral point
      for (int leg_index : leg_groups[leg_group_index]) {
        step_nr = std::max(
          step_nr,
          std::abs(
            (foot_pos_x[leg_index] - neutral_foot_pos_x[leg_index]) /
            (distance_per_step * scaling_factor))
        );
        step_nr = std::max(
          step_nr,
          std::abs(
            (foot_pos_y[leg_index] - neutral_foot_pos_y[leg_index]) /
            (distance_per_step * scaling_factor))
        );
      }
      // std::cerr << "Step nr: " << step_nr << std::endl;
      if (step_nr < 2) {  // catches the 1st step
        step_nr = std::ceil(step_nr);
      } else {  // TODO(voserp): check if always suitable
        step_nr = std::max(std::ceil(step_nr), SUB_STEPS / 2 - sub_step_index);
      }

      // TODO(voserp): if we can reach the neutral point fast, we should slow down a bit
      for (int leg_index : leg_groups[leg_group_index]) {
        // move foot the fastet way to neutral position
        dx[leg_index] = -sgn((foot_pos_x[leg_index] - neutral_foot_pos_x[leg_index])) *
          std::min(
          std::abs((foot_pos_x[leg_index] - neutral_foot_pos_x[leg_index])) / step_nr,
          (distance_per_step * scaling_factor)
          );
        dy[leg_index] = -sgn((foot_pos_y[leg_index] - neutral_foot_pos_y[leg_index])) *
          std::min(
          std::abs((foot_pos_y[leg_index] - neutral_foot_pos_y[leg_index])) / step_nr,
          (distance_per_step * scaling_factor)
          );
      }
    } else {
      // move from neutral point, as many steps as there are still left in the cycle
      double scaling_factor = (SUB_STEPS + transition_steps) / (SUB_STEPS - 2 * transition_steps);
      for (int leg_index : leg_groups[leg_group_index]) {
        if (cmd_vel.angular.z == 0) {
          dx[leg_index] = vx * scaling_factor;
          dy[leg_index] = vy * scaling_factor;
        } else {
          dx[leg_index] = -foot_pos_x[leg_index] + rho[leg_index] *
            cos(phi[leg_index] + scaling_factor * dphi) + x0;
          dy[leg_index] = -foot_pos_y[leg_index] + rho[leg_index] *
            sin(phi[leg_index] + scaling_factor * dphi) + y0;
        }
      }
    }
  }

  // Calculate the position for each foot
  for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
    next_foot_pos_x[leg_index] = foot_pos_x[leg_index] + dx[leg_index];
    next_foot_pos_y[leg_index] = foot_pos_y[leg_index] + dy[leg_index];
    next_foot_pos_z[leg_index] = foot_pos_z[leg_index] + dz[leg_index];
    // TODO(voserp): Test if z goes below ground

    feet->foot[leg_index].position.x = next_foot_pos_x[leg_index];
    feet->foot[leg_index].position.y = next_foot_pos_y[leg_index];
    // This way the floor is at height 0
    feet->foot[leg_index].position.z = next_foot_pos_z[leg_index] - walking_height;
  }

  sub_step_index++;
  gait_state = next_gait_state;

  // In case of swing or stance, this state is only valud for 1 leg group.
  // The other is in the opposite state
  if (new_gait_interval) {
    sub_step_index = 0;
    leg_group_index = (leg_group_index + 1) % 2;
    leg_group_index1 = (leg_group_index + 1) % 2;

    // std::cerr << "[----------] Switch leg group " << std::endl;
  }

  foot_pos_x = next_foot_pos_x;
  foot_pos_y = next_foot_pos_y;
  foot_pos_z = next_foot_pos_z;
}

bool Gait::is_standing(void)
{
  return standing;
}
