static PyObject * matrixCompMult(PyObject * self, PyObject * args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "matrixCompMult", arg1, arg2);

	void * o, *o2;

	char matType = unpack_imat(arg1, &o);

	if (matType == GLM_NONE || matType != unpack_imat(arg2, &o2)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for matrixCompMult(): ", arg1, arg2);
		return NULL;
	}
	
	switch (matType) {
	case GLM_TMAT2x2:
		return pack_tmat2x2(
			(((imat2x2*)o)->x.x * ((imat2x2*)o2)->x.x), (((imat2x2*)o)->x.y * ((imat2x2*)o2)->x.y),
			(((imat2x2*)o)->y.x * ((imat2x2*)o2)->y.x), (((imat2x2*)o)->y.y * ((imat2x2*)o2)->y.y)
		);
	case GLM_TMAT2x3:
		return pack_tmat2x3(
			(((imat2x3*)o)->x.x * ((imat2x3*)o2)->x.x), (((imat2x3*)o)->x.y * ((imat2x3*)o2)->x.y), (((imat2x3*)o)->x.z * ((imat2x3*)o2)->x.z),
			(((imat2x3*)o)->y.x * ((imat2x3*)o2)->y.x), (((imat2x3*)o)->y.y * ((imat2x3*)o2)->y.y), (((imat2x3*)o)->y.z * ((imat2x3*)o2)->y.z)
		);
	case GLM_TMAT2x4:
		return pack_tmat2x4(
			(((imat2x4*)o)->x.x * ((imat2x4*)o2)->x.x), (((imat2x4*)o)->x.y * ((imat2x4*)o2)->x.y), (((imat2x4*)o)->x.z * ((imat2x4*)o2)->x.z), (((imat2x4*)o)->x.w * ((imat2x4*)o2)->x.w),
			(((imat2x4*)o)->y.x * ((imat2x4*)o2)->y.x), (((imat2x4*)o)->y.y * ((imat2x4*)o2)->y.y), (((imat2x4*)o)->y.z * ((imat2x4*)o2)->y.z), (((imat2x4*)o)->y.w * ((imat2x4*)o2)->y.w)
		);
	case GLM_TMAT3x2:
		return pack_tmat3x2(
			(((imat3x2*)o)->x.x * ((imat3x2*)o2)->x.x), (((imat3x2*)o)->x.y * ((imat3x2*)o2)->x.y),
			(((imat3x2*)o)->y.x * ((imat3x2*)o2)->y.x), (((imat3x2*)o)->y.y * ((imat3x2*)o2)->y.y),
			(((imat3x2*)o)->z.x * ((imat3x2*)o2)->z.x), (((imat3x2*)o)->z.y * ((imat3x2*)o2)->z.y)
		);
	case GLM_TMAT3x3:
		return pack_tmat3x3(
			(((imat3x3*)o)->x.x * ((imat3x3*)o2)->x.x), (((imat3x3*)o)->x.y * ((imat3x3*)o2)->x.y), (((imat3x3*)o)->x.z * ((imat3x3*)o2)->x.z),
			(((imat3x3*)o)->y.x * ((imat3x3*)o2)->y.x), (((imat3x3*)o)->y.y * ((imat3x3*)o2)->y.y), (((imat3x3*)o)->y.z * ((imat3x3*)o2)->y.z),
			(((imat3x3*)o)->z.x * ((imat3x3*)o2)->z.x), (((imat3x3*)o)->z.y * ((imat3x3*)o2)->z.y), (((imat3x3*)o)->z.z * ((imat3x3*)o2)->z.z)
		);
	case GLM_TMAT3x4:
		return pack_tmat3x4(
			(((imat3x4*)o)->x.x * ((imat3x4*)o2)->x.x), (((imat3x4*)o)->x.y * ((imat3x4*)o2)->x.y), (((imat3x4*)o)->x.z * ((imat3x4*)o2)->x.z), (((imat3x4*)o)->x.w * ((imat3x4*)o2)->x.w),
			(((imat3x4*)o)->y.x * ((imat3x4*)o2)->y.x), (((imat3x4*)o)->y.y * ((imat3x4*)o2)->y.y), (((imat3x4*)o)->y.z * ((imat3x4*)o2)->y.z), (((imat3x4*)o)->y.w * ((imat3x4*)o2)->y.w),
			(((imat3x4*)o)->z.x * ((imat3x4*)o2)->z.x), (((imat3x4*)o)->z.y * ((imat3x4*)o2)->z.y), (((imat3x4*)o)->z.z * ((imat3x4*)o2)->z.z), (((imat3x4*)o)->z.w * ((imat3x4*)o2)->z.w)
		);
	case GLM_TMAT4x2:
		return pack_tmat4x2(
			(((imat4x2*)o)->x.x * ((imat4x2*)o2)->x.x), (((imat4x2*)o)->x.y * ((imat4x2*)o2)->x.y),
			(((imat4x2*)o)->y.x * ((imat4x2*)o2)->y.x), (((imat4x2*)o)->y.y * ((imat4x2*)o2)->y.y),
			(((imat4x2*)o)->z.x * ((imat4x2*)o2)->z.x), (((imat4x2*)o)->z.y * ((imat4x2*)o2)->z.y),
			(((imat4x2*)o)->w.x * ((imat4x2*)o2)->w.x), (((imat4x2*)o)->w.y * ((imat4x2*)o2)->w.y)
		);
	case GLM_TMAT4x3:
		return pack_tmat4x3(
			(((imat4x3*)o)->x.x * ((imat4x3*)o2)->x.x), (((imat4x3*)o)->x.y * ((imat4x3*)o2)->x.y), (((imat4x3*)o)->x.z * ((imat4x3*)o2)->x.z),
			(((imat4x3*)o)->y.x * ((imat4x3*)o2)->y.x), (((imat4x3*)o)->y.y * ((imat4x3*)o2)->y.y), (((imat4x3*)o)->y.z * ((imat4x3*)o2)->y.z),
			(((imat4x3*)o)->z.x * ((imat4x3*)o2)->z.x), (((imat4x3*)o)->z.y * ((imat4x3*)o2)->z.y), (((imat4x3*)o)->z.z * ((imat4x3*)o2)->z.z),
			(((imat4x3*)o)->w.x * ((imat4x3*)o2)->w.x), (((imat4x3*)o)->w.y * ((imat4x3*)o2)->w.y), (((imat4x3*)o)->w.z * ((imat4x3*)o2)->w.z)
		);
	case GLM_TMAT4x4:
		return pack_tmat4x4(
			(((imat4x4*)o)->x.x * ((imat4x4*)o2)->x.x), (((imat4x4*)o)->x.y * ((imat4x4*)o2)->x.y), (((imat4x4*)o)->x.z * ((imat4x4*)o2)->x.z), (((imat4x4*)o)->x.w * ((imat4x4*)o2)->x.w),
			(((imat4x4*)o)->y.x * ((imat4x4*)o2)->y.x), (((imat4x4*)o)->y.y * ((imat4x4*)o2)->y.y), (((imat4x4*)o)->y.z * ((imat4x4*)o2)->y.z), (((imat4x4*)o)->y.w * ((imat4x4*)o2)->y.w),
			(((imat4x4*)o)->z.x * ((imat4x4*)o2)->z.x), (((imat4x4*)o)->z.y * ((imat4x4*)o2)->z.y), (((imat4x4*)o)->z.z * ((imat4x4*)o2)->z.z), (((imat4x4*)o)->z.w * ((imat4x4*)o2)->z.w),
			(((imat4x4*)o)->w.x * ((imat4x4*)o2)->w.x), (((imat4x4*)o)->w.y * ((imat4x4*)o2)->w.y), (((imat4x4*)o)->w.z * ((imat4x4*)o2)->w.z), (((imat4x4*)o)->w.w * ((imat4x4*)o2)->w.w)
		);
	default:
		PY_TYPEERROR_2O("unsupported operand type(s) for matrixCompMult(): ", arg1, arg2);
		return NULL;
	}
}

