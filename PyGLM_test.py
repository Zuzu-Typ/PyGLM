import glm, sys, random, time, copy

glm.silence(0)

## type checking definitions ##
PyGLM_DT_UNKNOWN	= 0x0000000
PyGLM_DT_FLOAT		= 0x0000001
PyGLM_DT_DOUBLE		= 0x0000002
PyGLM_DT_INT		= 0x0000004
PyGLM_DT_UINT		= 0x0000008
PyGLM_DT_INT8		= 0x0000010
PyGLM_DT_UINT8		= 0x0000020
PyGLM_DT_INT16		= 0x0000040
PyGLM_DT_UINT16		= 0x0000080
PyGLM_DT_INT64		= 0x0000100
PyGLM_DT_UINT64		= 0x0000200
PyGLM_DT_BOOL		= 0x0000400

PyGLM_SHAPE_2x2		= 0x0000800
PyGLM_SHAPE_2x3		= 0x0001000
PyGLM_SHAPE_2x4		= 0x0002000
PyGLM_SHAPE_3x2		= 0x0004000
PyGLM_SHAPE_3x3		= 0x0008000
PyGLM_SHAPE_3x4		= 0x0010000
PyGLM_SHAPE_4x2		= 0x0020000
PyGLM_SHAPE_4x3		= 0x0040000
PyGLM_SHAPE_4x4		= 0x0080000

PyGLM_SHAPE_1		= 0x0100000
PyGLM_SHAPE_2		= 0x0200000
PyGLM_SHAPE_3		= 0x0400000
PyGLM_SHAPE_4		= 0x0800000

PyGLM_T_VEC			= 0x1000000
PyGLM_T_MVEC		= 0x2000000
PyGLM_T_MAT			= 0x4000000
PyGLM_T_QUA			= 0x8000000

PyGLM_T_NUMBER		= 0x10000000

PyGLM_T_ANY_VEC	    = (PyGLM_T_VEC | PyGLM_T_MVEC)
PyGLM_T_ANY_ARR	    = (PyGLM_T_ANY_VEC | PyGLM_T_QUA)

PyGLM_SHAPE_SQUARE  = (PyGLM_SHAPE_2x2 | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4)

PyGLM_SHAPE_2xM	    = (PyGLM_SHAPE_2x2 | PyGLM_SHAPE_2x3 | PyGLM_SHAPE_2x4)
PyGLM_SHAPE_3xM	    = (PyGLM_SHAPE_3x2 | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_3x4)
PyGLM_SHAPE_4xM	    = (PyGLM_SHAPE_4x2 | PyGLM_SHAPE_4x3 | PyGLM_SHAPE_4x4)

PyGLM_DT_ALL	    = ((1 << 11) - 1)
PyGLM_SHAPE_ALL		= (((1 << 13) - 1) << 11)
PyGLM_T_ALL			= (((1 << 5) - 1) << 24)

PyGLM_ALL           = (PyGLM_DT_ALL | PyGLM_SHAPE_ALL | PyGLM_T_ALL)
##/type checking definitions ##

#def get_info(num):
#    glob = globals()
#    vars_ = [x for x in glob if x.startswith("PyGLM_") and not "ANY" in x and not "xM" in x and not "ALL" in x and not "SQUARE" in x]
#    out = []
#    for var in vars_:
#        if (glob[var] & num):
#            out.append(var)

#    return ", ".join(out)

#def get_info_of(obj):
#    return get_info(glm._get_type_info(PyGLM_ALL, obj))

#gio = get_info_of

print("Testing PyGLM...")
start_time = time.time()

datatypes = ("float", "double", "int", "glm::uint", "glm::i64", "glm::u64", "glm::i16", "glm::u16", "glm::i8", "glm::u8", "bool")
prefixes = ("f", "d", "i", "u", "i64", "u64", "i16", "u16", "i8", "u8", "b")

suffixes = "fFiIqQsSuUB"

vector_type_ids = tuple(range(len(datatypes)))

matrix_type_ids = tuple(range(4))

quat_type_ids = tuple(range(2))

vector_type_dict = {}

vector_length_dict = {}

vector_types = []

matrix_type_dict = {}

matrix_length_dict = {}

matrix_types = []

quat_type_dict = {}

quat_types = []

for type_id in vector_type_ids:
    vector_type_dict[type_id] = []
    this_list = vector_type_dict[type_id]

    for L in range(1, 5):
        tp = getattr(glm, "{T}vec{L}".format(T=prefixes[type_id], L=L))
        vll = vector_length_dict.get(L, [])
        vll.append(tp)
        vector_length_dict[L] = vll
        this_list.append(tp)

    vector_types += this_list


for type_id in matrix_type_ids:
    matrix_type_dict[type_id] = []
    this_list = matrix_type_dict[type_id]

    for C in range(2, 5):
        for R in range(2, 5):
            tp = getattr(glm, "{T}mat{C}x{R}".format(T=prefixes[type_id], C=C, R=R))
            mll = matrix_length_dict.get((C,R), [])
            mll.append(tp)
            matrix_length_dict[(C,R)] = mll
            this_list.append(tp)

    matrix_types += this_list

for type_id in quat_type_ids:
    quat_type_dict[type_id] = []
    this_list = quat_type_dict[type_id]

    this_list.append(getattr(glm, "{T}quat".format(T=prefixes[type_id])))

    quat_types += this_list

obj_gen = lambda types: (T() for T in types)

def list_replace(list_, x, y):
    list_copy = list(list_)
    for i in range(len(list_copy)):
        list_copy[i] = list_copy[i].replace(x, y)
    return list_copy

randf = lambda: random.random()*100
randfs = lambda: randf()-50

def get_args(arg_string, type_, rand_func=None):
    if not rand_func:
        if type_ in "IQSU":
            rand_func = randf
        else:
            rand_func = randfs
    args = []
    for arg in arg_string:
        if arg == "N":
            if type_ in "fF":
                args.append(float(rand_func()))
            if type_ in "iqsu":
                args.append(int(rand_func()))
            if type_ in "IQSU":
                args.append(int(randf()))
            if type_ == "B":
                args.append(random.choice((True, False)))

        elif arg == "Ni":
            args.append(int(rand_func()))

        elif arg == "NB":
            args.append(random.choice((True, False)))

        elif "V" in arg:
            if len(arg) == 3 and arg[2] in "fFiB":
                T = prefixes[suffixes.index(arg[2])]
            else:
                T = prefixes[suffixes.index(type_)]

            L = int(arg[1])
            args.append(getattr(glm, "{T}vec{L}".format(T=T, L=L))(*([rand_func()] * L)))

        elif arg == "Q":
            args.append(getattr(glm, "{T}quat".format(T=prefixes[suffixes.index(type_)]))(rand_func(), rand_func(), rand_func(), rand_func()))

        elif "M" in arg:
            if len(arg) == 4 and arg[3] in "fFiI":
                T = prefixes[suffixes.index(arg[3])]
            else:
                T = prefixes[suffixes.index(type_)]

            n = int(arg[1])
            m = int(arg[2])
            args.append(getattr(glm, "{T}mat{n}x{m}".format(T=prefixes[suffixes.index(type_)], n=n, m=m))(*[rand_func() for i in range(n*m)]))

    return args


