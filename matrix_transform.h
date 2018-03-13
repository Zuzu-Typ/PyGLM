static PyObject* translate(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2;
	UNPACK_2_VARARGS(args, "translate", arg1, arg2);
	imat4x4 m;
	if (!unpack_imat4x4p(arg1, &m)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for translate(): ", arg1, arg2);
		return NULL;
	}
	ivec3 v;
	if (!unpack_ivec3p(arg2, &v)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for translate(): ", arg1, arg2);
		return NULL;
	}
	return build_imat4x4(to_imat4x4v(
		m.x,
		m.y,
		m.z,
		addv4v(addv4v(addv4v(mulv4d(m.x, v.x), mulv4d(m.y, v.y)), mulv4d(m.z, v.z)), m.w)));
}

static PyObject* rotate(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "rotate", arg1, arg2, arg3);
	if (!IS_NUMERIC(arg2)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for rotate()");
		return NULL;
	}
	double a = pyvalue_as_double(arg2);

	ivec3 v;
	if (!unpack_ivec3p(arg3, &v)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for rotate()");
		return NULL;
	}
	void* o = NULL;
	char type = unpack_pyobject(arg1, &o, GLM_HAS_TMAT4x4 | GLM_HAS_TQUAT);
	if (type == GLM_TMAT4x4) {
		double c = cos(a);
		double s = sin(a);

		ivec3 axis = (inormalize3(v));
		ivec3 temp = rmulv3d(((1.) - c), axis);

		imat3x3 Rotate = to_imat3x3(
			c + temp.x * axis.x, temp.x * axis.y + s * axis.z, temp.x * axis.z - s * axis.y,
			temp.y * axis.x - s * axis.z, c + temp.y * axis.y, temp.y * axis.z + s * axis.x,
			temp.z * axis.x + s * axis.y, temp.z * axis.y - s * axis.x, c + temp.z * axis.z
		);

		PyObject* out = build_imat4x4(to_imat4x4v(
			addv4v(addv4v(mulv4d(((imat4x4*)o)->x, Rotate.x.x), mulv4d(((imat4x4*)o)->y, Rotate.x.y)), mulv4d(((imat4x4*)o)->z, Rotate.x.z)),
			addv4v(addv4v(mulv4d(((imat4x4*)o)->x, Rotate.y.x), mulv4d(((imat4x4*)o)->y, Rotate.y.y)), mulv4d(((imat4x4*)o)->z, Rotate.y.z)),
			addv4v(addv4v(mulv4d(((imat4x4*)o)->x, Rotate.z.x), mulv4d(((imat4x4*)o)->y, Rotate.z.y)), mulv4d(((imat4x4*)o)->z, Rotate.z.z)),
			((imat4x4*)o)->w));
		free(o);
		return out;
	}
	if (type == GLM_TQUAT) {
		ivec3 Tmp = to_ivec3(v.x, v.y, v.z);
		// Axis of rotation must be normalised
		double len = ilength3(Tmp);
		if (fabs(len - (1.0)) > (0.001))
		{
			double oneOverLen = (1.0) / len;
			Tmp.x *= oneOverLen;
			Tmp.y *= oneOverLen;
			Tmp.z *= oneOverLen;
		}

		double Sin = sin(a * (0.5));

		PyObject* out = build_iquat(mulqq((*((iquat*)o)), to_iquatv(cos(a * (0.5)), Tmp.x * Sin, Tmp.y * Sin, Tmp.z * Sin)));
		free(o);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for rotate()");
	return NULL;
}

static PyObject* rotate_slow(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "rotate_slow", arg1, arg2, arg3);
	if (!IS_NUMERIC(arg2)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for rotate_slow()");
		return NULL;
	}
	double a = pyvalue_as_double(arg2);

	ivec3 v;
	if (!unpack_ivec3p(arg3, &v)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for rotate_slow()");
		return NULL;
	}
	imat4x4 m;
	if (unpack_imat4x4p(arg1, &m)) {
		double c = cos(a);
		double s = sin(a);

		ivec3 axis = inormalize3(v);

		imat4x4 Result = to_imat4x4(
			c + ((1.0) - c)      * axis.x     * axis.x, ((1.0) - c) * axis.x * axis.y + s * axis.z, ((1.0) - c) * axis.x * axis.z - s * axis.y, 0.0,
			((1.0) - c) * axis.y * axis.x - s * axis.z, c + ((1.0) - c) * axis.y * axis.y, ((1.0) - c) * axis.y * axis.z + s * axis.x, 0.0,
			((1.0) - c) * axis.z * axis.x + s * axis.y, ((1.0) - c) * axis.z * axis.y - s * axis.x, c + ((1.0) - c) * axis.z * axis.z, 0.0,
			0.0, 0.0, 0.0, 1.0);

		return build_imat4x4(mulm44m44(m, Result));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for rotate_slow()");
	return NULL;
}

