from threading import Thread

import time

glm_counter = 0
numpy_counter = 0

glm_time = 0
numpy_time = 0

repititions = 1000000

results = []

def measure_function_glm(func, *args, **kw):
    global glm_counter, repititions, glm_time
    glm_counter = 0
    glm_time = 0
    start = time.time()
    for i in range(repititions):
        func(*args, **kw)
        glm_counter += 1
    glm_time = time.time() - start

def measure_function_numpy(func, *args, **kw):
    global numpy_counter, repititions, numpy_time
    numpy_counter = 0
    numpy_time = 0
    start = time.time()
    for i in range(repititions):
        func(*args, **kw)
        numpy_counter += 1
    numpy_time = time.time() - start

def print_percentage():
    global glm_counter, numpy_counter
    while glm_counter < repititions or numpy_counter < repititions:
        print("\rPyGLM: {: 4d}%, NumPy: {: 4d}%".format(int(glm_counter / repititions * 100), int(numpy_counter / repititions * 100)), end="")
    print("\rPyGLM: {: 4d}%, NumPy: {: 4d}%".format(int(glm_counter / repititions * 100), int(numpy_counter / repititions * 100)))

def arg_to_string(arg):
    if isinstance(arg, type):
        return "{}.{}".format(arg.__module__, arg.__name__)
    return repr(arg)

def get_evaluation_string():
    if (glm_time < numpy_time):
        return "PyGLM was {:.2f}x as fast as NumPy".format(numpy_time / glm_time)
    else:
        return "NumPy was {:.2f}x as fast as PyGLM".format(glm_time / numpy_time)
        
def test_func(description, glm_func, glm_args, numpy_func, numpy_args):
    print("-"*80)
    print("Comparing {}.\n".format(description))
    print("PyGLM instruction:\n\t{}.{}({})\n".format(glm_func.__module__, glm_func.__name__, ", ".join([arg_to_string(x) for x in glm_args])))
    print("NumPy instruction:\n\t{}.{}({})\n".format(numpy_func.__module__, numpy_func.__name__, ", ".join([arg_to_string(x) for x in numpy_args])))
    print("Running for {:,} iterations...".format(repititions))
    Thread(target=measure_function_glm, args=[glm_func] + list(glm_args)).start()
    Thread(target=measure_function_numpy, args=[numpy_func] + list(numpy_args)).start()
    print_percentage()
    print("\nTime taken:\n\tPyGLM: {:.2f}s\n\tNumPy: {:.2f}s\n".format(glm_time, numpy_time))
    print("{}.\n".format(get_evaluation_string()))

    results.append((description, glm_time, numpy_time))

def test_operation(description, operation, format_, glm_args, numpy_args):
    print("-"*80)
    print("Comparing {}.\n".format(description))
    print("PyGLM instruction:\n\t{}\n".format(format_.format(*[arg_to_string(x) for x in glm_args])))
    print("NumPy instruction:\n\t{}\n".format(format_.format(*[arg_to_string(x) for x in numpy_args])))
    print("Running for {:,} iterations...".format(repititions))
    Thread(target=measure_function_glm, args=[operation] + list(glm_args)).start()
    Thread(target=measure_function_numpy, args=[operation] + list(numpy_args)).start()
    print_percentage()
    print("\nTime taken:\n\tPyGLM: {:.2f}s\n\tNumPy: {:.2f}s\n".format(glm_time, numpy_time))
    print("{}.\n".format(get_evaluation_string()))

    results.append((description, glm_time, numpy_time))

def print_table_row(descr, glm_time, numpy_time, ratio):
    while len(descr) > 38:
        last_space = descr[:38].rfind(" ")
        print(("| {} | " + " " * 10 + " | " + " " * 10 + " | " + " " * 9 + " |").format(descr[:last_space] + (38 - last_space) * " "))
        descr = descr[last_space + 1:]
    print("| {} | {} | {} | {} |".format(descr + (38 - len(descr)) * " ", glm_time, numpy_time, ratio))

def print_results():
    for description, glm_time, numpy_time in results:
        print_table_row(description, "{: 9.2f}s".format(glm_time), "{: 9.2f}s".format(numpy_time), "{: 8.2f}x".format(numpy_time / glm_time))
        print("+----------------------------------------+------------+------------+-----------+")
            

print("-"*80)
print("Comparing import speed.")
start = time.time()
import glm
glm_time = time.time() - start

start = time.time()
import numpy
numpy_time = time.time() - start

results.append(("import", glm_time, numpy_time))

print("\nTime taken:\n\tPyGLM: {:.2f}s\n\tNumPy: {:.2f}s\n".format(glm_time, numpy_time))
print("{}.\n".format(get_evaluation_string()))
    
test_func("3 component vector creation", glm.vec3, [0], numpy.zeros, [(3,), numpy.float32])
test_func("3 component vector creation with custom components", glm.vec3, [1, 2, 3], numpy.array, [(1, 2, 3), numpy.float32])
test_func("dot product", glm.dot, [glm.vec3(), glm.vec3()], numpy.dot, [numpy.zeros((3,)), numpy.zeros((3,))])
repititions = 100_000
test_func("cross product", glm.cross, [glm.vec3(1), glm.vec3(1,2,3)], numpy.cross, [numpy.array((1,1,1), numpy.float32), numpy.array((1,2,3), numpy.float32)])
test_func("L2-Norm of 3 component vector", glm.l2Norm, [glm.vec3(1,2,3)], numpy.linalg.norm, [numpy.array((1,2,3), numpy.float32)])
repititions = 1_000_000
test_func("4x4 matrix creation", glm.mat4, [0], numpy.zeros, [(4,4), numpy.float32])
test_func("4x4 identity matrix creation", glm.identity, [glm.mat4], numpy.identity, [4, numpy.float32])
test_func("4x4 matrix transposition", glm.transpose, [glm.mat4()], numpy.transpose, [numpy.identity(4, numpy.float32)])
repititions = 100_000
test_func("4x4 matrix multiplicative inverse", glm.inverse, [glm.mat4()], numpy.linalg.inv, [numpy.identity(4, numpy.float32)])
repititions = 1_000_000
test_operation("3 component vector addition", lambda x, y: (x+y), "{} + {}", [glm.vec3(), glm.vec3()], [numpy.zeros(3, numpy.float32), numpy.zeros(3, numpy.float32)])
test_operation("4x4 matrix multiplication", lambda x, y: (x*y), "{} * {}", [glm.mat4(), glm.mat4()], [numpy.identity(4, numpy.float32), numpy.identity(4, numpy.float32)])
test_operation("4x4 matrix - 4 component vector multiplication", lambda x, y: (x*y), "{} * {}", [glm.mat4(), glm.vec4()], [numpy.identity(4, numpy.float32), numpy.zeros(4, numpy.float32)])

print("#" *80)
print("RESULTS:\n")

print("+----------------------------------------+------------+------------+-----------+")
print("| Description                            | PyGLM time | NumPy time | ratio     |")
print("+----------------------------------------+------------+------------+-----------+")

print_results()
