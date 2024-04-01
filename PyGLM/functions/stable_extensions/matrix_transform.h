#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
identity_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg)) {
#define PyGLM_FUNC_TEMPLATE(C, R, T) \
		case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
			return pack(glm::identity<glm::mat<C, R, T> >());

		PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	if (!PyType_Check(arg)) {
		PyGLM_TYPEERROR_O("identity() requires a PyGLM matrix type as it's argument, not ", arg);
		return NULL;
	}
	PyErr_Format(PyExc_TypeError, "identity() requires a PyGLM matrix type as it's argument, not '%s'", ((PyTypeObject*)arg)->tp_name);
	return NULL;
}

static PyObject*
translate_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "translate", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::translate(glm::mat<L  + 1, L + 1, T>(1), PyGLM_Vec_Get(L, T, arg1))); \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::translate(glm::mat<L + 1, L + 1, T>(1), PyGLM_MVec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_2_AND_3(PyGLM_CODEGEN_PARAM_T_Vec_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	else {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg2)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				if (PyGLM_Mat_Check(L + 1, L + 1, T, arg1)) \
					return pack(glm::translate(PyGLM_Mat_Get(L + 1, L + 1, T, arg1), PyGLM_Vec_Get(L, T, arg2))); \
				break; \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				if (PyGLM_Mat_Check(L + 1, L + 1, T, arg1)) \
					return pack(glm::translate(PyGLM_Mat_Get(L + 1, L + 1, T, arg1), PyGLM_MVec_Get(L, T, arg2))); \
				break; 

			PyGLM_CODEGEN_PARAM_L_2_AND_3(PyGLM_CODEGEN_PARAM_T_Vec_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for translate(): ", arg1, arg2);
	return NULL;
}

static PyObject*
rotate_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "rotate", 1, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::rotate(glm::mat3(1), PyGLM_Number_FromPyObject<float>(arg1)));
		}
	}
	else if (arg3 == NULL) {
		if (Is_PyGLM_Object(arg2) && PyGLM_Number_Check(arg1)) {
			if (PyGLM_Vec_Check(3, float, arg2)) {
				return pack(glm::rotate(glm::mat<4, 4, float>(1), PyGLM_Number_FromPyObject<float>(arg1), PyGLM_VecOrMVec_GET(3, float, arg2)));
			}
			if (PyGLM_Vec_Check(3, double, arg2)) {
				return pack(glm::rotate(glm::mat<4, 4, double>(1), PyGLM_Number_FromPyObject<double>(arg1), PyGLM_VecOrMVec_GET(3, double, arg2)));
			}
		}
		else if (PyGLM_Number_Check(arg2)) {
			switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
			case PyGLMTypeObjectArrayOffsetMat<3, 3, float>():
				return pack(glm::rotate(PyGLM_Mat_Get(3, 3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
			case PyGLMTypeObjectArrayOffsetMat<3, 3, double>():
				return pack(glm::rotate(PyGLM_Mat_Get(3, 3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
			case PyGLMTypeObjectArrayOffsetVec<2, float>():
				return pack(glm::rotate(PyGLM_Vec_Get(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
			case PyGLMTypeObjectArrayOffsetVec<2, double>():
				return pack(glm::rotate(PyGLM_Vec_Get(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
			case PyGLMTypeObjectArrayOffsetMVec<2, float>():
				return pack(glm::rotate(PyGLM_MVec_Get(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
			case PyGLMTypeObjectArrayOffsetMVec<2, double>():
				return pack(glm::rotate(PyGLM_MVec_Get(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
			}
		}
	}
	else if (PyGLM_Number_Check(arg2)) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
		case PyGLMTypeObjectArrayOffsetMat<4, 4, float>():
			if (PyGLM_Vec_Check(3, float, arg3))
				return pack(glm::rotate(PyGLM_Mat_Get(4, 4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_VecOrMVec_GET(3, float, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetMat<4, 4, double>():
			if (PyGLM_Vec_Check(3, double, arg3))
				return pack(glm::rotate(PyGLM_Mat_Get(4, 4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_VecOrMVec_GET(3, double, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetQua<float>():
			if (PyGLM_Vec_Check(3, float, arg3))
				return pack(glm::rotate(PyGLM_Qua_Get(float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_VecOrMVec_GET(3, float, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetQua<double>():
			if (PyGLM_Vec_Check(3, double, arg3))
				return pack(glm::rotate(PyGLM_Qua_Get(double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_VecOrMVec_GET(3, double, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetVec<3, float>():
			if (PyGLM_Vec_Check(3, float, arg3))
				return pack(glm::rotate(PyGLM_Vec_Get(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_VecOrMVec_GET(3, float, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetVec<3, double>():
			if (PyGLM_Vec_Check(3, double, arg3))
				return pack(glm::rotate(PyGLM_Vec_Get(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_VecOrMVec_GET(3, double, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetMVec<3, float>():
			if (PyGLM_Vec_Check(3, float, arg3))
				return pack(glm::rotate(PyGLM_MVec_Get(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_VecOrMVec_GET(3, float, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetMVec<3, double>():
			if (PyGLM_Vec_Check(3, double, arg3))
				return pack(glm::rotate(PyGLM_MVec_Get(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_VecOrMVec_GET(3, double, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetVec<4, float>():
			if (PyGLM_Vec_Check(3, float, arg3))
				return pack(glm::rotate(PyGLM_Vec_Get(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_VecOrMVec_GET(3, float, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetVec<4, double>():
			if (PyGLM_Vec_Check(3, double, arg3))
				return pack(glm::rotate(PyGLM_Vec_Get(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_VecOrMVec_GET(3, double, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetMVec<4, float>():
			if (PyGLM_Vec_Check(3, float, arg3))
				return pack(glm::rotate(PyGLM_MVec_Get(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_VecOrMVec_GET(3, float, arg3)));
			break;
		case PyGLMTypeObjectArrayOffsetMVec<4, double>():
			if (PyGLM_Vec_Check(3, double, arg3))
				return pack(glm::rotate(PyGLM_MVec_Get(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_VecOrMVec_GET(3, double, arg3)));
			break;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate()");
	return NULL;
}

static PyObject*
rotate_slow_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "rotate_slow", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg2)) {
		if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Vec_Check(3, float, arg3)) {
			glm::mat<4, 4, float> m = PyGLM_Mat_Get(4, 4, float, arg1);
			glm::vec<3, float> axis = PyGLM_VecOrMVec_GET(3, float, arg3);
			return pack(glm::rotate_slow(m, PyGLM_Number_FromPyObject<float>(arg2), axis));
		}
		if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Vec_Check(3, double, arg3)) {
			glm::mat<4, 4, double> m = PyGLM_Mat_Get(4, 4, double, arg1);
			glm::vec<3, double> axis = PyGLM_VecOrMVec_GET(3, double, arg3);
			return pack(glm::rotate_slow(m, PyGLM_Number_FromPyObject<double>(arg2), axis));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate_slow()");
	return NULL;
}

static PyObject*
scale_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "scale", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::scale(glm::mat<L + 1, L + 1, T>(1), PyGLM_Vec_Get(L, T, arg1))); \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::scale(glm::mat<L + 1, L + 1, T>(1), PyGLM_MVec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_2_AND_3(PyGLM_CODEGEN_PARAM_T_Vec_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
		PyGLM_TYPEERROR_O("invalid argument type(s) for scale(): ", arg1);
		return NULL;
	}
	else {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg2)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				if (PyGLM_Mat_Check(L + 1, L + 1, T, arg1)) \
					return pack(glm::scale(PyGLM_Mat_Get(L + 1, L + 1, T, arg1), PyGLM_Vec_Get(L, T, arg1))); \
				break; \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				if (PyGLM_Mat_Check(L + 1, L + 1, T, arg1)) \
					return pack(glm::scale(PyGLM_Mat_Get(L + 1, L + 1, T, arg1), PyGLM_MVec_Get(L, T, arg1))); \
				break; 

			PyGLM_CODEGEN_PARAM_L_2_AND_3(PyGLM_CODEGEN_PARAM_T_Vec_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for scale(): ", arg1, arg2);
		return NULL;
	}
}

PyGLM_MAKE_GLM_FUNC_M4V3__tfF(scale_slow)

PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(lookAt)
PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(lookAtLH)
PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(lookAtRH)

PyDoc_STRVAR(identity_docstr,
	"identity(matrix_type: type) -> matNxM\n"
	"	Builds an identity matrix."
);
PyDoc_STRVAR(lookAt_docstr,
	"lookAt(eye: vec3, center: vec3, up: vec3) -> mat4x4\n"
	"	Build a look at view matrix based on the default handedness."
);
PyDoc_STRVAR(lookAtLH_docstr,
	"lookAtLH(eye: vec3, center: vec3, up: vec3) -> mat4x4\n"
	"	Build a left handed look at view matrix."
);
PyDoc_STRVAR(lookAtRH_docstr,
	"lookAtRH(eye: vec3, center: vec3, up: vec3) -> mat4x4\n"
	"	Build a right handed look at view matrix."
);
PyDoc_STRVAR(rotate_docstr,
	"rotate(angle: number, axis: vec3) -> mat4x4\n"
	"	Builds a rotation 4 x 4 matrix created from an axis vector and an angle.\n"
	"rotate(angle: number) -> mat3x3\n"
	"	Builds a rotation 3 x 3 matrix created from an angle.\n"
	"rotate(m: mat4x4, angle: number, axis: vec3) -> mat4x4\n"
	"	Builds a rotation 4 x 4 matrix created from an axis vector and an angle.\n"
	"	`m` is the input matrix multiplied by this translation matrix\n"
	"rotate(m: mat3x3, angle: number) -> mat3x3\n"
	"	Builds a rotation 3 x 3 matrix created from an angle.\n"
	"	`m` is the input matrix multiplied by this translation matrix\n"
	"rotate(v: vec2, angle: float) -> vec2\n"
	"	Rotate a two dimensional vector.\n"
	"rotate(v: vec3, angle: float, normal: vec3) -> vec3\n"
	"	Rotate a three dimensional vector around an axis.\n"
	"rotate(v: vec4, angle: float, normal: vec3) -> vec4\n"
	"	Rotate a four dimensional vector around an axis.\n"
	"rotate(q: quat, angle: float, axis: vec3) -> quat\n"
	"	Rotates a quaternion from a vector of 3 components axis and an angle."
);
PyDoc_STRVAR(scale_docstr,
	"scale(v: vec3) -> mat4x4\n"
	"	Builds a scale 4 x 4 matrix created from 3 scalars.\n"
	"scale(v: vec2) -> mat3x3\n"
	"	Builds a scale 3 x 3 matrix created from a vector of 2 components.\n"
	"scale(m: mat4x4, v: vec3) -> mat4x4\n"
	"	Builds a scale 4 x 4 matrix created from 3 scalars.\n"
	"	`m` is the input matrix multiplied by this translation matrix\n"
	"scale(m: mat3x3, v: vec2) -> mat3x3\n"
	"	Builds a scale 3 x 3 matrix created from a vector of 2 components.\n"
	"	`m` is the input matrix multiplied by this translation matrix"
);
PyDoc_STRVAR(translate_docstr,
	"translate(v: vec3) -> mat4x4\n"
	"	Builds a translation 4 x 4 matrix created from a vector of 3 components.\n"
	"translate(v: vec2) -> mat3x3\n"
	"	Builds a translation 3 x 3 matrix created from a vector of 2 components.\n"
	"translate(m: mat4x4, v: vec3) -> mat4x4\n"
	"	Builds a translation 4 x 4 matrix created from a vector of 3 components.\n"
	"	`m` is the input matrix multiplied by this translation matrix\n"
	"translate(m: mat3x3, v: vec2) -> mat3x3\n"
	"	Builds a translation 3 x 3 matrix created from a vector of 2 components.\n"
	"	`m` is the input matrix multiplied by this translation matrix"
);
PyDoc_STRVAR(rotate_slow_docstr,
	"rotate_slow(m: mat4x4, angle: number, axis: vec3) -> mat4x4\n"
	"	Builds a rotation 4 x 4 matrix created from an axis vector and an angle."
);
PyDoc_STRVAR(scale_slow_docstr,
	"scale_slow(m: mat4x4, v: vec3) -> mat4x4\n"
	"	Builds a scale 4 x 4 matrix created from 3 scalars."
);

#define MATRIX_TRANSFORM_METHODS \
{ "identity", (PyCFunction)identity_, METH_O, identity_docstr }, \
{ "translate", (PyCFunction)translate_, METH_VARARGS, translate_docstr }, \
{ "rotate", (PyCFunction)rotate_, METH_VARARGS, rotate_docstr }, \
{ "rotate_slow", (PyCFunction)rotate_slow_, METH_VARARGS, rotate_slow_docstr }, \
{ "scale", (PyCFunction)scale_, METH_VARARGS, scale_docstr }, \
{ "scale_slow", (PyCFunction)scale_slow_, METH_VARARGS, scale_slow_docstr }, \
{ "lookAt", (PyCFunction)lookAt_, METH_VARARGS, lookAt_docstr }, \
{ "lookAtRH", (PyCFunction)lookAtRH_, METH_VARARGS, lookAtRH_docstr }, \
{ "lookAtLH", (PyCFunction)lookAtLH_, METH_VARARGS, lookAtLH_docstr }
