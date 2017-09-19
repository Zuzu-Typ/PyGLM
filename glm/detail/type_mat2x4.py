from .setup import *

def _type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")

class tmat2x4:
    def __init__(self, *args):
        self.col_type = tvec4
        self.row_type = tvec2

        if len(args) == 1:
            if isinstance(args[0], tmat2x4) or isinstance(args[0], tmat3x4) or isinstance(args[0], tmat4x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1])]
            elif isinstance(args[0], tmat2x3) or isinstance(args[0], tmat3x3) or isinstance(args[0], tmat4x3):
                self.value = [self.col_type(args[0][0], 0),
                              self.col_type(args[0][1], 0)]
            elif isinstance(args[0], tmat2x2) or isinstance(args[0], tmat3x2) or isinstance(args[0], tmat4x2):
                self.value = [self.col_type(args[0][0], 0, 0),
                              self.col_type(args[0][1], 0, 0)]
                
            elif type(args[0]) in dtypes:
                self.value = [self.col_type(args[0],0, 0, 0),
                              self.col_type(0,args[0], 0, 0)]

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])

        elif len(args) == 2:
            if isinstance(args[0], self.col_type) and isinstance(args[1], self.col_type):
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1])]

        elif len(args) == 8:
            for arg in args:
                if not type(arg) in dtypes:
                    raise TypeError("unsupported type {} for tmat2x4()".format(arg))

            self.value = [self.col_type(*args[:4]),
                          self.col_type(*args[4:])]
                
        else:
            self.value = [self.col_type(1,0,0,0),
                          self.col_type(0,1,0,0)]

    def length():
        return 2
    __len__ = length

    def __eq__(self, value):
        if isinstance(value, tmat2x4):
            return (self[0] == value[0] and self[1] == value[1])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __ne__(self, value):
        if isinstance(value, tmat2x4):
            return (self[0] != value[0] or self[1] != value[1])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __add__(self, value):
        if type(value) in dtypes:
            return tmat2x4(self[0] + value,
                         self[1] + value)
        elif isinstance(value, tmat2x4):
            return tmat2x4(self[0] + value[0],
                         self[1] + value[1])
        else:
            try:
                return tmat2x4(self[0] + value[0],
                         self[1] + value[1])
            except:
                raise TypeError("unsupported operand type(s) for +: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        if type(value) in dtypes:
            return tmat2x4(self[0] - value,
                         self[1] - value)
        elif isinstance(value, tmat2x4):
            return tmat2x4(self[0] - value[0],
                         self[1] - value[1])
        else:
            try:
                return tmat2x4(self[0] - value[0],
                         self[1] - value[1])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __rsub__(self, value):
        if type(value) in dtypes:
            return tmat2x4(value - self[0],
                         value - self[1])
        elif isinstance(value, tmat2x4):
            return tmat2x4(value[0] - self[0],
                         value[1] - self[1])
        else:
            try:
                return tmat2x4(value[0] - self[0],
                         value[1] - self[1])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __mul__(self, value):
        if type(value) in dtypes:
            return tmat2x4(self[0] * value,
                         self[1] * value)
        elif isinstance(value, self.col_type):
            m = self
            v = value
            return self.col_type(m[0][0] * v.x + m[1][0] * v.y,
			m[0][1] * v.x + m[1][1] * v.y,
			m[0][2] * v.x + m[1][2] * v.y,
			m[0][3] * v.x + m[1][3] * v.y)
        elif isinstance(value, tmat2x2):
            m1 = self
            m2 = value
            return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1])
        elif isinstance(value, tmat4x2):
            m1 = self
            m2 = value
            SrcA00 = m1[0][0]
            SrcA01 = m1[0][1]
            SrcA02 = m1[0][2]
            SrcA03 = m1[0][3]
            SrcA10 = m1[1][0]
            SrcA11 = m1[1][1]
            SrcA12 = m1[1][2]
            SrcA13 = m1[1][3]

            SrcB00 = m2[0][0]
            SrcB01 = m2[0][1]
            SrcB10 = m2[1][0]
            SrcB11 = m2[1][1]
            SrcB20 = m2[2][0]
            SrcB21 = m2[2][1]
            SrcB30 = m2[3][0]
            SrcB31 = m2[3][1]

            Result = tmat4x4(0)
            Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01
            Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01
            Result[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01
            Result[0][3] = SrcA03 * SrcB00 + SrcA13 * SrcB01
            Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11
            Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11
            Result[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11
            Result[1][3] = SrcA03 * SrcB10 + SrcA13 * SrcB11
            Result[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21
            Result[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21
            Result[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21
            Result[2][3] = SrcA03 * SrcB20 + SrcA13 * SrcB21
            Result[3][0] = SrcA00 * SrcB30 + SrcA10 * SrcB31
            Result[3][1] = SrcA01 * SrcB30 + SrcA11 * SrcB31
            Result[3][2] = SrcA02 * SrcB30 + SrcA12 * SrcB31
            Result[3][3] = SrcA03 * SrcB30 + SrcA13 * SrcB31
            return Result
        elif isinstance(value, tmat3x2):
            m1 = self
            m2 = value
            return tmat3x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1])
        else:
            try:
                m1 = self
                m2 = value
                return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __rmul__(self, value):
        if type(value) in dtypes:
            return tmat2x4(self[0] * value,
                         self[1] * value)
        elif isinstance(value, self.row_type):
            m = self
            v = value
            return self.row_type(v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3],
			v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3])
        elif isinstance(value, tmat2x2):
            m1 = self
            m2 = value
            return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1])
        elif isinstance(value, tmat4x2):
            m1 = self
            m2 = value
            SrcA00 = m1[0][0]
            SrcA01 = m1[0][1]
            SrcA02 = m1[0][2]
            SrcA03 = m1[0][3]
            SrcA10 = m1[1][0]
            SrcA11 = m1[1][1]
            SrcA12 = m1[1][2]
            SrcA13 = m1[1][3]

            SrcB00 = m2[0][0]
            SrcB01 = m2[0][1]
            SrcB10 = m2[1][0]
            SrcB11 = m2[1][1]
            SrcB20 = m2[2][0]
            SrcB21 = m2[2][1]
            SrcB30 = m2[3][0]
            SrcB31 = m2[3][1]

            Result = tmat4x4(0)
            Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01
            Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01
            Result[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01
            Result[0][3] = SrcA03 * SrcB00 + SrcA13 * SrcB01
            Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11
            Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11
            Result[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11
            Result[1][3] = SrcA03 * SrcB10 + SrcA13 * SrcB11
            Result[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21
            Result[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21
            Result[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21
            Result[2][3] = SrcA03 * SrcB20 + SrcA13 * SrcB21
            Result[3][0] = SrcA00 * SrcB30 + SrcA10 * SrcB31
            Result[3][1] = SrcA01 * SrcB30 + SrcA11 * SrcB31
            Result[3][2] = SrcA02 * SrcB30 + SrcA12 * SrcB31
            Result[3][3] = SrcA03 * SrcB30 + SrcA13 * SrcB31
            return Result
        elif isinstance(value, tmat3x2):
            m1 = self
            m2 = value
            return tmat3x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1])
        else:
            try:
                m1 = self
                m2 = value
                return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __truediv__(self, value):
        if type(value) in dtypes:
            value = float(value)
            return tmat2x4(self[0] / value,
                         self[1] / value)
        else:
            raise TypeError("unsupported operand type(s) for /: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    def __rtruediv__(self, value):
        if type(value) in dtypes:
            value = float(value)
            return tmat2x4(value / self[0],
                         value / self[1])
        else:
            raise TypeError("unsupported operand type(s) for /: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in dtypes:
            self[0] += value
            self[1] += value
        elif isinstance(value, tmat2x4):
            self[0] += value[0]
            self[1] += value[1]
        else:
            try:
                self[0] += value[0]
                self[1] += value[1]
            except:
                raise TypeError("unsupported operand type(s) for +=: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __isub__(self, value):
        if type(value) in dtypes:
            self[0] -= value
            self[1] -= value
        elif isinstance(value, tmat2x4):
            self[0] -= value[0]
            self[1] -= value[1]
        else:
            try:
                self[0] -= value[0]
                self[1] -= value[1]
            except:
                raise TypeError("unsupported operand type(s) for -=: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __imul__(self, value):
        if type(value) in dtypes:
            self[0] *= value
            self[1] *= value
        else:
            raise TypeError("unsupported operand type(s) for *=: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __itruediv__(self, value):
        if type(value) in dtypes:
            self[0] /= float(value)
            self[1] /= float(value)
        else:
            raise TypeError("unsupported operand type(s) for /=: 'tmat2x4' and '{}'".format(_type_to_str(type(value))))
        return self

    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat2x4(-self[0],
                     -self[1])

    def __abs__(self):
        return tmat2x4(abs(self[0]),
                     abs(self[1]))

    def __invert__(self):
        return invert(self)

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat2x4 doesn't support slices")
        else:
            if key in (0,-2):
                return self.value[0]
            elif key in (1,-1):
                return self.value[1]
            else:
                raise IndexError("tmat2x4 index out of range")

    def __setitem__(self, key, value):
        if type(key) == slice:
            raise TypeError("tmat2x4 doesn't support slices")
        else:
            if key in (0,-2):
                self.value[0] = value
            elif key in (1,-1):
                self.value[1] = value
            else:
                raise IndexError("tmat2x4 index out of range")

    def __str__(self):
        return "tmat2x4( {}, {}, {}, {}\n         {}, {}, {}, {} )".format(self.value[0][0], self.value[0][1], self.value[0][2], self.value[0][3],
                                                                    self.value[1][0], self.value[1][1], self.value[1][2], self.value[1][3])

    __repr__ = __str__

from .func_matrix import *
from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4

from .type_mat2x2 import tmat2x2
from .type_mat2x3 import tmat2x3

from .type_mat3x2 import tmat3x2
from .type_mat3x3 import tmat3x3
from .type_mat3x4 import tmat3x4

from .type_mat4x2 import tmat4x2
from .type_mat4x3 import tmat4x3
from .type_mat4x4 import tmat4x4
