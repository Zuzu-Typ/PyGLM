#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
affineInverse_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>():
		return pack(glm::affineInverse(PyGLM_Mat_Get(3, 3, float, arg)));
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>():
		return pack(glm::affineInverse(PyGLM_Mat_Get(3, 3, double, arg)));
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>():
		return pack(glm::affineInverse(PyGLM_Mat_Get(4, 4, float, arg)));
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>():
		return pack(glm::affineInverse(PyGLM_Mat_Get(4, 4, double, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for affineInverse(): ", arg);
	return NULL;
}

static PyObject*
inverseTranspose_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
	case PyGLMTypeObjectArrayOffsetMat<2, 2, float>():
		return pack(glm::inverseTranspose(PyGLM_Mat_Get(2, 2, float, arg)));
	case PyGLMTypeObjectArrayOffsetMat<2, 2, double>():
		return pack(glm::inverseTranspose(PyGLM_Mat_Get(2, 2, double, arg)));
	case PyGLMTypeObjectArrayOffsetMat<3, 3, float>():
		return pack(glm::inverseTranspose(PyGLM_Mat_Get(3, 3, float, arg)));
	case PyGLMTypeObjectArrayOffsetMat<3, 3, double>():
		return pack(glm::inverseTranspose(PyGLM_Mat_Get(3, 3, double, arg)));
	case PyGLMTypeObjectArrayOffsetMat<4, 4, float>():
		return pack(glm::inverseTranspose(PyGLM_Mat_Get(4, 4, float, arg)));
	case PyGLMTypeObjectArrayOffsetMat<4, 4, double>():
		return pack(glm::inverseTranspose(PyGLM_Mat_Get(4, 4, double, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for inverseTranspose(): ", arg);
	return NULL;
}

PyDoc_STRVAR(affineInverse_docstr,
	"affineInverse(m: matSxS) -> matSxS\n"
	"	Fast matrix inverse for affine matrix."
);
PyDoc_STRVAR(inverseTranspose_docstr,
	"inverseTranspose(m: matSxS) -> matSxS\n"
	"	Compute the inverse transpose of a matrix."
);

#define MATRIX_INVERSE_METHODS \
{ "affineInverse", (PyCFunction)affineInverse_, METH_O, affineInverse_docstr }, \
{ "inverseTranspose", (PyCFunction)inverseTranspose_, METH_O, inverseTranspose_docstr }
