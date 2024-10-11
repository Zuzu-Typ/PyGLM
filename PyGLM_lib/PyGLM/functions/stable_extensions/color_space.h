#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(convertLinearToSRGB_docstr,
	"convertLinearToSRGB(ColorLinear: vecN) -> vecN\n"
	"	Convert a linear color to sRGB color using a standard gamma correction.\n"
	"convertLinearToSRGB(ColorLinear: vecN, Gamma: number) -> vecN\n"
	"	Convert a linear color to sRGB color using a custom gamma correction."
);
static PyObject*
convertLinearToSRGB_(PyObject*, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertLinearToSRGB", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
		glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
		glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertLinearToSRGB(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertLinearToSRGB(o));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
	return NULL;
}

PyDoc_STRVAR(convertSRGBToLinear_docstr,
	"convertSRGBToLinear(ColorLinear: vecN) -> vecN\n"
	"	Convert a sRGB color to linear color using a standard gamma correction.\n"
	"convertSRGBToLinear(ColorLinear: vecN, Gamma: number) -> vecN\n"
	"	Convert a sRGB color to linear color using a custom gamma correction."
);
static PyObject*
convertSRGBToLinear_(PyObject*, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertSRGBToLinear", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
		return NULL;
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
		glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<float>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
		glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			return pack(glm::convertSRGBToLinear(o, PyGLM_Number_FromPyObject<double>(arg2)));
		}
		return pack(glm::convertSRGBToLinear(o));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
	return NULL;
}

#define COLOR_SPACE_METHODS \
{ "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB_, METH_VARARGS, convertLinearToSRGB_docstr }, \
{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear_, METH_VARARGS, convertSRGBToLinear_docstr }
