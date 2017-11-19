from ..datatypes import default_dtype, dtypes, ltypes
from .setup import GLM_C_FLOAT_SIZE, GLM_VEC, GLM_VEC3, pyglmCompareType

import sys

import numpy

def _unswizzle(swizzle):
    return swizzle.replace("r","x").replace("s", "x").replace("g", "y").replace("t", "y").replace("b", "z").replace("p", "z").replace("a", "w").replace("q", "w")

class tvec3:
    def __init__(self, *args, **kw):
        self.dtype = kw.get("dtype", default_dtype)
        if len(args) == 1:
            # from tvec
            if type(args[0]) in dtypes:
                self.arr = numpy.array(args[0], dtype=self.dtype)
                
            elif pyglmCompareType(args[0], tvec3) or pyglmCompareType(args[0], tvec4):
                self.arr = args[0].arr[:3]

            elif pyglmCompareType(args[0], numpy.ndarray):
                self.arr = numpy.array(args[0]).reshape(args[0].size)[:3]

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])

        elif len(args) == 2:
            # check types
            if pyglmCompareType(args[0], tvec2):
                if not type(args[1]) in dtypes:
                    raise TypeError("expected int or float values, got {}".format(type(args[1])))
                self.arr = numpy.array(tuple(args[0].arr) + (args[1],), dtype=self.dtype)
            elif pyglmCompareType(args[1], tvec2):
                if not type(args[0]) in dtypes:
                    raise TypeError("expected int or float values, got {}".format(type(args[0])))
                self.arr = numpy.array((args[0],) + tuple(args[1].arr), dtype=self.dtype)
                self.arr[0] = args[0]
                self.arr[1] = self.dtype(args[1].x)
                self.arr[2] = self.dtype(args[1].y)
            else:
                raise TypeError("expected tvec2 and int or float values, got {} and {}".format(type(args[0]), type(args[1])))

        elif len(args) == 3:
            if not type(args[0]) in dtypes:
                raise TypeError("expected int or float values, got {}".format(type(args[0])))
            if not type(args[1]) in dtypes:
                raise TypeError("expected int or float values, got {}".format(type(args[1])))
            if not type(args[2]) in dtypes:
                raise TypeError("expected int or float values, got {}".format(type(args[2])))
            self.arr = numpy.array(args,dtype=self.dtype)

        elif len(args) > 3:
            raise TypeError("tvec3 takes at most 3 arguments, got {}".format(len(args)))

        else:
            self.arr = numpy.array((0,0,0),dtype=self.dtype)

    def __getitem__(self, *args,**kw):
        return self.arr.__getitem__(*args, **kw)

    def __setitem__(self, *args,**kw):
        return self.arr.__setitem__(*args, **kw)

    def __dtype__(self, dtype):
        pass

    def length(*args):
        return 3

    def __sizeof__(self):
        return GLM_C_FLOAT_SIZE * 3

    __len__ = length

    __size__ = GLM_C_FLOAT_SIZE * 3

    glm_type = GLM_VEC
    shape = GLM_VEC3

    def __eq__(self, value):
        if type(value) in dtypes:
            return (self.arr[0] == value and self.arr[1] == value and self.arr[2] == value)
        elif pyglmCompareType(value, tvec3):
            return (self.arr[0] == value.x and self.arr[1] == value.y and self.arr[2] == value.z)
        else:
            try:
                return (self.arr[0] == value[0] and self.arr[1] == value[1] and self.arr[2] == value[2])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tvec3' and '{}'".format(type(value)))

    def __ne__(self, value):
        if type(value) in dtypes:
            return (self.arr[0] != value and self.arr[1] != value and self.arr[2] != value)
        elif pyglmCompareType(value, tvec3):
            return (self.arr[0] != value.x and self.arr[1] != value.y and self.arr[2] != value.z)
        else:
            try:
                return (self.arr[0] != value[0] and self.arr[1] != value[1] and self.arr[2] != value[2])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tvec3' and '{}'".format(type(value)))

    def __add__(self, value):
        try:
            return tvec3(self.arr + value)
        except:
            raise TypeError("unsupported operand type(s) for +: 'tvec3' and '{}'".format(type(value)))

    __radd__ = __add__

    def __sub__(self, value):
        try:
            return tvec3(self.arr - value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tvec3' and '{}'".format(type(value)))

    def __rsub__(self, value):
        try:
            return tvec3(value - self.arr)
        except:
            raise TypeError("unsupported operand type(s) for +: 'tvec3' and '{}'".format(type(value)))

    def __mul__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr * value.arr)
            return tvec3(self.arr * value)
        except:
            raise TypeError("unsupported operand type(s) for *: 'tvec3' and '{}'".format(type(value)))

    __rmul__ = __mul__

    def __truediv__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr / value.arr)
            return tvec3(self.arr / value)
        except:
            raise TypeError("unsupported operand type(s) for /: 'tvec3' and '{}'".format(type(value)))

    def __rtruediv__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(value.arr / self.arr)
            return tvec3(value / self.arr)
        except:
            raise TypeError("unsupported operand type(s) for /: 'tvec3' and '{}'".format(type(value)))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    def __floordiv__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr // value.arr)
            return tvec3(self.arr // value)
        except:
            raise TypeError("unsupported operand type(s) for //: 'tvec3' and '{}'".format(type(value)))

    def __rfloordiv__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(value.arr // self.arr)
            return tvec3(value // self.arr)
        except:
            raise TypeError("unsupported operand type(s) for //: 'tvec3' and '{}'".format(type(value)))

    def __mod__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr % value.arr)
            return tvec3(self.arr % value)
        except:
            raise TypeError("unsupported operand type(s) for %: 'tvec3' and '{}'".format(type(value)))

    def __rmod__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(value.arr % self.arr)
            return tvec3(value % self.arr)
        except:
            raise TypeError("unsupported operand type(s) for %: 'tvec3' and '{}'".format(type(value)))

    def __pow__(self, value, modulo=None):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr ** value.arr)
            return tvec3(self.arr ** value)
        except:
            raise TypeError("unsupported operand type(s) for pow: 'tvec3' and '{}'".format(type(value)))

    def __rpow__(self, value, modulo=None):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(value.arr ** self.arr)
            return tvec3(value ** self.arr)
        except:
            raise TypeError("unsupported operand type(s) for pow: 'tvec3' and '{}'".format(type(value)))

    def __lshift__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr << value.arr)
            return tvec3(self.arr << value)
        except:
            raise TypeError("unsupported operand type(s) for <<: 'tvec3' and '{}'".format(type(value)))

    def __rlshift__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(value.arr << self.arr)
            return tvec3(value << self.arr)
        except:
            raise TypeError("unsupported operand type(s) for <<: 'tvec3' and '{}'".format(type(value)))

    def __rshift__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr >> value.arr)
            return tvec3(self.arr >> value)
        except:
            raise TypeError("unsupported operand type(s) for >>: 'tvec3' and '{}'".format(type(value)))

    def __rrshift__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(value.arr >> self.arr)
            return tvec3(value >> self.arr)
        except:
            raise TypeError("unsupported operand type(s) for >>: 'tvec3' and '{}'".format(type(value)))

    def __and__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr & value.arr)
            return tvec3(self.arr & value)
        except:
            raise TypeError("unsupported operand type(s) for &: 'tvec3' and '{}'".format(type(value)))

    __rand__ = __and__

    def __or__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr | value.arr)
            return tvec3(self.arr | value)
        except:
            raise TypeError("unsupported operand type(s) for |: 'tvec3' and '{}'".format(type(value)))

    __or__ = __or__

    def __xor__(self, value):
        try:
            if pyglmCompareType(value, tvec3):
                return tvec3(self.arr ^ value.arr)
            return tvec3(self.arr ^ value)
        except:
            raise TypeError("unsupported operand type(s) for ^: 'tvec3' and '{}'".format(type(value)))

    __rxor__ = __xor__

    # __i*__ functions
    def __iadd__(self, value):
        try:
            self.arr += value
        except:
            raise TypeError("unsupported operand type(s) for +=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __isub__(self, value):
        try:
            self.arr -= value
        except:
            raise TypeError("unsupported operand type(s) for -=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __imul__(self, value):
        try:
            self.arr *= value
        except:
            raise TypeError("unsupported operand type(s) for *=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __itruediv__(self, value):
        try:
            self.arr /= value
        except:
            raise TypeError("unsupported operand type(s) for /=: 'tvec3' and '{}'".format(type(value)))
        return self

    __idiv__ = __itruediv__

    def __ifloordiv__(self, value):
        try:
            self.arr //= value
        except:
            raise TypeError("unsupported operand type(s) for //=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __imod__(self, value):
        try:
            self.arr %= value
        except:
            raise TypeError("unsupported operand type(s) for %=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __ipow__(self, value, opt=None):
        try:
            self.arr **= value
        except:
            raise TypeError("unsupported operand type(s) for **=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __ilshift__(self, value):
        try:
            self.arr <<= value
        except:
            raise TypeError("unsupported operand type(s) for <<=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __irshift__(self, value):
        try:
            self.arr >>= value
        except:
            raise TypeError("unsupported operand type(s) for >>=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __iand__(self, value):
        try:
            self.arr &= value
        except:
            raise TypeError("unsupported operand type(s) for &=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __ior__(self, value):
        try:
            self.arr |= value
        except:
            raise TypeError("unsupported operand type(s) for |=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __ixor__(self, value):
        try:
            self.arr ^= value
        except:
            raise TypeError("unsupported operand type(s) for ^=: 'tvec3' and '{}'".format(type(value)))
        return self

    def __pos__(self):
        return self

    def __neg__(self):
        return tvec3(-self.arr)

    def __abs__(self):
        return tvec3(abs(self.arr))

    def __invert__(self):
        return tvec3(~self.arr)

    def __bool__(self):
        return (bool(self.arr[0]), bool(self.arr[1]), bool(self.arr[2]))

    __nonzero__ = __bool__

    def __array__(self, *args, **kw):
        return self.arr.__array__(*args, **kw)

    def __getattr__(self, name):
        if name.startswith('__') and name.endswith('__'):
            raise AttributeError(name)

        if name == "arr":
            return self.__dict__["arr"]

        if len(name) == 1:
            if name in "xrs":
                return self.__dict__["arr"][0]
            if name in "ygt":
                return self.__dict__["arr"][1]
            if name in "zbp":
                return self.__dict__["arr"][2]

        if len(name) == 2:
            for char in name:
                if not char in "xrsygtzbp":
                    raise AttributeError(name)
            return tvec2(self.__dict__["arr"][0] if name[0] in "xrs" else self.__dict__["arr"][1] if name[0] in "ygt" else self.__dict__["arr"][2],
                         self.__dict__["arr"][0] if name[1] in "xrs" else self.__dict__["arr"][1] if name[1] in "ygt" else self.__dict__["arr"][2])

        if len(name) == 3:
            for char in name:
                if not char in "xrsygtzbp":
                    raise AttributeError(name)
            return tvec3(self.__dict__["arr"][0] if name[0] in "xrs" else self.__dict__["arr"][1] if name[0] in "ygt" else self.__dict__["arr"][2],
                         self.__dict__["arr"][0] if name[1] in "xrs" else self.__dict__["arr"][1] if name[1] in "ygt" else self.__dict__["arr"][2],
                         self.__dict__["arr"][0] if name[2] in "xrs" else self.__dict__["arr"][1] if name[2] in "ygt" else self.__dict__["arr"][2])

        if len(name) == 4:
            for char in name:
                if not char in "xrsygtzbp":
                    raise AttributeError(name)
            return tvec4(self.__dict__["arr"][0] if name[0] in "xrs" else self.__dict__["arr"][1] if name[0] in "ygt" else self.__dict__["arr"][2],
                         self.__dict__["arr"][0] if name[1] in "xrs" else self.__dict__["arr"][1] if name[1] in "ygt" else self.__dict__["arr"][2],
                         self.__dict__["arr"][0] if name[2] in "xrs" else self.__dict__["arr"][1] if name[2] in "ygt" else self.__dict__["arr"][2],
                         self.__dict__["arr"][0] if name[3] in "xrs" else self.__dict__["arr"][1] if name[3] in "ygt" else self.__dict__["arr"][2])

        raise AttributeError(name)

    def __setattr__(self, name, value):
        if len(name) == 1:
            if name in "xrs":
                self.__dict__["arr"][0] = self.dtype(value)
            elif name in "ygt":
                self.__dict__["arr"][1] = self.dtype(value)
            elif name in "zbp":
                self.__dict__["arr"][2] = self.dtype(value)
            else:
                raise AttributeError(name)

        elif _unswizzle(name) == "xy":
            if pyglmCompareType(value, tvec2) or (type(value) in ltypes and len(value) == 2):
                self.__dict__["arr"][0] = self.dtype(value[0])
                self.__dict__["arr"][1] = self.dtype(value[1])
            else:
                raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
                
        elif _unswizzle(name) == "xyz":
            if pyglmCompareType(value, tvec3) or pyglmCompareType(value, tvec4) or (type(value) in ltypes and len(value) <= 4):
                self.__dict__["arr"][0] = self.dtype(value[0])
                self.__dict__["arr"][1] = self.dtype(value[1])
                self.__dict__["arr"][2] = self.dtype(value[2])
            else:
                raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
        else:
            self.__dict__[name] = value

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        return "tvec3( {} , {} , {} )".format(self.arr[0], self.arr[1], self.arr[2])

from .type_vec2 import tvec2
from .type_vec4 import tvec4
