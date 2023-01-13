#pragma once

#include "../../compiler_setup.h"
#include "../../internal_functions/all.h"

PyDoc_STRVAR(ternary_if_else_docstr,
	"if_else(b, x, y) -> Any\n"
	"	Equivalent to `x if b else y`."
);
static PyObject*
ternary_if_else(PyObject*, PyObject* args) {
	PyObject* b, * x, * y;
	PyGLM_Arg_Unpack_3O(args, "if_else", b, x, y);

	if (PyObject_IsTrue(b)) {
		return PyGLM_INCREF(x);
	}
	return PyGLM_INCREF(y);
}

#define TERNARY_METHODS \
{ "if_else", (PyCFunction)ternary_if_else, METH_VARARGS, ternary_if_else_docstr }
