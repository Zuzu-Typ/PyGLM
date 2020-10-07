import glm
import re, os, SlashBack, sys, traceback

builtin_function_or_method = type(glm.silence)

functions = []

func_common = ["abs", "sign", "floor", "trunc", "round", "roundEven",
               "ceil", "fract", "mod", "min", "max", "fmin",
               "fmax", "clamp", "mix", "step", "smoothstep", "isnan",
               "isinf", "fma", "frexp", "ldexp", "floatBitsToInt",
               "floatBitsToUint", "intBitsToFloat", "uintBitsToFloat",
               "modf"]

func_exponential = ["pow", "exp", "log", "exp2", "log2", "sqrt", "inversesqrt"]

func_geometric = ["length", "distance", "dot", "cross", "normalize", "faceforward", "reflect", "refract"]

func_integer = ["uaddCarry", "usubBorrow", "umulExtended", "imulExtended",
                "bitfieldExtract", "bitfieldInsert", "bitfieldReverse",
                "bitCount", "findLSB", "findMSB"]

func_matrix = ["matrixCompMult", "outerProduct", "transpose", "determinant", "inverse"]

func_packing = ["packDouble2x32", "packUnorm2x16", "packSnorm2x16", "packSnorm4x8",
                "packUnorm4x8", "packHalf2x16", "unpackDouble2x32", "unpackUnorm2x16",
                "unpackSnorm2x16", "unpackSnorm4x8", "unpackUnorm4x8", "unpackHalf2x16"]

func_trigonometric = ["radians", "degrees", "sin", "cos", "tan", "asin", "acos", "atan",
                      "sinh", "cosh", "tanh", "asinh", "acosh", "atanh"]

func_vector_relational = ["equal", "notEqual", "lessThan", "lessThanEqual", "greaterThan",
                          "greaterThanEqual", "any", "all", "not_"]

detail = func_common + func_exponential + func_geometric + func_integer + func_matrix + \
         func_packing + func_trigonometric + func_vector_relational

color_space = ["convertLinearToSRGB", "convertSRGBToLinear"]

constants = ["epsilon", "zero", "one", "pi", "two_pi", "root_pi",
             "half_pi", "three_over_two_pi", "quarter_pi", "one_over_pi",
             "one_over_two_pi", "two_over_pi", "four_over_pi",
             "two_over_root_pi", "one_over_root_two", "root_half_pi",
             "root_two_pi", "root_ln_four", "e", "euler", "root_two",
             "root_three", "root_five", "ln_two", "ln_ln_two", "ln_ten", "third",
             "two_thirds", "golden_ratio"]

epsilon = ["epsilonEqual", "epsilonNotEqual"]

integer = ["iround", "uround"]

matrix_access = ["row", "column"]

matrix_clip_space = ["tweakedInfinitePerspective"] + \
                    [x + y for y in ["", "LH", "RH", "NO", "ZO", "LH_ZO", "LH_NO", "RH_ZO", "RH_NO"] for x in ["ortho", "frustum", "perspective", "perspectiveFov"]] +\
                    ["infinitePerspective" + y for y in ["", "LH", "RH"]]

matrix_inverse = ["affineInverse", "inverseTranspose"]

matrix_projection = ["project", "projectNO", "projectZO", "unProject", "unProjectNO", "unProjectZO", "pickMatrix"]

matrix_transform = ["identity", "translate", "rotate", "rotate_slow", "scale", "scale_slow", "lookAt",
                    "lookAtRH", "lookAtLH"]

noise = ["perlin", "simplex"]

packing_pack_methods = ["pack" + x + y for x, z in [
    ("Int", ("2x8", "4x8", "4x16", "2x16", "2x32")),
    ("Uint", ("2x8", "4x8", "4x16", "2x16", "2x32")),
    ("Unorm", ("", "1x8", "2x8", "1x16", "4x16", "3x10_1x2", "2x4", "4x4", "1x5_1x6_1x5", "3x5_1x1", "2x3_1x2")),
    ("Snorm", ("", "1x8", "2x8", "1x16", "4x16", "3x10_1x2")),
    ("Half", ("", "1x16", "4x16")),
    ("", ("I3x10_1x2", "U3x10_1x2", "F2x11_1x10", "F3x9_E1x5", "RGBM")),
    ] for y in z]

packing = [y + x for x in packing_pack_methods for y in ["", "un"]]

quaternion = ["quatLookAt", "quatLookAtLH", "quatLookAtRH", "eulerAngles", "roll", "pitch", "yaw", "mat3_cast",
              "mat4_cast", "quat_cast"]

quaternion_common = ["lerp", "slerp", "conjugate"]

quaternion_trigonometric = ["angle", "axis", "angleAxis"]

random = ["linearRand", "gaussRand", "circularRand", "sphericalRand", "diskRand", "ballRand"]

