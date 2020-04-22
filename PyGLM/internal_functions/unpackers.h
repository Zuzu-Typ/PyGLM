#pragma once

#include "../compiler_setup.h"

#include "type_getters/all.h"

#include "helper_macros.h"

#include "type_checkers.h"

template<typename T>
static bool unpack_vec(PyObject* value, glm::vec<1, T>& out) {
	if (PyObject_TypeCheck(value, UNBRACKET(PyGLM_VEC_TYPE<1, T>()))) {
		out = ((vec<1, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	if (PyObject_CheckBuffer(value)) {
		Py_buffer view;
		if (PyObject_GetBuffer(value, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (view.ndim != 1 || ((view.shape[0] != 1 || !get_view_format_equal<T>(view.format)) && (view.shape[0] != 1 * sizeof(T) || view.format[0] != 'B')))) {
			PyBuffer_Release(&view);
		}
		else {
			memcpy(&out.x, view.buf, sizeof(out));
			return true;
		}
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 1) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);


			Py_DECREF(value_iter);


			if (value0 == NULL || !PyGLM_Number_Check(value0)) {

				Py_XDECREF(value0);

				return false;
			}

			T value0_as_T = PyGLM_Number_FromPyObject<T>(value0);

			out = glm::vec<1, T>(value0_as_T);


			Py_DECREF(value0);

			return true;
		}
	}
#endif
	return false;
}

template<typename T>
static bool unpack_vec(PyObject* value, glm::vec<2, T>& out) {
	if (PyObject_TypeCheck(value, UNBRACKET(PyGLM_VEC_TYPE<2, T>()))) {
		out = ((vec<2, T>*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == PyGLM_MVEC_TYPE<2, T>()) {
		out = *((mvec<2, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	if (PyObject_CheckBuffer(value)) {
		Py_buffer view;
		if (PyObject_GetBuffer(value, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (view.ndim != 1 || ((view.shape[0] != 2 || !get_view_format_equal<T>(view.format)) && (view.shape[0] != 2 * sizeof(T) || view.format[0] != 'B')))) {
			PyBuffer_Release(&view);
		}
		else {
			memcpy(glm::value_ptr(out), view.buf, sizeof(out));
			return true;
		}
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 2) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);
			PyObject* value1 = PyIter_Next(value_iter);


			Py_DECREF(value_iter);


			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1)) {

				Py_XDECREF(value0);
				Py_XDECREF(value1);

				return false;
			}

			T value0_as_T = PyGLM_Number_FromPyObject<T>(value0);
			T value1_as_T = PyGLM_Number_FromPyObject<T>(value1);

			out = glm::vec<2, T>(value0_as_T, value1_as_T);


			Py_DECREF(value0);
			Py_DECREF(value1);

			return true;
		}
	}
#endif
	return false;
}
template<typename T>
static bool unpack_vec(PyObject* value, glm::vec<3, T>& out) {
	if (PyObject_TypeCheck(value, UNBRACKET(PyGLM_VEC_TYPE<3, T>()))) {
		out = ((vec<3, T>*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == PyGLM_MVEC_TYPE<3, T>()) {
		out = *((mvec<3, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	if (PyObject_CheckBuffer(value)) {
		Py_buffer view;
		if (PyObject_GetBuffer(value, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (view.ndim != 1 || ((view.shape[0] != 3 || !get_view_format_equal<T>(view.format)) && (view.shape[0] != 3 * sizeof(T) || view.format[0] != 'B')))) {
			PyBuffer_Release(&view);
		}
		else {
			memcpy(glm::value_ptr(out), view.buf, sizeof(out));
			return true;
		}
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 3) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);
			PyObject* value1 = PyIter_Next(value_iter);
			PyObject* value2 = PyIter_Next(value_iter);


			Py_DECREF(value_iter);


			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2)) {

				Py_XDECREF(value0);
				Py_XDECREF(value1);
				Py_XDECREF(value2);

				return false;
			}

			T value0_as_T = PyGLM_Number_FromPyObject<T>(value0);
			T value1_as_T = PyGLM_Number_FromPyObject<T>(value1);
			T value2_as_T = PyGLM_Number_FromPyObject<T>(value2);

			out = glm::vec<3, T>(value0_as_T, value1_as_T, value2_as_T);


			Py_DECREF(value0);
			Py_DECREF(value1);
			Py_DECREF(value2);

			return true;
		}
	}
#endif
	return false;
}

template<typename T>
static bool unpack_vec(PyObject* value, glm::vec<4, T>& out) {
	if (PyObject_TypeCheck(value, UNBRACKET(PyGLM_VEC_TYPE<4, T>()))) {
		out = ((vec<4, T>*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == PyGLM_MVEC_TYPE<4, T>()) {
		out = *((mvec<4, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	if (PyObject_CheckBuffer(value)) {
		Py_buffer view;
		if (PyObject_GetBuffer(value, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (view.ndim != 1 || ((view.shape[0] != 4 || !get_view_format_equal<T>(view.format)) && (view.shape[0] != 4 * sizeof(T) || view.format[0] != 'B')))) {
			PyBuffer_Release(&view);
		}
		else {
			memcpy(glm::value_ptr(out), view.buf, sizeof(out));
			return true;
		}
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 4) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);
			PyObject* value1 = PyIter_Next(value_iter);
			PyObject* value2 = PyIter_Next(value_iter);
			PyObject* value3 = PyIter_Next(value_iter);


			Py_DECREF(value_iter);


			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2) || value3 == NULL || !PyGLM_Number_Check(value3)) {

				Py_XDECREF(value0);
				Py_XDECREF(value1);
				Py_XDECREF(value2);
				Py_XDECREF(value3);

				return false;
			}

			T value0_as_T = PyGLM_Number_FromPyObject<T>(value0);
			T value1_as_T = PyGLM_Number_FromPyObject<T>(value1);
			T value2_as_T = PyGLM_Number_FromPyObject<T>(value2);
			T value3_as_T = PyGLM_Number_FromPyObject<T>(value3);

			out = glm::vec<4, T>(value0_as_T, value1_as_T, value2_as_T, value3_as_T);


			Py_DECREF(value0);
			Py_DECREF(value1);
			Py_DECREF(value2);
			Py_DECREF(value3);

			return true;
		}
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
	if (PyObject_TypeCheck(value, UNBRACKET(PyGLM_MAT_TYPE<C, R, T>()))) {
		out = ((mat<C, R, T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	if (PyObject_CheckBuffer(value)) {
		Py_buffer view;
		if (PyObject_GetBuffer(value, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (((view.ndim != 2 || view.shape[0] != C || view.shape[1] != R || !get_view_format_equal<T>(view.format)) && (view.ndim != 1 || view.shape[0] != C * R * sizeof(T) || view.format[0] != 'B')))) {
			PyBuffer_Release(&view);
			return false;
		}
		memcpy(glm::value_ptr(out), view.buf, sizeof(out));
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
	if (PyObject_TypeCheck(value, UNBRACKET(PyGLM_QUA_TYPE<T>()))) {
		out = ((qua<T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	if (PyObject_CheckBuffer(value)) {
		Py_buffer view;
		if (PyObject_GetBuffer(value, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (view.ndim != 1 || ((view.shape[0] != 4 || !get_view_format_equal<T>(view.format)) && (view.shape[0] != 4 * sizeof(T) || view.format[0] != 'B')))) {
			PyBuffer_Release(&view);
			return false;
		}
		memcpy(glm::value_ptr(out), view.buf, sizeof(out));
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