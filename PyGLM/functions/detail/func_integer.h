#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

PyDoc_STRVAR(uaddCarry_docstr,
	"uaddCarry(x: uvecN, y: uvecN, carry: uvecN) -> uvecN\n"
	"	Adds 32-bit unsigned integer `x` and `y`, returning the `sum` modulo `pow(2, 32)`. The value carry\n"
	"	is set to `0` if the `sum` was less than `pow(2, 32)`, or to `1` otherwise."
);
static PyObject*
uaddCarry_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "uaddCarry", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "uaddCarry() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && Py_TYPE(arg3) == &huvec1Type) {
		glm::uvec1 o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
		glm::uvec1 o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
		return pack_vec(glm::uaddCarry(o, o2, ((vec<1, glm::uint>*)arg3)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && Py_TYPE(arg3) == &huvec2Type) {
		glm::uvec2 o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
		glm::uvec2 o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
		return pack_vec(glm::uaddCarry(o, o2, ((vec<2, glm::uint>*)arg3)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && Py_TYPE(arg3) == &huvec3Type) {
		glm::uvec3 o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
		glm::uvec3 o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
		return pack_vec(glm::uaddCarry(o, o2, ((vec<3, glm::uint>*)arg3)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && Py_TYPE(arg3) == &huvec4Type) {
		glm::uvec4 o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
		glm::uvec4 o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
		return pack_vec(glm::uaddCarry(o, o2, ((vec<4, glm::uint>*)arg3)->super_type));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for uaddCarry()");
	return NULL;
}

PyDoc_STRVAR(usubBorrow_docstr,
	"usubBorrow(x: uvecN, y: uvecN, borrow: uvecN) -> uvecN\n"
	"	Subtracts the 32-bit unsigned integer `y` from `x`, returning the difference if non-negative,\n"
	"	or `pow(2, 32)` plus the difference otherwise. The value borrow is set to `0` if `x >= y`, or to\n"
	"	`1` otherwise."
);
static PyObject*
usubBorrow_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "usubBorrow", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "usubBorrow() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && Py_TYPE(arg3) == &huvec1Type) {
		glm::uvec1 o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
		glm::uvec1 o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
		return pack_vec(glm::usubBorrow(o, o2, ((vec<1, glm::uint>*)arg3)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && Py_TYPE(arg3) == &huvec2Type) {
		glm::uvec2 o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
		glm::uvec2 o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
		return pack_vec(glm::usubBorrow(o, o2, ((vec<2, glm::uint>*)arg3)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && Py_TYPE(arg3) == &huvec3Type) {
		glm::uvec3 o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
		glm::uvec3 o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
		return pack_vec(glm::usubBorrow(o, o2, ((vec<3, glm::uint>*)arg3)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && Py_TYPE(arg3) == &huvec4Type) {
		glm::uvec4 o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
		glm::uvec4 o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
		return pack_vec(glm::usubBorrow(o, o2, ((vec<4, glm::uint>*)arg3)->super_type));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for usubBorrow()");
	return NULL;
}

PyDoc_STRVAR(umulExtended_docstr,
	"umulExtended(x: uvecN, y: uvecN, msb: uvecN, lsb: uvecN) -> uvecN\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`."
);
static PyObject*
umulExtended_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "umulExtended", arg1, arg2, arg3, arg4);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "umulExtended() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && Py_TYPE(arg3) == &huvec1Type && Py_TYPE(arg4) == &huvec1Type) {
		glm::uvec1 o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
		glm::uvec1 o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
		glm::umulExtended(o, o2, ((vec<1, glm::uint>*)arg3)->super_type, ((vec<1, glm::uint>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && Py_TYPE(arg3) == &huvec2Type && Py_TYPE(arg4) == &huvec2Type) {
		glm::uvec2 o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
		glm::uvec2 o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
		glm::umulExtended(o, o2, ((vec<2, glm::uint>*)arg3)->super_type, ((vec<2, glm::uint>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && Py_TYPE(arg3) == &huvec3Type && Py_TYPE(arg4) == &huvec3Type) {
		glm::uvec3 o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
		glm::uvec3 o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
		glm::umulExtended(o, o2, ((vec<3, glm::uint>*)arg3)->super_type, ((vec<3, glm::uint>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && Py_TYPE(arg3) == &huvec4Type && Py_TYPE(arg4) == &huvec4Type) {
		glm::uvec4 o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
		glm::uvec4 o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
		glm::umulExtended(o, o2, ((vec<4, glm::uint>*)arg3)->super_type, ((vec<4, glm::uint>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for umulExtended()");
	return NULL;
}

PyDoc_STRVAR(imulExtended_docstr,
	"imulExtended(x: ivecN, y: ivecN, msb: ivecN, lsb: ivecN) -> ivecN\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`."
);
static PyObject*
imulExtended_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "imulExtended", arg1, arg2, arg3, arg4);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "imulExtended() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2) && Py_TYPE(arg3) == &hivec1Type && Py_TYPE(arg4) == &hivec1Type) {
		glm::ivec1 o = PyGLM_Vec_PTI_Get0(1, int, arg1);
		glm::ivec1 o2 = PyGLM_Vec_PTI_Get1(1, int, arg2);
		glm::imulExtended(o, o2, ((vec<1, int>*)arg3)->super_type, ((vec<1, int>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2) && Py_TYPE(arg3) == &hivec2Type && Py_TYPE(arg4) == &hivec2Type) {
		glm::ivec2 o = PyGLM_Vec_PTI_Get0(2, int, arg1);
		glm::ivec2 o2 = PyGLM_Vec_PTI_Get1(2, int, arg2);
		glm::imulExtended(o, o2, ((vec<2, int>*)arg3)->super_type, ((vec<2, int>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2) && Py_TYPE(arg3) == &hivec3Type && Py_TYPE(arg4) == &hivec3Type) {
		glm::ivec3 o = PyGLM_Vec_PTI_Get0(3, int, arg1);
		glm::ivec3 o2 = PyGLM_Vec_PTI_Get1(3, int, arg2);
		glm::imulExtended(o, o2, ((vec<3, int>*)arg3)->super_type, ((vec<3, int>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2) && Py_TYPE(arg3) == &hivec4Type && Py_TYPE(arg4) == &hivec4Type) {
		glm::ivec4 o = PyGLM_Vec_PTI_Get0(4, int, arg1);
		glm::ivec4 o2 = PyGLM_Vec_PTI_Get1(4, int, arg2);
		glm::imulExtended(o, o2, ((vec<4, int>*)arg3)->super_type, ((vec<4, int>*)arg4)->super_type);
		Py_RETURN_NONE;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for imulExtended()");
	return NULL;
}

PyDoc_STRVAR(bitfieldExtract_docstr,
	"bitfieldExtract(value: int, offset: int, bits: int) -> int\n"
	"	Extracts bits `[offset, offset + bits - 1]` from value, returning them in the least\n"
	"	significant bits of the result. For unsigned data types, the most significant bits of the\n"
	"	result will be set to zero. For signed data types, the most significant bits will be set to\n"
	"	the value of bit `offset + base - 1`. If `bits` is zero, the result will be zero. The result\n"
	"	will be undefined if `offset` or `bits` is negative, or if the sum of `offset` and `bits` is\n"
	"	greater than the number of bits used to store the operand.\n"
	"bitfieldExtract(value: vecN, offset: int, bits: int) -> vecN\n"
	"	Returns `bitfieldExtract(c, offset, bits)` for every component `c` of `value`."
);
static PyObject*
bitfieldExtract_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "bitfieldExtract", arg1, arg2, arg3);
	if (PyLong_Check(arg2) && PyLong_Check(arg3)) {
		int i = (int)PyLong_AS_LONG(arg2), i2 = (int)PyLong_AS_LONG(arg3);
		if (PyLong_Check(arg1)) {
			return PyLong_FromLong(glm::bitfieldExtract(PyLong_AS_LONG(arg1), i, i2));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I);
		if (PyGLM_Vec_PTI_Check0(1, int32, arg1)) {
			glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int32, arg1)) {
			glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int32, arg1)) {
			glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int32, arg1)) {
			glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint32, arg1)) {
			glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint32, arg1)) {
			glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint32, arg1)) {
			glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint32, arg1)) {
			glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int64, arg1)) {
			glm::vec<1, int64> o = PyGLM_Vec_PTI_Get0(1, int64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int64, arg1)) {
			glm::vec<2, int64> o = PyGLM_Vec_PTI_Get0(2, int64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int64, arg1)) {
			glm::vec<3, int64> o = PyGLM_Vec_PTI_Get0(3, int64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int64, arg1)) {
			glm::vec<4, int64> o = PyGLM_Vec_PTI_Get0(4, int64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint64, arg1)) {
			glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint64, arg1)) {
			glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint64, arg1)) {
			glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint64, arg1)) {
			glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int16, arg1)) {
			glm::vec<1, int16> o = PyGLM_Vec_PTI_Get0(1, int16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int16, arg1)) {
			glm::vec<2, int16> o = PyGLM_Vec_PTI_Get0(2, int16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int16, arg1)) {
			glm::vec<3, int16> o = PyGLM_Vec_PTI_Get0(3, int16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int16, arg1)) {
			glm::vec<4, int16> o = PyGLM_Vec_PTI_Get0(4, int16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint16, arg1)) {
			glm::vec<1, uint16> o = PyGLM_Vec_PTI_Get0(1, uint16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint16, arg1)) {
			glm::vec<2, uint16> o = PyGLM_Vec_PTI_Get0(2, uint16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint16, arg1)) {
			glm::vec<3, uint16> o = PyGLM_Vec_PTI_Get0(3, uint16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint16, arg1)) {
			glm::vec<4, uint16> o = PyGLM_Vec_PTI_Get0(4, uint16, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int8, arg1)) {
			glm::vec<1, int8> o = PyGLM_Vec_PTI_Get0(1, int8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int8, arg1)) {
			glm::vec<2, int8> o = PyGLM_Vec_PTI_Get0(2, int8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int8, arg1)) {
			glm::vec<3, int8> o = PyGLM_Vec_PTI_Get0(3, int8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int8, arg1)) {
			glm::vec<4, int8> o = PyGLM_Vec_PTI_Get0(4, int8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint8, arg1)) {
			glm::vec<1, uint8> o = PyGLM_Vec_PTI_Get0(1, uint8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint8, arg1)) {
			glm::vec<2, uint8> o = PyGLM_Vec_PTI_Get0(2, uint8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint8, arg1)) {
			glm::vec<3, uint8> o = PyGLM_Vec_PTI_Get0(3, uint8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint8, arg1)) {
			glm::vec<4, uint8> o = PyGLM_Vec_PTI_Get0(4, uint8, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldExtract()");
	return NULL;
}

PyDoc_STRVAR(bitfieldInsert_docstr,
	"bitfieldInsert(base: int, insert: int, offset: int, bits: int) -> int\n"
	"	Returns the insertion the bits least-significant bits of insert into base. The result will\n"
	"	have `bits[offset, offset + bits - 1]` taken from `bits[0, bits - 1]` of `insert`, and all other\n"
	"	bits taken directly from the corresponding bits of `base`. If `bits` is zero, the result will\n"
	"	simply be `base`. The result will be undefined if `offset` or `bits` is negative, or if the sum of\n"
	"	`offset` and `bits` is greater than the number of bits used to store the operand.\n"
	"bitfieldInsert(base: vecN, insert: vecN, offset: int, bits: int) -> vecN\n"
	"	Returns `bitfieldInsert(base[i], insert[i], offset, bits)` for every index `i`."
);
static PyObject*
bitfieldInsert_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "bitfieldInsert", arg1, arg2, arg3, arg4);
	if (PyLong_Check(arg3) && PyLong_Check(arg4)) {
		int i = (int)PyLong_AS_LONG(arg3), i2 = (int)PyLong_AS_LONG(arg4);
		if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
			return PyLong_FromLong(glm::bitfieldInsert(PyLong_AS_LONG(arg1), PyLong_AS_LONG(arg2), i, i2));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I32 | PyGLM_DT_I64);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I32 | PyGLM_DT_I64);
		if (PyGLM_Vec_PTI_Check0(1, int32, arg1) && PyGLM_Vec_PTI_Check1(1, int32, arg2)) {
			glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg1);
			glm::vec<1, int32> o2 = PyGLM_Vec_PTI_Get1(1, int32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int32, arg1) && PyGLM_Vec_PTI_Check1(2, int32, arg2)) {
			glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg1);
			glm::vec<2, int32> o2 = PyGLM_Vec_PTI_Get1(2, int32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int32, arg1) && PyGLM_Vec_PTI_Check1(3, int32, arg2)) {
			glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg1);
			glm::vec<3, int32> o2 = PyGLM_Vec_PTI_Get1(3, int32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int32, arg1) && PyGLM_Vec_PTI_Check1(4, int32, arg2)) {
			glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg1);
			glm::vec<4, int32> o2 = PyGLM_Vec_PTI_Get1(4, int32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint32, arg1) && PyGLM_Vec_PTI_Check1(1, uint32, arg2)) {
			glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg1);
			glm::vec<1, uint32> o2 = PyGLM_Vec_PTI_Get1(1, uint32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint32, arg1) && PyGLM_Vec_PTI_Check1(2, uint32, arg2)) {
			glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg1);
			glm::vec<2, uint32> o2 = PyGLM_Vec_PTI_Get1(2, uint32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {
			glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg1);
			glm::vec<3, uint32> o2 = PyGLM_Vec_PTI_Get1(3, uint32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint32, arg1) && PyGLM_Vec_PTI_Check1(4, uint32, arg2)) {
			glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg1);
			glm::vec<4, uint32> o2 = PyGLM_Vec_PTI_Get1(4, uint32, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {
			glm::vec<1, int64> o = PyGLM_Vec_PTI_Get0(1, int64, arg1);
			glm::vec<1, int64> o2 = PyGLM_Vec_PTI_Get1(1, int64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {
			glm::vec<2, int64> o = PyGLM_Vec_PTI_Get0(2, int64, arg1);
			glm::vec<2, int64> o2 = PyGLM_Vec_PTI_Get1(2, int64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {
			glm::vec<3, int64> o = PyGLM_Vec_PTI_Get0(3, int64, arg1);
			glm::vec<3, int64> o2 = PyGLM_Vec_PTI_Get1(3, int64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {
			glm::vec<4, int64> o = PyGLM_Vec_PTI_Get0(4, int64, arg1);
			glm::vec<4, int64> o2 = PyGLM_Vec_PTI_Get1(4, int64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint64, arg1) && PyGLM_Vec_PTI_Check1(1, uint64, arg2)) {
			glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg1);
			glm::vec<1, uint64> o2 = PyGLM_Vec_PTI_Get1(1, uint64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint64, arg1) && PyGLM_Vec_PTI_Check1(2, uint64, arg2)) {
			glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg1);
			glm::vec<2, uint64> o2 = PyGLM_Vec_PTI_Get1(2, uint64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint64, arg1) && PyGLM_Vec_PTI_Check1(3, uint64, arg2)) {
			glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg1);
			glm::vec<3, uint64> o2 = PyGLM_Vec_PTI_Get1(3, uint64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint64, arg1) && PyGLM_Vec_PTI_Check1(4, uint64, arg2)) {
			glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg1);
			glm::vec<4, uint64> o2 = PyGLM_Vec_PTI_Get1(4, uint64, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldInsert()");
	return NULL;
}

PyDoc_STRVAR(bitfieldReverse_docstr,
	"bitfieldReverse(value: int) -> int\n"
	"	Returns the reversal of the bits of `value`. The bit numbered `n` of the result will be taken\n"
	"	from `bit(bits - 1) - n` of `value`, where `bits` is the total number of bits used to represent\n"
	"	`value`.\n"
	"bitfieldReverse(value: vecN) -> vecN\n"
	"	Returns the reversal of the bits of `value`. The bit numbered `n` of the result will be taken\n"
	"	from `bit(bits - 1) - n` of `value`, where `bits` is the total number of bits used to represent\n"
	"	`value`."
);
static PyObject* bitfieldReverse_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLongLong(glm::bitfieldReverse(PyLong_AsLongLong(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I32 | PyGLM_DT_I64);
	if (PyGLM_Vec_PTI_Check0(1, int32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(1, int32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(2, int32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(3, int32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(4, int32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(1, uint32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(2, uint32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(3, uint32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(4, uint32, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(1, int64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(2, int64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(3, int64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(4, int64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(1, uint64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(2, uint64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(3, uint64, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(4, uint64, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitfieldReverse(): ", arg);
	return NULL;
}

PyDoc_STRVAR(bitCount_docstr,
	"bitCount(v: int) -> int\n"
	"	Returns the number of bits set to `1` in the binary representation of `value`.\n"
	"bitCount(v: ivecN) -> ivecN\n"
	"	For every component `c` of `v`:\n"
	"	Returns the number of bits set to `1` in the binary representation of `c`."
);
static PyObject*
bitCount_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::bitCount(PyLong_AS_LONG(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I);
	if (PyGLM_Vec_PTI_Check0(1, int32, arg)) {
		glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int32, arg)) {
		glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int32, arg)) {
		glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int32, arg)) {
		glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg)) {
		glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg)) {
		glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg)) {
		glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg)) {
		glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg)) {
		glm::vec<1, int64> o = PyGLM_Vec_PTI_Get0(1, int64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg)) {
		glm::vec<2, int64> o = PyGLM_Vec_PTI_Get0(2, int64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg)) {
		glm::vec<3, int64> o = PyGLM_Vec_PTI_Get0(3, int64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg)) {
		glm::vec<4, int64> o = PyGLM_Vec_PTI_Get0(4, int64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg)) {
		glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg)) {
		glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg)) {
		glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg)) {
		glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg)) {
		glm::vec<1, int16> o = PyGLM_Vec_PTI_Get0(1, int16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg)) {
		glm::vec<2, int16> o = PyGLM_Vec_PTI_Get0(2, int16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg)) {
		glm::vec<3, int16> o = PyGLM_Vec_PTI_Get0(3, int16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg)) {
		glm::vec<4, int16> o = PyGLM_Vec_PTI_Get0(4, int16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg)) {
		glm::vec<1, uint16> o = PyGLM_Vec_PTI_Get0(1, uint16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg)) {
		glm::vec<2, uint16> o = PyGLM_Vec_PTI_Get0(2, uint16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg)) {
		glm::vec<3, uint16> o = PyGLM_Vec_PTI_Get0(3, uint16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg)) {
		glm::vec<4, uint16> o = PyGLM_Vec_PTI_Get0(4, uint16, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int8, arg)) {
		glm::vec<1, int8> o = PyGLM_Vec_PTI_Get0(1, int8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg)) {
		glm::vec<2, int8> o = PyGLM_Vec_PTI_Get0(2, int8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg)) {
		glm::vec<3, int8> o = PyGLM_Vec_PTI_Get0(3, int8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg)) {
		glm::vec<4, int8> o = PyGLM_Vec_PTI_Get0(4, int8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg)) {
		glm::vec<1, uint8> o = PyGLM_Vec_PTI_Get0(1, uint8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg)) {
		glm::vec<2, uint8> o = PyGLM_Vec_PTI_Get0(2, uint8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg)) {
		glm::vec<3, uint8> o = PyGLM_Vec_PTI_Get0(3, uint8, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg)) {
		glm::vec<4, uint8> o = PyGLM_Vec_PTI_Get0(4, uint8, arg);
		return pack_vec(glm::bitCount(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitCount(): ", arg);
	return NULL;
}

PyDoc_STRVAR(findLSB_docstr,
	"findLSB(value: int) -> int\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned.\n"
	"findLSB(value: vecN) -> vecN\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned."
);
static PyObject*
findLSB_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::findLSB(PyLong_AS_LONG(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I);
	if (PyGLM_Vec_PTI_Check0(1, int32, arg)) {
		glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int32, arg)) {
		glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int32, arg)) {
		glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int32, arg)) {
		glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg)) {
		glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg)) {
		glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg)) {
		glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg)) {
		glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg)) {
		glm::vec<1, int64> o = PyGLM_Vec_PTI_Get0(1, int64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg)) {
		glm::vec<2, int64> o = PyGLM_Vec_PTI_Get0(2, int64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg)) {
		glm::vec<3, int64> o = PyGLM_Vec_PTI_Get0(3, int64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg)) {
		glm::vec<4, int64> o = PyGLM_Vec_PTI_Get0(4, int64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg)) {
		glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg)) {
		glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg)) {
		glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg)) {
		glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg)) {
		glm::vec<1, int16> o = PyGLM_Vec_PTI_Get0(1, int16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg)) {
		glm::vec<2, int16> o = PyGLM_Vec_PTI_Get0(2, int16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg)) {
		glm::vec<3, int16> o = PyGLM_Vec_PTI_Get0(3, int16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg)) {
		glm::vec<4, int16> o = PyGLM_Vec_PTI_Get0(4, int16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg)) {
		glm::vec<1, uint16> o = PyGLM_Vec_PTI_Get0(1, uint16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg)) {
		glm::vec<2, uint16> o = PyGLM_Vec_PTI_Get0(2, uint16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg)) {
		glm::vec<3, uint16> o = PyGLM_Vec_PTI_Get0(3, uint16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg)) {
		glm::vec<4, uint16> o = PyGLM_Vec_PTI_Get0(4, uint16, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int8, arg)) {
		glm::vec<1, int8> o = PyGLM_Vec_PTI_Get0(1, int8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg)) {
		glm::vec<2, int8> o = PyGLM_Vec_PTI_Get0(2, int8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg)) {
		glm::vec<3, int8> o = PyGLM_Vec_PTI_Get0(3, int8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg)) {
		glm::vec<4, int8> o = PyGLM_Vec_PTI_Get0(4, int8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg)) {
		glm::vec<1, uint8> o = PyGLM_Vec_PTI_Get0(1, uint8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg)) {
		glm::vec<2, uint8> o = PyGLM_Vec_PTI_Get0(2, uint8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg)) {
		glm::vec<3, uint8> o = PyGLM_Vec_PTI_Get0(3, uint8, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg)) {
		glm::vec<4, uint8> o = PyGLM_Vec_PTI_Get0(4, uint8, arg);
		return pack_vec(glm::findLSB(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for findLSB(): ", arg);
	return NULL;
}

PyDoc_STRVAR(findMSB_docstr,
	"findMSB(value: int) -> int\n"
	"	Returns the bit number of the most significant bit in the binary representation of `value`.\n"
	"	For positive integers, the result will be the bit number of the most significant bit set to\n"
	"	`1`. For negative integers, the result will be the bit number of the most significant bit set\n"
	"	to `0`. For a value of zero or negative one, `-1` will be returned.\n"
	"findMSB(value: vecN) -> vecN\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned."
);
static PyObject*
findMSB_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::findMSB(PyLong_AS_LONG(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I);
	if (PyGLM_Vec_PTI_Check0(1, int32, arg)) {
		glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int32, arg)) {
		glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int32, arg)) {
		glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int32, arg)) {
		glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg)) {
		glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg)) {
		glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg)) {
		glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg)) {
		glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int64, arg)) {
		glm::vec<1, int64> o = PyGLM_Vec_PTI_Get0(1, int64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int64, arg)) {
		glm::vec<2, int64> o = PyGLM_Vec_PTI_Get0(2, int64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int64, arg)) {
		glm::vec<3, int64> o = PyGLM_Vec_PTI_Get0(3, int64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int64, arg)) {
		glm::vec<4, int64> o = PyGLM_Vec_PTI_Get0(4, int64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint64, arg)) {
		glm::vec<1, uint64> o = PyGLM_Vec_PTI_Get0(1, uint64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint64, arg)) {
		glm::vec<2, uint64> o = PyGLM_Vec_PTI_Get0(2, uint64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint64, arg)) {
		glm::vec<3, uint64> o = PyGLM_Vec_PTI_Get0(3, uint64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint64, arg)) {
		glm::vec<4, uint64> o = PyGLM_Vec_PTI_Get0(4, uint64, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int16, arg)) {
		glm::vec<1, int16> o = PyGLM_Vec_PTI_Get0(1, int16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int16, arg)) {
		glm::vec<2, int16> o = PyGLM_Vec_PTI_Get0(2, int16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int16, arg)) {
		glm::vec<3, int16> o = PyGLM_Vec_PTI_Get0(3, int16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int16, arg)) {
		glm::vec<4, int16> o = PyGLM_Vec_PTI_Get0(4, int16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint16, arg)) {
		glm::vec<1, uint16> o = PyGLM_Vec_PTI_Get0(1, uint16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint16, arg)) {
		glm::vec<2, uint16> o = PyGLM_Vec_PTI_Get0(2, uint16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint16, arg)) {
		glm::vec<3, uint16> o = PyGLM_Vec_PTI_Get0(3, uint16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint16, arg)) {
		glm::vec<4, uint16> o = PyGLM_Vec_PTI_Get0(4, uint16, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, int8, arg)) {
		glm::vec<1, int8> o = PyGLM_Vec_PTI_Get0(1, int8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int8, arg)) {
		glm::vec<2, int8> o = PyGLM_Vec_PTI_Get0(2, int8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int8, arg)) {
		glm::vec<3, int8> o = PyGLM_Vec_PTI_Get0(3, int8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int8, arg)) {
		glm::vec<4, int8> o = PyGLM_Vec_PTI_Get0(4, int8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, uint8, arg)) {
		glm::vec<1, uint8> o = PyGLM_Vec_PTI_Get0(1, uint8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint8, arg)) {
		glm::vec<2, uint8> o = PyGLM_Vec_PTI_Get0(2, uint8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint8, arg)) {
		glm::vec<3, uint8> o = PyGLM_Vec_PTI_Get0(3, uint8, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint8, arg)) {
		glm::vec<4, uint8> o = PyGLM_Vec_PTI_Get0(4, uint8, arg);
		return pack_vec(glm::findMSB(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for findMSB(): ", arg);
	return NULL;
}

#define FUNC_INTEGER_METHODS \
{ "uaddCarry", (PyCFunction)uaddCarry_, METH_VARARGS, uaddCarry_docstr }, \
{ "usubBorrow", (PyCFunction)usubBorrow_, METH_VARARGS, usubBorrow_docstr }, \
{ "umulExtended", (PyCFunction)umulExtended_, METH_VARARGS, umulExtended_docstr }, \
{ "imulExtended", (PyCFunction)imulExtended_, METH_VARARGS, imulExtended_docstr }, \
{ "bitfieldExtract", (PyCFunction)bitfieldExtract_, METH_VARARGS, bitfieldExtract_docstr }, \
{ "bitfieldInsert", (PyCFunction)bitfieldInsert_, METH_VARARGS, bitfieldInsert_docstr }, \
{ "bitfieldReverse", (PyCFunction)bitfieldReverse_, METH_O, bitfieldReverse_docstr }, \
{ "bitCount", (PyCFunction)bitCount_, METH_O, bitCount_docstr }, \
{ "findLSB", (PyCFunction)findLSB_, METH_O, findLSB_docstr }, \
{ "findMSB", (PyCFunction)findMSB_, METH_O, findMSB_docstr }
