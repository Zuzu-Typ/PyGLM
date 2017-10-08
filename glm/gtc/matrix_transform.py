from ..detail.type_mat4x4 import tmat4x4
from ..detail.type_vec2 import tvec2
from ..detail.type_vec3 import tvec3
from ..detail.type_vec4 import tvec4
from .constants import *
from ..detail.setup import *
from ..detail.func_geometric import *
from ..detail.func_trigonometric import *
from ..detail.func_matrix import *

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and not defined("GLM_EXT_INCLUDED"):
    message("GLM: GLM_GTC_matrix_transform extension included")
    
def translate(m, v):
    Result = tmat4x4(m)
    Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3]
    return Result

def rotate(m, angle, v):
    a = angle
    c = cos(a)
    s = sin(a)

    axis = normalize(v)
    temp = tvec3(((1) - c) * axis)
    
    Rotate = tmat3x3(c + temp[0] * axis[0],temp[0] * axis[1] + s * axis[2],temp[0] * axis[2] - s * axis[1],
                     temp[1] * axis[0] - s * axis[2],c + temp[1] * axis[1],temp[1] * axis[2] + s * axis[0],
                     temp[2] * axis[0] + s * axis[1],temp[2] * axis[1] - s * axis[0],c + temp[2] * axis[2])
##    Rotate[0,0:3] = (c + temp[0] * axis[0],
##                     temp[0] * axis[1] + s * axis[2],
##                     temp[0] * axis[2] - s * axis[1])
##
##    Rotate[1,0:3] = (temp[1] * axis[0] - s * axis[2],
##                     c + temp[1] * axis[1],
##                     temp[1] * axis[2] + s * axis[0])
##
##    Rotate[2,0:3] = (temp[2] * axis[0] + s * axis[1],
##                     temp[2] * axis[1] - s * axis[0],
##                     c + temp[2] * axis[2])
    
    return tmat4x4(m[0] * Rotate[0, 0] + m[1] * Rotate[0, 1] + m[2] * Rotate[0, 2],
                     m[0] * Rotate[1, 0] + m[1] * Rotate[1, 1] + m[2] * Rotate[1, 2],
                     m[0] * Rotate[2, 0] + m[1] * Rotate[2, 1] + m[2] * Rotate[2, 2],
                     m[3])

def rotate_slow(m, angle, v):
    a = angle
    c = cos(a)
    s = sin(a)
    Result = tmat4x4()

    axis = normalize(v)

    Result[0,0] = c + ((1) - c)      * axis.x     * axis.x
    Result[0,1] = ((1) - c) * axis.x * axis.y + s * axis.z
    Result[0,2] = ((1) - c) * axis.x * axis.z - s * axis.y
    Result[0,3] = (0)

    Result[1,0] = ((1) - c) * axis.y * axis.x - s * axis.z
    Result[1,1] = c + ((1) - c) * axis.y * axis.y
    Result[1,2] = ((1) - c) * axis.y * axis.z + s * axis.x
    Result[1,3] = (0)

    Result[2,0] = ((1) - c) * axis.z * axis.x + s * axis.y
    Result[2,1] = ((1) - c) * axis.z * axis.y - s * axis.x
    Result[2,2] = c + ((1) - c) * axis.z * axis.z
    Result[2,3] = (0)

    Result[3] = (0, 0, 0, 1)
    return m * Result

def scale(m, v):
    return tmat4x4(m[0] * v[0],
                     m[1] * v[1],
                     m[2] * v[2],
                     m[3])

def scale_slow(m, v):
    Result = tmat4x4((1))
    Result[0,0] = v.x
    Result[1,1] = v.y
    Result[2,2] = v.z
    return m * Result

