// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hexapod_msgs:msg/FeetPositions.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__TRAITS_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hexapod_msgs/msg/detail/feet_positions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'foot'
#include "hexapod_msgs/msg/detail/pose__traits.hpp"

namespace hexapod_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeetPositions & msg,
  std::ostream & out)
{
  out << "{";
  // member: foot
  {
    if (msg.foot.size() == 0) {
      out << "foot: []";
    } else {
      out << "foot: [";
      size_t pending_items = msg.foot.size();
      for (auto item : msg.foot) {
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
  const FeetPositions & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot.size() == 0) {
      out << "foot: []\n";
    } else {
      out << "foot:\n";
      for (auto item : msg.foot) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeetPositions & msg, bool use_flow_style = false)
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
  const hexapod_msgs::msg::FeetPositions & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_msgs::msg::FeetPositions & msg)
{
  return hexapod_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_msgs::msg::FeetPositions>()
{
  return "hexapod_msgs::msg::FeetPositions";
}

template<>
inline const char * name<hexapod_msgs::msg::FeetPositions>()
{
  return "hexapod_msgs/msg/FeetPositions";
}

template<>
struct has_fixed_size<hexapod_msgs::msg::FeetPositions>
  : std::integral_constant<bool, has_fixed_size<hexapod_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<hexapod_msgs::msg::FeetPositions>
  : std::integral_constant<bool, has_bounded_size<hexapod_msgs::msg::Pose>::value> {};

template<>
struct is_message<hexapod_msgs::msg::FeetPositions>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__TRAITS_HPP_
