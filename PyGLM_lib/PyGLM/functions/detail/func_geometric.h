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
	"dot(x: number, y: number) -> float\n"
	"	Returns the dot product of `x` and `y`, i.e., `result = x * y`.\n"
	"dot(x: vecN, y: vecN) -> number\n"
	"	Returns the dot product of `x` and `y`, i.e., `result = x[0] * y[0] + x[1] * y[1] + ...`\n"
	"dot(x: quat, y: quat) -> float\n"
	"	Returns dot product of `x` and `y`, i.e., `x[0] * y[0] + x[1] * y[1] + ...`"
);

static PyObject*
dot_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "dot", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::custom::dot(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD | PyGLM_DT_I);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD | PyGLM_DT_I);
	if (PyGLM_PTI_IsVec(0)) {
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int32, arg1) && PyGLM_Vec_PTI_Check1(1, int32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, int32, arg1), PyGLM_Vec_PTI_Get1(1, int32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint32, arg1) && PyGLM_Vec_PTI_Check1(1, uint32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, uint32, arg1), PyGLM_Vec_PTI_Get1(1, uint32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int64, arg1) && PyGLM_Vec_PTI_Check1(1, int64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, int64, arg1), PyGLM_Vec_PTI_Get1(1, int64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint64, arg1) && PyGLM_Vec_PTI_Check1(1, uint64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, uint64, arg1), PyGLM_Vec_PTI_Get1(1, uint64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int16, arg1) && PyGLM_Vec_PTI_Check1(1, int16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, int16, arg1), PyGLM_Vec_PTI_Get1(1, int16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint16, arg1) && PyGLM_Vec_PTI_Check1(1, uint16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, uint16, arg1), PyGLM_Vec_PTI_Get1(1, uint16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int8, arg1) && PyGLM_Vec_PTI_Check1(1, int8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, int8, arg1), PyGLM_Vec_PTI_Get1(1, int8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, uint8, arg1) && PyGLM_Vec_PTI_Check1(1, uint8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(1, uint8, arg1), PyGLM_Vec_PTI_Get1(1, uint8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int32, arg1) && PyGLM_Vec_PTI_Check1(2, int32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, int32, arg1), PyGLM_Vec_PTI_Get1(2, int32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint32, arg1) && PyGLM_Vec_PTI_Check1(2, uint32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, uint32, arg1), PyGLM_Vec_PTI_Get1(2, uint32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int64, arg1) && PyGLM_Vec_PTI_Check1(2, int64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, int64, arg1), PyGLM_Vec_PTI_Get1(2, int64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint64, arg1) && PyGLM_Vec_PTI_Check1(2, uint64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, uint64, arg1), PyGLM_Vec_PTI_Get1(2, uint64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int16, arg1) && PyGLM_Vec_PTI_Check1(2, int16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, int16, arg1), PyGLM_Vec_PTI_Get1(2, int16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint16, arg1) && PyGLM_Vec_PTI_Check1(2, uint16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, uint16, arg1), PyGLM_Vec_PTI_Get1(2, uint16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int8, arg1) && PyGLM_Vec_PTI_Check1(2, int8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, int8, arg1), PyGLM_Vec_PTI_Get1(2, int8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint8, arg1) && PyGLM_Vec_PTI_Check1(2, uint8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(2, uint8, arg1), PyGLM_Vec_PTI_Get1(2, uint8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int32, arg1) && PyGLM_Vec_PTI_Check1(3, int32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, int32, arg1), PyGLM_Vec_PTI_Get1(3, int32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int64, arg1) && PyGLM_Vec_PTI_Check1(3, int64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, int64, arg1), PyGLM_Vec_PTI_Get1(3, int64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint64, arg1) && PyGLM_Vec_PTI_Check1(3, uint64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, uint64, arg1), PyGLM_Vec_PTI_Get1(3, uint64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int16, arg1) && PyGLM_Vec_PTI_Check1(3, int16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, int16, arg1), PyGLM_Vec_PTI_Get1(3, int16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint16, arg1) && PyGLM_Vec_PTI_Check1(3, uint16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, uint16, arg1), PyGLM_Vec_PTI_Get1(3, uint16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int8, arg1) && PyGLM_Vec_PTI_Check1(3, int8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, int8, arg1), PyGLM_Vec_PTI_Get1(3, int8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint8, arg1) && PyGLM_Vec_PTI_Check1(3, uint8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(3, uint8, arg1), PyGLM_Vec_PTI_Get1(3, uint8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int32, arg1) && PyGLM_Vec_PTI_Check1(4, int32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, int32, arg1), PyGLM_Vec_PTI_Get1(4, int32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint32, arg1) && PyGLM_Vec_PTI_Check1(4, uint32, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, uint32, arg1), PyGLM_Vec_PTI_Get1(4, uint32, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int64, arg1) && PyGLM_Vec_PTI_Check1(4, int64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, int64, arg1), PyGLM_Vec_PTI_Get1(4, int64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint64, arg1) && PyGLM_Vec_PTI_Check1(4, uint64, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, uint64, arg1), PyGLM_Vec_PTI_Get1(4, uint64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int16, arg1) && PyGLM_Vec_PTI_Check1(4, int16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, int16, arg1), PyGLM_Vec_PTI_Get1(4, int16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint16, arg1) && PyGLM_Vec_PTI_Check1(4, uint16, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, uint16, arg1), PyGLM_Vec_PTI_Get1(4, uint16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int8, arg1) && PyGLM_Vec_PTI_Check1(4, int8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, int8, arg1), PyGLM_Vec_PTI_Get1(4, int8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, uint8, arg1) && PyGLM_Vec_PTI_Check1(4, uint8, arg2)) {
			return pack(glm::custom::dot(PyGLM_Vec_PTI_Get0(4, uint8, arg1), PyGLM_Vec_PTI_Get1(4, uint8, arg2)));
		}
	}
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
		return pack(glm::custom::dot(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Qua_PTI_Get1(float, arg2)));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
		return pack(glm::custom::dot(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Qua_PTI_Get1(double, arg2)));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for dot(): ", arg1, arg2);
	return NULL;
}

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
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
		glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
		glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
		glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
		glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
		return pack(glm::cross(o, o2));
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
