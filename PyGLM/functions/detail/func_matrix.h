#pragma once

#include "../../compiler_setup.h"

#include "../function_generator_macros.h"

PyObject*
outerProduct_(PyObject*, PyObject* args);

PyGLM_DECL_GLM_FUNC_MM__tfF(matrixCompMult)

PyGLM_DECL_GLM_FUNC_M(transpose)

PyGLM_DECL_GLM_FUNC_S__tfF(determinant)

PyGLM_DECL_GLM_FUNC_S_Q__tfF(inverse)
