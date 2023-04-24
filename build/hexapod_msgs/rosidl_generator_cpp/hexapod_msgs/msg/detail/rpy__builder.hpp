// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_msgs:msg/RPY.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__RPY__BUILDER_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__RPY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_msgs/msg/detail/rpy__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_msgs
{

namespace msg
{

namespace builder
{

class Init_RPY_yaw
{
public:
  explicit Init_RPY_yaw(::hexapod_msgs::msg::RPY & msg)
  : msg_(msg)
  {}
  ::hexapod_msgs::msg::RPY yaw(::hexapod_msgs::msg::RPY::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_msgs::msg::RPY msg_;
};

class Init_RPY_pitch
{
public:
  explicit Init_RPY_pitch(::hexapod_msgs::msg::RPY & msg)
  : msg_(msg)
  {}
  Init_RPY_yaw pitch(::hexapod_msgs::msg::RPY::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_RPY_yaw(msg_);
  }

private:
  ::hexapod_msgs::msg::RPY msg_;
};

class Init_RPY_roll
{
public:
  Init_RPY_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RPY_pitch roll(::hexapod_msgs::msg::RPY::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_RPY_pitch(msg_);
  }

private:
  ::hexapod_msgs::msg::RPY msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_msgs::msg::RPY>()
{
  return hexapod_msgs::msg::builder::Init_RPY_roll();
}

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__RPY__BUILDER_HPP_
