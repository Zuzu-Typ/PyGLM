#pragma once

#include "func_common.h"

PyDoc_STRVAR(abs_docstr,
	"abs(x: float) -> float\n"
	"	Returns `x` if `x >= 0`; otherwise it returns `-x`.\n"
	"abs(x: vecN) -> vecN\n"
	"	For each component `c` of `x`,\n"
	"	Returns `c` if `c >= 0`; otherwise it returns `-c`.\n"
	"abs(x: any) -> any\n"
	"	Returns `__builtins__.abs(x)`."
);

PyDoc_STRVAR(sign_docstr,
	"sign(x: number) -> float\n"
	"	Returns `1.0` if `x > 0`, `0.0` if `x == 0`, or `-1.0` if `x < 0`.\n"
	"sign(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns `1.0` if `x > 0`, `0.0` if `x == 0`, or `-1.0` if `x < 0`."
);

PyDoc_STRVAR(floor_docstr,
	"floor(x: float) -> float\n"
	"	Returns a value equal to the nearest integer that is less then or equal to `x`.\n"
	"floor(v: vecN) -> vecN\n"
	"	For each component `c` of `v`:\n"
	"	Returns a value equal to the nearest integer that is less then or equal to `c`."
);

PyDoc_STRVAR(trunc_docstr,
	"trunc(x: number) -> float\n"
	"	Returns a value equal to the nearest integer to `x` whose absolute value is not larger than\n"
	"	the absolute value of `x`.\n"
	"trunc(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns a value equal to the nearest integer to `c` whose absolute value is not larger than\n"
	"	the absolute value of `c`."
);

PyDoc_STRVAR(round_docstr,
	"round(x: number) -> float\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest. This\n"
	"	includes the possibility that `round(x)` returns the same value as `roundEven(x)`\n"
	"round(x: vecN) -> vecN\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest. This\n"
	"	includes the possibility that `round(x)` returns the same value as `roundEven(x)` for all\n"
	"	values of `x`."
);

PyDoc_STRVAR(roundEven_docstr,
	"roundEven(x: number) -> float\n"
	"	Returns a value equal to the nearest integer to `x`. A fractional part of `0.5` will round\n"
	"	toward the nearest even integer. (Both `3.5` and `4.5` for `x` will return `4.0`.)\n"
	"roundEven(x: vecN) -> vecN\n"
	"	Returns a value equal to the nearest integer to `x`. A fractional part of `0.5` will round\n"
	"	toward the nearest even integer. (Both `3.5` and `4.5` for `x` will return `4.0`.)"
);

PyDoc_STRVAR(ceil_docstr,
	"ceil(x: float) -> float\n"
	"	Returns a value equal to the nearest integer that is greater than or equal to `x`.\n"
	"ceil(x: vecN) -> vecN\n"
	"	For each component `c` of `x`,\n"
	"	Returns a value equal to the nearest integer that is greater than or equal to `c`.\n"
);

PyDoc_STRVAR(fract_docstr,
	"fract(x: float) -> float\n"
	"	Returns `x - floor(x)`.\n"
	"fract(c: vecN) -> vecN\n"
	"	Returns `x - floor(x)`."
);

PyDoc_STRVAR(mod_docstr,
	"mod(x: vecN, y: vecN) -> vecN\n"
	"	Returns `x - y * floor(x / y)` for each component in `x` using the floating point value `y`.\n"
	"mod(x: vecN, y: number) -> vecN\n"
	"	Returns `x - y * floor(x / y)` for each component in `x` using the floating point value `y`.\n"
	"mod(x: number, y: number) -> number\n"
	"	Returns `x - y * floor(x / y)` for each component in `x` using the floating point value `y`."
);

PyDoc_STRVAR(min_docstr,
	"min(x: number, y: number) -> float\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`.\n"
	"min(x: vecN, y: number) -> vecN\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`.\n"
	"min(x: vecN, y: vecN) -> vecN\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`.\n"
	"min(a: number, b: number, c: number) -> float\n"
	"	Returns the minimum value of 3 inputs.\n"
	"min(a: vecN, b: vecN, c: vecN) -> vecN\n"
	"	Returns the minimum component wise value of 3 inputs.\n"
	"min(a: number, b: number, c: number, d: number) -> float\n"
	"	Returns the minimum value of 4 inputs.\n"
	"min(a: vecN, b: vecN, c: vecN, d: vecN) -> vecN\n"
	"	Returns the minimum component wise value of 4 inputs.\n"
	"min(iterable) -> any\n"
	"	Returns the smallest number or the minimum component wise value respectively."
);

