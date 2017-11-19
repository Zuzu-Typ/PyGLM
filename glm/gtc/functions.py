
from ..detail.setup import pyglmCompareType
from ..detail.type_vec2 import *
from ..detail.func_exponential import *

def gauss(a, ExpectedValue, StandardDeviation):
	if pyglmCompareType(a , tvec2):
		Squared = ((a - ExpectedValue) * (a - ExpectedValue)) / ((2.) * StandardDeviation * StandardDeviation)
		return exp(-(Squared.x + Squared.y))
	return exp(-((a - ExpectedValue) * (a - ExpectedValue)) / ((2.) * StandardDeviation * StandardDeviation)) / (StandardDeviation * sqrt((6.28318530717958647692528676655900576)))