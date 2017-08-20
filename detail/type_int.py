import ctypes

from .setup import *

int8 = ctypes.c_int8
int16 = ctypes.c_int16
int32 = ctypes.c_int32
int64 = ctypes.c_int64

uint8 = ctypes.c_uint8
uint16 = ctypes.c_uint16
uint32 = ctypes.c_uint32
uint64 = ctypes.c_uint64

lowp_int = lowp_int_t = ctypes.c_int
mediump_int = mediump_int_t = ctypes.c_int
highp_int = highp_int_t = ctypes.c_int

lowp_uint = lowp_uint_t = ctypes.c_uint
mediump_uint = mediump_uint_t = ctypes.c_uint
highp_uint = highp_uint_t = ctypes.c_uint

####################
## check type sizes
if not defined("GLM_STATIC_ASSERT_NULL"):
    GLM_STATIC_ASSERT(ctypes.sizeof(int8) == 1, "int8 size isn't 1 byte on this platform")
    GLM_STATIC_ASSERT(ctypes.sizeof(int16) == 2, "int16 size isn't 2 bytes on this platform")
    GLM_STATIC_ASSERT(ctypes.sizeof(int32) == 4, "int32 size isn't 4 bytes on this platform")
    GLM_STATIC_ASSERT(ctypes.sizeof(int64) == 8, "int64 size isn't 8 bytes on this platform")

    GLM_STATIC_ASSERT(ctypes.sizeof(uint8) == 1, "uint8 size isn't 1 byte on this platform")
    GLM_STATIC_ASSERT(ctypes.sizeof(uint16) == 2, "uint16 size isn't 2 bytes on this platform")
    GLM_STATIC_ASSERT(ctypes.sizeof(uint32) == 4, "uint32 size isn't 4 bytes on this platform")
    GLM_STATIC_ASSERT(ctypes.sizeof(uint64) == 8, "uint64 size isn't 8 bytes on this platform")
