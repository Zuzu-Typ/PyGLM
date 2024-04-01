#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(convertLinearToSRGB_docstr,
	"convertLinearToSRGB(ColorLinear: vecN) -> vecN\n"
	"	Convert a linear color to sRGB color using a standard gamma correction.\n"
	"convertLinearToSRGB(ColorLinear: vecN, Gamma: number) -> vecN\n"
	"	Convert a linear color to sRGB color using a custom gamma correction."
);
static PyObject*
convertLinearToSRGB_(PyObject*, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertLinearToSRGB", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}
	if (arg2 == NULL) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::convertLinearToSRGB(PyGLM_Vec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::convertLinearToSRGB(PyGLM_MVec_Get(L, T, arg1)));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	else {
		if (PyGLM_Number_Check(arg2)) {
			switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::convertLinearToSRGB(PyGLM_Vec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::convertLinearToSRGB(PyGLM_MVec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

					PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
	return NULL;
}

PyDoc_STRVAR(convertSRGBToLinear_docstr,
	"convertSRGBToLinear(ColorLinear: vecN) -> vecN\n"
	"	Convert a sRGB color to linear color using a standard gamma correction.\n"
	"convertSRGBToLinear(ColorLinear: vecN, Gamma: number) -> vecN\n"
	"	Convert a sRGB color to linear color using a custom gamma correction."
);
static PyObject*
convertSRGBToLinear_(PyObject*, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertSRGBToLinear", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
		return NULL;
	}
	if (arg2 == NULL) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::convertSRGBToLinear(PyGLM_Vec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::convertSRGBToLinear(PyGLM_MVec_Get(L, T, arg1)));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	else {
		if (PyGLM_Number_Check(arg2)) {
			switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::convertSRGBToLinear(PyGLM_Vec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::convertSRGBToLinear(PyGLM_MVec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

					PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
	return NULL;
}

#define COLOR_SPACE_METHODS \
{ "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB_, METH_VARARGS, convertLinearToSRGB_docstr }, \
{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear_, METH_VARARGS, convertSRGBToLinear_docstr }
