from .setup import *

import ctypes

float32 = ctypes.c_float

float64 = ctypes.c_double

lowp_float = lowp_float_t = float32
mediump_float = mediump_float_t = float32
highp_float = highp_float_t = float64

####################
## check type sizes
if not defined("GLM_STATIC_ASSERT_NULL"):
    GLM_STATIC_ASSERT(ctypes.sizeof(float32) == 4, "float32 size isn't 4 bytes on this platform");
    GLM_STATIC_ASSERT(ctypes.sizeof(float64) == 8, "float64 size isn't 8 bytes on this platform");