def gen_args(args_string):
    if "#u" in args_string:
        rand_func = randf
        args_string = args_string.replace("#u", "")
    elif "#p" in args_string:
        rand_func = lambda: randf() + 1
        args_string = args_string.replace("#p", "")
    elif "#d" in args_string:
        rand_func = random.random
        args_string = args_string.replace("#d", "")
    else:
        rand_func = None

    if "__" in args_string:
        arg_part, type_part = args_string.split("__")
        parts = arg_part.split("_")
        types = type_part
    else:
        parts = args_string.split("_")
        types = suffixes
    
    for part in parts:
        arg_strings = []
        current_text = ""
        for char in part:
            if not char in "1234" + "fFiB":
                if current_text != "":
                    arg_strings.append(current_text)
                    current_text = ""
            current_text += char
        if current_text:
            arg_strings.append(current_text)
        
        if "N" in arg_strings and not ("V" in arg_strings or "M" in arg_strings):
            yield get_args(arg_strings, "F" if "F" in types else "f" if "f" in types else "i" if "i" in types else "I" if "I" in types else types[0], rand_func)
        elif "V" in arg_strings:
            for T in types:
                for L in range(1, 5):
                    yield get_args(list_replace(arg_strings, "V", "V{L}".format(L=L)), T, rand_func)

        elif "Vf" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "Vf", "V{L}".format(L=L)), "f", rand_func)

        elif "VF" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "VF", "V{L}".format(L=L)), "F", rand_func)

        elif "Vi" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "Vi", "V{L}".format(L=L)), "i", rand_func)

        elif "VB" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "VB", "V{L}".format(L=L)), "B", lambda: random.choice((True, False)))

        elif "V1" in arg_strings or "V2" in arg_strings or "V3" in arg_strings or "V4" in arg_strings or "M22" in arg_strings or "M23" in arg_strings or "M24" in arg_strings or "M32" in arg_strings or "M33" in arg_strings or "M34" in arg_strings or "M42" in arg_strings or "M43" in arg_strings or "M44" in arg_strings:
            for T in types:
                yield get_args(arg_strings, T, rand_func)

        elif "Q" in arg_strings:
            for T in types:
                if not T in "fF":
                    continue
                yield get_args(arg_strings, T, rand_func)

        elif "M" in arg_strings:
            for T in types:
                if not T in "fFiI":
                    continue
                for C in range(2,5):
                    for R in range(2,5):
                        yield get_args(list_replace(arg_strings, "M", "M{C}{R}".format(C=C,R=R)), T, rand_func)

        elif "Mf" in arg_strings:
            for C in range(2,5):
                for R in range(2,5):
                    yield get_args(list_replace(arg_strings, "Mf", "M{C}{R}".format(C=C,R=R)), "f", rand_func)

        elif "MF" in arg_strings:
            for C in range(2,5):
                for R in range(2,5):
                    yield get_args(list_replace(arg_strings, "MF", "M{C}{R}".format(C=C,R=R)), "F", rand_func)

        elif "-" in arg_strings:
            yield ()

def gen_obj(args_string):
    for args in gen_args(args_string):
        yield args[0]


#v1 = glm.vec1()
#v2 = glm.vec2()
#v3 = glm.vec3()
#v4 = glm.vec4()

#vectors = [v1, v2, v3, v4]

#vector_types = [glm.vec1, glm.vec2, glm.vec3, glm.vec4]

#m22 = glm.mat2x2()
#m23 = glm.mat2x3()
#m24 = glm.mat2x4()
#m32 = glm.mat3x2()
#m33 = glm.mat3x3()
#m34 = glm.mat3x4()
#m42 = glm.mat4x2()
#m43 = glm.mat4x3()
#m44 = glm.mat4x4()

#matrices = [m22, m23, m24, m32, m33, m34, m42, m43, m44]

#matrix_types = [glm.mat2x2, glm.mat2x3, glm.mat2x4, glm.mat3x2, glm.mat3x3, glm.mat3x4, glm.mat4x2, glm.mat4x3, glm.mat4x4]

#q = glm.quat()

#all_types = vector_types + matrix_types + [glm.quat]

#all_type_objects = vectors + matrices + [q]

#get_obj_generator = lambda types: (x() for x in types)

class FAssertionError(Exception):
    pass

def fassert(func, args):
    try:
        return func(*args)
    except:
        raise FAssertionError("{} raised {} with {}".format(func, sys.exc_info()[1], repr(args)))

def fail(*args):
    raise FAssertionError("Failed with " + str(args)) 
# Specific #
assert isinstance(glm.version, str)
assert isinstance(glm.license, str)
#/Specific #

# Initialization #
## vec1
for args in gen_args("#u-_N"): # need to add support for _V1_V2_V3_V4
    for T in vector_length_dict[1]:
        fassert(T, args)

## vec2
for args in gen_args("#u-_N_NN_V2"):
    for T in vector_length_dict[2]:
        fassert(T, args)

for args in gen_args("#uV2V3_V2V4"):
    fassert(type(args[0]), args[1:])

## vec3
for args in gen_args("#u-_N_NNN_V3"):
    for T in vector_length_dict[3]:
        fassert(T, args)

for args in gen_args("#uV3V4_V3NV2_V3V2N"):
    fassert(type(args[0]), args[1:])

## vec4
for args in gen_args("#u-_N_NNNN_V4"):
    for T in vector_length_dict[4]:
        fassert(T, args)

for args in gen_args("#uV4V2NN_V4NV2N_V4NNV2_V4NV3_V4V3N"):
    fassert(type(args[0]), args[1:])

