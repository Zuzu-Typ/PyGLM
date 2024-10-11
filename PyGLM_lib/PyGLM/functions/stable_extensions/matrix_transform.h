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

static PyObject*
translate_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "translate", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_DT_NORMAL);
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			return pack(glm::translate(glm::mat<4, 4, float>(1), PyGLM_Vec_PTI_Get0(3, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			return pack(glm::translate(glm::mat<4, 4, double>(1), PyGLM_Vec_PTI_Get0(3, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int32, arg1)) {
			return pack(glm::translate(glm::mat<4, 4, int32>(1), PyGLM_Vec_PTI_Get0(3, int32, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint32, arg1)) {
			return pack(glm::translate(glm::mat<4, 4, uint32>(1), PyGLM_Vec_PTI_Get0(3, uint32, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			return pack(glm::translate(glm::mat<3, 3, float>(1), PyGLM_Vec_PTI_Get0(2, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			return pack(glm::translate(glm::mat<3, 3, double>(1), PyGLM_Vec_PTI_Get0(2, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int32, arg1)) {
			return pack(glm::translate(glm::mat<3, 3, int32>(1), PyGLM_Vec_PTI_Get0(2, int32, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint32, arg1)) {
			return pack(glm::translate(glm::mat<3, 3, uint32>(1), PyGLM_Vec_PTI_Get0(2, uint32, arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type for translate(): ", arg1);
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4 | PyGLM_DT_NORMAL);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_DT_NORMAL);
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::translate(PyGLM_Mat_PTI_Get0(4, 4, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::translate(PyGLM_Mat_PTI_Get0(4, 4, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::translate(PyGLM_Mat_PTI_Get0(4, 4, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {
			return pack(glm::translate(PyGLM_Mat_PTI_Get0(4, 4, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::translate(PyGLM_Mat_PTI_Get0(3, 3, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::translate(PyGLM_Mat_PTI_Get0(3, 3, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
		}
		PyGLM_TYPEERROR_2O("invalid argument types for translate(): ", arg1, arg2);
	}
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
		if (PyGLM_Number_Check(arg1)) {
			PyGLM_PTI_Init0(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(3, float, arg2)) {
				return pack(glm::rotate(glm::mat<4, 4, float>(1), PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Vec_PTI_Get0(3, float, arg2)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg2)) {
				return pack(glm::rotate(glm::mat<4, 4, double>(1), PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Vec_PTI_Get0(3, double, arg2)));
			}
		}
		else if (PyGLM_Number_Check(arg2)) {
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_2 | PyGLM_SHAPE_3x3 | PyGLM_DT_FD);
			if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {
				glm::mat<3, 3, float> m = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
				return pack(glm::rotate(m, PyGLM_Number_FromPyObject<float>(arg2)));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {
				glm::mat<3, 3, double> m = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
				return pack(glm::rotate(m, PyGLM_Number_FromPyObject<double>(arg2)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
				return pack(glm::rotate(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
				return pack(glm::rotate(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
			}
		}
	}
	else if (PyGLM_Number_Check(arg2)) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
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
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			return pack(glm::rotate(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			return pack(glm::rotate(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			return pack(glm::rotate(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			return pack(glm::rotate(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
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

static PyObject*
scale_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "scale", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_DT_NORMAL);
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			return pack(glm::scale(glm::mat<4, 4, float>(1), PyGLM_Vec_PTI_Get0(3, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			return pack(glm::scale(glm::mat<4, 4, double>(1), PyGLM_Vec_PTI_Get0(3, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int32, arg1)) {
			return pack(glm::scale(glm::mat<4, 4, int32>(1), PyGLM_Vec_PTI_Get0(3, int32, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(3, uint32, arg1)) {
			return pack(glm::scale(glm::mat<4, 4, uint32>(1), PyGLM_Vec_PTI_Get0(3, uint32, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			return pack(glm::scale(glm::mat<3, 3, float>(1), PyGLM_Vec_PTI_Get0(2, float, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			return pack(glm::scale(glm::mat<3, 3, double>(1), PyGLM_Vec_PTI_Get0(2, double, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int32, arg1)) {
			return pack(glm::scale(glm::mat<3, 3, int32>(1), PyGLM_Vec_PTI_Get0(2, int32, arg1)));
		}
		if (PyGLM_Vec_PTI_Check0(2, uint32, arg1)) {
			return pack(glm::scale(glm::mat<3, 3, uint32>(1), PyGLM_Vec_PTI_Get0(2, uint32, arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type(s) for scale(): ", arg1);
		return NULL;
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4 | PyGLM_DT_NORMAL);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_DT_NORMAL);
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::scale(PyGLM_Mat_PTI_Get0(4, 4, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::scale(PyGLM_Mat_PTI_Get0(4, 4, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::scale(PyGLM_Mat_PTI_Get0(4, 4, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, uint32, arg1) && PyGLM_Vec_PTI_Check1(3, uint32, arg2)) {
			return pack(glm::scale(PyGLM_Mat_PTI_Get0(4, 4, uint32, arg1), PyGLM_Vec_PTI_Get1(3, uint32, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::scale(PyGLM_Mat_PTI_Get0(3, 3, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::scale(PyGLM_Mat_PTI_Get0(3, 3, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
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
