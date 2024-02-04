#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(outerProduct_docstr,
	"outerProduct(c: vecC, r: vecR) -> matRxC\n"
	"	Treats the first parameter `c` as a column vector and the second parameter `r` as a row vector\n"
	"	and does a linear algebraic matrix multiply `c * r`."
);
static PyObject*
outerProduct_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "outerProduct", arg1, arg2);
	if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
		GET_PyGLM_ARG_TYPE(arg1);
		GET_PyGLM_ARG_TYPE(arg2);

		GET_PyGLM_ARG_SUBTYPE(arg1);
		GET_PyGLM_ARG_SUBTYPE(arg2);

		switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					if (arg2Subtype == reinterpret_cast<PyGLMTypeObject*>(PyGLM_VEC_TYPE<2, T>())) \
						return pack(glm::outerProduct(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(2, T, arg2)));\
					if (arg2Subtype == reinterpret_cast<PyGLMTypeObject*>(PyGLM_VEC_TYPE<3, T>())) \
						return pack(glm::outerProduct(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(3, T, arg2)));\
					if (arg2Subtype == reinterpret_cast<PyGLMTypeObject*>(PyGLM_VEC_TYPE<4, T>())) \
						return pack(glm::outerProduct(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(4, T, arg2)));\
					break;

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_fF, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for outerProduct(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(matrixCompMult_docstr,
	"matrixCompMult(x: matNxM, y: matNxM) -> matNxM\n"
	"	Multiply matrix `x` by matrix `y` component-wise, i.e., `result[i][j]` is the scalar product of\n"
	"	`x[i][j]` and `y[i][j]`."
);
PyGLM_MAKE_GLM_FUNC_MM__tfF(matrixCompMult)

PyDoc_STRVAR(transpose_docstr,
	"transpose(x: matNxM) -> matMxN\n"
	"	Returns the transposed matrix of `x`."
);
PyGLM_MAKE_GLM_FUNC_M(transpose)

PyDoc_STRVAR(determinant_docstr,
	"determinant(m: matSxS) -> float\n"
	"	Return the determinant of a squared matrix."
);
PyGLM_MAKE_GLM_FUNC_S__tfF(determinant)

PyDoc_STRVAR(inverse_docstr,
	"inverse(m: matSxS) -> matSxS\n"
	"	Return the inverse of a squared matrix.\n"
	"inverse(q: quat) -> quat\n"
	"	Return the inverse of a quaternion."
);
PyGLM_MAKE_GLM_FUNC_S_Q__tfF(inverse)

#define FUNC_MATRIX_METHODS \
{ "matrixCompMult", (PyCFunction)matrixCompMult_, METH_VARARGS, matrixCompMult_docstr }, \
{ "outerProduct", (PyCFunction)outerProduct_, METH_VARARGS, outerProduct_docstr }, \
{ "transpose", (PyCFunction)transpose_, METH_O, transpose_docstr }, \
{ "determinant", (PyCFunction)determinant_, METH_O, determinant_docstr }, \
{ "inverse", (PyCFunction)inverse_, METH_O, inverse_docstr }