def ortho(left, right, bottom, top, zNear=None, zFar=None):
    if type(zNear) == type(zFar) == type(None):
        Result = tmat4x4((1))
        Result[0, 0] = (2.) / (right - left)
        Result[1, 1] = (2.) / (top - bottom)
        Result[2, 2] = - (1.)
        Result[3, 0] = - (right + left) / (right - left)
        Result[3, 1] = - (top + bottom) / (top - bottom)
        return Result
    
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        return orthoLH(left, right, bottom, top, zNear, zFar)
    else:
        return orthoRH(left, right, bottom, top, zNear, zFar)

def orthoLH(left, right, bottom, top, zNear, zFar):
    Result = tmat4x4(1)
    Result[0, 0] = (2.) / (right - left)
    Result[1, 1] = (2.) / (top - bottom)
    Result[3, 0] = - (right + left) / (right - left)
    Result[3, 1] = - (top + bottom) / (top - bottom)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = (1.) / (zFar - zNear)
        Result[3, 2] = - zNear / (zFar - zNear)
    else:
        Result[2, 2] = (2.) / (zFar - zNear)
        Result[3, 2] = - (zFar + zNear) / (zFar - zNear)

    return Result

def orthoRH(left, right, bottom, top, zNear, zFar):
    Result = tmat4x4(1)
    Result[0, 0] = (2.) / (right - left)
    Result[1, 1] = (2.) / (top - bottom)
    Result[3, 0] = - (right + left) / (right - left)
    Result[3, 1] = - (top + bottom) / (top - bottom)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = - (1.) / (zFar - zNear)
        Result[3, 2] = - zNear / (zFar - zNear)
    else:
        Result[2, 2] = - (2.) / (zFar - zNear)
        Result[3, 2] = - (zFar + zNear) / (zFar - zNear)

    return Result

def frustum(left, right, bottom, top, nearVal, farVal):
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        return frustumLH(left, right, bottom, top, nearVal, farVal)
    else:
        return frustumRH(left, right, bottom, top, nearVal, farVal)

def frustumLH(left, right, bottom, top, nearVal, farVal):
    Result = tmat4x4(0)
    Result[0, 0] = ((2.) * nearVal) / (right - left)
    Result[1, 1] = ((2.) * nearVal) / (top - bottom)
    Result[2, 0] = (right + left) / (right - left)
    Result[2, 1] = (top + bottom) / (top - bottom)
    Result[2, 3] = (1.)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = farVal / (farVal - nearVal)
        Result[3, 2] = -(farVal * nearVal) / (farVal - nearVal)
    else:
        Result[2, 2] = (farVal + nearVal) / (farVal - nearVal)
        Result[3, 2] = - ((2.) * farVal * nearVal) / (farVal - nearVal)

    return Result

def frustumRH(left, right, bottom, top, nearVal, farVal):
    Result = tmat4x4(0)
    Result[0, 0] = ((2.) * nearVal) / (right - left)
    Result[1, 1] = ((2.) * nearVal) / (top - bottom)
    Result[2, 0] = (right + left) / (right - left)
    Result[2, 1] = (top + bottom) / (top - bottom)
    Result[2, 3] = (-1.)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = farVal / (nearVal - farVal)
        Result[3, 2] = -(farVal * nearVal) / (farVal - nearVal)
    else:
        Result[2, 2] = - (farVal + nearVal) / (farVal - nearVal)
        Result[3, 2] = - ((2.) * farVal * nearVal) / (farVal - nearVal)

    return Result

def perspective(fovy, aspect, zNear, zFar):
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        return perspectiveLH(fovy, aspect, zNear, zFar)
    else:
        return perspectiveRH(fovy, aspect, zNear, zFar)

def perspectiveRH(fovy, aspect, zNear, zFar):
    assert(abs(aspect - epsilon()) > (0));

    tanHalfFovy = tan(fovy / (2))

    Result = tmat4x4((0))
    Result[0, 0] = (1.) / (aspect * tanHalfFovy)
    Result[1, 1] = (1.) / (tanHalfFovy)
    Result[2, 3] = - (1.)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = zFar / (zNear - zFar)
        Result[3, 2] = -(zFar * zNear) / (zFar - zNear)
    else:
        Result[2, 2] = - (zFar + zNear) / (zFar - zNear)
        Result[3, 2] = - ((2.) * zFar * zNear) / (zFar - zNear)

    return Result

