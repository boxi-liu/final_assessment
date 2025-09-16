// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__TRAITS_HPP_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "armor_interface/msg/detail/armor_points__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace armor_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmorPoints & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_top_x
  {
    out << "left_top_x: ";
    rosidl_generator_traits::value_to_yaml(msg.left_top_x, out);
    out << ", ";
  }

  // member: left_top_y
  {
    out << "left_top_y: ";
    rosidl_generator_traits::value_to_yaml(msg.left_top_y, out);
    out << ", ";
  }

  // member: left_bottom_x
  {
    out << "left_bottom_x: ";
    rosidl_generator_traits::value_to_yaml(msg.left_bottom_x, out);
    out << ", ";
  }

  // member: left_bottom_y
  {
    out << "left_bottom_y: ";
    rosidl_generator_traits::value_to_yaml(msg.left_bottom_y, out);
    out << ", ";
  }

  // member: right_bottom_x
  {
    out << "right_bottom_x: ";
    rosidl_generator_traits::value_to_yaml(msg.right_bottom_x, out);
    out << ", ";
  }

  // member: right_bottom_y
  {
    out << "right_bottom_y: ";
    rosidl_generator_traits::value_to_yaml(msg.right_bottom_y, out);
    out << ", ";
  }

  // member: right_top_x
  {
    out << "right_top_x: ";
    rosidl_generator_traits::value_to_yaml(msg.right_top_x, out);
    out << ", ";
  }

  // member: right_top_y
  {
    out << "right_top_y: ";
    rosidl_generator_traits::value_to_yaml(msg.right_top_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmorPoints & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_top_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_top_x: ";
    rosidl_generator_traits::value_to_yaml(msg.left_top_x, out);
    out << "\n";
  }

  // member: left_top_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_top_y: ";
    rosidl_generator_traits::value_to_yaml(msg.left_top_y, out);
    out << "\n";
  }

  // member: left_bottom_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_bottom_x: ";
    rosidl_generator_traits::value_to_yaml(msg.left_bottom_x, out);
    out << "\n";
  }

  // member: left_bottom_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_bottom_y: ";
    rosidl_generator_traits::value_to_yaml(msg.left_bottom_y, out);
    out << "\n";
  }

  // member: right_bottom_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_bottom_x: ";
    rosidl_generator_traits::value_to_yaml(msg.right_bottom_x, out);
    out << "\n";
  }

  // member: right_bottom_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_bottom_y: ";
    rosidl_generator_traits::value_to_yaml(msg.right_bottom_y, out);
    out << "\n";
  }

  // member: right_top_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_top_x: ";
    rosidl_generator_traits::value_to_yaml(msg.right_top_x, out);
    out << "\n";
  }

  // member: right_top_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_top_y: ";
    rosidl_generator_traits::value_to_yaml(msg.right_top_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmorPoints & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace armor_interface

namespace rosidl_generator_traits
{

[[deprecated("use armor_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armor_interface::msg::ArmorPoints & msg,
  std::ostream & out, size_t indentation = 0)
{
  armor_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armor_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const armor_interface::msg::ArmorPoints & msg)
{
  return armor_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<armor_interface::msg::ArmorPoints>()
{
  return "armor_interface::msg::ArmorPoints";
}

template<>
inline const char * name<armor_interface::msg::ArmorPoints>()
{
  return "armor_interface/msg/ArmorPoints";
}

template<>
struct has_fixed_size<armor_interface::msg::ArmorPoints>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<armor_interface::msg::ArmorPoints>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<armor_interface::msg::ArmorPoints>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__TRAITS_HPP_
