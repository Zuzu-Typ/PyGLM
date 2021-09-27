import glm, sys, random, time, copy, re, math

from collections import OrderedDict

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

ctypes_types = [glm.c_float, glm.c_double, glm.c_int64, glm.c_int32, glm.c_int16, glm.c_int8, glm.c_uint64, glm.c_uint32, glm.c_uint16, glm.c_uint8, glm.c_bool]

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

mvec_mats = {
    "f2" : glm.fmat2x2(0),
    "f3" : glm.fmat2x3(0),
    "f4" : glm.fmat2x4(0),
    "d2" : glm.dmat2x2(0),
    "d3" : glm.dmat2x3(0),
    "d4" : glm.dmat2x4(0),
    "i2" : glm.imat2x2(0),
    "i3" : glm.imat2x3(0),
    "i4" : glm.imat2x4(0),
    "u2" : glm.umat2x2(0),
    "u3" : glm.umat2x3(0),
    "u4" : glm.umat2x4(0),
    }

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
            rf = rand_func
            if T == "b":
                rf = lambda: random.choice((True, False))
            args.append(getattr(glm, "{T}vec{L}".format(T=T, L=L))(*(rf() for x in range(L))))

        elif "P" in arg:
            if len(arg) == 3 and arg[2] in "fFi":
                T = prefixes[suffixes.index(arg[2])]
            else:
                T = prefixes[suffixes.index(type_)]

            L = int(arg[1])
            args.append(mvec_mats["{T}{L}".format(T=T, L=L)][0])

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
    if "#M" in args_string:
        supports_mvec = True
        args_string = args_string.replace("#M", "")
    else:
        supports_mvec = False
    if "#u" in args_string:
        rand_func = randf
        args_string = args_string.replace("#u", "")
    elif "#p" in args_string:
        rand_func = lambda: randf() + 1
        args_string = args_string.replace("#p", "")
    elif "#d" in args_string:
        rand_func = random.random
        args_string = args_string.replace("#d", "")
    elif "#x" in args_string:
        res = randf()
        rand_func = lambda: res
        args_string = args_string.replace("#x", "")
    else:
        rand_func = None

    if "__" in args_string:
        arg_part, type_part = args_string.split("__")
        parts = arg_part.split("_")
        types = type_part
    else:
        parts = args_string.split("_")
        types = suffixes

    mvec_types = ("f" if "f" in types else "") + ("F" if "F" in types else "") + ("i" if "i" in types else "") + ("I" if "I" in types else "")
    
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
            if supports_mvec:
                for T in mvec_types:
                    for L in range(2, 5):
                        yield get_args(list_replace(arg_strings, "V", "P{L}".format(L=L)), T, rand_func)
        elif "P" in arg_strings:
            for T in mvec_types:
                for L in range(2, 5):
                    yield get_args(list_replace(arg_strings, "P", "P{L}".format(L=L)), T, rand_func)

        elif "Vf" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "Vf", "V{L}".format(L=L)), "f", rand_func)
            if supports_mvec:
                for L in range(2, 5):
                    yield get_args(list_replace(arg_strings, "Vf", "P{L}".format(L=L)), "f", rand_func)

        elif "VF" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "VF", "V{L}".format(L=L)), "F", rand_func)
            if supports_mvec:
                for L in range(2, 5):
                    yield get_args(list_replace(arg_strings, "VF", "P{L}".format(L=L)), "F", rand_func)

        elif "Vi" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "Vi", "V{L}".format(L=L)), "i", rand_func)
            if supports_mvec:
                for L in range(2, 5):
                    yield get_args(list_replace(arg_strings, "Vi", "P{L}".format(L=L)), "i", rand_func)

        elif "VB" in arg_strings:
            for L in range(1, 5):
                yield get_args(list_replace(arg_strings, "VB", "V{L}".format(L=L)), "B", lambda: random.choice((True, False)))

        elif "V1" in arg_strings or "V2" in arg_strings or "V3" in arg_strings or "V4" in arg_strings or "M22" in arg_strings or "M23" in arg_strings or "M24" in arg_strings or "M32" in arg_strings or "M33" in arg_strings or "M34" in arg_strings or "M42" in arg_strings or "M43" in arg_strings or "M44" in arg_strings:
            for T in types:
                yield get_args(arg_strings, T, rand_func)
            if supports_mvec:
                for T in mvec_types:
                    yield get_args(list_replace(arg_strings, "V", "P"), T, rand_func)

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
def test_specific():
    assert isinstance(glm.version, str)
    assert isinstance(glm.license, str)
#/Specific #

# Initialization #
## vec1
def test_vec1_types():
    for args in gen_args("#u-_N_V1"): # need to add support for _V1_V2_V3_V4
        for T in vector_length_dict[1]:
            fassert(T, args)

## vec2
def test_vec2_types():
    for args in gen_args("#u-_N_NN_V2"):
        for T in vector_length_dict[2]:
            fassert(T, args)

    for args in gen_args("#uV2V3_V2V4"):
        fassert(type(args[0]), args[1:])

## vec3
def test_vec3_types():
    for args in gen_args("#u-_N_NNN_V3"):
        for T in vector_length_dict[3]:
            fassert(T, args)

    for args in gen_args("#uV3V4_V3NV2_V3V2N"):
        fassert(type(args[0]), args[1:])

## vec4
def test_vec4_types():
    for args in gen_args("#u-_N_NNNN_V4"):
        for T in vector_length_dict[4]:
            fassert(T, args)

    for args in gen_args("#uV4V2NN_V4NV2N_V4NNV2_V4NV3_V4V3N"):
        fassert(type(args[0]), args[1:])

## mat
def test_mat_types():
    for C in range(2, 5):
        for R in range(2, 5):
            for args in gen_args("#u-_N_" + "N"*(C*R) + "_" + "N"*(int(math.sqrt(C*R))) + "_M{C}{R}__fFiI".format(C=C, R=R)): # need support for _M
                for T in matrix_length_dict[(C,R)]:
                    fassert(T, args)

            for args in gen_args("#uM{C}{R}".format(C=C, R=R) + "V{R}".format(R=R)*C + "_" + "_".join(["M{C}{R}M{c}{r}".format(C=C, R=R, c=c, r=r) for c in range(2, 5) for r in range(2,5)]) + "__fFiI"):
                fassert(type(args[0]), args[1:])

    for args in gen_args("Q__f"):
        fassert(glm.mat3, args)
        fassert(glm.mat4, args)

    for args in gen_args("Q__F"):
        fassert(glm.dmat3, args)
        fassert(glm.dmat4, args)

## quat
def test_quat_types():
    for args in gen_args("#u-_V3_M33_M44_NV3_V3V3_NNNN_Q__f"): # need support for conversion constructors
        fassert(glm.quat, args)

## dquat
def test_dquat_types():
    for args in gen_args("#u-_V3_M33_M44_NV3_V3V3_NNNN_Q__F"): # need support for conversion constructors
        fassert(glm.dquat, args)

## array
def test_array_types():
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

    assert glm.array([glm.float32(x) for x in range(10)])
    assert glm.array(tuple([glm.float32(x) for x in range(10)]))
    assert glm.array({x : glm.float32(x) for x in range(10)}.values())
    assert glm.array(memoryview(glm.array([glm.float32(x) for x in range(10)])))

    assert glm.array(glm.float32, *range(10))
    assert glm.array.from_numbers(glm.float32, *range(10))
    assert glm.array([glm.float32, 1, 2, 3]) == glm.array((glm.float32, 1, 2, 3))
    assert glm.array(OrderedDict([(glm.float32, 1), (1, 2), (2, 3), (3, 4)]))
    assert glm.array(memoryview(glm.array.from_numbers(glm.float32, *range(10))))
    
    assert glm.array.zeros(1000, glm.uint8) == glm.array.zeros(1000, glm.u8vec1) == glm.array(glm.int8, 0).repeat(1000)
    assert glm.array.zeros(1000, glm.quat)
    assert glm.array.zeros(1000, glm.vec4)
    assert glm.array.zeros(1000, glm.mat4)

    arr = glm.array(glm.mat4(), glm.mat4(2))

    mv = memoryview(arr)

    assert glm.array.as_reference(mv) == arr
    assert glm.array.as_reference(mv).reference == mv
    assert glm.array.as_reference(arr).address == arr.address

    assert len(arr) == 2, arr
    assert arr.typecode == "f", arr
    assert arr.dtype == "float32", arr
    assert arr.ctype == glm.float32, arr
    assert arr.dt_size == 4, arr
    assert arr.itemsize == arr.dt_size * 4 * 4, arr
    assert arr.ptr, arr
    assert arr.nbytes == arr.itemsize * len(arr), arr
    assert arr.element_type == glm.mat4, arr
    assert arr.readonly == False
    assert arr.reference is None

    arr = glm.array.from_numbers(glm.int32, 5, 4, 3, 2, 1)

    assert arr.filter(lambda x: True) == arr
    assert arr.filter(lambda x: False) == arr.repeat(0)
    assert arr.filter(lambda x: x <= 3) == glm.array.from_numbers(glm.int32, 3, 2, 1)
    assert arr.map(lambda x: x) == arr 
    assert arr.map(lambda x: glm.vec3(x)) == glm.array(glm.vec3(5), glm.vec3(4), glm.vec3(3), glm.vec3(2), glm.vec3(1))
    assert arr.map(lambda x: (x, x) if x == 1 else None) == glm.array(glm.int32, 1, 1)
    assert arr.map(glm.add, glm.array([glm.vec2(x) for x in range(5)])) == glm.array([glm.vec2(5) for x in range(5)])
    assert glm.array(glm.int32, 0, 1, 1, 0, 0).map(glm.if_else, arr, glm.array(glm.int32, 1, 2, 3, 4, 5)) == glm.array(glm.int32, 1, 4, 3, 4, 5)
    assert glm.array(glm.int32, *(x * 4 for x in range(-5,5))).map(lambda *args: args if sum(args) == 0 else None, 
                                                                glm.array(glm.int32, *(x * 3 for x in range(-5,5))), 
                                                                glm.array(glm.int32, *(x * 2 for x in range(-5,5))),
                                                                glm.array(glm.int32, *(x * 1 for x in range(-5,5))),
                                                                glm.array(glm.int32, *(x * -9.4 for x in range(-5,5)))) == glm.array(glm.int32, 0, 0, 0, 0, 0)
    assert arr.map(lambda x: None) == arr.repeat(0)
    arr.sort(glm.cmp)
    assert arr == glm.array.from_numbers(glm.int32, 1, 2, 3, 4, 5)

    arr = glm.array(glm.vec3(5), glm.vec3(4), glm.vec3(3), glm.vec3(2), glm.vec3(1))

    assert arr.filter(lambda x: True) == arr
    assert arr.filter(lambda x: False) == arr.repeat(0)
    assert arr.filter(lambda x: x.x <= 3) == glm.array(glm.vec3(3), glm.vec3(2), glm.vec3(1))
    assert arr.map(lambda x: x) == arr 
    assert arr.map(lambda x: x.xxxx) == glm.array(glm.vec4(5), glm.vec4(4), glm.vec4(3), glm.vec4(2), glm.vec4(1))
    assert arr.map(lambda x: (x, x) if x.x == 1 else None) == glm.array(glm.vec3(1), glm.vec3(1))
    assert arr.map(lambda x: None) == arr.repeat(0)
    assert arr.map(lambda x: (x.x), ctype = glm.int32) == glm.array.from_numbers(glm.int32, 5, 4, 3, 2, 1)
    arr.sort(lambda x, y: glm.cmp(x.x, y.x))
    assert arr == glm.array(glm.vec3(1), glm.vec3(2), glm.vec3(3), glm.vec3(4), glm.vec3(5))


