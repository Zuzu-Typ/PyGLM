#pragma once

#include "../compiler_setup.h"

#include "../types/all.h"

#include "../internal_functions/all.h"


#define PyGLM_MAKE_GLM_FUNC_V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V2__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg)));\
	}\
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NNN_VVV_VNN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init2(arg3, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg)));\
	}\
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_PTI_IsVec(0)) {\
		if (PyGLM_Vec_PTI_Check0(1, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(1, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(2, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(2, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(4, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(4, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg)));\
		}\
	}\
	if (PyGLM_Qua_PTI_Check0(float, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_PTI_IsVec(0)) {\
		if (PyGLM_Vec_PTI_Check0(1, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(1, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(2, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(2, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(4, float, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg)));\
		}\
		if (PyGLM_Vec_PTI_Check0(4, double, arg)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg)));\
		}\
	}\
	if (PyGLM_Qua_PTI_Check0(float, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_NNN_VVV__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init2(arg3, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NNN_VVN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_MM__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, float, arg1), PyGLM_Mat_PTI_Get1(2, 2, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, double, arg1), PyGLM_Mat_PTI_Get1(2, 2, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, float, arg1), PyGLM_Mat_PTI_Get1(2, 3, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, double, arg1), PyGLM_Mat_PTI_Get1(2, 3, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, float, arg1), PyGLM_Mat_PTI_Get1(2, 4, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, double, arg1), PyGLM_Mat_PTI_Get1(2, 4, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, float, arg1), PyGLM_Mat_PTI_Get1(3, 2, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, double, arg1), PyGLM_Mat_PTI_Get1(3, 2, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg1), PyGLM_Mat_PTI_Get1(3, 3, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg1), PyGLM_Mat_PTI_Get1(3, 3, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, float, arg1), PyGLM_Mat_PTI_Get1(3, 4, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, double, arg1), PyGLM_Mat_PTI_Get1(3, 4, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, float, arg1), PyGLM_Mat_PTI_Get1(4, 2, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, double, arg1), PyGLM_Mat_PTI_Get1(4, 2, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, float, arg1), PyGLM_Mat_PTI_Get1(4, 3, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, double, arg1), PyGLM_Mat_PTI_Get1(4, 3, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg1), PyGLM_Mat_PTI_Get1(4, 4, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg1), PyGLM_Mat_PTI_Get1(4, 4, double, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Mat_PTI_Check0(2, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);\
	if (PyGLM_Mat_PTI_Check0(2, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 2, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 2, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 3, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 3, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 4, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 4, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 2, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 2, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 4, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 4, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 2, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 2, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 3, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 3, uint32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, int32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, int32, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, uint32, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, uint32, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_S__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_SHAPE_SQUARE | PyGLM_DT_FD);\
	if (PyGLM_Mat_PTI_Check0(2, 2, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(2, 2, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_S_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_SQUARE | PyGLM_DT_FD);\
	if (PyGLM_PTI_IsMat(0)) {\
		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, float, arg)));\
		}\
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(2, 2, double, arg)));\
		}\
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));\
		}\
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));\
		}\
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));\
		}\
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));\
		}\
	}\
	if (PyGLM_Qua_PTI_Check0(float, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC__rF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject*) {\
	return pack(glm::NAME<double>());\
}

#define PyGLM_MAKE_GLM_FUNC_M3V2_M4V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4 | PyGLM_DT_NORMAL);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_DT_NORMAL);\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M3N__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg2)) {\
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_FD);\
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
		}\
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {\
			return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
		}\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M4V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_NORMAL);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_NORMAL);\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;\
	PyGLM_Arg_Unpack_6O(args, #NAME, arg1, arg2, arg3, arg4, arg5, arg6);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3), PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5), PyGLM_Number_FromPyObject<float>(arg6)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NNNN__tf(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4;\
	PyGLM_Arg_Unpack_4O(args, #NAME, arg1, arg2, arg3, arg4);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3), PyGLM_Number_FromPyObject<float>(arg4)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NNN__tf(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4;\
	PyGLM_Arg_Unpack_4O(args, #NAME, arg1, arg2, arg3, arg4);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);\
	PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);\
	PyGLM_PTI_Init3(arg4, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2) && PyGLM_Mat_PTI_Check2(4, 4, float, arg3) && PyGLM_Vec_PTI_Check3(4, float, arg4)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Mat_PTI_Get1(4, 4, float, arg2), PyGLM_Mat_PTI_Get2(4, 4, float, arg3), PyGLM_Vec_PTI_Get3(4, float, arg4)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2) && PyGLM_Mat_PTI_Check2(4, 4, float, arg3) && PyGLM_Vec_PTI_Check3(4, double, arg4)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Mat_PTI_Get1(4, 4, float, arg2), PyGLM_Mat_PTI_Get2(4, 4, float, arg3), PyGLM_Vec_PTI_Get3(4, double, arg4)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2) && PyGLM_Mat_PTI_Check2(4, 4, double, arg3) && PyGLM_Vec_PTI_Check3(4, float, arg4)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Mat_PTI_Get1(4, 4, double, arg2), PyGLM_Mat_PTI_Get2(4, 4, double, arg3), PyGLM_Vec_PTI_Get3(4, float, arg4)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2) && PyGLM_Mat_PTI_Check2(4, 4, double, arg3) && PyGLM_Vec_PTI_Check3(4, double, arg4)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Mat_PTI_Get1(4, 4, double, arg2), PyGLM_Mat_PTI_Get2(4, 4, double, arg3), PyGLM_Vec_PTI_Get3(4, double, arg4)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2 = NULL;\
	if (!PyArg_UnpackTuple(args, #NAME, 1, 2, &arg1, &arg2)) return NULL;\
	if (arg2 == NULL) {\
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1)));\
		}\
	}\
	else {\
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);\
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
		}\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_QQN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_QUA | PyGLM_DT_FD);\
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_Q(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_QUA | PyGLM_DT_FD);\
	if (PyGLM_Qua_PTI_Check0(float, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M3_M4__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);\
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));\
	}\
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {\
		return pack(glm::NAME(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg1) && PyGLM_Vec_PTI_Check1(1, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint32, arg1), PyGLM_Vec_PTI_Get1(1, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg1) && PyGLM_Vec_PTI_Check1(1, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint64, arg1), PyGLM_Vec_PTI_Get1(1, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg1) && PyGLM_Vec_PTI_Check1(1, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint16, arg1), PyGLM_Vec_PTI_Get1(1, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg1) && PyGLM_Vec_PTI_Check1(1, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint8, arg1), PyGLM_Vec_PTI_Get1(1, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, bool, arg1), PyGLM_Vec_PTI_Get1(1, bool, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg1) && PyGLM_Vec_PTI_Check1(2, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint32, arg1), PyGLM_Vec_PTI_Get1(2, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg1) && PyGLM_Vec_PTI_Check1(2, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint64, arg1), PyGLM_Vec_PTI_Get1(2, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg1) && PyGLM_Vec_PTI_Check1(2, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint16, arg1), PyGLM_Vec_PTI_Get1(2, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg1) && PyGLM_Vec_PTI_Check1(2, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint8, arg1), PyGLM_Vec_PTI_Get1(2, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, bool, arg1), PyGLM_Vec_PTI_Get1(2, bool, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg1) && PyGLM_Vec_PTI_Check1(3, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint64, arg1), PyGLM_Vec_PTI_Get1(3, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg1) && PyGLM_Vec_PTI_Check1(3, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint16, arg1), PyGLM_Vec_PTI_Get1(3, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg1) && PyGLM_Vec_PTI_Check1(3, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint8, arg1), PyGLM_Vec_PTI_Get1(3, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, bool, arg1), PyGLM_Vec_PTI_Get1(3, bool, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg1) && PyGLM_Vec_PTI_Check1(4, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint32, arg1), PyGLM_Vec_PTI_Get1(4, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg1) && PyGLM_Vec_PTI_Check1(4, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint64, arg1), PyGLM_Vec_PTI_Get1(4, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg1) && PyGLM_Vec_PTI_Check1(4, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint16, arg1), PyGLM_Vec_PTI_Get1(4, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg1) && PyGLM_Vec_PTI_Check1(4, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint8, arg1), PyGLM_Vec_PTI_Get1(4, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, bool, arg1), PyGLM_Vec_PTI_Get1(4, bool, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV__tGPL(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg1) && PyGLM_Vec_PTI_Check1(1, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint32, arg1), PyGLM_Vec_PTI_Get1(1, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg1) && PyGLM_Vec_PTI_Check1(1, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint64, arg1), PyGLM_Vec_PTI_Get1(1, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg1) && PyGLM_Vec_PTI_Check1(1, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint16, arg1), PyGLM_Vec_PTI_Get1(1, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg1) && PyGLM_Vec_PTI_Check1(1, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint8, arg1), PyGLM_Vec_PTI_Get1(1, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg1) && PyGLM_Vec_PTI_Check1(2, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint32, arg1), PyGLM_Vec_PTI_Get1(2, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg1) && PyGLM_Vec_PTI_Check1(2, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint64, arg1), PyGLM_Vec_PTI_Get1(2, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg1) && PyGLM_Vec_PTI_Check1(2, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint16, arg1), PyGLM_Vec_PTI_Get1(2, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg1) && PyGLM_Vec_PTI_Check1(2, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint8, arg1), PyGLM_Vec_PTI_Get1(2, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg1) && PyGLM_Vec_PTI_Check1(3, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint64, arg1), PyGLM_Vec_PTI_Get1(3, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg1) && PyGLM_Vec_PTI_Check1(3, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint16, arg1), PyGLM_Vec_PTI_Get1(3, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg1) && PyGLM_Vec_PTI_Check1(3, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint8, arg1), PyGLM_Vec_PTI_Get1(3, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg1) && PyGLM_Vec_PTI_Check1(4, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint32, arg1), PyGLM_Vec_PTI_Get1(4, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg1) && PyGLM_Vec_PTI_Check1(4, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint64, arg1), PyGLM_Vec_PTI_Get1(4, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg1) && PyGLM_Vec_PTI_Check1(4, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint16, arg1), PyGLM_Vec_PTI_Get1(4, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg1) && PyGLM_Vec_PTI_Check1(4, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint8, arg1), PyGLM_Vec_PTI_Get1(4, uint8, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV_QQ__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_PTI_IsVec(0)) {\
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
		}\
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
			return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
		}\
	}\
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<int64>(arg)));\
	}\
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);\
	if (PyGLM_Vec_PTI_Check0(1, int, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tiqsu(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<int64>(arg1), PyGLM_Number_FromPyObject<int64>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);\
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Number_FromPyObject<int64>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Number_FromPyObject<int16>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Number_FromPyObject<int8>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Number_FromPyObject<int64>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Number_FromPyObject<int16>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Number_FromPyObject<int8>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Number_FromPyObject<int64>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Number_FromPyObject<int16>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Number_FromPyObject<int8>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Number_FromPyObject<int64>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Number_FromPyObject<int16>(arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Number_FromPyObject<int8>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<int64>(arg1), PyGLM_Number_FromPyObject<int64>(arg2)));\
	}\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);\
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_VV_QQ(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg1) && PyGLM_Vec_PTI_Check1(1, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint32, arg1), PyGLM_Vec_PTI_Get1(1, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg1) && PyGLM_Vec_PTI_Check1(1, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint64, arg1), PyGLM_Vec_PTI_Get1(1, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg1) && PyGLM_Vec_PTI_Check1(1, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint16, arg1), PyGLM_Vec_PTI_Get1(1, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg1) && PyGLM_Vec_PTI_Check1(1, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, uint8, arg1), PyGLM_Vec_PTI_Get1(1, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, bool, arg1), PyGLM_Vec_PTI_Get1(1, bool, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg1) && PyGLM_Vec_PTI_Check1(2, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint32, arg1), PyGLM_Vec_PTI_Get1(2, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg1) && PyGLM_Vec_PTI_Check1(2, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint64, arg1), PyGLM_Vec_PTI_Get1(2, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg1) && PyGLM_Vec_PTI_Check1(2, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint16, arg1), PyGLM_Vec_PTI_Get1(2, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg1) && PyGLM_Vec_PTI_Check1(2, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, uint8, arg1), PyGLM_Vec_PTI_Get1(2, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, bool, arg1), PyGLM_Vec_PTI_Get1(2, bool, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg1) && PyGLM_Vec_PTI_Check1(3, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint64, arg1), PyGLM_Vec_PTI_Get1(3, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg1) && PyGLM_Vec_PTI_Check1(3, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint16, arg1), PyGLM_Vec_PTI_Get1(3, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg1) && PyGLM_Vec_PTI_Check1(3, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, uint8, arg1), PyGLM_Vec_PTI_Get1(3, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, bool, arg1), PyGLM_Vec_PTI_Get1(3, bool, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg1) && PyGLM_Vec_PTI_Check1(4, uint32, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint32, arg1), PyGLM_Vec_PTI_Get1(4, uint32, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg1) && PyGLM_Vec_PTI_Check1(4, uint64, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint64, arg1), PyGLM_Vec_PTI_Get1(4, uint64, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg1) && PyGLM_Vec_PTI_Check1(4, uint16, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint16, arg1), PyGLM_Vec_PTI_Get1(4, uint16, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg1) && PyGLM_Vec_PTI_Check1(4, uint8, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, uint8, arg1), PyGLM_Vec_PTI_Get1(4, uint8, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, bool, arg1), PyGLM_Vec_PTI_Get1(4, bool, arg2)));\
	}\
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2)));\
	}\
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {\
		return pack(glm::NAME(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}


#define PyGLM_MAKE_GLM_FUNC_VV__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);\
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));\
	}\
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {\
		return pack(glm::NAME(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}
