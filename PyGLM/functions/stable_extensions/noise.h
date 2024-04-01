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
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
					case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
						return pack(glm::perlin(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2)));

					PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	else {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::perlin(PyGLM_Vec_Get(L, T, arg1))); \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::perlin(PyGLM_MVec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perlin()");
	return NULL;
}

static PyObject*
simplex_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::simplex(PyGLM_Vec_Get(L, T, arg))); \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::simplex(PyGLM_MVec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
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
