

static PyObject * dot(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "dot", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(pyvalue_as_double(arg1) * pyvalue_as_double(arg2));
	}

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 * o2 = unpack_ivec2(arg2);

		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for dot(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(idot2((*(ivec2*)o), *o2));
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 * o2 = unpack_ivec3(arg2);

		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for dot(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(idot3((*(ivec3*)o), *o2));
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 * o2 = unpack_ivec4(arg2);

		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for dot(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(idot4((*(ivec4*)o), *o2));
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat * o2 = unpack_iquat(arg2);
		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for dot(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(idotq(*((iquat*)o), *o2));
		free(o);
		free(o2);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for dot(): ", arg1, arg2);
	return NULL;
}

static double ilength2(ivec2 o) {
	return sqrt(o.x * o.x + o.y * o.y);
}
static double ilength3(ivec3 o) {
	return sqrt(o.x * o.x + o.y * o.y + o.z * o.z);
}
static double ilength4(ivec4 o) {
	return sqrt(o.x * o.x + o.y * o.y + o.z * o.z + o.w * o.w);
}

//static double ilength2p(void* o) {
//	return sqrt(((ivec2*)o)->x * ((ivec2*)o)->x + ((ivec2*)o)->y * ((ivec2*)o)->y);
//}
//static double ilength3p(void* o) {
//	return sqrt(((ivec3*)o)->x * ((ivec3*)o)->x + ((ivec3*)o)->y * ((ivec3*)o)->y + ((ivec3*)o)->z * ((ivec3*)o)->z);
//}
//static double ilength4p(void* o) {
//	return sqrt(((ivec4*)o)->x * ((ivec4*)o)->x + ((ivec4*)o)->y * ((ivec4*)o)->y + ((ivec4*)o)->z * ((ivec4*)o)->z + ((ivec4*)o)->w * ((ivec4*)o)->w);
//}

static PyObject * length(PyObject * self, PyObject * arg) {
	if (IS_NUMERIC(arg)) {
		return PyObject_CallMethod(arg, "__abs__", "()");
	}
	void* o = NULL;
	char vecType = unpack_ivecq(arg, &o);
	if (vecType == GLM_TVEC2) {
		PyObject* out = PyFloat_FromDouble(ilength2(*((ivec2*)o)));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		PyObject* out = PyFloat_FromDouble(ilength3(*((ivec3*)o)));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		PyObject* out = PyFloat_FromDouble(ilength4(*((ivec4*)o)));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		PyObject* out = PyFloat_FromDouble(ilengthq(*((iquat*)o)));
		free(o);
		return out;
	}
	PY_TYPEERROR("unsupported operand type(s) for length(): ", arg);
	return NULL;
}

static PyObject * distance(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "distance", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(fabs(pyvalue_as_double(arg2) - pyvalue_as_double(arg1)));
	}
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2* o2 = unpack_ivec2(arg2);
		if (o2 == NULL) {
			PY_TYPEERROR_2O("unsupported operand type(s) for distance(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(ilength2(subv2v(*o2, *((ivec2*)o))));
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3* o2 = unpack_ivec3(arg2);
		if (o2 == NULL) {
			PY_TYPEERROR_2O("unsupported operand type(s) for distance(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(ilength3(subv3v(*o2, *((ivec3*)o))));
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4* o2 = unpack_ivec4(arg2);
		if (o2 == NULL) {
			PY_TYPEERROR_2O("unsupported operand type(s) for distance(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = PyFloat_FromDouble(ilength4(subv4v(*o2, *((ivec4*)o))));
		free(o);
		free(o2);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for distance(): ", arg1, arg2);
	return NULL;
}

static PyObject * cross(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "cross", arg1, arg2);

	void* o = NULL;
	char type = unpack_pyobject(arg1, &o, GLM_HAS_TVEC3 | GLM_HAS_TQUAT);
	if (type == GLM_TVEC3) {
		ivec3 * o2 = unpack_ivec3(arg2);

		if (o2 == NULL) {
			PY_TYPEERROR_2O("unsupported operand type(s) for cross(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec3(
			((ivec3*)o)->y * o2->z - o2->y * ((ivec3*)o)->z,
			((ivec3*)o)->z * o2->x - o2->z * ((ivec3*)o)->x,
			((ivec3*)o)->x * o2->y - o2->x * ((ivec3*)o)->y);
		free(o);
		free(o2);
		return out;
	}
	if (type == GLM_TQUAT) {
		iquat* q2 = unpack_iquat(arg2);
		if (q2 == NULL) {
			PY_TYPEERROR_2O("unsupported operand type(s) for cross(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = build_iquat(to_iquatv(
			((iquat*)o)->w * q2->w - ((iquat*)o)->x * q2->x - ((iquat*)o)->y * q2->y - ((iquat*)o)->z * q2->z,
			((iquat*)o)->w * q2->x + ((iquat*)o)->x * q2->w + ((iquat*)o)->y * q2->z - ((iquat*)o)->z * q2->y,
			((iquat*)o)->w * q2->y + ((iquat*)o)->y * q2->w + ((iquat*)o)->z * q2->x - ((iquat*)o)->x * q2->z,
			((iquat*)o)->w * q2->z + ((iquat*)o)->z * q2->w + ((iquat*)o)->x * q2->y - ((iquat*)o)->y * q2->x));
		free(o);
		free(q2);
		return out;
	}

	PY_TYPEERROR_2O("unsupported operand type(s) for cross(): ", arg1, arg2);
	return NULL;
}

static ivec2 inormalize2(ivec2 o) {
	double dotp = ilength2(o);
	return to_ivec2((o.x / dotp), (o.y / dotp));
}

static ivec3 inormalize3(ivec3 o) {
	double dotp = ilength3(o);
	return to_ivec3((o.x / dotp), (o.y / dotp), (o.z / dotp));
}

static ivec4 inormalize4(ivec4 o) {
	double dotp = ilength4(o);
	return to_ivec4((o.x / dotp), (o.y / dotp), (o.z / dotp), (o.w / dotp));
}

//static ivec2* inormalize2p(void* o) {
//	double dotp = ilength2p(((ivec2*)o));
//	return to_ivec2p((((ivec2*)o)->x / dotp), (((ivec2*)o)->y / dotp));
//}
//
//static ivec3* inormalize3p(void* o) {
//	double dotp = ilength3p(((ivec3*)o));
//	return to_ivec3p((((ivec3*)o)->x / dotp), (((ivec3*)o)->y / dotp), (((ivec3*)o)->z / dotp));
//}
//
//static ivec4* inormalize4p(void* o) {
//	double dotp = ilength4p(((ivec4*)o));
//	return to_ivec4p((((ivec4*)o)->x / dotp), (((ivec4*)o)->y / dotp), (((ivec4*)o)->z / dotp), (((ivec4*)o)->w / dotp));
//}

//#define NORMALIZE2_(o, d) to_tvec2((((tvec2*)o)->x / d), (((tvec2*)o)->y / d))
//#define NORMALIZE2(o) NORMALIZE2_(o, DOT2(o,o))
//
//#define NORMALIZE3_(o, d) to_tvec3((((tvec3*)o)->x / d), (((tvec3*)o)->y / d), (((tvec3*)o)->z / d))
//#define NORMALIZE3(o) NORMALIZE3_(o, DOT3(o,o))
//
//#define NORMALIZE4_(o, d) to_tvec4((((tvec4*)o)->x / d), (((tvec4*)o)->y / d), (((tvec4*)o)->z / d), (((tvec4*)o)->w / d))
//#define NORMALIZE4(o) NORMALIZE4_(o, DOT4(o,o))
//
//#define NORMALIZE2P_(o, d) pack_tvec2((((tvec2*)o)->x / d), (((tvec2*)o)->y / d))
//#define NORMALIZE2P(o) NORMALIZE2P_(o, DOT2(o,o))
//
//#define NORMALIZE3P_(o, d) pack_tvec3((((tvec3*)o)->x / d), (((tvec3*)o)->y / d), (((tvec3*)o)->z / d))
//#define NORMALIZE3P(o) NORMALIZE3P_(o, DOT3(o,o))
//
//#define NORMALIZE4P_(o, d) pack_tvec4((((tvec4*)o)->x / d), (((tvec4*)o)->y / d), (((tvec4*)o)->z / d), (((tvec4*)o)->w / d))
//#define NORMALIZE4P(o) NORMALIZE4P_(o, DOT4(o,o))

static PyObject * normalize(PyObject * self, PyObject * arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble((pyvalue_as_double(arg) < 0.0) ? -1.0 : 1.0);
	}
	void* o = NULL;
	char vecType = unpack_ivecq(arg, &o);
	if (vecType == GLM_TVEC2) {
		return build_ivec2(inormalize2(*((ivec2*)o)));
	}
	if (vecType == GLM_TVEC3) {
		return build_ivec3(inormalize3(*((ivec3*)o)));
	}
	if (vecType == GLM_TVEC4) {
		return build_ivec4(inormalize4(*((ivec4*)o)));
	}
	if (vecType == GLM_TQUAT) {
		return build_iquat(inormalizeq(*((iquat*)o)));
	}
	PY_TYPEERROR("unsupported operand type(s) for normalize(): ", arg);
	return NULL;
}

static PyObject * faceforward(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "faceforward", arg1, arg2, arg3);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		return PyFloat_FromDouble(((pyvalue_as_double(arg3) * pyvalue_as_double(arg2)) < 0.0) ? pyvalue_as_double(arg1) : -pyvalue_as_double(arg1));
	}
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2* o2 = unpack_ivec2(arg2);
		ivec2* o3 = unpack_ivec2(arg3);
		if (o2 == NULL || o3 == NULL) {
			free(o);
			free(o2);
			free(o3);
			PyErr_SetString(PyExc_TypeError,"unsupported operand type(s) for faceforward()");
			return NULL;
		}
		PyObject* out = (idot2p(o3,o2) < 0.0) ? pack_tvec2(((ivec2*)o)->x, ((ivec2*)o)->y) : pack_tvec2(-((ivec2*)o)->x, -((ivec2*)o)->y);
		free(o);
		free(o2);
		free(o3);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3* o2 = unpack_ivec3(arg2);
		ivec3* o3 = unpack_ivec3(arg3);
		if (o2 == NULL || o3 == NULL) {
			free(o);
			free(o2);
			free(o3);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for faceforward()");
			return NULL;
		}
		PyObject* out = (idot3p(o3, o2) < 0.0) ? pack_tvec3(((ivec3*)o)->x, ((ivec3*)o)->y, ((ivec3*)o)->z) : pack_tvec3(-((ivec3*)o)->x, -((ivec3*)o)->y, -((ivec3*)o)->z);
		free(o);
		free(o2);
		free(o3);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4* o2 = unpack_ivec4(arg2);
		ivec4* o3 = unpack_ivec4(arg3);
		if (o2 == NULL || o3 == NULL) {
			free(o);
			free(o2);
			free(o3);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for faceforward()");
			return NULL;
		}
		PyObject* out = (idot4p(o3, o2) < 0.0) ? pack_tvec4(((ivec4*)o)->x, ((ivec4*)o)->y, ((ivec4*)o)->z, ((ivec4*)o)->w) : pack_tvec4(-((ivec4*)o)->x, -((ivec4*)o)->y, -((ivec4*)o)->z, -((ivec4*)o)->w);
		free(o);
		free(o2);
		free(o3);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for faceforward()");
	return NULL;
}

static PyObject * reflect(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "reflect", arg1, arg2);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		double I = pyvalue_as_double(arg1);
		double N = pyvalue_as_double(arg2);
		return PyFloat_FromDouble(I - N * (N*I) * 2.0);
	}
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2* o2 = unpack_ivec2(arg2);
		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for reflect(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec2(
			((ivec2*)o)->x - o2->x * idot2(*o2, *((ivec2*)o)) * 2.0,
			((ivec2*)o)->y - o2->y * idot2(*o2, *((ivec2*)o)) * 2.0);
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3* o2 = unpack_ivec3(arg2);
		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for reflect(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec3(
			((ivec3*)o)->x - o2->x * idot3(*o2, *((ivec3*)o)) * 2.0,
			((ivec3*)o)->y - o2->y * idot3(*o2, *((ivec3*)o)) * 2.0,
			((ivec3*)o)->z - o2->z * idot3(*o2, *((ivec3*)o)) * 2.0);
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4* o2 = unpack_ivec4(arg2);
		if (o2 == NULL) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for reflect(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec4(
			((ivec4*)o)->x - o2->x * idot4(*o2, *((ivec4*)o)) * 2.0,
			((ivec4*)o)->y - o2->y * idot4(*o2, *((ivec4*)o)) * 2.0,
			((ivec4*)o)->z - o2->z * idot4(*o2, *((ivec4*)o)) * 2.0,
			((ivec4*)o)->w - o2->w * idot4(*o2, *((ivec4*)o)) * 2.0);
		free(o);
		free(o2);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for reflect(): ", arg1, arg2);
	return NULL;
}

#define REFRACT_SINGLE(I,N,eta, dotValue, k) ((eta * I - (eta * dotValue +sqrt(k)) * N) * (double)(k >= 0.0))

static PyObject * refract(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "refract", arg1, arg2, arg3);

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		double I = pyvalue_as_double(arg1);
		double N = pyvalue_as_double(arg2);
		double eta = pyvalue_as_double(arg3);
		double dotValue = (N*I);
		double k = (1.0 - eta * eta * (1.0 - dotValue * dotValue));
		return PyFloat_FromDouble(REFRACT_SINGLE(I,N,eta,dotValue,k));
	}
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2* o2 = unpack_ivec2(arg2);
		if (o2 == NULL || !IS_NUMERIC(arg3)) {
			free(o);
			free(o2);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for refract()");
			return NULL;
		}
		double eta = pyvalue_as_double(arg3);
		double dotValue = idot2p(o2,o);
		double k = (1.0 - eta * eta * (1.0 - dotValue * dotValue));
		PyObject* out =  pack_tvec2(
			REFRACT_SINGLE(((ivec2*)o)->x, o2->x, eta, dotValue, k),
			REFRACT_SINGLE(((ivec2*)o)->y, o2->y, eta, dotValue, k));
		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3* o2 = unpack_ivec3(arg2);
		if (o2 == NULL || !IS_NUMERIC(arg3)) {
			free(o);
			free(o2);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for refract()");
			return NULL;
		}
		double eta = pyvalue_as_double(arg3);
		double dotValue = idot3p(o2, o);
		double k = (1.0 - eta * eta * (1.0 - dotValue * dotValue));
		PyObject* out = pack_tvec3(
			REFRACT_SINGLE(((ivec3*)o)->x, o2->x, eta, dotValue, k),
			REFRACT_SINGLE(((ivec3*)o)->y, o2->y, eta, dotValue, k),
			REFRACT_SINGLE(((ivec3*)o)->z, o2->z, eta, dotValue, k));

		free(o);
		free(o2);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4* o2 = unpack_ivec4(arg2);
		if (o2 == NULL || !IS_NUMERIC(arg3)) {
			free(o);
			free(o2);
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for refract()");
			return NULL;
		}
		double eta = pyvalue_as_double(arg3);
		double dotValue = idot4p(o2, o);
		double k = (1.0 - eta * eta * (1.0 - dotValue * dotValue));
		PyObject* out = pack_tvec4(
			REFRACT_SINGLE(((ivec4*)o)->x, o2->x, eta, dotValue, k),
			REFRACT_SINGLE(((ivec4*)o)->y, o2->y, eta, dotValue, k),
			REFRACT_SINGLE(((ivec4*)o)->z, o2->z, eta, dotValue, k),
			REFRACT_SINGLE(((ivec4*)o)->w, o2->w, eta, dotValue, k));
		free(o);
		free(o2);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for refract()");
	return NULL;
}