PyDoc_STRVAR(max_docstr,
	"max(x: number, y: number) -> float\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`.\n"
	"max(x: vecN, y: number) -> vecN\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`.\n"
	"max(x: vecN, y: vecN) -> vecN\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`.\n"
	"max(a: number, b: number, c: number) -> float\n"
	"	Returns the maximum value of 3 inputs.\n"
	"max(a: vecN, b: vecN, c: vecN) -> vecN\n"
	"	Returns the maximum component wise value of 3 inputs.\n"
	"max(a: number, b: number, c: number, d: number) -> float\n"
	"	Returns the maximum value of 4 inputs.\n"
	"max(a: vecN, b: vecN, c: vecN, d: vecN) -> vecN\n"
	"	Returns the maximum component wise value of 4 inputs.\n"
	"max(iterable) -> any\n"
	"	Returns the greatest number or the maximum component wise value respectively."
);

PyDoc_STRVAR(fmin_docstr,
	"fmin(x: number, y: number) -> float\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmin(x: vecN, y: number) -> vecN\n"
	"	For each component `c` of `x`:\n"
	"	Returns `y` if `y < c`; otherwise, it returns `c`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmin(x: vecN, y: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `y[i]` if `y[i] < x[i]`; otherwise, it returns `x[i]`. If one of the two arguments is\n"
	"	`NaN`, the value of the other argument is returned.\n"
	"fmin(a: vecN, b: vecN, c : vecN) -> vecN\n"
	"	Returns `fmin(fmin(a, b), c)`.\n"
	"fmin(a: vecN, b: vecN, c : vecN, d: vecN) -> vecN\n"
	"	Returns `fmin(fmin(a, b), fmin(c, d))`."
);

PyDoc_STRVAR(fmax_docstr,
	"fmax(x: number, y: number) -> float\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmax(x: vecN, y: number) -> vecN\n"
	"	For each component `c` of `x`:\n"
	"	Returns `y` if `c < y`; otherwise, it returns `c`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmax(x: vecN, y: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `y[i]` if `x[i] < y[i]`; otherwise, it returns `x[i]`. If one of the two arguments is\n"
	"	`NaN`, the value of the other argument is returned.\n"
	"fmax(a: vecN, b: vecN, c: vecN) -> vecN\n"
	"	Returns `fmax(fmax(a, b), c)`.\n"
	"fmax(a: vecN, b: vecN, c: vecN, d: vecN) -> vecN\n"
	"	Returns `fmax(fmax(a, b), fmax(c, d))`."
);

PyDoc_STRVAR(clamp_docstr,
	"clamp(x: number, minVal: number, maxVal: number) -> number\n"
	"	Returns `min(max(x, minVal), maxVal)`.\n"
	"clamp(x: vecN, minVal: number, maxVal: number) -> vecN\n"
	"	Returns `min(max(x, minVal), maxVal)` for each component in `x` using the floating-point values\n"
	"	`minVal` and `maxVal`.\n"
	"clamp(x: vecN, minVal: vecN, maxVal: vecN) -> vecN\n"
	"	Returns `min(max(x, minVal), maxVal)` for each component in `x` using the floating-point values\n"
	"	`minVal` and `maxVal`.\n"
);

PyDoc_STRVAR(mix_docstr,
	"mix(x: number, y: number, a: float) -> number\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: number, y: number, a: bool) -> number\n"
	"	Returns `y` if `a` is `True` and `x` otherwise.\n"
	"mix(x: vecN, y: vecN, a: fvecN) -> vecN\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: vecN, y: vecN, a: bvecN) -> vecN\n"
	"	For each component index `i`:\n"
	"	Returns `y[i]` if `a[i]` is `True` and `x[i]` otherwise.\n"
	"mix(x: matNxM, y: matNxM, a: fmatNxM) -> matNxM\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a` for each component. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: matNxM, y: matNxM, a: float) -> matNxM\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a` for each component. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: quat, y: quat, a: float) -> quat\n"
	"	Spherical linear interpolation of two quaternions. The interpolation is oriented and the\n"
	"	rotation is performed at constant speed. For short path spherical linear interpolation, use\n"
	"	the `slerp` function."
);

PyDoc_STRVAR(step_docstr,
	"step(edge: number, x: number) -> float\n"
	"	Returns `0.0` if `x < edge`, otherwise it returns `1.0`.\n"
	"step(edge: number, x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns `0.0` if `c < edge`, otherwise it returns `1.0`.\n"
	"step(edge: vecN, x: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `0.0` if `x[i] < edge[i]`, otherwise it returns `1.0`."
);

