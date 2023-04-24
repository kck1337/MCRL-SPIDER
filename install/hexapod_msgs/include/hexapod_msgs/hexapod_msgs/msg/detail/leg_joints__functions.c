// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice
#include "hexapod_msgs/msg/detail/leg_joints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hexapod_msgs__msg__LegJoints__init(hexapod_msgs__msg__LegJoints * msg)
{
  if (!msg) {
    return false;
  }
  // coxa
  // femur
  // tibia
  // tarsus
  return true;
}

void
hexapod_msgs__msg__LegJoints__fini(hexapod_msgs__msg__LegJoints * msg)
{
  if (!msg) {
    return;
  }
  // coxa
  // femur
  // tibia
  // tarsus
}

bool
hexapod_msgs__msg__LegJoints__are_equal(const hexapod_msgs__msg__LegJoints * lhs, const hexapod_msgs__msg__LegJoints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // coxa
  if (lhs->coxa != rhs->coxa) {
    return false;
  }
  // femur
  if (lhs->femur != rhs->femur) {
    return false;
  }
  // tibia
  if (lhs->tibia != rhs->tibia) {
    return false;
  }
  // tarsus
  if (lhs->tarsus != rhs->tarsus) {
    return false;
  }
  return true;
}

bool
hexapod_msgs__msg__LegJoints__copy(
  const hexapod_msgs__msg__LegJoints * input,
  hexapod_msgs__msg__LegJoints * output)
{
  if (!input || !output) {
    return false;
  }
  // coxa
  output->coxa = input->coxa;
  // femur
  output->femur = input->femur;
  // tibia
  output->tibia = input->tibia;
  // tarsus
  output->tarsus = input->tarsus;
  return true;
}

hexapod_msgs__msg__LegJoints *
hexapod_msgs__msg__LegJoints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_msgs__msg__LegJoints * msg = (hexapod_msgs__msg__LegJoints *)allocator.allocate(sizeof(hexapod_msgs__msg__LegJoints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hexapod_msgs__msg__LegJoints));
  bool success = hexapod_msgs__msg__LegJoints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hexapod_msgs__msg__LegJoints__destroy(hexapod_msgs__msg__LegJoints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hexapod_msgs__msg__LegJoints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hexapod_msgs__msg__LegJoints__Sequence__init(hexapod_msgs__msg__LegJoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_msgs__msg__LegJoints * data = NULL;

  if (size) {
    data = (hexapod_msgs__msg__LegJoints *)allocator.zero_allocate(size, sizeof(hexapod_msgs__msg__LegJoints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hexapod_msgs__msg__LegJoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hexapod_msgs__msg__LegJoints__fini(&data[i - 1]);
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
hexapod_msgs__msg__LegJoints__Sequence__fini(hexapod_msgs__msg__LegJoints__Sequence * array)
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
      hexapod_msgs__msg__LegJoints__fini(&array->data[i]);
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

hexapod_msgs__msg__LegJoints__Sequence *
hexapod_msgs__msg__LegJoints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hexapod_msgs__msg__LegJoints__Sequence * array = (hexapod_msgs__msg__LegJoints__Sequence *)allocator.allocate(sizeof(hexapod_msgs__msg__LegJoints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hexapod_msgs__msg__LegJoints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hexapod_msgs__msg__LegJoints__Sequence__destroy(hexapod_msgs__msg__LegJoints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hexapod_msgs__msg__LegJoints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hexapod_msgs__msg__LegJoints__Sequence__are_equal(const hexapod_msgs__msg__LegJoints__Sequence * lhs, const hexapod_msgs__msg__LegJoints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hexapod_msgs__msg__LegJoints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hexapod_msgs__msg__LegJoints__Sequence__copy(
  const hexapod_msgs__msg__LegJoints__Sequence * input,
  hexapod_msgs__msg__LegJoints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hexapod_msgs__msg__LegJoints);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hexapod_msgs__msg__LegJoints * data =
      (hexapod_msgs__msg__LegJoints *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hexapod_msgs__msg__LegJoints__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hexapod_msgs__msg__LegJoints__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hexapod_msgs__msg__LegJoints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
