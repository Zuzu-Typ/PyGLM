#pragma once

#include "../compiler_setup.h"

#include "type_getters/mat.h"

#include "helper_macros.h"

#include "type_checkers.h"

#include "template_generator_macros.h"

template<int C, int R, typename T>
bool unpack_mat(PyObject* value, glm::mat<C, R, T>& out) {
	if (PyObject_TypeCheck(value, (UNBRACKET(PyGLM_MAT_TYPE<C, R, T>())))) {
		out = ((mat<C, R, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	PyGLM_PTI_Init3(value, (get_mat_PTI_info<C, R, T>()));
	if (PyGLM_Mat_PTI_Check3(C, R, T, value)) {
		out = PyGLM_Mat_PTI_Get3(C, R, T, value);
		return true;
	}
#endif
	return false;
}

#define unpack_mat_ref_TEMPLATE(C, R, T) template bool unpack_mat(PyObject* value, glm::mat<C, R, T>& out)
PyGLM_GENERATE_EXTERN_TEMPLATE_MAT(unpack_mat_ref_TEMPLATE);

#define unpack_matN(C, R, T, o, N) (sourceType ## N == NORMAL) ? (((UNBRACKET(mat<C,R,T>*)) o)->super_type) : PTI ## N.getMat<C,R,T>()

template<int C, int R, typename T>
glm::mat<C, R, T> unpack_mat(PyObject* value) {
	glm::mat<C, R, T> out;
	unpack_mat(value, out);
	return out;
}

#define unpack_mat_TEMPLATE(C, R, T) template glm::mat<C, R, T> unpack_mat(PyObject* value)
PyGLM_GENERATE_EXTERN_TEMPLATE_MAT(unpack_mat_TEMPLATE);
