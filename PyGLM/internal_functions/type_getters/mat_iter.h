#pragma once

#include "../../compiler_setup.h"

template<int C, int R, typename T>
static PyTypeObject* PyGLM_MATITER_TYPE() {
	if (std::is_same<matIter<C, R, T>, matIter<2, 2, float> >::value) {
		return (PyTypeObject*)&hfmat2x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 3, float> >::value) {
		return (PyTypeObject*)&hfmat2x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 4, float> >::value) {
		return (PyTypeObject*)&hfmat2x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 2, float> >::value) {
		return (PyTypeObject*)&hfmat3x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 3, float> >::value) {
		return (PyTypeObject*)&hfmat3x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 4, float> >::value) {
		return (PyTypeObject*)&hfmat3x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 2, float> >::value) {
		return (PyTypeObject*)&hfmat4x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 3, float> >::value) {
		return (PyTypeObject*)&hfmat4x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 4, float> >::value) {
		return (PyTypeObject*)&hfmat4x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 2, double> >::value) {
		return (PyTypeObject*)&hdmat2x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 3, double> >::value) {
		return (PyTypeObject*)&hdmat2x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 4, double> >::value) {
		return (PyTypeObject*)&hdmat2x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 2, double> >::value) {
		return (PyTypeObject*)&hdmat3x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 3, double> >::value) {
		return (PyTypeObject*)&hdmat3x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 4, double> >::value) {
		return (PyTypeObject*)&hdmat3x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 2, double> >::value) {
		return (PyTypeObject*)&hdmat4x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 3, double> >::value) {
		return (PyTypeObject*)&hdmat4x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 4, double> >::value) {
		return (PyTypeObject*)&hdmat4x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 2, glm::i32> >::value) {
		return (PyTypeObject*)&himat2x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 3, glm::i32> >::value) {
		return (PyTypeObject*)&himat2x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 4, glm::i32> >::value) {
		return (PyTypeObject*)&himat2x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 2, glm::i32> >::value) {
		return (PyTypeObject*)&himat3x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 3, glm::i32> >::value) {
		return (PyTypeObject*)&himat3x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 4, glm::i32> >::value) {
		return (PyTypeObject*)&himat3x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 2, glm::i32> >::value) {
		return (PyTypeObject*)&himat4x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 3, glm::i32> >::value) {
		return (PyTypeObject*)&himat4x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 4, glm::i32> >::value) {
		return (PyTypeObject*)&himat4x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 2, glm::u32> >::value) {
		return (PyTypeObject*)&humat2x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 3, glm::u32> >::value) {
		return (PyTypeObject*)&humat2x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<2, 4, glm::u32> >::value) {
		return (PyTypeObject*)&humat2x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 2, glm::u32> >::value) {
		return (PyTypeObject*)&humat3x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 3, glm::u32> >::value) {
		return (PyTypeObject*)&humat3x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<3, 4, glm::u32> >::value) {
		return (PyTypeObject*)&humat3x4IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 2, glm::u32> >::value) {
		return (PyTypeObject*)&humat4x2IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 3, glm::u32> >::value) {
		return (PyTypeObject*)&humat4x3IterType;
	}
	if (std::is_same<matIter<C, R, T>, matIter<4, 4, glm::u32> >::value) {
		return (PyTypeObject*)&humat4x4IterType;
	}
	return (PyTypeObject*)0;
}