static PyObject* scale(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2;
	UNPACK_2_VARARGS(args, "scale", arg1, arg2);
	imat4x4 m;
	if (!unpack_imat4x4p(arg1, &m)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for scale(): ", arg1, arg2);
		return NULL;
	}
	ivec3 v;
	if (!unpack_ivec3p(arg2, &v)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for scale(): ", arg1, arg2);
		return NULL;
	}
	return build_imat4x4(to_imat4x4v(
		mulv4d(m.x, v.x),
		mulv4d(m.y, v.y),
		mulv4d(m.z, v.z),
		m.w));
}

static PyObject* scale_slow(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2;
	UNPACK_2_VARARGS(args, "scale_slow", arg1, arg2);
	imat4x4 m;
	if (!unpack_imat4x4p(arg1, &m)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for scale_slow(): ", arg1, arg2);
		return NULL;
	}
	ivec3 v;
	if (!unpack_ivec3p(arg2, &v)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for scale_slow(): ", arg1, arg2);
		return NULL;
	}
	imat4x4 Result = to_imat4x4d(1.0);
	Result.x.x = v.x;
	Result.y.y = v.y;
	Result.z.z = v.z;
	return build_imat4x4(mulm44m44(m, Result));
}

static PyObject* orthoLH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "orthoLH_ZO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double zNear = pyvalue_as_double(arg5);
		double zFar = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = (2.) / (right - left);
		Result.y.y = (2.) / (top - bottom);
		Result.z.z = 1.0 / (zFar - zNear);
		Result.w.x = -(right + left) / (right - left);
		Result.w.y = -(top + bottom) / (top - bottom);
		Result.w.z = -zNear / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoLH_ZO()");
	return NULL;
}

static PyObject* orthoLH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "orthoLH_NO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double zNear = pyvalue_as_double(arg5);
		double zFar = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = (2.) / (right - left);
		Result.y.y = (2.) / (top - bottom);
		Result.z.z = (2.) / (zFar - zNear);
		Result.w.x = -(right + left) / (right - left);
		Result.w.y = -(top + bottom) / (top - bottom);
		Result.w.z = -(zFar + zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoLH_NO()");
	return NULL;
}

static PyObject* orthoRH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "orthoRH_ZO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double zNear = pyvalue_as_double(arg5);
		double zFar = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = (2.) / (right - left);
		Result.y.y = (2.) / (top - bottom);
		Result.z.z = -1.0 / (zFar - zNear);
		Result.w.x = -(right + left) / (right - left);
		Result.w.y = -(top + bottom) / (top - bottom);
		Result.w.z = -zNear / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoRH_ZO()");
	return NULL;
}

static PyObject* orthoRH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "orthoRH_NO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double zNear = pyvalue_as_double(arg5);
		double zFar = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = (2.) / (right - left);
		Result.y.y = (2.) / (top - bottom);
		Result.z.z = -(2.) / (zFar - zNear);
		Result.w.x = -(right + left) / (right - left);
		Result.w.y = -(top + bottom) / (top - bottom);
		Result.w.z = -(zFar + zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoRH_NO()");
	return NULL;
}

static PyObject* orthoZO(PyObject* self, PyObject * args) {
	PyObject* out = orthoRH_ZO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoZO()");
		return NULL;
	}
	return out;
}

static PyObject* orthoNO(PyObject* self, PyObject * args) {
	PyObject* out = orthoRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoNO()");
		return NULL;
	}
	return out;
}

static PyObject* orthoRH(PyObject* self, PyObject * args) {
	PyObject* out = orthoRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoRH()");
		return NULL;
	}
	return out;
}