PyDoc_STRVAR(smoothstep_docstr,
	"smoothstep(edge0: number, edge1: number, x: number) -> float\n"
	"	Returns `0.0` if `x <= edge0` and `1.0` if `x >= edge1` and performs smooth Hermite interpolation\n"
	"	between `0` and `1` when `edge0 < x < edge1`. This is useful in cases where you would want a\n"
	"	threshold function with a smooth transition. This is equivalent to :\n"
	"	`t = clamp((x - edge0) / (edge1 - edge0), 0, 1)`\n"
	"	`return t * t * (3 - 2 * t)`\n"
	"	Results are undefined if `edge0 >= edge1`.\n"
	"smoothstep(edge0: number, edge1: number, x: vecN) -> vecN\n"
	"	Returns `0.0` if `x <= edge0` and `1.0` if `x >= edge1` and performs smooth Hermite interpolation\n"
	"	between `0` and `1` when `edge0 < x < edge1`. This is useful in cases where you would want a\n"
	"	threshold function with a smooth transition. This is equivalent to :\n"
	"	`t = clamp((x - edge0) / (edge1 - edge0), 0, 1)`\n"
	"	`return t * t * (3 - 2 * t)`\n"
	"	Results are undefined if `edge0 >= edge1`.\n"
	"smoothstep(edge0: vecN, edge1: vecN, x: vecN) -> vecN\n"
	"	Returns `0.0` if `x <= edge0` and `1.0` if `x >= edge1` and performs smooth Hermite interpolation\n"
	"	between `0` and `1` when `edge0 < x < edge1`. This is useful in cases where you would want a\n"
	"	threshold function with a smooth transition. This is equivalent to :\n"
	"	`t = clamp((x - edge0) / (edge1 - edge0), 0, 1)`\n"
	"	`return t * t * (3 - 2 * t)`\n"
	"	Results are undefined if `edge0 >= edge1`."
);

PyDoc_STRVAR(isnan_docstr,
	"isnan(x: float) -> bool\n"
	"	Returns `True` if `x` holds a `NaN` (not a number) representation in the underlying\n"
	"	implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no `NaN` representations.\n"
	"isnan(x: vecN) -> bvecN\n"
	"	Returns `True` if `x` holds a `NaN` (not a number) representation in the underlying\n"
	"	implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no `NaN` representations.\n"
	"isnan(x: quat) -> bvecN\n"
	"	Returns `True` if `x` holds a `NaN` (not a number) representation in the underlying\n"
	"	implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no `NaN` representations."
);

PyDoc_STRVAR(isinf_docstr,
	"isinf(x: float) -> bool\n"
	"	Returns `True` if `x` holds a positive infinity or negative infinity representation in the\n"
	"	underlying implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no infinity representations.\n"
	"isinf(x: vecN) -> bvecN\n"
	"	Returns `True` if `x` holds a positive infinity or negative infinity representation in the\n"
	"	underlying implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no infinity representations.\n"
	"isinf(x: quat) -> bvecN\n"
	"	Returns `True` if `x` holds a positive infinity or negative infinity representation in the\n"
	"	underlying implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no infinity representations."
);

PyDoc_STRVAR(fma_docstr,
	"fma(a: float, b: float, c: float) -> float\n"
	"	Computes and returns `a * b + c`."
);

PyDoc_STRVAR(frexp_docstr,
	"frexp(x: float) -> (significant: float, exponent: int)\n"
	"	Splits `x` into a floating-point significand in the range `[0.5, 1.0)` and an integral exponent\n"
	"	of two, such that: `x = significand * exp(2, exponent)`\n"
	"frexp(x: vecN, exp: ivecN) -> vecN\n"
	"	Splits `x` into a floating-point significand in the range `[0.5, 1.0)` and an integral exponent\n"
	"	of two, such that: `x = significand * exp(2, exponent)`\n"
	"	The significand is returned by the function and the exponent is returned in the parameter\n"
	"	`exp`. For a floating-point value of zero, the significantand exponent are both zero. For a\n"
	"	floating-point value that is an infinity or is not a number, the results are undefined."
);

PyDoc_STRVAR(ldexp_docstr,
	"ldexp(x: number, exp: int) -> float\n"
	"	Builds a floating-point number from `x` and the corresponding integral exponent of two in\n"
	"	`exp`, returning: `significand * exp(2, exponent)`. If this product is too large to be\n"
	"	represented in the floating-point type, the result is undefined.\n"
	"ldexp(x: vecN, exp: ivecN) -> vecN\n"
	"	Builds a floating-point number from `x` and the corresponding integral exponent of two in\n"
	"	`exp`, returning: `significand * exp(2, exponent)`. If this product is too large to be\n"
	"	represented in the floating-point type, the result is undefined."
);

