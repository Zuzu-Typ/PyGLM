#pragma once

#include "../compiler_setup.h"

#include "type_getters/all.h"

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

template<typename T>
bool unpack_qua(PyObject* value, glm::qua<T>& out) {
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

#define unpack_qua_ref_TEMPLATE(T) template bool unpack_qua(PyObject* value, glm::qua<T>& out)
PyGLM_GENERATE_EXTERN_TEMPLATE_QUA(unpack_qua_ref_TEMPLATE);

template<typename T>
glm::qua<T> unpack_qua(PyObject* value) {
	glm::qua<T> out;
	unpack_qua(value, out);
	return out;
}

#define unpack_qua_TEMPLATE(T) template glm::qua<T> unpack_qua(PyObject* value)
PyGLM_GENERATE_EXTERN_TEMPLATE_QUA(unpack_qua_TEMPLATE);

// cpp
PyGLM_GENERATE_TEMPLATE_DEF_VEC(unpack_vec_ref_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_VEC(unpack_vec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MAT(unpack_mat_ref_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MAT(unpack_mat_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_QUA(unpack_qua_ref_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_QUA(unpack_qua_TEMPLATE);
