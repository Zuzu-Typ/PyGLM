#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_VV__tfF(distance2)


PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(l1Norm)
PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(l2Norm)
PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(lMaxNorm)

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

PyDoc_STRVAR(distance2_docstr,
	"distance2(p0: vecN, p1: vecN) -> float\n"
	"	Returns the squared distance between `p0` and `p1`, i.e., `length2(p0 - p1)`."
);
PyDoc_STRVAR(l1Norm_docstr,
	"l1Norm(v: vec3) -> float\n"
	"	Returns the L1 norm of `v`.\n"
	"l1Norm(x: vec3, y: vec3) -> float\n"
	"	Returns the L1 norm between `x` and `y`."
);
PyDoc_STRVAR(l2Norm_docstr,
	"l2Norm(v: vec3) -> float\n"
	"	Returns the L2 norm of `v`.\n"
	"l2Norm(x: vec3, y: vec3) -> float\n"
	"	Returns the L2 norm between `x` and `y`."
);
PyDoc_STRVAR(length2_docstr,
	"length2(v: vecN) -> float\n"
	"	Returns the squared length of `x`."
);
PyDoc_STRVAR(lMaxNorm_docstr,
	"lMaxNorm(v: vec3) -> float\n"
	"	Returns the LMax norm of `v`.\n"
	"lMaxNorm(x: vec3, y: vec3) -> float\n"
	"	Returns the LMax norm between `x` and `y`."
);
PyDoc_STRVAR(lxNorm_docstr,
	"lxNorm(v: vec3, Depth: int) -> float\n"
	"	Returns the L norm of `v`.\n"
	"lxNorm(x: vec3, y: vec3, Depth: int) -> float\n"
	"	Returns the L norm between `x` and `y`."
);

#define NORM_METHODS \
{ "distance2", (PyCFunction)distance2_, METH_VARARGS, distance2_docstr }, \
{ "l1Norm", (PyCFunction)l1Norm_, METH_VARARGS, l1Norm_docstr }, \
{ "l2Norm", (PyCFunction)l2Norm_, METH_VARARGS, l2Norm_docstr }, \
{ "lMaxNorm", (PyCFunction)lMaxNorm_, METH_VARARGS, lMaxNorm_docstr }, \
{ "length2", (PyCFunction)length2_, METH_O, length2_docstr }, \
{ "lxNorm", (PyCFunction)lxNorm_, METH_VARARGS, lxNorm_docstr }
