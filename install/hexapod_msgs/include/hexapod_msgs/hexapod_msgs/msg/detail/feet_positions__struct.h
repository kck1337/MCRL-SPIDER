// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_msgs:msg/FeetPositions.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__STRUCT_H_
#define HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'foot'
#include "hexapod_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/FeetPositions in the package hexapod_msgs.
typedef struct hexapod_msgs__msg__FeetPositions
{
  hexapod_msgs__msg__Pose foot[6];
} hexapod_msgs__msg__FeetPositions;

// Struct for a sequence of hexapod_msgs__msg__FeetPositions.
typedef struct hexapod_msgs__msg__FeetPositions__Sequence
{
  hexapod_msgs__msg__FeetPositions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_msgs__msg__FeetPositions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__STRUCT_H_
