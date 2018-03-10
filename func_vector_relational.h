static PyObject* equal(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "equal", arg1, arg2);

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2;

		if (!unpack_ivec2p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for equal(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x == o2.x), (double)(((ivec2*)o)->y == o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;

		if (!unpack_ivec3p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for equal(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x == o2.x), (double)(((ivec3*)o)->y == o2.y), (double)(((ivec3*)o)->z == o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;

		if (!unpack_ivec4p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for equal(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x == o2.x), (double)(((ivec4*)o)->y == o2.y), (double)(((ivec4*)o)->z == o2.z), (double)(((ivec4*)o)->w == o2.w));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat o2;

		if (!unpack_iquatp(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for equal(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tquat((double)(((iquat*)o)->x == o2.x), (double)(((iquat*)o)->y == o2.y), (double)(((iquat*)o)->z == o2.z), (double)(((iquat*)o)->w == o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for equal(): ", arg1, arg2);
	return NULL;
}

static PyObject* notEqual(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "equal", arg1, arg2);

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2;

		if (!unpack_ivec2p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x != o2.x), (double)(((ivec2*)o)->y != o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;

		if (!unpack_ivec3p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x != o2.x), (double)(((ivec3*)o)->y != o2.y), (double)(((ivec3*)o)->z != o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;

		if (!unpack_ivec4p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x != o2.x), (double)(((ivec4*)o)->y != o2.y), (double)(((ivec4*)o)->z != o2.z), (double)(((ivec4*)o)->w != o2.w));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat o2;

		if (!unpack_iquatp(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tquat((double)(((iquat*)o)->x != o2.x), (double)(((iquat*)o)->y != o2.y), (double)(((iquat*)o)->z != o2.z), (double)(((iquat*)o)->w != o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for notEqual(): ", arg1, arg2);
	return NULL;
}

static PyObject* lessThan(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "lessThan", arg1, arg2);

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2;

		if (!unpack_ivec2p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x < o2.x), (double)(((ivec2*)o)->y < o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;

		if (!unpack_ivec3p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x < o2.x), (double)(((ivec3*)o)->y < o2.y), (double)(((ivec3*)o)->z < o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;

		if (!unpack_ivec4p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x < o2.x), (double)(((ivec4*)o)->y < o2.y), (double)(((ivec4*)o)->z < o2.z), (double)(((ivec4*)o)->w < o2.w));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat o2;

		if (!unpack_iquatp(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tquat((double)(((iquat*)o)->x < o2.x), (double)(((iquat*)o)->y < o2.y), (double)(((iquat*)o)->z < o2.z), (double)(((iquat*)o)->w < o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for lessThan(): ", arg1, arg2);
	return NULL;
}

static PyObject* lessThanEqual(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "lessThanEqual", arg1, arg2);

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2;

		if (!unpack_ivec2p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x <= o2.x), (double)(((ivec2*)o)->y <= o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;

		if (!unpack_ivec3p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x <= o2.x), (double)(((ivec3*)o)->y <= o2.y), (double)(((ivec3*)o)->z <= o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;

		if (!unpack_ivec4p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x <= o2.x), (double)(((ivec4*)o)->y <= o2.y), (double)(((ivec4*)o)->z <= o2.z), (double)(((ivec4*)o)->w <= o2.w));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat o2;

		if (!unpack_iquatp(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tquat((double)(((iquat*)o)->x <= o2.x), (double)(((iquat*)o)->y <= o2.y), (double)(((iquat*)o)->z <= o2.z), (double)(((iquat*)o)->w <= o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for lessThanEqual(): ", arg1, arg2);
	return NULL;
}

static PyObject* greaterThan(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "greaterThan", arg1, arg2);

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2;

		if (!unpack_ivec2p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x > o2.x), (double)(((ivec2*)o)->y > o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;

		if (!unpack_ivec3p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x > o2.x), (double)(((ivec3*)o)->y > o2.y), (double)(((ivec3*)o)->z > o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;

		if (!unpack_ivec4p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x > o2.x), (double)(((ivec4*)o)->y > o2.y), (double)(((ivec4*)o)->z > o2.z), (double)(((ivec4*)o)->w > o2.w));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat o2;

		if (!unpack_iquatp(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tquat((double)(((iquat*)o)->x > o2.x), (double)(((iquat*)o)->y > o2.y), (double)(((iquat*)o)->z > o2.z), (double)(((iquat*)o)->w > o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for greaterThan(): ", arg1, arg2);
	return NULL;
}

static PyObject* greaterThanEqual(PyObject * self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "greaterThanEqual", arg1, arg2);

	void* o = NULL;
	char vecType = unpack_ivecq(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 o2;

		if (!unpack_ivec2p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x >= o2.x), (double)(((ivec2*)o)->y >= o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;

		if (!unpack_ivec3p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x >= o2.x), (double)(((ivec3*)o)->y >= o2.y), (double)(((ivec3*)o)->z >= o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;

		if (!unpack_ivec4p(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x >= o2.x), (double)(((ivec4*)o)->y >= o2.y), (double)(((ivec4*)o)->z >= o2.z), (double)(((ivec4*)o)->w >= o2.w));
		free(o);
		return out;
	}
	if (vecType == GLM_TQUAT) {
		iquat o2;

		if (!unpack_iquatp(arg2, &o2)) {
			free(o);
			PY_TYPEERROR_2O("unsupported operand type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}

		PyObject* out = pack_tquat((double)(((iquat*)o)->x >= o2.x), (double)(((iquat*)o)->y >= o2.y), (double)(((iquat*)o)->z >= o2.z), (double)(((iquat*)o)->w >= o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for greaterThanEqual(): ", arg1, arg2);
	return NULL;
}

static PyObject* any(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);
	if (vecType == GLM_TVEC2) {
		PyObject* out = PyBool_FromLong((int)((((ivec2*)o)->x != 0) || (((ivec2*)o)->y != 0)));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		PyObject* out = PyBool_FromLong((int)((((ivec3*)o)->x != 0) || (((ivec3*)o)->y != 0) || (((ivec3*)o)->z != 0)));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		PyObject* out = PyBool_FromLong((int)((((ivec4*)o)->x != 0) || (((ivec4*)o)->y != 0) || (((ivec4*)o)->z != 0) || (((ivec4*)o)->w != 0)));
		free(o);
		return out;
	}
	PY_TYPEERROR("unsupported operand type for any(): ", arg);
	return NULL;
}

static PyObject* all(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);
	if (vecType == GLM_TVEC2) {
		PyObject* out = PyBool_FromLong((int)((((ivec2*)o)->x != 0) && (((ivec2*)o)->y != 0)));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		PyObject* out = PyBool_FromLong((int)((((ivec3*)o)->x != 0) && (((ivec3*)o)->y != 0) && (((ivec3*)o)->z != 0)));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		PyObject* out = PyBool_FromLong((int)((((ivec4*)o)->x != 0) && (((ivec4*)o)->y != 0) && (((ivec4*)o)->z != 0) && (((ivec4*)o)->w != 0)));
		free(o);
		return out;
	}
	PY_TYPEERROR("unsupported operand type for all(): ", arg);
	return NULL;
}

static PyObject* not_(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);
	if (vecType == GLM_TVEC2) {
		PyObject* out = pack_tvec2((double)(((ivec2*)o)->x == 0), (double)(((ivec2*)o)->y == 0));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		PyObject* out = pack_tvec3((double)(((ivec3*)o)->x == 0), (double)(((ivec3*)o)->y == 0), (double)(((ivec3*)o)->z == 0));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		PyObject* out = pack_tvec4((double)(((ivec4*)o)->x == 0), (double)(((ivec4*)o)->y == 0), (double)(((ivec4*)o)->z == 0), (double)(((ivec4*)o)->w == 0));
		free(o);
		return out;
	}
	PY_TYPEERROR("unsupported operand type for not(): ", arg);
	return NULL;
}