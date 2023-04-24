// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_msgs:msg/FeetPositions.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__BUILDER_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_msgs/msg/detail/feet_positions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_msgs
{

namespace msg
{

namespace builder
{

class Init_FeetPositions_foot
{
public:
  Init_FeetPositions_foot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hexapod_msgs::msg::FeetPositions foot(::hexapod_msgs::msg::FeetPositions::_foot_type arg)
  {
    msg_.foot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_msgs::msg::FeetPositions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_msgs::msg::FeetPositions>()
{
  return hexapod_msgs::msg::builder::Init_FeetPositions_foot();
}

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__BUILDER_HPP_
