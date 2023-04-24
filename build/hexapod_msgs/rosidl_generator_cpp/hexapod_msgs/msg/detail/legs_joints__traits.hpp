// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__TRAITS_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hexapod_msgs/msg/detail/legs_joints__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'leg'
#include "hexapod_msgs/msg/detail/leg_joints__traits.hpp"

namespace hexapod_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LegsJoints & msg,
  std::ostream & out)
{
  out << "{";
  // member: leg
  {
    if (msg.leg.size() == 0) {
      out << "leg: []";
    } else {
      out << "leg: [";
      size_t pending_items = msg.leg.size();
      for (auto item : msg.leg) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LegsJoints & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: leg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.leg.size() == 0) {
      out << "leg: []\n";
    } else {
      out << "leg:\n";
      for (auto item : msg.leg) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LegsJoints & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hexapod_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hexapod_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hexapod_msgs::msg::LegsJoints & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_msgs::msg::LegsJoints & msg)
{
  return hexapod_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_msgs::msg::LegsJoints>()
{
  return "hexapod_msgs::msg::LegsJoints";
}

template<>
inline const char * name<hexapod_msgs::msg::LegsJoints>()
{
  return "hexapod_msgs/msg/LegsJoints";
}

template<>
struct has_fixed_size<hexapod_msgs::msg::LegsJoints>
  : std::integral_constant<bool, has_fixed_size<hexapod_msgs::msg::LegJoints>::value> {};

template<>
struct has_bounded_size<hexapod_msgs::msg::LegsJoints>
  : std::integral_constant<bool, has_bounded_size<hexapod_msgs::msg::LegJoints>::value> {};

template<>
struct is_message<hexapod_msgs::msg::LegsJoints>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__TRAITS_HPP_
