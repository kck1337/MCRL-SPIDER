// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hexapod_msgs:msg/RPY.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__RPY__TRAITS_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__RPY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hexapod_msgs/msg/detail/rpy__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hexapod_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RPY & msg,
  std::ostream & out)
{
  out << "{";
  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RPY & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RPY & msg, bool use_flow_style = false)
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
  const hexapod_msgs::msg::RPY & msg,
  std::ostream & out, size_t indentation = 0)
{
  hexapod_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hexapod_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hexapod_msgs::msg::RPY & msg)
{
  return hexapod_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hexapod_msgs::msg::RPY>()
{
  return "hexapod_msgs::msg::RPY";
}

template<>
inline const char * name<hexapod_msgs::msg::RPY>()
{
  return "hexapod_msgs/msg/RPY";
}

template<>
struct has_fixed_size<hexapod_msgs::msg::RPY>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hexapod_msgs::msg::RPY>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hexapod_msgs::msg::RPY>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HEXAPOD_MSGS__MSG__DETAIL__RPY__TRAITS_HPP_