# repr #
def test_repr_eval():
    glm_locals = {a : getattr(glm, a) for a in dir(glm)}
    for T in vector_types + matrix_types + quat_types:
        fassert(lambda o: eval(repr(o), glm_locals), (T(),))

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
    arr4 = glm.array(glm.int8, *range(10))
    assert eval(repr(arr), glm_locals) == arr, (arr, repr(arr), eval(repr(arr), glm_locals))
    assert eval(repr(arr2), glm_locals) == arr2, (arr2, repr(arr2), eval(repr(arr2), glm_locals))
    assert eval(repr(arr3), glm_locals) == arr3, (arr3, repr(arr3), eval(repr(arr3), glm_locals))
    assert eval(repr(arr4), glm_locals) == arr4, (arr4, repr(arr4), eval(repr(arr4), glm_locals))
#/repr #

# neg #
def test_neg():
    for obj in gen_obj("#MV_M_Q__fFiqsuB"):
        fassert(obj.__neg__, ())
        assert (-glm.array(obj))[0] == -obj, obj
#/neg #

# pos #
def test_pos():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        fassert(obj.__pos__, ())
        assert (+glm.array(obj))[0] == +obj, obj
#/pos #

# abs #
def test_abs():
    for obj in gen_obj("#MV__fFiqsuIQSU"):
        fassert(obj.__abs__, ())
        assert (abs(glm.array(obj)))[0] == abs(obj), obj
#/abs #

# invert #
def test_invert():
    for obj in gen_obj("#MV__iqsuIQSU"):
        fassert(obj.__invert__, ())
        assert (abs(glm.array(obj)))[0] == abs(obj), obj
#/invert #

# add #
def test_add():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSUB"):
        fassert(obj.__add__, (obj,))
        assert (glm.array(obj) + glm.array(obj))[0] == obj + obj, obj
        assert (glm.array(obj) + obj)[0] == obj + obj, obj
        assert (obj + glm.array(obj))[0] == obj + obj, obj

    arr = glm.array(glm.mat4())
    fassert(arr.concat, (arr,))
    fassert((arr.concat(arr)).concat, (arr,))
#/add #

# sub #
def test_sub():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        fassert(obj.__sub__, (obj,))
        assert (glm.array(obj) - glm.array(obj))[0] == obj - obj, obj
        assert (glm.array(obj) - obj)[0] == obj - obj, obj
        assert (obj - glm.array(obj))[0] == obj - obj, obj
#/sub #

# mul #
def test_mul():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSUB"):
        fassert(obj.__mul__, (1,))
        assert (glm.array(obj) * glm.array(glm.array(obj).ctype, 1))[0] == obj * 1, obj
        assert (glm.array(obj) * 1)[0] == obj * 1, obj
        assert (obj * glm.array(glm.array(obj).ctype, 1))[0] == obj * 1, obj

    arr = glm.array(glm.mat4())
    fassert(arr.repeat, (3,))
    fassert((arr.repeat(4)).repeat, (2,))
#/mul #

# div #
def test_div():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        fassert(obj.__truediv__, (1,))

    for obj in gen_obj("#MV_Q__fFiqsuIQSU"):
        fassert(obj.__truediv__, (1,))
        assert (glm.array(obj) / glm.array(glm.array(obj).ctype, 1))[0] == obj / 1, obj
        assert (glm.array(obj) / 1)[0] == obj / 1, obj
        assert (obj / glm.array(glm.array(obj).ctype, 1))[0] == obj / 1, obj

    for obj in gen_obj("V__iqsuIQSU"):
        try:
            obj.__truediv__(type(obj)(0))
            fail(obj)
        except ZeroDivisionError:
            pass
    for obj in gen_obj("P__iI"):
        try:
            obj.__truediv__(obj)
            fail(obj)
        except ZeroDivisionError:
            pass

    for obj in gen_obj("#MV_M_Q__iqsuIQSU"):
        try:
            obj.__truediv__(0)
            fail(obj)
        except ZeroDivisionError:
            pass
#/div #

# mod #
def test_mod():
    for obj in gen_obj("#MV__fF"):
        fassert(obj.__mod__, (1,))

    for obj in gen_obj("#MV__fF"):
        assert (glm.array(obj) % glm.array(glm.array(obj).ctype, 1))[0] == obj % 1, obj
        assert (glm.array(obj) % 1)[0] == obj % 1, obj
        assert (obj % glm.array(glm.array(obj).ctype, 1))[0] == obj % 1, obj
#/mod #

# floordiv #
def test_floordiv():
    for obj in gen_obj("#MV__fF"):
        fassert(obj.__floordiv__, (1,))
#/floordiv #

# divmod #
def test_divmod():
    for obj in gen_obj("#MV__fF"):
        fassert(obj.__divmod__, (1,))
#/divmod #

# lshift #
def test_lshift():
    for obj in gen_obj("#MV__iqsuIQSU"):
        fassert(obj.__lshift__, (1,))
        fassert(obj.__lshift__, (obj,))
#/lshift #

# rshift #
def test_rshift():
    for obj in gen_obj("#MV__iqsuIQSU"):
        fassert(obj.__rshift__, (1,))
        fassert(obj.__rshift__, (obj,))
#/rshift #

# and #
def test_and():
    for obj in gen_obj("#MV__iqsuIQSU"):
        fassert(obj.__and__, (1,))
        fassert(obj.__and__, (obj,))
#/and #

# or #
def test_or():
    for obj in gen_obj("#MV__iqsuIQSU"):
        fassert(obj.__or__, (1,))
        fassert(obj.__or__, (obj,))
#/or #

# xor #
def test_xor():
    for obj in gen_obj("#MV__iqsuIQSU"):
        fassert(obj.__xor__, (1,))
        fassert(obj.__xor__, (obj,))
#/xor #

# pow #
def test_pow():
    for obj in gen_obj("#p#MV__fF"):
        fassert(obj.__pow__, (obj,))
        fassert(obj.__pow__, (obj, obj))

        assert (glm.array(obj) ** glm.array(obj))[0] == obj ** obj, obj
        assert (glm.array(obj) ** obj)[0] == obj ** obj, obj
        assert (obj ** glm.array(obj))[0] == obj ** obj, obj
#/pow #

# matmul #
def test_matmul():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        try:
            obj @ obj
        except TypeError:
            pass
#/matmul #

# iadd #
def test_iadd():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSUB"):
        fassert(obj.__iadd__, (obj,))
    
    arr = glm.array(glm.mat4())
    fassert(arr.iconcat, (arr,))
    fassert(arr.iconcat, (arr,))
#/iadd #

# isub #
def test_isub():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        fassert(obj.__isub__, (obj,))
#/isub #

# imul #
def test_imul():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSUB"):
        fassert(obj.__imul__, (1,))

    arr = glm.array(glm.mat4())
    fassert(arr.irepeat, (3,))
    fassert(arr.irepeat, (3,))
#/imul #

# idiv #
def test_idiv():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        fassert(obj.__itruediv__, (1,))
#/idiv #

# imod #
def test_imod():
    for obj in gen_obj("#MV__fF"):
        fassert(obj.__imod__, (1,))
#/imod #

# ifloordiv #
def test_ifloordiv():
    for obj in gen_obj("#MV__fF"):
        fassert(obj.__ifloordiv__, (1,))
#/ifloordiv #

# ipow #
def test_ipow():
    for obj in gen_obj("#MV__fF"):
        fassert(obj.__ipow__, (obj,))
#/ipow #

# imatmul #
def test_imatmul():
    for obj in gen_obj("#MV_M_Q__fFiqsuIQSU"):
        try:
            obj @= obj
        except TypeError:
            pass
#/imatmul #

# str #
def test_str():
    for obj in gen_obj("#MV_M_Q"):
        assert str(obj), obj
#/str #

# repr #
def test_repr():
    for obj in gen_obj("#MV_M_Q"):
        assert repr(obj), obj
#/repr #

# len #
def test_len():
    for obj in gen_obj("#MV_M_Q"):
        assert len(obj), obj

    arr = glm.array(glm.mat4())
    arr2 = arr.concat(arr)
    assert len(arr) == 1, arr
    assert len(arr2) == 2, arr2
#/len #

# getitem #
def test_getitem():
    for obj in gen_obj("#MV_M_Q"):
        for i in range(len(obj)):
            assert obj[i] != None, obj

    arr = glm.array(glm.mat4(), glm.mat4(2))
    assert arr[0] == glm.mat4(), arr
    assert arr[1] == glm.mat4(2) == arr[-1], arr

    arr = glm.array(*glm.mat4())
    assert arr[:] == arr, arr
    assert arr[1:] == glm.array(glm.vec4(0,1,0,0),glm.vec4(0,0,1,0),glm.vec4(0,0,0,1)), arr
    assert arr[::2] == glm.array(glm.vec4(1,0,0,0),glm.vec4(0,0,1,0)), arr
    assert arr[1::2] == glm.array(glm.vec4(0,1,0,0),glm.vec4(0,0,0,1)), arr
#/getitem #

# setitem #
def test_setitem():
    for obj in gen_obj("#MV_M_Q"):
        for i in range(len(obj)):
            fassert(obj.__setitem__,(i, obj[i]))

    arr = glm.array(glm.mat4(), glm.mat4(2))
    arr[0] = glm.mat4(3)
    assert arr[0] == glm.mat4(3), arr
    del arr[0]
    assert arr == glm.array(glm.mat4(2)), arr

    arr = glm.array(*glm.mat4())
    del arr[::2]
    assert arr == glm.array(glm.vec4(0,1,0,0),glm.vec4(0,0,0,1)), arr
    arr[:] = glm.array(glm.vec4(), glm.vec4(2))
    assert arr == glm.array(glm.vec4(), glm.vec4(2)), arr
