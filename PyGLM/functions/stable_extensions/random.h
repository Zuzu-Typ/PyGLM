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

#define RANDOM_METHODS { "linearRand", (PyCFunction)linearRand_, METH_VARARGS, "linearRand(Min, Max) -> float or vecn\nGenerate random numbers in the interval [Min, Max], according a linear distribution" }, \
{ "gaussRand", (PyCFunction)gaussRand_, METH_VARARGS, "gaussRand(Mean, Deviation) -> float\nGenerate random numbers in the interval [Min, Max], according a gaussian distribution" }, \
{ "circularRand", (PyCFunction)circularRand_, METH_O, "circularRand(Radius) -> vec2\nGenerate a random 2D vector which coordinates are regulary distributed on a circle of a given radius" }, \
{ "sphericalRand", (PyCFunction)sphericalRand_, METH_O, "sphericalRand(Radius) -> vec3\nGenerate a random 3D vector which coordinates are regulary distributed on a sphere of a given radius" }, \
{ "diskRand", (PyCFunction)diskRand_, METH_O, "diskRand(Radius) -> vec2\nGenerate a random 2D vector which coordinates are regulary distributed within the area of a disk of a given radius" }, \
{ "ballRand", (PyCFunction)ballRand_, METH_O, "ballRand(Radius) -> vec3\nGenerate a random 3D vector which coordinates are regulary distributed within the area of a ball of a given radius" }
