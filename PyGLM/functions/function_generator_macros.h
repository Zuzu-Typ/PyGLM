#pragma once

#include "../compiler_setup.h"

#include "../types/all.h"

#include "../internal_functions/all.h"


#define PyGLM_MAKE_GLM_FUNC_V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Vec_Check(3, float, arg)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V2__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Vec_Check(2, float, arg)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg)));\
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
	if (PyGLM_Vec_Check(1, float, arg)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
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
	if (PyGLM_Vec_Check(1, float, arg)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg)));\
	}\
	if (PyGLM_Qua_Check(float, arg)) {\
		return pack(glm::NAME(unpack_qua<float>(arg)));\
	}\
	if (PyGLM_Qua_Check(double, arg)) {\
		return pack(glm::NAME(unpack_qua<double>(arg)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Vec_Check(1, float, arg)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg)));\
	}\
	if (PyGLM_Qua_Check(float, arg)) {\
		return pack(glm::NAME(unpack_qua<float>(arg)));\
	}\
	if (PyGLM_Qua_Check(double, arg)) {\
		return pack(glm::NAME(unpack_qua<double>(arg)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_MM__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Mat_Check(2, 2, float, arg1) && PyGLM_Mat_Check(2, 2, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<2, 2, float>(arg1), unpack_mat<2, 2, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(2, 2, double, arg1) && PyGLM_Mat_Check(2, 2, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<2, 2, double>(arg1), unpack_mat<2, 2, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(2, 3, float, arg1) && PyGLM_Mat_Check(2, 3, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<2, 3, float>(arg1), unpack_mat<2, 3, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(2, 3, double, arg1) && PyGLM_Mat_Check(2, 3, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<2, 3, double>(arg1), unpack_mat<2, 3, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(2, 4, float, arg1) && PyGLM_Mat_Check(2, 4, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<2, 4, float>(arg1), unpack_mat<2, 4, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(2, 4, double, arg1) && PyGLM_Mat_Check(2, 4, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<2, 4, double>(arg1), unpack_mat<2, 4, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(3, 2, float, arg1) && PyGLM_Mat_Check(3, 2, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<3, 2, float>(arg1), unpack_mat<3, 2, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(3, 2, double, arg1) && PyGLM_Mat_Check(3, 2, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<3, 2, double>(arg1), unpack_mat<3, 2, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(3, 3, float, arg1) && PyGLM_Mat_Check(3, 3, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<3, 3, float>(arg1), unpack_mat<3, 3, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(3, 3, double, arg1) && PyGLM_Mat_Check(3, 3, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<3, 3, double>(arg1), unpack_mat<3, 3, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(3, 4, float, arg1) && PyGLM_Mat_Check(3, 4, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<3, 4, float>(arg1), unpack_mat<3, 4, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(3, 4, double, arg1) && PyGLM_Mat_Check(3, 4, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<3, 4, double>(arg1), unpack_mat<3, 4, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 2, float, arg1) && PyGLM_Mat_Check(4, 2, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 2, float>(arg1), unpack_mat<4, 2, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 2, double, arg1) && PyGLM_Mat_Check(4, 2, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 2, double>(arg1), unpack_mat<4, 2, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 3, float, arg1) && PyGLM_Mat_Check(4, 3, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 3, float>(arg1), unpack_mat<4, 3, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 3, double, arg1) && PyGLM_Mat_Check(4, 3, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 3, double>(arg1), unpack_mat<4, 3, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 4, float>(arg1), unpack_mat<4, 4, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 4, double>(arg1), unpack_mat<4, 4, double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Mat_Check(2, 2, float, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 2, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 2, double, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 2, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 3, float, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 3, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 3, double, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 3, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 4, float, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 4, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 4, double, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 4, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 2, float, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 2, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 2, double, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 2, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, float, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, double, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 4, float, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 4, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 4, double, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 4, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 2, float, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 2, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 2, double, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 2, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 3, float, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 3, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 3, double, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 3, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, float, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, double, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_S__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Mat_Check(2, 2, float, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 2, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 2, double, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 2, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, float, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, double, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, float, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, double, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_S_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Mat_Check(2, 2, float, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 2, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(2, 2, double, arg)) {\
		return pack(glm::NAME(unpack_mat<2, 2, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, float, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, double, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, float, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, double, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, double>(arg)));\
	}\
	if (PyGLM_Qua_Check(float, arg)) {\
		return pack(glm::NAME(unpack_qua<float>(arg)));\
	}\
	if (PyGLM_Qua_Check(double, arg)) {\
		return pack(glm::NAME(unpack_qua<double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC__rF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject*) {\
	return pack(glm::NAME<double>());\
}

#define PyGLM_MAKE_GLM_FUNC_M4V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 4, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 4, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 4, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 4, int>(arg1), unpack_vec<3, int>(arg2)));\
	}\
	if (PyGLM_Mat_Check(4, 4, glm::uint, arg1) && PyGLM_Vec_Check(3, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_mat<4, 4, glm::uint>(arg1), unpack_vec<3, glm::uint>(arg2)));\
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
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2) && PyGLM_Mat_Check(4, 4, float, arg3) && PyGLM_Vec_Check(4, float, arg4)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_mat<4, 4, float>(arg2), unpack_mat<4, 4, float>(arg3), unpack_vec<4, float>(arg4)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2) && PyGLM_Mat_Check(4, 4, float, arg3) && PyGLM_Vec_Check(4, double, arg4)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_mat<4, 4, float>(arg2), unpack_mat<4, 4, float>(arg3), unpack_vec<4, double>(arg4)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2) && PyGLM_Mat_Check(4, 4, double, arg3) && PyGLM_Vec_Check(4, float, arg4)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_mat<4, 4, double>(arg2), unpack_mat<4, 4, double>(arg3), unpack_vec<4, float>(arg4)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2) && PyGLM_Mat_Check(4, 4, double, arg3) && PyGLM_Vec_Check(4, double, arg4)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_mat<4, 4, double>(arg2), unpack_mat<4, 4, double>(arg3), unpack_vec<4, double>(arg4)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_QQN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Qua_Check(float, arg1) && PyGLM_Qua_Check(float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_qua<float>(arg1), unpack_qua<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Qua_Check(double, arg1) && PyGLM_Qua_Check(double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(unpack_qua<double>(arg1), unpack_qua<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_Q(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Qua_Check(float, arg)) {\
		return pack(glm::NAME(unpack_qua<float>(arg)));\
	}\
	if (PyGLM_Qua_Check(double, arg)) {\
		return pack(glm::NAME(unpack_qua<double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M3_M4__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Mat_Check(3, 3, float, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(3, 3, double, arg)) {\
		return pack(glm::NAME(unpack_mat<3, 3, double>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, float, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, float>(arg)));\
	}\
	if (PyGLM_Mat_Check(4, 4, double, arg)) {\
		return pack(glm::NAME(unpack_mat<4, 4, double>(arg)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Vec_Check(1, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg1), unpack_vec<1, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::uint, arg1) && PyGLM_Vec_Check(1, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::uint>(arg1), unpack_vec<1, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Vec_Check(1, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg1), unpack_vec<1, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u64, arg1) && PyGLM_Vec_Check(1, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u64>(arg1), unpack_vec<1, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Vec_Check(1, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg1), unpack_vec<1, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u16, arg1) && PyGLM_Vec_Check(1, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u16>(arg1), unpack_vec<1, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Vec_Check(1, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg1), unpack_vec<1, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u8, arg1) && PyGLM_Vec_Check(1, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u8>(arg1), unpack_vec<1, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, bool, arg1) && PyGLM_Vec_Check(1, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, bool>(arg1), unpack_vec<1, bool>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Vec_Check(2, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg1), unpack_vec<2, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::uint, arg1) && PyGLM_Vec_Check(2, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::uint>(arg1), unpack_vec<2, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Vec_Check(2, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg1), unpack_vec<2, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u64, arg1) && PyGLM_Vec_Check(2, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u64>(arg1), unpack_vec<2, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Vec_Check(2, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg1), unpack_vec<2, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u16, arg1) && PyGLM_Vec_Check(2, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u16>(arg1), unpack_vec<2, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Vec_Check(2, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg1), unpack_vec<2, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u8, arg1) && PyGLM_Vec_Check(2, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u8>(arg1), unpack_vec<2, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, bool, arg1) && PyGLM_Vec_Check(2, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, bool>(arg1), unpack_vec<2, bool>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg1), unpack_vec<3, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::uint, arg1) && PyGLM_Vec_Check(3, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::uint>(arg1), unpack_vec<3, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Vec_Check(3, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg1), unpack_vec<3, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u64, arg1) && PyGLM_Vec_Check(3, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u64>(arg1), unpack_vec<3, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Vec_Check(3, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg1), unpack_vec<3, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u16, arg1) && PyGLM_Vec_Check(3, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u16>(arg1), unpack_vec<3, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Vec_Check(3, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg1), unpack_vec<3, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u8, arg1) && PyGLM_Vec_Check(3, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u8>(arg1), unpack_vec<3, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, bool, arg1) && PyGLM_Vec_Check(3, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, bool>(arg1), unpack_vec<3, bool>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Vec_Check(4, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg1), unpack_vec<4, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::uint, arg1) && PyGLM_Vec_Check(4, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::uint>(arg1), unpack_vec<4, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Vec_Check(4, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg1), unpack_vec<4, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u64, arg1) && PyGLM_Vec_Check(4, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u64>(arg1), unpack_vec<4, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Vec_Check(4, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg1), unpack_vec<4, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u16, arg1) && PyGLM_Vec_Check(4, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u16>(arg1), unpack_vec<4, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Vec_Check(4, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg1), unpack_vec<4, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u8, arg1) && PyGLM_Vec_Check(4, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u8>(arg1), unpack_vec<4, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, bool, arg1) && PyGLM_Vec_Check(4, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, bool>(arg1), unpack_vec<4, bool>(arg2)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Vec_Check(1, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg1), unpack_vec<1, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::uint, arg1) && PyGLM_Vec_Check(1, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::uint>(arg1), unpack_vec<1, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Vec_Check(1, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg1), unpack_vec<1, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u64, arg1) && PyGLM_Vec_Check(1, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u64>(arg1), unpack_vec<1, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Vec_Check(1, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg1), unpack_vec<1, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u16, arg1) && PyGLM_Vec_Check(1, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u16>(arg1), unpack_vec<1, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Vec_Check(1, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg1), unpack_vec<1, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u8, arg1) && PyGLM_Vec_Check(1, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u8>(arg1), unpack_vec<1, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Vec_Check(2, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg1), unpack_vec<2, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::uint, arg1) && PyGLM_Vec_Check(2, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::uint>(arg1), unpack_vec<2, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Vec_Check(2, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg1), unpack_vec<2, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u64, arg1) && PyGLM_Vec_Check(2, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u64>(arg1), unpack_vec<2, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Vec_Check(2, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg1), unpack_vec<2, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u16, arg1) && PyGLM_Vec_Check(2, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u16>(arg1), unpack_vec<2, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Vec_Check(2, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg1), unpack_vec<2, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u8, arg1) && PyGLM_Vec_Check(2, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u8>(arg1), unpack_vec<2, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg1), unpack_vec<3, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::uint, arg1) && PyGLM_Vec_Check(3, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::uint>(arg1), unpack_vec<3, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Vec_Check(3, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg1), unpack_vec<3, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u64, arg1) && PyGLM_Vec_Check(3, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u64>(arg1), unpack_vec<3, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Vec_Check(3, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg1), unpack_vec<3, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u16, arg1) && PyGLM_Vec_Check(3, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u16>(arg1), unpack_vec<3, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Vec_Check(3, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg1), unpack_vec<3, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u8, arg1) && PyGLM_Vec_Check(3, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u8>(arg1), unpack_vec<3, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Vec_Check(4, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg1), unpack_vec<4, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::uint, arg1) && PyGLM_Vec_Check(4, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::uint>(arg1), unpack_vec<4, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Vec_Check(4, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg1), unpack_vec<4, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u64, arg1) && PyGLM_Vec_Check(4, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u64>(arg1), unpack_vec<4, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Vec_Check(4, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg1), unpack_vec<4, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u16, arg1) && PyGLM_Vec_Check(4, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u16>(arg1), unpack_vec<4, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Vec_Check(4, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg1), unpack_vec<4, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u8, arg1) && PyGLM_Vec_Check(4, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u8>(arg1), unpack_vec<4, glm::u8>(arg2)));\
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
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));\
	}\
	if (PyGLM_Qua_Check(float, arg1) && PyGLM_Qua_Check(float, arg2)) {\
		return pack(glm::NAME(unpack_qua<float>(arg1), unpack_qua<float>(arg2)));\
	}\
	if (PyGLM_Qua_Check(double, arg1) && PyGLM_Qua_Check(double, arg2)) {\
		return pack(glm::NAME(unpack_qua<double>(arg1), unpack_qua<double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<glm::i64>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg)));\
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
		return pack(glm::NAME(PyGLM_Number_FromPyObject<glm::i64>(arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Vec_Check(1, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg1), unpack_vec<1, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Vec_Check(1, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg1), unpack_vec<1, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Vec_Check(1, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg1), unpack_vec<1, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Vec_Check(1, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg1), unpack_vec<1, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Vec_Check(2, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg1), unpack_vec<2, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Vec_Check(2, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg1), unpack_vec<2, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Vec_Check(2, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg1), unpack_vec<2, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Vec_Check(2, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg1), unpack_vec<2, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg1), unpack_vec<3, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Vec_Check(3, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg1), unpack_vec<3, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Vec_Check(3, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg1), unpack_vec<3, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Vec_Check(3, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg1), unpack_vec<3, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Vec_Check(4, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg1), unpack_vec<4, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Vec_Check(4, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg1), unpack_vec<4, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Vec_Check(4, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg1), unpack_vec<4, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Vec_Check(4, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg1), unpack_vec<4, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg1), PyGLM_Number_FromPyObject<int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));\
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
		return pack(glm::NAME(PyGLM_Number_FromPyObject<glm::i64>(arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Vec_Check(1, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg1), unpack_vec<1, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Vec_Check(1, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg1), unpack_vec<1, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Vec_Check(1, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg1), unpack_vec<1, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Vec_Check(1, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg1), unpack_vec<1, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Vec_Check(2, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg1), unpack_vec<2, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Vec_Check(2, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg1), unpack_vec<2, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Vec_Check(2, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg1), unpack_vec<2, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Vec_Check(2, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg1), unpack_vec<2, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg1), unpack_vec<3, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Vec_Check(3, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg1), unpack_vec<3, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Vec_Check(3, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg1), unpack_vec<3, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Vec_Check(3, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg1), unpack_vec<3, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Vec_Check(4, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg1), unpack_vec<4, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Vec_Check(4, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg1), unpack_vec<4, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Vec_Check(4, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg1), unpack_vec<4, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Vec_Check(4, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg1), unpack_vec<4, glm::i8>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_VV(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Vec_Check(1, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, int>(arg1), unpack_vec<1, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::uint, arg1) && PyGLM_Vec_Check(1, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::uint>(arg1), unpack_vec<1, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Vec_Check(1, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i64>(arg1), unpack_vec<1, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u64, arg1) && PyGLM_Vec_Check(1, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u64>(arg1), unpack_vec<1, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Vec_Check(1, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i16>(arg1), unpack_vec<1, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u16, arg1) && PyGLM_Vec_Check(1, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u16>(arg1), unpack_vec<1, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Vec_Check(1, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::i8>(arg1), unpack_vec<1, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, glm::u8, arg1) && PyGLM_Vec_Check(1, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, glm::u8>(arg1), unpack_vec<1, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(1, bool, arg1) && PyGLM_Vec_Check(1, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<1, bool>(arg1), unpack_vec<1, bool>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Vec_Check(2, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, int>(arg1), unpack_vec<2, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::uint, arg1) && PyGLM_Vec_Check(2, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::uint>(arg1), unpack_vec<2, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Vec_Check(2, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i64>(arg1), unpack_vec<2, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u64, arg1) && PyGLM_Vec_Check(2, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u64>(arg1), unpack_vec<2, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Vec_Check(2, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i16>(arg1), unpack_vec<2, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u16, arg1) && PyGLM_Vec_Check(2, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u16>(arg1), unpack_vec<2, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Vec_Check(2, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::i8>(arg1), unpack_vec<2, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, glm::u8, arg1) && PyGLM_Vec_Check(2, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, glm::u8>(arg1), unpack_vec<2, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(2, bool, arg1) && PyGLM_Vec_Check(2, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<2, bool>(arg1), unpack_vec<2, bool>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, int>(arg1), unpack_vec<3, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::uint, arg1) && PyGLM_Vec_Check(3, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::uint>(arg1), unpack_vec<3, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Vec_Check(3, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i64>(arg1), unpack_vec<3, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u64, arg1) && PyGLM_Vec_Check(3, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u64>(arg1), unpack_vec<3, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Vec_Check(3, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i16>(arg1), unpack_vec<3, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u16, arg1) && PyGLM_Vec_Check(3, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u16>(arg1), unpack_vec<3, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Vec_Check(3, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::i8>(arg1), unpack_vec<3, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, glm::u8, arg1) && PyGLM_Vec_Check(3, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, glm::u8>(arg1), unpack_vec<3, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(3, bool, arg1) && PyGLM_Vec_Check(3, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<3, bool>(arg1), unpack_vec<3, bool>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Vec_Check(4, int, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, int>(arg1), unpack_vec<4, int>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::uint, arg1) && PyGLM_Vec_Check(4, glm::uint, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::uint>(arg1), unpack_vec<4, glm::uint>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Vec_Check(4, glm::i64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i64>(arg1), unpack_vec<4, glm::i64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u64, arg1) && PyGLM_Vec_Check(4, glm::u64, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u64>(arg1), unpack_vec<4, glm::u64>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Vec_Check(4, glm::i16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i16>(arg1), unpack_vec<4, glm::i16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u16, arg1) && PyGLM_Vec_Check(4, glm::u16, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u16>(arg1), unpack_vec<4, glm::u16>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Vec_Check(4, glm::i8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::i8>(arg1), unpack_vec<4, glm::i8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, glm::u8, arg1) && PyGLM_Vec_Check(4, glm::u8, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, glm::u8>(arg1), unpack_vec<4, glm::u8>(arg2)));\
	}\
	if (PyGLM_Vec_Check(4, bool, arg1) && PyGLM_Vec_Check(4, bool, arg2)) {\
		return pack(glm::NAME(unpack_vec<4, bool>(arg1), unpack_vec<4, bool>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}
