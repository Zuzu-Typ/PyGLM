#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_N_V__tfF(radians)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(degrees)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(sin)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(cos)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(tan)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(asin)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acos)
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

PyGLM_MAKE_GLM_FUNC_N_V__tfF(sinh)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(cosh)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(tanh)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(asinh)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acosh)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(atanh)

#define FUNC_TRIGONOMETRIC_METHODS { "radians", (PyCFunction)radians_, METH_O, "radians(x) -> float or vecn\nConverts degrees to radians and returns the result." }, \
{ "degrees", (PyCFunction)degrees_, METH_O, "degrees(x) -> float or vecn\nConverts radians to degrees and returns the result." }, \
{ "sin", (PyCFunction)sin_, METH_O, "sin(x) -> vecn\nThe standard trigonometric sine function. \nThe values returned by this function will range from [-1, 1]." }, \
{ "cos", (PyCFunction)cos_, METH_O, "cos(x) -> vecn\nThe standard trigonometric cosine function.\nThe values returned by this function will range from [-1, 1]." }, \
{ "tan", (PyCFunction)tan_, METH_O, "tan(x) -> vecn\nThe standard trigonometric tangent function." }, \
{ "asin", (PyCFunction)asin_, METH_O, "asin(x) -> vecn\nArc sine. Returns an angle whose sine is x. \nThe range of values returned by this function is [-PI/2, PI/2].\nResults are undefined if |x| > 1." }, \
{ "acos", (PyCFunction)acos_, METH_O, "acos(x) -> vecn\nArc cosine. Returns an angle whose sine is x.\nThe range of values returned by this function is [0, PI].\nResults are undefined if |x| > 1." }, \
{ "atan", (PyCFunction)atan_,  METH_VARARGS, "atan(y [,x]) -> float or vecn\nArc tangent. Returns an angle whose tangent is y/x.\nThe signs of x and y are used to determine what\nquadrant the angle is in. The range of values returned\nby this function is [-PI, PI]. Results are undefined\nif x and y are both 0." }, \
{ "sinh", (PyCFunction)sinh_, METH_O, "sinh(x) -> vecn\nReturns the hyperbolic sine function, (exp(x) - exp(-x)) / 2" }, \
{ "cosh", (PyCFunction)cosh_, METH_O, "cosh(x) -> vecn\nReturns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2" }, \
{ "tanh", (PyCFunction)tanh_, METH_O, "tanh(x) -> vecn\nReturns the hyperbolic tangent function, sinh(angle) / cosh(angle)" }, \
{ "asinh", (PyCFunction)asinh_, METH_O, "asinh(x) -> float or vecn\nArc hyperbolic sine; returns the inverse of sinh." }, \
{ "acosh", (PyCFunction)acosh_, METH_O, "acosh(x) -> float or vecn\nArc hyperbolic cosine; returns the non-negative inverse\nof cosh. Results are undefined if x < 1." }, \
{ "atanh", (PyCFunction)atanh_, METH_O, "atanh(x) -> float or vecn\nArc hyperbolic tangent; returns the inverse of tanh.\nResults are undefined if abs(x) >= 1." }
