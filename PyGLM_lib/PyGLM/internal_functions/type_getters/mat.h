#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int C, int R, typename T>
static constexpr PyTypeObject* PyGLM_MAT_TYPE() {
	return (std::is_same<mat<C, R, T>, mat<2, 2, float> >::value) ? (PyTypeObject*)&hfmat2x2Type :
		(std::is_same<mat<C, R, T>, mat<2, 3, float> >::value) ? (PyTypeObject*)&hfmat2x3Type :
		(std::is_same<mat<C, R, T>, mat<2, 4, float> >::value) ? (PyTypeObject*)&hfmat2x4Type :
		(std::is_same<mat<C, R, T>, mat<3, 2, float> >::value) ? (PyTypeObject*)&hfmat3x2Type :
		(std::is_same<mat<C, R, T>, mat<3, 3, float> >::value) ? (PyTypeObject*)&hfmat3x3Type :
		(std::is_same<mat<C, R, T>, mat<3, 4, float> >::value) ? (PyTypeObject*)&hfmat3x4Type :
		(std::is_same<mat<C, R, T>, mat<4, 2, float> >::value) ? (PyTypeObject*)&hfmat4x2Type :
		(std::is_same<mat<C, R, T>, mat<4, 3, float> >::value) ? (PyTypeObject*)&hfmat4x3Type :
		(std::is_same<mat<C, R, T>, mat<4, 4, float> >::value) ? (PyTypeObject*)&hfmat4x4Type :
		(std::is_same<mat<C, R, T>, mat<2, 2, double> >::value) ? (PyTypeObject*)&hdmat2x2Type :
		(std::is_same<mat<C, R, T>, mat<2, 3, double> >::value) ? (PyTypeObject*)&hdmat2x3Type :
		(std::is_same<mat<C, R, T>, mat<2, 4, double> >::value) ? (PyTypeObject*)&hdmat2x4Type :
		(std::is_same<mat<C, R, T>, mat<3, 2, double> >::value) ? (PyTypeObject*)&hdmat3x2Type :
		(std::is_same<mat<C, R, T>, mat<3, 3, double> >::value) ? (PyTypeObject*)&hdmat3x3Type :
		(std::is_same<mat<C, R, T>, mat<3, 4, double> >::value) ? (PyTypeObject*)&hdmat3x4Type :
		(std::is_same<mat<C, R, T>, mat<4, 2, double> >::value) ? (PyTypeObject*)&hdmat4x2Type :
		(std::is_same<mat<C, R, T>, mat<4, 3, double> >::value) ? (PyTypeObject*)&hdmat4x3Type :
		(std::is_same<mat<C, R, T>, mat<4, 4, double> >::value) ? (PyTypeObject*)&hdmat4x4Type :
		(std::is_same<mat<C, R, T>, mat<2, 2, int32> >::value) ? (PyTypeObject*)&himat2x2Type :
		(std::is_same<mat<C, R, T>, mat<2, 3, int32> >::value) ? (PyTypeObject*)&himat2x3Type :
		(std::is_same<mat<C, R, T>, mat<2, 4, int32> >::value) ? (PyTypeObject*)&himat2x4Type :
		(std::is_same<mat<C, R, T>, mat<3, 2, int32> >::value) ? (PyTypeObject*)&himat3x2Type :
		(std::is_same<mat<C, R, T>, mat<3, 3, int32> >::value) ? (PyTypeObject*)&himat3x3Type :
		(std::is_same<mat<C, R, T>, mat<3, 4, int32> >::value) ? (PyTypeObject*)&himat3x4Type :
		(std::is_same<mat<C, R, T>, mat<4, 2, int32> >::value) ? (PyTypeObject*)&himat4x2Type :
		(std::is_same<mat<C, R, T>, mat<4, 3, int32> >::value) ? (PyTypeObject*)&himat4x3Type :
		(std::is_same<mat<C, R, T>, mat<4, 4, int32> >::value) ? (PyTypeObject*)&himat4x4Type :
		(std::is_same<mat<C, R, T>, mat<2, 2, uint32> >::value) ? (PyTypeObject*)&humat2x2Type :
		(std::is_same<mat<C, R, T>, mat<2, 3, uint32> >::value) ? (PyTypeObject*)&humat2x3Type :
		(std::is_same<mat<C, R, T>, mat<2, 4, uint32> >::value) ? (PyTypeObject*)&humat2x4Type :
		(std::is_same<mat<C, R, T>, mat<3, 2, uint32> >::value) ? (PyTypeObject*)&humat3x2Type :
		(std::is_same<mat<C, R, T>, mat<3, 3, uint32> >::value) ? (PyTypeObject*)&humat3x3Type :
		(std::is_same<mat<C, R, T>, mat<3, 4, uint32> >::value) ? (PyTypeObject*)&humat3x4Type :
		(std::is_same<mat<C, R, T>, mat<4, 2, uint32> >::value) ? (PyTypeObject*)&humat4x2Type :
		(std::is_same<mat<C, R, T>, mat<4, 3, uint32> >::value) ? (PyTypeObject*)&humat4x3Type :
		(std::is_same<mat<C, R, T>, mat<4, 4, uint32> >::value) ? (PyTypeObject*)&humat4x4Type :
		(PyTypeObject*)0;
}

