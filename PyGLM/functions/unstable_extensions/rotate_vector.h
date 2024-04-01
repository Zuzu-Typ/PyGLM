#pragma once

#include "../all.h"

static PyObject*
orientation_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "orientation", arg1, arg2);

	if (PyGLM_Vec_Check(3, float, arg1) && PyGLM_Vec_Check(3, float, arg2)) {
		return pack(glm::orientation(PyGLM_VecOrMVec_GET(3, float, arg1), PyGLM_VecOrMVec_GET(3, float, arg2)));
	}
	if (PyGLM_Vec_Check(3, double, arg1) && PyGLM_Vec_Check(3, double, arg2)) {
		return pack(glm::orientation(PyGLM_VecOrMVec_GET(3, double, arg1), PyGLM_VecOrMVec_GET(3, double, arg2)));
	}

	PyGLM_TYPEERROR_2O("invalid argument types for orientation(). Expected vec3, got ", arg1, arg2);
	return NULL;
}

static PyObject*
rotateX_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "rotateX", arg1, arg2);

	if (PyGLM_Number_Check(arg2)) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::rotateX(PyGLM_Vec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::rotateX(PyGLM_MVec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

			PyGLM_CODEGEN_PARAM_L_3_AND_4(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}

	PyGLM_TYPEERROR_2O("invalid argument types for rotateX(). Expected vec3/vec4 and a number, got ", arg1, arg2);
	return NULL;
}

static PyObject*
rotateY_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "rotateY", arg1, arg2);

	if (PyGLM_Number_Check(arg2)) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::rotateY(PyGLM_Vec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::rotateY(PyGLM_MVec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

			PyGLM_CODEGEN_PARAM_L_3_AND_4(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}

	PyGLM_TYPEERROR_2O("invalid argument types for rotateY(). Expected vec3/vec4 and a number, got ", arg1, arg2);
	return NULL;
}

static PyObject*
rotateZ_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "rotateZ", arg1, arg2);

	if (PyGLM_Number_Check(arg2)) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::rotateZ(PyGLM_Vec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));\
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::rotateZ(PyGLM_MVec_Get(L, T, arg1), PyGLM_Number_FromPyObject<T>(arg2)));

			PyGLM_CODEGEN_PARAM_L_3_AND_4(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}

	PyGLM_TYPEERROR_2O("invalid argument types for rotateZ(). Expected vec3/vec4 and a number, got ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(orientation_docstr,
	"orientation(Normal: vec3, Up: vec3) -> mat4\n"
	"	Build a rotation matrix from a normal and a up vector."
);

PyDoc_STRVAR(rotateX_docstr,
	"rotateX(v: vec3, angle: float) -> vec3\n"
	"	Rotate a three dimensional vector around the X axis.\n"
	"rotateX(v: vec4, angle: float) -> vec3\n"
	"	Rotate a four dimensional vector around the X axis."
);
PyDoc_STRVAR(rotateY_docstr,
	"rotateY(v: vec3, angle: float) -> vec3\n"
	"	Rotate a three dimensional vector around the Y axis.\n"
	"rotateY(v: vec4, angle: float) -> vec3\n"
	"	Rotate a four dimensional vector around the Y axis."
);
PyDoc_STRVAR(rotateZ_docstr,
	"rotateZ(v: vec3, angle: float) -> vec3\n"
	"	Rotate a three dimensional vector around the Z axis.\n"
	"rotateZ(v: vec4, angle: float) -> vec3\n"
	"	Rotate a four dimensional vector around the Z axis."
);


#define ROTATE_VECTOR_METHODS \
{ "orientation", (PyCFunction)orientation_, METH_VARARGS, orientation_docstr }, \
{ "rotateX", (PyCFunction)rotateX_, METH_VARARGS, rotateX_docstr }, \
{ "rotateY", (PyCFunction)rotateY_, METH_VARARGS, rotateY_docstr }, \
{ "rotateZ", (PyCFunction)rotateZ_, METH_VARARGS, rotateZ_docstr }
