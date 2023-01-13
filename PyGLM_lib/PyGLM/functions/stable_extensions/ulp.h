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
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(1, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(1, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(2, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(2, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(3, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(3, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(4, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(4, double, arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type for next_float(): ", arg1);
		return NULL;
	}
	if (PyLong_Check(arg2)) {
		int ULPs = PyGLM_Number_FromPyObject<int>(arg2);
		PyGLM_ASSERT((ULPs >= 0), "'ULPs' has to be greater than or equal to 0");
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::next_float(PyGLM_Number_FromPyObject<double>(arg1), ULPs));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(1, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(1, double, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(2, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(2, double, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(3, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(3, double, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(4, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(4, double, arg1), ULPs));
		}
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			return pack(glm::next_float(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for next_float(): ", arg1, arg2);
	return NULL;
}

static PyObject*
prev_float_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "prev_float", 1, 2, &arg1, &arg2)) return NULL;
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::prev_float(PyGLM_Number_FromPyObject<double>(arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(1, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(1, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(2, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(2, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(3, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(3, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(4, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(4, double, arg1)));
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
		if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(1, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(1, double, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(2, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(2, double, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(3, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(3, double, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(4, float, arg1), ULPs));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(4, double, arg1), ULPs));
		}
	}
	else {
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			return pack(glm::prev_float(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for prev_float(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(float_distance);

PyDoc_STRVAR(next_float_docstr,
	"next_float(x: float) -> float\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: vecN) -> vecN\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: float, ULPs: float) -> float\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: vecN, ULPs: float) -> vecN\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: vecN, ULPs: ivecN) -> float\n"
	"	Return the next ULP value(s) after the input value(s).\n"
);
PyDoc_STRVAR(prev_float_docstr,
	"prev_float(x: float) -> float\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: vecN) -> vecN\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: float, ULPs: float) -> float\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: vecN, ULPs: float) -> vecN\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: vecN, ULPs: ivecN) -> float\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
);
PyDoc_STRVAR(float_distance_docstr,
	"float_distance(x: float, y: float) -> float\n"
	"	Return the distance in the number of ULP between 2 double-precision floating-point scalars.\n"
	"float_distance(x: fvecN, y: fvecN) -> ivecN\n"
	"	Return the distance in the number of ULP between 2 single-precision floating-point scalars.\n"
	"float_distance(x: dvecN, y: dvecN) -> i64vecN\n"
	"	Return the distance in the number of ULP between 2 double-precision floating-point scalars.\n"
);

#define ULP_METHODS \
{ "next_float", (PyCFunction)next_float_, METH_VARARGS, next_float_docstr }, \
{ "prev_float", (PyCFunction)prev_float_, METH_VARARGS, prev_float_docstr }, \
{ "float_distance", (PyCFunction)float_distance_, METH_VARARGS, float_distance_docstr }
