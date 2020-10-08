#pragma once

#include "../function_generator_macros.h"

//TODO: Fix the supported types (should not be restricted to int)
//PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(isPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(ceilPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(floorPowerOfTwo);
PyGLM_MAKE_GLM_FUNC_N_V__tiqsu(roundPowerOfTwo);
//PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tiqsu(isMultiple);
PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(ceilMultiple);
PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(floorMultiple);
PyGLM_MAKE_GLM_FUNC_NN_VV__tiqsu(roundMultiple);

PyDoc_STRVAR(ceilMultiple_docstr, 
	"ceilMultiple(v: number, Multiple: number) -> number\n"
	"	Higher multiple number of Source.\n"
	"ceilMultiple(v: vecN, Multiple: vecN) -> vecN\n"
	"	Higher multiple number of Source."
);
PyDoc_STRVAR(ceilPowerOfTwo_docstr,
	"ceilPowerOfTwo(v: number) -> number\n"
	"	Return the power of two number which value is just higher the input value, round up to a\n"
	"	power of two.\n"
	"ceilPowerOfTwo(v: vecN) -> vecN\n"
	"	Return the power of two number which value is just higher the input value, round up to a\n"
	"	power of two."
);
PyDoc_STRVAR(floorMultiple_docstr,
	"floorMultiple(v: number, Multiple: number) -> number\n"
	"	Lower multiple number of Source.\n"
	"floorMultiple(v: vecN, Multiple: vecN) -> vecN\n"
	"	Lower multiple number of Source."
);
PyDoc_STRVAR(floorPowerOfTwo_docstr,
	"floorPowerOfTwo(v: number) -> number\n"
	"	Return the power of two number which value is just lower the input value, round down to a\n"
	"	power of two.\n"
	"floorPowerOfTwo(v: vecN) -> vecN\n"
	"	Return the power of two number which value is just lower the input value, round down to a\n"
	"	power of two."
);
PyDoc_STRVAR(roundMultiple_docstr,
	"roundMultiple(v: number, Multiple: number) -> number\n"
	"	Lower multiple number of Source.\n"
	"roundMultiple(v: vecN, Multiple: vecN) -> vecN\n"
	"	Lower multiple number of Source."
);
PyDoc_STRVAR(roundPowerOfTwo_docstr,
	"roundPowerOfTwo(v: number) -> number\n"
	"	Return the power of two number which value is the closet to the input value.\n"
	"roundPowerOfTwo(v: vecN) -> vecN\n"
	"	Return the power of two number which value is the closet to the input value."
);


#define ROUND_METHODS \
/*{ "isPowerOfTwo", (PyCFunction)isPowerOfTwo_, METH_O, "isPowerOfTwo(v) -> bool or bvecn\nReturn true if the value is a power of two number." },*/ \
{ "ceilPowerOfTwo", (PyCFunction)ceilPowerOfTwo_, METH_O, ceilPowerOfTwo_docstr }, \
{ "floorPowerOfTwo", (PyCFunction)floorPowerOfTwo_, METH_O, floorPowerOfTwo_docstr }, \
{ "roundPowerOfTwo", (PyCFunction)roundPowerOfTwo_, METH_O, roundPowerOfTwo_docstr }, \
/*{ "isMultiple", (PyCFunction)isMultiple_, METH_VARARGS, "isMultiple(v, Multiple) -> bool or bvecn\nReturn true if the 'Value' is a multiple of 'Multiple'." },  */ \
{ "ceilMultiple", (PyCFunction)ceilMultiple_, METH_VARARGS, ceilMultiple_docstr }, \
{ "floorMultiple", (PyCFunction)floorMultiple_, METH_VARARGS, floorMultiple_docstr }, \
{ "roundMultiple", (PyCFunction)roundMultiple_, METH_VARARGS, roundMultiple_docstr }
