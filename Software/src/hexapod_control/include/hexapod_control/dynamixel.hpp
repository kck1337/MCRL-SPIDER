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

#ifndef HEXAPOD_CONTROL__DYNAMIXEL_HPP_
#define HEXAPOD_CONTROL__DYNAMIXEL_HPP_


// Dynamixel MX Servo Registers Universal
#define MODEL_NUMBER_L 0
#define MODEL_NUMBER_H 1
#define VERSION 2
#define SERVO_ID 3
#define BAUD_RATE 4
#define RETURN_DELAY_TIME 5
#define CW_ANGLE_LIMIT_L 6
#define CW_ANGLE_LIMIT_H 7
#define CCW_ANGLE_LIMIT_L 8
#define CCW_ANGLE_LIMIT_H 9
#define LIMIT_TEMPERATURE 11
#define LOW_LIMIT_VOLTAGE 12
#define HIGH_LIMIT_VOLTAGE 13
#define MAX_TORQUE_L 14
#define MAX_TORQUE_H 15
#define RETURN_LEVEL 16
#define ALARM_LED 17
#define ALARM_SHUTDOWN 18
#define TORQUE_ENABLE 24
#define LED 25
#define GOAL_POSITION_L 30
#define GOAL_POSITION_H 31
#define GOAL_SPEED_L 32
#define GOAL_SPEED_H 33
#define TORQUE_LIMIT_L 34
#define TORQUE_LIMIT_H 35
#define PRESENT_POSITION_L 36
#define PRESENT_POSITION_H 37
#define PRESENT_SPEED_L 38
#define PRESENT_SPEED_H 39
#define PRESENT_LOAD_L 40
#define PRESENT_LOAD_H 41
#define PRESENT_VOLTAGE 42
#define PRESENT_TEMPERATURE 43
#define REGISTERED_INSTRUCTION 44
#define MOVING 46
#define LOCK 47
#define PUNCH_L 48
#define PUNCH_H 49

// Dynamixel MX Servo Registers Only
#define MX_MULTI_TURN_OFFSET 20
#define MX_RESOLUTION_DIVIDER 22
#define MX_P_GAIN 26
#define MX_I_GAIN 27
#define MX_D_GAIN 28
#define MX_CURRENT 68
#define MX_TORQUE_CONTROL_MODE 70
#define MX_GOAL_TORQUE 71
#define MX_GOAL_ACCELERATION 73

// Dynamixel AX Servo Registers Only
#define AX_CW_COMPLIANCE_MARGIN 26
#define AX_CCW_COMPLIANCE_MARGIN 27
#define AX_CW_COMPLIANCE_SLOPE 28
#define AX_CCW_COMPLIANCE_SLOPE 29

#endif  // HEXAPOD_CONTROL__DYNAMIXEL_HPP_
