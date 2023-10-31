#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_NN_VV__tGPL(linearRand)
PyGLM_MAKE_GLM_FUNC_NN_VV__tGPL(gaussRand)

static PyObject*
circularRand_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "circularRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack(glm::circularRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for circularRand(): ", arg);
	return NULL;
}

static PyObject*
sphericalRand_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "sphericalRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack(glm::sphericalRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for sphericalRand(): ", arg);
	return NULL;
}

static PyObject*
diskRand_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "diskRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack(glm::diskRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for diskRand(): ", arg);
	return NULL;
}

static PyObject*
ballRand_(PyObject*, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "ballRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack(glm::ballRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for ballRand(): ", arg);
	return NULL;
}

static PyObject*
setSeed_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		unsigned long seed = PyLong_AsUnsignedLong(arg);
		std::srand(seed);
		Py_RETURN_NONE;
	}
	PyGLM_TYPEERROR_O("invalid argument type for setSeed(): ", arg);
	return NULL;
}

PyDoc_STRVAR(ballRand_docstr,
	"ballRand(Radius: float) -> vec3\n"
	"	Generate a random 3D vector which coordinates are regulary distributed within the volume of\n"
	"	a ball of a given radius."
);
PyDoc_STRVAR(circularRand_docstr,
	"circularRand(Radius: float) -> vec2\n"
	"	Generate a random 2D vector which coordinates are regulary distributed on a circle of a\n"
	"	given radius."
);
PyDoc_STRVAR(diskRand_docstr,
	"diskRand(Radius: float) -> vec2\n"
	"	Generate a random 2D vector which coordinates are regulary distributed within the area of\n"
	"	a disk of a given radius."
);
PyDoc_STRVAR(gaussRand_docstr,
	"gaussRand(Mean: float, Deviation: float) -> float\n"
	"	Generate random numbers in the interval `[Min, Max]`, according a gaussian distribution.\n"
	"gaussRand(Mean: vecN, Deviation: vecN) -> vecN\n"
	"	Generate random numbers in the interval `[Min, Max]`, according a gaussian distribution."
);
PyDoc_STRVAR(linearRand_docstr,
	"linearRand(Min: float, Max: float) -> float\n"
	"	Generate random numbers in the interval `[Min, Max]`, according a linear distribution.\n"
	"linearRand(Min: vecN, Max: vecN) -> vecN\n"
	"	Generate random numbers in the interval `[Min, Max]`, according a linear distribution."
);
PyDoc_STRVAR(sphericalRand_docstr,
	"sphericalRand(Radius: float) -> vec3\n"
	"	Generate a random 3D vector which coordinates are regulary distributed on a sphere of a\n"
	"	given radius."
);
PyDoc_STRVAR(setSeed_docstr,
	"setSeed(seed: int) -> None\n"
	"	Sets the seed fot the pseudo-random number generator used by the -Rand functions.\n"
	"	The seed needs to be greater or equal to zero.\n"
	"	Default seed is `1`.\n"
);

#define RANDOM_METHODS \
{ "linearRand", (PyCFunction)linearRand_, METH_VARARGS, linearRand_docstr }, \
{ "gaussRand", (PyCFunction)gaussRand_, METH_VARARGS, gaussRand_docstr }, \
{ "circularRand", (PyCFunction)circularRand_, METH_O, circularRand_docstr }, \
{ "sphericalRand", (PyCFunction)sphericalRand_, METH_O, sphericalRand_docstr }, \
{ "diskRand", (PyCFunction)diskRand_, METH_O, diskRand_docstr }, \
{ "ballRand", (PyCFunction)ballRand_, METH_O, ballRand_docstr }, \
{ "setSeed", (PyCFunction)setSeed_, METH_O, setSeed_docstr }
