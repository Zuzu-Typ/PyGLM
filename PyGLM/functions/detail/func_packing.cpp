
#include "func_packing.h"

#include "../vec_imports.h"

#include "../../internal_functions/type_checkers.h"
#include "../../internal_functions/error_functions.h"
#include "../../internal_functions/number_functions.h"
#include "../../internal_functions/pack_vec.h"
#include "../../internal_functions/pack_number.h"

#include <glm/packing.hpp>

PyObject*
packDouble2x32_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg)) {
		glm::uvec2 o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg);
		return PyFloat_FromDouble(glm::packDouble2x32(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packDouble2x32(): ", arg);
	return NULL;
}

PyObject*
packUnorm2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return PyLong_FromLong((long)glm::packUnorm2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm2x16(): ", arg);
	return NULL;
}

PyObject*
packSnorm2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return PyLong_FromLong((long)glm::packSnorm2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm2x16(): ", arg);
	return NULL;
}

PyObject*
packUnorm4x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg);
		return PyLong_FromLong((long)glm::packUnorm4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm4x8(): ", arg);
	return NULL;
}

PyObject*
packSnorm4x8_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg);
		return PyLong_FromLong((long)glm::packSnorm4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm4x8(): ", arg);
	return NULL;
}

PyObject*
packHalf2x16_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return PyLong_FromUnsignedLong((unsigned long)glm::packHalf2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packHalf2x16(): ", arg);
	return NULL;
}

PyObject*
unpackDouble2x32_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackDouble2x32(PyGLM_Number_FromPyObject<double>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackDouble2x32(): ", arg);
	return NULL;
}

PyObject*
unpackUnorm2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm2x16(): ", arg);
	return NULL;
}

PyObject*
unpackSnorm2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm2x16(): ", arg);
	return NULL;
}

PyObject*
unpackUnorm4x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackUnorm4x8(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm4x8(): ", arg);
	return NULL;
}

PyObject*
unpackSnorm4x8_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackSnorm4x8(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm4x8(): ", arg);
	return NULL;
}

PyObject*
unpackHalf2x16_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack(glm::unpackHalf2x16(PyGLM_Number_FromPyObject<glm::u32>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackHalf2x16(): ", arg);
	return NULL;
}
