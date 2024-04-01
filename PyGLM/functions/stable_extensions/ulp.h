#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
next_float_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "next_float", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::next_float(PyGLM_Vec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::next_float(PyGLM_MVec_Get(L, T, arg1)));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::next_float(PyGLM_Number_FromPyObject<double>(arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type for next_float(): ", arg1);
		return NULL;
	}
	if (PyLong_Check(arg2)) {
		int ULPs = PyGLM_Number_FromPyObject<int>(arg2);
		PyGLM_ASSERT((ULPs >= 0), "'ULPs' has to be greater than or equal to 0");
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::next_float(PyGLM_Vec_Get(L, T, arg1), ULPs));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::next_float(PyGLM_MVec_Get(L, T, arg1), ULPs));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::next_float(PyGLM_Number_FromPyObject<double>(arg1), ULPs));
		}
	}
	else {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				if (PyGLM_Vec_Check(L, int, arg2)) \
					return pack(glm::next_float(PyGLM_Vec_Get(L, T, arg1), PyGLM_VecOrMVec_GET(L, int, arg2))); \
				break;

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				if (PyGLM_Vec_Check(L, int, arg2)) \
					return pack(glm::next_float(PyGLM_MVec_Get(L, T, arg1), PyGLM_VecOrMVec_GET(L, int, arg2))); \
				break;

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for next_float(): ", arg1, arg2);
	return NULL;
}

static PyObject*
prev_float_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "prev_float", 1, 2, &arg1, &arg2)) return NULL;
	if (arg2 == NULL) {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::prev_float(PyGLM_Vec_Get(L, T, arg1)));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::prev_float(PyGLM_MVec_Get(L, T, arg1)));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::prev_float(PyGLM_Number_FromPyObject<double>(arg1)));
		}
		PyGLM_TYPEERROR_O("invalid argument type for prev_float(): ", arg1);
		return NULL;
	}
	if (PyLong_Check(arg2)) {
		int ULPs = PyGLM_Number_FromPyObject<int>(arg2);
		PyGLM_ASSERT((ULPs >= 0), "'ULPs' has to be greater than or equal to 0");
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				return pack(glm::prev_float(PyGLM_Vec_Get(L, T, arg1), ULPs));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				return pack(glm::prev_float(PyGLM_MVec_Get(L, T, arg1), ULPs));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
		if (PyGLM_Number_Check(arg1)) {
			return pack(glm::prev_float(PyGLM_Number_FromPyObject<double>(arg1), ULPs));
		}
	}
	else {
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
				if (PyGLM_Vec_Check(L, int, arg2)) \
					return pack(glm::prev_float(PyGLM_Vec_Get(L, T, arg1), PyGLM_VecOrMVec_GET(L, int, arg2))); \
				break;

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
			case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
				if (PyGLM_Vec_Check(L, int, arg2)) \
					return pack(glm::prev_float(PyGLM_MVec_Get(L, T, arg1), PyGLM_VecOrMVec_GET(L, int, arg2))); \
				break;

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for prev_float(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(float_distance);

PyDoc_STRVAR(next_float_docstr,
	"next_float(x: float) -> float\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: vecN) -> vecN\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: float, ULPs: float) -> float\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: vecN, ULPs: float) -> vecN\n"
	"	Return the next ULP value(s) after the input value(s).\n"
	"next_float(x: vecN, ULPs: ivecN) -> float\n"
	"	Return the next ULP value(s) after the input value(s).\n"
);
PyDoc_STRVAR(prev_float_docstr,
	"prev_float(x: float) -> float\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: vecN) -> vecN\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: float, ULPs: float) -> float\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: vecN, ULPs: float) -> vecN\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
	"prev_float(x: vecN, ULPs: ivecN) -> float\n"
	"	Return the previous ULP value(s) before the input value(s).\n"
);
PyDoc_STRVAR(float_distance_docstr,
	"float_distance(x: float, y: float) -> float\n"
	"	Return the distance in the number of ULP between 2 double-precision floating-point scalars.\n"
	"float_distance(x: fvecN, y: fvecN) -> ivecN\n"
	"	Return the distance in the number of ULP between 2 single-precision floating-point scalars.\n"
	"float_distance(x: dvecN, y: dvecN) -> i64vecN\n"
	"	Return the distance in the number of ULP between 2 double-precision floating-point scalars.\n"
);

#define ULP_METHODS \
{ "next_float", (PyCFunction)next_float_, METH_VARARGS, next_float_docstr }, \
{ "prev_float", (PyCFunction)prev_float_, METH_VARARGS, prev_float_docstr }, \
{ "float_distance", (PyCFunction)float_distance_, METH_VARARGS, float_distance_docstr }
