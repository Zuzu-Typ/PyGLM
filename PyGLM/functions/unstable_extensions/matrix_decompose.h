#pragma once

#include "../all.h"

static PyObject*
decompose_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	PyGLM_Arg_Unpack_6O(args, "decompose", arg1, arg2, arg3, arg4, arg5, arg6);
	if (Py_TYPE(arg1) == &hfmat4x4Type && Py_TYPE(arg2) == &hfvec3Type && Py_TYPE(arg3) == &hfquaType && Py_TYPE(arg4) == &hfvec3Type && Py_TYPE(arg5) == &hfvec3Type && Py_TYPE(arg6) == &hfvec4Type) {
		return pack(glm::decompose(((mat<4, 4, float>*)arg1)->super_type, ((vec<3, float>*)arg2)->super_type, ((qua<float>*)arg3)->super_type, ((vec<3, float>*)arg4)->super_type, ((vec<3, float>*)arg5)->super_type, ((vec<4, float>*)arg6)->super_type));
	}
	if (Py_TYPE(arg1) == &hdmat4x4Type && Py_TYPE(arg2) == &hdvec3Type && Py_TYPE(arg3) == &hdquaType && Py_TYPE(arg4) == &hdvec3Type && Py_TYPE(arg5) == &hdvec3Type && Py_TYPE(arg6) == &hdvec4Type) {
		return pack(glm::decompose(((mat<4, 4, double>*)arg1)->super_type, ((vec<3, double>*)arg2)->super_type, ((qua<double>*)arg3)->super_type, ((vec<3, double>*)arg4)->super_type, ((vec<3, double>*)arg5)->super_type, ((vec<4, double>*)arg6)->super_type));
	}
	PyErr_SetString(PyExc_TypeError, "Invalid argument types for decompose()");
	return NULL;
}

PyDoc_STRVAR(decompose_docstr,
	"decompose(modelMatrix: mat4, scale: vec3, orientation: quat, translation: vec3, skew: vec3,\n"
	"	perspective: vec4) -> bool\n"
	"	Decomposes a model matrix to translations, rotation and scale components.\n"
	"	Returns `True` on success."
);

#define DECOMPOSE_METHODS \
{ "decompose", (PyCFunction)decompose_, METH_VARARGS, decompose_docstr }
