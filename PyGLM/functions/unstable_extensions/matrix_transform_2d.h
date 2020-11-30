#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_M3N__tfF(shearX)

PyGLM_MAKE_GLM_FUNC_M3N__tfF(shearY)

PyDoc_STRVAR(shearX_docstr,
	"shearX(m: mat3x3, y: number) -> mat3x3\n"
	"	Builds an horizontal (parallel to the x axis) shear 3 x 3 matrix.\n"
	"	`m` is the input matrix multiplied by this translation matrix"
);
PyDoc_STRVAR(shearY_docstr,
	"shearY(m: mat3x3, x: number) -> mat3x3\n"
	"	Builds a vertical (parallel to the y axis) shear 3 x 3 matrix.\n"
	"	`m` is the input matrix multiplied by this translation matrix"
);

#define MATRIX_TRANSFORM_2D_METHODS \
{ "shearX", (PyCFunction)shearX_, METH_VARARGS, shearX_docstr }, \
{ "shearY", (PyCFunction)shearY_, METH_VARARGS, shearY_docstr }
