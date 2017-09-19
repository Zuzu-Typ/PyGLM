from .setup import *

def _type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")

class tmat4x2:
    def __init__(self, *args):
        self.col_type = tvec2
        self.row_type = tvec4

        if len(args) == 1:
            if isinstance(args[0], tmat4x2) or\
               isinstance(args[0], tmat4x3) or\
               isinstance(args[0], tmat4x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1]),
                              self.col_type(args[0][2]),
                              self.col_type(args[0][3])]

            elif isinstance(args[0], tmat3x2) or isinstance(args[0], tmat3x3)  or isinstance(args[0], tmat3x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1]),
                              self.col_type(args[0][2]),
                              self.col_type(0)]

            elif isinstance(args[0], tmat2x2) or isinstance(args[0], tmat2x3) or isinstance(args[0], tmat2x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1]),
                              self.col_type(0),
                              self.col_type(0)]
                
            elif type(args[0]) in dtypes:
                self.value = [self.col_type(args[0],0),
                              self.col_type(0,args[0]),
                              self.col_type(0, 0),
                              self.col_type(0, 0)]

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])

        elif len(args) == 4:
            if isinstance(args[0], self.col_type) and isinstance(args[1], self.col_type) and isinstance(args[2], self.col_type) and isinstance(args[3], self.col_type):
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1]),
                              self.col_type(args[2]),
                              self.col_type(args[3])]

        elif len(args) == 8:
            for arg in args:
                if not type(arg) in dtypes:
                    raise TypeError("unsupported type {} for tmat4x2()".format(arg))

            self.value = [self.col_type(*args[:2]),
                          self.col_type(*args[2:4]),
                          self.col_type(*args[4:6]),
                          self.col_type(*args[6:])]
                
        else:
            self.value = [self.col_type(1,0),
                          self.col_type(0,1),
                          self.col_type(0,0),
                          self.col_type(0,0)]

    def length():
        return 4
    __len__ = length

    def __eq__(self, value):
        if isinstance(value, tmat4x2):
            return (self[0] == value[0] and self[1] == value[1] and self[2] == value[2] and self[3] == value[3])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1] and self[2] == value[2] and self[3] == value[3])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __ne__(self, value):
        if isinstance(value, tmat4x2):
            return (self[0] != value[0] or self[1] != value[1] or self[2] != value[2] or self[3] != value[3])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1] or self[2] != value[2] or self[3] != value[3])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __add__(self, value):
        if type(value) in dtypes:
            return tmat4x2(self[0] + value,
                         self[1] + value,
                           self[2] + value,
                           self[3] + value)
        elif isinstance(value, tmat4x2):
            return tmat4x2(self[0] + value[0],
                         self[1] + value[1],
                           self[2] + value[2],
                           self[3] + value[3])
        else:
            try:
                return tmat4x2(self[0] + value[0],
                         self[1] + value[1],
                               self[2] + value[2],
                               self[3] + value[3])
            except:
                raise TypeError("unsupported operand type(s) for +: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        if type(value) in dtypes:
            return tmat4x2(self[0] - value,
                         self[1] - value,
                           self[2] - value,
                           self[3] - value)
        elif isinstance(value, tmat4x2):
            return tmat4x2(self[0] - value[0],
                         self[1] - value[1],
                           self[2] - value[2],
                           self[3] - value[3])
        else:
            try:
                return tmat4x2(self[0] - value[0],
                         self[1] - value[1],
                               self[2] - value[2],
                               self[3] - value[3])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __rsub__(self, value):
        if type(value) in dtypes:
            return tmat4x2(value - self[0],
                         value - self[1],
                           value - self[2],
                           value - self[3])
        elif isinstance(value, tmat4x2):
            return tmat4x2(value[0] - self[0],
                         value[1] - self[1],
                           value[2] - self[2],
                           value[3] - self[3])
        else:
            try:
                return tmat4x2(value[0] - self[0],
                         value[1] - self[1],
                               value[2] - self[2],
                               value[3] - self[3])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __mul__(self, value):
        if type(value) in dtypes:
            return tmat4x2(self[0] * value,
                         self[1] * value,
                           self[2] * value,
                           self[3] * value)
        elif isinstance(value, self.row_type):
            m = self
            v = value
            return self.col_type(m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z,
			m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z)
        elif isinstance(value, tmat2x3):
            m1 = self
            m2 = value
            SrcA00 = m1[0][0]
            SrcA01 = m1[0][1]
            SrcA10 = m1[1][0]
            SrcA11 = m1[1][1]
            SrcA20 = m1[2][0]
            SrcA21 = m1[2][1]
            SrcA30 = m1[3][0]
            SrcA31 = m1[3][1]

            SrcB00 = m2[0][0]
            SrcB01 = m2[0][1]
            SrcB02 = m2[0][2]
            SrcB03 = m2[0][3]
            SrcB10 = m2[1][0]
            SrcB11 = m2[1][1]
            SrcB12 = m2[1][2]
            SrcB13 = m2[1][3]

            Result = tmat2x2(0)
            Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01 + SrcA20 * SrcB02 + SrcA30 * SrcB03
            Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01 + SrcA21 * SrcB02 + SrcA31 * SrcB03
            Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11 + SrcA20 * SrcB12 + SrcA30 * SrcB13
            Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11 + SrcA21 * SrcB12 + SrcA31 * SrcB13
            return Result
        elif isinstance(value, tmat3x4):
            m1 = self
            m2 = value
            return tmat3x2(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3])
        elif isinstance(value, tmat4x4):
            m1 = self
            m2 = value
            return tmat4x2(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3])
        else:
            raise TypeError("unsupported operand type(s) for *: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __rmul__(self, value):
        if type(value) in dtypes:
            return tmat4x2(self[0] * value,
                         self[1] * value,
                           self[2] * value,
                           self[3] * value)
        elif isinstance(value, self.col_type):
            m = self
            v = value
            return self.row_type(v.x * m[0][0] + v.y * m[0][1],
			v.x * m[1][0] + v.y * m[1][1],
			v.x * m[2][0] + v.y * m[2][1],
			v.x * m[3][0] + v.y * m[3][1])
        elif isinstance(value, tmat2x3):
            m1 = self
            m2 = value
            SrcA00 = m1[0][0]
            SrcA01 = m1[0][1]
            SrcA10 = m1[1][0]
            SrcA11 = m1[1][1]
            SrcA20 = m1[2][0]
            SrcA21 = m1[2][1]
            SrcA30 = m1[3][0]
            SrcA31 = m1[3][1]

            SrcB00 = m2[0][0]
            SrcB01 = m2[0][1]
            SrcB02 = m2[0][2]
            SrcB03 = m2[0][3]
            SrcB10 = m2[1][0]
            SrcB11 = m2[1][1]
            SrcB12 = m2[1][2]
            SrcB13 = m2[1][3]

            Result = tmat2x2(0)
            Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01 + SrcA20 * SrcB02 + SrcA30 * SrcB03
            Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01 + SrcA21 * SrcB02 + SrcA31 * SrcB03
            Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11 + SrcA20 * SrcB12 + SrcA30 * SrcB13
            Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11 + SrcA21 * SrcB12 + SrcA31 * SrcB13
            return Result
        elif isinstance(value, tmat3x4):
            m1 = self
            m2 = value
            return tmat3x2(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3])
        elif isinstance(value, tmat4x4):
            m1 = self
            m2 = value
            return tmat4x2(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3])
        else:
            raise TypeError("unsupported operand type(s) for *: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __truediv__(self, value):
        if type(value) in dtypes:
            value = float(value)
            return tmat4x2(self[0] / value,
                         self[1] / value,
                           self[2] / value,
                           self[3] / value)
        else:
            try:
                return self * inverse(value)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    def __rtruediv__(self, value):
        if type(value) in dtypes:
            value = float(value)
            return tmat4x2(value / self[0],
                         value / self[1],
                           value / self[2])
        else:
            try:
                return value * inverse(self)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in dtypes:
            self[0] += value
            self[1] += value
            self[2] += value
            self[3] += value
        elif isinstance(value, tmat4x2):
            self[0] += value[0]
            self[1] += value[1]
            self[2] += value[2]
            self[3] += value[3]
        else:
            try:
                self[0] += value[0]
                self[1] += value[1]
                self[2] += value[2]
                self[3] += value[3]
            except:
                raise TypeError("unsupported operand type(s) for +=: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))
        return self

    def __isub__(self, value):
        if type(value) in dtypes:
            self[0] -= value
            self[1] -= value
            self[2] -= value
            self[3] -= value
        elif isinstance(value, tmat4x2):
            self[0] -= value[0]
            self[1] -= value[1]
            self[2] -= value[2]
            self[3] -= value[3]
        else:
            try:
                self[0] -= value[0]
                self[1] -= value[1]
                self[2] -= value[2]
                self[3] -= value[3]
            except:
                raise TypeError("unsupported operand type(s) for -=: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))
        return self

    def __imul__(self, value):
        if type(value) in dtypes:
            self[0] *= value
            self[1] *= value
            self[2] *= value
            self[3] *= value
        elif isinstance(value, tmat4x2):
            self.value = (self * value).value
        else:
            try:
                self[0] *= value[0]
                self[1] *= value[1]
                self[2] *= value[2]
                self[3] *= value[3]
            except:
                raise TypeError("unsupported operand type(s) for *=: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))
        return self

    def __itruediv__(self, value):
        if type(value) in dtypes:
            self[0] /= float(value)
            self[1] /= float(value)
            self[2] /= float(value)
            self[3] /= float(value)
        else:
            try:
                self *= inverse(value)
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tmat4x2' and '{}'".format(_type_to_str(type(value))))
        return self

    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat4x2(-self[0],
                     -self[1],
                       -self[2],
                       -self[3])

    def __abs__(self):
        return tmat4x2(abs(self[0]),
                     abs(self[1]),
                       abs(self[2]),
                       abs(self[3]))

    def __invert__(self):
        return invert(self)

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat4x2 doesn't support slices")
        else:
            if key in (0,-4):
                return self.value[0]
            elif key in (1,-3):
                return self.value[1]
            elif key in (2,-2):
                return self.value[2]
            elif key in (3,-1):
                return self.value[3]
            else:
                raise IndexError("tmat4x2 index out of range")

    def __setitem__(self, key, value):
        if type(key) == slice:
            raise TypeError("tmat4x2 doesn't support slices")
        else:
            if key in (0,-4):
                self.value[0] = value
            elif key in (1,-3):
                self.value[1] = value
            elif key in (2,-2):
                self.value[2] = value
            elif key in (3,-1):
                self.value[3] = value
            else:
                raise IndexError("tmat4x2 index out of range")

    def __str__(self):
        return "tmat4x2( {}, {},\n         {}, {},\n         {}, {},\n         {}, {} )".format(self.value[0][0], self.value[0][1],
                                                                             self.value[1][0], self.value[1][1],
                                                                             self.value[2][0], self.value[2][1],
                                                                                                self.value[3][0], self.value[3][1])

    __repr__ = __str__

from .func_matrix import *
from .type_vec2 import tvec2
from .type_vec3 import tvec3
from .type_vec4 import tvec4

from .type_mat2x2 import tmat2x2
from .type_mat2x3 import tmat2x3
from .type_mat2x4 import tmat2x4

from .type_mat3x2 import tmat3x2
from .type_mat3x3 import tmat3x3
from .type_mat3x4 import tmat3x4

from .type_mat4x3 import tmat4x3
from .type_mat4x4 import tmat4x4