#define TRANSPOSE_IMAT2x2P(m) to_imat2x2p(((imat2x2*)m)->x.x, ((imat2x2*)m)->y.x, ((imat2x2*)m)->x.y, ((imat2x2*)m)->y.y)
#define TRANSPOSE_TMAT2x2P(m) pack_tmat2x2(((imat2x2*)m)->x.x, ((imat2x2*)m)->y.x, ((imat2x2*)m)->x.y, ((imat2x2*)m)->y.y)

#define TRANSPOSE_IMAT2x3P(m) to_imat3x2p(((imat2x3*)m)->x.x, ((imat2x3*)m)->y.x, ((imat2x3*)m)->x.y, ((imat2x3*)m)->y.y, ((imat2x3*)m)->x.z, ((imat2x3*)m)->y.z)
#define TRANSPOSE_TMAT2x3P(m) pack_tmat3x2(((imat2x3*)m)->x.x, ((imat2x3*)m)->y.x, ((imat2x3*)m)->x.y, ((imat2x3*)m)->y.y, ((imat2x3*)m)->x.z, ((imat2x3*)m)->y.z)

#define TRANSPOSE_IMAT2x4P(m) to_imat4x2p(((imat2x4*)m)->x.x, ((imat2x4*)m)->y.x, ((imat2x4*)m)->x.y, ((imat2x4*)m)->y.y, ((imat2x4*)m)->x.z, ((imat2x4*)m)->y.z, ((imat2x4*)m)->x.w, ((imat2x4*)m)->y.w)
#define TRANSPOSE_TMAT2x4P(m) pack_tmat4x2(((imat2x4*)m)->x.x, ((imat2x4*)m)->y.x, ((imat2x4*)m)->x.y, ((imat2x4*)m)->y.y, ((imat2x4*)m)->x.z, ((imat2x4*)m)->y.z, ((imat2x4*)m)->x.w, ((imat2x4*)m)->y.w)

