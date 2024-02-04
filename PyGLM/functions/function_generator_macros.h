#pragma once

#include "../compiler_setup.h"

#include "../types/all.h"

//#include "../internal_functions/all.h"

// Repeats the code with T in [float, double, int32, uint32, int64, uint64, int16, uint16, int8, uint8, bool]
#define PyGLM_CODEGEN_PARAM_T_Vec_ALL(MACRO, L)\
MACRO(L, float)\
MACRO(L, double)\
MACRO(L, int32)\
MACRO(L, uint32)\
MACRO(L, int64)\
MACRO(L, uint64)\
MACRO(L, int16)\
MACRO(L, uint16)\
MACRO(L, int8)\
MACRO(L, uint8)\
MACRO(L, bool)

// Repeats the code with T in [float, double, int32, uint32, int64, uint64, int16, uint16, int8, uint8]
#define PyGLM_CODEGEN_PARAM_T_Vec_fFiqsuIQSU(MACRO, L)\
MACRO(L, float)\
MACRO(L, double)\
MACRO(L, int32)\
MACRO(L, uint32)\
MACRO(L, int64)\
MACRO(L, uint64)\
MACRO(L, int16)\
MACRO(L, uint16)\
MACRO(L, int8)\
MACRO(L, uint8)

// Repeats the code with T in [int32, uint32, int64, uint64, int16, uint16, int8, uint8]
#define PyGLM_CODEGEN_PARAM_T_Vec_iqsuIQSU(MACRO, L)\
MACRO(L, int32)\
MACRO(L, uint32)\
MACRO(L, int64)\
MACRO(L, uint64)\
MACRO(L, int16)\
MACRO(L, uint16)\
MACRO(L, int8)\
MACRO(L, uint8)

// Repeats the code with T in [int32, uint32, int64, uint64]
#define PyGLM_CODEGEN_PARAM_T_Vec_iqIQ(MACRO, L)\
MACRO(L, int32)\
MACRO(L, uint32)\
MACRO(L, int64)\
MACRO(L, uint64)

// Repeats the code with T in [float, double, int32, int64, int16, int8]
#define PyGLM_CODEGEN_PARAM_T_Vec_fFiqsu(MACRO, L)\
MACRO(L, float)\
MACRO(L, double)\
MACRO(L, int32)\
MACRO(L, int64)\
MACRO(L, int16)\
MACRO(L, int8)

// Repeats the code with T in [float, double, int32]
#define PyGLM_CODEGEN_PARAM_T_Vec_fFi(MACRO, L)\
MACRO(L, float)\
MACRO(L, double)\
MACRO(L, int32)

// Repeats the code with T in [float, double, int32, uint32]
#define PyGLM_CODEGEN_PARAM_T_Mat_fFiI(MACRO, C, R)\
MACRO(C, R, float)\
MACRO(C, R, double)\
MACRO(C, R, int32)\
MACRO(C, R, uint32)

// Repeats the code with T in [float, double]
#define PyGLM_CODEGEN_PARAM_T_Mat_fF(MACRO, C, R)\
MACRO(C, R, float)\
MACRO(C, R, double)

// Repeats the code with T in [float, double]
#define PyGLM_CODEGEN_PARAM_T_Vec_fF(MACRO, L)\
MACRO(L, float)\
MACRO(L, double)

// Repeats the code with T in [float, double, int32, uint32]
#define PyGLM_CODEGEN_PARAM_T_Vec_fFiI(MACRO, L)\
MACRO(L, float)\
MACRO(L, double)\
MACRO(L, int32)\
MACRO(L, uint32)

// Repeats the code with T in [int32, uint32]
#define PyGLM_CODEGEN_PARAM_T_Vec_iI(MACRO, L)\
MACRO(L, int32)\
MACRO(L, uint32)

// Repeats the code with T in [float, double]
#define PyGLM_CODEGEN_PARAM_T_Qua_fF(MACRO)\
MACRO(float)\
MACRO(double)

// Just passes through L
#define PyGLM_CODEGEN_PARAM_T_Vec_Undefined(MACRO, L)\
MACRO(L)

