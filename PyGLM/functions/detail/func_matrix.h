#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
outerProduct_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "outerProduct", arg1, arg2);
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
		glm::vec2 o;
		glm::vec2 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
		glm::vec2 o;
		glm::vec3 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
		glm::vec2 o;
		glm::vec4 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
		glm::vec3 o;
		glm::vec2 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
		glm::vec3 o;
		glm::vec3 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
		glm::vec3 o;
		glm::vec4 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
		glm::vec4 o;
		glm::vec2 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
		glm::vec4 o;
		glm::vec3 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
		glm::vec4 o;
		glm::vec4 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
		glm::dvec2 o;
		glm::dvec2 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
		glm::dvec2 o;
		glm::dvec3 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
		glm::dvec2 o;
		glm::dvec4 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
		glm::dvec3 o;
		glm::dvec2 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
		glm::dvec3 o;
		glm::dvec3 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
		glm::dvec3 o;
		glm::dvec4 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
		glm::dvec4 o;
		glm::dvec2 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
		glm::dvec4 o;
		glm::dvec3 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
		glm::dvec4 o;
		glm::dvec4 o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		return pack(glm::outerProduct(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for outerProduct(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_MM__tfF(matrixCompMult)
PyGLM_MAKE_GLM_FUNC_M__tfF(transpose)
PyGLM_MAKE_GLM_FUNC_S__tfF(determinant)
PyGLM_MAKE_GLM_FUNC_S_Q__tfF(inverse)

#define FUNC_MATRIX_METHODS { "matrixCompMult", (PyCFunction)matrixCompMult_, METH_VARARGS, "matrixCompMult(x, y) -> matnxn\nMultiply matrix x by matrix y component-wise, i.e.,\nresult[i][j] is the scalar product of x[i][j] and y[i][j]." }, \
{ "outerProduct", (PyCFunction)outerProduct_, METH_VARARGS, "outerProduct(c, r) -> matnxn\nTreats the first parameter c as a column vector\nand the second parameter r as a row vector\nand does a linear algebraic matrix multiply c * r." }, \
{ "transpose", (PyCFunction)transpose_, METH_O, "transpose(x) -> matnxn\nReturns the transposed matrix of x" }, \
{ "determinant", (PyCFunction)determinant_, METH_O, "determinant(x) -> float\nReturn the determinant of a squared matrix." }, \
{ "inverse", (PyCFunction)inverse_, METH_O, "inverse(x) -> matnxn or quat\nReturn the inverse of a squared matrix or quaternion." }
