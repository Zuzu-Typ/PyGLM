from .func_vector_relational import *
from .func_geometric import dot
from .func_trigonometric import acos, sin
from ..gtc.constants import epsilon
from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4
from ._vectorize import *
from .setup import dtypes

import math

import numpy

##_round = round

##_abs = abs

##_max = max
##
##_min = min

##def round_(x):
##    return int(_round(x,0))
##
##def trunc_(x):
##    return -math.floor(-x) if x < 0 else math.floor(x)

##def compute_abs(x):
##    return x if x >= 0 else -x
##
##def compute_abs_vector(x):
##    return functor1(_abs, x)
##
def compute_mix_vector(x, y, a):
    if type(a[0]) == bool:
        Result = x.__class__()
        for i in range(len(x)):
            Result[i] = y[i] if a[i] else x[i]
        return Result
    return x.__class__(x + a * (y-x))

def compute_mix_scalar(x, y, a):
    if type(a) == bool:
        return y if a else x
    return x.__class__(x, a*(y-x))
##
def compute_mix(x,y,a):
    if type(a) == bool:
        return y if a else x
    return x.__class__(x + a * (y-x))
##
##def compute_sign(x):
##    return x.__class__(lessThan(0,x)) - x.__class__(lessThan(x,0))
##
##def compute_floor(x):
##    return functor1(math.floor, x)
##
##def compute_ceil(x):
##    return functor1(math.ceil, x)
##
##def compute_fract(x):
##    return x - compute_floor(x)
##
##def compute_trunc(x):
##    return functor1(trunc_, x)
##
##def compute_round(x):
##    return functor1(round_, x)
##
##def compute_mod(a, b):
##    return a - b * compute_floor(a / b)
##
##def compute_min_vector(x, y):
##    return functor2(_min, x, y)
##
##def compute_max_vector(x, y):
##    return functor2(_max, x, y)
##
##def compute_clamp_vector(x, minVal, maxVal):
##    return compute_min_vector(compute_max_vector(x, minVal), maxVal)
##
def compute_step_vector(edge, x):
    return mix(edge.__class__(1), edge.__class__(0), lessThan(x, edge))

def compute_smoothstep_vector(edge0, edge1, x):
    tmp = edge0.__class__(clamp((x - edge0) / (edge1 - edge0), 0., 1.))
    return tmp * tmp * (3. - 2. * tmp)

def abs(x):
    return x.__class__(numpy.absolute(x))
##    return compute_abs_vector(x)

def sign(x):
    return x.__class__(numpy.sign(x))

def floor(x):
    return x.__class__(numpy.floor(x))

def trunc(x):
    return x.__class__(numpy.trunc(x))

def round(x):
    return x.__class__(numpy.round(x))

def roundEven_(x):
    return float(int(x + float(int(x) % 2)))

def roundEven(x):
    return functor1(roundEven_, x)

def ceil(x):
    return x.__class__(numpy.ceil(x))

def fract(x):
    return x.__class__(x - floor(x))

def mod(x, y):
    return x.__class__(numpy.mod(x, y))

def min(a,b):
    return a.__class__(numpy.minimum(a,b))

def max(a,b):
    return a.__class__(numpy.maximum(a,b))

def clamp(x, minVal, maxVal):
    return x.__class__(numpy.clip(x, minVal, maxVal))

def mix(x, y, a):
    if type(x) in dtypes:
        return compute_mix(x,y,a)
    elif hasattr(x, "__tname__") and x.__tname__ == "tquat":
        tquat = x.__class__
        cosTheta = dot(x, y)

        # Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
        if(cosTheta > (1.) - epsilon()):
            # Linear interpolation
            return tquat(mix(x.w, y.w, a),
                mix(x.x, y.x, a),
                mix(x.y, y.y, a),
                mix(x.z, y.z, a))
        else:
            # Essential Mathematics, page 467
            angle = acos(cosTheta)
            return (sin(((1.) - a) * angle) * x + sin(a * angle) * y) / sin(angle)

    elif type(a) in dtypes:
        return compute_mix_scalar(x,y, a)
    else:
        return compute_mix_vector(x,y,a)

def step(edge, x):
    if type(edge) in dtypes:
        return mix(1., 0., lessThan(x,edge))
    return compute_step_vector(x.__class__(edge),x)

def smoothstep(edge0, edge1, x):
    compute_smoothstep_vector(x.__class__(edge0), x.__class__(edge1), x)

def isnan(x):
    return x.__class__(numpy.isnan(x))

def isinf(x):
    return x.__class__(numpy.isinf(x))

def fma(a,b,c):
    return a*b + c
