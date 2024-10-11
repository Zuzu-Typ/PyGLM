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

PyDoc_STRVAR(acot_docstr,
	"acot(x: float) -> float\n"
	"	Inverse cotangent function."
);
PyDoc_STRVAR(acoth_docstr,
	"acoth(x: float) -> float\n"
	"	Inverse cotangent hyperbolic function."
);
PyDoc_STRVAR(acsc_docstr,
	"acsc(x: float) -> float\n"
	"	Inverse cosecant function."
);
PyDoc_STRVAR(acsch_docstr,
	"acsch(x: float) -> float\n"
	"	Inverse cosecant hyperbolic function."
);
PyDoc_STRVAR(asec_docstr,
	"asec(x: float) -> float\n"
	"	Inverse secant function."
);
PyDoc_STRVAR(asech_docstr,
	"asech(x: float) -> float\n"
	"	Inverse secant hyperbolic function."
);
PyDoc_STRVAR(cot_docstr,
	"cot(angle: float) -> float\n"
	"	Cotangent function. adjacent / opposite or `1 / tan(x)`."
);
PyDoc_STRVAR(coth_docstr,
	"coth(angle: float) -> float\n"
	"	Cotangent hyperbolic function."
);
PyDoc_STRVAR(csc_docstr,
	"csc(angle: float) -> float\n"
	"	Cosecant function. hypotenuse / opposite or `1 / sin(x)`."
);
PyDoc_STRVAR(csch_docstr,
	"csch(angle: float) -> float\n"
	"	Cosecant hyperbolic function."
);
PyDoc_STRVAR(sec_docstr,
	"sec(angle: float) -> float\n"
	"	Secant function. hypotenuse / adjacent or `1 / cos(x)`."
);
PyDoc_STRVAR(sech_docstr,
	"sech(angle: float) -> float\n"
	"	Secant hyperbolic function."
);

#define RECIPROCAL_METHODS \
{ "sec", (PyCFunction)sec_, METH_O, sec_docstr }, \
{ "csc", (PyCFunction)csc_, METH_O, csc_docstr }, \
{ "cot", (PyCFunction)cot_, METH_O, cot_docstr }, \
{ "asec", (PyCFunction)asec_, METH_O, asec_docstr }, \
{ "acsc", (PyCFunction)acsc_, METH_O, acsc_docstr }, \
{ "acot", (PyCFunction)acot_, METH_O, acot_docstr }, \
{ "sech", (PyCFunction)sech_, METH_O, sech_docstr }, \
{ "csch", (PyCFunction)csch_, METH_O, csch_docstr }, \
{ "coth", (PyCFunction)coth_, METH_O, coth_docstr }, \
{ "asech", (PyCFunction)asech_, METH_O, asech_docstr }, \
{ "acsch", (PyCFunction)acsch_, METH_O, acsch_docstr }, \
{ "acoth", (PyCFunction)acoth_, METH_O, acoth_docstr }
