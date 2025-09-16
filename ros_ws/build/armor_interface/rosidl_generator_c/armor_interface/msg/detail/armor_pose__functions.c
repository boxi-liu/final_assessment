// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armor_interface:msg/ArmorPose.idl
// generated code does not contain a copyright notice
#include "armor_interface/msg/detail/armor_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
armor_interface__msg__ArmorPose__init(armor_interface__msg__ArmorPose * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // pitch
  // yaw
  // roll
  return true;
}

void
armor_interface__msg__ArmorPose__fini(armor_interface__msg__ArmorPose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // pitch
  // yaw
  // roll
}

bool
armor_interface__msg__ArmorPose__are_equal(const armor_interface__msg__ArmorPose * lhs, const armor_interface__msg__ArmorPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  return true;
}

bool
armor_interface__msg__ArmorPose__copy(
  const armor_interface__msg__ArmorPose * input,
  armor_interface__msg__ArmorPose * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // roll
  output->roll = input->roll;
  return true;
}

armor_interface__msg__ArmorPose *
armor_interface__msg__ArmorPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armor_interface__msg__ArmorPose * msg = (armor_interface__msg__ArmorPose *)allocator.allocate(sizeof(armor_interface__msg__ArmorPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armor_interface__msg__ArmorPose));
  bool success = armor_interface__msg__ArmorPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armor_interface__msg__ArmorPose__destroy(armor_interface__msg__ArmorPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armor_interface__msg__ArmorPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armor_interface__msg__ArmorPose__Sequence__init(armor_interface__msg__ArmorPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armor_interface__msg__ArmorPose * data = NULL;

  if (size) {
    data = (armor_interface__msg__ArmorPose *)allocator.zero_allocate(size, sizeof(armor_interface__msg__ArmorPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armor_interface__msg__ArmorPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armor_interface__msg__ArmorPose__fini(&data[i - 1]);
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
armor_interface__msg__ArmorPose__Sequence__fini(armor_interface__msg__ArmorPose__Sequence * array)
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
      armor_interface__msg__ArmorPose__fini(&array->data[i]);
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

armor_interface__msg__ArmorPose__Sequence *
armor_interface__msg__ArmorPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armor_interface__msg__ArmorPose__Sequence * array = (armor_interface__msg__ArmorPose__Sequence *)allocator.allocate(sizeof(armor_interface__msg__ArmorPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armor_interface__msg__ArmorPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armor_interface__msg__ArmorPose__Sequence__destroy(armor_interface__msg__ArmorPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armor_interface__msg__ArmorPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armor_interface__msg__ArmorPose__Sequence__are_equal(const armor_interface__msg__ArmorPose__Sequence * lhs, const armor_interface__msg__ArmorPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armor_interface__msg__ArmorPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armor_interface__msg__ArmorPose__Sequence__copy(
  const armor_interface__msg__ArmorPose__Sequence * input,
  armor_interface__msg__ArmorPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armor_interface__msg__ArmorPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armor_interface__msg__ArmorPose * data =
      (armor_interface__msg__ArmorPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armor_interface__msg__ArmorPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armor_interface__msg__ArmorPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armor_interface__msg__ArmorPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
