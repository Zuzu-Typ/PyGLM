from ..detail.setup import *
from ..detail.func_matrix import *
from ..detail.type_mat2x2 import tmat2x2
from ..detail.type_mat3x3 import tmat3x3
from ..detail.type_mat4x4 import tmat4x4

def affineInverse(m):
    if isinstance(m, tmat3x3):
        Inv = tmat2x2(inverse(tmat2x2(m)))
        return tmat3x3(tvec3(Inv[0], 0),
                       tvec3(Inv[1], 0),
                       tvec3(-Inv * tvec2(m[2]), 1))
    elif isinstance(m, tmat4x4):
        Inv = tmat3x3(inverse(tmat3x3(m)))

        return tmat4x4(
            tvec4(Inv[0], (0)),
            tvec4(Inv[1], (0)),
            tvec4(Inv[2], (0)),
            tvec4(-Inv * tvec3(m[3]), (1)))

def inverseTranspose(m):
    if isinstance(m, tmat2x2):
        Determinant = m[0][0] * m[1][1] - m[1][0] * m[0][1]
        
        Inverse = tmat2x2(
            + m[1][1] / Determinant,
            - m[0][1] / Determinant,
            - m[1][0] / Determinant,
            + m[0][0] / Determinant)

        return Inverse

    elif isinstance(m, tmat3x3):
        Determinant = + m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0])

        Inverse = tmat3x3(0)
        Inverse[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2])
        Inverse[0][1] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2])
        Inverse[0][2] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1])
        Inverse[1][0] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2])
        Inverse[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2])
        Inverse[1][2] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1])
        Inverse[2][0] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2])
        Inverse[2][1] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2])
        Inverse[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1])
        Inverse /= Determinant

        return Inverse

    elif isinstance(m, tmat4x4):
        SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3]
        SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3]
        SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2]
        SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3]
        SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2]
        SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1]
        SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3]
        SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3]
        SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2]
        SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3]
        SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2]
        SubFactor11 = m[1][1] * m[3][3] - m[3][1] * m[1][3]
        SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1]
        SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3]
        SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3]
        SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2]
        SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3]
        SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2]
        SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1]
        
        Inverse = tmat4x4(0)
        Inverse[0][0] = + (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02)
        Inverse[0][1] = - (m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04)
        Inverse[0][2] = + (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05)
        Inverse[0][3] = - (m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05)

        Inverse[1][0] = - (m[0][1] * SubFactor00 - m[0][2] * SubFactor01 + m[0][3] * SubFactor02)
        Inverse[1][1] = + (m[0][0] * SubFactor00 - m[0][2] * SubFactor03 + m[0][3] * SubFactor04)
        Inverse[1][2] = - (m[0][0] * SubFactor01 - m[0][1] * SubFactor03 + m[0][3] * SubFactor05)
        Inverse[1][3] = + (m[0][0] * SubFactor02 - m[0][1] * SubFactor04 + m[0][2] * SubFactor05)

        Inverse[2][0] = + (m[0][1] * SubFactor06 - m[0][2] * SubFactor07 + m[0][3] * SubFactor08)
        Inverse[2][1] = - (m[0][0] * SubFactor06 - m[0][2] * SubFactor09 + m[0][3] * SubFactor10)
        Inverse[2][2] = + (m[0][0] * SubFactor11 - m[0][1] * SubFactor09 + m[0][3] * SubFactor12)
        Inverse[2][3] = - (m[0][0] * SubFactor08 - m[0][1] * SubFactor10 + m[0][2] * SubFactor12)

        Inverse[3][0] = - (m[0][1] * SubFactor13 - m[0][2] * SubFactor14 + m[0][3] * SubFactor15)
        Inverse[3][1] = + (m[0][0] * SubFactor13 - m[0][2] * SubFactor16 + m[0][3] * SubFactor17)
        Inverse[3][2] = - (m[0][0] * SubFactor14 - m[0][1] * SubFactor16 + m[0][3] * SubFactor18)
        Inverse[3][3] = + (m[0][0] * SubFactor15 - m[0][1] * SubFactor17 + m[0][2] * SubFactor18)

        Determinant = + m[0][0] * Inverse[0][0] + m[0][1] * Inverse[0][1] + m[0][2] * Inverse[0][2] + m[0][3] * Inverse[0][3]

        Inverse /= Determinant

        return Inverse
