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
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::atan(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec1 o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::dvec1 o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::atan(o, o2));
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for atan(): ", arg1, arg2);
		return NULL;
	}

	if (PyGLM_Number_Check(arg1)) {
		return pack(glm::atan(PyGLM_Number_FromPyObject<double>(arg1)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
		glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
		glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		return pack(glm::atan(o));
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
