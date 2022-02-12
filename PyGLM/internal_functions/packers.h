#pragma once

#include "../compiler_setup.h"

#include "type_getters/all.h"

#include "number_functions.h"

#include "template_generator_macros.h"

template<int L, typename T>
PyObject*
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

#define pack_vec_TEMPLATE(L, T) template PyObject* pack_vec(glm::vec<L, T> value)
PyGLM_GENERATE_EXTERN_TEMPLATE_VEC(pack_vec_TEMPLATE);

template<int L, typename T>
PyObject*
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

#define pack_mvec_TEMPLATE(L, T) template PyObject* pack_mvec(glm::vec<L, T>* value, PyObject* master)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(pack_mvec_TEMPLATE);

template<int C, int R, typename T>
PyObject*
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

#define pack_mat_TEMPLATE(C, R, T) template PyObject* pack_mat(glm::mat<C, R, T> value)
PyGLM_GENERATE_EXTERN_TEMPLATE_MAT(pack_mat_TEMPLATE);

template<typename T>
PyObject*
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

#define pack_qua_TEMPLATE(T) template PyObject* pack_qua(glm::qua<T> value)
PyGLM_GENERATE_EXTERN_TEMPLATE_QUA(pack_qua_TEMPLATE);

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


// cpp
PyGLM_GENERATE_TEMPLATE_DEF_VEC(pack_vec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(pack_mvec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MAT(pack_mat_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_QUA(pack_qua_TEMPLATE);
