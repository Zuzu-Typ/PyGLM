#pragma once

#include "types.h"

struct glmArray {
	PyObject_HEAD
		char format;
	uint8 shape[2];
	uint8 glmType;
	Py_ssize_t nBytes;
	Py_ssize_t itemCount;
	Py_ssize_t dtSize;
	Py_ssize_t itemSize;
	PyTypeObject* subtype;
	PyObject* reference;
	bool readonly;
	void* data;

	const int getShape();

	const int getShape(uint8 index);

	void setShape(int L);

	void setShape(int C, int R);
};
