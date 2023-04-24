// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_msgs:msg/RPY.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__RPY__STRUCT_H_
#define HEXAPOD_MSGS__MSG__DETAIL__RPY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RPY in the package hexapod_msgs.
typedef struct hexapod_msgs__msg__RPY
{
  double roll;
  double pitch;
  double yaw;
} hexapod_msgs__msg__RPY;

// Struct for a sequence of hexapod_msgs__msg__RPY.
typedef struct hexapod_msgs__msg__RPY__Sequence
{
  hexapod_msgs__msg__RPY * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_msgs__msg__RPY__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_MSGS__MSG__DETAIL__RPY__STRUCT_H_
