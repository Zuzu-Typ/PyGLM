#pragma once

#include "func_vector_relational.h"

PyDoc_STRVAR(equal_docstr,
	"equal(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x == y`.\n"
	"equal(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x == y`.\n"
	"equal(x: matNxM, y: matNxM) -> bvecN\n"
	"	Perform a component-wise equal-to comparison of two matrices. Return a boolean vector which\n"
	"	components value is `True` if this expression is satisfied per column of the matrices.\n"
	"equal(x: number, y: number, ULPs: int) -> bool\n"
	"	Returns the component-wise comparison between two scalars in term of `ULPs`.\n"
	"equal(x: vecN, y: vecN, ULPs: int) -> bvecN\n"
	"	Returns the component-wise comparison between two vectors in term of `ULPs`.\n"
	"equal(x: matNxM, y: matNxM, ULPs: int) -> bvecN\n"
	"	Returns the component-wise comparison between two matrices in term of `ULPs`.\n"
	"equal(x: vecN, y: vecN, ULPs: ivecN) -> bvecN\n"
	"	Returns the component-wise comparison between two vectors in term of `ULPs`.\n"
	"equal(x: matNxM, y: matNxM, ULPs: ivecN) -> bvecN\n"
	"	Returns the component-wise comparison between two matrices in term of `ULPs`.\n"
	"equal(x: number, y: number, epsilon: number) -> bool\n"
	"	Returns the comparison of `|x - y| < epsilon`.\n"
	"equal(x: vecN, y: vecN, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: quat, y: quat, epsilon: number) -> bvec4\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: matNxM, y: matNxM, epsilon: number) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: vecN, y: vecN, epsilon: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`.\n"
	"equal(x: matNxM, y: matNxM, epsilon: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of `|x - y| < epsilon`."
);

PyDoc_STRVAR(notEqual_docstr,
	"notEqual(*args) -> bvecN\n"
	"	Returns `not equal(*args)`."
);

PyDoc_STRVAR(lessThan_docstr,
	"lessThan(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x < y`.\n"
	"lessThan(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x < y`."
);

PyDoc_STRVAR(lessThanEqual_docstr,
	"lessThanEqual(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x <= y`.\n"
	"lessThanEqual(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x <= y`."
);

PyDoc_STRVAR(greaterThan_docstr,
	"greaterThan(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x > y`.\n"
	"greaterThan(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x > y`."
);

PyDoc_STRVAR(greaterThanEqual_docstr,
	"greaterThanEqual(x: vecN, y: vecN) -> bvecN\n"
	"	Returns the component-wise comparison of result `x >= y`.\n"
	"greaterThanEqual(x: quat, y: quat) -> bvec4\n"
	"	Returns the component-wise comparison of result `x >= y`."
);

PyDoc_STRVAR(any_docstr,
	"any(v: bvecN) -> bool\n"
	"	Returns `True` if any component of `x` is `True`."
);

PyDoc_STRVAR(all_docstr,
	"all(v: bvecN) -> bool\n"
	"	Returns `True` if all components of `x` are `True`."
);

PyDoc_STRVAR(not_docstr,
	"not_(v: bvecN) -> bool\n"
	"	Returns the component-wise logical complement of `x`."
);

#define FUNC_VECTOR_RELATIONAL_METHODS \
{ "equal", (PyCFunction)equal, METH_VARARGS, equal_docstr }, \
{ "notEqual", (PyCFunction)notEqual, METH_VARARGS, notEqual_docstr }, \
{ "lessThan", (PyCFunction)lessThan_, METH_VARARGS, lessThan_docstr }, \
{ "lessThanEqual", (PyCFunction)lessThanEqual_, METH_VARARGS, lessThanEqual_docstr }, \
{ "greaterThan", (PyCFunction)greaterThan_, METH_VARARGS, greaterThan_docstr }, \
{ "greaterThanEqual", (PyCFunction)greaterThanEqual_, METH_VARARGS, greaterThanEqual_docstr }, \
{ "any", (PyCFunction)any, METH_O, any_docstr }, \
{ "all", (PyCFunction)all, METH_O, all_docstr }, \
{ "not_", (PyCFunction)not_, METH_O, not_docstr }