#define TRANSPOSE_IMAT3x2P(m) to_imat2x3p(((imat3x2*)m)->x.x, ((imat3x2*)m)->y.x, ((imat3x2*)m)->z.x, ((imat3x2*)m)->x.y, ((imat3x2*)m)->y.y, ((imat3x2*)m)->z.y)
#define TRANSPOSE_TMAT3x2P(m) pack_tmat2x3(((imat3x2*)m)->x.x, ((imat3x2*)m)->y.x, ((imat3x2*)m)->z.x, ((imat3x2*)m)->x.y, ((imat3x2*)m)->y.y, ((imat3x2*)m)->z.y)

#define TRANSPOSE_IMAT3x3P(m) to_imat3x3p(((imat3x3*)m)->x.x, ((imat3x3*)m)->y.x, ((imat3x3*)m)->z.x, ((imat3x3*)m)->x.y, ((imat3x3*)m)->y.y, ((imat3x3*)m)->z.y, ((imat3x3*)m)->x.z, ((imat3x3*)m)->y.z, ((imat3x3*)m)->z.z)
#define TRANSPOSE_TMAT3x3P(m) pack_tmat3x3(((imat3x3*)m)->x.x, ((imat3x3*)m)->y.x, ((imat3x3*)m)->z.x, ((imat3x3*)m)->x.y, ((imat3x3*)m)->y.y, ((imat3x3*)m)->z.y, ((imat3x3*)m)->x.z, ((imat3x3*)m)->y.z, ((imat3x3*)m)->z.z)

#define TRANSPOSE_IMAT3x4P(m) to_imat4x3p(((imat3x4*)m)->x.x, ((imat3x4*)m)->y.x, ((imat3x4*)m)->z.x, ((imat3x4*)m)->x.y, ((imat3x4*)m)->y.y, ((imat3x4*)m)->z.y, ((imat3x4*)m)->x.z, ((imat3x4*)m)->y.z, ((imat3x4*)m)->z.z, ((imat3x4*)m)->x.w, ((imat3x4*)m)->y.w, ((imat3x4*)m)->z.w)
#define TRANSPOSE_TMAT3x4P(m) pack_tmat4x3(((imat3x4*)m)->x.x, ((imat3x4*)m)->y.x, ((imat3x4*)m)->z.x, ((imat3x4*)m)->x.y, ((imat3x4*)m)->y.y, ((imat3x4*)m)->z.y, ((imat3x4*)m)->x.z, ((imat3x4*)m)->y.z, ((imat3x4*)m)->z.z, ((imat3x4*)m)->x.w, ((imat3x4*)m)->y.w, ((imat3x4*)m)->z.w)

#define TRANSPOSE_IMAT4x2P(m) to_imat2x4p(((imat4x2*)m)->x.x, ((imat4x2*)m)->y.x, ((imat4x2*)m)->z.x, ((imat4x2*)m)->w.x, ((imat4x2*)m)->x.y, ((imat4x2*)m)->y.y, ((imat4x2*)m)->z.y, ((imat4x2*)m)->w.y)
#define TRANSPOSE_TMAT4x2P(m) pack_tmat2x4(((imat4x2*)m)->x.x, ((imat4x2*)m)->y.x, ((imat4x2*)m)->z.x, ((imat4x2*)m)->w.x, ((imat4x2*)m)->x.y, ((imat4x2*)m)->y.y, ((imat4x2*)m)->z.y, ((imat4x2*)m)->w.y)