## mat
for C in range(2, 5):
    for R in range(2, 5):
        for args in gen_args("#u-_N_" + "N"*(C*R) + "_M{C}{R}__fFiI".format(C=C, R=R)): # need support for _M
            for T in matrix_length_dict[(C,R)]:
                fassert(T, args)

        for args in gen_args("#uM{C}{R}".format(C=C, R=R) + "V{R}".format(R=R)*C + "_" + "_".join(["M{C}{R}M{c}{r}".format(C=C, R=R, c=c, r=r) for c in range(2, 5) for r in range(2,5)]) + "__fFiI"):
            fassert(type(args[0]), args[1:])

## quat
for args in gen_args("#u-_V3_M33_M44_NV3_V3V3_NNNN_Q__f"): # need support for conversion constructors
    fassert(glm.quat, args)

## dquat
for args in gen_args("#u-_V3_M33_M44_NV3_V3V3_NNNN_Q__F"): # need support for conversion constructors
    fassert(glm.dquat, args)

## array
for args in gen_args("V_M_Q_VV_MM_QQ_VVV_MMM_QQQ"):
    fassert(glm.array, args)

assert glm.array([glm.vec4() for x in range(10)])
assert glm.array(tuple([glm.vec4() for x in range(10)]))
assert glm.array({x : glm.vec4() for x in range(10)}.values())
assert glm.array(memoryview(glm.array([glm.vec4() for x in range(10)])))

assert glm.array([glm.quat() for x in range(10)])
assert glm.array(tuple([glm.quat() for x in range(10)]))
assert glm.array({x : glm.quat() for x in range(10)}.values())
assert glm.array(memoryview(glm.array([glm.quat() for x in range(10)])))

assert glm.array([glm.mat4() for x in range(10)])
assert glm.array(tuple([glm.mat4() for x in range(10)]))
assert glm.array({x : glm.mat4() for x in range(10)}.values())
assert glm.array(memoryview(glm.array([glm.mat4() for x in range(10)])))

arr = glm.array(glm.mat4(), glm.mat4(2))
assert len(arr) == 2, arr
assert arr.typecode == "f", arr
assert arr.dtype == "float32", arr
assert arr.dt_size == 4, arr
assert arr.itemsize == arr.dt_size * 4 * 4, arr
assert arr.ptr, arr
assert arr.nbytes == arr.itemsize * len(arr), arr
assert arr.element_type == glm.mat4, arr

# repr #
for T in vector_types + matrix_types + quat_types:
    fassert(lambda o: eval(repr(o), {a : getattr(glm, a) for a in dir(glm)}), (T(),))

assert False, (glm.vec1((1,)), glm.vec4((1,2,3,4)), glm.mat2(((1,2),(3,4))), glm.mat4x4((1, 1, 1, 1), (1, 1, 1, 1), (1, 1, 1, 1), (1, 1, 1, 1)))

arr = glm.array(glm.vec4(*[-1.23457e+06]*4), glm.vec4(*[-7.65432e+06]*4))
arr2 = glm.array(glm.quat(*[-1.23457e+06]*4), glm.quat(*[-7.65432e+06]*4))
arr3 = glm.array(glm.mat4(*[-1.23457e+06]*16), glm.mat4(*[-7.65432e+06]*16))
assert repr(arr), arr
assert repr(arr2), arr2
assert repr(arr3), arr3
assert str(arr), arr
assert str(arr2), arr2
assert str(arr3), arr3

arr = glm.array(glm.vec4(*[1]*4), glm.vec4(*[2]*4))
arr2 = glm.array(glm.quat(*[1]*4), glm.quat(*[2]*4))
arr3 = glm.array(glm.mat4(*[1]*16), glm.mat4(*[2]*16))
assert eval(repr(arr)) == arr, (arr, repr(arr), eval(repr(arr)))
assert eval(repr(arr2)) == arr2, (arr2, repr(arr2), eval(repr(arr2)))
assert eval(repr(arr3)) == arr3, (arr3, repr(arr3), eval(repr(arr3)))
#/repr #

# neg #
for obj in gen_obj("V_M_Q__fFiqsu"):
    fassert(obj.__neg__, ())
#/neg #

# pos #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__pos__, ())
#/pos #

# abs #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__pos__, ())
#/abs #

# add #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__add__, (obj,))

arr = glm.array(glm.mat4())
fassert(arr.__add__, (arr,))
fassert((arr+arr).__add__, (arr,))
#/add #

# sub #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__sub__, (obj,))
#/sub #

# mul #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__mul__, (1,))

arr = glm.array(glm.mat4())
fassert(arr.__mul__, (3,))
fassert((arr*4).__mul__, (2,))
#/mul #

# div #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__truediv__, (1,))

for obj in gen_obj("V__iqsuIQSU"):
    try:
        obj.__truediv__(type(obj)(0))
        fail(obj)
    except ZeroDivisionError:
        pass

for obj in gen_obj("V_M_Q__iqsuIQSU"):
    try:
        obj.__truediv__(0)
        fail(obj)
    except ZeroDivisionError:
        pass
#/div #

# mod #
for obj in gen_obj("V__fF"):
    fassert(obj.__mod__, (1,))
#/mod #

# floordiv #
for obj in gen_obj("V__fF"):
    fassert(obj.__floordiv__, (1,))
#/floordiv #

# divmod #
for obj in gen_obj("V__fF"):
    fassert(obj.__divmod__, (1,))
#/divmod #

# pow #
for obj in gen_obj("V__fF"):
    fassert(obj.__pow__, (obj,))
    fassert(obj.__pow__, (obj, obj))
#/pow #

# iadd #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__iadd__, (obj,))
    
arr = glm.array(glm.mat4())
fassert(arr.__iadd__, (arr,))
fassert(arr.__iadd__, (arr,))
#/iadd #

# isub #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__isub__, (obj,))
#/isub #

# imul #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__imul__, (1,))

arr = glm.array(glm.mat4())
fassert(arr.__imul__, (3,))
fassert(arr.__imul__, (3,))
#/imul #

# idiv #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__itruediv__, (1,))
#/idiv #

# imod #
for obj in gen_obj("V__fF"):
    fassert(obj.__imod__, (1,))
#/imod #

# ifloordiv #
for obj in gen_obj("V__fF"):
    fassert(obj.__ifloordiv__, (1,))
#/ifloordiv #

# ipow #
for obj in gen_obj("V__fF"):
    fassert(obj.__ipow__, (obj,))
#/ipow #

# str #
for obj in gen_obj("V_M_Q"):
    assert str(obj), obj
#/str #

# repr #
for obj in gen_obj("V_M_Q"):
    assert repr(obj), obj
#/repr #

