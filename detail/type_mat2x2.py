from .setup import *

from .type_vec2 import tvec2
from .type_vec4 import tvec4

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
                
            elif type(args[0]) in (int, long, float):
                self.value = [self.col_type(args[0],0),
                              self.col_type(0,args[0])]

            elif type(args[0]) in (tuple, list, set):
                self.__init__(*args[0])

        elif len(args) == 2:
            if isinstance(args[0], tvec2) and isinstance(args[1], tvec2):
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1])]

        elif len(args) == 3:
            if isinstance(args[0], tvec2) and type(args[1]) in (int, long, float, bool) and type(args[2]) in (int, long, float, bool):
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1], args[2])]
            if isinstance(args[2], tvec2) and type(args[0]) in (int, long, float, bool) and type(args[1]) in (int, long, float, bool):
                self.value = [self.col_type(args[0], args[1]),
                              self.col_type(args[2])]

        elif len(args) == 4:
            if not type(args[0]) in (int, long, float, bool):
                raise TypeError("unsupported type {} for tmat2x2()".format(args[0]))
            if not type(args[1]) in (int, long, float, bool):
                raise TypeError("unsupported type {} for tmat2x2()".format(args[1]))
            if not type(args[2]) in (int, long, float, bool):
                raise TypeError("unsupported type {} for tmat2x2()".format(args[2]))
            if not type(args[3]) in (int, long, float, bool):
                raise TypeError("unsupported type {} for tmat2x2()".format(args[3]))

            self.value = [self.col_type(args[0], args[1]),
                          self.col_type(args[2], args[3])]
                
        else:
            self.value = [self.col_type(1,0),
                          self.col_type(0,1)]

    def __add__(self, value):
        if type(value) in (int, float, long):
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
        if type(value) in (int, float, long):
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

    __rsub__ = __sub__

    def __mul__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] * value,
                         self[1] * value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] * value[0],
                         self[1] * value[1])
        else:
            try:
                return tmat2x2(self[0] * value[0],
                         self[1] * value[1])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rmul__ = __mul__

    def __truediv__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] / value,
                         self[1] / value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] / value[0],
                         self[1] / value[1])
        else:
            try:
                return tmat2x2(self[0] / value[0],
                         self[1] / value[1])
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rtruediv__ = __truediv__

    def __div__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] / float(value),
                         self[1] / float(value))
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] / float(value[0]),
                         self[1] / float(value[1]))
        else:
            try:
                return tmat2x2(self[0] / float(value[0]),
                         self[1] / float(value[1]))
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rdiv__ = __div__

    def __floordiv__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] // value,
                         self[1] // value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] // value[0],
                         self[1] // value[1])
        else:
            try:
                return tmat2x2(self[0] // value[0],
                         self[1] // value[1])
            except:
                raise TypeError("unsupported operand type(s) for //: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rfloordiv__ = __floordiv__

    def __mod__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] % value,
                         self[1] % value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] % value[0],
                         self[1] % value[1])
        else:
            try:
                return tmat2x2(self[0] % value[0],
                         self[1] % value[1])
            except:
                raise TypeError("unsupported operand type(s) for %: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rmod__ = __mod__

    def __pow__(self, value, modulo=None):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] ** value,
                         self[1] ** value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] ** value[0],
                         self[1] ** value[1])
        else:
            try:
                return tmat2x2(self[0] ** value[0],
                         self[1] ** value[1])
            except:
                raise TypeError("unsupported operand type(s) for pow: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rpow__ = __pow__

    def __lshift__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] << value,
                         self[1] << value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] << value[0],
                         self[1] << value[1])
        else:
            try:
                return tmat2x2(self[0] << value[0],
                         self[1] << value[1])
            except:
                raise TypeError("unsupported operand type(s) for <<: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rlshift__ = __lshift__

    def __rshift__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] >> value,
                         self[1] >> value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] >> value[0],
                         self[1] >> value[1])
        else:
            try:
                return tmat2x2(self[0] >> value[0],
                         self[1] >> value[1])
            except:
                raise TypeError("unsupported operand type(s) for >>: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rrshift__ = __rshift__

    def __and__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] & value,
                         self[1] & value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] & value[0],
                         self[1] & value[1])
        else:
            try:
                return tmat2x2(self[0] & value[0],
                         self[1] & value[1])
            except:
                raise TypeError("unsupported operand type(s) for &: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rand__ = __and__

    def __or__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] | value,
                         self[1] | value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] | value[0],
                         self[1] | value[1])
        else:
            try:
                return tmat2x2(self[0] | value[0],
                         self[1] | value[1])
            except:
                raise TypeError("unsupported operand type(s) for |: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __or__ = __or__

    def __xor__(self, value):
        if type(value) in (int, float, long):
            return tmat2x2(self[0] ^ value,
                         self[1] ^ value)
        elif isinstance(value, tmat2x2):
            return tmat2x2(self[0] ^ value[0],
                         self[1] ^ value[1])
        else:
            try:
                return tmat2x2(self[0] ^ value[0],
                         self[1] ^ value[1])
            except:
                raise TypeError("unsupported operand type(s) for ^: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

    __rxor__ = __xor__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in (int, float, long):
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

    def __isub__(self, value):
        if type(value) in (int, float, long):
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

    def __imul__(self, value):
        if type(value) in (int, float, long):
            self[0] *= value
            self[1] *= value
        else:
            self.value = (self * value).value
##
    def __itruediv__(self, value):
        if type(value) in (int, float, long):
            self[0] /= value
            self[1] /= value
        else:
            self.value = (self / value).value
##
    def __idiv__(self, value):
        if type(value) in (int, float, long):
            self[0] /= value
            self[1] /= value
        elif isinstance(value, tmat2x2):
            self.value = (self / value).value

    def __ifloordiv__(self, value):
        if type(value) in (int, float, long):
            self[0] //= value
            self[1] //= value
        else:
            self.value = (self // value).value
##
##    def __imod__(self, value):
##        if type(value) in (int, float, long):
##            self[0] %= value
##            self[1] %= value
##        elif isinstance(value, tmat2x2):
##            self[0] %= value[0]
##            self[1] %= value[1]
##        else:
##            try:
##                self[0] %= value[0]
##                self[1] %= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for %=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
##
##    def __ipow__(self, value, opt=None):
##        if type(value) in (int, float, long):
##            self[0] **= value
##            self[1] **= value
##        elif isinstance(value, tmat2x2):
##            self[0] **= value[0]
##            self[1] **= value[1]
##        else:
##            try:
##                self[0] **= value[0]
##                self[1] **= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for **=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
##
##    def __ilshift__(self, value):
##        if type(value) in (int, float, long):
##            self[0] <<= value
##            self[1] <<= value
##        elif isinstance(value, tmat2x2):
##            self[0] <<= value[0]
##            self[1] <<= value[1]
##        else:
##            try:
##                self[0] <<= value[0]
##                self[1] <<= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for <<=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
##
##    def __irshift__(self, value):
##        if type(value) in (int, float, long):
##            self[0] >>= value
##            self[1] >>= value
##        elif isinstance(value, tmat2x2):
##            self[0] >>= value[0]
##            self[1] >>= value[1]
##        else:
##            try:
##                self[0] >>= value[0]
##                self[1] >>= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for >>=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
##
##    def __iand__(self, value):
##        if type(value) in (int, float, long):
##            self[0] &= value
##            self[1] &= value
##        elif isinstance(value, tmat2x2):
##            self[0] &= value[0]
##            self[1] &= value[1]
##        else:
##            try:
##                self[0] &= value[0]
##                self[1] &= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for &=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
##
##    def __ior__(self, value):
##        if type(value) in (int, float, long):
##            self[0] |= value
##            self[1] |= value
##        elif isinstance(value, tmat2x2):
##            self[0] |= value[0]
##            self[1] |= value[1]
##        else:
##            try:
##                self[0] |= value[0]
##                self[1] |= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for |=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))
##
##    def __ixor__(self, value):
##        if type(value) in (int, float, long):
##            self[0] ^= value
##            self[1] ^= value
##        elif isinstance(value, tmat2x2):
##            self[0] ^= value[0]
##            self[1] ^= value[1]
##        else:
##            try:
##                self[0] ^= value[0]
##                self[1] ^= value[1]
##            except:
##                raise TypeError("unsupported operand type(s) for ^=: 'tmat2x2' and '{}'".format(_type_to_str(type(value))))

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

##from .func_matrix import *
