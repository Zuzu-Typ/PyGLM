#from ..detail.setup import *
from ..detail.func_common import abs, sign

def compute_ceilShift(v, Shift=None):
    if Shift:
        return v | (v >> Shift)
    return v

def compute_ceilPowerOfTwo(x):
    Sign = sign(x)
    v = abs(x)

    v = v - 1.
    v = v | (v >> 1.)
    v = v | (v >> 2.)
    v = v | (v >> 4.)
    v = compute_ceilShift(v,8)
    v = compute_ceilShift(v,16)
    v = compute_ceilShift(v,32)
    return (v + 1.) * Sign