# len #
for obj in gen_obj("V_M_Q"):
    assert len(obj), obj

arr = glm.array(glm.mat4())
arr2 = arr + arr
assert len(arr) == 1, arr
assert len(arr2) == 2, arr2
#/len #

# getitem #
for obj in gen_obj("V_M_Q"):
    for i in range(len(obj)):
        assert obj[i] != None, obj

arr = glm.array(glm.mat4(), glm.mat4(2))
assert arr[0] == glm.mat4(), arr
assert arr[1] == glm.mat4(2) == arr[-1], arr
#/getitem #

# setitem #
for obj in gen_obj("V_M_Q"):
    for i in range(len(obj)):
        fassert(obj.__setitem__,(i, obj[i]))

arr = glm.array(glm.mat4(), glm.mat4(2))
arr[0] = glm.mat4(3)
assert arr[0] == glm.mat4(3), arr
#/setitem #

# contains #
for obj in gen_obj("V_M_Q"):
    assert obj[0] in obj, obj

arr = glm.array(glm.mat4(), glm.mat4(2))
assert glm.mat4(2) in arr and not glm.mat4(3) in arr, arr
#/contains #

# Richcompare #
## EQ
for obj in gen_obj("V_M_Q"):
    assert obj == type(obj)(obj), obj

arr = glm.array(glm.mat4(), glm.mat4(2))
arr2 = glm.array(glm.mat4(), glm.mat4(2))
arr3 = glm.array(glm.mat4(), glm.mat4(2), glm.mat4(0))
assert arr == arr2 and not arr == arr3, (arr, arr2, arr3)

## NE
for obj in gen_obj("#uV_M__fFiqsuIQSU"):
    assert obj != (obj + 1), obj

for obj in gen_obj("V_M__B"):
    assert obj != (not obj), obj

for obj in gen_obj("Q"):
    assert obj != (1,0,0,0)

arr = glm.array(glm.mat4(), glm.mat4(2))
arr2 = glm.array(glm.mat4(), glm.mat4(2))
arr3 = glm.array(glm.mat4(), glm.mat4(2), glm.mat4(0))
assert not arr != arr2 and arr != arr3, (arr, arr2, arr3)

## LT
for obj in gen_obj("#uV__fFiqsuIQSU"):
    assert all(obj < (obj + 1)) and not any(obj < obj), obj

## LE
for obj in gen_obj("#uV__fFiqsuIQSU"):
    assert all(obj <= obj) and all(obj <= (obj + 1)) and not any((obj + 1) <= obj), obj

## GT
for obj in gen_obj("#uV__fFiqsuIQSU"):
    assert all((obj + 1) > obj) and not any(obj > obj), obj

## GE
for obj in gen_obj("#uV__fFiqsuIQSU"):
    assert all(obj >= obj) and all((obj + 1) >= obj) and not any(obj >= (obj + 1)), obj
#/Richcompare #

# iter #
for obj in gen_obj("V_M_Q"):
    fassert(iter, (obj,))

arr = glm.array(glm.mat4(), glm.mat4(2))
assert list(arr) == arr.to_list(), arr
#/iter #

# buffer protocol #
def check_buffer_protocol(type_, shape, format):
    obj = type_()
    memview = memoryview(obj)
    assert shape == memview.shape
    assert format == memview.format

for t, s, f in (
    (glm.vec1, (1,), "f"),
    (glm.vec2, (2,), "f"),
    (glm.vec3, (3,), "f"),
    (glm.vec4, (4,), "f"),
    
    (glm.dvec1, (1,), "d"),
    (glm.dvec2, (2,), "d"),
    (glm.dvec3, (3,), "d"),
    (glm.dvec4, (4,), "d"),

    (glm.ivec1, (1,), "i"),
    (glm.ivec2, (2,), "i"),
    (glm.ivec3, (3,), "i"),
    (glm.ivec4, (4,), "i"),

    (glm.uvec1, (1,), "I"),
    (glm.uvec2, (2,), "I"),
    (glm.uvec3, (3,), "I"),
    (glm.uvec4, (4,), "I"),
    
    (glm.i8vec1, (1,), "b"),
    (glm.i8vec2, (2,), "b"),
    (glm.i8vec3, (3,), "b"),
    (glm.i8vec4, (4,), "b"),
    
    (glm.u8vec1, (1,), "B"),
    (glm.u8vec2, (2,), "B"),
    (glm.u8vec3, (3,), "B"),
    (glm.u8vec4, (4,), "B"),
    
    (glm.i16vec1, (1,), "h"),
    (glm.i16vec2, (2,), "h"),
    (glm.i16vec3, (3,), "h"),
    (glm.i16vec4, (4,), "h"),
    
    (glm.u16vec1, (1,), "H"),
    (glm.u16vec2, (2,), "H"),
    (glm.u16vec3, (3,), "H"),
    (glm.u16vec4, (4,), "H"),

    (glm.i64vec1, (1,), "q"),
    (glm.i64vec2, (2,), "q"),
    (glm.i64vec3, (3,), "q"),
    (glm.i64vec4, (4,), "q"),
    
    (glm.u64vec1, (1,), "Q"),
    (glm.u64vec2, (2,), "Q"),
    (glm.u64vec3, (3,), "Q"),
    (glm.u64vec4, (4,), "Q"),
    
    (glm.bvec1, (1,), "?"),
    (glm.bvec2, (2,), "?"),
    (glm.bvec3, (3,), "?"),
    (glm.bvec4, (4,), "?"),
    
    (glm.mat2x2, (2, 2), "f"),
    (glm.mat2x3, (2, 3), "f"),
    (glm.mat2x4, (2, 4), "f"),
    (glm.mat3x2, (3, 2), "f"),
    (glm.mat3x3, (3, 3), "f"),
    (glm.mat3x4, (3, 4), "f"),
    (glm.mat4x2, (4, 2), "f"),
    (glm.mat4x3, (4, 3), "f"),
    (glm.mat4x4, (4, 4), "f"),
    
    
    (glm.dmat2x2, (2, 2), "d"),
    (glm.dmat2x3, (2, 3), "d"),
    (glm.dmat2x4, (2, 4), "d"),
    (glm.dmat3x2, (3, 2), "d"),
    (glm.dmat3x3, (3, 3), "d"),
    (glm.dmat3x4, (3, 4), "d"),
    (glm.dmat4x2, (4, 2), "d"),
    (glm.dmat4x3, (4, 3), "d"),
    (glm.dmat4x4, (4, 4), "d"),
    
    
    (glm.imat2x2, (2, 2), "i"),
    (glm.imat2x3, (2, 3), "i"),
    (glm.imat2x4, (2, 4), "i"),
    (glm.imat3x2, (3, 2), "i"),
    (glm.imat3x3, (3, 3), "i"),
    (glm.imat3x4, (3, 4), "i"),
    (glm.imat4x2, (4, 2), "i"),
    (glm.imat4x3, (4, 3), "i"),
    (glm.imat4x4, (4, 4), "i"),
    
    
    (glm.umat2x2, (2, 2), "I"),
    (glm.umat2x3, (2, 3), "I"),
    (glm.umat2x4, (2, 4), "I"),
    (glm.umat3x2, (3, 2), "I"),
    (glm.umat3x3, (3, 3), "I"),
    (glm.umat3x4, (3, 4), "I"),
    (glm.umat4x2, (4, 2), "I"),
    (glm.umat4x3, (4, 3), "I"),
    (glm.umat4x4, (4, 4), "I"),
    
    (glm.quat, (4,), "f"),
    
    (glm.dquat, (4,), "d"),
    ):
    check_buffer_protocol(t,s,f)