// Runs T_MACRO(CODE_MACRO, L) for L in [1, 2, 3, 4]
#define PyGLM_CODEGEN_PARAM_L_ALL(T_MACRO, CODE_MACRO)\
T_MACRO(CODE_MACRO, 1) \
T_MACRO(CODE_MACRO, 2) \
T_MACRO(CODE_MACRO, 3) \
T_MACRO(CODE_MACRO, 4)

// Runs T_MACRO(CODE_MACRO, L) for L in [2, 3, 4]
#define PyGLM_CODEGEN_PARAM_L_MVEC(T_MACRO, CODE_MACRO)\
T_MACRO(CODE_MACRO, 2) \
T_MACRO(CODE_MACRO, 3) \
T_MACRO(CODE_MACRO, 4)

// Runs T_MACRO(CODE_MACRO, S, S) for S in [2, 3, 4]
#define PyGLM_CODEGEN_PARAM_S_ALL(T_MACRO, CODE_MACRO)\
T_MACRO(CODE_MACRO, 2, 2) \
T_MACRO(CODE_MACRO, 3, 3) \
T_MACRO(CODE_MACRO, 4, 4)

// Runs T_MACRO(CODE_MACRO, C, R) for R in [2, 3, 4]
#define PyGLM_CODEGEN_PARAM_R_ALL(C, T_MACRO, CODE_MACRO)\
T_MACRO(CODE_MACRO, C, 2) \
T_MACRO(CODE_MACRO, C, 3) \
T_MACRO(CODE_MACRO, C, 4)

// Runs R_MACRO(C, T_MACRO, CODE_MACRO) for C in [2, 3, 4]
#define PyGLM_CODEGEN_PARAM_C_ALL(R_MACRO, T_MACRO, CODE_MACRO)\
R_MACRO(2, T_MACRO, CODE_MACRO) \
R_MACRO(3, T_MACRO, CODE_MACRO) \
R_MACRO(4, T_MACRO, CODE_MACRO)


