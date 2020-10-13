#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../ctypes_pointers.h"

template<typename T>
static constexpr PyTypeObject* PyGLM_CTYPES_TYPE() {
	return (std::is_same<T, float>::value) ? (PyTypeObject*)ctypes_float : 
		(std::is_same<T, double>::value) ? (PyTypeObject*)ctypes_double :
		(std::is_same<T, int8>::value) ? (PyTypeObject*)ctypes_int8 :
		(std::is_same<T, int16>::value) ? (PyTypeObject*)ctypes_int16 :
		(std::is_same<T, int32>::value) ? (PyTypeObject*)ctypes_int32 :
		(std::is_same<T, int64>::value) ? (PyTypeObject*)ctypes_int64 :
		(std::is_same<T, uint8>::value) ? (PyTypeObject*)ctypes_uint8 :
		(std::is_same<T, uint16>::value) ? (PyTypeObject*)ctypes_uint16 :
		(std::is_same<T, uint32>::value) ? (PyTypeObject*)ctypes_uint32 :
		(std::is_same<T, uint64>::value) ? (PyTypeObject*)ctypes_uint64 :
		(std::is_same<T, bool>::value) ? (PyTypeObject*)ctypes_bool :
		(PyTypeObject*)0;
}

template<typename T>
static constexpr const char* PyGLM_CTYPES_TYPE_STRING() {
	return (std::is_same<T, float>::value) ? "c_float" :
		(std::is_same<T, double>::value) ? "c_double" :
		(std::is_same<T, int8>::value) ? "c_int8" :
		(std::is_same<T, int16>::value) ? "c_int16" :
		(std::is_same<T, int32>::value) ? "c_int32" :
		(std::is_same<T, int64>::value) ? "c_int64" :
		(std::is_same<T, uint8>::value) ? "c_uint8" :
		(std::is_same<T, uint16>::value) ? "c_uint16" :
		(std::is_same<T, uint32>::value) ? "c_uint32" :
		(std::is_same<T, uint64>::value) ? "c_uint64" :
		(std::is_same<T, bool>::value) ? "c_bool" :
		"";
}