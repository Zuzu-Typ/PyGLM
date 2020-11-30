#pragma once

#include "error_functions.h"

#define PyGLM_FREXP_WARNING					0x1
#define PyGLM_FLOAT_ZERO_DIVISION_WARNING	0x2
#define PyGLM_NO_REFERENCE_POSSIBLE_WARNING	0x4

int PyGLM_SHOW_WARNINGS = PyGLM_FREXP_WARNING | PyGLM_FLOAT_ZERO_DIVISION_WARNING | PyGLM_NO_REFERENCE_POSSIBLE_WARNING;

PyDoc_STRVAR(silence_docstr,
	"silence(ID: int) -> None\n"
	"	Silence a PyGLM warning (or all using 0)."
);

static PyObject*
silence(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		int warning_id = static_cast<int>(PyLong_AS_LONG(arg));
		if (warning_id < 0 || warning_id > 3) {
			PyErr_SetString(PyExc_ValueError, "the specified warning does not exist.");
			return NULL;
		}
		if (warning_id == 0) {
			PyGLM_SHOW_WARNINGS = 0;
		}
		else {
			PyGLM_SHOW_WARNINGS &= (PyGLM_SHOW_WARNINGS ^ (1 << (warning_id - 1)));
		}
		Py_RETURN_NONE;
	}
	PyGLM_TYPEERROR_O("silence() requires an integer as it's argument, not ", arg);
	return NULL;
}