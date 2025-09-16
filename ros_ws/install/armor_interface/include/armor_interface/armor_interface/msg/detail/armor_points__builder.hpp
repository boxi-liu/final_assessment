// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__BUILDER_HPP_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armor_interface/msg/detail/armor_points__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armor_interface
{

namespace msg
{

namespace builder
{

class Init_ArmorPoints_right_top_y
{
public:
  explicit Init_ArmorPoints_right_top_y(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  ::armor_interface::msg::ArmorPoints right_top_y(::armor_interface::msg::ArmorPoints::_right_top_y_type arg)
  {
    msg_.right_top_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_right_top_x
{
public:
  explicit Init_ArmorPoints_right_top_x(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  Init_ArmorPoints_right_top_y right_top_x(::armor_interface::msg::ArmorPoints::_right_top_x_type arg)
  {
    msg_.right_top_x = std::move(arg);
    return Init_ArmorPoints_right_top_y(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_right_bottom_y
{
public:
  explicit Init_ArmorPoints_right_bottom_y(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  Init_ArmorPoints_right_top_x right_bottom_y(::armor_interface::msg::ArmorPoints::_right_bottom_y_type arg)
  {
    msg_.right_bottom_y = std::move(arg);
    return Init_ArmorPoints_right_top_x(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_right_bottom_x
{
public:
  explicit Init_ArmorPoints_right_bottom_x(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  Init_ArmorPoints_right_bottom_y right_bottom_x(::armor_interface::msg::ArmorPoints::_right_bottom_x_type arg)
  {
    msg_.right_bottom_x = std::move(arg);
    return Init_ArmorPoints_right_bottom_y(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_left_bottom_y
{
public:
  explicit Init_ArmorPoints_left_bottom_y(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  Init_ArmorPoints_right_bottom_x left_bottom_y(::armor_interface::msg::ArmorPoints::_left_bottom_y_type arg)
  {
    msg_.left_bottom_y = std::move(arg);
    return Init_ArmorPoints_right_bottom_x(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_left_bottom_x
{
public:
  explicit Init_ArmorPoints_left_bottom_x(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  Init_ArmorPoints_left_bottom_y left_bottom_x(::armor_interface::msg::ArmorPoints::_left_bottom_x_type arg)
  {
    msg_.left_bottom_x = std::move(arg);
    return Init_ArmorPoints_left_bottom_y(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_left_top_y
{
public:
  explicit Init_ArmorPoints_left_top_y(::armor_interface::msg::ArmorPoints & msg)
  : msg_(msg)
  {}
  Init_ArmorPoints_left_bottom_x left_top_y(::armor_interface::msg::ArmorPoints::_left_top_y_type arg)
  {
    msg_.left_top_y = std::move(arg);
    return Init_ArmorPoints_left_bottom_x(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

class Init_ArmorPoints_left_top_x
{
public:
  Init_ArmorPoints_left_top_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmorPoints_left_top_y left_top_x(::armor_interface::msg::ArmorPoints::_left_top_x_type arg)
  {
    msg_.left_top_x = std::move(arg);
    return Init_ArmorPoints_left_top_y(msg_);
  }

private:
  ::armor_interface::msg::ArmorPoints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armor_interface::msg::ArmorPoints>()
{
  return armor_interface::msg::builder::Init_ArmorPoints_left_top_x();
}

}  // namespace armor_interface

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__BUILDER_HPP_
