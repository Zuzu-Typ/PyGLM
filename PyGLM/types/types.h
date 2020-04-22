#pragma once

#include "../imports.h"

// type identifiers
#define PyGLM_TYPE_UNKNOWN 0
#define PyGLM_TYPE_VEC 1
#define PyGLM_TYPE_MAT 2
#define PyGLM_TYPE_QUA 3
/*
shape looks like this:
For Vec:
  bits 0-3 = shape
  bits 4-7 = type
  examples:
    0 1 2 3 4 5 6 7
	0 0 1 0 1 1 0 1
	= bvec4

	0 1 2 3 4 5 6 7
	1 0 0 0 0 0 0 0
	= fvec1

For Mat:
  bits 0-2 = shape1 (n)
  bits 3-5 = shape2 (m)
  bits 6-7 = type
  examples:
    0 1 2 3 4 5 6 7
	0 1 0 1 1 0 1 0
	= dmat2x3

For Qua:
  bits 0-3 = 4 (shape == 4)
  bits 4-7 = type (0 or 1 i.e. float or double respectively)
  examples:
	0 1 2 3 4 5 6 7
	0 0 1 0 0 0 0 0
	= quat
*/

#define PyGLM_TYPE_INFO_VEC_SHAPE_OFFSET	0
#define PyGLM_TYPE_INFO_VEC_SHAPE_LENGTH	4

#define PyGLM_TYPE_INFO_VEC_TYPE_OFFSET		4
#define PyGLM_TYPE_INFO_VEC_TYPE_LENGTH		4


#define PyGLM_TYPE_INFO_MAT_SHAPE1_OFFSET	0
#define PyGLM_TYPE_INFO_MAT_SHAPE1_LENGTH	3

#define PyGLM_TYPE_INFO_MAT_SHAPE2_OFFSET	3
#define PyGLM_TYPE_INFO_MAT_SHAPE2_LENGTH	3

#define PyGLM_TYPE_INFO_MAT_TYPE_OFFSET		6
#define PyGLM_TYPE_INFO_MAT_TYPE_LENGTH		2


#define PyGLM_TYPE_INFO_FLOAT	0
#define PyGLM_TYPE_INFO_DOUBLE	1
#define PyGLM_TYPE_INFO_INT		2
#define PyGLM_TYPE_INFO_UINT	3
#define PyGLM_TYPE_INFO_INT8	4
#define PyGLM_TYPE_INFO_UINT8	5
#define PyGLM_TYPE_INFO_INT16	6
#define PyGLM_TYPE_INFO_UINT16	7
#define PyGLM_TYPE_INFO_INT64	8
#define PyGLM_TYPE_INFO_UINT64	9
#define PyGLM_TYPE_INFO_BOOL	10

#define PyGLM_TYPE_INFO_UNKNOWN 15

typedef int8_t		int8;
typedef uint8_t		uint8;
typedef int16_t		int16;
typedef uint16_t	uint16;
typedef int32_t		int32;
typedef uint32_t	uint32;
typedef int64_t		int64;
typedef uint64_t	uint64;

template<typename T>
constexpr uint8_t get_type_helper_type() {
	if (std::is_same<float, T>::value)
		return PyGLM_TYPE_INFO_FLOAT;
	if (std::is_same<double, T>::value)
		return PyGLM_TYPE_INFO_DOUBLE;
	if (std::is_same<int32_t, T>::value)
		return PyGLM_TYPE_INFO_INT;
	if (std::is_same<uint32_t, T>::value)
		return PyGLM_TYPE_INFO_UINT;
	if (std::is_same<int8_t, T>::value)
		return PyGLM_TYPE_INFO_INT8;
	if (std::is_same<uint8_t, T>::value)
		return PyGLM_TYPE_INFO_UINT8;
	if (std::is_same<int16_t, T>::value)
		return PyGLM_TYPE_INFO_INT16;
	if (std::is_same<uint16_t, T>::value)
		return PyGLM_TYPE_INFO_UINT16;
	if (std::is_same<int64_t, T>::value)
		return PyGLM_TYPE_INFO_INT64;
	if (std::is_same<uint64_t, T>::value)
		return PyGLM_TYPE_INFO_UINT64;
	if (std::is_same<bool, T>::value)
		return PyGLM_TYPE_INFO_BOOL;

	return PyGLM_TYPE_INFO_UNKNOWN;
}

struct shape_helper {
	PyObject_HEAD
		uint8_t shape;
};

// type definitions
struct type_helper {
	PyObject_HEAD
		uint8_t info;
};

template<int L, typename T>
struct vec {
	PyObject_HEAD
		uint8_t info;
	glm::vec<L, T> super_type;
};

template<int L, typename T>
struct vecIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	vec<L, T>* sequence;
};

struct mvec_helper {
	PyObject_HEAD
		uint8_t info;
	void* super_type;
	PyObject* master;
};

template<int L, typename T>
struct mvec {
	PyObject_HEAD
		uint8_t info;
	glm::vec<L, T>* super_type;
	PyObject* master;
};

template<int L, typename T>
struct mvecIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	mvec<L, T>* sequence;
};

template<int C, int R, typename T>
struct mat {
	PyObject_HEAD
		uint8_t info;
	glm::mat<C, R, T> super_type;
};

template<int C, int R, typename T>
struct matIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	mat<C, R, T>* sequence;
};

template<typename T>
struct qua {
	PyObject_HEAD
		uint8_t info;
	glm::qua<T> super_type;
};

template<typename T>
struct quaIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	qua<T>* sequence;
};