def perspectiveLH(fovy, aspect, zNear, zFar):
    assert(abs(aspect - epsilon()) > (0))

    tanHalfFovy = tan(fovy / (2.))
    
    Result = tmat4x4((0))
    Result[0, 0] = (1.) / (aspect * tanHalfFovy)
    Result[1, 1] = (1.) / (tanHalfFovy)
    Result[2, 3] = (1.)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = zFar / (zFar - zNear)
        Result[3, 2] = -(zFar * zNear) / (zFar - zNear)
    else:
        Result[2, 2] = (zFar + zNear) / (zFar - zNear)
        Result[3, 2] = - ((2.) * zFar * zNear) / (zFar - zNear)

    return Result

def perspectiveFov(fov, width, height, zNear, zFar):
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        return perspectiveFovLH(fov, width, height, zNear, zFar)
    else:
        return perspectiveFovRH(fov, width, height, zNear, zFar)

def perspectiveFovRH(fov, width, height, zNear, zFar):
    assert(width > (0))
    assert(height > (0))
    assert(fov > (0))

    rad = fov;
    h = cos((0.5) * rad) / sin((0.5) * rad)
    w = h * height / width

    Result = tmat4x4((0))
    Result[0, 0] = w
    Result[1, 1] = h
    Result[2, 3] = - 1.

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = zFar / (zNear - zFar)
        Result[3, 2] = -(zFar * zNear) / (zFar - zNear)
    else:
        Result[2, 2] = - (zFar + zNear) / (zFar - zNear)
        Result[3, 2] = - ((2.) * zFar * zNear) / (zFar - zNear)

    return Result

def perspectiveFovLH(fov, width, height, zNear, zFar):
    assert(width > (0))
    assert(height > (0))
    assert(fov > (0))

    rad = fov
    h = cos((0.5) * rad) / sin((0.5) * rad)
    w = h * height / width

    Result = tmat4x4((0))
    Result[0, 0] = w
    Result[1, 1] = h
    Result[2, 3] = (1.)

    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        Result[2, 2] = zFar / (zFar - zNear)
        Result[3, 2] = -(zFar * zNear) / (zFar - zNear)
    else:
        Result[2, 2] = (zFar + zNear) / (zFar - zNear)
        Result[3, 2] = - ((2.) * zFar * zNear) / (zFar - zNear)

    return Result

def infinitePerspective(fovy, aspect, zNear):
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        return infinitePerspectiveLH(fovy, aspect, zNear)
    else:
        return infinitePerspectiveRH(fovy, aspect, zNear)

def infinitePerspectiveRH(fovy, aspect, zNear):
    range = tan(fovy / (2.)) * zNear
    left = -range * aspect
    right = range * aspect
    bottom = -range
    top = range

    Result = tmat4x4((0))
    Result[0, 0] = ((2.) * zNear) / (right - left)
    Result[1, 1] = ((2.) * zNear) / (top - bottom)
    Result[2, 2] = - (1.)
    Result[2, 3] = - (1.)
    Result[3, 2] = - (2.) * zNear
    return Result

def infinitePerspectiveLH(fovy, aspect, zNear):
    range = tan(fovy / (2.)) * zNear
    left = -range * aspect
    right = range * aspect
    bottom = -range
    top = range

    Result = tmat4x4((0))
    Result[0, 0] = ((2.) * zNear) / (right - left)
    Result[1, 1] = ((2.) * zNear) / (top - bottom)
    Result[2, 2] = (1.)
    Result[2, 3] = (1.)
    Result[3, 2] = - (2.) * zNear
    return Result

