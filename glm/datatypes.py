import numpy

numpy_dtypes = (numpy.bool_,
                numpy.int_,
                numpy.intc,
                numpy.intp,
                numpy.int8,
                numpy.int16,
                numpy.int32,
                numpy.int64,
                numpy.uint8,
                numpy.uint16,
                numpy.uint32,
                numpy.uint64,
                numpy.float_,
                numpy.float16,
                numpy.float32,
                numpy.float64)
    
try:
    dtypes = (int, long, float, bool) + numpy_dtypes
except:
    dtypes = (int, float, bool) + numpy_dtypes

ltypes = (list, tuple, set, numpy.ndarray)

default_dtype = numpy.float32

glm_highp_float = numpy.float64
glm_highp_int = numpy.int64
glm_highp_uint = numpy.uint
