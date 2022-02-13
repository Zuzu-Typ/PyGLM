#pragma once

#include "func_matrix.h"

PyDoc_STRVAR(outerProduct_docstr,
	"outerProduct(c: vecC, r: vecR) -> matRxC\n"
	"	Treats the first parameter `c` as a column vector and the second parameter `r` as a row vector\n"
	"	and does a linear algebraic matrix multiply `c * r`."
);

PyDoc_STRVAR(matrixCompMult_docstr,
	"matrixCompMult(x: matNxM, y: matNxM) -> matNxM\n"
	"	Multiply matrix `x` by matrix `y` component-wise, i.e., `result[i][j]` is the scalar product of\n"
	"	`x[i][j]` and `y[i][j]`."
);

PyDoc_STRVAR(transpose_docstr,
	"transpose(x: matNxM) -> matMxN\n"
	"	Returns the transposed matrix of `x`."
);

PyDoc_STRVAR(determinant_docstr,
	"determinant(m: matSxS) -> float\n"
	"	Return the determinant of a squared matrix."
);

PyDoc_STRVAR(inverse_docstr,
	"inverse(m: matSxS) -> matSxS\n"
	"	Return the inverse of a squared matrix.\n"
	"inverse(q: quat) -> quat\n"
	"	Return the inverse of a quaternion."
);

#define FUNC_MATRIX_METHODS \
{ "matrixCompMult", (PyCFunction)matrixCompMult_, METH_VARARGS, matrixCompMult_docstr }, \
{ "outerProduct", (PyCFunction)outerProduct_, METH_VARARGS, outerProduct_docstr }, \
{ "transpose", (PyCFunction)transpose_, METH_O, transpose_docstr }, \
{ "determinant", (PyCFunction)determinant_, METH_O, determinant_docstr }, \
{ "inverse", (PyCFunction)inverse_, METH_O, inverse_docstr }
