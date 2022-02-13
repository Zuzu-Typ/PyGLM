#pragma once

#include "../compiler_setup.h"

#include "type_getters/vec.h"
#include "type_getters/mvec.h"

#include "helper_macros.h"

#include "type_checkers.h"

#include "template_generator_macros.h"

template<int L, typename T>
bool unpack_vec(PyObject* value, glm::vec<L, T>& out) {
	if (PyObject_TypeCheck(value, (UNBRACKET(PyGLM_VEC_TYPE<L, T>())))) {
		out = ((vec<L, T>*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == PyGLM_MVEC_TYPE<L, T>()) {
		out = *((mvec<L, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	PyGLM_PTI_Init3(value, (get_vec_PTI_info<L, T>()));
	if (PyGLM_Vec_PTI_Check3(L, T, value)) {
		out = PyGLM_Vec_PTI_Get3(L, T, value);
		return true;
	}
#endif
	return false;
}

#define unpack_vec_ref_TEMPLATE(L, T) template bool unpack_vec(PyObject* value, glm::vec<L, T>& out)
PyGLM_GENERATE_EXTERN_TEMPLATE_VEC(unpack_vec_ref_TEMPLATE);

template<int L, typename T>
glm::vec<L, T> unpack_vec(PyObject* value) {
	glm::vec<L, T> out;
	unpack_vec(value, out);
	return out;
}

#define unpack_vec_TEMPLATE(L, T) template glm::vec<L, T> unpack_vec(PyObject* value)
PyGLM_GENERATE_EXTERN_TEMPLATE_VEC(unpack_vec_TEMPLATE);
