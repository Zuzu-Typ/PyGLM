#pragma once

#include "all.h"

static PyGLMTypeObject PyGLMTypeObjectArray[] = {
	{ DVEC1_GLM_TYPEOBJECT },
	{ DVEC2_GLM_TYPEOBJECT },
	{ DVEC3_GLM_TYPEOBJECT },
	{ DVEC4_GLM_TYPEOBJECT },
	{ FVEC1_GLM_TYPEOBJECT },
	{ FVEC2_GLM_TYPEOBJECT },
	{ FVEC3_GLM_TYPEOBJECT },
	{ FVEC4_GLM_TYPEOBJECT },
	{ I64VEC1_GLM_TYPEOBJECT },
	{ I64VEC2_GLM_TYPEOBJECT },
	{ I64VEC3_GLM_TYPEOBJECT },
	{ I64VEC4_GLM_TYPEOBJECT },
	{ IVEC1_GLM_TYPEOBJECT },
	{ IVEC2_GLM_TYPEOBJECT },
	{ IVEC3_GLM_TYPEOBJECT },
	{ IVEC4_GLM_TYPEOBJECT },
	{ I16VEC1_GLM_TYPEOBJECT },
	{ I16VEC2_GLM_TYPEOBJECT },
	{ I16VEC3_GLM_TYPEOBJECT },
	{ I16VEC4_GLM_TYPEOBJECT },
	{ I8VEC1_GLM_TYPEOBJECT },
	{ I8VEC2_GLM_TYPEOBJECT },
	{ I8VEC3_GLM_TYPEOBJECT },
	{ I8VEC4_GLM_TYPEOBJECT },
	{ U64VEC1_GLM_TYPEOBJECT },
	{ U64VEC2_GLM_TYPEOBJECT },
	{ U64VEC3_GLM_TYPEOBJECT },
	{ U64VEC4_GLM_TYPEOBJECT },
	{ UVEC1_GLM_TYPEOBJECT },
	{ UVEC2_GLM_TYPEOBJECT },
	{ UVEC3_GLM_TYPEOBJECT },
	{ UVEC4_GLM_TYPEOBJECT },
	{ U16VEC1_GLM_TYPEOBJECT },
	{ U16VEC2_GLM_TYPEOBJECT },
	{ U16VEC3_GLM_TYPEOBJECT },
	{ U16VEC4_GLM_TYPEOBJECT },
	{ U8VEC1_GLM_TYPEOBJECT },
	{ U8VEC2_GLM_TYPEOBJECT },
	{ U8VEC3_GLM_TYPEOBJECT },
	{ U8VEC4_GLM_TYPEOBJECT },
	{ BVEC1_GLM_TYPEOBJECT },
	{ BVEC2_GLM_TYPEOBJECT },
	{ BVEC3_GLM_TYPEOBJECT },
	{ BVEC4_GLM_TYPEOBJECT },

	{ DMVEC2_GLM_TYPEOBJECT },
	{ DMVEC3_GLM_TYPEOBJECT },
	{ DMVEC4_GLM_TYPEOBJECT },
	{ FMVEC2_GLM_TYPEOBJECT },
	{ FMVEC3_GLM_TYPEOBJECT },
	{ FMVEC4_GLM_TYPEOBJECT },
	{ IMVEC2_GLM_TYPEOBJECT },
	{ IMVEC3_GLM_TYPEOBJECT },
	{ IMVEC4_GLM_TYPEOBJECT },
	{ UMVEC2_GLM_TYPEOBJECT },
	{ UMVEC3_GLM_TYPEOBJECT },
	{ UMVEC4_GLM_TYPEOBJECT },

	{ DMAT2x2_GLM_TYPEOBJECT },
	{ DMAT2x3_GLM_TYPEOBJECT },
	{ DMAT2x4_GLM_TYPEOBJECT },
	{ DMAT3x2_GLM_TYPEOBJECT },
	{ DMAT3x3_GLM_TYPEOBJECT },
	{ DMAT3x4_GLM_TYPEOBJECT },
	{ DMAT4x2_GLM_TYPEOBJECT },
	{ DMAT4x3_GLM_TYPEOBJECT },
	{ DMAT4x4_GLM_TYPEOBJECT },
	{ FMAT2x2_GLM_TYPEOBJECT },
	{ FMAT2x3_GLM_TYPEOBJECT },
	{ FMAT2x4_GLM_TYPEOBJECT },
	{ FMAT3x2_GLM_TYPEOBJECT },
	{ FMAT3x3_GLM_TYPEOBJECT },
	{ FMAT3x4_GLM_TYPEOBJECT },
	{ FMAT4x2_GLM_TYPEOBJECT },
	{ FMAT4x3_GLM_TYPEOBJECT },
	{ FMAT4x4_GLM_TYPEOBJECT },
	{ IMAT2x2_GLM_TYPEOBJECT },
	{ IMAT2x3_GLM_TYPEOBJECT },
	{ IMAT2x4_GLM_TYPEOBJECT },
	{ IMAT3x2_GLM_TYPEOBJECT },
	{ IMAT3x3_GLM_TYPEOBJECT },
	{ IMAT3x4_GLM_TYPEOBJECT },
	{ IMAT4x2_GLM_TYPEOBJECT },
	{ IMAT4x3_GLM_TYPEOBJECT },
	{ IMAT4x4_GLM_TYPEOBJECT },
	{ UMAT2x2_GLM_TYPEOBJECT },
	{ UMAT2x3_GLM_TYPEOBJECT },
	{ UMAT2x4_GLM_TYPEOBJECT },
	{ UMAT3x2_GLM_TYPEOBJECT },
	{ UMAT3x3_GLM_TYPEOBJECT },
	{ UMAT3x4_GLM_TYPEOBJECT },
	{ UMAT4x2_GLM_TYPEOBJECT },
	{ UMAT4x3_GLM_TYPEOBJECT },
	{ UMAT4x4_GLM_TYPEOBJECT },

	{ DQUA_GLM_TYPEOBJECT },
	{ FQUA_GLM_TYPEOBJECT }
};

