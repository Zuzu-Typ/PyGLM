#pragma once

#include "error_functions.h"

#define PyGLM_FREXP_WARNING					1 // This warning is deprecated
#define PyGLM_FLOAT_ZERO_DIVISION_WARNING	2
#define PyGLM_NO_REFERENCE_POSSIBLE_WARNING	3
#define PyGLM_OPERATOR_DEPRECATION_WARNING	4
#define PyGLM_OVERFLOW_WARNING				5
#define PyGLM_ARGUMENT_DEPRECATION_WARNING	6

static unsigned long long PyGLM_SHOW_WARNINGS = 18446744073709551615ull;

PyDoc_STRVAR(silence_docstr,
	"silence(ID: int) -> None\n"
	"	Silence a PyGLM warning (or all using 0)."
);

static PyObject*
silence(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		unsigned long long warning_id = static_cast<unsigned long long>(PyLong_AS_LONG(arg));
		if (warning_id < 0 || warning_id > 6) {
			PyErr_SetString(PyExc_ValueError, "the specified warning does not exist.");
			return NULL;
		}
		if (warning_id == 0) {
			PyGLM_SHOW_WARNINGS = 0;
		}
		else {
			PyGLM_SHOW_WARNINGS &= (PyGLM_SHOW_WARNINGS ^ (1ull << (warning_id - 1)));
		}
		Py_RETURN_NONE;
	}
	PyGLM_TYPEERROR_O("silence() requires an integer as it's argument, not ", arg);
	return NULL;
}