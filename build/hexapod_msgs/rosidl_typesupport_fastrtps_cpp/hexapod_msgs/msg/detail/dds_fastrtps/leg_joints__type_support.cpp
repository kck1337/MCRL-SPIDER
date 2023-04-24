// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice
#include "hexapod_msgs/msg/detail/leg_joints__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hexapod_msgs/msg/detail/leg_joints__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace hexapod_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
cdr_serialize(
  const hexapod_msgs::msg::LegJoints & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: coxa
  cdr << ros_message.coxa;
  // Member: femur
  cdr << ros_message.femur;
  // Member: tibia
  cdr << ros_message.tibia;
  // Member: tarsus
  cdr << ros_message.tarsus;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hexapod_msgs::msg::LegJoints & ros_message)
{
  // Member: coxa
  cdr >> ros_message.coxa;

  // Member: femur
  cdr >> ros_message.femur;

  // Member: tibia
  cdr >> ros_message.tibia;

  // Member: tarsus
  cdr >> ros_message.tarsus;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
get_serialized_size(
  const hexapod_msgs::msg::LegJoints & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: coxa
  {
    size_t item_size = sizeof(ros_message.coxa);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: femur
  {
    size_t item_size = sizeof(ros_message.femur);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tibia
  {
    size_t item_size = sizeof(ros_message.tibia);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tarsus
  {
    size_t item_size = sizeof(ros_message.tarsus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
max_serialized_size_LegJoints(
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


  // Member: coxa
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: femur
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tibia
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tarsus
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LegJoints__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hexapod_msgs::msg::LegJoints *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LegJoints__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hexapod_msgs::msg::LegJoints *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LegJoints__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hexapod_msgs::msg::LegJoints *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LegJoints__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LegJoints(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LegJoints__callbacks = {
  "hexapod_msgs::msg",
  "LegJoints",
  _LegJoints__cdr_serialize,
  _LegJoints__cdr_deserialize,
  _LegJoints__get_serialized_size,
  _LegJoints__max_serialized_size
};

static rosidl_message_type_support_t _LegJoints__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LegJoints__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hexapod_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hexapod_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<hexapod_msgs::msg::LegJoints>()
{
  return &hexapod_msgs::msg::typesupport_fastrtps_cpp::_LegJoints__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hexapod_msgs, msg, LegJoints)() {
  return &hexapod_msgs::msg::typesupport_fastrtps_cpp::_LegJoints__handle;
}

#ifdef __cplusplus
}
#endif
