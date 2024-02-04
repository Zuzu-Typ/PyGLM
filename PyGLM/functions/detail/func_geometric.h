#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"


PyDoc_STRVAR(length_docstr,
	"length(x: float) -> float\n"
	"	Returns the length of `x`, i.e., `abs(x)`.\n"
	"length(x: vecN) -> float\n"
	"	Returns the length of `x`, i.e., `sqrt(x * x)`.\n"
	"length(x: quat) -> float\n"
	"	Returns the norm of a quaternion."
);
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(length)

PyDoc_STRVAR(distance_docstr,
	"distance(p0: float, p1: float) -> float\n"
	"	Returns the distance between `p0` and `p1`, i.e., `length(p0 - p1)`.\n"
	"distance(p0: vecN, p1: vecN) -> float\n"
	"	Returns the distance between `p0` and `p1`, i.e., `length(p0 - p1)`."
);
PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(distance)

PyDoc_STRVAR(dot_docstr,
	"dot(x: float, y: float) -> float\n"
	"	Returns the dot product of `x` and `y`, i.e., `result = x * y`.\n"
	"dot(x: vecN, y: vecN) -> float\n"
	"	Returns the dot product of `x` and `y`, i.e., `result = x[0] * y[0] + x[1] * y[1] + ...`\n"
	"dot(x: quat, y: quat) -> float\n"
	"	Returns dot product of `x` and `y`, i.e., `x[0] * y[0] + x[1] * y[1] + ...`"
);
PyGLM_MAKE_GLM_FUNC_NN_VV_QQ__tfF(dot)

PyDoc_STRVAR(cross_docstr,
	"cross(x: vec3, y: vec3) -> vec3\n"
	"	Returns the cross product of `x` and `y`.\n"
	"cross(x: quat, y: quat) -> quat\n"
	"	Compute a cross product."
);
static PyObject*
cross_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "cross", arg1, arg2);
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);

		if (arg1Subtype == arg2Subtype) {
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::cross(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2)));

				PyGLM_CODEGEN_PARAM_T_Vec_fF(PyGLM_FUNC_TEMPLATE, 3)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::cross(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2)));

					PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for cross(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(normalize_docstr,
	"normalize(x: vecN) -> vecN\n"
	"	Returns a vector in the same direction as `x` but with length of `1`.\n"
	"normalize(x: quat) -> quat\n"
	"	Returns the normalized quaternion."
);
PyGLM_MAKE_GLM_FUNC_V_Q__tfF(normalize)

PyDoc_STRVAR(faceforward_docstr,
	"faceforward(N: float, I: float, Nref: float) -> float\n"
	"	If `dot(Nref, I) < 0.0`, return `N`, otherwise, return `-N`.\n"
	"faceforward(N: vecN, I: vecN, Nref: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	If `dot(Nref[i], I[i]) < 0.0`, return `N[i]`, otherwise, return `-N[i]`."
);
PyGLM_MAKE_GLM_FUNC_NNN_VVV__tfF(faceforward)

PyDoc_STRVAR(reflect_docstr,
	"reflect(I: float, N: float) -> float\n"
	"	For the incident vector `I` and surface orientation `N`, returns the reflection direction:\n"
	"	`result = I - 2.0 * dot(N, I) * N`.\n"
	"reflect(I: vecN, N: vecN) -> vecN\n"
	"	For the incident vector `I` and surface orientation `N`, returns the reflection direction:\n"
	"	`result = I - 2.0 * dot(N, I) * N`."
);
PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(reflect)

PyDoc_STRVAR(refract_docstr,
	"refract(I: float, N: float, eta: float) -> float\n"
	"	For the incident vector `I` and surface normal `N`, and the ratio of indices of refraction `eta`,\n"
	"	return the refraction vector.\n"
	"refract(I: vecN, N: vecN, eta: float) -> vecN\n"
	"	For the incident vector `I` and surface normal `N`, and the ratio of indices of refraction `eta`,\n"
	"	return the refraction vector."
);
PyGLM_MAKE_GLM_FUNC_NNN_VVN__tfF(refract)

#define FUNC_GEOMETRIC_METHODS \
{ "length", (PyCFunction)length_, METH_O, length_docstr }, \
{ "distance", (PyCFunction)distance_, METH_VARARGS, distance_docstr }, \
{ "dot", (PyCFunction)dot_, METH_VARARGS, dot_docstr }, \
{ "cross", (PyCFunction)cross_, METH_VARARGS, cross_docstr }, \
{ "normalize", (PyCFunction)normalize_, METH_O, normalize_docstr }, \
{ "faceforward", (PyCFunction)faceforward_, METH_VARARGS, faceforward_docstr }, \
{ "reflect", (PyCFunction)reflect_, METH_VARARGS, reflect_docstr }, \
{ "refract", (PyCFunction)refract_, METH_VARARGS, refract_docstr }
