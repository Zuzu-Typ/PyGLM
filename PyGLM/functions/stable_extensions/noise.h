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
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			PyGLM_Vec_PTI_Assign0(2, float);
			PyGLM_Vec_PTI_Assign1(2, float);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			PyGLM_Vec_PTI_Assign0(3, float);
			PyGLM_Vec_PTI_Assign1(3, float);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			PyGLM_Vec_PTI_Assign0(4, float);
			PyGLM_Vec_PTI_Assign1(4, float);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			PyGLM_Vec_PTI_Assign0(2, double);
			PyGLM_Vec_PTI_Assign1(2, double);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			PyGLM_Vec_PTI_Assign0(3, double);
			PyGLM_Vec_PTI_Assign1(3, double);
			return pack(glm::perlin(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			PyGLM_Vec_PTI_Assign0(4, double);
			PyGLM_Vec_PTI_Assign1(4, double);
			return pack(glm::perlin(o, o2));
		}
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			PyGLM_Vec_PTI_Assign0(2, float);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			PyGLM_Vec_PTI_Assign0(3, float);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
			PyGLM_Vec_PTI_Assign0(4, float);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			PyGLM_Vec_PTI_Assign0(2, double);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			PyGLM_Vec_PTI_Assign0(3, double);
			return pack(glm::perlin(o));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
			PyGLM_Vec_PTI_Assign0(4, double);
			return pack(glm::perlin(o));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perlin()");
	return NULL;
}

static PyObject*
simplex_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		PyGLM_Vec_PTI_Assign(2, float);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		PyGLM_Vec_PTI_Assign(3, float);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		PyGLM_Vec_PTI_Assign(4, float);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg)) {
		PyGLM_Vec_PTI_Assign(2, double);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg)) {
		PyGLM_Vec_PTI_Assign(3, double);
		return pack(glm::simplex(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg)) {
		PyGLM_Vec_PTI_Assign(4, double);
		return pack(glm::simplex(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for simplex(): ", arg);
	return NULL;
}

PyDoc_STRVAR(perlin_docstr, 
	"perlin(p: vecN) -> float\n"
	"	Classic perlin noise.\n"
	"perlin(p: vecN, rep: vecN) -> float\n"
	"	Periodic perlin noise."
);
PyDoc_STRVAR(simplex_docstr,
	"simplex(p: vecN) -> float\n"
	"	Simplex noise."
);

#define NOISE_METHODS \
{ "perlin", (PyCFunction)perlin_, METH_VARARGS, perlin_docstr }, \
{ "simplex", (PyCFunction)simplex_, METH_O, simplex_docstr }
