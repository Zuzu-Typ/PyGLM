import numpy

def lessThan(x, y):
    assert (len(x) == len(y))

    return x.__class__(numpy.less(x,y))

def lessThanEqual(x, y):
    assert (len(x) == len(y))

    return x.__class__(numpy.less_equal(x,y))

def greaterThan(x, y):
    assert (len(x) == len(y))

    return x.__class__(numpy.greater(x,y))

def greaterThanEqual(x, y):
    assert (len(x) == len(y))

    return x.__class__(numpy.greater_equal(x,y))

def equal(x, y):
    assert (len(x) == len(y))

    return x.__class__(numpy.equal(x,y))

def notEqual(x, y):
    assert (len(x) == len(y))

    return x.__class__(numpy.not_equal(x,y))

any = numpy.any
all = numpy.all

def not_(v):
    return v.__class__(numpy.logical_not(v))

