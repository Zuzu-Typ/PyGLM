#pragma once

#include "../../compiler_setup.h"
#include "../../internal_functions/all.h"

PyDoc_STRVAR(binary_add_docstr,
	"add(a, b) -> Any\n"
	"	Equivalent to `a + b`."
);
static PyObject*
binary_add(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "add", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.add is deprecated. Use operator.add instead");

	return PyNumber_Add(arg1, arg2);
}

PyDoc_STRVAR(binary_sub_docstr,
	"sub(a, b) -> Any\n"
	"	Equivalent to `a - b`."
);
static PyObject*
binary_sub(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "sub", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.sub is deprecated. Use operator.sub instead");

	return PyNumber_Subtract(arg1, arg2);
}

PyDoc_STRVAR(binary_mul_docstr,
	"mul(a, b) -> Any\n"
	"	Equivalent to `a * b`."
);
static PyObject*
binary_mul(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "mul", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.mul is deprecated. Use operator.mul instead");

	return PyNumber_Multiply(arg1, arg2);
}

PyDoc_STRVAR(binary_div_docstr,
	"div(a, b) -> Any\n"
	"	Equivalent to `a / b`."
);
static PyObject*
binary_div(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "div", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.div is deprecated. Use operator.truediv instead");

	return PyNumber_TrueDivide(arg1, arg2);
}

PyDoc_STRVAR(binary_floordiv_docstr,
	"floordiv(a, b) -> Any\n"
	"	Equivalent to `a // b`."
);
static PyObject*
binary_floordiv(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "floordiv", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.floordiv is deprecated. Use operator.floordiv instead");

	return PyNumber_FloorDivide(arg1, arg2);
}

PyDoc_STRVAR(binary_mod_docstr,
	"mod(a, b) -> Any\n"
	"	Equivalent to `a % b`."
);
static PyObject*
binary_mod(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "mod", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.mod is deprecated. Use operator.mod instead");

	return PyNumber_Remainder(arg1, arg2);
}

PyDoc_STRVAR(binary_lshift_docstr,
	"lshift(a, b) -> Any\n"
	"	Equivalent to `a << b`."
);
static PyObject*
binary_lshift(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "lshift", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.lshift is deprecated. Use operator.lshift instead");

	return PyNumber_Lshift(arg1, arg2);
}

PyDoc_STRVAR(binary_rshift_docstr,
	"rshift(a, b) -> Any\n"
	"	Equivalent to `a >> b`."
);
static PyObject*
binary_rshift(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "rshift", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.rshift is deprecated. Use operator.rshift instead");

	return PyNumber_Rshift(arg1, arg2);
}

PyDoc_STRVAR(binary_and_docstr,
	"and_(a, b) -> Any\n"
	"	Equivalent to `a & b`."
);
static PyObject*
binary_and(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "band", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.band is deprecated. Use operator.and_ instead");

	return PyNumber_And(arg1, arg2);
}

PyDoc_STRVAR(binary_xor_docstr,
	"xor(a, b) -> Any\n"
	"	Equivalent to `a ^ b`."
);
static PyObject*
binary_xor(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "bxor", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.bxor is deprecated. Use operator.xor instead");

	return PyNumber_Xor(arg1, arg2);
}

PyDoc_STRVAR(binary_or_docstr,
	"or_(a, b) -> Any\n"
	"	Equivalent to `a | b`."
);
static PyObject*
binary_or(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "bor", arg1, arg2);

	PyGLM_WARN_TYPE(PyGLM_OPERATOR_DEPRECATION_WARNING, PyExc_DeprecationWarning, "glm.bor is deprecated. Use operator.or_ instead");

	return PyNumber_Or(arg1, arg2);
}

PyDoc_STRVAR(binary_cmp_docstr,
	"cmp(a, b) -> Any\n"
	"	Equivalent to `-1 if a < b else 1 if a > b else 0`."
);
static PyObject*
binary_cmp(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "cmp", arg1, arg2);

	int cmpResult = PyObject_RichCompareBool(arg1, arg2, Py_EQ);
	
	if (cmpResult == 1) {
		return PyGLM_PyObject_FromNumber<int>(0);
	}
	if (cmpResult == -1) {
		return NULL;
	}

	cmpResult = PyObject_RichCompareBool(arg1, arg2, Py_LT);

	if (cmpResult == 1) {
		return PyGLM_PyObject_FromNumber<int>(-1);
	}
	if (cmpResult == -1) {
		return NULL;
	}

	return PyGLM_PyObject_FromNumber<int>(1);
}

#define BINARY_METHODS \
{ "add", (PyCFunction)binary_add, METH_VARARGS, binary_add_docstr }, \
{ "sub", (PyCFunction)binary_sub, METH_VARARGS, binary_sub_docstr }, \
{ "mul", (PyCFunction)binary_mul, METH_VARARGS, binary_mul_docstr }, \
{ "div", (PyCFunction)binary_div, METH_VARARGS, binary_div_docstr }, \
{ "floordiv", (PyCFunction)binary_floordiv, METH_VARARGS, binary_floordiv_docstr }, \
{ "mod", (PyCFunction)binary_mod, METH_VARARGS, binary_mod_docstr }, \
{ "lshift", (PyCFunction)binary_lshift, METH_VARARGS, binary_lshift_docstr }, \
{ "rshift", (PyCFunction)binary_rshift, METH_VARARGS, binary_rshift_docstr }, \
{ "and_", (PyCFunction)binary_and, METH_VARARGS, binary_and_docstr }, \
{ "xor", (PyCFunction)binary_xor, METH_VARARGS, binary_xor_docstr }, \
{ "or_", (PyCFunction)binary_or, METH_VARARGS, binary_or_docstr }, \
{ "cmp", (PyCFunction)binary_cmp, METH_VARARGS, binary_cmp_docstr }
