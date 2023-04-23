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

#include <hexapod_control/ik.hpp>

//==============================================================================
//  Initialize ik variables
//==============================================================================

void IK::init(rclcpp::node_interfaces::NodeParametersInterface::SharedPtr param_pointer)
{
  rclcpp::Logger logger = rclcpp::get_logger("IK");

  // Init for testing, parameters cannot be accessed. Used standard values...
  if (param_pointer == NULL) {
    RCLCPP_WARN(logger, "Parameter pointer is Null. Ignore if testing");


    COXA_TO_CENTER_X = coxa_to_center_x_test;
    COXA_TO_CENTER_Y = coxa_to_center_y_test;
    INIT_COXA_ANGLE = init_coxa_angle_test;
    COXA_LENGTH = coxa_length_test;
    FEMUR_LENGTH = femur_length_test;
    TIBIA_LENGTH = tibia_length_test;
    NUMBER_OF_LEGS = number_of_legs_test;

    // Convert Degree to radians
    for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
      INIT_COXA_ANGLE[leg_index] = INIT_COXA_ANGLE[leg_index] * M_PI / 180;
    }
    return;
  }
  //=============================================================================
  // Define Physical Measurements in mm <config file>
  //=============================================================================

  COXA_TO_CENTER_X = param_pointer->get_parameter("COXA_TO_CENTER_X").as_double_array();
  COXA_TO_CENTER_Y = param_pointer->get_parameter("COXA_TO_CENTER_Y").as_double_array();
  INIT_COXA_ANGLE = param_pointer->get_parameter("INIT_COXA_ANGLE").as_double_array();
  COXA_LENGTH = param_pointer->get_parameter("COXA_LENGTH").as_double();
  FEMUR_LENGTH = param_pointer->get_parameter("FEMUR_LENGTH").as_double();
  TIBIA_LENGTH = param_pointer->get_parameter("TIBIA_LENGTH").as_double();
  // TARSUS_LENGTH = param_pointer->get_parameter( "TARSUS_LENGTH" ).as_double();
  NUMBER_OF_LEGS = param_pointer->get_parameter("NUMBER_OF_LEGS").as_int();

// Convert Degree to radians
  for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
    INIT_COXA_ANGLE[leg_index] = INIT_COXA_ANGLE[leg_index] * M_PI / 180;
  }
}

// Returns the sign, fast. Modified behaviour for 0 --> sgn(0)= +1
// Source: https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
template<typename T>
int sgn(T val)
{
  return (T(0) <= val) - (val < T(0));
}


