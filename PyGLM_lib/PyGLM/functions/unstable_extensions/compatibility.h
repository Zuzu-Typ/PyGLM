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
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::saturate<double>(PyGLM_Number_FromPyObject<double>(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		return pack(glm::saturate(PyGLM_Vec_PTI_Get0(2, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {
		return pack(glm::saturate(PyGLM_Vec_PTI_Get0(2, double, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		return pack(glm::saturate(PyGLM_Vec_PTI_Get0(3, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {
		return pack(glm::saturate(PyGLM_Vec_PTI_Get0(3, double, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		return pack(glm::saturate(PyGLM_Vec_PTI_Get0(4, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {
		return pack(glm::saturate(PyGLM_Vec_PTI_Get0(4, double, arg)));
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
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::isfinite<double>(PyGLM_Number_FromPyObject<double>(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(1, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(1, double, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(2, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(2, double, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(3, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(3, double, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(4, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {
		return pack(glm::isfinite(PyGLM_Vec_PTI_Get0(4, double, arg)));
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
