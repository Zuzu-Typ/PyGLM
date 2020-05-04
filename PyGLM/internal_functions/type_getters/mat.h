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