static PyObject* orthoLH(PyObject* self, PyObject * args) {
	PyObject* out = orthoLH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for orthoLH()");
		return NULL;
	}
	return out;
}

static PyObject* ortho(PyObject* self, PyObject* args) {
	if (PyTuple_GET_SIZE(args) == 6) {
		PyObject* out = orthoRH_NO(self, args);
		if (out == NULL) {
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for ortho()");
			return NULL;
		}
		return out;
	}
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "ortho", arg1, arg2, arg3, arg4);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = (2.) / (right - left);
		Result.y.y = (2.) / (top - bottom);
		Result.w.x = -(right + left) / (right - left);
		Result.w.y = -(top + bottom) / (top - bottom);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for ortho()");
	return NULL;
}

static PyObject* frustumLH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "frustumLH_ZO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double nearVal = pyvalue_as_double(arg5);
		double farVal = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = ((2.0) * nearVal) / (right - left);
		Result.y.y = ((2.0) * nearVal) / (top - bottom);
		Result.z.x = (right + left) / (right - left);
		Result.z.y = (top + bottom) / (top - bottom);
		Result.z.z = farVal / (farVal - nearVal);
		Result.z.w = (1.0);
		Result.w.z = -(farVal * nearVal) / (farVal - nearVal);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumLH_ZO()");
	return NULL;
}

static PyObject* frustumLH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "frustumLH_NO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double nearVal = pyvalue_as_double(arg5);
		double farVal = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = ((2.0) * nearVal) / (right - left);
		Result.y.y = ((2.0) * nearVal) / (top - bottom);
		Result.z.x = (right + left) / (right - left);
		Result.z.y = (top + bottom) / (top - bottom);
		Result.z.z = (farVal + nearVal) / (farVal - nearVal);
		Result.z.w = (1.0);
		Result.w.z = -((2.0) * farVal * nearVal) / (farVal - nearVal);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumLH_NO()");
	return NULL;
}

static PyObject* frustumRH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "frustumRH_ZO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double nearVal = pyvalue_as_double(arg5);
		double farVal = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = ((2.0) * nearVal) / (right - left);
		Result.y.y = ((2.0) * nearVal) / (top - bottom);
		Result.z.x = (right + left) / (right - left);
		Result.z.y = (top + bottom) / (top - bottom);
		Result.z.z = farVal / (farVal - nearVal);
		Result.z.w = (-1.0);
		Result.w.z = -(farVal * nearVal) / (farVal - nearVal);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumRH_ZO()");
	return NULL;
}

static PyObject* frustumRH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
	UNPACK_6_VARARGS(args, "frustumRH_NO", arg1, arg2, arg3, arg4, arg5, arg6);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		double left = pyvalue_as_double(arg1);
		double right = pyvalue_as_double(arg2);
		double bottom = pyvalue_as_double(arg3);
		double top = pyvalue_as_double(arg4);
		double nearVal = pyvalue_as_double(arg5);
		double farVal = pyvalue_as_double(arg6);

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = ((2.0) * nearVal) / (right - left);
		Result.y.y = ((2.0) * nearVal) / (top - bottom);
		Result.z.x = (right + left) / (right - left);
		Result.z.y = (top + bottom) / (top - bottom);
		Result.z.z = -(farVal + nearVal) / (farVal - nearVal);
		Result.z.w = (-1.0);
		Result.w.z = -((2.0) * farVal * nearVal) / (farVal - nearVal);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumRH_NO()");
	return NULL;
}

static PyObject* frustumZO(PyObject* self, PyObject * args) {
	PyObject* out = frustumRH_ZO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumZO()");
		return NULL;
	}
	return out;
}

static PyObject* frustumNO(PyObject* self, PyObject * args) {
	PyObject* out = frustumRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumNO()");
		return NULL;
	}
	return out;
}

static PyObject* frustumRH(PyObject* self, PyObject * args) {
	PyObject* out = frustumRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumRH()");
		return NULL;
	}
	return out;
}

static PyObject* frustumLH(PyObject* self, PyObject * args) {
	PyObject* out = frustumLH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustumLH()");
		return NULL;
	}
	return out;
}

