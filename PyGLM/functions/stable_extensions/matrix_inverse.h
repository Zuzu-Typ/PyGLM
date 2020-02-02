#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
affineInverse_(PyObject*, PyObject* arg) {
	if (PyGLM_Mat_Check(3, 3, float, arg)) {
		return pack(glm::affineInverse(unpack_mat<3, 3, float>(arg)));
	}
	if (PyGLM_Mat_Check(3, 3, double, arg)) {
		return pack(glm::affineInverse(unpack_mat<3, 3, double>(arg)));
	}
	if (PyGLM_Mat_Check(4, 4, float, arg)) {
		return pack(glm::affineInverse(unpack_mat<4, 4, float>(arg)));
	}
	if (PyGLM_Mat_Check(4, 4, double, arg)) {
		return pack(glm::affineInverse(unpack_mat<4, 4, double>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for affineInverse(): ", arg);
	return NULL;
}

static PyObject*
inverseTranspose_(PyObject*, PyObject* arg) {
	if (PyGLM_Mat_Check(2, 2, float, arg)) {
		return pack(glm::inverseTranspose(unpack_mat<2, 2, float>(arg)));
	}
	if (PyGLM_Mat_Check(2, 2, double, arg)) {
		return pack(glm::inverseTranspose(unpack_mat<2, 2, double>(arg)));
	}
	if (PyGLM_Mat_Check(3, 3, float, arg)) {
		return pack(glm::inverseTranspose(unpack_mat<3, 3, float>(arg)));
	}
	if (PyGLM_Mat_Check(3, 3, double, arg)) {
		return pack(glm::inverseTranspose(unpack_mat<3, 3, double>(arg)));
	}
	if (PyGLM_Mat_Check(4, 4, float, arg)) {
		return pack(glm::inverseTranspose(unpack_mat<4, 4, float>(arg)));
	}
	if (PyGLM_Mat_Check(4, 4, double, arg)) {
		return pack(glm::inverseTranspose(unpack_mat<4, 4, double>(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for inverseTranspose(): ", arg);
	return NULL;
}

#define MATRIX_INVERSE_METHODS { "affineInverse", (PyCFunction)affineInverse_, METH_O, "affineInverse(m) -> matn\nFast matrix inverse for affine matrix." }, \
{ "inverseTranspose", (PyCFunction)inverseTranspose_, METH_O, "inverseTranspose(m) -> matn\nCompute the inverse transpose of a matrix." }
