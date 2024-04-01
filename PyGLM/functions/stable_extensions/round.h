#pragma once

#include "../function_generator_macros.h"

//TODO: Fix the supported types (should not be restricted to int)
//PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(isPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(ceilPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(floorPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(roundPowerOfTwo);

static union {
	int i;
	glm::vec<1, int8> vec1int8;
	glm::vec<2, int8> vec2int8;
	glm::vec<3, int8> vec3int8;
	glm::vec<4, int8> vec4int8;
	glm::vec<1, int16> vec1int16;
	glm::vec<2, int16> vec2int16;
	glm::vec<3, int16> vec3int16;
	glm::vec<4, int16> vec4int16;
	glm::vec<1, int32> vec1int32;
	glm::vec<2, int32> vec2int32;
	glm::vec<3, int32> vec3int32;
	glm::vec<4, int32> vec4int32;
	glm::vec<1, int64> vec1int64;
	glm::vec<2, int64> vec2int64;
	glm::vec<3, int64> vec3int64;
	glm::vec<4, int64> vec4int64;
} _round_PyGLM_temp{ 0 };

static PyObject*
ceilMultiple_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "ceilMultiple", arg1, arg2);
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);

		if (arg1Subtype == arg2Subtype) {
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					_round_PyGLM_temp.vec ## L ## T = PyGLM_VecOrMVec_Get(L, T, arg2); \
					PyGLM_ASSERT(glm::all(glm::greaterThan(_round_PyGLM_temp.vec ## L ## T, glm::vec<L, T>(0))), "Invalid Multiple. Must be positive"); \
				return pack(glm::ceilMultiple(PyGLM_VecOrMVec_Get(L, T, arg1), _round_PyGLM_temp.vec ## L ## T));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsu, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		int64 o2 = PyGLM_Number_FromPyObject<int64>(arg2);
		PyGLM_ASSERT((o2 > 0), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Number_FromPyObject<int64>(arg1), o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for ceilMultiple(): ", arg1, arg2);
	return NULL;
}

static PyObject*
floorMultiple_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "floorMultiple", arg1, arg2);
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);

		if (arg1Subtype == arg2Subtype) {
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					_round_PyGLM_temp.vec ## L ## T = PyGLM_VecOrMVec_Get(L, T, arg2); \
					PyGLM_ASSERT(glm::all(glm::notEqual(_round_PyGLM_temp.vec ## L ## T , glm::vec<L, T>(0))), "Invalid Multiple. Must not be zero"); \
					return pack(glm::floorMultiple(PyGLM_VecOrMVec_Get(L, T, arg1), _round_PyGLM_temp.vec ## L ## T));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsu, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		int64 o2 = PyGLM_Number_FromPyObject<int64>(arg2);
		PyGLM_ASSERT((o2 != 0), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Number_FromPyObject<int64>(arg1), o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for floorMultiple(): ", arg1, arg2);
	return NULL;
}

static PyObject*
roundMultiple_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "roundMultiple", arg1, arg2);
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);

		if (arg1Subtype == arg2Subtype) {
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					_round_PyGLM_temp.vec ## L ## T = PyGLM_VecOrMVec_Get(L, T, arg2); \
					PyGLM_ASSERT(glm::all(glm::notEqual(_round_PyGLM_temp.vec ## L ## T , glm::vec<L, T>(0))), "Invalid Multiple. Must not be zero"); \
					return pack(glm::roundMultiple(PyGLM_VecOrMVec_Get(L, T, arg1), _round_PyGLM_temp.vec ## L ## T));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsu, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		int64 o2 = PyGLM_Number_FromPyObject<int64>(arg2);
		PyGLM_ASSERT((o2 != 0), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Number_FromPyObject<int64>(arg1), o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for roundMultiple(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(ceilMultiple_docstr, 
	"ceilMultiple(v: number, Multiple: number) -> number\n"
	"	Higher multiple number of Source.\n"
	"ceilMultiple(v: vecN, Multiple: vecN) -> vecN\n"
	"	Higher multiple number of Source."
);
PyDoc_STRVAR(ceilPowerOfTwo_docstr,
	"ceilPowerOfTwo(v: number) -> number\n"
	"	Return the power of two number which value is just higher the input value, round up to a\n"
	"	power of two.\n"
	"ceilPowerOfTwo(v: vecN) -> vecN\n"
	"	Return the power of two number which value is just higher the input value, round up to a\n"
	"	power of two."
);
PyDoc_STRVAR(floorMultiple_docstr,
	"floorMultiple(v: number, Multiple: number) -> number\n"
	"	Lower multiple number of Source.\n"
	"floorMultiple(v: vecN, Multiple: vecN) -> vecN\n"
	"	Lower multiple number of Source."
);
PyDoc_STRVAR(floorPowerOfTwo_docstr,
	"floorPowerOfTwo(v: number) -> number\n"
	"	Return the power of two number which value is just lower the input value, round down to a\n"
	"	power of two.\n"
	"floorPowerOfTwo(v: vecN) -> vecN\n"
	"	Return the power of two number which value is just lower the input value, round down to a\n"
	"	power of two."
);
PyDoc_STRVAR(roundMultiple_docstr,
	"roundMultiple(v: number, Multiple: number) -> number\n"
	"	Lower multiple number of Source.\n"
	"roundMultiple(v: vecN, Multiple: vecN) -> vecN\n"
	"	Lower multiple number of Source."
);
PyDoc_STRVAR(roundPowerOfTwo_docstr,
	"roundPowerOfTwo(v: number) -> number\n"
	"	Return the power of two number which value is the closet to the input value.\n"
	"roundPowerOfTwo(v: vecN) -> vecN\n"
	"	Return the power of two number which value is the closet to the input value."
);


#define ROUND_METHODS \
/*{ "isPowerOfTwo", (PyCFunction)isPowerOfTwo_, METH_O, "isPowerOfTwo(v) -> bool or bvecn\nReturn true if the value is a power of two number." },*/ \
{ "ceilPowerOfTwo", (PyCFunction)ceilPowerOfTwo_, METH_O, ceilPowerOfTwo_docstr }, \
{ "floorPowerOfTwo", (PyCFunction)floorPowerOfTwo_, METH_O, floorPowerOfTwo_docstr }, \
{ "roundPowerOfTwo", (PyCFunction)roundPowerOfTwo_, METH_O, roundPowerOfTwo_docstr }, \
/*{ "isMultiple", (PyCFunction)isMultiple_, METH_VARARGS, "isMultiple(v, Multiple) -> bool or bvecn\nReturn true if the 'Value' is a multiple of 'Multiple'." },  */ \
{ "ceilMultiple", (PyCFunction)ceilMultiple_, METH_VARARGS, ceilMultiple_docstr }, \
{ "floorMultiple", (PyCFunction)floorMultiple_, METH_VARARGS, floorMultiple_docstr }, \
{ "roundMultiple", (PyCFunction)roundMultiple_, METH_VARARGS, roundMultiple_docstr }
