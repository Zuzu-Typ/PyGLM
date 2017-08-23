from .setup import *
from ._vectorize import *
import math

def radians(degrees):
    return degrees * (0.01745329251994329576923690768489)

def degrees(radians):
    return radians * (57.295779513082320876798154814105)

def sin(v):
    return functor1(math.sin, v)

def cos(v):
    return functor1(math.cos, v)

def tan(v):
    return functor1(math.tan, v)

def asin(v):
    return functor1(math.asin, v)

def acos(v):
    return functor1(math.acos, v)

def atan(*args):
    if len(args) == 2:
        a,b = args
        if type(a) in (int, long, float, bool):
            return math.atan2(a, b)
        return functor2(math.atan2, a, b)
    else:
        return functor1(math.tan,args[0])

def sinh(v):
    return functor1(math.sinh, v)

def cosh(v):
    return functor1(math.cosh, v)

def tanh(v):
    return functor1(math.tanh, v)

def asinh(v):
    return functor1(math.asinh, v)

def acosh(v):
    return functor1(math.acosh, v)

def atanh(v):
    return functor1(math.atanh, v)