static PyObject* frustum(PyObject* self, PyObject * args) {
	PyObject* out = frustumRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for frustum()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveRH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "perspectiveRH_ZO", arg1, arg2, arg3, arg4);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);
		double zFar = pyvalue_as_double(arg4);

		double tanHalfFovy = tan(fovy / (2.0));

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = 1.0 / (aspect * tanHalfFovy);
		Result.y.y = 1.0 / (tanHalfFovy);
		Result.z.z = zFar / (zNear - zFar);
		Result.z.w = -1.0;
		Result.w.z = -(zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveRH_ZO()");
	return NULL;
}

static PyObject* perspectiveRH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "perspectiveRH_NO", arg1, arg2, arg3, arg4);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);
		double zFar = pyvalue_as_double(arg4);

		double tanHalfFovy = tan(fovy / (2.0));

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = 1.0 / (aspect * tanHalfFovy);
		Result.y.y = 1.0 / (tanHalfFovy);
		Result.z.z = -(zFar + zNear) / (zFar - zNear);
		Result.z.w = -1.0;
		Result.w.z = -(2.0 * zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveRH_NO()");
	return NULL;
}

static PyObject* perspectiveLH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "perspectiveLH_ZO", arg1, arg2, arg3, arg4);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);
		double zFar = pyvalue_as_double(arg4);

		double tanHalfFovy = tan(fovy / (2.0));

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = 1.0 / (aspect * tanHalfFovy);
		Result.y.y = 1.0 / (tanHalfFovy);
		Result.z.z = zFar / (zNear - zFar);
		Result.z.w = 1.0;
		Result.w.z = -(zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveLH_ZO()");
	return NULL;
}

static PyObject* perspectiveLH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "perspectiveLH_NO", arg1, arg2, arg3, arg4);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);
		double zFar = pyvalue_as_double(arg4);

		double tanHalfFovy = tan(fovy / (2.0));

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = 1.0 / (aspect * tanHalfFovy);
		Result.y.y = 1.0 / (tanHalfFovy);
		Result.z.z = (zFar + zNear) / (zFar - zNear);
		Result.z.w = 1.0;
		Result.w.z = -(2.0 * zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveLH_NO()");
	return NULL;
}

static PyObject* perspectiveZO(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveRH_ZO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveZO()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveNO(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveNO()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveRH(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveRH()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveLH(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveLH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveLH()");
		return NULL;
	}
	return out;
}

static PyObject* perspective(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspective()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveFovRH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5;
	UNPACK_5_VARARGS(args, "perspectiveFovRH_ZO", arg1, arg2, arg3, arg4, arg5);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5)) {
		double rad = pyvalue_as_double(arg1);
		double width = pyvalue_as_double(arg2);
		double height = pyvalue_as_double(arg3);
		double zNear = pyvalue_as_double(arg4);
		double zFar = pyvalue_as_double(arg5);

		double h = cos((0.5) * rad) / sin((0.5) * rad);
		double w = h * height / width;

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = w;
		Result.y.y = h;
		Result.z.z = zFar / (zNear - zFar);
		Result.z.w = -1.0;
		Result.w.z = -(zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovRH_ZO()");
	return NULL;
}

static PyObject* perspectiveFovRH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5;
	UNPACK_5_VARARGS(args, "perspectiveFovRH_NO", arg1, arg2, arg3, arg4, arg5);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5)) {
		double rad = pyvalue_as_double(arg1);
		double width = pyvalue_as_double(arg2);
		double height = pyvalue_as_double(arg3);
		double zNear = pyvalue_as_double(arg4);
		double zFar = pyvalue_as_double(arg5);

		double h = cos((0.5) * rad) / sin((0.5) * rad);
		double w = h * height / width;

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = w;
		Result.y.y = h;
		Result.z.z = -(zFar + zNear) / (zFar - zNear);
		Result.z.w = -1.0;
		Result.w.z = -((2.0) * zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovRH_NO()");
	return NULL;
}

static PyObject* perspectiveFovLH_ZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5;
	UNPACK_5_VARARGS(args, "perspectiveFovLH_ZO", arg1, arg2, arg3, arg4, arg5);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5)) {
		double rad = pyvalue_as_double(arg1);
		double width = pyvalue_as_double(arg2);
		double height = pyvalue_as_double(arg3);
		double zNear = pyvalue_as_double(arg4);
		double zFar = pyvalue_as_double(arg5);

		double h = cos((0.5) * rad) / sin((0.5) * rad);
		double w = h * height / width;

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = w;
		Result.y.y = h;
		Result.z.z = zFar / (zNear - zFar);
		Result.z.w = 1.0;
		Result.w.z = -(zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovLH_ZO()");
	return NULL;
}

static PyObject* perspectiveFovLH_NO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4, *arg5;
	UNPACK_5_VARARGS(args, "perspectiveFovLH_NO", arg1, arg2, arg3, arg4, arg5);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5)) {
		double rad = pyvalue_as_double(arg1);
		double width = pyvalue_as_double(arg2);
		double height = pyvalue_as_double(arg3);
		double zNear = pyvalue_as_double(arg4);
		double zFar = pyvalue_as_double(arg5);

		double h = cos((0.5) * rad) / sin((0.5) * rad);
		double w = h * height / width;

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = w;
		Result.y.y = h;
		Result.z.z = (zFar + zNear) / (zFar - zNear);
		Result.z.w = 1.0;
		Result.w.z = -((2.0) * zFar * zNear) / (zFar - zNear);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovLH_NO()");
	return NULL;
}