#define TRANSPOSE_IMAT4x3P(m) to_imat3x4p(((imat4x3*)m)->x.x, ((imat4x3*)m)->y.x, ((imat4x3*)m)->z.x, ((imat4x3*)m)->w.x, ((imat4x3*)m)->x.y, ((imat4x3*)m)->y.y, ((imat4x3*)m)->z.y, ((imat4x3*)m)->w.y, ((imat4x3*)m)->x.z, ((imat4x3*)m)->y.z, ((imat4x3*)m)->z.z, ((imat4x3*)m)->w.z)
#define TRANSPOSE_TMAT4x3P(m) pack_tmat3x4(((imat4x3*)m)->x.x, ((imat4x3*)m)->y.x, ((imat4x3*)m)->z.x, ((imat4x3*)m)->w.x, ((imat4x3*)m)->x.y, ((imat4x3*)m)->y.y, ((imat4x3*)m)->z.y, ((imat4x3*)m)->w.y, ((imat4x3*)m)->x.z, ((imat4x3*)m)->y.z, ((imat4x3*)m)->z.z, ((imat4x3*)m)->w.z)

#define TRANSPOSE_IMAT4x4P(m) to_imat4x4p(((imat4x4*)m)->x.x, ((imat4x4*)m)->y.x, ((imat4x4*)m)->z.x, ((imat4x4*)m)->w.x, ((imat4x4*)m)->x.y, ((imat4x4*)m)->y.y, ((imat4x4*)m)->z.y, ((imat4x4*)m)->w.y, ((imat4x4*)m)->x.z, ((imat4x4*)m)->y.z, ((imat4x4*)m)->z.z, ((imat4x4*)m)->w.z, ((imat4x4*)m)->x.w, ((imat4x4*)m)->y.w, ((imat4x4*)m)->z.w, ((imat4x4*)m)->w.w)
#define TRANSPOSE_TMAT4x4P(m) pack_tmat4x4(((imat4x4*)m)->x.x, ((imat4x4*)m)->y.x, ((imat4x4*)m)->z.x, ((imat4x4*)m)->w.x, ((imat4x4*)m)->x.y, ((imat4x4*)m)->y.y, ((imat4x4*)m)->y.y, ((imat4x4*)m)->w.y, ((imat4x4*)m)->x.z, ((imat4x4*)m)->y.z, ((imat4x4*)m)->z.z, ((imat4x4*)m)->w.z, ((imat4x4*)m)->x.w, ((imat4x4*)m)->y.w, ((imat4x4*)m)->z.w, ((imat4x4*)m)->w.w)


static PyObject* transpose(PyObject * self, PyObject* arg) {
	void * o;
	switch (unpack_imat(arg, &o)) {
	case GLM_NONE:
		PY_TYPEERROR("unsupported operand type for transpose(): ", arg);
		return NULL;
	case GLM_TMAT2x2:
		return TRANSPOSE_TMAT2x2P(o);
	case GLM_TMAT2x3:
		return TRANSPOSE_TMAT2x3P(o);
	case GLM_TMAT2x4:
		return TRANSPOSE_TMAT2x4P(o);
	case GLM_TMAT3x2:
		return TRANSPOSE_TMAT3x2P(o);
	case GLM_TMAT3x3:
		return TRANSPOSE_TMAT3x3P(o);
	case GLM_TMAT3x4:
		return TRANSPOSE_TMAT3x4P(o);
	case GLM_TMAT4x2:
		return TRANSPOSE_TMAT4x2P(o);
	case GLM_TMAT4x3:
		return TRANSPOSE_TMAT4x3P(o);
	case GLM_TMAT4x4:
		return TRANSPOSE_TMAT4x4P(o);
	default:
		PY_TYPEERROR("unsupported operand type for transpose(): ", arg);
		return NULL;
	}
}

