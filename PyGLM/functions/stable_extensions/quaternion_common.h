#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
lerp_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3;
	PyGLM_Arg_Unpack_3O(args, "lerp", arg1, arg2, arg3);
	if (Is_PyGLM_Object(arg3) && Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);
		GET_PyGLM_ARG_TYPE(arg3);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);
		GET_PyGLM_ARG_SUBTYPE(arg3);

		if (arg1Subtype == arg2Subtype && arg1Subtype == arg3Subtype) {
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::lerp(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, T, arg3)));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	if (PyGLM_Number_Check(arg3)) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				union
				{
					float _float;
					double _double;
				} a;

				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
					case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
						return pack(glm::lerp(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

					PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
					case PyGLMTypeObjectArrayOffsetQua<T>(): \
						a._##T = PyGLM_Number_FromPyObject<T>(arg3); \
						PyGLM_ASSERT((a._##T >= static_cast<T>(0.0) && a._##T <= static_cast<T>(1.0)), "Lerp is only defined in [0, 1]"); \
						return pack(glm::lerp(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2), a._##T));

					PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return PyGLM_PyObject_FromNumber(glm::lerp(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for lerp()");
	return NULL;
}

static PyObject*
slerp_(PyObject*, PyObject * args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "slerp", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3) && Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);

		if (arg1Subtype == arg2Subtype) {
			switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetVec<3, T>(): \
					return pack(glm::slerp(PyGLM_VecOrMVec_Get(3, T, arg1), PyGLM_VecOrMVec_Get(3, T, arg2), PyGLM_Number_FromPyObject<T>(arg3))); \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::slerp(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2), PyGLM_Number_FromPyObject<T>(arg3))); 

				PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for slerp()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_Q(conjugate)

PyDoc_STRVAR(conjugate_docstr,
	"conjugate(q: quat) -> quat\n"
	"	Returns the `q` conjugate."
);
PyDoc_STRVAR(lerp_docstr,
	"lerp(x: float, y: float, a: float) -> float\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the\n"
	"	floating-point value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"lerp(x: vecN, y: vecN, a: float) -> vecN\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the\n"
	"	floating-point value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"lerp(x: vecN, y: vecN, a: vecN) -> vecN\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the\n"
	"	vector `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"lerp(x: quat, y: quat, a: float) -> quat\n"
	"	Linear interpolation of two quaternions. The interpolation is oriented."
);
PyDoc_STRVAR(slerp_docstr,
	"slerp(x: quat, y: quat, a: float) -> quat\n"
	"	Spherical linear interpolation of two quaternions. The interpolation always take the short\n"
	"	path and the rotation is performed at constant speed.\n"
	"slerp(x: vec3, y: vec3, a: float) -> vec3\n"
	"	Returns Spherical interpolation between two vectors."
);

#define QUATERNION_COMMON_METHODS \
{ "lerp", (PyCFunction)lerp_, METH_VARARGS, lerp_docstr }, \
{ "slerp", (PyCFunction)slerp_, METH_VARARGS, slerp_docstr }, \
{ "conjugate", (PyCFunction)conjugate_, METH_O, conjugate_docstr }
