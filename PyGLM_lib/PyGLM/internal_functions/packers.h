#pragma once

#include "../compiler_setup.h"

#include "type_getters/all.h"

#include "number_functions.h"

template<int L, typename T>
static PyObject*
pack_vec(glm::vec<L, T> value) {
	PyTypeObject* vecType = PyGLM_VEC_TYPE<L, T>();
	vec<L, T>* out = (vec<L, T>*)vecType->tp_alloc(vecType, 0);

	if (out != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = L | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		//out->info = info;
		out->super_type = value;
	}

	return (PyObject*)out;
}

template<int L, typename T>
static PyObject*
pack_mvec(glm::vec<L, T>* value, PyObject* master) {
	PyTypeObject* mvecType = PyGLM_MVEC_TYPE<L, T>();
	mvec<L, T>* out = (mvec<L, T>*)mvecType->tp_alloc(mvecType, 0);

	if (out != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = L | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		//out->info = info;
		out->super_type = value;
		out->master = master;
		Py_INCREF(master);
	}

	return (PyObject*)out;
}

template<int C, int R, typename T>
static PyObject*
pack_mat(glm::mat<C, R, T> value) {
	PyTypeObject* matType = PyGLM_MAT_TYPE<C, R, T>();
	mat<C, R, T>* out = (mat<C, R, T>*)matType->tp_alloc(matType, 0);

	if (out != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = (uint8_t)((C << PyGLM_TYPE_INFO_MAT_SHAPE1_OFFSET) | (R << PyGLM_TYPE_INFO_MAT_SHAPE2_OFFSET) | (info_type << PyGLM_TYPE_INFO_MAT_TYPE_OFFSET));
		//out->info = info;
		out->super_type = value;
	}

	return (PyObject*)out;
}

template<typename T>
static PyObject*
pack_qua(glm::qua<T> value) {
	PyTypeObject* quaType = PyGLM_QUA_TYPE<T>();
	qua<T>* out = (qua<T>*)quaType->tp_alloc(quaType, 0);

	if (out != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = 4 | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		//out->info = info;
		out->super_type = value;
	}

	return (PyObject*)out;
}

template<typename T>
static inline PyObject*
pack(T value) {
	return PyGLM_PyObject_FromNumber(value);
}

template<int L, typename T>
static inline PyObject*
pack(glm::vec<L, T> value) {
	return pack_vec(value);
}

template<int C, int R, typename T>
static inline PyObject*
pack(glm::mat<C, R, T> value) {
	return pack_mat(value);
}

template<typename T>
static inline PyObject*
pack(glm::qua<T> value) {
	return pack_qua(value);
}