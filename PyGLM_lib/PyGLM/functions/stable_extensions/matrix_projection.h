#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(project)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(projectZO)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(projectNO)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(unProject)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(unProjectZO)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(unProjectNO)

static PyObject*
pickMatrix_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3;
	PyGLM_Arg_Unpack_3O(args, "pickMatrix", arg1, arg2, arg3);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD);
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		PyGLM_Vec_PTI_Assign0(2, float);
		PyGLM_Vec_PTI_Assign1(2, float);
		PyGLM_Vec_PTI_Assign2(4, float);
		if (!(o2.x > 0.0f && o2.y > 0.0f)) {
			PyErr_SetString(PyExc_ValueError, "delta has to be greater than 0 for pickMatrix()");
			return NULL;
		}
		return pack(glm::pickMatrix(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		PyGLM_Vec_PTI_Assign0(2, double);
		PyGLM_Vec_PTI_Assign1(2, double);
		PyGLM_Vec_PTI_Assign2(4, double);
		if (!(o2.x > 0.0 && o2.y > 0.0)) {
			PyErr_SetString(PyExc_ValueError, "delta has to be greater than 0 for pickMatrix()");
			return NULL;
		}
		return pack(glm::pickMatrix(o, o2, o3));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for pickMatrix()");
	return NULL;
}

PyDoc_STRVAR(pickMatrix_docstr,
	"pickMatrix(center: vec2, delta: vec2, viewport: vec4) -> mat4\n"
	"	Define a picking region."
);
PyDoc_STRVAR(project_docstr,
	"project(obj: vec3, model: mat4, proj: mat4, viewport: vec4) -> vec3\n"
	"	See projectNO()."
);
PyDoc_STRVAR(projectNO_docstr,
	"projectNO(obj: vec3, model: mat4, proj: mat4, viewport: vec4) -> vec3\n"
	"	Map the specified object coordinates `(obj.x, obj.y, obj.z)` into window coordinates.\n"
	"	The near and far clip planes correspond to z normalized device coordinates of `-1` and `+1`\n"
	"	respectively. (OpenGL clip volume definition)"
);
PyDoc_STRVAR(projectZO_docstr,
	"projectZO(obj: vec3, model: mat4, proj: mat4, viewport: vec4) -> vec3\n"
	"	Map the specified object coordinates `(obj.x, obj.y, obj.z)` into window coordinates.\n"
	"	The nearand far clip planes correspond to z normalized device coordinates of `0` and `+1`\n"
	"	respectively. (Direct3D clip volume definition)"
);
PyDoc_STRVAR(unProject_docstr,
	"unProject(win: vec3, model: mat4, proj: mat4, viewport: vec4) -> vec3\n"
	"	See unProjectNO()."
);
PyDoc_STRVAR(unProjectNO_docstr,
	"unProjectNO(win: vec3, model: mat4, proj: mat4, viewport: vec4) -> vec3\n"
	"	Map the specified window coordinates `(win.x, win.y, win.z)` into object coordinates.\n"
	"	The nearand far clip planes correspond to z normalized device coordinates of `-1` and `+1`\n"
	"	respectively. (OpenGL clip volume definition)"
);
PyDoc_STRVAR(unProjectZO_docstr,
	"unProjectZO(win: vec3, model: mat4, proj: mat4, viewport: vec4) -> vec3\n"
	"	Map the specified window coordinates `(win.x, win.y, win.z)` into object coordinates.\n"
	"	The nearand far clip planes correspond to z normalized device coordinates of `0` and `+1`\n"
	"	respectively. (Direct3D clip volume definition)"
);

#define MATRIX_PROJECTION_METHODS \
{ "project", (PyCFunction)project_, METH_VARARGS, project_docstr }, \
{ "projectNO", (PyCFunction)projectNO_, METH_VARARGS, projectNO_docstr }, \
{ "projectZO", (PyCFunction)projectZO_, METH_VARARGS, projectZO_docstr }, \
{ "unProject", (PyCFunction)unProject_, METH_VARARGS, unProject_docstr }, \
{ "unProjectNO", (PyCFunction)unProjectNO_, METH_VARARGS, unProjectNO_docstr }, \
{ "unProjectZO", (PyCFunction)unProjectZO_, METH_VARARGS, unProjectZO_docstr },  \
{ "pickMatrix", (PyCFunction)pickMatrix_, METH_VARARGS, pickMatrix_docstr }