#define DETERMINANT2(m) (((imat2x2*)m)->x.x * ((imat2x2*)m)->y.y - ((imat2x2*)m)->y.x * ((imat2x2*)m)->x.y)
#define DETERMINANT3(m) (((imat3x3*)m)->x.x * (((imat3x3*)m)->y.y * ((imat3x3*)m)->z.z - ((imat3x3*)m)->z.y * ((imat3x3*)m)->y.z)- ((imat3x3*)m)->y.x * (((imat3x3*)m)->x.y * ((imat3x3*)m)->z.z - ((imat3x3*)m)->z.y * ((imat3x3*)m)->x.z)+ ((imat3x3*)m)->z.x * (((imat3x3*)m)->x.y * ((imat3x3*)m)->y.z - ((imat3x3*)m)->y.y * ((imat3x3*)m)->x.z))
static double DETERMINANT4(imat4x4* m) {
	double SubFactor00 = m->z.z * m->w.w - m->w.z * m->z.w;
	double SubFactor01 = m->z.y * m->w.w - m->w.y * m->z.w;
	double SubFactor02 = m->z.y * m->w.z - m->w.y * m->z.z;
	double SubFactor03 = m->z.x * m->w.w - m->w.x * m->z.w;
	double SubFactor04 = m->z.x * m->w.z - m->w.x * m->z.z;
	double SubFactor05 = m->z.x * m->w.y - m->w.x * m->z.y;

	ivec4* DetCof = to_ivec4p(
		+(m->y.y * SubFactor00 - m->y.z * SubFactor01 + m->y.w * SubFactor02),
		-(m->y.x * SubFactor00 - m->y.z * SubFactor03 + m->y.w * SubFactor04),
		+(m->y.x * SubFactor01 - m->y.y * SubFactor03 + m->y.w * SubFactor05),
		-(m->y.x * SubFactor02 - m->y.y * SubFactor04 + m->y.z * SubFactor05));

	return m->x.x * DetCof->x + m->x.y * DetCof->y + m->x.z * DetCof->z + m->x.w * DetCof->w;
}

static PyObject * determinant(PyObject * self, PyObject* arg) {
	void* o;
	switch (unpack_imat(arg, &o)) {
	case GLM_TMAT2x2:
		return PyFloat_FromDouble(DETERMINANT2(o));
	case GLM_TMAT3x3:
		return PyFloat_FromDouble(DETERMINANT3(o));
	case GLM_TMAT4x4:
		return PyFloat_FromDouble(DETERMINANT4(o));
	default:
		PY_TYPEERROR("unsupported operand type for determinant(): ", arg);
		return NULL;
	}
}

