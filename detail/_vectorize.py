from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4

def functor1(Func, v):
    if isinstance(v, tvec2):
        return tvec2(Func(v.x),
                     Func(v.y))

    elif isinstance(v, tvec3):
        return tvec3(Func(v.x),
                     Func(v.y),
                     Func(v.z))

    elif isinstance(v, tvec4):
        return tvec4(Func(v.x),
                     Func(v.y),
                     Func(v.z),
                     Func(v.w))

def functor2(Func, v):
    if isinstance(v, tvec2):
        return tvec2(Func(v.x, v.x),
                     Func(v.y, v.y))

    elif isinstance(v, tvec3):
        return tvec3(Func(v.x, v.x),
                     Func(v.y, v.y),
                     Func(v.z, v.z))

    elif isinstance(v, tvec4):
        return tvec4(Func(v.x, v.x),
                     Func(v.y, v.y),
                     Func(v.z, v.z),
                     Func(v.w, v.w))

def functor2_vec_sca(Func, a, b):
    if isinstance(a, tvec2):
        return tvec2(Func(a.x, b),
                     Func(a.y, b))

    elif isinstance(a, tvec3):
        return tvec3(Func(a.x, b),
                     Func(a.y, b),
                     Func(a.z, b))

    elif isinstance(a, tvec4):
        return tvec4(Func(a.x, b),
                     Func(a.y, b),
                     Func(a.z, b),
                     Func(a.w, b))
