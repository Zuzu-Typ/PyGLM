#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int L, typename T>
static constexpr PyTypeObject* PyGLM_MVEC_TYPE() {
	if (std::is_same<mvec<L, T>, mvec<2, float> >::value) {
		return (PyTypeObject*)&hfmvec2Type;
	}
	if (std::is_same<mvec<L, T>, mvec<3, float> >::value) {
		return (PyTypeObject*)&hfmvec3Type;
	}
	if (std::is_same<mvec<L, T>, mvec<4, float> >::value) {
		return (PyTypeObject*)&hfmvec4Type;
	}
	if (std::is_same<mvec<L, T>, mvec<2, double> >::value) {
		return (PyTypeObject*)&hdmvec2Type;
	}
	if (std::is_same<mvec<L, T>, mvec<3, double> >::value) {
		return (PyTypeObject*)&hdmvec3Type;
	}
	if (std::is_same<mvec<L, T>, mvec<4, double> >::value) {
		return (PyTypeObject*)&hdmvec4Type;
	}
	if (std::is_same<mvec<L, T>, mvec<2, glm::i32> >::value) {
		return (PyTypeObject*)&himvec2Type;
	}
	if (std::is_same<mvec<L, T>, mvec<3, glm::i32> >::value) {
		return (PyTypeObject*)&himvec3Type;
	}
	if (std::is_same<mvec<L, T>, mvec<4, glm::i32> >::value) {
		return (PyTypeObject*)&himvec4Type;
	}
	if (std::is_same<mvec<L, T>, mvec<2, glm::u32> >::value) {
		return (PyTypeObject*)&humvec2Type;
	}
	if (std::is_same<mvec<L, T>, mvec<3, glm::u32> >::value) {
		return (PyTypeObject*)&humvec3Type;
	}
	if (std::is_same<mvec<L, T>, mvec<4, glm::u32> >::value) {
		return (PyTypeObject*)&humvec4Type;
	}
	return (PyTypeObject*)0;
}