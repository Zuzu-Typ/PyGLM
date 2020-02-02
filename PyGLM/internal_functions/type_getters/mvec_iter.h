#pragma once

#include "../../compiler_setup.h"

template<int L, typename T>
static PyTypeObject* PyGLM_MVECITER_TYPE() {
	if (std::is_same<mvecIter<L, T>, mvecIter<2, float> >::value) {
		return (PyTypeObject*)&hfmvec2IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<3, float> >::value) {
		return (PyTypeObject*)&hfmvec3IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<4, float> >::value) {
		return (PyTypeObject*)&hfmvec4IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<2, double> >::value) {
		return (PyTypeObject*)&hdmvec2IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<3, double> >::value) {
		return (PyTypeObject*)&hdmvec3IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<4, double> >::value) {
		return (PyTypeObject*)&hdmvec4IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<2, glm::i32> >::value) {
		return (PyTypeObject*)&himvec2IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<3, glm::i32> >::value) {
		return (PyTypeObject*)&himvec3IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<4, glm::i32> >::value) {
		return (PyTypeObject*)&himvec4IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<2, glm::u32> >::value) {
		return (PyTypeObject*)&humvec2IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<3, glm::u32> >::value) {
		return (PyTypeObject*)&humvec3IterType;
	}
	if (std::is_same<mvecIter<L, T>, mvecIter<4, glm::u32> >::value) {
		return (PyTypeObject*)&humvec4IterType;
	}
	return (PyTypeObject*)0;
}
