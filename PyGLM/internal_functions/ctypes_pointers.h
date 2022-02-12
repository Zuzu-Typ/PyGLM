#pragma once

#include "../compiler_setup.h"

extern PyObject* ctypes_float;
extern PyObject* ctypes_double;
extern PyObject* ctypes_int64;
extern PyObject* ctypes_int32;
extern PyObject* ctypes_int16;
extern PyObject* ctypes_int8;
extern PyObject* ctypes_uint64;
extern PyObject* ctypes_uint32;
extern PyObject* ctypes_uint16;
extern PyObject* ctypes_uint8;
extern PyObject* ctypes_bool;

extern destructor ctypes_dealloc;

extern PyObject* ctypes_void_p;
extern PyObject* ctypes_cast;

#if defined(_M_IX86) || defined(__i386__)
PyObject* PyGLM_CtypesVoidP_FromVoidP(void* p);
unsigned long PyGLM_UnsignedLongLong_FromCtypesP(PyObject* ptr);
#else
PyObject* PyGLM_CtypesVoidP_FromVoidP(void* p);
unsigned long long PyGLM_UnsignedLongLong_FromCtypesP(PyObject* ptr);
#endif

#if !(PyGLM_BUILD & PyGLM_NO_FUNCTIONS)

extern PyObject* ctypes_float_p;
extern PyObject* ctypes_double_p;
extern PyObject* ctypes_int64_p;
extern PyObject* ctypes_int32_p;
extern PyObject* ctypes_int16_p;
extern PyObject* ctypes_int8_p;
extern PyObject* ctypes_uint64_p;
extern PyObject* ctypes_uint32_p;
extern PyObject* ctypes_uint16_p;
extern PyObject* ctypes_uint8_p;
extern PyObject* ctypes_bool_p;

PyObject* PyGLM_ToCtypesP(float* ptr);
PyObject* PyGLM_ToCtypesP(double* ptr);
PyObject* PyGLM_ToCtypesP(glm::int64* ptr);
PyObject* PyGLM_ToCtypesP(glm::int32* ptr);
PyObject* PyGLM_ToCtypesP(glm::int16* ptr);
PyObject* PyGLM_ToCtypesP(glm::int8* ptr);
PyObject* PyGLM_ToCtypesP(glm::uint64* ptr);
PyObject* PyGLM_ToCtypesP(glm::uint32* ptr);
PyObject* PyGLM_ToCtypesP(glm::uint16* ptr);
PyObject* PyGLM_ToCtypesP(glm::uint8* ptr);
PyObject* PyGLM_ToCtypesP(bool* ptr);
PyObject* PyGLM_ToCtypesP(void* ptr);
#endif