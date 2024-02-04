#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(equal_docstr,
	"equal(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x == y`.\n"
	"equal(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x == y`.\n"
	"equal(x: matNxM, y: matNxM) -> bvecN\n"
	"	Perform a component-wise equal-to comparison of two matrices. Return a boolean vector which\n"
	"	components value is `True` if this expression is satisfied per column of the matrices.\n"
	"equal(x: number, y: number, ULPs: int) -> bool\n"
	"	Returns the component-wise comparison between two scalars in term of `ULPs`.\n"
	"equal(x: vecN, y: vecN, ULPs: int) -> bvecN\n"
	"	Returns the component-wise comparison between two vectors in term of `ULPs`.\n"
	"equal(x: matNxM, y: matNxM, ULPs: int) -> bvecN\n"
	"	Returns the component-wise comparison between two matrices in term of `ULPs`.\n"
	"equal(x: vecN, y: vecN, ULPs: ivecN) -> bvecN\n"
	"	Returns the component-wise comparison between two vectors in term of `ULPs`.\n"
	"equal(x: matNxM, y: matNxM, ULPs: ivecN) -> bvecN\n"
	"	Returns the component-wise comparison between two matrices in term of `ULPs`.\n"
	"equal(x: number, y: number, epsilon: number) -> bool\n"
	"	Returns the comparison of `|x - y| < epsilon`.\n"
	"equal(x: vecN, y: vecN, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: quat, y: quat, epsilon: number) -> bvec4\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: matNxM, y: matNxM, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: vecN, y: vecN, epsilon: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: matNxM, y: matNxM, epsilon: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`."
);
static PyObject*
equal(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "equal", 2, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg3 == NULL) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::equal(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_ALL, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::equal(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2)));

					PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::equal(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2)));

						PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
		return NULL;
	}
	if (PyLong_Check(arg3)) {
		const int o3 = PyGLM_Number_FromPyObject<int>(arg3);

		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::equal(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), o3));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::equal(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), o3));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::equal(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}

	if (PyGLM_Number_Check(arg3)) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::equal(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::equal(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::equal(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

						PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE


				}
			}
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::equal(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);
		GET_PyGLM_ARG_TYPE(arg3);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);
		GET_PyGLM_ARG_SUBTYPE(arg3);

		if (arg1Subtype == arg2Subtype && arg1Subtype->C == arg3Subtype->C && arg3Subtype->glmType == PyGLM_TYPE_VEC) {
			if (arg3Subtype->format == PyGLM_FS_INT32) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::equal(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, int32, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::equal(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), PyGLM_VecOrMVec_Get(C, int32, arg3)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
			if (arg3Subtype->format == arg1Subtype->format) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::equal(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, T, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::equal(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), PyGLM_VecOrMVec_Get(C, T, arg3)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
	return NULL;
}

PyDoc_STRVAR(notEqual_docstr,
	"notEqual(*args) -> bvecN\n"
	"	Returns `not equal(*args)`."
);
static PyObject*
notEqual(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "notEqual", 2, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg3 == NULL) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::notEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_ALL, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::notEqual(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fFiI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::notEqual(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2)));

						PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
		return NULL;
	}
	if (PyLong_Check(arg3)) {
		const int o3 = PyGLM_Number_FromPyObject<int>(arg3);

		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::notEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), o3));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::notEqual(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), o3));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::notEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}

	if (PyGLM_Number_Check(arg3)) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::notEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::notEqual(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(T) \
				case PyGLMTypeObjectArrayOffsetQua<T>(): \
					return pack(glm::notEqual(PyGLM_Qua_Get(T, arg1), PyGLM_Qua_Get(T, arg2), PyGLM_Number_FromPyObject<T>(arg3)));

						PyGLM_CODEGEN_PARAM_T_Qua_fF(PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE


				}
			}
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::notEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);
		GET_PyGLM_ARG_TYPE(arg3);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);
		GET_PyGLM_ARG_SUBTYPE(arg3);

		if (arg1Subtype == arg2Subtype && arg1Subtype->C == arg3Subtype->C && arg3Subtype->glmType == PyGLM_TYPE_VEC) {
			if (arg3Subtype->format == PyGLM_FS_INT32) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::notEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, int32, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::notEqual(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), PyGLM_VecOrMVec_Get(C, int32, arg3)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
			if (arg3Subtype->format == arg1Subtype->format) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::notEqual(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), PyGLM_VecOrMVec_Get(L, T, arg2)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(C, R, T) \
				case PyGLMTypeObjectArrayOffsetMat<C, R, T>(): \
					return pack(glm::notEqual(PyGLM_Mat_Get(C, R, T, arg1), PyGLM_Mat_Get(C, R, T, arg2), PyGLM_VecOrMVec_Get(C, T, arg3)));

						PyGLM_CODEGEN_PARAM_C_ALL(PyGLM_CODEGEN_PARAM_R_ALL, PyGLM_CODEGEN_PARAM_T_Mat_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}

	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
	return NULL;
}

