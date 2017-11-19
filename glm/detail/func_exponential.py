import numpy

##def compute_sqrt(vec):
##    return functor1(math.sqrt, vec)

def exp(vec):
    return vec.__class__(numpy.exp(vec))

def log(vec):
    return vec.__class__(numpy.log(vec))

def exp2(x):
    return x.__class__(numpy.exp2(x))

def log2(x):
    return x.__class__(numpy.log2(x))

##def compute_log2(vec):
##    return functor1(log2, vec)

def sqrt(x):
    return x.__class__(numpy.sqrt(x))

def inversesqrt(vec):
    return 1. / sqrt(vec)

def pow(base, exponent):
    return base.__class__(numpy.power(base, exponent))
    
