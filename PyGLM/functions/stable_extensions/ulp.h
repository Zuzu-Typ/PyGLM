#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
next_float_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "next_float", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::next_float(PyGLM_Number_FromPyObject<double>(arg1)));
		}
		if (PyGLM_Vec_Check(1, float, arg1)) {
			return pack(glm::next_float(unpack_vec<1, float>(arg1)));
		}
		if (PyGLM_Vec_Check(1, double, arg1)) {
			return pack(glm::next_float(unpack_vec<1, double>(arg1)));
		}
		if (PyGLM_Vec_Check(2, float, arg1)) {
			return pack(glm::next_float(unpack_vec<2, float>(arg1)));
		}
		if (PyGLM_Vec_Check(2, double, arg1)) {
			return pack(glm::next_float(unpack_vec<2, double>(arg1)));
		}
		if (PyGLM_Vec_Check(3, float, arg1)) {
			return pack(glm::next_float(unpack_vec<3, float>(arg1)));
		}
		if (PyGLM_Vec_Check(3, double, arg1)) {
			return pack(glm::next_float(unpack_vec<3, double>(arg1)));
		}
		if (PyGLM_Vec_Check(4, float, arg1)) {
			return pack(glm::next_float(unpack_vec<4, float>(arg1)));
		}
		if (PyGLM_Vec_Check(4, double, arg1)) {
			return pack(glm::next_float(unpack_vec<4, double>(arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type for next_float(): ", arg1);
		return NULL;
	}
	if (PyLong_Check(arg2)) {
		int ULPs = PyGLM_Number_FromPyObject<int>(arg2);
		PyGLM_ASSERT((ULPs >= 0), "'ULPs' has to be greater than or equal to 0")
			if (PyGLM_Number_Check(arg1)) {
				return pack(glm::next_float(PyGLM_Number_FromPyObject<double>(arg1), ULPs));
			}
		if (PyGLM_Vec_Check(1, float, arg1)) {
			return pack(glm::next_float(unpack_vec<1, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(1, double, arg1)) {
			return pack(glm::next_float(unpack_vec<1, double>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(2, float, arg1)) {
			return pack(glm::next_float(unpack_vec<2, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(2, double, arg1)) {
			return pack(glm::next_float(unpack_vec<2, double>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(3, float, arg1)) {
			return pack(glm::next_float(unpack_vec<3, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(3, double, arg1)) {
			return pack(glm::next_float(unpack_vec<3, double>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(4, float, arg1)) {
			return pack(glm::next_float(unpack_vec<4, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(4, double, arg1)) {
			return pack(glm::next_float(unpack_vec<4, double>(arg1), ULPs));
		}
	}
	else {
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, int, arg2)) {
			return pack(glm::next_float(unpack_vec<1, float>(arg1), unpack_vec<1, int>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, int, arg2)) {
			return pack(glm::next_float(unpack_vec<1, double>(arg1), unpack_vec<1, int>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, int, arg2)) {
			return pack(glm::next_float(unpack_vec<2, float>(arg1), unpack_vec<2, int>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, int, arg2)) {
			return pack(glm::next_float(unpack_vec<2, double>(arg1), unpack_vec<2, int>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, int, arg2)) {
			return pack(glm::next_float(unpack_vec<3, float>(arg1), unpack_vec<3, int>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, int, arg2)) {
			return pack(glm::next_float(unpack_vec<3, double>(arg1), unpack_vec<3, int>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, int, arg2)) {
			return pack(glm::next_float(unpack_vec<4, float>(arg1), unpack_vec<4, int>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, int, arg2)) {
			return pack(glm::next_float(unpack_vec<4, double>(arg1), unpack_vec<4, int>(arg2)));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for next_float(): ", arg1, arg2);
	return NULL;
}

static PyObject*
prev_float_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "prev_float", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::prev_float(PyGLM_Number_FromPyObject<double>(arg1)));
		}
		if (PyGLM_Vec_Check(1, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<1, float>(arg1)));
		}
		if (PyGLM_Vec_Check(1, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<1, double>(arg1)));
		}
		if (PyGLM_Vec_Check(2, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<2, float>(arg1)));
		}
		if (PyGLM_Vec_Check(2, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<2, double>(arg1)));
		}
		if (PyGLM_Vec_Check(3, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<3, float>(arg1)));
		}
		if (PyGLM_Vec_Check(3, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<3, double>(arg1)));
		}
		if (PyGLM_Vec_Check(4, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<4, float>(arg1)));
		}
		if (PyGLM_Vec_Check(4, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<4, double>(arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type for prev_float(): ", arg1);
		return NULL;
	}
	if (PyLong_Check(arg2)) {
		int ULPs = PyGLM_Number_FromPyObject<int>(arg2);
		PyGLM_ASSERT((ULPs >= 0), "'ULPs' has to be greater than or equal to 0")
			if (PyGLM_Number_Check(arg1)) {
				return pack(glm::prev_float(PyGLM_Number_FromPyObject<double>(arg1), ULPs));
			}
		if (PyGLM_Vec_Check(1, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<1, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(1, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<1, double>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(2, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<2, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(2, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<2, double>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(3, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<3, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(3, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<3, double>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(4, float, arg1)) {
			return pack(glm::prev_float(unpack_vec<4, float>(arg1), ULPs));
		}
		if (PyGLM_Vec_Check(4, double, arg1)) {
			return pack(glm::prev_float(unpack_vec<4, double>(arg1), ULPs));
		}
	}
	else {
		if (PyGLM_Vec_Check(1, float, arg1) && PyGLM_Vec_Check(1, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<1, float>(arg1), unpack_vec<1, int>(arg2)));
		}
		if (PyGLM_Vec_Check(1, double, arg1) && PyGLM_Vec_Check(1, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<1, double>(arg1), unpack_vec<1, int>(arg2)));
		}
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<2, float>(arg1), unpack_vec<2, int>(arg2)));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<2, double>(arg1), unpack_vec<2, int>(arg2)));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<3, float>(arg1), unpack_vec<3, int>(arg2)));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<3, double>(arg1), unpack_vec<3, int>(arg2)));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<4, float>(arg1), unpack_vec<4, int>(arg2)));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, int, arg2)) {
			return pack(glm::prev_float(unpack_vec<4, double>(arg1), unpack_vec<4, int>(arg2)));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for prev_float(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(float_distance);

#define ULP_METHODS { "next_float", (PyCFunction)next_float_, METH_VARARGS, "next_float(x[, ULPs]) -> float or vecn\nReturn the next ULP value(s) after the input value(s)." }, \
{ "prev_float", (PyCFunction)prev_float_, METH_VARARGS, "prev_float(x[, ULPs]) -> float or vecn\nReturn the previous ULP value(s) before the input value(s)." }, \
{ "float_distance", (PyCFunction)float_distance_, METH_VARARGS, "float_distance(x, y) -> ivecn or i64vecn\nReturn the distance in the number of ULP between 2 single-precision floating-point scalars." }
