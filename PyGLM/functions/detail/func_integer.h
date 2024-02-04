#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

PyDoc_STRVAR(uaddCarry_docstr,
	"uaddCarry(x: int, y: int) -> (result: int, carry: int)\n"
	"	Adds 32-bit unsigned integer `x` and `y`, returning the `sum` modulo `pow(2, 32)`. The value carry\n"
	"	is set to `0` if the `sum` was less than `pow(2, 32)`, or to `1` otherwise.\n"
	"uaddCarry(x: uvecN, y: uvecN, carry: uvecN) -> uvecN\n"
	"	Adds 32-bit unsigned integer `x` and `y`, returning the `sum` modulo `pow(2, 32)`. The value carry\n"
	"	is set to `0` if the `sum` was less than `pow(2, 32)`, or to `1` otherwise."
);
static PyObject*
uaddCarry_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "uaddCarry", 2, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg3 == NULL) {
		if (PyLong_Check(arg1) && PyLong_Check(arg2) ) {
			glm::uint carry;
			glm::uint result = glm::uaddCarry(_PyGLM_Long_As_Number_No_Error<glm::uint>(arg1), _PyGLM_Long_As_Number_No_Error<glm::uint>(arg2), carry);
			return Py_BuildValue("(I,I)", result, carry);
		}
	}
	else {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);
			GET_PyGLM_ARG_TYPE(arg3);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);
			GET_PyGLM_ARG_SUBTYPE(arg3);

			if (arg1Subtype == arg2Subtype && arg1Subtype == arg3Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L) \
				case PyGLMTypeObjectArrayOffsetVec<L, uint32>(): \
					return pack(glm::uaddCarry(PyGLM_VecOrMVec_Get(L, uint32, arg1), PyGLM_VecOrMVec_Get(L, uint32, arg2), PyGLM_VecOrMVec_Get(L, uint32, arg3)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for uaddCarry()");
	return NULL;
}

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
static PyObject*
usubBorrow_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "usubBorrow", 2, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg3 == NULL) {
		if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
			glm::uint borrow;
			glm::uint result = glm::usubBorrow(_PyGLM_Long_As_Number_No_Error<glm::uint>(arg1), _PyGLM_Long_As_Number_No_Error<glm::uint>(arg2), borrow);
			return Py_BuildValue("(I,I)", result, borrow);
		}
	}
	else {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);
			GET_PyGLM_ARG_TYPE(arg3);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);
			GET_PyGLM_ARG_SUBTYPE(arg3);

			if (arg1Subtype == arg2Subtype && arg1Subtype == arg3Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L) \
				case PyGLMTypeObjectArrayOffsetVec<L, uint32>(): \
					return pack(glm::usubBorrow(PyGLM_VecOrMVec_Get(L, uint32, arg1), PyGLM_VecOrMVec_Get(L, uint32, arg2), PyGLM_VecOrMVec_Get(L, uint32, arg3)));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for usubBorrow()");
	return NULL;
}

PyDoc_STRVAR(umulExtended_docstr,
	"umulExtended(x: int, y: int) -> (msb: int, lsb: int)\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`.\n"
	"umulExtended(x: uvecN, y: uvecN, msb: uvecN, lsb: uvecN) -> uvecN\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`."
);
static PyObject*
umulExtended_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "umulExtended", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
			glm::uint msb, lsb;
			glm::umulExtended(_PyGLM_Long_As_Number_No_Error<glm::uint>(arg1), _PyGLM_Long_As_Number_No_Error<glm::uint>(arg2), msb, lsb);
			return Py_BuildValue("(I,I)", msb, lsb);
		}
	}
	else if (arg4 != NULL) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3) && Is_PyGLM_Object(arg4)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);
			GET_PyGLM_ARG_TYPE(arg3);
			GET_PyGLM_ARG_TYPE(arg4);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);
			GET_PyGLM_ARG_SUBTYPE(arg3);
			GET_PyGLM_ARG_SUBTYPE(arg4);

			if (arg1Subtype == arg2Subtype && arg1Subtype == arg3Subtype && arg1Subtype == arg4Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L) \
					case PyGLMTypeObjectArrayOffsetVec<L, uint32>(): \
						glm::umulExtended(PyGLM_VecOrMVec_Get(L, uint32, arg1), PyGLM_VecOrMVec_Get(L, uint32, arg2), PyGLM_VecOrMVec_Get(L, uint32, arg3), PyGLM_VecOrMVec_Get(L, uint32, arg4)); \
						Py_RETURN_NONE;

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for umulExtended()");
	return NULL;
}

