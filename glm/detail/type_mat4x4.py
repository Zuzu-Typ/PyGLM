from ..datatypes import default_dtype, dtypes, ltypes
from .setup import GLM_C_FLOAT_SIZE, GLM_MAT, GLM_MAT4x4, pyglmCompareType

import numpy

class tmat4x4:
    def __init__(self, *args, **kw):
        self.dtype = kw.get("dtype", default_dtype)
        
        self.col_type = self.row_type = tvec4
        
        if len(args) == 1:
            if type(args[0]) == numpy.matrixlib.defmatrix.matrix and args[0].size == 16 and args[0].shape == (4,4):
                self.value = args[0].copy()
            elif pyglmCompareType(args[0], tmat4x4):
                self.value = args[0].value.copy()

            elif pyglmCompareType(args[0], tmat4x3):
                self.value = numpy.matrix([tuple(args[0][0])+(0,),
                              tuple(args[0][1])+(0,),
                              tuple(args[0][2])+(0,),
                              tuple(args[0][3])+(1,)], dtype=self.dtype)
                
            elif pyglmCompareType(args[0], tmat4x2):
                self.value = numpy.matrix([tuple(args[0][0])+(0,0),
                              tuple(args[0][1])+(0,0),
                              tuple(args[0][2])+(1,0),
                              tuple(args[0][3])+(0,1)], dtype=self.dtype)

            elif pyglmCompareType(args[0], tmat3x3)  or pyglmCompareType(args[0], tmat3x4):
                self.value = numpy.matrix([tuple(args[0][0])+(0,),
                              tuple(args[0][1])+(0,),
                              tuple(args[0][2])+(0,),
                              (0,0,0,1)], dtype=self.dtype)

            elif pyglmCompareType(args[0], tmat3x2):
                self.value = numpy.matrix([tuple(args[0][0])+(0,0),
                              tuple(args[0][1])+(0,0),
                              tuple(args[0][2])+(1,0),
                              (0,0,0,1)], dtype=self.dtype)

            elif pyglmCompareType(args[0], tmat2x4):
                self.value = numpy.matrix([tuple(args[0][0]),
                              tuple(args[0][1]),
                              (0,0,1,0),
                              (0,0,0,1)], dtype=self.dtype)
                
            elif pyglmCompareType(args[0], tmat2x3):
                self.value = numpy.matrix([tuple(args[0][0])+(0,),
                              tuple(args[0][1])+(0,),
                              (0,0,1,0),
                              (0,0,0,1)], dtype=self.dtype)

            elif pyglmCompareType(args[0], tmat2x2):
                self.value = numpy.matrix([tuple(args[0][0])+(0,0),
                              tuple(args[0][1])+(0,0),
                              (0,0,1,0),
                              (0,0,0,1)], dtype=self.dtype)
                
            elif type(args[0]) in dtypes:
                self.value = numpy.matrix([(args[0],0,0,0),
                              (0,args[0],0,0),
                              (0, 0,args[0],0),
                              (0, 0,0,args[0])], dtype=self.dtype)

            elif type(args[0]) in ltypes:
                self.__init__(*args[0])


            

        elif len(args) == 4:
            self.value = numpy.matrix([(args[0]),
                              (args[1]),
                              (args[2]),
                              (args[3])], dtype=self.dtype)

        elif len(args) == 16:
##            for arg in args:
##                if not type(arg) in dtypes:
##                    raise TypeError("unsupported type {} for tmat4x4()".format(arg))

            self.value = numpy.matrix([(args[:4]),
                          (args[4:8]),
                          (args[8:12]),
                          (args[12:])], dtype=self.dtype)
                
        else:
            self.value = numpy.matrix([(1,0,0,0),
                          (0,1,0,0),
                          (0,0,1,0),
                          (0,0,0,1)], dtype=self.dtype)
            

    def __setitem__(self, *args, **kw):
        return self.value.__setitem__(*args, **kw)

    def length(*args):
        return 4
    __len__ = length

    def __sizeof__(self):
        return GLM_C_FLOAT_SIZE * 16

    __size__ = GLM_C_FLOAT_SIZE * 16

    glm_type = GLM_MAT
    shape = GLM_MAT4x4

    def __eq__(self, value):
        if pyglmCompareType(value, tmat4x4):
            return (self[0] == value[0] and self[1] == value[1] and self[2] == value[2] and self[3] == value[3])
        else:
            try:
                return (self[0] == value[0] and self[1] == value[1] and self[2] == value[2] and self[3] == value[3])
            except:
                raise TypeError("unsupported operand type(s) for ==: 'tmat4x4' and '{}'".format(type(value)))

    def __ne__(self, value):
        if pyglmCompareType(value, tmat4x4):
            return (self[0] != value[0] or self[1] != value[1] or self[2] != value[2] or self[3] != value[3])
        else:
            try:
                return (self[0] != value[0] or self[1] != value[1] or self[2] != value[2] or self[3] != value[3])
            except:
                raise TypeError("unsupported operand type(s) for !=: 'tmat4x4' and '{}'".format(type(value)))

    def __add__(self, value):
        try:
            return tmat4x4(self.value + value)
        except:
            raise TypeError("unsupported operand type(s) for +: 'tmat4x4' and '{}'".format(type(value)))

    __radd__ = __add__

    def __sub__(self, value):
        try:
            return tmat4x4(self.value - value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tmat4x4' and '{}'".format(type(value)))

    def __rsub__(self, value):
        try:
            return tmat4x4(value - self.value)
        except:
            raise TypeError("unsupported operand type(s) for -: 'tmat4x4' and '{}'".format(type(value)))

    def __mul__(self, value):
        try:
            if hasattr(value, "__rmul__"):
                rmul = value.__rmul__
                
            if (hasattr(value, "glm_type") and value.glm_type == GLM_MAT):
                value = value.value
                
            if pyglmCompareType(value, self.row_type):
                return self.row_type(value.arr.reshape(4) * self.value)
            if type(value) == numpy.ndarray:
                return self.row_type(value.reshape(4) * self.value)

            if type(value) == numpy.matrixlib.defmatrix.matrix:
                if value.shape == (2,4):
                    return tmat2x4(value * self.value)
                if value.shape == (3,4):
                    return tmat3x4(value * self.value)
                if value.shape == (4,4):
                    return tmat4x4(value * self.value)
            
            if type(value) in dtypes:
                return tmat4x4(self.value * value)

            return rmul(self)
            
        except:
            raise TypeError("unsupported operand type(s) for *: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat4x4(self[0] * value,
##                         self[1] * value,
##                           self[2] * value,
##                           self[3] * value)
##        elif pyglmCompareType(value, self.row_type):
##            m = self
##            v = value
##            Mov0 = self.col_type(v[0])
##            Mov1 = self.col_type(v[1])
##            Mul0 = m[0] * Mov0
##            Mul1 = m[1] * Mov1
##            Add0 = Mul0 + Mul1
##            Mov2 = self.col_type(v[2])
##            Mov3 = self.col_type(v[3])
##            Mul2 = m[2] * Mov2
##            Mul3 = m[3] * Mov3
##            Add1 = Mul2 + Mul3
##            Add2 = Add0 + Add1
##            return Add2
##        elif pyglmCompareType(value, tmat4x4):
##            m1 = self
##            m2 = value
##            SrcA0 = m1[0]
##            SrcA1 = m1[1]
##            SrcA2 = m1[2]
##            SrcA3 = m1[3]
##
##            SrcB0 = m2[0]
##            SrcB1 = m2[1]
##            SrcB2 = m2[2]
##            SrcB3 = m2[3]
##            
##            Result = tmat4x4(0)
##            Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3]
##            Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3]
##            Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3]
##            Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3]
##            return Result
##        elif pyglmCompareType(value, tmat2x4):
##            m1 = self
##            m2 = value
##            return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
##			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
##			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
##			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
##			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
##			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
##			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
##			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3])
##        elif pyglmCompareType(value, tmat3x4):
##            m1 = self
##            m2 = value
##            return tmat3x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
##			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
##			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
##			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
##			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
##			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
##			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
##			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
##			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
##			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
##			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
##			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3])
##        else:
##            raise TypeError("unsupported operand type(s) for *: 'tmat4x4' and '{}'".format(type(value)))

    def __rmul__(self, value):
        try:
            if (hasattr(value, "glm_type") and value.glm_type == GLM_MAT):
                value = value.value
                
            if pyglmCompareType(value, self.col_type):
                return self.row_type(self.value * value.arr.reshape(4,1))
            if type(value) == numpy.ndarray:
                return self.row_type(self.value * value.reshape(4,1))

            if type(value) == numpy.matrixlib.defmatrix.matrix:
                if value.shape == (2,4):
                    return tmat2x4(self.value * value)
                if value.shape == (3,4):
                    return tmat3x4(self.value * value)
                if value.shape == (4,4):
                    return tmat4x4(self.value * value)
            
            return tmat4x4(self.value * value)
        except:
            raise TypeError("unsupported operand type(s) for *: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            return tmat4x4(self[0] * value,
##                         self[1] * value,
##                           self[2] * value,
##                           self[3] * value)
##        elif pyglmCompareType(value, self.col_type):
##            m = self
##            v = value
##            return self.row_type(m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
##			m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3],
##			m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3],
##			m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3])
##        elif pyglmCompareType(value, tmat4x4):
##            m1 = self
##            m2 = value
##            SrcA0 = m1[0]
##            SrcA1 = m1[1]
##            SrcA2 = m1[2]
##            SrcA3 = m1[3]
##
##            SrcB0 = m2[0]
##            SrcB1 = m2[1]
##            SrcB2 = m2[2]
##            SrcB3 = m2[3]
##            
##            Result = tmat4x4(0)
##            Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3]
##            Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3]
##            Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3]
##            Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3]
##            return Result
##        elif pyglmCompareType(value, tmat2x4):
##            m1 = self
##            m2 = value
##            return tmat2x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
##			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
##			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
##			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
##			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
##			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
##			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
##			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3])
##        elif pyglmCompareType(value, tmat3x4):
##            m1 = self
##            m2 = value
##            return tmat3x4(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
##			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
##			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
##			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
##			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
##			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
##			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
##			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
##			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
##			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
##			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
##			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3])
##        else:
##            raise TypeError("unsupported operand type(s) for *: 'tmat4x4' and '{}'".format(type(value)))

    def __truediv__(self, value):
        try:
            if pyglmCompareType(value, self.row_type):
                return self.row_type(inverse(self) * value)
            return self * inverse(value)
        except:
            try:
                return value.__rdiv__(self)
            except:
                raise TypeError("unsupported operand type(s) for /: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            value = float(value)
##            return tmat4x4(self[0] / value,
##                         self[1] / value,
##                           self[2] / value,
##                           self[3] / value)
##        elif pyglmCompareType(value, self.row_type):
##            return inverse(self) * value
##        elif pyglmCompareType(value, tmat4x4):
##            return self * inverse(value)
##        else:
##            try:
##                return self * inverse(value)
##            except:
##                raise TypeError("unsupported operand type(s) for /: 'tmat4x4' and '{}'".format(type(value)))

    def __rtruediv__(self, value):
        try:
            if pyglmCompareType(value, self.col_type):
                return self.col_type(value * inverse(self))
            return value * inverse(self)
        except:
            raise TypeError("unsupported operand type(s) for /: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            value = float(value)
##            return tmat4x4(value / self[0],
##                         value / self[1],
##                           value / self[2])
##        elif pyglmCompareType(value, self.col_type):
##            return value * inverse(self)
##        elif pyglmCompareType(value, tmat4x4):
##            return self * inverse(value)
##        else:
##            try:
##                return value * inverse(self)
##            except:
##                raise TypeError("unsupported operand type(s) for /: 'tmat4x4' and '{}'".format(type(value)))

    __div__ = __truediv__

    __rdiv__ = __rtruediv__

    # __i*__ functions
    def __iadd__(self, value):
        try:
            self.value += value
        except:
            raise TypeError("unsupported operand type(s) for +=: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] += value
##            self[1] += value
##            self[2] += value
##            self[3] += value
##        elif pyglmCompareType(value, tmat4x4):
##            self[0] += value[0]
##            self[1] += value[1]
##            self[2] += value[2]
##            self[3] += value[3]
##        else:
##            try:
##                self[0] += value[0]
##                self[1] += value[1]
##                self[2] += value[2]
##                self[3] += value[3]
##            except:
##                raise TypeError("unsupported operand type(s) for +=: 'tmat4x4' and '{}'".format(type(value)))
        return self

    def __isub__(self, value):
        try:
            self.value -= value
        except:
            raise TypeError("unsupported operand type(s) for -=: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] -= value
##            self[1] -= value
##            self[2] -= value
##            self[3] -= value
##        elif pyglmCompareType(value, tmat4x4):
##            self[0] -= value[0]
##            self[1] -= value[1]
##            self[2] -= value[2]
##            self[3] -= value[3]
##        else:
##            try:
##                self[0] -= value[0]
##                self[1] -= value[1]
##                self[2] -= value[2]
##                self[3] -= value[3]
##            except:
##                raise TypeError("unsupported operand type(s) for -=: 'tmat4x4' and '{}'".format(type(value)))
        return self

    def __imul__(self, value):
        try:
            self.value *= value
        except:
            raise TypeError("unsupported operand type(s) for *=: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] *= value
##            self[1] *= value
##            self[2] *= value
##            self[3] *= value
##        elif pyglmCompareType(value, tmat4x4):
##            self.value = (self * value).value
##        else:
##            try:
##                self[0] *= value[0]
##                self[1] *= value[1]
##                self[2] *= value[2]
##                self[3] *= value[3]
##            except:
##                raise TypeError("unsupported operand type(s) for *=: 'tmat4x4' and '{}'".format(type(value)))
        return self

    def __itruediv__(self, value):
        try:
            self.value *= inverse(value)
        except:
            raise TypeError("unsupported operand type(s) for /=: 'tmat4x4' and '{}'".format(type(value)))
##        if type(value) in dtypes:
##            self[0] /= float(value)
##            self[1] /= float(value)
##            self[2] /= float(value)
##            self[3] /= float(value)
##        elif pyglmCompareType(value, tmat4x4):
##            self *= inverse(value)
##        else:
##            try:
##                self *= inverse(value)
##            except:
##                raise TypeError("unsupported operand type(s) for /=: 'tmat4x4' and '{}'".format(type(value)))
        return self

    __idiv__ = __itruediv__
    
    def __pos__(self):
        return self

    def __neg__(self):
        return tmat4x4(-self.value)

    def __abs__(self):
        return tmat4x4(abs(self.value))

##    def __invert__(self):
##        return invert(self)

    def __getitem__(self, key):
        if type(key) == slice:
            raise TypeError("tmat4x4 doesn't support slices")
        elif type(key) == tuple and len(key) == 2:
            return self.value[key[0], key[1]]
        else:
            if key in (0,-4):
                return self.col_type(self.value[0])
            elif key in (1,-3):
                return self.col_type(self.value[1])
            elif key in (2,-2):
                return self.col_type(self.value[2])
            elif key in (3,-1):
                return self.col_type(self.value[3])
            else:
                raise IndexError("tmat4x4 index out of range")

    def __array__(self, *args, **kw):
        return numpy.matrix(self.value, *args, **kw)

##    def __setitem__(self, key, value):
##        if type(key) == slice:
##            raise TypeError("tmat4x4 doesn't support slices")
##        else:
##            if key in (0,-4):
##                self.value[0] = value
##            elif key in (1,-3):
##                self.value[1] = value
##            elif key in (2,-2):
##                self.value[2] = value
##            elif key in (3,-1):
##                self.value[3] = value
##            else:
##                raise IndexError("tmat4x4 index out of range")

    def __str__(self):
        return "tmat4x4( {}, {}, {}, {},\n         {}, {}, {}, {},\n         {}, {}, {}, {},\n         {}, {}, {}, {} )".format(self[0,0], self[0,1], self[0,2], self[0,3],
                                                                             self[1,0], self[1,1], self[1,2], self[1,3],
                                                                             self[2,0], self[2,1], self[2,2], self[2,3],
                                                                                                self[3,0], self[3,1], self[3,2], self[3,3])

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
