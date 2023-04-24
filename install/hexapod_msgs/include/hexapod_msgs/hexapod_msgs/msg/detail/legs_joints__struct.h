// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__STRUCT_H_
#define HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'leg'
#include "hexapod_msgs/msg/detail/leg_joints__struct.h"

/// Struct defined in msg/LegsJoints in the package hexapod_msgs.
typedef struct hexapod_msgs__msg__LegsJoints
{
  hexapod_msgs__msg__LegJoints leg[6];
} hexapod_msgs__msg__LegsJoints;

// Struct for a sequence of hexapod_msgs__msg__LegsJoints.
typedef struct hexapod_msgs__msg__LegsJoints__Sequence
{
  hexapod_msgs__msg__LegsJoints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_msgs__msg__LegsJoints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__STRUCT_H_
