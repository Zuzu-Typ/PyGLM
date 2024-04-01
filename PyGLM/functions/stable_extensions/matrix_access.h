#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
row_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "row", 2, 3, &arg1, &arg2, &arg3) || !PyGLM_Number_Check(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for row()");
		return NULL;
	}
	glm::length_t index = PyGLM_Number_FromPyObject<glm::length_t>(arg2);
	if (index < 0) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(C, R, T) \
		case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
			if (index >= R) { \
				PyErr_SetString(PyExc_IndexError, "index out of range"); \
				return NULL; \
			} \
			if (arg3 != NULL) {\
				if (PyGLM_Vec_Check(C, T, arg3)) \
					return pack(glm::row(PyGLM_Mat_Get(C, R, T, arg1), index, PyGLM_VecOrMVec_GET(C, T, arg3))); \
			} else {\
				return pack(glm::row(PyGLM_Mat_Get(C, R, T, arg1), index)); \
			} \
			break;
			

		PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for row()");
	return NULL;
}

static PyObject*
column_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "column", 2, 3, &arg1, &arg2, &arg3) || !PyGLM_Number_Check(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
		return NULL;
	}
	glm::length_t index = PyGLM_Number_FromPyObject<glm::length_t>(arg2);
	if (index < 0) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(C, R, T) \
		case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
			if (index >= C) { \
				PyErr_SetString(PyExc_IndexError, "index out of range"); \
				return NULL; \
			} \
			if (arg3 != NULL) {\
				if (PyGLM_Vec_Check(R, T, arg3)) \
					return pack(glm::column(PyGLM_Mat_Get(C, R, T, arg1), index, PyGLM_VecOrMVec_GET(R, T, arg3))); \
			} else {\
				return pack(glm::column(PyGLM_Mat_Get(C, R, T, arg1), index)); \
			} \
			break;


		PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
	return NULL;
}

PyDoc_STRVAR(row_docstr,
	"row(m: matNxM, index: int) -> vecN\n"
	"	Get a specific row of a matrix.\n"
	"row(m: matNxM, index: int, x: vecN) -> matNxM\n"
	"	Set a specific row to a matrix."
);
PyDoc_STRVAR(column_docstr,
	"column(m: matNxM, index: int) -> vecM\n"
	"	Get a specific column of a matrix.\n"
	"column(m: matNxM, index: int, x: vecM) -> matNxM\n"
	"	Set a specific column to a matrix."
);

#define MATRIX_ACCESS_METHODS \
{ "row", (PyCFunction)row_, METH_VARARGS, row_docstr }, \
{ "column", (PyCFunction)column_, METH_VARARGS, column_docstr }
