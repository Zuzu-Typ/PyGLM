#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
packHalf1x16_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyLong_FromUnsignedLong((unsigned long)glm::packHalf1x16(PyGLM_Number_FromPyObject<float>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packHalf1x16(): ", arg);
	return NULL;
}

static PyObject*
packHalf4x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLongLong(glm::packHalf4x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packHalf4x16(): ", arg);
	return NULL;
}

static PyObject*
packI3x10_1x2_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(4, int, arg)) {
		PyGLM_Vec_PTI_Assign(4, int);
		return PyLong_FromUnsignedLong((unsigned long)glm::packI3x10_1x2(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packI3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
packU3x10_1x2_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg)) {
		PyGLM_Vec_PTI_Assign(4, uint32);
		return PyLong_FromUnsignedLong((unsigned long)glm::packU3x10_1x2(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packU3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
packF2x11_1x10_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packF2x11_1x10(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packF2x11_1x10(): ", arg);
	return NULL;
}

static PyObject*
packF3x9_E1x5_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packF3x9_E1x5(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packF3x9_E1x5(): ", arg);
	return NULL;
}

static PyObject*
packRGBM_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return pack(glm::packRGBM(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {
		PyGLM_Vec_PTI_Assign(3, double);
		return pack(glm::packRGBM(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packRGBM(): ", arg);
	return NULL;
}

static PyObject*
packHalf_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
		PyGLM_Vec_PTI_Assign(1, float);
		return pack(glm::packHalf(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		PyGLM_Vec_PTI_Assign(2, float);
		return pack(glm::packHalf(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return pack(glm::packHalf(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return pack(glm::packHalf(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packHalf(): ", arg);
	return NULL;
}

static PyObject*
packInt2x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT8);
	if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg)) {
		PyGLM_Vec_PTI_Assign(2, int8);
		return PyLong_FromLong((long)glm::packInt2x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packInt2x8(): ", arg);
	return NULL;
}

static PyObject*
packInt4x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT8);
	if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg)) {
		PyGLM_Vec_PTI_Assign(4, int8);
		return PyLong_FromLong((long)glm::packInt4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packInt4x8(): ", arg);
	return NULL;
}

static PyObject*
packInt2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT16);
	if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg)) {
		PyGLM_Vec_PTI_Assign(2, int16);
		return PyLong_FromLong((long)glm::packInt2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packInt2x16(): ", arg);
	return NULL;
}

static PyObject*
packInt4x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT16);
	if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg)) {
		PyGLM_Vec_PTI_Assign(4, int16);
		return PyLong_FromLongLong(glm::packInt4x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packInt4x16(): ", arg);
	return NULL;
}

static PyObject*
packInt2x32_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(2, glm::i32, arg)) {
		PyGLM_Vec_PTI_Assign(2, int32);
		return PyLong_FromLongLong(glm::packInt2x32(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packInt2x32(): ", arg);
	return NULL;
}

static PyObject*
packUint2x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT8);
	if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg)) {
		PyGLM_Vec_PTI_Assign(2, uint8);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUint2x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUint2x8(): ", arg);
	return NULL;
}

static PyObject*
packUint4x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT8);
	if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg)) {
		PyGLM_Vec_PTI_Assign(4, uint8);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUint4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUint4x8(): ", arg);
	return NULL;
}

static PyObject*
packUint2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT16);
	if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg)) {
		PyGLM_Vec_PTI_Assign(2, uint16);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUint2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUint2x16(): ", arg);
	return NULL;
}

static PyObject*
packUint4x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT16);
	if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg)) {
		PyGLM_Vec_PTI_Assign(4, uint16);
		return PyLong_FromUnsignedLongLong(glm::packUint4x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUint4x16(): ", arg);
	return NULL;
}

static PyObject*
packUint2x32_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(2, glm::u32, arg)) {
		PyGLM_Vec_PTI_Assign(2, uint32);
		return PyLong_FromUnsignedLongLong(glm::packUint2x32(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUint2x32(): ", arg);
	return NULL;
}

static PyObject*
packSnorm_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "packSnorm", arg1, arg2);

	PyGLM_PTI_Init0(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg2)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg2)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg2)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg2)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg2)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg2)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg2)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg2)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg2);
		if (arg1 == ctypes_int8)
			return pack(glm::packSnorm<int8>(o));
		if (arg1 == ctypes_int16)
			return pack(glm::packSnorm<int16>(o));
		if (arg1 == ctypes_int32)
			return pack(glm::packSnorm<int32>(o));
		if (arg1 == ctypes_int64)
			return pack(glm::packSnorm<int64>(o));
		if (arg1 == ctypes_uint8)
			return pack(glm::packSnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packSnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packSnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packSnorm<uint64>(o));
	}
	PyGLM_TYPEERROR_2O("invalid argument type for packSnorm(): ", arg1, arg2);
	return NULL;
}

static PyObject*
packSnorm1x8_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyLong_FromUnsignedLong((unsigned long)glm::packSnorm1x8(PyGLM_Number_FromPyObject<float>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm1x8(): ", arg);
	return NULL;
}

static PyObject*
packSnorm2x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		PyGLM_Vec_PTI_Assign(2, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packSnorm2x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm2x8(): ", arg);
	return NULL;
}

static PyObject*
packSnorm1x16_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyLong_FromUnsignedLong((unsigned long)glm::packSnorm1x16(PyGLM_Number_FromPyObject<float>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm1x16(): ", arg);
	return NULL;
}

static PyObject*
packSnorm4x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLongLong(glm::packSnorm4x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm4x16(): ", arg);
	return NULL;
}

static PyObject*
packSnorm3x10_1x2_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLong(glm::packSnorm3x10_1x2(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
packUnorm_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "packUnorm", arg1, arg2);

	PyGLM_PTI_Init0(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg2)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg2)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg2)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg2)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg2)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg2)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg2)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg2)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg2);
		if (arg1 == ctypes_uint8)
			return pack(glm::packUnorm<uint8>(o));
		if (arg1 == ctypes_uint16)
			return pack(glm::packUnorm<uint16>(o));
		if (arg1 == ctypes_uint32)
			return pack(glm::packUnorm<uint32>(o));
		if (arg1 == ctypes_uint64)
			return pack(glm::packUnorm<uint64>(o));
	}
	PyGLM_TYPEERROR_2O("invalid argument type for packUnorm(): ", arg1, arg2);
	return NULL;
}

