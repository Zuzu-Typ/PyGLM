from .setup import *

def _type_to_str(type_):
    return str(type_).replace("<type '", "").replace("'>", "")

class tmat4x4:
    def __init__(self, *args):
        self.col_type = tvec4
        self.row_type = tvec4

        if len(args) == 1:
            if isinstance(args[0], tmat4x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1]),
                              self.col_type(args[0][2]),
                              self.col_type(args[0][3])]

            elif isinstance(args[0], tmat4x3):
                self.value = [self.col_type(args[0][0],0),
                              self.col_type(args[0][1],0),
                              self.col_type(args[0][2],0),
                              self.col_type(args[0][3],1)]
                
            elif isinstance(args[0], tmat4x2):
                self.value = [self.col_type(args[0][0], 0,0),
                              self.col_type(args[0][1], 0,0),
                              self.col_type(args[0][2], 1,0),
                              self.col_type(args[0][3], 0,1)]

            elif isinstance(args[0], tmat3x3)  or isinstance(args[0], tmat3x4):
                self.value = [self.col_type(args[0][0],0),
                              self.col_type(args[0][1],0),
                              self.col_type(args[0][2],0),
                              self.col_type(0,0,0,1)]

            elif isinstance(args[0], tmat3x2):
                self.value = [self.col_type(args[0][0], 0,0),
                              self.col_type(args[0][1], 0,0),
                              self.col_type(args[0][2], 1,0),
                              self.col_type(0,0,0,1)]

            elif isinstance(args[0], tmat2x4):
                self.value = [self.col_type(args[0][0]),
                              self.col_type(args[0][1]),
                              self.col_type(0,0,1,0),
                              self.col_type(0,0,0,1)]
            elif isinstance(args[0], tmat2x3):
                self.value = [self.col_type(args[0][0],0),
                              self.col_type(args[0][1],0),
                              self.col_type(0,0,1,0),
                              self.col_type(0,0,0,1)]

            elif isinstance(args[0], tmat2x2):
                self.value = [self.col_type(args[0][0], 0,0),
                              self.col_type(args[0][1], 0,0),
                              self.col_type(0,0,1,0),
                              self.col_type(0,0,0,1)]
                
            elif type(args[0]) in (int, long, float):
                self.value = [self.col_type(args[0],0,0,0),
                              self.col_type(0,args[0],0,0),
                              self.col_type(0, 0,args[0],0),
                              self.col_type(0, 0,0,args[0])]

            elif type(args[0]) in (tuple, list, set):
                self.__init__(*args[0])

        elif len(args) == 4:
            if isinstance(args[0], self.col_type) and isinstance(args[1], self.col_type) and isinstance(args[2], self.col_type) and isinstance(args[3], self.col_type):
                self.value = [self.col_type(args[0]),
                              self.col_type(args[1]),
                              self.col_type(args[2]),
                              self.col_type(args[3])]

        elif len(args) == 16:
            for arg in args:
                if not type(arg) in (int, long, float, bool):
                    raise TypeError("unsupported type {} for tmat4x4()".format(arg))

            self.value = [self.col_type(*args[:4]),
                          self.col_type(*args[4:8]),
                          self.col_type(*args[8:12]),
                          self.col_type(*args[12:])]
                
        else:
            self.value = [self.col_type(1,0,0,0),
                          self.col_type(0,1,0,0),
                          self.col_type(0,0,1,0),
                          self.col_type(0,0,0,1)]

    def __eq__(self, value):
        if isinstance(value, tmat4x4):
            return (self[0] == value[0] and self[1] == value[1] and self[2] == value[2] and self[3] == value[3])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1] and self[2] == value[2] and self[3] == value[3])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __ne__(self, value):
        if isinstance(value, tmat4x4):
            return (self[0] != value[0] or self[1] != value[1] or self[2] != value[2] or self[3] != value[3])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1] or self[2] != value[2] or self[3] != value[3])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __add__(self, value):
        if type(value) in (int, float, long, bool):
            return tmat4x4(self[0] + value,
                         self[1] + value,
                           self[2] + value,
                           self[3] + value)
        elif isinstance(value, tmat4x4):
            return tmat4x4(self[0] + value[0],
                         self[1] + value[1],
                           self[2] + value[2],
                           self[3] + value[3])
        else:
            try:
                return tmat4x4(self[0] + value[0],
                         self[1] + value[1],
                               self[2] + value[2],
                               self[3] + value[3])
            except:
                raise TypeError("unsupported operand type(s) for +: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    __radd__ = __add__

    def __sub__(self, value):
        if type(value) in (int, float, long, bool):
            return tmat4x4(self[0] - value,
                         self[1] - value,
                           self[2] - value,
                           self[3] - value)
        elif isinstance(value, tmat4x4):
            return tmat4x4(self[0] - value[0],
                         self[1] - value[1],
                           self[2] - value[2],
                           self[3] - value[3])
        else:
            try:
                return tmat4x4(self[0] - value[0],
                         self[1] - value[1],
                               self[2] - value[2],
                               self[3] - value[3])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __rsub__(self, value):
        if type(value) in (int, float, long, bool):
            return tmat4x4(value - self[0],
                         value - self[1],
                           value - self[2],
                           value - self[3])
        elif isinstance(value, tmat4x4):
            return tmat4x4(value[0] - self[0],
                         value[1] - self[1],
                           value[2] - self[2],
                           value[3] - self[3])
        else:
            try:
                return tmat4x4(value[0] - self[0],
                         value[1] - self[1],
                               value[2] - self[2],
                               value[3] - self[3])
            except:
                raise TypeError("unsupported operand type(s) for -: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __mul__(self, value):
        if type(value) in (int, float, long, bool):
            return tmat4x4(self[0] * value,
                         self[1] * value,
                           self[2] * value,
                           self[3] * value)
        elif isinstance(value, self.row_type):
            m = self
            v = value
            Mov0 = self.col_type(v[0])
            Mov1 = self.col_type(v[1])
            Mul0 = m[0] * Mov0
            Mul1 = m[1] * Mov1
            Add0 = Mul0 + Mul1
            Mov2 = self.col_type(v[2])
            Mov3 = self.col_type(v[3])
            Mul2 = m[2] * Mov2
            Mul3 = m[3] * Mov3
            Add1 = Mul2 + Mul3
            Add2 = Add0 + Add1
            return Add2
        elif isinstance(value, tmat4x4):
            m1 = self
            m2 = value
            SrcA0 = m1[0]
            SrcA1 = m1[1]
            SrcA2 = m1[2]
            SrcA3 = m1[3]

            SrcB0 = m2[0]
            SrcB1 = m2[1]
            SrcB2 = m2[2]
            SrcB3 = m2[3]
            
            Result = tmat4x4(0)
            Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3]
            Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3]
            Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3]
            Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3]
            return Result
        elif isinstance(value, tmat2x4):
            m1 = self
            m2 = value
            return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3])
        elif isinstance(value, tmat3x4):
            m1 = self
            m2 = value
            return tmat3x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3])
        else:
            raise TypeError("unsupported operand type(s) for *: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __rmul__(self, value):
        if type(value) in (int, float, long, bool):
            return tmat4x4(self[0] * value,
                         self[1] * value,
                           self[2] * value,
                           self[3] * value)
        elif isinstance(value, self.col_type):
            m = self
            v = value
            return self.row_type(m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
			m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3],
			m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3],
			m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3])
        elif isinstance(value, tmat4x4):
            m1 = self
            m2 = value
            SrcA0 = m1[0]
            SrcA1 = m1[1]
            SrcA2 = m1[2]
            SrcA3 = m1[3]

            SrcB0 = m2[0]
            SrcB1 = m2[1]
            SrcB2 = m2[2]
            SrcB3 = m2[3]
            
            Result = tmat4x4(0)
            Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3]
            Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3]
            Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3]
            Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3]
            return Result
        elif isinstance(value, tmat2x4):
            m1 = self
            m2 = value
            return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3])
        elif isinstance(value, tmat3x4):
            m1 = self
            m2 = value
            return tmat3x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3])
        else:
            raise TypeError("unsupported operand type(s) for *: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __truediv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tmat4x4(self[0] / value,
                         self[1] / value,
                           self[2] / value,
                           self[3] / value)
        elif isinstance(value, self.row_type):
            return inverse(self) * value
        elif isinstance(value, tmat4x4):
            return self * inverse(value)
        else:
            try:
                return self * inverse(value)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    def __rtruediv__(self, value):
        if type(value) in (int, float, long, bool):
            value = float(value)
            return tmat4x4(value / self[0],
                         value / self[1],
                           value / self[2])
        elif isinstance(value, self.col_type):
            return value * inverse(self)
        elif isinstance(value, tmat4x4):
            return self * inverse(value)
        else:
            try:
                return value * inverse(self)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        if type(value) in (int, float, long, bool):
            self[0] += value
            self[1] += value
            self[2] += value
            self[3] += value
        elif isinstance(value, tmat4x4):
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
                raise TypeError("unsupported operand type(s) for +=: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __isub__(self, value):
        if type(value) in (int, float, long, bool):
            self[0] -= value
            self[1] -= value
            self[2] -= value
            self[3] -= value
        elif isinstance(value, tmat4x4):
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
                raise TypeError("unsupported operand type(s) for -=: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __imul__(self, value):
        if type(value) in (int, float, long, bool):
            self[0] *= value
            self[1] *= value
            self[2] *= value
            self[3] *= value
        elif isinstance(value, tmat4x4):
            self.value = (self * value).value
        else:
            try:
                self[0] *= value[0]
                self[1] *= value[1]
                self[2] *= value[2]
                self[3] *= value[3]
            except:
                raise TypeError("unsupported operand type(s) for *=: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))
        return self

    def __itruediv__(self, value):
        if type(value) in (int, float, long, bool):
            self[0] /= float(value)
            self[1] /= float(value)
            self[2] /= float(value)
            self[3] /= float(value)
        elif isinstance(value, tmat4x4):
            self *= inverse(value)
        else:
            try:
                self *= inverse(value)
            except:
                raise TypeError("unsupported operand type(s) for /=: 'tmat4x4' and '{}'".format(_type_to_str(type(value))))
        return self

    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat4x4(-self[0],
                     -self[1],
                       -self[2],
                       -self[3])

    def __abs__(self):
        return tmat4x4(abs(self[0]),
                     abs(self[1]),
                       abs(self[2]),
                       abs(self[3]))

    def __invert__(self):
        return invert(self)

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat4x4 doesn't support slices")
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
                raise IndexError("tmat4x4 index out of range")

    def __setitem__(self, key, value):
        if type(key) == slice:
            raise TypeError("tmat4x4 doesn't support slices")
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
                raise IndexError("tmat4x4 index out of range")

    def __str__(self):
        return "tmat4x4( {}, {}, {}, {},\n         {}, {}, {}, {},\n         {}, {}, {}, {},\n         {}, {}, {}, {} )".format(self.value[0][0], self.value[0][1], self.value[0][2], self.value[0][3],
                                                                             self.value[1][0], self.value[1][1], self.value[1][2], self.value[1][3],
                                                                             self.value[2][0], self.value[2][1], self.value[2][2], self.value[2][3],
                                                                                                self.value[3][0], self.value[3][1], self.value[3][2], self.value[3][3])

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

from .type_mat4x2 import tmat4x2
from .type_mat4x3 import tmat4x3
