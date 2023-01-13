#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
iround_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		double d = PyGLM_Number_FromPyObject<double>(arg);
		PyGLM_ASSERT((0.0 <= d), "x has to be greater than or equal to 0");
		return pack(glm::iround(d));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for iround(): ", arg);
	return NULL;
}

static PyObject*
uround_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		double d = PyGLM_Number_FromPyObject<double>(arg);
		PyGLM_ASSERT((0.0 <= d), "x has to be greater than or equal to 0");
		return pack(glm::uround(d));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for uround(): ", arg);
	return NULL;
}

PyDoc_STRVAR(iround_docstr,
	"iround(x: number) -> int\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest.\n"
	"iround(x: vecN) -> ivecN\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest."
);
PyDoc_STRVAR(uround_docstr,
	"uround(x: number) -> int\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest.\n"
	"uround(x: vecN) -> uvecN\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest."
);

#define INTEGER_METHODS \
{ "iround", (PyCFunction)iround_, METH_O, iround_docstr }, \
{ "uround", (PyCFunction)uround_, METH_O, uround_docstr }
