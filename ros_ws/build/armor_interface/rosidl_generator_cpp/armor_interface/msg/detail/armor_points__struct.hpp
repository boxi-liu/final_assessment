// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__STRUCT_HPP_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armor_interface__msg__ArmorPoints __attribute__((deprecated))
#else
# define DEPRECATED__armor_interface__msg__ArmorPoints __declspec(deprecated)
#endif

namespace armor_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmorPoints_
{
  using Type = ArmorPoints_<ContainerAllocator>;

  explicit ArmorPoints_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_top_x = 0l;
      this->left_top_y = 0l;
      this->left_bottom_x = 0l;
      this->left_bottom_y = 0l;
      this->right_bottom_x = 0l;
      this->right_bottom_y = 0l;
      this->right_top_x = 0l;
      this->right_top_y = 0l;
    }
  }

  explicit ArmorPoints_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_top_x = 0l;
      this->left_top_y = 0l;
      this->left_bottom_x = 0l;
      this->left_bottom_y = 0l;
      this->right_bottom_x = 0l;
      this->right_bottom_y = 0l;
      this->right_top_x = 0l;
      this->right_top_y = 0l;
    }
  }

  // field types and members
  using _left_top_x_type =
    int32_t;
  _left_top_x_type left_top_x;
  using _left_top_y_type =
    int32_t;
  _left_top_y_type left_top_y;
  using _left_bottom_x_type =
    int32_t;
  _left_bottom_x_type left_bottom_x;
  using _left_bottom_y_type =
    int32_t;
  _left_bottom_y_type left_bottom_y;
  using _right_bottom_x_type =
    int32_t;
  _right_bottom_x_type right_bottom_x;
  using _right_bottom_y_type =
    int32_t;
  _right_bottom_y_type right_bottom_y;
  using _right_top_x_type =
    int32_t;
  _right_top_x_type right_top_x;
  using _right_top_y_type =
    int32_t;
  _right_top_y_type right_top_y;

  // setters for named parameter idiom
  Type & set__left_top_x(
    const int32_t & _arg)
  {
    this->left_top_x = _arg;
    return *this;
  }
  Type & set__left_top_y(
    const int32_t & _arg)
  {
    this->left_top_y = _arg;
    return *this;
  }
  Type & set__left_bottom_x(
    const int32_t & _arg)
  {
    this->left_bottom_x = _arg;
    return *this;
  }
  Type & set__left_bottom_y(
    const int32_t & _arg)
  {
    this->left_bottom_y = _arg;
    return *this;
  }
  Type & set__right_bottom_x(
    const int32_t & _arg)
  {
    this->right_bottom_x = _arg;
    return *this;
  }
  Type & set__right_bottom_y(
    const int32_t & _arg)
  {
    this->right_bottom_y = _arg;
    return *this;
  }
  Type & set__right_top_x(
    const int32_t & _arg)
  {
    this->right_top_x = _arg;
    return *this;
  }
  Type & set__right_top_y(
    const int32_t & _arg)
  {
    this->right_top_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armor_interface::msg::ArmorPoints_<ContainerAllocator> *;
  using ConstRawPtr =
    const armor_interface::msg::ArmorPoints_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armor_interface::msg::ArmorPoints_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armor_interface::msg::ArmorPoints_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armor_interface__msg__ArmorPoints
    std::shared_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armor_interface__msg__ArmorPoints
    std::shared_ptr<armor_interface::msg::ArmorPoints_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmorPoints_ & other) const
  {
    if (this->left_top_x != other.left_top_x) {
      return false;
    }
    if (this->left_top_y != other.left_top_y) {
      return false;
    }
    if (this->left_bottom_x != other.left_bottom_x) {
      return false;
    }
    if (this->left_bottom_y != other.left_bottom_y) {
      return false;
    }
    if (this->right_bottom_x != other.right_bottom_x) {
      return false;
    }
    if (this->right_bottom_y != other.right_bottom_y) {
      return false;
    }
    if (this->right_top_x != other.right_top_x) {
      return false;
    }
    if (this->right_top_y != other.right_top_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmorPoints_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmorPoints_

// alias to use template instance with default allocator
using ArmorPoints =
  armor_interface::msg::ArmorPoints_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace armor_interface

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__STRUCT_HPP_
