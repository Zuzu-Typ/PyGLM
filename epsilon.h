static int epsilonEqual_(double x, double y, double epsilon) {
	return fabs(x - y) < epsilon;
}

static PyObject* epsilonEqual(PyObject* self, PyObject* args) {
	PyObject *x, *y, *epsilon;
	UNPACK_3_VARARGS(args, "epsilonEqual", x, y, epsilon);
	if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(epsilon)) {
		return PyBool_FromLong(epsilonEqual_(pyvalue_as_double(x), pyvalue_as_double(y), pyvalue_as_double(epsilon)));
	}

	if (IS_TQUAT(x) && IS_TQUAT(y) && IS_NUMERIC(epsilon)) {
		iquat o, o2;
		unpack_iquatp(x, &o);
		unpack_iquatp(y, &o2);
		return pack_tvec4(
			epsilonEqual_(o.x, o2.x, pyvalue_as_double(epsilon)),
			epsilonEqual_(o.y, o2.y, pyvalue_as_double(epsilon)),
			epsilonEqual_(o.z, o2.z, pyvalue_as_double(epsilon)),
			epsilonEqual_(o.w, o2.w, pyvalue_as_double(epsilon)));
	}

	void* o = NULL;
	char vecType = unpack_ivec(x, &o);

	if (vecType != GLM_NONE) {
		if (IS_NUMERIC(epsilon)) {
			if (vecType == GLM_TVEC2) {
				ivec2 o2;
				if (!unpack_ivec2p(y, &o2)) {
					PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
					return NULL;
				}
				PyObject* out = pack_tvec2(
					epsilonEqual_(((ivec2*)o)->x,o2.x,pyvalue_as_double(epsilon)),
					epsilonEqual_(((ivec2*)o)->y, o2.y, pyvalue_as_double(epsilon)));
				free(o);
				return out;
			}
			if (vecType == GLM_TVEC3) {
				ivec3 o2;
				if (!unpack_ivec3p(y, &o2)) {
					PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
					return NULL;
				}
				PyObject* out = pack_tvec3(
					epsilonEqual_(((ivec3*)o)->x, o2.x, pyvalue_as_double(epsilon)),
					epsilonEqual_(((ivec3*)o)->y, o2.y, pyvalue_as_double(epsilon)),
					epsilonEqual_(((ivec3*)o)->z, o2.z, pyvalue_as_double(epsilon)));
				free(o);
				return out;
			}
			if (vecType == GLM_TVEC4) {
				ivec4 o2;
				if (!unpack_ivec4p(y, &o2)) {
					PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
					return NULL;
				}
				PyObject* out = pack_tvec4(
					epsilonEqual_(((ivec4*)o)->x, o2.x, pyvalue_as_double(epsilon)),
					epsilonEqual_(((ivec4*)o)->y, o2.y, pyvalue_as_double(epsilon)),
					epsilonEqual_(((ivec4*)o)->z, o2.z, pyvalue_as_double(epsilon)),
					epsilonEqual_(((ivec4*)o)->w, o2.w, pyvalue_as_double(epsilon)));
				free(o);
				return out;
			}
		}
		if (vecType == GLM_TVEC2) {
			ivec2 o2, o3;
			if (!unpack_ivec2p(y, &o2)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
				return NULL;
			}
			if (!unpack_ivec2p(epsilon, &o3)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
				return NULL;
			}
			PyObject* out = pack_tvec2(
				epsilonEqual_(((ivec2*)o)->x, o2.x, (o3.x)),
				epsilonEqual_(((ivec2*)o)->y, o2.y, (o3.y)));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			ivec3 o2, o3;
			if (!unpack_ivec3p(y, &o2)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
				return NULL;
			}
			if (!unpack_ivec3p(epsilon, &o3)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
				return NULL;
			}
			PyObject* out = pack_tvec3(
				epsilonEqual_(((ivec3*)o)->x, o2.x, (o3.x)),
				epsilonEqual_(((ivec3*)o)->y, o2.y, (o3.y)),
				epsilonEqual_(((ivec3*)o)->z, o2.z, (o3.z)));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			ivec4 o2, o3;
			if (!unpack_ivec4p(y, &o2)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
				return NULL;
			}
			if (!unpack_ivec4p(epsilon, &o3)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
				return NULL;
			}
			PyObject* out = pack_tvec4(
				epsilonEqual_(((ivec4*)o)->x, o2.x, (o3.x)),
				epsilonEqual_(((ivec4*)o)->y, o2.y, (o3.y)),
				epsilonEqual_(((ivec4*)o)->z, o2.z, (o3.z)),
				epsilonEqual_(((ivec4*)o)->w, o2.w, (o3.w)));
			free(o);
			return out;
		}
	}
	
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonEqual()");
	return NULL;
}

