#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_N_V__tfF(abs)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(sign)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(floor)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(trunc)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(round)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(roundEven)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(ceil)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(fract)

PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tfF(mod)
//PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tfF(min)

static PyObject*
min_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "min", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {
			return pack(glm::min(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {
			return pack(glm::min(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
			return pack(glm::min(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
			return pack(glm::min(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
			return pack(glm::min(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
			return pack(glm::min(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
			return pack(glm::min(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
			return pack(glm::min(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<1, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<1, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<2, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<2, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<3, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<3, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<4, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(unpack_vec<4, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::min(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3)) {
				return pack(glm::min(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3)) {
				return pack(glm::min(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3)) {
				return pack(glm::min(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3)) {
				return pack(glm::min(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {
				return pack(glm::min(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {
				return pack(glm::min(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3)) {
				return pack(glm::min(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3)) {
				return pack(glm::min(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::min(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3) && PyGLM_Vec_Check(1, float, arg4)) {
				return pack(glm::min(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3), unpack_vec<1, float>(arg4)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3) && PyGLM_Vec_Check(1, double, arg4)) {
				return pack(glm::min(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3), unpack_vec<1, double>(arg4)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3) && PyGLM_Vec_Check(2, float, arg4)) {
				return pack(glm::min(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3), unpack_vec<2, float>(arg4)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3) && PyGLM_Vec_Check(2, double, arg4)) {
				return pack(glm::min(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3), unpack_vec<2, double>(arg4)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3) && PyGLM_Vec_Check(3, float, arg4)) {
				return pack(glm::min(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3), unpack_vec<3, float>(arg4)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3) && PyGLM_Vec_Check(3, double, arg4)) {
				return pack(glm::min(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3), unpack_vec<3, double>(arg4)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3) && PyGLM_Vec_Check(4, float, arg4)) {
				return pack(glm::min(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3), unpack_vec<4, float>(arg4)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3) && PyGLM_Vec_Check(4, double, arg4)) {
				return pack(glm::min(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3), unpack_vec<4, double>(arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for min()");
	return NULL;
}

static PyObject*
max_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "max", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {
			return pack(glm::max(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {
			return pack(glm::max(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
			return pack(glm::max(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
			return pack(glm::max(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
			return pack(glm::max(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
			return pack(glm::max(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
			return pack(glm::max(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
			return pack(glm::max(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<1, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<1, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<2, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<2, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<3, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<3, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<4, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(unpack_vec<4, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::max(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3)) {
				return pack(glm::max(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3)) {
				return pack(glm::max(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3)) {
				return pack(glm::max(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3)) {
				return pack(glm::max(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {
				return pack(glm::max(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {
				return pack(glm::max(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3)) {
				return pack(glm::max(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3)) {
				return pack(glm::max(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::max(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3) && PyGLM_Vec_Check(1, float, arg4)) {
				return pack(glm::max(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3), unpack_vec<1, float>(arg4)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3) && PyGLM_Vec_Check(1, double, arg4)) {
				return pack(glm::max(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3), unpack_vec<1, double>(arg4)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3) && PyGLM_Vec_Check(2, float, arg4)) {
				return pack(glm::max(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3), unpack_vec<2, float>(arg4)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3) && PyGLM_Vec_Check(2, double, arg4)) {
				return pack(glm::max(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3), unpack_vec<2, double>(arg4)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3) && PyGLM_Vec_Check(3, float, arg4)) {
				return pack(glm::max(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3), unpack_vec<3, float>(arg4)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3) && PyGLM_Vec_Check(3, double, arg4)) {
				return pack(glm::max(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3), unpack_vec<3, double>(arg4)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3) && PyGLM_Vec_Check(4, float, arg4)) {
				return pack(glm::max(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3), unpack_vec<4, float>(arg4)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3) && PyGLM_Vec_Check(4, double, arg4)) {
				return pack(glm::max(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3), unpack_vec<4, double>(arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for max()");
	return NULL;
}

static PyObject*
fmin_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "fmin", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {
			return pack(glm::fmin(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {
			return pack(glm::fmin(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
			return pack(glm::fmin(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
			return pack(glm::fmin(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
			return pack(glm::fmin(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
			return pack(glm::fmin(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
			return pack(glm::fmin(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
			return pack(glm::fmin(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<1, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<1, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<2, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<2, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<3, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<3, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<4, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(unpack_vec<4, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::fmin(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3)) {
				return pack(glm::fmin(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3)) {
				return pack(glm::fmin(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3)) {
				return pack(glm::fmin(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3)) {
				return pack(glm::fmin(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {
				return pack(glm::fmin(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {
				return pack(glm::fmin(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3)) {
				return pack(glm::fmin(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3)) {
				return pack(glm::fmin(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::fmin(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3) && PyGLM_Vec_Check(1, float, arg4)) {
				return pack(glm::fmin(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3), unpack_vec<1, float>(arg4)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3) && PyGLM_Vec_Check(1, double, arg4)) {
				return pack(glm::fmin(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3), unpack_vec<1, double>(arg4)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3) && PyGLM_Vec_Check(2, float, arg4)) {
				return pack(glm::fmin(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3), unpack_vec<2, float>(arg4)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3) && PyGLM_Vec_Check(2, double, arg4)) {
				return pack(glm::fmin(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3), unpack_vec<2, double>(arg4)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3) && PyGLM_Vec_Check(3, float, arg4)) {
				return pack(glm::fmin(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3), unpack_vec<3, float>(arg4)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3) && PyGLM_Vec_Check(3, double, arg4)) {
				return pack(glm::fmin(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3), unpack_vec<3, double>(arg4)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3) && PyGLM_Vec_Check(4, float, arg4)) {
				return pack(glm::fmin(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3), unpack_vec<4, float>(arg4)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3) && PyGLM_Vec_Check(4, double, arg4)) {
				return pack(glm::fmin(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3), unpack_vec<4, double>(arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fmin()");
	return NULL;
}

static PyObject*
fmax_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "fmax", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {
			return pack(glm::fmax(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {
			return pack(glm::fmax(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
			return pack(glm::fmax(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
			return pack(glm::fmax(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
			return pack(glm::fmax(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
			return pack(glm::fmax(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
			return pack(glm::fmax(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
			return pack(glm::fmax(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2)));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<1, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<1, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<2, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<2, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<3, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<3, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<4, float>(arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(unpack_vec<4, double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::fmax(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3)) {
				return pack(glm::fmax(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3)) {
				return pack(glm::fmax(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3)) {
				return pack(glm::fmax(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3)) {
				return pack(glm::fmax(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3)) {
				return pack(glm::fmax(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3)) {
				return pack(glm::fmax(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3)) {
				return pack(glm::fmax(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3)) {
				return pack(glm::fmax(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::fmax(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2) && PyGLM_Vec_Check(1, float, arg3) && PyGLM_Vec_Check(1, float, arg4)) {
				return pack(glm::fmax(unpack_vec<1, float>(arg1), unpack_vec<1, float>(arg2), unpack_vec<1, float>(arg3), unpack_vec<1, float>(arg4)));
			}
			if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2) && PyGLM_Vec_Check(1, double, arg3) && PyGLM_Vec_Check(1, double, arg4)) {
				return pack(glm::fmax(unpack_vec<1, double>(arg1), unpack_vec<1, double>(arg2), unpack_vec<1, double>(arg3), unpack_vec<1, double>(arg4)));
			}
			if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2) && PyGLM_Vec_Check(2, float, arg3) && PyGLM_Vec_Check(2, float, arg4)) {
				return pack(glm::fmax(unpack_vec<2, float>(arg1), unpack_vec<2, float>(arg2), unpack_vec<2, float>(arg3), unpack_vec<2, float>(arg4)));
			}
			if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2) && PyGLM_Vec_Check(2, double, arg3) && PyGLM_Vec_Check(2, double, arg4)) {
				return pack(glm::fmax(unpack_vec<2, double>(arg1), unpack_vec<2, double>(arg2), unpack_vec<2, double>(arg3), unpack_vec<2, double>(arg4)));
			}
			if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2) && PyGLM_Vec_Check(3, float, arg3) && PyGLM_Vec_Check(3, float, arg4)) {
				return pack(glm::fmax(unpack_vec<3, float>(arg1), unpack_vec<3, float>(arg2), unpack_vec<3, float>(arg3), unpack_vec<3, float>(arg4)));
			}
			if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2) && PyGLM_Vec_Check(3, double, arg3) && PyGLM_Vec_Check(3, double, arg4)) {
				return pack(glm::fmax(unpack_vec<3, double>(arg1), unpack_vec<3, double>(arg2), unpack_vec<3, double>(arg3), unpack_vec<3, double>(arg4)));
			}
			if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2) && PyGLM_Vec_Check(4, float, arg3) && PyGLM_Vec_Check(4, float, arg4)) {
				return pack(glm::fmax(unpack_vec<4, float>(arg1), unpack_vec<4, float>(arg2), unpack_vec<4, float>(arg3), unpack_vec<4, float>(arg4)));
			}
			if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2) && PyGLM_Vec_Check(4, double, arg3) && PyGLM_Vec_Check(4, double, arg4)) {
				return pack(glm::fmax(unpack_vec<4, double>(arg1), unpack_vec<4, double>(arg2), unpack_vec<4, double>(arg3), unpack_vec<4, double>(arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fmax()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_NNN_VVV_VNN__tfF(clamp)

static PyObject*
mix_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "mix", arg1, arg2, arg3);

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyBool_Check(arg3)) {
		return PyGLM_PyObject_FromNumber(glm::mix(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<bool>(arg3)));
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return PyGLM_PyObject_FromNumber(glm::mix(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}

	if (PyGLM_Qua_Check(float, arg1) && PyGLM_Qua_Check(float, arg2) && PyGLM_Number_Check(arg3)) {
		glm::quat o, o2;
		unpack_qua(arg1, o);
		unpack_qua(arg2, o2);
		return pack_qua(glm::mix(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
	}
	if (PyGLM_Qua_Check(double, arg1) && PyGLM_Qua_Check(double, arg2) && PyGLM_Number_Check(arg3)) {
		glm::dquat o, o2;
		unpack_qua(arg1, o);
		unpack_qua(arg2, o2);
		return pack_qua(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	}

	if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {
		glm::vec<1, float> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {
		glm::vec<1, double> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, int, arg1) && PyGLM_Vec_Check(1, int, arg2)) {
		glm::vec<1, int> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::uint, arg1) && PyGLM_Vec_Check(1, glm::uint, arg2)) {
		glm::vec<1, glm::uint> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::i64, arg1) && PyGLM_Vec_Check(1, glm::i64, arg2)) {
		glm::vec<1, glm::i64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::u64, arg1) && PyGLM_Vec_Check(1, glm::u64, arg2)) {
		glm::vec<1, glm::u64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::i16, arg1) && PyGLM_Vec_Check(1, glm::i16, arg2)) {
		glm::vec<1, glm::i16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::u16, arg1) && PyGLM_Vec_Check(1, glm::u16, arg2)) {
		glm::vec<1, glm::u16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::i8, arg1) && PyGLM_Vec_Check(1, glm::i8, arg2)) {
		glm::vec<1, glm::i8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, glm::u8, arg1) && PyGLM_Vec_Check(1, glm::u8, arg2)) {
		glm::vec<1, glm::u8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, bool, arg1) && PyGLM_Vec_Check(1, bool, arg2)) {
		glm::vec<1, bool> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(1, float, arg3)) {
			glm::vec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, double, arg3)) {
			glm::dvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(1, bool, arg3)) {
			glm::bvec1 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
		glm::vec<2, float> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
		glm::vec<2, double> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, int, arg1) && PyGLM_Vec_Check(2, int, arg2)) {
		glm::vec<2, int> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::uint, arg1) && PyGLM_Vec_Check(2, glm::uint, arg2)) {
		glm::vec<2, glm::uint> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::i64, arg1) && PyGLM_Vec_Check(2, glm::i64, arg2)) {
		glm::vec<2, glm::i64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::u64, arg1) && PyGLM_Vec_Check(2, glm::u64, arg2)) {
		glm::vec<2, glm::u64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::i16, arg1) && PyGLM_Vec_Check(2, glm::i16, arg2)) {
		glm::vec<2, glm::i16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::u16, arg1) && PyGLM_Vec_Check(2, glm::u16, arg2)) {
		glm::vec<2, glm::u16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::i8, arg1) && PyGLM_Vec_Check(2, glm::i8, arg2)) {
		glm::vec<2, glm::i8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, glm::u8, arg1) && PyGLM_Vec_Check(2, glm::u8, arg2)) {
		glm::vec<2, glm::u8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, bool, arg1) && PyGLM_Vec_Check(2, bool, arg2)) {
		glm::vec<2, bool> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::dvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::bvec2 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
		glm::vec<3, float> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
		glm::vec<3, double> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, int, arg1) && PyGLM_Vec_Check(3, int, arg2)) {
		glm::vec<3, int> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::uint, arg1) && PyGLM_Vec_Check(3, glm::uint, arg2)) {
		glm::vec<3, glm::uint> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::i64, arg1) && PyGLM_Vec_Check(3, glm::i64, arg2)) {
		glm::vec<3, glm::i64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::u64, arg1) && PyGLM_Vec_Check(3, glm::u64, arg2)) {
		glm::vec<3, glm::u64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::i16, arg1) && PyGLM_Vec_Check(3, glm::i16, arg2)) {
		glm::vec<3, glm::i16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::u16, arg1) && PyGLM_Vec_Check(3, glm::u16, arg2)) {
		glm::vec<3, glm::u16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::i8, arg1) && PyGLM_Vec_Check(3, glm::i8, arg2)) {
		glm::vec<3, glm::i8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, glm::u8, arg1) && PyGLM_Vec_Check(3, glm::u8, arg2)) {
		glm::vec<3, glm::u8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, bool, arg1) && PyGLM_Vec_Check(3, bool, arg2)) {
		glm::vec<3, bool> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::dvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::bvec3 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
		glm::vec<4, float> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
		glm::vec<4, double> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, int, arg1) && PyGLM_Vec_Check(4, int, arg2)) {
		glm::vec<4, int> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::uint, arg1) && PyGLM_Vec_Check(4, glm::uint, arg2)) {
		glm::vec<4, glm::uint> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::i64, arg1) && PyGLM_Vec_Check(4, glm::i64, arg2)) {
		glm::vec<4, glm::i64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::u64, arg1) && PyGLM_Vec_Check(4, glm::u64, arg2)) {
		glm::vec<4, glm::u64> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::i16, arg1) && PyGLM_Vec_Check(4, glm::i16, arg2)) {
		glm::vec<4, glm::i16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::u16, arg1) && PyGLM_Vec_Check(4, glm::u16, arg2)) {
		glm::vec<4, glm::u16> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::i8, arg1) && PyGLM_Vec_Check(4, glm::i8, arg2)) {
		glm::vec<4, glm::i8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, glm::u8, arg1) && PyGLM_Vec_Check(4, glm::u8, arg2)) {
		glm::vec<4, glm::u8> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, bool, arg1) && PyGLM_Vec_Check(4, bool, arg2)) {
		glm::vec<4, bool> o, o2;
		unpack_vec(arg1, o);
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::dvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::bvec4 o3;
			unpack_vec(arg3, o3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}

	if (PyGLM_Mat_Check(2, 2, float, arg1) && PyGLM_Mat_Check(2, 2, float, arg2)) {
		glm::mat<2, 2, float> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(2, 2, double, arg1) && PyGLM_Mat_Check(2, 2, double, arg2)) {
		glm::mat<2, 2, double> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(2, 2, int, arg1) && PyGLM_Mat_Check(2, 2, int, arg2)) {
		glm::mat<2, 2, int> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(2, 2, glm::uint, arg1) && PyGLM_Mat_Check(2, 2, glm::uint, arg2)) {
		glm::mat<2, 2, glm::uint> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	//if (PyGLM_Mat_Check(2, 3, float, arg1) && PyGLM_Mat_Check(2, 3, float, arg2)) {
	//	glm::mat<2, 3, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 3, double, arg1) && PyGLM_Mat_Check(2, 3, double, arg2)) {
	//	glm::mat<2, 3, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 3, int, arg1) && PyGLM_Mat_Check(2, 3, int, arg2)) {
	//	glm::mat<2, 3, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 3, glm::uint, arg1) && PyGLM_Mat_Check(2, 3, glm::uint, arg2)) {
	//	glm::mat<2, 3, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 4, float, arg1) && PyGLM_Mat_Check(2, 4, float, arg2)) {
	//	glm::mat<2, 4, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 4, double, arg1) && PyGLM_Mat_Check(2, 4, double, arg2)) {
	//	glm::mat<2, 4, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 4, int, arg1) && PyGLM_Mat_Check(2, 4, int, arg2)) {
	//	glm::mat<2, 4, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(2, 4, glm::uint, arg1) && PyGLM_Mat_Check(2, 4, glm::uint, arg2)) {
	//	glm::mat<2, 4, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 2, float, arg1) && PyGLM_Mat_Check(3, 2, float, arg2)) {
	//	glm::mat<3, 2, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 2, double, arg1) && PyGLM_Mat_Check(3, 2, double, arg2)) {
	//	glm::mat<3, 2, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 2, int, arg1) && PyGLM_Mat_Check(3, 2, int, arg2)) {
	//	glm::mat<3, 2, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 2, glm::uint, arg1) && PyGLM_Mat_Check(3, 2, glm::uint, arg2)) {
	//	glm::mat<3, 2, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	if (PyGLM_Mat_Check(3, 3, float, arg1) && PyGLM_Mat_Check(3, 3, float, arg2)) {
		glm::mat<3, 3, float> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(3, 3, double, arg1) && PyGLM_Mat_Check(3, 3, double, arg2)) {
		glm::mat<3, 3, double> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(3, 3, int, arg1) && PyGLM_Mat_Check(3, 3, int, arg2)) {
		glm::mat<3, 3, int> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(3, 3, glm::uint, arg1) && PyGLM_Mat_Check(3, 3, glm::uint, arg2)) {
		glm::mat<3, 3, glm::uint> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	//if (PyGLM_Mat_Check(3, 4, float, arg1) && PyGLM_Mat_Check(3, 4, float, arg2)) {
	//	glm::mat<3, 4, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 4, double, arg1) && PyGLM_Mat_Check(3, 4, double, arg2)) {
	//	glm::mat<3, 4, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 4, int, arg1) && PyGLM_Mat_Check(3, 4, int, arg2)) {
	//	glm::mat<3, 4, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(3, 4, glm::uint, arg1) && PyGLM_Mat_Check(3, 4, glm::uint, arg2)) {
	//	glm::mat<3, 4, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 2, float, arg1) && PyGLM_Mat_Check(4, 2, float, arg2)) {
	//	glm::mat<4, 2, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 2, double, arg1) && PyGLM_Mat_Check(4, 2, double, arg2)) {
	//	glm::mat<4, 2, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 2, int, arg1) && PyGLM_Mat_Check(4, 2, int, arg2)) {
	//	glm::mat<4, 2, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 2, glm::uint, arg1) && PyGLM_Mat_Check(4, 2, glm::uint, arg2)) {
	//	glm::mat<4, 2, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 3, float, arg1) && PyGLM_Mat_Check(4, 3, float, arg2)) {
	//	glm::mat<4, 3, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 3, double, arg1) && PyGLM_Mat_Check(4, 3, double, arg2)) {
	//	glm::mat<4, 3, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 3, int, arg1) && PyGLM_Mat_Check(4, 3, int, arg2)) {
	//	glm::mat<4, 3, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_Check(4, 3, glm::uint, arg1) && PyGLM_Mat_Check(4, 3, glm::uint, arg2)) {
	//	glm::mat<4, 3, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_Check(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2)) {
		glm::mat<4, 4, float> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2)) {
		glm::mat<4, 4, double> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(4, 4, int, arg1) && PyGLM_Mat_Check(4, 4, int, arg2)) {
		glm::mat<4, 4, int> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_Check(4, 4, glm::uint, arg1) && PyGLM_Mat_Check(4, 4, glm::uint, arg2)) {
		glm::mat<4, 4, glm::uint> o, o2;
		unpack_mat(arg1, o);
		unpack_mat(arg2, o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_Check(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_Check(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3;
			unpack_mat(arg3, o3);
			return pack(glm::mix(o, o2, o3));
		}
	}

	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mix()");
	return NULL;
}

static PyObject*
step_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "step", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return PyGLM_PyObject_FromNumber(glm::step(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	if (PyGLM_Vec_Check(1, float, arg2)) {
		glm::vec<1, float> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, float, arg1)) {
			glm::vec<1, float> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, double, arg2)) {
		glm::vec<1, double> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, double, arg1)) {
			glm::vec<1, double> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, int, arg2)) {
		glm::vec<1, int> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, int, arg1)) {
			glm::vec<1, int> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::uint, arg2)) {
		glm::vec<1, glm::uint> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::uint, arg1)) {
			glm::vec<1, glm::uint> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::i64, arg2)) {
		glm::vec<1, glm::i64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::i64, arg1)) {
			glm::vec<1, glm::i64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::u64, arg2)) {
		glm::vec<1, glm::u64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::u64, arg1)) {
			glm::vec<1, glm::u64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::i16, arg2)) {
		glm::vec<1, glm::i16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::i16, arg1)) {
			glm::vec<1, glm::i16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::u16, arg2)) {
		glm::vec<1, glm::u16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::u16, arg1)) {
			glm::vec<1, glm::u16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::i8, arg2)) {
		glm::vec<1, glm::i8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::i8, arg1)) {
			glm::vec<1, glm::i8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, glm::u8, arg2)) {
		glm::vec<1, glm::u8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, glm::u8, arg1)) {
			glm::vec<1, glm::u8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(1, bool, arg2)) {
		glm::vec<1, bool> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_Check(1, bool, arg1)) {
			glm::vec<1, bool> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, float, arg2)) {
		glm::vec<2, float> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, float, arg1)) {
			glm::vec<2, float> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, double, arg2)) {
		glm::vec<2, double> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, double, arg1)) {
			glm::vec<2, double> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, int, arg2)) {
		glm::vec<2, int> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, int, arg1)) {
			glm::vec<2, int> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::uint, arg2)) {
		glm::vec<2, glm::uint> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::uint, arg1)) {
			glm::vec<2, glm::uint> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::i64, arg2)) {
		glm::vec<2, glm::i64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::i64, arg1)) {
			glm::vec<2, glm::i64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::u64, arg2)) {
		glm::vec<2, glm::u64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::u64, arg1)) {
			glm::vec<2, glm::u64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::i16, arg2)) {
		glm::vec<2, glm::i16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::i16, arg1)) {
			glm::vec<2, glm::i16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::u16, arg2)) {
		glm::vec<2, glm::u16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::u16, arg1)) {
			glm::vec<2, glm::u16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::i8, arg2)) {
		glm::vec<2, glm::i8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::i8, arg1)) {
			glm::vec<2, glm::i8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, glm::u8, arg2)) {
		glm::vec<2, glm::u8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, glm::u8, arg1)) {
			glm::vec<2, glm::u8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(2, bool, arg2)) {
		glm::vec<2, bool> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_Check(2, bool, arg1)) {
			glm::vec<2, bool> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, float, arg2)) {
		glm::vec<3, float> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, float, arg1)) {
			glm::vec<3, float> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, double, arg2)) {
		glm::vec<3, double> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, double, arg1)) {
			glm::vec<3, double> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, int, arg2)) {
		glm::vec<3, int> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, int, arg1)) {
			glm::vec<3, int> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::uint, arg2)) {
		glm::vec<3, glm::uint> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::uint, arg1)) {
			glm::vec<3, glm::uint> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::i64, arg2)) {
		glm::vec<3, glm::i64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::i64, arg1)) {
			glm::vec<3, glm::i64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::u64, arg2)) {
		glm::vec<3, glm::u64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::u64, arg1)) {
			glm::vec<3, glm::u64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::i16, arg2)) {
		glm::vec<3, glm::i16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::i16, arg1)) {
			glm::vec<3, glm::i16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::u16, arg2)) {
		glm::vec<3, glm::u16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::u16, arg1)) {
			glm::vec<3, glm::u16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::i8, arg2)) {
		glm::vec<3, glm::i8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::i8, arg1)) {
			glm::vec<3, glm::i8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, glm::u8, arg2)) {
		glm::vec<3, glm::u8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, glm::u8, arg1)) {
			glm::vec<3, glm::u8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(3, bool, arg2)) {
		glm::vec<3, bool> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_Check(3, bool, arg1)) {
			glm::vec<3, bool> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, float, arg2)) {
		glm::vec<4, float> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, float, arg1)) {
			glm::vec<4, float> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, double, arg2)) {
		glm::vec<4, double> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, double, arg1)) {
			glm::vec<4, double> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, int, arg2)) {
		glm::vec<4, int> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, int, arg1)) {
			glm::vec<4, int> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::uint, arg2)) {
		glm::vec<4, glm::uint> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::uint, arg1)) {
			glm::vec<4, glm::uint> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::i64, arg2)) {
		glm::vec<4, glm::i64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::i64, arg1)) {
			glm::vec<4, glm::i64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::u64, arg2)) {
		glm::vec<4, glm::u64> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::u64, arg1)) {
			glm::vec<4, glm::u64> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::i16, arg2)) {
		glm::vec<4, glm::i16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::i16, arg1)) {
			glm::vec<4, glm::i16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::u16, arg2)) {
		glm::vec<4, glm::u16> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::u16, arg1)) {
			glm::vec<4, glm::u16> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::i8, arg2)) {
		glm::vec<4, glm::i8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::i8, arg1)) {
			glm::vec<4, glm::i8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, glm::u8, arg2)) {
		glm::vec<4, glm::u8> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, glm::u8, arg1)) {
			glm::vec<4, glm::u8> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_Check(4, bool, arg2)) {
		glm::vec<4, bool> o2;
		unpack_vec(arg2, o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_Check(4, bool, arg1)) {
			glm::vec<4, bool> o;
			unpack_vec(arg1, o);
			return pack_vec(glm::step(o, o2));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for step(): ", arg1, arg2);
	return NULL;
}

static PyObject*
smoothstep_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "smoothstep", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return PyGLM_PyObject_FromNumber(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	if (PyGLM_Vec_Check(1, float, arg3)) {
		glm::vec<1, float> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, float, arg2)) {
			glm::vec<1, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(1, double, arg3)) {
		glm::vec<1, double> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, double, arg2)) {
			glm::vec<1, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, float, arg3)) {
		glm::vec<2, float> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
			glm::vec<2, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(2, double, arg3)) {
		glm::vec<2, double> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
			glm::vec<2, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, float, arg3)) {
		glm::vec<3, float> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
			glm::vec<3, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(3, double, arg3)) {
		glm::vec<3, double> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
			glm::vec<3, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, float, arg3)) {
		glm::vec<4, float> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
			glm::vec<4, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_Check(4, double, arg3)) {
		glm::vec<4, double> o3;
		unpack_vec(arg3, o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
			glm::vec<4, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for smoothstep()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(isnan)
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(isinf)

static PyObject*
fma_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "fma", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2), PyGLM_Number_Check(arg3)) {
		return PyGLM_PyObject_FromNumber(glm::fma(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fma()");
	return NULL;
}

static PyObject*
frexp_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "frexp", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyLong_Check(arg2)) {
		if (PyGLM_SHOW_WARNINGS & PyGLM_FREXP_WARNING) PyErr_WarnEx(PyExc_UserWarning, "This function will return this pair: (m, e), which differs from glm behaviour. You can silence this warning by calling glm.silence(1)", 1);
		int e = (int)PyLong_AS_LONG(arg2);
		double m = glm::frexp(PyGLM_Number_FromPyObject<double>(arg1), e);
		return Py_BuildValue("(d, i)", m, e);
	}
	if (PyGLM_Vec_Check(1, float, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(1, double, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(2, float, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(2, double, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(3, float, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(4, float, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(4, double, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::frexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for frexp(): ", arg1, arg2);
	return NULL;
}

static PyObject*
ldexp_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "ldexp", arg1, arg2);
	if (PyGLM_Vec_Check(1, float, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(1, double, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(2, float, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(2, double, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(3, float, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(4, float, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, float> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_Check(4, double, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, double> o;
		unpack_vec(arg1, o);
		return pack_vec(glm::ldexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for ldexp(): ", arg1, arg2);
	return NULL;
}

#define FUNC_COMMON_METHODS { "abs", (PyCFunction)abs_, METH_O, "abs(x) -> float or vecn\nReturns x if x >= 0; otherwise, it returns -x." }, \
{ "sign", (PyCFunction)sign_, METH_O, "sign(x) -> float or vecn\nReturns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0. " }, \
{ "floor", (PyCFunction)floor_, METH_O, "floor(x) -> float or vecn\nReturns a value equal to the nearest integer that is less then or equal to x." }, \
{ "trunc", (PyCFunction)trunc_, METH_O, "trunc(x) -> float or vecn\nReturns a value equal to the nearest integer to x\nwhose absolute value is not larger than the absolute value of x." }, \
{ "round", (PyCFunction)round_, METH_O, "round(x) -> float or vecn\nReturns a value equal to the nearest integer to x.\nThe fraction 0.5 will round in a direction chosen by the\nimplementation, presumably the direction that is fastest.\nThis includes the possibility that round(x) returns the\nsame value as roundEven(x) for all values of x." }, \
{ "roundEven", (PyCFunction)roundEven_, METH_O, "roundEven(x) -> float or vecn\nReturns a value equal to the nearest integer to x.\nA fractional part of 0.5 will round toward the nearest even\ninteger. (Both 3.5 and 4.5 for x will return 4.0.)" }, \
{ "ceil", (PyCFunction)ceil_, METH_O, "ceil(x) -> float or vecn\nReturns a value equal to the nearest integer\nthat is greater than or equal to x." }, \
{ "fract", (PyCFunction)fract_, METH_O, "fract(x) -> float or vecn\nReturn x - floor(x)." }, \
{ "mod", (PyCFunction)mod_, METH_VARARGS, "mod(x, y) -> float or vecn\nModulus. Returns x - y * floor(x / y)\nfor each component in x using the floating point value y." }, \
{ "min", (PyCFunction)min_, METH_VARARGS, "min(x, y[, z, w]) -> float or vecn\nReturns y if y < x; otherwise, it returns x." }, \
{ "max", (PyCFunction)max_, METH_VARARGS, "max(x, y[, z, w]) -> float or vecn\nReturns y if x < y; otherwise, it returns x." }, \
{ "fmin", (PyCFunction)fmin_, METH_VARARGS, "fmin(x, y[, z, w]) -> float or vecn\nReturns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned." }, \
{ "fmax", (PyCFunction)fmax_, METH_VARARGS, "fmax(x, y[, z, w]) -> float or vecn\nReturns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned." }, \
{ "clamp", (PyCFunction)clamp_, METH_VARARGS, "clamp(x, minVal, maxVal) -> float or vecn\nReturns min(max(x, minVal), maxVal) for each component in x\nusing the floating-point values minVal and maxVal." }, \
{ "mix", (PyCFunction)mix_, METH_VARARGS, "mix(x, y, a) -> float, vecn or quat\nReturns x * (1.0 - a) + y * a, i.e., the linear blend of\nx and y using the floating-point value a.\nThe value for a is not restricted to the range [0, 1]." }, \
{ "step", (PyCFunction)step_, METH_VARARGS, "step(edge, x) -> Returns 0.0 if x < edge, otherwise it returns 1.0." }, \
{ "smoothstep", (PyCFunction)smoothstep_, METH_VARARGS, "smoothstep(edge0, edge1, x) -> float or vecn\nReturns 0.0 if x <= edge0 and 1.0 if x >= edge1 and\nperforms smooth Hermite interpolation between 0 and 1\nwhen edge0 < x < edge1. This is useful in cases where\nyou would want a threshold function with a smooth\ntransition." }, \
{ "isnan", (PyCFunction)isnan_, METH_O, "isnan(x) -> bool or vecn\nReturns true if x holds a NaN (not a number)\nrepresentation in the underlying implementation's set of\nfloating point representations. Returns false otherwise,\nincluding for implementations with no NaN\nrepresentations." }, \
{ "isinf", (PyCFunction)isinf_, METH_O, "isinf(x) -> bool or vecn\nReturns true if x holds a positive infinity or negative\ninfinity representation in the underlying implementation's\nset of floating point representations. Returns false\notherwise, including for implementations with no infinity\nrepresentations." }, \
{ "fma", (PyCFunction)fma_, METH_VARARGS, "fma(a, b, c) -> float\nComputes and returns a * b + c." }, \
{ "frexp", (PyCFunction)frexp_, METH_VARARGS, "frexp(x, exp) -> float or vecn\nSplits x into a floating-point significand in the range\n[0.5, 1.0) and an integral exponent of two, such that:\nx = significand * exp(2, exponent)" }, \
{ "ldexp", (PyCFunction)ldexp_, METH_VARARGS, "ldexp(x, exp) -> float or vecn\nBuilds a floating-point number from x and the\ncorresponding integral exponent of two in exp, returning:\nsignificand * exp(2, exponent)" }
