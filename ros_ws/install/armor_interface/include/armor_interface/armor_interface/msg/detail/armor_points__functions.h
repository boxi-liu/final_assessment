// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice

#ifndef ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__FUNCTIONS_H_
#define ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "armor_interface/msg/rosidl_generator_c__visibility_control.h"

#include "armor_interface/msg/detail/armor_points__struct.h"

/// Initialize msg/ArmorPoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * armor_interface__msg__ArmorPoints
 * )) before or use
 * armor_interface__msg__ArmorPoints__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
bool
armor_interface__msg__ArmorPoints__init(armor_interface__msg__ArmorPoints * msg);

/// Finalize msg/ArmorPoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
void
armor_interface__msg__ArmorPoints__fini(armor_interface__msg__ArmorPoints * msg);

/// Create msg/ArmorPoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * armor_interface__msg__ArmorPoints__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
armor_interface__msg__ArmorPoints *
armor_interface__msg__ArmorPoints__create();

/// Destroy msg/ArmorPoints message.
/**
 * It calls
 * armor_interface__msg__ArmorPoints__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
void
armor_interface__msg__ArmorPoints__destroy(armor_interface__msg__ArmorPoints * msg);

/// Check for msg/ArmorPoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
bool
armor_interface__msg__ArmorPoints__are_equal(const armor_interface__msg__ArmorPoints * lhs, const armor_interface__msg__ArmorPoints * rhs);

/// Copy a msg/ArmorPoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
bool
armor_interface__msg__ArmorPoints__copy(
  const armor_interface__msg__ArmorPoints * input,
  armor_interface__msg__ArmorPoints * output);

/// Initialize array of msg/ArmorPoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * armor_interface__msg__ArmorPoints__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
bool
armor_interface__msg__ArmorPoints__Sequence__init(armor_interface__msg__ArmorPoints__Sequence * array, size_t size);

/// Finalize array of msg/ArmorPoints messages.
/**
 * It calls
 * armor_interface__msg__ArmorPoints__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
void
armor_interface__msg__ArmorPoints__Sequence__fini(armor_interface__msg__ArmorPoints__Sequence * array);

/// Create array of msg/ArmorPoints messages.
/**
 * It allocates the memory for the array and calls
 * armor_interface__msg__ArmorPoints__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
armor_interface__msg__ArmorPoints__Sequence *
armor_interface__msg__ArmorPoints__Sequence__create(size_t size);

/// Destroy array of msg/ArmorPoints messages.
/**
 * It calls
 * armor_interface__msg__ArmorPoints__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
void
armor_interface__msg__ArmorPoints__Sequence__destroy(armor_interface__msg__ArmorPoints__Sequence * array);

/// Check for msg/ArmorPoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
bool
armor_interface__msg__ArmorPoints__Sequence__are_equal(const armor_interface__msg__ArmorPoints__Sequence * lhs, const armor_interface__msg__ArmorPoints__Sequence * rhs);

/// Copy an array of msg/ArmorPoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_armor_interface
bool
armor_interface__msg__ArmorPoints__Sequence__copy(
  const armor_interface__msg__ArmorPoints__Sequence * input,
  armor_interface__msg__ArmorPoints__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ARMOR_INTERFACE__MSG__DETAIL__ARMOR_POINTS__FUNCTIONS_H_
