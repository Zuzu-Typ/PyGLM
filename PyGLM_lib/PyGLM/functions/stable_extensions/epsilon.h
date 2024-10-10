#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
epsilonEqual_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "epsilonEqual", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			if (glm::epsilonEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3))) {
				Py_RETURN_TRUE;
			}
			else {
				Py_RETURN_FALSE;
			}
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec1 o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::dvec1 o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack_vec(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			glm::quat o = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::quat o2 = PyGLM_Qua_PTI_Get1(float, arg2);
			return pack(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			glm::dquat o = PyGLM_Qua_PTI_Get0(double, arg1);
			glm::dquat o2 = PyGLM_Qua_PTI_Get1(double, arg2);
			return pack(glm::epsilonEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack(glm::epsilonEqual(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for epsilonEqual()");
	return NULL;
}

static PyObject*
epsilonNotEqual_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "epsilonNotEqual", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			if (glm::epsilonNotEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3))) {
				Py_RETURN_TRUE;
			}
			else {
				Py_RETURN_FALSE;
			}
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec1 o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::dvec1 o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack_vec(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			glm::quat o = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::quat o2 = PyGLM_Qua_PTI_Get1(float, arg2);
			return pack(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			glm::dquat o = PyGLM_Qua_PTI_Get0(double, arg1);
			glm::dquat o2 = PyGLM_Qua_PTI_Get1(double, arg2);
			return pack(glm::epsilonNotEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack(glm::epsilonNotEqual(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for epsilonNotEqual()");
	return NULL;
}

PyDoc_STRVAR(epsilonEqual_docstr,
	"epsilonEqual(x: number, y: number, epsilon: number) -> bool\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"epsilonEqual(x: vecN, y: vecN, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`."
);

PyDoc_STRVAR(epsilonNotEqual_docstr,
	"epsilonNotEqual(*args) -> not epsilonEqual(*args)"
);

#define EPSILON_METHODS \
{ "epsilonEqual", (PyCFunction)epsilonEqual_, METH_VARARGS, epsilonEqual_docstr }, \
{ "epsilonNotEqual", (PyCFunction)epsilonNotEqual_, METH_VARARGS, epsilonNotEqual_docstr }
