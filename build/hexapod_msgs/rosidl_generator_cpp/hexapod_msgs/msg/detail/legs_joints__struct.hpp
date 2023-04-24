// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__STRUCT_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'leg'
#include "hexapod_msgs/msg/detail/leg_joints__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hexapod_msgs__msg__LegsJoints __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_msgs__msg__LegsJoints __declspec(deprecated)
#endif

namespace hexapod_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LegsJoints_
{
  using Type = LegsJoints_<ContainerAllocator>;

  explicit LegsJoints_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leg.fill(hexapod_msgs::msg::LegJoints_<ContainerAllocator>{_init});
    }
  }

  explicit LegsJoints_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : leg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leg.fill(hexapod_msgs::msg::LegJoints_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _leg_type =
    std::array<hexapod_msgs::msg::LegJoints_<ContainerAllocator>, 6>;
  _leg_type leg;

  // setters for named parameter idiom
  Type & set__leg(
    const std::array<hexapod_msgs::msg::LegJoints_<ContainerAllocator>, 6> & _arg)
  {
    this->leg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_msgs::msg::LegsJoints_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_msgs::msg::LegsJoints_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::LegsJoints_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::LegsJoints_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_msgs__msg__LegsJoints
    std::shared_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_msgs__msg__LegsJoints
    std::shared_ptr<hexapod_msgs::msg::LegsJoints_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LegsJoints_ & other) const
  {
    if (this->leg != other.leg) {
      return false;
    }
    return true;
  }
  bool operator!=(const LegsJoints_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LegsJoints_

// alias to use template instance with default allocator
using LegsJoints =
  hexapod_msgs::msg::LegsJoints_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__LEGS_JOINTS__STRUCT_HPP_
