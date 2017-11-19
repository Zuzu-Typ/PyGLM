from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4
from .setup import pyglmCompareType

def functor1(Func, v):
	if pyglmCompareType(v, tvec2):
		return tvec2(Func(v.x),
					 Func(v.y))

	elif pyglmCompareType(v, tvec3):
		return tvec3(Func(v.x),
					 Func(v.y),
					 Func(v.z))

	elif pyglmCompareType(v, tvec4):
		return tvec4(Func(v.x),
					 Func(v.y),
					 Func(v.z),
					 Func(v.w))
	else:
		return Func(v)

def functor2(Func, a,b):
	if pyglmCompareType(a, tvec2):
		return tvec2(Func(a.x, b.x),
					 Func(a.y, b.y))

	elif pyglmCompareType(a, tvec3):
		return tvec3(Func(a.x, b.x),
					 Func(a.y, b.y),
					 Func(a.z, b.z))

	elif pyglmCompareType(a, tvec4):
		return tvec4(Func(a.x, b.x),
					 Func(a.y, b.y),
					 Func(a.z, b.z),
					 Func(a.w, b.w))

def functor2_vec_sca(Func, a, b):
	if pyglmCompareType(a, tvec2):
		return tvec2(Func(a.x, b),
					 Func(a.y, b))

	elif pyglmCompareType(a, tvec3):
		return tvec3(Func(a.x, b),
					 Func(a.y, b),
					 Func(a.z, b))

	elif pyglmCompareType(a, tvec4):
		return tvec4(Func(a.x, b),
					 Func(a.y, b),
					 Func(a.z, b),
					 Func(a.w, b))
