#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int C, int R, typename T>
static constexpr PyTypeObject* PyGLM_MAT_TYPE() {
	if (std::is_same<mat<C, R, T>, mat<2, 2, float> >::value) {
		return (PyTypeObject*)&hfmat2x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 3, float> >::value) {
		return (PyTypeObject*)&hfmat2x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 4, float> >::value) {
		return (PyTypeObject*)&hfmat2x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 2, float> >::value) {
		return (PyTypeObject*)&hfmat3x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 3, float> >::value) {
		return (PyTypeObject*)&hfmat3x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 4, float> >::value) {
		return (PyTypeObject*)&hfmat3x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 2, float> >::value) {
		return (PyTypeObject*)&hfmat4x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 3, float> >::value) {
		return (PyTypeObject*)&hfmat4x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 4, float> >::value) {
		return (PyTypeObject*)&hfmat4x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 2, double> >::value) {
		return (PyTypeObject*)&hdmat2x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 3, double> >::value) {
		return (PyTypeObject*)&hdmat2x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 4, double> >::value) {
		return (PyTypeObject*)&hdmat2x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 2, double> >::value) {
		return (PyTypeObject*)&hdmat3x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 3, double> >::value) {
		return (PyTypeObject*)&hdmat3x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 4, double> >::value) {
		return (PyTypeObject*)&hdmat3x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 2, double> >::value) {
		return (PyTypeObject*)&hdmat4x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 3, double> >::value) {
		return (PyTypeObject*)&hdmat4x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 4, double> >::value) {
		return (PyTypeObject*)&hdmat4x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 2, glm::i32> >::value) {
		return (PyTypeObject*)&himat2x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 3, glm::i32> >::value) {
		return (PyTypeObject*)&himat2x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 4, glm::i32> >::value) {
		return (PyTypeObject*)&himat2x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 2, glm::i32> >::value) {
		return (PyTypeObject*)&himat3x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 3, glm::i32> >::value) {
		return (PyTypeObject*)&himat3x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 4, glm::i32> >::value) {
		return (PyTypeObject*)&himat3x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 2, glm::i32> >::value) {
		return (PyTypeObject*)&himat4x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 3, glm::i32> >::value) {
		return (PyTypeObject*)&himat4x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 4, glm::i32> >::value) {
		return (PyTypeObject*)&himat4x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 2, glm::u32> >::value) {
		return (PyTypeObject*)&humat2x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 3, glm::u32> >::value) {
		return (PyTypeObject*)&humat2x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<2, 4, glm::u32> >::value) {
		return (PyTypeObject*)&humat2x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 2, glm::u32> >::value) {
		return (PyTypeObject*)&humat3x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 3, glm::u32> >::value) {
		return (PyTypeObject*)&humat3x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<3, 4, glm::u32> >::value) {
		return (PyTypeObject*)&humat3x4Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 2, glm::u32> >::value) {
		return (PyTypeObject*)&humat4x2Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 3, glm::u32> >::value) {
		return (PyTypeObject*)&humat4x3Type;
	}
	if (std::is_same<mat<C, R, T>, mat<4, 4, glm::u32> >::value) {
		return (PyTypeObject*)&humat4x4Type;
	}
	return (PyTypeObject*)0;
}