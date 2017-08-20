from .setup import *

import sys

def _type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")

def _unswizzle(swizzle):
    return swizzle.replace("r","x").replace("s", "x").replace("g", "y").replace("t", "y").replace("b", "z").replace("p", "z").replace("a", "w").replace("q", "w")

class tvec3:
    def __init__(self, *args):
        if len(args) == 1:
            # from tvec
            if isinstance(args[0], tvec3) or isinstance(args[0], tvec4):
                self.x = args[0].x
                self.y = args[0].y
                self.z = args[0].z

            elif type(args[0]) in (tuple, list, set):
                self.__init__(*args[0])

        elif len(args) == 2:
            # check types
            if isinstance(args[0], tvec2):
                if not type(args[1]) in (int, long, bool, float):
                    raise TypeError("expected int or float values, got {}".format(type(args[1])))
                self.x = args[0].x
                self.y = args[0].y
                self.z = args[1]
            elif isinstance(args[1], tvec2):
                if not type(args[0]) in (int, long, bool, float):
                    raise TypeError("expected int or float values, got {}".format(type(args[0])))
                self.x = args[0]
                self.y = args[1].x
                self.z = args[1].y
            else:
                raise TypeError("expected tvec2 and int or float values, got {} and {}".format(type(args[0]), type(args[1])))

        elif len(args) == 3:
            if not type(args[0]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[0])))
            if not type(args[1]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[1])))
            if not type(args[2]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[2])))
            self.x, self.y, self.z = args

        elif len(args) > 3:
            raise TypeError("tvec3 takes at most 3 arguments, got {}".format(len(args)))

        else:
            self.x = self.y = self.z = 0

    def length(self):
        return 3

    __len__ = length

##    def __lt__(self, value):
##        if type(value) in (int, float, long, bool):
##            return (self.x < value and self.y < value and self.z < value)
##        elif isinstance(value, tvec3):
##            return (self.x < value.x and self.y < value.y and self.z < value.z)
##        else:
##            try:
##                return (self.x < value[0] and self.y < value[1] and self.z < value[2])
##            except:
##                raise TypeError("unsupported operand type(s) for <: 'tvec3' and '{}'".format(_type_to_str(type(value))))
##
##    def __le__(self, value):
##        if type(value) in (int, float, long, bool):
##            return (self.x <= value and self.y <= value and self.z <= value)
##        elif isinstance(value, tvec3):
##            return (self.x <= value.x and self.y <= value.y and self.z <= value.z)
##        else:
##            try:
##                return (self.x <= value[0] and self.y <= value[1] and self.z <= value[2])
##            except:
##                raise TypeError("unsupported operand type(s) for <=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __eq__(self, value):
        if type(value) in (int, float, long, bool):
            return (self.x == value and self.y == value and self.z == value)
        elif isinstance(value, tvec3):
            return (self.x == value.x and self.y == value.y and self.z == value.z)
        else:
            try:
                return (self.x == value[0] and self.y == value[1] and self.z == value[2])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __ne__(self, value):
        if type(value) in (int, float, long, bool):
            return (self.x != value and self.y != value and self.z != value)
        elif isinstance(value, tvec3):
            return (self.x != value.x and self.y != value.y and self.z != value.z)
        else:
            try:
                return (self.x != value[0] and self.y != value[1] and self.z != value[2])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