static PyObject * outerProduct(PyObject * self, PyObject * args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "outerProduct", arg1, arg2);

	void * o, *o2;

	char matType;
	
	char vecType1 = unpack_ivec(arg1, &o);
	char vecType2 = unpack_ivec(arg2, &o2);

	if (vecType1 == GLM_NONE || vecType2 == GLM_NONE) {
		PY_TYPEERROR_2O("unsupported operand type(s) for outerProduct(): ", arg1, arg2);
		return NULL;
	}

	if (vecType1 == GLM_TVEC2) {
		if (vecType2 == GLM_TVEC2) matType = GLM_TMAT2x2;
		else if (vecType2 == GLM_TVEC3) matType = GLM_TMAT2x3;
		else matType = GLM_TMAT2x4;
	}
	else if (vecType1 == GLM_TVEC3) {
		if (vecType2 == GLM_TVEC2) matType = GLM_TMAT3x2;
		else if (vecType2 == GLM_TVEC3) matType = GLM_TMAT3x3;
		else matType = GLM_TMAT3x4;
	}
	else {
		if (vecType2 == GLM_TVEC2) matType = GLM_TMAT4x2;
		else if (vecType2 == GLM_TVEC3) matType = GLM_TMAT4x3;
		else matType = GLM_TMAT4x4;
	}

	switch (matType) {
	case GLM_TMAT2x2:
		return pack_tmat2x2(
			(((ivec2*)o)->x * ((ivec2*)o2)->x), (((ivec2*)o)->y * ((ivec2*)o2)->x),
			(((ivec2*)o)->x * ((ivec2*)o2)->y), (((ivec2*)o)->y * ((ivec2*)o2)->y)
		);
	case GLM_TMAT2x3:
		return pack_tmat2x3(
			(((ivec3*)o)->x * ((ivec2*)o2)->x), (((ivec3*)o)->y * ((ivec2*)o2)->x), (((ivec3*)o)->z * ((ivec2*)o2)->x),
			(((ivec3*)o)->x * ((ivec2*)o2)->y), (((ivec3*)o)->y * ((ivec2*)o2)->y), (((ivec3*)o)->z * ((ivec2*)o2)->y)
		);
	case GLM_TMAT2x4:
		return pack_tmat2x4(
			(((ivec4*)o)->x * ((ivec2*)o2)->x), (((ivec4*)o)->y * ((ivec2*)o2)->x), (((ivec4*)o)->z * ((ivec2*)o2)->x), (((ivec4*)o)->w * ((ivec2*)o2)->x),
			(((ivec4*)o)->x * ((ivec2*)o2)->y), (((ivec4*)o)->y * ((ivec2*)o2)->y), (((ivec4*)o)->z * ((ivec2*)o2)->y), (((ivec4*)o)->w * ((ivec2*)o2)->y)
		);
	case GLM_TMAT3x2:
		return pack_tmat3x2(
			(((ivec2*)o)->x * ((ivec3*)o2)->x), (((ivec2*)o)->y * ((ivec3*)o2)->x),
			(((ivec2*)o)->x * ((ivec3*)o2)->y), (((ivec2*)o)->y * ((ivec3*)o2)->y),
			(((ivec2*)o)->x * ((ivec3*)o2)->z), (((ivec2*)o)->y * ((ivec3*)o2)->z)
		);
	case GLM_TMAT3x3:
		return pack_tmat3x3(
			(((ivec3*)o)->x * ((ivec3*)o2)->x), (((ivec3*)o)->y * ((ivec3*)o2)->x), (((ivec3*)o)->z * ((ivec3*)o2)->x),
			(((ivec3*)o)->x * ((ivec3*)o2)->y), (((ivec3*)o)->y * ((ivec3*)o2)->y), (((ivec3*)o)->z * ((ivec3*)o2)->y),
			(((ivec3*)o)->x * ((ivec3*)o2)->z), (((ivec3*)o)->y * ((ivec3*)o2)->z), (((ivec3*)o)->z * ((ivec3*)o2)->z)
		);
	case GLM_TMAT3x4:
		return pack_tmat3x4(
			(((ivec4*)o)->x * ((ivec3*)o2)->x), (((ivec4*)o)->y * ((ivec3*)o2)->x), (((ivec4*)o)->z * ((ivec3*)o2)->x), (((ivec4*)o)->w * ((ivec3*)o2)->x),
			(((ivec4*)o)->x * ((ivec3*)o2)->y), (((ivec4*)o)->y * ((ivec3*)o2)->y), (((ivec4*)o)->z * ((ivec3*)o2)->y), (((ivec4*)o)->w * ((ivec3*)o2)->y),
			(((ivec4*)o)->x * ((ivec3*)o2)->z), (((ivec4*)o)->y * ((ivec3*)o2)->z), (((ivec4*)o)->z * ((ivec3*)o2)->z), (((ivec4*)o)->w * ((ivec3*)o2)->z)
		);
	case GLM_TMAT4x2:
		return pack_tmat4x2(
			(((ivec2*)o)->x * ((ivec4*)o2)->x), (((ivec2*)o)->y * ((ivec4*)o2)->x),
			(((ivec2*)o)->x * ((ivec4*)o2)->y), (((ivec2*)o)->y * ((ivec4*)o2)->y),
			(((ivec2*)o)->x * ((ivec4*)o2)->z), (((ivec2*)o)->y * ((ivec4*)o2)->z),
			(((ivec2*)o)->x * ((ivec4*)o2)->w), (((ivec2*)o)->y * ((ivec4*)o2)->w)
		);
	case GLM_TMAT4x3:
		return pack_tmat4x3(
			(((ivec3*)o)->x * ((ivec4*)o2)->x), (((ivec3*)o)->y * ((ivec4*)o2)->x), (((ivec3*)o)->z * ((ivec4*)o2)->x),
			(((ivec3*)o)->x * ((ivec4*)o2)->y), (((ivec3*)o)->y * ((ivec4*)o2)->y), (((ivec3*)o)->z * ((ivec4*)o2)->y),
			(((ivec3*)o)->x * ((ivec4*)o2)->z), (((ivec3*)o)->y * ((ivec4*)o2)->z), (((ivec3*)o)->z * ((ivec4*)o2)->z),
			(((ivec3*)o)->x * ((ivec4*)o2)->w), (((ivec3*)o)->y * ((ivec4*)o2)->w), (((ivec3*)o)->z * ((ivec4*)o2)->w)
		);
	case GLM_TMAT4x4:
		return pack_tmat4x4(
			(((ivec4*)o)->x * ((ivec4*)o2)->x), (((ivec4*)o)->y * ((ivec4*)o2)->x), (((ivec4*)o)->z * ((ivec4*)o2)->x), (((ivec4*)o)->w * ((ivec4*)o2)->x),
			(((ivec4*)o)->x * ((ivec4*)o2)->y), (((ivec4*)o)->y * ((ivec4*)o2)->y), (((ivec4*)o)->z * ((ivec4*)o2)->y), (((ivec4*)o)->w * ((ivec4*)o2)->y),
			(((ivec4*)o)->x * ((ivec4*)o2)->z), (((ivec4*)o)->y * ((ivec4*)o2)->z), (((ivec4*)o)->z * ((ivec4*)o2)->z), (((ivec4*)o)->w * ((ivec4*)o2)->z),
			(((ivec4*)o)->x * ((ivec4*)o2)->w), (((ivec4*)o)->y * ((ivec4*)o2)->w), (((ivec4*)o)->z * ((ivec4*)o2)->w), (((ivec4*)o)->w * ((ivec4*)o2)->w)
		);
	default:
		PY_TYPEERROR_2O("unsupported operand type(s) for outerProduct(): ", arg1, arg2);
		return NULL;
	}
}

