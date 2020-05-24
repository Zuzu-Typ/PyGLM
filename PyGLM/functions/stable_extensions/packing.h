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

#define PACKING_METHODS { "packInt2x8", (PyCFunction)packInt2x8_, METH_O, "packInt2x8(v) -> int\nConvert each component from an integer vector into a packed integer." }, \
{ "unpackInt2x8", (PyCFunction)unpackInt2x8_, METH_O, "unpackInt2x8(v) -> i8vec2\nConvert a packed integer into an integer vector." }, \
{ "packInt4x8", (PyCFunction)packInt4x8_, METH_O, "packInt4x8(v) -> int\nConvert each component from an integer vector into a packed integer." }, \
{ "unpackInt4x8", (PyCFunction)unpackInt4x8_, METH_O, "unpackInt4x8(v) -> i8vec4\nConvert a packed integer into an integer vector." }, \
{ "packInt2x16", (PyCFunction)packInt2x16_, METH_O, "packInt2x16(v) -> int\nConvert each component from an integer vector into a packed integer." }, \
{ "unpackInt2x16", (PyCFunction)unpackInt2x16_, METH_O, "unpackInt2x16(v) -> i16vec2\nConvert a packed integer into an integer vector." }, \
{ "packInt4x16", (PyCFunction)packInt4x16_, METH_O, "packInt4x16(v) -> int\nConvert each component from an integer vector into a packed integer." }, \
{ "unpackInt4x16", (PyCFunction)unpackInt4x16_, METH_O, "unpackInt4x16(v) -> i16vec4\nConvert a packed integer into an integer vector." }, \
{ "packInt2x32", (PyCFunction)packInt2x32_, METH_O, "packInt2x32(v) -> int\nConvert each component from an integer vector into a packed integer." }, \
{ "unpackInt2x32", (PyCFunction)unpackInt2x32_, METH_O, "unpackInt2x32(v) -> i32vec2\nConvert a packed integer into an integer vector." }, \
{ "packUint2x8", (PyCFunction)packUint2x8_, METH_O, "packUint2x8(v) -> int\nConvert each component from an integer vector into a packed unsigned integer." }, \
{ "unpackUint2x8", (PyCFunction)unpackUint2x8_, METH_O, "unpackUint2x8(v) -> u8vec2\nConvert a packed integer into an integer vector." }, \
{ "packUint4x8", (PyCFunction)packUint4x8_, METH_O, "packUint4x8(v) -> int\nConvert each component from an integer vector into a packed unsigned integer." }, \
{ "unpackUint4x8", (PyCFunction)unpackUint4x8_, METH_O, "unpackUint4x8(v) -> u8vec4\nConvert a packed integer into an integer vector." }, \
{ "packUint2x16", (PyCFunction)packUint2x16_, METH_O, "packUint2x16(v) -> int\nConvert each component from an integer vector into a packed unsigned integer." }, \
{ "unpackUint2x16", (PyCFunction)unpackUint2x16_, METH_O, "unpackUint2x16(v) -> u16vec2\nConvert a packed integer into an integer vector." }, \
{ "packUint4x16", (PyCFunction)packUint4x16_, METH_O, "packUint4x16(v) -> int\nConvert each component from an integer vector into a packed unsigned integer." }, \
{ "unpackUint4x16", (PyCFunction)unpackUint4x16_, METH_O, "unpackUint4x16(v) -> u16vec4\nConvert a packed integer into an integer vector." }, \
{ "packUint2x32", (PyCFunction)packUint2x32_, METH_O, "packUint2x32(v) -> int\nConvert each component from an integer vector into a packed unsigned integer." }, \
{ "unpackUint2x32", (PyCFunction)unpackUint2x32_, METH_O, "unpackUint2x32(v) -> u32vec2\nConvert a packed integer into an integer vector." }, \
{ "packHalf1x16", (PyCFunction)packHalf1x16_, METH_O, "packHalf1x16(v) -> int\nReturns an unsigned integer obtained by converting the components of a floating-point scalar\nto the 16-bit floating-point representation found in the OpenGL Specification,\nand then packing this 16-bit value into a 16-bit unsigned integer." }, \
{ "unpackHalf1x16", (PyCFunction)unpackHalf1x16_, METH_O, "unpackHalf1x16(v) -> float\nReturns a floating-point scalar with components obtained by unpacking a 16-bit unsigned integer into a 16-bit value,\ninterpreted as a 16-bit floating-point number according to the OpenGL Specification,\nand converting it to 32-bit floating-point values." }, \
{ "packHalf4x16", (PyCFunction)packHalf4x16_, METH_O, "packHalf4x16(v) -> int\nReturns an unsigned integer obtained by converting the components of a floating-point scalar\nto the 16-bit floating-point representation found in the OpenGL Specification,\nand then packing this 16-bit value into a 16-bit unsigned integer." }, \
{ "unpackHalf4x16", (PyCFunction)unpackHalf4x16_, METH_O, "unpackHalf4x16(v) -> vec4\nReturns a floating-point scalar with components obtained by unpacking a 16-bit unsigned integer into a 16-bit value,\ninterpreted as a 16-bit floating-point number according to the OpenGL Specification,\nand converting it to 32-bit floating-point values." }, \
{ "packUnorm1x8", (PyCFunction)packUnorm1x8_, METH_O, "packUnorm1x8(v) -> int\nFirst, converts the normalized floating-point value v into a 8-bit integer value.\nThen, the results are packed into the returned 8-bit unsigned integer." }, \
{ "unpackUnorm1x8", (PyCFunction)unpackUnorm1x8_, METH_O, "unpackUnorm1x8(v) -> float\nConvert a single 8-bit integer to a normalized floating-point value." }, \
{ "packUnorm2x8", (PyCFunction)packUnorm2x8_, METH_O, "packUnorm2x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8-bit integer values.\nThen, the results are packed into the returned 16-bit unsigned integer." }, \
{ "unpackUnorm2x8", (PyCFunction)unpackUnorm2x8_, METH_O, "unpackUnorm2x8(v) -> vec2\nFirst, unpacks a single 16-bit unsigned integer p into a pair of 8-bit unsigned integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two-component vector." }, \
{ "packUnorm1x16", (PyCFunction)packUnorm1x16_, METH_O, "packUnorm1x16(v) -> int\nFirst, converts the normalized floating-point value v into a 16-bit integer value.\nThen, the results are packed into the returned 16-bit unsigned integer." }, \
{ "unpackUnorm1x16", (PyCFunction)unpackUnorm1x16_, METH_O, "unpackUnorm1x16(v) -> float\nFirst, unpacks a single 16-bit unsigned integer p into a of 16-bit unsigned integers.\nThen, the value is converted to a normalized floating-point value to generate the returned scalar." }, \
{ "packUnorm4x16", (PyCFunction)packUnorm4x16_, METH_O, "packUnorm4x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 16-bit integer values.\nThen, the results are packed into the returned 64-bit unsigned integer." }, \
{ "unpackUnorm4x16", (PyCFunction)unpackUnorm4x16_, METH_O, "unpackUnorm4x16(v) -> vec4\nFirst, unpacks a single 64-bit unsigned integer p into four 16-bit unsigned integers.\nThen, each component is converted to a normalized floating-point value to generate the returned four-component vector." }, \
{ "packUnorm3x10_1x2", (PyCFunction)packUnorm3x10_1x2_, METH_O, "packUnorm3x10_1x2(v) -> int\nFirst, converts the first three components of the normalized floating-point value v into 10-bit unsigned integer values.\nThen, converts the forth component of the normalized floating-point value v into 2-bit signed uninteger values.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "unpackUnorm3x10_1x2", (PyCFunction)unpackUnorm3x10_1x2_, METH_O, "unpackUnorm3x10_1x2(v) -> vec4\nFirst, unpacks a single 32-bit unsigned integer p into four 16-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned four-component vector." }, \
{ "packUnorm2x4", (PyCFunction)packUnorm2x4_, METH_O, "packUnorm2x4(v) -> int\nConvert each component of the normalized floating-point vector into unsigned integer values." }, \
{ "unpackUnorm2x4", (PyCFunction)unpackUnorm2x4_, METH_O, "unpackUnorm2x4(v) -> vec2\nConvert a packed integer to a normalized floating-point vector." }, \
{ "packUnorm4x4", (PyCFunction)packUnorm4x4_, METH_O, "packUnorm4x4(v) -> int\nConvert each component of the normalized floating-point vector into unsigned integer values." }, \
{ "unpackUnorm4x4", (PyCFunction)unpackUnorm4x4_, METH_O, "unpackUnorm4x4(v) -> vec2\nConvert a packed integer to a normalized floating-point vector." }, \
{ "packUnorm1x5_1x6_1x5", (PyCFunction)packUnorm1x5_1x6_1x5_, METH_O, "packUnorm1x5_1x6_1x5(v) -> int\nConvert each component of the normalized floating-point vector into unsigned integer values." }, \
{ "unpackUnorm1x5_1x6_1x5", (PyCFunction)unpackUnorm1x5_1x6_1x5_, METH_O, "unpackUnorm1x5_1x6_1x5(v) -> vec3\nConvert a packed integer to a normalized floating-point vector." }, \
{ "packUnorm3x5_1x1", (PyCFunction)packUnorm3x5_1x1_, METH_O, "packUnorm3x5_1x1(v) -> int\nConvert each component of the normalized floating-point vector into unsigned integer values." }, \
{ "unpackUnorm3x5_1x1", (PyCFunction)unpackUnorm3x5_1x1_, METH_O, "unpackUnorm3x5_1x1(v) -> vec2\nConvert a packed integer to a normalized floating-point vector." }, \
{ "packUnorm2x3_1x2", (PyCFunction)packUnorm2x3_1x2_, METH_O, "packUnorm2x3_1x2(v) -> int\nConvert each component of the normalized floating-point vector into unsigned integer values." }, \
{ "unpackUnorm2x3_1x2", (PyCFunction)unpackUnorm2x3_1x2_, METH_O, "unpackUnorm2x3_1x2(v) -> vec2\nConvert a packed integer to a normalized floating-point vector." }, \
{ "packSnorm1x8", (PyCFunction)packSnorm1x8_, METH_O, "packSnorm1x8(v) -> int\nFirst, converts the normalized floating-point value v into a 8-bit integer value.\nThen, the results are packed into the returned 8-bit unsigned integer." }, \
{ "unpackSnorm1x8", (PyCFunction)unpackSnorm1x8_, METH_O, "unpackSnorm1x8(v) -> float\nConvert a single 8-bit integer to a normalized floating-point value." }, \
{ "packSnorm2x8", (PyCFunction)packSnorm2x8_, METH_O, "packSnorm2x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8-bit integer values.\nThen, the results are packed into the returned 16-bit unsigned integer." }, \
{ "unpackSnorm2x8", (PyCFunction)unpackSnorm2x8_, METH_O, "unpackSnorm2x8(v) -> vec2\nFirst, unpacks a single 16-bit unsigned integer p into a pair of 8-bit unsigned integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two-component vector." }, \
{ "packSnorm1x16", (PyCFunction)packSnorm1x16_, METH_O, "packSnorm1x16(v) -> int\nFirst, converts the normalized floating-point value v into a 16-bit integer value.\nThen, the results are packed into the returned 16-bit unsigned integer." }, \
{ "unpackSnorm1x16", (PyCFunction)unpackSnorm1x16_, METH_O, "unpackSnorm1x16(v) -> float\nFirst, unpacks a single 16-bit unsigned integer p into a of 16-bit unsigned integers.\nThen, the value is converted to a normalized floating-point value to generate the returned scalar." }, \
{ "packSnorm4x16", (PyCFunction)packSnorm4x16_, METH_O, "packSnorm4x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 16-bit integer values.\nThen, the results are packed into the returned 64-bit unsigned integer." }, \
{ "unpackSnorm4x16", (PyCFunction)unpackSnorm4x16_, METH_O, "unpackSnorm4x16(v) -> vec4\nFirst, unpacks a single 64-bit unsigned integer p into four 16-bit unsigned integers.\nThen, each component is converted to a normalized floating-point value to generate the returned four-component vector." }, \
{ "packSnorm3x10_1x2", (PyCFunction)packSnorm3x10_1x2_, METH_O, "packSnorm3x10_1x2(v) -> int\nFirst, converts the first three components of the normalized floating-point value v into 10-bit unsigned integer values.\nThen, converts the forth component of the normalized floating-point value v into 2-bit signed uninteger values.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "unpackSnorm3x10_1x2", (PyCFunction)unpackSnorm3x10_1x2_, METH_O, "unpackSnorm3x10_1x2(v) -> vec4\nFirst, unpacks a single 32-bit unsigned integer p into four 16-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned four-component vector." }, \
{ "packI3x10_1x2", (PyCFunction)packI3x10_1x2_, METH_O, "packI3x10_1x2(v) -> int\nReturns an unsigned integer obtained by converting the components of a four-component signed integer vector\nto the 10-10-10-2-bit signed integer representation found in the OpenGL Specification,\nand then packing these four values into a 32-bit unsigned integer.\nThe first vector component specifies the 10 least-significant bits of the result;\nthe forth component specifies the 2 most-significant bits." }, \
{ "unpackI3x10_1x2", (PyCFunction)unpackI3x10_1x2_, METH_O, "unpackI3x10_1x2(v) -> ivec4\nUnpacks a single 32-bit unsigned integer p into three 10-bit and one 2-bit signed integers." }, \
{ "packU3x10_1x2", (PyCFunction)packU3x10_1x2_, METH_O, "packU3x10_1x2(v) -> int\nReturns an unsigned integer obtained by converting the components of a four-component unsigned integer vector\nto the 10-10-10-2-bit unsigned integer representation found in the OpenGL Specification,\nand then packing these four values into a 32-bit unsigned integer.\nThe first vector component specifies the 10 least-significant bits of the result;\nthe forth component specifies the 2 most-significant bits." }, \
{ "unpackU3x10_1x2", (PyCFunction)unpackU3x10_1x2_, METH_O, "unpackU3x10_1x2(v) -> uvec4\nUnpacks a single 32-bit unsigned integer p into three 10-bit and one 2-bit unsigned integers." }, \
{ "packF2x11_1x10", (PyCFunction)packF2x11_1x10_, METH_O, "packF2x11_1x10(v) -> int\nFirst, converts the first two components of the normalized floating-point value v into 11-bit signless floating-point values.\nThen, converts the third component of the normalized floating-point value v into a 10-bit signless floating-point value.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "unpackF2x11_1x10", (PyCFunction)unpackF2x11_1x10_, METH_O, "unpackF2x11_1x10(v) -> vec3\nFirst, unpacks a single 32-bit unsigned integer p into two 11-bit signless floating-point values and one 10-bit signless floating-point value.\nThen, each component is converted to a normalized floating-point value to generate the returned three-component vector." }, \
{ "packF3x9_E1x5", (PyCFunction)packF3x9_E1x5_, METH_O, "packF3x9_E1x5(v) -> int\nFirst, converts the first two components of the normalized floating-point value v into 11-bit signless floating-point values.\nThen, converts the third component of the normalized floating-point value v into a 10-bit signless floating-point value.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "unpackF3x9_E1x5", (PyCFunction)unpackF3x9_E1x5_, METH_O, "unpackF3x9_E1x5(v) -> vec3\nFirst, unpacks a single 32-bit unsigned integer p into two 11-bit signless floating-point values and one 10-bit signless floating-point value.\nThen, each component is converted to a normalized floating-point value to generate the returned three-component vector." }, \
{ "packRGBM", (PyCFunction)packRGBM_, METH_O, "packRGBM(v) -> vec4\nReturns an unsigned integer vector obtained by converting the components of a floating-point vector\nto the 16-bit floating-point representation found in the OpenGL Specification.\nThe first vector component specifies the 16 least-significant bits of the result;\nthe forth component specifies the 16 most-significant bits." }, \
{ "unpackRGBM", (PyCFunction)unpackRGBM_, METH_O, "unpackRGBM(v) -> vec3\nReturns a floating-point vector with components obtained by reinterpreting an integer vector as 16-bit floating-point numbers and converting them to 32-bit floating-point values.\nThe first component of the vector is obtained from the 16 least-significant bits of v;\nthe forth component is obtained from the 16 most-significant bits of v." }, \
{ "packHalf", (PyCFunction)packHalf_, METH_O, "packHalf(v) -> u16vecn\nReturns an unsigned integer vector obtained by converting the components of a floating-point vector\nto the 16-bit floating-point representation found in the OpenGL Specification.\nThe first vector component specifies the 16 least-significant bits of the result;\nthe forth component specifies the 16 most-significant bits." }, \
{ "unpackHalf", (PyCFunction)unpackHalf_, METH_O, "unpackHalf(v) -> vecn\nReturns a floating-point vector with components obtained by reinterpreting an integer vector as 16-bit floating-point numbers and converting them to 32-bit floating-point values.\nThe first component of the vector is obtained from the 16 least-significant bits of v;\nthe forth component is obtained from the 16 most-significant bits of v." }