static int epsilonNotEqual_(double x, double y, double epsilon) {
	return fabs(x - y) >= epsilon;
}

static PyObject* epsilonNotEqual(PyObject* self, PyObject* args) {
	PyObject *x, *y, *epsilon;
	UNPACK_3_VARARGS(args, "epsilonNotEqual", x, y, epsilon);
	if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(epsilon)) {
		return PyBool_FromLong(epsilonNotEqual_(pyvalue_as_double(x), pyvalue_as_double(y), pyvalue_as_double(epsilon)));
	}

	if (IS_TQUAT(x) && IS_TQUAT(y) && IS_NUMERIC(epsilon)) {
		iquat o, o2;
		unpack_iquatp(x, &o);
		unpack_iquatp(y, &o2);
		return pack_tvec4(
			epsilonNotEqual_(o.x, o2.x, pyvalue_as_double(epsilon)),
			epsilonNotEqual_(o.y, o2.y, pyvalue_as_double(epsilon)),
			epsilonNotEqual_(o.z, o2.z, pyvalue_as_double(epsilon)),
			epsilonNotEqual_(o.w, o2.w, pyvalue_as_double(epsilon)));
	}

	void* o = NULL;
	char vecType = unpack_ivec(x, &o);

	if (vecType != GLM_NONE) {
		if (IS_NUMERIC(epsilon)) {
			if (vecType == GLM_TVEC2) {
				ivec2 o2;
				if (!unpack_ivec2p(y, &o2)) {
					PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
					return NULL;
				}
				PyObject* out = pack_tvec2(
					epsilonNotEqual_(((ivec2*)o)->x, o2.x, pyvalue_as_double(epsilon)),
					epsilonNotEqual_(((ivec2*)o)->y, o2.y, pyvalue_as_double(epsilon)));
				free(o);
				return out;
			}
			if (vecType == GLM_TVEC3) {
				ivec3 o2;
				if (!unpack_ivec3p(y, &o2)) {
					PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
					return NULL;
				}
				PyObject* out = pack_tvec3(
					epsilonNotEqual_(((ivec3*)o)->x, o2.x, pyvalue_as_double(epsilon)),
					epsilonNotEqual_(((ivec3*)o)->y, o2.y, pyvalue_as_double(epsilon)),
					epsilonNotEqual_(((ivec3*)o)->z, o2.z, pyvalue_as_double(epsilon)));
				free(o);
				return out;
			}
			if (vecType == GLM_TVEC4) {
				ivec4 o2;
				if (!unpack_ivec4p(y, &o2)) {
					PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
					return NULL;
				}
				PyObject* out = pack_tvec4(
					epsilonNotEqual_(((ivec4*)o)->x, o2.x, pyvalue_as_double(epsilon)),
					epsilonNotEqual_(((ivec4*)o)->y, o2.y, pyvalue_as_double(epsilon)),
					epsilonNotEqual_(((ivec4*)o)->z, o2.z, pyvalue_as_double(epsilon)),
					epsilonNotEqual_(((ivec4*)o)->w, o2.w, pyvalue_as_double(epsilon)));
				free(o);
				return out;
			}
		}
		if (vecType == GLM_TVEC2) {
			ivec2 o2, o3;
			if (!unpack_ivec2p(y, &o2)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
				return NULL;
			}
			if (!unpack_ivec2p(epsilon, &o3)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
				return NULL;
			}
			PyObject* out = pack_tvec2(
				epsilonNotEqual_(((ivec2*)o)->x, o2.x, (o3.x)),
				epsilonNotEqual_(((ivec2*)o)->y, o2.y, (o3.y)));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			ivec3 o2, o3;
			if (!unpack_ivec3p(y, &o2)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
				return NULL;
			}
			if (!unpack_ivec3p(epsilon, &o3)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
				return NULL;
			}
			PyObject* out = pack_tvec3(
				epsilonNotEqual_(((ivec3*)o)->x, o2.x, (o3.x)),
				epsilonNotEqual_(((ivec3*)o)->y, o2.y, (o3.y)),
				epsilonNotEqual_(((ivec3*)o)->z, o2.z, (o3.z)));
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			ivec4 o2, o3;
			if (!unpack_ivec4p(y, &o2)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
				return NULL;
			}
			if (!unpack_ivec4p(epsilon, &o3)) {
				PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
				return NULL;
			}
			PyObject* out = pack_tvec4(
				epsilonNotEqual_(((ivec4*)o)->x, o2.x, (o3.x)),
				epsilonNotEqual_(((ivec4*)o)->y, o2.y, (o3.y)),
				epsilonNotEqual_(((ivec4*)o)->z, o2.z, (o3.z)),
				epsilonNotEqual_(((ivec4*)o)->w, o2.w, (o3.w)));
			free(o);
			return out;
		}
	}

	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for epsilonNotEqual()");
	return NULL;
}