arr = glm.array(glm.mat4(), glm.mat4(2))
mv = memoryview(arr)
assert glm.array(mv) == arr, arr
#/buffer protocol #

# lists and tuples #
for tp, arg in (
    (glm.vec1, (1,)),
    (glm.vec2, (1, 2,)),
    (glm.vec3, (1, 2, 3,)),
    (glm.vec4, (1, 2, 3, 4)),
    (glm.vec1, [1]),
    (glm.vec2, [1, 2]),
    (glm.vec3, [1, 2, 3]),
    (glm.vec4, [1, 2, 3, 4]),
    (glm.mat2x2, ((1, 2), (3, 4))),
    (glm.mat2x3, ((1, 2, 3), (4, 5, 6))),
    (glm.mat2x4, ((1, 2, 3, 4), (5, 6, 7, 8))),
    (glm.mat3x2, ((1, 2), (3, 4), (5, 6))),
    (glm.mat3x3, ((1, 2, 3), (4, 5, 6), (7, 8, 9))),
    (glm.mat3x4, ((1, 2, 3, 4), (5, 6, 7, 8), (9, 10, 11, 12))),
    (glm.mat4x2, ((1, 2), (3, 4), (5, 6), (7, 8))),
    (glm.mat4x3, ((1, 2, 3), (4, 5, 6), (7, 8, 9), (10, 11, 12))),
    (glm.mat4x4, ((1, 2, 3, 4), (5, 6, 7, 8), (9, 10, 11, 12), (13, 14, 15, 16))),
    (glm.quat, (1, 2, 3, 4)),
    ):
    fassert(tp, [arg]);
#/lists and tuples #

# copy module #
for args in gen_args("V_M_Q"):
    fassert(copy.copy, args)
    fassert(copy.deepcopy, args)

arr = glm.array(glm.mat4(), glm.mat4(2))
assert copy.copy(arr) == arr, arr
assert copy.deepcopy(arr) == arr, arr
#/copy module #

# to_list #
for args in gen_args("V_Q"):
    for arg in args:
        assert arg.to_list() == [x for x in arg]

for args in gen_args("M"):
    for arg in args:
        assert arg.to_list() == [[y for y in x] for x in arg]

arr = glm.array(glm.mat4(), glm.mat4(2))
assert arr.to_list() == [glm.mat4(), glm.mat4(2)]
#/to_list #

# to_tuple #
for args in gen_args("V_Q"):
    for arg in args:
        assert arg.to_tuple() == tuple([x for x in arg])

for args in gen_args("M"):
    for arg in args:
        assert arg.to_tuple() == tuple([tuple([y for y in x]) for x in arg])

arr = glm.array(glm.mat4(), glm.mat4(2))
assert arr.to_tuple() == (glm.mat4(), glm.mat4(2))
#/to_tuple #

## DETAIL ##

# func_packing #
fassert(glm.packDouble2x32, (glm.uvec2(randf()),))
fassert(glm.packUnorm2x16, (glm.vec2(randfs()),))
fassert(glm.packSnorm2x16, (glm.vec2(randfs()),))
fassert(glm.packSnorm4x8, (glm.vec4(randfs()),))
fassert(glm.packUnorm4x8, (glm.vec4(randfs()),))
fassert(glm.packHalf2x16, (glm.vec2(randfs()),))
fassert(glm.unpackDouble2x32, (randfs(),))
fassert(glm.unpackUnorm2x16, (int(randf()),))
fassert(glm.unpackSnorm2x16, (int(randf()),))
fassert(glm.unpackUnorm4x8, (int(randf()),))
fassert(glm.unpackSnorm4x8, (int(randf()),))
fassert(glm.unpackHalf2x16, (int(randf()),))
#/func_packing #

# func_integer #
for args in gen_args("#uVVV__I"):
    fassert(glm.uaddCarry, args)

for args in gen_args("#uVVV__I"):
    fassert(glm.usubBorrow, args)

for args in gen_args("#uVVVV__I"):
    fassert(glm.umulExtended, args)

for args in gen_args("#uVVVV__i"):
    fassert(glm.imulExtended, args)

for args in gen_args("#uNNN_VNN__i"):
    fassert(glm.bitfieldExtract, args)

for args in gen_args("#uNNNN_VVNN__i"):
    fassert(glm.bitfieldInsert, args)

for args in gen_args("#uV_N__I"):
    fassert(glm.bitfieldReverse, args)

for args in gen_args("#uV_N__i"):
    fassert(glm.bitCount, args)
    fassert(glm.findLSB, args)
    fassert(glm.findMSB, args)
#/func_integer #

# func_vector_relational #
for args in gen_args("#uVV_QQ_NNNi_VfVfNi_VFVFNi_MfMfNi_MFMFNi"): # need to add support for _MM
    fassert(glm.equal, args)
    fassert(glm.notEqual, args)

for args in gen_args("#uVV"):
    fassert(glm.lessThan, args)
    fassert(glm.lessThanEqual, args)

for args in gen_args("#uV__B"):
    fassert(glm.any, args)
    fassert(glm.all, args)
    fassert(glm.not_, args)
#/func_vector_relational #

# func_exponential #
for args in gen_args("VV_QN_NN__fF"):
    fassert(glm.pow, args)

for args in gen_args("N_V_Q__fF"):
    fassert(glm.exp, args)
    fassert(glm.log, args)
    fassert(glm.sqrt, args)