#/setitem #

# contains #
def test_contains():
    for obj in gen_obj("#MV_M_Q"):
        assert obj[0] in obj, obj

    arr = glm.array(glm.mat4(), glm.mat4(2))
    assert glm.mat4(2) in arr and not glm.mat4(3) in arr, arr
#/contains #

# Richcompare #
## EQ
def test_EQ():
    for obj in gen_obj("V_M_Q"):
        assert obj == type(obj)(obj), obj

    arr = glm.array(glm.mat4(), glm.mat4(2))
    arr2 = glm.array(glm.mat4(), glm.mat4(2))
    arr3 = glm.array(glm.mat4(), glm.mat4(2), glm.mat4(0))
    assert arr == arr2 and not arr == arr3, (arr, arr2, arr3)

## NE
def test_NE():
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
def test_LT():
    for obj in gen_obj("#uV__fFiqsuIQSU"):
        assert all(obj < (obj + 1)) and not any(obj < obj), obj

## LE
def test_LE():
    for obj in gen_obj("#uV__fFiqsuIQSU"):
        assert all(obj <= obj) and all(obj <= (obj + 1)) and not any((obj + 1) <= obj), obj

## GT
def test_GT():
    for obj in gen_obj("#uV__fFiqsuIQSU"):
        assert all((obj + 1) > obj) and not any(obj > obj), obj

## GE
def test_GE():
    for obj in gen_obj("#uV__fFiqsuIQSU"):
        assert all(obj >= obj) and all((obj + 1) >= obj) and not any(obj >= (obj + 1)), obj
#/Richcompare #

# iter #
def test_iter():
    for obj in gen_obj("V_M_Q"):
        fassert(iter, (obj,))

    arr = glm.array(glm.mat4(), glm.mat4(2))
    assert list(arr) == arr.to_list(), arr
#/iter #

# hash #
def test_hash():
    for obj in gen_obj("V_M_Q"):
        fassert(hash, (obj,))

    arr = glm.array(glm.mat4(), glm.mat4(2))
    assert hash(arr), arr
#/hash #

# buffer protocol #
def check_buffer_protocol(type_, shape, format):
    obj = type_()
    memview = memoryview(obj)
    assert shape == memview.shape
    assert format == memview.format

def test_buffer_protocol():
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
        (glm.mat2x3, (3, 2), "f"),
        (glm.mat2x4, (4, 2), "f"),
        (glm.mat3x2, (2, 3), "f"),
        (glm.mat3x3, (3, 3), "f"),
        (glm.mat3x4, (4, 3), "f"),
        (glm.mat4x2, (2, 4), "f"),
        (glm.mat4x3, (3, 4), "f"),
        (glm.mat4x4, (4, 4), "f"),
    
    
        (glm.dmat2x2, (2, 2), "d"),
        (glm.dmat2x3, (3, 2), "d"),
        (glm.dmat2x4, (4, 2), "d"),
        (glm.dmat3x2, (2, 3), "d"),
        (glm.dmat3x3, (3, 3), "d"),
        (glm.dmat3x4, (4, 3), "d"),
        (glm.dmat4x2, (2, 4), "d"),
        (glm.dmat4x3, (3, 4), "d"),
        (glm.dmat4x4, (4, 4), "d"),
    
    
        (glm.imat2x2, (2, 2), "i"),
        (glm.imat2x3, (3, 2), "i"),
        (glm.imat2x4, (4, 2), "i"),
        (glm.imat3x2, (2, 3), "i"),
        (glm.imat3x3, (3, 3), "i"),
        (glm.imat3x4, (4, 3), "i"),
        (glm.imat4x2, (2, 4), "i"),
        (glm.imat4x3, (3, 4), "i"),
        (glm.imat4x4, (4, 4), "i"),
    
    
        (glm.umat2x2, (2, 2), "I"),
        (glm.umat2x3, (3, 2), "I"),
        (glm.umat2x4, (4, 2), "I"),
        (glm.umat3x2, (2, 3), "I"),
        (glm.umat3x3, (3, 3), "I"),
        (glm.umat3x4, (4, 3), "I"),
        (glm.umat4x2, (2, 4), "I"),
        (glm.umat4x3, (3, 4), "I"),
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
def test_lists_and_tuples():
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
def test_copy():
    for args in gen_args("V_M_Q"):
        fassert(copy.copy, args)
        fassert(copy.deepcopy, args)

    arr = glm.array(glm.mat4(), glm.mat4(2))
    assert copy.copy(arr) == arr, arr
    assert copy.deepcopy(arr) == arr, arr
#/copy module #

# to_list #
def test_to_list():
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
def test_to_tuple():
    for args in gen_args("V_Q"):
        for arg in args:
            assert arg.to_tuple() == tuple([x for x in arg])

    for args in gen_args("M"):
        for arg in args:
            assert arg.to_tuple() == tuple([tuple([y for y in x]) for x in arg])

    arr = glm.array(glm.mat4(), glm.mat4(2))
    assert arr.to_tuple() == (glm.mat4(), glm.mat4(2))
#/to_tuple #

# to/from_bytes #
def test_to_from_bytes():
    for obj in gen_obj("V_M_Q"):
        assert type(obj).from_bytes(obj.to_bytes()) == obj, repr(obj)
    for obj in gen_obj("#MV"):
        assert obj.to_bytes() == bytes(obj), repr(obj)

    for args in gen_args("VVV_MMM_QQQ"):
        arr = glm.array(args)
        assert arr.from_bytes(arr.to_bytes(), arr.element_type) == arr
#/to/from_bytes #

# reinterpret_cast #
def test_reinterpret_cast():
    arr = glm.array.zeros(8*3*3*4*4, glm.uint8)

    for type_ in (vector_types + matrix_types + quat_types + ctypes_types):
        assert arr.reinterpret_cast(type_).element_type == type_
#/reinterpret_cast #

# pickling #
import os
if (eval(os.environ.get("TEST_PICKLING", "True"))):
    from pickle import dumps, loads

    def test_pickling():
        for obj in gen_obj("V_Q"):
            assert loads(dumps(obj)) == obj, obj

        for obj in gen_obj("M"):
            assert loads(dumps(obj)) == obj, obj
            assert loads(dumps(obj[0])) == obj[0], obj

        arr = glm.array(glm.mat4(), glm.mat4(2))
        assert loads(dumps(arr)) == arr
#/pickling #

