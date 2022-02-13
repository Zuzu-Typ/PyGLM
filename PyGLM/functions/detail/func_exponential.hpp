#pragma once

#include "func_exponential.h"

PyDoc_STRVAR(pow_docstr,
	"pow(base: float, exponent: float) -> float\n"
	"	Returns base raised to the power exponent.\n"
	"pow(base: vecN, exponent: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `base[i]` raised to the power `exponent[i]`.\n"
	"pow(base: quat, exponent: quat) -> quat\n"
	"	Returns a quaternion raised to a power."
);

PyDoc_STRVAR(exp_docstr,
	"exp(x: float) -> float\n"
	"	Returns the natural exponentiation of `x`, i.e., `e^x`.\n"
	"exp(x: vecN) -> vecN\n"
	"	For every component c of x:\n"
	"	Returns the natural exponentiation of `c`, i.e., `e^c`.\n"
	"exp(x: quat) -> quat\n"
	"	Returns an exponential of a quaternion."
);

PyDoc_STRVAR(log_docstr,
	"log(x: float) -> float\n"
	"	Returns the natural logarithm of `x`, i.e., returns the value `y` which satisfies the equation\n"
	"	`x = e^y`. Results are undefined if `x <= 0`.\n"
	"log(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the natural logarithm of `c`, i.e., returns the value `y` which satisfies the equation\n"
	"	`c = e^y`. Results are undefined if `c <= 0`.\n"
	"log(x: quat) -> quat\n"
	"	Returns a logarithm of a quaternion."
);

PyDoc_STRVAR(exp2_docstr,
	"exp2(x: float) -> float\n"
	"	Returns `2` raised to the `x` power.\n"
	"exp2(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns `2` raised to the `c` power."
);

PyDoc_STRVAR(log2_docstr,
	"log2(x: float) -> float\n"
	"	Returns the base `2` log of `x`, i.e., returns the value `y`, which satisfies the equation\n"
	"	`x = 2 ^ y`.\n"
	"log2(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the base `2` log of `c`, i.e., returns the value `y`, which satisfies the equation\n"
	"	`c = 2 ^ y`."
);

PyDoc_STRVAR(sqrt_docstr,
	"sqrt(x: float) -> float\n"
	"	Returns the positive square root of `x`.\n"
	"sqrt(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the positive square root of `c`.\n"
	"sqrt(x: quat) -> quat\n"
	"	Returns the square root of a quaternion."
);

PyDoc_STRVAR(inversesqrt_docstr,
	"inversesqrt(x: float) -> float\n"
	"	Returns the reciprocal of the positive square root of `x`.\n"
	"inversesqrt(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns the reciprocal of the positive square root of `c`."
);

#define FUNC_EXPONENTIAL \
{ "pow", (PyCFunction)pow_, METH_VARARGS, pow_docstr }, \
{ "exp", (PyCFunction)exp_, METH_O, exp_docstr }, \
{ "log", (PyCFunction)log_, METH_O, log_docstr }, \
{ "exp2", (PyCFunction)exp2_, METH_O, exp2_docstr }, \
{ "log2", (PyCFunction)log2_, METH_O, log2_docstr }, \
{ "sqrt", (PyCFunction)sqrt_, METH_O, sqrt_docstr }, \
{ "inversesqrt", (PyCFunction)inversesqrt_, METH_O, inversesqrt_docstr }
