#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<int L, typename T>
static PyTypeObject* PyGLM_VECITER_TYPE() {
	return (std::is_same<vecIter<L, T>, vecIter<1, float> >::value) ? (PyTypeObject*)&hfvec1IterType : 
		(std::is_same<vecIter<L, T>, vecIter<2, float> >::value) ? (PyTypeObject*)&hfvec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, float> >::value) ? (PyTypeObject*)&hfvec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, float> >::value) ? (PyTypeObject*)&hfvec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, double> >::value) ? (PyTypeObject*)&hdvec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, double> >::value) ? (PyTypeObject*)&hdvec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, double> >::value) ? (PyTypeObject*)&hdvec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, double> >::value) ? (PyTypeObject*)&hdvec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, int8> >::value) ? (PyTypeObject*)&hi8vec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, int8> >::value) ? (PyTypeObject*)&hi8vec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, int8> >::value) ? (PyTypeObject*)&hi8vec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, int8> >::value) ? (PyTypeObject*)&hi8vec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, int16> >::value) ? (PyTypeObject*)&hi16vec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, int16> >::value) ? (PyTypeObject*)&hi16vec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, int16> >::value) ? (PyTypeObject*)&hi16vec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, int16> >::value) ? (PyTypeObject*)&hi16vec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, int32> >::value) ? (PyTypeObject*)&hivec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, int32> >::value) ? (PyTypeObject*)&hivec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, int32> >::value) ? (PyTypeObject*)&hivec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, int32> >::value) ? (PyTypeObject*)&hivec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, int64> >::value) ? (PyTypeObject*)&hi64vec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, int64> >::value) ? (PyTypeObject*)&hi64vec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, int64> >::value) ? (PyTypeObject*)&hi64vec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, int64> >::value) ? (PyTypeObject*)&hi64vec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, uint8> >::value) ? (PyTypeObject*)&hu8vec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, uint8> >::value) ? (PyTypeObject*)&hu8vec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, uint8> >::value) ? (PyTypeObject*)&hu8vec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, uint8> >::value) ? (PyTypeObject*)&hu8vec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, uint16> >::value) ? (PyTypeObject*)&hu16vec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, uint16> >::value) ? (PyTypeObject*)&hu16vec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, uint16> >::value) ? (PyTypeObject*)&hu16vec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, uint16> >::value) ? (PyTypeObject*)&hu16vec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, uint32> >::value) ? (PyTypeObject*)&huvec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, uint32> >::value) ? (PyTypeObject*)&huvec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, uint32> >::value) ? (PyTypeObject*)&huvec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, uint32> >::value) ? (PyTypeObject*)&huvec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, uint64> >::value) ? (PyTypeObject*)&hu64vec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, uint64> >::value) ? (PyTypeObject*)&hu64vec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, uint64> >::value) ? (PyTypeObject*)&hu64vec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, uint64> >::value) ? (PyTypeObject*)&hu64vec4IterType :
		(std::is_same<vecIter<L, T>, vecIter<1, bool> >::value) ? (PyTypeObject*)&hbvec1IterType :
		(std::is_same<vecIter<L, T>, vecIter<2, bool> >::value) ? (PyTypeObject*)&hbvec2IterType :
		(std::is_same<vecIter<L, T>, vecIter<3, bool> >::value) ? (PyTypeObject*)&hbvec3IterType :
		(std::is_same<vecIter<L, T>, vecIter<4, bool> >::value) ? (PyTypeObject*)&hbvec4IterType :
		(PyTypeObject*)0;
}