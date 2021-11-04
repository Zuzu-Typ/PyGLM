#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
lerp_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3;
	PyGLM_Arg_Unpack_3O(args, "lerp", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return PyGLM_PyObject_FromNumber(glm::lerp(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_QUA | PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			float a = PyGLM_Number_FromPyObject<float>(arg3);
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), a));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			double a = PyGLM_Number_FromPyObject<double>(arg3);
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), a));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			float a = PyGLM_Number_FromPyObject<float>(arg3);
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), a));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			double a = PyGLM_Number_FromPyObject<double>(arg3);
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), a));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			float a = PyGLM_Number_FromPyObject<float>(arg3);
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), a));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			double a = PyGLM_Number_FromPyObject<double>(arg3);
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), a));
		}
		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			float a = PyGLM_Number_FromPyObject<float>(arg3);
			PyGLM_ASSERT((a >= 0.0f && a <= 1.0f), "Lerp is only defined in [0, 1]")
			return pack(glm::lerp(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2), a));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			double a = PyGLM_Number_FromPyObject<double>(arg3);
			PyGLM_ASSERT((a >= 0.0 && a <= 1.0), "Lerp is only defined in [0, 1]")
			return pack(glm::lerp(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2), a));
		}
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		PyGLM_PTI_Init2(arg3, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			return pack(glm::lerp(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for lerp()");
	return NULL;
}

static PyObject*
slerp_(PyObject*, PyObject * args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "slerp", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3)) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_QUA | PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			return pack(glm::slerp(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			return pack(glm::slerp(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::slerp(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::slerp(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for slerp()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_Q(conjugate)

PyDoc_STRVAR(conjugate_docstr,
	"conjugate(q: quat) -> quat\n"
	"	Returns the `q` conjugate."
);
PyDoc_STRVAR(lerp_docstr,
	"lerp(x: float, y: float, a: float) -> float\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the\n"
	"	floating-point value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"lerp(x: vecN, y: vecN, a: float) -> vecN\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the\n"
	"	floating-point value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"lerp(x: vecN, y: vecN, a: vecN) -> vecN\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the\n"
	"	vector `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"lerp(x: quat, y: quat, a: float) -> quat\n"
	"	Linear interpolation of two quaternions. The interpolation is oriented."
);
PyDoc_STRVAR(slerp_docstr,
	"slerp(x: quat, y: quat, a: float) -> quat\n"
	"	Spherical linear interpolation of two quaternions. The interpolation always take the short\n"
	"	path and the rotation is performed at constant speed.\n"
	"slerp(x: vec3, y: vec3, a: float) -> vec3\n"
	"	Returns Spherical interpolation between two vectors."
);

#define QUATERNION_COMMON_METHODS \
{ "lerp", (PyCFunction)lerp_, METH_VARARGS, lerp_docstr }, \
{ "slerp", (PyCFunction)slerp_, METH_VARARGS, slerp_docstr }, \
{ "conjugate", (PyCFunction)conjugate_, METH_O, conjugate_docstr }
