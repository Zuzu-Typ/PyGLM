#pragma once

#include "func_packing.h"

PyDoc_STRVAR(packDouble2x32_docstr,
	"packDouble2x32(v: uvec2) -> float\n"
	"	Returns a double-qualifier value obtained by packing the components of `v` into a 64-bit\n"
	"	value. If an IEEE 754 `Inf` or `NaN` is created, it will not signal, and the resulting floating\n"
	"	point value is unspecified. Otherwise, the bit-level representation of `v` is preserved. The\n"
	"	first vector component specifies the 32 least significant bits; the second component\n"
	"	specifies the 32 most significant bits."
);

PyDoc_STRVAR(packUnorm2x16_docstr,
	"packUnorm2x16(v: vec2) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 8- or 16-bit\n"
	"	integer values. Then, the results are packed into the returned 32-bit unsigned integer.\n"
	"	The conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, 0, +1) * 65535.0)`. The first component of the vector will be written to the\n"
	"	least significant bits of the output; the last component will be written to the most\n"
	"	significant bits."
);

PyDoc_STRVAR(packSnorm2x16_docstr,
	"packSnorm2x16(v: vec2) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 8- or 16-bit\n"
	"	integer values. Then, the results are packed into the returned 32-bit unsigned integer.\n"
	"	The conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(v, -1, +1) * 32767.0)`. The first component of the vector will be written to\n"
	"	the least significant bits of the output; the last component will be written to the most\n"
	"	significant bits."
);

PyDoc_STRVAR(packUnorm4x8_docstr,
	"packUnorm4x8(v: vec4) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 8- or 16-bit\n"
	"	integer values. Then, the results are packed into the returned 32-bit unsigned integer.\n"
	"	The conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, 0, +1) * 255.0)`. The first component of the vector will be written to the\n"
	"	least significant bits of the output; the last component will be written to the most\n"
	"	significant bits."
);

PyDoc_STRVAR(packSnorm4x8_docstr,
	"packSnorm4x8(v: vec4) -> int\n"
	"	First, converts each component of the normalized floating-point value `v` into 8- or 16-bit\n"
	"	integer values. Then, the results are packed into the returned 32-bit unsigned integer.\n"
	"	The conversion for component `c` of `v` to fixed point is done as follows :\n"
	"	`round(clamp(c, -1, +1) * 127.0)`. The first component of the vector will be written to\n"
	"	the least significant bits of the output; the last component will be written to the most\n"
	"	significant bits."
);

PyDoc_STRVAR(packHalf2x16_docstr,
	"packHalf2x16(v: vec2) -> int\n"
	"	Returns an unsigned integer obtained by converting the components of a two-component\n"
	"	floating-point vector to the 16-bit floating-point representation found in the OpenGL\n"
	"	Specification, and then packing these two 16-bit integers into a 32-bit unsigned integer.\n"
	"	The first vector component specifies the 16 least-significant bits of the result; the\n"
	"	second component specifies the 16 most-significant bits."
);

PyDoc_STRVAR(unpackDouble2x32_docstr,
	"unpackDouble2x32(v: double) -> uvec2\n"
	"	Returns a two-component unsigned integer vector representation of `v`. The bit-level\n"
	"	representation of `v` is preserved. The first component of the vector contains the 32 least\n"
	"	significant bits of the double; the second component consists the 32 most significant bits."
);

PyDoc_STRVAR(unpackUnorm2x16_docstr,
	"unpackUnorm2x16(p: int) -> vec2\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into a pair of 16-bit unsigned integers,\n"
	"	four 8-bit unsigned integers, or four 8-bit signed integers. Then, each component is\n"
	"	converted to a normalized floating-point value to generate the returned two- or\n"
	"	four-component vector. The conversion for unpacked fixed-point value `f` to floating point\n"
	"	is done as follows : `f / 65535.0`. The first component of the returned\n"
	"	vector will be extracted from the least significant bits of the input; the last component\n"
	"	will be extracted from the most significant bits."
);

