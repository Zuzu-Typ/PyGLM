// Based on the work of Stefan Gustavson and Ashima Arts on "webgl-noise": 
// https://github.com/ashima/webgl-noise 
// Following Stefan Gustavson's paper "Simplex noise demystified": 
// http://www.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf

//static ivec4* grad4p(double j, ivec4* ip) {
//	ivec3* pXYZ = to_ivec3p(
//		floor(fract(j * ip->x) * 7.0) * ip->z - 1.0,
//		floor(fract(j * ip->y) * 7.0) * ip->z - 1.0,
//		floor(fract(j * ip->z) * 7.0) * ip->z - 1.0);
//	double pW = 1.5 - idot3p(to_ivec3p(fabs(pXYZ->x), fabs(pXYZ->y), fabs(pXYZ->z)), to_ivec3dp(1));
//	ivec4* s = to_ivec4p((pXYZ->x < 0.0),(pXYZ->y < 0.0),(pXYZ->z < 0.0),(pW < 0.0));
//	pXYZ = addv3vp(pXYZ, mulv3dp((subv3dp(mulv3dp(to_ivec3p(s->x, s->y, s->z), (2.0)), (1.0))), s->w));
//	return to_ivec4p(pXYZ->x, pXYZ->y, pXYZ->z, pW);
//}
static ivec4 grad4(double j, ivec4 ip) {
	ivec3 pXYZ = to_ivec3(
		floor(fract(j * ip.x) * 7.0) * ip.z - 1.0,
		floor(fract(j * ip.y) * 7.0) * ip.z - 1.0,
		floor(fract(j * ip.z) * 7.0) * ip.z - 1.0);
	double pW = 1.5 - idot3(to_ivec3(fabs(pXYZ.x), fabs(pXYZ.y), fabs(pXYZ.z)), to_ivec3d(1));
	ivec4 s = to_ivec4((pXYZ.x < 0.0), (pXYZ.y < 0.0), (pXYZ.z < 0.0), (pW < 0.0));
	pXYZ = addv3v(pXYZ, mulv3d((subv3d(mulv3d(to_ivec3(s.x, s.y, s.z), (2.0)), (1.0))), s.w));
	return to_ivec4(pXYZ.x, pXYZ.y, pXYZ.z, pW);
}

