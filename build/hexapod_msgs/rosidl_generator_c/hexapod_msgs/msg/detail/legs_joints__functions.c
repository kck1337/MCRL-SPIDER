// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hexapod_msgs:msg/LegsJoints.idl
// generated code does not contain a copyright notice
#include "hexapod_msgs/msg/detail/legs_joints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `leg`
#include "hexapod_msgs/msg/detail/leg_joints__functions.h"

bool
hexapod_msgs__msg__LegsJoints__init(hexapod_msgs__msg__LegsJoints * msg)
{
  if (!msg) {
    return false;
  }
  // leg
  for (size_t i = 0; i < 6; ++i) {
    if (!hexapod_msgs__msg__LegJoints__init(&msg->leg[i])) {
      hexapod_msgs__msg__LegsJoints__fini(msg);
      return false;
    }
  }
  return true;
}

void
hexapod_msgs__msg__LegsJoints__fini(hexapod_msgs__msg__LegsJoints * msg)
{
  if (!msg) {
    return;
  }
  // leg
  for (size_t i = 0; i < 6; ++i) {
    hexapod_msgs__msg__LegJoints__fini(&msg->leg[i]);
  }
}

bool
hexapod_msgs__msg__LegsJoints__are_equal(const hexapod_msgs__msg__LegsJoints * lhs, const hexapod_msgs__msg__LegsJoints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // leg
  for (size_t i = 0; i < 6; ++i) {
    if (!hexapod_msgs__msg__LegJoints__are_equal(
        &(lhs->leg[i]), &(rhs->leg[i])))
    {
      return false;
    }
  }
  return true;
}

bool
hexapod_msgs__msg__LegsJoints__copy(
  const hexapod_msgs__msg__LegsJoints * input,
  hexapod_msgs__msg__LegsJoints * output)
{
  if (!input || !output) {
    return false;
  }
  // leg
  for (size_t i = 0; i < 6; ++i) {
    if (!hexapod_msgs__msg__LegJoints__copy(
        &(input->leg[i]), &(output->leg[i])))
    {
      return false;
    }
  }
  return true;
}

hexapod_msgs__msg__LegsJoints *
hexapod_msgs__msg__LegsJoints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_msgs__msg__LegsJoints * msg = (hexapod_msgs__msg__LegsJoints *)allocator.allocate(sizeof(hexapod_msgs__msg__LegsJoints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hexapod_msgs__msg__LegsJoints));
  bool success = hexapod_msgs__msg__LegsJoints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hexapod_msgs__msg__LegsJoints__destroy(hexapod_msgs__msg__LegsJoints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hexapod_msgs__msg__LegsJoints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hexapod_msgs__msg__LegsJoints__Sequence__init(hexapod_msgs__msg__LegsJoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_msgs__msg__LegsJoints * data = NULL;

  if (size) {
    data = (hexapod_msgs__msg__LegsJoints *)allocator.zero_allocate(size, sizeof(hexapod_msgs__msg__LegsJoints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hexapod_msgs__msg__LegsJoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hexapod_msgs__msg__LegsJoints__fini(&data[i - 1]);
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
hexapod_msgs__msg__LegsJoints__Sequence__fini(hexapod_msgs__msg__LegsJoints__Sequence * array)
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
      hexapod_msgs__msg__LegsJoints__fini(&array->data[i]);
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

hexapod_msgs__msg__LegsJoints__Sequence *
hexapod_msgs__msg__LegsJoints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_msgs__msg__LegsJoints__Sequence * array = (hexapod_msgs__msg__LegsJoints__Sequence *)allocator.allocate(sizeof(hexapod_msgs__msg__LegsJoints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hexapod_msgs__msg__LegsJoints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hexapod_msgs__msg__LegsJoints__Sequence__destroy(hexapod_msgs__msg__LegsJoints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hexapod_msgs__msg__LegsJoints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hexapod_msgs__msg__LegsJoints__Sequence__are_equal(const hexapod_msgs__msg__LegsJoints__Sequence * lhs, const hexapod_msgs__msg__LegsJoints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hexapod_msgs__msg__LegsJoints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hexapod_msgs__msg__LegsJoints__Sequence__copy(
  const hexapod_msgs__msg__LegsJoints__Sequence * input,
  hexapod_msgs__msg__LegsJoints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hexapod_msgs__msg__LegsJoints);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hexapod_msgs__msg__LegsJoints * data =
      (hexapod_msgs__msg__LegsJoints *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hexapod_msgs__msg__LegsJoints__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hexapod_msgs__msg__LegsJoints__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hexapod_msgs__msg__LegsJoints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
