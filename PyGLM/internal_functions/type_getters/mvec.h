#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int L, typename T>
static constexpr PyTypeObject* PyGLM_MVEC_TYPE() {
	return (std::is_same<mvec<L, T>, mvec<2, float> >::value) ? (PyTypeObject*)&hfmvec2Type :
		(std::is_same<mvec<L, T>, mvec<3, float> >::value) ? (PyTypeObject*)&hfmvec3Type :
		(std::is_same<mvec<L, T>, mvec<4, float> >::value) ? (PyTypeObject*)&hfmvec4Type :
		(std::is_same<mvec<L, T>, mvec<2, double> >::value) ? (PyTypeObject*)&hdmvec2Type :
		(std::is_same<mvec<L, T>, mvec<3, double> >::value) ? (PyTypeObject*)&hdmvec3Type :
		(std::is_same<mvec<L, T>, mvec<4, double> >::value) ? (PyTypeObject*)&hdmvec4Type :
		(std::is_same<mvec<L, T>, mvec<2, int32> >::value) ? (PyTypeObject*)&himvec2Type :
		(std::is_same<mvec<L, T>, mvec<3, int32> >::value) ? (PyTypeObject*)&himvec3Type :
		(std::is_same<mvec<L, T>, mvec<4, int32> >::value) ? (PyTypeObject*)&himvec4Type :
		(std::is_same<mvec<L, T>, mvec<2, uint32> >::value) ? (PyTypeObject*)&humvec2Type :
		(std::is_same<mvec<L, T>, mvec<3, uint32> >::value) ? (PyTypeObject*)&humvec3Type :
		(std::is_same<mvec<L, T>, mvec<4, uint32> >::value) ? (PyTypeObject*)&humvec4Type :
		(PyTypeObject*)0;
}