static PyObject* perspectiveFovZO(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveFovRH_ZO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovZO()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveFovNO(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveFovRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovNO()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveFovRH(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveFovRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovRH()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveFovLH(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveFovLH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFovLH()");
		return NULL;
	}
	return out;
}

static PyObject* perspectiveFov(PyObject* self, PyObject * args) {
	PyObject* out = perspectiveFovRH_NO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for perspectiveFov()");
		return NULL;
	}
	return out;
}

static PyObject* infinitePerspectiveLH(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "infinitePerspectiveLH", arg1, arg2, arg3);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);

		double range = tan(fovy / (2.0)) * zNear;
		double left = -range * aspect;
		double right = range * aspect;
		double bottom = -range;
		double top = range;

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = (2.0 * zNear) / (right - left);
		Result.y.y = (2.0 * zNear) / (top - bottom);
		Result.z.z = (1.0);
		Result.z.w = (1.0);
		Result.w.z = -2.0 * zNear;
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for infinitePerspectiveLH()");
	return NULL;
}

static PyObject* infinitePerspectiveRH(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "infinitePerspectiveRH", arg1, arg2, arg3);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);

		double range = tan(fovy / (2.0)) * zNear;
		double left = -range * aspect;
		double right = range * aspect;
		double bottom = -range;
		double top = range;

		imat4x4 Result = to_imat4x4d(0.0);
		Result.x.x = (2.0 * zNear) / (right - left);
		Result.y.y = (2.0 * zNear) / (top - bottom);
		Result.z.z = (-1.0);
		Result.z.w = (-1.0);
		Result.w.z = -2.0 * zNear;
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for infinitePerspectiveRH()");
	return NULL;
}

static PyObject* infinitePerspective(PyObject* self, PyObject * args) {
	PyObject* out = infinitePerspectiveRH(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for infinitePerspective()");
		return NULL;
	}
	return out;
}

static PyObject* tweakedInfinitePerspective_(double fovy, double aspect, double zNear, double ep) {
	double range = tan(fovy / 2.0) * zNear;
	double left = -range * aspect;
	double right = range * aspect;
	double bottom = -range;
	double top = range;

	imat4x4 Result = to_imat4x4d(0.0);
	Result.x.x = (2.0 * zNear) / (right - left);
	Result.y.y = (2.0 * zNear) / (top - bottom);
	Result.z.z = ep - 1.0;
	Result.z.w = (-1.0);
	Result.w.z = (ep - (2.0)) * zNear;
	return build_imat4x4(Result);
}

// Infinite projection matrix: http://www.terathon.com/gdc07_lengyel.pdf
static PyObject* tweakedInfinitePerspective(PyObject* self, PyObject* args) {
	if (PyTuple_GET_SIZE(args) == 4) {
		PyObject* arg1, *arg2, *arg3, *arg4;
		UNPACK_4_VARARGS(args, "tweakedInfinitePerspective", arg1, arg2, arg3, arg4);
		if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
			double fovy = pyvalue_as_double(arg1);
			double aspect = pyvalue_as_double(arg2);
			double zNear = pyvalue_as_double(arg3);
			double ep = pyvalue_as_double(arg4);

			return tweakedInfinitePerspective_(fovy, aspect, zNear, ep);
		}
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for tweakedInfinitePerspective()");
		return NULL;
	}
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "tweakedInfinitePerspective", arg1, arg2, arg3);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
		double fovy = pyvalue_as_double(arg1);
		double aspect = pyvalue_as_double(arg2);
		double zNear = pyvalue_as_double(arg3);

		return tweakedInfinitePerspective_(fovy, aspect, zNear, DBL_EPSILON);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for tweakedInfinitePerspective()");
	return NULL;
}

