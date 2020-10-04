#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
sizeof_(PyObject*, PyObject* arg) {
	if (arg == ctypes_float) {
		return PyLong_FromLong(sizeof(float));
	}
	if (arg == ctypes_double) {
		return PyLong_FromLong(sizeof(double));
	}
	if (arg == ctypes_int64) {
		return PyLong_FromLong(sizeof(int64));
	}
	if (arg == ctypes_int32) {
		return PyLong_FromLong(sizeof(int32));
	}
	if (arg == ctypes_int16) {
		return PyLong_FromLong(sizeof(int16));
	}
	if (arg == ctypes_int8) {
		return PyLong_FromLong(sizeof(int8));
	}
	if (arg == ctypes_uint64) {
		return PyLong_FromLong(sizeof(uint64));
	}
	if (arg == ctypes_uint32) {
		return PyLong_FromLong(sizeof(uint32));
	}
	if (arg == ctypes_uint16) {
		return PyLong_FromLong(sizeof(uint16));
	}
	if (arg == ctypes_uint8) {
		return PyLong_FromLong(sizeof(uint8));
	}
	if (arg == ctypes_bool) {
		return PyLong_FromLong(sizeof(bool));
	}
	if (PyGLM_Vec_Check(1, float, arg) || arg == (PyObject*)&hfvec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, float>));
	}
	if (PyGLM_Vec_Check(1, double, arg) || arg == (PyObject*)&hdvec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, double>));
	}
	if (PyGLM_Vec_Check(1, int, arg) || arg == (PyObject*)&hivec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, int>));
	}
	if (PyGLM_Vec_Check(1, glm::uint, arg) || arg == (PyObject*)&huvec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::uint>));
	}
	if (PyGLM_Vec_Check(1, glm::i64, arg) || arg == (PyObject*)&hi64vec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::i64>));
	}
	if (PyGLM_Vec_Check(1, glm::u64, arg) || arg == (PyObject*)&hu64vec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::u64>));
	}
	if (PyGLM_Vec_Check(1, glm::i16, arg) || arg == (PyObject*)&hi16vec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::i16>));
	}
	if (PyGLM_Vec_Check(1, glm::u16, arg) || arg == (PyObject*)&hu16vec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::u16>));
	}
	if (PyGLM_Vec_Check(1, glm::i8, arg) || arg == (PyObject*)&hi8vec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::i8>));
	}
	if (PyGLM_Vec_Check(1, glm::u8, arg) || arg == (PyObject*)&hu8vec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, glm::u8>));
	}
	if (PyGLM_Vec_Check(1, bool, arg) || arg == (PyObject*)&hbvec1Type) {
		return PyLong_FromLong(sizeof(glm::vec<1, bool>));
	}
	if (PyGLM_Vec_Check(2, float, arg) || arg == (PyObject*)&hfvec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, float>));
	}
	if (PyGLM_Vec_Check(2, double, arg) || arg == (PyObject*)&hdvec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, double>));
	}
	if (PyGLM_Vec_Check(2, int, arg) || arg == (PyObject*)&hivec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, int>));
	}
	if (PyGLM_Vec_Check(2, glm::uint, arg) || arg == (PyObject*)&huvec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::uint>));
	}
	if (PyGLM_Vec_Check(2, glm::i64, arg) || arg == (PyObject*)&hi64vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::i64>));
	}
	if (PyGLM_Vec_Check(2, glm::u64, arg) || arg == (PyObject*)&hu64vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::u64>));
	}
	if (PyGLM_Vec_Check(2, glm::i16, arg) || arg == (PyObject*)&hi16vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::i16>));
	}
	if (PyGLM_Vec_Check(2, glm::u16, arg) || arg == (PyObject*)&hu16vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::u16>));
	}
	if (PyGLM_Vec_Check(2, glm::i8, arg) || arg == (PyObject*)&hi8vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::i8>));
	}
	if (PyGLM_Vec_Check(2, glm::u8, arg) || arg == (PyObject*)&hu8vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, glm::u8>));
	}
	if (PyGLM_Vec_Check(2, bool, arg) || arg == (PyObject*)&hbvec2Type) {
		return PyLong_FromLong(sizeof(glm::vec<2, bool>));
	}
	if (PyGLM_Vec_Check(3, float, arg) || arg == (PyObject*)&hfvec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, float>));
	}
	if (PyGLM_Vec_Check(3, double, arg) || arg == (PyObject*)&hdvec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, double>));
	}
	if (PyGLM_Vec_Check(3, int, arg) || arg == (PyObject*)&hivec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, int>));
	}
	if (PyGLM_Vec_Check(3, glm::uint, arg) || arg == (PyObject*)&huvec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::uint>));
	}
	if (PyGLM_Vec_Check(3, glm::i64, arg) || arg == (PyObject*)&hi64vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::i64>));
	}
	if (PyGLM_Vec_Check(3, glm::u64, arg) || arg == (PyObject*)&hu64vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::u64>));
	}
	if (PyGLM_Vec_Check(3, glm::i16, arg) || arg == (PyObject*)&hi16vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::i16>));
	}
	if (PyGLM_Vec_Check(3, glm::u16, arg) || arg == (PyObject*)&hu16vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::u16>));
	}
	if (PyGLM_Vec_Check(3, glm::i8, arg) || arg == (PyObject*)&hi8vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::i8>));
	}
	if (PyGLM_Vec_Check(3, glm::u8, arg) || arg == (PyObject*)&hu8vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, glm::u8>));
	}
	if (PyGLM_Vec_Check(3, bool, arg) || arg == (PyObject*)&hbvec3Type) {
		return PyLong_FromLong(sizeof(glm::vec<3, bool>));
	}
	if (PyGLM_Vec_Check(4, float, arg) || arg == (PyObject*)&hfvec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, float>));
	}
	if (PyGLM_Vec_Check(4, double, arg) || arg == (PyObject*)&hdvec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, double>));
	}
	if (PyGLM_Vec_Check(4, int, arg) || arg == (PyObject*)&hivec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, int>));
	}
	if (PyGLM_Vec_Check(4, glm::uint, arg) || arg == (PyObject*)&huvec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::uint>));
	}
	if (PyGLM_Vec_Check(4, glm::i64, arg) || arg == (PyObject*)&hi64vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::i64>));
	}
	if (PyGLM_Vec_Check(4, glm::u64, arg) || arg == (PyObject*)&hu64vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::u64>));
	}
	if (PyGLM_Vec_Check(4, glm::i16, arg) || arg == (PyObject*)&hi16vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::i16>));
	}
	if (PyGLM_Vec_Check(4, glm::u16, arg) || arg == (PyObject*)&hu16vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::u16>));
	}
	if (PyGLM_Vec_Check(4, glm::i8, arg) || arg == (PyObject*)&hi8vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::i8>));
	}
	if (PyGLM_Vec_Check(4, glm::u8, arg) || arg == (PyObject*)&hu8vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, glm::u8>));
	}
	if (PyGLM_Vec_Check(4, bool, arg) || arg == (PyObject*)&hbvec4Type) {
		return PyLong_FromLong(sizeof(glm::vec<4, bool>));
	}
	if (PyGLM_Qua_Check(float, arg) || arg == (PyObject*)&hfquaType) {
		return PyLong_FromLong(sizeof(glm::qua<float>));
	}
	if (PyGLM_Qua_Check(double, arg) || arg == (PyObject*)&hdquaType) {
		return PyLong_FromLong(sizeof(glm::qua<double>));
	}
	if (PyGLM_Mat_Check(2, 2, float, arg) || arg == (PyObject*)&hfmat2x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 2, float>));
	}
	if (PyGLM_Mat_Check(2, 2, double, arg) || arg == (PyObject*)&hdmat2x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 2, double>));
	}
	if (PyGLM_Mat_Check(2, 2, int, arg) || arg == (PyObject*)&himat2x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 2, int>));
	}
	if (PyGLM_Mat_Check(2, 2, glm::uint, arg) || arg == (PyObject*)&humat2x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 2, glm::uint>));
	}
	if (PyGLM_Mat_Check(2, 3, float, arg) || arg == (PyObject*)&hfmat2x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 3, float>));
	}
	if (PyGLM_Mat_Check(2, 3, double, arg) || arg == (PyObject*)&hdmat2x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 3, double>));
	}
	if (PyGLM_Mat_Check(2, 3, int, arg) || arg == (PyObject*)&himat2x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 3, int>));
	}
	if (PyGLM_Mat_Check(2, 3, glm::uint, arg) || arg == (PyObject*)&humat2x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 3, glm::uint>));
	}
	if (PyGLM_Mat_Check(2, 4, float, arg) || arg == (PyObject*)&hfmat2x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 4, float>));
	}
	if (PyGLM_Mat_Check(2, 4, double, arg) || arg == (PyObject*)&hdmat2x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 4, double>));
	}
	if (PyGLM_Mat_Check(2, 4, int, arg) || arg == (PyObject*)&himat2x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 4, int>));
	}
	if (PyGLM_Mat_Check(2, 4, glm::uint, arg) || arg == (PyObject*)&humat2x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<2, 4, glm::uint>));
	}
	if (PyGLM_Mat_Check(3, 2, float, arg) || arg == (PyObject*)&hfmat3x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 2, float>));
	}
	if (PyGLM_Mat_Check(3, 2, double, arg) || arg == (PyObject*)&hdmat3x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 2, double>));
	}
	if (PyGLM_Mat_Check(3, 2, int, arg) || arg == (PyObject*)&himat3x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 2, int>));
	}
	if (PyGLM_Mat_Check(3, 2, glm::uint, arg) || arg == (PyObject*)&humat3x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 2, glm::uint>));
	}
	if (PyGLM_Mat_Check(3, 3, float, arg) || arg == (PyObject*)&hfmat3x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 3, float>));
	}
	if (PyGLM_Mat_Check(3, 3, double, arg) || arg == (PyObject*)&hdmat3x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 3, double>));
	}
	if (PyGLM_Mat_Check(3, 3, int, arg) || arg == (PyObject*)&himat3x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 3, int>));
	}
	if (PyGLM_Mat_Check(3, 3, glm::uint, arg) || arg == (PyObject*)&humat3x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 3, glm::uint>));
	}
	if (PyGLM_Mat_Check(3, 4, float, arg) || arg == (PyObject*)&hfmat3x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 4, float>));
	}
	if (PyGLM_Mat_Check(3, 4, double, arg) || arg == (PyObject*)&hdmat3x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 4, double>));
	}
	if (PyGLM_Mat_Check(3, 4, int, arg) || arg == (PyObject*)&himat3x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 4, int>));
	}
	if (PyGLM_Mat_Check(3, 4, glm::uint, arg) || arg == (PyObject*)&humat3x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<3, 4, glm::uint>));
	}
	if (PyGLM_Mat_Check(4, 2, float, arg) || arg == (PyObject*)&hfmat4x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 2, float>));
	}
	if (PyGLM_Mat_Check(4, 2, double, arg) || arg == (PyObject*)&hdmat4x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 2, double>));
	}
	if (PyGLM_Mat_Check(4, 2, int, arg) || arg == (PyObject*)&himat4x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 2, int>));
	}
	if (PyGLM_Mat_Check(4, 2, glm::uint, arg) || arg == (PyObject*)&humat4x2Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 2, glm::uint>));
	}
	if (PyGLM_Mat_Check(4, 3, float, arg) || arg == (PyObject*)&hfmat4x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 3, float>));
	}
	if (PyGLM_Mat_Check(4, 3, double, arg) || arg == (PyObject*)&hdmat4x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 3, double>));
	}
	if (PyGLM_Mat_Check(4, 3, int, arg) || arg == (PyObject*)&himat4x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 3, int>));
	}
	if (PyGLM_Mat_Check(4, 3, glm::uint, arg) || arg == (PyObject*)&humat4x3Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 3, glm::uint>));
	}
	if (PyGLM_Mat_Check(4, 4, float, arg) || arg == (PyObject*)&hfmat4x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 4, float>));
	}
	if (PyGLM_Mat_Check(4, 4, double, arg) || arg == (PyObject*)&hdmat4x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 4, double>));
	}
	if (PyGLM_Mat_Check(4, 4, int, arg) || arg == (PyObject*)&himat4x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 4, int>));
	}
	if (PyGLM_Mat_Check(4, 4, glm::uint, arg) || arg == (PyObject*)&humat4x4Type) {
		return PyLong_FromLong(sizeof(glm::mat<4, 4, glm::uint>));
	}
	if (PyObject_TypeCheck(arg, &glmArrayType)) {
		return PyLong_FromSsize_t(((glmArray*)arg)->nBytes);
	}
	PyGLM_TYPEERROR_O("sizeof() requires the argument to be a glm type, not ", arg);
	return NULL;
}

