#pragma once

#include "../compiler_setup.h"

#include "type_getters/qua.h"

#include "template_generator_macros.h"

#include "../types/qua.hpp"

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
inline PyObject*
pack(glm::qua<T> value) {
	return pack_qua(value);
}
