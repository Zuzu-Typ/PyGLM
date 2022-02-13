#pragma once

#include "../compiler_setup.h"

#include "type_getters/mat.h"

#include "template_generator_macros.h"

#include "../types/mat.hpp"

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

template<int C, int R, typename T>
inline PyObject*
pack(glm::mat<C, R, T> value) {
	return pack_mat(value);
}
