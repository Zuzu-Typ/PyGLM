from ..detail.setup import pyglmCompareType
from ..detail._noise import *
from ..detail.func_geometric import *
from ..detail.func_common import *
from ..detail.func_vector_relational import *
from ..detail.type_vec2 import *
from ..detail.type_vec3 import *
from ..detail.type_vec4 import *

def grad4(j, ip):
	pXYZ = floor(fract(tvec3(j) * tvec3(ip)) * 7.) *ip[2] - 1.
	pW = (1.5) - dot(abs(pXYZ), tvec3(1))
	s = tvec4(lessThan(tvec4(pXYZ, pW), tvec4(0.0)))
	pXYZ = pXYZ + (tvec3(s) * (2.) - (1.)) * s.w
	return tvec4(pXYZ, pW)

def perlin(Position, rep = None):
	if rep:
		if pyglmCompareType(Position, tvec2):
			Pi = floor(tvec4(Position.x, Position.y, Position.x, Position.y)) + tvec4(0.0, 0.0, 1.0, 1.0)
			Pf = fract(tvec4(Position.x, Position.y, Position.x, Position.y)) - tvec4(0.0, 0.0, 1.0, 1.0)
			Pi = mod(Pi, tvec4(rep.x, rep.y, rep.x, rep.y)) # o create noise with explicit period
			Pi = mod(Pi, tvec4(289)) # o avoid truncation effects in permutation
			ix = tvec4(Pi.x, Pi.z, Pi.x, Pi.z)
			iy = tvec4(Pi.y, Pi.y, Pi.w, Pi.w)
			fx = tvec4(Pf.x, Pf.z, Pf.x, Pf.z)
			fy = tvec4(Pf.y, Pf.y, Pf.w, Pf.w)

			i = permute(permute(ix) + iy)

			gx = (2.) * fract(i / (41.)) - (1.)
			gy = abs(gx) - (0.5)
			tx = floor(gx + (0.5))
			gx = gx - tx

			g00 = tvec2(gx.x, gy.x)
			g10 = tvec2(gx.y, gy.y)
			g01 = tvec2(gx.z, gy.z)
			g11 = tvec2(gx.w, gy.w)

			norm = taylorInvSqrt(tvec4(dot(g00, g00), dot(g01, g01), dot(g10, g10), dot(g11, g11)))
			g00 *= norm.x
			g01 *= norm.y
			g10 *= norm.z
			g11 *= norm.w

			n00 = dot(g00, tvec2(fx.x, fy.x))
			n10 = dot(g10, tvec2(fx.y, fy.y))
			n01 = dot(g01, tvec2(fx.z, fy.z))
			n11 = dot(g11, tvec2(fx.w, fy.w))

			fade_xy = fade(tvec2(Pf.x, Pf.y))
			n_x = mix(tvec2(n00, n01), tvec2(n10, n11), fade_xy.x)
			n_xy = mix(n_x.x, n_x.y, fade_xy.y)
			return (2.3) * n_xy

		if pyglmCompareType(Position, tvec3):
			Pi0 = mod(floor(Position), rep) # Integer part, modulo period
			Pi1 = mod(Pi0 + tvec3((1)), rep) # Integer part + 1, mod period
			Pi0 = mod(Pi0, tvec3(289))
			Pi1 = mod(Pi1, tvec3(289))
			Pf0 = fract(Position) # Fractional part for interpolation
			Pf1 = Pf0 - tvec3((1)) # Fractional part - 1.0
			ix = tvec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x)
			iy = tvec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y)
			iz0 = tvec4(Pi0.z)
			iz1 = tvec4(Pi1.z)

			ixy = permute(permute(ix) + iy)
			ixy0 = permute(ixy + iz0)
			ixy1 = permute(ixy + iz1)

			gx0 = ixy0 / (7.)
			gy0 = fract(floor(gx0) / (7.)) - (0.5)
			gx0 = fract(gx0)
			gz0 = tvec4(0.5) - abs(gx0) - abs(gy0)
			sz0 = step(gz0, tvec4(0.))
			gx0 -= sz0 * (step(tvec4(0.), gx0) - (0.5))
			gy0 -= sz0 * (step(tvec4(0.), gy0) - (0.5))

			gx1 = ixy1 / (7.)
			gy1 = fract(floor(gx1) / (7.)) - (0.5)
			gx1 = fract(gx1)
			gz1 = tvec4(0.5) - abs(gx1) - abs(gy1)
			sz1 = step(gz1, tvec4((0.)))
			gx1 -= sz1 * (step(tvec4(0.), gx1) - (0.5))
			gy1 -= sz1 * (step(tvec4(0.), gy1) - (0.5))

			g000 = tvec3(gx0.x, gy0.x, gz0.x)
			g100 = tvec3(gx0.y, gy0.y, gz0.y)
			g010 = tvec3(gx0.z, gy0.z, gz0.z)
			g110 = tvec3(gx0.w, gy0.w, gz0.w)
			g001 = tvec3(gx1.x, gy1.x, gz1.x)
			g101 = tvec3(gx1.y, gy1.y, gz1.y)
			g011 = tvec3(gx1.z, gy1.z, gz1.z)
			g111 = tvec3(gx1.w, gy1.w, gz1.w)

			norm0 = taylorInvSqrt(tvec4(dot(g000, g000), dot(g010, g010), dot(g100, g100), dot(g110, g110)))
			g000 *= norm0.x
			g010 *= norm0.y
			g100 *= norm0.z
			g110 *= norm0.w
			norm1 = taylorInvSqrt(tvec4(dot(g001, g001), dot(g011, g011), dot(g101, g101), dot(g111, g111)))
			g001 *= norm1.x
			g011 *= norm1.y
			g101 *= norm1.z
			g111 *= norm1.w

			n000 = dot(g000, Pf0)
			n100 = dot(g100, tvec3(Pf1.x, Pf0.y, Pf0.z))
			n010 = dot(g010, tvec3(Pf0.x, Pf1.y, Pf0.z))
			n110 = dot(g110, tvec3(Pf1.x, Pf1.y, Pf0.z))
			n001 = dot(g001, tvec3(Pf0.x, Pf0.y, Pf1.z))
			n101 = dot(g101, tvec3(Pf1.x, Pf0.y, Pf1.z))
			n011 = dot(g011, tvec3(Pf0.x, Pf1.y, Pf1.z))
			n111 = dot(g111, Pf1)

			fade_xyz = fade(Pf0)
			n_z = mix(tvec4(n000, n100, n010, n110), tvec4(n001, n101, n011, n111), fade_xyz.z)
			n_yz = mix(tvec2(n_z.x, n_z.y), tvec2(n_z.z, n_z.w), fade_xyz.y)
			n_xyz = mix(n_yz.x, n_yz.y, fade_xyz.x)
			return (2.2) * n_xyz

		if pyglmCompareType(Position, tvec4):
			Pi0 = mod(floor(Position), rep) # Integer part modulo rep
			Pi1 = mod(Pi0 + (1.), rep) # Integer part + 1 mod rep
			Pf0 = fract(Position) # Fractional part for interpolation
			Pf1 = Pf0 - (1.) # Fractional part - 1.0
			ix = tvec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x)
			iy = tvec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y)
			iz0 = tvec4(Pi0.z)
			iz1 = tvec4(Pi1.z)
			iw0 = tvec4(Pi0.w)
			iw1 = tvec4(Pi1.w)

			ixy = permute(permute(ix) + iy)
			ixy0 = permute(ixy + iz0)
			ixy1 = permute(ixy + iz1)
			ixy00 = permute(ixy0 + iw0)
			ixy01 = permute(ixy0 + iw1)
			ixy10 = permute(ixy1 + iw0)
			ixy11 = permute(ixy1 + iw1)

			gx00 = ixy00 / (7.)
			gy00 = floor(gx00) / (7.)
			gz00 = floor(gy00) / (6.)
			gx00 = fract(gx00) - (0.5)
			gy00 = fract(gy00) - (0.5)
			gz00 = fract(gz00) - (0.5)
			gw00 = tvec4(0.75) - abs(gx00) - abs(gy00) - abs(gz00)
			sw00 = step(gw00, tvec4(0.))
			gx00 -= sw00 * (step(tvec4(0), gx00) - (0.5))
			gy00 -= sw00 * (step(tvec4(0), gy00) - (0.5))

			gx01 = ixy01 / (7.)
			gy01 = floor(gx01) / (7.)
			gz01 = floor(gy01) / (6.)
			gx01 = fract(gx01) - (0.5)
			gy01 = fract(gy01) - (0.5)
			gz01 = fract(gz01) - (0.5)
			gw01 = tvec4(0.75) - abs(gx01) - abs(gy01) - abs(gz01)
			sw01 = step(gw01, tvec4(0.0))
			gx01 -= sw01 * (step(tvec4(0.), gx01) - (0.5))
			gy01 -= sw01 * (step(tvec4(0.), gy01) - (0.5))

			gx10 = ixy10 / (7.)
			gy10 = floor(gx10) / (7.)
			gz10 = floor(gy10) / (6.)
			gx10 = fract(gx10) - (0.5)
			gy10 = fract(gy10) - (0.5)
			gz10 = fract(gz10) - (0.5)
			gw10 = tvec4(0.75) - abs(gx10) - abs(gy10) - abs(gz10)
			sw10 = step(gw10, tvec4(0.0))
			gx10 -= sw10 * (step(tvec4(0.), gx10) - (0.5))
			gy10 -= sw10 * (step(tvec4(0.), gy10) - (0.5))

			gx11 = ixy11 / (7.)
			gy11 = floor(gx11) / (7.)
			gz11 = floor(gy11) / (6.)
			gx11 = fract(gx11) - (0.5)
			gy11 = fract(gy11) - (0.5)
			gz11 = fract(gz11) - (0.5)
			gw11 = tvec4(0.75) - abs(gx11) - abs(gy11) - abs(gz11)
			sw11 = step(gw11, tvec4((0.)))
			gx11 -= sw11 * (step(tvec4(0.), gx11) - (0.5))
			gy11 -= sw11 * (step(tvec4(0.), gy11) - (0.5))

			g0000 = tvec4(gx00.x, gy00.x, gz00.x, gw00.x)
			g1000 = tvec4(gx00.y, gy00.y, gz00.y, gw00.y)
			g0100 = tvec4(gx00.z, gy00.z, gz00.z, gw00.z)
			g1100 = tvec4(gx00.w, gy00.w, gz00.w, gw00.w)
			g0010 = tvec4(gx10.x, gy10.x, gz10.x, gw10.x)
			g1010 = tvec4(gx10.y, gy10.y, gz10.y, gw10.y)
			g0110 = tvec4(gx10.z, gy10.z, gz10.z, gw10.z)
			g1110 = tvec4(gx10.w, gy10.w, gz10.w, gw10.w)
			g0001 = tvec4(gx01.x, gy01.x, gz01.x, gw01.x)
			g1001 = tvec4(gx01.y, gy01.y, gz01.y, gw01.y)
			g0101 = tvec4(gx01.z, gy01.z, gz01.z, gw01.z)
			g1101 = tvec4(gx01.w, gy01.w, gz01.w, gw01.w)
			g0011 = tvec4(gx11.x, gy11.x, gz11.x, gw11.x)
			g1011 = tvec4(gx11.y, gy11.y, gz11.y, gw11.y)
			g0111 = tvec4(gx11.z, gy11.z, gz11.z, gw11.z)
			g1111 = tvec4(gx11.w, gy11.w, gz11.w, gw11.w)

			norm00 = taylorInvSqrt(tvec4(dot(g0000, g0000), dot(g0100, g0100), dot(g1000, g1000), dot(g1100, g1100)))
			g0000 *= norm00.x
			g0100 *= norm00.y
			g1000 *= norm00.z
			g1100 *= norm00.w

			norm01 = taylorInvSqrt(tvec4(dot(g0001, g0001), dot(g0101, g0101), dot(g1001, g1001), dot(g1101, g1101)))
			g0001 *= norm01.x
			g0101 *= norm01.y
			g1001 *= norm01.z
			g1101 *= norm01.w

			norm10 = taylorInvSqrt(tvec4(dot(g0010, g0010), dot(g0110, g0110), dot(g1010, g1010), dot(g1110, g1110)))
			g0010 *= norm10.x
			g0110 *= norm10.y
			g1010 *= norm10.z
			g1110 *= norm10.w

			norm11 = taylorInvSqrt(tvec4(dot(g0011, g0011), dot(g0111, g0111), dot(g1011, g1011), dot(g1111, g1111)))
			g0011 *= norm11.x
			g0111 *= norm11.y
			g1011 *= norm11.z
			g1111 *= norm11.w

			n0000 = dot(g0000, Pf0)
			n1000 = dot(g1000, tvec4(Pf1.x, Pf0.y, Pf0.z, Pf0.w))
			n0100 = dot(g0100, tvec4(Pf0.x, Pf1.y, Pf0.z, Pf0.w))
			n1100 = dot(g1100, tvec4(Pf1.x, Pf1.y, Pf0.z, Pf0.w))
			n0010 = dot(g0010, tvec4(Pf0.x, Pf0.y, Pf1.z, Pf0.w))
			n1010 = dot(g1010, tvec4(Pf1.x, Pf0.y, Pf1.z, Pf0.w))
			n0110 = dot(g0110, tvec4(Pf0.x, Pf1.y, Pf1.z, Pf0.w))
			n1110 = dot(g1110, tvec4(Pf1.x, Pf1.y, Pf1.z, Pf0.w))
			n0001 = dot(g0001, tvec4(Pf0.x, Pf0.y, Pf0.z, Pf1.w))
			n1001 = dot(g1001, tvec4(Pf1.x, Pf0.y, Pf0.z, Pf1.w))
			n0101 = dot(g0101, tvec4(Pf0.x, Pf1.y, Pf0.z, Pf1.w))
			n1101 = dot(g1101, tvec4(Pf1.x, Pf1.y, Pf0.z, Pf1.w))
			n0011 = dot(g0011, tvec4(Pf0.x, Pf0.y, Pf1.z, Pf1.w))
			n1011 = dot(g1011, tvec4(Pf1.x, Pf0.y, Pf1.z, Pf1.w))
			n0111 = dot(g0111, tvec4(Pf0.x, Pf1.y, Pf1.z, Pf1.w))
			n1111 = dot(g1111, Pf1)

			fade_xyzw = fade(Pf0)
			n_0w = mix(tvec4(n0000, n1000, n0100, n1100), tvec4(n0001, n1001, n0101, n1101), fade_xyzw.w)
			n_1w = mix(tvec4(n0010, n1010, n0110, n1110), tvec4(n0011, n1011, n0111, n1111), fade_xyzw.w)
			n_zw = mix(n_0w, n_1w, fade_xyzw.z)
			n_yzw = mix(tvec2(n_zw.x, n_zw.y), tvec2(n_zw.z, n_zw.w), fade_xyzw.y)
			n_xyzw = mix(n_yzw.x, n_yzw.y, fade_xyzw.x)
			return (2.2) * n_xyzw

	if pyglmCompareType(Position, tvec2):
		Pi = floor(tvec4(Position.x, Position.y, Position.x, Position.y)) + tvec4(0.0, 0.0, 1.0, 1.0)
		Pf = fract(tvec4(Position.x, Position.y, Position.x, Position.y)) - tvec4(0.0, 0.0, 1.0, 1.0)
		Pi = mod(Pi, tvec4(289)) # To avoid truncation effects in permutation
		ix = tvec4(Pi.x, Pi.z, Pi.x, Pi.z)
		iy = tvec4(Pi.y, Pi.y, Pi.w, Pi.w)
		fx = tvec4(Pf.x, Pf.z, Pf.x, Pf.z)
		fy = tvec4(Pf.y, Pf.y, Pf.w, Pf.w)

		i = permute(permute(ix) + iy)

		gx = (2.) * fract(i / (41.)) - (1.)
		gy = abs(gx) - (0.5)
		tx = floor(gx + (0.5))
		gx = gx - tx

		g00 = tvec2(gx.x, gy.x)
		g10 = tvec2(gx.y, gy.y)
		g01 = tvec2(gx.z, gy.z)
		g11 = tvec2(gx.w, gy.w)

		norm = taylorInvSqrt(tvec4(dot(g00, g00), dot(g01, g01), dot(g10, g10), dot(g11, g11)))
		g00 *= norm.x
		g01 *= norm.y
		g10 *= norm.z
		g11 *= norm.w

		n00 = dot(g00, tvec2(fx.x, fy.x))
		n10 = dot(g10, tvec2(fx.y, fy.y))
		n01 = dot(g01, tvec2(fx.z, fy.z))
		n11 = dot(g11, tvec2(fx.w, fy.w))

		fade_xy = fade(tvec2(Pf.x, Pf.y))
		n_x = mix(tvec2(n00, n01), tvec2(n10, n11), fade_xy.x)
		n_xy = mix(n_x.x, n_x.y, fade_xy.y)
		return (2.3) * n_xy

	elif pyglmCompareType(Position, tvec3):
		Pi0 = floor(Position) # Integer part for indexing
		Pi1 = Pi0 + (1.) # Integer part + 1
		Pi0 = mod289(Pi0)
		Pi1 = mod289(Pi1)
		Pf0 = fract(Position) # Fractional part for interpolation
		Pf1 = Pf0 - (1.) # Fractional part - 1.0
		ix = tvec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x)
		iy = tvec4(tvec2(Pi0.y), tvec2(Pi1.y))
		iz0 = tvec4(Pi0.z)
		iz1 = tvec4(Pi1.z)

		ixy = permute(permute(ix) + iy)
		ixy0 = permute(ixy + iz0)
		ixy1 = permute(ixy + iz1)

		gx0 = ixy0 * (1.0 / 7.0)
		gy0 = fract(floor(gx0) * (1.0 / 7.0)) - (0.5)
		gx0 = fract(gx0)
		gz0 = tvec4(0.5) - abs(gx0) - abs(gy0)
		sz0 = step(gz0, tvec4(0.0))
		gx0 -= sz0 * (step(tvec4(0.), gx0) - (0.5))
		gy0 -= sz0 * (step(tvec4(0.), gy0) - (0.5))

		gx1 = ixy1 * (1.0 / 7.0)
		gy1 = fract(floor(gx1) * (1.0 / 7.0)) - (0.5)
		gx1 = fract(gx1)
		gz1 = tvec4(0.5) - abs(gx1) - abs(gy1)
		sz1 = step(gz1, tvec4(0.0))
		gx1 -= sz1 * (step(tvec4(0.), gx1) - (0.5))
		gy1 -= sz1 * (step(tvec4(0.), gy1) - (0.5))

		g000 = tvec3(gx0.x, gy0.x, gz0.x)
		g100 = tvec3(gx0.y, gy0.y, gz0.y)
		g010 = tvec3(gx0.z, gy0.z, gz0.z)
		g110 = tvec3(gx0.w, gy0.w, gz0.w)
		g001 = tvec3(gx1.x, gy1.x, gz1.x)
		g101 = tvec3(gx1.y, gy1.y, gz1.y)
		g011 = tvec3(gx1.z, gy1.z, gz1.z)
		g111 = tvec3(gx1.w, gy1.w, gz1.w)

		norm0 = taylorInvSqrt(tvec4(dot(g000, g000), dot(g010, g010), dot(g100, g100), dot(g110, g110)))
		g000 *= norm0.x
		g010 *= norm0.y
		g100 *= norm0.z
		g110 *= norm0.w
		norm1 = taylorInvSqrt(tvec4(dot(g001, g001), dot(g011, g011), dot(g101, g101), dot(g111, g111)))
		g001 *= norm1.x
		g011 *= norm1.y
		g101 *= norm1.z
		g111 *= norm1.w

		n000 = dot(g000, Pf0)
		n100 = dot(g100, tvec3(Pf1.x, Pf0.y, Pf0.z))
		n010 = dot(g010, tvec3(Pf0.x, Pf1.y, Pf0.z))
		n110 = dot(g110, tvec3(Pf1.x, Pf1.y, Pf0.z))
		n001 = dot(g001, tvec3(Pf0.x, Pf0.y, Pf1.z))
		n101 = dot(g101, tvec3(Pf1.x, Pf0.y, Pf1.z))
		n011 = dot(g011, tvec3(Pf0.x, Pf1.y, Pf1.z))
		n111 = dot(g111, Pf1)

		fade_xyz = fade(Pf0)
		n_z = mix(tvec4(n000, n100, n010, n110), tvec4(n001, n101, n011, n111), fade_xyz.z)
		n_yz = mix(tvec2(n_z.x, n_z.y), tvec2(n_z.z, n_z.w), fade_xyz.y)
		n_xyz = mix(n_yz.x, n_yz.y, fade_xyz.x)
		return (2.2) * n_xyz

	elif pyglmCompareType(Position, tvec4):
		Pi0 = floor(Position)	# Integer part for indexing
		Pi1 = Pi0 + (1.)		# Integer part + 1
		Pi0 = mod(Pi0, tvec4(289))
		Pi1 = mod(Pi1, tvec4(289))
		Pf0 = fract(Position)	# Fractional part for interpolation
		Pf1 = Pf0 - (1.)		# Fractional part - 1.0
		ix = tvec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x)
		iy = tvec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y)
		iz0 = tvec4(Pi0.z)
		iz1 = tvec4(Pi1.z)
		iw0 = tvec4(Pi0.w)
		iw1 = tvec4(Pi1.w)

		ixy = permute(permute(ix) + iy)
		ixy0 = permute(ixy + iz0)
		ixy1 = permute(ixy + iz1)
		ixy00 = permute(ixy0 + iw0)
		ixy01 = permute(ixy0 + iw1)
		ixy10 = permute(ixy1 + iw0)
		ixy11 = permute(ixy1 + iw1)

		gx00 = ixy00 / (7.)
		gy00 = floor(gx00) / (7.)
		gz00 = floor(gy00) / (6.)
		gx00 = fract(gx00) - (0.5)
		gy00 = fract(gy00) - (0.5)
		gz00 = fract(gz00) - (0.5)
		gw00 = tvec4(0.75) - abs(gx00) - abs(gy00) - abs(gz00)
		sw00 = step(gw00, tvec4(0.0))
		gx00 -= sw00 * (step(tvec4(0.), gx00) - (0.5))
		gy00 -= sw00 * (step(tvec4(0.), gy00) - (0.5))

		gx01 = ixy01 / (7.)
		gy01 = floor(gx01) / (7.)
		gz01 = floor(gy01) / (6.)
		gx01 = fract(gx01) - (0.5)
		gy01 = fract(gy01) - (0.5)
		gz01 = fract(gz01) - (0.5)
		gw01 = tvec4(0.75) - abs(gx01) - abs(gy01) - abs(gz01)
		sw01 = step(gw01, tvec4(0.0))
		gx01 -= sw01 * (step(tvec4(0.), gx01) - (0.5))
		gy01 -= sw01 * (step(tvec4(0.), gy01) - (0.5))

		gx10 = ixy10 / (7.)
		gy10 = floor(gx10) / (7.)
		gz10 = floor(gy10) / (6.)
		gx10 = fract(gx10) - (0.5)
		gy10 = fract(gy10) - (0.5)
		gz10 = fract(gz10) - (0.5)
		gw10 = tvec4(0.75) - abs(gx10) - abs(gy10) - abs(gz10)
		sw10 = step(gw10, tvec4(0))
		gx10 -= sw10 * (step(tvec4(0.), gx10) - (0.5))
		gy10 -= sw10 * (step(tvec4(0.), gy10) - (0.5))

		gx11 = ixy11 / (7.)
		gy11 = floor(gx11) / (7.)
		gz11 = floor(gy11) / (6.)
		gx11 = fract(gx11) - (0.5)
		gy11 = fract(gy11) - (0.5)
		gz11 = fract(gz11) - (0.5)
		gw11 = tvec4(0.75) - abs(gx11) - abs(gy11) - abs(gz11)
		sw11 = step(gw11, tvec4(0.0))
		gx11 -= sw11 * (step(tvec4(0.), gx11) - (0.5))
		gy11 -= sw11 * (step(tvec4(0.), gy11) - (0.5))

		g0000 = tvec4(gx00.x, gy00.x, gz00.x, gw00.x)
		g1000 = tvec4(gx00.y, gy00.y, gz00.y, gw00.y)
		g0100 = tvec4(gx00.z, gy00.z, gz00.z, gw00.z)
		g1100 = tvec4(gx00.w, gy00.w, gz00.w, gw00.w)
		g0010 = tvec4(gx10.x, gy10.x, gz10.x, gw10.x)
		g1010 = tvec4(gx10.y, gy10.y, gz10.y, gw10.y)
		g0110 = tvec4(gx10.z, gy10.z, gz10.z, gw10.z)
		g1110 = tvec4(gx10.w, gy10.w, gz10.w, gw10.w)
		g0001 = tvec4(gx01.x, gy01.x, gz01.x, gw01.x)
		g1001 = tvec4(gx01.y, gy01.y, gz01.y, gw01.y)
		g0101 = tvec4(gx01.z, gy01.z, gz01.z, gw01.z)
		g1101 = tvec4(gx01.w, gy01.w, gz01.w, gw01.w)
		g0011 = tvec4(gx11.x, gy11.x, gz11.x, gw11.x)
		g1011 = tvec4(gx11.y, gy11.y, gz11.y, gw11.y)
		g0111 = tvec4(gx11.z, gy11.z, gz11.z, gw11.z)
		g1111 = tvec4(gx11.w, gy11.w, gz11.w, gw11.w)

		norm00 = taylorInvSqrt(tvec4(dot(g0000, g0000), dot(g0100, g0100), dot(g1000, g1000), dot(g1100, g1100)))
		g0000 *= norm00.x
		g0100 *= norm00.y
		g1000 *= norm00.z
		g1100 *= norm00.w

		norm01 = taylorInvSqrt(tvec4(dot(g0001, g0001), dot(g0101, g0101), dot(g1001, g1001), dot(g1101, g1101)))
		g0001 *= norm01.x
		g0101 *= norm01.y
		g1001 *= norm01.z
		g1101 *= norm01.w

		norm10 = taylorInvSqrt(tvec4(dot(g0010, g0010), dot(g0110, g0110), dot(g1010, g1010), dot(g1110, g1110)))
		g0010 *= norm10.x
		g0110 *= norm10.y
		g1010 *= norm10.z
		g1110 *= norm10.w

		norm11 = taylorInvSqrt(tvec4(dot(g0011, g0011), dot(g0111, g0111), dot(g1011, g1011), dot(g1111, g1111)))
		g0011 *= norm11.x
		g0111 *= norm11.y
		g1011 *= norm11.z
		g1111 *= norm11.w

		n0000 = dot(g0000, Pf0)
		n1000 = dot(g1000, tvec4(Pf1.x, Pf0.y, Pf0.z, Pf0.w))
		n0100 = dot(g0100, tvec4(Pf0.x, Pf1.y, Pf0.z, Pf0.w))
		n1100 = dot(g1100, tvec4(Pf1.x, Pf1.y, Pf0.z, Pf0.w))
		n0010 = dot(g0010, tvec4(Pf0.x, Pf0.y, Pf1.z, Pf0.w))
		n1010 = dot(g1010, tvec4(Pf1.x, Pf0.y, Pf1.z, Pf0.w))
		n0110 = dot(g0110, tvec4(Pf0.x, Pf1.y, Pf1.z, Pf0.w))
		n1110 = dot(g1110, tvec4(Pf1.x, Pf1.y, Pf1.z, Pf0.w))
		n0001 = dot(g0001, tvec4(Pf0.x, Pf0.y, Pf0.z, Pf1.w))
		n1001 = dot(g1001, tvec4(Pf1.x, Pf0.y, Pf0.z, Pf1.w))
		n0101 = dot(g0101, tvec4(Pf0.x, Pf1.y, Pf0.z, Pf1.w))
		n1101 = dot(g1101, tvec4(Pf1.x, Pf1.y, Pf0.z, Pf1.w))
		n0011 = dot(g0011, tvec4(Pf0.x, Pf0.y, Pf1.z, Pf1.w))
		n1011 = dot(g1011, tvec4(Pf1.x, Pf0.y, Pf1.z, Pf1.w))
		n0111 = dot(g0111, tvec4(Pf0.x, Pf1.y, Pf1.z, Pf1.w))
		n1111 = dot(g1111, Pf1)

		fade_xyzw = fade(Pf0)
		n_0w = mix(tvec4(n0000, n1000, n0100, n1100), tvec4(n0001, n1001, n0101, n1101), fade_xyzw.w)
		n_1w = mix(tvec4(n0010, n1010, n0110, n1110), tvec4(n0011, n1011, n0111, n1111), fade_xyzw.w)
		n_zw = mix(n_0w, n_1w, fade_xyzw.z)
		n_yzw = mix(tvec2(n_zw.x, n_zw.y), tvec2(n_zw.z, n_zw.w), fade_xyzw.y)
		n_xyzw = mix(n_yzw.x, n_yzw.y, fade_xyzw.x)
		return (2.2) * n_xyzw

