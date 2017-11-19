
from ..detail.setup import dtypes
from ..detail.func_trigonometric import *
from ..detail._vectorize import functor1
import math

def sec(angle):
	if type(angle) in dtypes:
		return 1. / math.cos(angle)

	return functor1(sec, angle)

def csc(angle):
	if type(angle) in dtypes:
		return 1. / math.sin(angle)

	return functor1(csc, angle)

def cot(angle):
	if type(angle) in dtypes:
		pi_over_2 = (3.1415926535897932384626433832795 / 2.0)
		return math.tan(pi_over_2 - angle)

	return functor1(cot, angle)

def asec(x):
	if type(x) in dtypes:
		return math.acos(1. / x)

	return functor1(asec, x)

def acsc(x):
	if type(x) in dtypes:
		return math.asin(1. / x)

	return functor1(acsc, x)

def acot(x):
	if type(x) in dtypes:
		pi_over_2 = (3.1415926535897932384626433832795 / 2.0)
		return pi_over_2 - math.atan(x)

	return functor1(acot, x)

def sech(angle):
	if type(angle) in dtypes:
		return 1. / math.cosh(angle)

	return functor1(sech, angle)

def csch(angle):
	if type(angle) in dtypes:
		return 1. / math.sinh(angle)

	return functor1(csch, angle)

def coth(angle):
	if type(angle) in dtypes:
		return math.cosh(angle) / math.sinh(angle)

	return functor1(coth, angle)

def asech(x):
	if type(x) in dtypes:
		return math.acosh(1. / x)

	return functor1(asech, x)

def acsch(x):
	if type(x) in dtypes:
		return math.asinh(1. / x)

	return functor1(acsch, x)

def acoth(x):
	if type(x) in dtypes:
		return math.atanh(1. / x)

	return functor1(acoth, x)