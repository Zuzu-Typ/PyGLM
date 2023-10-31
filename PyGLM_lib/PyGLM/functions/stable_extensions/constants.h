#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC__rF(epsilon)
PyGLM_MAKE_GLM_FUNC__rF(zero)
PyGLM_MAKE_GLM_FUNC__rF(one)
PyGLM_MAKE_GLM_FUNC__rF(pi)
PyGLM_MAKE_GLM_FUNC__rF(two_pi)
PyGLM_MAKE_GLM_FUNC__rF(root_pi)
PyGLM_MAKE_GLM_FUNC__rF(half_pi)
PyGLM_MAKE_GLM_FUNC__rF(three_over_two_pi)
PyGLM_MAKE_GLM_FUNC__rF(quarter_pi)
PyGLM_MAKE_GLM_FUNC__rF(one_over_pi)
PyGLM_MAKE_GLM_FUNC__rF(one_over_two_pi)
PyGLM_MAKE_GLM_FUNC__rF(two_over_pi)
PyGLM_MAKE_GLM_FUNC__rF(four_over_pi)
PyGLM_MAKE_GLM_FUNC__rF(two_over_root_pi)
PyGLM_MAKE_GLM_FUNC__rF(one_over_root_two)
PyGLM_MAKE_GLM_FUNC__rF(root_half_pi)
PyGLM_MAKE_GLM_FUNC__rF(root_two_pi)
PyGLM_MAKE_GLM_FUNC__rF(root_ln_four)
PyGLM_MAKE_GLM_FUNC__rF(e)
PyGLM_MAKE_GLM_FUNC__rF(euler)
PyGLM_MAKE_GLM_FUNC__rF(root_two)
PyGLM_MAKE_GLM_FUNC__rF(root_three)
PyGLM_MAKE_GLM_FUNC__rF(root_five)
PyGLM_MAKE_GLM_FUNC__rF(ln_two)
PyGLM_MAKE_GLM_FUNC__rF(ln_ten)
PyGLM_MAKE_GLM_FUNC__rF(ln_ln_two)
PyGLM_MAKE_GLM_FUNC__rF(third)
PyGLM_MAKE_GLM_FUNC__rF(two_thirds)
PyGLM_MAKE_GLM_FUNC__rF(golden_ratio)

PyDoc_STRVAR(epsilon_docstr,
	"epsilon() -> float\n"
	"	Return the `epsilon` constant for floating point types."
);
PyDoc_STRVAR(pi_docstr,
	"pi() -> float\n"
	"	Return the `pi` constant for floating point types."
);
PyDoc_STRVAR(e_docstr,
	"e() -> float\n"
	"	Return `e` constant."
);
PyDoc_STRVAR(euler_docstr,
	"euler() -> float\n"
	"	Return Euler's constant."
);
PyDoc_STRVAR(four_over_pi_docstr,
	"four_over_pi() -> float\n"
	"	Return `4 / pi`."
);
PyDoc_STRVAR(golden_ratio_docstr,
	"golden_ratio() -> float\n"
	"	Return the golden ratio constant."
);
PyDoc_STRVAR(half_pi_docstr,
	"half_pi() -> float\n"
	"	Return `pi / 2`."
);
PyDoc_STRVAR(ln_ln_two_docstr,
	"ln_ln_two() -> float\n"
	"	Return `ln(ln(2))`."
);
PyDoc_STRVAR(ln_ten_docstr,
	"ln_ten() -> float\n"
	"	Return `ln(10)`."
);
PyDoc_STRVAR(ln_two_docstr,
	"ln_two() -> float\n"
	"	Return `ln(2)`."
);
PyDoc_STRVAR(one_docstr,
	"one() -> float\n"
	"	Return `1`."
);
PyDoc_STRVAR(one_over_pi_docstr,
	"one_over_pi() -> float\n"
	"	Return `1 / pi`."
);
PyDoc_STRVAR(one_over_root_two_docstr,
	"one_over_root_two() -> float\n"
	"	Return `1 / sqrt(2)`."
);
PyDoc_STRVAR(one_over_two_pi_docstr,
	"one_over_two_pi() -> float\n"
	"	Return `1 / (pi * 2)`."
);
PyDoc_STRVAR(quarter_pi_docstr,
	"quarter_pi() -> float\n"
	"	Return `pi / 4`."
);
PyDoc_STRVAR(root_five_docstr,
	"root_five() -> float\n"
	"	Return `sqrt(5)`."
);
PyDoc_STRVAR(root_half_pi_docstr,
	"root_half_pi() -> float\n"
	"	Return `sqrt(pi / 2)`."
);
PyDoc_STRVAR(root_ln_four_docstr,
	"root_ln_four() -> float\n"
	"	Return `sqrt(ln(4))`."
);
PyDoc_STRVAR(root_pi_docstr,
	"root_pi() -> float\n"
	"	Return square root of `pi`."
);
PyDoc_STRVAR(root_three_docstr,
	"root_three() -> float\n"
	"	Return `sqrt(3)`."
);
PyDoc_STRVAR(root_two_docstr,
	"root_two() -> float\n"
	"	Return `sqrt(2)`."
);
PyDoc_STRVAR(root_two_pi_docstr,
	"root_two_pi() -> float\n"
	"	Return `sqrt(2 * pi)`."
);
PyDoc_STRVAR(third_docstr,
	"third() -> float\n"
	"	Return `1 / 3`."
);
PyDoc_STRVAR(three_over_two_pi_docstr,
	"three_over_two_pi() -> float\n"
	"	Return `pi / 2 * 3`."
);
PyDoc_STRVAR(two_over_pi_docstr,
	"two_over_pi() -> float\n"
	"	Return `2 / pi`."
);
PyDoc_STRVAR(two_over_root_pi_docstr,
	"two_over_root_pi() -> float\n"
	"	Return `2 / sqrt(pi)`."
);
PyDoc_STRVAR(two_pi_docstr,
	"two_pi() -> float\n"
	"	Return `pi * 2`."
);
PyDoc_STRVAR(two_thirds_docstr,
	"two_thirds() -> float\n"
	"	Return `2 / 3`."
);
PyDoc_STRVAR(zero_docstr,
	"zero() -> float\n"
	"	Return `0`."
);

