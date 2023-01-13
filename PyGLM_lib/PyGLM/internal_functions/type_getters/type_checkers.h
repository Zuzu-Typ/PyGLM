#pragma once

#include "../compiler_setup.h"

#define _SUB_PyGLM_GET_TYPE(o) ((o->ob_type->tp_dealloc == NULL) ? PyGLM_TYPE_UNKNOWN : (o->ob_type->tp_dealloc == (destructor)vec_dealloc) ? PyGLM_TYPE_VEC : (o->ob_type->tp_dealloc == (destructor)mat_dealloc) ? PyGLM_TYPE_MAT : (o->ob_type->tp_dealloc == (destructor)qua_dealloc) ? PyGLM_TYPE_QUA : (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) ? PyGLM_TYPE_VEC : PyGLM_TYPE_UNKNOWN)
#define PyGLM_GET_TYPE(o) _SUB_PyGLM_GET_TYPE(((PyObject*)o))

#define PyGLM_VEC_SHAPE_CHECK(o, L) (((shape_helper*)o)->shape == L)
#define PyGLM_MAT_SHAPE_CHECK(o, C, R) (((shape_helper*)o)->shape == (C + (R << 3)))

#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
bool PyGLM_Vec1i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 1 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 1) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);

	Py_DECREF(iterator);

	if (value0 == NULL || !PyGLM_Number_Check(value0)) {
		Py_XDECREF(value0);

		return false;
	}
	Py_DECREF(value0);

	return true;
}

bool PyGLM_Vec2i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 2 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 1))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 2) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);
	PyObject* value1 = PyIter_Next(iterator);

	Py_DECREF(iterator);

	if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1)) {
		Py_XDECREF(value0);
		Py_XDECREF(value1);

		return false;
	}
	Py_DECREF(value0);
	Py_DECREF(value1);

	return true;
}

bool PyGLM_Vec3i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 3 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 1)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 2))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 3) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);
	PyObject* value1 = PyIter_Next(iterator);
	PyObject* value2 = PyIter_Next(iterator);


	Py_DECREF(iterator);


	if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2)) {

		Py_XDECREF(value0);
		Py_XDECREF(value1);
		Py_XDECREF(value2);

		return false;
	}
	Py_DECREF(value0);
	Py_DECREF(value1);
	Py_DECREF(value2);

	return true;
}

bool PyGLM_Vec4i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 4 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 1)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 2)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 3))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 4) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);
	PyObject* value1 = PyIter_Next(iterator);
	PyObject* value2 = PyIter_Next(iterator);
	PyObject* value3 = PyIter_Next(iterator);


	Py_DECREF(iterator);


	if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2) || value3 == NULL || !PyGLM_Number_Check(value3)) {

		Py_XDECREF(value0);
		Py_XDECREF(value1);
		Py_XDECREF(value2);
		Py_XDECREF(value3);

		return false;
	}
	Py_DECREF(value0);
	Py_DECREF(value1);
	Py_DECREF(value2);
	Py_DECREF(value3);

	return true;
}

#define PyGLM_Veci_Check(L, o) ((L == 1) ? PyGLM_Vec1i_Check(o) : (L == 2) ? PyGLM_Vec2i_Check(o) : (L == 3) ? PyGLM_Vec3i_Check(o) : PyGLM_Vec4i_Check(o))

template<typename T>
static bool get_view_format_equal(char* value) {
	char& v_char = value[0];
	if (v_char == 'f') {
		return std::is_same<T, float>::value;
	}
	if (v_char == 'd') {
		return std::is_same<T, double>::value;
	}
	if (v_char == 'c') {
		return std::is_same<T, std::int8_t>::value;
	}
	if (v_char == 'b') {
		return std::is_same<T, std::uint8_t>::value;
	}
	if (v_char == 'h') {
		return std::is_same<T, std::int16_t>::value;
	}
	if (v_char == 'H') {
		return std::is_same<T, std::uint16_t>::value;
	}
	if (v_char == 'i') {
		return std::is_same<T, std::int32_t>::value;
	}
	if (v_char == 'I') {
		return std::is_same<T, std::uint32_t>::value;
	}
	if (v_char == 'L') {
		return std::is_same<T, std::int64_t>::value;
	}
	if (v_char == 'K') {
		return std::is_same<T, std::uint64_t>::value;
	}
	if (v_char == 'p') {
		return std::is_same<T, bool>::value;
	}
	return false;
}

template<typename T>
static bool PyGLM_Matb_Check(int C, int R, PyObject* o) {
	if (!PyObject_CheckBuffer(o)) {
		return false;
	}
	Py_buffer view;
	if (PyObject_GetBuffer(o, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (((view.ndim != 2 || view.shape[0] != static_cast<Py_ssize_t>(C) || view.shape[1] != static_cast<Py_ssize_t>(R) || !get_view_format_equal<T>(view.format)) && (view.ndim != 1 || view.shape[0] != static_cast<Py_ssize_t>(C * R * sizeof(T)) || view.format[0] != 'B')))) {
		PyBuffer_Release(&view);
		return false;
	}
	PyBuffer_Release(&view);
	return true;
}

template<typename T>
static bool PyGLM_Vecb_Check(int L, PyObject* o) {
	if (!PyObject_CheckBuffer(o)) {
		return false;
	}
	Py_buffer view;
	if (PyObject_GetBuffer(o, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1 || (view.ndim != 1 || ((view.shape[0] != static_cast<Py_ssize_t>(L) || !get_view_format_equal<T>(view.format)) && (view.shape[0] != static_cast<Py_ssize_t>(L * sizeof(T)) || view.format[0] != 'B')))) {
		PyBuffer_Release(&view);
		return false;
	}
	PyBuffer_Release(&view);
	return true;
}

#define PyGLM_Vec_Check(L, T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_VEC_TYPE<L, T>())) || Py_TYPE(o) == PyGLM_MVEC_TYPE<L, T>() || ((PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN) && (PyGLM_Vecb_Check<T>(L, (PyObject*)o))))

#define PyGLM_Vec_Check_IgnoreType(L, T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_VEC_TYPE<L, T>())) || Py_TYPE(o) == PyGLM_MVEC_TYPE<L, T>() || ((PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN || (PyGLM_GET_TYPE(o) == PyGLM_TYPE_VEC && PyGLM_VEC_SHAPE_CHECK(o, L))) && ((PyGLM_Vecb_Check<T>(L, (PyObject*)o)) || (PyGLM_Veci_Check(L, o)))))

#define PyGLM_Qua_Check(T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_QUA_TYPE<T>())) || ((PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN || (PyGLM_GET_TYPE(o) == PyGLM_TYPE_QUA)) && PyGLM_Vecb_Check<T>(4, (PyObject*)o)))

#define PyGLM_Mat_Check(C, R, T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_MAT_TYPE<C, R, T>())) || ((PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN || (PyGLM_GET_TYPE(o) == PyGLM_TYPE_MAT && PyGLM_MAT_SHAPE_CHECK(o, C, R))) && PyGLM_Matb_Check<T>(C, R, (PyObject*)o)))

#else
#define PyGLM_Vec_Check(L, T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_VEC_TYPE<L, T>())) || Py_TYPE(o) == PyGLM_MVEC_TYPE<L, T>())

#define PyGLM_Vec_Check_IgnoreType PyGLM_Vec_Check

#define PyGLM_Qua_Check(T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_QUA_TYPE<T>())))

#define PyGLM_Mat_Check(C, R, T, o) PyObject_TypeCheck(o, UNBRACKET (PyGLM_MAT_TYPE<C, R, T>()))
#endif