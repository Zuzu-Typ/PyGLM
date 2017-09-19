from .setup import *

def _type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")

class tmat2x2:
    def __init__(self, *args):
        self.col_type = self.row_type = tvec2

        if len(args) == 1:
            if isinstance(args[0], tmat2x2) or isinstance(args[0], tmat3x2) or isinstance(args[0], tmat4x2) or\
               isinstance(args[0], tmat2x3) or isinstance(args[0], tmat3x3) or isinstance(args[0], tmat4x3) or\
               isinstance(args[0], tmat2x4) or isinstance(args[0], tmat3x4) or isinstance(args[0], tmat4x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1])]

            elif isinstance(args[0], tvec4):
                self.value = [self.col_type(args[0].xy),
                              self.col_type(args[0].zw)]
                
            elif type(args[0]) in dtypes:
                self.value = [self.col_type(args[0],0),
                              self.col_type(0,args[0])]

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])

        elif len(args) == 2:
            if isinstance(args[0], tvec2) and isinstance(args[1], tvec2):
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1])]

        elif len(args) == 3:
            if isinstance(args[0], tvec2) and type(args[1]) in dtypes and type(args[2]) in dtypes:
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1], args[2])]
            if isinstance(args[2], tvec2) and type(args[0]) in dtypes and type(args[1]) in dtypes:
                self.value = [self.col_type(args[0], args[1]),
                              self.col_type(args[2])]

        elif len(args) == 4:
            for arg in args:
                if not type(arg) in dtypes:
                    raise TypeError("unsupported type {} for tmat2x2()".format(arg))

            self.value = [self.col_type(*args[:2]),
                          self.col_type(*args[2:])]
                
        else:
            self.value = [self.col_type(1,0),
                          self.col_type(0,1)]

    def length():
        return 2
    __len__ = length

    def __eq__(self, value):
        if isinstance(value, tmat2x2):
            return (self[0] == value[0] and self[1] == value[1])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __ne__(self, value):
        if isinstance(value, tmat2x2):
            return (self[0] != value[0] or self[1] != value[1])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __add__(self, value):
        if type(value) in dtypes:
            return tmat2x2(self[0] + value,
                         self[1] + value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] + value[0],
                         self[1] + value[1])
        else:
            try:
                return tmat2x2(self[0] + value[0],
                         self[1] + value[1])
            except:
                raise TypeError("unsupported operand type(s) for +: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        if type(value) in dtypes:
            return tmat2x2(self[0] - value,
                         self[1] - value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] - value[0],
                         self[1] - value[1])
        else:
            try:
                return tmat2x2(self[0] - value[0],
                         self[1] - value[1])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __rsub__(self, value):
        if type(value) in dtypes:
            return tmat2x2(value - self[0],
                         value - self[1])
        elif isinstance(value, tmat2x2):
            return tmat2x2(value[0] - self[0],
                         value[1] - self[1])
        else:
            try:
                return tmat2x2(value[0] - self[0],
                         value[1] - self[1])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __mul__(self, value):
        if type(value) in dtypes:
            return tmat2x2(self[0] * value,
                         self[1] * value)
        elif isinstance(value, self.col_type):
            return tvec2(self[0][0] * value.x + self[1][0] * value.y,
			self[0][1] * value.x + self[1][1] * value.y)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1])
        elif isinstance(value, tmat3x2):
            return tmat3x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1],
			self[0][0] * value[2][0] + self[1][0] * value[2][1],
			self[0][1] * value[2][0] + self[1][1] * value[2][1])
        elif isinstance(value, tmat4x2):
            return tmat4x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1],
			self[0][0] * value[2][0] + self[1][0] * value[2][1],
			self[0][1] * value[2][0] + self[1][1] * value[2][1],
			self[0][0] * value[3][0] + self[1][0] * value[3][1],
			self[0][1] * value[3][0] + self[1][1] * value[3][1])
        else:
            try:
                return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __rmul__(self, value):
        if type(value) in dtypes:
            return tmat2x2(self[0] * value,
                         self[1] * value)
        elif isinstance(value, self.row_type):
            return tvec2(v.x * m[0][0] + v.y * m[0][1],
			v.x * m[1][0] + v.y * m[1][1])
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1])
        elif isinstance(value, tmat3x2):
            return tmat3x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1],
			self[0][0] * value[2][0] + self[1][0] * value[2][1],
			self[0][1] * value[2][0] + self[1][1] * value[2][1])
        elif isinstance(value, tmat4x2):
            return tmat4x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1],
			self[0][0] * value[2][0] + self[1][0] * value[2][1],
			self[0][1] * value[2][0] + self[1][1] * value[2][1],
			self[0][0] * value[3][0] + self[1][0] * value[3][1],
			self[0][1] * value[3][0] + self[1][1] * value[3][1])
        else:
            try:
                return tmat2x2(self[0][0] * value[0][0] + self[1][0] * value[0][1],
			self[0][1] * value[0][0] + self[1][1] * value[0][1],
			self[0][0] * value[1][0] + self[1][0] * value[1][1],
			self[0][1] * value[1][0] + self[1][1] * value[1][1])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __truediv__(self, value):
        if type(value) in dtypes:
            value = float(value)
            return tmat2x2(self[0] / value,
                         self[1] / value)
        elif isinstance(value, tvec2):
            return inverse(self) * value
        elif isinstance(value, tmat2x2):
            return self * inverse(value)
        else:
            try:
                return self * inverse(value)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    def __rtruediv__(self, value):
        if type(value) in dtypes:
            value = float(value)
            return tmat2x2(value / self[0],
                         value / self[1])
        elif isinstance(value, tvec2):
            return value * inverse(self)
        elif isinstance(value, tmat2x2):
            return inverse(self) * value
        else:
            try:
                return value * inverse(self)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in dtypes:
            self[0] += value
            self[1] += value
        elif isinstance(value, tmat2x2):
            self[0] += value[0]
            self[1] += value[1]
        else:
            try:
                self[0] += value[0]
                self[1] += value[1]
            except:
                raise TypeError("unsupported operand type(s) for +=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
        return self

    def __isub__(self, value):
        if type(value) in dtypes:
            self[0] -= value
            self[1] -= value
        elif isinstance(value, tmat2x2):
            self[0] -= value[0]
            self[1] -= value[1]
        else:
            try:
                self[0] -= value[0]
                self[1] -= value[1]
            except:
                raise TypeError("unsupported operand type(s) for -=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
        return self

    def __imul__(self, value):
        if type(value) in dtypes:
            self[0] *= value
            self[1] *= value
        elif isinstance(value, tmat2x2):
            self.value = (self * value).value
        else:
            try:
                self[0] *= value[0]
                self[1] *= value[1]
            except:
                raise TypeError("unsupported operand type(s) for *=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
        return self

    def __itruediv__(self, value):
        if type(value) in dtypes:
            self[0] /= float(value)
            self[1] /= float(value)
        elif isinstance(value, tmat2x2):
            self *= inverse(value)
        else:
            try:
                self *= inverse(value)
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
        return self

    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat2x2(-self[0],
                     -self[1])

    def __abs__(self):
        return tmat2x2(abs(self[0]),
                     abs(self[1]))

    def __invert__(self):
        return invert(self)

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat2x2 doesn't support slices")
        else:
            if key in (0,-2):
                return self.value[0]
            elif key in (1,-1):
                return self.value[1]
            else:
                raise IndexError("tmat2x2 index out of range")

    def __setitem__(self, key, value):
        if type(key) == slice:
            raise TypeError("tmat2x2 doesn't support slices")
        else:
            if key in (0,-2):
                self.value[0] = value
            elif key in (1,-1):
                self.value[1] = value
            else:
                raise IndexError("tmat2x2 index out of range")

    def __str__(self):
        return "tmat2x2( {}, {},\n         {}, {} )".format(self.value[0][0], self.value[0][1], self.value[1][0], self.value[1][1])

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
