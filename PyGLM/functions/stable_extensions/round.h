#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(isPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(ceilPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(floorPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(roundPowerOfTwo);
//PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tiqsu(isMultiple);
PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(ceilMultiple);
PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(floorMultiple);
PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(roundMultiple);

#define ROUND_METHODS { "isPowerOfTwo", (PyCFunction)isPowerOfTwo_, METH_O, "isPowerOfTwo(v) -> bool or bvecn\nReturn true if the value is a power of two number." }, \
{ "ceilPowerOfTwo", (PyCFunction)ceilPowerOfTwo_, METH_O, "ceilPowerOfTwo(v) -> float or vecn\nReturn the power of two number which value is just higher the input value,\nround up to a power of two." }, \
{ "floorPowerOfTwo", (PyCFunction)floorPowerOfTwo_, METH_O, "floorPowerOfTwo(v) -> float or vecn\nReturn the power of two number which value is just lower the input value,\nround down to a power of two." }, \
{ "roundPowerOfTwo", (PyCFunction)roundPowerOfTwo_, METH_O, "roundPowerOfTwo(v) -> float or vecn\nReturn the power of two number which value is the closet to the input value." }, \
/*{ "isMultiple", (PyCFunction)isMultiple_, METH_VARARGS, "isMultiple(v, Multiple) -> bool or bvecn\nReturn true if the 'Value' is a multiple of 'Multiple'." },  */ \
{ "ceilMultiple", (PyCFunction)ceilMultiple_, METH_VARARGS, "ceilMultiple(v, Multiple) -> float or vecn\nHigher multiple number of Source." }, \
{ "floorMultiple", (PyCFunction)floorMultiple_, METH_VARARGS, "floorMultiple(v, Multiple) -> float or vecn\nLower multiple number of Source." }, \
{ "roundMultiple", (PyCFunction)roundMultiple_, METH_VARARGS, "roundMultiple(v, Multiple) -> float or vecn\nLower multiple number of Source." }
