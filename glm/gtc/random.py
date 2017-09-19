from ..detail.type_vec2 import tvec2
from ..detail.type_vec3 import tvec3
from ..detail.func_geometric import *
from ..detail.func_exponential import *
from ..detail.setup import *

import random, sys

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_EXT_INCLUDED"):
    message("GLM: GLM_GTC_random extension included")

def compute_rand():
    return tvec4(random.random()*sys.maxsize,
                 random.random()*sys.maxsize,
                 random.random()*sys.maxsize,
                 random.random()*sys.maxsize)

def compute_linearRand(Min, Max):
    vecType = Min.__class__
    return (vecType(compute_rand()) % vecType(Max + 1 - Min)) + Min

linearRand = compute_linearRand

def gaussRand(Mean, Deviation):
    if type(Mean) in dtypes:
        x1 = linearRang(-1, 1)
        x2 = linearRand(-1, 1)

        w = x1 * x1 + x2 * x2
        while w > 1:
            x1 = linearRang(-1, 1)
            x2 = linearRand(-1, 1)

            w = x1 * x1 + x2 * x2

        return x2 * Deviation * Deviation * sqrt((-2. * log(w)) / w) + Mean
    return functor2(gaussRand, Mean, Deviation)

def diskRand(Radius):
    Result = tvec2((0))
    LenRadius = ((0))
    
    Result = linearRand(tvec2(-Radius),
            tvec2(Radius))
    LenRadius = length(Result)
    
    while(LenRadius > Radius):
        Result = linearRand(tvec2(-Radius),
            tvec2(Radius))
        LenRadius = length(Result)
    
    return Result

def ballRand(Radius):
    Result = tvec3((0))
    LenRadius = ((0))
    
    Result = linearRand(tvec3(-Radius),
            tvec3(Radius))
    LenRadius = length(Result)
    
    while(LenRadius > Radius):
        Result = linearRand(tvec3(-Radius),
            tvec3(Radius))
        LenRadius = length(Result)
    
    return Result

def circularRand(Radius):
    a = linearRand((0), (6.283185307179586476925286766559))
    return tvec2(cos(a), sin(a)) * Radius

def sphericalRand(Radius):
    z = linearRand((-1), (1))
    a = linearRand((0), (6.283185307179586476925286766559))

    r = sqrt((1) - z * z)

    x = r * cos(a)
    y = r * sin(a)

    return tvec3(x, y, z) * Radius

