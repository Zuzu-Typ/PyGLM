#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

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

static PyObject*
bitfieldExtract_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "bitfieldExtract", arg1, arg2, arg3);
	if (PyLong_Check(arg2) && PyLong_Check(arg3)) {
		int i = (int)PyLong_AS_LONG(arg2), i2 = (int)PyLong_AS_LONG(arg3);
		if (PyLong_Check(arg1)) {
			return PyLong_FromLong(glm::bitfieldExtract(PyLong_AS_LONG(arg1), i, i2));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
		if (PyGLM_Vec_PTI_Check0(1, int, arg1)) {
			glm::ivec1 o = PyGLM_Vec_PTI_Get0(1, int, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1)) {
			glm::ivec2 o = PyGLM_Vec_PTI_Get0(2, int, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1)) {
			glm::ivec3 o = PyGLM_Vec_PTI_Get0(3, int, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1)) {
			glm::ivec4 o = PyGLM_Vec_PTI_Get0(4, int, arg1);
			return pack_vec(glm::bitfieldExtract(o, i, i2));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldExtract()");
	return NULL;
}

static PyObject*
bitfieldInsert_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "bitfieldInsert", arg1, arg2, arg3, arg4);
	if (PyLong_Check(arg3) && PyLong_Check(arg4)) {
		int i = (int)PyLong_AS_LONG(arg3), i2 = (int)PyLong_AS_LONG(arg4);
		if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
			return PyLong_FromLong(glm::bitfieldInsert(PyLong_AS_LONG(arg1), PyLong_AS_LONG(arg2), i, i2));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			glm::ivec1 o = PyGLM_Vec_PTI_Get0(1, int, arg1);
			glm::ivec1 o2 = PyGLM_Vec_PTI_Get1(1, int, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			glm::ivec2 o = PyGLM_Vec_PTI_Get0(2, int, arg1);
			glm::ivec2 o2 = PyGLM_Vec_PTI_Get1(2, int, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			glm::ivec3 o = PyGLM_Vec_PTI_Get0(3, int, arg1);
			glm::ivec3 o2 = PyGLM_Vec_PTI_Get1(3, int, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			glm::ivec4 o = PyGLM_Vec_PTI_Get0(4, int, arg1);
			glm::ivec4 o2 = PyGLM_Vec_PTI_Get1(4, int, arg2);
			return pack_vec(glm::bitfieldInsert(o, o2, i, i2));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldInsert()");
	return NULL;
}

static PyObject* bitfieldReverse_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::bitfieldReverse(PyLong_AsUnsignedLong(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(1, glm::uint, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(2, glm::uint, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(3, glm::uint, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg)) {
		return pack_vec(glm::bitfieldReverse(PyGLM_Vec_PTI_Get0(4, glm::uint, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitfieldReverse(): ", arg);
	return NULL;
}

static PyObject*
bitCount_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::bitCount(PyLong_AS_LONG(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(1, int, arg)) {
		glm::ivec1 o = PyGLM_Vec_PTI_Get0(1, int, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg)) {
		glm::ivec2 o = PyGLM_Vec_PTI_Get0(2, int, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg)) {
		glm::ivec3 o = PyGLM_Vec_PTI_Get0(3, int, arg);
		return pack_vec(glm::bitCount(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg)) {
		glm::ivec4 o = PyGLM_Vec_PTI_Get0(4, int, arg);
		return pack_vec(glm::bitCount(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitCount(): ", arg);
	return NULL;
}

static PyObject*
findLSB_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::findLSB(PyLong_AS_LONG(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(1, int, arg)) {
		glm::ivec1 o = PyGLM_Vec_PTI_Get0(1, int, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg)) {
		glm::ivec2 o = PyGLM_Vec_PTI_Get0(2, int, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg)) {
		glm::ivec3 o = PyGLM_Vec_PTI_Get0(3, int, arg);
		return pack_vec(glm::findLSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg)) {
		glm::ivec4 o = PyGLM_Vec_PTI_Get0(4, int, arg);
		return pack_vec(glm::findLSB(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for findLSB(): ", arg);
	return NULL;
}

static PyObject*
findMSB_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_FromLong(glm::findMSB(PyLong_AS_LONG(arg)));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(1, int, arg)) {
		glm::ivec1 o = PyGLM_Vec_PTI_Get0(1, int, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg)) {
		glm::ivec2 o = PyGLM_Vec_PTI_Get0(2, int, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg)) {
		glm::ivec3 o = PyGLM_Vec_PTI_Get0(3, int, arg);
		return pack_vec(glm::findMSB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg)) {
		glm::ivec4 o = PyGLM_Vec_PTI_Get0(4, int, arg);
		return pack_vec(glm::findMSB(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for findMSB(): ", arg);
	return NULL;
}


#define FUNC_INTEGER_METHODS { "uaddCarry", (PyCFunction)uaddCarry_, METH_VARARGS, "uaddCarry(x, y, Carry) -> vecn\nAdds 32-bit unsigned integer x and y, returning the sum\nmodulo pow(2, 32). The value carry is set to 0 if the sum was\nless than pow(2, 32), or to 1 otherwise." }, \
{ "usubBorrow", (PyCFunction)usubBorrow_, METH_VARARGS, "usubBorrow(x, y, Borrow) -> vecn\nSubtracts the 32-bit unsigned integer y from x, returning\nthe difference if non-negative, or pow(2, 32) plus the difference\notherwise. The value borrow is set to 0 if x >= y, or to 1 otherwise." }, \
{ "umulExtended", (PyCFunction)umulExtended_, METH_VARARGS, "umulExtended(x, y, msb, lsb) -> None\nMultiplies 32-bit integers x and y, producing a 64-bit\nresult. The 32 least-significant bits are returned in lsb.\nThe 32 most-significant bits are returned in msb." }, \
{ "imulExtended", (PyCFunction)imulExtended_, METH_VARARGS, "imulExtended(x, y, msb, lsb) -> None\nMultiplies 32-bit integers x and y, producing a 64-bit\nresult. The 32 least-significant bits are returned in lsb.\nThe 32 most-significant bits are returned in msb." }, \
{ "bitfieldExtract", (PyCFunction)bitfieldExtract_, METH_VARARGS, "bitfieldExtract(Value, Offset, Bits) -> vecn or int\nExtracts bits [offset, offset + bits - 1] from value,\nreturning them in the least significant bits of the result." }, \
{ "bitfieldInsert", (PyCFunction)bitfieldInsert_, METH_VARARGS, "bitfieldInsert(Base, Insert, Offset, Bits) -> vecn or int\nReturns the insertion the bits least-significant bits of insert into base." }, \
{ "bitfieldReverse", (PyCFunction)bitfieldReverse_, METH_O, "bitfieldReverse(v) -> vecn or float\nReturns the reversal of the bits of value." }, \
{ "bitCount", (PyCFunction)bitCount_, METH_O, "bitCount(v) -> vecn or int\nReturns the number of bits set to 1 in the binary representation of value." }, \
{ "findLSB", (PyCFunction)findLSB_, METH_O, "findLSB(x) -> vecn or int\nReturns the bit number of the least significant bit set to\n1 in the binary representation of value.\nIf value is zero, -1 will be returned." }, \
{ "findMSB", (PyCFunction)findMSB_, METH_O, "findMSB(x) -> vecn or int\nReturns the bit number of the most significant bit in the binary representation of value." }
