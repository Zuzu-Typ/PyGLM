#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(radians_docstr,
	"radians(angle: float) -> float\n"
	"	Converts degrees to radians and returns the result.\n"
	"radians(angle: vecN) -> vecN\n"
	"	Returns `radians(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(radians)

PyDoc_STRVAR(degrees_docstr,
	"degrees(angle: float) -> float\n"
	"	Converts radians to degrees and returns the result.\n"
	"degrees(angle: vecN) -> vecN\n"
	"	Returns `degrees(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(degrees)

PyDoc_STRVAR(sin_docstr,
	"sin(angle: float) -> float\n"
	"	The standard trigonometric sine function. The values returned by this function will range\n"
	"	from `[-1, 1]`.\n"
	"sin(angle: vecN) -> vecN\n"
	"	Returns `sin(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(sin)

PyDoc_STRVAR(cos_docstr,
	"cos(angle: float) -> float\n"
	"	The standard trigonometric cosine function. The values returned by this function will range\n"
	"	from `[-1, 1]`.\n"
	"cos(angle: vecN) -> vecN\n"
	"	Returns `cos(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(cos)

PyDoc_STRVAR(tan_docstr,
	"tan(angle: float) -> float\n"
	"	The standard trigonometric tangent function.\n"
	"tan(angle: vecN) -> vecN\n"
	"	Returns `tan(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(tan)

PyDoc_STRVAR(asin_docstr,
	"asin(x: float) -> float\n"
	"	Arc sine. Returns an angle whose sine is `x`. The range of values returned by this function\n"
	"	is `[0, PI]`. Results are undefined if `|x| > 1`.\n"
	"asin(x: vecN) -> vecN\n"
	"	Returns `asin(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(asin)

PyDoc_STRVAR(acos_docstr,
	"acos(x: float) -> float\n"
	"	Arc cosine. Returns an angle whose cosine is `x`. The range of values returned by this function\n"
	"	is `[0, PI]`. Results are undefined if `|x| > 1`.\n"
	"acos(x: vecN) -> vecN\n"
	"	Returns `acos(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acos)

PyDoc_STRVAR(atan_docstr,
	"atan(y_over_x: float) -> float\n"
	"	Arc tangent. Returns an angle whose tangent is `y_over_x`. The range of values returned by\n"
	"	this function is `[-PI / 2, PI / 2]`.\n"
	"atan(y_over_x: vecN) -> vecN\n"
	"	Returns `atan(c)` for every component `c` of `x`.\n"
	"atan(y: float, x: float) -> float\n"
	"	Arc tangent. Returns an angle whose tangent is `y / x`. The signs of `x` and `y` are used to\n"
	"	determine what quadrant the angle is in. The range of values returned by this function\n"
	"	is `[-PI, PI]`. Results are undefined if `x` and `y` are both `0`.\n"
	"atan(y: vecN, x: vecN) -> vecN\n"
	"	Returns `atan(y[i], x[i])` for every index `i`."
);
static PyObject*
atan_(PyObject*, PyObject* args) {
	PyObject* arg1 = NULL, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "atan", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for atan()");
		return NULL;
	}

	if (arg2 != NULL) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::atan(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::atan(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for atan(): ", arg1, arg2);
		return NULL;
	}

	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
		case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
			return pack(glm::atan(PyGLM_Vec_Get(L, T, arg1)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
		case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
			return pack(glm::atan(PyGLM_MVec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	if (PyGLM_Number_Check(arg1)) {
		return pack(glm::atan(PyGLM_Number_FromPyObject<double>(arg1)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for atan(): ", arg1);
	return NULL;
}

PyDoc_STRVAR(sinh_docstr,
	"sinh(angle: float) -> float\n"
	"	Returns the hyperbolic sine function, `(exp(angle) - exp(-angle)) / 2`.\n"
	"sinh(angle: vecN) -> vecN\n"
	"	Returns `sinh(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(sinh)

PyDoc_STRVAR(cosh_docstr,
	"cosh(angle: float) -> float\n"
	"	Returns the hyperbolic cosine function, `(exp(angle) + exp(-angle)) / 2`.\n"
	"cosh(angle: vecN) -> vecN\n"
	"	Returns `cosh(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(cosh)

PyDoc_STRVAR(tanh_docstr,
	"tanh(angle: float) -> float\n"
	"	Returns the hyperbolic tangent function, `sinh(angle) / cosh(angle)`\n"
	"tanh(angle: vecN) -> vecN\n"
	"	Returns `tanh(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(tanh)

PyDoc_STRVAR(asinh_docstr,
	"asinh(x: float) -> float\n"
	"	Arc hyperbolic sine; returns the inverse of `sinh`.\n"
	"asinh(x: vecN) -> vecN\n"
	"	Returns `asinh(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(asinh)

PyDoc_STRVAR(acosh_docstr,
	"acosh(x: float) -> float\n"
	"	Arc hyperbolic cosine; returns the non-negative inverse of `cosh`. Results are undefined\n"
	"	if `x < 1`.\n"
	"acosh(x: vecN) -> vecN\n"
	"	Returns `acosh(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acosh)

PyDoc_STRVAR(atanh_docstr,
	"atanh(x: float) -> float\n"
	"	Arc hyperbolic tangent; returns the inverse of `tanh`. Results are undefined if `abs(x) >= 1`.\n"
	"atanh(x: vecN) -> vecN\n"
	"	Returns `atanh(c)` for every component `c` of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(atanh)

#define FUNC_TRIGONOMETRIC_METHODS \
{ "radians", (PyCFunction)radians_, METH_O, radians_docstr }, \
{ "degrees", (PyCFunction)degrees_, METH_O, degrees_docstr }, \
{ "sin", (PyCFunction)sin_, METH_O, sin_docstr }, \
{ "cos", (PyCFunction)cos_, METH_O, cos_docstr }, \
{ "tan", (PyCFunction)tan_, METH_O, tan_docstr }, \
{ "asin", (PyCFunction)asin_, METH_O, asin_docstr }, \
{ "acos", (PyCFunction)acos_, METH_O, acos_docstr }, \
{ "atan", (PyCFunction)atan_,  METH_VARARGS, atan_docstr }, \
{ "sinh", (PyCFunction)sinh_, METH_O, sinh_docstr }, \
{ "cosh", (PyCFunction)cosh_, METH_O, cosh_docstr }, \
{ "tanh", (PyCFunction)tanh_, METH_O, tanh_docstr }, \
{ "asinh", (PyCFunction)asinh_, METH_O, asinh_docstr }, \
{ "acosh", (PyCFunction)acosh_, METH_O, acosh_docstr }, \
{ "atanh", (PyCFunction)atanh_, METH_O, atanh_docstr }
