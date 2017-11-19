from ..detail.type_mat3x3 import tmat3x3
from ..detail.type_mat4x4 import tmat4x4
from ..detail.type_vec3 import tvec3
from ..detail.type_vec4 import tvec4
from .constants import *

from ..detail.func_trigonometric import *
from ..detail.func_geometric import *
from ..detail.func_exponential import *
from ..detail.func_common import mix, clamp
from ..datatypes import default_dtype, dtypes, ltypes, default_dtype
from ..detail.setup import GLM_C_FLOAT_SIZE, GLM_QUAT, pyglmCompareType

def _unswizzle(swizzle):
	return swizzle.replace("r","x").replace("s", "x").replace("g", "y").replace("t", "y").replace("b", "z").replace("p", "z").replace("a", "w").replace("q", "w")


def compute_quat_dot(x, y):
	tmp = tvec4(x.x * y.x, x.y * y.y, x.z * y.z, x.w * y.w)
	return (tmp.x + tmp.y) + (tmp.z + tmp.w)

def compute_quat_add(q, p):
	return tquat(q.w + p.w, q.x + p.x, q.y + p.y, q.z + p.z)

def compute_quat_sub(q, p):
	return tquat(q.w - p.w, q.x - p.x, q.y - p.y, q.z - p.z)

def compute_quat_mul_scalar(q, s):
	return tquat(q.w * s, q.x * s, q.y * s, q.z * s)

def compute_quat_div_scalar(q, s):
	return tquat(q.w / s, q.x / s, q.y / s, q.z / s)

def compute_quat_mul_vec4(q, v):
	return tvec4(q * tvec3(v), v.w)

def conjugate_quat(q):
	return tquat(q.w, -q.x, -q.y, -q.z)

def inverse_quat(q):
	return conjugate_quat(q) / compute_quat_dot(q,q)

def lerp(x, y, a):
	assert(a >= (0))
	assert(a <= (1))

	return x * ((1) - a) + (y * a)

def slerp(x, y, a):
	z = tquat(y)

	cosTheta = dot(x, y)

	# If cosTheta < 0, the interpolation will take the long way around the sphere. 
	# To fix this, one quat must be negated.
	if (cosTheta < (0)):
		z        = -y
		cosTheta = -cosTheta

	# Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
	if(cosTheta > (1.) - epsilon()):
		# Linear interpolation
		return tquat(mix(x.w, z.w, a),
			mix(x.x, z.x, a),
			mix(x.y, z.y, a),
			mix(x.z, z.z, a))
	else:
		# Essential Mathematics, page 467
		angle = acos(cosTheta)
		return (sin(((1.) - a) * angle) * x + sin(a * angle) * z) / sin(angle)

def rotate_quat(q, angle, v):
	Tmp = tvec3(v)

	# Axis of rotation must be normalised
	len = Tmp.length()
	if(abs(len - (1.)) > (0.001)):
		oneOverLen = (1.) / len
		Tmp.x *= oneOverLen
		Tmp.y *= oneOverLen
		Tmp.z *= oneOverLen

	AngleRad = (angle)
	Sin = sin(AngleRad * (0.5))

	return q * tquat(cos(AngleRad * (0.5)), Tmp.x * Sin, Tmp.y * Sin, Tmp.z * Sin)

def length_quat(q):
	return sqrt(compute_dot(q, q))

def normalize_quat(q):
	len = length_quat(q)
	if(len <= (0)): # Problem
		return tquat(1, 0, 0, 0)
	oneOverLen = (1.) / len
	return tquat(q.w * oneOverLen, q.x * oneOverLen, q.y * oneOverLen, q.z * oneOverLen)

def eulerAngles(x):
	return tvec3(pitch(x), yaw(x), roll(x))

def roll(q):
	return (atan((2.) * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z))

