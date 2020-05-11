#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
pow_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "pow", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::pow(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
	}

	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::pow(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::pow(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for pow(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(exp)
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(log)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(exp2)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(log2)
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(sqrt)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(inversesqrt)

#define FUNC_EXPONENTIAL { "pow", (PyCFunction)pow_, METH_VARARGS, "pow(base, exponent) -> float, vecn or quat\nReturns 'base' raised to the power 'exponent'." }, \
{ "exp", (PyCFunction)exp_, METH_O, "exp(x) -> float, vecn or quat\nReturns the natural exponentiation of x, i.e., e^x." }, \
{ "log", (PyCFunction)log_, METH_O, "log(v) -> float, vecn or quat\nReturns the natural logarithm of v, i.e.,\nreturns the value y which satisfies the equation x = e^y.\nResults are undefined if v <= 0." }, \
{ "exp2", (PyCFunction)exp2_, METH_O, "exp2(v) -> float or vecn\nReturns 2 raised to the v power." }, \
{ "log2", (PyCFunction)log2_, METH_O, "log2(x) -> float or vecn\nReturns the base 2 log of x, i.e., returns the value y,\nwhich satisfies the equation x = 2 ^ y." }, \
{ "sqrt", (PyCFunction)sqrt_, METH_O, "sqrt(v) -> float, vecn or quat\nReturns the positive square root of v." }, \
{ "inversesqrt", (PyCFunction)inversesqrt_, METH_O, "inversesqrt(v) -> float or vecn\nReturns the reciprocal of the positive square root of v." }