PyDoc_STRVAR(lessThan_docstr,
	"lessThan(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x < y`.\n"
	"lessThan(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x < y`."
);
PyGLM_MAKE_GLM_FUNC_VV_QQ(lessThan)

PyDoc_STRVAR(lessThanEqual_docstr,
	"lessThanEqual(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x <= y`.\n"
	"lessThanEqual(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x <= y`."
);
PyGLM_MAKE_GLM_FUNC_VV_QQ(lessThanEqual)

PyDoc_STRVAR(greaterThan_docstr,
	"greaterThan(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x > y`.\n"
	"greaterThan(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x > y`."
);
PyGLM_MAKE_GLM_FUNC_VV_QQ(greaterThan)

PyDoc_STRVAR(greaterThanEqual_docstr,
	"greaterThanEqual(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x >= y`.\n"
	"greaterThanEqual(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x >= y`."
);
PyGLM_MAKE_GLM_FUNC_VV_QQ(greaterThanEqual)

PyDoc_STRVAR(any_docstr,
	"any(v: bvecN) -> bool\n"
	"	Returns `True` if any component of `x` is `True`."
);
static PyObject*
any(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L) \
	case PyGLMTypeObjectArrayOffsetVec<L, bool>(): \
		if (glm::any(PyGLM_Vec_Get(L, bool, arg))) { \
			Py_RETURN_TRUE; \
		} \
		Py_RETURN_FALSE;

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for any(): ", arg);
	return NULL;
}

PyDoc_STRVAR(all_docstr,
	"all(v: bvecN) -> bool\n"
	"	Returns `True` if all components of `x` are `True`."
);
static PyObject*
all(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L) \
	case PyGLMTypeObjectArrayOffsetVec<L, bool>(): \
		if (glm::all(PyGLM_Vec_Get(L, bool, arg))) { \
			Py_RETURN_TRUE; \
		} \
		Py_RETURN_FALSE;

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for all(): ", arg);
	return NULL;
}

PyDoc_STRVAR(not_docstr,
	"not_(v: bvecN) -> bool\n"
	"	Returns the component-wise logical complement of `x`."
);
static PyObject*
not_(PyObject*, PyObject* arg) {
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L) \
	case PyGLMTypeObjectArrayOffsetVec<L, bool>(): \
		return pack(glm::not_(PyGLM_Vec_Get(L, bool, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for not_(): ", arg);
	return NULL;
}

#define FUNC_VECTOR_RELATIONAL_METHODS \
{ "equal", (PyCFunction)equal, METH_VARARGS, equal_docstr }, \
{ "notEqual", (PyCFunction)notEqual, METH_VARARGS, notEqual_docstr }, \
{ "lessThan", (PyCFunction)lessThan_, METH_VARARGS, lessThan_docstr }, \
{ "lessThanEqual", (PyCFunction)lessThanEqual_, METH_VARARGS, lessThanEqual_docstr }, \
{ "greaterThan", (PyCFunction)greaterThan_, METH_VARARGS, greaterThan_docstr }, \
{ "greaterThanEqual", (PyCFunction)greaterThanEqual_, METH_VARARGS, greaterThanEqual_docstr }, \
{ "any", (PyCFunction)any, METH_O, any_docstr }, \
{ "all", (PyCFunction)all, METH_O, all_docstr }, \
{ "not_", (PyCFunction)not_, METH_O, not_docstr }
