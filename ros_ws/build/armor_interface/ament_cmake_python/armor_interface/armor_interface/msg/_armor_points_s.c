// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from armor_interface:msg/ArmorPoints.idl
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
#include "armor_interface/msg/detail/armor_points__struct.h"
#include "armor_interface/msg/detail/armor_points__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool armor_interface__msg__armor_points__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("armor_interface.msg._armor_points.ArmorPoints", full_classname_dest, 45) == 0);
  }
  armor_interface__msg__ArmorPoints * ros_message = _ros_message;
  {  // left_top_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_top_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_top_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_top_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_top_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_top_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_bottom_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_bottom_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_bottom_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_bottom_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_bottom_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_bottom_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_bottom_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_bottom_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_bottom_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_bottom_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_bottom_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_bottom_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_top_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_top_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_top_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_top_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_top_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_top_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * armor_interface__msg__armor_points__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ArmorPoints */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("armor_interface.msg._armor_points");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ArmorPoints");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  armor_interface__msg__ArmorPoints * ros_message = (armor_interface__msg__ArmorPoints *)raw_ros_message;
  {  // left_top_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_top_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_top_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_top_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_top_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_top_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_bottom_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_bottom_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_bottom_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_bottom_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_bottom_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_bottom_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_bottom_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_bottom_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_bottom_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_bottom_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_bottom_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_bottom_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_top_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_top_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_top_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_top_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_top_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_top_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
