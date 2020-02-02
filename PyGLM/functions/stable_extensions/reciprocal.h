#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_N_V__tfF(sec)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(csc)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(cot)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(asec)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acsc)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acot)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(sech)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(csch)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(coth)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(asech)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acsch)
PyGLM_MAKE_GLM_FUNC_N_V__tfF(acoth)

#define RECIPROCAL_METHODS { "sec", (PyCFunction)sec_, METH_O, "sec(x) -> float or vecn\nSecant function.\nhypotenuse / adjacent or 1 / cos(x)" }, \
{ "csc", (PyCFunction)csc_, METH_O, "csc(x) -> float or vecn\nCosecant function.\nhypotenuse / opposite or 1 / sin(x)" }, \
{ "cot", (PyCFunction)cot_, METH_O, "cot(x) -> float or vecn\nCotangent function.\nadjacent / opposite or 1 / tan(x)" }, \
{ "asec", (PyCFunction)asec_, METH_O, "asec(x) -> float or vecn\nInverse secant function." }, \
{ "acsc", (PyCFunction)acsc_, METH_O, "acsc(x) -> float or vecn\nInverse cosecant function." }, \
{ "acot", (PyCFunction)acot_, METH_O, "acot(x) -> float or vecn\nInverse cotangent function." }, \
{ "sech", (PyCFunction)sech_, METH_O, "sech(x) -> float or vecn\nSecant hyperbolic function." }, \
{ "csch", (PyCFunction)csch_, METH_O, "csch(x) -> float or vecn\nCosecant hyperbolic function." }, \
{ "coth", (PyCFunction)coth_, METH_O, "coth(x) -> float or vecn\nCotangent hyperbolic function." }, \
{ "asech", (PyCFunction)asech_, METH_O, "asech(x) -> float or vecn\nInverse secant hyperbolic function." }, \
{ "acsch", (PyCFunction)acsch_, METH_O, "acsch(x) -> float or vecn\nInverse cosecant hyperbolic function." }, \
{ "acoth", (PyCFunction)acoth_, METH_O, "acoth(x) -> float or vecn\nInverse cotangent hyperbolic function." }