#define _PyGLM_VEC_START 0
#define _PyGLM_MVEC_START 44
#define _PyGLM_MAT_START 56
#define _PyGLM_QUA_START 92

#define _TOTAL_TYPEOBJECTS 94 

static PyGLMTypeObject* const PyGLMTypeObjectArrayStart = PyGLMTypeObjectArray;
static PyGLMTypeObject* const PyGLMTypeObjectArrayEnd = reinterpret_cast<PyGLMTypeObject*>(reinterpret_cast<char*>(PyGLMTypeObjectArray) + sizeof(PyGLMTypeObjectArray));



template<int L, typename T>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec() {
	return 0;
	/*if (std::is_same<T, double>::value) {
		return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 0 + L - 1);
	}*/
	
	/*
	if (std::is_same<T, float>::value) {
		return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 4 + L - 1);
	}
	if (std::is_same<T, bool>::value) {
		return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 40 + L - 1);
	}
	if (std::is_integral<T>::value) {
		if (std::is_signed<T>::value) {
			switch (sizeof(T)) {
			case sizeof(int64) :
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 8 + L - 1);
			case sizeof(int32) :
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 12 + L - 1);
			case sizeof(int16) :
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 16 + L - 1);
			case sizeof(int8):
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 20 + L - 1);
			}
		}
		if (std::is_unsigned<T>::value) {
			switch (sizeof(T)) {
			case sizeof(uint64) :
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 24 + L - 1);
			case sizeof(uint32) :
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 28 + L - 1);
			case sizeof(uint16) :
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 32 + L - 1);
			case sizeof(uint8):
				return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 36 + L - 1);
			}
		}
	}*/
}

template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, double>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 0 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, float>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 4 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, int64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 8 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, int32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 12 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, int16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 16 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, int8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 20 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, uint64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 24 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, uint32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 28 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, uint16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 32 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, uint8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 36 + 1 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<1, bool>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 40 + 1 - 1);
}template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, double>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 0 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, float>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 4 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, int64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 8 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, int32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 12 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, int16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 16 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, int8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 20 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, uint64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 24 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, uint32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 28 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, uint16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 32 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, uint8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 36 + 2 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<2, bool>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 40 + 2 - 1);
}template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, double>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 0 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, float>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 4 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, int64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 8 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, int32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 12 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, int16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 16 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, int8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 20 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, uint64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 24 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, uint32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 28 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, uint16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 32 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, uint8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 36 + 3 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<3, bool>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 40 + 3 - 1);
}template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, double>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 0 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, float>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 4 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, int64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 8 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, int32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 12 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, int16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 16 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, int8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 20 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, uint64>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 24 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, uint32>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 28 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, uint16>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 32 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, uint8>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 36 + 4 - 1);
}
template <>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetVec<4, bool>() {
	return static_cast<ptrdiff_t>(_PyGLM_VEC_START + 40 + 4 - 1);
}