reciprocal = [f.format(x) for f in ("{}", "a{}", "{}h", "a{}h") for x in ("sec", "csc", "cot")]

round = ["ceilPowerOfTwo", "floorPowerOfTwo", "roundPowerOfTwo", "ceilMultiple", "floorMultiple",
         "roundMultiple"]

type_ptr = ["value_ptr", "sizeof", "make_quat"] + [f + str(x) for x in range(2, 5) for f in ("make_vec", "make_mat")] +\
           ["make_mat{}x{}".format(x, y) for x in range(2,5) for y in range(2,5)]

ulp = ["next_float", "prev_float", "float_distance"]

decompose = ["decompose"]

norm = ["distance2", "l1Norm", "l2Norm", "lMaxNorm", "length2", "lxNorm"]

polar_coordinates = ["polar", "euclidean"]

stable_extensions = matrix_clip_space + matrix_projection + matrix_transform + quaternion_common +\
                    quaternion_trigonometric

recommended_extensions = color_space + constants + epsilon + integer + matrix_access + matrix_inverse +\
                         noise + packing + quaternion + random + reciprocal + round + type_ptr + ulp

unstable_extensions = decompose + norm + polar_coordinates

other_functions = ["silence"]

known_functions = detail + recommended_extensions + stable_extensions + unstable_extensions + other_functions


for raw in dir(glm):
    func = getattr(glm, raw)
    if (raw.startswith("__") and raw.endswith("__") or not isinstance(func, builtin_function_or_method)):
        continue
    functions.append(raw)

is_defined = lambda x: x in functions
is_known = lambda x: x in known_functions

for known_func in known_functions:
    if not is_defined(known_func):
        print("A 'known' function was not defined: {}".format(known_func))

    if known_functions.count(known_func) != 1:
        print("Function '{}' is known multiple times".format(known_func))


for function in functions:
    if not is_known(function):
        print("Function {} is not known".format(function))



class FunctionName:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return "glm.<code>**{}**".format(self.name)

class Parameters:
    def __init__(self, param_string):
        self.param_string = param_string

    def __str__(self):
        inner_out = []
        for param in self.param_string.split(","):
            param = param.strip()
            if not param:
                continue
            if ":" in param:
                if param.count(":") != 1:
                    print("Invalid amount of ':': {}".format(self.param_string))
                else:
                    param, type_ = param.split(":")
                    inner_out.append("**{}**: *{}*".format(param, type_.strip()))
            else:
                inner_out.append("**{}**".format(param))
                
        return "({})".format(", ".join(inner_out))

class ReturnValue:
    def __init__(self, return_value):
        self.return_value = return_value

    def __str__(self):
        return " -\\\\> *{}*".format(self.return_value)

class Description:
    def __init__(self, descr):
        self.descr = descr

    def __str__(self):
        return self.descr.replace("\t", "\\raw\\&emsp;&emsp;\\raw\\")

FUNC_PATTERN = re.compile("(^\\w+)\\s*\\(([^)]*)\\)\\s*->\\s*(.+$)")

def convert_doc_entry_to_sb(subdoc):
    lines = subdoc.split("\n")
    first_line = ""
    rest_start = 0
    for line in lines:
        first_line += line
        rest_start += 1
        if "->" in line:
            break
    descr = Description("\n".join(lines[rest_start:]))
    match = FUNC_PATTERN.fullmatch(first_line)
    if match:
        func_name = FunctionName(match.group(1))
        parameters = Parameters(match.group(2))
        return_val = ReturnValue(match.group(3))
        return "\\raw\\#### <code>{}{}{}</code></code>\\raw\\\n{}\n".format(str(func_name), str(parameters), str(return_val), str(descr))
    print("{} doesn't match the FUNC_PATTERN!".format(subdoc))
    return ""

def convert_doc_to_sb(func):
    doc = func.__doc__
    name = func.__name__
    out = "\\h3\\{}() function\\h3\\\n".format(name)
    lines = doc.split("\n")
    current_subdoc = ""
    for line in lines:
        if not line.startswith("\t") and current_subdoc:
            out += convert_doc_entry_to_sb(current_subdoc)
            current_subdoc = ""
        current_subdoc += line + "\n"
    if current_subdoc.strip():
        out += convert_doc_entry_to_sb(current_subdoc)
    return out

def check_doc(func):
    name = func.__name__
    doc = func.__doc__
    for line in doc.split("\n"):
        if line.strip() and not line.startswith("\t") and not line.startswith(name) or len(line) > 100:
            print("{} has invalid doc: \n{}\n".format(name, line))
            return False
    return True

def convert_sb_file(filename):
    out_filename = os.path.splitext(filename)[0] + ".md"
    try:
        sbf = SlashBack.open(filename)
        sbf.write(out_filename)
    except SlashBack.SlashBackParserError as exception:
        print(f"\nERROR: {exception!s}", file=sys.stderr)
    except Exception as exception:
        print("\nUNHANDLED EXCEPTION OCCURED!", file=sys.stderr)
        traceback.print_exc()

