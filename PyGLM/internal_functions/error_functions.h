#pragma once

#include "helper_macros.h"
#include "warnings.h"
#include "../compiler_setup.h"

#define PyGLM_TYPEERROR_O(str, obj) PyErr_Format(PyExc_TypeError, "%s'%s'", str, PyGLM_TYPE_AS_CSTRING(obj));
#define PyGLM_TYPEERROR_2O(str, obj1, obj2) PyErr_Format(PyExc_TypeError, "%s'%s' and '%s'", str, PyGLM_TYPE_AS_CSTRING(obj1), PyGLM_TYPE_AS_CSTRING(obj2));

#define PyGLM_ZERO_DIVISION_ERROR PyErr_SetString(PyExc_ZeroDivisionError, "Whoopsie. Integers can't divide by zero (:")

#define PyGLM_ZERO_DIVISION_ERROR_T(T) if (std::numeric_limits<T>::is_iec559) { PyGLM_WARN(PyGLM_FLOAT_ZERO_DIVISION_WARNING, "Uh oh.. There is a float division by zero here. I hope that's intended!"); } else { PyGLM_ZERO_DIVISION_ERROR; return NULL; }