def simplex(v):
	if pyglmCompareType(v, tvec2):
		C = tvec4(
			( 0.211324865405187),  # (3.0 -  sqrt(3.0)) / 6.0
			( 0.366025403784439),  #  0.5 * (sqrt(3.0)  - 1.0)
			(-0.577350269189626),	# -1.0 + 2.0 * C.x
			( 0.024390243902439)) #  1.0 / 41.0

		# First corner
		i  = floor(v + dot(v, tvec2(C[1])))
		x0 = v -   i + dot(i, tvec2(C[0]))

		# Other corners
		#i1.x = step( x0.y, x0.x ) # x0.x > x0.y ? 1.0 : 0.0
		#i1.y = 1.0 - i1.x
		i1 = tvec2(1, 0) if (x0.x > x0.y) else tvec2(0, 1)
		# x0 = x0 - 0.0 + 0.0 * C.xx 
		# x1 = x0 - i1 + 1.0 * C.xx 
		# x2 = x0 - 1.0 + 2.0 * C.xx 
		x12 = tvec4(x0.x, x0.y, x0.x, x0.y) + tvec4(C.x, C.x, C.z, C.z)
		x12 = tvec4(tvec2(x12) - i1, x12.z, x12.w)

		# Permutations
		i = mod(i, tvec2(289.)) # Avoid truncation effects in permutation
		p = permute(
			permute(i.y + tvec3((0.), i1.y, (1.)))
			+ i.x + tvec3((0.), i1.x, (1.)))

		m = max(tvec3(0.5) - tvec3(
			dot(x0, x0),
			dot(tvec2(x12.x, x12.y), tvec2(x12.x, x12.y)), 
			dot(tvec2(x12.z, x12.w), tvec2(x12.z, x12.w))), tvec3(0))
		m = m * m 
		m = m * m 

		# Gradients: 41 points uniformly over a line, mapped onto a diamond.
		# he ring size 17*17 = 289 is close to a multiple of 41 (41*7 = 287)

		x = (2.) * fract(p * C.w) - (1.)
		h = abs(x) - (0.5)
		ox = floor(x + (0.5))
		a0 = x - ox

		# Normalise gradients implicitly by scaling m
		# Inlined for speed: m *= taylorInvSqrt( a0*a0 + h*h )
		m *= (1.79284291400159) - (0.85373472095314) * (a0 * a0 + h * h)

		# Compute final noise value at P
		g = tvec3()
		g.x  = a0.x  * x0.x  + h.x  * x0.y
		#g.yz = a0.yz * x12.xz + h.yz * x12.yw
		g.y = a0.y * x12.x + h.y * x12.y
		g.z = a0.z * x12.z + h.z * x12.w
		return (130.) * dot(m, g)

	elif pyglmCompareType(v, tvec3):
		C = tvec2(1.0 / 6.0, 1.0 / 3.0)
		D = tvec4(0.0, 0.5, 1.0, 2.0)

		# First corner
		i = tvec3(floor(v + dot(v, tvec3(C.y))))
		x0 = tvec3(v - i + dot(i, tvec3(C.x)))

		# Other corners
		g = tvec3(step(tvec3(x0.y, x0.z, x0.x), x0))
		l = tvec3((1.) - g)
		i1 = tvec3(min(g, tvec3(l.z, l.x, l.y)))
		i2 = tvec3(max(g, tvec3(l.z, l.x, l.y)))

		#   x0 = x0 - 0.0 + 0.0 * C.xxx
		#   x1 = x0 - i1  + 1.0 * C.xxx
		#   x2 = x0 - i2  + 2.0 * C.xxx
		#   x3 = x0 - 1.0 + 3.0 * C.xxx
		x1 = tvec3(x0 - i1 + C.x)
		x2 = tvec3(x0 - i2 + C.y) # 2.0*C.x = 1/3 = C.y
		x3 = tvec3(x0 - D.y)      # -1.0+3.0*C.x = -0.5 = -D.y

		# Permutations
		i = mod289(i)
		p = tvec4(permute(permute(permute(
			i.z + tvec4((0.), i1.z, i2.z, (1.))) +
			i.y + tvec4((0.), i1.y, i2.y, (1.))) +
			i.x + tvec4((0.), i1.x, i2.x, (1.))))

		# Gradients: 7x7 points over a square, mapped onto an octahedron.
		# he ring size 17*17 = 289 is close to a multiple of 49 (49*6 = 294)
		n_ = (0.142857142857) # 1.0/7.0
		ns = tvec3(n_ * tvec3(D.w, D.y, D.z) - tvec3(D.x, D.z, D.x))

		j = tvec4(p - (49.) * floor(p * ns.z * ns.z))  #  mod(p,7*7)

		x_ = tvec4(floor(j * ns.z))
		y_ = tvec4(floor(j - (7.) * x_))    # mod(j,N)

		x = tvec4(x_ * ns.x + ns.y)
		y = tvec4(y_ * ns.x + ns.y)
		h = tvec4((1.) - abs(x) - abs(y))

		b0 = tvec4(x.x, x.y, y.x, y.y)
		b1 = tvec4(x.z, x.w, y.z, y.w)

		# vec4 s0 = vec4(lesshan(b0,0.0))*2.0 - 1.0
		# vec4 s1 = vec4(lesshan(b1,0.0))*2.0 - 1.0
		s0 = tvec4(floor(b0) * (2.) + (1.))
		s1 = tvec4(floor(b1) * (2.) + (1.))
		sh = tvec4(-step(h, tvec4(0.0)))

		a0 = tvec4(b0.x, b0.z, b0.y, b0.w) + tvec4(s0.x, s0.z, s0.y, s0.w) * tvec4(sh.x, sh.x, sh.y, sh.y)
		a1 = tvec4(b1.x, b1.z, b1.y, b1.w) + tvec4(s1.x, s1.z, s1.y, s1.w) * tvec4(sh.z, sh.z, sh.w, sh.w)

		p0 = tvec3(a0.x, a0.y, h.x)
		p1 = tvec3(a0.z, a0.w, h.y)
		p2 = tvec3(a1.x, a1.y, h.z)
		p3 = tvec3(a1.z, a1.w, h.w)

		# Normalise gradients
		norm = taylorInvSqrt(tvec4(dot(p0, p0), dot(p1, p1), dot(p2, p2), dot(p3, p3)))
		p0 *= norm.x
		p1 *= norm.y
		p2 *= norm.z
		p3 *= norm.w

		# Mix final noise value
		m = max((0.6) - tvec4(dot(x0, x0), dot(x1, x1), dot(x2, x2), dot(x3, x3)), tvec4(0.))
		m = m * m
		return (42.) * dot(m * m, tvec4(dot(p0, x0), dot(p1, x1), dot(p2, x2), dot(p3, x3)))

	elif pyglmCompareType(v, tvec4):
		C = tvec4(
			0.138196601125011,  # (5 - sqrt(5))/20  G4
			0.276393202250021,  # 2 * G4
			0.414589803375032,  # 3 * G4
			-0.447213595499958) # -1 + 4 * G4

		# (sqrt(5) - 1)/4 = F4, used once below
		F4 = (0.309016994374947451)

		# First corner
		i  = floor(v + dot(v, tvec4(F4)))
		x0 = v -   i + dot(i, tvec4(C.x))

		# Other corners

		# Rank sorting originally contributed by Bill Licea-Kane, AMD (formerly AI)
		isX = step(tvec3(x0.y, x0.z, x0.w), tvec3(x0.x))
		isYZ = step(tvec3(x0.z, x0.w, x0.w), tvec3(x0.y, x0.y, x0.z))
		#  i0.x = dot(isX, vec3(1.0))
		#i0.x = isX.x + isX.y + isX.z
		#i0.yzw = static_cast<>(1) - isX
		i0 = tvec4(isX.x + isX.y + isX.z, (1.) - isX)
		#  i0.y += dot(isYZ.xy, vec2(1.0))
		i0.y += isYZ.x + isYZ.y
		#i0.zw += 1.0 - tvec2(isYZ.x, isYZ.y)
		i0.z += (1.) - isYZ.x
		i0.w += (1.) - isYZ.y
		i0.z += isYZ.z
		i0.w += (1.) - isYZ.z

		# i0 now contains the unique values 0,1,2,3 in each channel
		i3 = clamp(i0, (0.), (1.))
		i2 = clamp(i0 - (1.), (0.), (1.))
		i1 = clamp(i0 - (2.), (0.), (1.))

		#  x0 = x0 - 0.0 + 0.0 * C.xxxx
		#  x1 = x0 - i1  + 0.0 * C.xxxx
		#  x2 = x0 - i2  + 0.0 * C.xxxx
		#  x3 = x0 - i3  + 0.0 * C.xxxx
		#  x4 = x0 - 1.0 + 4.0 * C.xxxx
		x1 = x0 - i1 + C.x
		x2 = x0 - i2 + C.y
		x3 = x0 - i3 + C.z
		x4 = x0 + C.w

		# Permutations
		i = mod(i, tvec4(289.)) 
		j0 = permute(permute(permute(permute(i.w) + i.z) + i.y) + i.x)
		j1 = permute(permute(permute(permute(
			i.w + tvec4(i1.w, i2.w, i3.w, (1.))) +
			i.z + tvec4(i1.z, i2.z, i3.z, (1.))) +
			i.y + tvec4(i1.y, i2.y, i3.y, (1.))) +
			i.x + tvec4(i1.x, i2.x, i3.x, (1.)))

		# Gradients: 7x7x6 points over a cube, mapped onto a 4-cross polytope
		# 7*7*6 = 294, which is close to the ring size 17*17 = 289.
		ip = tvec4((1.) / (294.), (1.) / (49.), (1.) / (7.), (0.))

		p0 = grad4(j0,   ip)
		p1 = grad4(j1.x, ip)
		p2 = grad4(j1.y, ip)
		p3 = grad4(j1.z, ip)
		p4 = grad4(j1.w, ip)

		# Normalise gradients
		norm = taylorInvSqrt(tvec4(dot(p0, p0), dot(p1, p1), dot(p2, p2), dot(p3, p3)))
		p0 *= norm.x
		p1 *= norm.y
		p2 *= norm.z
		p3 *= norm.w
		p4 *= taylorInvSqrt(dot(p4, p4))

		# Mix contributions from the five corners
		m0 = max((0.6) - tvec3(dot(x0, x0), dot(x1, x1), dot(x2, x2)), tvec3(0.))
		m1 = max((0.6) - tvec2(dot(x3, x3), dot(x4, x4)             ), tvec2(0.))
		m0 = m0 * m0
		m1 = m1 * m1
		return (49.) * (dot(m0 * m0, tvec3(dot(p0, x0), dot(p1, x1), dot(p2, x2))) + dot(m1 * m1, tvec2(dot(p3, x3), dot(p4, x4))))