for args in gen_args("N_V__fF"):
    fassert(glm.exp2, args)
    fassert(glm.log2, args)
    fassert(glm.inversesqrt, args)
#/func_exponential #

    
# func_common #
for args in gen_args("N_V__fF"):
    fassert(glm.abs, args)
    fassert(glm.sign, args)
    fassert(glm.floor, args)
    fassert(glm.trunc, args)
    fassert(glm.round, args)
    fassert(glm.roundEven, args)
    fassert(glm.ceil, args)
    fassert(glm.fract, args)

for args in gen_args("NN_VV_VN__fF"):
    fassert(glm.mod, args)

for args in gen_args("NN_VV_VN_NNN_VVV_NNNN_VVVV__fFiqsuIQSU"):
    fassert(glm.min, args)
    fassert(glm.max, args)

for args in gen_args("NN_VV_VN_NNN_VVV_NNNN_VVVV__fF"):
    fassert(glm.fmin, args)
    fassert(glm.fmax, args)

for args in gen_args("NNN_VVV_VNN__fF"):
    fassert(glm.clamp, args)

for args in list(gen_args("NNNB_NNN_QQN__fF")) + list(gen_args("VVN_VVVf_VVVF_VVVB")): # need to add support for _MMN_MMMf_MMMF
    fassert(glm.mix, args)

for args in gen_args("NN_NV_VV"):
    fassert(glm.step, args)

for args in gen_args("NNN_NNV_VVV__fF"):
    fassert(glm.smoothstep, args)

for args in gen_args("N_V_Q__fF"):
    fassert(glm.isnan, args)
    fassert(glm.isinf, args)

fassert(glm.fma, ((randfs(), randfs(), randfs())))

for args in gen_args("NNi_VVi__fF"):
    fassert(glm.frexp, args)

for args in gen_args("VVi__fF"):
    fassert(glm.ldexp, args)
#/func_common #

# func_geometric #
for args in gen_args("N_V_Q__fF"):
    fassert(glm.length, args)

for args in gen_args("NN_VV__fF"):
    fassert(glm.distance, args)

for args in gen_args("NN_VV_QQ__fF"):
    fassert(glm.dot, args)

for args in gen_args("V3V3_QQ__fF"):
    fassert(glm.cross, args)

for args in gen_args("V_Q__fF"):
    fassert(glm.normalize, args)

for args in gen_args("NNN_VVV__fF"):
    fassert(glm.faceforward, args)

for args in gen_args("NN_VV__fF"):
    fassert(glm.reflect, args)

for args in gen_args("NNN_VVN__fF"):
    fassert(glm.refract, args)
#/func_geometric #

# func_matrix #
for args in gen_args("MM__fF"):
    fassert(glm.matrixCompMult, args)

for args in gen_args("V2V2_V2V3_V2V4_V3V2_V3V3_V3V4_V4V2_V4V3_V4V4__fF"):
    fassert(glm.outerProduct, args)

for args in gen_args("M__fF"):
    fassert(glm.transpose, args)

for args in gen_args("M22_M33_M44__fF"):
    fassert(glm.determinant, args)

for args in gen_args("M22_M33_M44_Q__fF"):
    fassert(glm.inverse, args)
#/func_matrix #

# func_trigonometric #
for args in gen_args("N_V__fF"):
    fassert(glm.radians, args)
    fassert(glm.degrees, args)
    fassert(glm.sin, args)
    fassert(glm.cos, args)
    fassert(glm.tan, args)
    fassert(glm.asin, args)
    fassert(glm.acos, args)
    fassert(glm.sinh, args)
    fassert(glm.cosh, args)
    fassert(glm.tanh, args)
    fassert(glm.asinh, args)
    fassert(glm.acosh, args)
    fassert(glm.atanh, args)

for args in gen_args("NN_VV_N_V__fF"):
    fassert(glm.atan, args)
#/func_trigonometric #
##/DETAIL ##

## EXTENSIONS ##
# color_space #
for args in gen_args("V_VN__fF"):
    fassert(glm.convertLinearToSRGB, args)
    fassert(glm.convertSRGBToLinear, args)
#/color_space #

# constants #
fassert(glm.epsilon, (()))
fassert(glm.zero, (()))
fassert(glm.one, (()))
fassert(glm.pi, (()))
fassert(glm.two_pi, (()))
fassert(glm.root_pi, (()))
fassert(glm.half_pi, (()))
fassert(glm.three_over_two_pi, (()))
fassert(glm.quarter_pi, (()))
fassert(glm.one_over_pi, (()))
fassert(glm.one_over_two_pi, (()))
fassert(glm.two_over_pi, (()))
fassert(glm.four_over_pi, (()))
fassert(glm.two_over_root_pi, (()))
fassert(glm.one_over_root_two, (()))
fassert(glm.root_half_pi, (()))
fassert(glm.root_two_pi, (()))
fassert(glm.root_ln_four, (()))
fassert(glm.e, (()))
fassert(glm.euler, (()))
fassert(glm.root_two, (()))
fassert(glm.root_three, (()))
fassert(glm.root_five, (()))
fassert(glm.ln_two, (()))
fassert(glm.ln_ten, (()))
fassert(glm.ln_ln_two, (()))
fassert(glm.third, (()))
fassert(glm.two_thirds, (()))
fassert(glm.golden_ratio, (()))
#/constants #

# epsilon #
for args in gen_args("NNN_VVN_QQN_VVV__fF"):
    fassert(glm.epsilonEqual, args)
    fassert(glm.epsilonNotEqual, args)
#/epsilon #

# integer #
for args in gen_args("#uN_V__fF"):
    fassert(glm.iround, args)
    fassert(glm.uround, args)
#/integer #

# matrix_inverse #
for args in gen_args("M33_M44__fF"):
    fassert(glm.affineInverse, args)

for args in gen_args("M22_M33_M44__fF"):
    fassert(glm.inverseTranspose, args)
#/matrix_inverse #

# matrix_transform #
for type_ in matrix_types:
    fassert(glm.identity, (type_,))

for args in gen_args("M44V3__fF"):
    fassert(glm.translate, args)
    fassert(glm.scale, args)
    fassert(glm.scale_slow, args)

for args in gen_args("M44NV3_QNV3__fF"):
    fassert(glm.rotate, args)

for args in gen_args("M44NV3__fF"):
    fassert(glm.rotate_slow, args)

for args in gen_args("NNNN_NNNNNN"):
    fassert(glm.ortho, args)

