
#include "number_functions.h"

#include "warnings.h"

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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		double d = PyGLM_Number_AsDouble(num);
		Py_DECREF(num);
		return d;
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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		long l = PyGLM_Number_AsLong(num);
		Py_DECREF(num);
		return l;
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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		unsigned long l = PyGLM_Number_AsUnsignedLong(num);
		Py_DECREF(num);
		return l;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (unsigned long)-1l;
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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		long long l = PyGLM_Number_AsLongLong(num);
		Py_DECREF(num);
		return l;
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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		unsigned long long l = PyGLM_Number_AsUnsignedLongLong(num);
		Py_DECREF(num);
		return l;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return (unsigned long long) - 1ll;
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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		bool b = PyGLM_Number_AsBool(num);
		Py_DECREF(num);
		return b;
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
	if (PyNumber_Check(arg)) {
		PyObject* num = PyGLM_GetNumber(arg);
		float f = PyGLM_Number_AsFloat(num);
		Py_DECREF(num);
		return f;
	}
	PyErr_SetString(PyExc_Exception, "supplied argument is not a number (this should not occur)");
	return -1.0f;
}

PyGLM_GENERATE_TEMPLATE_DEF_NUM(_PyGLM_Long_As_Number_No_Error_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_NUM(PyGLM_Number_FromPyObject_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_NUM(PyGLM_PyObject_FromNumber_TEMPLATE);
