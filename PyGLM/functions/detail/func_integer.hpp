#pragma once

#include "func_integer.h"

PyDoc_STRVAR(uaddCarry_docstr,
	"uaddCarry(x: int, y: int) -> (result: int, carry: int)\n"
	"	Adds 32-bit unsigned integer `x` and `y`, returning the `sum` modulo `pow(2, 32)`. The value carry\n"
	"	is set to `0` if the `sum` was less than `pow(2, 32)`, or to `1` otherwise.\n"
	"uaddCarry(x: uvecN, y: uvecN, carry: uvecN) -> uvecN\n"
	"	Adds 32-bit unsigned integer `x` and `y`, returning the `sum` modulo `pow(2, 32)`. The value carry\n"
	"	is set to `0` if the `sum` was less than `pow(2, 32)`, or to `1` otherwise."
);

PyDoc_STRVAR(usubBorrow_docstr,
	"usubBorrow(x: int, y: int) -> (result: int, borrow: int)\n"
	"	Subtracts the 32-bit unsigned integer `y` from `x`, returning the difference if non-negative,\n"
	"	or `pow(2, 32)` plus the difference otherwise. The value borrow is set to `0` if `x >= y`, or to\n"
	"	`1` otherwise.\n"
	"usubBorrow(x: uvecN, y: uvecN, borrow: uvecN) -> uvecN\n"
	"	Subtracts the 32-bit unsigned integer `y` from `x`, returning the difference if non-negative,\n"
	"	or `pow(2, 32)` plus the difference otherwise. The value borrow is set to `0` if `x >= y`, or to\n"
	"	`1` otherwise."
);

PyDoc_STRVAR(umulExtended_docstr,
	"umulExtended(x: int, y: int) -> (msb: int, lsb: int)\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`.\n"
	"umulExtended(x: uvecN, y: uvecN, msb: uvecN, lsb: uvecN) -> uvecN\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`."
);

PyDoc_STRVAR(imulExtended_docstr,
	"imulExtended(x: int, y: int) -> (msb: int, lsb: int)\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`.\n"
	"imulExtended(x: ivecN, y: ivecN, msb: ivecN, lsb: ivecN) -> ivecN\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`."
);

PyDoc_STRVAR(bitfieldExtract_docstr,
	"bitfieldExtract(value: ctypes, offset: int, bits: int) -> int\n"
	"	Extracts bits `[offset, offset + bits - 1]` from value, returning them in the least\n"
	"	significant bits of the result. For unsigned data types, the most significant bits of the\n"
	"	result will be set to zero. For signed data types, the most significant bits will be set to\n"
	"	the value of bit `offset + base - 1`. If `bits` is zero, the result will be zero. The result\n"
	"	will be undefined if `offset` or `bits` is negative, or if the sum of `offset` and `bits` is\n"
	"	greater than the number of bits used to store the operand.\n"
	"	You can use `int32`, `uint32`, `int64` or `uint64` types to specify the number of bits and the\n"
	"	sign.\n"
	"bitfieldExtract(value: vecN, offset: int, bits: int) -> vecN\n"
	"	Returns `bitfieldExtract(c, offset, bits)` for every component `c` of `value`."
);

PyDoc_STRVAR(bitfieldInsert_docstr,
	"bitfieldInsert(base: ctypes, insert: ctypes, offset: int, bits: int) -> int\n"
	"	Returns the insertion the bits least-significant bits of insert into base. The result will\n"
	"	have `bits[offset, offset + bits - 1]` taken from `bits[0, bits - 1]` of `insert`, and all other\n"
	"	bits taken directly from the corresponding bits of `base`. If `bits` is zero, the result will\n"
	"	simply be `base`. The result will be undefined if `offset` or `bits` is negative, or if the sum of\n"
	"	`offset` and `bits` is greater than the number of bits used to store the operand.\n"
	"	You can use `int32`, `uint32`, `int64` or `uint64` types to specify the number of bits and the\n"
	"	sign.\n"
	"bitfieldInsert(base: vecN, insert: vecN, offset: int, bits: int) -> vecN\n"
	"	Returns `bitfieldInsert(base[i], insert[i], offset, bits)` for every index `i`."
);

PyDoc_STRVAR(bitfieldReverse_docstr,
	"bitfieldReverse(value: ctypes) -> int\n"
	"	Returns the reversal of the bits of `value`. The bit numbered `n` of the result will be taken\n"
	"	from `bit(bits - 1) - n` of `value`, where `bits` is the total number of bits used to represent\n"
	"	`value`. You can use `int32`, `uint32`, `int64` or `uint64` types to specify the number of bits\n"
	"	and the sign.\n"
	"bitfieldReverse(value: vecN) -> vecN\n"
	"	Returns the reversal of the bits of `value`. The bit numbered `n` of the result will be taken\n"
	"	from `bit(bits - 1) - n` of `value`, where `bits` is the total number of bits used to represent\n"
	"	`value`."
);

PyDoc_STRVAR(bitCount_docstr,
	"bitCount(v: int) -> int\n"
	"	Returns the number of bits set to `1` in the binary representation of `value`.\n"
	"bitCount(v: vecN) -> ivecN\n"
	"	For every component `c` of `v`:\n"
	"	Returns the number of bits set to `1` in the binary representation of `c`."
);

PyDoc_STRVAR(findLSB_docstr,
	"findLSB(value: int) -> int\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned.\n"
	"findLSB(value: vecN) -> ivecN\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned."
);

PyDoc_STRVAR(findMSB_docstr,
	"findMSB(value: int) -> int\n"
	"	Returns the bit number of the most significant bit in the binary representation of `value`.\n"
	"	For positive integers, the result will be the bit number of the most significant bit set to\n"
	"	`1`. For negative integers, the result will be the bit number of the most significant bit set\n"
	"	to `0`. For a value of zero or negative one, `-1` will be returned.\n"
	"findMSB(value: vecN) -> ivecN\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned."
);

#define FUNC_INTEGER_METHODS \
{ "uaddCarry", (PyCFunction)uaddCarry_, METH_VARARGS, uaddCarry_docstr }, \
{ "usubBorrow", (PyCFunction)usubBorrow_, METH_VARARGS, usubBorrow_docstr }, \
{ "umulExtended", (PyCFunction)umulExtended_, METH_VARARGS, umulExtended_docstr }, \
{ "imulExtended", (PyCFunction)imulExtended_, METH_VARARGS, imulExtended_docstr }, \
{ "bitfieldExtract", (PyCFunction)bitfieldExtract_, METH_VARARGS, bitfieldExtract_docstr }, \
{ "bitfieldInsert", (PyCFunction)bitfieldInsert_, METH_VARARGS, bitfieldInsert_docstr }, \
{ "bitfieldReverse", (PyCFunction)bitfieldReverse_, METH_O, bitfieldReverse_docstr }, \
{ "bitCount", (PyCFunction)bitCount_, METH_O, bitCount_docstr }, \
{ "findLSB", (PyCFunction)findLSB_, METH_O, findLSB_docstr }, \
{ "findMSB", (PyCFunction)findMSB_, METH_O, findMSB_docstr }
