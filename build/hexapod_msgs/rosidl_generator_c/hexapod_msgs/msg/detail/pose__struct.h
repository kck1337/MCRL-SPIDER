// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_msgs:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__POSE__STRUCT_H_
#define HEXAPOD_MSGS__MSG__DETAIL__POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'orientation'
#include "hexapod_msgs/msg/detail/rpy__struct.h"

/// Struct defined in msg/Pose in the package hexapod_msgs.
typedef struct hexapod_msgs__msg__Pose
{
  geometry_msgs__msg__Point position;
  hexapod_msgs__msg__RPY orientation;
} hexapod_msgs__msg__Pose;

// Struct for a sequence of hexapod_msgs__msg__Pose.
typedef struct hexapod_msgs__msg__Pose__Sequence
{
  hexapod_msgs__msg__Pose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_msgs__msg__Pose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_MSGS__MSG__DETAIL__POSE__STRUCT_H_
