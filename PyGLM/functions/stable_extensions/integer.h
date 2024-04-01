#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
iround_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
		case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
			PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<L, T>(0), PyGLM_Vec_Get(L, T, arg)))), "x has to be greater than or equal to 0"); \
			return pack(glm::iround(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
		case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
			PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<L, T>(0), PyGLM_MVec_Get(L, T, arg)))), "x has to be greater than or equal to 0"); \
			return pack(glm::iround(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	if (PyGLM_Number_Check(arg)) {
		double d = PyGLM_Number_FromPyObject<double>(arg);
		PyGLM_ASSERT((0.0 <= d), "x has to be greater than or equal to 0");
		return pack(glm::iround(d));
	}
	PyGLM_TYPEERROR_O("invalid argument type for iround(): ", arg);
	return NULL;
}

static PyObject*
uround_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
		case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
			PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<L, T>(0), PyGLM_Vec_Get(L, T, arg)))), "x has to be greater than or equal to 0"); \
			return pack(glm::uround(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
		case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
			PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<L, T>(0), PyGLM_MVec_Get(L, T, arg)))), "x has to be greater than or equal to 0"); \
			return pack(glm::uround(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	if (PyGLM_Number_Check(arg)) {
		double d = PyGLM_Number_FromPyObject<double>(arg);
		PyGLM_ASSERT((0.0 <= d), "x has to be greater than or equal to 0");
		return pack(glm::uround(d));
	}
	PyGLM_TYPEERROR_O("invalid argument type for uround(): ", arg);
	return NULL;
}

PyDoc_STRVAR(iround_docstr,
	"iround(x: number) -> int\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest.\n"
	"	`x` must be greater than or equal to `0`\n"
	"iround(x: vecN) -> ivecN\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest.\n"
	"	Each component of `x` must be greater than or equal to `0`"
);
PyDoc_STRVAR(uround_docstr,
	"uround(x: number) -> int\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest.\n"
	"	`x` must be greater than or equal to `0`\n"
	"uround(x: vecN) -> uvecN\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest.\n"
	"	Each component of `x` must be greater than or equal to `0`"
);

#define INTEGER_METHODS \
{ "iround", (PyCFunction)iround_, METH_O, iround_docstr }, \
{ "uround", (PyCFunction)uround_, METH_O, uround_docstr }
