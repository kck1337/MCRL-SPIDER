// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__BUILDER_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_msgs/msg/detail/legs_joints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_msgs
{

namespace msg
{

namespace builder
{

class Init_LegsJoints_leg
{
public:
  Init_LegsJoints_leg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hexapod_msgs::msg::LegsJoints leg(::hexapod_msgs::msg::LegsJoints::_leg_type arg)
  {
    msg_.leg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_msgs::msg::LegsJoints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_msgs::msg::LegsJoints>()
{
  return hexapod_msgs::msg::builder::Init_LegsJoints_leg();
}

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__BUILDER_HPP_
