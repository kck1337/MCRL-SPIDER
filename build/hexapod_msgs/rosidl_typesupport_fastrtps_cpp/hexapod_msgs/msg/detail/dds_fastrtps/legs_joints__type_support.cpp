// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice
#include "hexapod_msgs/msg/detail/legs_joints__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hexapod_msgs/msg/detail/legs_joints__struct.hpp"

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
bool cdr_serialize(
  const hexapod_msgs::msg::LegJoints &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  hexapod_msgs::msg::LegJoints &);
size_t get_serialized_size(
  const hexapod_msgs::msg::LegJoints &,
  size_t current_alignment);
size_t
max_serialized_size_LegJoints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace hexapod_msgs


namespace hexapod_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
cdr_serialize(
  const hexapod_msgs::msg::LegsJoints & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: leg
  {
    for (size_t i = 0; i < 6; i++) {
      hexapod_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.leg[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hexapod_msgs::msg::LegsJoints & ros_message)
{
  // Member: leg
  {
    for (size_t i = 0; i < 6; i++) {
      hexapod_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.leg[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
get_serialized_size(
  const hexapod_msgs::msg::LegsJoints & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: leg
  {
    size_t array_size = 6;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        hexapod_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.leg[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hexapod_msgs
max_serialized_size_LegsJoints(
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


  // Member: leg
  {
    size_t array_size = 6;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        hexapod_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_LegJoints(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _LegsJoints__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hexapod_msgs::msg::LegsJoints *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LegsJoints__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hexapod_msgs::msg::LegsJoints *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LegsJoints__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hexapod_msgs::msg::LegsJoints *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LegsJoints__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LegsJoints(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LegsJoints__callbacks = {
  "hexapod_msgs::msg",
  "LegsJoints",
  _LegsJoints__cdr_serialize,
  _LegsJoints__cdr_deserialize,
  _LegsJoints__get_serialized_size,
  _LegsJoints__max_serialized_size
};

static rosidl_message_type_support_t _LegsJoints__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LegsJoints__callbacks,
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
get_message_type_support_handle<hexapod_msgs::msg::LegsJoints>()
{
  return &hexapod_msgs::msg::typesupport_fastrtps_cpp::_LegsJoints__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hexapod_msgs, msg, LegsJoints)() {
  return &hexapod_msgs::msg::typesupport_fastrtps_cpp::_LegsJoints__handle;
}

#ifdef __cplusplus
}
#endif