template<int C, int R, typename T>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetMat() {
	if (std::is_same<T, double>::value) {
		return _PyGLM_MAT_START + 0 + R - 2 + 3 * (C - 2);
	}
	if (std::is_same<T, float>::value) {
		return _PyGLM_MAT_START + 9 + R - 2 + 3 * (C - 2);
	}
	if (std::is_integral<T>::value) {
		if (std::is_signed<T>::value) {
			if (sizeof(T) == sizeof(int32)) {
				return _PyGLM_MAT_START + 18 + R - 2 + 3 * (C - 2);
			}
		}
		if (std::is_unsigned<T>::value) {
			if (sizeof(T) == sizeof(int32)) {
				return _PyGLM_MAT_START + 27 + R - 2 + 3 * (C - 2);
			}
		}
	}
}

template<int L, typename T>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetMVec() {
	if (2 <= L && L <= 4) {
		if (std::is_same<T, double>::value) {
			return _PyGLM_MVEC_START + 0 + L - 2;
		}
		if (std::is_same<T, float>::value) {
			return _PyGLM_MVEC_START + 3 + L - 2;
		}
		if (std::is_integral<T>::value) {
			if (std::is_signed<T>::value) {
				if (sizeof(T) == sizeof(int32)) {
					return _PyGLM_MVEC_START + 6 + L - 2;
				}
			}
			if (std::is_unsigned<T>::value) {
				if (sizeof(T) == sizeof(int32)) {
					return _PyGLM_MVEC_START + 9 + L - 2;
				}
			}
		}
	}
}

template<typename T>
static constexpr ptrdiff_t PyGLMTypeObjectArrayOffsetQua() {
	if (std::is_same<T, double>::value) {
		return _PyGLM_QUA_START + 0;
	}
	if (std::is_same<T, float>::value) {
		return _PyGLM_QUA_START + 1;
	}
}

// vec
static PyTypeObject& hdvec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 0].typeObject;
static PyTypeObject& hdvec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 1].typeObject;
static PyTypeObject& hdvec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 2].typeObject;
static PyTypeObject& hdvec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 3].typeObject;

static PyTypeObject& hfvec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 4].typeObject;
static PyTypeObject& hfvec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 5].typeObject;
static PyTypeObject& hfvec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 6].typeObject;
static PyTypeObject& hfvec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 7].typeObject;

static PyTypeObject& hi64vec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 8].typeObject;
static PyTypeObject& hi64vec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 9].typeObject;
static PyTypeObject& hi64vec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 10].typeObject;
static PyTypeObject& hi64vec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 11].typeObject;

static PyTypeObject& hivec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 12].typeObject;
static PyTypeObject& hivec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 13].typeObject;
static PyTypeObject& hivec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 14].typeObject;
static PyTypeObject& hivec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 15].typeObject;

static PyTypeObject& hi16vec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 16].typeObject;
static PyTypeObject& hi16vec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 17].typeObject;
static PyTypeObject& hi16vec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 18].typeObject;
static PyTypeObject& hi16vec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 19].typeObject;

static PyTypeObject& hi8vec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 20].typeObject;
static PyTypeObject& hi8vec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 21].typeObject;
static PyTypeObject& hi8vec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 22].typeObject;
static PyTypeObject& hi8vec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 23].typeObject;

static PyTypeObject& hu64vec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 24].typeObject;
static PyTypeObject& hu64vec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 25].typeObject;
static PyTypeObject& hu64vec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 26].typeObject;
static PyTypeObject& hu64vec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 27].typeObject;

static PyTypeObject& huvec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 28].typeObject;
static PyTypeObject& huvec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 29].typeObject;
static PyTypeObject& huvec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 30].typeObject;
static PyTypeObject& huvec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 31].typeObject;

