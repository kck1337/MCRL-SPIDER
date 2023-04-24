// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__STRUCT_H_
#define HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LegJoints in the package hexapod_msgs.
typedef struct hexapod_msgs__msg__LegJoints
{
  double coxa;
  double femur;
  double tibia;
  double tarsus;
} hexapod_msgs__msg__LegJoints;

// Struct for a sequence of hexapod_msgs__msg__LegJoints.
typedef struct hexapod_msgs__msg__LegJoints__Sequence
{
  hexapod_msgs__msg__LegJoints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hexapod_msgs__msg__LegJoints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__STRUCT_H_
