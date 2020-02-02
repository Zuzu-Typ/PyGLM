#pragma once

#include "../../compiler_setup.h"

template<int L, typename T>
static PyTypeObject* PyGLM_VECITER_TYPE() {
	if (std::is_same<vecIter<L, T>, vecIter<1, float> >::value) {
		return (PyTypeObject*)&hfvec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, float> >::value) {
		return (PyTypeObject*)&hfvec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, float> >::value) {
		return (PyTypeObject*)&hfvec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, float> >::value) {
		return (PyTypeObject*)&hfvec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, double> >::value) {
		return (PyTypeObject*)&hdvec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, double> >::value) {
		return (PyTypeObject*)&hdvec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, double> >::value) {
		return (PyTypeObject*)&hdvec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, double> >::value) {
		return (PyTypeObject*)&hdvec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::i32> >::value) {
		return (PyTypeObject*)&hivec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::i32> >::value) {
		return (PyTypeObject*)&hivec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::i32> >::value) {
		return (PyTypeObject*)&hivec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::i32> >::value) {
		return (PyTypeObject*)&hivec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::u32> >::value) {
		return (PyTypeObject*)&huvec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::u32> >::value) {
		return (PyTypeObject*)&huvec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::u32> >::value) {
		return (PyTypeObject*)&huvec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::u32> >::value) {
		return (PyTypeObject*)&huvec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec4IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<1, bool> >::value) {
		return (PyTypeObject*)&hbvec1IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<2, bool> >::value) {
		return (PyTypeObject*)&hbvec2IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<3, bool> >::value) {
		return (PyTypeObject*)&hbvec3IterType;
	}
	if (std::is_same<vecIter<L, T>, vecIter<4, bool> >::value) {
		return (PyTypeObject*)&hbvec4IterType;
	}
	return (PyTypeObject*)0;
}