// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice
#include "hexapod_msgs/msg/detail/legs_joints__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hexapod_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hexapod_msgs/msg/detail/legs_joints__struct.h"
#include "hexapod_msgs/msg/detail/legs_joints__functions.h"
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

#include "hexapod_msgs/msg/detail/leg_joints__functions.h"  // leg

// forward declare type support functions
size_t get_serialized_size_hexapod_msgs__msg__LegJoints(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_hexapod_msgs__msg__LegJoints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hexapod_msgs, msg, LegJoints)();


using _LegsJoints__ros_msg_type = hexapod_msgs__msg__LegsJoints;

static bool _LegsJoints__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LegsJoints__ros_msg_type * ros_message = static_cast<const _LegsJoints__ros_msg_type *>(untyped_ros_message);
  // Field name: leg
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, hexapod_msgs, msg, LegJoints
      )()->data);
    size_t size = 6;
    auto array_ptr = ros_message->leg;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _LegsJoints__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LegsJoints__ros_msg_type * ros_message = static_cast<_LegsJoints__ros_msg_type *>(untyped_ros_message);
  // Field name: leg
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, hexapod_msgs, msg, LegJoints
      )()->data);
    size_t size = 6;
    auto array_ptr = ros_message->leg;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hexapod_msgs
size_t get_serialized_size_hexapod_msgs__msg__LegsJoints(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LegsJoints__ros_msg_type * ros_message = static_cast<const _LegsJoints__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name leg
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->leg;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_hexapod_msgs__msg__LegJoints(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LegsJoints__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hexapod_msgs__msg__LegsJoints(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hexapod_msgs
size_t max_serialized_size_hexapod_msgs__msg__LegsJoints(
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

  // member: leg
  {
    size_t array_size = 6;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_hexapod_msgs__msg__LegJoints(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _LegsJoints__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_hexapod_msgs__msg__LegsJoints(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LegsJoints = {
  "hexapod_msgs::msg",
  "LegsJoints",
  _LegsJoints__cdr_serialize,
  _LegsJoints__cdr_deserialize,
  _LegsJoints__get_serialized_size,
  _LegsJoints__max_serialized_size
};

static rosidl_message_type_support_t _LegsJoints__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LegsJoints,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hexapod_msgs, msg, LegsJoints)() {
  return &_LegsJoints__type_support;
}

#if defined(__cplusplus)
}
#endif