#define PyGLM_MAKE_GLM_FUNC_V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<3, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<3, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(3, double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V2__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<2, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<2, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(2, double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) {\
	case PyGLMTypeObjectArrayOffsetVec<1, float>():\
		return pack(glm::NAME(PyGLM_Vec_Get(1, float, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<1, double>():\
		return pack(glm::NAME(PyGLM_Vec_Get(1, double, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<2, float>():\
		return pack(glm::NAME(PyGLM_Vec_Get(2, float, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<2, double>():\
		return pack(glm::NAME(PyGLM_Vec_Get(2, double, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<3, float>():\
		return pack(glm::NAME(PyGLM_Vec_Get(3, float, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<3, double>():\
		return pack(glm::NAME(PyGLM_Vec_Get(3, double, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<4, float>():\
		return pack(glm::NAME(PyGLM_Vec_Get(4, float, arg)));\
	case PyGLMTypeObjectArrayOffsetVec<4, double>():\
		return pack(glm::NAME(PyGLM_Vec_Get(4, double, arg)));\
	case PyGLMTypeObjectArrayOffsetMVec<2, float>():\
		return pack(glm::NAME(PyGLM_MVec_Get(2, float, arg)));\
	case PyGLMTypeObjectArrayOffsetMVec<2, double>():\
		return pack(glm::NAME(PyGLM_MVec_Get(2, double, arg)));\
	case PyGLMTypeObjectArrayOffsetMVec<3, float>():\
		return pack(glm::NAME(PyGLM_MVec_Get(3, float, arg)));\
	case PyGLMTypeObjectArrayOffsetMVec<3, double>():\
		return pack(glm::NAME(PyGLM_MVec_Get(3, double, arg)));\
	case PyGLMTypeObjectArrayOffsetMVec<4, float>():\
		return pack(glm::NAME(PyGLM_MVec_Get(4, float, arg)));\
	case PyGLMTypeObjectArrayOffsetMVec<4, double>():\
		return pack(glm::NAME(PyGLM_MVec_Get(4, double, arg)));\
	}\
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (Is_PyGLM_Object(arg1)){\
		if (Is_PyGLM_Object(arg2)) {\
			GET_PyGLM_ARG_TYPE(arg1);\
			GET_PyGLM_ARG_TYPE(arg2);\
			if (arg1Type->subtype == arg2Type->subtype) {\
				switch(GET_PyGLMTypeObjectArrayOffsetOfType(arg1Type->subtype)) {\
				case PyGLMTypeObjectArrayOffsetVec<1, float>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<1, double>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<2, float>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<2, double>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<3, float>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<3, double>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<4, float>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2)));\
				case PyGLMTypeObjectArrayOffsetVec<4, double>():\
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2)));\
				}\
			}\
		}\
		if (PyGLM_Number_Check(arg2)){\
			switch(GET_PyGLMTypeObjectArrayOffsetOf(arg1)){\
			case PyGLMTypeObjectArrayOffsetVec<1, float>():\
				return pack(glm::NAME(PyGLM_Vec_Get(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<1, double>():\
				return pack(glm::NAME(PyGLM_Vec_Get(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<2, float>():\
				return pack(glm::NAME(PyGLM_Vec_Get(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<2, double>():\
				return pack(glm::NAME(PyGLM_Vec_Get(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<3, float>():\
				return pack(glm::NAME(PyGLM_Vec_Get(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<3, double>():\
				return pack(glm::NAME(PyGLM_Vec_Get(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<4, float>():\
				return pack(glm::NAME(PyGLM_Vec_Get(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetVec<4, double>():\
				return pack(glm::NAME(PyGLM_Vec_Get(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<2, float>():\
				return pack(glm::NAME(PyGLM_MVec_Get(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<2, double>():\
				return pack(glm::NAME(PyGLM_MVec_Get(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<3, float>():\
				return pack(glm::NAME(PyGLM_MVec_Get(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<3, double>():\
				return pack(glm::NAME(PyGLM_MVec_Get(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<4, float>():\
				return pack(glm::NAME(PyGLM_MVec_Get(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<4, double>():\
				return pack(glm::NAME(PyGLM_MVec_Get(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
			}\
		}\
	}\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(1, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(1, double, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<2, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<3, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<4, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<2, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<3, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<4, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetQua<float>(): \
		return pack(glm::NAME(PyGLM_Qua_Get(float, arg))); \
	case PyGLMTypeObjectArrayOffsetQua<double>(): \
		return pack(glm::NAME(PyGLM_Qua_Get(double, arg))); \
	} \
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2); \
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) { \
		GET_PyGLM_ARG_TYPE(arg1); \
		GET_PyGLM_ARG_TYPE(arg2); \
		GET_PyGLM_ARG_SUBTYPE(arg1); \
		GET_PyGLM_ARG_SUBTYPE(arg2); \
		if (arg1Subtype == arg2Subtype) { \
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
			case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2))); \
			} \
		} \
	} \
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(1, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(1, double, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
		return pack(glm::NAME(PyGLM_Vec_Get(4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<2, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<2, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<3, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<3, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<4, float>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMVec<4, double>(): \
		return pack(glm::NAME(PyGLM_MVec_Get(4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetQua<float>(): \
		return pack(glm::NAME(PyGLM_Qua_Get(float, arg))); \
	case PyGLMTypeObjectArrayOffsetQua<double>(): \
		return pack(glm::NAME(PyGLM_Qua_Get(double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_NNN_VVV__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3)) { \
		GET_PyGLM_ARG_TYPE(arg1); \
		GET_PyGLM_ARG_TYPE(arg2); \
		GET_PyGLM_ARG_TYPE(arg3); \
		GET_PyGLM_ARG_SUBTYPE(arg1); \
		GET_PyGLM_ARG_SUBTYPE(arg2); \
		GET_PyGLM_ARG_SUBTYPE(arg3); \
		if (arg1Subtype == arg2Subtype && arg1Subtype == arg3Subtype) { \
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
			case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2), PyGLM_VecOrMVec_Get(1, float, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2), PyGLM_VecOrMVec_Get(1, double, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2), PyGLM_VecOrMVec_Get(2, float, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2), PyGLM_VecOrMVec_Get(2, double, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2), PyGLM_VecOrMVec_Get(3, float, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2), PyGLM_VecOrMVec_Get(3, double, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2), PyGLM_VecOrMVec_Get(4, float, arg3))); \
			case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2), PyGLM_VecOrMVec_Get(4, double, arg3))); \
			} \
		} \
	} \
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NNN_VVN__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3); \
	if (PyGLM_Number_Check(arg3)) { \
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) { \
			GET_PyGLM_ARG_TYPE(arg1); \
			GET_PyGLM_ARG_TYPE(arg2); \
			GET_PyGLM_ARG_SUBTYPE(arg1); \
			GET_PyGLM_ARG_SUBTYPE(arg2); \
			if (arg1Subtype == arg2Subtype) { \
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
				case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2), PyGLM_Number_FromPyObject<float>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2), PyGLM_Number_FromPyObject<double>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2), PyGLM_Number_FromPyObject<float>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2), PyGLM_Number_FromPyObject<double>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2), PyGLM_Number_FromPyObject<float>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2), PyGLM_Number_FromPyObject<double>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2), PyGLM_Number_FromPyObject<float>(arg3))); \
				case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
					return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2), PyGLM_Number_FromPyObject<double>(arg3))); \
				} \
			} \
		} \
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
			return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
		}\
	} \
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_MM__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (Py_TYPE(arg1) == Py_TYPE(arg2)) { \
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) { \
		case PyGLMTypeObjectArrayOffsetMat<2, 2, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(2, 2, float, arg1), PyGLM_Mat_Get(2, 2, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<2, 2, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(2, 2, double, arg1), PyGLM_Mat_Get(2, 2, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<2, 3, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(2, 3, float, arg1), PyGLM_Mat_Get(2, 3, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<2, 3, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(2, 3, double, arg1), PyGLM_Mat_Get(2, 3, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<2, 4, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(2, 4, float, arg1), PyGLM_Mat_Get(2, 4, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<2, 4, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(2, 4, double, arg1), PyGLM_Mat_Get(2, 4, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<3, 2, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 2, float, arg1), PyGLM_Mat_Get(3, 2, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<3, 2, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 2, double, arg1), PyGLM_Mat_Get(3, 2, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<3, 3, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg1), PyGLM_Mat_Get(3, 3, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<3, 3, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg1), PyGLM_Mat_Get(3, 3, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<3, 4, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 4, float, arg1), PyGLM_Mat_Get(3, 4, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<3, 4, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 4, double, arg1), PyGLM_Mat_Get(3, 4, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<4, 2, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(4, 2, float, arg1), PyGLM_Mat_Get(4, 2, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<4, 2, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(4, 2, double, arg1), PyGLM_Mat_Get(4, 2, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<4, 3, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(4, 3, float, arg1), PyGLM_Mat_Get(4, 3, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<4, 3, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(4, 3, double, arg1), PyGLM_Mat_Get(4, 3, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<4, 4, float>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg1), PyGLM_Mat_Get(4, 4, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetMat<4, 4, double>(): \
			return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg1), PyGLM_Mat_Get(4, 4, double, arg2))); \
		} \
	} \
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 3, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 3, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 3, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 3, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 4, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 4, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 4, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 4, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 2, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 2, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 2, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 2, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 4, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 4, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 4, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 4, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 2, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 2, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 2, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 2, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 3, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 3, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 3, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 3, uint32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, int32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, int32, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, uint32>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, uint32, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_S__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_S_Q__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<2, 2, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(2, 2, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg))); \
	case PyGLMTypeObjectArrayOffsetQua<float>(): \
		return pack(glm::NAME(PyGLM_Qua_Get(float, arg))); \
	case PyGLMTypeObjectArrayOffsetQua<double>(): \
		return pack(glm::NAME(PyGLM_Qua_Get(double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC__rF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject*) {\
	return pack(glm::NAME<double>());\
}



#define PyGLM_MAKE_GLM_FUNC_M3N__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg2)) {\
		if (PyGLM_Mat_Check(3, 3, float, arg1)) { \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2))); \
		} \
		if (PyGLM_Mat_Check(3, 3, double, arg1)) { \
			return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2))); \
		} \
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M4V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) { \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg1), PyGLM_VecOrMVec_GET(3, float, arg2))); \
	} \
	if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) { \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg1), PyGLM_VecOrMVec_GET(3, double, arg2))); \
	} \
	if (PyGLM_Mat_Check(4, 4, int32, arg1) && PyGLM_Vec_Check(3, int32, arg2)) { \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, int32, arg1), PyGLM_VecOrMVec_GET(3, int32, arg2))); \
	} \
	if (PyGLM_Mat_Check(4, 4, uint32, arg1) && PyGLM_Vec_Check(3, uint32, arg2)) { \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, uint32, arg1), PyGLM_VecOrMVec_GET(3, uint32, arg2))); \
	} \
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
	PyGLM_Arg_Unpack_4O(args, #NAME, arg1, arg2, arg3, arg4); \
	if (PyGLM_Vec_Check(4, float, arg4)) { \
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2) && PyGLM_Mat_Check(4, 4, float, arg3)) { \
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, float, arg1), PyGLM_Mat_Get(4, 4, float, arg2), PyGLM_Mat_Get(4, 4, float, arg3), PyGLM_VecOrMVec_GET(4, float, arg4))); \
		} \
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2) && PyGLM_Mat_Check(4, 4, double, arg3)) { \
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, double, arg1), PyGLM_Mat_Get(4, 4, double, arg2), PyGLM_Mat_Get(4, 4, double, arg3), PyGLM_VecOrMVec_GET(4, float, arg4))); \
		} \
	} \
	if (PyGLM_Vec_Check(4, double, arg4)) { \
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2) && PyGLM_Mat_Check(4, 4, float, arg3)) { \
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, float, arg1), PyGLM_Mat_Get(4, 4, float, arg2), PyGLM_Mat_Get(4, 4, float, arg3), PyGLM_VecOrMVec_GET(4, double, arg4))); \
		} \
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2) && PyGLM_Mat_Check(4, 4, double, arg3)) { \
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, double, arg1), PyGLM_Mat_Get(4, 4, double, arg2), PyGLM_Mat_Get(4, 4, double, arg3), PyGLM_VecOrMVec_GET(4, double, arg4))); \
		} \
	} \
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) { \
		return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, float, arg1), PyGLM_VecOrMVec_GET(3, float, arg2), PyGLM_VecOrMVec_GET(3, float, arg3))); \
	} \
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) { \
		return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, double, arg1), PyGLM_VecOrMVec_GET(3, double, arg2), PyGLM_VecOrMVec_GET(3, double, arg3))); \
	} \
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) { \
		return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, float, arg1), PyGLM_VecOrMVec_GET(3, float, arg2))); \
	} \
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) { \
		return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, double, arg1), PyGLM_VecOrMVec_GET(3, double, arg2))); \
	} \
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_V3_V3V3__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2 = NULL;\
	if (!PyArg_UnpackTuple(args, #NAME, 1, 2, &arg1, &arg2)) return NULL;\
	if (arg2 == NULL) {\
		if (PyGLM_Vec_Check(3, float, arg1)) {\
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, float, arg1)));\
		}\
		if (PyGLM_Vec_Check(3, double, arg1)) {\
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, double, arg1)));\
		}\
	}\
	else {\
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {\
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, float, arg1), PyGLM_VecOrMVec_GET(3, float, arg2)));\
		}\
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {\
			return pack(glm::NAME(PyGLM_VecOrMVec_GET(3, double, arg1), PyGLM_VecOrMVec_GET(3, double, arg2)));\
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
	if (PyGLM_Qua_Check(float, arg1) && PyGLM_Qua_Check(float, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Qua_Get(float, arg1), PyGLM_Qua_Get(float, arg2), PyGLM_Number_FromPyObject<float>(arg3)));\
	}\
	if (PyGLM_Qua_Check(double, arg1) && PyGLM_Qua_Check(double, arg2) && PyGLM_Number_Check(arg3)) {\
		return pack(glm::NAME(PyGLM_Qua_Get(double, arg1), PyGLM_Qua_Get(double, arg2), PyGLM_Number_FromPyObject<double>(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_Q(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (PyGLM_Qua_Check(float, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_Get(float, arg)));\
	}\
	if (PyGLM_Qua_Check(double, arg)) {\
		return pack(glm::NAME(PyGLM_Qua_Get(double, arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_M3_M4__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	switch(GET_PyGLMTypeObjectArrayOffsetOf(arg)) { \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(3, 3, double, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, float, arg))); \
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>(): \
		return pack(glm::NAME(PyGLM_Mat_Get(4, 4, double, arg))); \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV__tGPL(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) { \
		GET_PyGLM_ARG_TYPE(arg1); \
		GET_PyGLM_ARG_TYPE(arg2); \
		GET_PyGLM_ARG_SUBTYPE(arg1); \
		GET_PyGLM_ARG_SUBTYPE(arg2); \
		switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
		case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int64, arg1), PyGLM_VecOrMVec_Get(1, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int32, arg1), PyGLM_VecOrMVec_Get(1, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int16, arg1), PyGLM_VecOrMVec_Get(1, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int8, arg1), PyGLM_VecOrMVec_Get(1, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint64, arg1), PyGLM_VecOrMVec_Get(1, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint32, arg1), PyGLM_VecOrMVec_Get(1, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint16, arg1), PyGLM_VecOrMVec_Get(1, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint8, arg1), PyGLM_VecOrMVec_Get(1, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int64, arg1), PyGLM_VecOrMVec_Get(2, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int32, arg1), PyGLM_VecOrMVec_Get(2, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int16, arg1), PyGLM_VecOrMVec_Get(2, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int8, arg1), PyGLM_VecOrMVec_Get(2, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint64, arg1), PyGLM_VecOrMVec_Get(2, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint32, arg1), PyGLM_VecOrMVec_Get(2, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint16, arg1), PyGLM_VecOrMVec_Get(2, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint8, arg1), PyGLM_VecOrMVec_Get(2, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int64, arg1), PyGLM_VecOrMVec_Get(3, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int32, arg1), PyGLM_VecOrMVec_Get(3, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int16, arg1), PyGLM_VecOrMVec_Get(3, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int8, arg1), PyGLM_VecOrMVec_Get(3, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint64, arg1), PyGLM_VecOrMVec_Get(3, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint32, arg1), PyGLM_VecOrMVec_Get(3, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint16, arg1), PyGLM_VecOrMVec_Get(3, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint8, arg1), PyGLM_VecOrMVec_Get(3, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int64, arg1), PyGLM_VecOrMVec_Get(4, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int32, arg1), PyGLM_VecOrMVec_Get(4, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int16, arg1), PyGLM_VecOrMVec_Get(4, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int8, arg1), PyGLM_VecOrMVec_Get(4, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint64, arg1), PyGLM_VecOrMVec_Get(4, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint32, arg1), PyGLM_VecOrMVec_Get(4, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint16, arg1), PyGLM_VecOrMVec_Get(4, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint8, arg1), PyGLM_VecOrMVec_Get(4, uint8, arg2))); \
		} \
	} \
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_NN_VV_QQ__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) { \
		GET_PyGLM_ARG_TYPE(arg1); \
		GET_PyGLM_ARG_TYPE(arg2); \
		GET_PyGLM_ARG_SUBTYPE(arg1); \
		GET_PyGLM_ARG_SUBTYPE(arg2); \
		if (arg1Subtype == arg2Subtype) { \
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
			case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetQua<float>(): \
				return pack(glm::NAME(PyGLM_Qua_Get(float, arg1), PyGLM_Qua_Get(float, arg2))); \
			case PyGLMTypeObjectArrayOffsetQua<double>(): \
				return pack(glm::NAME(PyGLM_Qua_Get(double, arg1), PyGLM_Qua_Get(double, arg2))); \
			} \
		} \
	} \
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* arg) {\
	if (Is_PyGLM_Object(arg)) { \
		GET_PyGLM_ARG_TYPE(arg); \
		GET_PyGLM_ARG_SUBTYPE(arg); \
		switch (GET_PyGLMTypeObjectArrayOffsetOfType(argSubtype)) { \
		case PyGLMTypeObjectArrayOffsetVec<1, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int64, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int32, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int16, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int8, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int64, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int32, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int16, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int8, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int64, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int32, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int16, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int8, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int64, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int32, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int16, arg))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int8, arg))); \
		} \
	} \
	if (PyGLM_Number_Check(arg)) {\
		return pack(glm::NAME(PyGLM_Number_FromPyObject<int64>(arg)));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_VV_QQ(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) { \
		GET_PyGLM_ARG_TYPE(arg1); \
		GET_PyGLM_ARG_TYPE(arg2); \
		GET_PyGLM_ARG_SUBTYPE(arg1); \
		GET_PyGLM_ARG_SUBTYPE(arg2); \
		switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
		case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int64, arg1), PyGLM_VecOrMVec_Get(1, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int32, arg1), PyGLM_VecOrMVec_Get(1, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int16, arg1), PyGLM_VecOrMVec_Get(1, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, int8, arg1), PyGLM_VecOrMVec_Get(1, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint64, arg1), PyGLM_VecOrMVec_Get(1, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint32, arg1), PyGLM_VecOrMVec_Get(1, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint16, arg1), PyGLM_VecOrMVec_Get(1, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, uint8, arg1), PyGLM_VecOrMVec_Get(1, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<1, bool>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, bool, arg1), PyGLM_VecOrMVec_Get(1, bool, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int64, arg1), PyGLM_VecOrMVec_Get(2, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int32, arg1), PyGLM_VecOrMVec_Get(2, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int16, arg1), PyGLM_VecOrMVec_Get(2, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, int8, arg1), PyGLM_VecOrMVec_Get(2, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint64, arg1), PyGLM_VecOrMVec_Get(2, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint32, arg1), PyGLM_VecOrMVec_Get(2, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint16, arg1), PyGLM_VecOrMVec_Get(2, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, uint8, arg1), PyGLM_VecOrMVec_Get(2, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<2, bool>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, bool, arg1), PyGLM_VecOrMVec_Get(2, bool, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int64, arg1), PyGLM_VecOrMVec_Get(3, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int32, arg1), PyGLM_VecOrMVec_Get(3, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int16, arg1), PyGLM_VecOrMVec_Get(3, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, int8, arg1), PyGLM_VecOrMVec_Get(3, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint64, arg1), PyGLM_VecOrMVec_Get(3, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint32, arg1), PyGLM_VecOrMVec_Get(3, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint16, arg1), PyGLM_VecOrMVec_Get(3, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, uint8, arg1), PyGLM_VecOrMVec_Get(3, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<3, bool>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, bool, arg1), PyGLM_VecOrMVec_Get(3, bool, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int64, arg1), PyGLM_VecOrMVec_Get(4, int64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int32, arg1), PyGLM_VecOrMVec_Get(4, int32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int16, arg1), PyGLM_VecOrMVec_Get(4, int16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, int8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, int8, arg1), PyGLM_VecOrMVec_Get(4, int8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint64>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint64, arg1), PyGLM_VecOrMVec_Get(4, uint64, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint32>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint32, arg1), PyGLM_VecOrMVec_Get(4, uint32, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint16>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint16, arg1), PyGLM_VecOrMVec_Get(4, uint16, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, uint8>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, uint8, arg1), PyGLM_VecOrMVec_Get(4, uint8, arg2))); \
		case PyGLMTypeObjectArrayOffsetVec<4, bool>(): \
			return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, bool, arg1), PyGLM_VecOrMVec_Get(4, bool, arg2))); \
		case PyGLMTypeObjectArrayOffsetQua<float>(): \
			return pack(glm::NAME(PyGLM_Qua_Get(float, arg1), PyGLM_Qua_Get(float, arg2))); \
		case PyGLMTypeObjectArrayOffsetQua<double>(): \
			return pack(glm::NAME(PyGLM_Qua_Get(double, arg1), PyGLM_Qua_Get(double, arg2))); \
		} \
	} \
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}


