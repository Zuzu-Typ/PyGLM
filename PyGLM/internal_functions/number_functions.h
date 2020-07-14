#pragma once

#include "../compiler_setup.h"

PyObject* PyGLM_GetNumber(PyObject* arg) {
	if (arg->ob_type->tp_as_number->nb_float != NULL) {
		return PyNumber_Float(arg);
	}
	if (arg->ob_type->tp_as_number->nb_int != NULL) {
		return PyNumber_Long(arg);
	}
	if (arg->ob_type->tp_as_number->nb_index != NULL) {
		return PyNumber_Index(arg);
	}
	PyErr_SetString(PyExc_Exception, "invalid getnumber request (this should not occur)");
	return NULL;
}

bool PyGLM_TestNumber(PyObject* arg) {
	PyObject* num = PyGLM_GetNumber(arg);

	if (num == NULL) {
		PyErr_Clear();
		return false;
	}
	Py_DECREF(num);
	return true;
}

#define PyGLM_COULD_BE_NUMBER(arg) (Py_TYPE(arg)->tp_as_number != NULL && (arg->ob_type->tp_as_number->nb_index != NULL || arg->ob_type->tp_as_number->nb_int != NULL || arg->ob_type->tp_as_number->nb_float != NULL))

#define PyGLM_Number_Check(arg) (PyFloat_Check(arg) || PyLong_Check(arg) || PyBool_Check(arg) || (PyGLM_COULD_BE_NUMBER(arg) &&PyGLM_TestNumber(arg)))

double PyGLM_Number_AsDouble(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyFloat_AS_DOUBLE(arg);
	}
	if (PyLong_Check(arg)) {
		return PyLong_AsDouble(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.0 : 0.0;
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsDouble(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1.0;
}

long PyGLM_Number_AsLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_AS_LONG(arg);
	}
	if (PyFloat_Check(arg)) {
		return (long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1 : 0;
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsLong(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1l;
}

unsigned long PyGLM_Number_AsUnsignedLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_AsUnsignedLong(arg);
	}
	if (PyFloat_Check(arg)) {
		return (unsigned long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1UL : 0UL;
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsUnsignedLong(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (unsigned long) - 1l;
}

long long PyGLM_Number_AsLongLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_AsLongLong(arg);
	}
	if (PyFloat_Check(arg)) {
		return (long long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1LL : 0LL;
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsLongLong(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1ll;
}

unsigned long long PyGLM_Number_AsUnsignedLongLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_AsUnsignedLongLong(arg);
	}
	if (PyFloat_Check(arg)) {
		return (unsigned long long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1ull : 0ull;
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsUnsignedLongLong(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (unsigned long long)-1ll;
}

bool PyGLM_Number_AsBool(PyObject* arg) {
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? true : false;
	}
	if (PyLong_Check(arg)) {
		return (bool)PyLong_AS_LONG(arg);
	}
	if (PyFloat_Check(arg)) {
		return (bool)PyFloat_AS_DOUBLE(arg);
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsBool(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return false;
}

float PyGLM_Number_AsFloat(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return (float)PyFloat_AS_DOUBLE(arg);
	}
	if (PyLong_Check(arg)) {
		return (float)PyLong_AS_LONG(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.f : 0.f;
	}
	if (PyNumber_Check(arg)) {
		return PyGLM_Number_AsFloat(PyGLM_GetNumber(arg));
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1.0f;
}

template<typename T>
static T PyGLM_Number_FromPyObject(PyObject* value) {
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

template<typename T>
static PyObject* PyGLM_PyObject_FromNumber(T value) {
	if (std::numeric_limits<T>::is_iec559) {
		return PyFloat_FromDouble(static_cast<double>(value));
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
	else if (std::is_same<T, bool>::value) {
		if (value) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	return NULL;
}