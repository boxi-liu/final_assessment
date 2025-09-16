// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice
#include "armor_interface/msg/detail/armor_points__rosidl_typesupport_fastrtps_cpp.hpp"
#include "armor_interface/msg/detail/armor_points__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace armor_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armor_interface
cdr_serialize(
  const armor_interface::msg::ArmorPoints & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: left_top_x
  cdr << ros_message.left_top_x;
  // Member: left_top_y
  cdr << ros_message.left_top_y;
  // Member: left_bottom_x
  cdr << ros_message.left_bottom_x;
  // Member: left_bottom_y
  cdr << ros_message.left_bottom_y;
  // Member: right_bottom_x
  cdr << ros_message.right_bottom_x;
  // Member: right_bottom_y
  cdr << ros_message.right_bottom_y;
  // Member: right_top_x
  cdr << ros_message.right_top_x;
  // Member: right_top_y
  cdr << ros_message.right_top_y;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armor_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  armor_interface::msg::ArmorPoints & ros_message)
{
  // Member: left_top_x
  cdr >> ros_message.left_top_x;

  // Member: left_top_y
  cdr >> ros_message.left_top_y;

  // Member: left_bottom_x
  cdr >> ros_message.left_bottom_x;

  // Member: left_bottom_y
  cdr >> ros_message.left_bottom_y;

  // Member: right_bottom_x
  cdr >> ros_message.right_bottom_x;

  // Member: right_bottom_y
  cdr >> ros_message.right_bottom_y;

  // Member: right_top_x
  cdr >> ros_message.right_top_x;

  // Member: right_top_y
  cdr >> ros_message.right_top_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armor_interface
get_serialized_size(
  const armor_interface::msg::ArmorPoints & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: left_top_x
  {
    size_t item_size = sizeof(ros_message.left_top_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_top_y
  {
    size_t item_size = sizeof(ros_message.left_top_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_bottom_x
  {
    size_t item_size = sizeof(ros_message.left_bottom_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_bottom_y
  {
    size_t item_size = sizeof(ros_message.left_bottom_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_bottom_x
  {
    size_t item_size = sizeof(ros_message.right_bottom_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_bottom_y
  {
    size_t item_size = sizeof(ros_message.right_bottom_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_top_x
  {
    size_t item_size = sizeof(ros_message.right_top_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_top_y
  {
    size_t item_size = sizeof(ros_message.right_top_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armor_interface
max_serialized_size_ArmorPoints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: left_top_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_top_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_bottom_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_bottom_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_bottom_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_bottom_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_top_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_top_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = armor_interface::msg::ArmorPoints;
    is_plain =
      (
      offsetof(DataType, right_top_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ArmorPoints__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const armor_interface::msg::ArmorPoints *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArmorPoints__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<armor_interface::msg::ArmorPoints *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArmorPoints__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const armor_interface::msg::ArmorPoints *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArmorPoints__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ArmorPoints(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ArmorPoints__callbacks = {
  "armor_interface::msg",
  "ArmorPoints",
  _ArmorPoints__cdr_serialize,
  _ArmorPoints__cdr_deserialize,
  _ArmorPoints__get_serialized_size,
  _ArmorPoints__max_serialized_size
};

static rosidl_message_type_support_t _ArmorPoints__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArmorPoints__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace armor_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_armor_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<armor_interface::msg::ArmorPoints>()
{
  return &armor_interface::msg::typesupport_fastrtps_cpp::_ArmorPoints__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armor_interface, msg, ArmorPoints)() {
  return &armor_interface::msg::typesupport_fastrtps_cpp::_ArmorPoints__handle;
}

#ifdef __cplusplus
}
#endif