for args in gen_args("NNNNNN"):
    fassert(glm.orthoLH_ZO, args)
    fassert(glm.orthoLH_NO, args)
    fassert(glm.orthoRH_ZO, args)
    fassert(glm.orthoRH_NO, args)
    fassert(glm.orthoZO, args)
    fassert(glm.orthoNO, args)
    fassert(glm.orthoLH, args)
    fassert(glm.orthoRH, args)
    fassert(glm.frustum, args)
    fassert(glm.frustumLH_ZO, args)
    fassert(glm.frustumLH_NO, args)
    fassert(glm.frustumRH_ZO, args)
    fassert(glm.frustumRH_NO, args)
    fassert(glm.frustumZO, args)
    fassert(glm.frustumNO, args)
    fassert(glm.frustumLH, args)
    fassert(glm.frustumRH, args)

for args in gen_args("NNNN"):
    fassert(glm.perspective, args)
    fassert(glm.perspectiveLH_ZO, args)
    fassert(glm.perspectiveLH_NO, args)
    fassert(glm.perspectiveRH_ZO, args)
    fassert(glm.perspectiveRH_NO, args)
    fassert(glm.perspectiveZO, args)
    fassert(glm.perspectiveNO, args)
    fassert(glm.perspectiveLH, args)
    fassert(glm.perspectiveRH, args)

for args in gen_args("#uNNNNN"):
    fassert(glm.perspectiveFov, args)
    fassert(glm.perspectiveFovLH_ZO, args)
    fassert(glm.perspectiveFovLH_NO, args)
    fassert(glm.perspectiveFovRH_ZO, args)
    fassert(glm.perspectiveFovRH_NO, args)
    fassert(glm.perspectiveFovZO, args)
    fassert(glm.perspectiveFovNO, args)
    fassert(glm.perspectiveFovLH, args)
    fassert(glm.perspectiveFovRH, args)

for args in gen_args("NNN"):
    fassert(glm.infinitePerspective, args)
    fassert(glm.infinitePerspectiveRH, args)
    fassert(glm.infinitePerspectiveLH, args)

for args in gen_args("NNN_NNNN"):
    fassert(glm.tweakedInfinitePerspective, args)

for args in gen_args("V3M44M44V4__fF"):
    fassert(glm.project, args)
    fassert(glm.projectNO, args)
    fassert(glm.projectZO, args)
    fassert(glm.unProject, args)
    fassert(glm.unProjectNO, args)
    fassert(glm.unProjectZO, args)

for args in gen_args("#pV2V2V4__fF"):
    fassert(glm.pickMatrix, args)

for args in gen_args("V3V3V3__fF"):
    fassert(glm.lookAt, args)
    fassert(glm.lookAtRH, args)
    fassert(glm.lookAtLH, args)
#/matrix_transform #

# quaternion #
for args in gen_args("V3V3__fF"):
    fassert(glm.quatLookAt, args)
    fassert(glm.quatLookAtLH, args)
    fassert(glm.quatLookAtRH, args)

for args in gen_args("#dQQN__fF"):
    fassert(glm.lerp, args)

for args in gen_args("QQN__fF"):
    fassert(glm.slerp, args)

for args in gen_args("Q"):
    fassert(glm.conjugate, args)
    fassert(glm.eulerAngles, args)
    fassert(glm.roll, args)
    fassert(glm.pitch, args)
    fassert(glm.yaw, args)
    fassert(glm.mat3_cast, args)
    fassert(glm.mat4_cast, args)
    fassert(glm.angle, args)
    fassert(glm.axis, args)

for args in gen_args("M33_M44__fF"):
    fassert(glm.quat_cast, args)

for args in gen_args("NV3__fF"):
    fassert(glm.angleAxis, args)
#/quaternion #

# matrix_access #
for T_id in matrix_type_ids:
    T = prefixes[T_id]
    for C in range(2, 5):
        for R in range(2, 5):
            m = getattr(glm, "{T}mat{C}x{R}".format(T=T,C=C,R=R))()
            row_i = random.randrange(R)
            row_v = getattr(glm, "{T}vec{C}".format(T=T, C=C))()
            column_i = random.randrange(C)
            column_v = getattr(glm, "{T}vec{R}".format(T=T, R=R))()
            fassert(glm.row, (m, row_i))
            fassert(glm.row, (m, row_i, row_v))
            fassert(glm.column, (m, column_i))
            fassert(glm.column, (m, column_i, column_v))
#/matrix_access #

# noise #
for args in gen_args("V2_V3_V4_V2V2_V3V3_V4V4__fF"):
    fassert(glm.perlin, args)

for args in gen_args("V2_V3_V4__fF"):
    fassert(glm.simplex, args)
#/noise #