static PyObject* projectZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "projectZO", arg1, arg2, arg3, arg4);
	ivec3 obj;
	imat4x4 model;
	imat4x4 proj; 
	ivec4 viewport; 

	if (unpack_ivec3p(arg1, &obj) && unpack_imat4x4p(arg2, &model) && unpack_imat4x4p(arg3, &proj) && unpack_ivec4p(arg4, &viewport)) {
		ivec4 tmp = to_ivec4(obj.x, obj.y, obj.z, (1.));
		tmp = mulm44v4(proj, mulm44v4(model, tmp));

		tmp = divv4d(tmp, tmp.w);
		tmp.x = tmp.x * (0.5) + (0.5);
		tmp.y = tmp.y * (0.5) + (0.5);

		tmp.x = tmp.x * (viewport.z) + (viewport.x);
		tmp.y = tmp.y * (viewport.w) + (viewport.y);

		return build_ivec3(to_ivec3(tmp.x, tmp.y, tmp.z));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for projectZO()");
	return NULL;
}

static PyObject* projectNO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "projectNO", arg1, arg2, arg3, arg4);
	ivec3 obj;
	imat4x4 model;
	imat4x4 proj;
	ivec4 viewport;

	if (unpack_ivec3p(arg1, &obj) && unpack_imat4x4p(arg2, &model) && unpack_imat4x4p(arg3, &proj) && unpack_ivec4p(arg4, &viewport)) {
		ivec4 tmp = to_ivec4(obj.x, obj.y, obj.z, (1.));
		tmp = mulm44v4(proj, mulm44v4(model, tmp));

		tmp = divv4d(tmp, tmp.w);
		tmp = addv4d(mulv4d(tmp, 0.5), 0.5);

		tmp.x = tmp.x * (viewport.z) + (viewport.x);
		tmp.y = tmp.y * (viewport.w) + (viewport.y);

		return build_ivec3(to_ivec3(tmp.x, tmp.y, tmp.z));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for projectNO()");
	return NULL;
}

static PyObject* project(PyObject* self, PyObject * args) {
	PyObject* out = projectNO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for project()");
		return NULL;
	}
	return out;
}

static PyObject* unProjectZO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "unProjectZO", arg1, arg2, arg3, arg4);
	ivec3 win;
	imat4x4 model;
	imat4x4 proj;
	ivec4 viewport;

	if (unpack_ivec3p(arg1, &win) && unpack_imat4x4p(arg2, &model) && unpack_imat4x4p(arg3, &proj) && unpack_ivec4p(arg4, &viewport)) {
		imat4x4 Inverse;
		Inverse = INVERSE4(mulm44m44(proj, model));

		ivec4 tmp = to_ivec4(win.x, win.y, win.z, (1.));
		tmp.x = (tmp.x - (viewport.x)) / (viewport.z);
		tmp.y = (tmp.y - (viewport.y)) / (viewport.w);
		tmp.x = tmp.x * (2.0) - (1.0);
		tmp.y = tmp.y * (2.0) - (1.0);

		ivec4 obj = mulm44v4(Inverse, tmp);
		obj = divv4d(obj, obj.w);

		return build_ivec3(to_ivec3(obj.x, obj.y, obj.z));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for unProjectZO()");
	return NULL;
}

