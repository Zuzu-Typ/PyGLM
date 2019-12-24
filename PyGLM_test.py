import glm, sys, random, time, copy

glm.silence(0)

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

# buffer protocol #
for type_ in vector_types + matrix_types + quat_types:
    fassert(type_, (fassert(bytes, (type_(),)),))
#/buffer protocol #

# copy module #
for args in gen_args("V_M_Q"):
    fassert(copy.copy, args)
    fassert(copy.deepcopy, args)
#/copy module #

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

for args in gen_args("NN_VV_VN_NNN_VVV_NNNN_VVVV__fF"):
    fassert(glm.min, args)
    fassert(glm.max, args)
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
##/UNSTABLE EXTENSIONS ##

print("Finished tests in {:.3g}s".format(time.time()-start_time))
