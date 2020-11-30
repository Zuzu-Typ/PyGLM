#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(outerProduct_docstr,
	"outerProduct(c: vecC, r: vecR) -> matRxC\n"
	"	Treats the first parameter `c` as a column vector and the second parameter `r` as a row vector\n"
	"	and does a linear algebraic matrix multiply `c * r`."
);
static PyObject*
outerProduct_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "outerProduct", arg1, arg2);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for outerProduct(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(matrixCompMult_docstr,
	"matrixCompMult(x: matNxM, y: matNxM) -> matNxM\n"
	"	Multiply matrix `x` by matrix `y` component-wise, i.e., `result[i][j]` is the scalar product of\n"
	"	`x[i][j]` and `y[i][j]`."
);
PyGLM_MAKE_GLM_FUNC_MM__tfF(matrixCompMult)

PyDoc_STRVAR(transpose_docstr,
	"transpose(x: matNxM) -> matMxN\n"
	"	Returns the transposed matrix of `x`."
);
PyGLM_MAKE_GLM_FUNC_M(transpose)

PyDoc_STRVAR(determinant_docstr,
	"determinant(m: matSxS) -> float\n"
	"	Return the determinant of a squared matrix."
);
PyGLM_MAKE_GLM_FUNC_S__tfF(determinant)

PyDoc_STRVAR(inverse_docstr,
	"inverse(m: matSxS) -> matSxS\n"
	"	Return the inverse of a squared matrix.\n"
	"inverse(q: quat) -> quat\n"
	"	Return the inverse of a quaternion."
);
PyGLM_MAKE_GLM_FUNC_S_Q__tfF(inverse)

#define FUNC_MATRIX_METHODS \
{ "matrixCompMult", (PyCFunction)matrixCompMult_, METH_VARARGS, matrixCompMult_docstr }, \
{ "outerProduct", (PyCFunction)outerProduct_, METH_VARARGS, outerProduct_docstr }, \
{ "transpose", (PyCFunction)transpose_, METH_O, transpose_docstr }, \
{ "determinant", (PyCFunction)determinant_, METH_O, determinant_docstr }, \
{ "inverse", (PyCFunction)inverse_, METH_O, inverse_docstr }
