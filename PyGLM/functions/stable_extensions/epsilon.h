#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
epsilonEqual_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "epsilonEqual", arg1, arg2, arg3);
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
					return pack(glm::epsilonEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, T, arg3)));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	else if (PyGLM_Number_Check(arg3)) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::epsilonEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::epsilonEqual(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

					PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		} else if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			if (glm::epsilonEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3))) {
				Py_RETURN_TRUE;
			}
			else {
				Py_RETURN_FALSE;
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for epsilonEqual()");
	return NULL;
}

static PyObject*
epsilonNotEqual_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3;
	PyGLM_Arg_Unpack_3O(args, "epsilonNotEqual", arg1, arg2, arg3);
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
					return pack(glm::epsilonNotEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, T, arg3)));

				PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
			}
		}
	}
	else if (PyGLM_Number_Check(arg3)) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::epsilonNotEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::epsilonNotEqual(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

						PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		else if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			if (glm::epsilonNotEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3))) {
				Py_RETURN_TRUE;
			}
			else {
				Py_RETURN_FALSE;
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for epsilonNotEqual()");
	return NULL;
}

PyDoc_STRVAR(epsilonEqual_docstr,
	"epsilonEqual(x: number, y: number, epsilon: number) -> bool\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"epsilonEqual(x: vecN, y: vecN, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"epsilonEqual(x: quat, y: quat, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"epsilonEqual(x: vecN, y: vecN, epsilon: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`."
);

PyDoc_STRVAR(epsilonNotEqual_docstr,
	"epsilonNotEqual(x: number, y: number, epsilon: number) -> bool\n"
	"	Returns the component-wise comparison of `|x - y| >= epsilon`.\n"
	"epsilonNotEqual(x: vecN, y: vecN, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| >= epsilon`.\n"
	"epsilonNotEqual(x: quat, y: quat, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| >= epsilon`.\n"
	"epsilonNotEqual(x: vecN, y: vecN, epsilon: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| >= epsilon`."
);

#define EPSILON_METHODS \
{ "epsilonEqual", (PyCFunction)epsilonEqual_, METH_VARARGS, epsilonEqual_docstr }, \
{ "epsilonNotEqual", (PyCFunction)epsilonNotEqual_, METH_VARARGS, epsilonNotEqual_docstr }