#define PyGLM_MAKE_GLM_FUNC_VV__tfF(NAME)\
static PyObject*\
NAME##_(PyObject*, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) { \
		GET_PyGLM_ARG_TYPE(arg1); \
		GET_PyGLM_ARG_TYPE(arg2); \
		GET_PyGLM_ARG_SUBTYPE(arg1); \
		GET_PyGLM_ARG_SUBTYPE(arg2); \
		if (arg1Subtype == arg2Subtype) { \
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) { \
			case PyGLMTypeObjectArrayOffsetVec<1, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, float, arg1), PyGLM_VecOrMVec_Get(1, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<1, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(1, double, arg1), PyGLM_VecOrMVec_Get(1, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<2, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, float, arg1), PyGLM_VecOrMVec_Get(2, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<2, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(2, double, arg1), PyGLM_VecOrMVec_Get(2, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<3, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, float, arg1), PyGLM_VecOrMVec_Get(3, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<3, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(3, double, arg1), PyGLM_VecOrMVec_Get(3, double, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<4, float>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, float, arg1), PyGLM_VecOrMVec_Get(4, float, arg2))); \
			case PyGLMTypeObjectArrayOffsetVec<4, double>(): \
				return pack(glm::NAME(PyGLM_VecOrMVec_Get(4, double, arg1), PyGLM_VecOrMVec_Get(4, double, arg2))); \
			} \
		} \
	} \
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}
