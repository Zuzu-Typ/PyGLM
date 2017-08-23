from .setup import *

import sys

def _type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")

def _unswizzle(swizzle):
    return swizzle.replace("r","x").replace("s", "x").replace("g", "y").replace("t", "y").replace("b", "z").replace("p", "z").replace("a", "w").replace("q", "w")

class tvec4:
    def __init__(self, *args):
        if len(args) == 1:
            # from tvec
            if type(args[0]) in (int, long, float, bool):
                self.x = self.y = self.z = self.w = args[0]
            elif isinstance(args[0], tvec4):
                self.x = args[0].x
                self.y = args[0].y
                self.z = args[0].z
                self.w = args[0].w

            elif type(args[0]) in (tuple, list, set):
                self.__init__(*args[0])

        elif len(args) == 2:
            # check types
            if isinstance(args[0], tvec2):
                if not isinstance(args[1], tvec2):
                    raise TypeError("expected a pair of tvec2, got tvec2 and {}".format(type(args[1])))
                self.x = args[0].x
                self.y = args[0].y
                self.z = args[1].x
                self.w = args[1].y
            elif isinstance(args[0], tvec3):
                if not type(args[1]) in (int, long, bool, float):
                    raise TypeError("expected int or float values, got {}".format(type(args[1])))
                self.x = args[0].x
                self.y = args[0].y
                self.z = args[0].z
                self.w = args[1]
            elif type(args[0]) in (int, long, bool, float):
                if not isinstance(args[1], tvec3):
                    raise TypeError("expected tvec3, got {}".format(type(args[1])))
                self.x = args[0]
                self.y = args[1].x
                self.z = args[1].y
                self.w = args[1].z
            else:
                raise TypeError("expected a total of four values using tvec2, tvec3, int or float, got {} and {}".format(type(args[0]), type(args[1])))

        elif len(args) == 3:
            # check types
            if isinstance(args[0], tvec2):
                if not type(args[1]) in (int, long, bool, float):
                    raise TypeError("expected a total of four values using tvec2, int or float, got tvec2, {} and {}".format(type(args[0]), type(args[1]), type(args[2])))
                if not type(args[2]) in (int, long, bool, float):
                    raise TypeError("expected a total of four values using tvec2, int or float, got tvec2, {} and {}".format(type(args[0]), type(args[1]), type(args[2])))
                self.x = args[0].x
                self.y = args[0].y
                self.z = args[1]
                self.w = args[2]
                
            elif isinstance(args[1], tvec2):
                if not type(args[0]) in (int, long, bool, float):
                    raise TypeError("expected a total of four values using tvec2, int or float, got {}, tvec2 and {}".format(type(args[0]), type(args[2])))
                if not type(args[2]) in (int, long, bool, float):
                    raise TypeError("expected a total of four values using tvec2, int or float, got {}, tvec2 and {}".format(type(args[0]), type(args[2])))
                self.x = args[0]
                self.y = args[1].x
                self.z = args[1].y
                self.w = args[2]
                
            elif isinstance(args[2], tvec2):
                if not type(args[0]) in (int, long, bool, float):
                    raise TypeError("expected a total of four values using tvec2, int or float, got {}, {} and tvec2".format(type(args[0]), type(args[1])))
                if not type(args[1]) in (int, long, bool, float):
                    raise TypeError("expected a total of four values using tvec2, int or float, got {}, {} and tvec2".format(type(args[0]), type(args[1])))
                self.x = args[0]
                self.y = args[1]
                self.z = args[2].x
                self.w = args[2].y
            else:
                raise TypeError("expected a total of four values using tvec2, int or float, got {}, {} and {}".format(type(args[0]), type(args[1]), type(args[2])))

        elif len(args) == 4:
            if not type(args[0]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[0])))
            if not type(args[1]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[1])))
            if not type(args[2]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[2])))
            if not type(args[3]) in (int, long, bool, float):
                raise TypeError("expected int or float values, got {}".format(type(args[2])))
            self.x, self.y, self.z, self.w = args

        elif len(args) > 4:
            raise TypeError("tvec4 takes at most 4 arguments, got {}".format(len(args)))

        else:
            self.x = self.y = self.z = self.w = 0

    def length(self):
        return 4

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
            return (self.x == value and self.y == value and self.z == value and self.w == value)
        elif isinstance(value, tvec4):
            return (self.x == value.x and self.y == value.y and self.z == value.z and self.w == value.w)
        else:
            try:
                return (self.x == value[0] and self.y == value[1] and self.z == value[2] and self.w == value[3])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __ne__(self, value):
        if type(value) in (int, float, long, bool):
            return (self.x != value and self.y != value and self.z != value and self.w != value)
        elif isinstance(value, tvec4):
            return (self.x != value.x and self.y != value.y and self.z != value.z and self.w != value.w)
        else:
            try:
                return (self.x != value[0] and self.y != value[1] and self.z != value[2] and self.w != value[2])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tvec4' and '{}'".format(_type_to_str(type(value))))

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
            return tvec4(self.x + value,
                         self.y + value,
                         self.z + value,
                         self.w + value)
        elif isinstance(value, tvec4):
            return tvec4(self.x + value.x,
                         self.y + value.y,
                         self.z + value.z,
                         self.w + value.w)
        else:
            try:
                return tvec4(self.x + value[0],
                         self.y + value[1],
                             self.z + value[2],
                             self.w + value[3])
            except:
                raise TypeError("unsupported operand type(s) for +: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x - value,
                         self.y - value,
                         self.z - value,
                         self.w - value)
        elif isinstance(value, tvec4):
            return tvec4(self.x - value.x,
                         self.y - value.y,
                         self.z - value.z,
                         self.w - value.w)
        else:
            try:
                return tvec4(self.x - value[0],
                         self.y - value[1],
                             self.z - value[2],
                             self.w - value[3])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rsub__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(value - self.x,
                         value - self.y,
                         value - self.z,
                         value - self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x - self.x,
                         value.y - self.y,
                         value.z - self.z,
                         value.w - self.w)
        else:
            try:
                return tvec4(value[0] - self[0],
                         value[1] - self[1],
                             value[2] - self[2],
                             value[3] - self[3])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __mul__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x * value,
                         self.y * value,
                         self.z * value,
                         self.w * value)
        elif isinstance(value, tvec4):
            return tvec4(self.x * value.x,
                         self.y * value.y,
                         self.z * value.z,
                         self.w * value.w)
        else:
            try:
                return tvec4(self.x * value[0],
                         self.y * value[1],
                             self.z * value[2],
                             self.w * value[3])
            except:
                raise TypeError("unsupported operand type(s) for *: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    __rmul__ = __mul__

    def __truediv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tvec4(self.x / value,
                         self.y / value,
                         self.z / value,
                         self.w / value)
        elif isinstance(value, tvec4):
            return tvec4(self.x / float(value.x),
                         self.y / float(value.y),
                         self.z / float(value.z),
                         self.w / float(value.w))
        else:
            try:
                return tvec4(self.x / float(value[0]),
                         self.y / float(value[1]),
                             self.z / float(value[2]),
                             self.w / float(value[3]))
            except:
                raise TypeError("unsupported operand type(s) for /: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rtruediv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tvec4(value / self.x,
                         value / self.y,
                         value / self.z,
                         value / self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x / float(self.x),
                         value.y / float(self.y),
                         value.z / float(self.z),
                         value.w / float(self.w))
        else:
            try:
                return tvec4(value[0] / float(self[0]),
                         value[1] / float(self[1]),
                             value[2] / float(self[2]),
                             value[3] / float(self[3]))
            except:
                raise TypeError("unsupported operand type(s) for /: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    def __floordiv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tvec4(self.x // value,
                         self.y // value,
                         self.z // value,
                         self.w // value)
        elif isinstance(value, tvec4):
            return tvec4(self.x // float(value.x),
                         self.y // float(value.y),
                         self.z // float(value.z),
                         self.w // float(value.w))
        else:
            try:
                return tvec4(self.x // float(value[0]),
                         self.y // float(value[1]),
                             self.z // float(value[2]),
                             self.w // float(value[3]))
            except:
                raise TypeError("unsupported operand type(s) for //: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rfloordiv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tvec4(value // self.x,
                         value // self.y,
                         value // self.z,
                         value // self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x // float(value.x),
                         value.y // float(value.y),
                         value.z // float(value.z),
                         value.w // float(value.w))
        else:
            try:
                return tvec4(value[0] // float(self[0]),
                         value[1] // float(self[1]),
                             value[2] // float(self[2]),
                             value[3] // float(self[3]))
            except:
                raise TypeError("unsupported operand type(s) for //: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __mod__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x % value,
                         self.y % value,
                         self.z % value,
                         self.w % value)
        elif isinstance(value, tvec4):
            return tvec4(self.x % value.x,
                         self.y % value.y,
                         self.z % value.z,
                         self.w % value.w)
        else:
            try:
                return tvec4(self.x % value[0],
                         self.y % value[1],
                             self.z % value[2],
                             self.w % value[3])
            except:
                raise TypeError("unsupported operand type(s) for %: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rmod__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(value % self.x,
                         value % self.y,
                         value % self.z,
                         value % self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x % self.x,
                         value.y % self.y,
                         value.z % self.z,
                         value.w % self.w)
        else:
            try:
                return tvec4(value[0] % self[0],
                         value[1] % self[1],
                             value[2] % self[2],
                             value[3] % self[3])
            except:
                raise TypeError("unsupported operand type(s) for %: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __pow__(self, value, modulo=None):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x ** value,
                         self.y ** value,
                         self.z ** value,
                         self.w ** value)
        elif isinstance(value, tvec4):
            return tvec4(self.x ** value.x,
                         self.y ** value.y,
                         self.z ** value.z,
                         self.w ** value.w)
        else:
            try:
                return tvec4(self.x ** value[0],
                         self.y ** value[1],
                             self.z ** value[2],
                             self.w ** value[3])
            except:
                raise TypeError("unsupported operand type(s) for pow: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rpow__(self, value, modulo=None):
        if type(value) in (int, float, long, bool):
            return tvec4(value ** self.x,
                         value ** self.y,
                         value ** self.z,
                         value ** self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x ** self.x,
                         value.y ** self.y,
                         value.z ** self.z,
                         value.w ** self.w)
        else:
            try:
                return tvec4(value[0] ** self[0],
                         value[1] ** self[1],
                             value[2] ** self[2],
                             value[3] ** self[3])
            except:
                raise TypeError("unsupported operand type(s) for pow: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __lshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x << value,
                         self.y << value,
                         self.z << value,
                         self.w << value)
        elif isinstance(value, tvec4):
            return tvec4(self.x << value.x,
                         self.y << value.y,
                         self.z << value.z,
                         self.w << value.w)
        else:
            try:
                return tvec4(self.x << value[0],
                         self.y << value[1],
                             self.z << value[2],
                             self.w << value[3])
            except:
                raise TypeError("unsupported operand type(s) for <<: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rlshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(value << self.x,
                         value << self.y,
                         value << self.z,
                         value << self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x << self.x,
                         value.y << self.y,
                         value.z << self.z,
                         value.w << self.w)
        else:
            try:
                return tvec4(value[0] << self[0],
                         value[1] << self[1],
                             value[2] << self[2],
                             value[3] << self[3])
            except:
                raise TypeError("unsupported operand type(s) for <<: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x >> value,
                         self.y >> value,
                         self.z >> value,
                         self.w >> value)
        elif isinstance(value, tvec4):
            return tvec4(self.x >> value.x,
                         self.y >> value.y,
                         self.z >> value.z,
                         self.w >> value.w)
        else:
            try:
                return tvec4(self.x >> value[0],
                         self.y >> value[1],
                             self.z >> value[2],
                             self.w >> value[3])
            except:
                raise TypeError("unsupported operand type(s) for >>: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __rrshift__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(value >> self.x,
                         value >> self.y,
                         value >> self.z,
                         value >> self.w)
        elif isinstance(value, tvec4):
            return tvec4(value.x >> self.x,
                         value.y >> self.y,
                         value.z >> self.z,
                         value.w >> self.w)
        else:
            try:
                return tvec4(value[0] >> self[0],
                         value[1] >> self[1],
                             value[2] >> self[2],
                             value[3] >> self[3])
            except:
                raise TypeError("unsupported operand type(s) for >>: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    def __and__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x & value,
                         self.y & value,
                         self.z & value,
                         self.w & value)
        elif isinstance(value, tvec4):
            return tvec4(self.x & value.x,
                         self.y & value.y,
                         self.z & value.z,
                         self.w & value.w)
        else:
            try:
                return tvec4(self.x & value[0],
                         self.y & value[1],
                             self.z & value[2],
                             self.w & value[3])
            except:
                raise TypeError("unsupported operand type(s) for &: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    __rand__ = __and__

    def __or__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x | value,
                         self.y | value,
                         self.z | value,
                         self.w | value)
        elif isinstance(value, tvec4):
            return tvec4(self.x | value.x,
                         self.y | value.y,
                         self.z | value.z,
                         self.w | value.w)
        else:
            try:
                return tvec4(self.x | value[0],
                         self.y | value[1],
                             self.z | value[2],
                             self.w | value[3])
            except:
                raise TypeError("unsupported operand type(s) for |: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    __or__ = __or__

    def __xor__(self, value):
        if type(value) in (int, float, long, bool):
            return tvec4(self.x ^ value,
                         self.y ^ value,
                         self.z ^ value,
                         self.w ^ value)
        elif isinstance(value, tvec4):
            return tvec4(self.x ^ value.x,
                         self.y ^ value.y,
                         self.z ^ value.z,
                         self.w ^ value.w)
        else:
            try:
                return tvec4(self.x ^ value[0],
                         self.y ^ value[1],
                             self.z ^ value[2],
                             self.w ^ value[3])
            except:
                raise TypeError("unsupported operand type(s) for ^: 'tvec4' and '{}'".format(_type_to_str(type(value))))

    __rxor__ = __xor__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in (int, float, long, bool):
            self.x += value
            self.y += value
            self.z += value
            self.w += value
        elif isinstance(value, tvec4):
            self.x += value.x
            self.y += value.y
            self.z += value.z
            self.w += value.w
        else:
            try:
                self.x += value[0]
                self.y += value[1]
                self.z += value[2]
                self.w += value[3]
            except:
                raise TypeError("unsupported operand type(s) for +=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __isub__(self, value):
        if type(value) in (int, float, long, bool):
            self.x -= value
            self.y -= value
            self.z -= value
            self.w -= value
        elif isinstance(value, tvec4):
            self.x -= value.x
            self.y -= value.y
            self.z -= value.z
            self.w -= value.w
        else:
            try:
                self.x -= value[0]
                self.y -= value[1]
                self.z -= value[2]
                self.w -= value[3]
            except:
                raise TypeError("unsupported operand type(s) for -=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __imul__(self, value):
        if type(value) in (int, float, long, bool):
            self.x *= value
            self.y *= value
            self.z *= value
            self.w *= value
        elif isinstance(value, tvec4):
            self.x *= value.x
            self.y *= value.y
            self.z *= value.z
            self.w *= value.w
        else:
            try:
                self.x *= value[0]
                self.y *= value[1]
                self.z *= value[2]
                self.w *= value[3]
            except:
                raise TypeError("unsupported operand type(s) for *=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __itruediv__(self, value):
        if type(value) in (int, float, long, bool):
            self.x /= value
            self.y /= value
            self.z /= value
            self.w /= value
        elif isinstance(value, tvec4):
            self.x /= value.x
            self.y /= value.y
            self.z /= value.z
            self.w /= value.w
        else:
            try:
                self.x /= value[0]
                self.y /= value[1]
                self.z /= value[2]
                self.w /= value[3]
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __idiv__(self, value):
        if type(value) in (int, float, long, bool):
            self.x /= value
            self.y /= value
            self.z /= value
            self.w /= value
        elif isinstance(value, tvec4):
            self.x /= value.x
            self.y /= value.y
            self.z /= value.z
            self.w /= value.w
        else:
            try:
                self.x /= value[0]
                self.y /= value[1]
                self.z /= value[2]
                self.w /= value[3]
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __ifloordiv__(self, value):
        if type(value) in (int, float, long, bool):
            self.x //= value
            self.y //= value
            self.z //= value
            self.w //= value
        elif isinstance(value, tvec4):
            self.x //= value.x
            self.y //= value.y
            self.z //= value.z
            self.w //= value.w
        else:
            try:
                self.x //= value[0]
                self.y //= value[1]
                self.z //= value[2]
                self.w //= value[3]
            except:
                raise TypeError("unsupported operand type(s) for //=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __imod__(self, value):
        if type(value) in (int, float, long, bool):
            self.x %= value
            self.y %= value
            self.z %= value
            self.w %= value
        elif isinstance(value, tvec4):
            self.x %= value.x
            self.y %= value.y
            self.z %= value.z
            self.w %= value.w
        else:
            try:
                self.x %= value[0]
                self.y %= value[1]
                self.z %= value[2]
                self.w %= value[3]
            except:
                raise TypeError("unsupported operand type(s) for %=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __ipow__(self, value, opt=None):
        if type(value) in (int, float, long, bool):
            self.x **= value
            self.y **= value
            self.z **= value
            self.w **= value
        elif isinstance(value, tvec4):
            self.x **= value.x
            self.y **= value.y
            self.z **= value.z
            self.w **= value.w
        else:
            try:
                self.x **= value[0]
                self.y **= value[1]
                self.z **= value[2]
                self.w **= value[3]
            except:
                raise TypeError("unsupported operand type(s) for **=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __ilshift__(self, value):
        if type(value) in (int, float, long, bool):
            self.x <<= value
            self.y <<= value
            self.z <<= value
            self.w <<= value
        elif isinstance(value, tvec4):
            self.x <<= value.x
            self.y <<= value.y
            self.z <<= value.z
            self.w <<= value.w
        else:
            try:
                self.x <<= value[0]
                self.y <<= value[1]
                self.z <<= value[2]
                self.w <<= value[3]
            except:
                raise TypeError("unsupported operand type(s) for <<=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __irshift__(self, value):
        if type(value) in (int, float, long, bool):
            self.x >>= value
            self.y >>= value
            self.z >>= value
            self.w >>= value
        elif isinstance(value, tvec4):
            self.x >>= value.x
            self.y >>= value.y
            self.z >>= value.z
            self.w >>= value.w
        else:
            try:
                self.x >>= value[0]
                self.y >>= value[1]
                self.z >>= value[2]
                self.w >>= value[3]
            except:
                raise TypeError("unsupported operand type(s) for >>=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __iand__(self, value):
        if type(value) in (int, float, long, bool):
            self.x &= value
            self.y &= value
            self.z &= value
            self.w &= value
        elif isinstance(value, tvec4):
            self.x &= value.x
            self.y &= value.y
            self.z &= value.z
            self.w &= value.w
        else:
            try:
                self.x &= value[0]
                self.y &= value[1]
                self.z &= value[2]
                self.w &= value[3]
            except:
                raise TypeError("unsupported operand type(s) for &=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __ior__(self, value):
        if type(value) in (int, float, long, bool):
            self.x |= value
            self.y |= value
            self.z |= value
            self.w |= value
        elif isinstance(value, tvec4):
            self.x |= value.x
            self.y |= value.y
            self.z |= value.z
            self.w |= value.w
        else:
            try:
                self.x |= value[0]
                self.y |= value[1]
                self.z |= value[2]
                self.w |= value[3]
            except:
                raise TypeError("unsupported operand type(s) for |=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __ixor__(self, value):
        if type(value) in (int, float, long, bool):
            self.x ^= value
            self.y ^= value
            self.z ^= value
            self.w ^= value
        elif isinstance(value, tvec4):
            self.x ^= value.x
            self.y ^= value.y
            self.z ^= value.z
            self.w ^= value.w
        else:
            try:
                self.x ^= value[0]
                self.y ^= value[1]
                self.z ^= value[2]
                self.w ^= value[3]
            except:
                raise TypeError("unsupported operand type(s) for ^=: 'tvec4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __pos__(self):
        return self

    def __neg__(self):
        return tvec4(-self.x,
                     -self.y,
                     -self.z,
                     -self.w)

    def __abs__(self):
        return tvec4(abs(self.x),
                     abs(self.y),
                     abs(self.z),
                     abs(self.w))

    def __invert__(self):
        return tvec4(~self.x,
                     ~self.y,
                     ~self.z,
                     ~self.w)

    def __bool__(self):
        return (bool(self.x), bool(self.y), bool(self.z), bool(self.w))

    __nonzero__ = __bool__

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tvec4 doesn't support slices")
        else:
            if key in (0,-4):
                return self.x
            elif key in (1,-3):
                return self.y
            elif key in (2,-2):
                return self.z
            elif key in (3,-1):
                return self.w
            else:
                raise IndexError("tvec4 index out of range")

    def __setitem__(self, key, value):
        if type(key) == slice:
            raise TypeError("tvec4 doesn't support slices")
        else:
            if key in (0,-4):
                self.x = value
            elif key in (1,-3):
                self.y = value
            elif key in (2,-2):
                self.z = value
            elif key in (3,-1):
                self.w = value
            else:
                raise IndexError("tvec4 index out of range")

    def __getattr__(self, name):
        if name.startswith('__') and name.endswith('__'):
            raise AttributeError(name)

        if len(name) == 1:
            if name in "xrs":
                return self.__dict__["x"]
            if name in "ygt":
                return self.__dict__["y"]
            if name in "zbp":
                return self.__dict__["z"]
            if name in "waq":
                return self.__dict__["w"]

        if len(name) == 2:
            for char in name:
                if not char in "xrsygtzbpwaq":
                    raise AttributeError(name)
            return tvec2(self.__dict__["x"] if name[0] in "xrs" else self.__dict__["y"] if name[0] in "ygt" else self.__dict__["z"] if name[0] in "zbp" else self.__dict__["w"],
                         self.__dict__["x"] if name[1] in "xrs" else self.__dict__["y"] if name[1] in "ygt" else self.__dict__["z"] if name[1] in "zbp" else self.__dict__["w"])

        if len(name) == 3:
            for char in name:
                if not char in "xrsygtzbpwaq":
                    raise AttributeError(name)
            return tvec3(self.__dict__["x"] if name[0] in "xrs" else self.__dict__["y"] if name[0] in "ygt" else self.__dict__["z"] if name[0] in "zbp" else self.__dict__["w"],
                         self.__dict__["x"] if name[1] in "xrs" else self.__dict__["y"] if name[1] in "ygt" else self.__dict__["z"] if name[1] in "zbp" else self.__dict__["w"],
                         self.__dict__["x"] if name[2] in "xrs" else self.__dict__["y"] if name[2] in "ygt" else self.__dict__["z"] if name[2] in "zbp" else self.__dict__["w"])

        if len(name) == 4:
            for char in name:
                if not char in "xrsygtzbpwaq":
                    raise AttributeError(name)
            return tvec4(self.__dict__["x"] if name[0] in "xrs" else self.__dict__["y"] if name[0] in "ygt" else self.__dict__["z"] if name[0] in "zbp" else self.__dict__["w"],
                         self.__dict__["x"] if name[1] in "xrs" else self.__dict__["y"] if name[1] in "ygt" else self.__dict__["z"] if name[1] in "zbp" else self.__dict__["w"],
                         self.__dict__["x"] if name[2] in "xrs" else self.__dict__["y"] if name[2] in "ygt" else self.__dict__["z"] if name[2] in "zbp" else self.__dict__["w"],
                         self.__dict__["x"] if name[3] in "xrs" else self.__dict__["y"] if name[3] in "ygt" else self.__dict__["z"] if name[3] in "zbp" else self.__dict__["w"])

        raise AttributeError(name)

    def __setattr__(self, name, value):
        if name.startswith('__') and name.endswith('__'):
            raise AttributeError(name)

        if len(name) == 1:
            if name in "xrs":
                self.__dict__["x"] = value
            elif name in "ygt":
                self.__dict__["y"] = value
            elif name in "zbp":
                self.__dict__["z"] = value
            elif name in "waq":
                self.__dict__["w"] = value
            else:
                raise AttributeError(name)
                
        elif _unswizzle(name) == "xy":
            if (isinstance(value, tvec2) or type(value) in (tuple, list, set)) and len(value) == 2:
                self.__dict__["x"] = value[0]
                self.__dict__["y"] = value[1]
            else:
                raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
            
        elif _unswizzle(name) == "xyz":
            if (isinstance(value, tvec3) or type(value) in (tuple, list, set)) and len(value) == 3:
                self.__dict__["x"] = value[0]
                self.__dict__["y"] = value[1]
                self.__dict__["z"] = value[2]
            else:
                raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
            
        elif _unswizzle(name) == "xyzw":
            if (isinstance(value, tvec4) or type(value) in (tuple, list, set)) and len(value) == 4:
                self.__dict__["x"] = value[0]
                self.__dict__["y"] = value[1]
                self.__dict__["z"] = value[2]
                self.__dict__["w"] = value[3]
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
        return "tvec4( {} , {} , {} , {} )".format(self.x, self.y, self.z, self.w)


from .type_vec2 import tvec2
from .type_vec3 import tvec3
