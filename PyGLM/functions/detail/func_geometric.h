#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(length)

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(distance)
PyGLM_MAKE_GLM_FUNC_NN_VV_QQ__tfF(dot)

static PyObject*
cross_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "cross", arg1, arg2);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
		glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
		glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
		glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
		glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
		return pack(glm::cross(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for cross(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_V_Q__tfF(normalize)

PyGLM_MAKE_GLM_FUNC_NNN_VVV__tfF(faceforward)

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(reflect)

PyGLM_MAKE_GLM_FUNC_NNN_VVN__tfF(refract)

#define FUNC_GEOMETRIC_METHODS { "length", (PyCFunction)length_, METH_O, "length(x) -> float\nReturns the length of x, i.e., sqrt(x * x)." }, \
{ "distance", (PyCFunction)distance_, METH_VARARGS, "distance(p0, p1) -> float\nReturns the distance betwwen p0 and p1, i.e., length(p0 - p1)." }, \
{ "dot", (PyCFunction)dot_, METH_VARARGS, "dot(x, y) -> float\nReturns the dot product of x and y, i.e., result = x * y." }, \
{ "cross", (PyCFunction)cross_, METH_VARARGS, "cross(x, y) -> vec3 or quat\nReturns the cross product of x and y." }, \
{ "normalize", (PyCFunction)normalize_, METH_O, "normalize(x) -> vecn or quat\nReturns a vector in the same direction as x but with length of 1." }, \
{ "faceforward", (PyCFunction)faceforward_, METH_VARARGS, "faceforward(N, I, Nref) -> float or vecn\nIf dot(Nref, I) < 0.0, return N, otherwise, return -N." }, \
{ "reflect", (PyCFunction)reflect_, METH_VARARGS, "reflect(I, N) -> float or vecn\nFor the incident vector I and surface orientation N,\nreturns the reflection direction : result = I - 2.0 * dot(N, I) * N." }, \
{ "refract", (PyCFunction)refract_, METH_VARARGS, "refract(I, N, eta) -> float or vecn\nFor the incident vector I and surface normal N,\nand the ratio of indices of refraction eta,\nreturn the refraction vector." }