#define CONSTANTS_METHODS \
{ "epsilon", (PyCFunction)epsilon_, METH_NOARGS, epsilon_docstr }, \
{ "zero", (PyCFunction)zero_, METH_NOARGS, zero_docstr }, \
{ "one", (PyCFunction)one_, METH_NOARGS, one_docstr }, \
{ "pi", (PyCFunction)pi_, METH_NOARGS, pi_docstr }, \
{ "two_pi", (PyCFunction)two_pi_, METH_NOARGS, two_pi_docstr }, \
{ "root_pi", (PyCFunction)root_pi_, METH_NOARGS, root_pi_docstr }, \
{ "half_pi", (PyCFunction)half_pi_, METH_NOARGS, half_pi_docstr }, \
{ "three_over_two_pi", (PyCFunction)three_over_two_pi_, METH_NOARGS, three_over_two_pi_docstr }, \
{ "quarter_pi", (PyCFunction)quarter_pi_, METH_NOARGS, quarter_pi_docstr }, \
{ "one_over_pi", (PyCFunction)one_over_pi_, METH_NOARGS, one_over_pi_docstr }, \
{ "one_over_two_pi", (PyCFunction)one_over_two_pi_, METH_NOARGS, one_over_two_pi_docstr }, \
{ "two_over_pi", (PyCFunction)two_over_pi_, METH_NOARGS, two_over_pi_docstr }, \
{ "four_over_pi", (PyCFunction)four_over_pi_, METH_NOARGS, four_over_pi_docstr }, \
{ "two_over_root_pi", (PyCFunction)two_over_root_pi_, METH_NOARGS, two_over_root_pi_docstr }, \
{ "one_over_root_two", (PyCFunction)one_over_root_two_, METH_NOARGS, one_over_root_two_docstr }, \
{ "root_half_pi", (PyCFunction)root_half_pi_, METH_NOARGS, root_half_pi_docstr }, \
{ "root_two_pi", (PyCFunction)root_two_pi_, METH_NOARGS, root_two_pi_docstr }, \
{ "root_ln_four", (PyCFunction)root_ln_four_, METH_NOARGS, root_ln_four_docstr }, \
{ "e", (PyCFunction)e_, METH_NOARGS, e_docstr }, \
{ "euler", (PyCFunction)euler_, METH_NOARGS, euler_docstr }, \
{ "root_two", (PyCFunction)root_two_, METH_NOARGS, root_two_docstr }, \
{ "root_three", (PyCFunction)root_three_, METH_NOARGS, root_three_docstr }, \
{ "root_five", (PyCFunction)root_five_, METH_NOARGS, root_five_docstr }, \
{ "ln_two", (PyCFunction)ln_two_, METH_NOARGS, ln_two_docstr }, \
{ "ln_ten", (PyCFunction)ln_ten_, METH_NOARGS, ln_ten_docstr }, \
{ "ln_ln_two", (PyCFunction)ln_ln_two_, METH_NOARGS, ln_ln_two_docstr }, \
{ "third", (PyCFunction)third_, METH_NOARGS, third_docstr }, \
{ "two_thirds", (PyCFunction)two_thirds_, METH_NOARGS, two_thirds_docstr }, \
{ "golden_ratio", (PyCFunction)golden_ratio_, METH_NOARGS, golden_ratio_docstr }