//#define INVERSE2_(m,ood) to_tmat2x2((m->y->y * ood),(- m->x->y * ood),(- m->y->x * ood),(m->x->x * ood))

static imat2x2* INVERSE2(imat2x2* m) {
	double ood = 1.0 / DETERMINANT2(m);
	return to_imat2x2p((m->y.y * ood), (-m->x.y * ood), (-m->y.x * ood), (m->x.x * ood));
}

//#define INVERSE3_(m,ood) to_tmat3x3(+(m->y.y * m->z.z - m->z.y * m->y.z) * ood,-(m->x.y * m->z.z - m->z.y * m->x.z) * ood,+(m->x.y * m->y.z - m->y.y * m->x.z) * ood,-(m->y.x * m->z.z - m->z.x * m->y.z) * ood,+(m->x.x * m->z.z - m->z.x * m->x.z) * ood,+(m->y.x * m->z.y - m->z.x * m->y.y) * ood,-(m->x.x * m->y.z - m->y.x * m->x.z) * ood,-(m->x.x * m->z.y - m->z.x * m->x.y) * ood,+(m->x.x * m->y.y - m->y.x * m->x.y) * ood)

static imat3x3* INVERSE3(imat3x3* m) {
	double ood = 1.0 / DETERMINANT3(m);
	return to_imat3x3p(+(m->y.y * m->z.z - m->z.y * m->y.z) * ood, -(m->x.y * m->z.z - m->z.y * m->x.z) * ood, +(m->x.y * m->y.z - m->y.y * m->x.z) * ood, -(m->y.x * m->z.z - m->z.x * m->y.z) * ood, +(m->x.x * m->z.z - m->z.x * m->x.z) * ood, +(m->y.x * m->z.y - m->z.x * m->y.y) * ood, -(m->x.x * m->y.z - m->y.x * m->x.z) * ood, -(m->x.x * m->z.y - m->z.x * m->x.y) * ood, +(m->x.x * m->y.y - m->y.x * m->x.y) * ood);
}