# other #
def test_other():
    test_values = [-1, 0, 2, 3]
    assert all([(+a) == glm.pos(a) for a in test_values])
    assert all([(-a) == glm.neg(a) for a in test_values])
    assert all([(~a) == glm.inv(a) for a in test_values])

    test_values = [(1, 2), (3, 4), (-1, 1), (0, 2)]
    assert all([(a + b) == glm.add(a,b) for a, b in test_values])
    assert all([(a - b) == glm.sub(a,b) for a, b in test_values])
    assert all([(a * b) == glm.mul(a,b) for a, b in test_values])
    assert all([(a / b) == glm.div(a,b) for a, b in test_values])
    assert all([(a // b) == glm.floordiv(a,b) for a, b in test_values])
    assert all([(a % b) == glm.mod(a,b) for a, b in test_values])
    assert all([(a << b) == glm.lshift(a,b) for a, b in test_values])
    assert all([(a >> b) == glm.rshift(a,b) for a, b in test_values])
    assert all([(a & b) == glm.and_(a,b) for a, b in test_values])
    assert all([(a ^ b) == glm.xor(a,b) for a, b in test_values])
    assert all([(a | b) == glm.or_(a,b) for a, b in test_values])
    assert all([(-1 if a < b else 1 if a > b else 0) == glm.cmp(a,b) for a, b in test_values])

    test_values = [(1, 2, 3), (3, 4, 5), (-1, 1, 0), (0, 2, 3)]
    assert all([(x if b else y) == glm.if_else(b, x, y) for b, x, y in test_values])
#/other #

## DETAIL ##

# func_packing #
def test_func_packing():
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
def test_func_integer():
    for args in gen_args("#uVVV__I"):
        fassert(glm.uaddCarry, args)

    for args in gen_args("#uVVV__I"):
        fassert(glm.usubBorrow, args)

    for args in gen_args("#uVVVV__I"):
        fassert(glm.umulExtended, args)

    for args in gen_args("#uVVVV__i"):
        fassert(glm.imulExtended, args)

    for args in gen_args("#uNNN_VNN__iqsuIQSU"):
        fassert(glm.bitfieldExtract, args)

    for args in gen_args("#uNNNN_VVNN__iqIQ"):
        fassert(glm.bitfieldInsert, args)

    for args in gen_args("#uV_N__iqIQ"):
        fassert(glm.bitfieldReverse, args)

    for args in gen_args("#uV_N__iqsuIQSU"):
        fassert(glm.bitCount, args)
        fassert(glm.findLSB, args)
        fassert(glm.findMSB, args)
#/func_integer #

# func_vector_relational #
def test_func_vector_relational():
    for args in gen_args("#uVV_QQ_NNNi_VfVfNi_VFVFNi_MfMfNi_MFMFNi"): # need to add support for _MM
        fassert(glm.equal, args)
        fassert(glm.notEqual, args)

    for args in gen_args("#uVV_QQ"):
        fassert(glm.lessThan, args)
        fassert(glm.lessThanEqual, args)
        fassert(glm.greaterThan, args)
        fassert(glm.greaterThanEqual, args)

    for args in gen_args("#uV__B"):
        fassert(glm.any, args)
        fassert(glm.all, args)
        fassert(glm.not_, args)
#/func_vector_relational #

# func_exponential #
def test_func_exponential():
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
def test_func_common():
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

    for args in gen_args("NN_VV_NNN_VVV_NNNN_VVVV_NNNNNNNNNNNN_VVVVVVVVVVVV__fFiqsuIQSU"):
        fassert(glm.min, (args,))
        fassert(glm.max, (args,))

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

    for args in gen_args("N_VVi__fF"):
        fassert(glm.frexp, args)

    for args in gen_args("VVi__fF"):
        fassert(glm.ldexp, args)

    for args in gen_args("N_V__f"):
        fassert(lambda x: glm.intBitsToFloat(glm.floatBitsToInt(x)), args)
        fassert(lambda x: glm.uintBitsToFloat(glm.floatBitsToUint(x)), args)

    for args in gen_args("N_VV__fF"):
        fassert(glm.modf, args)
#/func_common #

# func_geometric #
def test_func_geometric():
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
def test_func_matrix():
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
def test_func_trigonometric():
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
def test_color_space():
    for args in gen_args("V_VN__fF"):
        fassert(glm.convertLinearToSRGB, args)
        fassert(glm.convertSRGBToLinear, args)
#/color_space #

# constants #
def test_constants():
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
def test_epsilon():
    for args in gen_args("NNN_VVN_QQN_VVV__fF"):
        fassert(glm.epsilonEqual, args)
        fassert(glm.epsilonNotEqual, args)
#/epsilon #

# integer #
def test_integer():
    for args in gen_args("#uN_V__fF"):
        fassert(glm.iround, args)
        fassert(glm.uround, args)
#/integer #

# matrix_inverse #
def test_matrix_inverse():
    for args in gen_args("M33_M44__fF"):
        fassert(glm.affineInverse, args)

    for args in gen_args("M22_M33_M44__fF"):
        fassert(glm.inverseTranspose, args)
#/matrix_inverse #

# matrix_transform #
def test_matrix_transform():
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
def test_quaternion():
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
def test_matrix_access():
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
def test_noise():
    for args in gen_args("V2_V3_V4_V2V2_V3V3_V4V4__fF"):
        fassert(glm.perlin, args)

    for args in gen_args("V2_V3_V4__fF"):
        fassert(glm.simplex, args)
#/noise #

# packing #
def test_packing():
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

    for args in gen_args("V__fF"):
        for dt in (glm.int8, glm.int16, glm.int32, glm.int64, glm.uint8, glm.uint16, glm.uint32, glm.uint64):
            fassert(glm.packSnorm, (dt, args[0]))

    for args in gen_args("V__iqsuIQSU"):
        for dt in (glm.float32, glm.float64):
            fassert(glm.unpackSnorm, (dt, args[0]))

    for args in gen_args("V__fF"):
        for dt in (glm.uint8, glm.uint16, glm.uint32, glm.uint64):
            fassert(glm.packUnorm, (dt, args[0]))

    for args in gen_args("V__IQSU"):
        for dt in (glm.float32, glm.float64):
            fassert(glm.unpackUnorm, (dt, args[0]))
#/packing #

# random #
def test_random():
    for args in gen_args("#xNN_VV__fFiqsuIQSU"):
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

    fassert(glm.setSeed, (0,))
#/random #

# round #
def test_round():
    for args in gen_args("N_V__iqsu"):
        # need to add support for isPowerOfTwo
        #fassert(glm.isPowerOfTwo, args)
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
def test_reciprocal():
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
def test_type_ptr():
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
def test_ulp():
    for args in gen_args("#uN_V_NNi_VNi_VVi__fF"):
        fassert(glm.next_float, args)
        fassert(glm.prev_float, args)

    for args in gen_args("NN_VV__fF"):
        fassert(glm.float_distance, args)
#/ulp #
##/EXTENSIONS ##
    
## UNSTABLE EXTENSIONS ##
# polar_coordinates #
def test_polar_coordinated():
    for args in gen_args("V3__fF"):
        fassert(glm.polar, args)
    
    for args in gen_args("V2__fF"):
        fassert(glm.euclidean, args)
#/polar_coordinates #

# norm #
def test_norm():
    for args in gen_args("VV__fF"):
        fassert(glm.distance2, args)

    for args in gen_args("V_N__fF"):
        fassert(glm.length2, args)

    for args in gen_args("V3V3_V3__fF"):
        fassert(glm.l1Norm, args)

    for args in gen_args("V3V3_V3__fF"):
        fassert(glm.l2Norm, args)

    for args in gen_args("V3V3_V3__fF"):
        fassert(glm.lMaxNorm, args)

    for args in gen_args("#uV3V3Ni_V3Ni__fF"):
        fassert(glm.lxNorm, args)
#/norm #

# matrix_decompose #
def test_matrix_decompose():
    for args in gen_args("M44V3QV3V3V4__fF"):
        fassert(glm.decompose, args)
#/matrix_decompose #

# matrix_transform_2d #
def test_matrix_transform_2d():
    for args in gen_args("M33N__fF"):
        fassert(glm.rotate, args)
        fassert(glm.shearX, args)
        fassert(glm.shearY, args)
    for args in gen_args("M33V2__fF"):
        fassert(glm.scale, args)
        fassert(glm.translate, args)
#/matrix_transform_2d #

# rotate_vector #
def test_rotate_vector():
    for args in gen_args("V3V3__fF"):
        fassert(glm.orientation, args)
    for args in gen_args("V2N_V3NV3_V4NV3__fF"):
        fassert(glm.rotate, args)
    for args in gen_args("V3N_V4N__fF"):
        fassert(glm.rotateX, args)
        fassert(glm.rotateY, args)
        fassert(glm.rotateZ, args)
    for args in gen_args("V3V3N__fF"):
        fassert(glm.slerp, args)
#/rotate_vector #
##/UNSTABLE EXTENSIONS ##



### SPECIFIC TESTS ###

def test_spec_init():
    ## vectors ##
    # vec1
    for vecT in vector_length_dict[1]:
        assert vecT() == vecT(0) and vecT(1) == vecT(1) and vecT(1).x and not vecT(0).x, vecT 
        assert vecT(vecT(5)) == vecT(5) and vecT(vecT(4).xx) == vecT(4) and vecT(vecT(3).xxx) == vecT(3) and vecT(vecT(2).xxxx) == vecT(2), vecT
        
        assert vecT((8,)) == vecT(8)

        for vecB in vector_length_dict[1]:
            assert vecT(vecB(1)) == vecT(1), (vecT, vecB)

        assert vecT(x = 5) == vecT(5), vecT

    # vec2
    for vecT in vector_length_dict[2]:
        assert vecT() == vecT(0) and vecT(1) == vecT(1) and vecT(1).x and not vecT(0).x and vecT(1).y and not vecT(0).y, vecT 
        assert vecT(vecT(5)) == vecT(5) and vecT(vecT(3).xxx) == vecT(3) and vecT(vecT(2).xxxx) == vecT(2), vecT
        
        assert vecT(1, 2) == vecT(vecT(1).x, vecT(2).y)

        assert vecT(1, 2).yx == vecT(2, 1)

        assert vecT((8, 7)) == vecT(8, 7)
        
        for vecB in vector_length_dict[2]:
            assert vecT(vecB(1)) == vecT(1), (vecT, vecB)

        assert vecT(y = 8, x = 5) == vecT(5, 8), vecT

    # vec3
    for vecT in vector_length_dict[3]:
        assert vecT() == vecT(0) and vecT(1) == vecT(1) and vecT(1).x and not vecT(0).x and vecT(1).y and not vecT(0).y and vecT(1).z and not vecT(0).z, vecT 
        assert vecT(vecT(5)) == vecT(5) and vecT(vecT(2).xxxx) == vecT(2), vecT
        
        assert vecT(1, 2, 3) == vecT(vecT(1).x, vecT(2).y, vecT(3).z)
        assert vecT(1, vecT(1, 2, 3).yz) == vecT(1, 2, 3) and vecT(vecT(1, 2, 3).xy, 3) == vecT(1, 2, 3)

        assert vecT(1, 2, 3).zyx == vecT(3, 2, 1)

        assert vecT((8, 7, 6)) == vecT(8, 7, 6)
        
        for vecB in vector_length_dict[3]:
            assert vecT(vecB(1)) == vecT(1), (vecT, vecB)

        assert vecT(z = 3, y = 8, x = 5) == vecT(5, 8, 3), vecT

    # vec4
    for vecT in vector_length_dict[4]:
        assert vecT() == vecT(0) and vecT(1) == vecT(1) and vecT(1).x and not vecT(0).x and vecT(1).y and not vecT(0).y and vecT(1).z and not vecT(0).z and vecT(1).w and not vecT(0).w, vecT 
        assert vecT(vecT(5)) == vecT(5), vecT
        
        assert vecT(1, 2, 3, 4) == vecT(vecT(1).x, vecT(2).y, vecT(3).z, vecT(4).w)
        assert vecT(1, 2, 3, 4) == vecT(1, vecT(1, 2, 3, 4).yzw) == vecT(vecT(1, 2, 3, 4).xyz, 4) == vecT(vecT(1, 2, 3, 4).xy, vecT(1, 2, 3, 4).zw) == vecT(1, vecT(1, 2, 3, 4).yz, 4)

        assert vecT(1, 2, 3, 4).wzyx == vecT(4, 3, 2, 1)

        assert vecT((8, 7, 6, 5)) == vecT(8, 7, 6, 5)
        
        for vecB in vector_length_dict[4]:
            assert vecT(vecB(1)) == vecT(1), (vecT, vecB)

        assert vecT(w = 4, z = 3, y = 8, x = 5) == vecT(5, 8, 3, 4), vecT
    ##/vectors ##
    
    ## matrices ##
    # mat2x2
    for matT in matrix_length_dict[(2, 2)]:
        assert matT() == matT(1) == matT(1, 0, 0, 1)
        assert matT(0) == matT(0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 2)

        assert matT(1, 2, 3, 4) == matT(matT(1, 2, 3, 4)[0], matT(1, 2, 3, 4)[1])

        assert matT(matT(1, 2, 3, 4)) == matT(1, 2, 3, 4)
        
        for matB in matrix_length_dict[(2, 2)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat2x3
    for matT in matrix_length_dict[(2, 3)]:
        assert matT() == matT(1) == matT(1, 0, 0, 0, 1, 0)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 0, 2, 0)

        assert matT(1, 2, 3, 4, 5, 6) == matT(matT(1, 2, 3, 4, 5, 6)[0], matT(1, 2, 3, 4, 5, 6)[1])

        assert matT(matT(1, 2, 3, 4, 5, 6)) == matT(1, 2, 3, 4, 5, 6)
        
        for matB in matrix_length_dict[(2, 3)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat2x4
    for matT in matrix_length_dict[(2, 4)]:
        assert matT() == matT(1) == matT(1, 0, 0, 0, 0, 1, 0, 0)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 0, 0, 2, 0, 0)

        assert matT(1, 2, 3, 4, 5, 6, 7, 8) == matT(matT(1, 2, 3, 4, 5, 6, 7, 8)[0], matT(1, 2, 3, 4, 5, 6, 7, 8)[1])

        assert matT(matT(1, 2, 3, 4, 5, 6, 7, 8)) == matT(1, 2, 3, 4, 5, 6, 7, 8)
        
        for matB in matrix_length_dict[(2, 4)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat3x2
    for matT in matrix_length_dict[(3, 2)]:
        assert matT() == matT(1) == matT(1, 0, 0, 1, 0, 0)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 2, 0, 0)

        assert matT(1, 2, 3, 4, 5, 6) == matT(matT(1, 2, 3, 4, 5, 6)[0], matT(1, 2, 3, 4, 5, 6)[1], matT(1, 2, 3, 4, 5, 6)[2])

        assert matT(matT(1, 2, 3, 4, 5, 6)) == matT(1, 2, 3, 4, 5, 6)
        
        for matB in matrix_length_dict[(3, 2)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat3x3
    for matT in matrix_length_dict[(3, 3)]:
        assert matT() == matT(1) == matT(1, 0, 0, 0, 1, 0, 0, 0, 1)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 0, 2, 0, 0, 0, 2)

        assert matT(1, 2, 3, 4, 5, 6, 7, 8, 9) == matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9)[0], matT(1, 2, 3, 4, 5, 6, 7, 8, 9)[1], matT(1, 2, 3, 4, 5, 6, 7, 8, 9)[2])

        assert matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9)) == matT(1, 2, 3, 4, 5, 6, 7, 8, 9)
        
        for matB in matrix_length_dict[(3, 3)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat3x4
    for matT in matrix_length_dict[(3, 4)]:
        assert matT() == matT(1) == matT(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0)

        assert matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) == matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[0], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[1], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[2])

        assert matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) == matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
        
        for matB in matrix_length_dict[(3, 4)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat4x2
    for matT in matrix_length_dict[(4, 2)]:
        assert matT() == matT(1) == matT(1, 0, 0, 1, 0, 0, 0, 0)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 2, 0, 0, 0, 0)

        assert matT(1, 2, 3, 4, 5, 6, 7, 8) == matT(matT(1, 2, 3, 4, 5, 6, 7, 8)[0], matT(1, 2, 3, 4, 5, 6, 7, 8)[1], matT(1, 2, 3, 4, 5, 6, 7, 8)[2], matT(1, 2, 3, 4, 5, 6, 7, 8)[3])

        assert matT(matT(1, 2, 3, 4, 5, 6, 7, 8)) == matT(1, 2, 3, 4, 5, 6, 7, 8)
        
        for matB in matrix_length_dict[(4, 2)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat4x3
    for matT in matrix_length_dict[(4, 3)]:
        assert matT() == matT(1) == matT(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0)

        assert matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) == matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[0], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[1], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[2], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)[3])

        assert matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)) == matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
        
        for matB in matrix_length_dict[(4, 3)]:
            assert matT(matB()) == matT(), (matT, matB)

    # mat4x4
    for matT in matrix_length_dict[(4, 4)]:
        assert matT() == matT(1) == matT(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)
        assert matT(0) == matT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) and matT(2) == matT(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2)

        assert matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16) == matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)[0], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)[1], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)[2], matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)[3])

        assert matT(matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) == matT(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
        
        for matB in matrix_length_dict[(4, 4)]:
            assert matT(matB()) == matT(), (matT, matB)
    ##/matrices ##

    ## quats ##
    for quaT in quat_types:
        assert quaT() == quaT(1, 0, 0, 0)

        assert quaT(1, 2, 3, 4).w == 1 and quaT(1, 2, 3, 4).x == 2 and quaT(1, 2, 3, 4).y == 3 and quaT(1, 2, 3, 4).z == 4

        assert quaT(1, 2, 3, 4) == quaT(quaT(1, 2, 3, 4))

        for quaB in quat_types:
            assert quaT(quaB(1, 2, 3, 4)) == quaT(1, 2, 3, 4)

        assert quaT(1, 2, 3, 4) == quaT(1, (2, 3, 4))

        assert all(glm.epsilonEqual(glm.vec3(1, 0, 0), glm.vec3(0, 1, 0) * glm.quat(glm.vec3(1, 0, 0), glm.vec3(0, 1, 0)), 0.00001))
        assert all(glm.epsilonEqual(glm.dvec3(1, 0, 0), glm.dvec3(0, 1, 0) * glm.dquat(glm.dvec3(1, 0, 0), glm.dvec3(0, 1, 0)), 0.00001))

        eulerAngles = glm.radians(glm.vec3(10, 20, 30))

        q = glm.quat(eulerAngles)

        assert glm.epsilonEqual(glm.pitch(q), glm.radians(10), 0.00001)
        assert glm.epsilonEqual(glm.yaw(q), glm.radians(20), 0.00001)
        assert glm.epsilonEqual(glm.roll(q), glm.radians(30), 0.00001)

        eulerAngles = glm.radians(glm.dvec3(10, 20, 30))

        q = glm.dquat(eulerAngles)

        assert glm.epsilonEqual(glm.pitch(q), glm.radians(10), 0.00001)
        assert glm.epsilonEqual(glm.yaw(q), glm.radians(20), 0.00001)
        assert glm.epsilonEqual(glm.roll(q), glm.radians(30), 0.00001)
    ##/quats ##

    ## arrays ##
    for obj in gen_obj("#MV_M_Q"):
        assert glm.array(obj).repeat(2) == glm.array(obj, obj) == glm.array(glm.array(obj, obj)) == glm.array.as_reference(glm.array(obj, obj)) and glm.array(obj).repeat(4) == glm.array(obj, obj, obj, obj) == glm.array([obj, obj, obj, obj]) == glm.array(obj, obj).repeat(3)[:4]

        assert glm.array.zeros(5, type(obj))

    for T in matrix_types + vector_types:
        assert glm.array.zeros(5, T) == glm.array([T(0)] * 5)

    for obj in gen_obj("V_M_Q"):
        assert glm.array(obj).element_type == type(obj)

    for cT in ctypes_types:
        assert glm.array(cT(2), cT(3)) == glm.array(cT, 2, 3) == glm.array.from_numbers(cT, 2, 3)

        assert glm.array(cT).ctype == cT
    ##/arrays ##

def test_spec_add():
    for vecT in vector_length_dict[1]:
        if (vecT == glm.bvec1):
            continue

        assert vecT(1) + vecT(1) == vecT(1 + 1)          == (glm.array(vecT(1)) + glm.array(vecT(1)))[0] == (glm.array(vecT(1)) + vecT(1))[0] == (vecT(1) + glm.array(vecT(1)))[0]
        assert vecT(2) + vecT(3) == vecT(3) + vecT(2)    == (glm.array(vecT(2)) + glm.array(vecT(3)))[0] == (glm.array(vecT(3)) + glm.array(vecT(2)))[0] 
        assert vecT(1) + 2 == vecT(1 + 2) == 2 + vecT(1) == (glm.array(vecT(1)) + 2)[0] == (2 + glm.array(vecT(1)))[0]
        assert vecT(0) + vecT(0) == vecT(0)              == (glm.array(vecT(0)) + glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[2]:
        if (vecT == glm.bvec2):
            continue

        assert vecT(1, 2) + vecT(1, 2) == vecT(1 + 1, 2 + 2) == (glm.array(vecT(1, 2)) + glm.array(vecT(1, 2)))[0]
        assert vecT(2) + vecT(3) == vecT(3) + vecT(2)        == (glm.array(vecT(2)) + glm.array(vecT(3)))[0] == (glm.array(vecT(3)) + glm.array(vecT(2)))[0] 
        assert vecT(1) + 2 == vecT(1 + 2)                    == (glm.array(vecT(1)) + 2)[0] == (2 + glm.array(vecT(1)))[0]
        assert vecT(0) + vecT(0) == vecT(0)                  == (glm.array(vecT(0)) + glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[3]:
        if (vecT == glm.bvec3):
            continue

        assert vecT(1, 2, 3) + vecT(1, 2, 3) == vecT(1 + 1, 2 + 2, 3 + 3) == (glm.array(vecT(1, 2, 3)) + glm.array(vecT(1, 2, 3)))[0]
        assert vecT(2) + vecT(3) == vecT(3) + vecT(2)                     == (glm.array(vecT(2)) + glm.array(vecT(3)))[0] == (glm.array(vecT(3)) + glm.array(vecT(2)))[0] 
        assert vecT(1) + 2 == vecT(1 + 2)                                 == (glm.array(vecT(1)) + 2)[0] == (2 + glm.array(vecT(1)))[0]
        assert vecT(0) + vecT(0) == vecT(0)                               == (glm.array(vecT(0)) + glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[4]:
        if (vecT == glm.bvec4):
            continue

        assert vecT(1, 2, 3, 4) + vecT(1, 2, 3, 4) == vecT(1 + 1, 2 + 2, 3 + 3, 4 + 4) == (glm.array(vecT(1, 2, 3, 4)) + glm.array(vecT(1, 2, 3, 4)))[0]
        assert vecT(2) + vecT(3) == vecT(3) + vecT(2)                                  == (glm.array(vecT(2)) + glm.array(vecT(3)))[0] == (glm.array(vecT(3)) + glm.array(vecT(2)))[0] 
        assert vecT(1) + 2 == vecT(1 + 2)                                              == (glm.array(vecT(1)) + 2)[0] == (2 + glm.array(vecT(1)))[0]
        assert vecT(0) + vecT(0) == vecT(0)                                            == (glm.array(vecT(0)) + glm.array(vecT(0)))[0]

    for c in range(2, 5):
        for r in range(2, 5):
            for matT in matrix_length_dict[(c, r)]:
                assert matT(*range(c*r)) + matT(*range(c*r)) == matT(*map(lambda x: x + x, range(c*r)))   == (glm.array(matT(*range(c*r))) + glm.array(matT(*range(c*r))))[0]
                assert matT(2) + matT(3) == matT(3) + matT(2)                                             == (glm.array(matT(2)) + glm.array(matT(3)))[0] == (glm.array(matT(3)) + glm.array(matT(2)))[0]
                assert matT(1) + 2 == matT(*[(1 + 2) if C==R else 2 for C in range(c) for R in range(r)]) == (glm.array(matT(1)) + 2)[0] == (2 + glm.array(matT(1)))[0]
                assert matT(0) + matT(0) == matT(0)                                                       == (glm.array(matT(0)) + glm.array(matT(0)))[0]

    for quaT in quat_types:
        assert quaT(1, 2, 3, 4) + quaT(1, 2, 3, 4) == quaT(1 + 1, 2 + 2, 3 + 3, 4 + 4) == (glm.array(quaT(1, 2, 3, 4)) + glm.array(quaT(1, 2, 3, 4)))[0]
        assert quaT() + quaT() == quaT(1 + 1, 0, 0, 0)                                 == (glm.array(quaT()) + glm.array(quaT()))[0]

    for cT in ctypes_types:
        assert glm.array(cT, 1, 2, 3) + glm.array(cT, 1, 2, 3) == glm.array(cT, 1 + 1, 2 + 2, 3 + 3)
        assert glm.array(cT, 1, 2, 3) + 2 == glm.array(cT, 1 + 2, 2 + 2, 3 + 2) == 2 + glm.array(cT, 1, 2, 3)

def test_spec_sub():
    for vecT in vector_length_dict[1]:
        if (vecT == glm.bvec1):
            continue

        assert vecT(1) - vecT(1) == vecT(1 - 1)          == (glm.array(vecT(1)) - glm.array(vecT(1)))[0] == (glm.array(vecT(1)) - vecT(1))[0] == (vecT(1) - glm.array(vecT(1)))[0]
        assert vecT(2) - vecT(3) != vecT(3) - vecT(2)    and (glm.array(vecT(2)) - glm.array(vecT(3)))[0] != (glm.array(vecT(3)) - glm.array(vecT(2)))[0]
        assert vecT(1) - 2 == vecT(1 - 2) == 1 - vecT(2) == (glm.array(vecT(1)) - 2)[0] == (1 - glm.array(vecT(2)))[0]
        assert vecT(0) - vecT(0) == vecT(0)              == (glm.array(vecT(0)) - glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[2]:
        if (vecT == glm.bvec2):
            continue

        assert vecT(1, 2) - vecT(1, 2) == vecT(1 - 1, 2 - 2) == (glm.array(vecT(1, 2)) - glm.array(vecT(1, 2)))[0]
        assert vecT(2) - vecT(3) != vecT(3) - vecT(2)        and (glm.array(vecT(2)) - glm.array(vecT(3)))[0] != (glm.array(vecT(3)) - glm.array(vecT(2)))[0]
        assert vecT(1) - 2 == vecT(1 - 2)                    == (glm.array(vecT(1)) - 2)[0] == (1 - glm.array(vecT(2)))[0]
        assert vecT(0) - vecT(0) == vecT(0)                  == (glm.array(vecT(0)) - glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[3]:
        if (vecT == glm.bvec3):
            continue

        assert vecT(1, 2, 3) - vecT(1, 2, 3) == vecT(1 - 1, 2 - 2, 3 - 3) == (glm.array(vecT(1, 2, 3)) - glm.array(vecT(1, 2, 3)))[0]
        assert vecT(2) - vecT(3) != vecT(3) - vecT(2)                     and (glm.array(vecT(2)) - glm.array(vecT(3)))[0] != (glm.array(vecT(3)) - glm.array(vecT(2)))[0] 
        assert vecT(1) - 2 == vecT(1 - 2)                                 == (glm.array(vecT(1)) - 2)[0] == (1 - glm.array(vecT(2)))[0]
        assert vecT(0) - vecT(0) == vecT(0)                               == (glm.array(vecT(0)) - glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[4]:
        if (vecT == glm.bvec4):
            continue

        assert vecT(1, 2, 3, 4) - vecT(1, 2, 3, 4) == vecT(1 - 1, 2 - 2, 3 - 3, 4 - 4) == (glm.array(vecT(1, 2, 3, 4)) - glm.array(vecT(1, 2, 3, 4)))[0]
        assert vecT(2) - vecT(3) != vecT(3) - vecT(2)                                  and (glm.array(vecT(2)) - glm.array(vecT(3)))[0] != (glm.array(vecT(3)) - glm.array(vecT(2)))[0] 
        assert vecT(1) - 2 == vecT(1 - 2)                                              == (glm.array(vecT(1)) - 2)[0] == (1 - glm.array(vecT(2)))[0]
        assert vecT(0) - vecT(0) == vecT(0)                                            == (glm.array(vecT(0)) - glm.array(vecT(0)))[0]

    for c in range(2, 5):
        for r in range(2, 5):
            for matT in matrix_length_dict[(c, r)]:
                assert matT(*range(c*r)) - matT(*range(c*r)) == matT(*map(lambda x: x - x, range(c*r)))   == (glm.array(matT(*range(c*r))) - glm.array(matT(*range(c*r))))[0]
                assert matT(2) - matT(3) != matT(3) - matT(2)                                             and (glm.array(matT(2)) - glm.array(matT(3)))[0] != (glm.array(matT(3)) - glm.array(matT(2)))[0]
                assert matT(1) - 2 == matT(*[(1 - 2) if C==R else -2 for C in range(c) for R in range(r)]) == (glm.array(matT(1)) - 2)[0]
                if (c==r):
                    assert 2 - matT(1) == (2 - glm.array(matT(1)))[0]
                assert matT(0) - matT(0) == matT(0)                                                       == (glm.array(matT(0)) - glm.array(matT(0)))[0]

    for quaT in quat_types:
        assert quaT(1, 2, 3, 4) - quaT(1, 2, 3, 4) == quaT(1 - 1, 2 - 2, 3 - 3, 4 - 4) == (glm.array(quaT(1, 2, 3, 4)) - glm.array(quaT(1, 2, 3, 4)))[0]
        assert quaT() - quaT() == quaT(1 - 1, 0, 0, 0)                                 == (glm.array(quaT()) - glm.array(quaT()))[0]

    for cT in ctypes_types:
        if (cT == glm.c_bool):
            continue
        assert glm.array(cT, 1, 2, 3) - glm.array(cT, 1, 2, 3) == glm.array(cT, 1 - 1, 2 - 2, 3 - 3)
        assert glm.array(cT, 1, 2, 3) - 2 == glm.array(cT, 1 - 2, 2 - 2, 3 - 2)
        assert 2 - glm.array(cT, 1, 2, 3) == glm.array(cT, 2 - 1, 2 - 2, 2 - 3)

def test_spec_mul():
    for vecT in vector_length_dict[1]:
        if (vecT == glm.bvec1):
            continue

        assert vecT(1) * vecT(1) == vecT(1 * 1)          == (glm.array(vecT(1)) * glm.array(vecT(1)))[0] == (glm.array(vecT(1)) * vecT(1))[0] == (vecT(1) * glm.array(vecT(1)))[0]
        assert vecT(2) * vecT(3) == vecT(3) * vecT(2)    == (glm.array(vecT(2)) * glm.array(vecT(3)))[0] == (glm.array(vecT(3)) * glm.array(vecT(2)))[0] 
        assert vecT(1) * 2 == vecT(1 * 2) == 2 * vecT(1) == (glm.array(vecT(1)) * 2)[0] == (2 * glm.array(vecT(1)))[0]
        assert vecT(0) * vecT(0) == vecT(0)              == (glm.array(vecT(0)) * glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[2]:
        if (vecT == glm.bvec2):
            continue

        assert vecT(1, 2) * vecT(1, 2) == vecT(1 * 1, 2 * 2) == (glm.array(vecT(1, 2)) * glm.array(vecT(1, 2)))[0]
        assert vecT(2) * vecT(3) == vecT(3) * vecT(2)        == (glm.array(vecT(2)) * glm.array(vecT(3)))[0] == (glm.array(vecT(3)) * glm.array(vecT(2)))[0] 
        assert vecT(1) * 2 == vecT(1 * 2)                    == (glm.array(vecT(1)) * 2)[0] == (2 * glm.array(vecT(1)))[0]
        assert vecT(0) * vecT(0) == vecT(0)                  == (glm.array(vecT(0)) * glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[3]:
        if (vecT == glm.bvec3):
            continue

        assert vecT(1, 2, 3) * vecT(1, 2, 3) == vecT(1 * 1, 2 * 2, 3 * 3) == (glm.array(vecT(1, 2, 3)) * glm.array(vecT(1, 2, 3)))[0]
        assert vecT(2) * vecT(3) == vecT(3) * vecT(2)                     == (glm.array(vecT(2)) * glm.array(vecT(3)))[0] == (glm.array(vecT(3)) * glm.array(vecT(2)))[0] 
        assert vecT(1) * 2 == vecT(1 * 2)                                 == (glm.array(vecT(1)) * 2)[0] == (2 * glm.array(vecT(1)))[0]
        assert vecT(0) * vecT(0) == vecT(0)                               == (glm.array(vecT(0)) * glm.array(vecT(0)))[0]

    for vecT in vector_length_dict[4]:
        if (vecT == glm.bvec4):
            continue

        assert vecT(1, 2, 3, 4) * vecT(1, 2, 3, 4) == vecT(1 * 1, 2 * 2, 3 * 3, 4 * 4) == (glm.array(vecT(1, 2, 3, 4)) * glm.array(vecT(1, 2, 3, 4)))[0]
        assert vecT(2) * vecT(3) == vecT(3) * vecT(2)                                  == (glm.array(vecT(2)) * glm.array(vecT(3)))[0] == (glm.array(vecT(3)) * glm.array(vecT(2)))[0] 
        assert vecT(1) * 2 == vecT(1 * 2)                                              == (glm.array(vecT(1)) * 2)[0] == (2 * glm.array(vecT(1)))[0]
        assert vecT(0) * vecT(0) == vecT(0)                                            == (glm.array(vecT(0)) * glm.array(vecT(0)))[0]

    for c in range(2, 5):
        for r in range(2, 5):
            for matT in matrix_length_dict[(c, r)]:
                assert matT(*range(c*r)) * glm.transpose(matT(*range(c*r)))                               == (glm.array(matT(*range(c*r))) * glm.array(glm.transpose(matT(*range(c*r)))))[0]
                assert matT(*range(c*r)) * glm.transpose(matT(*range(c*r))) != glm.transpose(matT(*range(c*r))) * matT(*range(c*r)) and (glm.array(matT(*range(c*r))) * glm.array(glm.transpose(matT(*range(c*r)))))[0] != (glm.array(glm.transpose(matT(*range(c*r)))) * glm.array(matT(*range(c*r))))[0]
                assert matT(1) * 2 == matT(*[(1 * 2) if C==R else 0 for C in range(c) for R in range(r)]) == (glm.array(matT(1)) * 2)[0] == (2 * glm.array(matT(1)))[0]

    for quaT in quat_types:
        assert quaT(1, 2, 3, 4) * quaT(1, 2, 3, 4) == (glm.array(quaT(1, 2, 3, 4)) * glm.array(quaT(1, 2, 3, 4)))[0]
        assert quaT() * quaT() == quaT(1 * 1, 0, 0, 0)                                 == (glm.array(quaT()) * glm.array(quaT()))[0]

    for cT in ctypes_types:
        assert glm.array(cT, 1, 2, 3) * glm.array(cT, 1, 2, 3) == glm.array(cT, 1 * 1, 2 * 2, 3 * 3)
        assert glm.array(cT, 1, 2, 3) * 2 == glm.array(cT, 1 * 2, 2 * 2, 3 * 2) == 2 * glm.array(cT, 1, 2, 3)

def test_spec_div():
    for vecT in vector_length_dict[1]:
        if (vecT == glm.bvec1):
            continue

        assert vecT(1) / vecT(1) == vecT(1 / 1)          == (glm.array(vecT(1)) / glm.array(vecT(1)))[0] == (glm.array(vecT(1)) / vecT(1))[0] == (vecT(1) / glm.array(vecT(1)))[0]
        assert vecT(2) / vecT(3) != vecT(3) / vecT(2)    and (glm.array(vecT(2)) / glm.array(vecT(3)))[0] != (glm.array(vecT(3)) / glm.array(vecT(2)))[0]
        assert vecT(1) / 2 == vecT(1 / 2) == 1 / vecT(2) == (glm.array(vecT(1)) / 2)[0] == (1 / glm.array(vecT(2)))[0]
        assert vecT(0) / vecT(1) == vecT(0)              == (glm.array(vecT(0)) / glm.array(vecT(1)))[0]

    for vecT in vector_length_dict[2]:
        if (vecT == glm.bvec2):
            continue

        assert vecT(1, 2) / vecT(1, 2) == vecT(1 / 1, 2 / 2) == (glm.array(vecT(1, 2)) / glm.array(vecT(1, 2)))[0]
        assert vecT(2) / vecT(3) != vecT(3) / vecT(2)        and (glm.array(vecT(2)) / glm.array(vecT(3)))[0] != (glm.array(vecT(3)) / glm.array(vecT(2)))[0]
        assert vecT(1) / 2 == vecT(1 / 2)                    == (glm.array(vecT(1)) / 2)[0] == (1 / glm.array(vecT(2)))[0]
        assert vecT(0) / vecT(1) == vecT(0)                  == (glm.array(vecT(0)) / glm.array(vecT(1)))[0]

    for vecT in vector_length_dict[3]:
        if (vecT == glm.bvec3):
            continue

        assert vecT(1, 2, 3) / vecT(1, 2, 3) == vecT(1 / 1, 2 / 2, 3 / 3) == (glm.array(vecT(1, 2, 3)) / glm.array(vecT(1, 2, 3)))[0]
        assert vecT(2) / vecT(3) != vecT(3) / vecT(2)                     and (glm.array(vecT(2)) / glm.array(vecT(3)))[0] != (glm.array(vecT(3)) / glm.array(vecT(2)))[0] 
        assert vecT(1) / 2 == vecT(1 / 2)                                 == (glm.array(vecT(1)) / 2)[0] == (1 / glm.array(vecT(2)))[0]
        assert vecT(0) / vecT(1) == vecT(0)                               == (glm.array(vecT(0)) / glm.array(vecT(1)))[0]

    for vecT in vector_length_dict[4]:
        if (vecT == glm.bvec4):
            continue

        assert vecT(1, 2, 3, 4) / vecT(1, 2, 3, 4) == vecT(1 / 1, 2 / 2, 3 / 3, 4 / 4) == (glm.array(vecT(1, 2, 3, 4)) / glm.array(vecT(1, 2, 3, 4)))[0]
        assert vecT(2) / vecT(3) != vecT(3) / vecT(2)                                  and (glm.array(vecT(2)) / glm.array(vecT(3)))[0] != (glm.array(vecT(3)) / glm.array(vecT(2)))[0] 
        assert vecT(1) / 2 == vecT(1 / 2)                                              == (glm.array(vecT(1)) / 2)[0] == (1 / glm.array(vecT(2)))[0]
        assert vecT(0) / vecT(1) == vecT(0)                                            == (glm.array(vecT(0)) / glm.array(vecT(1)))[0]

    for c in range(2, 5):
        for r in range(2, 5):
            for matT in matrix_length_dict[(c, r)]:
                assert matT(*range(c*r)) / 2 == matT(*map(lambda x: x / 2, range(c*r)))

    for cT in ctypes_types:
        if (cT == glm.c_bool):
            continue
        assert glm.array(cT, 1, 2, 3) / glm.array(cT, 1, 2, 3) == glm.array(cT, 1 / 1, 2 / 2, 3 / 3)
        assert glm.array(cT, 1, 2, 3) / 2 == glm.array(cT, 1 / 2, 2 / 2, 3 / 2)
        assert 2 / glm.array(cT, 1, 2, 3) == glm.array(cT, 2 / 1, 2 / 2, 2 / 3)

def test_spec_mod():
    for vecT in vector_length_dict[1]:
        if (vecT == glm.bvec1):
            continue

        assert vecT(1) % vecT(1) == vecT(1 % 1)          == (glm.array(vecT(1)) % glm.array(vecT(1)))[0] == (glm.array(vecT(1)) % vecT(1))[0] == (vecT(1) % glm.array(vecT(1)))[0]
        assert vecT(2) % vecT(3) != vecT(3) % vecT(2)    and (glm.array(vecT(2)) % glm.array(vecT(3)))[0] != (glm.array(vecT(3)) % glm.array(vecT(2)))[0]
        assert vecT(1) % 2 == vecT(1 % 2) == 1 % vecT(2) == (glm.array(vecT(1)) % 2)[0] == (1 % glm.array(vecT(2)))[0]
        assert vecT(0) % vecT(1) == vecT(0)              == (glm.array(vecT(0)) % glm.array(vecT(1)))[0]

    for vecT in vector_length_dict[2]:
        if (vecT == glm.bvec2):
            continue

        assert vecT(1, 2) % vecT(1, 2) == vecT(1 % 1, 2 % 2) == (glm.array(vecT(1, 2)) % glm.array(vecT(1, 2)))[0]
        assert vecT(2) % vecT(3) != vecT(3) % vecT(2)        and (glm.array(vecT(2)) % glm.array(vecT(3)))[0] != (glm.array(vecT(3)) % glm.array(vecT(2)))[0]
        assert vecT(1) % 2 == vecT(1 % 2)                    == (glm.array(vecT(1)) % 2)[0] == (1 % glm.array(vecT(2)))[0]
        assert vecT(0) % vecT(1) == vecT(0)                  == (glm.array(vecT(0)) % glm.array(vecT(1)))[0]

    for vecT in vector_length_dict[3]:
        if (vecT == glm.bvec3):
            continue

        assert vecT(1, 2, 3) % vecT(1, 2, 3) == vecT(1 % 1, 2 % 2, 3 % 3) == (glm.array(vecT(1, 2, 3)) % glm.array(vecT(1, 2, 3)))[0]
        assert vecT(2) % vecT(3) != vecT(3) % vecT(2)                     and (glm.array(vecT(2)) % glm.array(vecT(3)))[0] != (glm.array(vecT(3)) % glm.array(vecT(2)))[0] 
        assert vecT(1) % 2 == vecT(1 % 2)                                 == (glm.array(vecT(1)) % 2)[0] == (1 % glm.array(vecT(2)))[0]
        assert vecT(0) % vecT(1) == vecT(0)                               == (glm.array(vecT(0)) % glm.array(vecT(1)))[0]

    for vecT in vector_length_dict[4]:
        if (vecT == glm.bvec4):
            continue

        assert vecT(1, 2, 3, 4) % vecT(1, 2, 3, 4) == vecT(1 % 1, 2 % 2, 3 % 3, 4 % 4) == (glm.array(vecT(1, 2, 3, 4)) % glm.array(vecT(1, 2, 3, 4)))[0]
        assert vecT(2) % vecT(3) != vecT(3) % vecT(2)                                  and (glm.array(vecT(2)) % glm.array(vecT(3)))[0] != (glm.array(vecT(3)) % glm.array(vecT(2)))[0] 
        assert vecT(1) % 2 == vecT(1 % 2)                                              == (glm.array(vecT(1)) % 2)[0] == (1 % glm.array(vecT(2)))[0]
        assert vecT(0) % vecT(1) == vecT(0)                                            == (glm.array(vecT(0)) % glm.array(vecT(1)))[0]

    for cT in ctypes_types:
        if (cT == glm.c_bool):
            continue
        assert glm.array(cT, 1, 2, 3) % glm.array(cT, 1, 2, 3) == glm.array(cT, 1 % 1, 2 % 2, 3 % 3)
        assert glm.array(cT, 1, 2, 3) % 2 == glm.array(cT, 1 % 2, 2 % 2, 3 % 2)
        assert 2 % glm.array(cT, 1, 2, 3) == glm.array(cT, 2 % 1, 2 % 2, 2 % 3)

def test_spec_pow():
    for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
        assert vecT(2) ** vecT(3) == vecT(2 ** 3) == (glm.array(vecT(2)) ** glm.array(vecT(3)))[0] == (glm.array(vecT(2)) ** 3)[0] == (glm.array(vecT(2)) ** vecT(3))[0] == (vecT(2) ** glm.array(vecT(3)))[0] == (2 ** glm.array(vecT(3)))[0]

    for cT in [glm.c_float, glm.c_double]:
        assert glm.array(cT, 1, 2, 3) ** glm.array(cT, 1, 2, 3) == glm.array(cT, 1 ** 1, 2 ** 2, 3 ** 3)
        assert glm.array(cT, 1, 2, 3) ** 2 == glm.array(cT, 1 ** 2, 2 ** 2, 3 ** 2)
        assert 2 ** glm.array(cT, 1, 2, 3) == glm.array(cT, 2 ** 1, 2 ** 2, 2 ** 3)

def test_spec_neg():
    for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")] + vector_type_dict[datatypes.index("int")] + vector_type_dict[datatypes.index("glm::i64")] + vector_type_dict[datatypes.index("glm::i16")] + vector_type_dict[datatypes.index("glm::i8")]:
        assert -vecT(5) == vecT(0) - vecT(5) == (-glm.array(vecT(5)))[0]

    for matT in matrix_type_dict[datatypes.index("float")] + matrix_type_dict[datatypes.index("double")] + matrix_type_dict[datatypes.index("int")]:
        assert -matT(5) == matT(0) - matT(5) == (-glm.array(matT(5)))[0]

    for quaT in quat_types:
        assert -quaT(1, 2, 3, 4) == quaT(0, 0, 0, 0) - quaT(1, 2, 3, 4) == (-glm.array(quaT(1, 2, 3, 4)))[0]

    for cT in [glm.c_float, glm.c_double, glm.c_int64, glm.c_int32, glm.c_int16, glm.c_int8]:
        assert -glm.array(cT, 1, 2, 3) == glm.array.zeros(3, cT) - glm.array(cT, 1, 2, 3)

def test_spec_abs():
    for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")] + vector_type_dict[datatypes.index("int")] + vector_type_dict[datatypes.index("glm::i64")] + vector_type_dict[datatypes.index("glm::i16")] + vector_type_dict[datatypes.index("glm::i8")]:
        assert abs(vecT(-5)) == vecT(5) == (abs(glm.array(vecT(-5))))[0]

    for matT in matrix_type_dict[datatypes.index("float")] + matrix_type_dict[datatypes.index("double")] + matrix_type_dict[datatypes.index("int")]:
        assert matT(5) == (abs(glm.array(matT(-5))))[0]

    for quaT in quat_types:
        assert quaT(1, 2, 3, 4) == (abs(glm.array(quaT(1, -2, 3, -4))))[0]

    for cT in [glm.c_float, glm.c_double, glm.c_int64, glm.c_int32, glm.c_int16, glm.c_int8]:
        assert abs(glm.array(cT, 1, -2, -3)) == glm.array(cT, 1, 2, 3)

def test_spec_array_methods():
    assert glm.array(glm.vec3(1, 2, 3)).concat(glm.array(glm.vec3(1, 2, 3))) == glm.array(glm.vec3(1, 2, 3)).repeat(2) == glm.array(glm.vec3(1, 2, 3)).map(lambda x: (x,x)) == glm.array(glm.vec3(1, 2, 3), glm.vec3(1, 2, 3))

    assert glm.array(glm.vec3(1, 2, 3)).map(lambda x: x * 2) == glm.array(glm.vec3(1, 2, 3)) * 2
    assert glm.array(glm.vec3(1, 2, 3)).filter(lambda x: True) == glm.array(glm.vec3(1, 2, 3)).map(lambda x: x) == glm.array(glm.vec3(1, 2, 3))
    assert glm.array(glm.vec3(1, 2, 3)).map(lambda x: None) == glm.array(glm.vec3(1, 2, 3)).filter(lambda x: False) == glm.array(glm.vec3(1, 2, 3)).repeat(0)

    arr = glm.array(glm.c_float, 5, 3, 4, 2, 1)
    arr.sort(glm.cmp)

    assert arr == glm.array(glm.c_float, 1, 2, 3, 4, 5)

    assert glm.array(glm.vec3(1, 2, 3)).split_components() == (glm.array(glm.float32, 1), glm.array(glm.float32, 2), glm.array(glm.float32, 3))
    assert glm.array(glm.vec4(1, 2, 3, 4), glm.vec4(6, 7, 8, 9)).split_components() == (glm.array(glm.float32, 1, 6), glm.array(glm.float32, 2, 7), glm.array(glm.float32, 3, 8), glm.array(glm.float32, 4, 9))
    assert glm.array(glm.mat2(1, 2, 3, 4)).split_components() == (glm.array(glm.vec2(1, 2)), glm.array(glm.vec2(3, 4)))

    assert glm.array(glm.vec4(1, 2, 3, 4), glm.vec4(6, 7, 8, 9)).reduce(glm.add) == glm.vec4(7, 9, 11, 13)
    assert glm.array(glm.c_float, 5, 3, 4, 2, 1).reduce(glm.add) == 15
    assert glm.array(glm.c_float, 5, 3, 4, 2, 1).reduce(glm.add, 20) == 35

def test_spec_common_abs():
    for i in range(-10, 10):
        assert glm.abs(i) == abs(i)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([x == abs(i) for x in glm.abs(vecT(i))])

def test_spec_common_ceil():
    for i in range(-10, 10):
        x = i / 10

        assert glm.ceil(x) == math.ceil(x)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([a == math.ceil(x) for a in glm.ceil(vecT(x))])

def test_spec_common_clamp():
    assert glm.clamp(0, 1, 2) == 1 
    assert glm.clamp(1, 1, 2) == 1
    assert glm.clamp(2, 1, 2) == 2
    assert glm.clamp(3, 1, 2) == 2

    for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
        assert glm.clamp(vecT(0), 1, 2) == vecT(1) 
        assert glm.clamp(vecT(1), 1, 2) == vecT(1)
        assert glm.clamp(vecT(2), 1, 2) == vecT(2)
        assert glm.clamp(vecT(3), 1, 2) == vecT(2)

        assert glm.clamp(vecT(0), vecT(1), vecT(2)) == vecT(1) 
        assert glm.clamp(vecT(1), vecT(1), vecT(2)) == vecT(1)
        assert glm.clamp(vecT(2), vecT(1), vecT(2)) == vecT(2)
        assert glm.clamp(vecT(3), vecT(1), vecT(2)) == vecT(2)

def test_spec_common_floor():
    for i in range(-10, 10):
        x = i / 10

        assert glm.floor(x) == math.floor(x)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([a == math.floor(x) for a in glm.floor(vecT(x))])

def test_spec_common_fma():
    assert glm.fma(1, 2, 3) == 1 * 2 + 3
    assert glm.fma(4, 5, 6) == 4 * 5 + 6

def test_spec_common_fmax():
    for a in range(-2, 2):
        for b in range(-2, 2):
            assert glm.fmax(a, b) == max([a, b])

            for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                assert glm.fmax(vecT(a), b) == vecT(max([a,b])) == glm.fmax(vecT(a), vecT(b))

    for a in range(-2, 2):
        for b in range(-2, 2):
            for c in range(-2, 2):
                for d in range(-2, 2):
                    assert glm.fmax(a, b, c, d) == max([a,b,c,d])
                assert glm.fmax(a, b, c) == max([a,b,c])

def test_spec_common_fmin():
    for a in range(-2, 2):
        for b in range(-2, 2):
            assert glm.fmin(a, b) == min([a, b])

            for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                assert glm.fmin(vecT(a), b) == vecT(min([a,b])) == glm.fmin(vecT(a), vecT(b))

    for a in range(-2, 2):
        for b in range(-2, 2):
            for c in range(-2, 2):
                for d in range(-2, 2):
                    assert glm.fmin(a, b, c, d) == min([a,b,c,d])
                assert glm.fmin(a, b, c) == min([a,b,c])

def test_spec_common_fract():
    for i in range(-10, 10):
        x = i / 10

        assert glm.fract(x) == x - glm.floor(x)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert glm.fract(vecT(x)) == vecT(x) - glm.floor(vecT(x))

def test_spec_common_max():
    for a in range(-2, 2):
        for b in range(-2, 2):
            assert glm.max(a, b) == max([a, b])

            for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                assert glm.max(vecT(a), b) == vecT(max([a,b])) == glm.max(vecT(a), vecT(b))

    for a in range(-2, 2):
        for b in range(-2, 2):
            for c in range(-2, 2):
                for d in range(-2, 2):
                    assert glm.max(a, b, c, d) == max([a,b,c,d])

                    for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                        assert glm.max(vecT(a), vecT(b), vecT(c), vecT(d)) == vecT(max([a, b, c, d]))

                assert glm.max(a, b, c) == max([a,b,c])

                for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                    assert glm.max(vecT(a), vecT(b), vecT(c)) == vecT(max([a, b, c]))

def test_spec_common_min():
    for a in range(-2, 2):
        for b in range(-2, 2):
            assert glm.min(a, b) == min([a, b])

            for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                assert glm.min(vecT(a), b) == vecT(min([a,b])) == glm.min(vecT(a), vecT(b))

    for a in range(-2, 2):
        for b in range(-2, 2):
            for c in range(-2, 2):
                for d in range(-2, 2):
                    assert glm.min(a, b, c, d) == min([a,b,c,d])

                    for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                        assert glm.min(vecT(a), vecT(b), vecT(c), vecT(d)) == vecT(min([a, b, c, d]))

                assert glm.min(a, b, c) == min([a,b,c])

                for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                    assert glm.min(vecT(a), vecT(b), vecT(c)) == vecT(min([a, b, c]))

def test_spec_common_mix():
    for a in range(-2, 2):
        for b in range(-2, 2):
            assert glm.mix(a, b, 0.) == a
            assert glm.mix(a, b, 1.) == b
            assert glm.mix(a, b, 0.5) == (a + b) / 2

            assert glm.mix(a, b, True) == b
            assert glm.mix(a, b, False) == a

            for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
                assert glm.mix(vecT(a), vecT(b), [0.] * len(vecT(a))) == vecT(a)
                assert glm.mix(vecT(a), vecT(b), [1.] * len(vecT(a))) == vecT(b)
                assert glm.mix(vecT(a), vecT(b), [0.5] * len(vecT(a))) == vecT((a + b) / 2)

                assert glm.mix(vecT(a), vecT(b), [True] * len(vecT(a))) == vecT(b)
                assert glm.mix(vecT(a), vecT(b), [False] * len(vecT(a))) == vecT(a)

def test_spec_common_round():
    for i in range(-10, 10):
        x = i / 10

        if abs(x) == 0.5:
            x += .05

        assert glm.round(x) == round(x, 0), x

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([a == round(x, 0) for a in glm.round(vecT(x))])

def test_spec_common_frexp():
    for i in range(-10, 10):
        x = i / 10

        assert glm.frexp(x) == math.frexp(x)

        #for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
        #    assert all([(a, b) == math.frexp(x) for a, b in glm.frexp(vecT(x))])

def test_spec_exponential_exp():
    for i in range(5):
        assert round(glm.exp(i), 5) == round(math.exp(i), 5)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([round(a, 5) == round(math.exp(i), 5) for a in glm.exp(vecT(i))])

def test_spec_exponential_exp2():
    for i in range(5):
        assert round(glm.exp2(i), 5) == round(2 ** i, 5)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([round(a, 5) == round(2 ** i, 5) for a in glm.exp2(vecT(i))])

def test_spec_exponential_sqrt():
    for i in range(1,6):
        assert round(glm.sqrt(i), 5) == round(math.sqrt(i), 5)
        assert round(glm.inversesqrt(i), 5) == round(1 / math.sqrt(i), 5)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([round(a, 5) == round(math.sqrt(i), 5) for a in glm.sqrt(vecT(i))])
            assert all([round(a, 5) == round(1 / math.sqrt(i), 5) for a in glm.inversesqrt(vecT(i))])

def test_spec_exponential_log():
    for i in range(1,6):
        assert round(glm.log(i), 5) == round(math.log(i), 5)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([round(a, 5) == round(math.log(i), 5) for a in glm.log(vecT(i))])

def test_spec_exponential_log2():
    for i in range(1,6):
        assert round(glm.log2(i), 5) == round(math.log2(i), 5)

        for vecT in vector_type_dict[datatypes.index("float")] + vector_type_dict[datatypes.index("double")]:
            assert all([round(a, 5) == round(math.log2(i), 5) for a in glm.log2(vecT(i))])

###/SPECIFIC TESTS ###



### TEST TEST ###
    
def test_everything_tested():
    f = open(__file__, "r")
    content = f.read()
    f.close()

    excluded = ["make_mat.+", "make_vec.+"]

    builtin_function_or_method = type(glm.silence)

    for raw in dir(glm):
        func = getattr(glm, raw)
        if (raw.startswith("__") and raw.endswith("__") or not isinstance(func, builtin_function_or_method)):
            continue
        if not raw in content and not any((re.fullmatch(ex, raw) for ex in excluded)):
            print("{} has no test.".format(raw))