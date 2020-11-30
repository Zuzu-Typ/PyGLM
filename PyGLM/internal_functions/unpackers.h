#pragma once

#include "../compiler_setup.h"

#include "type_getters/all.h"

#include "helper_macros.h"

#include "type_checkers.h"

template<int L, typename T>
static bool unpack_vec(PyObject* value, glm::vec<L, T>& out) {
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

template<int L, typename T>
static glm::vec<L, T> unpack_vec(PyObject* value) {
	glm::vec<L, T> out;
	unpack_vec(value, out);
	return out;
}

template<int C, int R, typename T>
static bool unpack_mat(PyObject* value, glm::mat<C, R, T>& out) {
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

#define unpack_matN(C, R, T, o, N) (sourceType ## N == NORMAL) ? (((UNBRACKET(mat<C,R,T>*)) o)->super_type) : PTI ## N.getMat<C,R,T>()

template<int C, int R, typename T>
static glm::mat<C, R, T> unpack_mat(PyObject* value) {
	glm::mat<C, R, T> out;
	unpack_mat(value, out);
	return out;
}

template<typename T>
static bool unpack_qua(PyObject* value, glm::qua<T>& out) {
	if (PyObject_TypeCheck(value, (UNBRACKET(PyGLM_QUA_TYPE<T>())))) {
		out = ((qua<T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	PyGLM_PTI_Init3(value, (get_qua_PTI_info<T>()));
	if (PyGLM_Qua_PTI_Check3(T, value)) {
		out = PyGLM_Qua_PTI_Get3(T, value);
		return true;
	}
#endif
	return false;
}

template<typename T>
static glm::qua<T> unpack_qua(PyObject* value) {
	glm::qua<T> out;
	unpack_qua(value, out);
	return out;
}