static imat4x4* INVERSE4(imat4x4* m) {
	double Coef00 = m->z.z * m->w.w - m->w.z * m->z.w;
	double Coef02 = m->y.z * m->w.w - m->w.z * m->y.w;
	double Coef03 = m->y.z * m->z.w - m->z.z * m->y.w;

	double Coef04 = m->z.y * m->w.w - m->w.y * m->z.w;
	double Coef06 = m->y.y * m->w.w - m->w.y * m->y.w;
	double Coef07 = m->y.y * m->z.w - m->z.y * m->y.w;

	double Coef08 = m->z.y * m->w.z - m->w.y * m->z.z;
	double Coef10 = m->y.y * m->w.z - m->w.y * m->y.z;
	double Coef11 = m->y.y * m->z.z - m->z.y * m->y.z;

	double Coef12 = m->z.x * m->w.w - m->w.x * m->z.w;
	double Coef14 = m->y.x * m->w.w - m->w.x * m->y.w;
	double Coef15 = m->y.x * m->z.w - m->z.x * m->y.w;

	double Coef16 = m->z.x * m->w.z - m->w.x * m->z.z;
	double Coef18 = m->y.x * m->w.z - m->w.x * m->y.z;
	double Coef19 = m->y.x * m->z.z - m->z.x * m->y.z;

	double Coef20 = m->z.x * m->w.y - m->w.x * m->z.y;
	double Coef22 = m->y.x * m->w.y - m->w.x * m->y.y;
	double Coef23 = m->y.x * m->z.y - m->z.x * m->y.y;

	ivec4 Fac0 = to_ivec4(Coef00, Coef00, Coef02, Coef03);
	ivec4 Fac1 = to_ivec4(Coef04, Coef04, Coef06, Coef07);
	ivec4 Fac2 = to_ivec4(Coef08, Coef08, Coef10, Coef11);
	ivec4 Fac3 = to_ivec4(Coef12, Coef12, Coef14, Coef15);
	ivec4 Fac4 = to_ivec4(Coef16, Coef16, Coef18, Coef19);
	ivec4 Fac5 = to_ivec4(Coef20, Coef20, Coef22, Coef23);

	ivec4 Vec0 = to_ivec4(m->y.x, m->x.x, m->x.x, m->x.x);
	ivec4 Vec1 = to_ivec4(m->y.y, m->x.y, m->x.y, m->x.y);
	ivec4 Vec2 = to_ivec4(m->y.z, m->x.z, m->x.z, m->x.z);
	ivec4 Vec3 = to_ivec4(m->y.w, m->x.w, m->x.w, m->x.w);

	ivec4* Inv0 = addv4vp(subv4vp(mulv4vp(&Vec1, &Fac0), mulv4vp(&Vec2, &Fac1)), mulv4vp(&Vec3, &Fac2));
	ivec4* Inv1 = addv4vp(subv4vp(mulv4vp(&Vec0, &Fac0), mulv4vp(&Vec2, &Fac3)), mulv4vp(&Vec3, &Fac4));
	ivec4* Inv2 = addv4vp(subv4vp(mulv4vp(&Vec0, &Fac1), mulv4vp(&Vec1, &Fac3)), mulv4vp(&Vec3, &Fac5));
	ivec4* Inv3 = addv4vp(subv4vp(mulv4vp(&Vec0, &Fac2), mulv4vp(&Vec1, &Fac4)), mulv4vp(&Vec2, &Fac5));

	ivec4* SignA = to_ivec4p(+1, -1, +1, -1);
	ivec4* SignB = to_ivec4p(-1, +1, -1, +1);
	ivec4 *a = mulv4vp(Inv0, SignA), *b = mulv4vp(Inv1, SignB), *c = mulv4vp(Inv2, SignA), *d = mulv4vp(Inv3, SignB);
	imat4x4 Inverse = to_imat4x4(
		a->x, a->y, a->z, a->w,
		b->x, b->y, b->z, b->w,
		c->x, c->y, c->z, c->w,
		d->x, d->y, d->z, d->w
	);

	ivec4 Row0 = to_ivec4(Inverse.x.x, Inverse.y.x, Inverse.z.x, Inverse.w.x);

	ivec4* Dot0 = mulv4vp(&m->x, &Row0);
	double Dot1 = (Dot0->x + Dot0->y) + (Dot0->z + Dot0->w);

	double OneOverDeterminant = 1.0 / Dot1;

	return to_imat4x4p(
		Inverse.x.x * OneOverDeterminant, Inverse.x.y * OneOverDeterminant, Inverse.x.z * OneOverDeterminant, Inverse.x.w * OneOverDeterminant,
		Inverse.y.x * OneOverDeterminant, Inverse.y.y * OneOverDeterminant, Inverse.y.z * OneOverDeterminant, Inverse.y.w * OneOverDeterminant,
		Inverse.z.x * OneOverDeterminant, Inverse.z.y * OneOverDeterminant, Inverse.z.z * OneOverDeterminant, Inverse.z.w * OneOverDeterminant,
		Inverse.w.x * OneOverDeterminant, Inverse.w.y * OneOverDeterminant, Inverse.w.z * OneOverDeterminant, Inverse.w.w * OneOverDeterminant);
}

static PyObject * inverse(PyObject* self, PyObject* arg) {
	void * o;
	switch (unpack_isqmat(arg, &o)) {
	case GLM_TMAT2x2:
		return build_imat2x2p(INVERSE2(o));
	case GLM_TMAT3x3:
		return build_imat3x3p(INVERSE3(o));
	case GLM_TMAT4x4:
		return build_imat4x4p(INVERSE4(o));
	default:
		PY_TYPEERROR("unsupported operand type for inverse(): ", arg);
		return NULL;
	}
}