static PyObject*
value_ptr_(PyObject*, PyObject* arg) {
	if (Py_TYPE(arg) == &hfvec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdvec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hivec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &huvec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi64vec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::i64>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu64vec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::u64>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi16vec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::i16>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu16vec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::u16>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi8vec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::i8>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu8vec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, glm::u8>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hbvec2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<2, bool>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfvec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdvec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hivec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &huvec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi64vec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::i64>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu64vec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::u64>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi16vec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::i16>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu16vec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::u16>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi8vec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::i8>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu8vec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, glm::u8>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hbvec3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<3, bool>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfvec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdvec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hivec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &huvec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi64vec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::i64>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu64vec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::u64>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi16vec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::i16>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu16vec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::u16>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hi8vec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::i8>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hu8vec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, glm::u8>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hbvec4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((vec<4, bool>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfquaType) {
		return PyGLM_ToCtypesP(glm::value_ptr(((qua<float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdquaType) {
		return PyGLM_ToCtypesP(glm::value_ptr(((qua<double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat2x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 2, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat2x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 2, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat2x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 2, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat2x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 2, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat2x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 3, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat2x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 3, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat2x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 3, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat2x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 3, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat2x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 4, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat2x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 4, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat2x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 4, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat2x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<2, 4, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat3x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 2, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat3x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 2, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat3x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 2, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat3x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 2, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat3x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 3, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat3x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 3, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat3x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 3, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat3x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 3, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat3x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 4, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat3x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 4, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat3x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 4, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat3x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<3, 4, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat4x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 2, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat4x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 2, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat4x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 2, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat4x2Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 2, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat4x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 3, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat4x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 3, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat4x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 3, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat4x3Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 3, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hfmat4x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 4, float>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &hdmat4x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 4, double>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &himat4x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 4, int>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &humat4x4Type) {
		return PyGLM_ToCtypesP(glm::value_ptr(((mat<4, 4, glm::uint>*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &glmArrayType) {
		return PyGLM_ToCtypesP(((glmArray*)arg)->data);
	}
	PyGLM_TYPEERROR_O("value_ptr() requires the argument to be a glm type, not ", arg);
	return NULL;
}

static PyObject*
make_vec2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_vec2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_vec2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_vec2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_vec2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int64_p)) {
		return pack(glm::make_vec2((glm::i64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint64_p)) {
		return pack(glm::make_vec2((glm::u64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int16_p)) {
		return pack(glm::make_vec2((glm::i16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint16_p)) {
		return pack(glm::make_vec2((glm::u16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int8_p)) {
		return pack(glm::make_vec2((glm::i8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint8_p)) {
		return pack(glm::make_vec2((glm::u8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_bool_p)) {
		return pack(glm::make_vec2((bool*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_vec2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_vec3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_vec3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_vec3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_vec3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_vec3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int64_p)) {
		return pack(glm::make_vec3((glm::i64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint64_p)) {
		return pack(glm::make_vec3((glm::u64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int16_p)) {
		return pack(glm::make_vec3((glm::i16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint16_p)) {
		return pack(glm::make_vec3((glm::u16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int8_p)) {
		return pack(glm::make_vec3((glm::i8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint8_p)) {
		return pack(glm::make_vec3((glm::u8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_bool_p)) {
		return pack(glm::make_vec3((bool*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_vec3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_vec4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_vec4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_vec4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_vec4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_vec4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int64_p)) {
		return pack(glm::make_vec4((glm::i64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint64_p)) {
		return pack(glm::make_vec4((glm::u64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int16_p)) {
		return pack(glm::make_vec4((glm::i16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint16_p)) {
		return pack(glm::make_vec4((glm::u16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int8_p)) {
		return pack(glm::make_vec4((glm::i8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint8_p)) {
		return pack(glm::make_vec4((glm::u8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_bool_p)) {
		return pack(glm::make_vec4((bool*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_vec4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_mat2x2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat2x2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat2x2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat2x2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat2x2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat2x2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat2x3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat2x3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat2x3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat2x3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat2x3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat2x3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat2x4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat2x4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat2x4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat2x4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat2x4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat2x4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat3x2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat3x2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat3x2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat3x2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat3x2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat3x2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat3x3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat3x3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat3x3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat3x3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat3x3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat3x3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat3x4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat3x4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat3x4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat3x4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat3x4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat3x4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat4x2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat4x2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat4x2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat4x2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat4x2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat4x2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat4x3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat4x3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat4x3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat4x3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat4x3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat4x3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat4x4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat4x4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat4x4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat4x4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat4x4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat4x4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_quat_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_quat((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_quat((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_quat() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

PyDoc_STRVAR(value_ptr_docstr,
	"value_ptr(x) -> ctypes pointer\n"
	"	Return the constant address to the data of the input parameter."
);
PyDoc_STRVAR(sizeof_docstr,
	"sizeof(x: type) -> int\n"
	"	Return the data size of x in bytes.\n"
	"	E.g. sizeof(vec4) == sizeof(float32) * 4 = 4 * 4 = 16."
);
PyDoc_STRVAR(make_vec2_docstr,
	"make_vec2(x: ctypes pointer) -> vec2\n"
	"	Build a vector from a pointer."
);
PyDoc_STRVAR(make_vec3_docstr,
	"make_vec3(x: ctypes pointer) -> vec3\n"
	"	Build a vector from a pointer."
);
PyDoc_STRVAR(make_vec4_docstr,
	"make_vec4(x: ctypes pointer) -> vec4\n"
	"	Build a vector from a pointer."
);
PyDoc_STRVAR(make_mat2_docstr,
	"make_mat2(x: ctypes pointer) -> mat2\n"
	"	See make_mat2x2()."
);
PyDoc_STRVAR(make_mat3_docstr,
	"make_mat3(x: ctypes pointer) -> mat3\n"
	"	See make_mat3x3()."
);
PyDoc_STRVAR(make_mat4_docstr,
	"make_mat4(x: ctypes pointer) -> mat4\n"
	"	See make_mat4x4()."
);
PyDoc_STRVAR(make_mat2x2_docstr,
	"make_mat2x2(x: ctypes pointer) -> mat2\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat2x3_docstr,
	"make_mat2x3(x: ctypes pointer) -> mat2x3\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat2x4_docstr,
	"make_mat2x4(x: ctypes pointer) -> mat2x4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat3x2_docstr,
	"make_mat3x2(x: ctypes pointer) -> mat3x2\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat3x3_docstr,
	"make_mat3x3(x: ctypes pointer) -> mat3\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat3x4_docstr,
	"make_mat3x4(x: ctypes pointer) -> mat3x4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat4x2_docstr,
	"make_mat4x2(x: ctypes pointer) -> mat4x2\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat4x3_docstr,
	"make_mat4x3(x: ctypes pointer) -> mat4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat4x4_docstr,
	"make_mat4x4(x: ctypes pointer) -> mat4x4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_quat_docstr,
	"make_quat(x: ctypes pointer) -> quat\n"
	"	Build a quaternion from a pointer."
);

#define TYPE_PTR_METHODS \
{ "value_ptr", (PyCFunction)value_ptr_, METH_O, value_ptr_docstr }, \
{ "sizeof", (PyCFunction)sizeof_, METH_O, sizeof_docstr }, \
{ "make_vec2", (PyCFunction)make_vec2_, METH_O, make_vec2_docstr }, \
{ "make_vec3", (PyCFunction)make_vec3_, METH_O, make_vec3_docstr }, \
{ "make_vec4", (PyCFunction)make_vec4_, METH_O, make_vec4_docstr }, \
{ "make_mat2", (PyCFunction)make_mat2x2_, METH_O, make_mat2_docstr }, \
{ "make_mat2x2", (PyCFunction)make_mat2x2_, METH_O, make_mat2x2_docstr }, \
{ "make_mat2x3", (PyCFunction)make_mat2x3_, METH_O, make_mat2x3_docstr }, \
{ "make_mat2x4", (PyCFunction)make_mat2x4_, METH_O, make_mat2x4_docstr }, \
{ "make_mat3x2", (PyCFunction)make_mat3x2_, METH_O, make_mat3x2_docstr }, \
{ "make_mat3", (PyCFunction)make_mat3x3_, METH_O, make_mat3_docstr }, \
{ "make_mat3x3", (PyCFunction)make_mat3x3_, METH_O, make_mat3x3_docstr }, \
{ "make_mat3x4", (PyCFunction)make_mat3x4_, METH_O, make_mat3x4_docstr }, \
{ "make_mat4x2", (PyCFunction)make_mat4x2_, METH_O, make_mat4x2_docstr }, \
{ "make_mat4x3", (PyCFunction)make_mat4x3_, METH_O, make_mat4x3_docstr }, \
{ "make_mat4", (PyCFunction)make_mat4x4_, METH_O, make_mat4_docstr }, \
{ "make_mat4x4", (PyCFunction)make_mat4x4_, METH_O, make_mat4x4_docstr }, \
{ "make_quat", (PyCFunction)make_quat_, METH_O, make_quat_docstr }
