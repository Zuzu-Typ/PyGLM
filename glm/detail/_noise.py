from .func_common import floor

def mod289(x):
	return x - floor(x * 1.0 / 289.) * 289.

def permute(x):
	return mod289(((x * 34.) + 1.) * x)

def taylorInvSqrt(r):
	return (1.79284291400159) - (0.85373472095314) * r

def fade(t):
	return (t * t * t) * (t * (t * 6. - 15.) + 10.)