#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
convertLinearToSRGB_(PyObject*, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertLinearToSRGB", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}
	if (PyGLM_Vec_Check(1, float, arg1)) {
		glm::vec1 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(2, float, arg1)) {
		glm::vec2 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(3, float, arg1)) {
		glm::vec3 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(4, float, arg1)) {
		glm::vec4 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(1, double, arg1)) {
		glm::dvec1 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(2, double, arg1)) {
		glm::dvec2 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(3, double, arg1)) {
		glm::dvec3 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_Check(4, double, arg1)) {
		glm::dvec4 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
	return NULL;
}

static PyObject*
convertSRGBToLinear_(PyObject*, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertSRGBToLinear", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
		return NULL;
	}
	if (PyGLM_Vec_Check(1, float, arg1)) {
		glm::vec1 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(2, float, arg1)) {
		glm::vec2 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(3, float, arg1)) {
		glm::vec3 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(4, float, arg1)) {
		glm::vec4 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(1, double, arg1)) {
		glm::dvec1 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(2, double, arg1)) {
		glm::dvec2 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(3, double, arg1)) {
		glm::dvec3 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_Check(4, double, arg1)) {
		glm::dvec4 o;
		unpack_vec(arg1, o);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
	return NULL;
}

#define COLOR_SPACE_METHODS { "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB_, METH_VARARGS, "convertLinearToSRGB(ColorLinear[, Gamma]) -> vecn\nConvert a linear color to sRGB color using a standard / custom gamma correction." }, \
{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear_, METH_VARARGS, "convertSRGBToLinear(ColorLinear[, Gamma]) -> vecn\nConvert a sRGB color to linear color using a standard / custom gamma correction." }
