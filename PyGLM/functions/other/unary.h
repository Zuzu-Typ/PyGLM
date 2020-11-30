#pragma once

#include "../../compiler_setup.h"

//#include "../../types/all.h"
//
//#include "../../internal_functions/all.h"
//
//#include "../function_generator_macros.h"

PyDoc_STRVAR(unary_pos_docstr,
	"pos(a) -> Any\n"
	"	Equivalent to `+a`."
);
static PyObject* 
unary_pos(PyObject*, PyObject* arg) {
	return PyNumber_Positive(arg);
}

PyDoc_STRVAR(unary_neg_docstr,
	"neg(a) -> Any\n"
	"	Equivalent to `-a`."
);
static PyObject*
unary_neg(PyObject*, PyObject* arg) {
	return PyNumber_Negative(arg);
}

PyDoc_STRVAR(unary_inv_docstr,
	"inv(a) -> Any\n"
	"	Equivalent to `~a`."
);
static PyObject*
unary_inv(PyObject*, PyObject* arg) {
	return PyNumber_Invert(arg);
}

#define UNARY_METHODS \
{ "pos", (PyCFunction)unary_pos, METH_O, unary_pos_docstr }, \
{ "neg", (PyCFunction)unary_neg, METH_O, unary_neg_docstr }, \
{ "inv", (PyCFunction)unary_inv, METH_O, unary_inv_docstr }
