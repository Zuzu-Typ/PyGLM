#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_Q(angle)
PyGLM_MAKE_GLM_FUNC_Q(axis)

static PyObject*
angleAxis_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "angleAxis", arg1, arg2);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	if (PyGLM_Number_Check(arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		return pack(glm::angleAxis(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		return pack(glm::angleAxis(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for angleAxis()");
	return NULL;
}

PyDoc_STRVAR(angle_docstr,
	"angle(x: quat) -> float\n"
	"	Returns the quaternion rotation angle."
);
PyDoc_STRVAR(angleAxis_docstr,
	"angleAxis(angle: float, axis: vec3) -> quat\n"
	"	Build a quaternion from an angle and a normalized axis."
);
PyDoc_STRVAR(axis_docstr,
	"axis(x: quat) -> vec3\n"
	"	Returns the `q` rotation axis."
);

#define QUATERNION_TRIGONOMETRIC_METHODS \
{ "angle", (PyCFunction)angle_, METH_O, angle_docstr }, \
{ "axis", (PyCFunction)axis_, METH_O, axis_docstr }, \
{ "angleAxis", (PyCFunction)angleAxis_, METH_VARARGS, angleAxis_docstr }
