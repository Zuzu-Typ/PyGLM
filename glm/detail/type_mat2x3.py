from .setup import *

import numpy

class tmat2x3:
    def __init__(self, *args, **kw):
        self.dtype = kw.get("dtype", default_dtype)
        
        self.col_type = tvec3
        self.row_type = tvec2

        if len(args) == 1:
            if type(args[0]) == numpy.matrixlib.defmatrix.matrix and args[0].size == 6 and args[0].shape == (2,3):
                self.value = args[0].copy()
                
            if isinstance(args[0], tmat2x3) or isinstance(args[0], tmat3x3) or isinstance(args[0], tmat4x3) or\
               isinstance(args[0], tmat2x4) or isinstance(args[0], tmat3x4) or isinstance(args[0], tmat4x4):
                self.value = args[0].value[:2,:3]
                
            elif isinstance(args[0], tmat2x2) or isinstance(args[0], tmat3x2) or isinstance(args[0], tmat4x2):
                self.value = numpy.matrix([tuple(args[0][0])+(0,),
                              tuple(args[0][1])+(0,)], dtype=self.dtype)
                
            elif type(args[0]) in dtypes:
                self.value = numpy.matrix([(args[0],0, 0),
                              (0,args[0], 0)], dtype=self.dtype)

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])

        elif len(args) == 2:
            self.value = numpy.matrix([(args[0]),
                              (args[1])], dtype=self.dtype)
##            if isinstance(args[0], self.col_type) and isinstance(args[1], self.col_type):
##                self.value = [self.col_type(args[0]),
##                              self.col_type(args[1])]

        elif len(args) == 6:
            self.value = numpy.matrix([(args[:3]),
                          (args[3:])], dtype=self.dtype)
##            for arg in args:
##                if not type(arg) in dtypes:
##                    raise TypeError("unsupported type {} for tmat2x3()".format(arg))
##
##            self.value = [self.col_type(*args[:3]),
##                          self.col_type(*args[3:])]
                
        else:
            self.value = numpy.matrix([(1,0,0),
                          (0,1,0)], dtype=self.dtype)
