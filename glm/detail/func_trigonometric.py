from .setup import *
from ._vectorize import *
import math
import numpy

radians = math.radians
degrees = math.degrees

def sin(v):
    return v.__class__(numpy.sin(v))

def cos(v):
    return v.__class__(numpy.cos(v))

def tan(v):
    return v.__class__(numpy.tan(v))

def asin(v):
    return v.__class__(numpy.arcsin(v))

def acos(v):
    return v.__class__(numpy.arccos(v))

def atan(*args):
    if len(args) == 2:
        return args[0].__class__(numpy.arctan2(*args))
    else:
        return args[0].__class__(numpy.arctan(*args))

def sinh(v):
    return v.__class__(numpy.sinh(v))

def cosh(v):
    return v.__class__(numpy.cosh(v))

def tanh(v):
    return v.__class__(numpy.tanh(v))

def asinh(v):
    return v.__class__(numpy.arcsinh(v))

def acosh(v):
    return v.__class__(numpy.arcosh(v))

def atanh(v):
    return v.__class__(numpy.arctanh(v))

