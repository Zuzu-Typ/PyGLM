#pragma once

#include "../compiler_setup.h"

#include "type_getters/mvec.h"

#include "template_generator_macros.h"

#include "../types/mvec.hpp"

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