static PyTypeObject& hu16vec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 32].typeObject;
static PyTypeObject& hu16vec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 33].typeObject;
static PyTypeObject& hu16vec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 34].typeObject;
static PyTypeObject& hu16vec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 35].typeObject;

static PyTypeObject& hu8vec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 36].typeObject;
static PyTypeObject& hu8vec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 37].typeObject;
static PyTypeObject& hu8vec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 38].typeObject;
static PyTypeObject& hu8vec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 39].typeObject;

static PyTypeObject& hbvec1Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 40].typeObject;
static PyTypeObject& hbvec2Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 41].typeObject;
static PyTypeObject& hbvec3Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 42].typeObject;
static PyTypeObject& hbvec4Type = PyGLMTypeObjectArray[_PyGLM_VEC_START + 43].typeObject;

// mvec
static PyTypeObject& hdmvec2Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 0].typeObject;
static PyTypeObject& hdmvec3Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 1].typeObject;
static PyTypeObject& hdmvec4Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 2].typeObject;

static PyTypeObject& hfmvec2Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 3].typeObject;
static PyTypeObject& hfmvec3Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 4].typeObject;
static PyTypeObject& hfmvec4Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 5].typeObject;

static PyTypeObject& himvec2Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 6].typeObject;
static PyTypeObject& himvec3Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 7].typeObject;
static PyTypeObject& himvec4Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 8].typeObject;

static PyTypeObject& humvec2Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 9].typeObject;
static PyTypeObject& humvec3Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 10].typeObject;
static PyTypeObject& humvec4Type = PyGLMTypeObjectArray[_PyGLM_MVEC_START + 11].typeObject;

// mat
static PyTypeObject& hdmat2x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 0].typeObject;
static PyTypeObject& hdmat2x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 1].typeObject;
static PyTypeObject& hdmat2x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 2].typeObject;
static PyTypeObject& hdmat3x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 3].typeObject;
static PyTypeObject& hdmat3x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 4].typeObject;
static PyTypeObject& hdmat3x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 5].typeObject;
static PyTypeObject& hdmat4x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 6].typeObject;
static PyTypeObject& hdmat4x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 7].typeObject;
static PyTypeObject& hdmat4x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 8].typeObject;

static PyTypeObject& hfmat2x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 9].typeObject;
static PyTypeObject& hfmat2x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 10].typeObject;
static PyTypeObject& hfmat2x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 11].typeObject;
static PyTypeObject& hfmat3x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 12].typeObject;
static PyTypeObject& hfmat3x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 13].typeObject;
static PyTypeObject& hfmat3x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 14].typeObject;
static PyTypeObject& hfmat4x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 15].typeObject;
static PyTypeObject& hfmat4x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 16].typeObject;
static PyTypeObject& hfmat4x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 17].typeObject;

static PyTypeObject& himat2x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 18].typeObject;
static PyTypeObject& himat2x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 19].typeObject;
static PyTypeObject& himat2x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 20].typeObject;
static PyTypeObject& himat3x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 21].typeObject;
static PyTypeObject& himat3x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 22].typeObject;
static PyTypeObject& himat3x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 23].typeObject;
static PyTypeObject& himat4x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 24].typeObject;
static PyTypeObject& himat4x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 25].typeObject;
static PyTypeObject& himat4x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 26].typeObject;

static PyTypeObject& humat2x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 27].typeObject;
static PyTypeObject& humat2x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 28].typeObject;
static PyTypeObject& humat2x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 29].typeObject;
static PyTypeObject& humat3x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 30].typeObject;
static PyTypeObject& humat3x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 31].typeObject;
static PyTypeObject& humat3x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 32].typeObject;
static PyTypeObject& humat4x2Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 33].typeObject;
static PyTypeObject& humat4x3Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 34].typeObject;
static PyTypeObject& humat4x4Type = PyGLMTypeObjectArray[_PyGLM_MAT_START + 35].typeObject;

// qua
static PyTypeObject& hdquaType = PyGLMTypeObjectArray[_PyGLM_QUA_START + 0].typeObject;
static PyTypeObject& hfquaType = PyGLMTypeObjectArray[_PyGLM_QUA_START + 1].typeObject;

#undef _PyGLM_VEC_START 
#undef _PyGLM_MVEC_START 
#undef _PyGLM_MAT_START 
#undef _PyGLM_QUA_START 
