// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__STRUCT_H_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ArmorPoints in the package armor_interface.
/**
  * ArmorPoints.msg：装甲板四个角点的坐标（整数类型）
 */
typedef struct armor_interface__msg__ArmorPoints
{
  /// 左上角x坐标
  int32_t left_top_x;
  /// 左上角y坐标
  int32_t left_top_y;
  /// 左下角x坐标
  int32_t left_bottom_x;
  /// 左下角y坐标
  int32_t left_bottom_y;
  /// 右下角x坐标
  int32_t right_bottom_x;
  /// 右下角y坐标
  int32_t right_bottom_y;
  /// 右上角x坐标
  int32_t right_top_x;
  /// 右上角y坐标
  int32_t right_top_y;
} armor_interface__msg__ArmorPoints;

// Struct for a sequence of armor_interface__msg__ArmorPoints.
typedef struct armor_interface__msg__ArmorPoints__Sequence
{
  armor_interface__msg__ArmorPoints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armor_interface__msg__ArmorPoints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__STRUCT_H_
