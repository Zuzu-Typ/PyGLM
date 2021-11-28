#pragma once

#include "../compiler_setup.h"

unsigned long PyLong_AsUnsignedLongAndOverflow(PyObject* arg, int* overflow) {
	unsigned long out = PyLong_AsUnsignedLong(arg);
	if (PyErr_Occurred()) {
		PyErr_Clear();
		*overflow = 1;
	}
	else {
		*overflow = 0;
	}
	return out;
}

unsigned long long PyLong_AsUnsignedLongLongAndOverflow(PyObject* arg, int* overflow) {
	unsigned long long out = PyLong_AsUnsignedLongLong(arg);
	if (PyErr_Occurred()) {
		PyErr_Clear();
		*overflow = 1;
	}
	else {
		*overflow = 0;
	}
	return out;
}

int PyLong_Sign(PyObject* arg) {
	int overflow;
	long l = PyLong_AsLongAndOverflow(arg, &overflow);
	if (overflow) {
		return overflow;
	}
	return glm::sign(l);
}

#define PyGLM_Number_Check(arg) (PyFloat_Check(arg) || PyLong_Check(arg) || PyBool_Check(arg))

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

double PyGLM_Number_AsDouble(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyFloat_AS_DOUBLE(arg);
	}
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<double>(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.0 : 0.0;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1.0;
}

long PyGLM_Number_AsLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<long>(arg);
	}
	if (PyFloat_Check(arg)) {
		return (long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1 : 0;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1l;
}

unsigned long PyGLM_Number_AsUnsignedLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<unsigned long>(arg);
	}
	if (PyFloat_Check(arg)) {
		return (unsigned long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1UL : 0UL;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (unsigned long) - 1l;
}

long long PyGLM_Number_AsLongLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<long long>(arg);
	}
	if (PyFloat_Check(arg)) {
		return (long long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1LL : 0LL;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1ll;
}

unsigned long long PyGLM_Number_AsUnsignedLongLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<unsigned long long>(arg);
	}
	if (PyFloat_Check(arg)) {
		return (unsigned long long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1ull : 0ull;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (unsigned long long)-1ll;
}

bool PyGLM_Number_AsBool(PyObject* arg) {
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? true : false;
	}
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<bool>(arg);
	}
	if (PyFloat_Check(arg)) {
		return (bool)PyFloat_AS_DOUBLE(arg);
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return false;
}

float PyGLM_Number_AsFloat(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return (float)PyFloat_AS_DOUBLE(arg);
	}
	if (PyLong_Check(arg)) {
		return _PyGLM_Long_As_Number_No_Error<float>(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.f : 0.f;
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