static PyObject*
packUnorm2x4_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		PyGLM_Vec_PTI_Assign(2, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm2x4(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm2x4(): ", arg);
	return NULL;
}

static PyObject*
packUnorm4x4_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm4x4(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm4x4(): ", arg);
	return NULL;
}

static PyObject*
packUnorm1x8_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm1x8(PyGLM_Number_FromPyObject<float>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm1x8(): ", arg);
	return NULL;
}

static PyObject*
packUnorm2x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		PyGLM_Vec_PTI_Assign(2, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm2x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm2x8(): ", arg);
	return NULL;
}

static PyObject*
packUnorm1x16_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm1x16(PyGLM_Number_FromPyObject<float>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm1x16(): ", arg);
	return NULL;
}

static PyObject*
packUnorm4x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLongLong(glm::packUnorm4x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm4x16(): ", arg);
	return NULL;
}

static PyObject*
packUnorm3x10_1x2_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLong(glm::packUnorm3x10_1x2(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
packUnorm1x5_1x6_1x5_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm1x5_1x6_1x5(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm1x5_1x6_1x5(): ", arg);
	return NULL;
}

static PyObject*
packUnorm3x5_1x1_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm3x5_1x1(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm3x5_1x1(): ", arg);
	return NULL;
}

static PyObject*
packUnorm2x3_1x2_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return PyLong_FromUnsignedLong((unsigned long)glm::packUnorm2x3_1x2(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm2x3_1x2(): ", arg);
	return NULL;
}

static PyObject*
unpackHalf1x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackHalf1x16(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackHalf1x16(): ", arg);
	return NULL;
}

static PyObject*
unpackHalf4x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackHalf4x16(PyGLM_Number_FromPyObject<glm::u64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackHalf4x16(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "unpackSnorm", arg1, arg2);

	PyGLM_PTI_Init0(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I);
	if (PyGLM_Vec_PTI_Check0(1, int8, arg2)) {
		glm::vec<1, int8> o = PyGLM_Vec_PTI_Get0(1, int8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg2)) {
		glm::vec<2, int8> o = PyGLM_Vec_PTI_Get0(2, int8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg2)) {
		glm::vec<3, int8> o = PyGLM_Vec_PTI_Get0(3, int8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg2)) {
		glm::vec<4, int8> o = PyGLM_Vec_PTI_Get0(4, int8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg2)) {
		glm::vec<1, int16> o = PyGLM_Vec_PTI_Get0(1, int16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg2)) {
		glm::vec<2, int16> o = PyGLM_Vec_PTI_Get0(2, int16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg2)) {
		glm::vec<3, int16> o = PyGLM_Vec_PTI_Get0(3, int16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg2)) {
		glm::vec<4, int16> o = PyGLM_Vec_PTI_Get0(4, int16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int32, arg2)) {
		glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int32, arg2)) {
		glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int32, arg2)) {
		glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int32, arg2)) {
		glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg2)) {
		glm::vec<1, int64> o = PyGLM_Vec_PTI_Get0(1, int64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg2)) {
		glm::vec<2, int64> o = PyGLM_Vec_PTI_Get0(2, int64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg2)) {
		glm::vec<3, int64> o = PyGLM_Vec_PTI_Get0(3, int64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg2)) {
		glm::vec<4, int64> o = PyGLM_Vec_PTI_Get0(4, int64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg2)) {
		glm::vec<1, uint8> o = PyGLM_Vec_PTI_Get0(1, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg2)) {
		glm::vec<2, uint8> o = PyGLM_Vec_PTI_Get0(2, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg2)) {
		glm::vec<3, uint8> o = PyGLM_Vec_PTI_Get0(3, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg2)) {
		glm::vec<4, uint8> o = PyGLM_Vec_PTI_Get0(4, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg2)) {
		glm::vec<1, uint16> o = PyGLM_Vec_PTI_Get0(1, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg2)) {
		glm::vec<2, uint16> o = PyGLM_Vec_PTI_Get0(2, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg2)) {
		glm::vec<3, uint16> o = PyGLM_Vec_PTI_Get0(3, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg2)) {
		glm::vec<4, uint16> o = PyGLM_Vec_PTI_Get0(4, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg2)) {
		glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg2)) {
		glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg2)) {
		glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg2)) {
		glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg2)) {
		glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg2)) {
		glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg2)) {
		glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg2)) {
		glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackSnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackSnorm<double>(o));
	}
	PyGLM_TYPEERROR_2O("invalid argument type for unpackSnorm(): ", arg1, arg2);
	return NULL;
}

static PyObject*
unpackSnorm1x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm1x8(PyGLM_Number_FromPyObject<glm::u8>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm1x8(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm2x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm2x8(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm2x8(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm1x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm1x16(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm1x16(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm4x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm4x16(PyGLM_Number_FromPyObject<glm::u64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm4x16(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm3x10_1x2_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm3x10_1x2(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "unpackUnorm", arg1, arg2);

	PyGLM_PTI_Init0(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT | PyGLM_DT_UINT8 | PyGLM_DT_UINT16 | PyGLM_DT_UINT64);
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg2)) {
		glm::vec<1, uint8> o = PyGLM_Vec_PTI_Get0(1, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg2)) {
		glm::vec<2, uint8> o = PyGLM_Vec_PTI_Get0(2, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg2)) {
		glm::vec<3, uint8> o = PyGLM_Vec_PTI_Get0(3, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg2)) {
		glm::vec<4, uint8> o = PyGLM_Vec_PTI_Get0(4, uint8, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg2)) {
		glm::vec<1, uint16> o = PyGLM_Vec_PTI_Get0(1, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg2)) {
		glm::vec<2, uint16> o = PyGLM_Vec_PTI_Get0(2, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg2)) {
		glm::vec<3, uint16> o = PyGLM_Vec_PTI_Get0(3, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg2)) {
		glm::vec<4, uint16> o = PyGLM_Vec_PTI_Get0(4, uint16, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg2)) {
		glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg2)) {
		glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg2)) {
		glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg2)) {
		glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg2)) {
		glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg2)) {
		glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg2)) {
		glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg2)) {
		glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg2);
		if (arg1 == ctypes_float)
			return pack(glm::unpackUnorm<float>(o));
		if (arg1 == ctypes_double)
			return pack(glm::unpackUnorm<double>(o));
	}
	PyGLM_TYPEERROR_2O("invalid argument type for unpackUnorm(): ", arg1, arg2);
	return NULL;
}

