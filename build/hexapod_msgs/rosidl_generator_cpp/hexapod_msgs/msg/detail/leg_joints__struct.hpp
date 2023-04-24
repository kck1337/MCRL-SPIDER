// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__STRUCT_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hexapod_msgs__msg__LegJoints __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_msgs__msg__LegJoints __declspec(deprecated)
#endif

namespace hexapod_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LegJoints_
{
  using Type = LegJoints_<ContainerAllocator>;

  explicit LegJoints_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->coxa = 0.0;
      this->femur = 0.0;
      this->tibia = 0.0;
      this->tarsus = 0.0;
    }
  }

  explicit LegJoints_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->coxa = 0.0;
      this->femur = 0.0;
      this->tibia = 0.0;
      this->tarsus = 0.0;
    }
  }

  // field types and members
  using _coxa_type =
    double;
  _coxa_type coxa;
  using _femur_type =
    double;
  _femur_type femur;
  using _tibia_type =
    double;
  _tibia_type tibia;
  using _tarsus_type =
    double;
  _tarsus_type tarsus;

  // setters for named parameter idiom
  Type & set__coxa(
    const double & _arg)
  {
    this->coxa = _arg;
    return *this;
  }
  Type & set__femur(
    const double & _arg)
  {
    this->femur = _arg;
    return *this;
  }
  Type & set__tibia(
    const double & _arg)
  {
    this->tibia = _arg;
    return *this;
  }
  Type & set__tarsus(
    const double & _arg)
  {
    this->tarsus = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_msgs::msg::LegJoints_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_msgs::msg::LegJoints_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::LegJoints_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::LegJoints_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_msgs__msg__LegJoints
    std::shared_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_msgs__msg__LegJoints
    std::shared_ptr<hexapod_msgs::msg::LegJoints_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LegJoints_ & other) const
  {
    if (this->coxa != other.coxa) {
      return false;
    }
    if (this->femur != other.femur) {
      return false;
    }
    if (this->tibia != other.tibia) {
      return false;
    }
    if (this->tarsus != other.tarsus) {
      return false;
    }
    return true;
  }
  bool operator!=(const LegJoints_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LegJoints_

// alias to use template instance with default allocator
using LegJoints =
  hexapod_msgs::msg::LegJoints_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEG_JOINTS__STRUCT_HPP_