def pitch(q):
	return (atan((2.) * (q.y * q.z + q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z))

def yaw(q):
	return asin(clamp((-2.) * (q.x * q.z - q.w * q.y), (-1.), (1.)))

def mat3_cast(q):
##    Result = tmat3x3((1))
	qxx = (q.x * q.x)
	qyy = (q.y * q.y)
	qzz = (q.z * q.z)
	qxz = (q.x * q.z)
	qxy = (q.x * q.y)
	qyz = (q.y * q.z)
	qwx = (q.w * q.x)
	qwy = (q.w * q.y)
	qwz = (q.w * q.z)

##    Result[0][0] = (1.) - (2) * (qyy +  qzz)
##    Result[0][1] = (2.) * (qxy + qwz)
##    Result[0][2] = (2.) * (qxz - qwy)
##
##    Result[1][0] = (2.) * (qxy - qwz)
##    Result[1][1] = (1.) - (2.) * (qxx +  qzz)
##    Result[1][2] = (2.) * (qyz + qwx)
##
##    Result[2][0] = (2.) * (qxz + qwy)
##    Result[2][1] = (2.) * (qyz - qwx)
##    Result[2][2] = (1.) - (2) * (qxx +  qyy)

	Result = tmat3x3((((1.) - (2) * (qyy +  qzz), (2.) * (qxy + qwz), (2.) * (qxz - qwy)),
					  ((2.) * (qxy - qwz), (1.) - (2.) * (qxx +  qzz), (2.) * (qyz + qwx)),
					  ((2.) * (qxz + qwy), (2.) * (qyz - qwx), (1.) - (2) * (qxx +  qyy))))
	
	return Result

def mat4_cast(q):
	return tmat4x4(mat3_cast(q))

def quat_cast(m):
	fourXSquaredMinus1 = m[0,0] - m[1,1] - m[2,2]
	fourYSquaredMinus1 = m[1,1] - m[0,0] - m[2,2]
	fourZSquaredMinus1 = m[2,2] - m[0,0] - m[1,1]
	fourWSquaredMinus1 = m[0,0] + m[1,1] + m[2,2]

	biggestIndex = 0
	fourBiggestSquaredMinus1 = fourWSquaredMinus1
	if(fourXSquaredMinus1 > fourBiggestSquaredMinus1):
		fourBiggestSquaredMinus1 = fourXSquaredMinus1
		biggestIndex = 1
	
	if(fourYSquaredMinus1 > fourBiggestSquaredMinus1):
		fourBiggestSquaredMinus1 = fourYSquaredMinus1
		biggestIndex = 2
	
	if(fourZSquaredMinus1 > fourBiggestSquaredMinus1):
		fourBiggestSquaredMinus1 = fourZSquaredMinus1
		biggestIndex = 3
	

	biggestVal = sqrt(fourBiggestSquaredMinus1 + (1)) * (0.5)
	mult = (0.25) / biggestVal

	Result = tquat()
	if biggestVal == 0:
		Result.w = biggestVal;
		Result.x = (m[1,2] - m[2,1]) * mult;
		Result.y = (m[2,0] - m[0,2]) * mult;
		Result.z = (m[0,1] - m[1,0]) * mult;
		
	elif biggestVal == 1:
		Result.w = (m[1,2] - m[2,1]) * mult;
		Result.x = biggestVal;
		Result.y = (m[0,1] + m[1,0]) * mult;
		Result.z = (m[2,0] + m[0,2]) * mult;
		
	elif biggestVal == 2:
		Result.w = (m[2,0] - m[0,2]) * mult;
		Result.x = (m[0,1] + m[1,0]) * mult;
		Result.y = biggestVal;
		Result.z = (m[1,2] + m[2,1]) * mult;
		
	elif biggestVal == 3:
		Result.w = (m[0,1] - m[1,0]) * mult;
		Result.x = (m[2,0] + m[0,2]) * mult;
		Result.y = (m[1,2] + m[2,1]) * mult;
		Result.z = biggestVal;
		
	else:
		assert(False)
	return Result

def angle(x):
	return acos(x.w) * 2.

def axis(x):
	tmp1 = (1.) - x.w * x.w
	if(tmp1 <= (0)):
		return tvec3(0, 0, 1)
	tmp2 = (1.) / sqrt(tmp1)
	return tvec3(x.x * tmp2, x.y * tmp2, x.z * tmp2)

def angleAxis(angle, v):
	Result = tquat()

	a = (angle)
	s = sin(a * (0.5))

	Result.w = cos(a * (0.5))
	Result.x = v.x * s
	Result.y = v.y * s
	Result.z = v.z * s
	return Result

	
class tquat:
	glm_type = GLM_QUAT
	shape = GLM_QUAT
	def __init__(self, *args, **kw):
		self.dtype = kw.get("dtype", default_dtype)
		__tname__ = "tquat"
		if len(args) == 1:
			if pyglmCompareType(args[0], tquat):
				self.value = args[0].value.copy()
##                q = args[0]
##                self.x = q.x
##                self.y = q.y
##                self.z = q.z
##                self.w = q.w
				
			elif pyglmCompareType(args[0], tvec3):
				eulerAngle = args[0]

				c = cos(eulerAngle * 0.5)
				s = sin(eulerAngle * 0.5)

				self.value = numpy.array((s.x * c.y * c.z - c.x * s.y * s.z,
										  c.x * s.y * c.z + s.x * c.y * s.z,
										  c.x * c.y * s.z - s.x * s.y * c.z,
										  c.x * c.y * c.z + s.x * s.y * s.z), dtype=self.dtype)
##                self.w = c.x * c.y * c.z + s.x * s.y * s.z
##                self.x = s.x * c.y * c.z - c.x * s.y * s.z
##                self.y = c.x * s.y * c.z + s.x * c.y * s.z
##                self.z = c.x * c.y * s.z - s.x * s.y * c.z

			elif type(args[0]) in ltypes:
				self.__init__(self, *args[0])

			elif pyglmCompareType(args[0], tmat3x3) or pyglmCompareType(args[0], tmat4x4):
					Result = self.quat_cast(args[0])

					self.value = Result.value

			else:
				raise TypeError("unsupported type {} for tquat".format(type(args[0])))

		elif len(args) == 2:
			if pyglmCompareType(args[1], tvec3) and type(args[0]) in dtypes:
				s, v = args
				self.value = numpy.array((v.x,v.y,v.z,s), dtype = self.dtype)
##                self.x = v.x
##                self.y = v.y
##                self.z = v.z
##                self.w = s

			elif pyglmCompareType(args[0], tvec3) and pyglmCompareType(args[1], tvec3):
				u, v = args
				LocalW = tvec3(cross(u,v))
				Dot = dot(u,v)
				q = tquat(1.+ Dot, LocalW.x, LocalW.y, LocalW.z)

				Result = normalize_quat(q)

				self.value = numpy.array((Result.x, Result.y, Result.z, Result.w), dtype=self.dtype)

##                self.x = Result.x
##                self.y = Result.y
##                self.z = Result.z
##                self.w = Result.w

			else:
				raise TypeError("unsupported types {}, {} for tquat".format(type(args[0]), type(args[1])))
				
		elif len(args) == 4:
			for i in args:
				if not type(i) in dtypes:
					raise TypeError("unsupported type {} for tquat".format(type(i)))
				
##            w, x, y, z = args
			self.value = numpy.array(args[1:] + (args[0],),dtype=self.dtype)
##            self.x = x
##            self.y = y
##            self.z = z
##            self.w = w

##        elif len(args) == 4:
##            for i in args:
##                if not type(i) in dtypes:
##                    raise TypeError("unsupported type {} for tquat".format(type(i)))
##                
##            w, x, y, z = args
##            self.x = x
##            self.y = y
##            self.z = z
##            self.w = w
			
		else:
			self.value = numpy.array((0,0,0,1),dtype = self.dtype)
##            self.x = self.y = self.z = 0
##            self.w = 1

	def length(self):
		return 4

	__len__ = length

	

	def __iadd__(self, value):
		self = compute_quat_add(self, tquat(value))
		return self

	def __isub__(self,value):
		self = compute_quat_sub(self, tquat(value))
		return self

	def __imul__(self, value):
		if type(value) in dtypes:
			self = compute_quat_mul_scalar(self, value)
		elif pyglmCompareType(value, tquat):
			r = value

			p = tquat(self)
			q = tquat(r)

			self.w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z
			self.x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y
			self.y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z
			self.z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x
			return self

	def __itruediv__(self, value):
		if type(value) in dtypes:
			self = compute_quat_div_scalar(self, value)

	__idiv__ = __itruediv__

	def __pos__(self):
		return self

	def __neg__(self):
		return tquat(-self.w, -self.x, -self.y, -self.z)

	def __add__(self, value):
		Result = tquat(self)
		Result += value
		return Result

	__radd__ = __add__

	def __mul__(self, value):
		if pyglmCompareType(value, tquat):
			Result = tquat(self)
			Result *= value
			return Result

		elif pyglmCompareType(value, tvec3):
			q = self
			v = value
			QuatVector = tvec3(q.x, q.y, q.z)
			uv = tvec3(cross(QuatVector, v))
			uuv = tvec3(cross(QuatVector, uv))

			return v + ((uv * q.w) + uuv) * (2.)

		elif pyglmCompareType(value, tvec4):
			return compute_quat_mul_vec4(self,value)

		elif type(value) in dtypes:
			q = self
			s = value
			return tquat(q.w * s, q.x * s, q.y * s, q.z * s)

	def __rmul__(self, value):
		if pyglmCompareType(value, tquat):
			return self.__mul__(self,value)

		elif pyglmCompareType(value, tvec3):
			v = value
			q = self

			return inverse_quat(q) * v

		elif pyglmCompareType(value, tvec4):
			v = value
			q = self

			return inverse_quat(q) * v

		elif type(value) in dtypes:
			q = self
			s = value
			return q * s

	def __eq__(q1, q2):
		return (q1.x == q2.x) and (q1.y == q2.y) and (q1.z == q2.z) and (q1.w == q2.w)

	def __ne__(q1, q2):
		return (q1.x != q2.x) or (q1.y != q2.y) or (q1.z != q2.z) or (q1.w != q2.w)

	def __lt__(x, y):
		Result = tvec4(0)
		for i in range(x.length()):
			Result[i] = x[i] < y[i]
		return Result

	def __le__(x,y):
		Result = tvec4(0)
		for i in range(x.length()):
			Result[i] = x[i] <= y[i]
		return Result

	def __gt__(x,y):
		Result = tvec4(0)
		for i in range(x.length()):
			Result[i] = x[i] > y[i]
		return Result

	def __ge__(x,y):
		Result = tvec4(0)
		for i in range(x.length()):
			Result[i] = x[i] >= y[i]
		return Result

	def __bool__(self):
		return (bool(self.x), bool(self.y), bool(self.z), bool(self.w))

	__nonzero__ = __bool__

	def __getitem__(self, key):
		if type(key) == slice:
			raise TypeError("tquat doesn't support slices")
		else:
			if key in (0,-4):
				return self.__dict__["value"][0]
			elif key in (1,-3):
				return self.__dict__["value"][1]
			elif key in (2,-2):
				return self.__dict__["value"][2]
			elif key in (3,-1):
				return self.__dict__["value"][3]
			else:
				raise IndexError("tquat index out of range")

	def __setitem__(self, key, value):
		if type(key) == slice:
			raise TypeError("tquat doesn't support slices")
		else:
			if key in (0,-4):
				self.__dict__["value"][0] = value
			elif key in (1,-3):
				self.__dict__["value"][1] = value
			elif key in (2,-2):
				self.__dict__["value"][2] = value
			elif key in (3,-1):
				self.__dict__["value"][3] = value
			else:
				raise IndexError("tquat index out of range")

	def __getattr__(self, name):
		if name.startswith('__') and name.endswith('__'):
			raise AttributeError(name)

		if name == "value":
			return self.__dict__["value"]

		if len(name) == 1:
			if name in "xrs":
				return self.__dict__["value"][0]
			if name in "ygt":
				return self.__dict__["value"][1]
			if name in "zbp":
				return self.__dict__["value"][2]
			if name in "waq":
				return self.__dict__["value"][3]

		if len(name) == 2:
			for char in name:
				if not char in "xrsygtzbpwaq":
					raise AttributeError(name)
			return tvec2(self.__dict__["value"][0] if name[0] in "xrs" else self.__dict__["value"][1] if name[0] in "ygt" else self.__dict__["value"][2] if name[0] in "zbp" else self.__dict__["value"][3],
						 self.__dict__["value"][0] if name[1] in "xrs" else self.__dict__["value"][1] if name[1] in "ygt" else self.__dict__["value"][2] if name[1] in "zbp" else self.__dict__["value"][3])

		if len(name) == 3:
			for char in name:
				if not char in "xrsygtzbpwaq":
					raise AttributeError(name)
			return tvec3(self.__dict__["value"][0] if name[0] in "xrs" else self.__dict__["value"][1] if name[0] in "ygt" else self.__dict__["value"][2] if name[0] in "zbp" else self.__dict__["value"][3],
						 self.__dict__["value"][0] if name[1] in "xrs" else self.__dict__["value"][1] if name[1] in "ygt" else self.__dict__["value"][2] if name[1] in "zbp" else self.__dict__["value"][3],
						 self.__dict__["value"][0] if name[2] in "xrs" else self.__dict__["value"][1] if name[2] in "ygt" else self.__dict__["value"][2] if name[2] in "zbp" else self.__dict__["value"][3])

		if len(name) == 4:
			for char in name:
				if not char in "xrsygtzbpwaq":
					raise AttributeError(name)
			return tvec4(self.__dict__["value"][0] if name[0] in "xrs" else self.__dict__["value"][1] if name[0] in "ygt" else self.__dict__["value"][2] if name[0] in "zbp" else self.__dict__["value"][3],
						 self.__dict__["value"][0] if name[1] in "xrs" else self.__dict__["value"][1] if name[1] in "ygt" else self.__dict__["value"][2] if name[1] in "zbp" else self.__dict__["value"][3],
						 self.__dict__["value"][0] if name[2] in "xrs" else self.__dict__["value"][1] if name[2] in "ygt" else self.__dict__["value"][2] if name[2] in "zbp" else self.__dict__["value"][3],
						 self.__dict__["value"][0] if name[3] in "xrs" else self.__dict__["value"][1] if name[3] in "ygt" else self.__dict__["value"][2] if name[3] in "zbp" else self.__dict__["value"][3])

		raise AttributeError(name)

	def __setattr__(self, name, value):
		if len(name) == 1:
			if name in "xrs":
				self.__dict__["value"][0] = self.dtype(value)
			elif name in "ygt":
				self.__dict__["value"][1] = self.dtype(value)
			elif name in "zbp":
				self.__dict__["value"][2] = self.dtype(value)
			elif name in "waq":
				self.__dict__["value"][3] = self.dtype(value)
			else:
				raise AttributeError(name)
				
		elif _unswizzle(name) == "xy":
			if (pyglmCompareType(value, tvec2) or type(value) in ltypes) and len(value) == 2:
				self.__dict__["value"][0] = self.dtype(value[0])
				self.__dict__["value"][1] = self.dtype(value[1])
			else:
				raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
			
		elif _unswizzle(name) == "xyz":
			if (pyglmCompareType(value, tvec3) or type(value) in ltypes) and len(value) == 3:
				self.__dict__["value"][0] = self.dtype(value[0])
				self.__dict__["value"][1] = self.dtype(value[1])
				self.__dict__["value"][2] = self.dtype(value[2])
			else:
				raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
			
		elif _unswizzle(name) == "xyzw":
			if (pyglmCompareType(value, tvec4) or type(value) in ltypes) and len(value) == 4:
				self.__dict__["value"][0] = self.dtype(value[0])
				self.__dict__["value"][1] = self.dtype(value[1])
				self.__dict__["value"][2] = self.dtype(value[2])
				self.__dict__["value"][3] = self.dtype(value[3])
			else:
				raise TypeError("expected iterable of length 2 to 4, got {}", type(value))
			
		else:
			self.__dict__[name] = value

	def __repr__(self):
		return self.__str__()

	def __str__(self):
		return "tquat( {} , {} , {} , {} )".format(*self.value)
