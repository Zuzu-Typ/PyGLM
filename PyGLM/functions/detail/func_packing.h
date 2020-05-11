#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
packDouble2x32_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg)) {
		glm::uvec2 o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg);
		return PyFloat_FromDouble(glm::packDouble2x32(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packDouble2x32(): ", arg);
	return NULL;
}

static PyObject*
packUnorm2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return PyLong_FromLong((long)glm::packUnorm2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
packSnorm2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return PyLong_FromLong((long)glm::packSnorm2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
packUnorm4x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg);
		return PyLong_FromLong((long)glm::packUnorm4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
packSnorm4x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg);
		return PyLong_FromLong((long)glm::packSnorm4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
packHalf2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return PyLong_FromUnsignedLong((unsigned long)glm::packHalf2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packHalf2x16(): ", arg);
	return NULL;
}



static PyObject*
unpackDouble2x32_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackDouble2x32(PyGLM_Number_FromPyObject<double>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackDouble2x32(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm4x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm4x8(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm4x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm4x8(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
unpackHalf2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackHalf2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackHalf2x16(): ", arg);
	return NULL;
}

#define FUNC_PACKING_METHODS { "packDouble2x32", (PyCFunction)packDouble2x32_, METH_O, "packDouble2x32(v) -> float\nReturns a double-qualifier value obtained by packing the components of v into a 64-bit value." }, \
{ "packUnorm2x16", (PyCFunction)packUnorm2x16_, METH_O, "packUnorm2x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "packSnorm2x16", (PyCFunction)packSnorm2x16_, METH_O, "packSnorm2x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "packSnorm4x8", (PyCFunction)packSnorm4x8_, METH_O, "packSnorm4x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "packUnorm4x8", (PyCFunction)packUnorm4x8_, METH_O, "packUnorm4x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." }, \
{ "packHalf2x16", (PyCFunction)packHalf2x16_, METH_O, "packHalf2x16(v) -> int\nReturns an unsigned integer obtained by converting the components of a two - component floating - point vector\nto the 16-bit floating-point representation found in the OpenGL Specification,\nand then packing these two 16- bit integers into a 32-bit unsigned integer." }, \
{ "unpackDouble2x32", (PyCFunction)unpackDouble2x32_, METH_O, "unpackDouble2x32(v) -> float\nReturns a two-component unsigned integer vector representation of v." }, \
{ "unpackUnorm2x16", (PyCFunction)unpackUnorm2x16_, METH_O, "unpackUnorm2x16(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." }, \
{ "unpackSnorm2x16", (PyCFunction)unpackSnorm2x16_, METH_O, "unpackSnorm2x16(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." }, \
{ "unpackSnorm4x8", (PyCFunction)unpackSnorm4x8_, METH_O, "unpackSnorm4x8(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." }, \
{ "unpackUnorm4x8", (PyCFunction)unpackUnorm4x8_, METH_O, "unpackUnorm4x8(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." }, \
{ "unpackHalf2x16", (PyCFunction)unpackHalf2x16_, METH_O, "unpackHalf2x16(v) -> int\nReturns a two - component floating - point vector with components obtained by unpacking a 32 - bit unsigned integer into a pair of 16 - bit values,\ninterpreting those values as 16-bit floating-point numbers according to the OpenGL Specification,\nand converting them to 32-bit floating-point values." }
