#pragma once

#include "../compiler_setup.h"

#define Py_IS_NOTIMPLEMENTED(op) (op == NULL || (PyObject*)op == Py_NotImplemented) // find out if op is NULL or NotImplemented

#define PyGLM_ASSERT(cond, msg) if (!cond) {PyErr_SetString(PyExc_AssertionError, msg); return NULL;}

#define PyObject_IterCheck(op) ((op)->ob_type->tp_iter != 0)

#define PyGLM_TYPE_AS_CSTRING(op) op->ob_type->tp_name

#define PyGLM_TypeCheck(op, tp) (Py_TYPE(op) == tp) 

#define PyGLM_String_AsString(name) PyBytes_AsString(PyUnicode_AsASCIIString(name));