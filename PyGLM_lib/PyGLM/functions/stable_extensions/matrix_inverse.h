#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
affineInverse_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {
		return pack(glm::affineInverse(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {
		return pack(glm::affineInverse(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {
		return pack(glm::affineInverse(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {
		return pack(glm::affineInverse(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for affineInverse(): ", arg);
	return NULL;
}

static PyObject*
inverseTranspose_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_MAT | PyGLM_SHAPE_SQUARE | PyGLM_DT_FD);
	if (PyGLM_Mat_PTI_Check0(2, 2, float, arg)) {
		return pack(glm::inverseTranspose(PyGLM_Mat_PTI_Get0(2, 2, float, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(2, 2, double, arg)) {
		return pack(glm::inverseTranspose(PyGLM_Mat_PTI_Get0(2, 2, double, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg)) {
		return pack(glm::inverseTranspose(PyGLM_Mat_PTI_Get0(3, 3, float, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg)) {
		return pack(glm::inverseTranspose(PyGLM_Mat_PTI_Get0(3, 3, double, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg)) {
		return pack(glm::inverseTranspose(PyGLM_Mat_PTI_Get0(4, 4, float, arg)));
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg)) {
		return pack(glm::inverseTranspose(PyGLM_Mat_PTI_Get0(4, 4, double, arg)));
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
