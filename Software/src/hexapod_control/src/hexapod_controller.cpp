// ROS2 Hexapod Main Controller
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

#include <sensor_msgs/msg/joy.hpp>
#include <rclcpp/rclcpp.hpp>
#include <hexapod_control/motion_control.hpp>
#include <memory>
#include <chrono>

#define debounce_time 1

using namespace std::chrono_literals;

using std::placeholders::_1;

geometry_msgs::msg::Twist cmd_vel_;
int command = 0, old_command = 0;
int button_time_old[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};   // XBOX controller has 11 buttons

class HexapodController : public rclcpp::Node
{
public:
  rclcpp::node_interfaces::NodeParametersInterface::SharedPtr parameterinterface;

  HexapodController()
  : Node("hexapod_controller")
  {
    RCLCPP_INFO(this->get_logger(), "Hello Log");

    parameterinterface = this->get_node_parameters_interface();

    // declare parameters here
    parameterinterface->declare_parameter("SERVO_NAMES", rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("SUB_STEPS",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("LEG_LIFT_HEIGHT",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("INIT_FOOT_POS_X",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("INIT_FOOT_POS_Y",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("INIT_FOOT_POS_Z",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("COXA_TO_CENTER_X",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("COXA_TO_CENTER_Y",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("INIT_COXA_ANGLE",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("COXA_LENGTH",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("FEMUR_LENGTH",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("TIBIA_LENGTH",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("TARSUS_LENGTH",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("LIMIT_COXA",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("LIMIT_FEMUR",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("LIMIT_TIBIA",rclcpp::ParameterValue(), rcl_interfaces::msg::ParameterDescriptor());
    parameterinterface->declare_parameter("NUMBER_OF_LEGS", rclcpp::ParameterValue(3));

    // Initilaize Class Objects
    motion_control.init(parameterinterface);

    // Create publisher for rviz control
    motion_control.joint_state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>(
      "joint_states", 10);


    // Create timer for "main loop"
    timer_ = this->create_wall_timer(10ms, std::bind(&HexapodController::timer_callback, this));
  }

private:
  void timer_callback()
  {
    if (command != old_command) {
      switch (command) {
        case 1:
          motion_control.stand_up();
          break;
        case 2:
          motion_control.sit_down();
          break;
        case 3:
          motion_control.stand_walk();
          break;
        case 8:
          motion_control.start_stop();
          break;
      }
    }
    old_command = command;

    motion_control.update_vel(cmd_vel_);
    motion_control.motion_loop();
    motion_control.publish_joint_state(this->now());  // For RVIZ
  }
  rclcpp::TimerBase::SharedPtr timer_;
  // Create Class objects
  MotionControl motion_control;
};


//=============================================================================
// Main
//=============================================================================
// FSM control the motion state of the Hexapod
int main(int argc, char ** argv)
{
  RCLCPP_INFO(rclcpp::get_logger("Main"), "Hello World");
  bool is_rpi = false;
  if (strcmp(argv[1], "-RPi") == 0) {
    std::cerr << "Arguments: RPi received" << std::endl;
    is_rpi = true;
  }

  rclcpp::init(argc, argv);

  // You MUST use the MultiThreadedExecutor to use, well, multiple threads
  rclcpp::executors::MultiThreadedExecutor executor;

  auto hexa_node = std::make_shared<HexapodController>();
  // This contains BOTH subscriber callbacks.
  // They will still run on different threads
  // One Node. Two callbacks. Two Threads


  auto joy_callback =
    [is_rpi](sensor_msgs::msg::Joy::SharedPtr joy) -> void
    {
      command = 0;

      // XBOX one button map, per button debounce required
      if (joy->buttons[0] == 1) {
        if (joy->header.stamp.sec - button_time_old[0] >= debounce_time) {
          command = 1;  // stand up
          button_time_old[0] = joy->header.stamp.sec;
        }
      }
      if (joy->buttons[1] == 1) {
        if (joy->header.stamp.sec - button_time_old[1] >= debounce_time) {
          command = 2;  // stand up
          button_time_old[1] = joy->header.stamp.sec;
        }
      }
      if (joy->buttons[2] == 1) {
        if (joy->header.stamp.sec - button_time_old[2] >= debounce_time) {
          command = 3;  // walk or stand
          button_time_old[2] = joy->header.stamp.sec;
        }
      }
      if (joy->buttons[7] == 1) {
        if (joy->header.stamp.sec - button_time_old[7] >= debounce_time) {
          command = 8;  // stand up
          button_time_old[7] = joy->header.stamp.sec;
        }
      }

      cmd_vel_.linear.x = joy->axes[1];
      cmd_vel_.linear.y = joy->axes[0];
      if (is_rpi) {
        cmd_vel_.angular.z = joy->axes[2];
        // cmd_vel_.angular.y = joy->axes[3];
      } else {
        cmd_vel_.angular.z = joy->axes[3];
        // cmd_vel_.angular.y = joy->axes[4];
      }
    };

  auto subscription_ = hexa_node->create_subscription<sensor_msgs::msg::Joy>(
    "/joy", 1, joy_callback);

  spin(hexa_node);

  rclcpp::shutdown();
  return 0;
}