# packing #
fassert(glm.packInt2x8, (glm.i8vec2(),))
fassert(glm.unpackInt2x8, (0,))
fassert(glm.packInt4x8, (glm.i8vec4(),))
fassert(glm.unpackInt4x8, (0,))
fassert(glm.packInt2x16, (glm.i16vec2(),))
fassert(glm.unpackInt2x16, (0,))
fassert(glm.packInt4x16, (glm.i16vec4(),))
fassert(glm.unpackInt4x16, (0,))
fassert(glm.packInt2x32, (glm.i32vec2(),))
fassert(glm.unpackInt2x32, (0,))
fassert(glm.packUint2x8, (glm.u8vec2(),))
fassert(glm.unpackUint2x8, (0,))
fassert(glm.packUint4x8, (glm.u8vec4(),))
fassert(glm.unpackUint4x8, (0,))
fassert(glm.packUint2x16, (glm.u16vec2(),))
fassert(glm.unpackUint2x16, (0,))
fassert(glm.packUint4x16, (glm.u16vec4(),))
fassert(glm.unpackUint4x16, (0,))
fassert(glm.packUint2x32, (glm.u32vec2(),))
fassert(glm.unpackUint2x32, (0,))
fassert(glm.packHalf1x16, (0.,))
fassert(glm.unpackHalf1x16, (0,))
fassert(glm.packHalf4x16, (glm.vec4(),))
fassert(glm.unpackHalf4x16, (0,))
fassert(glm.packUnorm1x8, (0.,))
fassert(glm.unpackUnorm1x8, (0,))
fassert(glm.packUnorm2x8, (glm.vec2(),))
fassert(glm.unpackUnorm2x8, (0,))
fassert(glm.packUnorm1x16, (0.,))
fassert(glm.unpackUnorm1x16, (0,))
fassert(glm.packUnorm4x16, (glm.vec4(),))
fassert(glm.unpackUnorm4x16, (0,))
fassert(glm.packUnorm3x10_1x2, (glm.vec4(),))
fassert(glm.unpackUnorm3x10_1x2, (0,))
fassert(glm.packUnorm2x4, (glm.vec2(),))
fassert(glm.unpackUnorm2x4, (0,))
fassert(glm.packUnorm4x4, (glm.vec4(),))
fassert(glm.unpackUnorm4x4, (0,))
fassert(glm.packUnorm1x5_1x6_1x5, (glm.vec3(),))
fassert(glm.unpackUnorm1x5_1x6_1x5, (0,))
fassert(glm.packUnorm3x5_1x1, (glm.vec4(),))
fassert(glm.unpackUnorm3x5_1x1, (0,))
fassert(glm.packUnorm2x3_1x2, (glm.vec3(),))
fassert(glm.unpackUnorm2x3_1x2, (0,))
fassert(glm.packSnorm1x8, (0.,))
fassert(glm.unpackSnorm1x8, (0,))
fassert(glm.packSnorm2x8, (glm.vec2(),))
fassert(glm.unpackSnorm2x8, (0,))
fassert(glm.packSnorm1x16, (0.,))
fassert(glm.unpackSnorm1x16, (0,))
fassert(glm.packSnorm4x16, (glm.vec4(),))
fassert(glm.unpackSnorm4x16, (0,))
fassert(glm.packSnorm3x10_1x2, (glm.vec4(),))
fassert(glm.unpackSnorm3x10_1x2, (0,))
fassert(glm.packI3x10_1x2, (glm.ivec4(),))
fassert(glm.unpackI3x10_1x2, (0,))
fassert(glm.packU3x10_1x2, (glm.uvec4(),))
fassert(glm.unpackU3x10_1x2, (0,))
fassert(glm.packF2x11_1x10, (glm.vec3(),))
fassert(glm.unpackF2x11_1x10, (0,))
fassert(glm.packF3x9_E1x5, (glm.vec3(),))
fassert(glm.unpackF3x9_E1x5, (0,))

for args in gen_args("V3__fF"):
    fassert(glm.packRGBM, args)

for args in gen_args("V4__fF"):
    fassert(glm.unpackRGBM, args)

for args in gen_args("V__f"):
    fassert(glm.packHalf, args)

for args in gen_args("V__S"):
    fassert(glm.unpackHalf, args)
#/packing #

# random #
for args in gen_args("NN_VV__fFiqsuIQSU"):
    comp = args[0] > args[1]
    if type(comp) != bool: comp = any(comp)
    if len(args) == 2 and comp:
        args = (args[1], args[0])
    fassert(glm.linearRand, args)
    fassert(glm.gaussRand, args)

for args in gen_args("#pN"):
    fassert(glm.circularRand, args)
    fassert(glm.sphericalRand, args)
    fassert(glm.diskRand, args)
    fassert(glm.ballRand, args)
#/random #

# round #
for args in gen_args("N_V__iqsu"):
    # need to add support for isPowerOfTwo
    fassert(glm.isPowerOfTwo, args)
    fassert(glm.ceilPowerOfTwo, args)
    fassert(glm.floorPowerOfTwo, args)
    fassert(glm.roundPowerOfTwo, args)

for args in gen_args("#pNN_VV__iqsu"):
    # need to add support for isMultiple
    fassert(glm.ceilMultiple, args)
    fassert(glm.floorMultiple, args)
    fassert(glm.roundMultiple, args)
#/round #

# reciprocal #
for args in gen_args("N_V__fF"):
    fassert(glm.sec, args)
    fassert(glm.csc, args)
    fassert(glm.cot, args)
    fassert(glm.asec, args)
    fassert(glm.acsc, args)
    fassert(glm.acot, args)
    fassert(glm.sech, args)
    fassert(glm.csch, args)
    fassert(glm.coth, args)
    fassert(glm.asech, args)
    fassert(glm.acsch, args)
    fassert(glm.acoth, args)
#/reciprocal #

# type_ptr #
for args in gen_args("V2_V3_V4_M_Q"):
    fassert(glm.value_ptr, args)

for args in list(gen_args("V_M_Q")) + [(x,) for x in (list(vector_types) + list(matrix_types) + list(quat_types))]:
    fassert(glm.sizeof, args)

for L in range(2, 5):
    for T in prefixes:
        vec = getattr(glm, "{T}vec{L}".format(T=T,L=L))()
        ptr = glm.value_ptr(vec)
        fassert(getattr(glm, "make_vec{L}".format(L=L)), (ptr,))

for C in range(2, 5):
    for R in range(2, 5):
        for T_id in matrix_type_ids:
            T = prefixes[T_id]
            mat = getattr(glm, "{T}mat{C}x{R}".format(T=T,C=C,R=R))()
            ptr = glm.value_ptr(mat)
            fassert(getattr(glm, "make_mat{C}x{R}".format(C=C,R=R)), (ptr,))

for T_id in quat_type_ids:
    T = prefixes[T_id]
    quat = getattr(glm, "{T}quat".format(T=T))()
    ptr = glm.value_ptr(quat)
    fassert(glm.make_quat, (ptr,))
#/type_ptr #

# ulp #
for args in gen_args("#uN_V_NNi_VNi_VVi__fF"):
    fassert(glm.next_float, args)
    fassert(glm.prev_float, args)

for args in gen_args("NN_VV__fF"):
    fassert(glm.float_distance, args)
#/ulp #
##/EXTENSIONS ##
    
## UNSTABLE EXTENSIONS ##
# polar_coordinates #
for args in gen_args("V3__fF"):
    fassert(glm.polar, args)
    
for args in gen_args("V2__fF"):
    fassert(glm.euclidean, args)
#/polar_coordinates #

# norm #
for args in gen_args("VV__fF"):
    fassert(glm.distance2, args)

for args in gen_args("V_N__fF"):
    fassert(glm.length2, args)

for args in gen_args("V3V3_V3__fF"):
    fassert(glm.l1Norm, args)

for args in gen_args("V3V3_V3__fF"):
    fassert(glm.l2Norm, args)

for args in gen_args("#uV3V3Ni_V3Ni__fF"):
    fassert(glm.lxNorm, args)
#/norm #

# matrix_decompose #
for args in gen_args("M44V3QV3V3V4__fF"):
    fassert(glm.decompose, args)
#/matrix_decompose #
##/UNSTABLE EXTENSIONS ##
    
print("Finished tests in {:.3g}s".format(time.time()-start_time))
