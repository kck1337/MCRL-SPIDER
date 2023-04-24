// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice
#include "hexapod_msgs/msg/detail/leg_joints__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hexapod_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hexapod_msgs/msg/detail/leg_joints__struct.h"
#include "hexapod_msgs/msg/detail/leg_joints__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _LegJoints__ros_msg_type = hexapod_msgs__msg__LegJoints;

static bool _LegJoints__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LegJoints__ros_msg_type * ros_message = static_cast<const _LegJoints__ros_msg_type *>(untyped_ros_message);
  // Field name: coxa
  {
    cdr << ros_message->coxa;
  }

  // Field name: femur
  {
    cdr << ros_message->femur;
  }

  // Field name: tibia
  {
    cdr << ros_message->tibia;
  }

  // Field name: tarsus
  {
    cdr << ros_message->tarsus;
  }

  return true;
}

static bool _LegJoints__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LegJoints__ros_msg_type * ros_message = static_cast<_LegJoints__ros_msg_type *>(untyped_ros_message);
  // Field name: coxa
  {
    cdr >> ros_message->coxa;
  }

  // Field name: femur
  {
    cdr >> ros_message->femur;
  }

  // Field name: tibia
  {
    cdr >> ros_message->tibia;
  }

  // Field name: tarsus
  {
    cdr >> ros_message->tarsus;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hexapod_msgs
size_t get_serialized_size_hexapod_msgs__msg__LegJoints(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LegJoints__ros_msg_type * ros_message = static_cast<const _LegJoints__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name coxa
  {
    size_t item_size = sizeof(ros_message->coxa);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name femur
  {
    size_t item_size = sizeof(ros_message->femur);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tibia
  {
    size_t item_size = sizeof(ros_message->tibia);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tarsus
  {
    size_t item_size = sizeof(ros_message->tarsus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LegJoints__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hexapod_msgs__msg__LegJoints(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hexapod_msgs
size_t max_serialized_size_hexapod_msgs__msg__LegJoints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: coxa
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: femur
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tibia
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tarsus
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LegJoints__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hexapod_msgs__msg__LegJoints(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LegJoints = {
  "hexapod_msgs::msg",
  "LegJoints",
  _LegJoints__cdr_serialize,
  _LegJoints__cdr_deserialize,
  _LegJoints__get_serialized_size,
  _LegJoints__max_serialized_size
};

static rosidl_message_type_support_t _LegJoints__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LegJoints,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hexapod_msgs, msg, LegJoints)() {
  return &_LegJoints__type_support;
}

#if defined(__cplusplus)
}
#endif
