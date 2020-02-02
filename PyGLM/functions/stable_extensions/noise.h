#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
perlin_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "perlin", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perlin()");
		return NULL;
	}
	if (arg2 != NULL) {
		if (PyGLM_Vec_Check(2, float, arg1) && PyGLM_Vec_Check(2, float, arg2)) {
			glm::vec<2, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
			glm::vec<3, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_Check(4, float, arg1) && PyGLM_Vec_Check(4, float, arg2)) {
			glm::vec<4, float> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_Check(2, double, arg1) && PyGLM_Vec_Check(2, double, arg2)) {
			glm::vec<2, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
			glm::vec<3, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_Check(4, double, arg1) && PyGLM_Vec_Check(4, double, arg2)) {
			glm::vec<4, double> o, o2;
			unpack_vec(arg1, o);
			unpack_vec(arg2, o2);
			return pack(glm::perlin(o, o2));
		}
	}
	else {
		if (PyGLM_Vec_Check(2, float, arg1)) {
			glm::vec<2, float> o;
			unpack_vec(arg1, o);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_Check(3, float, arg1)) {
			glm::vec<3, float> o;
			unpack_vec(arg1, o);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_Check(4, float, arg1)) {
			glm::vec<4, float> o;
			unpack_vec(arg1, o);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_Check(2, double, arg1)) {
			glm::vec<2, double> o;
			unpack_vec(arg1, o);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_Check(3, double, arg1)) {
			glm::vec<3, double> o;
			unpack_vec(arg1, o);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_Check(4, double, arg1)) {
			glm::vec<4, double> o;
			unpack_vec(arg1, o);
			return pack(glm::perlin(o));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perlin()");
	return NULL;
}

static PyObject*
simplex_(PyObject*, PyObject* arg) {
	if (PyGLM_Vec_Check(2, float, arg)) {
		glm::vec<2, float> o;
		unpack_vec(arg, o);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_Check(3, float, arg)) {
		glm::vec<3, float> o;
		unpack_vec(arg, o);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_Check(4, float, arg)) {
		glm::vec<4, float> o;
		unpack_vec(arg, o);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_Check(2, double, arg)) {
		glm::vec<2, double> o;
		unpack_vec(arg, o);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_Check(3, double, arg)) {
		glm::vec<3, double> o;
		unpack_vec(arg, o);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_Check(4, double, arg)) {
		glm::vec<4, double> o;
		unpack_vec(arg, o);
		return pack(glm::simplex(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for simplex(): ", arg);
	return NULL;
}

#define NOISE_METHODS { "perlin", (PyCFunction)perlin_, METH_VARARGS, "perlin(p[, rep]) -> float\nClassic or periodic perlin noise." }, \
{ "simplex", (PyCFunction)simplex_, METH_O, "simplex(p) -> float\nSimplex noise." }