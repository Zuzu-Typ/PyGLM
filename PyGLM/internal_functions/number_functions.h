#pragma once

#include "../compiler_setup.h"

bool PyGLM_Number_Check(PyObject* arg) {
	if (PyFloat_Check(arg) || PyLong_Check(arg) || PyBool_Check(arg)) {
		return true;
	}
	if (arg->ob_type->tp_as_number != NULL && arg->ob_type->tp_as_number->nb_float != NULL) {
		PyObject* temp = PyNumber_Float(arg);
		if (temp != NULL) {
			Py_DECREF(temp);
			return true;
		}
		PyErr_Clear();
	}
	return false;
}

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
	PyObject* arg_as_float = PyNumber_Float(arg);
	double out = PyFloat_AS_DOUBLE(arg_as_float);
	Py_DECREF(arg_as_float);
	return out;
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
	PyObject* arg_as_long = PyNumber_Long(arg);
	long out = PyLong_AS_LONG(arg_as_long);
	Py_DECREF(arg_as_long);
	return out;
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
	PyObject* arg_as_long = PyNumber_Long(arg);
	unsigned long out = PyLong_AsUnsignedLong(arg_as_long);
	Py_DECREF(arg_as_long);
	return out;
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
	PyObject* arg_as_long = PyNumber_Long(arg);
	long long out = PyLong_AsLongLong(arg_as_long);
	Py_DECREF(arg_as_long);
	return out;
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
	PyObject* arg_as_long = PyNumber_Long(arg);
	unsigned long long out = PyLong_AsUnsignedLongLong(arg_as_long);
	Py_DECREF(arg_as_long);
	return out;
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
	PyObject* arg_as_bool = PyNumber_Long(arg);
	bool out = (bool)PyLong_AS_LONG(arg_as_bool);
	Py_DECREF(arg_as_bool);
	return out;
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
	PyObject* arg_as_float = PyNumber_Float(arg);
	float out = (float)PyFloat_AS_DOUBLE(arg_as_float);
	Py_DECREF(arg_as_float);
	return out;
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