##    def __gt__(self, value):
##        if type(value) in (int, float, long, bool):
##            return (self.x < value and self.y < value and self.z < value)
##        elif isinstance(value, tvec3):
##            return (self.x < value.x and self.y < value.y and self.z < value.z)
##        else:
##            try:
##                return (self.x < value[0] and self.y < value[1] and self.z < value[2])
##            except:
##                raise TypeError("unsupported operand type(s) for >: 'tvec3' and '{}'".format(_type_to_str(type(value))))
##
##    def __ge__(self, value):
##        if type(value) in (int, float, long, bool):
##            return (self.x < value and self.y < value and self.z < value)
##        elif isinstance(value, tvec3):
##            return (self.x < value.x and self.y < value.y and self.z < value.z)
##        else:
##            try:
##                return (self.x < value[0] and self.y < value[1] and self.z < value[2])
##            except:
##                raise TypeError("unsupported operand type(s) for >=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __add__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x + value,
                         self.y + value,
                         self.z + value)
        elif isinstance(value, tvec3):
            return tvec3(self.x + value.x,
                         self.y + value.y,
                         self.z + value.z)
        else:
            try:
                return tvec3(self.x + value[0],
                         self.y + value[1],
                             self.z + value[2])
            except:
                raise TypeError("unsupported operand type(s) for +: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x - value,
                         self.y - value,
                         self.z - value)
        elif isinstance(value, tvec3):
            return tvec3(self.x - value.x,
                         self.y - value.y,
                         self.z - value.z)
        else:
            try:
                return tvec3(self.x - value[0],
                         self.y - value[1],
                             self.z - value[2])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rsub__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(value - self.x,
                         value - self.y,
                         value - self.z)
        elif isinstance(value, tvec3):
            return tvec3(value.x - self.x,
                         value.y - self.y,
                         value.z - self.z)
        else:
            try:
                return tvec3(value[0] - self[0],
                         value[1] - self[1],
                             value[2] - self[2])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __mul__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x * value,
                         self.y * value,
                         self.z * value)
        elif isinstance(value, tvec3):
            return tvec3(self.x * value.x,
                         self.y * value.y,
                         self.z * value.z)
        else:
            try:
                return tvec3(self.x * value[0],
                         self.y * value[1],
                             self.z * value[2])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    __rmul__ = __mul__

    def __truediv__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x / value,
                         self.y / value,
                         self.z / value)
        elif isinstance(value, tvec3):
            return tvec3(self.x / float(value.x),
                         self.y / float(value.y),
                         self.z / float(value.z))
        else:
            try:
                return tvec3(self.x / float(value[0]),
                         self.y / float(value[1]),
                             self.z / float(value[2]))
            except:
                raise TypeError("unsupported operand type(s) for /: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rtruediv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tvec3(value / self.x,
                         value / self.y,
                         value / self.z)
        elif isinstance(value, tvec3):
            return tvec3(float(value.x) / self.x,
                         float(value.y) / self.y,
                         float(value.z) / self.z)
        else:
            try:
                return tvec3(float(value[0]) / self[0],
                         float(value[1]) / self[1],
                             float(value[2]) / self[2])
            except:
                raise TypeError("unsupported operand type(s) for /: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    def __floordiv__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x // value,
                         self.y // value,
                         self.z // value)
        elif isinstance(value, tvec3):
            return tvec3(self.x // value.x,
                         self.y // value.y,
                         self.z // value.z)
        else:
            try:
                return tvec3(self.x // value[0],
                         self.y // value[1],
                             self.z // value[2])
            except:
                raise TypeError("unsupported operand type(s) for //: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rfloordiv__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(value // self.x,
                         value // self.y,
                         value // self.z)
        elif isinstance(value, tvec3):
            return tvec3(value.x // self.x,
                         value.y // self.y,
                         value.z // self.z)
        else:
            try:
                return tvec3(value[0] // self[0],
                         value[1] // self[1],
                             value[2] // self[2])
            except:
                raise TypeError("unsupported operand type(s) for //: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __mod__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x % value,
                         self.y % value,
                         self.z % value)
        elif isinstance(value, tvec3):
            return tvec3(self.x % value.x,
                         self.y % value.y,
                         self.z % value.z)
        else:
            try:
                return tvec3(self.x % value[0],
                         self.y % value[1],
                             self.z % value[2])
            except:
                raise TypeError("unsupported operand type(s) for %: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rmod__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(value % self.x,
                         value % self.y,
                         value % self.z)
        elif isinstance(value, tvec3):
            return tvec3(value.x % self.x,
                         value.y % self.y,
                         value.z % self.z)
        else:
            try:
                return tvec3(value[0] % self[0],
                         value[1] % self[1],
                             value[2] % self[2])
            except:
                raise TypeError("unsupported operand type(s) for %: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __pow__(self, value, modulo=None):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x ** value,
                         self.y ** value,
                         self.z ** value)
        elif isinstance(value, tvec3):
            return tvec3(self.x ** value.x,
                         self.y ** value.y,
                         self.z ** value.z)
        else:
            try:
                return tvec3(self.x ** value[0],
                         self.y ** value[1],
                             self.z ** value[2])
            except:
                raise TypeError("unsupported operand type(s) for pow: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rpow__(self, value, modulo=None):
        if type(value) in (int, float, long, bool):
            return tvec3(value ** self.x,
                         value ** self.y,
                         value ** self.z)
        elif isinstance(value, tvec3):
            return tvec3(value.x ** self.x,
                         value.y ** self.y,
                         value.z ** self.z)
        else:
            try:
                return tvec3(value[0] ** self[0],
                         value[1] ** self[1],
                             value[2] ** self[2])
            except:
                raise TypeError("unsupported operand type(s) for pow: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __lshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x << value,
                         self.y << value,
                         self.z << value)
        elif isinstance(value, tvec3):
            return tvec3(self.x << value.x,
                         self.y << value.y,
                         self.z << value.z)
        else:
            try:
                return tvec3(self.x << value[0],
                         self.y << value[1],
                             self.z << value[2])
            except:
                raise TypeError("unsupported operand type(s) for <<: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rlshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(value << self.x,
                         value << self.y,
                         value << self.z)
        elif isinstance(value, tvec3):
            return tvec3(value.x << self.x,
                         value.y << self.y,
                         value.z << self.z)
        else:
            try:
                return tvec3(value[0] << self[0],
                         value[1] << self[1],
                             value[2] << self[2])
            except:
                raise TypeError("unsupported operand type(s) for <<: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x >> value,
                         self.y >> value,
                         self.z >> value)
        elif isinstance(value, tvec3):
            return tvec3(self.x >> value.x,
                         self.y >> value.y,
                         self.z >> value.z)
        else:
            try:
                return tvec3(self.x >> value[0],
                         self.y >> value[1],
                             self.z >> value[2])
            except:
                raise TypeError("unsupported operand type(s) for >>: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __rrshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(value >> self.x,
                         value >> self.y,
                         value >> self.z)
        elif isinstance(value, tvec3):
            return tvec3(value.x >> self.x,
                         value.y >> self.y,
                         value.z >> self.z)
        else:
            try:
                return tvec3(value[0] >> self[0],
                         value[1] >> self[1],
                             value[2] >> self[2])
            except:
                raise TypeError("unsupported operand type(s) for >>: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __and__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x & value,
                         self.y & value,
                         self.z & value)
        elif isinstance(value, tvec3):
            return tvec3(self.x & value.x,
                         self.y & value.y,
                         self.z & value.z)
        else:
            try:
                return tvec3(self.x & value[0],
                         self.y & value[1],
                             self.z & value[2])
            except:
                raise TypeError("unsupported operand type(s) for &: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    __rand__ = __and__

    def __or__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x | value,
                         self.y | value,
                         self.z | value)
        elif isinstance(value, tvec3):
            return tvec3(self.x | value.x,
                         self.y | value.y,
                         self.z | value.z)
        else:
            try:
                return tvec3(self.x | value[0],
                         self.y | value[1],
                             self.z | value[2])
            except:
                raise TypeError("unsupported operand type(s) for |: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    __or__ = __or__

    def __xor__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec3(self.x ^ value,
                         self.y ^ value,
                         self.z ^ value)
        elif isinstance(value, tvec3):
            return tvec3(self.x ^ value.x,
                         self.y ^ value.y,
                         self.z ^ value.z)
        else:
            try:
                return tvec3(self.x ^ value[0],
                         self.y ^ value[1],
                             self.z ^ value[2])
            except:
                raise TypeError("unsupported operand type(s) for ^: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    __rxor__ = __xor__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in (int, float, long, bool):
            self.x += value
            self.y += value
            self.z += value
        elif isinstance(value, tvec3):
            self.x += value.x
            self.y += value.y
            self.z += value.z
        else:
            try:
                self.x += value[0]
                self.y += value[1]
                self.z += value[2]
            except:
                raise TypeError("unsupported operand type(s) for +=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __isub__(self, value):
        if type(value) in (int, float, long, bool):
            self.x -= value
            self.y -= value
            self.z -= value
        elif isinstance(value, tvec3):
            self.x -= value.x
            self.y -= value.y
            self.z -= value.z
        else:
            try:
                self.x -= value[0]
                self.y -= value[1]
                self.z -= value[2]
            except:
                raise TypeError("unsupported operand type(s) for -=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __imul__(self, value):
        if type(value) in (int, float, long, bool):
            self.x *= value
            self.y *= value
            self.z *= value
        elif isinstance(value, tvec3):
            self.x *= value.x
            self.y *= value.y
            self.z *= value.z
        else:
            try:
                self.x *= value[0]
                self.y *= value[1]
                self.z *= value[2]
            except:
                raise TypeError("unsupported operand type(s) for *=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __itruediv__(self, value):
        if type(value) in (int, float, long, bool):
            self.x /= value
            self.y /= value
            self.z /= value
        elif isinstance(value, tvec3):
            self.x /= value.x
            self.y /= value.y
            self.z /= value.z
        else:
            try:
                self.x /= value[0]
                self.y /= value[1]
                self.z /= value[2]
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __idiv__(self, value):
        if type(value) in (int, float, long, bool):
            self.x /= value
            self.y /= value
            self.z /= value
        elif isinstance(value, tvec3):
            self.x /= value.x
            self.y /= value.y
            self.z /= value.z
        else:
            try:
                self.x /= value[0]
                self.y /= value[1]
                self.z /= value[2]
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __ifloordiv__(self, value):
        if type(value) in (int, float, long, bool):
            self.x //= value
            self.y //= value
            self.z //= value
        elif isinstance(value, tvec3):
            self.x //= value.x
            self.y //= value.y
            self.z //= value.z
        else:
            try:
                self.x //= value[0]
                self.y //= value[1]
                self.z //= value[2]
            except:
                raise TypeError("unsupported operand type(s) for //=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __imod__(self, value):
        if type(value) in (int, float, long, bool):
            self.x %= value
            self.y %= value
            self.z %= value
        elif isinstance(value, tvec3):
            self.x %= value.x
            self.y %= value.y
            self.z %= value.z
        else:
            try:
                self.x %= value[0]
                self.y %= value[1]
                self.z %= value[2]
            except:
                raise TypeError("unsupported operand type(s) for %=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __ipow__(self, value, opt=None):
        if type(value) in (int, float, long, bool):
            self.x **= value
            self.y **= value
            self.z **= value
        elif isinstance(value, tvec3):
            self.x **= value.x
            self.y **= value.y
            self.z **= value.z
        else:
            try:
                self.x **= value[0]
                self.y **= value[1]
                self.z **= value[2]
            except:
                raise TypeError("unsupported operand type(s) for **=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __ilshift__(self, value):
        if type(value) in (int, float, long, bool):
            self.x <<= value
            self.y <<= value
            self.z <<= value
        elif isinstance(value, tvec3):
            self.x <<= value.x
            self.y <<= value.y
            self.z <<= value.z
        else:
            try:
                self.x <<= value[0]
                self.y <<= value[1]
                self.z <<= value[2]
            except:
                raise TypeError("unsupported operand type(s) for <<=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __irshift__(self, value):
        if type(value) in (int, float, long, bool):
            self.x >>= value
            self.y >>= value
            self.z >>= value
        elif isinstance(value, tvec3):
            self.x >>= value.x
            self.y >>= value.y
            self.z >>= value.z
        else:
            try:
                self.x >>= value[0]
                self.y >>= value[1]
                self.z >>= value[2]
            except:
                raise TypeError("unsupported operand type(s) for >>=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __iand__(self, value):
        if type(value) in (int, float, long, bool):
            self.x &= value
            self.y &= value
            self.z &= value
        elif isinstance(value, tvec3):
            self.x &= value.x
            self.y &= value.y
            self.z &= value.z
        else:
            try:
                self.x &= value[0]
                self.y &= value[1]
                self.z &= value[2]
            except:
                raise TypeError("unsupported operand type(s) for &=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __ior__(self, value):
        if type(value) in (int, float, long, bool):
            self.x |= value
            self.y |= value
            self.z |= value
        elif isinstance(value, tvec3):
            self.x |= value.x
            self.y |= value.y
            self.z |= value.z
        else:
            try:
                self.x |= value[0]
                self.y |= value[1]
                self.z |= value[2]
            except:
                raise TypeError("unsupported operand type(s) for |=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __ixor__(self, value):
        if type(value) in (int, float, long, bool):
            self.x ^= value
            self.y ^= value
            self.z ^= value
        elif isinstance(value, tvec3):
            self.x ^= value.x
            self.y ^= value.y
            self.z ^= value.z
        else:
            try:
                self.x ^= value[0]
                self.y ^= value[1]
                self.z ^= value[2]
            except:
                raise TypeError("unsupported operand type(s) for ^=: 'tvec3' and '{}'".format(_type_to_str(type(value))))

    def __pos__(self):
        return self

    def __neg__(self):
        return tvec3(-self.x,
                     -self.y,
                     -self.z)

    def __abs__(self):
        return tvec3(abs(self.x),
                     abs(self.y),
                     abs(self.z))

    def __invert__(self):
        return tvec3(~self.x,
                     ~self.y,
                     ~self.z)

    def __bool__(self):
        return (bool(self.x), bool(self.y), bool(self.z))

    __nonzero__ = __bool__

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tvec3 doesn't support slices")
        else:
            if key in (0,-3):
                return self.x
            elif key in (1,-2):
                return self.y
            elif key in (2,-1):
                return self.z
            else:
                raise IndexError("tvec3 index out of range")

    def __setitem__(self, key, value):
        if type(key) == slice:
            raise TypeError("tvec3 doesn't support slices")
        else:
            if key in (0,-3):
                self.x = value
            elif key in (1,-2):
                self.y = value
            elif key in (2,-1):
                self.z = value
            else:
                raise IndexError("tvec3 index out of range")

    def __getattr__(self, name):
        if name.startswith('__') and name.endswith('__'):
            raise AttributeError(name)

        if len(name) == 1:
            if name in "xrs":
                return self.x
            if name in "ygt":
                return self.y
            if name in "zbp":
                return self.z

        if len(name) == 2:
            for char in name:
                if not char in "xrsygtzbp":
                    raise AttributeError(name)
            return tvec2(self.x if name[0] in "xrs" else self.y if name[0] in "ygt" else self.z,
                         self.x if name[1] in "xrs" else self.y if name[1] in "ygt" else self.z)

        if len(name) == 3:
            for char in name:
                if not char in "xrsygtzbp":
                    raise AttributeError(name)
            return tvec3(self.x if name[0] in "xrs" else self.y if name[0] in "ygt" else self.z,
                         self.x if name[1] in "xrs" else self.y if name[1] in "ygt" else self.z,
                         self.x if name[2] in "xrs" else self.y if name[2] in "ygt" else self.z)

        if len(name) == 4:
            for char in name:
                if not char in "xrsygtzbp":
                    raise AttributeError(name)
            return tvec4(self.x if name[0] in "xrs" else self.y if name[0] in "ygt" else self.z,
                         self.x if name[1] in "xrs" else self.y if name[1] in "ygt" else self.z,
                         self.x if name[2] in "xrs" else self.y if name[2] in "ygt" else self.z,
                         self.x if name[3] in "xrs" else self.y if name[3] in "ygt" else self.z)

        raise AttributeError(name)

    def __setattr__(self, name, value):
        if name.startswith('__') and name.endswith('__'):
            raise AttributeError(name)

        if len(name) == 1:
            if name in "xrs":
                self.__dict__["x"] = value
            if name in "ygt":
                self.__dict__["y"] = value
            if name in "zbp":
                self.__dict__["z"] = value

        elif _unswizzle(name) == "xy":
            if isinstance(value, tvec2) or (type(value) in (tuple, list, set) and len(value) == 2):
                self.__dict__["x"] = value[0]
                self.__dict__["y"] = value[1]
            else:
                raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
                
        elif _unswizzle(name) == "xyz":
            if isinstance(value, tvec3) or isinstance(value, tvec4) or (type(value) in (tuple, list, set) and len(value) <= 4):
                self.__dict__["x"] = value[0]
                self.__dict__["y"] = value[1]
                self.__dict__["z"] = value[2]
            else:
                raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
        else:
            try:
                for char in name:
                    if not char in "xrsygt":
                        raise AttributeError(name)
                raise AttributeError("swizzle operators do not support setattr")
            except AttributeError:
                self.__dict__[name] = value

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        return "tvec3( {} , {} , {} )".format(self.x, self.y, self.z)

from .type_vec2 import tvec2
from .type_vec4 import tvec4