template<typename T>
static PyTypeObject* PyGLM_MAT_TYPE_T_ONLY(int C, int R) {
	return (C == 2) ? (
			(R == 2) ? PyGLM_MAT_TYPE<2, 2, T>() :
			(R == 3) ? PyGLM_MAT_TYPE<2, 3, T>() :
			(R == 4) ? PyGLM_MAT_TYPE<2, 4, T>() :
			NULL
		) :
		(C == 3) ? (
			(R == 2) ? PyGLM_MAT_TYPE<3, 2, T>() :
			(R == 3) ? PyGLM_MAT_TYPE<3, 3, T>() :
			(R == 4) ? PyGLM_MAT_TYPE<3, 4, T>() :
			NULL
		) :
		(C == 4) ? (
			(R == 2) ? PyGLM_MAT_TYPE<4, 2, T>() :
			(R == 3) ? PyGLM_MAT_TYPE<4, 3, T>() :
			(R == 4) ? PyGLM_MAT_TYPE<4, 4, T>() :
			NULL
		) :
		NULL;
}

static PyTypeObject* PyGLM_PYOBJECT_MAT_GET_COLUMN_TYPE(PyGLMTypeObject* mat) {
	switch (mat->C) {
	case 2:
		switch (mat->format) {
		case PyGLM_FS_FLOAT:
			return PyGLM_VEC_TYPE<2, float>();
		case PyGLM_FS_DOUBLE:
			return PyGLM_VEC_TYPE<2, double>();
		case PyGLM_FS_INT64:
			return PyGLM_VEC_TYPE<2, int64>();
		case PyGLM_FS_UINT64:
			return PyGLM_VEC_TYPE<2, uint64>();
		case PyGLM_FS_INT32:
			return PyGLM_VEC_TYPE<2, int32>();
		case PyGLM_FS_UINT32:
			return PyGLM_VEC_TYPE<2, uint32>();
		case PyGLM_FS_INT16:
			return PyGLM_VEC_TYPE<2, int16>();
		case PyGLM_FS_UINT16:
			return PyGLM_VEC_TYPE<2, uint16>();
		case PyGLM_FS_INT8:
			return PyGLM_VEC_TYPE<2, int8>();
		case PyGLM_FS_UINT8:
			return PyGLM_VEC_TYPE<2, uint8>();
		case PyGLM_FS_BOOL:
			return PyGLM_VEC_TYPE<2, bool>();
		}
	case 3:
		switch (mat->format) {
		case PyGLM_FS_FLOAT:
			return PyGLM_VEC_TYPE<3, float>();
		case PyGLM_FS_DOUBLE:
			return PyGLM_VEC_TYPE<3, double>();
		case PyGLM_FS_INT64:
			return PyGLM_VEC_TYPE<3, int64>();
		case PyGLM_FS_UINT64:
			return PyGLM_VEC_TYPE<3, uint64>();
		case PyGLM_FS_INT32:
			return PyGLM_VEC_TYPE<3, int32>();
		case PyGLM_FS_UINT32:
			return PyGLM_VEC_TYPE<3, uint32>();
		case PyGLM_FS_INT16:
			return PyGLM_VEC_TYPE<3, int16>();
		case PyGLM_FS_UINT16:
			return PyGLM_VEC_TYPE<3, uint16>();
		case PyGLM_FS_INT8:
			return PyGLM_VEC_TYPE<3, int8>();
		case PyGLM_FS_UINT8:
			return PyGLM_VEC_TYPE<3, uint8>();
		case PyGLM_FS_BOOL:
			return PyGLM_VEC_TYPE<3, bool>();
		}
	case 4:
		switch (mat->format) {
		case PyGLM_FS_FLOAT:
			return PyGLM_VEC_TYPE<4, float>();
		case PyGLM_FS_DOUBLE:
			return PyGLM_VEC_TYPE<4, double>();
		case PyGLM_FS_INT64:
			return PyGLM_VEC_TYPE<4, int64>();
		case PyGLM_FS_UINT64:
			return PyGLM_VEC_TYPE<4, uint64>();
		case PyGLM_FS_INT32:
			return PyGLM_VEC_TYPE<4, int32>();
		case PyGLM_FS_UINT32:
			return PyGLM_VEC_TYPE<4, uint32>();
		case PyGLM_FS_INT16:
			return PyGLM_VEC_TYPE<4, int16>();
		case PyGLM_FS_UINT16:
			return PyGLM_VEC_TYPE<4, uint16>();
		case PyGLM_FS_INT8:
			return PyGLM_VEC_TYPE<4, int8>();
		case PyGLM_FS_UINT8:
			return PyGLM_VEC_TYPE<4, uint8>();
		case PyGLM_FS_BOOL:
			return PyGLM_VEC_TYPE<4, bool>();
		}
	}
	return NULL;
}
