#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int L, typename T>
static PyTypeObject* PyGLM_MVECITER_TYPE() {
	return (std::is_same<mvecIter<L, T>, mvecIter<2, float> >::value) ? (PyTypeObject*)&hfmvec2IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<3, float> >::value) ? (PyTypeObject*)&hfmvec3IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<4, float> >::value) ? (PyTypeObject*)&hfmvec4IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<2, double> >::value) ? (PyTypeObject*)&hdmvec2IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<3, double> >::value) ? (PyTypeObject*)&hdmvec3IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<4, double> >::value) ? (PyTypeObject*)&hdmvec4IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<2, int32> >::value) ? (PyTypeObject*)&himvec2IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<3, int32> >::value) ? (PyTypeObject*)&himvec3IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<4, int32> >::value) ? (PyTypeObject*)&himvec4IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<2, uint32> >::value) ? (PyTypeObject*)&humvec2IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<3, uint32> >::value) ? (PyTypeObject*)&humvec3IterType:
		(std::is_same<mvecIter<L, T>, mvecIter<4, uint32> >::value) ? (PyTypeObject*)&humvec4IterType:
		(PyTypeObject*)0;
}