static PyObject * grad4_(PyObject self, PyObject* args) {
	PyObject * arg1, *arg2;
	UNPACK_2_VARARGS(args, "grad4", arg1, arg2);
	if (!IS_NUMERIC(arg1)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for grad4(): ", arg1, arg2);
		return NULL;
	}
	ivec4 v;
	if (unpack_ivec4p(arg2, &v)) {
		return build_ivec4(grad4(pyvalue_as_double(arg1), v));
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for grad4(): ", arg1, arg2);
	return NULL;
}

static PyObject* perlin(PyObject* self, PyObject* args) {
	if (PyTuple_GET_SIZE(args) == 2) {
		PyObject *arg1, *arg2;
		UNPACK_2_VARARGS(args, "perlin", arg1, arg2);
		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			ivec2 o2;
			if (!unpack_ivec2p(arg2, &o2)) {
				PY_TYPEERROR_2O("unsupported operand type(s) for perlin(): ", arg1, arg2);
				return NULL;
			}
			ivec2 Position = *((ivec2*)o);
			ivec2 rep = o2;
			ivec4 Pi = to_ivec4(
				floor(Position.x),
				floor(Position.y),
				floor(Position.x) + 1.0,
				floor(Position.y) + 1.0);
			ivec4 Pf = to_ivec4(
				fract(Position.x),
				fract(Position.y),
				fract(Position.x) - 1.0,
				fract(Position.y) - 1.0);
			Pi = to_ivec4(
				imod(Pi.x, rep.x),
				imod(Pi.y, rep.y),
				imod(Pi.z, rep.x),
				imod(Pi.w, rep.y)); // To create noise with explicit period
			Pi = to_ivec4(
				imod(Pi.x, 289.),
				imod(Pi.y, 289.),
				imod(Pi.z, 289.),
				imod(Pi.w, 289.));
			ivec4 ix = to_ivec4(Pi.x, Pi.z, Pi.x, Pi.z);
			ivec4 iy = to_ivec4(Pi.y, Pi.y, Pi.w, Pi.w);
			ivec4 fx = to_ivec4(Pf.x, Pf.z, Pf.x, Pf.z);
			ivec4 fy = to_ivec4(Pf.y, Pf.y, Pf.w, Pf.w);

			ivec4 i = to_ivec4(
				permute_(permute_(ix.x) + iy.x),
				permute_(permute_(ix.y) + iy.y),
				permute_(permute_(ix.z) + iy.z),
				permute_(permute_(ix.w) + iy.w));

			ivec4 gx = to_ivec4(
				2.0 * fract(i.x / 41.0) - 1.0,
				2.0 * fract(i.y / 41.0) - 1.0,
				2.0 * fract(i.z / 41.0) - 1.0,
				2.0 * fract(i.w / 41.0) - 1.0);
			ivec4 gy = to_ivec4(
				fabs(gx.x) - (0.5),
				fabs(gx.y) - (0.5),
				fabs(gx.z) - (0.5),
				fabs(gx.w) - (0.5));
			ivec4 tx = to_ivec4(
				floor(gx.x + (0.5)),
				floor(gx.y + (0.5)),
				floor(gx.z + (0.5)),
				floor(gx.w + (0.5)));
			gx = subv4v(gx, tx);

			ivec2 g00 = to_ivec2(gx.x, gy.x);
			ivec2 g10 = to_ivec2(gx.y, gy.y);
			ivec2 g01 = to_ivec2(gx.z, gy.z);
			ivec2 g11 = to_ivec2(gx.w, gy.w);

			ivec4 norm = to_ivec4(
				taylorInvSqrt_(idot2(g00, g00)),
				taylorInvSqrt_(idot2(g01, g01)),
				taylorInvSqrt_(idot2(g10, g10)),
				taylorInvSqrt_(idot2(g11, g11)));
			g00 = mulv2d(g00, norm.x);
			g01 = mulv2d(g01, norm.y);
			g10 = mulv2d(g10, norm.z);
			g11 = mulv2d(g11, norm.w);

			double n00 = idot2(g00, to_ivec2(fx.x, fy.x));
			double n10 = idot2(g10, to_ivec2(fx.y, fy.y));
			double n01 = idot2(g01, to_ivec2(fx.z, fy.z));
			double n11 = idot2(g11, to_ivec2(fx.w, fy.w));

			ivec2 fade_xy = to_ivec2(
				fade_(Pf.x),
				fade_(Pf.y));
			ivec2 n_x = to_ivec2(
				mixf(n00, n10, fade_xy.x),
				mixf(n01, n11, fade_xy.x));
			double n_xy = mixf(n_x.x, n_x.y, fade_xy.y);
			PyObject* out = PyFloat_FromDouble((2.3) * n_xy);
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			ivec3 o2;
			if (!unpack_ivec3p(arg2, &o2)) {
				PY_TYPEERROR_2O("unsupported operand type(s) for perlin(): ", arg1, arg2);
				return NULL;
			}
			ivec3 Position = *((ivec3*)o);
			ivec3 rep = o2;
			ivec3 Pi0 = to_ivec3(
				imod(floor(Position.x), rep.x),
				imod(floor(Position.y), rep.y),
				imod(floor(Position.z), rep.z)); // Integer part, modulo period
			ivec3 Pi1 = to_ivec3(
				imod(Pi0.x + 1.0, rep.x),
				imod(Pi0.y + 1.0, rep.y),
				imod(Pi0.z + 1.0, rep.z)); // Integer part + 1, mod period
			Pi0 = to_ivec3(
				imod(Pi0.x, 289.),
				imod(Pi0.y, 289.),
				imod(Pi0.z, 289.));
			Pi1 = to_ivec3(
				imod(Pi1.x, 289.),
				imod(Pi1.y, 289.),
				imod(Pi1.z, 289.));
			ivec3 Pf0 = to_ivec3(
				fract(Position.x),
				fract(Position.y),
				fract(Position.z)); // Fractional part for interpolation
			ivec3 Pf1 = subv3d(Pf0, 1.0); // Fractional part - 1.0
			ivec4 ix = to_ivec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x);
			ivec4 iy = to_ivec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y);
			ivec4 iz0 = to_ivec4d(Pi0.z);
			ivec4 iz1 = to_ivec4d(Pi1.z);

			

			ivec4 ixy = to_ivec4(
				permute_(permute_(ix.x) + iy.x),
				permute_(permute_(ix.y) + iy.y),
				permute_(permute_(ix.z) + iy.z),
				permute_(permute_(ix.w) + iy.w));
			ivec4 ixy0 = to_ivec4(
				permute_(ixy.x + iz0.x),
				permute_(ixy.y + iz0.y),
				permute_(ixy.z + iz0.z),
				permute_(ixy.w + iz0.w));
			ivec4 ixy1 = to_ivec4(
				permute_(ixy.x + iz1.x),
				permute_(ixy.y + iz1.y),
				permute_(ixy.z + iz1.z),
				permute_(ixy.w + iz1.w));

			ivec4 gx0 = mulv4d(ixy0, (1.0 / 7.0));

			ivec4 gy0 = to_ivec4(
				fract(floor(gx0.x) * (1.0 / 7.0)) - 0.5,
				fract(floor(gx0.y) * (1.0 / 7.0)) - 0.5,
				fract(floor(gx0.z) * (1.0 / 7.0)) - 0.5,
				fract(floor(gx0.w) * (1.0 / 7.0)) - 0.5);

			gx0 = to_ivec4(
				fract(gx0.x),
				fract(gx0.y),
				fract(gx0.z),
				fract(gx0.w));

			ivec4 gz0 = to_ivec4(
				0.5 - fabs(gx0.x) - fabs(gy0.x),
				0.5 - fabs(gx0.y) - fabs(gy0.y),
				0.5 - fabs(gx0.z) - fabs(gy0.z),
				0.5 - fabs(gx0.w) - fabs(gy0.w));
			ivec4 sz0 = to_ivec4(
				step(gz0.x, 0.0),
				step(gz0.y, 0.0),
				step(gz0.z, 0.0),
				step(gz0.w, 0.0));
			gx0 = to_ivec4(
				gx0.x - (sz0.x * (step(0.0, gx0.x) - 0.5)),
				gx0.y - (sz0.y * (step(0.0, gx0.y) - 0.5)),
				gx0.z - (sz0.z * (step(0.0, gx0.z) - 0.5)),
				gx0.w - (sz0.w * (step(0.0, gx0.w) - 0.5)));
			gy0 = to_ivec4(
				gy0.x - (sz0.x * (step(0.0, gy0.x) - 0.5)),
				gy0.y - (sz0.y * (step(0.0, gy0.y) - 0.5)),
				gy0.z - (sz0.z * (step(0.0, gy0.z) - 0.5)),
				gy0.w - (sz0.w * (step(0.0, gy0.w) - 0.5)));

			ivec4 gx1 = mulv4d(ixy1, 1.0 / 7.0);
			ivec4 gy1 = to_ivec4(
				fract(floor(gx1.x) * (1.0 / 7.0)) - 0.5,
				fract(floor(gx1.y) * (1.0 / 7.0)) - 0.5,
				fract(floor(gx1.z) * (1.0 / 7.0)) - 0.5,
				fract(floor(gx1.w) * (1.0 / 7.0)) - 0.5);
			gx1 = to_ivec4(
				fract(gx1.x),
				fract(gx1.y),
				fract(gx1.z),
				fract(gx1.w));
			ivec4 gz1 = to_ivec4(
				0.5 - fabs(gx1.x) - fabs(gy1.x),
				0.5 - fabs(gx1.y) - fabs(gy1.y),
				0.5 - fabs(gx1.z) - fabs(gy1.z),
				0.5 - fabs(gx1.w) - fabs(gy1.w));
			ivec4 sz1 = to_ivec4(
				step(gz1.x, 0.0),
				step(gz1.y, 0.0),
				step(gz1.z, 0.0),
				step(gz1.w, 0.0));
			gx1 = to_ivec4(
				gx1.x - (sz1.x * (step(0.0, gx1.x) - 0.5)),
				gx1.y - (sz1.y * (step(0.0, gx1.y) - 0.5)),
				gx1.z - (sz1.z * (step(0.0, gx1.z) - 0.5)),
				gx1.w - (sz1.w * (step(0.0, gx1.w) - 0.5)));
			gy1 = to_ivec4(
				gy1.x - (sz1.x * (step(0.0, gy1.x) - 0.5)),
				gy1.y - (sz1.y * (step(0.0, gy1.y) - 0.5)),
				gy1.z - (sz1.z * (step(0.0, gy1.z) - 0.5)),
				gy1.w - (sz1.w * (step(0.0, gy1.w) - 0.5)));

			ivec3 g000 = to_ivec3(gx0.x, gy0.x, gz0.x);
			ivec3 g100 = to_ivec3(gx0.y, gy0.y, gz0.y);
			ivec3 g010 = to_ivec3(gx0.z, gy0.z, gz0.z);
			ivec3 g110 = to_ivec3(gx0.w, gy0.w, gz0.w);
			ivec3 g001 = to_ivec3(gx1.x, gy1.x, gz1.x);
			ivec3 g101 = to_ivec3(gx1.y, gy1.y, gz1.y);
			ivec3 g011 = to_ivec3(gx1.z, gy1.z, gz1.z);
			ivec3 g111 = to_ivec3(gx1.w, gy1.w, gz1.w);

			ivec4 norm0 = to_ivec4(
				taylorInvSqrt_(idot3(g000, g000)),
				taylorInvSqrt_(idot3(g010, g010)),
				taylorInvSqrt_(idot3(g100, g100)),
				taylorInvSqrt_(idot3(g110, g110)));
			g000 = mulv3d(g000, norm0.x);
			g010 = mulv3d(g010, norm0.y);
			g100 = mulv3d(g100, norm0.z);
			g110 = mulv3d(g110, norm0.w);
			ivec4 norm1 = to_ivec4(
				taylorInvSqrt_(idot3(g001, g001)),
				taylorInvSqrt_(idot3(g011, g011)),
				taylorInvSqrt_(idot3(g101, g101)),
				taylorInvSqrt_(idot3(g111, g111)));
			g001 = mulv3d(g001, norm1.x);
			g011 = mulv3d(g011, norm1.y);
			g101 = mulv3d(g101, norm1.z);
			g111 = mulv3d(g111, norm1.w);

			double n000 = idot3(g000, Pf0);
			double n100 = idot3(g100, to_ivec3(Pf1.x, Pf0.y, Pf0.z));
			double n010 = idot3(g010, to_ivec3(Pf0.x, Pf1.y, Pf0.z));
			double n110 = idot3(g110, to_ivec3(Pf1.x, Pf1.y, Pf0.z));
			double n001 = idot3(g001, to_ivec3(Pf0.x, Pf0.y, Pf1.z));
			double n101 = idot3(g101, to_ivec3(Pf1.x, Pf0.y, Pf1.z));
			double n011 = idot3(g011, to_ivec3(Pf0.x, Pf1.y, Pf1.z));
			double n111 = idot3(g111, Pf1);

			ivec3 fade_xyz = to_ivec3(
				fade_(Pf0.x),
				fade_(Pf0.y),
				fade_(Pf0.z));
			ivec4 n_z = to_ivec4(
				mixf(n000, n001, fade_xyz.z),
				mixf(n100, n101, fade_xyz.z),
				mixf(n010, n011, fade_xyz.z),
				mixf(n110, n111, fade_xyz.z));
			ivec2 n_yz = to_ivec2(
				mixf(n_z.x, n_z.z, fade_xyz.y),
				mixf(n_z.y, n_z.w, fade_xyz.y));
			double n_xyz = mixf(n_yz.x, n_yz.y, fade_xyz.x);
			PyObject* out = PyFloat_FromDouble((2.2) * n_xyz);
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			ivec4 o2;
			if (!unpack_ivec4p(arg2, &o2)) {
				PY_TYPEERROR_2O("unsupported operand type(s) for perlin(): ", arg1, arg2);
				return NULL;
			}
			ivec4 Position = *((ivec4*)o);
			ivec4 rep = o2;
			ivec4 Pi0 = to_ivec4(
				imod(floor(Position.x), rep.x),
				imod(floor(Position.y), rep.y),
				imod(floor(Position.z), rep.z),
				imod(floor(Position.w), rep.w)); // Integer part modulo rep
			ivec4 Pi1 = to_ivec4(
				imod(Pi0.x + 1.0, rep.x),
				imod(Pi0.y + 1.0, rep.y),
				imod(Pi0.z + 1.0, rep.z),
				imod(Pi0.w + 1.0, rep.w)); // Integer part + 1 mod rep
			ivec4 Pf0 = to_ivec4(
				fract(Position.x),
				fract(Position.y),
				fract(Position.z),
				fract(Position.w)); // Fractional part for interpolation
			ivec4 Pf1 = subv4d(Pf0, 1.0); // Fractional part - 1.0
			ivec4 ix = to_ivec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x);
			ivec4 iy = to_ivec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y);
			ivec4 iz0 = to_ivec4d(Pi0.z);
			ivec4 iz1 = to_ivec4d(Pi1.z);
			ivec4 iw0 = to_ivec4d(Pi0.w);
			ivec4 iw1 = to_ivec4d(Pi1.w);

			ivec4 ixy = to_ivec4(
				permute_(permute_(ix.x) + iy.x),
				permute_(permute_(ix.y) + iy.y),
				permute_(permute_(ix.z) + iy.z),
				permute_(permute_(ix.w) + iy.w));
			ivec4 ixy0 = to_ivec4(
				permute_(ixy.x + iz0.x),
				permute_(ixy.y + iz0.y),
				permute_(ixy.z + iz0.z),
				permute_(ixy.w + iz0.w));
			ivec4 ixy1 = to_ivec4(
				permute_(ixy.x + iz1.x),
				permute_(ixy.y + iz1.y),
				permute_(ixy.z + iz1.z),
				permute_(ixy.w + iz1.w));
			ivec4 ixy00 = to_ivec4(
				permute_(ixy0.x + iw0.x),
				permute_(ixy0.y + iw0.y),
				permute_(ixy0.z + iw0.z),
				permute_(ixy0.w + iw0.w));
			ivec4 ixy01 = to_ivec4(
				permute_(ixy0.x + iw1.x),
				permute_(ixy0.y + iw1.y),
				permute_(ixy0.z + iw1.z),
				permute_(ixy0.w + iw1.w));
			ivec4 ixy10 = to_ivec4(
				permute_(ixy1.x + iw0.x),
				permute_(ixy1.y + iw0.y),
				permute_(ixy1.z + iw0.z),
				permute_(ixy1.w + iw0.w));
			ivec4 ixy11 = to_ivec4(
				permute_(ixy1.x + iw1.x),
				permute_(ixy1.y + iw1.y),
				permute_(ixy1.z + iw1.z),
				permute_(ixy1.w + iw1.w));

			ivec4 gx00 = divv4d(ixy00, 7.0);
			ivec4 gy00 = to_ivec4(
				floor(gx00.x) / 7.0,
				floor(gx00.y) / 7.0,
				floor(gx00.z) / 7.0,
				floor(gx00.w) / 7.0);
			ivec4 gz00 = to_ivec4(
				floor(gy00.x) / 6.0,
				floor(gy00.y) / 6.0,
				floor(gy00.z) / 6.0,
				floor(gy00.w) / 6.0);
			gx00 = to_ivec4(
				fract(gx00.x) - 0.5,
				fract(gx00.y) - 0.5,
				fract(gx00.z) - 0.5,
				fract(gx00.w) - 0.5);
			gy00 = to_ivec4(
				fract(gy00.x) - 0.5,
				fract(gy00.y) - 0.5,
				fract(gy00.z) - 0.5,
				fract(gy00.w) - 0.5);
			gz00 = to_ivec4(
				fract(gz00.x) - 0.5,
				fract(gz00.y) - 0.5,
				fract(gz00.z) - 0.5,
				fract(gz00.w) - 0.5);
			ivec4 gw00 = to_ivec4(
				0.75 - fabs(gx00.x) - fabs(gy00.x) - fabs(gz00.x),
				0.75 - fabs(gx00.y) - fabs(gy00.y) - fabs(gz00.y),
				0.75 - fabs(gx00.z) - fabs(gy00.z) - fabs(gz00.z),
				0.75 - fabs(gx00.w) - fabs(gy00.w) - fabs(gz00.w));
			ivec4 sw00 = to_ivec4(
				step(gw00.x, 0.0),
				step(gw00.y, 0.0),
				step(gw00.z, 0.0),
				step(gw00.w, 0.0));
			gx00 = to_ivec4(
				gx00.x - (sw00.x * (step(0.0, gx00.x) - 0.5)),
				gx00.y - (sw00.y * (step(0.0, gx00.y) - 0.5)),
				gx00.z - (sw00.z * (step(0.0, gx00.z) - 0.5)),
				gx00.w - (sw00.w * (step(0.0, gx00.w) - 0.5)));
			gy00 = to_ivec4(
				gy00.x - (sw00.x * (step(0.0, gy00.x) - 0.5)),
				gy00.y - (sw00.y * (step(0.0, gy00.y) - 0.5)),
				gy00.z - (sw00.z * (step(0.0, gy00.z) - 0.5)),
				gy00.w - (sw00.w * (step(0.0, gy00.w) - 0.5)));

			ivec4 gx01 = divv4d(ixy01, 7.0);
			ivec4 gy01 = to_ivec4(
				floor(gx01.x) / 7.0,
				floor(gx01.y) / 7.0,
				floor(gx01.z) / 7.0,
				floor(gx01.w) / 7.0);
			ivec4 gz01 = to_ivec4(
				floor(gy01.x) / 6.0,
				floor(gy01.y) / 6.0,
				floor(gy01.z) / 6.0,
				floor(gy01.w) / 6.0);
			gx01 = to_ivec4(
				fract(gx01.x) - 0.5,
				fract(gx01.y) - 0.5,
				fract(gx01.z) - 0.5,
				fract(gx01.w) - 0.5);
			gy01 = to_ivec4(
				fract(gy01.x) - 0.5,
				fract(gy01.y) - 0.5,
				fract(gy01.z) - 0.5,
				fract(gy01.w) - 0.5);
			gz01 = to_ivec4(
				fract(gz01.x) - 0.5,
				fract(gz01.y) - 0.5,
				fract(gz01.z) - 0.5,
				fract(gz01.w) - 0.5);
			ivec4 gw01 = to_ivec4(
				0.75 - fabs(gx01.x) - fabs(gy01.x) - fabs(gz01.x),
				0.75 - fabs(gx01.y) - fabs(gy01.y) - fabs(gz01.y),
				0.75 - fabs(gx01.z) - fabs(gy01.z) - fabs(gz01.z),
				0.75 - fabs(gx01.w) - fabs(gy01.w) - fabs(gz01.w));
			ivec4 sw01 = to_ivec4(
				step(gw01.x, 0.0),
				step(gw01.y, 0.0),
				step(gw01.z, 0.0),
				step(gw01.w, 0.0));
			gx01 = to_ivec4(
				gx01.x - (sw01.x * (step(0.0, gx01.x) - 0.5)),
				gx01.y - (sw01.y * (step(0.0, gx01.y) - 0.5)),
				gx01.z - (sw01.z * (step(0.0, gx01.z) - 0.5)),
				gx01.w - (sw01.w * (step(0.0, gx01.w) - 0.5)));
			gy01 = to_ivec4(
				gy01.x - (sw01.x * (step(0.0, gy01.x) - 0.5)),
				gy01.y - (sw01.y * (step(0.0, gy01.y) - 0.5)),
				gy01.z - (sw01.z * (step(0.0, gy01.z) - 0.5)),
				gy01.w - (sw01.w * (step(0.0, gy01.w) - 0.5)));

			ivec4 gx10 = divv4d(ixy10, 7.0);
			ivec4 gy10 = to_ivec4(
				floor(gx10.x) / 7.0,
				floor(gx10.y) / 7.0,
				floor(gx10.z) / 7.0,
				floor(gx10.w) / 7.0);
			ivec4 gz10 = to_ivec4(
				floor(gy10.x) / 6.0,
				floor(gy10.y) / 6.0,
				floor(gy10.z) / 6.0,
				floor(gy10.w) / 6.0);
			gx10 = to_ivec4(
				fract(gx10.x) - 0.5,
				fract(gx10.y) - 0.5,
				fract(gx10.z) - 0.5,
				fract(gx10.w) - 0.5);
			gy10 = to_ivec4(
				fract(gy10.x) - 0.5,
				fract(gy10.y) - 0.5,
				fract(gy10.z) - 0.5,
				fract(gy10.w) - 0.5);
			gz10 = to_ivec4(
				fract(gz10.x) - 0.5,
				fract(gz10.y) - 0.5,
				fract(gz10.z) - 0.5,
				fract(gz10.w) - 0.5);
			ivec4 gw10 = to_ivec4(
				0.75 - fabs(gx10.x) - fabs(gy10.x) - fabs(gz10.x),
				0.75 - fabs(gx10.y) - fabs(gy10.y) - fabs(gz10.y),
				0.75 - fabs(gx10.z) - fabs(gy10.z) - fabs(gz10.z),
				0.75 - fabs(gx10.w) - fabs(gy10.w) - fabs(gz10.w));
			ivec4 sw10 = to_ivec4(
				step(gw10.x, 0.0),
				step(gw10.y, 0.0),
				step(gw10.z, 0.0),
				step(gw10.w, 0.0));
			gx10 = to_ivec4(
				gx10.x - (sw10.x * (step(0.0, gx10.x) - 0.5)),
				gx10.y - (sw10.y * (step(0.0, gx10.y) - 0.5)),
				gx10.z - (sw10.z * (step(0.0, gx10.z) - 0.5)),
				gx10.w - (sw10.w * (step(0.0, gx10.w) - 0.5)));
			gy10 = to_ivec4(
				gy10.x - (sw10.x * (step(0.0, gy10.x) - 0.5)),
				gy10.y - (sw10.y * (step(0.0, gy10.y) - 0.5)),
				gy10.z - (sw10.z * (step(0.0, gy10.z) - 0.5)),
				gy10.w - (sw10.w * (step(0.0, gy10.w) - 0.5)));

			ivec4 gx11 = divv4d(ixy11, 7.0);
			ivec4 gy11 = to_ivec4(
				floor(gx11.x) / 7.0,
				floor(gx11.y) / 7.0,
				floor(gx11.z) / 7.0,
				floor(gx11.w) / 7.0);
			ivec4 gz11 = to_ivec4(
				floor(gy11.x) / 6.0,
				floor(gy11.y) / 6.0,
				floor(gy11.z) / 6.0,
				floor(gy11.w) / 6.0);
			gx11 = to_ivec4(
				fract(gx11.x) - 0.5,
				fract(gx11.y) - 0.5,
				fract(gx11.z) - 0.5,
				fract(gx11.w) - 0.5);
			gy11 = to_ivec4(
				fract(gy11.x) - 0.5,
				fract(gy11.y) - 0.5,
				fract(gy11.z) - 0.5,
				fract(gy11.w) - 0.5);
			gz11 = to_ivec4(
				fract(gz11.x) - 0.5,
				fract(gz11.y) - 0.5,
				fract(gz11.z) - 0.5,
				fract(gz11.w) - 0.5);
			ivec4 gw11 = to_ivec4(
				0.75 - fabs(gx11.x) - fabs(gy11.x) - fabs(gz11.x),
				0.75 - fabs(gx11.y) - fabs(gy11.y) - fabs(gz11.y),
				0.75 - fabs(gx11.z) - fabs(gy11.z) - fabs(gz11.z),
				0.75 - fabs(gx11.w) - fabs(gy11.w) - fabs(gz11.w));
			ivec4 sw11 = to_ivec4(
				step(gw11.x, 0.0),
				step(gw11.y, 0.0),
				step(gw11.z, 0.0),
				step(gw11.w, 0.0));
			gx11 = to_ivec4(
				gx11.x - (sw11.x * (step(0.0, gx11.x) - 0.5)),
				gx11.y - (sw11.y * (step(0.0, gx11.y) - 0.5)),
				gx11.z - (sw11.z * (step(0.0, gx11.z) - 0.5)),
				gx11.w - (sw11.w * (step(0.0, gx11.w) - 0.5)));
			gy11 = to_ivec4(
				gy11.x - (sw11.x * (step(0.0, gy11.x) - 0.5)),
				gy11.y - (sw11.y * (step(0.0, gy11.y) - 0.5)),
				gy11.z - (sw11.z * (step(0.0, gy11.z) - 0.5)),
				gy11.w - (sw11.w * (step(0.0, gy11.w) - 0.5)));

			ivec4 g0000 = to_ivec4(gx00.x, gy00.x, gz00.x, gw00.x);
			ivec4 g1000 = to_ivec4(gx00.y, gy00.y, gz00.y, gw00.y);
			ivec4 g0100 = to_ivec4(gx00.z, gy00.z, gz00.z, gw00.z);
			ivec4 g1100 = to_ivec4(gx00.w, gy00.w, gz00.w, gw00.w);
			ivec4 g0010 = to_ivec4(gx10.x, gy10.x, gz10.x, gw10.x);
			ivec4 g1010 = to_ivec4(gx10.y, gy10.y, gz10.y, gw10.y);
			ivec4 g0110 = to_ivec4(gx10.z, gy10.z, gz10.z, gw10.z);
			ivec4 g1110 = to_ivec4(gx10.w, gy10.w, gz10.w, gw10.w);
			ivec4 g0001 = to_ivec4(gx01.x, gy01.x, gz01.x, gw01.x);
			ivec4 g1001 = to_ivec4(gx01.y, gy01.y, gz01.y, gw01.y);
			ivec4 g0101 = to_ivec4(gx01.z, gy01.z, gz01.z, gw01.z);
			ivec4 g1101 = to_ivec4(gx01.w, gy01.w, gz01.w, gw01.w);
			ivec4 g0011 = to_ivec4(gx11.x, gy11.x, gz11.x, gw11.x);
			ivec4 g1011 = to_ivec4(gx11.y, gy11.y, gz11.y, gw11.y);
			ivec4 g0111 = to_ivec4(gx11.z, gy11.z, gz11.z, gw11.z);
			ivec4 g1111 = to_ivec4(gx11.w, gy11.w, gz11.w, gw11.w);

			ivec4 norm00 = to_ivec4(
				taylorInvSqrt_(idot4(g0000, g0000)),
				taylorInvSqrt_(idot4(g0100, g0100)),
				taylorInvSqrt_(idot4(g1000, g1000)),
				taylorInvSqrt_(idot4(g1100, g1100)));
			g0000 = mulv4d(g0000, norm00.x);
			g0100 = mulv4d(g0100, norm00.y);
			g1000 = mulv4d(g1000, norm00.z);
			g1100 = mulv4d(g1100, norm00.w);

			ivec4 norm01 = to_ivec4(
				taylorInvSqrt_(idot4(g0001, g0001)),
				taylorInvSqrt_(idot4(g0101, g0101)),
				taylorInvSqrt_(idot4(g1001, g1001)),
				taylorInvSqrt_(idot4(g1101, g1101)));
			g0001 = mulv4d(g0001, norm01.x);
			g0101 = mulv4d(g0101, norm01.y);
			g1001 = mulv4d(g1001, norm01.z);
			g1101 = mulv4d(g1101, norm01.w);

			ivec4 norm10 = to_ivec4(
				taylorInvSqrt_(idot4(g0010, g0010)),
				taylorInvSqrt_(idot4(g0110, g0110)),
				taylorInvSqrt_(idot4(g1010, g1010)),
				taylorInvSqrt_(idot4(g1110, g1110)));
			g0010 = mulv4d(g0010, norm10.x);
			g0110 = mulv4d(g0110, norm10.y);
			g1010 = mulv4d(g1010, norm10.z);
			g1110 = mulv4d(g1110, norm10.w);

			ivec4 norm11 = to_ivec4(
				taylorInvSqrt_(idot4(g0011, g0011)),
				taylorInvSqrt_(idot4(g0111, g0111)),
				taylorInvSqrt_(idot4(g1011, g1011)),
				taylorInvSqrt_(idot4(g1111, g1111)));
			g0011 = mulv4d(g0011, norm11.x);
			g0111 = mulv4d(g0111, norm11.y);
			g1011 = mulv4d(g1011, norm11.z);
			g1111 = mulv4d(g1111, norm11.w);

			double n0000 = idot4(g0000, Pf0);
			double n1000 = idot4(g1000, to_ivec4(Pf1.x, Pf0.y, Pf0.z, Pf0.w));
			double n0100 = idot4(g0100, to_ivec4(Pf0.x, Pf1.y, Pf0.z, Pf0.w));
			double n1100 = idot4(g1100, to_ivec4(Pf1.x, Pf1.y, Pf0.z, Pf0.w));
			double n0010 = idot4(g0010, to_ivec4(Pf0.x, Pf0.y, Pf1.z, Pf0.w));
			double n1010 = idot4(g1010, to_ivec4(Pf1.x, Pf0.y, Pf1.z, Pf0.w));
			double n0110 = idot4(g0110, to_ivec4(Pf0.x, Pf1.y, Pf1.z, Pf0.w));
			double n1110 = idot4(g1110, to_ivec4(Pf1.x, Pf1.y, Pf1.z, Pf0.w));
			double n0001 = idot4(g0001, to_ivec4(Pf0.x, Pf0.y, Pf0.z, Pf1.w));
			double n1001 = idot4(g1001, to_ivec4(Pf1.x, Pf0.y, Pf0.z, Pf1.w));
			double n0101 = idot4(g0101, to_ivec4(Pf0.x, Pf1.y, Pf0.z, Pf1.w));
			double n1101 = idot4(g1101, to_ivec4(Pf1.x, Pf1.y, Pf0.z, Pf1.w));
			double n0011 = idot4(g0011, to_ivec4(Pf0.x, Pf0.y, Pf1.z, Pf1.w));
			double n1011 = idot4(g1011, to_ivec4(Pf1.x, Pf0.y, Pf1.z, Pf1.w));
			double n0111 = idot4(g0111, to_ivec4(Pf0.x, Pf1.y, Pf1.z, Pf1.w));
			double n1111 = idot4(g1111, Pf1);

			ivec4 fade_xyzw = to_ivec4(
				fade_(Pf0.x),
				fade_(Pf0.y),
				fade_(Pf0.z),
				fade_(Pf0.w));
			ivec4 n_0w = to_ivec4(
				mixf(n0000, n0001, fade_xyzw.w),
				mixf(n1000, n1001, fade_xyzw.w),
				mixf(n0100, n0101, fade_xyzw.w),
				mixf(n1100, n1101, fade_xyzw.w));
			ivec4 n_1w = to_ivec4(
				mixf(n0010, n0011, fade_xyzw.w),
				mixf(n1010, n1011, fade_xyzw.w),
				mixf(n0110, n0111, fade_xyzw.w),
				mixf(n1110, n1111, fade_xyzw.w));
			ivec4 n_zw = to_ivec4(
				mixf(n_0w.x, n_1w.x, fade_xyzw.z),
				mixf(n_0w.y, n_1w.y, fade_xyzw.z),
				mixf(n_0w.z, n_1w.z, fade_xyzw.z),
				mixf(n_0w.w, n_1w.w, fade_xyzw.z));
			ivec2 n_yzw = to_ivec2(
				mixf(n_zw.x, n_zw.z, fade_xyzw.y),
				mixf(n_zw.y, n_zw.w, fade_xyzw.y));
			double n_xyzw = mixf(n_yzw.x, n_yzw.y, fade_xyzw.x);

			PyObject* out = PyFloat_FromDouble((2.2) * n_xyzw);
			free(o);
			return out;
		}
	}
	PyObject* arg;
	UNPACK_1_VARARG(args, "perlin", arg);
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 Position = *((ivec2*)o);
		ivec4 Pi = to_ivec4(
			floor(Position.x),
			floor(Position.y),
			floor(Position.x) + 1.0,
			floor(Position.y) + 1.0);
		ivec4 Pf = to_ivec4(
			fract(Position.x),
			fract(Position.y),
			fract(Position.x) - 1.0,
			fract(Position.y) - 1.0);
		Pi = to_ivec4(
			imod(Pi.x, 289),
			imod(Pi.y, 289),
			imod(Pi.z, 289),
			imod(Pi.w, 289)); // To avoid truncation effects in permutation

		ivec4 ix = to_ivec4(Pi.x, Pi.z, Pi.x, Pi.z);
		ivec4 iy = to_ivec4(Pi.y, Pi.y, Pi.w, Pi.w);
		ivec4 fx = to_ivec4(Pf.x, Pf.z, Pf.x, Pf.z);
		ivec4 fy = to_ivec4(Pf.y, Pf.y, Pf.w, Pf.w);

		ivec4 i = to_ivec4(
			permute_(permute_(ix.x)+ iy.x),
			permute_(permute_(ix.y)+ iy.y),
			permute_(permute_(ix.z)+ iy.z),
			permute_(permute_(ix.w)+ iy.w));

		ivec4 gx = to_ivec4(
			2.0*fract(i.x / 41.0) - 1.0,
			2.0*fract(i.y / 41.0) - 1.0,
			2.0*fract(i.z / 41.0) - 1.0,
			2.0*fract(i.w / 41.0) - 1.0);

		ivec4 gy = to_ivec4(
			fabs(gx.x) - 0.5,
			fabs(gx.y) - 0.5,
			fabs(gx.z) - 0.5,
			fabs(gx.w) - 0.5);
		ivec4 tx = to_ivec4(
			floor(gx.x + 0.5),
			floor(gx.y + 0.5),
			floor(gx.z + 0.5),
			floor(gx.w + 0.5));

		gx = subv4v(gx, tx);

		ivec2 g00 = to_ivec2(gx.x, gy.x);
		ivec2 g10 = to_ivec2(gx.y, gy.y);
		ivec2 g01 = to_ivec2(gx.z, gy.z);
		ivec2 g11 = to_ivec2(gx.w, gy.w);

		ivec4 norm = to_ivec4(
			taylorInvSqrt_(idot2(g00, g00)),
			taylorInvSqrt_(idot2(g01, g01)),
			taylorInvSqrt_(idot2(g10, g10)),
			taylorInvSqrt_(idot2(g11, g11)));
		g00 = mulv2d(g00, norm.x);
		g01 = mulv2d(g01, norm.y);
		g10 = mulv2d(g10, norm.z);
		g11 = mulv2d(g11, norm.w);

		double n00 = idot2(g00, to_ivec2(fx.x, fy.x));
		double n10 = idot2(g10, to_ivec2(fx.y, fy.y));
		double n01 = idot2(g01, to_ivec2(fx.z, fy.z));
		double n11 = idot2(g11, to_ivec2(fx.w, fy.w));

		ivec2 fade_xy = to_ivec2(
			fade_(Pf.x),
			fade_(Pf.y));
		ivec2 n_x = to_ivec2(
			mixf(n00, n10, fade_xy.x),
			mixf(n01, n11, fade_xy.x));
		double n_xy = mixf(n_x.x, n_x.y, fade_xy.y);
		PyObject* out = PyFloat_FromDouble((2.3) * n_xy);
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 Position = *((ivec3*)o);
		ivec3 Pi0 = to_ivec3(
			floor(Position.x),
			floor(Position.y),
			floor(Position.z)); // Integer part for indexing
		ivec3 Pi1 = addv3d(Pi0, (1.0)); // Integer part + 1
		Pi0 = to_ivec3(
			MOD289(Pi0.x),
			MOD289(Pi0.y),
			MOD289(Pi0.z));
		Pi1 = to_ivec3(
			MOD289(Pi1.x),
			MOD289(Pi1.y),
			MOD289(Pi1.z));
		ivec3 Pf0 = to_ivec3(
			fract(Position.x),
			fract(Position.y),
			fract(Position.z)); // Fractional part for interpolation
		ivec3 Pf1 = subv3d(Pf0, 1.0); // Fractional part - 1.0
		ivec4 ix = to_ivec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x);
		ivec4 iy = to_ivec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y);
		ivec4 iz0 = to_ivec4d(Pi0.z);
		ivec4 iz1 = to_ivec4d(Pi1.z);

		ivec4 ixy = to_ivec4(
			permute_(permute_(ix.x) + iy.x),
			permute_(permute_(ix.y) + iy.y),
			permute_(permute_(ix.z) + iy.z),
			permute_(permute_(ix.w) + iy.w));
		ivec4 ixy0 = to_ivec4(
			permute_(ixy.x + iz0.x),
			permute_(ixy.y + iz0.y),
			permute_(ixy.z + iz0.z),
			permute_(ixy.w + iz0.w));
		ivec4 ixy1 = to_ivec4(
			permute_(ixy.x + iz1.x),
			permute_(ixy.y + iz1.y),
			permute_(ixy.z + iz1.z),
			permute_(ixy.w + iz1.w));

		ivec4 gx0 = mulv4d(ixy0, (1.0 / 7.0));
		
		ivec4 gy0 = to_ivec4(
			fract(floor(gx0.x) * (1.0 / 7.0)) - 0.5,
			fract(floor(gx0.y) * (1.0 / 7.0)) - 0.5,
			fract(floor(gx0.z) * (1.0 / 7.0)) - 0.5,
			fract(floor(gx0.w) * (1.0 / 7.0)) - 0.5);
		
		gx0 = to_ivec4(
			fract(gx0.x),
			fract(gx0.y),
			fract(gx0.z),
			fract(gx0.w));
		
		ivec4 gz0 = to_ivec4(
			0.5 - fabs(gx0.x) - fabs(gy0.x),
			0.5 - fabs(gx0.y) - fabs(gy0.y),
			0.5 - fabs(gx0.z) - fabs(gy0.z),
			0.5 - fabs(gx0.w) - fabs(gy0.w));
		ivec4 sz0 = to_ivec4(
			step(gz0.x, 0.0),
			step(gz0.y, 0.0),
			step(gz0.z, 0.0),
			step(gz0.w, 0.0));
		gx0 = to_ivec4(
			gx0.x - (sz0.x * (step(0.0, gx0.x) - 0.5)),
			gx0.y - (sz0.y * (step(0.0, gx0.y) - 0.5)),
			gx0.z - (sz0.z * (step(0.0, gx0.z) - 0.5)),
			gx0.w - (sz0.w * (step(0.0, gx0.w) - 0.5)));
		gy0 = to_ivec4(
			gy0.x - (sz0.x * (step(0.0, gy0.x) - 0.5)),
			gy0.y - (sz0.y * (step(0.0, gy0.y) - 0.5)),
			gy0.z - (sz0.z * (step(0.0, gy0.z) - 0.5)),
			gy0.w - (sz0.w * (step(0.0, gy0.w) - 0.5)));

		ivec4 gx1 = mulv4d(ixy1, 1.0 / 7.0);
		ivec4 gy1 = to_ivec4(
			fract(floor(gx1.x) * (1.0 / 7.0)) - 0.5,
			fract(floor(gx1.y) * (1.0 / 7.0)) - 0.5,
			fract(floor(gx1.z) * (1.0 / 7.0)) - 0.5,
			fract(floor(gx1.w) * (1.0 / 7.0)) - 0.5);
		gx1 = to_ivec4(
			fract(gx1.x),
			fract(gx1.y),
			fract(gx1.z),
			fract(gx1.w));
		ivec4 gz1 = to_ivec4(
			0.5 - fabs(gx1.x) - fabs(gy1.x),
			0.5 - fabs(gx1.y) - fabs(gy1.y),
			0.5 - fabs(gx1.z) - fabs(gy1.z),
			0.5 - fabs(gx1.w) - fabs(gy1.w));
		ivec4 sz1 = to_ivec4(
			step(gz1.x, 0.0),
			step(gz1.y, 0.0),
			step(gz1.z, 0.0),
			step(gz1.w, 0.0));
		gx1 = to_ivec4(
			gx1.x - (sz1.x * (step(0.0, gx1.x) - 0.5)),
			gx1.y - (sz1.y * (step(0.0, gx1.y) - 0.5)),
			gx1.z - (sz1.z * (step(0.0, gx1.z) - 0.5)),
			gx1.w - (sz1.w * (step(0.0, gx1.w) - 0.5)));
		gy1 = to_ivec4(
			gy1.x - (sz1.x * (step(0.0, gy1.x) - 0.5)),
			gy1.y - (sz1.y * (step(0.0, gy1.y) - 0.5)),
			gy1.z - (sz1.z * (step(0.0, gy1.z) - 0.5)),
			gy1.w - (sz1.w * (step(0.0, gy1.w) - 0.5)));

		ivec3 g000 = to_ivec3(gx0.x, gy0.x, gz0.x);
		ivec3 g100 = to_ivec3(gx0.y, gy0.y, gz0.y);
		ivec3 g010 = to_ivec3(gx0.z, gy0.z, gz0.z);
		ivec3 g110 = to_ivec3(gx0.w, gy0.w, gz0.w);
		ivec3 g001 = to_ivec3(gx1.x, gy1.x, gz1.x);
		ivec3 g101 = to_ivec3(gx1.y, gy1.y, gz1.y);
		ivec3 g011 = to_ivec3(gx1.z, gy1.z, gz1.z);
		ivec3 g111 = to_ivec3(gx1.w, gy1.w, gz1.w);

		ivec4 norm0 = to_ivec4(
			taylorInvSqrt_(idot3(g000, g000)),
			taylorInvSqrt_(idot3(g010, g010)),
			taylorInvSqrt_(idot3(g100, g100)),
			taylorInvSqrt_(idot3(g110, g110)));
		g000 = mulv3d(g000, norm0.x);
		g010 = mulv3d(g010, norm0.y);
		g100 = mulv3d(g100, norm0.z);
		g110 = mulv3d(g110, norm0.w);
		ivec4 norm1 = to_ivec4(
			taylorInvSqrt_(idot3(g001, g001)),
			taylorInvSqrt_(idot3(g011, g011)),
			taylorInvSqrt_(idot3(g101, g101)),
			taylorInvSqrt_(idot3(g111, g111)));
		g001 = mulv3d(g001, norm1.x);
		g011 = mulv3d(g011, norm1.y);
		g101 = mulv3d(g101, norm1.z);
		g111 = mulv3d(g111, norm1.w);

		double n000 = idot3(g000, Pf0);
		double n100 = idot3(g100, to_ivec3(Pf1.x, Pf0.y, Pf0.z));
		double n010 = idot3(g010, to_ivec3(Pf0.x, Pf1.y, Pf0.z));
		double n110 = idot3(g110, to_ivec3(Pf1.x, Pf1.y, Pf0.z));
		double n001 = idot3(g001, to_ivec3(Pf0.x, Pf0.y, Pf1.z));
		double n101 = idot3(g101, to_ivec3(Pf1.x, Pf0.y, Pf1.z));
		double n011 = idot3(g011, to_ivec3(Pf0.x, Pf1.y, Pf1.z));
		double n111 = idot3(g111, Pf1);

		ivec3 fade_xyz = to_ivec3(
			fade_(Pf0.x),
			fade_(Pf0.y),
			fade_(Pf0.z));
		ivec4 n_z = to_ivec4(
			mixf(n000, n001, fade_xyz.z),
			mixf(n100, n101, fade_xyz.z),
			mixf(n010, n011, fade_xyz.z),
			mixf(n110, n111, fade_xyz.z));
		ivec2 n_yz = to_ivec2(
			mixf(n_z.x, n_z.z, fade_xyz.y),
			mixf(n_z.y, n_z.w, fade_xyz.y));
		double n_xyz = mixf(n_yz.x, n_yz.y, fade_xyz.x);
		PyObject* out = PyFloat_FromDouble((2.2) * n_xyz);
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 Position = *((ivec4*)o);
		ivec4 Pi0 = to_ivec4(
			floor(Position.x),
			floor(Position.y),
			floor(Position.z),
			floor(Position.w));
		ivec4 Pi1 = addv4d(Pi0, 1.0);
		Pi0 = to_ivec4(
			imod(Pi0.x, 289.),
			imod(Pi0.y, 289.),
			imod(Pi0.z, 289.),
			imod(Pi0.w, 289.));
		Pi1 = to_ivec4(
			imod(Pi1.x, 289.),
			imod(Pi1.y, 289.),
			imod(Pi1.z, 289.),
			imod(Pi1.w, 289.));
		ivec4 Pf0 = to_ivec4(
			fract(Position.x),
			fract(Position.y),
			fract(Position.z),
			fract(Position.w)); // Fractional part for interpolation
		ivec4 Pf1 = subv4d(Pf0, 1.0); // Fractional part - 1.0
		ivec4 ix = to_ivec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x);
		ivec4 iy = to_ivec4(Pi0.y, Pi0.y, Pi1.y, Pi1.y);
		ivec4 iz0 = to_ivec4d(Pi0.z);
		ivec4 iz1 = to_ivec4d(Pi1.z);
		ivec4 iw0 = to_ivec4d(Pi0.w);
		ivec4 iw1 = to_ivec4d(Pi1.w);

		ivec4 ixy = to_ivec4(
			permute_(permute_(ix.x) + iy.x),
			permute_(permute_(ix.y) + iy.y),
			permute_(permute_(ix.z) + iy.z),
			permute_(permute_(ix.w) + iy.w));
		ivec4 ixy0 = to_ivec4(
			permute_(ixy.x + iz0.x),
			permute_(ixy.y + iz0.y),
			permute_(ixy.z + iz0.z),
			permute_(ixy.w + iz0.w));
		ivec4 ixy1 = to_ivec4(
			permute_(ixy.x + iz1.x),
			permute_(ixy.y + iz1.y),
			permute_(ixy.z + iz1.z),
			permute_(ixy.w + iz1.w));
		ivec4 ixy00 = to_ivec4(
			permute_(ixy0.x + iw0.x),
			permute_(ixy0.y + iw0.y),
			permute_(ixy0.z + iw0.z),
			permute_(ixy0.w + iw0.w));
		ivec4 ixy01 = to_ivec4(
			permute_(ixy0.x + iw1.x),
			permute_(ixy0.y + iw1.y),
			permute_(ixy0.z + iw1.z),
			permute_(ixy0.w + iw1.w));
		ivec4 ixy10 = to_ivec4(
			permute_(ixy1.x + iw0.x),
			permute_(ixy1.y + iw0.y),
			permute_(ixy1.z + iw0.z),
			permute_(ixy1.w + iw0.w));
		ivec4 ixy11 = to_ivec4(
			permute_(ixy1.x + iw1.x),
			permute_(ixy1.y + iw1.y),
			permute_(ixy1.z + iw1.z),
			permute_(ixy1.w + iw1.w));

		ivec4 gx00 = divv4d(ixy00, 7.0);
		ivec4 gy00 = to_ivec4(
			floor(gx00.x) / 7.0,
			floor(gx00.y) / 7.0,
			floor(gx00.z) / 7.0,
			floor(gx00.w) / 7.0);
		ivec4 gz00 = to_ivec4(
			floor(gy00.x) / 6.0,
			floor(gy00.y) / 6.0,
			floor(gy00.z) / 6.0,
			floor(gy00.w) / 6.0);
		gx00 = to_ivec4(
			fract(gx00.x) - 0.5,
			fract(gx00.y) - 0.5,
			fract(gx00.z) - 0.5,
			fract(gx00.w) - 0.5);
		gy00 = to_ivec4(
			fract(gy00.x) - 0.5,
			fract(gy00.y) - 0.5,
			fract(gy00.z) - 0.5,
			fract(gy00.w) - 0.5);
		gz00 = to_ivec4(
			fract(gz00.x) - 0.5,
			fract(gz00.y) - 0.5,
			fract(gz00.z) - 0.5,
			fract(gz00.w) - 0.5);
		ivec4 gw00 = to_ivec4(
			0.75 - fabs(gx00.x) - fabs(gy00.x) - fabs(gz00.x),
			0.75 - fabs(gx00.y) - fabs(gy00.y) - fabs(gz00.y),
			0.75 - fabs(gx00.z) - fabs(gy00.z) - fabs(gz00.z),
			0.75 - fabs(gx00.w) - fabs(gy00.w) - fabs(gz00.w));
		ivec4 sw00 = to_ivec4(
			step(gw00.x, 0.0),
			step(gw00.y, 0.0),
			step(gw00.z, 0.0),
			step(gw00.w, 0.0));
		gx00 = to_ivec4(
			gx00.x - (sw00.x * (step(0.0, gx00.x) - 0.5)),
			gx00.y - (sw00.y * (step(0.0, gx00.y) - 0.5)),
			gx00.z - (sw00.z * (step(0.0, gx00.z) - 0.5)),
			gx00.w - (sw00.w * (step(0.0, gx00.w) - 0.5)));
		gy00 = to_ivec4(
			gy00.x - (sw00.x * (step(0.0, gy00.x) - 0.5)),
			gy00.y - (sw00.y * (step(0.0, gy00.y) - 0.5)),
			gy00.z - (sw00.z * (step(0.0, gy00.z) - 0.5)),
			gy00.w - (sw00.w * (step(0.0, gy00.w) - 0.5)));

		ivec4 gx01 = divv4d(ixy01, 7.0);
		ivec4 gy01 = to_ivec4(
			floor(gx01.x) / 7.0,
			floor(gx01.y) / 7.0,
			floor(gx01.z) / 7.0,
			floor(gx01.w) / 7.0);
		ivec4 gz01 = to_ivec4(
			floor(gy01.x) / 6.0,
			floor(gy01.y) / 6.0,
			floor(gy01.z) / 6.0,
			floor(gy01.w) / 6.0);
		gx01 = to_ivec4(
			fract(gx01.x) - 0.5,
			fract(gx01.y) - 0.5,
			fract(gx01.z) - 0.5,
			fract(gx01.w) - 0.5);
		gy01 = to_ivec4(
			fract(gy01.x) - 0.5,
			fract(gy01.y) - 0.5,
			fract(gy01.z) - 0.5,
			fract(gy01.w) - 0.5);
		gz01 = to_ivec4(
			fract(gz01.x) - 0.5,
			fract(gz01.y) - 0.5,
			fract(gz01.z) - 0.5,
			fract(gz01.w) - 0.5);
		ivec4 gw01 = to_ivec4(
			0.75 - fabs(gx01.x) - fabs(gy01.x) - fabs(gz01.x),
			0.75 - fabs(gx01.y) - fabs(gy01.y) - fabs(gz01.y),
			0.75 - fabs(gx01.z) - fabs(gy01.z) - fabs(gz01.z),
			0.75 - fabs(gx01.w) - fabs(gy01.w) - fabs(gz01.w));
		ivec4 sw01 = to_ivec4(
			step(gw01.x, 0.0),
			step(gw01.y, 0.0),
			step(gw01.z, 0.0),
			step(gw01.w, 0.0));
		gx01 = to_ivec4(
			gx01.x - (sw01.x * (step(0.0, gx01.x) - 0.5)),
			gx01.y - (sw01.y * (step(0.0, gx01.y) - 0.5)),
			gx01.z - (sw01.z * (step(0.0, gx01.z) - 0.5)),
			gx01.w - (sw01.w * (step(0.0, gx01.w) - 0.5)));
		gy01 = to_ivec4(
			gy01.x - (sw01.x * (step(0.0, gy01.x) - 0.5)),
			gy01.y - (sw01.y * (step(0.0, gy01.y) - 0.5)),
			gy01.z - (sw01.z * (step(0.0, gy01.z) - 0.5)),
			gy01.w - (sw01.w * (step(0.0, gy01.w) - 0.5)));

		ivec4 gx10 = divv4d(ixy10, 7.0);
		ivec4 gy10 = to_ivec4(
			floor(gx10.x) / 7.0,
			floor(gx10.y) / 7.0,
			floor(gx10.z) / 7.0,
			floor(gx10.w) / 7.0);
		ivec4 gz10 = to_ivec4(
			floor(gy10.x) / 6.0,
			floor(gy10.y) / 6.0,
			floor(gy10.z) / 6.0,
			floor(gy10.w) / 6.0);
		gx10 = to_ivec4(
			fract(gx10.x) - 0.5,
			fract(gx10.y) - 0.5,
			fract(gx10.z) - 0.5,
			fract(gx10.w) - 0.5);
		gy10 = to_ivec4(
			fract(gy10.x) - 0.5,
			fract(gy10.y) - 0.5,
			fract(gy10.z) - 0.5,
			fract(gy10.w) - 0.5);
		gz10 = to_ivec4(
			fract(gz10.x) - 0.5,
			fract(gz10.y) - 0.5,
			fract(gz10.z) - 0.5,
			fract(gz10.w) - 0.5);
		ivec4 gw10 = to_ivec4(
			0.75 - fabs(gx10.x) - fabs(gy10.x) - fabs(gz10.x),
			0.75 - fabs(gx10.y) - fabs(gy10.y) - fabs(gz10.y),
			0.75 - fabs(gx10.z) - fabs(gy10.z) - fabs(gz10.z),
			0.75 - fabs(gx10.w) - fabs(gy10.w) - fabs(gz10.w));
		ivec4 sw10 = to_ivec4(
			step(gw10.x, 0.0),
			step(gw10.y, 0.0),
			step(gw10.z, 0.0),
			step(gw10.w, 0.0));
		gx10 = to_ivec4(
			gx10.x - (sw10.x * (step(0.0, gx10.x) - 0.5)),
			gx10.y - (sw10.y * (step(0.0, gx10.y) - 0.5)),
			gx10.z - (sw10.z * (step(0.0, gx10.z) - 0.5)),
			gx10.w - (sw10.w * (step(0.0, gx10.w) - 0.5)));
		gy10 = to_ivec4(
			gy10.x - (sw10.x * (step(0.0, gy10.x) - 0.5)),
			gy10.y - (sw10.y * (step(0.0, gy10.y) - 0.5)),
			gy10.z - (sw10.z * (step(0.0, gy10.z) - 0.5)),
			gy10.w - (sw10.w * (step(0.0, gy10.w) - 0.5)));

		ivec4 gx11 = divv4d(ixy11, 7.0);
		ivec4 gy11 = to_ivec4(
			floor(gx11.x) / 7.0,
			floor(gx11.y) / 7.0,
			floor(gx11.z) / 7.0,
			floor(gx11.w) / 7.0);
		ivec4 gz11 = to_ivec4(
			floor(gy11.x) / 6.0,
			floor(gy11.y) / 6.0,
			floor(gy11.z) / 6.0,
			floor(gy11.w) / 6.0);
		gx11 = to_ivec4(
			fract(gx11.x) - 0.5,
			fract(gx11.y) - 0.5,
			fract(gx11.z) - 0.5,
			fract(gx11.w) - 0.5);
		gy11 = to_ivec4(
			fract(gy11.x) - 0.5,
			fract(gy11.y) - 0.5,
			fract(gy11.z) - 0.5,
			fract(gy11.w) - 0.5);
		gz11 = to_ivec4(
			fract(gz11.x) - 0.5,
			fract(gz11.y) - 0.5,
			fract(gz11.z) - 0.5,
			fract(gz11.w) - 0.5);
		ivec4 gw11 = to_ivec4(
			0.75 - fabs(gx11.x) - fabs(gy11.x) - fabs(gz11.x),
			0.75 - fabs(gx11.y) - fabs(gy11.y) - fabs(gz11.y),
			0.75 - fabs(gx11.z) - fabs(gy11.z) - fabs(gz11.z),
			0.75 - fabs(gx11.w) - fabs(gy11.w) - fabs(gz11.w));
		ivec4 sw11 = to_ivec4(
			step(gw11.x, 0.0),
			step(gw11.y, 0.0),
			step(gw11.z, 0.0),
			step(gw11.w, 0.0));
		gx11 = to_ivec4(
			gx11.x - (sw11.x * (step(0.0, gx11.x) - 0.5)),
			gx11.y - (sw11.y * (step(0.0, gx11.y) - 0.5)),
			gx11.z - (sw11.z * (step(0.0, gx11.z) - 0.5)),
			gx11.w - (sw11.w * (step(0.0, gx11.w) - 0.5)));
		gy11 = to_ivec4(
			gy11.x - (sw11.x * (step(0.0, gy11.x) - 0.5)),
			gy11.y - (sw11.y * (step(0.0, gy11.y) - 0.5)),
			gy11.z - (sw11.z * (step(0.0, gy11.z) - 0.5)),
			gy11.w - (sw11.w * (step(0.0, gy11.w) - 0.5)));
			
		ivec4 g0000 = to_ivec4(gx00.x, gy00.x, gz00.x, gw00.x);
		ivec4 g1000 = to_ivec4(gx00.y, gy00.y, gz00.y, gw00.y);
		ivec4 g0100 = to_ivec4(gx00.z, gy00.z, gz00.z, gw00.z);
		ivec4 g1100 = to_ivec4(gx00.w, gy00.w, gz00.w, gw00.w);
		ivec4 g0010 = to_ivec4(gx10.x, gy10.x, gz10.x, gw10.x);
		ivec4 g1010 = to_ivec4(gx10.y, gy10.y, gz10.y, gw10.y);
		ivec4 g0110 = to_ivec4(gx10.z, gy10.z, gz10.z, gw10.z);
		ivec4 g1110 = to_ivec4(gx10.w, gy10.w, gz10.w, gw10.w);
		ivec4 g0001 = to_ivec4(gx01.x, gy01.x, gz01.x, gw01.x);
		ivec4 g1001 = to_ivec4(gx01.y, gy01.y, gz01.y, gw01.y);
		ivec4 g0101 = to_ivec4(gx01.z, gy01.z, gz01.z, gw01.z);
		ivec4 g1101 = to_ivec4(gx01.w, gy01.w, gz01.w, gw01.w);
		ivec4 g0011 = to_ivec4(gx11.x, gy11.x, gz11.x, gw11.x);
		ivec4 g1011 = to_ivec4(gx11.y, gy11.y, gz11.y, gw11.y);
		ivec4 g0111 = to_ivec4(gx11.z, gy11.z, gz11.z, gw11.z);
		ivec4 g1111 = to_ivec4(gx11.w, gy11.w, gz11.w, gw11.w);

		ivec4 norm00 = to_ivec4(
			taylorInvSqrt_(idot4(g0000, g0000)),
			taylorInvSqrt_(idot4(g0100, g0100)),
			taylorInvSqrt_(idot4(g1000, g1000)),
			taylorInvSqrt_(idot4(g1100, g1100)));
		g0000 = mulv4d(g0000, norm00.x);
		g0100 = mulv4d(g0100, norm00.y);
		g1000 = mulv4d(g1000, norm00.z);
		g1100 = mulv4d(g1100, norm00.w);

		ivec4 norm01 = to_ivec4(
			taylorInvSqrt_(idot4(g0001, g0001)),
			taylorInvSqrt_(idot4(g0101, g0101)),
			taylorInvSqrt_(idot4(g1001, g1001)),
			taylorInvSqrt_(idot4(g1101, g1101)));
		g0001 = mulv4d(g0001, norm01.x);
		g0101 = mulv4d(g0101, norm01.y);
		g1001 = mulv4d(g1001, norm01.z);
		g1101 = mulv4d(g1101, norm01.w);

		ivec4 norm10 = to_ivec4(
			taylorInvSqrt_(idot4(g0010, g0010)),
			taylorInvSqrt_(idot4(g0110, g0110)),
			taylorInvSqrt_(idot4(g1010, g1010)),
			taylorInvSqrt_(idot4(g1110, g1110)));
		g0010 = mulv4d(g0010, norm10.x);
		g0110 = mulv4d(g0110, norm10.y);
		g1010 = mulv4d(g1010, norm10.z);
		g1110 = mulv4d(g1110, norm10.w);

		ivec4 norm11 = to_ivec4(
			taylorInvSqrt_(idot4(g0011, g0011)),
			taylorInvSqrt_(idot4(g0111, g0111)),
			taylorInvSqrt_(idot4(g1011, g1011)),
			taylorInvSqrt_(idot4(g1111, g1111)));
		g0011 = mulv4d(g0011, norm11.x);
		g0111 = mulv4d(g0111, norm11.y);
		g1011 = mulv4d(g1011, norm11.z);
		g1111 = mulv4d(g1111, norm11.w);

		double n0000 = idot4(g0000, Pf0);
		double n1000 = idot4(g1000, to_ivec4(Pf1.x, Pf0.y, Pf0.z, Pf0.w));
		double n0100 = idot4(g0100, to_ivec4(Pf0.x, Pf1.y, Pf0.z, Pf0.w));
		double n1100 = idot4(g1100, to_ivec4(Pf1.x, Pf1.y, Pf0.z, Pf0.w));
		double n0010 = idot4(g0010, to_ivec4(Pf0.x, Pf0.y, Pf1.z, Pf0.w));
		double n1010 = idot4(g1010, to_ivec4(Pf1.x, Pf0.y, Pf1.z, Pf0.w));
		double n0110 = idot4(g0110, to_ivec4(Pf0.x, Pf1.y, Pf1.z, Pf0.w));
		double n1110 = idot4(g1110, to_ivec4(Pf1.x, Pf1.y, Pf1.z, Pf0.w));
		double n0001 = idot4(g0001, to_ivec4(Pf0.x, Pf0.y, Pf0.z, Pf1.w));
		double n1001 = idot4(g1001, to_ivec4(Pf1.x, Pf0.y, Pf0.z, Pf1.w));
		double n0101 = idot4(g0101, to_ivec4(Pf0.x, Pf1.y, Pf0.z, Pf1.w));
		double n1101 = idot4(g1101, to_ivec4(Pf1.x, Pf1.y, Pf0.z, Pf1.w));
		double n0011 = idot4(g0011, to_ivec4(Pf0.x, Pf0.y, Pf1.z, Pf1.w));
		double n1011 = idot4(g1011, to_ivec4(Pf1.x, Pf0.y, Pf1.z, Pf1.w));
		double n0111 = idot4(g0111, to_ivec4(Pf0.x, Pf1.y, Pf1.z, Pf1.w));
		double n1111 = idot4(g1111, Pf1);

		ivec4 fade_xyzw = to_ivec4(
			fade_(Pf0.x),
			fade_(Pf0.y),
			fade_(Pf0.z),
			fade_(Pf0.w));
		ivec4 n_0w = to_ivec4(
			mixf(n0000, n0001, fade_xyzw.w),
			mixf(n1000, n1001, fade_xyzw.w),
			mixf(n0100, n0101, fade_xyzw.w),
			mixf(n1100, n1101, fade_xyzw.w));
		ivec4 n_1w = to_ivec4(
			mixf(n0010, n0011, fade_xyzw.w),
			mixf(n1010, n1011, fade_xyzw.w),
			mixf(n0110, n0111, fade_xyzw.w),
			mixf(n1110, n1111, fade_xyzw.w));
		ivec4 n_zw = to_ivec4(
			mixf(n_0w.x, n_1w.x, fade_xyzw.z),
			mixf(n_0w.y, n_1w.y, fade_xyzw.z),
			mixf(n_0w.z, n_1w.z, fade_xyzw.z),
			mixf(n_0w.w, n_1w.w, fade_xyzw.z));
		ivec2 n_yzw = to_ivec2(
			mixf(n_zw.x, n_zw.z, fade_xyzw.y),
			mixf(n_zw.y, n_zw.w, fade_xyzw.y));
		double n_xyzw = mixf(n_yzw.x, n_yzw.y, fade_xyzw.x);
		
		PyObject* out = PyFloat_FromDouble((2.2) * n_xyzw);
		free(o);
		return out;
	}
	PY_TYPEERROR("unsupported operand type for perlin(): ", arg);
	return NULL;
}

