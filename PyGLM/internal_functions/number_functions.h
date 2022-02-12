#pragma once

#include "../compiler_setup.h"
#include "template_generator_macros.h"
#include "warnings.h"

#define PyGLM_COULD_BE_NUMBER(arg) (Py_TYPE(arg)->tp_as_number != NULL && (arg->ob_type->tp_as_number->nb_index != NULL || arg->ob_type->tp_as_number->nb_int != NULL || arg->ob_type->tp_as_number->nb_float != NULL))

#define PyGLM_Number_Check(arg) (PyFloat_Check(arg) || PyLong_Check(arg) || PyBool_Check(arg) || (PyGLM_COULD_BE_NUMBER(arg) && PyGLM_TestNumber(arg)))

PyObject* PyGLM_GetNumber(PyObject* arg);

bool PyGLM_TestNumber(PyObject* arg);

unsigned long PyLong_AsUnsignedLongAndOverflow(PyObject* arg, int* overflow);

unsigned long long PyLong_AsUnsignedLongLongAndOverflow(PyObject* arg, int* overflow);

int PyLong_Sign(PyObject* arg);

double PyGLM_Number_AsDouble(PyObject* arg);

long PyGLM_Number_AsLong(PyObject* arg);

unsigned long PyGLM_Number_AsUnsignedLong(PyObject* arg);

long long PyGLM_Number_AsLongLong(PyObject* arg);

unsigned long long PyGLM_Number_AsUnsignedLongLong(PyObject* arg);

bool PyGLM_Number_AsBool(PyObject* arg);

float PyGLM_Number_AsFloat(PyObject* arg);

template<typename T>
T _PyGLM_Long_As_Number_No_Error(PyObject* arg) {
	if (std::numeric_limits<T>::is_iec559) {
		int overflow;
		long long ll;
		ll = PyLong_AsLongLongAndOverflow(arg, &overflow);
		if (overflow == 1) {
			return static_cast<T>(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg));
		}
		else if (overflow == -1) {
			return static_cast<T>(_PyGLM_Long_As_Number_No_Error<long long>(arg));
		}
		return static_cast<T>(ll);
	}
	if (std::is_same<T, long>::value) {
		int overflow;
		long l = PyLong_AsLongAndOverflow(arg, &overflow);
		if (overflow) {
			PyGLM_WARN(PyGLM_OVERFLOW_WARNING, "Integer overflow (or underflow) occured.");
		}
		else {
			return static_cast<T>(l);
		}
	}
	if (std::is_same<T, unsigned long>::value) {
		unsigned long ul = PyLong_AsUnsignedLong(arg);
		if (PyErr_Occurred()) {
			PyErr_Clear();
			PyGLM_WARN(PyGLM_OVERFLOW_WARNING, "Integer overflow (or underflow) occured.");
		}
		else {
			return static_cast<T>(ul);
		}
	}
	if (std::is_same<T, long long>::value) {
		int overflow;
		long long ll = PyLong_AsLongLongAndOverflow(arg, &overflow);
		if (overflow) {
			PyGLM_WARN(PyGLM_OVERFLOW_WARNING, "Integer overflow (or underflow) occured.");
		}
		else {
			return static_cast<T>(ll);
		}
	}
	if (std::is_same<T, unsigned long>::value) {
		unsigned long long ull = PyLong_AsUnsignedLongLong(arg);
		if (PyErr_Occurred()) {
			PyErr_Clear();
			PyGLM_WARN(PyGLM_OVERFLOW_WARNING, "Integer overflow (or underflow) occured.");
		}
		else {
			return static_cast<T>(ull);
		}
	}
	return static_cast<T>(PyLong_AsUnsignedLongLongMask(arg));
}
#define _PyGLM_Long_As_Number_No_Error_TEMPLATE(T) template T _PyGLM_Long_As_Number_No_Error(PyObject* arg)
PyGLM_GENERATE_EXTERN_TEMPLATE_NUM(_PyGLM_Long_As_Number_No_Error_TEMPLATE);

template<typename T>
T PyGLM_Number_FromPyObject(PyObject* value) {
	if (std::numeric_limits<T>::is_iec559) {
		if (std::is_same<T, double>::value) {
			return (T)PyGLM_Number_AsDouble(value);
		}
		return static_cast<T>(PyGLM_Number_AsFloat(value));
	}
	else if (std::numeric_limits<T>::is_integer) {
		if (std::is_same<T, long long>::value) {
			return (T)PyGLM_Number_AsLongLong(value);
		}
		if (std::is_same<T, unsigned long long>::value) {
			return (T)PyGLM_Number_AsUnsignedLongLong(value);
		}
		if (std::is_same<T, unsigned long>::value || !std::is_signed<T>::value) {
			return (T)PyGLM_Number_AsUnsignedLong(value);
		}
		return static_cast<T>(PyGLM_Number_AsLong(value));
	}
	else if (std::is_same<T, bool>::value) {
		return (T)PyGLM_Number_AsBool(value);
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (T)0;
}
#define PyGLM_Number_FromPyObject_TEMPLATE(T) template T PyGLM_Number_FromPyObject<T>(PyObject* value)
PyGLM_GENERATE_EXTERN_TEMPLATE_NUM(PyGLM_Number_FromPyObject_TEMPLATE);

template<typename T>
PyObject* PyGLM_PyObject_FromNumber(T value) {
	if (std::numeric_limits<T>::is_iec559) {
		return PyFloat_FromDouble(static_cast<double>(value));
	}
	else if (std::is_same<T, bool>::value) {
		if (value) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	else if (std::numeric_limits<T>::is_integer) {
		if (std::is_same<T, long long>::value) {
			return PyLong_FromLongLong((long long)value);
		}
		if (std::is_same<T, unsigned long long>::value) {
			return PyLong_FromUnsignedLongLong((unsigned long long)value);
		}
		if (std::is_same<T, unsigned long>::value || !std::is_signed<T>::value) {
			return PyLong_FromUnsignedLong((unsigned long)value);
		}
		return PyLong_FromLong((long)value);
	}
	return NULL;
}
#define PyGLM_PyObject_FromNumber_TEMPLATE(T) template PyObject* PyGLM_PyObject_FromNumber(T value)
PyGLM_GENERATE_EXTERN_TEMPLATE_NUM(PyGLM_PyObject_FromNumber_TEMPLATE);
