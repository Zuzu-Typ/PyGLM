
from ..detail.setup import pyglmCompareType
from .quaternion import *
from ..detail.func_vector_relational import *
from ..detail.func_common import *
from ..detail.type_vec2 import *
from ..detail.type_vec3 import *
from ..detail.type_vec4 import *

def epsilonEqual(x,y,epsilon):
	if pyglmCompareType(x , tquat):
		v = tvec4(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w)
		return lessThan(abs(v), tvec4(epsilon))
	elif pyglmCompareType(x, tvec2) or pyglmCompareType(x, tvec3) or pyglmCompareType(x, tvec4):
		return lessThan(abs(x - y ), x.__class__(epsilon))
	return abs(x - y) < epsilon

def epsilonNotEqual(x, y, epsilon):
	if pyglmCompareType(x , tquat):
		v = tvec4(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w)
		return greaterThanEqual(abs(v), tvec4(epsilon))
	elif pyglmCompareType(x, tvec2) or pyglmCompareType(x, tvec3) or pyglmCompareType(x, tvec4):
		return greaterThanEqual(abs(x - y ), x.__class__(epsilon))
	return abs(x - y ) >= epsilon