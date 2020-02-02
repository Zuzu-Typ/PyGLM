#pragma once

#include "../imports.h"

// type identifiers
#define PyGLM_TYPE_UNKNOWN 0
#define PyGLM_TYPE_VEC 1
#define PyGLM_TYPE_MAT 2
#define PyGLM_TYPE_QUA 3

// type definitions
struct shape_helper {
	PyObject_HEAD
		uint8_t shape;
};

template<int L, typename T>
struct vec {
	PyObject_HEAD
		uint8_t shape;
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
		uint8_t shape;
	void* super_type;
	PyObject* master;
};

template<int L, typename T>
struct mvec {
	PyObject_HEAD
		uint8_t shape;
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
		uint8_t shape;
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
		glm::qua<T> super_type;
};

template<typename T>
struct quaIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	qua<T>* sequence;
};