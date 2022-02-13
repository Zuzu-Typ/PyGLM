#pragma once

#include "../compiler_setup.h"

#include "type_getters/vec.h"

#include "template_generator_macros.h"

#include "../types/vec.hpp"

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
inline PyObject*
pack(glm::vec<L, T> value) {
	return pack_vec(value);
}
