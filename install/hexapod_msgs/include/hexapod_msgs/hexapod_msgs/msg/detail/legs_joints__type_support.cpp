// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hexapod_msgs/msg/detail/legs_joints__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hexapod_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LegsJoints_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hexapod_msgs::msg::LegsJoints(_init);
}

void LegsJoints_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hexapod_msgs::msg::LegsJoints *>(message_memory);
  typed_message->~LegsJoints();
}

size_t size_function__LegsJoints__leg(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__LegsJoints__leg(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<hexapod_msgs::msg::LegJoints, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__LegsJoints__leg(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<hexapod_msgs::msg::LegJoints, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__LegsJoints__leg(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const hexapod_msgs::msg::LegJoints *>(
    get_const_function__LegsJoints__leg(untyped_member, index));
  auto & value = *reinterpret_cast<hexapod_msgs::msg::LegJoints *>(untyped_value);
  value = item;
}

void assign_function__LegsJoints__leg(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<hexapod_msgs::msg::LegJoints *>(
    get_function__LegsJoints__leg(untyped_member, index));
  const auto & value = *reinterpret_cast<const hexapod_msgs::msg::LegJoints *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LegsJoints_message_member_array[1] = {
  {
    "leg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<hexapod_msgs::msg::LegJoints>(),  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(hexapod_msgs::msg::LegsJoints, leg),  // bytes offset in struct
    nullptr,  // default value
    size_function__LegsJoints__leg,  // size() function pointer
    get_const_function__LegsJoints__leg,  // get_const(index) function pointer
    get_function__LegsJoints__leg,  // get(index) function pointer
    fetch_function__LegsJoints__leg,  // fetch(index, &value) function pointer
    assign_function__LegsJoints__leg,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LegsJoints_message_members = {
  "hexapod_msgs::msg",  // message namespace
  "LegsJoints",  // message name
  1,  // number of fields
  sizeof(hexapod_msgs::msg::LegsJoints),
  LegsJoints_message_member_array,  // message members
  LegsJoints_init_function,  // function to initialize message memory (memory has to be allocated)
  LegsJoints_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LegsJoints_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LegsJoints_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hexapod_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hexapod_msgs::msg::LegsJoints>()
{
  return &::hexapod_msgs::msg::rosidl_typesupport_introspection_cpp::LegsJoints_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hexapod_msgs, msg, LegsJoints)() {
  return &::hexapod_msgs::msg::rosidl_typesupport_introspection_cpp::LegsJoints_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
