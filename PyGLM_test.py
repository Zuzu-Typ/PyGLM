import glm, sys, random, time

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
        if list_copy[i] == x:
            list_copy[i] = y
    return list_copy

randf = lambda: random.random()*100
randfs = lambda: randf()-50

def get_args(arg_string, type_, rand_func=randfs):
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

        elif arg == "V1":
            args.append(getattr(glm, "{T}vec1".format(T=prefixes[suffixes.index(type_)]))(rand_func()))

        elif arg == "V2":
            args.append(getattr(glm, "{T}vec2".format(T=prefixes[suffixes.index(type_)]))(rand_func(),rand_func()))

        elif arg == "V3":
            args.append(getattr(glm, "{T}vec3".format(T=prefixes[suffixes.index(type_)]))(rand_func(),rand_func(),rand_func()))

        elif arg == "V4":
            args.append(getattr(glm, "{T}vec4".format(T=prefixes[suffixes.index(type_)]))(rand_func(),rand_func(),rand_func(),rand_func()))

        elif arg == "Q":
            args.append(getattr(glm, "{T}quat".format(T=prefixes[suffixes.index(type_)]))(rand_func(), rand_func(), rand_func(), rand_func()))

        elif "M" in arg:
            n = int(arg[1])
            m = int(arg[2])
            args.append(getattr(glm, "{T}mat{n}x{m}".format(T=prefixes[suffixes.index(type_)], n=n, m=m))(*[rand_func() for i in range(n*m)]))

    return args


def gen_args(args_string):
    if "#u" in args_string:
        rand_func = randf
        args_string = args_string.replace("#u", "")
    else:
        rand_func = randfs

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
            if not char in "1234":
                if current_text != "":
                    arg_strings.append(current_text)
                    current_text = ""
            current_text += char
        if current_text:
            arg_strings.append(current_text)
        
        if "N" in arg_strings:
            if "V" in arg_strings:
                for T in types:
                    for L in range(1, 5):
                        yield get_args(list_replace(arg_strings, "V", "V{L}".format(L=L)), T, rand_func)
            else:
                yield get_args(arg_strings, "F" if "F" in types else "f" if "f" in types else "i" if "i" in types else "I" if "I" in types else types[0])
        elif "V" in arg_strings:
            for T in types:
                for L in range(1, 5):
                    yield get_args(list_replace(arg_strings, "V", "V{L}".format(L=L)), T, rand_func)

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
        func(*args)
    except:
        raise FAssertionError("{} raised {} with {}".format(func, sys.exc_info()[1], repr(args)))

# Initialization #
## vec1
for args in gen_args("#u-_N"): # need to add support for _V1_V2_V3_V4
    for T in vector_length_dict[1]:
        fassert(T, args)

## vec2
for args in gen_args("#u-_N_NN_V2_V3_V4"):
    for T in vector_length_dict[2]:
        fassert(T, args)

## vec3
for args in gen_args("#u-_N_NNN_NV2_V2N_V3_V4"):
    for T in vector_length_dict[3]:
        fassert(T, args)

## vec4
for args in gen_args("#u-_N_NNNN_V2NN_NV2N_NNV2_NV3_V3N_V4"):
    for T in vector_length_dict[4]:
        fassert(T, args)

## mat
for C in range(2, 5):
    for R in range(2, 5):
        for args in gen_args("#u-_N_" + "N"*(C*R) + "_" + "V{R}".format(R=R)*C): # need support for _M
            for T in matrix_length_dict[(C,R)]:
                fassert(T, args)

## quat
for args in gen_args("#u-_V3_M33_M44_NV3_V3V3_NNNN_Q__f"): # need support for conversion constructors
    fassert(glm.quat, args)

## dquat
for args in gen_args("#u-_V3_M33_M44_NV3_V3V3_NNNN_Q__F"): # need support for conversion constructors
    fassert(glm.dquat, args)

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
#/add #

# sub #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__sub__, (obj,))
#/sub #

# mul #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__mul__, (1,))
#/mul #

# div #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__truediv__, (1,))
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
#/iadd #

# isub #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__isub__, (obj,))
#/isub #

# imul #
for obj in gen_obj("V_M_Q__fFiqsuIQSU"):
    fassert(obj.__imul__, (1,))
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
#/len #

# getitem #
for obj in gen_obj("V_M_Q"):
    for i in range(len(obj)):
        assert obj[i] != None, obj
#/getitem #

# setitem #
for obj in gen_obj("V_M_Q"):
    for i in range(len(obj)):
        fassert(obj.__setitem__,(i, obj[i]))
#/setitem #

# contains #
for obj in gen_obj("V_M_Q"):
    assert obj[0] in obj, obj
#/contains #

# Richcompare #
## EQ
for obj in gen_obj("V_M_Q"):
    assert obj == type(obj)(obj), obj

## NE
for obj in gen_obj("#uV_M__fFiqsuIQSU"):
    assert obj != (obj + 1), obj

for obj in gen_obj("V_M__B"):
    assert obj != (not obj), obj

for obj in gen_obj("Q"):
    assert obj != (1,0,0,0)

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
#/iter #

print("Finished tests in {:.3g}s".format(time.time()-start_time))