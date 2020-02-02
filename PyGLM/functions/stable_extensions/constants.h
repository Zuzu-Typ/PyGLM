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

#define CONSTANTS_METHODS { "epsilon", (PyCFunction)epsilon_, METH_NOARGS, "epsilon() -> float\nReturn the epsilon constant for floating point types." }, \
{ "zero", (PyCFunction)zero_, METH_NOARGS, "zero() -> float\nReturn 0." }, \
{ "one", (PyCFunction)one_, METH_NOARGS, "one() -> float\nReturn 1." }, \
{ "pi", (PyCFunction)pi_, METH_NOARGS, "pi() -> float\nReturn the pi constant." }, \
{ "two_pi", (PyCFunction)two_pi_, METH_NOARGS, "two_pi() -> float\nReturn pi * 2." }, \
{ "root_pi", (PyCFunction)root_pi_, METH_NOARGS, "root_pi() -> float\nReturn square root of pi." }, \
{ "half_pi", (PyCFunction)half_pi_, METH_NOARGS, "half_pi() -> float\nReturn pi / 2." }, \
{ "three_over_two_pi", (PyCFunction)three_over_two_pi_, METH_NOARGS, "three_over_two_pi() -> float\nReturn pi / 2 * 3." }, \
{ "quarter_pi", (PyCFunction)quarter_pi_, METH_NOARGS, "quarter_pi() -> float\nReturn pi / 4." }, \
{ "one_over_pi", (PyCFunction)one_over_pi_, METH_NOARGS, "one_over_pi() -> float\nReturn 1 / pi." }, \
{ "one_over_two_pi", (PyCFunction)one_over_two_pi_, METH_NOARGS, "one_over_two_pi() -> float\nReturn 1 / (pi * 2)." }, \
{ "two_over_pi", (PyCFunction)two_over_pi_, METH_NOARGS, "two_over_pi() -> float\nReturn 2 / pi." }, \
{ "four_over_pi", (PyCFunction)four_over_pi_, METH_NOARGS, "four_over_pi() -> float\nReturn 4 / pi." }, \
{ "two_over_root_pi", (PyCFunction)two_over_root_pi_, METH_NOARGS, "two_over_root_pi() -> float\nReturn 2 / sqrt(pi)." }, \
{ "one_over_root_two", (PyCFunction)one_over_root_two_, METH_NOARGS, "one_over_root_two() -> float\nReturn 1 / sqrt(2)." }, \
{ "root_half_pi", (PyCFunction)root_half_pi_, METH_NOARGS, "root_half_pi() -> float\nReturn sqrt(pi / 2)." }, \
{ "root_two_pi", (PyCFunction)root_two_pi_, METH_NOARGS, "root_two_pi() -> float\nReturn sqrt(2 * pi)." }, \
{ "root_ln_four", (PyCFunction)root_ln_four_, METH_NOARGS, "root_ln_four() -> float\nReturn sqrt(ln(4))." }, \
{ "e", (PyCFunction)e_, METH_NOARGS, "e() -> float\nReturn e constant." }, \
{ "euler", (PyCFunction)euler_, METH_NOARGS, "euler() -> float\nReturn Euler's constant." }, \
{ "root_two", (PyCFunction)root_two_, METH_NOARGS, "root_two() -> float\nReturn sqrt(2)." }, \
{ "root_three", (PyCFunction)root_three_, METH_NOARGS, "root_three() -> float\nReturn sqrt(3)." }, \
{ "root_five", (PyCFunction)root_five_, METH_NOARGS, "root_five() -> float\nReturn sqrt(5)." }, \
{ "ln_two", (PyCFunction)ln_two_, METH_NOARGS, "ln_two() -> float\nReturn ln(2)." }, \
{ "ln_ten", (PyCFunction)ln_ten_, METH_NOARGS, "ln_ten() -> float\nReturn ln(10)." }, \
{ "ln_ln_two", (PyCFunction)ln_ln_two_, METH_NOARGS, "ln_ln_two() -> float\nReturn ln(ln(2))." }, \
{ "third", (PyCFunction)third_, METH_NOARGS, "third() -> float\nReturn 1 / 3." }, \
{ "two_thirds", (PyCFunction)two_thirds_, METH_NOARGS, "two_thirds() -> float\nReturn 2 / 3." }, \
{ "golden_ratio", (PyCFunction)golden_ratio_, METH_NOARGS, "golden_ratio() -> float\nReturn the golden ratio constant." }
