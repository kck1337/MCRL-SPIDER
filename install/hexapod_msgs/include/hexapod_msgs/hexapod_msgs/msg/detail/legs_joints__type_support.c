// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hexapod_msgs/msg/detail/legs_joints__rosidl_typesupport_introspection_c.h"
#include "hexapod_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hexapod_msgs/msg/detail/legs_joints__functions.h"
#include "hexapod_msgs/msg/detail/legs_joints__struct.h"


// Include directives for member types
// Member `leg`
#include "hexapod_msgs/msg/leg_joints.h"
// Member `leg`
#include "hexapod_msgs/msg/detail/leg_joints__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hexapod_msgs__msg__LegsJoints__init(message_memory);
}

void hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_fini_function(void * message_memory)
{
  hexapod_msgs__msg__LegsJoints__fini(message_memory);
}

size_t hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__size_function__LegsJoints__leg(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__get_const_function__LegsJoints__leg(
  const void * untyped_member, size_t index)
{
  const hexapod_msgs__msg__LegJoints * member =
    (const hexapod_msgs__msg__LegJoints *)(untyped_member);
  return &member[index];
}

void * hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__get_function__LegsJoints__leg(
  void * untyped_member, size_t index)
{
  hexapod_msgs__msg__LegJoints * member =
    (hexapod_msgs__msg__LegJoints *)(untyped_member);
  return &member[index];
}

void hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__fetch_function__LegsJoints__leg(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const hexapod_msgs__msg__LegJoints * item =
    ((const hexapod_msgs__msg__LegJoints *)
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__get_const_function__LegsJoints__leg(untyped_member, index));
  hexapod_msgs__msg__LegJoints * value =
    (hexapod_msgs__msg__LegJoints *)(untyped_value);
  *value = *item;
}

void hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__assign_function__LegsJoints__leg(
  void * untyped_member, size_t index, const void * untyped_value)
{
  hexapod_msgs__msg__LegJoints * item =
    ((hexapod_msgs__msg__LegJoints *)
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__get_function__LegsJoints__leg(untyped_member, index));
  const hexapod_msgs__msg__LegJoints * value =
    (const hexapod_msgs__msg__LegJoints *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_member_array[1] = {
  {
    "leg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(hexapod_msgs__msg__LegsJoints, leg),  // bytes offset in struct
    NULL,  // default value
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__size_function__LegsJoints__leg,  // size() function pointer
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__get_const_function__LegsJoints__leg,  // get_const(index) function pointer
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__get_function__LegsJoints__leg,  // get(index) function pointer
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__fetch_function__LegsJoints__leg,  // fetch(index, &value) function pointer
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__assign_function__LegsJoints__leg,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_members = {
  "hexapod_msgs__msg",  // message namespace
  "LegsJoints",  // message name
  1,  // number of fields
  sizeof(hexapod_msgs__msg__LegsJoints),
  hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_member_array,  // message members
  hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_init_function,  // function to initialize message memory (memory has to be allocated)
  hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_type_support_handle = {
  0,
  &hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hexapod_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hexapod_msgs, msg, LegsJoints)() {
  hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hexapod_msgs, msg, LegJoints)();
  if (!hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_type_support_handle.typesupport_identifier) {
    hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &hexapod_msgs__msg__LegsJoints__rosidl_typesupport_introspection_c__LegsJoints_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
