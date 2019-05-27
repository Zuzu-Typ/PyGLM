import glm, sys

v1 = glm.vec1()
v2 = glm.vec2()
v3 = glm.vec3()
v4 = glm.vec4()

vectors = [v1, v2, v3, v4]

vector_types = [glm.vec1, glm.vec2, glm.vec3, glm.vec4]

m22 = glm.mat2x2()
m23 = glm.mat2x3()
m24 = glm.mat2x4()
m32 = glm.mat3x2()
m33 = glm.mat3x3()
m34 = glm.mat3x4()
m42 = glm.mat4x2()
m43 = glm.mat4x3()
m44 = glm.mat4x4()

matrices = [m22, m23, m24, m32, m33, m34, m42, m43, m44]

matrix_types = [glm.mat2x2, glm.mat2x3, glm.mat2x4, glm.mat3x2, glm.mat3x3, glm.mat3x4, glm.mat4x2, glm.mat4x3, glm.mat4x4]

q = glm.quat()

all_types = vector_types + matrix_types + [glm.quat]

all_type_objects = vectors + matrices + [q]

get_obj_generator = lambda types: (x() for x in types)

class FAssertionError(Exception):
    pass

def fassert(func, args):
    try:
        func(*args)
    except:
        raise FAssertionError("{} raised {} with {}".format(func, sys.exc_info()[1], repr(args)))

# Initialization #
## vec2
for args in [(), (1,), (1, 2), (v2,), (v3,), (v4,)]:
    fassert(glm.vec2, args)

## vec3
for args in [(), (1,), (1, 2, 3), (v2, 1), (1, v2), (v3,), (v4,)]:
    fassert(glm.vec3, args)

## vec4
for args in [(), (1,), (1, 2, 3, 4), (v2, 1, 2), (1, v2 ,2), (v2, 1, 2), (v3, 1), (1, v3), (v4,)]:
    fassert(glm.vec4, args)

## mat2x2
for args in [(), (1,), (1, 2, 3, 4), (v2, v2)] + [(x,) for x in matrices]:
    fassert(glm.mat2x2, args)

## mat2x3
for args in [(), (1,), (1, 2, 3, 4, 5, 6), (v3, v3)] + [(x,) for x in matrices]:
    fassert(glm.mat2x3, args)

## mat2x4
for args in [(), (1,), (1, 2, 3, 4, 5, 6, 7, 8), (v4, v4)] + [(x,) for x in matrices]:
    fassert(glm.mat2x4, args)

## mat3x2
for args in [(), (1,), (1, 2, 3, 4, 5, 6), (v2, v2, v2)] + [(x,) for x in matrices]:
    fassert(glm.mat3x2, args)

## mat3x3
for args in [(), (1,), (1, 2, 3, 4, 5, 6, 7, 8, 9), (v3, v3, v3)] + [(x,) for x in matrices]:
    fassert(glm.mat3x3, args)

## mat3x4
for args in [(), (1,), (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12), (v4, v4, v4)] + [(x,) for x in matrices]:
    fassert(glm.mat3x4, args)

## mat4x2
for args in [(), (1,), (1, 2, 3, 4, 5, 6, 7, 8), (v2, v2, v2, v2)] + [(x,) for x in matrices]:
    fassert(glm.mat4x2, args)

## mat4x3
for args in [(), (1,), (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12), (v3, v3, v3, v3)] + [(x,) for x in matrices]:
    fassert(glm.mat4x3, args)

## mat4x4
for args in [(), (1,), (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16), (v4, v4, v4, v4)] + [(x,) for x in matrices]:
    fassert(glm.mat4x4, args)

## quat
for args in [(), (q,), (v3,), (m33,), (m44,), (1, v3), (v3, v3), (1, 2, 3, 4)]:
    fassert(glm.quat, args)
#/Initialization #

# neg #
for obj in get_obj_generator(all_types):
    fassert(obj.__neg__, ())