def tweakedInfinitePerspective(fovy, aspect, zNear, ep = None):
    if type(ep) == type(None):
        ep = epsilon()
    
    range = tan(fovy / (2.)) * zNear
    left = -range * aspect
    right = range * aspect
    bottom = -range
    top = range

    Result = tmat4x4((0))
    Result[0, 0] = ((2.) * zNear) / (right - left)
    Result[1, 1] = ((2.) * zNear) / (top - bottom)
    Result[2, 2] = ep - (1.)
    Result[2, 3] = (-1.)
    Result[3, 2] = (ep - (2.)) * zNear
    return Result

def project(obj, model, proj, viewport):
    tmp = tvec4(obj, (1))
    tmp = model * tmp
    tmp = proj * tmp

    tmp /= tmp.w
    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        tmp.x = tmp.x * (0.5) + (0.5)
        tmp.y = tmp.y * (0.5) + (0.5)
    else:
        tmp = tmp * (0.5) + (0.5)
    tmp[0] = tmp[0] * (viewport[2]) + (viewport[0])
    tmp[1] = tmp[1] * (viewport[3]) + (viewport[1])

    return tvec3(tmp)

def unProject(win, model, proj, viewport):
    Inverse = inverse(proj * model)

    tmp = tvec4(win, (1.))
    tmp.x = (tmp.x - (viewport[0])) / (viewport[2])
    tmp.y = (tmp.y - (viewport[1])) / (viewport[3])
    if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE:
        tmp.x = tmp.x * (2.) - (1.)
        tmp.y = tmp.y * (2.) - (1.)
    else:
        tmp = tmp * (2.) - (1.)

    obj = Inverse * tmp
    obj /= obj.w

    return tvec3(obj)

def pickMatrix(center, delta, viewport):
    assert(delta.x > (0) and delta.y > (0))
    Result = tmat4x4((1))

    if(not (delta.x > (0) and delta.y > (0))):
        return Result # Error

    Temp = tvec3(
        ((viewport[2]) - (2.) * (center.x - (viewport[0]))) / delta.x,
        ((viewport[3]) - (2.) * (center.y - (viewport[1]))) / delta.y,
        (0))

    # Translate and scale the picked region to the entire window
    Result = translate(Result, Temp)
    return scale(Result, tvec3((viewport[2]) / delta.x, (viewport[3]) / delta.y, (1.)))

def lookAt(eye, center, up):
    if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED:
        return lookAtLH(eye, center, up)
    else:
        return lookAtRH(eye, center, up)

def lookAtRH(eye, center, up):
    f = tvec3(normalize(center - eye))
    s = tvec3(normalize(cross(f, up)))
    u = tvec3(cross(s, f))

    Result = tmat4x4(1)
    Result[0, 0] = s.x
    Result[1, 0] = s.y
    Result[2, 0] = s.z
    Result[0, 1] = u.x
    Result[1, 1] = u.y
    Result[2, 1] = u.z
    Result[0, 2] =-f.x
    Result[1, 2] =-f.y
    Result[2, 2] =-f.z
    Result[3, 0] =-dot(s, eye)
    Result[3, 1] =-dot(u, eye)
    Result[3, 2] = dot(f, eye)
    return Result

def lookAtLH(eye, center, up):
    f = tvec3(normalize(center - eye))
    s = tvec3(normalize(cross(up, f)))
    u = tvec3(cross(f, s))

    Result = tmat4x4(1)
    Result[0, 0] = s.x
    Result[1, 0] = s.y
    Result[2, 0] = s.z
    Result[0, 1] = u.x
    Result[1, 1] = u.y
    Result[2, 1] = u.z
    Result[0, 2] = f.x
    Result[1, 2] = f.y
    Result[2, 2] = f.z
    Result[3, 0] = -dot(s, eye)
    Result[3, 1] = -dot(u, eye)
    Result[3, 2] = -dot(f, eye)
    return Result
