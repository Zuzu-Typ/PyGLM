import ctypes
#from ..detail.setup import *

from ..detail.type_vec2 import *
from ..detail.type_vec3 import *
from ..detail.type_vec4 import *

from ..detail.type_mat2x2 import tmat2x2
from ..detail.type_mat2x3 import tmat2x3
from ..detail.type_mat2x4 import tmat2x4

from ..detail.type_mat3x2 import tmat3x2
from ..detail.type_mat3x3 import tmat3x3
from ..detail.type_mat3x4 import tmat3x4

from ..detail.type_mat4x2 import tmat4x2
from ..detail.type_mat4x3 import tmat4x3
from ..detail.type_mat4x4 import tmat4x4

def value_ptr(x):
	if x.__class__ in (tvec2, tvec3, tvec4): #vec
		tpl = tuple( x )
		return ctypes.pointer((ctypes.c_float * len(tpl))(*tpl))
	else:
		l = []
		w = len( tuple(x) )
		h = len( x[0] )
		for y_pos in range(h):
						l += list(x[y_pos])
##			for x_pos in range( w ):
##				l.append(x[ y_pos ][x_pos ])
		return ctypes.pointer((ctypes.c_float * len(l))(*l))
def sizeof(x):
		try:
				return x.__size__
		except:
				raise TypeError("sizeof requires a glm type")
