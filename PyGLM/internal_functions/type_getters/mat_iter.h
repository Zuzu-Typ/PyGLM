#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int C, int R, typename T>
static PyTypeObject* PyGLM_MATITER_TYPE() {
	return (std::is_same<matIter<C, R, T>, matIter<2, 2, float> >::value) ? (PyTypeObject*)&hfmat2x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 3, float> >::value) ? (PyTypeObject*)&hfmat2x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 4, float> >::value) ? (PyTypeObject*)&hfmat2x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 2, float> >::value) ? (PyTypeObject*)&hfmat3x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 3, float> >::value) ? (PyTypeObject*)&hfmat3x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 4, float> >::value) ? (PyTypeObject*)&hfmat3x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 2, float> >::value) ? (PyTypeObject*)&hfmat4x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 3, float> >::value) ? (PyTypeObject*)&hfmat4x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 4, float> >::value) ? (PyTypeObject*)&hfmat4x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 2, double> >::value) ? (PyTypeObject*)&hdmat2x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 3, double> >::value) ? (PyTypeObject*)&hdmat2x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 4, double> >::value) ? (PyTypeObject*)&hdmat2x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 2, double> >::value) ? (PyTypeObject*)&hdmat3x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 3, double> >::value) ? (PyTypeObject*)&hdmat3x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 4, double> >::value) ? (PyTypeObject*)&hdmat3x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 2, double> >::value) ? (PyTypeObject*)&hdmat4x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 3, double> >::value) ? (PyTypeObject*)&hdmat4x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 4, double> >::value) ? (PyTypeObject*)&hdmat4x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 2, int32> >::value) ? (PyTypeObject*)&himat2x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 3, int32> >::value) ? (PyTypeObject*)&himat2x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 4, int32> >::value) ? (PyTypeObject*)&himat2x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 2, int32> >::value) ? (PyTypeObject*)&himat3x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 3, int32> >::value) ? (PyTypeObject*)&himat3x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 4, int32> >::value) ? (PyTypeObject*)&himat3x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 2, int32> >::value) ? (PyTypeObject*)&himat4x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 3, int32> >::value) ? (PyTypeObject*)&himat4x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 4, int32> >::value) ? (PyTypeObject*)&himat4x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 2, uint32> >::value) ? (PyTypeObject*)&humat2x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 3, uint32> >::value) ? (PyTypeObject*)&humat2x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<2, 4, uint32> >::value) ? (PyTypeObject*)&humat2x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 2, uint32> >::value) ? (PyTypeObject*)&humat3x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 3, uint32> >::value) ? (PyTypeObject*)&humat3x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<3, 4, uint32> >::value) ? (PyTypeObject*)&humat3x4IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 2, uint32> >::value) ? (PyTypeObject*)&humat4x2IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 3, uint32> >::value) ? (PyTypeObject*)&humat4x3IterType :
		(std::is_same<matIter<C, R, T>, matIter<4, 4, uint32> >::value) ? (PyTypeObject*)&humat4x4IterType :
		(PyTypeObject*)0;
}