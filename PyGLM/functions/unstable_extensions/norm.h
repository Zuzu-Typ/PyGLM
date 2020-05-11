#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_VV__tfF(distance2)


PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(l1Norm)
PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(l2Norm)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(length2)

static PyObject*
lxNorm_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "lxNorm", 2, 3, &arg1, &arg2, &arg3)) return NULL;

	if (arg3 == NULL) {
		if (PyLong_Check(arg2)) {
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
				return pack(glm::lxNorm(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_AsUnsignedLong(arg2)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
				return pack(glm::lxNorm(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_AsUnsignedLong(arg2)));
			}
		}
	}
	else {
		if (PyLong_Check(arg3)) {
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
				return pack(glm::lxNorm(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Number_AsUnsignedLong(arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
				return pack(glm::lxNorm(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Number_AsUnsignedLong(arg3)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for lxNorm()");
	return NULL;
}

#define NORM_METHODS { "distance2", (PyCFunction)distance2_, METH_VARARGS, "distance2(p0, p1) -> float\nReturns the squared distance between p0 and p1, i.e., length2(p0 - p1)." }, \
{ "l1Norm", (PyCFunction)l1Norm_, METH_VARARGS, "l1Norm(x[, y]) -> float\nReturns the L1 norm of x or the L1 norm between x and y respectively." }, \
{ "l2Norm", (PyCFunction)l2Norm_, METH_VARARGS, "l2Norm(x[, y]) -> float\nReturns the L2 norm of x or the L2 norm between x and y respectively." }, \
{ "length2", (PyCFunction)length2_, METH_O, "length2(x) -> float\nReturns the squared length of x." }, \
{ "lxNorm", (PyCFunction)lxNorm_, METH_VARARGS, "lxNorm(x[, y], Depth) -> float\nReturns the L norm of x or the L norm between x and y respectively." }
