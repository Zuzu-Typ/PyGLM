from ..datatypes import default_dtype, dtypes, ltypes
from .setup import GLM_C_FLOAT_SIZE, GLM_MAT, GLM_MAT2x2, pyglmCompareType, pyglmTypeIn

import numpy

class tmat2x2:
    def __init__(self, *args, **kw):
        self.dtype = kw.get("dtype", default_dtype)
        self.col_type = self.row_type = tvec2

        if len(args) == 1:
            if pyglmTypeIn(args[0], (tmat2x2, tmat2x3, tmat2x4, tmat3x2, tmat3x3, tmat3x4, tmat4x2, tmat4x3, tmat4x4)):
                self.value = args[0].value[:2,:2]

            elif pyglmCompareType(args[0], tvec4):
                self.value = numpy.matrix([(args[0].xy),
                              (args[0].zw)], dtype=self.dtype)
                
            elif type(args[0]) in dtypes:
                self.value = numpy.matrix([(args[0],0),
                              (0,args[0])], dtype=self.dtype)

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])

        elif len(args) == 2:
            self.value = numpy.matrix([(args[0]),
                              (args[1])], dtype=self.dtype)

        elif len(args) == 3:
            if pyglmCompareType(args[0], tvec2) and type(args[1]) in dtypes and type(args[2]) in dtypes:
                self.value = numpy.matrix([(args[0]),
                              (args[1], args[2])], dtype=self.dtype)
            if pyglmCompareType(args[2], tvec2) and type(args[0]) in dtypes and type(args[1]) in dtypes:
                self.value = numpy.matrix([(args[0], args[1]),
                              (args[2])], dtype=self.dtype)

        elif len(args) == 4:
            self.value = numpy.matrix([(args[:2]),
                          (args[2:])], dtype=self.dtype)
