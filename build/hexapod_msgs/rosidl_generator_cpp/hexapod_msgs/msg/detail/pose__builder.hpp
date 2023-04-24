// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_msgs:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__POSE__BUILDER_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_msgs/msg/detail/pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_msgs
{

namespace msg
{

namespace builder
{

class Init_Pose_orientation
{
public:
  explicit Init_Pose_orientation(::hexapod_msgs::msg::Pose & msg)
  : msg_(msg)
  {}
  ::hexapod_msgs::msg::Pose orientation(::hexapod_msgs::msg::Pose::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_msgs::msg::Pose msg_;
};

class Init_Pose_position
{
public:
  Init_Pose_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pose_orientation position(::hexapod_msgs::msg::Pose::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Pose_orientation(msg_);
  }

private:
  ::hexapod_msgs::msg::Pose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_msgs::msg::Pose>()
{
  return hexapod_msgs::msg::builder::Init_Pose_position();
}

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__POSE__BUILDER_HPP_
