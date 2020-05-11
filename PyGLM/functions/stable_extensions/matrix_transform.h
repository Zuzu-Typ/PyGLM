#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
identity_(PyObject*, PyObject* arg) {
	if (!PyType_Check(arg)) {
		PyGLM_TYPEERROR_O("identity() requires a PyGLM matrix type as it's argument, not ", arg);
		return NULL;
	}
	if (arg == (PyObject*)&hfmat2x2Type) {
		return pack(glm::identity<glm::mat<2, 2, float> >());
	}
	if (arg == (PyObject*)&hdmat2x2Type) {
		return pack(glm::identity<glm::mat<2, 2, double> >());
	}
	if (arg == (PyObject*)&himat2x2Type) {
		return pack(glm::identity<glm::mat<2, 2, int> >());
	}
	if (arg == (PyObject*)&humat2x2Type) {
		return pack(glm::identity<glm::mat<2, 2, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat2x3Type) {
		return pack(glm::identity<glm::mat<2, 3, float> >());
	}
	if (arg == (PyObject*)&hdmat2x3Type) {
		return pack(glm::identity<glm::mat<2, 3, double> >());
	}
	if (arg == (PyObject*)&himat2x3Type) {
		return pack(glm::identity<glm::mat<2, 3, int> >());
	}
	if (arg == (PyObject*)&humat2x3Type) {
		return pack(glm::identity<glm::mat<2, 3, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat2x4Type) {
		return pack(glm::identity<glm::mat<2, 4, float> >());
	}
	if (arg == (PyObject*)&hdmat2x4Type) {
		return pack(glm::identity<glm::mat<2, 4, double> >());
	}
	if (arg == (PyObject*)&himat2x4Type) {
		return pack(glm::identity<glm::mat<2, 4, int> >());
	}
	if (arg == (PyObject*)&humat2x4Type) {
		return pack(glm::identity<glm::mat<2, 4, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat3x2Type) {
		return pack(glm::identity<glm::mat<3, 2, float> >());
	}
	if (arg == (PyObject*)&hdmat3x2Type) {
		return pack(glm::identity<glm::mat<3, 2, double> >());
	}
	if (arg == (PyObject*)&himat3x2Type) {
		return pack(glm::identity<glm::mat<3, 2, int> >());
	}
	if (arg == (PyObject*)&humat3x2Type) {
		return pack(glm::identity<glm::mat<3, 2, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat3x3Type) {
		return pack(glm::identity<glm::mat<3, 3, float> >());
	}
	if (arg == (PyObject*)&hdmat3x3Type) {
		return pack(glm::identity<glm::mat<3, 3, double> >());
	}
	if (arg == (PyObject*)&himat3x3Type) {
		return pack(glm::identity<glm::mat<3, 3, int> >());
	}
	if (arg == (PyObject*)&humat3x3Type) {
		return pack(glm::identity<glm::mat<3, 3, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat3x4Type) {
		return pack(glm::identity<glm::mat<3, 4, float> >());
	}
	if (arg == (PyObject*)&hdmat3x4Type) {
		return pack(glm::identity<glm::mat<3, 4, double> >());
	}
	if (arg == (PyObject*)&himat3x4Type) {
		return pack(glm::identity<glm::mat<3, 4, int> >());
	}
	if (arg == (PyObject*)&humat3x4Type) {
		return pack(glm::identity<glm::mat<3, 4, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat4x2Type) {
		return pack(glm::identity<glm::mat<4, 2, float> >());
	}
	if (arg == (PyObject*)&hdmat4x2Type) {
		return pack(glm::identity<glm::mat<4, 2, double> >());
	}
	if (arg == (PyObject*)&himat4x2Type) {
		return pack(glm::identity<glm::mat<4, 2, int> >());
	}
	if (arg == (PyObject*)&humat4x2Type) {
		return pack(glm::identity<glm::mat<4, 2, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat4x3Type) {
		return pack(glm::identity<glm::mat<4, 3, float> >());
	}
	if (arg == (PyObject*)&hdmat4x3Type) {
		return pack(glm::identity<glm::mat<4, 3, double> >());
	}
	if (arg == (PyObject*)&himat4x3Type) {
		return pack(glm::identity<glm::mat<4, 3, int> >());
	}
	if (arg == (PyObject*)&humat4x3Type) {
		return pack(glm::identity<glm::mat<4, 3, glm::uint> >());
	}
	if (arg == (PyObject*)&hfmat4x4Type) {
		return pack(glm::identity<glm::mat<4, 4, float> >());
	}
	if (arg == (PyObject*)&hdmat4x4Type) {
		return pack(glm::identity<glm::mat<4, 4, double> >());
	}
	if (arg == (PyObject*)&himat4x4Type) {
		return pack(glm::identity<glm::mat<4, 4, int> >());
	}
	if (arg == (PyObject*)&humat4x4Type) {
		return pack(glm::identity<glm::mat<4, 4, glm::uint> >());
	}
	PyErr_Format(PyExc_TypeError, "identity() requires a PyGLM matrix type as it's argument, not '%s'", ((PyTypeObject*)arg)->tp_name);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_M4V3__tfF(translate)

static PyObject*
rotate_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "rotate", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg2)) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::mat4x4 m = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::vec3 axis = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack(glm::rotate(m, PyGLM_Number_FromPyObject<float>(arg2), axis));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::dmat4x4 m = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::dvec3 axis = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack(glm::rotate(m, PyGLM_Number_FromPyObject<double>(arg2), axis));
		}
		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::quat q = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::vec3 axis = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_qua(glm::rotate(q, PyGLM_Number_FromPyObject<float>(arg2), axis));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::dquat q = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::dvec3 axis = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_qua(glm::rotate(q, PyGLM_Number_FromPyObject<double>(arg2), axis));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate()");
	return NULL;
}

static PyObject*
rotate_slow_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "rotate_slow", arg1, arg2, arg3);
	PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	if (PyGLM_Number_Check(arg2)) {
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::mat<4, 4, float> m = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::vec<3, float> axis = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack(glm::rotate_slow(m, PyGLM_Number_FromPyObject<float>(arg2), axis));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::mat<4, 4, double> m = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::vec<3, double> axis = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack(glm::rotate_slow(m, PyGLM_Number_FromPyObject<double>(arg2), axis));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate_slow()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_M4V3__tfF(scale)
PyGLM_MAKE_GLM_FUNC_M4V3__tfF(scale_slow)

static PyObject*
ortho_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5 = NULL, *arg6 = NULL;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
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
	PyObject *arg1, *arg2, *arg3, *arg4 = NULL;
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

PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(project)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(projectZO)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(projectNO)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(unProject)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(unProjectZO)
PyGLM_MAKE_GLM_FUNC_V3M4M4V4__tfF(unProjectNO)

static PyObject*
pickMatrix_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "pickMatrix", arg1, arg2, arg3);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD);
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		PyGLM_Vec_PTI_Assign0(2, float);
		PyGLM_Vec_PTI_Assign1(2, float);
		PyGLM_Vec_PTI_Assign2(4, float);
		if (!(o.x > 0.0f && o.y > 0.0f)) {
			PyErr_SetString(PyExc_ValueError, "delta has to be greater than 0 for pickMatrix()");
			return NULL;
		}
		return pack(glm::pickMatrix(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		PyGLM_Vec_PTI_Assign0(2, double);
		PyGLM_Vec_PTI_Assign1(2, double);
		PyGLM_Vec_PTI_Assign2(4, double);
		if (!(o.x > 0.0 && o.y > 0.0)) {
			PyErr_SetString(PyExc_ValueError, "delta has to be greater than 0 for pickMatrix()");
			return NULL;
		}
		return pack(glm::pickMatrix(o, o2, o3));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for pickMatrix()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(lookAt)
PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(lookAtLH)
PyGLM_MAKE_GLM_FUNC_V3V3V3__tfF(lookAtRH)

#define MATRIX_TRANSFORM_METHODS { "identity", (PyCFunction)identity_, METH_O, "identity(matrix_type) -> matrix\nBuilds an identity matrix." }, \
{ "translate", (PyCFunction)translate_, METH_VARARGS, "translate(m, v) -> mat4x4\nBuilds a translation 4 * 4 matrix created from a vector of 3 components." }, \
{ "rotate", (PyCFunction)rotate_, METH_VARARGS, "rotate(m, angle, axis) -> mat4x4 or quat\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle\nor rotates a quaternion from a vector of 3 components axis and an angle." }, \
{ "rotate_slow", (PyCFunction)rotate_slow_, METH_VARARGS, "rotate_slow(m, angle, axis) -> mat4x4\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle." }, \
{ "scale", (PyCFunction)scale_, METH_VARARGS, "scale(m, v) -> mat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." }, \
{ "scale_slow", (PyCFunction)scale_slow_, METH_VARARGS, "scale_slow(m, v) -> mat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." }, \
{ "ortho", (PyCFunction)ortho_, METH_VARARGS, "ortho(left, right, bottom, top[, zNear, zFar]) -> mat4x4\nCreates a matrix for projecting two-dimensional coordinates onto the screen." }, \
{ "orthoLH_ZO", (PyCFunction)orthoLH_ZO_, METH_VARARGS, "orthoLH_ZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "orthoLH_NO", (PyCFunction)orthoLH_NO_, METH_VARARGS, "orthoLH_NO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "orthoRH_ZO", (PyCFunction)orthoRH_ZO_, METH_VARARGS, "orthoRH_ZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "orthoRH_NO", (PyCFunction)orthoRH_NO_, METH_VARARGS, "orthoRH_NO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "orthoZO", (PyCFunction)orthoZO_, METH_VARARGS, "orthoZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "orthoNO", (PyCFunction)orthoNO_, METH_VARARGS, "orthoNO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "orthoLH", (PyCFunction)orthoLH_, METH_VARARGS, "orthoLH(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "orthoRH", (PyCFunction)orthoRH_, METH_VARARGS, "orthoRH(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "frustum", (PyCFunction)frustum_, METH_VARARGS, "frustum(left, right, bottom, top, near, far) -> mat4x4\nCreates a frustum matrix with default handedness, using right-handedness and -1 to +1 near and far clip planes definition." }, \
{ "frustumLH_ZO", (PyCFunction)frustumLH_ZO_, METH_VARARGS, "frustumLH_ZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "frustumLH_NO", (PyCFunction)frustumLH_NO_, METH_VARARGS, "frustumLH_NO(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "frustumRH_ZO", (PyCFunction)frustumRH_ZO_, METH_VARARGS, "frustumRH_ZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "frustumRH_NO", (PyCFunction)frustumRH_NO_, METH_VARARGS, "frustumRH_NO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "frustumZO", (PyCFunction)frustumZO_, METH_VARARGS, "frustumZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "frustumNO", (PyCFunction)frustumNO_, METH_VARARGS, "frustumNO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "frustumLH", (PyCFunction)frustumLH_, METH_VARARGS, "frustumLH(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "frustumRH", (PyCFunction)frustumRH_, METH_VARARGS, "frustumRH(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspective", (PyCFunction)perspective_, METH_VARARGS, "perspective(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum." }, \
{ "perspectiveLH_ZO", (PyCFunction)perspectiveLH_ZO_, METH_VARARGS, "perspectiveLH_ZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "perspectiveLH_NO", (PyCFunction)perspectiveLH_NO_, METH_VARARGS, "perspectiveLH_NO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveRH_ZO", (PyCFunction)perspectiveRH_ZO_, METH_VARARGS, "perspectiveRH_ZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "perspectiveRH_NO", (PyCFunction)perspectiveRH_NO_, METH_VARARGS, "perspectiveRH_NO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveZO", (PyCFunction)perspectiveZO_, METH_VARARGS, "perspectiveZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "perspectiveNO", (PyCFunction)perspectiveNO_, METH_VARARGS, "perspectiveNO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveLH", (PyCFunction)perspectiveLH_, METH_VARARGS, "perspectiveLH(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveRH", (PyCFunction)perspectiveRH_, METH_VARARGS, "perspectiveRH(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveFov", (PyCFunction)perspectiveFov_, METH_VARARGS, "perspectiveFov(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates." }, \
{ "perspectiveFovLH_ZO", (PyCFunction)perspectiveFovLH_ZO_, METH_VARARGS, "perspectiveFovLH_ZO(fov, width, height, near, far) -> mat4x4\n\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "perspectiveFovLH_NO", (PyCFunction)perspectiveFovLH_NO_, METH_VARARGS, "perspectiveFovLH_NO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveFovRH_ZO", (PyCFunction)perspectiveFovRH_ZO_, METH_VARARGS, "perspectiveFovRH_ZO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "perspectiveFovRH_NO", (PyCFunction)perspectiveFovRH_NO_, METH_VARARGS, "perspectiveFovRH_NO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveFovZO", (PyCFunction)perspectiveFovZO_, METH_VARARGS, "perspectiveFovZO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "perspectiveFovNO", (PyCFunction)perspectiveFovNO_, METH_VARARGS, "perspectiveFovNO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveFovLH", (PyCFunction)perspectiveFovLH_, METH_VARARGS, "perspectiveFovLH(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "perspectiveFovRH", (PyCFunction)perspectiveFovRH_, METH_VARARGS, "perspectiveFovRH(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "infinitePerspective", (PyCFunction)infinitePerspective_, METH_VARARGS, "infinitePerspective(fovy, aspect, near) -> mat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." }, \
{ "infinitePerspectiveRH", (PyCFunction)infinitePerspectiveRH_, METH_VARARGS, "infinitePerspectiveRH(fovy, aspect, near) -> mat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." }, \
{ "infinitePerspectiveLH", (PyCFunction)infinitePerspectiveLH_, METH_VARARGS, "infinitePerspectiveLH(fovy, aspect, near) -> mat4x4\nCreates a matrix for a left handed, symmetric perspective-view frustum with far plane at infinite." }, \
{ "tweakedInfinitePerspective", (PyCFunction)tweakedInfinitePerspective_, METH_VARARGS, "tweakedInfinitePerspective(fovy, aspect, near[, ep]) -> mat4x4\nCreates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping." }, \
{ "project", (PyCFunction)project_, METH_VARARGS, "project(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "projectNO", (PyCFunction)projectNO_, METH_VARARGS, "projectNO(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "projectZO", (PyCFunction)projectZO_, METH_VARARGS, "projectZO(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" }, \
{ "unProject", (PyCFunction)unProject_, METH_VARARGS, "unProject(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "unProjectNO", (PyCFunction)unProjectNO_, METH_VARARGS, "unProjectNO(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" }, \
{ "unProjectZO", (PyCFunction)unProjectZO_, METH_VARARGS, "unProjectZO(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },  \
{ "pickMatrix", (PyCFunction)pickMatrix_, METH_VARARGS, "pickMatrix(center, delta, viewport) -> mat4x4\nDefine a picking region" }, \
{ "lookAt", (PyCFunction)lookAt_, METH_VARARGS, "lookAt(eye, center, up) -> mat4x4\nBuild a right handed look at view matrix." }, \
{ "lookAtRH", (PyCFunction)lookAtRH_, METH_VARARGS, "lookAtRH(eye, center, up) -> mat4x4\nBuild a right handed look at view matrix." }, \
{ "lookAtLH", (PyCFunction)lookAtLH_, METH_VARARGS, "lookAtLH(eye, center, up) -> mat4x4\nBuild a left handed look at view matrix." }
