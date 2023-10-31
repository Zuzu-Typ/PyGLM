#pragma once

#include "../compiler_setup.h"

static PyObject* ctypes_float;
static PyObject* ctypes_double;
static PyObject* ctypes_int64;
static PyObject* ctypes_int32;
static PyObject* ctypes_int16;
static PyObject* ctypes_int8;
static PyObject* ctypes_uint64;
static PyObject* ctypes_uint32;
static PyObject* ctypes_uint16;
static PyObject* ctypes_uint8;
static PyObject* ctypes_bool;

static destructor ctypes_dealloc;

static PyObject* ctypes_void_p = NULL;
static PyObject* ctypes_cast = NULL;

#if defined(_M_IX86) || defined(__i386__)
static PyObject* PyGLM_CtypesVoidP_FromVoidP(void* p) {
	PyObject* argList = Py_BuildValue("(K)", (unsigned long)p);
	PyObject* out = PyObject_CallObject(ctypes_void_p, argList);
	Py_DECREF(argList);
	return out;
}
static unsigned long PyGLM_UnsignedLongLong_FromCtypesP(PyObject* ptr) {
	PyObject* ptr_as_c_void_p = PyObject_CallFunctionObjArgs(ctypes_cast, ptr, ctypes_void_p, NULL);
	PyObject* ptr_value = PyObject_GetAttrString(ptr_as_c_void_p, "value");
	unsigned long out = PyLong_AsUnsignedLong(ptr_value);
	Py_DECREF(ptr_value);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
#else
static PyObject* PyGLM_CtypesVoidP_FromVoidP(void* p) {
	PyObject* argList = Py_BuildValue("(K)", (unsigned long long)p);
	PyObject* out = PyObject_CallObject(ctypes_void_p, argList);
	Py_DECREF(argList);
	return out;
}
static unsigned long long PyGLM_UnsignedLongLong_FromCtypesP(PyObject* ptr) {
	PyObject* ptr_as_c_void_p = PyObject_CallFunctionObjArgs(ctypes_cast, ptr, ctypes_void_p, NULL);
	PyObject* ptr_value = PyObject_GetAttrString(ptr_as_c_void_p, "value");
	unsigned long long out = PyLong_AsUnsignedLongLong(ptr_value);
	Py_DECREF(ptr_value);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
#endif

#if !(PyGLM_BUILD & PyGLM_NO_FUNCTIONS)

static PyObject* ctypes_float_p = NULL;
static PyObject* ctypes_double_p = NULL;
static PyObject* ctypes_int64_p = NULL;
static PyObject* ctypes_int32_p = NULL;
static PyObject* ctypes_int16_p = NULL;
static PyObject* ctypes_int8_p = NULL;
static PyObject* ctypes_uint64_p = NULL;
static PyObject* ctypes_uint32_p = NULL;
static PyObject* ctypes_uint16_p = NULL;
static PyObject* ctypes_uint8_p = NULL;
static PyObject* ctypes_bool_p = NULL;







static PyObject* PyGLM_ToCtypesP(float* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_float_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(double* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_double_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::int64* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_int64_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::int32* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_int32_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::int16* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_int16_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::int8* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_int8_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::uint64* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_uint64_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::uint32* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_uint32_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::uint16* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_uint16_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(glm::uint8* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_uint8_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(bool* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP((void*)ptr);
	PyObject* out = PyObject_CallFunctionObjArgs(ctypes_cast, ptr_as_c_void_p, ctypes_bool_p, NULL);
	Py_DECREF(ptr_as_c_void_p);
	return out;
}
static PyObject* PyGLM_ToCtypesP(void* ptr) {
	PyObject* ptr_as_c_void_p = PyGLM_CtypesVoidP_FromVoidP(ptr);
	return ptr_as_c_void_p;
}
#endif