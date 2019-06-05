import numpy, glm

import time

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
numpy_v4 = numpy.array((0,0,0,0), dtype=numpy.float32)

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

print("How PyGLM's performance roughly compares to NumPy's performance:")

print("4x4 matrices were created {} times as fast in PyGLM".format((round(test_func(numpy_create_mat4) / test_func(glm_create_mat4), 2))))

print("The dot product of two 3 component vectors was calculated {} times as fast in PyGLM".format((round(test_func(numpy_dot) / test_func(glm_dot), 2))))

print("Transposing a 4x4 matrix was {} times as fast in PyGLM".format((round(test_func(numpy_transpose) / test_func(glm_transpose), 2))))

print("Multiplying a 4 component vector by a 4 component vector was {} times as fast in PyGLM".format((round(test_func(numpy_mul_v4_v4) / test_func(glm_mul_v4_v4), 2))))

print("Multiplying a 4x4 matrix by a 4 component vector was {} times as fast in PyGLM".format((round(test_func(numpy_mul_m44_v4) / test_func(glm_mul_m44_v4), 2))))
