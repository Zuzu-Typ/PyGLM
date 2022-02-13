#pragma once

#include "func_trigonometric.h"

PyDoc_STRVAR(radians_docstr,
	"radians(angle: float) -> float\n"
	"	Converts degrees to radians and returns the result.\n"
	"radians(angle: vecN) -> vecN\n"
	"	Returns `radians(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(degrees_docstr,
	"degrees(angle: float) -> float\n"
	"	Converts radians to degrees and returns the result.\n"
	"degrees(angle: vecN) -> vecN\n"
	"	Returns `degrees(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(sin_docstr,
	"sin(angle: float) -> float\n"
	"	The standard trigonometric sine function. The values returned by this function will range\n"
	"	from `[-1, 1]`.\n"
	"sin(angle: vecN) -> vecN\n"
	"	Returns `sin(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(cos_docstr,
	"cos(angle: float) -> float\n"
	"	The standard trigonometric cosine function. The values returned by this function will range\n"
	"	from `[-1, 1]`.\n"
	"cos(angle: vecN) -> vecN\n"
	"	Returns `cos(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(tan_docstr,
	"tan(angle: float) -> float\n"
	"	The standard trigonometric tangent function.\n"
	"tan(angle: vecN) -> vecN\n"
	"	Returns `tan(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(asin_docstr,
	"asin(x: float) -> float\n"
	"	Arc sine. Returns an angle whose sine is `x`. The range of values returned by this function\n"
	"	is `[0, PI]`. Results are undefined if `|x| > 1`.\n"
	"asin(x: vecN) -> vecN\n"
	"	Returns `asin(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(acos_docstr,
	"acos(x: float) -> float\n"
	"	Arc cosine. Returns an angle whose cosine is `x`. The range of values returned by this function\n"
	"	is `[0, PI]`. Results are undefined if `|x| > 1`.\n"
	"acos(x: vecN) -> vecN\n"
	"	Returns `acos(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(atan_docstr,
	"atan(y_over_x: float) -> float\n"
	"	Arc tangent. Returns an angle whose tangent is `y_over_x`. The range of values returned by\n"
	"	this function is `[-PI / 2, PI / 2]`.\n"
	"atan(y_over_x: vecN) -> vecN\n"
	"	Returns `atan(c)` for every component `c` of `x`.\n"
	"atan(y: float, x: float) -> float\n"
	"	Arc tangent. Returns an angle whose tangent is `y / x`. The signs of `x` and `y` are used to\n"
	"	determine what quadrant the angle is in. The range of values returned by this function\n"
	"	is `[-PI, PI]`. Results are undefined if `x` and `y` are both `0`.\n"
	"atan(y: vecN, x: vecN) -> vecN\n"
	"	Returns `atan(y[i], x[i])` for every index `i`."
);

PyDoc_STRVAR(sinh_docstr,
	"sinh(angle: float) -> float\n"
	"	Returns the hyperbolic sine function, `(exp(angle) - exp(-angle)) / 2`.\n"
	"sinh(angle: vecN) -> vecN\n"
	"	Returns `sinh(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(cosh_docstr,
	"cosh(angle: float) -> float\n"
	"	Returns the hyperbolic cosine function, `(exp(angle) + exp(-angle)) / 2`.\n"
	"cosh(angle: vecN) -> vecN\n"
	"	Returns `cosh(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(tanh_docstr,
	"tanh(angle: float) -> float\n"
	"	Returns the hyperbolic tangent function, `sinh(angle) / cosh(angle)`\n"
	"tanh(angle: vecN) -> vecN\n"
	"	Returns `tanh(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(asinh_docstr,
	"asinh(x: float) -> float\n"
	"	Arc hyperbolic sine; returns the inverse of `sinh`.\n"
	"asinh(x: vecN) -> vecN\n"
	"	Returns `asinh(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(acosh_docstr,
	"acosh(x: float) -> float\n"
	"	Arc hyperbolic cosine; returns the non-negative inverse of `cosh`. Results are undefined\n"
	"	if `x < 1`.\n"
	"acosh(x: vecN) -> vecN\n"
	"	Returns `acosh(c)` for every component `c` of `x`."
);

PyDoc_STRVAR(atanh_docstr,
	"atanh(x: float) -> float\n"
	"	Arc hyperbolic tangent; returns the inverse of `tanh`. Results are undefined if `abs(x) >= 1`.\n"
	"atanh(x: vecN) -> vecN\n"
	"	Returns `atanh(c)` for every component `c` of `x`."
);

#define FUNC_TRIGONOMETRIC_METHODS \
{ "radians", (PyCFunction)radians_, METH_O, radians_docstr }, \
{ "degrees", (PyCFunction)degrees_, METH_O, degrees_docstr }, \
{ "sin", (PyCFunction)sin_, METH_O, sin_docstr }, \
{ "cos", (PyCFunction)cos_, METH_O, cos_docstr }, \
{ "tan", (PyCFunction)tan_, METH_O, tan_docstr }, \
{ "asin", (PyCFunction)asin_, METH_O, asin_docstr }, \
{ "acos", (PyCFunction)acos_, METH_O, acos_docstr }, \
{ "atan", (PyCFunction)atan_,  METH_VARARGS, atan_docstr }, \
{ "sinh", (PyCFunction)sinh_, METH_O, sinh_docstr }, \
{ "cosh", (PyCFunction)cosh_, METH_O, cosh_docstr }, \
{ "tanh", (PyCFunction)tanh_, METH_O, tanh_docstr }, \
{ "asinh", (PyCFunction)asinh_, METH_O, asinh_docstr }, \
{ "acosh", (PyCFunction)acosh_, METH_O, acosh_docstr }, \
{ "atanh", (PyCFunction)atanh_, METH_O, atanh_docstr }
