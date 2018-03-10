static PyObject* abs_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(fabs(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(fabs, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for abs(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* floor_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(floor(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(floor, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for floor(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* trunc_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(trunc(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(trunc, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for trunc(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* round_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(round(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(round, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for round(): ", arg);
		return NULL;
	}
	return out;
}

static double roundEven(double x) {
	double IntegerPart = floor(x);
	double FractionalPart = x - IntegerPart;

	if (FractionalPart > 0.5 || FractionalPart < 0.5) {
		return round(x);
	}
	else if (((int)IntegerPart % 2) == 0) {
		return IntegerPart;
	}
	else if (x <= 0.) {
		return IntegerPart - 1.;
	}
	else {
		return IntegerPart + 1.;
	}
}

static PyObject* roundEven_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(roundEven(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(roundEven, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for roundEven(): ", arg);
		return NULL;
	}
	return out;
}

static double sign(double x) {
	if (x > 0.0) return 1.0;
	else if (x < 0.0) return -1.0;
	else return 0.0;
}

static PyObject* sign_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(sign(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(sign, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for sign(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* ceil_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(ceil(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(ceil, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for ceil(): ", arg);
		return NULL;
	}
	return out;
}

static double fract(double x) {
	return x - floor(x);
}

static PyObject* fract_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(fract(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(fract, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for fract(): ", arg);
		return NULL;
	}
	return out;
}

static double imod(double a, double b) {
	return a - b * floor(a / b);
}

static PyObject* mod_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "mod", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(imod(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}

	if (IS_NUMERIC(arg2)) {
		double d = pyvalue_as_double(arg2);
		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			PyObject* out = pack_tvec2(imod(((ivec2*)o)->x, d), imod(((ivec2*)o)->y, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			PyObject* out = pack_tvec3(imod(((ivec3*)o)->x, d), imod(((ivec3*)o)->y, d), imod(((ivec3*)o)->z, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			PyObject* out = pack_tvec4(imod(((ivec4*)o)->x, d), imod(((ivec4*)o)->y, d), imod(((ivec4*)o)->z, d), imod(((ivec4*)o)->w, d));
			free(o);
			return out;
		}
		PY_TYPEERROR_2O("unsupported operand type(s) for mod(): ", arg1, arg2);
		return NULL;
	}

	PyObject * out = functor2(imod, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for mod(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static double minf(double x, double y) {
	return min(x, y);
}

static double maxf(double x, double y) {
	return max(x, y);
}

static PyObject* min_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "min", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(min(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}

	if (IS_NUMERIC(arg2)) {
		double d = pyvalue_as_double(arg2);
		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			PyObject* out = pack_tvec2(minf(((ivec2*)o)->x, d), minf(((ivec2*)o)->y, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			PyObject* out = pack_tvec3(minf(((ivec3*)o)->x, d), minf(((ivec3*)o)->y, d), minf(((ivec3*)o)->z, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			PyObject* out = pack_tvec4(minf(((ivec4*)o)->x, d), minf(((ivec4*)o)->y, d), minf(((ivec4*)o)->z, d), minf(((ivec4*)o)->w, d));
			free(o);
			return out;
		}
		PY_TYPEERROR_2O("unsupported operand type(s) for min(): ", arg1, arg2);
		return NULL;
	}

	PyObject * out = functor2(minf, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for min(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static PyObject* max_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "max", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(max(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}

	if (IS_NUMERIC(arg2)) {
		double d = pyvalue_as_double(arg2);
		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			PyObject* out = pack_tvec2(maxf(((ivec2*)o)->x, d), maxf(((ivec2*)o)->y, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			PyObject* out = pack_tvec3(maxf(((ivec3*)o)->x, d), maxf(((ivec3*)o)->y, d), maxf(((ivec3*)o)->z, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			PyObject* out = pack_tvec4(maxf(((ivec4*)o)->x, d), maxf(((ivec4*)o)->y, d), maxf(((ivec4*)o)->z, d), maxf(((ivec4*)o)->w, d));
			free(o);
			return out;
		}
		PY_TYPEERROR_2O("unsupported operand type(s) for max(): ", arg1, arg2);
		return NULL;
	}

	PyObject * out = functor2(maxf, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for max(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

#define clamp(x, minVal, maxVal) min(max(x,minVal),maxVal)

static PyObject* clamp_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "clamp", arg1, arg2, arg3);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		return PyFloat_FromDouble(clamp(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3)));
	}

	if (IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		double d = pyvalue_as_double(arg2);
		double d2 = pyvalue_as_double(arg3);

		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			PyObject* out = pack_tvec2(clamp(((ivec2*)o)->x, d, d2), clamp(((ivec2*)o)->y, d, d2));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			PyObject* out = pack_tvec3(clamp(((ivec3*)o)->x, d, d2), clamp(((ivec3*)o)->y, d, d2), clamp(((ivec3*)o)->z, d, d2));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			PyObject* out = pack_tvec4(clamp(((ivec4*)o)->x, d, d2), clamp(((ivec4*)o)->y, d, d2), clamp(((ivec4*)o)->z, d, d2), clamp(((ivec4*)o)->w, d, d2));
			free(o);
			return out;
		}
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for clamp()");
		return NULL;
	}
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2, o3;
		if (!unpack_ivec2p(arg2, &o2) || !unpack_ivec2p(arg2, &o3)) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for clamp()");
			return NULL;
		}
		PyObject* out = pack_tvec2(clamp(((ivec2*)o)->x, o2.x, o3.x), clamp(((ivec2*)o)->y, o2.y, o3.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2, o3;
		if (!unpack_ivec3p(arg2, &o2) || !unpack_ivec3p(arg2, &o3)) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for clamp()");
			return NULL;
		}
		PyObject* out = pack_tvec3(clamp(((ivec3*)o)->x, o2.x, o3.x), clamp(((ivec3*)o)->y, o2.y, o3.y), clamp(((ivec3*)o)->z, o2.z, o3.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2, o3;
		if (!unpack_ivec4p(arg2, &o2) || !unpack_ivec4p(arg2, &o3)) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for clamp()");
			return NULL;
		}
		PyObject* out = pack_tvec4(clamp(((ivec4*)o)->x, o2.x, o3.x), clamp(((ivec4*)o)->y, o2.y, o3.y), clamp(((ivec4*)o)->z, o2.z, o3.z), clamp(((ivec4*)o)->w, o2.w, o3.w));
		free(o);
		return out;
	}

	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for clamp()");
	return NULL;
}

#define mixb(x,y,a) a ? y : x

#define mixf(x,y,a) (x + ((double)a) * (y-x))

static double mix(double x, double y, double a) {
	return mixf(x, y, a);
}

static PyObject* mix_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "mix", arg1, arg2, arg3);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		return PyFloat_FromDouble(mixf(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3)));
	}

	if (IS_NUMERIC(arg3)) {
		double d = pyvalue_as_double(arg3);

		void* o = NULL;
		char vecType = unpack_ivecq(arg1, &o);
		if (vecType == GLM_TVEC2) {
			ivec2 o2;
			if (!unpack_ivec2p(arg2, &o2)) {
				free(o);
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
				return NULL;
			}
			PyObject* out = pack_tvec2(mixf(((ivec2*)o)->x, o2.x, d), mixf(((ivec2*)o)->y, o2.y, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			ivec3 o2;
			if (!unpack_ivec3p(arg2, &o2)) {
				free(o);
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
				return NULL;
			}
			PyObject* out = pack_tvec3(mixf(((ivec3*)o)->x, o2.x, d), mixf(((ivec3*)o)->y, o2.y, d), mixf(((ivec3*)o)->z, o2.z, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			ivec4 o2;
			if (!unpack_ivec4p(arg2, &o2)) {
				free(o);
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
				return NULL;
			}
			PyObject* out = pack_tvec4(mixf(((ivec4*)o)->x, o2.x, d), mixf(((ivec4*)o)->y, o2.y, d), mixf(((ivec4*)o)->z, o2.z, d), mixf(((ivec4*)o)->w, o2.w, d));
			free(o);
			return out;
		}
		if (vecType == GLM_TQUAT) {
			iquat o2;
			if (!unpack_iquatp(arg2, &o2)) {
				free(o);
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
				return NULL;
			}

			double cosTheta = idotq(*((iquat*)o), o2);

			// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
			if (cosTheta > (1.0) - DBL_EPSILON)
			{
				// Linear interpolation
				return build_iquat(to_iquatv(
					mixf(((iquat*)o)->w, o2.w, d),
					mixf(((iquat*)o)->x, o2.x, d),
					mixf(((iquat*)o)->y, o2.y, d),
					mixf(((iquat*)o)->z, o2.z, d)));
			}
			else
			{
				// Essential Mathematics, page 467
				double angle = acos(cosTheta);
				return build_iquat(divqd(addqq(mulqd(*((iquat*)o), sin((1.0 - d) * angle)), mulqd(o2, sin(d * angle))), sin(angle)));
			}
		}
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
		return NULL;
	}

	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2, o3;
		if (!unpack_ivec2p(arg2, &o2) || !unpack_ivec2p(arg3, &o3)) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
			return NULL;
		}
		PyObject* out = pack_tvec2(mixf(((ivec2*)o)->x, o2.x, o3.x), mixf(((ivec2*)o)->y, o2.y, o3.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2, o3;
		if (!unpack_ivec3p(arg2, &o2) || !unpack_ivec3p(arg3, &o3)) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
			return NULL;
		}
		PyObject* out = pack_tvec3(mixf(((ivec3*)o)->x, o2.x, o3.x), mixf(((ivec3*)o)->y, o2.y, o3.y), mixf(((ivec3*)o)->z, o2.z, o3.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2, o3;
		if (!unpack_ivec4p(arg2, &o2) || unpack_ivec4p(arg3, &o3)) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
			return NULL;
		}
		PyObject* out = pack_tvec4(mixf(((ivec4*)o)->x, o2.x, o3.x), mixf(((ivec4*)o)->y, o2.y, o3.y), mixf(((ivec4*)o)->z, o2.z, o3.z), mixf(((ivec4*)o)->w, o2.w, o3.w));
		free(o);
		return out;
	}

	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for mix()");
	return NULL;
}

static double step(double x, double y) {
	return mixb(1.0, 0.0, y < x);
}

static PyObject* step_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "step", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(mixb(1.0, 0.0, pyvalue_as_double(arg1) > pyvalue_as_double(arg2)));
	}

	if (IS_NUMERIC(arg1)) {
		double d = pyvalue_as_double(arg1);
		void* o = NULL;
		char vecType = unpack_ivec(arg2, &o);
		if (vecType == GLM_TVEC2) {
			PyObject* out = pack_tvec2(mixb(1.0,0.0, ((ivec2*)o)->x < d), mixb(1.0, 0.0, ((ivec2*)o)->y < d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			PyObject* out = pack_tvec3(mixb(1.0, 0.0, ((ivec3*)o)->x < d), mixb(1.0, 0.0, ((ivec3*)o)->y < d), mixb(1.0, 0.0, ((ivec3*)o)->z < d));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			PyObject* out = pack_tvec4(mixb(1.0, 0.0, ((ivec4*)o)->x < d), mixb(1.0, 0.0, ((ivec4*)o)->y < d), mixb(1.0, 0.0, ((ivec4*)o)->z < d), mixb(1.0, 0.0, ((ivec4*)o)->w < d));
			free(o);
			return out;
		}
		PY_TYPEERROR_2O("unsupported operand type(s) for step(): ", arg1, arg2);
		return NULL;
	}

	PyObject * out = functor2(step, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for step(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static double smoothstep(double edge0, double edge1, double x) {
	double tmp = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	return tmp * tmp * (3.0 - 2.0 * tmp);
}

static PyObject* smoothstep_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "smoothstep", arg1, arg2, arg3);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		return PyFloat_FromDouble(smoothstep(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3)));
	}

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		double edge0 = pyvalue_as_double(arg1);
		double edge1 = pyvalue_as_double(arg2);

		void* o = NULL;
		char vecType = unpack_ivec(arg3, &o);
		if (vecType == GLM_TVEC2) {
			PyObject* out = pack_tvec2(smoothstep(edge0, edge1, ((ivec2*)o)->x), smoothstep(edge0, edge1, ((ivec2*)o)->y));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			PyObject* out = pack_tvec3(smoothstep(edge0, edge1, ((ivec3*)o)->x), smoothstep(edge0, edge1, ((ivec3*)o)->y), smoothstep(edge0, edge1, ((ivec3*)o)->z));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			PyObject* out = pack_tvec4(smoothstep(edge0, edge1, ((ivec4*)o)->x), smoothstep(edge0, edge1, ((ivec4*)o)->y), smoothstep(edge0, edge1, ((ivec4*)o)->z), smoothstep(edge0, edge1, ((ivec4*)o)->w));
			free(o);
			return out;
		}
		free(o);
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for smoothstep()");
		return NULL;
	}

	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2, o3;
		if (!unpack_ivec2p(arg2, &o2) || !unpack_ivec2p(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for smoothstep()");
			return NULL;
		}
		return pack_tvec2(mixf(((ivec2*)o)->x, o2.x, o3.x), mixf(((ivec2*)o)->y, o2.y, o3.y));
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2, o3;
		if (!unpack_ivec3p(arg2, &o2) || !unpack_ivec3p(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for smoothstep()");
			return NULL;
		}
		return pack_tvec3(mixf(((ivec3*)o)->x, o2.x, o3.x), mixf(((ivec3*)o)->y, o2.y, o3.y), mixf(((ivec3*)o)->z, o2.z, o3.z));
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2, o3;
		if (!unpack_ivec4p(arg2, &o2) || !unpack_ivec4p(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for smoothstep()");
			return NULL;
		}
		return pack_tvec4(mixf(((ivec4*)o)->x, o2.x, o3.x), mixf(((ivec4*)o)->y, o2.y, o3.y), mixf(((ivec4*)o)->z, o2.z, o3.z), mixf(((ivec4*)o)->w, o2.w, o3.w));
	}

	free(o);
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for smoothstep()");
	return NULL;
}

static double isnanf_(double x) {
	return isnan(x);
}


static PyObject* isnan_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		if (isnan(pyvalue_as_double(arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (IS_TQUAT(arg)) {
		iquat q;
		if (!unpack_iquatp(arg, &q)) {
			PY_TYPEERROR("unsupported operand type for isnan(): ", arg);
			return NULL;
		}
		return pack_tvec4(isnan(q.x), isnan(q.y), isnan(q.z), isnan(q.w));
	}
	PyObject * out = functor1(isnanf_, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for isnan(): ", arg);
		return NULL;
	}
	return out;
}

static double isinff_(double x) {
	return isinf(x);
}

static PyObject* isinf_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		if (isinf(pyvalue_as_double(arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (IS_TQUAT(arg)) {
		iquat q;
		if (!unpack_iquatp(arg, &q)) {
			PY_TYPEERROR("unsupported operand type for isnan(): ", arg);
			return NULL;
		}
		return pack_tvec4(isinf(q.x), isinf(q.y), isinf(q.z), isinf(q.w));
	}
	PyObject * out = functor1(isinff_, arg);

	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for isinf(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* fma_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "fma", arg1, arg2, arg3);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		return PyFloat_FromDouble(fma(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3)));
	}

	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for fma()");
	return NULL;
}

static double frexpf_(double x, double y) {
	int d = (int)y;
	return frexp(x, &d);
}

static PyObject* frexp_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "frexp", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		
		return PyFloat_FromDouble(frexpf_(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}

	PyObject * out = functor2(frexpf_, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for frexp(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static double ldexpf_(double x, double y) {
	return ldexp(x, (int)y);
}

static PyObject* ldexp_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "ldexp", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {

		return PyFloat_FromDouble(ldexpf_(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}

	PyObject * out = functor2(ldexpf_, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for ldexp(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static char * attr_name_to_cstr(PyObject * name) {
#if PY3K
	return PyBytes_AsString(PyUnicode_AsASCIIString(name));
#else
	return PyString_AsString(name);
#endif
}
