// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__BUILDER_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hexapod_msgs/msg/detail/leg_joints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hexapod_msgs
{

namespace msg
{

namespace builder
{

class Init_LegJoints_tarsus
{
public:
  explicit Init_LegJoints_tarsus(::hexapod_msgs::msg::LegJoints & msg)
  : msg_(msg)
  {}
  ::hexapod_msgs::msg::LegJoints tarsus(::hexapod_msgs::msg::LegJoints::_tarsus_type arg)
  {
    msg_.tarsus = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hexapod_msgs::msg::LegJoints msg_;
};

class Init_LegJoints_tibia
{
public:
  explicit Init_LegJoints_tibia(::hexapod_msgs::msg::LegJoints & msg)
  : msg_(msg)
  {}
  Init_LegJoints_tarsus tibia(::hexapod_msgs::msg::LegJoints::_tibia_type arg)
  {
    msg_.tibia = std::move(arg);
    return Init_LegJoints_tarsus(msg_);
  }

private:
  ::hexapod_msgs::msg::LegJoints msg_;
};

class Init_LegJoints_femur
{
public:
  explicit Init_LegJoints_femur(::hexapod_msgs::msg::LegJoints & msg)
  : msg_(msg)
  {}
  Init_LegJoints_tibia femur(::hexapod_msgs::msg::LegJoints::_femur_type arg)
  {
    msg_.femur = std::move(arg);
    return Init_LegJoints_tibia(msg_);
  }

private:
  ::hexapod_msgs::msg::LegJoints msg_;
};

class Init_LegJoints_coxa
{
public:
  Init_LegJoints_coxa()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LegJoints_femur coxa(::hexapod_msgs::msg::LegJoints::_coxa_type arg)
  {
    msg_.coxa = std::move(arg);
    return Init_LegJoints_femur(msg_);
  }

private:
  ::hexapod_msgs::msg::LegJoints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hexapod_msgs::msg::LegJoints>()
{
  return hexapod_msgs::msg::builder::Init_LegJoints_coxa();
}

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__BUILDER_HPP_
