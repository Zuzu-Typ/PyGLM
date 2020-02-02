#pragma once

#include "../../compiler_setup.h"

template<int L, typename T>
static PyTypeObject* PyGLM_VEC_TYPE() {
	if (std::is_same<vec<L, T>, vec<1, float> >::value) {
		return (PyTypeObject*)&hfvec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, float> >::value) {
		return (PyTypeObject*)&hfvec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, float> >::value) {
		return (PyTypeObject*)&hfvec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, float> >::value) {
		return (PyTypeObject*)&hfvec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, double> >::value) {
		return (PyTypeObject*)&hdvec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, double> >::value) {
		return (PyTypeObject*)&hdvec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, double> >::value) {
		return (PyTypeObject*)&hdvec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, double> >::value) {
		return (PyTypeObject*)&hdvec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::i8> >::value) {
		return (PyTypeObject*)&hi8vec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::i16> >::value) {
		return (PyTypeObject*)&hi16vec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::i32> >::value) {
		return (PyTypeObject*)&hivec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::i32> >::value) {
		return (PyTypeObject*)&hivec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::i32> >::value) {
		return (PyTypeObject*)&hivec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::i32> >::value) {
		return (PyTypeObject*)&hivec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::i64> >::value) {
		return (PyTypeObject*)&hi64vec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::u8> >::value) {
		return (PyTypeObject*)&hu8vec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::u16> >::value) {
		return (PyTypeObject*)&hu16vec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::u32> >::value) {
		return (PyTypeObject*)&huvec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::u32> >::value) {
		return (PyTypeObject*)&huvec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::u32> >::value) {
		return (PyTypeObject*)&huvec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::u32> >::value) {
		return (PyTypeObject*)&huvec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, glm::u64> >::value) {
		return (PyTypeObject*)&hu64vec4Type;
	}
	if (std::is_same<vec<L, T>, vec<1, bool> >::value) {
		return (PyTypeObject*)&hbvec1Type;
	}
	if (std::is_same<vec<L, T>, vec<2, bool> >::value) {
		return (PyTypeObject*)&hbvec2Type;
	}
	if (std::is_same<vec<L, T>, vec<3, bool> >::value) {
		return (PyTypeObject*)&hbvec3Type;
	}
	if (std::is_same<vec<L, T>, vec<4, bool> >::value) {
		return (PyTypeObject*)&hbvec4Type;
	}
	return (PyTypeObject*)0;
}