static PyObject* unProjectNO(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3, *arg4;
	UNPACK_4_VARARGS(args, "unProjectNO", arg1, arg2, arg3, arg4);
	ivec3 win;
	imat4x4 model;
	imat4x4 proj;
	ivec4 viewport;

	if (unpack_ivec3p(arg1, &win) && unpack_imat4x4p(arg2, &model) && unpack_imat4x4p(arg3, &proj) && unpack_ivec4p(arg4, &viewport)) {
		imat4x4 Inverse = INVERSE4(mulm44m44(proj, model));

		ivec4 tmp = to_ivec4(win.x, win.y, win.z, (1.));
		tmp.x = (tmp.x - (viewport.x)) / (viewport.z);
		tmp.y = (tmp.y - (viewport.y)) / (viewport.w);
		tmp = subv4d(mulv4d(tmp, 2.0), 1.0);

		ivec4 obj = mulm44v4(Inverse, tmp);
		obj = divv4d(obj, obj.w);

		return build_ivec3(to_ivec3(obj.x, obj.y, obj.z));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for unProjectNO()");
	return NULL;
}

static PyObject* unProject(PyObject* self, PyObject * args) {
	PyObject* out = unProjectNO(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for unProject()");
		return NULL;
	}
	return out;
}

static PyObject* pickMatrix(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "pickMatrix", arg1, arg2, arg3);
	ivec2 center; 
	ivec2 delta; 
	ivec4 viewport;

	if (unpack_ivec2p(arg1, &center) && unpack_ivec2p(arg2, &delta) && unpack_ivec4p(arg3, &viewport)) {
		imat4x4 Result = to_imat4x4d((1.));

		if (!(delta.x > (0.) && delta.y > (0.)))
			return build_imat4x4(Result); // Error

		ivec3 Temp = to_ivec3(
			((viewport.z) - (2.0) * (center.x - (viewport.x))) / delta.x,
			((viewport.w) - (2.0) * (center.y - (viewport.y))) / delta.y,
			0.0);

		// Translate and scale the picked region to the entire window
		Result = to_imat4x4v(Result.x, Result.y, addv4v(addv4v(addv4v(mulv4d(Result.x, Temp.x), mulv4d(Result.y, Temp.y)), mulv4d(Result.z, Temp.z)), Result.w), Result.w);
		ivec3 v = to_ivec3((viewport.z) / delta.x, (viewport.w) / delta.y, (1.));
		Result = to_imat4x4v(mulv4d(Result.x, v.x), mulv4d(Result.y, v.y), mulv4d(Result.z, v.z), Result.w);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for pickMatrix()");
	return NULL;
}

static PyObject* lookAtRH(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "lookAtRH", arg1, arg2, arg3);
	ivec3 eye;
	ivec3 center;
	ivec3 up;

	if (unpack_ivec3p(arg1, &eye) && unpack_ivec3p(arg2, &center) && unpack_ivec3p(arg3, &up)) {
		ivec3 f = (inormalize3(subv3v(center, eye)));
		ivec3 s = (inormalize3(icross(f, up)));
		ivec3 u = (icross(s, f));

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = s.x;
		Result.y.x = s.y;
		Result.z.x = s.z;
		Result.x.y = u.x;
		Result.y.y = u.y;
		Result.z.y = u.z;
		Result.x.z = -f.x;
		Result.y.z = -f.y;
		Result.z.z = -f.z;
		Result.w.x = -idot3(s, eye);
		Result.w.y = -idot3(u, eye);
		Result.w.z = idot3(f, eye);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for lookAtRH()");
	return NULL;
}

static PyObject* lookAtLH(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "lookAtLH", arg1, arg2, arg3);
	ivec3 eye;
	ivec3 center;
	ivec3 up;

	if (unpack_ivec3p(arg1, &eye) && unpack_ivec3p(arg2, &center) && unpack_ivec3p(arg3, &up)) {
		ivec3 f = (inormalize3(subv3v(center, eye)));
		ivec3 s = (inormalize3(icross(f, up)));
		ivec3 u = (icross(s, f));

		imat4x4 Result = to_imat4x4d(1.0);
		Result.x.x = s.x;
		Result.y.x = s.y;
		Result.z.x = s.z;
		Result.x.y = u.x;
		Result.y.y = u.y;
		Result.z.y = u.z;
		Result.x.z = f.x;
		Result.y.z = f.y;
		Result.z.z = f.z;
		Result.w.x = -idot3(s, eye);
		Result.w.y = -idot3(u, eye);
		Result.w.z = -idot3(f, eye);
		return build_imat4x4(Result);
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for lookAtLH()");
	return NULL;
}

static PyObject* lookAt(PyObject* self, PyObject * args) {
	PyObject* out = lookAtRH(self, args);
	if (out == NULL) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for lookAt()");
		return NULL;
	}
	return out;
}
