#pragma once

#include "types.h"

struct PyGLMTypeObject {
	PyTypeObject typeObject;
	uint8 glmType;
	uint8 C;
	uint8 R;
	Py_ssize_t dtSize;
	Py_ssize_t itemSize;
	char format;
	char reserved = '\x00';

	int PTI_info;

	PyTypeObject* subtype;

	PyGLMTypeObject() = default;

	PyGLMTypeObject(PyTypeObject typeObject, uint8 glmType, uint8 C, uint8 R, Py_ssize_t dtSize, Py_ssize_t itemSize, char format);

	PyGLMTypeObject(PyTypeObject typeObject, uint8 glmType, uint8 C, uint8 R, Py_ssize_t dtSize, Py_ssize_t itemSize, char format, PyTypeObject* subtype);

	char* getDataOf(PyObject* src);
};
