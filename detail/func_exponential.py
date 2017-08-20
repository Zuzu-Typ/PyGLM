from .func_vector_relational import *
from ._vectorize import *
from .setup import *

import math



def compute_sqrt(vec):
    return functor1(math.sqrt, vec)

def compute_inversesqrt(vec):
    return 1. / sqrt(vec)

def exp(vec):
    return functor1(math.exp, vec)

def log(vec):
    return functor1(math.log, vec)

def exp2(x):
    if type(x) in (float, int, long, bool):
        return math.exp(0.69314718055994530941723212145818*x)
    else:
        return functor1(exp2, x)

def log2(x):
    if type(x) in (float, int, long, bool):
        return math.log(x) * 1.4426950408889634073599246810019
    else:
        return functor1(log2, x)

def compute_log2(vec):
    return functor1(log2, vec)

def sqrt(x):
    if type(x) in (int, long, float, bool):
        return math.sqrt(x)
    return compute_sqrt(x)
        
inversesqrt = compute_inversesqrt
    
