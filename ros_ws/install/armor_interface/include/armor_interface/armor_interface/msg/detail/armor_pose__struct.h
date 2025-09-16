// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armor_interface:msg/ArmorPose.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POSE__STRUCT_H_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ArmorPose in the package armor_interface.
/**
  * 装甲板核心姿态消息（仅保留必要参数，无时间戳）
 */
typedef struct armor_interface__msg__ArmorPose
{
  /// 原始/滤波后 X坐标（单位：m）
  double x;
  /// 原始/滤波后 Y坐标（单位：m）
  double y;
  /// 原始/滤波后 Z坐标（单位：m）
  double z;
  /// 原始俯仰角（单位：rad，未滤波）
  double pitch;
  /// 原始/滤波后 偏航角（单位：rad）
  double yaw;
  /// 原始横滚角（单位：rad，未滤波）
  double roll;
} armor_interface__msg__ArmorPose;

// Struct for a sequence of armor_interface__msg__ArmorPose.
typedef struct armor_interface__msg__ArmorPose__Sequence
{
  armor_interface__msg__ArmorPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armor_interface__msg__ArmorPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POSE__STRUCT_H_
