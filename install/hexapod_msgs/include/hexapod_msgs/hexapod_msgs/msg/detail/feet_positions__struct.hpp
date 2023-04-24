// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hexapod_msgs:msg/FeetPositions.idl
// generated code does not contain a copyright notice

#ifndef HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__STRUCT_HPP_
#define HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'foot'
#include "hexapod_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hexapod_msgs__msg__FeetPositions __attribute__((deprecated))
#else
# define DEPRECATED__hexapod_msgs__msg__FeetPositions __declspec(deprecated)
#endif

namespace hexapod_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FeetPositions_
{
  using Type = FeetPositions_<ContainerAllocator>;

  explicit FeetPositions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->foot.fill(hexapod_msgs::msg::Pose_<ContainerAllocator>{_init});
    }
  }

  explicit FeetPositions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : foot(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->foot.fill(hexapod_msgs::msg::Pose_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _foot_type =
    std::array<hexapod_msgs::msg::Pose_<ContainerAllocator>, 6>;
  _foot_type foot;

  // setters for named parameter idiom
  Type & set__foot(
    const std::array<hexapod_msgs::msg::Pose_<ContainerAllocator>, 6> & _arg)
  {
    this->foot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hexapod_msgs::msg::FeetPositions_<ContainerAllocator> *;
  using ConstRawPtr =
    const hexapod_msgs::msg::FeetPositions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::FeetPositions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hexapod_msgs::msg::FeetPositions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hexapod_msgs__msg__FeetPositions
    std::shared_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hexapod_msgs__msg__FeetPositions
    std::shared_ptr<hexapod_msgs::msg::FeetPositions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeetPositions_ & other) const
  {
    if (this->foot != other.foot) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeetPositions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeetPositions_

// alias to use template instance with default allocator
using FeetPositions =
  hexapod_msgs::msg::FeetPositions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hexapod_msgs

#endif  // HEXAPOD_MSGS__MSG__DETAIL__FEET_POSITIONS__STRUCT_HPP_
