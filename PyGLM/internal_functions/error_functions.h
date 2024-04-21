#pragma once

#include "helper_macros.h"
#include "../compiler_setup.h"

#define PyGLM_TYPEERROR_O(str, obj) PyErr_Format(PyExc_TypeError, "%s'%s'", str, PyGLM_TYPE_AS_CSTRING(obj));
#define PyGLM_TYPEERROR_2O(str, obj1, obj2) PyErr_Format(PyExc_TypeError, "%s'%s' and '%s'", str, PyGLM_TYPE_AS_CSTRING(obj1), PyGLM_TYPE_AS_CSTRING(obj2));

#define PyGLM_ZERO_DIVISION_ERROR PyErr_SetString(PyExc_ZeroDivisionError, "Whoopsie. Integers can't divide by zero (:")

#define PyGLM_ZERO_DIVISION_ERROR_T(T) if (std::numeric_limits<T>::is_iec559) { PyGLM_WARN(PyGLM_FLOAT_ZERO_DIVISION_WARNING, "Uh oh.. There is a float division by zero here. I hope that's intended!"); } else { PyGLM_ZERO_DIVISION_ERROR; return NULL; }

#define PyGLM_Arg_Unpack_1O(args, name, arg1) if(!PyArg_UnpackTuple(args, name, 1, 1, &arg1)) return NULL
#define PyGLM_Arg_Unpack_2O(args, name, arg1, arg2) if(!PyArg_UnpackTuple(args, name, 2, 2, &arg1, &arg2)) return NULL
#define PyGLM_Arg_Unpack_3O(args, name, arg1, arg2, arg3) if(!PyArg_UnpackTuple(args, name, 3, 3, &arg1, &arg2, &arg3)) return NULL
#define PyGLM_Arg_Unpack_4O(args, name, arg1, arg2, arg3, arg4) if(!PyArg_UnpackTuple(args, name, 4, 4, &arg1, &arg2, &arg3, &arg4)) return NULL
#define PyGLM_Arg_Unpack_5O(args, name, arg1, arg2, arg3, arg4, arg5) if(!PyArg_UnpackTuple(args, name, 5, 5, &arg1, &arg2, &arg3, &arg4, &arg5)) return NULL
#define PyGLM_Arg_Unpack_6O(args, name, arg1, arg2, arg3, arg4, arg5, arg6) if(!PyArg_UnpackTuple(args, name, 6, 6, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) return NULL