##            self.value = [self.col_type(1,0,0),
##                          self.col_type(0,1,0)]

    def __setitem__(self, *args, **kw):
        return self.value.__setitem__(*args, **kw)

    def length():
        return 2
    __len__ = length

    glm_type = GLM_MAT
    shape = GLM_MAT2x3

    def __eq__(self, value):
        if isinstance(value, tmat2x3):
            return (self[0] == value[0] and self[1] == value[1])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

    def __ne__(self, value):
        if isinstance(value, tmat2x3):
            return (self[0] != value[0] or self[1] != value[1])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

    def __add__(self, value):
        try:
            return tmat2x3(self.value + value)
        except:
            raise TypeError("unsupported operand type(s) for +: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            return tmat2x3(self[0] + value,
##                         self[1] + value)
##        elif isinstance(value, tmat2x3):
##            return tmat2x3(self[0] + value[0],
##                         self[1] + value[1])
##        else:
##            try:
##                return tmat2x3(self[0] + value[0],
##                         self[1] + value[1])
##            except:
##                raise TypeError("unsupported operand type(s) for +: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        try:
            return tmat2x3(self.value - value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            return tmat2x3(self[0] - value,
##                         self[1] - value)
##        elif isinstance(value, tmat2x3):
##            return tmat2x3(self[0] - value[0],
##                         self[1] - value[1])
##        else:
##            try:
##                return tmat2x3(self[0] - value[0],
##                         self[1] - value[1])
##            except:
##                raise TypeError("unsupported operand type(s) for -: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

    def __rsub__(self, value):
        try:
            return tmat2x3(value - self.value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            return tmat2x3(value - self[0],
##                         value - self[1])
##        elif isinstance(value, tmat2x3):
##            return tmat2x3(value[0] - self[0],
##                         value[1] - self[1])
##        else:
##            try:
##                return tmat2x2(value[0] - self[0],
##                         value[1] - self[1])
##            except:
##                raise TypeError("unsupported operand type(s) for -: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

    def __mul__(self, value):
        try:
            if hasattr(value, "__rmul__"):
                rmul = value.__rmul__
                
            if hasattr(value, "glm_type") and value.glm_type == GLM_MAT:
                value = value.value
                
            if isinstance(value, self.row_type):
                return self.row_type(value.arr.reshape(2) * self.value)
            if type(value) == numpy.ndarray:
                return self.row_type(value.reshape(2) * self.value)

            if type(value) == numpy.matrixlib.defmatrix.matrix:
                if value.shape == (2,2):
                    return tmat2x3(value * self.value)
                if value.shape == (3,2):
                    return tmat3x3(value * self.value)
                if value.shape == (4,2):
                    return tmat4x3(value * self.value)
            
            return rmul(self)
            
        except:
            raise TypeError("unsupported operand type(s) for *: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            return tmat2x3(self[0] * value,
##                         self[1] * value)
##        elif isinstance(value, self.col_type):
##            return self.col_type(self[0][0] * value.x + self[1][0] * value.y,
##			self[0][1] * value.x + self[1][1] * value.y,
##			self[0][2] * value.x + self[1][2] * value.y)
##        elif isinstance(value, tmat2x2):
##            return tmat2x3(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][2] * value[0][0] + self[1][2] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][2] * value[1][0] + self[1][2] * value[1][1])
##        elif isinstance(value, tmat3x2):
##            SrcA01 = self[0][1]
##            SrcA02 = self[0][2]
##            SrcA10 = self[1][0]
##            SrcA11 = self[1][1]
##            SrcA12 = self[1][2]
##
##            SrcB00 = value[0][0]
##            SrcB01 = value[0][1]
##            SrcB10 = value[1][0]
##            SrcB11 = value[1][1]
##            SrcB20 = value[2][0]
##            SrcB21 = value[2][1]
##
##            Result = tmat3x3(0)
##            Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01
##            Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01
##            Result[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01
##            Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11
##            Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11
##            Result[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11
##            Result[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21
##            Result[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21
##            Result[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21
##            return Result
##        elif isinstance(value, tmat4x2):
##            return tmat4x3(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][2] * value[0][0] + self[1][2] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][2] * value[1][0] + self[1][2] * value[1][1],
##			self[0][0] * value[2][0] + self[1][0] * value[2][1],
##			self[0][1] * value[2][0] + self[1][1] * value[2][1],
##			self[0][2] * value[2][0] + self[1][2] * value[2][1],
##			self[0][0] * value[3][0] + self[1][0] * value[3][1],
##			self[0][1] * value[3][0] + self[1][1] * value[3][1],
##			self[0][2] * value[3][0] + self[1][2] * value[3][1])
##        else:
##            try:
##                return tmat2x3(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][2] * value[0][0] + self[1][2] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][2] * value[1][0] + self[1][2] * value[1][1])
##            except:
##                raise TypeError("unsupported operand type(s) for *: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

    def __rmul__(self, value):
        try:
            if (hasattr(value, "glm_type") and value.glm_type == GLM_MAT):
                value = value.value
                
            if isinstance(value, self.col_type):
                return self.row_type(self.value * value.arr.reshape(3,1))
            if type(value) == numpy.ndarray:
                return self.row_type(self.value * value.reshape(3,1))

            if type(value) == numpy.matrixlib.defmatrix.matrix:
                if value.shape == (2,2):
                    return tmat2x3(self.value * value)
                if value.shape == (3,2):
                    return tmat3x3(self.value * value)
                if value.shape == (4,2):
                    return tmat4x3(self.value * value)
            
        except:
            raise TypeError("unsupported operand type(s) for *: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            return tmat2x3(self[0] * value,
##                         self[1] * value)
##        elif isinstance(value, self.row_type):
##            return self.row_type(v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2],
##			v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2])
##        elif isinstance(value, tmat2x2):
##            return tmat2x3(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][2] * value[0][0] + self[1][2] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][2] * value[1][0] + self[1][2] * value[1][1])
##        elif isinstance(value, tmat3x2):
##            SrcA01 = self[0][1]
##            SrcA02 = self[0][2]
##            SrcA10 = self[1][0]
##            SrcA11 = self[1][1]
##            SrcA12 = self[1][2]
##
##            SrcB00 = value[0][0]
##            SrcB01 = value[0][1]
##            SrcB10 = value[1][0]
##            SrcB11 = value[1][1]
##            SrcB20 = value[2][0]
##            SrcB21 = value[2][1]
##
##            Result = tmat3x3(0)
##            Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01
##            Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01
##            Result[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01
##            Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11
##            Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11
##            Result[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11
##            Result[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21
##            Result[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21
##            Result[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21
##            return Result
##        elif isinstance(value, tmat4x2):
##            return tmat4x3(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][2] * value[0][0] + self[1][2] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][2] * value[1][0] + self[1][2] * value[1][1],
##			self[0][0] * value[2][0] + self[1][0] * value[2][1],
##			self[0][1] * value[2][0] + self[1][1] * value[2][1],
##			self[0][2] * value[2][0] + self[1][2] * value[2][1],
##			self[0][0] * value[3][0] + self[1][0] * value[3][1],
##			self[0][1] * value[3][0] + self[1][1] * value[3][1],
##			self[0][2] * value[3][0] + self[1][2] * value[3][1])
##        else:
##            try:
##                return tmat2x3(self[0][0] * value[0][0] + self[1][0] * value[0][1],
##			self[0][1] * value[0][0] + self[1][1] * value[0][1],
##			self[0][2] * value[0][0] + self[1][2] * value[0][1],
##			self[0][0] * value[1][0] + self[1][0] * value[1][1],
##			self[0][1] * value[1][0] + self[1][1] * value[1][1],
##			self[0][2] * value[1][0] + self[1][2] * value[1][1])
##            except:
##                raise TypeError("unsupported operand type(s) for *: 'tmat2x3' and '{}'".format(type_to_str(type(value))))

##    def __truediv__(self, value):
##        if type(value) in dtypes:
##            value = float(value)
##            return tmat2x3(self[0] / value,
##                         self[1] / value)
##        else:
##            raise TypeError("unsupported operand type(s) for /: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##
##    def __rtruediv__(self, value):
##        if type(value) in dtypes:
##            value = float(value)
##            return tmat2x3(value / self[0],
##                         value / self[1])
##        else:
##            raise TypeError("unsupported operand type(s) for /: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##
##    __div__ = __truediv__
##
##    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        try:
            self.value += value
        except:
            raise TypeError("unsupported operand type(s) for +=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            self[0] += value
##            self[1] += value
##        elif isinstance(value, tmat2x3):
##            self[0] += value[0]
##            self[1] += value[1]
##        else:
##            try:
##                self[0] += value[0]
##                self[1] += value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for +=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
        return self

    def __isub__(self, value):
        try:
            self.value -= value
        except:
            raise TypeError("unsupported operand type(s) for -=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            self[0] -= value
##            self[1] -= value
##        elif isinstance(value, tmat2x3):
##            self[0] -= value[0]
##            self[1] -= value[1]
##        else:
##            try:
##                self[0] -= value[0]
##                self[1] -= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for -=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
        return self

    def __imul__(self, value):
        try:
            self.value *= value
        except:
            raise TypeError("unsupported operand type(s) for *=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        if type(value) in dtypes:
##            self[0] *= value
##            self[1] *= value
##        else:
##            raise TypeError("unsupported operand type(s) for *=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
        return self

##    def __itruediv__(self, value):
##        if type(value) in dtypes:
##            self[0] /= float(value)
##            self[1] /= float(value)
##        else:
##            raise TypeError("unsupported operand type(s) for /=: 'tmat2x3' and '{}'".format(type_to_str(type(value))))
##        return self
##
##    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat2x3(-self.value)

    def __abs__(self):
        return tmat2x3(abs(self.value))

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat2x3 doesn't support slices")
        elif type(key) == tuple and len(key) == 2:
            return self.value[key[0], key[1]]
        else:
            if key in (0,-2):
                return self.col_type(self.value[0])
            elif key in (1,-1):
                return self.col_type(self.value[1])
            else:
                raise IndexError("tmat2x3 index out of range")

    def __array__(self, *args, **kw):
        return numpy.matrix(self.value, *args, **kw)

##    def __setitem__(self, key, value):
##        if type(key) == slice:
##            raise TypeError("tmat2x3 doesn't support slices")
##        else:
##            if key in (0,-2):
##                self.value[0] = value
##            elif key in (1,-1):
##                self.value[1] = value
##            else:
##                raise IndexError("tmat2x3 index out of range")

    def __str__(self):
        return "tmat2x3( {}, {}, {},\n         {}, {}, {} )".format(self[0][0], self[0][1], self[0][2],
                                                                    self[1][0], self[1][1], self[1][2])

    __repr__ = __str__

from .func_matrix import *
from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4

from .type_mat2x2 import tmat2x2
from .type_mat2x4 import tmat2x4

from .type_mat3x2 import tmat3x2
from .type_mat3x3 import tmat3x3
from .type_mat3x4 import tmat3x4

from .type_mat4x2 import tmat4x2
from .type_mat4x3 import tmat4x3
from .type_mat4x4 import tmat4x4
