import sys

import ctypes

from ..prep import *

from ..datatypes import *

GLM_FORCE_SWIZZLE = True

class PyGLMError(Exception):
    pass

class PyGLMWarning(Warning):
    pass

def defined(name):
    pyglm_globals = globals()
    return name in pyglm_globals

def error(msg):
    PyGLMError(msg)

def message(msg):
    print(msg)

if (defined("GLM_FORCE_SWIZZLE") or defined("GLM_SWIZZLE")) and defined("GLM_FORCE_UNRESTRICTED_GENTYPE"):
    error("Both GLM_FORCE_SWIZZLE and GLM_FORCE_UNRESTRICTED_GENTYPE can't be defined at the same time")

##########################################
# Messages

if defined("GLM_MESSAGES"):
    message("GLM: GLM_MESSAGES is deprecated, use GLM_FORCE_MESSAGES instead")

GLM_MESSAGES_ENABLED = 1
GLM_MESSAGES_DISABLE = 0

if defined("GLM_FORCE_MESSAGES") or defined("GLM_MESSAGES"):
    GLM_MESSAGES = GLM_MESSAGES_ENABLED
else:
    GLM_MESSAGES = GLM_MESSAGES_DISABLE
    
#include <cassert>
#include <cstddef>
#include "../simd/platform.h"
from ..simd.platform import *

##########################################
# Version

GLM_VERSION                 = 98
GLM_VERSION_MAJOR           = 0
GLM_VERSION_MINOR           = 9
GLM_VERSION_PATCH           = 8
GLM_VERSION_REVISION        = 4

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_VERSION_DISPLAYED"):
    GLM_MESSAGE_VERSION_DISPLAYED = True
    message("GLM: version 0.9.8.4")

GLM_MODEL = GLM_MODEL_64 if sys.maxsize > 2**32 else GLM_MODEL_32

##########################################
# Build model

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_MODEL_DISPLAYED"):
    GLM_MESSAGE_MODEL_DISPLAYED = True
    if(GLM_MODEL == GLM_MODEL_64):
        message("GLM: 64 bits model")
    elif(GLM_MODEL == GLM_MODEL_32):
        message("GLM: 32 bits model")
        
if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_ARCH_DISPLAYED"):
    GLM_MESSAGE_ARCH_DISPLAYED = True
    message("GLM: Platform independent code")
    
##########################################
# Static assert
def static_assert(x, message):
    assert x, message
    
GLM_HAS_STATIC_ASSERT = True
GLM_STATIC_ASSERT = static_assert

##########################################
# Swizzle operators

# User defines: GLM_FORCE_SWIZZLE

if defined("GLM_SWIZZLE"):
    message("GLM: GLM_SWIZZLE is deprecated, use GLM_FORCE_SWIZZLE instead")

GLM_SWIZZLE_ENABLED = 1
GLM_SWIZZLE_DISABLE = 0

if defined("GLM_FORCE_SWIZZLE") or defined("GLM_SWIZZLE"):
    GLM_SWIZZLE = GLM_SWIZZLE_ENABLED
else:
    GLM_SWIZZLE = GLM_SWIZZLE_DISABLE

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_SWIZZLE_DISPLAYED"):
    GLM_MESSAGE_SWIZZLE_DISPLAYED = True
    if GLM_SWIZZLE == GLM_SWIZZLE_ENABLED:
        message("GLM: Swizzling operators enabled")
    else:
        message("GLM: Swizzling operators disabled, define GLM_SWIZZLE to enable swizzle operators")

##########################################
# Clip control

if defined("GLM_DEPTH_ZERO_TO_ONE"): # Legacy 0.9.8 development
    error("Define GLM_FORCE_DEPTH_ZERO_TO_ONE instead of GLM_DEPTH_ZERO_TO_ONE to use 0 to 1 clip space.")
    
GLM_DEPTH_ZERO_TO_ONE               = 0x00000001
GLM_DEPTH_NEGATIVE_ONE_TO_ONE       = 0x00000002

if defined("GLM_FORCE_DEPTH_ZERO_TO_ONE"):
    GLM_DEPTH_CLIP_SPACE = GLM_DEPTH_ZERO_TO_ONE
else:
    GLM_DEPTH_CLIP_SPACE = GLM_DEPTH_NEGATIVE_ONE_TO_ONE

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_DEPTH_DISPLAYED"):
    GLM_MESSAGE_DEPTH_DISPLAYED = True
    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        message("GLM: Depth clip space: Zero to one")
    else:
        message("GLM: Depth clip space: negative one to one")

##########################################
# Coordinate system, define GLM_FORCE_LEFT_HANDED before including GLM
# to use left handed coordinate system by default.

if defined("GLM_LEFT_HANDED"): # Legacy 0.9.8 development
    error("Define GLM_FORCE_LEFT_HANDED instead of GLM_LEFT_HANDED left handed coordinate system by default.")
#endif

GLM_LEFT_HANDED             = 0x00000001    # For DirectX, Metal, Vulkan
GLM_RIGHT_HANDED            = 0x00000002    # For OpenGL, default in GLM

if defined("GLM_FORCE_LEFT_HANDED"):
    GLM_COORDINATE_SYSTEM = GLM_LEFT_HANDED
else:
    GLM_COORDINATE_SYSTEM = GLM_RIGHT_HANDED
#endif

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_HANDED_DISPLAYED"):
    GLM_MESSAGE_HANDED_DISPLAYED = True
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        message("GLM: Coordinate system: left handed")
    else:
        message("GLM: Coordinate system: right handed")

##########################################
# Length type

# User defines: GLM_FORCE_SIZE_T_LENGTH GLM_FORCE_SIZE_FUNC
if defined("GLM_FORCE_SIZE_T_LENGTH"):
    length_t = ctypes.c_size_t
else:
    length_t = ctypes.c_int

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_MESSAGE_FORCE_SIZE_T_LENGTH"):
    GLM_MESSAGE_FORCE_SIZE_T_LENGTH = True
    if defined("GLM_FORCE_SIZE_T_LENGTH"):
        message("GLM: .length() returns length_t, a typedef of size_t")
    else:
        message("GLM: .length() returns length_t, a typedef of int following the GLSL specification")

##########################################
# countof
def GLM_COUNTOF(arr):
    return len(arr)


#########################################
# PyGLM stuff
GLM_VEC = 0
GLM_MAT = 1
GLM_QUAT = 2

GLM_VEC2 = 0
GLM_VEC3 = 1
GLM_VEC4 = 2

GLM_MAT2x2 = 0
GLM_MAT2x3 = 1
GLM_MAT2x4 = 2
GLM_MAT3x2 = 3
GLM_MAT3x3 = 4
GLM_MAT3x4 = 5
GLM_MAT4x2 = 6
GLM_MAT4x3 = 7
GLM_MAT4x4 = 8

def type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")
