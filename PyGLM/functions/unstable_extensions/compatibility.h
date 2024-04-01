#pragma once

#include "../function_generator_macros.h"
#include "../detail/func_trigonometric.h"

PyDoc_STRVAR(saturate_docstr,
	"saturate(x: float) -> float\n"
	"	Returns `clamp(x, 0, 1)`.\n"
	"saturate(x: vecN) -> vecN\n"
	"	Returns `clamp(x, 0, 1)`."
);
static PyObject*
saturate_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::saturate(PyGLM_Vec_Get(L, T, arg))); \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::saturate(PyGLM_MVec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::saturate<double>(PyGLM_Number_FromPyObject<double>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for saturate(): ", arg);
	return NULL;
}

PyDoc_STRVAR(isfinite_docstr,
	"isfinite(x: float) -> bool\n"
	"	Test whether or not a scalar is a finite value.\n"
	"isfinite(x: vecN) -> bvecN\n"
	"	Test whether or not each vector component is a finite value."
);
static PyObject*
isfinite_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::isfinite(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::isfinite(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::isfinite<double>(PyGLM_Number_FromPyObject<double>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for isfinite(): ", arg);
	return NULL;
}

PyDoc_STRVAR(atan2_docstr,
	"atan2(y: float, x: float) -> float\n"
	"	Arc tangent. Returns an angle whose tangent is `y / x`. The signs of `x` and `y` are used to\n"
	"	determine what quadrant the angle is in. The range of values returned by this function\n"
	"	is `[-PI, PI]`. Results are undefined if `x` and `y` are both `0`.\n"
	"	Alias for `atan`.\n"
	"atan2(y: vecN, x: vecN) -> vecN\n"
	"	Returns `atan(y[i], x[i])` for every index `i`.\n"
	"	Alias for `atan`."
);

#define COMPATIBILITY_METHODS \
{ "atan2", (PyCFunction)atan_, METH_VARARGS, atan2_docstr }, \
{ "isfinite", (PyCFunction)isfinite_, METH_O, isfinite_docstr }, \
{ "saturate", (PyCFunction)saturate_, METH_O, saturate_docstr }
