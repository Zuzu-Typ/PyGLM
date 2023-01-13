#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(pow_docstr,
	"pow(base: float, exponent: float) -> float\n"
	"	Returns base raised to the power exponent.\n"
	"pow(base: vecN, exponent: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `base[i]` raised to the power `exponent[i]`.\n"
	"pow(base: quat, exponent: quat) -> quat\n"
	"	Returns a quaternion raised to a power."
);
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

PyDoc_STRVAR(exp_docstr,
	"exp(x: float) -> float\n"
	"	Returns the natural exponentiation of `x`, i.e., `e^x`.\n"
	"exp(x: vecN) -> vecN\n"
	"	For every component c of x:\n"
	"	Returns the natural exponentiation of `c`, i.e., `e^c`.\n"
	"exp(x: quat) -> quat\n"
	"	Returns an exponential of a quaternion."
);
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(exp)

PyDoc_STRVAR(log_docstr,
	"log(x: float) -> float\n"
	"	Returns the natural logarithm of `x`, i.e., returns the value `y` which satisfies the equation\n"
	"	`x = e^y`. Results are undefined if `x <= 0`.\n"
	"log(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the natural logarithm of `c`, i.e., returns the value `y` which satisfies the equation\n"
	"	`c = e^y`. Results are undefined if `c <= 0`.\n"
	"log(x: quat) -> quat\n"
	"	Returns a logarithm of a quaternion."
);
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(log)

PyDoc_STRVAR(exp2_docstr,
	"exp2(x: float) -> float\n"
	"	Returns `2` raised to the `x` power.\n"
	"exp2(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns `2` raised to the `c` power."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(exp2)

PyDoc_STRVAR(log2_docstr,
	"log2(x: float) -> float\n"
	"	Returns the base `2` log of `x`, i.e., returns the value `y`, which satisfies the equation\n"
	"	`x = 2 ^ y`.\n"
	"log2(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the base `2` log of `c`, i.e., returns the value `y`, which satisfies the equation\n"
	"	`c = 2 ^ y`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(log2)

PyDoc_STRVAR(sqrt_docstr,
	"sqrt(x: float) -> float\n"
	"	Returns the positive square root of `x`.\n"
	"sqrt(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the positive square root of `c`.\n"
	"sqrt(x: quat) -> quat\n"
	"	Returns the square root of a quaternion."
);
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(sqrt)

PyDoc_STRVAR(inversesqrt_docstr,
	"inversesqrt(x: float) -> float\n"
	"	Returns the reciprocal of the positive square root of `x`.\n"
	"inversesqrt(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the reciprocal of the positive square root of `c`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(inversesqrt)

#define FUNC_EXPONENTIAL \
{ "pow", (PyCFunction)pow_, METH_VARARGS, pow_docstr }, \
{ "exp", (PyCFunction)exp_, METH_O, exp_docstr }, \
{ "log", (PyCFunction)log_, METH_O, log_docstr }, \
{ "exp2", (PyCFunction)exp2_, METH_O, exp2_docstr }, \
{ "log2", (PyCFunction)log2_, METH_O, log2_docstr }, \
{ "sqrt", (PyCFunction)sqrt_, METH_O, sqrt_docstr }, \
{ "inversesqrt", (PyCFunction)inversesqrt_, METH_O, inversesqrt_docstr }