PyDoc_STRVAR(unpackSnorm2x16_docstr,
	"unpackSnorm2x16(p: int) -> vec2\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into a pair of 16-bit unsigned integers,\n"
	"	four 8-bit unsigned integers, or four 8-bit signed integers. Then, each component is\n"
	"	converted to a normalized floating-point value to generate the returned two- or\n"
	"	four-component vector. The conversion for unpacked fixed-point value `f` to floating point\n"
	"	is done as follows : `clamp(f / 32767.0, -1, +1)`. The first component of\n"
	"	the returned vector will be extracted from the least significant bits of the input; the\n"
	"	last component will be extracted from the most significant bits."
);

PyDoc_STRVAR(unpackUnorm4x8_docstr,
	"unpackUnorm4x8(p: int) -> vec4\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into a pair of 16-bit unsigned integers,\n"
	"	four 8-bit unsigned integers, or four 8-bit signed integers. Then, each component is\n"
	"	converted to a normalized floating-point value to generate the returned two- or\n"
	"	four-component vector. The conversion for unpacked fixed-point value `f` to floating point\n"
	"	is done as follows : `f / 255.0`. The first component of the returned vector\n"
	"	will be extracted from the least significant bits of the input; the last component will be\n"
	"	extracted from the most significant bits."
);

PyDoc_STRVAR(unpackSnorm4x8_docstr,
	"unpackSnorm4x8(p: int) -> vec4\n"
	"	First, unpacks a single 32-bit unsigned integer `p` into a pair of 16-bit unsigned integers,\n"
	"	four 8-bit unsigned integers, or four 8-bit signed integers. Then, each component is\n"
	"	converted to a normalized floating-point value to generate the returned two- or\n"
	"	four-component vector. The conversion for unpacked fixed-point value `f` to floating point\n"
	"	is done as follows : `clamp(f / 127.0, -1, +1)`. The first component of the\n"
	"	returned vector will be extracted from the least significant bits of the input; the last\n"
	"	component will be extracted from the most significant bits."
);

PyDoc_STRVAR(unpackHalf2x16_docstr,
	"unpackHalf2x16(v: int) -> vec2\n"
	"	Returns a two-component floating-point vector with components obtained by unpacking a\n"
	"	32-bit unsigned integer into a pair of 16-bit values, interpreting those values as 16-bit\n"
	"	floating-point numbers according to the OpenGL Specification, and converting them to 32-bit\n"
	"	floating-point values. The first component of the vector is obtained from the 16\n"
	"	least-significant bits of `v`; the second component is obtained from the 16\n"
	"	most-significant bits of `v`."
);

#define FUNC_PACKING_METHODS \
{ "packDouble2x32", (PyCFunction)packDouble2x32_, METH_O, packDouble2x32_docstr }, \
{ "packUnorm2x16", (PyCFunction)packUnorm2x16_, METH_O, packUnorm2x16_docstr }, \
{ "packSnorm2x16", (PyCFunction)packSnorm2x16_, METH_O, packSnorm2x16_docstr }, \
{ "packSnorm4x8", (PyCFunction)packSnorm4x8_, METH_O, packSnorm4x8_docstr }, \
{ "packUnorm4x8", (PyCFunction)packUnorm4x8_, METH_O, packUnorm4x8_docstr }, \
{ "packHalf2x16", (PyCFunction)packHalf2x16_, METH_O, packHalf2x16_docstr }, \
{ "unpackDouble2x32", (PyCFunction)unpackDouble2x32_, METH_O, unpackDouble2x32_docstr }, \
{ "unpackUnorm2x16", (PyCFunction)unpackUnorm2x16_, METH_O, unpackUnorm2x16_docstr }, \
{ "unpackSnorm2x16", (PyCFunction)unpackSnorm2x16_, METH_O, unpackSnorm2x16_docstr }, \
{ "unpackSnorm4x8", (PyCFunction)unpackSnorm4x8_, METH_O, unpackSnorm4x8_docstr }, \
{ "unpackUnorm4x8", (PyCFunction)unpackUnorm4x8_, METH_O, unpackUnorm4x8_docstr }, \
{ "unpackHalf2x16", (PyCFunction)unpackHalf2x16_, METH_O, unpackHalf2x16_docstr }
