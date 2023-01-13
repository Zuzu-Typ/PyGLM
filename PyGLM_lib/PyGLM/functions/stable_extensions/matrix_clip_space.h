#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
ortho_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5 = NULL, * arg6 = NULL;
	if (!PyArg_UnpackTuple(args, "ortho", 4, 6, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for ortho()");
		return NULL;
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
		if (arg5 != NULL && arg6 != NULL && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) return pack(glm::ortho(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3), PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5), PyGLM_Number_FromPyObject<float>(arg6)));
		if (arg5 == NULL && arg6 == NULL) return pack(glm::ortho(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3), PyGLM_Number_FromPyObject<float>(arg4)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for ortho()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoLH_ZO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoLH_NO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoRH_ZO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoRH_NO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoLH)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoZO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoRH)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(orthoNO)

PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustum)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumLH_ZO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumLH_NO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumRH_ZO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumRH_NO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumLH)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumZO)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumRH)
PyGLM_MAKE_GLM_FUNC_NNNNNN__tf(frustumNO)

PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspective)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveLH_ZO)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveLH_NO)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveRH_ZO)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveRH_NO)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveLH)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveZO)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveRH)
PyGLM_MAKE_GLM_FUNC_NNNN__tf(perspectiveNO)

static PyObject*
perspectiveFov_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFov", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFov() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFov(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFov()");
	return NULL;
}
static PyObject*
perspectiveFovLH_ZO_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovLH_ZO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovLH_ZO() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovLH_ZO(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovLH_ZO()");
	return NULL;
}
static PyObject*
perspectiveFovLH_NO_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovLH_NO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovLH_NO() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovLH_NO(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovLH_NO()");
	return NULL;
}
static PyObject*
perspectiveFovRH_ZO_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovRH_ZO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovRH_ZO() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovRH_ZO(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovRH_ZO()");
	return NULL;
}
static PyObject*
perspectiveFovRH_NO_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovRH_NO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovRH_NO() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovRH_NO(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovRH_NO()");
	return NULL;
}
static PyObject*
perspectiveFovLH_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovLH", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovLH() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovLH(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovLH()");
	return NULL;
}
static PyObject*
perspectiveFovZO_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovZO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovZO() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovZO(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovZO()");
	return NULL;
}
static PyObject*
perspectiveFovRH_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovRH", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovRH() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovRH(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovRH()");
	return NULL;
}
static PyObject*
perspectiveFovNO_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4, * arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovNO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_FromPyObject<float>(arg1), f2 = PyGLM_Number_FromPyObject<float>(arg2), f3 = PyGLM_Number_FromPyObject<float>(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovNO() must be greater than 0");
			return NULL;
		}
		return pack(glm::perspectiveFovNO(f, f2, f3, PyGLM_Number_FromPyObject<float>(arg4), PyGLM_Number_FromPyObject<float>(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovNO()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_NNN__tf(infinitePerspective)
PyGLM_MAKE_GLM_FUNC_NNN__tf(infinitePerspectiveLH)
PyGLM_MAKE_GLM_FUNC_NNN__tf(infinitePerspectiveRH)

static PyObject*
tweakedInfinitePerspective_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3, * arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "tweakedInfinitePerspective", 3, 4, &arg1, &arg2, &arg3, &arg4)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tweakedInfinitePerspective()");
		return NULL;
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		if (arg4 != NULL && PyGLM_Number_Check(arg4)) {
			return pack(glm::tweakedInfinitePerspective(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3), PyGLM_Number_FromPyObject<float>(arg4)));
		}
		return pack(glm::tweakedInfinitePerspective(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tweakedInfinitePerspective()");
	return NULL;
}

PyDoc_STRVAR(frustum_docstr,
	"frustum(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	See frustumRH_NO."
);
PyDoc_STRVAR(frustumLH_docstr,
	"frustumLH(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	See frustumLH_NO."
);
PyDoc_STRVAR(frustumLH_NO_docstr,
	"frustumLH_NO(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Creates a left handed frustum matrix. The near and far clip planes correspond to z\n"
	"	normalized device coordinates of `-1` and `+1` respectively.\n"
	"	(OpenGL clip volume definition)"
);
PyDoc_STRVAR(frustumLH_ZO_docstr,
	"frustumLH_ZO(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Creates a left handed frustum matrix. The near and far clip planes correspond to z\n"
	"	normalized device coordinates of `0` and `+1` respectively.\n"
	"	(Direct3D clip volume definition)"
);
PyDoc_STRVAR(frustumNO_docstr,
	"frustumNO(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	See frustumRH_NO."
);
PyDoc_STRVAR(frustumRH_docstr,
	"frustumRH(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	See frustumRH_NO."
);
PyDoc_STRVAR(frustumRH_NO_docstr,
	"frustumRH_NO(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Creates a right handed frustum matrix. The near and far clip planes correspond to z\n"
	"	normalized device coordinates of `-1` and `+1` respectively.\n"
	"	(OpenGL clip volume definition)"
);
PyDoc_STRVAR(frustumRH_ZO_docstr,
	"frustumRH_ZO(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Creates a right handed frustum matrix. The near and far clip planes correspond to z\n"
	"	normalized device coordinates of `0` and `+1` respectively.\n"
	"	(Direct3D clip volume definition)"
);
PyDoc_STRVAR(frustumZO_docstr,
	"frustumZO(left: float, right: float, bottom: float, top: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	See frustumRH_ZO."
);
PyDoc_STRVAR(infinitePerspective_docstr,
	"infinitePerspective(fovy: float, aspect: float, near: float) -> fmat4x4\n"
	"	See infinitePerspectiveRH."
);
PyDoc_STRVAR(infinitePerspectiveLH_docstr,
	"infinitePerspectiveLH(fovy: float, aspect: float, near: float) -> fmat4x4\n"
	"	Creates a matrix for a left handed, symmetric perspective-view frustum with far plane at\n"
	"	infinite."
);
PyDoc_STRVAR(infinitePerspectiveRH_docstr,
	"infinitePerspectiveRH(fovy: float, aspect: float, near: float) -> fmat4x4\n"
	"	Creates a matrix for a right handed, symmetric perspective-view frustum with far plane at\n"
	"	infinite."
);
PyDoc_STRVAR(ortho_docstr,
	"ortho(left: float, right: float, bottom: float, top: float) -> fmat4x4\n"
	"	Creates a matrix for projecting two-dimensional coordinates onto the screen.\n"
	"ortho(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	See orthoRH_NO."
);
PyDoc_STRVAR(orthoLH_docstr,
	"orthoLH(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	See orthoLH_NO."
);
PyDoc_STRVAR(orthoRH_docstr,
	"orthoRH(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	See orthoRH_NO."
);
PyDoc_STRVAR(orthoZO_docstr,
	"orthoZO(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	See orthoRH_ZO."
);
PyDoc_STRVAR(orthoNO_docstr,
	"orthoNO(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	See orthoRH_NO."
);
PyDoc_STRVAR(orthoLH_ZO_docstr,
	"orthoLH_ZO(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	Creates a matrix for an orthographic parallel viewing volume, using left-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device\n"
	"	coordinates of `0` and `+1` respectively.\n"
	"	(Direct3D clip volume definition)"
);
PyDoc_STRVAR(orthoLH_NO_docstr,
	"orthoLH_NO(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	Creates a matrix for an orthographic parallel viewing volume using left-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device coordinates of\n"
	"	`-1` and `+1` respectively.\n"
	"	(OpenGL clip volume definition)"
);
PyDoc_STRVAR(orthoRH_ZO_docstr,
	"orthoRH_ZO(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	Creates a matrix for an orthographic parallel viewing volume, using right-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device\n"
	"	coordinates of `0` and `+1` respectively.\n"
	"	(Direct3D clip volume definition)"
);
PyDoc_STRVAR(orthoRH_NO_docstr,
	"orthoRH_NO(left: float, right: float, bottom: float, top: float, zNear: float, zFar: float)\n"
	"	-> fmat4x4\n"
	"	Creates a matrix for an orthographic parallel viewing volume using right-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device coordinates of\n"
	"	`-1` and `+1` respectively.\n"
	"	(OpenGL clip volume definition)"
);
PyDoc_STRVAR(perspective_docstr,
	"perspective(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveRH_NO."
);
PyDoc_STRVAR(perspectiveRH_docstr,
	"perspectiveRH(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveRH_NO."
);
PyDoc_STRVAR(perspectiveNO_docstr,
	"perspectiveNO(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveRH_NO."
);
PyDoc_STRVAR(perspectiveLH_docstr,
	"perspectiveLH(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveLH_NO."
);
PyDoc_STRVAR(perspectiveZO_docstr,
	"perspectiveZO(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveRH_ZO."
);
PyDoc_STRVAR(perspectiveLH_NO_docstr,
	"perspectiveLH_NO(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	Creates a matrix for a left handed, symetric perspective-view frustum. The near and far\n"
	"	clip planes correspond to z normalized device coordinates of `-1` and `+1` respectively.\n"
	"	(OpenGL clip volume definition)"
);
PyDoc_STRVAR(perspectiveLH_ZO_docstr,
	"perspectiveLH_ZO(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	Creates a matrix for a left handed, symetric perspective-view frustum. The near and far\n"
	"	clip planes correspond to z normalized device coordinates of `0` and `+1` respectively.\n"
	"	(Direct3D clip volume definition)"
);
PyDoc_STRVAR(perspectiveRH_NO_docstr,
	"perspectiveRH_NO(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	Creates a matrix for a right handed, symetric perspective-view frustum. The near and far\n"
	"	clip planes correspond to z normalized device coordinates of `-1` and `+1` respectively.\n"
	"	(OpenGL clip volume definition)"
);
PyDoc_STRVAR(perspectiveRH_ZO_docstr,
	"perspectiveRH_ZO(fovy: float, aspect: float, near: float, far: float) -> fmat4x4\n"
	"	Creates a matrix for a right handed, symetric perspective-view frustum. The near and far\n"
	"	clip planes correspond to z normalized device coordinates of `0` and `+1` respectively.\n"
	"	(Direct3D clip volume definition)"
);
PyDoc_STRVAR(perspectiveFov_docstr,
	"perspectiveFov(fov: float, width: float, height: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveFovRH_NO."
);
PyDoc_STRVAR(perspectiveFovRH_docstr,
	"perspectiveFovRH(fov: float, width: float, height: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveFovRH_NO."
);
PyDoc_STRVAR(perspectiveFovNO_docstr,
	"perspectiveFovNO(fov: float, width: float, height: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveFovRH_NO."
);
PyDoc_STRVAR(perspectiveFovLH_docstr,
	"perspectiveFovLH(fov: float, width: float, height: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveFovLH_NO."
);
PyDoc_STRVAR(perspectiveFovZO_docstr,
	"perspectiveFovZO(fov: float, width: float, height: float, near: float, far: float) -> fmat4x4\n"
	"	See perspectiveFovRH_ZO."
);
PyDoc_STRVAR(perspectiveFovLH_NO_docstr,
	"perspectiveFovLH_NO(fov: float, width: float, height: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Builds a perspective projection matrix based on a field of view using left-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device coordinates of\n"
	"	`-1` and `+1` respectively. (OpenGL clip volume definition)"
);
PyDoc_STRVAR(perspectiveFovLH_ZO_docstr,
	"perspectiveFovLH_ZO(fov: float, width: float, height: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Builds a perspective projection matrix based on a field of view using left-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device coordinates of\n"
	"	`0` and `+1` respectively. (Direct3D clip volume definition)"
);
PyDoc_STRVAR(perspectiveFovRH_NO_docstr,
	"perspectiveFovRH_NO(fov: float, width: float, height: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Builds a perspective projection matrix based on a field of view using right-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device coordinates of\n"
	"	`-1` and `+1` respectively. (OpenGL clip volume definition)"
);
PyDoc_STRVAR(perspectiveFovRH_ZO_docstr,
	"perspectiveFovRH_ZO(fov: float, width: float, height: float, near: float, far: float)\n"
	"	-> fmat4x4\n"
	"	Builds a perspective projection matrix based on a field of view using right-handed\n"
	"	coordinates. The nearand far clip planes correspond to z normalized device coordinates of\n"
	"	`0` and `+1` respectively. (Direct3D clip volume definition)"
);
PyDoc_STRVAR(tweakedInfinitePerspective_docstr,
	"tweakedInfinitePerspective(fovy: float, aspect: float, near: float) -> fmat4x4\n"
	"	Creates a matrix for a symmetric perspective-view frustum with far plane at infinite for\n"
	"	graphics hardware that doesn't support depth clamping.\n"
	"tweakedInfinitePerspective(fovy: float, aspect: float, near: float, epsilon: float) -> fmat4x4\n"
	"	Creates a matrix for a symmetric perspective-view frustum with far plane at infinite for\n"
	"	graphics hardware that doesn't support depth clamping."
);

#define MATRIX_CLIP_SPACE_METHODS \
{ "ortho", (PyCFunction)ortho_, METH_VARARGS, ortho_docstr }, \
{ "orthoLH_ZO", (PyCFunction)orthoLH_ZO_, METH_VARARGS, orthoLH_ZO_docstr }, \
{ "orthoLH_NO", (PyCFunction)orthoLH_NO_, METH_VARARGS, orthoLH_NO_docstr }, \
{ "orthoRH_ZO", (PyCFunction)orthoRH_ZO_, METH_VARARGS, orthoRH_ZO_docstr }, \
{ "orthoRH_NO", (PyCFunction)orthoRH_NO_, METH_VARARGS, orthoRH_NO_docstr }, \
{ "orthoZO", (PyCFunction)orthoZO_, METH_VARARGS, orthoZO_docstr }, \
{ "orthoNO", (PyCFunction)orthoNO_, METH_VARARGS, orthoNO_docstr }, \
{ "orthoLH", (PyCFunction)orthoLH_, METH_VARARGS, orthoLH_docstr }, \
{ "orthoRH", (PyCFunction)orthoRH_, METH_VARARGS, orthoRH_docstr }, \
{ "frustum", (PyCFunction)frustum_, METH_VARARGS, frustum_docstr }, \
{ "frustumLH_ZO", (PyCFunction)frustumLH_ZO_, METH_VARARGS, frustumLH_ZO_docstr }, \
{ "frustumLH_NO", (PyCFunction)frustumLH_NO_, METH_VARARGS, frustumLH_NO_docstr }, \
{ "frustumRH_ZO", (PyCFunction)frustumRH_ZO_, METH_VARARGS, frustumRH_ZO_docstr }, \
{ "frustumRH_NO", (PyCFunction)frustumRH_NO_, METH_VARARGS, frustumRH_NO_docstr }, \
{ "frustumZO", (PyCFunction)frustumZO_, METH_VARARGS, frustumZO_docstr }, \
{ "frustumNO", (PyCFunction)frustumNO_, METH_VARARGS, frustumNO_docstr }, \
{ "frustumLH", (PyCFunction)frustumLH_, METH_VARARGS, frustumLH_docstr }, \
{ "frustumRH", (PyCFunction)frustumRH_, METH_VARARGS, frustumRH_docstr }, \
{ "perspective", (PyCFunction)perspective_, METH_VARARGS, perspective_docstr }, \
{ "perspectiveLH_ZO", (PyCFunction)perspectiveLH_ZO_, METH_VARARGS, perspectiveLH_ZO_docstr }, \
{ "perspectiveLH_NO", (PyCFunction)perspectiveLH_NO_, METH_VARARGS, perspectiveLH_NO_docstr }, \
{ "perspectiveRH_ZO", (PyCFunction)perspectiveRH_ZO_, METH_VARARGS, perspectiveRH_ZO_docstr }, \
{ "perspectiveRH_NO", (PyCFunction)perspectiveRH_NO_, METH_VARARGS, perspectiveRH_NO_docstr }, \
{ "perspectiveZO", (PyCFunction)perspectiveZO_, METH_VARARGS, perspectiveZO_docstr }, \
{ "perspectiveNO", (PyCFunction)perspectiveNO_, METH_VARARGS, perspectiveNO_docstr }, \
{ "perspectiveLH", (PyCFunction)perspectiveLH_, METH_VARARGS, perspectiveLH_docstr }, \
{ "perspectiveRH", (PyCFunction)perspectiveRH_, METH_VARARGS, perspectiveRH_docstr }, \
{ "perspectiveFov", (PyCFunction)perspectiveFov_, METH_VARARGS, perspectiveFov_docstr }, \
{ "perspectiveFovLH_ZO", (PyCFunction)perspectiveFovLH_ZO_, METH_VARARGS, perspectiveFovLH_ZO_docstr }, \
{ "perspectiveFovLH_NO", (PyCFunction)perspectiveFovLH_NO_, METH_VARARGS, perspectiveFovLH_NO_docstr }, \
{ "perspectiveFovRH_ZO", (PyCFunction)perspectiveFovRH_ZO_, METH_VARARGS, perspectiveFovRH_ZO_docstr }, \
{ "perspectiveFovRH_NO", (PyCFunction)perspectiveFovRH_NO_, METH_VARARGS, perspectiveFovRH_NO_docstr }, \
{ "perspectiveFovZO", (PyCFunction)perspectiveFovZO_, METH_VARARGS, perspectiveFovZO_docstr }, \
{ "perspectiveFovNO", (PyCFunction)perspectiveFovNO_, METH_VARARGS, perspectiveFovNO_docstr }, \
{ "perspectiveFovLH", (PyCFunction)perspectiveFovLH_, METH_VARARGS, perspectiveFovLH_docstr }, \
{ "perspectiveFovRH", (PyCFunction)perspectiveFovRH_, METH_VARARGS, perspectiveFovRH_docstr }, \
{ "infinitePerspective", (PyCFunction)infinitePerspective_, METH_VARARGS, infinitePerspective_docstr }, \
{ "infinitePerspectiveRH", (PyCFunction)infinitePerspectiveRH_, METH_VARARGS, infinitePerspectiveRH_docstr }, \
{ "infinitePerspectiveLH", (PyCFunction)infinitePerspectiveLH_, METH_VARARGS, infinitePerspectiveLH_docstr }, \
{ "tweakedInfinitePerspective", (PyCFunction)tweakedInfinitePerspective_, METH_VARARGS, tweakedInfinitePerspective_docstr }
