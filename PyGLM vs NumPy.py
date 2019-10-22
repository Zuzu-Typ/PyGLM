#import numpy, glm

import time

start_time = time.time()
import glm
glm_import_time = time.time() - start_time

start_time = time.time()
import numpy
numpy_import_time = time.time() - start_time

numpy_import_time /= glm_import_time
numpy_import_time = (1. / numpy_import_time) * 100
glm_import_time = 100

REPETITIONS = 100000

def test_func(func, *args, **kw):
    before = time.time()
    for i in range(REPETITIONS):
        func(*args, **kw)
    return time.time() - before

glm_create_mat4 = lambda: glm.mat4()

numpy_create_mat4 = lambda: numpy.identity(4, dtype=numpy.float32)

glm_v3 = glm.vec3()
numpy_v3 = numpy.array((0,0,0), dtype=numpy.float32)

glm_v4 = glm.vec4()
numpy_v4 = numpy.zeros((4,), dtype=numpy.float32)#numpy.array((0,0,0,0), dtype=numpy.float32)

glm_m44 = glm.mat4()
numpy_m44 = numpy.identity(4, dtype=numpy.float32)

glm_dot = lambda: glm.dot(glm_v3, glm_v3)
numpy_dot = lambda: numpy.vdot(numpy_v3, numpy_v3)

glm_transpose = lambda: glm.transpose(glm_m44)
numpy_transpose = lambda: numpy.transpose(numpy_m44)

glm_mul_v4_v4 = lambda: glm_v4 * glm_v4
numpy_mul_v4_v4 = lambda: numpy_v4 * numpy_v4

glm_mul_m44_v4 = lambda: glm_m44 * glm_v4
numpy_mul_m44_v4 = lambda: numpy_m44 * numpy_v4

glm_mat4_getitem = lambda: glm_m44[0]
numpy_mat4_getitem = lambda: numpy_m44[0]

print("How PyGLM's performance roughly compares to NumPy's performance:")

print("instruction\t | np speed (%)\t | glm speed (%)\t ")

def print_instruction(string_, np_func, glm_func):
    np_result = test_func(np_func)
    glm_result = test_func(glm_func)
    np_result /= glm_result
    np_result = (1. / np_result) * 100
    glm_result = 100

    print(string_ + " | {: 6.2f}\t | {: 6.2f}".format(np_result, glm_result))

print("import\t\t | {: 6.2f}\t | {: 6.2f}".format(numpy_import_time, glm_import_time))

instructions = [
    ("mat4()\t\t", numpy_create_mat4, glm_create_mat4),
    ("dot(vec3, vec3)\t", numpy_dot, glm_dot),
    ("transpose(mat4)\t", numpy_transpose, glm_transpose),
    ("vec4 * vec4\t", numpy_mul_v4_v4, glm_mul_v4_v4),
    ("mat4 * vec4\t", numpy_mul_m44_v4, glm_mul_m44_v4),
    ("mat4[0]\t\t", numpy_mat4_getitem, glm_mat4_getitem),
    ]

for s, np_f, glm_f in instructions:
    print_instruction(s, np_f, glm_f)