static PyObject* simplex(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 v = *((ivec2*)o);
		ivec4 C = to_ivec4(
			(0.211324865405187),  // (3.0 -  sqrt(3.0)) / 6.0
			(0.366025403784439),  //  0.5 * (sqrt(3.0)  - 1.0)
			(-0.577350269189626),	// -1.0 + 2.0 * C.x
			(0.024390243902439)); //  1.0 / 41.0

								  // First corner
		ivec2 i = to_ivec2(
			floor(v.x + idot2(v, to_ivec2d(C.y))),
			floor(v.y + idot2(v, to_ivec2d(C.y))));
		ivec2 x0 = addv2d(subv2v(v, i), idot2(i, to_ivec2d(C.x)));

		// Other corners
		//i1.x = step( x0.y, x0.x ); // x0.x > x0.y ? 1.0 : 0.0
		//i1.y = 1.0 - i1.x;
		ivec2 i1 = (x0.x > x0.y) ? to_ivec2(1., 0.) : to_ivec2(0., 1.);
		// x0 = x0 - 0.0 + 0.0 * C.xx ;
		// x1 = x0 - i1 + 1.0 * C.xx ;
		// x2 = x0 - 1.0 + 2.0 * C.xx ;
		ivec4 x12 = addv4v(to_ivec4(x0.x, x0.y, x0.x, x0.y), to_ivec4(C.x, C.x, C.z, C.z));
		x12 = to_ivec4(x12.x - i1.x, x12.y - i1.y, x12.z, x12.w);

		// Permutations
		i = to_ivec2(
			imod(i.x, 289.),
			imod(i.y, 289.));// Avoid truncation effects in permutation
		ivec3 p = to_ivec3(
			permute_(permute_(i.y) + i.x),
			permute_(permute_(i.y + i1.y) + i.x + i1.x),
			permute_(permute_(i.y + 1.0) + i.x + 1.0));

		ivec3 m = to_ivec3(
			max(0.5 - idot2(x0,x0), 0.0),
			max(0.5 - idot2(to_ivec2(x12.x,x12.y), to_ivec2(x12.x,x12.y)), 0.0),
			max(0.5 - idot2(to_ivec2(x12.z, x12.w), to_ivec2(x12.z, x12.w)), 0.0));
		m = mulv3v(m, m);
		m = mulv3v(m, m);

		// Gradients: 41 points uniformly over a line, mapped onto a diamond.
		// The ring size 17*17 = 289 is close to a multiple of 41 (41*7 = 287)

		ivec3 x = to_ivec3(
			2.0 * fract(p.x * C.w) - 1.0,
			2.0 * fract(p.y * C.w) - 1.0,
			2.0 * fract(p.z * C.w) - 1.0);
		ivec3 h = to_ivec3(
			fabs(x.x) - (0.5),
			fabs(x.y) - (0.5), 
			fabs(x.z) - (0.5));
		ivec3 ox = to_ivec3(
			floor(x.x + (0.5)),
			floor(x.y + (0.5)), 
			floor(x.z + (0.5)));
		ivec3 a0 = subv3v(x, ox);

		// Normalise gradients implicitly by scaling m
		// Inlined for speed: m *= taylorInvSqrt( a0*a0 + h*h );
		m = mulv3v(m, (rsubv3d(1.79284291400159, (rmulv3d(0.85373472095314, (addv3v(mulv3v(a0,a0), mulv3v(h,h))))))));

		// Compute final noise value at P
		ivec3 g;
		g.x = a0.x  * x0.x + h.x  * x0.y;
		//g.yz = a0.yz * x12.xz + h.yz * x12.yw;
		g.y = a0.y * x12.x + h.y * x12.y;
		g.z = a0.z * x12.z + h.z * x12.w;
		PyObject* out = PyFloat_FromDouble((130.) * idot3(m, g));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 v = *((ivec3*)o);
		ivec2 C = to_ivec2(1.0 / 6.0, 1.0 / 3.0);
		ivec4 D = to_ivec4(0.0, 0.5, 1.0, 2.0);

		// First corner
		ivec3 i = to_ivec3(
			floor(v.x + idot3(v, to_ivec3d(C.y))),
			floor(v.y + idot3(v, to_ivec3d(C.y))),
			floor(v.z + idot3(v, to_ivec3d(C.y))));
		ivec3 x0 = (addv3d(subv3v(v, i), idot3(i, to_ivec3d(C.x))));

		// Other corners
		ivec3 g = to_ivec3(
			step(x0.y, x0.x),
			step(x0.z, x0.y),
			step(x0.x, x0.z));
		ivec3 l = (rsubv3d((1.0), g));
		ivec3 i1 = to_ivec3(
			min(g.x, l.z),
			min(g.y, l.x),
			min(g.z, l.y));

		ivec3 i2 = to_ivec3(
			max(g.x, l.z),
			max(g.y, l.x),
			max(g.z, l.y));

		//   x0 = x0 - 0.0 + 0.0 * C.xxx;
		//   x1 = x0 - i1  + 1.0 * C.xxx;
		//   x2 = x0 - i2  + 2.0 * C.xxx;
		//   x3 = x0 - 1.0 + 3.0 * C.xxx;
		ivec3 x1 = (addv3d(subv3v(x0, i1), C.x));
		ivec3 x2 = (addv3d(subv3v(x0, i2), C.y)); // 2.0*C.x = 1/3 = C.y
		ivec3 x3 = (subv3d(x0, D.y));      // -1.0+3.0*C.x = -0.5 = -D.y

										// Permutations
		i = to_ivec3(
			MOD289(i.x),
			MOD289(i.y),
			MOD289(i.z));
		ivec4 p = to_ivec4(
			permute_(permute_(permute_(i.z + 0.0) + i.y + 0.0) + i.x + 0.0),
			permute_(permute_(permute_(i.z + i1.z) + i.y + i1.y) + i.x + i1.x),
			permute_(permute_(permute_(i.z + i2.z) + i.y + i2.y) + i.x + i2.x),
			permute_(permute_(permute_(i.z + 1.0) + i.y + 1.0) + i.x + 1.0));//(detail::permute(detail::permute(detail::permute(

		// Gradients: 7x7 points over a square, mapped onto an octahedron.
		// The ring size 17*17 = 289 is close to a multiple of 49 (49*6 = 294)
		double n_ = (1.0 / 7.0); // 1.0/7.0
		ivec3 ns = to_ivec3(
			n_ * D.w - D.x,
			n_ * D.y - D.z,
			n_ * D.z - D.x);

		ivec4 j = to_ivec4(
			p.x - 49. * floor(p.x * ns.z * ns.z),
			p.y - 49. * floor(p.y * ns.z * ns.z),
			p.z - 49. * floor(p.z * ns.z * ns.z),
			p.w - 49. * floor(p.w * ns.z * ns.z)); //  mod(p,7*7)

		ivec4 x_ = to_ivec4(
			floor(j.x * ns.z),
			floor(j.y * ns.z),
			floor(j.z * ns.z),
			floor(j.w * ns.z));
		ivec4 y_ = to_ivec4(
			floor(j.x - 7.0 * x_.x),
			floor(j.y - 7.0 * x_.y),
			floor(j.z - 7.0 * x_.z),
			floor(j.w - 7.0 * x_.w));    // mod(j,N)

		ivec4 x = (addv4d(mulv4d(x_, ns.x), ns.y));
		ivec4 y = (addv4d(mulv4d(y_, ns.x), ns.y));
		ivec4 h = to_ivec4(
			1.0 - fabs(x.x) - fabs(y.x),
			1.0 - fabs(x.y) - fabs(y.y),
			1.0 - fabs(x.z) - fabs(y.z),
			1.0 - fabs(x.w) - fabs(y.w));

		ivec4 b0 = to_ivec4(x.x, x.y, y.x, y.y);
		ivec4 b1 = to_ivec4(x.z, x.w, y.z, y.w);

		// vec4 s0 = vec4(lessThan(b0,0.0))*2.0 - 1.0;
		// vec4 s1 = vec4(lessThan(b1,0.0))*2.0 - 1.0;
		ivec4 s0 = to_ivec4(
			floor(b0.x) * 2.0 + 1.0,
			floor(b0.y) * 2.0 + 1.0,
			floor(b0.z) * 2.0 + 1.0,
			floor(b0.w) * 2.0 + 1.0);
		ivec4 s1 = to_ivec4(
			floor(b1.x) * 2.0 + 1.0,
			floor(b1.y) * 2.0 + 1.0,
			floor(b1.z) * 2.0 + 1.0,
			floor(b1.w) * 2.0 + 1.0);
		ivec4 sh = to_ivec4(
			-step(h.x, 0.0),
			-step(h.y, 0.0),
			-step(h.z, 0.0),
			-step(h.w, 0.0));

		ivec4 a0 = to_ivec4(
			b0.x + s0.x * sh.x,
			b0.z + s0.z * sh.x,
			b0.y + s0.y * sh.y,
			b0.w + s0.w * sh.y);
		ivec4 a1 = to_ivec4(
			b1.x + s1.x * sh.z,
			b1.z + s1.z * sh.z,
			b1.y + s1.y * sh.w,
			b1.w + s1.w * sh.w);

		ivec3 p0 = to_ivec3(a0.x, a0.y, h.x);
		ivec3 p1 = to_ivec3(a0.z, a0.w, h.y);
		ivec3 p2 = to_ivec3(a1.x, a1.y, h.z);
		ivec3 p3 = to_ivec3(a1.z, a1.w, h.w);

		// Normalise gradients
		ivec4 norm = to_ivec4(
			taylorInvSqrt_(idot3(p0, p0)),
			taylorInvSqrt_(idot3(p1, p1)),
			taylorInvSqrt_(idot3(p2, p2)),
			taylorInvSqrt_(idot3(p3, p3)));
		p0 = mulv3d(p0, norm.x);
		p1 = mulv3d(p1, norm.y);
		p2 = mulv3d(p2, norm.z);
		p3 = mulv3d(p3, norm.w);

		// Mix final noise value
		ivec4 m = to_ivec4(
			max(0.6 - idot3(x0, x0), 0.0),
			max(0.6 - idot3(x1, x1), 0.0),
			max(0.6 - idot3(x2, x2), 0.0),
			max(0.6 - idot3(x3, x3), 0.0));
		m = mulv4v(m, m);
		PyObject* out = PyFloat_FromDouble((42.) * idot4(mulv4v(m, m), to_ivec4(idot3(p0, x0), idot3(p1, x1), idot3(p2, x2), idot3(p3, x3))));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		double const sqrt_of_five = sqrt(5.0);
		double const G4 = (5. - sqrt_of_five) / 20.;
		ivec4 v = *((ivec4*)o);
		ivec4 const C = to_ivec4(
			G4,  // (5 - sqrt(5))/20  G4
			2.0 * G4,  // 2 * G4
			3.0 * G4,  // 3 * G4
			-1. + 4. * G4); // -1 + 4 * G4

								 // (sqrt(5) - 1)/4 = F4, used once below
		double const F4 = ((sqrt_of_five - 1.0) / 4.0);

		// First corner
		ivec4 i = to_ivec4(
			floor(v.x + idot4(v, to_ivec4d(F4))),
			floor(v.y + idot4(v, to_ivec4d(F4))),
			floor(v.z + idot4(v, to_ivec4d(F4))),
			floor(v.w + idot4(v, to_ivec4d(F4))));
		ivec4 x0 = addv4d(subv4v(v, i), idot4(i, to_ivec4d(C.x)));

		// Other corners

		// Rank sorting originally contributed by Bill Licea-Kane, AMD (formerly ATI)
		ivec4 i0;
		ivec3 isX = to_ivec3(
			step(x0.y, x0.x),
			step(x0.z, x0.x),
			step(x0.w, x0.x));
		ivec3 isYZ = to_ivec3(
			step(x0.z, x0.y),
			step(x0.w, x0.y),
			step(x0.w, x0.z));
		//  i0.x = dot(isX, vec3(1.0));
		//i0.x = isX.x + isX.y + isX.z;
		//i0.yzw = static_cast<T>(1) - isX;
		i0 = to_ivec4(isX.x + isX.y + isX.z, 1.0 - isX.x, 1.0 - isX.y, 1.0 - isX.z);
		//  i0.y += dot(isYZ.xy, vec2(1.0));
		i0.y += isYZ.x + isYZ.y;
		//i0.zw += 1.0 - vec<2, T, Q>(isYZ.x, isYZ.y);
		i0.z += 1.0 - isYZ.x;
		i0.w += 1.0 - isYZ.y;
		i0.z += isYZ.z;
		i0.w += 1.0 - isYZ.z;

		// i0 now contains the unique values 0,1,2,3 in each channel
		ivec4 i3 = to_ivec4(
			clamp(i0.x, 0.0, 1.0),
			clamp(i0.y, 0.0, 1.0),
			clamp(i0.z, 0.0, 1.0),
			clamp(i0.w, 0.0, 1.0));
		ivec4 i2 = to_ivec4(
			clamp(i0.x - 1.0, 0.0, 1.0),
			clamp(i0.y - 1.0, 0.0, 1.0),
			clamp(i0.z - 1.0, 0.0, 1.0),
			clamp(i0.w - 1.0, 0.0, 1.0));
		ivec4 i1 = to_ivec4(
			clamp(i0.x - 2.0, 0.0, 1.0),
			clamp(i0.y - 2.0, 0.0, 1.0),
			clamp(i0.z - 2.0, 0.0, 1.0),
			clamp(i0.w - 2.0, 0.0, 1.0));

		//  x0 = x0 - 0.0 + 0.0 * C.xxxx
		//  x1 = x0 - i1  + 0.0 * C.xxxx
		//  x2 = x0 - i2  + 0.0 * C.xxxx
		//  x3 = x0 - i3  + 0.0 * C.xxxx
		//  x4 = x0 - 1.0 + 4.0 * C.xxxx
		ivec4 x1 = addv4d(subv4v(x0, i1), C.x);
		ivec4 x2 = addv4d(subv4v(x0, i2), C.y);
		ivec4 x3 = addv4d(subv4v(x0, i3), C.z);
		ivec4 x4 = addv4d(x0, C.w);

		// Permutations
		i = to_ivec4(
			imod(i.x, 289.),
			imod(i.y, 289.),
			imod(i.z, 289.),
			imod(i.w, 289.));
		double j0 = permute_(permute_(permute_(permute_(i.w) + i.z) + i.y) + i.x);
		ivec4 j1 = to_ivec4(
			permute_(permute_(permute_(permute_(i.w + i1.w) + i.z + i1.z) + i.y + i1.y) + i.x + i1.x),
			permute_(permute_(permute_(permute_(i.w + i2.w) + i.z + i2.z) + i.y + i2.y) + i.x + i2.x),
			permute_(permute_(permute_(permute_(i.w + i3.w) + i.z + i3.z) + i.y + i3.y) + i.x + i3.x),
			permute_(permute_(permute_(permute_(i.w + 1.0) + i.z + 1.0) + i.y + 1.0) + i.x + 1.0));

		// Gradients: 7x7x6 points over a cube, mapped onto a 4-cross polytope
		// 7*7*6 = 294, which is close to the ring size 17*17 = 289.
		ivec4 ip = to_ivec4((1.) / (294.), (1.) / (49.), (1.) / (7.), (0.));

		ivec4 p0 = grad4(j0, ip);
		ivec4 p1 = grad4(j1.x, ip);
		ivec4 p2 = grad4(j1.y, ip);
		ivec4 p3 = grad4(j1.z, ip);
		ivec4 p4 = grad4(j1.w, ip);

		// Normalise gradients
		ivec4 norm = to_ivec4(
			taylorInvSqrt_(idot4(p0, p0)),
			taylorInvSqrt_(idot4(p1, p1)),
			taylorInvSqrt_(idot4(p2, p2)),
			taylorInvSqrt_(idot4(p3, p3)));
		p0 = mulv4d(p0, norm.x);
		p1 = mulv4d(p1, norm.y);
		p2 = mulv4d(p2, norm.z);
		p3 = mulv4d(p3, norm.w);
		p4 = mulv4d(p4, taylorInvSqrt_(idot4(p4, p4)));

		// Mix contributions from the five corners
		ivec3 m0 = to_ivec3(
			max(0.6 - idot4(x0, x0), 0.0),
			max(0.6 - idot4(x1, x1), 0.0),
			max(0.6 - idot4(x2, x2), 0.0));//max(T(0.6) - vec<3, T, Q>(dot(x0, x0), dot(x1, x1), dot(x2, x2)), vec<3, T, Q>(0));
		ivec2 m1 = to_ivec2(
			max(0.6 - idot4(x3, x3), 0.0),
			max(0.6 - idot4(x4, x4), 0.0));
		m0 = mulv3v(m0, m0);
		m1 = mulv2v(m1, m1);
		PyObject* out = PyFloat_FromDouble((49.) *
			(idot3(mulv3v(m0, m0), to_ivec3(idot4(p0, x0), idot4(p1, x1), idot4(p2, x2))) +
				idot2(mulv2v(m1, m1), to_ivec2(idot4(p3, x3), idot4(p4, x4)))));
		free(o);
		return out;
	}
	PY_TYPEERROR("unsupported operand type for simplex(): ", arg);
	return NULL;
}