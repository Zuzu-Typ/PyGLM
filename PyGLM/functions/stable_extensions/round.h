#pragma once

#include "../function_generator_macros.h"

//TODO: Fix the supported types (should not be restricted to int)
//PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(isPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(ceilPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(floorPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(roundPowerOfTwo);

static PyObject*
ceilMultiple_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "ceilMultiple", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		int64 o2 = PyGLM_Number_FromPyObject<int64>(arg2);
		PyGLM_ASSERT((o2 > 0), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Number_FromPyObject<int64>(arg1), o2));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<1, int>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(1, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int64);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<1, int64>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int16);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<1, int16>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int8);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<1, int8>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<2, int>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(2, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int64);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<2, int64>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int16);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<2, int16>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int8);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<2, int8>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<3, int>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(3, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int64);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<3, int64>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int16);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<3, int16>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int8);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<3, int8>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<4, int>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(4, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int64);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<4, int64>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int16);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<4, int16>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int8);
		PyGLM_ASSERT(glm::all(glm::greaterThan(o2, glm::vec<4, int8>(0))), "Invalid Multiple. Must be positive");
		return pack(glm::ceilMultiple(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for ceilMultiple(): ", arg1, arg2);
	return NULL;
}

static PyObject*
floorMultiple_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "floorMultiple", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		int64 o2 = PyGLM_Number_FromPyObject<int64>(arg2);
		PyGLM_ASSERT((o2 != 0), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Number_FromPyObject<int64>(arg1), o2));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(1, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(2, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(3, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(4, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::floorMultiple(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for floorMultiple(): ", arg1, arg2);
	return NULL;
}

static PyObject*
roundMultiple_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "roundMultiple", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		int64 o2 = PyGLM_Number_FromPyObject<int64>(arg2);
		PyGLM_ASSERT((o2 != 0), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Number_FromPyObject<int64>(arg1), o2));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT | PyGLM_DT_INT64 | PyGLM_DT_INT16 | PyGLM_DT_INT8);
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(1, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(1, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<1, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(2, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(2, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<2, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(3, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(3, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<3, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(4, int, arg1), o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int64);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int64>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int16);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int16>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {
		PyGLM_Vec_PTI_Assign1(4, int8);
		PyGLM_ASSERT(glm::all(glm::notEqual(o2, glm::vec<4, int8>(0))), "Invalid Multiple. Must not be zero");
		return pack(glm::roundMultiple(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));
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