##            for arg in args:
##                if not type(arg) in dtypes:
##                    raise TypeError("unsupported type {} for tmat2x2()".format(arg))
##
##            self.value = [self.col_type(*args[:2]),
##                          self.col_type(*args[2:])]
                
        else:
            self.value = numpy.matrix([(1,0),
                          (0,1)], dtype=self.dtype)

    def __setitem__(self, *args, **kw):
        return self.value.__setitem__(*args, **kw)

    def length(*args):
        return 2
    __len__ = length

    def __sizeof__(self):
        return GLM_C_FLOAT_SIZE * 4

    __size__ = GLM_C_FLOAT_SIZE * 4

    glm_type = GLM_MAT
    shape = GLM_MAT2x2

    def __eq__(self, value):
        if pyglmCompareType(value, tmat2x2):
            return (self[0] == value[0] and self[1] == value[1])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat2x2' and '{}'".format(type(value)))

    def __ne__(self, value):
        if pyglmCompareType(value, tmat2x2):
            return (self[0] != value[0] or self[1] != value[1])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat2x2' and '{}'".format(type(value)))

    def __add__(self, value):
        try:
            return tmat2x2(self.value + value)
        except:
            raise TypeError("unsupported operand type(s) for +: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat2x2(self[0] + value,
##                         self[1] + value)
##        elif pyglmCompareType(value, tmat2x2):
##            return tmat2x2(self[0] + value[0],
##                         self[1] + value[1])
##        else:
##            try:
##                return tmat2x2(self[0] + value[0],
##                         self[1] + value[1])
##            except:
##                raise TypeError("unsupported operand type(s) for +: 'tmat2x2' and '{}'".format(type(value)))

    __radd__ = __add__

    def __sub__(self, value):
        try:
            return tmat2x2(self.value - value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat2x2(self[0] - value,
##                         self[1] - value)
##        elif pyglmCompareType(value, tmat2x2):
##            return tmat2x2(self[0] - value[0],
##                         self[1] - value[1])
##        else:
##            try:
##                return tmat2x2(self[0] - value[0],
##                         self[1] - value[1])
##            except:
##                raise TypeError("unsupported operand type(s) for -: 'tmat2x2' and '{}'".format(type(value)))

    def __rsub__(self, value):
        try:
            return tmat2x2(value - self.value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat2x2(value - self[0],
##                         value - self[1])
##        elif pyglmCompareType(value, tmat2x2):
##            return tmat2x2(value[0] - self[0],
##                         value[1] - self[1])
##        else:
##            try:
##                return tmat2x2(value[0] - self[0],
##                         value[1] - self[1])
##            except:
##                raise TypeError("unsupported operand type(s) for -: 'tmat2x2' and '{}'".format(type(value)))

    def __mul__(self, value):
        try:
            if hasattr(value, "__rmul__"):
                rmul = value.__rmul__
                
            if hasattr(value, "glm_type") and value.glm_type == GLM_MAT:
                value = value.value
                
            if pyglmCompareType(value, self.row_type):
                return self.row_type(value.arr.reshape(2) * self.value)
            if type(value) == numpy.ndarray:
                return self.row_type(value.reshape(2) * self.value)

            if type(value) == numpy.matrixlib.defmatrix.matrix:
                if value.shape == (2,2):
                    return tmat2x2(value * self.value)
                if value.shape == (3,2):
                    return tmat3x2(value * self.value)
                if value.shape == (4,2):
                    return tmat4x2(value * self.value)
            
            return rmul(self)
            
        except:
            raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat2x2(self[0] * value,
##                         self[1] * value)
##        elif pyglmCompareType(value, self.col_type):
##            return tvec2(self[0][0] * value.x + self[1][0] * value.y,
##			self[0][1] * value.x + self[1][1] * value.y)
##        elif pyglmCompareType(value, tmat2x2):
##            return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1])
##        elif pyglmCompareType(value, tmat3x2):
##            return tmat3x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][0] * value[2][0] + self[1][0] * value[2][1],
##			self[0][1] * value[2][0] + self[1][1] * value[2][1])
##        elif pyglmCompareType(value, tmat4x2):
##            return tmat4x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][0] * value[2][0] + self[1][0] * value[2][1],
##			self[0][1] * value[2][0] + self[1][1] * value[2][1],
##			self[0][0] * value[3][0] + self[1][0] * value[3][1],
##			self[0][1] * value[3][0] + self[1][1] * value[3][1])
##        else:
##            try:
##                return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1])
##            except:
##                raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(type(value)))

    def __rmul__(self, value):
        try:
            if (hasattr(value, "glm_type") and value.glm_type == GLM_MAT):
                value = value.value
                
            if pyglmCompareType(value, self.col_type):
                return self.row_type(self.value * value.arr.reshape(2,1))
            if type(value) == numpy.ndarray:
                return self.row_type(self.value * value.reshape(2,1))

            if type(value) == numpy.matrixlib.defmatrix.matrix:
                if value.shape == (2,2):
                    return tmat2x2(self.value * value)
                if value.shape == (3,2):
                    return tmat3x2(self.value * value)
                if value.shape == (4,2):
                    return tmat4x2(self.value * value)
            
        except:
            raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat2x2(self[0] * value,
##                         self[1] * value)
##        elif pyglmCompareType(value, self.row_type):
##            return tvec2(v.x * m[0][0] + v.y * m[0][1],
##			v.x * m[1][0] + v.y * m[1][1])
##        elif pyglmCompareType(value, tmat2x2):
##            return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1])
##        elif pyglmCompareType(value, tmat3x2):
##            return tmat3x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][0] * value[2][0] + self[1][0] * value[2][1],
##			self[0][1] * value[2][0] + self[1][1] * value[2][1])
##        elif pyglmCompareType(value, tmat4x2):
##            return tmat4x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][0] * value[2][0] + self[1][0] * value[2][1],
##			self[0][1] * value[2][0] + self[1][1] * value[2][1],
##			self[0][0] * value[3][0] + self[1][0] * value[3][1],
##			self[0][1] * value[3][0] + self[1][1] * value[3][1])
##        else:
##            try:
##                return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1])
##            except:
##                raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(type(value)))

    def __truediv__(self, value):
        try:
            if pyglmCompareType(value, self.row_type):
                return self.row_type(inverse(self) * value)
            return self * inverse(value)
        except:
            try:
                return value.__rdiv__(self)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            value = float(value)
##            return tmat2x2(self[0] / value,
##                         self[1] / value)
##        elif pyglmCompareType(value, tvec2):
##            return inverse(self) * value
##        elif pyglmCompareType(value, tmat2x2):
##            return self * inverse(value)
##        else:
##            try:
##                return self * inverse(value)
##            except:
##                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(type(value)))

    def __rtruediv__(self, value):
        try:
            if pyglmCompareType(value, self.col_type):
                return self.col_type(value * inverse(self))
            return value * inverse(self)
        except:
            raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            value = float(value)
##            return tmat2x2(value / self[0],
##                         value / self[1])
##        elif pyglmCompareType(value, tvec2):
##            return value * inverse(self)
##        elif pyglmCompareType(value, tmat2x2):
##            return inverse(self) * value
##        else:
##            try:
##                return value * inverse(self)
##            except:
##                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(type(value)))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        try:
            self.value += value
        except:
            raise TypeError("unsupported operand type(s) for +=: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] += value
##            self[1] += value
##        elif pyglmCompareType(value, tmat2x2):
##            self[0] += value[0]
##            self[1] += value[1]
##        else:
##            try:
##                self[0] += value[0]
##                self[1] += value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for +=: 'tmat2x2' and '{}'".format(type(value)))
        return self

    def __isub__(self, value):
        try:
            self.value -= value
        except:
            raise TypeError("unsupported operand type(s) for -=: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] -= value
##            self[1] -= value
##        elif pyglmCompareType(value, tmat2x2):
##            self[0] -= value[0]
##            self[1] -= value[1]
##        else:
##            try:
##                self[0] -= value[0]
##                self[1] -= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for -=: 'tmat2x2' and '{}'".format(type(value)))
        return self

    def __imul__(self, value):
        try:
            self.value *= value
        except:
            raise TypeError("unsupported operand type(s) for *=: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] *= value
##            self[1] *= value
##        elif pyglmCompareType(value, tmat2x2):
##            self.value = (self * value).value
##        else:
##            try:
##                self[0] *= value[0]
##                self[1] *= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for *=: 'tmat2x2' and '{}'".format(type(value)))
        return self

    def __itruediv__(self, value):
        try:
            self.value *= inverse(value)
        except:
            raise TypeError("unsupported operand type(s) for /=: 'tmat2x2' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] /= float(value)
##            self[1] /= float(value)
##        elif pyglmCompareType(value, tmat2x2):
##            self *= inverse(value)
##        else:
##            try:
##                self *= inverse(value)
##            except:
##                raise TypeError("unsupported operand type(s) for /=: 'tmat2x2' and '{}'".format(type(value)))
        return self

    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat3x3(-self.value)

    def __abs__(self):
        return tmat3x3(abs(self.value))

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat2x2 doesn't support slices")
        elif type(key) == tuple and len(key) == 2:
            return self.value[key[0], key[1]]
        else:
            if key in (0,-2):
                return self.col_type(self.value[0])
            elif key in (1,-1):
                return self.col_type(self.value[1])
            else:
                raise IndexError("tmat2x2 index out of range")

    def __array__(self, *args, **kw):
        return numpy.matrix(self.value, *args, **kw)

##    def __setitem__(self, key, value):
##        if type(key) == slice:
##            raise TypeError("tmat2x2 doesn't support slices")
##        else:
##            if key in (0,-2):
##                self.value[0] = value
##            elif key in (1,-1):
##                self.value[1] = value
##            else:
##                raise IndexError("tmat2x2 index out of range")

    def __str__(self):
        return "tmat2x2( {}, {},\n         {}, {} )".format(self[0,0], self[0,1], self[1,0], self[1,1])

    __repr__ = __str__

from .func_matrix import *
from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4

from .type_mat2x3 import tmat2x3
from .type_mat2x4 import tmat2x4

from .type_mat3x2 import tmat3x2
from .type_mat3x3 import tmat3x3
from .type_mat3x4 import tmat3x4

from .type_mat4x2 import tmat4x2
from .type_mat4x3 import tmat4x3
from .type_mat4x4 import tmat4x4