static PyObject*
unpackUnorm1x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm1x8(PyGLM_Number_FromPyObject<glm::u8>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm1x8(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm2x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm2x8(PyGLM_Number_FromPyObject<glm::u8>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm2x8(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm1x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm1x16(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm1x16(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm4x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm4x16(PyGLM_Number_FromPyObject<glm::u64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm4x16(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm3x10_1x2_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm3x10_1x2(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm2x4_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm2x4(PyGLM_Number_FromPyObject<glm::u8>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm2x4(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm4x4_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm4x4(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm4x4(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm1x5_1x6_1x5_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm1x5_1x6_1x5(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm1x5_1x6_1x5(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm3x5_1x1_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm3x5_1x1(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm3x5_1x1(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm2x3_1x2_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm2x3_1x2(PyGLM_Number_FromPyObject<glm::u8>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm2x3_1x2(): ", arg);
	return NULL;
}

static PyObject*
unpackInt2x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackInt2x8(PyGLM_Number_FromPyObject<glm::i16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackInt2x8(): ", arg);
	return NULL;
}

static PyObject*
unpackInt4x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackInt4x8(PyGLM_Number_FromPyObject<glm::i32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackInt4x8(): ", arg);
	return NULL;
}

static PyObject*
unpackInt2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackInt2x16(PyGLM_Number_FromPyObject<glm::i32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackInt2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackInt4x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackInt4x16(PyGLM_Number_FromPyObject<glm::i64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackInt4x16(): ", arg);
	return NULL;
}

static PyObject*
unpackInt2x32_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackInt2x32(PyGLM_Number_FromPyObject<glm::i64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackInt2x32(): ", arg);
	return NULL;
}

static PyObject*
unpackUint2x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUint2x8(PyGLM_Number_FromPyObject<glm::u16>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUint2x8(): ", arg);
	return NULL;
}

static PyObject*
unpackUint4x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUint4x8(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUint4x8(): ", arg);
	return NULL;
}

static PyObject*
unpackUint2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUint2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUint2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackUint4x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUint4x16(PyGLM_Number_FromPyObject<glm::u64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUint4x16(): ", arg);
	return NULL;
}

static PyObject*
unpackUint2x32_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUint2x32(PyGLM_Number_FromPyObject<glm::u64>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUint2x32(): ", arg);
	return NULL;
}

static PyObject*
unpackI3x10_1x2_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackI3x10_1x2(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackI3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
unpackU3x10_1x2_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackU3x10_1x2(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackU3x10_1x2(): ", arg);
	return NULL;
}

static PyObject*
unpackF2x11_1x10_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackF2x11_1x10(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackF2x11_1x10(): ", arg);
	return NULL;
}

static PyObject*
unpackF3x9_E1x5_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackF3x9_E1x5(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackF3x9_E1x5(): ", arg);
	return NULL;
}

static PyObject*
unpackRGBM_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		return pack(glm::unpackRGBM(PyGLM_Vec_PTI_Get0(4, float, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {
		return pack(glm::unpackRGBM(PyGLM_Vec_PTI_Get0(4, double, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackRGBM(): ", arg);
	return NULL;
}

static PyObject*
unpackHalf_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT16);
	if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg)) {
		return pack(glm::unpackHalf(PyGLM_Vec_PTI_Get0(1, glm::u16, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg)) {
		return pack(glm::unpackHalf(PyGLM_Vec_PTI_Get0(2, glm::u16, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg)) {
		return pack(glm::unpackHalf(PyGLM_Vec_PTI_Get0(3, glm::u16, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg)) {
		return pack(glm::unpackHalf(PyGLM_Vec_PTI_Get0(4, glm::u16, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackHalf(): ", arg);
	return NULL;
}

PyDoc_STRVAR(packF2x11_1x10_docstr,
	"packF2x11_1x10(v: vec3) -> int\n"
	"	First, converts the first two components of the normalized floating-point value `v` into\n"
	"	11-bit signless floating-point values. Then, converts the third component of the normalized\n"
	"	floating-point value `v` into a 10-bit signless floating-point value. Then, the results\n"
	"	are packed into the returned 32-bit unsigned integer. The first vector component\n"
	"	specifies the 11 least-significant bits of the result; the last component specifies the\n"
	"	10 most-significant bits."
);
PyDoc_STRVAR(packF3x9_E1x5_docstr,
	"packF3x9_E1x5(v: vec3) -> int\n"
	"	First, converts the first two components of the normalized floating-point value `v` into\n"
	"	11-bit signless floating-point values. Then, converts the third component of the normalized\n"
	"	floating-point value `v` into a 10-bit signless floating-point value.Then, the results\n"
	"	are packed into the returned 32-bit unsigned integer. The first vector component\n"
	"	specifies the 11 least-significant bits of the result; the last component specifies the\n"
	"	10 most-significant bits. packF3x9_E1x5 allows encoding into RGBE / RGB9E5 format"
);
PyDoc_STRVAR(packHalf_docstr,
	"packHalf(v: vecN) -> u16vecN\n"
	"	Returns an unsigned integer vector obtained by converting the components of a\n"
	"	floating-point vector to the 16-bit floating-point representation found in the OpenGL\n"
	"	Specification. The first vector component specifies the 16 least-significant bits of the\n"
	"	result; the forth component specifies the 16 most-significant bits."
);
PyDoc_STRVAR(packHalf1x16_docstr,
	"packHalf1x16(v: float) -> int\n"
	"	Returns an unsigned integer obtained by converting the components of a floating-point\n"
	"	scalar to the 16-bit floating-point representation found in the OpenGL Specification, and\n"
	"	then packing this 16-bit value into a 16-bit unsigned integer."
);
PyDoc_STRVAR(packHalf4x16_docstr,
	"packHalf4x16(v: vec4) -> int\n"
	"	Returns an unsigned integer obtained by converting the components of a four-component\n"
	"	floating-point vector to the 16-bit floating-point representation found in the OpenGL\n"
	"	Specification, and then packing these four 16-bit values into a 64-bit unsigned integer.\n"
	"	The first vector component specifies the 16 least-significant bits of the result; the\n"
	"	forth component specifies the 16 most-significant bits."
);
PyDoc_STRVAR(packI3x10_1x2_docstr,
	"packI3x10_1x2(v: ivec4) -> int\n"
	"	Returns an unsigned integer obtained by converting the components of a four-component\n"
	"	signed integer vector to the 10-10-10-2-bit signed integer representation found in the\n"
	"	OpenGL Specification, and then packing these four values into a 32-bit unsigned integer.\n"
	"	The first vector component specifies the 10 least-significant bits of the result; the\n"
	"	forth component specifies the 2 most-significant bits."
);
PyDoc_STRVAR(packInt2x16_docstr,
	"packInt2x16(v: i16vec2) -> int\n"
	"	Convert each component from an integer vector into a packed integer."
);
PyDoc_STRVAR(packInt2x32_docstr,
	"packInt2x32(v: i32vec2) -> int\n"
	"	Convert each component from an integer vector into a packed integer."
);
PyDoc_STRVAR(packInt2x8_docstr,
	"packInt2x8(v: i8vec2) -> int\n"
	"	Convert each component from an integer vector into a packed integer."
);
PyDoc_STRVAR(packInt4x16_docstr,
	"packInt4x16(v: i16vec4) -> int\n"
	"	Convert each component from an integer vector into a packed integer."
);
PyDoc_STRVAR(packInt4x8_docstr,
	"packInt4x8(v: i8vec4) -> int\n"
	"	Convert each component from an integer vector into a packed integer."
);
PyDoc_STRVAR(packRGBM_docstr,
	"packRGBM(v: vec3) -> vec4\n"
	"	Returns an unsigned integer vector obtained by converting the components of a\n"
	"	floating-point vector to the 16-bit floating-point representation found in the OpenGL\n"
	"	Specification. The first vector component specifies the 16 least-significant bits of the\n"
	"	result; the forth component specifies the 16 most-significant bits."
);
PyDoc_STRVAR(packSnorm_docstr,
	"packSnorm(t: type, v: vecN) -> vecN\n"
	"	Convert each component of the normalized floating-point vector into signed integer values\n"
	"	of type `t`.\n"
	"	`t` can be any of the 8 integer types (`glm.int32`, `glm.int64`, `glm.uint8`, ...)."
);
PyDoc_STRVAR(packSnorm1x16_docstr,
	"packSnorm1x16(v: float) -> int\n"
	"	First, converts the normalized floating-point value `v` into 16-bit integer value. Then, the\n"
	"	results are packed into the returned 16-bit unsigned integer. The conversion to fixed point is\n"
	"	done as follows : `round(clamp(s, -1, +1) * 32767.0)`"
);
PyDoc_STRVAR(packSnorm1x8_docstr,
	"packSnorm1x8(v: float) -> int\n"
	"	First, converts the normalized floating-point value `v` into 8-bit integer value. Then, the\n"
	"	results are packed into the returned 8-bit unsigned integer. The conversion to fixed point is\n"
	"	done as follows : `round(clamp(v, -1, +1) * 127.0)`"
);
PyDoc_STRVAR(packSnorm2x8_docstr,
	"packSnorm2x8(v: fvec2) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 8-bit integer\n"
	"	values. Then, the results are packed into the returned 16-bit unsigned integer. The\n"
	"	conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, -1, +1) * 127.0)`. The first component of the vector will be\n"
	"	written to the least significant bits of the output; the last component will be written to\n"
	"	the most significant bits."
);
PyDoc_STRVAR(packSnorm3x10_1x2_docstr,
	"packSnorm3x10_1x2(v: fvec4) -> int\n"
	"	First, converts the first three components of the normalized floating-point value `v` into\n"
	"	10-bit signed integer values. Then, converts the forth component of the normalized\n"
	"	floating-point value `v` into 2-bit signed integer values. Then, the results are packed into\n"
	"	the returned 32-bit unsigned integer. The conversion for component c of v to fixed point\n"
	"	is done as follows : `packSnorm3x10_1x2(xyz)` : `round(clamp(c, -1, +1) * 511.0)`\n"
	"	`packSnorm3x10_1x2(w)` : `round(clamp(c, -1, +1) * 1.0)`. The first vector component specifies\n"
	"	the 10 least-significant bits of the result; the forth component specifies the 2\n"
	"	most-significant bits."
);
PyDoc_STRVAR(packSnorm4x16_docstr,
	"packSnorm4x16(v: fvec4) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 16-bit integer\n"
	"	values. Then, the results are packed into the returned 64-bit unsigned integer. The\n"
	"	conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, -1, +1) * 32767.0)`. The first component of the vector will be\n"
	"	written to the least significant bits of the output; the last component will be written to\n"
	"	the most significant bits."
);
PyDoc_STRVAR(packU3x10_1x2_docstr,
	"packU3x10_1x2(v: uvec4) -> int\n"
	"	Returns an unsigned integer obtained by converting the components of a four-component\n"
	"	unsigned integer vector to the 10-10-10-2-bit unsigned integer representation found in the\n"
	"	OpenGL Specification, and then packing these four values into a 32-bit unsigned integer.\n"
	"	The first vector component specifies the 10 least-significant bits of the result; the\n"
	"	forth component specifies the 2 most-significant bits."
);
PyDoc_STRVAR(packUint2x16_docstr,
	"packUint2x16(v: u16vec2) -> int\n"
	"	Convert each component from an integer vector into a packed unsigned integer."
);
PyDoc_STRVAR(packUint2x32_docstr,
	"packUint2x32(v: u32vec2) -> int\n"
	"	Convert each component from an integer vector into a packed unsigned integer."
);
PyDoc_STRVAR(packUint2x8_docstr,
	"packUint2x8(v: u8vec2) -> int\n"
	"	Convert each component from an integer vector into a packed unsigned integer."
);
PyDoc_STRVAR(packUint4x16_docstr,
	"packUint4x16(v: u16vec4) -> int\n"
	"	Convert each component from an integer vector into a packed unsigned integer."
);
PyDoc_STRVAR(packUint4x8_docstr,
	"packUint4x8(v: u16vec4) -> int\n"
	"	Convert each component from an integer vector into a packed unsigned integer."
);
PyDoc_STRVAR(packUnorm_docstr,
	"packUnorm(t: type, v: vecN) -> vecN\n"
	"	Convert each component of the normalized floating-point vector into unsigned integer values\n"
	"	of type `t`.\n"
	"	`t` can be any of the 4 unsigned integer types\n"
	"	(`glm.uint64`, `glm.uint32`, `glm.uint16`, `glm.uint8`)."
);
PyDoc_STRVAR(packUnorm1x16_docstr,
	"packUnorm1x16(v: float) -> int\n"
	"	First, converts the normalized floating-point value `v` into a 16-bit integer value. Then,\n"
	"	the results are packed into the returned 16-bit unsigned integer. The conversion for\n"
	"	component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, 0, +1) * 65535.0)`"
);
PyDoc_STRVAR(packUnorm1x5_1x6_1x5_docstr,
	"packUnorm1x5_1x6_1x5(v: fvec3) -> int\n"
	"	Convert each component of the normalized floating-point vector into unsigned integer\n"
	"	values."
);
PyDoc_STRVAR(packUnorm1x8_docstr,
	"packUnorm1x8(v: float) -> int\n"
	"	First, converts the normalized floating-point value `v` into a 8-bit integer value. Then, the\n"
	"	results are packed into the returned 8-bit unsigned integer. The conversion for component\n"
	"	`c` of `v` to fixed point is done as follows : `round(clamp(c, 0, +1) * 255.0)`"
);
PyDoc_STRVAR(packUnorm2x3_1x2_docstr,
	"packUnorm2x3_1x2(v: fvec3) -> int\n"
	"	Convert each component of the normalized floating-point vector into unsigned integer\n"
	"	values."
);
PyDoc_STRVAR(packUnorm2x4_docstr,
	"packUnorm2x4(v: fvec2) -> int\n"
	"	Convert each component of the normalized floating-point vector into unsigned integer\n"
	"	values."
);
PyDoc_STRVAR(packUnorm2x8_docstr,
	"packUnorm2x8(v: fvec2) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 8-bit integer\n"
	"	values. Then, the results are packed into the returned 16-bit unsigned integer. The\n"
	"	conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, 0, +1) * 255.0)`. The first component of the vector will be\n"
	"	written to the least significant bits of the output; the last component will be written to\n"
	"	the most significant bits."
);
PyDoc_STRVAR(packUnorm3x10_1x2_docstr,
	"packUnorm3x10_1x2(v: fvec4) -> int\n"
	"	First, converts the first three components of the normalized floating-point value `v` into\n"
	"	10-bit unsigned integer values. Then, converts the forth component of the normalized\n"
	"	floating-point value `v` into 2-bit signed uninteger values.Then, the results are packed into\n"
	"	the returned 32-bit unsigned integer. The conversion for component c of v to fixed point is\n"
	"	done as follows : `packUnorm3x10_1x2(xyz)` : `round(clamp(c, 0, +1) * 1023.0)`\n"
	"	`packUnorm3x10_1x2(w)` : `round(clamp(c, 0, +1) * 3.0)`. The first vector component specifies\n"
	"	the 10 least-significant bits of the result; the forth component specifies the 2\n"
	"	most-significant bits."
);
PyDoc_STRVAR(packUnorm3x5_1x1_docstr,
	"packUnorm3x5_1x1(v: fvec4) -> int\n"
	"	Convert each component of the normalized floating-point vector into unsigned integer\n"
	"	values."
);
PyDoc_STRVAR(packUnorm4x16_docstr,
	"packUnorm4x16(v: fvec4) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 16-bit integer\n"
	"	values. Then, the results are packed into the returned 64-bit unsigned integer. The\n"
	"	conversion for component c of v to fixed point is done as follows :\n"
	"	`round(clamp(c, 0, +1) * 65535.0)`. The first component of the vector will be\n"
	"	written to the least significant bits of the output; the last component will be written to\n"
	"	the most significant bits."
);
PyDoc_STRVAR(packUnorm4x4_docstr,
	"packUnorm4x4(v: fvec4) -> int\n"
	"	Convert each component of the normalized floating-point vector into unsigned integer\n"
	"	values."
);
PyDoc_STRVAR(unpackF2x11_1x10_docstr,
	"unpackF2x11_1x10(p: int) -> vec3\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into two 11-bit signless floating-point\n"
	"	values and one 10-bit signless floating-point value. Then, each component is converted to a\n"
	"	normalized floating-point value to generate the returned three-component vector. The\n"
	"	first component of the returned vector will be extracted from the least significant bits of\n"
	"	the input; the last component will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackF3x9_E1x5_docstr,
	"unpackF3x9_E1x5(p: int) -> vec3\n"
	"	First, unpacks a single 32-bit unsigned integer p into two 11-bit signless floating-point\n"
	"	values and one 10-bit signless floating-point value. Then, each component is converted to a\n"
	"	normalized floating-point value to generate the returned three-component vector. The\n"
	"	first component of the returned vector will be extracted from the least significant bits of\n"
	"	the input; the last component will be extracted from the most significant bits.\n"
	"	unpackF3x9_E1x5 allows decoding RGBE / RGB9E5 data"
);
PyDoc_STRVAR(unpackHalf_docstr,
	"unpackHalf(p: u16vecN) -> vecN\n"
	"	Returns a floating-point vector with components obtained by reinterpreting an integer\n"
	"	vector as 16-bit floating-point numbers and converting them to 32-bit floating-point\n"
	"	values. The first component of the vector is obtained from the 16 least-significant bits\n"
	"	of `v`; the forth component is obtained from the 16 most-significant bits of `v`."
);
PyDoc_STRVAR(unpackHalf1x16_docstr,
	"unpackHalf1x16(p: int) -> float\n"
	"	Returns a floating-point scalar with components obtained by unpacking a 16-bit unsigned\n"
	"	integer into a 16-bit value, interpreted as a 16-bit floating-point number according to the\n"
	"	OpenGL Specification, and converting it to 32-bit floating-point values."
);
PyDoc_STRVAR(unpackHalf4x16_docstr,
	"unpackHalf4x16(p: int) -> vec4\n"
	"	Returns a four-component floating-point vector with components obtained by unpacking a\n"
	"	64-bit unsigned integer into four 16-bit values, interpreting those values as 16-bit\n"
	"	floating-point numbers according to the OpenGL Specification, and converting them to 32-bit\n"
	"	floating-point values. The first component of the vector is obtained from the 16\n"
	"	least-significant bits of `v`; the forth component is obtained from the 16 most-significant\n"
	"	bits of `v`."
);
PyDoc_STRVAR(unpackI3x10_1x2_docstr,
	"unpackI3x10_1x2(p: int) -> ivec4\n"
	"	Unpacks a single 32-bit unsigned integer p into three 10-bit and one 2-bit signed integers.\n"
	"	The first component of the returned vector will be extracted from the least significant\n"
	"	bits of the input; the last component will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackInt2x16_docstr,
	"unpackInt2x16(p: int) -> i16vec2\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackInt2x32_docstr,
	"unpackInt2x32(p: int) -> i32vec2\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackInt2x8_docstr,
	"unpackInt2x8(p: int) -> i8vec2\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackInt4x16_docstr,
	"unpackInt4x16(p: int) -> i16vec4\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackInt4x8_docstr,
	"unpackInt4x8(p: int) -> i8vec4\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackRGBM_docstr,
	"unpackRGBM(rgbm: vec4) -> vec3\n"
	"	Returns a floating-point vector with components obtained by reinterpreting an integer\n"
	"	vector as 16-bit floating-point numbers and converting them to 32-bit floating-point\n"
	"	values. The first component of the vector is obtained from the 16 least-significant bits of\n"
	"	`v`; the forth component is obtained from the 16 most-significant bits of `v`."
);
PyDoc_STRVAR(unpackSnorm_docstr,
	"unpackSnorm(t: type, v: vecN) -> vecN\n"
	"	Convert a packed integer to a normalized floating-point vector of type `t`.\n"
	"	`t` can be either `glm.float` or `glm.double`."
);
PyDoc_STRVAR(unpackSnorm1x16_docstr,
	"unpackSnorm1x16(p: int) -> float\n"
	"	First, unpacks a single 16-bit unsigned integer `p` into a single 16-bit signed integers.\n"
	"	Then, each component is converted to a normalized floating-point value to generate the\n"
	"	returned scalar. The conversion for unpacked fixed-point value `f` to floating point is\n"
	"	done as follows : `clamp(f / 32767.0, -1, +1)`"
);
PyDoc_STRVAR(unpackSnorm1x8_docstr,
	"unpackSnorm1x8(p: int) -> float\n"
	"	First, unpacks a single 8-bit unsigned integer `p` into a single 8-bit signed integers.\n"
	"	Then, the value is converted to a normalized floating-point value to generate the\n"
	"	returned scalar. The conversion for unpacked fixed-point value `f` to floating point is\n"
	"	done as follows : `clamp(f / 127.0, -1, +1)`"
);
PyDoc_STRVAR(unpackSnorm2x8_docstr,
	"unpackSnorm2x8(p: int) -> vec2\n"
	"	First, unpacks a single 16-bit unsigned integer p into a pair of 8-bit signed integers.\n"
	"	Then, each component is converted to a normalized floating-point value to generate the\n"
	"	returned two-component vector. The conversion for unpacked fixed-point value `f` to\n"
	"	floating point is done as follows : `clamp(f / 127.0, -1, +1)`\n"
	"	The first component of the returned vector will be extracted from the least significant\n"
	"	bits of the input; the last component will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackSnorm3x10_1x2_docstr,
	"unpackSnorm3x10_1x2(p: int) -> vec4\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into four 16-bit signed integers. Then,\n"
	"	each component is converted to a normalized floating-point value to generate the returned\n"
	"	four-component vector. The conversion for unpacked fixed-point value `f` to floating point\n"
	"	is done as follows : `unpackSnorm3x10_1x2(xyz)` : `clamp(f / 511.0, -1, +1)`\n"
	"	`unpackSnorm3x10_1x2(w)` : `clamp(f / 511.0, -1, +1)`. The first component of the returned\n"
	"	vector will be extracted from the least significant bits of the input; the last component\n"
	"	will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackSnorm4x16_docstr,
	"unpackSnorm4x16(p: int) -> vec4\n"
	"	First, unpacks a single 64-bit unsigned integer `p` into four 16-bit signed integers. Then,\n"
	"	each component is converted to a normalized floating-point value to generate the returned\n"
	"	four-component vector. The conversion for unpacked fixed-point value `f` to floating point\n"
	"	is done as follows : `clamp(f / 32767.0, -1, +1)`\n"
	"	The first component of the returned vector will be extracted from the least significant\n"
	"	bits of the input; the last component will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackU3x10_1x2_docstr,
	"unpackU3x10_1x2(p: int) -> uvec4\n"
	"	Unpacks a single 32-bit unsigned integer `p` into three 10-bit and one 2-bit unsigned\n"
	"	integers. The first component of the returned vector will be extracted from the least\n"
	"	significant bits of the input; the last component will be extracted from the most\n"
	"	significant bits."
);
PyDoc_STRVAR(unpackUint2x16_docstr,
	"unpackUint2x16(p: int) -> u16vec2\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackUint2x32_docstr,
	"unpackUint2x32(p: int) -> u32vec2\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackUint2x8_docstr,
	"unpackUint2x8(p: int) -> u8vec2\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackUint4x16_docstr,
	"unpackUint4x16(p: int) -> u16vec4\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackUint4x8_docstr,
	"unpackUint4x8(p: int) -> u8vec4\n"
	"	Convert a packed integer into an integer vector."
);
PyDoc_STRVAR(unpackUnorm_docstr,
	"unpackUnorm(t: type, v: vecN) -> vecN\n"
	"	Convert a packed unsigned integer to a normalized floating-point vector of type `t`.\n"
	"	`t` can be either `glm.float` or `glm.double`."
);
PyDoc_STRVAR(unpackUnorm1x16_docstr,
	"unpackUnorm1x16(p: int) -> float\n"
	"	First, unpacks a single 16-bit unsigned integer `p` into a of 16-bit unsigned integers.\n"
	"	Then, the value is converted to a normalized floating-point value to generate the\n"
	"	returned scalar. The conversion for unpacked fixed-point value `f` to floating point is\n"
	"	done as follows : `f / 65535.0`"
);
PyDoc_STRVAR(unpackUnorm1x5_1x6_1x5_docstr,
	"unpackUnorm1x5_1x6_1x5(p: int) -> vec3\n"
	"	Convert a packed integer to a normalized floating-point vector."
);
PyDoc_STRVAR(unpackUnorm1x8_docstr,
	"unpackUnorm1x8(p: int) -> float\n"
	"	Convert a single 8-bit integer to a normalized floating-point value. The conversion for\n"
	"	unpacked fixed-point value `f` to floating point is done as follows :\n"
	"	`f / 255.0`"
);
PyDoc_STRVAR(unpackUnorm2x3_1x2_docstr,
	"unpackUnorm2x3_1x2(p: int) -> vec3\n"
	"	Convert a packed integer to a normalized floating-point vector."
);
PyDoc_STRVAR(unpackUnorm2x4_docstr,
	"unpackUnorm2x4(p: int) -> vec2\n"
	"	Convert a packed integer to a normalized floating-point vector."
);
PyDoc_STRVAR(unpackUnorm2x8_docstr,
	"unpackUnorm2x8(p: int) -> vec2\n"
	"	First, unpacks a single 16-bit unsigned integer `p` into a pair of 8-bit unsigned integers.\n"
	"	Then, each component is converted to a normalized floating-point value to generate the\n"
	"	returned two-component vector. The conversion for unpacked fixed-point value `f` to\n"
	"	floating point is done as follows : `f / 255.0`. The first component of the\n"
	"	returned vector will be extracted from the least significant bits of the input; the last\n"
	"	component will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackUnorm3x10_1x2_docstr,
	"unpackUnorm3x10_1x2(p: int) -> vec4\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into four 16-bit signed integers.\n"
	"	Then, each component is converted to a normalized floating-point value to generate the\n"
	"	returned four-component vector. The conversion for unpacked fixed-point value `f` to\n"
	"	floating point is done as follows : `unpackSnorm3x10_1x2(xyz)` : `clamp(f / 1023.0, 0, +1)`\n"
	"	`unpackSnorm3x10_1x2(w)` : `clamp(f / 3.0, 0, +1)`. The first component of the returned vector\n"
	"	will be extracted from the least significant bits of the input; the last component will be\n"
	"	extracted from the most significant bits."
);
PyDoc_STRVAR(unpackUnorm3x5_1x1_docstr,
	"unpackUnorm3x5_1x1(p: int) -> vec4\n"
	"	Convert a packed integer to a normalized floating-point vector."
);
PyDoc_STRVAR(unpackUnorm4x16_docstr,
	"unpackUnorm4x16(p: int) -> vec4\n"
	"	First, unpacks a single 64-bit unsigned integer `p` into four 16-bit unsigned integers.\n"
	"	Then, each component is converted to a normalized floating-point value to generate the\n"
	"	returned four-component vector. The conversion for unpacked fixed-point value `f` to\n"
	"	floating point is done as follows : `f / 65535.0`. The first component of\n"
	"	the returned vector will be extracted from the least significant bits of the input; the\n"
	"	last component will be extracted from the most significant bits."
);
PyDoc_STRVAR(unpackUnorm4x4_docstr,
	"unpackUnorm4x4(p: int) -> vec4\n"
	"	Convert a packed integer to a normalized floating-point vector."
);


#define PACKING_METHODS \
{ "packInt2x8", (PyCFunction)packInt2x8_, METH_O, packInt2x8_docstr }, \
{ "unpackInt2x8", (PyCFunction)unpackInt2x8_, METH_O, unpackInt2x8_docstr }, \
{ "packInt4x8", (PyCFunction)packInt4x8_, METH_O, packInt4x8_docstr }, \
{ "unpackInt4x8", (PyCFunction)unpackInt4x8_, METH_O, unpackInt4x8_docstr }, \
{ "packInt2x16", (PyCFunction)packInt2x16_, METH_O, packInt2x16_docstr }, \
{ "unpackInt2x16", (PyCFunction)unpackInt2x16_, METH_O, unpackInt2x16_docstr }, \
{ "packInt4x16", (PyCFunction)packInt4x16_, METH_O, packInt4x16_docstr }, \
{ "unpackInt4x16", (PyCFunction)unpackInt4x16_, METH_O, unpackInt4x16_docstr }, \
{ "packInt2x32", (PyCFunction)packInt2x32_, METH_O, packInt2x32_docstr }, \
{ "unpackInt2x32", (PyCFunction)unpackInt2x32_, METH_O, unpackInt2x32_docstr }, \
{ "packUint2x8", (PyCFunction)packUint2x8_, METH_O, packUint2x8_docstr }, \
{ "unpackUint2x8", (PyCFunction)unpackUint2x8_, METH_O, unpackUint2x8_docstr }, \
{ "packUint4x8", (PyCFunction)packUint4x8_, METH_O, packUint4x8_docstr }, \
{ "unpackUint4x8", (PyCFunction)unpackUint4x8_, METH_O, unpackUint4x8_docstr }, \
{ "packUint2x16", (PyCFunction)packUint2x16_, METH_O, packUint2x16_docstr }, \
{ "unpackUint2x16", (PyCFunction)unpackUint2x16_, METH_O, unpackUint2x16_docstr }, \
{ "packUint4x16", (PyCFunction)packUint4x16_, METH_O, packUint4x16_docstr }, \
{ "unpackUint4x16", (PyCFunction)unpackUint4x16_, METH_O, unpackUint4x16_docstr }, \
{ "packUint2x32", (PyCFunction)packUint2x32_, METH_O, packUint2x32_docstr }, \
{ "unpackUint2x32", (PyCFunction)unpackUint2x32_, METH_O, unpackUint2x32_docstr }, \
{ "packHalf1x16", (PyCFunction)packHalf1x16_, METH_O, packHalf1x16_docstr }, \
{ "unpackHalf1x16", (PyCFunction)unpackHalf1x16_, METH_O, unpackHalf1x16_docstr }, \
{ "packHalf4x16", (PyCFunction)packHalf4x16_, METH_O, packHalf4x16_docstr }, \
{ "unpackHalf4x16", (PyCFunction)unpackHalf4x16_, METH_O, unpackHalf4x16_docstr }, \
{ "packUnorm", (PyCFunction)packUnorm_, METH_VARARGS, packUnorm_docstr }, \
{ "unpackUnorm", (PyCFunction)unpackUnorm_, METH_VARARGS, unpackUnorm_docstr }, \
{ "packUnorm1x8", (PyCFunction)packUnorm1x8_, METH_O, packUnorm1x8_docstr }, \
{ "unpackUnorm1x8", (PyCFunction)unpackUnorm1x8_, METH_O, unpackUnorm1x8_docstr }, \
{ "packUnorm2x8", (PyCFunction)packUnorm2x8_, METH_O, packUnorm2x8_docstr }, \
{ "unpackUnorm2x8", (PyCFunction)unpackUnorm2x8_, METH_O, unpackUnorm2x8_docstr }, \
{ "packUnorm1x16", (PyCFunction)packUnorm1x16_, METH_O, packUnorm1x16_docstr }, \
{ "unpackUnorm1x16", (PyCFunction)unpackUnorm1x16_, METH_O, unpackUnorm1x16_docstr }, \
{ "packUnorm4x16", (PyCFunction)packUnorm4x16_, METH_O, packUnorm4x16_docstr }, \
{ "unpackUnorm4x16", (PyCFunction)unpackUnorm4x16_, METH_O, unpackUnorm4x16_docstr }, \
{ "packUnorm3x10_1x2", (PyCFunction)packUnorm3x10_1x2_, METH_O, packUnorm3x10_1x2_docstr }, \
{ "unpackUnorm3x10_1x2", (PyCFunction)unpackUnorm3x10_1x2_, METH_O, unpackUnorm3x10_1x2_docstr }, \
{ "packUnorm2x4", (PyCFunction)packUnorm2x4_, METH_O, packUnorm2x4_docstr }, \
{ "unpackUnorm2x4", (PyCFunction)unpackUnorm2x4_, METH_O, unpackUnorm2x4_docstr }, \
{ "packUnorm4x4", (PyCFunction)packUnorm4x4_, METH_O, packUnorm4x4_docstr }, \
{ "unpackUnorm4x4", (PyCFunction)unpackUnorm4x4_, METH_O, unpackUnorm4x4_docstr }, \
{ "packUnorm1x5_1x6_1x5", (PyCFunction)packUnorm1x5_1x6_1x5_, METH_O, packUnorm1x5_1x6_1x5_docstr }, \
{ "unpackUnorm1x5_1x6_1x5", (PyCFunction)unpackUnorm1x5_1x6_1x5_, METH_O, unpackUnorm1x5_1x6_1x5_docstr }, \
{ "packUnorm3x5_1x1", (PyCFunction)packUnorm3x5_1x1_, METH_O, packUnorm3x5_1x1_docstr }, \
{ "unpackUnorm3x5_1x1", (PyCFunction)unpackUnorm3x5_1x1_, METH_O, unpackUnorm3x5_1x1_docstr }, \
{ "packUnorm2x3_1x2", (PyCFunction)packUnorm2x3_1x2_, METH_O, packUnorm2x3_1x2_docstr }, \
{ "unpackUnorm2x3_1x2", (PyCFunction)unpackUnorm2x3_1x2_, METH_O, unpackUnorm2x3_1x2_docstr }, \
{ "packSnorm", (PyCFunction)packSnorm_, METH_VARARGS, packSnorm_docstr }, \
{ "unpackSnorm", (PyCFunction)unpackSnorm_, METH_VARARGS, unpackSnorm_docstr }, \
{ "packSnorm1x8", (PyCFunction)packSnorm1x8_, METH_O, packSnorm1x8_docstr }, \
{ "unpackSnorm1x8", (PyCFunction)unpackSnorm1x8_, METH_O, unpackSnorm1x8_docstr }, \
{ "packSnorm2x8", (PyCFunction)packSnorm2x8_, METH_O, packSnorm2x8_docstr }, \
{ "unpackSnorm2x8", (PyCFunction)unpackSnorm2x8_, METH_O, unpackSnorm2x8_docstr }, \
{ "packSnorm1x16", (PyCFunction)packSnorm1x16_, METH_O, packSnorm1x16_docstr }, \
{ "unpackSnorm1x16", (PyCFunction)unpackSnorm1x16_, METH_O, unpackSnorm1x16_docstr }, \
{ "packSnorm4x16", (PyCFunction)packSnorm4x16_, METH_O, packSnorm4x16_docstr }, \
{ "unpackSnorm4x16", (PyCFunction)unpackSnorm4x16_, METH_O, unpackSnorm4x16_docstr }, \
{ "packSnorm3x10_1x2", (PyCFunction)packSnorm3x10_1x2_, METH_O, packSnorm3x10_1x2_docstr }, \
{ "unpackSnorm3x10_1x2", (PyCFunction)unpackSnorm3x10_1x2_, METH_O, unpackSnorm3x10_1x2_docstr }, \
{ "packI3x10_1x2", (PyCFunction)packI3x10_1x2_, METH_O, packI3x10_1x2_docstr }, \
{ "unpackI3x10_1x2", (PyCFunction)unpackI3x10_1x2_, METH_O, unpackI3x10_1x2_docstr }, \
{ "packU3x10_1x2", (PyCFunction)packU3x10_1x2_, METH_O, packU3x10_1x2_docstr }, \
{ "unpackU3x10_1x2", (PyCFunction)unpackU3x10_1x2_, METH_O, unpackU3x10_1x2_docstr }, \
{ "packF2x11_1x10", (PyCFunction)packF2x11_1x10_, METH_O, packF2x11_1x10_docstr }, \
{ "unpackF2x11_1x10", (PyCFunction)unpackF2x11_1x10_, METH_O, unpackF2x11_1x10_docstr }, \
{ "packF3x9_E1x5", (PyCFunction)packF3x9_E1x5_, METH_O, packF3x9_E1x5_docstr }, \
{ "unpackF3x9_E1x5", (PyCFunction)unpackF3x9_E1x5_, METH_O, unpackF3x9_E1x5_docstr }, \
{ "packRGBM", (PyCFunction)packRGBM_, METH_O, packRGBM_docstr }, \
{ "unpackRGBM", (PyCFunction)unpackRGBM_, METH_O, unpackRGBM_docstr }, \
{ "packHalf", (PyCFunction)packHalf_, METH_O, packHalf_docstr }, \
{ "unpackHalf", (PyCFunction)unpackHalf_, METH_O, unpackHalf_docstr }
