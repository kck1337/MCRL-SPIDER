// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_msgs:msg/RPY.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__RPY__STRUCT_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__RPY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hexapod_msgs__msg__RPY __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_msgs__msg__RPY __declspec(deprecated)
#endif

namespace hexapod_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RPY_
{
  using Type = RPY_<ContainerAllocator>;

  explicit RPY_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit RPY_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_msgs::msg::RPY_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_msgs::msg::RPY_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::RPY_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::RPY_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_msgs__msg__RPY
    std::shared_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_msgs__msg__RPY
    std::shared_ptr<hexapod_msgs::msg::RPY_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RPY_ & other) const
  {
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const RPY_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RPY_

// alias to use template instance with default allocator
using RPY =
  hexapod_msgs::msg::RPY_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__RPY__STRUCT_HPP_
