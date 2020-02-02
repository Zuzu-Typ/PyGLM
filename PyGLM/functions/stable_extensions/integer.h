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
	if (PyGLM_Vec_Check(1, float, arg)) {
		glm::vec<1, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(1, double, arg)) {
		glm::vec<1, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(2, float, arg)) {
		glm::vec<2, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(2, double, arg)) {
		glm::vec<2, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(3, float, arg)) {
		glm::vec<3, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(3, double, arg)) {
		glm::vec<3, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(4, float, arg)) {
		glm::vec<4, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::iround(o));
	}
	if (PyGLM_Vec_Check(4, double, arg)) {
		glm::vec<4, double> o;
		unpack_vec(arg, o);
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
	if (PyGLM_Vec_Check(1, float, arg)) {
		glm::vec<1, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(1, double, arg)) {
		glm::vec<1, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<1, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(2, float, arg)) {
		glm::vec<2, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(2, double, arg)) {
		glm::vec<2, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<2, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(3, float, arg)) {
		glm::vec<3, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(3, double, arg)) {
		glm::vec<3, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<3, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(4, float, arg)) {
		glm::vec<4, float> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, float>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	if (PyGLM_Vec_Check(4, double, arg)) {
		glm::vec<4, double> o;
		unpack_vec(arg, o);
		PyGLM_ASSERT((glm::all(glm::lessThanEqual(glm::vec<4, double>(0), o))), "x has to be greater than or equal to 0");
		return pack(glm::uround(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for uround(): ", arg);
	return NULL;
}

#define INTEGER_METHODS { "iround", (PyCFunction)iround_, METH_O, "iround(x) -> int or ivec\nReturns a value equal to the nearest integer to x." }, \
{ "uround", (PyCFunction)uround_, METH_O, "uround(x) -> int or uvec\nReturns a value equal to the nearest integer to x." }