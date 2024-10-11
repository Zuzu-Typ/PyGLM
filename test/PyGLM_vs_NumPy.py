import timeit, sys, random
import glm, numpy

ON_WINDOWS = sys.platform == 'win32'

print_horizontal_rule = lambda: print("+----------------------------------------+------------+------------+-----------+")

pad_with_spaces = lambda text, length, align="left": text + " " * (length - len(text)) if align == "left" else " " * (length - len(text)) + text

seconds_to_milliseconds = lambda seconds: int(round(seconds * 1000, 0))

pyglm_total_time = 0
numpy_total_time = 0

def word_wrap(text, max_length):
    out = []
    current_word = []
    current_length = 0
    for c in text:
        if current_length >= max_length:
            out.append("\n")
            current_length = len(current_word)

        if c == " ":
            out.append("".join(current_word))
            if (current_length < max_length):
                out.append(" ")
            current_word = []
        elif c == "\n":
            out.append("".join(current_word))
            out.append("\n")
            current_word = []
            current_length = 0
        else:
            current_word.append(c)

        current_length += 1

    if current_word:
        out.append("".join(current_word))

    return "".join(out).rstrip()

def print_row(descr, pyglm, numpy, ratio, print_header=True, end="\n"):
    descr = word_wrap(descr, 38)

    descr_lines = descr.split("\n")

    if print_header:
        for line in descr_lines[:-1]:
            print(f"| {pad_with_spaces(line, 38)} | {' ' * 10} | {' ' * 10} | {' ' * 9} |")

    descr_last_line = descr_lines[-1]
    
    print(f"| {pad_with_spaces(descr_last_line, 38)} | {pad_with_spaces(pyglm, 10, align='right')} | {pad_with_spaces(numpy, 10, align='right')} | {pad_with_spaces(ratio, 9, align='right')} |", end=end)

def run_test(descr, pyglm_setup_code, pyglm_code, numpy_setup_code, numpy_code, number):
    global pyglm_total_time, numpy_total_time

    descr += f"\n({number:,} times)"
    
    if ON_WINDOWS:
        print_row(descr, "", "", "", end="\r")
    
    pyglm_result = 2**31
    numpy_result = 2**31

    for i in range(10):
        run_pyglm_first = random.choice((True,False))

        if run_pyglm_first:
            pyglm_result = min(pyglm_result, timeit.timeit(pyglm_code, pyglm_setup_code, number=number))
            numpy_result = min(numpy_result, timeit.timeit(numpy_code, numpy_setup_code, number=number))
        else:
            numpy_result = min(numpy_result, timeit.timeit(numpy_code, numpy_setup_code, number=number))
            pyglm_result = min(pyglm_result, timeit.timeit(pyglm_code, pyglm_setup_code, number=number))
            
    
        if ON_WINDOWS:
            print_row(descr, "{}ms".format(seconds_to_milliseconds(pyglm_result)), "{}ms".format(seconds_to_milliseconds(numpy_result)),  "{:.02f}x".format(numpy_result / pyglm_result), end="\r", print_header=False)

    pyglm_total_time += pyglm_result
    numpy_total_time += numpy_result
    
    print_row(descr, "{}ms".format(seconds_to_milliseconds(pyglm_result)), "{}ms".format(seconds_to_milliseconds(numpy_result)),  "{:.02f}x".format(numpy_result / pyglm_result), print_header=not ON_WINDOWS)
    print_horizontal_rule()

print(f"""Evaluating performance of PyGLM compared to NumPy.

Running on platform '{sys.platform}'.

Python version:
{sys.version}

Comparing the following module versions:
{glm.version}
 vs
NumPy version {numpy.__version__}
________________________________________________________________________________

The following table shows information about a task to be achieved and the time
it took when using the given module. Lower time is better.
Each task is repeated ten times per module, only showing the best (i.e. lowest)
value.

""")

print_horizontal_rule()
print_row("Description", "PyGLM time", "NumPy time", "ratio")
print_horizontal_rule()

############################
# Actual tests start here: #
############################

run_test("3 component vector creation",
         
         "import glm",
         "glm.vec3()",

         "import numpy",
         "numpy.zeros((3,), numpy.float32)",

         100000
)

run_test("3 component vector creation with custom components",
         
         "import glm",
         "glm.vec3(1,2,3)",

         "import numpy",
         "numpy.array((1,2,3), numpy.float32)",

         50000
)

run_test("dot product",
         
         "import glm; v1 = glm.vec3(); v2 = glm.vec3()",
         "glm.dot(v1, v2)",
         
         "import numpy; v1 = numpy.zeros((3,), numpy.float32); v2 = numpy.zeros((3,), numpy.float32)",
         "numpy.dot(v1, v2)",

         50000
)

run_test("cross product",
         
         "import glm; v1 = glm.vec3(1); v2 = glm.vec3(1,2,3)",
         "glm.cross(v1, v2)",

         "import numpy; v1 = numpy.array((1,1,1), numpy.float32); v2 = numpy.array((1,2,3), numpy.float32)",
         "numpy.cross(v1, v2)",

         25000
)

run_test("L2-Norm of 3 component vector",
         
         "import glm; v = glm.vec3(1,2,3)",
         "glm.l2Norm(v)",
         
         "import numpy; v = numpy.array((1,1,1), numpy.float32)",
         "numpy.linalg.norm(v)",

         100000
)

run_test("4x4 matrix creation",
         
         "import glm",
         "glm.mat4(0)",
         
         "import numpy",
         "numpy.zeros((4,4), numpy.float32)",

         50000
)
run_test("4x4 identity matrix creation",
         
         "import glm",
         "glm.mat4()",
         
         "import numpy",
         "numpy.identity(4, numpy.float32)",

         100000
)

run_test("4x4 matrix transposition",
         
         "import glm; m = glm.mat4()",
         "glm.transpose(m)",
         
         "import numpy; m = numpy.identity(4, numpy.float32)",
         "numpy.transpose(m)",

         50000
)

run_test("4x4 multiplicative inverse",
         
         "import glm; m = glm.mat4()",
         "glm.inverse(m)",
         
         "import numpy; m = numpy.identity(4, numpy.float32)",
         "numpy.linalg.inv(m)",

         50000
)

run_test("3 component vector addition",
         
         "import glm; v1 = glm.vec3(1); v2 = glm.vec3(1,2,3)",
         "v1 + v2",
         
         "import numpy; v1 = numpy.array((1,1,1), numpy.float32); v2 = numpy.array((1,2,3), numpy.float32)",
         "v1 + v2",

         100000
)

run_test("4x4 matrix multiplication",
         
         "import glm; m1 = glm.mat4(); m2 = glm.mat4(2)",
         "m1 * m2",
         
         "import numpy; m1 = numpy.identity(4, numpy.float32); m2 = numpy.identity(4, numpy.float32) * 2",
         "m1 * m2",

         100000
)

run_test("4x4 matrix x vector multiplication",
         
         "import glm; m = glm.mat4(); v = glm.vec4()",
         "m * v",
         
         "import numpy; m = numpy.identity(4, numpy.float32); v = numpy.zeros((4,), numpy.float32)",
         "m * v",

         100000
)

print_row("TOTAL",
          "{:.02f}s".format(pyglm_total_time),
          "{:.02f}s".format(numpy_total_time),
          "{:.02f}x".format(numpy_total_time / pyglm_total_time))
print_horizontal_rule()