PyDoc_STRVAR(floatBitsToInt_docstr,
	"floatBitsToInt(v: float) -> int\n"
	"	Returns a signed integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
	"floatBitsToInt(v: fvecN) -> ivecN\n"
	"	Returns a signed integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
);

PyDoc_STRVAR(floatBitsToUint_docstr,
	"floatBitsToUint(v: float) -> int\n"
	"	Returns an unsigned integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
	"floatBitsToUint(v: fvecN) -> uvecN\n"
	"	Returns an unsigned integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
);

PyDoc_STRVAR(intBitsToFloat_docstr,
	"intBitsToFloat(v: int) -> float\n"
	"	Returns a floating-point value corresponding to a signed integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved.\n"
	"intBitsToFloat(v: ivecN) -> fvecN\n"
	"	Returns a floating-point value corresponding to a signed integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved."
);

PyDoc_STRVAR(uintBitsToFloat_docstr,
	"uintBitsToFloat(v: int) -> float\n"
	"	Returns a floating-point value corresponding to an unsigned integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved.\n"
	"uintBitsToFloat(v: ivecN) -> fvecN\n"
	"	Returns a floating-point value corresponding to an unsigned integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved."
);

PyDoc_STRVAR(modf_docstr,
	"modf(x: float) -> (fraction, integer)\n"
	"	Returns the fractional part of `x` and the integer part (as a whole number floating point value).\n"
	"modf(x: vecN, i: vecN) -> vecN\n"
	"	Returns the fractional part of `x` and sets `i` to the integer part (as a whole number floating\n"
	"	point value)."
);

#define FUNC_COMMON_METHODS \
{ "abs", (PyCFunction)abs_, METH_O, abs_docstr }, \
{ "sign", (PyCFunction)sign_, METH_O, sign_docstr }, \
{ "floor", (PyCFunction)floor_, METH_O, floor_docstr }, \
{ "trunc", (PyCFunction)trunc_, METH_O, trunc_docstr }, \
{ "round", (PyCFunction)round_, METH_O, round_docstr }, \
{ "roundEven", (PyCFunction)roundEven_, METH_O, roundEven_docstr }, \
{ "ceil", (PyCFunction)ceil_, METH_O, ceil_docstr }, \
{ "fract", (PyCFunction)fract_, METH_O, fract_docstr }, \
{ "mod", (PyCFunction)mod_, METH_VARARGS, mod_docstr }, \
{ "min", (PyCFunction)min_, METH_VARARGS, min_docstr }, \
{ "max", (PyCFunction)max_, METH_VARARGS, max_docstr }, \
{ "fmin", (PyCFunction)fmin_, METH_VARARGS, fmin_docstr }, \
{ "fmax", (PyCFunction)fmax_, METH_VARARGS, fmax_docstr }, \
{ "clamp", (PyCFunction)clamp_, METH_VARARGS, clamp_docstr }, \
{ "mix", (PyCFunction)mix_, METH_VARARGS, mix_docstr }, \
{ "step", (PyCFunction)step_, METH_VARARGS, step_docstr }, \
{ "smoothstep", (PyCFunction)smoothstep_, METH_VARARGS, smoothstep_docstr }, \
{ "isnan", (PyCFunction)isnan_, METH_O, isnan_docstr }, \
{ "isinf", (PyCFunction)isinf_, METH_O, isinf_docstr }, \
{ "fma", (PyCFunction)fma_, METH_VARARGS, fma_docstr }, \
{ "frexp", (PyCFunction)frexp_, METH_VARARGS, frexp_docstr }, \
{ "ldexp", (PyCFunction)ldexp_, METH_VARARGS, ldexp_docstr }, \
{ "floatBitsToInt", (PyCFunction)floatBitsToInt_, METH_O, floatBitsToInt_docstr }, \
{ "floatBitsToUint", (PyCFunction)floatBitsToUint_, METH_O, floatBitsToUint_docstr }, \
{ "intBitsToFloat", (PyCFunction)intBitsToFloat_, METH_O, intBitsToFloat_docstr }, \
{ "uintBitsToFloat", (PyCFunction)uintBitsToFloat_, METH_O, uintBitsToFloat_docstr }, \
{ "modf", (PyCFunction)modf_, METH_VARARGS, modf_docstr }