def generate_reference_for(name, function_names, description):
    file_name = "../wiki/function reference/{}.sb".format(name)
    file = open(file_name, "w")
    file.write("\\c\\This file was generated using a tool\\c\\\n")
    file.write("\\h1\\{} methods\\h1\\\n".format(name))
    file.write("The following methods are all part of the \\b\\{} methods\\b\\.\n".format(name))
    file.write(description)
    file.write("\n\\h2\\Table of contents\\h2\\\n")
    file.write("\\ul\\\n")

    function_names.sort()
    
    for function_name in function_names:
        file.write("\\-\\\\url #{}-function\\\\b\\{}\\b\\ function\\url\\\n".format(function_name.lower(), function_name))
    file.write("\\ul\\\n")
    
    for function_name in function_names:
        if is_defined(function_name):
            func = getattr(glm, function_name)
            if check_doc(func):
                file.write(convert_doc_to_sb(func))
    file.close()
    convert_sb_file(file_name)

        
generate_reference_for("func_common", func_common, "It contains common GLSL functions.")

generate_reference_for("func_exponential", func_exponential, "It contains exponential GLSL functions.")

generate_reference_for("func_geometric", func_geometric, "These operate on vectors as vectors, not component-wise.")

generate_reference_for("func_integer", func_integer, "It contains GLSL functions on integer types.")

generate_reference_for("func_matrix", func_matrix, "It contains GLSL matrix functions.")

generate_reference_for("func_packing", func_packing, "Provides GLSL functions to pack and unpack half, single"+\
                       " and double-precision floating point values into more compact integer types.")

generate_reference_for("func_trigonometric", func_trigonometric,
                       "Function parameters specified as angle are assumed to be in units of radians.")

generate_reference_for("color_space", color_space, "Allow to perform bit operations on integer values.")

generate_reference_for("constants", constants, "Provide a list of constants and precomputed useful values.")

generate_reference_for("epsilon", epsilon, "Comparison functions for a user defined epsilon values.")

generate_reference_for("integer", integer, "Contains two different rounding methods.")

generate_reference_for("matrix_access", matrix_access,
                       "Defines functions to access rows or columns of a matrix easily.")

generate_reference_for("matrix_clip_space", matrix_clip_space,
                       "Defines functions that generate clip space transformation matrices.")

generate_reference_for("matrix_inverse", matrix_inverse,
                       "Defines additional matrix inverting functions.")

generate_reference_for("matrix_projection", matrix_projection,
                       "Functions that generate common projection transformation matrices.")

generate_reference_for("matrix_transform", matrix_transform,
                       "Defines functions that generate common transformation matrices.")

generate_reference_for("noise", noise,
                       "Defines 2D, 3D and 4D procedural noise functions Based on the work of Stefan Gustavson"+\
                       " and Ashima Arts on \"webgl-noise\": \\raw\\https://github.com/ashima/webgl-noise\\raw\\ Following"+\
                       " Stefan Gustavson's paper \"Simplex noise demystified\": "+\
                       "\\raw\\http://www.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf\\raw\\")

generate_reference_for("packing", packing,
                       "This extension provides a set of function to convert vertors to packed formats.")

generate_reference_for("quaternion", quaternion,
                       "Defines a templated quaternion type and several quaternion operations.")

generate_reference_for("quaternion_common", quaternion_common,
                       "Provides common functions for quaternion types.")

generate_reference_for("quaternion_trigonometric", quaternion_trigonometric,
                       "Provides trigonometric functions for quaternion types.")

generate_reference_for("random", random,
                       "Generate random number from various distribution methods.")

generate_reference_for("reciprocal", reciprocal,
                       "Define secant, cosecant and cotangent functions.")

generate_reference_for("round", round,
                       "Rounding value to specific boundings.")

generate_reference_for("type_ptr", type_ptr,
                       "Handles the interaction between pointers and vector, matrix types. "+\
                       "This extension defines an overloaded function, glm.value_ptr. It "+\
                       "returns a pointer to the memory layout of the object. Matrix types "+\
                       "store their values in column-major order. This is useful for uploading "+\
                       "data to matrices or copying data to buffer objects.")

generate_reference_for("ulp", ulp,
                       "Allow the measurement of the accuracy of a function against a reference implementation. "+\
                       "This extension works on floating-point data and provide results in ULP.")

generate_reference_for("decompose", decompose,
                       "Decomposes a model matrix to translations, rotation and scale components.")

generate_reference_for("norm", norm,
                       "Various ways to compute vector norms.")

generate_reference_for("polar_coordinates", polar_coordinates,
                       "Conversion from Euclidean space to polar space and revert.")


generate_reference_for("other", other_functions,
                       "PyGLM's custom functions.")

























