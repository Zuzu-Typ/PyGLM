#pragma once

#include "../compiler_setup.h"

#include "helper_macros.h"

#define PyGLM_FREXP_WARNING					1 // This warning is deprecated
#define PyGLM_FLOAT_ZERO_DIVISION_WARNING	2
#define PyGLM_NO_REFERENCE_POSSIBLE_WARNING	3
#define PyGLM_OPERATOR_DEPRECATION_WARNING	4
#define PyGLM_OVERFLOW_WARNING				5
#define PyGLM_ARGUMENT_DEPRECATION_WARNING	6

extern unsigned long long PyGLM_SHOW_WARNINGS;

#define PyGLM_WARN_TYPE(id, type, msg) if (PyGLM_SHOW_WARNINGS & (1ull << id)) PyErr_WarnEx(type, msg "\nYou can silence this warning by calling glm.silence(" PyGLM_PREPROCESSOR_TOSTRING(id) ")", 1)

#define PyGLM_WARN(id, msg) PyGLM_WARN_TYPE(id, PyExc_UserWarning, msg)

PyDoc_STRVAR(silence_docstr,
	"silence(ID: int) -> None\n"
	"	Silence a PyGLM warning (or all using 0)."
);

PyObject*
silence(PyObject*, PyObject * arg);