from .setup import *

import numpy

def matrixCompMult(x, y):
    return x.__class__(numpy.array(x) * numpy.array(y))

def transpose(m):
    return m.__class__(m.value.T)
##    if isinstance(m, tmat2x2):
##        result = tmat2x2(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        return result
##    
##    elif isinstance(m, tmat2x3):
##        result = tmat3x2(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[2][0] = m[0][2]
##        result[2][1] = m[1][2]
##        return result
##
##    elif isinstance(m, tmat2x4):
##        result = tmat4x2(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[2][0] = m[0][2]
##        result[2][1] = m[1][2]
##        result[3][0] = m[0][3]
##        result[3][1] = m[1][3]
##        return result
##
##    elif isinstance(m, tmat3x2):
##        result = tmat2x3(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[0][2] = m[2][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[1][2] = m[2][1]
##        return result
##
##    elif isinstance(m, tmat3x3):
##        result = tmat3x3(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[0][2] = m[2][0]
##
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[1][2] = m[2][1]
##
##        result[2][0] = m[0][2]
##        result[2][1] = m[1][2]
##        result[2][2] = m[2][2]
##        return result
##
##    elif isinstance(m, tmat3x4):
##        result = tmat4x3(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[0][2] = m[2][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[1][2] = m[2][1]
##        result[2][0] = m[0][2]
##        result[2][1] = m[1][2]
##        result[2][2] = m[2][2]
##        result[3][0] = m[0][3]
##        result[3][1] = m[1][3]
##        result[3][2] = m[2][3]
##        return result
##
##    elif isinstance(m, tmat4x2):
##        result = tmat2x4(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[0][2] = m[2][0]
##        result[0][3] = m[3][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[1][2] = m[2][1]
##        result[1][3] = m[3][1]
##        return result
##
##    elif isinstance(m, tmat4x3):
##        result = tmat3x4(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[0][2] = m[2][0]
##        result[0][3] = m[3][0]
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[1][2] = m[2][1]
##        result[1][3] = m[3][1]
##        result[2][0] = m[0][2]
##        result[2][1] = m[1][2]
##        result[2][2] = m[2][2]
##        result[2][3] = m[3][2]
##        return result
##
##    elif isinstance(m, tmat4x4):
##        result = tmat4x4(0)
##        result[0][0] = m[0][0]
##        result[0][1] = m[1][0]
##        result[0][2] = m[2][0]
##        result[0][3] = m[3][0]
##
##        result[1][0] = m[0][1]
##        result[1][1] = m[1][1]
##        result[1][2] = m[2][1]
##        result[1][3] = m[3][1]
##
##        result[2][0] = m[0][2]
##        result[2][1] = m[1][2]
##        result[2][2] = m[2][2]
##        result[2][3] = m[3][2]
##
##        result[3][0] = m[0][3]
##        result[3][1] = m[1][3]
##        result[3][2] = m[2][3]
##        result[3][3] = m[3][3]
##        return result

def determinant(m):
    return numpy.linalg.det(m)
##    if isinstance(m, tmat2x2):
##        return m[0][0] * m[1][1] - m[1][0] * m[0][1]
##    
##    elif isinstance(m, tmat3x3):
##        return + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2])
##
##    elif isinstance(m, tmat4x4):
##        SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3]
##        SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3]
##        SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2]
##        SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3]
##        SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2]
##        SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1]
##
##        DetCof = tvec4(+ (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02),
##                - (m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04),
##                + (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05),
##                - (m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05))
##
##        return m[0][0] * DetCof[0] + m[0][1] * DetCof[1] + m[0][2] * DetCof[2] + m[0][3] * DetCof[3]

def inverse(m):
    return m.__class__(numpy.linalg.inv(m))
##    if isinstance(m, tmat2x2):
##        OneOverDeterminant = 1. / (+ m[0][0] * m[1][1] - m[1][0] * m[0][1])
##
##        Inverse = tmat2x2(+ m[1][1] * OneOverDeterminant,
##            - m[0][1] * OneOverDeterminant,
##            - m[1][0] * OneOverDeterminant,
##            + m[0][0] * OneOverDeterminant)
##
##        return Inverse
##
##    elif isinstance(m, tmat3x3):
##        OneOverDeterminant = 1. / (+ m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2]) + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]))
##
##        Inverse = tmat3x3(0)
##        Inverse[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * OneOverDeterminant
##        Inverse[1][0] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2]) * OneOverDeterminant
##        Inverse[2][0] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * OneOverDeterminant
##        Inverse[0][1] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2]) * OneOverDeterminant
##        Inverse[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2]) * OneOverDeterminant
##        Inverse[2][1] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1]) * OneOverDeterminant
##        Inverse[0][2] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2]) * OneOverDeterminant
##        Inverse[1][2] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2]) * OneOverDeterminant
##        Inverse[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * OneOverDeterminant
##
##        return Inverse
##
##    elif isinstance(m, tmat4x4):
##        return tmat4x4(numpy.linalg.inv(m.value))
##        Coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3]
##        Coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3]
##        Coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3]
##
##        Coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3]
##        Coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3]
##        Coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3]
##
##        Coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2]
##        Coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2]
##        Coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2]
##
##        Coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3]
##        Coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3]
##        Coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3]
##
##        Coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2]
##        Coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2]
##        Coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2]
##
##        Coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1]
##        Coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1]
##        Coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1]
##
##        Fac0 = tvec4(Coef00, Coef00, Coef02, Coef03)
##        Fac1 = tvec4(Coef04, Coef04, Coef06, Coef07)
##        Fac2 = tvec4(Coef08, Coef08, Coef10, Coef11)
##        Fac3 = tvec4(Coef12, Coef12, Coef14, Coef15)
##        Fac4 = tvec4(Coef16, Coef16, Coef18, Coef19)
##        Fac5 = tvec4(Coef20, Coef20, Coef22, Coef23)
##
##        Vec0 = tvec4(m[1][0], m[0][0], m[0][0], m[0][0])
##        Vec1 = tvec4(m[1][1], m[0][1], m[0][1], m[0][1])
##        Vec2 = tvec4(m[1][2], m[0][2], m[0][2], m[0][2])
##        Vec3 = tvec4(m[1][3], m[0][3], m[0][3], m[0][3])
##
##        Inv0 = tvec4(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2)
##        Inv1 = tvec4(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4)
##        Inv2 = tvec4(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5)
##        Inv3 = tvec4(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5)
##
##        SignA = tvec4(+1., -1., +1., -1.)
##        SignB = tvec4(-1., +1., -1., +1.)
##        Inverse = tmat4x4(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB)
##
##        Row0 = tvec4(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0])
##
##        Dot0 = tvec4(m[0] * Row0)
##        Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w)
##
##        OneOverDeterminant = 1. / Dot1
##
##        return Inverse * OneOverDeterminant
        
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
from .type_mat4x4 import tmat4x4