#/neg #

# pos #
for obj in get_obj_generator(all_types):
    fassert(obj.__pos__, ())
#/pos #

# abs #
for obj in get_obj_generator(vector_types):
    fassert(obj.__abs__, ())
#/abs #

# add #
for obj in get_obj_generator(all_types):
    fassert(obj.__add__, (obj,))
#/add #

# sub #
for obj in get_obj_generator(all_types):
    fassert(obj.__sub__, (obj,))
#/sub #

# mul #
for obj in get_obj_generator(all_types):
    fassert(obj.__mul__, (1,))
#/mul #

# div #
for obj in get_obj_generator(all_types):
    fassert(obj.__truediv__, (1,))
#/div #

# mod #
for obj in get_obj_generator(vector_types):
    fassert(obj.__mod__, (1,))
#/mod #

# floordiv #
for obj in get_obj_generator(vector_types):
    fassert(obj.__floordiv__, (1,))
#/floordiv #

# divmod #
for obj in get_obj_generator(vector_types):
    fassert(obj.__divmod__, (1,))
#/divmod #

# pow #
for obj in get_obj_generator(vector_types):
    fassert(obj.__pow__, (obj,))
    fassert(obj.__pow__, (obj, obj))
#/pow #

# iadd #
for obj in get_obj_generator(all_types):
    fassert(obj.__iadd__, (obj,))
#/iadd #

# isub #
for obj in get_obj_generator(all_types):
    fassert(obj.__isub__, (obj,))
#/isub #

# imul #
for obj in get_obj_generator(all_types):
    fassert(obj.__imul__, (1,))
#/imul #

# idiv #
for obj in get_obj_generator(all_types):
    fassert(obj.__itruediv__, (1,))
#/idiv #

# imod #
for obj in get_obj_generator(vector_types):
    fassert(obj.__imod__, (1,))
#/imod #

# ifloordiv #
for obj in get_obj_generator(vector_types):
    fassert(obj.__ifloordiv__, (1,))
#/ifloordiv #
    
# ipow #
for obj in get_obj_generator(vector_types):
    fassert(obj.__ipow__, (obj,))
#/ipow #

# str #
for obj in get_obj_generator(all_types):
    assert str(obj), obj
#/str #

# repr #
for obj in get_obj_generator(all_types):
    assert repr(obj), obj
#/repr #

# len #
for obj in get_obj_generator(all_types):
    assert len(obj), obj
#/len #

# getitem #
for obj in get_obj_generator(all_types):
    for i in range(len(obj)):
        assert obj[i] != None, obj
#/getitem #
        
# setitem #
for obj in get_obj_generator(all_types):
    for i in range(len(obj)):
        fassert(obj.__setitem__,(i, obj[i]))
#/setitem #

# contains #
for obj in get_obj_generator(all_types):
    assert obj[0] in obj, obj
#/contains #

# Richcompare #
## EQ
for obj in get_obj_generator(all_types):
    assert obj == type(obj)(obj), obj

## NE
for obj in get_obj_generator(vector_types + matrix_types):
    assert obj != (obj + 1), obj
assert q != (1,0,0,0)
## LT
for obj in get_obj_generator(vector_types):
    assert all(obj < (obj + 1)) and not any(obj < obj), obj

## LE
for obj in get_obj_generator(vector_types):
    assert all(obj <= obj) and all(obj <= (obj + 1)) and not any(obj <= (obj - 1)), obj
## GT
for obj in get_obj_generator(vector_types):
    assert all(obj > (obj - 1)) and not any(obj > obj), obj

## GE
for obj in get_obj_generator(vector_types):
    assert all(obj >= obj) and all(obj >= (obj - 1)) and not any(obj >= (obj + 1)), obj
#/Richcompare #

# iter #
for obj in get_obj_generator(all_types):
    fassert(iter, (obj,))
#/iter #

