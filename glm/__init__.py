####################
# GLM License      #
####################
__doc__ = license = """
Copyright (c) 2005 - 2016 G-Truc Creation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Restrictions: By making use of the Software for military purposes, you choose
to make a Bunny unhappy.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
"""

#from . import detail
##from fwd import *
##from .detail.type_int import *
##from .detail.type_float import *
from .prep import *
from .datatypes import *
from .detail.setup import *

from .detail.type_vec2 import *
from .detail.type_vec3 import *
from .detail.type_vec4 import *

from .detail.func_geometric import *

from .detail.type_mat2x2 import tmat2x2
from .detail.type_mat2x3 import tmat2x3
from .detail.type_mat2x4 import tmat2x4

from .detail.type_mat3x2 import tmat3x2
from .detail.type_mat3x3 import tmat3x3
from .detail.type_mat3x4 import tmat3x4

from .detail.type_mat4x2 import tmat4x2
from .detail.type_mat4x3 import tmat4x3
from .detail.type_mat4x4 import tmat4x4

from .detail.func_matrix import *
#include "fwd.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_MESSAGE_CORE_INCLUDED_DISPLAYED)
#	define GLM_MESSAGE_CORE_INCLUDED_DISPLAYED
#	pragma message("GLM: Core library included")
#endif//GLM_MESSAGES

vec2 = tvec2
vec3 = tvec3
vec4 = tvec4

mat2 = tmat2x2
mat3 = tmat3x3
mat4 = tmat4x4

from .detail.func_trigonometric import *
from .detail.func_exponential import *
from .detail.func_common import *
from .detail.func_geometric import *
from .detail.func_matrix import *
from .detail.func_vector_relational import *
from .gtc.constants import *
from .gtc.matrix_access import *
from .gtc.matrix_transform import *
from .gtc.quaternion import *
from .gtc.random import *
from .gtc.noise import *
from .gtc.type_ptr import *
from .gtc.reciprocal import *