//=============================================================================
// Inverse Kinematics
//=============================================================================
// TODO(voserp): Non reachable coordinates
bool IK::calculate_ik(
  const hexapod_msgs::msg::FeetPositions & feet,
  const hexapod_msgs::msg::Pose & body,
  hexapod_msgs::msg::LegsJoints * legs)
{
  rclcpp::Logger logger = rclcpp::get_logger("IK");

  // For each leg calculate the servo angles corresponding to the foot position
  for (int leg_index = 0; leg_index < NUMBER_OF_LEGS; leg_index++) {
    double Fx = feet.foot[leg_index].position.x;
    double Fy = feet.foot[leg_index].position.y;
    double Fz = feet.foot[leg_index].position.z;

    // Shift the coordiantes accorsing to body position
    Fx -= body.position.x;
    Fy -= body.position.y;
    Fz -= body.position.z;

    RCLCPP_DEBUG(logger, "Foot number %i", leg_index);

    RCLCPP_DEBUG(logger, "Foot x %.3f", Fx);
    RCLCPP_DEBUG(logger, "Foot y %.3f", Fy);
    RCLCPP_DEBUG(logger, "Foot z %.3f", Fz);

    // The foot coordinates (Fx, Fy, Fz) are transformed so that the Coxe joint
    // becomes the center of the new coordinate system (Fx_n, Fy_n, Fz_n)
    // This is accomplished using a rotation matrix according to Tait-Brian
    // angles, in this case Z1Y2X3
    // http://en.wikipedia.org/wiki/Euler_angles
    double s1 = sin(body.orientation.yaw);
    double c1 = cos(body.orientation.yaw);
    double s2 = sin(body.orientation.pitch);
    double c2 = cos(body.orientation.pitch);
    double s3 = sin(body.orientation.roll);
    double c3 = cos(body.orientation.roll);

    double Fx_n = (c1 * c2) * Fx + (c1 * s2 * s3 - c3 * s1) * Fy + (s1 * s3 + c1 * c3 * s2) * Fz;
    double Fy_n = (c2 * s1) * Fx + (c1 * c3 + s1 * s2 * s3) * Fy + (c3 * s1 * s2 - c1 * s3) * Fz;
    double Fz_n = (-s2) * Fx + (c2 * s3) * Fy + (c2 * c3) * Fz;

    RCLCPP_DEBUG(logger, "Fx_n %.3f", Fx_n);
    RCLCPP_DEBUG(logger, "Fy_n %.3f", Fy_n);
    RCLCPP_DEBUG(logger, "Fz_n %.3f", Fz_n);

    // we have rotated the coordinate system along the 3 angles calculated the coordinates of the
    // foot in this new system now we need to shift the center of the new system to the Coxa joint.
    // Since we have the coordinates of the coxa joint relative to the body we can simply subtract
    // these (new coordinates are fixed to the body and its rotation)

    Fx_n -= COXA_TO_CENTER_X[leg_index];
    Fy_n -= COXA_TO_CENTER_Y[leg_index];
    // Fz_n stays, COXA_TO_CENTER_Z = 0
    RCLCPP_DEBUG(logger, "Fx %.3f", Fx_n);
    RCLCPP_DEBUG(logger, "Fy %.3f", Fy_n);
    RCLCPP_DEBUG(logger, "Fz %.3f", Fz_n);

    // With these new coordinates we can calculate the angles using the trigonometric functions
    // calulated

    double G = sqrt(pow(Fy_n, 2) + pow(Fx_n, 2)) - COXA_LENGTH;
    double H = sqrt(pow(G, 2) + pow(Fz_n, 2));

    RCLCPP_DEBUG(logger, "T top %.3f", (pow(FEMUR_LENGTH, 2) + pow(H, 2) - pow(TIBIA_LENGTH, 2)));
    RCLCPP_DEBUG(logger, "T bot %.3f", (2 * FEMUR_LENGTH * H));

    double t =
      acos((pow(FEMUR_LENGTH, 2) + pow(H, 2) - pow(TIBIA_LENGTH, 2)) / (2 * FEMUR_LENGTH * H));
    if (!std::isfinite(t)) {RCLCPP_DEBUG(logger, "IK fail t: %f", t); return false;}
    double g = atan(G / Fz_n);  // TODO(voserp): Fz_n = 0
    if (!std::isfinite(g)) {RCLCPP_DEBUG(logger, "IK fail g: %f", g); return false;}

    RCLCPP_DEBUG(logger, "G %.3f", G);
    RCLCPP_DEBUG(logger, "H %.3f", H);
    RCLCPP_DEBUG(logger, "t %.3f", t);
    RCLCPP_DEBUG(logger, "g %.3f", g);

    double temp_angle = std::fmod(atan2(Fx_n, abs(Fy_n)) - INIT_COXA_ANGLE[leg_index], M_PI);
    if (!std::isfinite(temp_angle)) {
      RCLCPP_DEBUG(logger, "IK fail coxa: %f", temp_angle); return false;
    }
    legs->leg[leg_index].coxa = temp_angle;

    // Resulting joint angles in radians.

    legs->leg[leg_index].femur = t - g + sgn(Fz_n) * M_PI / 2;

    temp_angle = acos(
      (pow(TIBIA_LENGTH, 2) + pow(FEMUR_LENGTH, 2) - pow(H, 2)) /
      (2 * FEMUR_LENGTH * TIBIA_LENGTH)) - M_PI;
    if (!std::isfinite(temp_angle)) {
      RCLCPP_DEBUG(logger, "IK fail tibia: %f", temp_angle); return false;
    }
    legs->leg[leg_index].tibia = temp_angle;
    // legs->leg[leg_index].tarsus = legs->leg[leg_index].femur + legs->leg[leg_index].tibia;
  }

  return true;
}
