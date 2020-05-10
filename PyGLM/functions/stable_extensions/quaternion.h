#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_V3V3__tfF(quatLookAt)
PyGLM_MAKE_GLM_FUNC_V3V3__tfF(quatLookAtLH)
PyGLM_MAKE_GLM_FUNC_V3V3__tfF(quatLookAtRH)

static PyObject*
lerp_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "lerp", arg1, arg2, arg3);
	PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_QUA | PyGLM_DT_FD);
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2) && PyGLM_Number_Check(arg3)) {
		float a = PyGLM_Number_FromPyObject<float>(arg3);
		PyGLM_ASSERT((a >= 0.0f && a <= 1.0f), "Lerp is only defined in [0, 1]")
			return pack(glm::lerp(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2), a));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2) && PyGLM_Number_Check(arg3)) {
		double a = PyGLM_Number_FromPyObject<double>(arg3);
		PyGLM_ASSERT((a >= 0.0 && a <= 1.0), "Lerp is only defined in [0, 1]")
			return pack(glm::lerp(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2), a));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for lerp()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_QQN__tfF(slerp)

PyGLM_MAKE_GLM_FUNC_Q(conjugate)

PyGLM_MAKE_GLM_FUNC_Q(eulerAngles)

PyGLM_MAKE_GLM_FUNC_Q(roll)
PyGLM_MAKE_GLM_FUNC_Q(pitch)
PyGLM_MAKE_GLM_FUNC_Q(yaw)

PyGLM_MAKE_GLM_FUNC_Q(mat3_cast)

PyGLM_MAKE_GLM_FUNC_Q(mat4_cast)

PyGLM_MAKE_GLM_FUNC_M3_M4__tfF(quat_cast)

PyGLM_MAKE_GLM_FUNC_Q(angle)
PyGLM_MAKE_GLM_FUNC_Q(axis)

static PyObject*
angleAxis_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
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

#define QUATERNION_METHODS { "quatLookAt", (PyCFunction)quatLookAt_, METH_VARARGS, "quatLookAt(direction, up) -> quat\nBuild a look at quaternion based on the default handedness." }, \
{ "quatLookAtLH", (PyCFunction)quatLookAtLH_, METH_VARARGS, "quatLookAtLH(direction, up) -> quat\nBuild a left-handed look at quaternion." }, \
{ "quatLookAtRH", (PyCFunction)quatLookAtRH_, METH_VARARGS, "quatLookAtRH(direction, up) -> quat\nBuild a right-handed look at quaternion." }, \
{ "lerp", (PyCFunction)lerp_, METH_VARARGS, "lerp(x, y, a) -> quat\nLinear interpolation of two quaternions.\nThe interpolation is oriented." }, \
{ "slerp", (PyCFunction)slerp_, METH_VARARGS, "slerp(x, y, a) -> quat\nSpherical linear interpolation of two quaternions.\nThe interpolation always take the short path and the rotation is performed at constant speed." }, \
{ "conjugate", (PyCFunction)conjugate_, METH_O, "conjugate(q) -> quat\nReturns the q conjugate." }, \
{ "eulerAngles", (PyCFunction)eulerAngles_, METH_O, "eulerAngles(x) -> vec3\nReturns euler angles, pitch as x, yaw as y, roll as z." }, \
{ "roll", (PyCFunction)roll_, METH_O, "roll(x) -> float\nReturns roll value of euler angles expressed in radians." }, \
{ "pitch", (PyCFunction)pitch_, METH_O, "pitch(x) -> float\nReturns pitch value of euler angles expressed in radians." }, \
{ "yaw", (PyCFunction)yaw_, METH_O, "yaw(x) -> float\nReturns yaw value of euler angles expressed in radians." }, \
{ "mat3_cast", (PyCFunction)mat3_cast_, METH_O, "mat3_cast(x) -> mat3x3\nConverts a quaternion to a 3 * 3 matrix." }, \
{ "mat4_cast", (PyCFunction)mat4_cast_, METH_O, "mat4_cast(x) -> mat4x4\nConverts a quaternion to a 4 * 4 matrix." }, \
{ "quat_cast", (PyCFunction)quat_cast_, METH_O, "quat_cast(m) -> quat\nConverts a 3 * 3 or 4 * 4 matrix to a quaternion." }, \
{ "angle", (PyCFunction)angle_, METH_O, "angle(x) -> float\nReturns the quaternion rotation angle." }, \
{ "axis", (PyCFunction)axis_, METH_O, "axis(x) -> vec3\nReturns the quaternion rotation axis." }, \
{ "angleAxis", (PyCFunction)angleAxis_, METH_VARARGS, "angleAxis(angle, v) -> quat\nBuild a quaternion from an angle and a normalized axis." }
