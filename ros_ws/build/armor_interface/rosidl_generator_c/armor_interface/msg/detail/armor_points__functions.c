// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armor_interface:msg/ArmorPoints.idl
// generated code does not contain a copyright notice
#include "armor_interface/msg/detail/armor_points__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
armor_interface__msg__ArmorPoints__init(armor_interface__msg__ArmorPoints * msg)
{
  if (!msg) {
    return false;
  }
  // left_top_x
  // left_top_y
  // left_bottom_x
  // left_bottom_y
  // right_bottom_x
  // right_bottom_y
  // right_top_x
  // right_top_y
  return true;
}

void
armor_interface__msg__ArmorPoints__fini(armor_interface__msg__ArmorPoints * msg)
{
  if (!msg) {
    return;
  }
  // left_top_x
  // left_top_y
  // left_bottom_x
  // left_bottom_y
  // right_bottom_x
  // right_bottom_y
  // right_top_x
  // right_top_y
}

bool
armor_interface__msg__ArmorPoints__are_equal(const armor_interface__msg__ArmorPoints * lhs, const armor_interface__msg__ArmorPoints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_top_x
  if (lhs->left_top_x != rhs->left_top_x) {
    return false;
  }
  // left_top_y
  if (lhs->left_top_y != rhs->left_top_y) {
    return false;
  }
  // left_bottom_x
  if (lhs->left_bottom_x != rhs->left_bottom_x) {
    return false;
  }
  // left_bottom_y
  if (lhs->left_bottom_y != rhs->left_bottom_y) {
    return false;
  }
  // right_bottom_x
  if (lhs->right_bottom_x != rhs->right_bottom_x) {
    return false;
  }
  // right_bottom_y
  if (lhs->right_bottom_y != rhs->right_bottom_y) {
    return false;
  }
  // right_top_x
  if (lhs->right_top_x != rhs->right_top_x) {
    return false;
  }
  // right_top_y
  if (lhs->right_top_y != rhs->right_top_y) {
    return false;
  }
  return true;
}

bool
armor_interface__msg__ArmorPoints__copy(
  const armor_interface__msg__ArmorPoints * input,
  armor_interface__msg__ArmorPoints * output)
{
  if (!input || !output) {
    return false;
  }
  // left_top_x
  output->left_top_x = input->left_top_x;
  // left_top_y
  output->left_top_y = input->left_top_y;
  // left_bottom_x
  output->left_bottom_x = input->left_bottom_x;
  // left_bottom_y
  output->left_bottom_y = input->left_bottom_y;
  // right_bottom_x
  output->right_bottom_x = input->right_bottom_x;
  // right_bottom_y
  output->right_bottom_y = input->right_bottom_y;
  // right_top_x
  output->right_top_x = input->right_top_x;
  // right_top_y
  output->right_top_y = input->right_top_y;
  return true;
}

armor_interface__msg__ArmorPoints *
armor_interface__msg__ArmorPoints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armor_interface__msg__ArmorPoints * msg = (armor_interface__msg__ArmorPoints *)allocator.allocate(sizeof(armor_interface__msg__ArmorPoints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armor_interface__msg__ArmorPoints));
  bool success = armor_interface__msg__ArmorPoints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armor_interface__msg__ArmorPoints__destroy(armor_interface__msg__ArmorPoints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armor_interface__msg__ArmorPoints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armor_interface__msg__ArmorPoints__Sequence__init(armor_interface__msg__ArmorPoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armor_interface__msg__ArmorPoints * data = NULL;

  if (size) {
    data = (armor_interface__msg__ArmorPoints *)allocator.zero_allocate(size, sizeof(armor_interface__msg__ArmorPoints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armor_interface__msg__ArmorPoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armor_interface__msg__ArmorPoints__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
armor_interface__msg__ArmorPoints__Sequence__fini(armor_interface__msg__ArmorPoints__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      armor_interface__msg__ArmorPoints__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

armor_interface__msg__ArmorPoints__Sequence *
armor_interface__msg__ArmorPoints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armor_interface__msg__ArmorPoints__Sequence * array = (armor_interface__msg__ArmorPoints__Sequence *)allocator.allocate(sizeof(armor_interface__msg__ArmorPoints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armor_interface__msg__ArmorPoints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armor_interface__msg__ArmorPoints__Sequence__destroy(armor_interface__msg__ArmorPoints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armor_interface__msg__ArmorPoints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armor_interface__msg__ArmorPoints__Sequence__are_equal(const armor_interface__msg__ArmorPoints__Sequence * lhs, const armor_interface__msg__ArmorPoints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armor_interface__msg__ArmorPoints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armor_interface__msg__ArmorPoints__Sequence__copy(
  const armor_interface__msg__ArmorPoints__Sequence * input,
  armor_interface__msg__ArmorPoints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armor_interface__msg__ArmorPoints);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armor_interface__msg__ArmorPoints * data =
      (armor_interface__msg__ArmorPoints *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armor_interface__msg__ArmorPoints__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armor_interface__msg__ArmorPoints__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armor_interface__msg__ArmorPoints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
