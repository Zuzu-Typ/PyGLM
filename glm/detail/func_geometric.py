from .func_exponential import *
from .func_common import *
from .type_vec2 import *
from .type_vec3 import *
from .type_vec4 import *

def compute_length(v):
    return sqrt(dot(v,v))

def compute_distance(p0, p1):
    return length(p1 - p0)

def compute_dot(x, y):
    if type(x) in (int, long, float, bool):
        return x + y
    if len(x) == 2:
        tmp = x * y
        return tmp.x + tmp.y
    
    if len(x) == 3:
        tmp = x * y
        return tmp.x + tmp.y + tmp.z

    if len(x) == 4:
        tmp = x * y
        return (tmp.x + tmp.y) + (tmp.z + tmp.w)

def compute_cross(x, y):
    return tvec3(x.y * y.z - y.y * x.z,
                 x.z * y.x - y.z * x.x,
                 x.x * y.y - y.x * x.y)

def compute_normalize(v):
    return v * inversesqrt(dot(v,v))

def compute_faceforward(N, I, Nref):
    return N if dot(Nref, I) < 0 else -N

def compute_reflect(I, N):
    return I - N * dot(N, I) * 2

def compute_refract(I, N, eta):
    dotValue = dot(N,I)
    k = 1. - eta * eta * (1. - dotValue * dotValue)
    return (eta * I - (eta * dotValue + math.sqrt(k)) * N) * int(k >= 0)

def length(x):
    if type(x) in (int, long, float, bool):
        return abs(x)

    return compute_length(x)

def distance(p0, p1):
    if type(p0) in (int, long, float, bool):
        return length(p1-p0)
    return compute_distance(p0,p1)

def dot(x,y):
    if type(x) in (int, long, float, bool):
        return x * y
    return compute_dot(x,y)

def cross(x,y):
    return compute_cross(x,y)

def normalize(x):
    if type(x) in (int, long, float, bool):
        return -1. if x < 0 else 1.
    return compute_normalize(x)

def faceforward(N, I, Nref):
    if type(N) in (int, long, float, bool):
        return N if dot(Nref, I) < 0 else -N
    return compute_faceforward(N, I, Nref)

def reflect(I, N):
    if type(N) in (int, long, float, bool):
        return I - N * dot(N,I) * 2.
    return compute_reflect(I,N)

def refract(I, N, eta):
    if type(I) in (int, long, float, bool):
        dotValue = dot(N,I)
        k = 1. - eta * eta * (1. - dotValue * dotValue)
        return (eta * I - (eta * dotValue + sqrt(k)) * N) * int(k >= 0)
    return compute_refract(I,N,eta)
    
