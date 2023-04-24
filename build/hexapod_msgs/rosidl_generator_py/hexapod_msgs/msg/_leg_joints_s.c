// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hexapod_msgs:msg/LegJoints.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "hexapod_msgs/msg/detail/leg_joints__struct.h"
#include "hexapod_msgs/msg/detail/leg_joints__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hexapod_msgs__msg__leg_joints__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("hexapod_msgs.msg._leg_joints.LegJoints", full_classname_dest, 38) == 0);
  }
  hexapod_msgs__msg__LegJoints * ros_message = _ros_message;
  {  // coxa
    PyObject * field = PyObject_GetAttrString(_pymsg, "coxa");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->coxa = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // femur
    PyObject * field = PyObject_GetAttrString(_pymsg, "femur");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->femur = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tibia
    PyObject * field = PyObject_GetAttrString(_pymsg, "tibia");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tibia = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tarsus
    PyObject * field = PyObject_GetAttrString(_pymsg, "tarsus");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tarsus = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hexapod_msgs__msg__leg_joints__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LegJoints */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hexapod_msgs.msg._leg_joints");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LegJoints");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hexapod_msgs__msg__LegJoints * ros_message = (hexapod_msgs__msg__LegJoints *)raw_ros_message;
  {  // coxa
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->coxa);
    {
      int rc = PyObject_SetAttrString(_pymessage, "coxa", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // femur
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->femur);
    {
      int rc = PyObject_SetAttrString(_pymessage, "femur", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tibia
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tibia);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tibia", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tarsus
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tarsus);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tarsus", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