PyDoc_STRVAR(imulExtended_docstr,
	"imulExtended(x: int, y: int) -> (msb: int, lsb: int)\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`.\n"
	"imulExtended(x: ivecN, y: ivecN, msb: ivecN, lsb: ivecN) -> ivecN\n"
	"	Multiplies 32-bit integers `x` and `y`, producing a 64-bit result. The 32 least-significant\n"
	"	bits are returned in `lsb`. The 32 most-significant bits are returned in `msb`."
);
static PyObject*
imulExtended_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2, * arg3 = NULL, * arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "imulExtended", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyLong_Check(arg1) && PyLong_Check(arg2)) {
			int msb, lsb;
			glm::imulExtended(_PyGLM_Long_As_Number_No_Error<int>(arg1), _PyGLM_Long_As_Number_No_Error<int>(arg2), msb, lsb);
			return Py_BuildValue("(i,i)", msb, lsb);
		}
	}
	else if (arg4 != NULL) {
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2) && Is_PyGLM_Object(arg3) && Is_PyGLM_Object(arg4)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);
			GET_PyGLM_ARG_TYPE(arg3);
			GET_PyGLM_ARG_TYPE(arg4);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);
			GET_PyGLM_ARG_SUBTYPE(arg3);
			GET_PyGLM_ARG_SUBTYPE(arg4);

			if (arg1Subtype == arg2Subtype && arg1Subtype == arg3Subtype && arg1Subtype == arg4Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L) \
					case PyGLMTypeObjectArrayOffsetVec<L, int32>(): \
						glm::imulExtended(PyGLM_VecOrMVec_Get(L, int32, arg1), PyGLM_VecOrMVec_Get(L, int32, arg2), PyGLM_VecOrMVec_Get(L, int32, arg3), PyGLM_VecOrMVec_Get(L, int32, arg4)); \
						Py_RETURN_NONE;

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_Undefined, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for imulExtended()");
	return NULL;
}

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
static PyObject*
bitfieldExtract_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "bitfieldExtract", arg1, arg2, arg3);
	if (PyLong_Check(arg2) && PyLong_Check(arg3)) {
		int i = (int)PyLong_AS_LONG(arg2), i2 = (int)PyLong_AS_LONG(arg3);
		if (PyGLM_Ctypes_Check(arg1)) {
			if (PyGLM_Ctypes_TypeCheck(arg1, int32)) {
				return pack(glm::bitfieldExtract(PyGLM_Ctypes_Get(arg1, int32), i, i2));
			}
			if (PyGLM_Ctypes_TypeCheck(arg1, uint32)) {
				return pack(glm::bitfieldExtract(PyGLM_Ctypes_Get(arg1, uint32), i, i2));
			}
			if (PyGLM_Ctypes_TypeCheck(arg1, int64)) {
				return pack(glm::bitfieldExtract(PyGLM_Ctypes_Get(arg1, int64), i, i2));
			}
			if (PyGLM_Ctypes_TypeCheck(arg1, uint64)) {
				return pack(glm::bitfieldExtract(PyGLM_Ctypes_Get(arg1, uint64), i, i2));
			}
		}
		if (PyLong_Check(arg1)) {

			PyGLM_WARN_TYPE(PyGLM_ARGUMENT_DEPRECATION_WARNING, PyExc_DeprecationWarning, "Using bitfieldExtract(int, [...]) is deprecated. Please use ctypes-integers with 32 or 64 bits instead (e.g. glm.int32)");

			int sign1 = PyLong_Sign(arg1);

			int overflow;

			if (sign1 == -1) {
				long l = PyLong_AsLongAndOverflow(arg1, &overflow);
				if (overflow) {
					return pack(glm::bitfieldExtract(_PyGLM_Long_As_Number_No_Error<long long>(arg1), i, i2));
				}
				return pack(glm::bitfieldExtract(l, i, i2));
			}

			unsigned long ul = PyLong_AsUnsignedLongAndOverflow(arg1, &overflow);
			if (overflow) {
				return pack(glm::bitfieldExtract(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg1), i, i2));
			}
			return pack(glm::bitfieldExtract(ul, i, i2));
		}
		switch (GET_PyGLMTypeObjectArrayOffsetOf(arg1)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::bitfieldExtract(PyGLM_Vec_Get(L, T, arg1), i, i2));

			PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsuIQSU, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::bitfieldExtract(PyGLM_Vec_Get(L, T, arg1), i, i2));

				PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_iI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldExtract()");
	return NULL;
}

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
static PyObject*
bitfieldInsert_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "bitfieldInsert", arg1, arg2, arg3, arg4);
	if (PyLong_Check(arg3) && PyLong_Check(arg4)) {
		int i = (int)PyLong_AS_LONG(arg3), i2 = (int)PyLong_AS_LONG(arg4);
		if (PyGLM_Ctypes_Check(arg1) && PyGLM_Ctypes_Check(arg2)) {
			if (PyGLM_Ctypes_TypeCheck(arg1, int32) && PyGLM_Ctypes_TypeCheck(arg2, int32)) {
				return pack(glm::bitfieldInsert(PyGLM_Ctypes_Get(arg1, int32), PyGLM_Ctypes_Get(arg2, int32), i, i2));
			}
			if (PyGLM_Ctypes_TypeCheck(arg1, uint32) && PyGLM_Ctypes_TypeCheck(arg2, uint32)) {
				return pack(glm::bitfieldInsert(PyGLM_Ctypes_Get(arg1, uint32), PyGLM_Ctypes_Get(arg2, uint32), i, i2));
			}
			if (PyGLM_Ctypes_TypeCheck(arg1, int64) && PyGLM_Ctypes_TypeCheck(arg2, int64)) {
				return pack(glm::bitfieldInsert(PyGLM_Ctypes_Get(arg1, int64), PyGLM_Ctypes_Get(arg2, int64), i, i2));
			}
			if (PyGLM_Ctypes_TypeCheck(arg1, uint64) && PyGLM_Ctypes_TypeCheck(arg2, uint64)) {
				return pack(glm::bitfieldInsert(PyGLM_Ctypes_Get(arg1, uint64), PyGLM_Ctypes_Get(arg2, uint64), i, i2));
			}
		}
		if (PyLong_Check(arg1) && PyLong_Check(arg2)) {

			PyGLM_WARN_TYPE(PyGLM_ARGUMENT_DEPRECATION_WARNING, PyExc_DeprecationWarning, "Using bitfieldInsert(int, int, [...]) is deprecated. Please use ctypes-integers with 32 or 64 bits instead (e.g. glm.int32)");

			int sign1 = PyLong_Sign(arg1);
			int sign2 = PyLong_Sign(arg2);

			int overflow1, overflow2;

			if (sign1 == -1 || sign2 == -1) {
				long l1 = PyLong_AsLongAndOverflow(arg1, &overflow1);
				long l2 = PyLong_AsLongAndOverflow(arg2, &overflow2);
				if (overflow1 || overflow2) {
					return pack(glm::bitfieldInsert(_PyGLM_Long_As_Number_No_Error<long long>(arg1), _PyGLM_Long_As_Number_No_Error<long long>(arg2), i, i2));
				}
				return pack(glm::bitfieldInsert(l1, l2, i, i2));
			}

			unsigned long ul1 = PyLong_AsUnsignedLongAndOverflow(arg1, &overflow1);
			unsigned long ul2 = PyLong_AsUnsignedLongAndOverflow(arg2, &overflow2);
			if (overflow1 || overflow2) {
				return pack(glm::bitfieldInsert(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg1), _PyGLM_Long_As_Number_No_Error<unsigned long long>(arg2), i, i2));
			}
			return pack(glm::bitfieldInsert(ul1, ul2, i, i2));
		}
		if (Is_PyGLM_Object(arg1) && Is_PyGLM_Object(arg2)) {
			GET_PyGLM_ARG_TYPE(arg1);
			GET_PyGLM_ARG_TYPE(arg2);

			GET_PyGLM_ARG_SUBTYPE(arg1);
			GET_PyGLM_ARG_SUBTYPE(arg2);

			if (arg1Subtype == arg2Subtype) {
				switch (GET_PyGLMTypeObjectArrayOffsetOfType(arg1Subtype)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::bitfieldInsert(PyGLM_VecOrMVec_Get(L, T, arg1), PyGLM_VecOrMVec_Get(L, T, arg2), i, i2));

					PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqIQ, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
				}
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldInsert()");
	return NULL;
}

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
static PyObject* bitfieldReverse_(PyObject*, PyObject* arg) {
	if (PyGLM_Ctypes_Check(arg)) {
		if (PyGLM_Ctypes_TypeCheck(arg, int32)) {
			return pack(glm::bitfieldReverse(PyGLM_Ctypes_Get(arg, int32)));
		}
		if (PyGLM_Ctypes_TypeCheck(arg, uint32)) {
			return pack(glm::bitfieldReverse(PyGLM_Ctypes_Get(arg, uint32)));
		}
		if (PyGLM_Ctypes_TypeCheck(arg, int64)) {
			return pack(glm::bitfieldReverse(PyGLM_Ctypes_Get(arg, int64)));
		}
		if (PyGLM_Ctypes_TypeCheck(arg, uint64)) {
			return pack(glm::bitfieldReverse(PyGLM_Ctypes_Get(arg, uint64)));
		}
	}
	if (PyLong_Check(arg)) {

		PyGLM_WARN_TYPE(PyGLM_ARGUMENT_DEPRECATION_WARNING, PyExc_DeprecationWarning, "Using bitfieldReverse(int) is deprecated. Please use ctypes-integers with 32 or 64 bits instead (e.g. glm.int32)");

		int sign1 = PyLong_Sign(arg);

		int overflow;

		if (sign1 == -1) {
			long l = PyLong_AsLongAndOverflow(arg, &overflow);
			if (overflow) {
				return pack(glm::bitfieldReverse(_PyGLM_Long_As_Number_No_Error<long long>(arg)));
			}
			return pack(glm::bitfieldReverse(l));
		}

		unsigned long ul = PyLong_AsUnsignedLongAndOverflow(arg, &overflow);
		if (overflow) {
			return pack(glm::bitfieldReverse(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg)));
		}
		return pack(glm::bitfieldReverse(ul));
	}
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::bitfieldReverse(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqIQ, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::bitfieldReverse(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_iI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitfieldReverse(): ", arg);
	return NULL;
}

PyDoc_STRVAR(bitCount_docstr,
	"bitCount(v: int) -> int\n"
	"	Returns the number of bits set to `1` in the binary representation of `value`.\n"
	"bitCount(v: vecN) -> ivecN\n"
	"	For every component `c` of `v`:\n"
	"	Returns the number of bits set to `1` in the binary representation of `c`."
);
static PyObject*
bitCount_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		int sign1 = PyLong_Sign(arg);

		int overflow;

		if (sign1 == -1) {
			long l = PyLong_AsLongAndOverflow(arg, &overflow);
			if (overflow) {
				return pack(glm::bitCount(_PyGLM_Long_As_Number_No_Error<long long>(arg)));
			}
			return pack(glm::bitCount(l));
		}

		unsigned long ul = PyLong_AsUnsignedLongAndOverflow(arg, &overflow);
		if (overflow) {
			return pack(glm::bitCount(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg)));
		}
		return pack(glm::bitCount(ul));
	}
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::bitCount(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsuIQSU, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::bitCount(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_iI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitCount(): ", arg);
	return NULL;
}

PyDoc_STRVAR(findLSB_docstr,
	"findLSB(value: int) -> int\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned.\n"
	"findLSB(value: vecN) -> ivecN\n"
	"	Returns the bit number of the least significant bit set to `1` in the binary representation\n"
	"	of `value`. If `value` is zero, `-1` will be returned."
);
static PyObject*
findLSB_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		int sign1 = PyLong_Sign(arg);

		int overflow;

		if (sign1 == -1) {
			long l = PyLong_AsLongAndOverflow(arg, &overflow);
			if (overflow) {
				return pack(glm::findLSB(_PyGLM_Long_As_Number_No_Error<long long>(arg)));
			}
			return pack(glm::findLSB(l));
		}

		unsigned long ul = PyLong_AsUnsignedLongAndOverflow(arg, &overflow);
		if (overflow) {
			return pack(glm::findLSB(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg)));
		}
		return pack(glm::findLSB(ul));
	}
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::findLSB(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsuIQSU, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::findLSB(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_iI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for findLSB(): ", arg);
	return NULL;
}

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
static PyObject*
findMSB_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		int sign1 = PyLong_Sign(arg);

		int overflow;

		if (sign1 == -1) {
			long l = PyLong_AsLongAndOverflow(arg, &overflow);
			if (overflow) {
				return pack(glm::findMSB(_PyGLM_Long_As_Number_No_Error<long long>(arg)));
			}
			return pack(glm::findMSB(l));
		}

		unsigned long ul = PyLong_AsUnsignedLongAndOverflow(arg, &overflow);
		if (overflow) {
			return pack(glm::findMSB(_PyGLM_Long_As_Number_No_Error<unsigned long long>(arg)));
		}
		return pack(glm::findMSB(ul));
	}
	switch (GET_PyGLMTypeObjectArrayOffsetOf(arg)) {
#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetVec<L, T>(): \
					return pack(glm::findMSB(PyGLM_Vec_Get(L, T, arg)));

		PyGLM_CODEGEN_PARAM_L_ALL(PyGLM_CODEGEN_PARAM_T_Vec_iqsuIQSU, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE

#define PyGLM_FUNC_TEMPLATE(L, T) \
				case PyGLMTypeObjectArrayOffsetMVec<L, T>(): \
					return pack(glm::findMSB(PyGLM_MVec_Get(L, T, arg)));

			PyGLM_CODEGEN_PARAM_L_MVEC(PyGLM_CODEGEN_PARAM_T_Vec_iI, PyGLM_FUNC_TEMPLATE)
#undef PyGLM_FUNC_TEMPLATE
	}
	PyGLM_TYPEERROR_O("invalid argument type for findMSB(): ", arg);
	return NULL;
}

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
