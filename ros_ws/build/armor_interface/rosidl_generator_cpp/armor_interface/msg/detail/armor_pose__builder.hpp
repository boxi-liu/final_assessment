// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armor_interface:msg/ArmorPose.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POSE__BUILDER_HPP_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armor_interface/msg/detail/armor_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armor_interface
{

namespace msg
{

namespace builder
{

class Init_ArmorPose_roll
{
public:
  explicit Init_ArmorPose_roll(::armor_interface::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  ::armor_interface::msg::ArmorPose roll(::armor_interface::msg::ArmorPose::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armor_interface::msg::ArmorPose msg_;
};

class Init_ArmorPose_yaw
{
public:
  explicit Init_ArmorPose_yaw(::armor_interface::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  Init_ArmorPose_roll yaw(::armor_interface::msg::ArmorPose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_ArmorPose_roll(msg_);
  }

private:
  ::armor_interface::msg::ArmorPose msg_;
};

class Init_ArmorPose_pitch
{
public:
  explicit Init_ArmorPose_pitch(::armor_interface::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  Init_ArmorPose_yaw pitch(::armor_interface::msg::ArmorPose::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_ArmorPose_yaw(msg_);
  }

private:
  ::armor_interface::msg::ArmorPose msg_;
};

class Init_ArmorPose_z
{
public:
  explicit Init_ArmorPose_z(::armor_interface::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  Init_ArmorPose_pitch z(::armor_interface::msg::ArmorPose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_ArmorPose_pitch(msg_);
  }

private:
  ::armor_interface::msg::ArmorPose msg_;
};

class Init_ArmorPose_y
{
public:
  explicit Init_ArmorPose_y(::armor_interface::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  Init_ArmorPose_z y(::armor_interface::msg::ArmorPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ArmorPose_z(msg_);
  }

private:
  ::armor_interface::msg::ArmorPose msg_;
};

class Init_ArmorPose_x
{
public:
  Init_ArmorPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmorPose_y x(::armor_interface::msg::ArmorPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ArmorPose_y(msg_);
  }

private:
  ::armor_interface::msg::ArmorPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armor_interface::msg::ArmorPose>()
{
  return armor_interface::msg::builder::Init_ArmorPose_x();
}

}  // namespace armor_interface

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POSE__BUILDER_HPP_
