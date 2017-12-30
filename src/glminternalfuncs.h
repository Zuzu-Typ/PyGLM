typedef struct {
	double x, y;
} ivec2;
typedef struct {
	double x, y, z;
} ivec3;
typedef struct {
	double x, y, z, w;
} ivec4;

typedef struct {
	ivec2 x, y;
} imat2x2;
typedef struct {
	ivec3 x, y;
} imat2x3;
typedef struct {
	ivec4 x, y;
} imat2x4;

typedef struct {
	ivec2 x, y, z;
} imat3x2;
typedef struct {
	ivec3 x, y, z;
} imat3x3;
typedef struct {
	ivec4 x, y, z;
} imat3x4;

typedef struct {
	ivec2 x, y, z, w;
} imat4x2;
typedef struct {
	ivec3 x, y, z, w;
} imat4x3;
typedef struct {
	ivec4 x, y, z, w;
} imat4x4;

#define IS_NUMERIC(op) (PyLong_Check(op) || PyFloat_Check(op) || PyBool_Check(op))

static double * pyvalue_as_double_p(PyObject * value) {
	double * out = malloc(sizeof(double));
	if (PyFloat_Check(value)) {
		*out = PyFloat_AS_DOUBLE(value);
		return out;
	}
	if (PyLong_Check(value)) {
		*out = (double)PyLong_AS_LONG(value);
		return out;
	}
	if (PyBool_Check(value)) {
		*out = (PyObject_IsTrue(value)) ? 1 : 0;
		return out;
	}
	return NULL;
}
static double pyvalue_as_double(PyObject * value) {
	double out;
	if (PyFloat_Check(value)) {
		out = PyFloat_AS_DOUBLE(value);
		return out;
	}
	else if (PyLong_Check(value)) {
		out = (double)PyLong_AS_LONG(value);
		return out;
	}
	else {
		out = (PyObject_IsTrue(value)) ? 1 : 0;
		return out;
	}
}

//#define new_tvec2() (tvec2*)malloc(sizeof(tvec2))
//
//#define new_tvec3() (tvec3*)malloc(sizeof(tvec3))
//
//#define new_tvec4() (tvec4*)malloc(sizeof(tvec4))

// internal glm types (initialized)
static ivec2 new_ivec2() {
	ivec2 out;
	out.x = out.y = 0.0;
	return out;
}
static ivec3 new_ivec3() {
	ivec3 out;
	out.x = out.y = out.z = 0.0;
	return out;
}
static ivec4 new_ivec4() {
	ivec4 out;
	out.x = out.y = out.z = out.w = 0.0;
	return out;
}

static imat2x2 new_imat2x2() {
	imat2x2 out;
	out.x.x = out.y.y = 1.0;
	out.x.y = out.y.x = 0.0;
	return out;
}
static imat2x3 new_imat2x3() {
	imat2x3 out;
	out.x.x = out.y.y = 1.0;
	out.x.y = out.y.x = out.x.z = out.y.z = 0.0;
	return out;
}
static imat2x4 new_imat2x4() {
	imat2x4 out;
	out.x.x = out.y.y = 1.0;
	out.x.y = out.y.x = out.x.z = out.y.z = out.x.w = out.y.w = 0.0;
	return out;
}

static imat3x2 new_imat3x2() {
	imat3x2 out;
	out.x.x = out.y.y = 1.0;
	out.x.y = out.y.x = out.z.x = out.z.y = 0.0;
	return out;
}
static imat3x3 new_imat3x3() {
	imat3x3 out;
	out.x.x = out.y.y = out.z.z = 1.0;
	out.x.y = out.y.x = out.x.z = out.y.z = out.z.x = out.z.y = 0.0;
	return out;
}
static imat3x4 new_imat3x4() {
	imat3x4 out;
	out.x.x = out.y.y = out.z.z = 1.0;
	out.x.y = out.y.x = out.x.z = out.y.z = out.x.w = out.y.w = out.z.x = out.z.y = out.z.w = 0.0;
	return out;
}

static imat4x2 new_imat4x2() {
	imat4x2 out;
	out.x.x = out.y.y = 1.0;
	out.x.y = out.y.x = out.z.x = out.z.y = out.w.x = out.w.y = 0.0;
	return out;
}
static imat4x3 new_imat4x3() {
	imat4x3 out;
	out.x.x = out.y.y = out.z.z = 1.0;
	out.x.y = out.y.x = out.x.z = out.y.z = out.z.x = out.z.y = out.w.x = out.w.y = out.w.z = 0.0;
	return out;
}
static imat4x4 new_imat4x4() {
	imat4x4 out;
	out.x.x = out.y.y = out.z.z = out.w.w = 1.0;
	out.x.y = out.y.x = out.x.z = out.y.z = out.x.w = out.y.w = out.z.x = out.z.y = out.z.w = out.w.x = out.w.y = out.w.z = 0.0;
	return out;
}

// internal glm type pointers (initialized)
static ivec2* new_ivec2p() {
	ivec2* out = (ivec2*)malloc(sizeof(*out));
	out->x = out->y = 0.0;
	return out;
}
static ivec3* new_ivec3p() {
	ivec3* out = (ivec3*)malloc(sizeof(*out));
	out->x = out->y = out->z = 0.0;
	return out;
}
static ivec4* new_ivec4p() {
	ivec4* out = (ivec4*)malloc(sizeof(*out));
	out->x = out->y = out->z = out->w = 0.0;
	return out;
}

static imat2x2* new_imat2x2p() {
	imat2x2* out = (imat2x2*)malloc(sizeof(*out));
	out->x.x = out->y.y = 1.0;
	out->x.y = out->y.x = 0.0;
	return out;
}
static imat2x3* new_imat2x3p() {
	imat2x3* out = (imat2x3*)malloc(sizeof(*out));
	out->x.x = out->y.y = 1.0;
	out->x.y = out->y.x = out->x.z = out->y.z = 0.0;
	return out;
}
static imat2x4* new_imat2x4p() {
	imat2x4* out = (imat2x4*)malloc(sizeof(*out));
	out->x.x = out->y.y = 1.0;
	out->x.y = out->y.x = out->x.z = out->y.z = out->x.w = out->y.w = 0.0;
	return out;
}

static imat3x2* new_imat3x2p() {
	imat3x2* out = (imat3x2*)malloc(sizeof(*out));
	out->x.x = out->y.y = 1.0;
	out->x.y = out->y.x = out->z.x = out->z.y = 0.0;
	return out;
}
static imat3x3* new_imat3x3p() {
	imat3x3* out = (imat3x3*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = 1.0;
	out->x.y = out->y.x = out->x.z = out->y.z = out->z.x = out->z.y = 0.0;
	return out;
}
static imat3x4* new_imat3x4p() {
	imat3x4* out = (imat3x4*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = 1.0;
	out->x.y = out->y.x = out->x.z = out->y.z = out->x.w = out->y.w = out->z.x = out->z.y = out->z.w = 0.0;
	return out;
}

static imat4x2* new_imat4x2p() {
	imat4x2* out = (imat4x2*)malloc(sizeof(*out));
	out->x.x = out->y.y = 1.0;
	out->x.y = out->y.x = out->z.x = out->z.y = out->w.x = out->w.y = 0.0;
	return out;
}
static imat4x3* new_imat4x3p() {
	imat4x3* out = (imat4x3*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = 1.0;
	out->x.y = out->y.x = out->x.z = out->y.z = out->z.x = out->z.y = out->w.x = out->w.y = out->w.z = 0.0;
	return out;
}
static imat4x4* new_imat4x4p() {
	imat4x4* out = (imat4x4*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = out->w.w = 1.0;
	out->x.y = out->y.x = out->x.z = out->y.z = out->x.w = out->y.w = out->z.x = out->z.y = out->z.w = out->w.x = out->w.y = out->w.z = 0.0;
	return out;
}

// internal glm types from doubles
static ivec2 to_ivec2(double x, double y) {
	ivec2 out;
	out.x = x;
	out.y = y;
	return out;
}
static ivec3 to_ivec3(double x, double y, double z) {
	ivec3 out;
	out.x = x;
	out.y = y;
	out.z = z;
	return out;
}
static ivec4 to_ivec4(double x, double y, double z, double w) {
	ivec4 out;
	out.x = x;
	out.y = y;
	out.z = z;
	out.w = w;
	return out;
}

static imat2x2 to_imat2x2(double x0, double x1, double y0, double y1) {
	imat2x2 out;
	out.x = to_ivec2(x0, x1);
	out.y = to_ivec2(y0, y1);
	return out;
}
static imat2x3 to_imat2x3(double x0, double x1, double x2,  double y0, double y1, double y2) {
	imat2x3 out;
	out.x = to_ivec3(x0, x1, x2);
	out.y = to_ivec3(y0, y1, y2);
	return out;
}
static imat2x4 to_imat2x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3) {
	imat2x4 out;
	out.x = to_ivec4(x0, x1, x2, x3);
	out.y = to_ivec4(y0, y1, y2, y3);
	return out;
}

static imat3x2 to_imat3x2(double x0, double x1, double y0, double y1, double z0, double z1) {
	imat3x2 out;
	out.x = to_ivec2(x0, x1);
	out.y = to_ivec2(y0, y1);
	out.z = to_ivec2(z0, z1);
	return out;
}
static imat3x3 to_imat3x3(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2) {
	imat3x3 out;
	out.x = to_ivec3(x0, x1, x2);
	out.y = to_ivec3(y0, y1, y2);
	out.z = to_ivec3(z0, z1, z2);
	return out;
}
static imat3x4 to_imat3x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3) {
	imat3x4 out;
	out.x = to_ivec4(x0, x1, x2, x3);
	out.y = to_ivec4(y0, y1, y2, y3);
	out.z = to_ivec4(z0, z1, z2, z3);
	return out;
}

static imat4x2 to_imat4x2(double x0, double x1, double y0, double y1, double z0, double z1, double w0, double w1) {
	imat4x2 out;
	out.x = to_ivec2(x0, x1);
	out.y = to_ivec2(y0, y1);
	out.z = to_ivec2(z0, z1);
	out.w = to_ivec2(w0, w1);
	return out;
}
static imat4x3 to_imat4x3(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2, double w0, double w1, double w2) {
	imat4x3 out;
	out.x = to_ivec3(x0, x1, x2);
	out.y = to_ivec3(y0, y1, y2);
	out.z = to_ivec3(z0, z1, z2);
	out.w = to_ivec3(w0, w1, w2);
	return out;
}
static imat4x4 to_imat4x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3, double w0, double w1, double w2, double w3) {
	imat4x4 out;
	out.x = to_ivec4(x0, x1, x2, x3);
	out.y = to_ivec4(y0, y1, y2, y3);
	out.z = to_ivec4(z0, z1, z2, z3);
	out.w = to_ivec4(w0, w1, w2, w3);
	return out;
}


// internal glm types from scalar
static ivec2 to_ivec2d(double d) {
	ivec2 out;
	out.x = out.y = d;
	return out;
}
static ivec3 to_ivec3d(double d) {
	ivec3 out;
	out.x = out.y = out.z = d;
	return out;
}
static ivec4 to_ivec4d(double d) {
	ivec4 out;
	out.x = out.y = out.z = out.w = d;
	return out;
}

static imat2x2 to_imat2x2d(double d) {
	imat2x2 out;
	out.x.x = out.y.y = d;
	out.x.y = out.y.x = 0.0;
	return out;
}
static imat2x3 to_imat2x3d(double d) {
	imat2x3 out;
	out.x.x = out.y.y = d;
	out.x.y = out.y.x = out.x.z = out.y.z = 0.0;
	return out;
}
static imat2x4 to_imat2x4d(double d) {
	imat2x4 out;
	out.x.x = out.y.y = d;
	out.x.y = out.y.x = out.x.z = out.y.z = out.x.w = out.y.w = 0.0;
	return out;
}

static imat3x2 to_imat3x2d(double d) {
	imat3x2 out;
	out.x.x = out.y.y = d;
	out.x.y = out.y.x = out.z.x = out.z.y = 0.0;
	return out;
}
static imat3x3 to_imat3x3d(double d) {
	imat3x3 out;
	out.x.x = out.y.y = out.z.z = d;
	out.x.y = out.y.x = out.x.z = out.y.z = out.z.x = out.z.y = 0.0;
	return out;
}
static imat3x4 to_imat3x4d(double d) {
	imat3x4 out;
	out.x.x = out.y.y = out.z.z = d;
	out.x.y = out.y.x = out.x.z = out.y.z = out.x.w = out.y.w = out.z.x = out.z.y = out.z.w = 0.0;
	return out;
}

static imat4x2 to_imat4x2d(double d) {
	imat4x2 out;
	out.x.x = out.y.y = d;
	out.x.y = out.y.x = out.z.x = out.z.y = out.w.x = out.w.y = 0.0;
	return out;
}
static imat4x3 to_imat4x3d(double d) {
	imat4x3 out;
	out.x.x = out.y.y = out.z.z = d;
	out.x.y = out.y.x = out.x.z = out.y.z = out.z.x = out.z.y = out.w.x = out.w.y = out.w.z = 0.0;
	return out;
}
static imat4x4 to_imat4x4d(double d) {
	imat4x4 out;
	out.x.x = out.y.y = out.z.z = out.w.w = d;
	out.x.y = out.y.x = out.x.z = out.y.z = out.x.w = out.y.w = out.z.x = out.z.y = out.z.w = out.w.x = out.w.y = out.w.z = 0.0;
	return out;
}

// internal glm types from subtypes
static imat2x2 to_imat2x2v(ivec2 x, ivec2 y) {
	imat2x2 out;
	out.x = x;
	out.y = y;
	return out;
}
static imat2x3 to_imat2x3v(ivec3 x, ivec3 y) {
	imat2x3 out;
	out.x = x;
	out.y = y;
	return out;
}
static imat2x4 to_imat2x4v(ivec4 x, ivec4 y) {
	imat2x4 out;
	out.x = x;
	out.y = y;
	return out;
}

static imat3x2 to_imat3x2v(ivec2 x, ivec2 y, ivec2 z) {
	imat3x2 out;
	out.x = x;
	out.y = y;
	out.z = z;
	return out;
}
static imat3x3 to_imat3x3v(ivec3 x, ivec3 y, ivec3 z) {
	imat3x3 out;
	out.x = x;
	out.y = y;
	out.z = z;
	return out;
}
static imat3x4 to_imat3x4v(ivec4 x, ivec4 y, ivec4 z) {
	imat3x4 out;
	out.x = x;
	out.y = y;
	out.z = z;
	return out;
}

static imat4x2 to_imat4x2v(ivec2 x, ivec2 y, ivec2 z, ivec2 w) {
	imat4x2 out;
	out.x = x;
	out.y = y;
	out.z = z;
	out.w = w;
	return out;
}
static imat4x3 to_imat4x3v(ivec3 x, ivec3 y, ivec3 z, ivec3 w) {
	imat4x3 out;
	out.x = x;
	out.y = y;
	out.z = z;
	out.w = w;
	return out;
}
static imat4x4 to_imat4x4v(ivec4 x, ivec4 y, ivec4 z, ivec4 w) {
	imat4x4 out;
	out.x = x;
	out.y = y;
	out.z = z;
	out.w = w;
	return out;
}

// pointers
// internal glm type pointers from doubles
static ivec2* to_ivec2p(double x, double y) {
	ivec2* out = (ivec2*)malloc(sizeof(*out));
	out->x = x;
	out->y = y;
	return out;
}
static ivec3* to_ivec3p(double x, double y, double z) {
	ivec3* out = (ivec3*)malloc(sizeof(*out));
	out->x = x;
	out->y = y;
	out->z = z;
	return out;
}
static ivec4* to_ivec4p(double x, double y, double z, double w) {
	ivec4* out = (ivec4*)malloc(sizeof(*out));
	out->x = x;
	out->y = y;
	out->z = z;
	out->w = w;
	return out;
}

static imat2x2* to_imat2x2p(double x0, double x1, double y0, double y1) {
	imat2x2* out = (imat2x2*)malloc(sizeof(*out));
	out->x = to_ivec2(x0, x1);
	out->y = to_ivec2(y0, y1);
	return out;
}
static imat2x3* to_imat2x3p(double x0, double x1, double x2, double y0, double y1, double y2) {
	imat2x3* out = (imat2x3*)malloc(sizeof(*out));
	out->x = to_ivec3(x0, x1, x2);
	out->y = to_ivec3(y0, y1, y2);
	return out;
}
static imat2x4* to_imat2x4p(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3) {
	imat2x4* out = (imat2x4*)malloc(sizeof(*out));
	out->x = to_ivec4(x0, x1, x2, x3);
	out->y = to_ivec4(y0, y1, y2, y3);
	return out;
}

static imat3x2* to_imat3x2p(double x0, double x1, double y0, double y1, double z0, double z1) {
	imat3x2* out = (imat3x2*)malloc(sizeof(*out));
	out->x = to_ivec2(x0, x1);
	out->y = to_ivec2(y0, y1);
	out->z = to_ivec2(z0, z1);
	return out;
}
static imat3x3* to_imat3x3p(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2) {
	imat3x3* out = (imat3x3*)malloc(sizeof(*out));
	out->x = to_ivec3(x0, x1, x2);
	out->y = to_ivec3(y0, y1, y2);
	out->z = to_ivec3(z0, z1, z2);
	return out;
}
static imat3x4* to_imat3x4p(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3) {
	imat3x4* out = (imat3x4*)malloc(sizeof(*out));
	out->x = to_ivec4(x0, x1, x2, x3);
	out->y = to_ivec4(y0, y1, y2, y3);
	out->z = to_ivec4(z0, z1, z2, z3);
	return out;
}

static imat4x2* to_imat4x2p(double x0, double x1, double y0, double y1, double z0, double z1, double w0, double w1) {
	imat4x2* out = (imat4x2*)malloc(sizeof(*out));
	out->x = to_ivec2(x0, x1);
	out->y = to_ivec2(y0, y1);
	out->z = to_ivec2(z0, z1);
	out->w = to_ivec2(w0, w1);
	return out;
}
static imat4x3* to_imat4x3p(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2, double w0, double w1, double w2) {
	imat4x3* out = (imat4x3*)malloc(sizeof(*out));
	out->x = to_ivec3(x0, x1, x2);
	out->y = to_ivec3(y0, y1, y2);
	out->z = to_ivec3(z0, z1, z2);
	out->w = to_ivec3(w0, w1, w2);
	return out;
}
static imat4x4* to_imat4x4p(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3, double w0, double w1, double w2, double w3) {
	imat4x4* out = (imat4x4*)malloc(sizeof(*out));
	out->x = to_ivec4(x0, x1, x2, x3);
	out->y = to_ivec4(y0, y1, y2, y3);
	out->z = to_ivec4(z0, z1, z2, z3);
	out->w = to_ivec4(w0, w1, w2, w3);
	return out;
}


// internal glm type pointers from scalar
static ivec2* to_ivec2dp(double d) {
	ivec2* out = (ivec2*)malloc(sizeof(*out));
	out->x = out->y = d;
	return out;
}
static ivec3* to_ivec3dp(double d) {
	ivec3* out = (ivec3*)malloc(sizeof(*out));
	out->x = out->y = out->z = d;
	return out;
}
static ivec4* to_ivec4dp(double d) {
	ivec4* out = (ivec4*)malloc(sizeof(*out));
	out->x = out->y = out->z = out->w = d;
	return out;
}

static imat2x2* to_imat2x2dp(double d) {
	imat2x2* out = (imat2x2*)malloc(sizeof(*out));
	out->x.x = out->y.y = d;
	out->x.y = out->y.x = 0.0;
	return out;
}
static imat2x3* to_imat2x3dp(double d) {
	imat2x3* out = (imat2x3*)malloc(sizeof(*out));
	out->x.x = out->y.y = d;
	out->x.y = out->y.x = out->x.z = out->y.z = 0.0;
	return out;
}
static imat2x4* to_imat2x4dp(double d) {
	imat2x4* out = (imat2x4*)malloc(sizeof(*out));
	out->x.x = out->y.y = d;
	out->x.y = out->y.x = out->x.z = out->y.z = out->x.w = out->y.w = 0.0;
	return out;
}

static imat3x2* to_imat3x2dp(double d) {
	imat3x2* out = (imat3x2*)malloc(sizeof(*out));
	out->x.x = out->y.y = d;
	out->x.y = out->y.x = out->z.x = out->z.y = 0.0;
	return out;
}
static imat3x3* to_imat3x3dp(double d) {
	imat3x3* out = (imat3x3*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = d;
	out->x.y = out->y.x = out->x.z = out->y.z = out->z.x = out->z.y = 0.0;
	return out;
}
static imat3x4* to_imat3x4dp(double d) {
	imat3x4* out = (imat3x4*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = d;
	out->x.y = out->y.x = out->x.z = out->y.z = out->x.w = out->y.w = out->z.x = out->z.y = out->z.w = 0.0;
	return out;
}

static imat4x2* to_imat4x2dp(double d) {
	imat4x2* out = (imat4x2*)malloc(sizeof(*out));
	out->x.x = out->y.y = d;
	out->x.y = out->y.x = out->z.x = out->z.y = out->w.x = out->w.y = 0.0;
	return out;
}
static imat4x3* to_imat4x3dp(double d) {
	imat4x3* out = (imat4x3*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = d;
	out->x.y = out->y.x = out->x.z = out->y.z = out->z.x = out->z.y = out->w.x = out->w.y = out->w.z = 0.0;
	return out;
}
static imat4x4* to_imat4x4dp(double d) {
	imat4x4* out = (imat4x4*)malloc(sizeof(*out));
	out->x.x = out->y.y = out->z.z = out->w.w = d;
	out->x.y = out->y.x = out->x.z = out->y.z = out->x.w = out->y.w = out->z.x = out->z.y = out->z.w = out->w.x = out->w.y = out->w.z = 0.0;
	return out;
}

// internal glm type pointers from subtypes
static imat2x2* to_imat2x2vp(ivec2* x, ivec2* y) {
	imat2x2* out = (imat2x2*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	return out;
}
static imat2x3* to_imat2x3vp(ivec3* x, ivec3* y) {
	imat2x3* out = (imat2x3*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	return out;
}
static imat2x4* to_imat2x4vp(ivec4* x, ivec4* y) {
	imat2x4* out = (imat2x4*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	return out;
}

static imat3x2* to_imat3x2vp(ivec2* x, ivec2* y, ivec2* z) {
	imat3x2* out = (imat3x2*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	out->z = *z;
	return out;
}
static imat3x3* to_imat3x3vp(ivec3* x, ivec3* y, ivec3* z) {
	imat3x3* out = (imat3x3*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	out->z = *z;
	return out;
}
static imat3x4* to_imat3x4vp(ivec4* x, ivec4* y, ivec4* z) {
	imat3x4* out = (imat3x4*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	out->z = *z;
	return out;
}

static imat4x2* to_imat4x2vp(ivec2* x, ivec2* y, ivec2* z, ivec2* w) {
	imat4x2* out = (imat4x2*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	out->z = *z;
	out->w = *w;
	return out;
}
static imat4x3* to_imat4x3vp(ivec3* x, ivec3* y, ivec3* z, ivec3* w) {
	imat4x3* out = (imat4x3*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	out->z = *z;
	out->w = *w;
	return out;
}
static imat4x4* to_imat4x4vp(ivec4* x, ivec4* y, ivec4* z, ivec4* w) {
	imat4x4* out = (imat4x4*)malloc(sizeof(*out));
	out->x = *x;
	out->y = *y;
	out->z = *z;
	out->w = *w;
	return out;
}


// internal vec aritmetics
// add
static ivec2 addv2v(ivec2 x, ivec2 y) {
	return to_ivec2(x.x + y.x, x.y + y.y);
}
static ivec3 addv3v(ivec3 x, ivec3 y) {
	return to_ivec3(x.x + y.x, x.y + y.y, x.z + y.z);
}
static ivec4 addv4v(ivec4 x, ivec4 y) {
	return to_ivec4(x.x + y.x, x.y + y.y, x.z + y.z, x.w + y.w);
}

static ivec2 addv2d(ivec2 x, double y) {
	return to_ivec2(x.x + y, x.y + y);
}
static ivec3 addv3d(ivec3 x, double y) {
	return to_ivec3(x.x + y, x.y + y, x.z + y);
}
static ivec4 addv4d(ivec4 x, double y) {
	return to_ivec4(x.x + y, x.y + y, x.z + y, x.w + y);
}

static ivec2 raddv2d(double x, ivec2 y) {
	return to_ivec2(x + y.x, x + y.y);
}
static ivec3 raddv3d(double x, ivec3 y) {
	return to_ivec3(x + y.x, x + y.y, x + y.z);
}
static ivec4 raddv4d(double x, ivec4 y) {
	return to_ivec4(x + y.x, x + y.y, x + y.z, x + y.w);
}

// sub
static ivec2 subv2v(ivec2 x, ivec2 y) {
	return to_ivec2(x.x - y.x, x.y - y.y);
}
static ivec3 subv3v(ivec3 x, ivec3 y) {
	return to_ivec3(x.x - y.x, x.y - y.y, x.z - y.z);
}
static ivec4 subv4v(ivec4 x, ivec4 y) {
	return to_ivec4(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
}

static ivec2 subv2d(ivec2 x, double y) {
	return to_ivec2(x.x - y, x.y - y);
}
static ivec3 subv3d(ivec3 x, double y) {
	return to_ivec3(x.x - y, x.y - y, x.z - y);
}
static ivec4 subv4d(ivec4 x, double y) {
	return to_ivec4(x.x - y, x.y - y, x.z - y, x.w - y);
}

static ivec2 rsubv2d(double x, ivec2 y) {
	return to_ivec2(x - y.x, x - y.y);
}
static ivec3 rsubv3d(double x, ivec3 y) {
	return to_ivec3(x - y.x, x - y.y, x - y.z);
}
static ivec4 rsubv4d(double x, ivec4 y) {
	return to_ivec4(x - y.x, x - y.y, x - y.z, x - y.w);
}

// mul
static ivec2 mulv2v(ivec2 x, ivec2 y) {
	return to_ivec2(x.x * y.x, x.y * y.y);
}
static ivec3 mulv3v(ivec3 x, ivec3 y) {
	return to_ivec3(x.x * y.x, x.y * y.y, x.z * y.z);
}
static ivec4 mulv4v(ivec4 x, ivec4 y) {
	return to_ivec4(x.x * y.x, x.y * y.y, x.z * y.z, x.w * y.w);
}

static ivec2 mulv2d(ivec2 x, double y) {
	return to_ivec2(x.x * y, x.y * y);
}
static ivec3 mulv3d(ivec3 x, double y) {
	return to_ivec3(x.x * y, x.y * y, x.z * y);
}
static ivec4 mulv4d(ivec4 x, double y) {
	return to_ivec4(x.x * y, x.y * y, x.z * y, x.w * y);
}

static ivec2 rmulv2d(double x, ivec2 y) {
	return to_ivec2(x * y.x, x * y.y);
}
static ivec3 rmulv3d(double x, ivec3 y) {
	return to_ivec3(x * y.x, x * y.y, x * y.z);
}
static ivec4 rmulv4d(double x, ivec4 y) {
	return to_ivec4(x * y.x, x * y.y, x * y.z, x * y.w);
}

// div
static ivec2 divv2v(ivec2 x, ivec2 y) {
	return to_ivec2(x.x / y.x, x.y / y.y);
}
static ivec3 divv3v(ivec3 x, ivec3 y) {
	return to_ivec3(x.x / y.x, x.y / y.y, x.z / y.z);
}
static ivec4 divv4v(ivec4 x, ivec4 y) {
	return to_ivec4(x.x / y.x, x.y / y.y, x.z / y.z, x.w / y.w);
}

static ivec2 divv2d(ivec2 x, double y) {
	return to_ivec2(x.x / y, x.y / y);
}
static ivec3 divv3d(ivec3 x, double y) {
	return to_ivec3(x.x / y, x.y / y, x.z / y);
}
static ivec4 divv4d(ivec4 x, double y) {
	return to_ivec4(x.x / y, x.y / y, x.z / y, x.w / y);
}

static ivec2 rdivv2d(double x, ivec2 y) {
	return to_ivec2(x / y.x, x / y.y);
}
static ivec3 rdivv3d(double x, ivec3 y) {
	return to_ivec3(x / y.x, x / y.y, x / y.z);
}
static ivec4 rdivv4d(double x, ivec4 y) {
	return to_ivec4(x / y.x, x / y.y, x / y.z, x / y.w);
}

// with pointers
// add
static ivec2* addv2vp(ivec2* x, ivec2* y) {
	return to_ivec2p(x->x + y->x, x->y + y->y);
}
static ivec3* addv3vp(ivec3* x, ivec3* y) {
	return to_ivec3p(x->x + y->x, x->y + y->y, x->z + y->z);
}
static ivec4* addv4vp(ivec4* x, ivec4* y) {
	return to_ivec4p(x->x + y->x, x->y + y->y, x->z + y->z, x->w + y->w);
}

static ivec2* addv2dp(ivec2* x, double y) {
	return to_ivec2p(x->x + y, x->y + y);
}
static ivec3* addv3dp(ivec3* x, double y) {
	return to_ivec3p(x->x + y, x->y + y, x->z + y);
}
static ivec4* addv4dp(ivec4* x, double y) {
	return to_ivec4p(x->x + y, x->y + y, x->z + y, x->w + y);
}

static ivec2* raddv2dp(double x, ivec2* y) {
	return to_ivec2p(x + y->x, x + y->y);
}
static ivec3* raddv3dp(double x, ivec3* y) {
	return to_ivec3p(x + y->x, x + y->y, x + y->z);
}
static ivec4* raddv4dp(double x, ivec4* y) {
	return to_ivec4p(x + y->x, x + y->y, x + y->z, x + y->w);
}

// sub
static ivec2* subv2vp(ivec2* x, ivec2* y) {
	return to_ivec2p(x->x - y->x, x->y - y->y);
}
static ivec3* subv3vp(ivec3* x, ivec3* y) {
	return to_ivec3p(x->x - y->x, x->y - y->y, x->z - y->z);
}
static ivec4* subv4vp(ivec4* x, ivec4* y) {
	return to_ivec4p(x->x - y->x, x->y - y->y, x->z - y->z, x->w - y->w);
}

static ivec2* subv2dp(ivec2* x, double y) {
	return to_ivec2p(x->x - y, x->y - y);
}
static ivec3* subv3dp(ivec3* x, double y) {
	return to_ivec3p(x->x - y, x->y - y, x->z - y);
}
static ivec4* subv4dp(ivec4* x, double y) {
	return to_ivec4p(x->x - y, x->y - y, x->z - y, x->w - y);
}

static ivec2* rsubv2dp(double x, ivec2* y) {
	return to_ivec2p(x - y->x, x - y->y);
}
static ivec3* rsubv3dp(double x, ivec3* y) {
	return to_ivec3p(x - y->x, x - y->y, x - y->z);
}
static ivec4* rsubv4dp(double x, ivec4* y) {
	return to_ivec4p(x - y->x, x - y->y, x - y->z, x - y->w);
}

// mul
static ivec2* mulv2vp(ivec2* x, ivec2* y) {
	return to_ivec2p(x->x * y->x, x->y * y->y);
}
static ivec3* mulv3vp(ivec3* x, ivec3* y) {
	return to_ivec3p(x->x * y->x, x->y * y->y, x->z * y->z);
}
static ivec4* mulv4vp(ivec4* x, ivec4* y) {
	return to_ivec4p(x->x * y->x, x->y * y->y, x->z * y->z, x->w * y->w);
}

static ivec2* mulv2dp(ivec2* x, double y) {
	return to_ivec2p(x->x * y, x->y * y);
}
static ivec3* mulv3dp(ivec3* x, double y) {
	return to_ivec3p(x->x * y, x->y * y, x->z * y);
}
static ivec4* mulv4dp(ivec4* x, double y) {
	return to_ivec4p(x->x * y, x->y * y, x->z * y, x->w * y);
}

static ivec2* rmulv2dp(double x, ivec2* y) {
	return to_ivec2p(x * y->x, x * y->y);
}
static ivec3* rmulv3dp(double x, ivec3* y) {
	return to_ivec3p(x * y->x, x * y->y, x * y->z);
}
static ivec4* rmulv4dp(double x, ivec4* y) {
	return to_ivec4p(x * y->x, x * y->y, x * y->z, x * y->w);
}

// div
static ivec2* divv2vp(ivec2* x, ivec2* y) {
	return to_ivec2p(x->x / y->x, x->y / y->y);
}
static ivec3* divv3vp(ivec3* x, ivec3* y) {
	return to_ivec3p(x->x / y->x, x->y / y->y, x->z / y->z);
}
static ivec4* divv4vp(ivec4* x, ivec4* y) {
	return to_ivec4p(x->x / y->x, x->y / y->y, x->z / y->z, x->w / y->w);
}

static ivec2* divv2dp(ivec2* x, double y) {
	return to_ivec2p(x->x / y, x->y / y);
}
static ivec3* divv3dp(ivec3* x, double y) {
	return to_ivec3p(x->x / y, x->y / y, x->z / y);
}
static ivec4* divv4dp(ivec4* x, double y) {
	return to_ivec4p(x->x / y, x->y / y, x->z / y, x->w / y);
}

static ivec2* rdivv2dp(double x, ivec2* y) {
	return to_ivec2p(x / y->x, x / y->y);
}
static ivec3* rdivv3dp(double x, ivec3* y) {
	return to_ivec3p(x / y->x, x / y->y, x / y->z);
}
static ivec4* rdivv4dp(double x, ivec4* y) {
	return to_ivec4p(x / y->x, x / y->y, x / y->z, x / y->w);
}

// conversion from PyObject * to glm internal types
static char unpack_ivec(PyObject * arg, void** o) {
	if (PyObject_TypeCheck(arg, &tvec2Type)) {
		*o = malloc(sizeof(ivec2));
		*((ivec2*)*o) = to_ivec2(((tvec2*)arg)->x, ((tvec2*)arg)->y);
		return GLM_TVEC2;
	}
	if (PyObject_TypeCheck(arg, &tvec3Type)) {
		*o = malloc(sizeof(ivec3));
		*((ivec3*)*o) = to_ivec3(((tvec3*)arg)->x, ((tvec3*)arg)->y, ((tvec3*)arg)->z);
		return GLM_TVEC3;
	}
	if (PyObject_TypeCheck(arg, &tvec4Type)) {
		*o = malloc(sizeof(ivec4));
		*((ivec4*)*o) = to_ivec4(((tvec4*)arg)->x, ((tvec4*)arg)->y, ((tvec4*)arg)->z, ((tvec4*)arg)->w);
		return GLM_TVEC4;
	}
	if (PyTuple_Check(arg)) {
		Py_ssize_t len = PyTuple_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
				*o = malloc(sizeof(ivec2));
				*((ivec2*)*o) = to_ivec2(pyvalue_as_double(arg1), pyvalue_as_double(arg2));
				return GLM_TVEC2;
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
				*o = malloc(sizeof(ivec3));
				*((ivec3*)*o) = to_ivec3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3));
				return GLM_TVEC3;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(ivec4));
				*((ivec4*)*o) = to_ivec4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TVEC4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	if (PyList_Check(arg)) {
		Py_ssize_t len = PyList_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
				*o = malloc(sizeof(ivec2));
				*((ivec2*)*o) = to_ivec2(pyvalue_as_double(arg1), pyvalue_as_double(arg2));
				return GLM_TVEC2;
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
				*o = malloc(sizeof(ivec3));
				*((ivec3*)*o) = to_ivec3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3));
				return GLM_TVEC3;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(ivec4));
				*((ivec4*)*o) = to_ivec4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TVEC4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	return GLM_NONE;
}

static char unpack_imat(PyObject * arg, void** o) {
	if (PyObject_TypeCheck(arg, &tmat2x2Type)) {
		*o = malloc(sizeof(imat2x2));
		*((imat2x2*)*o) = to_imat2x2(((tmat2x2*)arg)->x->x, ((tmat2x2*)arg)->x->y, ((tmat2x2*)arg)->y->x, ((tmat2x2*)arg)->y->y);
		return GLM_TMAT2x2;
	}
	if (PyObject_TypeCheck(arg, &tmat2x3Type)) {
		*o = malloc(sizeof(imat2x3));
		*((imat2x3*)*o) = to_imat2x3(((tmat2x3*)arg)->x->x, ((tmat2x3*)arg)->x->y, ((tmat2x3*)arg)->x->z, ((tmat2x3*)arg)->y->x, ((tmat2x3*)arg)->y->y,  ((tmat2x3*)arg)->y->z);
		return GLM_TMAT2x3;
	}
	if (PyObject_TypeCheck(arg, &tmat2x4Type)) {
		*o = malloc(sizeof(imat2x4));
		*((imat2x4*)*o) = to_imat2x4(((tmat2x4*)arg)->x->x, ((tmat2x4*)arg)->x->y, ((tmat2x4*)arg)->x->z, ((tmat2x4*)arg)->x->w, ((tmat2x4*)arg)->y->x, ((tmat2x4*)arg)->y->y, ((tmat2x4*)arg)->y->z, ((tmat2x4*)arg)->y->w);
		return GLM_TMAT2x4;
	}
	if (PyObject_TypeCheck(arg, &tmat3x2Type)) {
		*o = malloc(sizeof(imat3x2));
		*((imat3x2*)*o) = to_imat3x2(((tmat3x2*)arg)->x->x, ((tmat3x2*)arg)->x->y, ((tmat3x2*)arg)->y->x, ((tmat3x2*)arg)->y->y, ((tmat3x2*)arg)->z->x, ((tmat3x2*)arg)->z->y);
		return GLM_TMAT3x2;
	}
	if (PyObject_TypeCheck(arg, &tmat3x3Type)) {
		*o = malloc(sizeof(imat3x3));
		*((imat3x3*)*o) = to_imat3x3(((tmat3x3*)arg)->x->x, ((tmat3x3*)arg)->x->y, ((tmat3x3*)arg)->x->z, ((tmat3x3*)arg)->y->x, ((tmat3x3*)arg)->y->y, ((tmat3x3*)arg)->y->z, ((tmat3x3*)arg)->z->x, ((tmat3x3*)arg)->z->y, ((tmat3x3*)arg)->z->z);
		return GLM_TMAT3x3;
	}
	if (PyObject_TypeCheck(arg, &tmat3x4Type)) {
		*o = malloc(sizeof(imat3x4));
		*((imat3x4*)*o) = to_imat3x4(((tmat3x4*)arg)->x->x, ((tmat3x4*)arg)->x->y, ((tmat3x4*)arg)->x->z, ((tmat3x4*)arg)->x->w, ((tmat3x4*)arg)->y->x, ((tmat3x4*)arg)->y->y, ((tmat3x4*)arg)->y->z, ((tmat3x4*)arg)->y->w, ((tmat3x4*)arg)->z->x, ((tmat3x4*)arg)->z->y, ((tmat3x4*)arg)->z->z, ((tmat3x4*)arg)->z->w);
		return GLM_TMAT3x4;
	}
	if (PyObject_TypeCheck(arg, &tmat4x2Type)) {
		*o = malloc(sizeof(imat4x2));
		*((imat4x2*)*o) = to_imat4x2(((tmat4x2*)arg)->x->x, ((tmat4x2*)arg)->x->y, ((tmat4x2*)arg)->y->x, ((tmat4x2*)arg)->y->y, ((tmat4x2*)arg)->z->x, ((tmat4x2*)arg)->z->y, ((tmat4x2*)arg)->w->x, ((tmat4x2*)arg)->w->y);
		return GLM_TMAT4x2;
	}
	if (PyObject_TypeCheck(arg, &tmat4x3Type)) {
		*o = malloc(sizeof(imat4x3));
		*((imat4x3*)*o) = to_imat4x3(((tmat4x3*)arg)->x->x, ((tmat4x3*)arg)->x->y, ((tmat4x3*)arg)->x->z, ((tmat4x3*)arg)->y->x, ((tmat4x3*)arg)->y->y, ((tmat4x3*)arg)->y->z, ((tmat4x3*)arg)->z->x, ((tmat4x3*)arg)->z->y, ((tmat4x3*)arg)->z->z, ((tmat4x3*)arg)->w->x, ((tmat4x3*)arg)->w->y, ((tmat4x3*)arg)->w->z);
		return GLM_TMAT4x3;
	}
	if (PyObject_TypeCheck(arg, &tmat4x4Type)) {
		*o = malloc(sizeof(imat4x4));
		*((imat4x4*)*o) = to_imat4x4(((tmat4x4*)arg)->x->x, ((tmat4x4*)arg)->x->y, ((tmat4x4*)arg)->x->z, ((tmat4x4*)arg)->x->w, ((tmat4x4*)arg)->y->x, ((tmat4x4*)arg)->y->y, ((tmat4x4*)arg)->y->z, ((tmat4x4*)arg)->y->w, ((tmat4x4*)arg)->z->x, ((tmat4x4*)arg)->z->y, ((tmat4x4*)arg)->z->z, ((tmat4x4*)arg)->z->w, ((tmat4x4*)arg)->w->x, ((tmat4x4*)arg)->w->y, ((tmat4x4*)arg)->w->z, ((tmat4x4*)arg)->w->w);
		return GLM_TMAT4x4;
	}
	if (PyTuple_Check(arg)) {
		Py_ssize_t len = PyTuple_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			void *x, *y;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat2x2));
					*((imat2x2*)*o) = to_imat2x2v(*((ivec2*)x), *((ivec2*)y));
					return GLM_TMAT2x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat2x3));
					*((imat2x3*)*o) = to_imat2x3v(*((ivec3*)x), *((ivec3*)y));
					return GLM_TMAT2x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat2x4));
					*((imat2x4*)*o) = to_imat2x4v(*((ivec4*)x), *((ivec4*)y));
					return GLM_TMAT2x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			void *x, *y, *z;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat3x2));
					*((imat3x2*)*o) = to_imat3x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z));
					return GLM_TMAT3x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat3x3));
					*((imat3x3*)*o) = to_imat3x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z));
					return GLM_TMAT3x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat3x4));
					*((imat3x4*)*o) = to_imat3x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z));
					return GLM_TMAT3x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(imat2x2));
				*((imat2x2*)*o) = to_imat2x2(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TMAT2x2;
			}
			void *x, *y, *z, *w;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType && unpack_ivec(arg4, &w)) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat4x2));
					*((imat4x2*)*o) = to_imat4x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z), *((ivec2*)w));
					return GLM_TMAT4x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat4x3));
					*((imat4x3*)*o) = to_imat4x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z), *((ivec3*)w));
					return GLM_TMAT4x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat4x4));
					*((imat4x4*)*o) = to_imat4x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z), *((ivec4*)w));
					return GLM_TMAT4x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 6) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
				*o = malloc(sizeof(imat2x3));
				*((imat2x3*)*o) = to_imat2x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6));
				return GLM_TMAT2x3;
			}
			return GLM_NONE;
		}
		if (len == 8) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8)) {
				*o = malloc(sizeof(imat2x4));
				*((imat2x4*)*o) = to_imat2x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8));
				return GLM_TMAT2x4;
			}
			return GLM_NONE;
		}
		if (len == 9) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9)) {
				*o = malloc(sizeof(imat3x3));
				*((imat3x3*)*o) = to_imat3x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9));
				return GLM_TMAT3x3;
			}
			return GLM_NONE;
		}
		if (len == 12) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			arg10 = PyTuple_GET_ITEM(arg, 9);
			arg11 = PyTuple_GET_ITEM(arg, 10);
			arg12 = PyTuple_GET_ITEM(arg, 11);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12)) {
				*o = malloc(sizeof(imat3x4));
				*((imat3x4*)*o) = to_imat3x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12));
				return GLM_TMAT3x4;
			}
			return GLM_NONE;
		}
		if (len == 16) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12, *arg13, *arg14, *arg15, *arg16;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			arg10 = PyTuple_GET_ITEM(arg, 9);
			arg11 = PyTuple_GET_ITEM(arg, 10);
			arg12 = PyTuple_GET_ITEM(arg, 11);
			arg13 = PyTuple_GET_ITEM(arg, 12);
			arg14 = PyTuple_GET_ITEM(arg, 13);
			arg15 = PyTuple_GET_ITEM(arg, 14);
			arg16 = PyTuple_GET_ITEM(arg, 15);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12) && IS_NUMERIC(arg13) && IS_NUMERIC(arg14) && IS_NUMERIC(arg15) && IS_NUMERIC(arg16)) {
				*o = malloc(sizeof(imat4x4));
				*((imat4x4*)*o) = to_imat4x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12), pyvalue_as_double(arg13), pyvalue_as_double(arg14), pyvalue_as_double(arg15), pyvalue_as_double(arg16));
				return GLM_TMAT4x4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	if (PyList_Check(arg)) {
		Py_ssize_t len = PyList_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			void *x, *y;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat2x2));
					*((imat2x2*)*o) = to_imat2x2v(*((ivec2*)x), *((ivec2*)y));
					return GLM_TMAT2x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat2x3));
					*((imat2x3*)*o) = to_imat2x3v(*((ivec3*)x), *((ivec3*)y));
					return GLM_TMAT2x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat2x4));
					*((imat2x4*)*o) = to_imat2x4v(*((ivec4*)x), *((ivec4*)y));
					return GLM_TMAT2x4;
				}
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			void *x, *y, *z;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat3x2));
					*((imat3x2*)*o) = to_imat3x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z));
					return GLM_TMAT3x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat3x3));
					*((imat3x3*)*o) = to_imat3x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z));
					return GLM_TMAT3x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat3x4));
					*((imat3x4*)*o) = to_imat3x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z));
					return GLM_TMAT3x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(imat2x2));
				*((imat2x2*)*o) = to_imat2x2(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TMAT2x2;
			}
			void *x, *y, *z, *w;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType && unpack_ivec(arg4, &w)) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat4x2));
					*((imat4x2*)*o) = to_imat4x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z), *((ivec2*)w));
					return GLM_TMAT4x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat4x3));
					*((imat4x3*)*o) = to_imat4x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z), *((ivec3*)w));
					return GLM_TMAT4x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat4x4));
					*((imat4x4*)*o) = to_imat4x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z), *((ivec4*)w));
					return GLM_TMAT4x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 6) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
				*o = malloc(sizeof(imat2x3));
				*((imat2x3*)*o) = to_imat2x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6));
				return GLM_TMAT2x3;
			}
			return GLM_NONE;
		}
		if (len == 8) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8)) {
				*o = malloc(sizeof(imat2x4));
				*((imat2x4*)*o) = to_imat2x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8));
				return GLM_TMAT2x4;
			}
			return GLM_NONE;
		}
		if (len == 9) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9)) {
				*o = malloc(sizeof(imat3x3));
				*((imat3x3*)*o) = to_imat3x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9));
				return GLM_TMAT3x3;
			}
			return GLM_NONE;
		}
		if (len == 12) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			arg10 = PyList_GET_ITEM(arg, 9);
			arg11 = PyList_GET_ITEM(arg, 10);
			arg12 = PyList_GET_ITEM(arg, 11);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12)) {
				*o = malloc(sizeof(imat3x4));
				*((imat3x4*)*o) = to_imat3x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12));
				return GLM_TMAT3x4;
			}
			return GLM_NONE;
		}
		if (len == 16) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12, *arg13, *arg14, *arg15, *arg16;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			arg10 = PyList_GET_ITEM(arg, 9);
			arg11 = PyList_GET_ITEM(arg, 10);
			arg12 = PyList_GET_ITEM(arg, 11);
			arg13 = PyList_GET_ITEM(arg, 12);
			arg14 = PyList_GET_ITEM(arg, 13);
			arg15 = PyList_GET_ITEM(arg, 14);
			arg16 = PyList_GET_ITEM(arg, 15);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12) && IS_NUMERIC(arg13) && IS_NUMERIC(arg14) && IS_NUMERIC(arg15) && IS_NUMERIC(arg16)) {
				*o = malloc(sizeof(imat4x4));
				*((imat4x4*)*o) = to_imat4x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12), pyvalue_as_double(arg13), pyvalue_as_double(arg14), pyvalue_as_double(arg15), pyvalue_as_double(arg16));
				return GLM_TMAT4x4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	return GLM_NONE;
}

static char unpack_isqmat(PyObject * arg, void** o) {
	if (PyObject_TypeCheck(arg, &tmat2x2Type)) {
		*o = malloc(sizeof(imat2x2));
		*((imat2x2*)*o) = to_imat2x2(((tmat2x2*)arg)->x->x, ((tmat2x2*)arg)->x->y, ((tmat2x2*)arg)->y->x, ((tmat2x2*)arg)->y->y);
		return GLM_TMAT2x2;
	}
	if (PyObject_TypeCheck(arg, &tmat3x3Type)) {
		*o = malloc(sizeof(imat3x3));
		*((imat3x3*)*o) = to_imat3x3(((tmat3x3*)arg)->x->x, ((tmat3x3*)arg)->x->y, ((tmat3x3*)arg)->x->z, ((tmat3x3*)arg)->y->x, ((tmat3x3*)arg)->y->y, ((tmat3x3*)arg)->y->z, ((tmat3x3*)arg)->z->x, ((tmat3x3*)arg)->z->y, ((tmat3x3*)arg)->z->z);
		return GLM_TMAT3x3;
	}
	if (PyObject_TypeCheck(arg, &tmat4x4Type)) {
		*o = malloc(sizeof(imat4x4));
		*((imat4x4*)*o) = to_imat4x4(((tmat4x4*)arg)->x->x, ((tmat4x4*)arg)->x->y, ((tmat4x4*)arg)->x->z, ((tmat4x4*)arg)->x->w, ((tmat4x4*)arg)->y->x, ((tmat4x4*)arg)->y->y, ((tmat4x4*)arg)->y->z, ((tmat4x4*)arg)->y->w, ((tmat4x4*)arg)->z->x, ((tmat4x4*)arg)->z->y, ((tmat4x4*)arg)->z->z, ((tmat4x4*)arg)->z->w, ((tmat4x4*)arg)->w->x, ((tmat4x4*)arg)->w->y, ((tmat4x4*)arg)->w->z, ((tmat4x4*)arg)->w->w);
		return GLM_TMAT4x4;
	}
	if (PyTuple_Check(arg)) {
		Py_ssize_t len = PyTuple_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			void *x, *y;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat2x2));
					*((imat2x2*)*o) = to_imat2x2v(*((ivec2*)x), *((ivec2*)y));
					return GLM_TMAT2x2;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			void *x, *y, *z;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType) {
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat3x3));
					*((imat3x3*)*o) = to_imat3x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z));
					return GLM_TMAT3x3;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(imat2x2));
				*((imat2x2*)*o) = to_imat2x2(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TMAT2x2;
			}
			void *x, *y, *z, *w;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType && unpack_ivec(arg4, &w)) {
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat4x4));
					*((imat4x4*)*o) = to_imat4x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z), *((ivec4*)w));
					return GLM_TMAT4x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 9) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9)) {
				*o = malloc(sizeof(imat3x3));
				*((imat3x3*)*o) = to_imat3x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9));
				return GLM_TMAT3x3;
			}
			return GLM_NONE;
		}
		if (len == 16) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12, *arg13, *arg14, *arg15, *arg16;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			arg10 = PyTuple_GET_ITEM(arg, 9);
			arg11 = PyTuple_GET_ITEM(arg, 10);
			arg12 = PyTuple_GET_ITEM(arg, 11);
			arg13 = PyTuple_GET_ITEM(arg, 12);
			arg14 = PyTuple_GET_ITEM(arg, 13);
			arg15 = PyTuple_GET_ITEM(arg, 14);
			arg16 = PyTuple_GET_ITEM(arg, 15);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12) && IS_NUMERIC(arg13) && IS_NUMERIC(arg14) && IS_NUMERIC(arg15) && IS_NUMERIC(arg16)) {
				*o = malloc(sizeof(imat4x4));
				*((imat4x4*)*o) = to_imat4x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12), pyvalue_as_double(arg13), pyvalue_as_double(arg14), pyvalue_as_double(arg15), pyvalue_as_double(arg16));
				return GLM_TMAT4x4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	if (PyList_Check(arg)) {
		Py_ssize_t len = PyList_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			void *x, *y;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat2x2));
					*((imat2x2*)*o) = to_imat2x2v(*((ivec2*)x), *((ivec2*)y));
					return GLM_TMAT2x2;
				}
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			void *x, *y, *z;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType) {
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat3x3));
					*((imat3x3*)*o) = to_imat3x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z));
					return GLM_TMAT3x3;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(imat2x2));
				*((imat2x2*)*o) = to_imat2x2(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TMAT2x2;
			}
			void *x, *y, *z, *w;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType && unpack_ivec(arg4, &w)) {
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat4x4));
					*((imat4x4*)*o) = to_imat4x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z), *((ivec4*)w));
					return GLM_TMAT4x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 9) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9)) {
				*o = malloc(sizeof(imat3x3));
				*((imat3x3*)*o) = to_imat3x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9));
				return GLM_TMAT3x3;
			}
			return GLM_NONE;
		}
		if (len == 16) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12, *arg13, *arg14, *arg15, *arg16;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			arg10 = PyList_GET_ITEM(arg, 9);
			arg11 = PyList_GET_ITEM(arg, 10);
			arg12 = PyList_GET_ITEM(arg, 11);
			arg13 = PyList_GET_ITEM(arg, 12);
			arg14 = PyList_GET_ITEM(arg, 13);
			arg15 = PyList_GET_ITEM(arg, 14);
			arg16 = PyList_GET_ITEM(arg, 15);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12) && IS_NUMERIC(arg13) && IS_NUMERIC(arg14) && IS_NUMERIC(arg15) && IS_NUMERIC(arg16)) {
				*o = malloc(sizeof(imat4x4));
				*((imat4x4*)*o) = to_imat4x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12), pyvalue_as_double(arg13), pyvalue_as_double(arg14), pyvalue_as_double(arg15), pyvalue_as_double(arg16));
				return GLM_TMAT4x4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	return GLM_NONE;
}

static char unpack_pyobject(PyObject * arg, void** o) {
	if (PyObject_TypeCheck(arg, &tvec2Type)) {
		*o = malloc(sizeof(ivec2));
		*((ivec2*)*o) = to_ivec2(((tvec2*)arg)->x, ((tvec2*)arg)->y);
		return GLM_TVEC2;
	}
	if (PyObject_TypeCheck(arg, &tvec3Type)) {
		*o = malloc(sizeof(ivec3));
		*((ivec3*)*o) = to_ivec3(((tvec3*)arg)->x, ((tvec3*)arg)->y, ((tvec3*)arg)->z);
		return GLM_TVEC3;
	}
	if (PyObject_TypeCheck(arg, &tvec4Type)) {
		*o = malloc(sizeof(ivec4));
		*((ivec4*)*o) = to_ivec4(((tvec4*)arg)->x, ((tvec4*)arg)->y, ((tvec4*)arg)->z, ((tvec4*)arg)->w);
		return GLM_TVEC4;
	}
	if (PyObject_TypeCheck(arg, &tmat2x2Type)) {
		*o = malloc(sizeof(imat2x2));
		*((imat2x2*)*o) = to_imat2x2(((tmat2x2*)arg)->x->x, ((tmat2x2*)arg)->x->y, ((tmat2x2*)arg)->y->x, ((tmat2x2*)arg)->y->y);
		return GLM_TMAT2x2;
	}
	if (PyObject_TypeCheck(arg, &tmat2x3Type)) {
		*o = malloc(sizeof(imat2x3));
		*((imat2x3*)*o) = to_imat2x3(((tmat2x3*)arg)->x->x, ((tmat2x3*)arg)->x->y, ((tmat2x3*)arg)->x->z, ((tmat2x3*)arg)->y->x, ((tmat2x3*)arg)->y->y, ((tmat2x3*)arg)->y->z);
		return GLM_TMAT2x3;
	}
	if (PyObject_TypeCheck(arg, &tmat2x4Type)) {
		*o = malloc(sizeof(imat2x4));
		*((imat2x4*)*o) = to_imat2x4(((tmat2x4*)arg)->x->x, ((tmat2x4*)arg)->x->y, ((tmat2x4*)arg)->x->z, ((tmat2x4*)arg)->x->w, ((tmat2x4*)arg)->y->x, ((tmat2x4*)arg)->y->y, ((tmat2x4*)arg)->y->z, ((tmat2x4*)arg)->y->w);
		return GLM_TMAT2x4;
	}
	if (PyObject_TypeCheck(arg, &tmat3x2Type)) {
		*o = malloc(sizeof(imat3x2));
		*((imat3x2*)*o) = to_imat3x2(((tmat3x2*)arg)->x->x, ((tmat3x2*)arg)->x->y, ((tmat3x2*)arg)->y->x, ((tmat3x2*)arg)->y->y, ((tmat3x2*)arg)->z->x, ((tmat3x2*)arg)->z->y);
		return GLM_TMAT3x2;
	}
	if (PyObject_TypeCheck(arg, &tmat3x3Type)) {
		*o = malloc(sizeof(imat3x3));
		*((imat3x3*)*o) = to_imat3x3(((tmat3x3*)arg)->x->x, ((tmat3x3*)arg)->x->y, ((tmat3x3*)arg)->x->z, ((tmat3x3*)arg)->y->x, ((tmat3x3*)arg)->y->y, ((tmat3x3*)arg)->y->z, ((tmat3x3*)arg)->z->x, ((tmat3x3*)arg)->z->y, ((tmat3x3*)arg)->z->z);
		return GLM_TMAT3x3;
	}
	if (PyObject_TypeCheck(arg, &tmat3x4Type)) {
		*o = malloc(sizeof(imat3x4));
		*((imat3x4*)*o) = to_imat3x4(((tmat3x4*)arg)->x->x, ((tmat3x4*)arg)->x->y, ((tmat3x4*)arg)->x->z, ((tmat3x4*)arg)->x->w, ((tmat3x4*)arg)->y->x, ((tmat3x4*)arg)->y->y, ((tmat3x4*)arg)->y->z, ((tmat3x4*)arg)->y->w, ((tmat3x4*)arg)->z->x, ((tmat3x4*)arg)->z->y, ((tmat3x4*)arg)->z->z, ((tmat3x4*)arg)->z->w);
		return GLM_TMAT3x4;
	}
	if (PyObject_TypeCheck(arg, &tmat4x2Type)) {
		*o = malloc(sizeof(imat4x2));
		*((imat4x2*)*o) = to_imat4x2(((tmat4x2*)arg)->x->x, ((tmat4x2*)arg)->x->y, ((tmat4x2*)arg)->y->x, ((tmat4x2*)arg)->y->y, ((tmat4x2*)arg)->z->x, ((tmat4x2*)arg)->z->y, ((tmat4x2*)arg)->w->x, ((tmat4x2*)arg)->w->y);
		return GLM_TMAT4x2;
	}
	if (PyObject_TypeCheck(arg, &tmat4x3Type)) {
		*o = malloc(sizeof(imat4x3));
		*((imat4x3*)*o) = to_imat4x3(((tmat4x3*)arg)->x->x, ((tmat4x3*)arg)->x->y, ((tmat4x3*)arg)->x->z, ((tmat4x3*)arg)->y->x, ((tmat4x3*)arg)->y->y, ((tmat4x3*)arg)->y->z, ((tmat4x3*)arg)->z->x, ((tmat4x3*)arg)->z->y, ((tmat4x3*)arg)->z->z, ((tmat4x3*)arg)->w->x, ((tmat4x3*)arg)->w->y, ((tmat4x3*)arg)->w->z);
		return GLM_TMAT4x3;
	}
	if (PyObject_TypeCheck(arg, &tmat4x4Type)) {
		*o = malloc(sizeof(imat4x4));
		*((imat4x4*)*o) = to_imat4x4(((tmat4x4*)arg)->x->x, ((tmat4x4*)arg)->x->y, ((tmat4x4*)arg)->x->z, ((tmat4x4*)arg)->x->w, ((tmat4x4*)arg)->y->x, ((tmat4x4*)arg)->y->y, ((tmat4x4*)arg)->y->z, ((tmat4x4*)arg)->y->w, ((tmat4x4*)arg)->z->x, ((tmat4x4*)arg)->z->y, ((tmat4x4*)arg)->z->z, ((tmat4x4*)arg)->z->w, ((tmat4x4*)arg)->w->x, ((tmat4x4*)arg)->w->y, ((tmat4x4*)arg)->w->z, ((tmat4x4*)arg)->w->w);
		return GLM_TMAT4x4;
	}
	if (PyTuple_Check(arg)) {
		Py_ssize_t len = PyTuple_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
				*o = malloc(sizeof(ivec2));
				*((ivec2*)*o) = to_ivec2(pyvalue_as_double(arg1), pyvalue_as_double(arg2));
				return GLM_TVEC2;
			}
			void *x, *y;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat2x2));
					*((imat2x2*)*o) = to_imat2x2v(*((ivec2*)x), *((ivec2*)y));
					return GLM_TMAT2x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat2x3));
					*((imat2x3*)*o) = to_imat2x3v(*((ivec3*)x), *((ivec3*)y));
					return GLM_TMAT2x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat2x4));
					*((imat2x4*)*o) = to_imat2x4v(*((ivec4*)x), *((ivec4*)y));
					return GLM_TMAT2x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
				*o = malloc(sizeof(ivec3));
				*((ivec3*)*o) = to_ivec3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3));
				return GLM_TVEC3;
			}
			void *x, *y, *z;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat3x2));
					*((imat3x2*)*o) = to_imat3x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z));
					return GLM_TMAT3x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat3x3));
					*((imat3x3*)*o) = to_imat3x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z));
					return GLM_TMAT3x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat3x4));
					*((imat3x4*)*o) = to_imat3x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z));
					return GLM_TMAT3x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(ivec4));
				*((ivec4*)*o) = to_ivec4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TVEC4;
			}
			void *x, *y, *z, *w;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType && unpack_ivec(arg4, &w)) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat4x2));
					*((imat4x2*)*o) = to_imat4x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z), *((ivec2*)w));
					return GLM_TMAT4x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat4x3));
					*((imat4x3*)*o) = to_imat4x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z), *((ivec3*)w));
					return GLM_TMAT4x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat4x4));
					*((imat4x4*)*o) = to_imat4x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z), *((ivec4*)w));
					return GLM_TMAT4x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 6) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
				*o = malloc(sizeof(imat2x3));
				*((imat2x3*)*o) = to_imat2x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6));
				return GLM_TMAT2x3;
			}
		}
		if (len == 8) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8)) {
				*o = malloc(sizeof(imat2x4));
				*((imat2x4*)*o) = to_imat2x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8));
				return GLM_TMAT2x4;
			}
			return GLM_NONE;
		}
		if (len == 9) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9)) {
				*o = malloc(sizeof(imat3x3));
				*((imat3x3*)*o) = to_imat3x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9));
				return GLM_TMAT3x3;
			}
			return GLM_NONE;
		}
		if (len == 12) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			arg10 = PyTuple_GET_ITEM(arg, 9);
			arg11 = PyTuple_GET_ITEM(arg, 10);
			arg12 = PyTuple_GET_ITEM(arg, 11);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12)) {
				*o = malloc(sizeof(imat3x4));
				*((imat3x4*)*o) = to_imat3x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12));
				return GLM_TMAT3x4;
			}
			return GLM_NONE;
		}
		if (len == 16) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12, *arg13, *arg14, *arg15, *arg16;
			arg1 = PyTuple_GET_ITEM(arg, 0);
			arg2 = PyTuple_GET_ITEM(arg, 1);
			arg3 = PyTuple_GET_ITEM(arg, 2);
			arg4 = PyTuple_GET_ITEM(arg, 3);
			arg5 = PyTuple_GET_ITEM(arg, 4);
			arg6 = PyTuple_GET_ITEM(arg, 5);
			arg7 = PyTuple_GET_ITEM(arg, 6);
			arg8 = PyTuple_GET_ITEM(arg, 7);
			arg9 = PyTuple_GET_ITEM(arg, 8);
			arg10 = PyTuple_GET_ITEM(arg, 9);
			arg11 = PyTuple_GET_ITEM(arg, 10);
			arg12 = PyTuple_GET_ITEM(arg, 11);
			arg13 = PyTuple_GET_ITEM(arg, 12);
			arg14 = PyTuple_GET_ITEM(arg, 13);
			arg15 = PyTuple_GET_ITEM(arg, 14);
			arg16 = PyTuple_GET_ITEM(arg, 15);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12) && IS_NUMERIC(arg13) && IS_NUMERIC(arg14) && IS_NUMERIC(arg15) && IS_NUMERIC(arg16)) {
				*o = malloc(sizeof(imat4x4));
				*((imat4x4*)*o) = to_imat4x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12), pyvalue_as_double(arg13), pyvalue_as_double(arg14), pyvalue_as_double(arg15), pyvalue_as_double(arg16));
				return GLM_TMAT4x4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	if (PyList_Check(arg)) {
		Py_ssize_t len = PyList_GET_SIZE(arg);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
				*o = malloc(sizeof(ivec2));
				*((ivec2*)*o) = to_ivec2(pyvalue_as_double(arg1), pyvalue_as_double(arg2));
				return GLM_TVEC2;
			}
			void *x, *y;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat2x2));
					*((imat2x2*)*o) = to_imat2x2v(*((ivec2*)x), *((ivec2*)y));
					return GLM_TMAT2x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat2x3));
					*((imat2x3*)*o) = to_imat2x3v(*((ivec3*)x), *((ivec3*)y));
					return GLM_TMAT2x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat2x4));
					*((imat2x4*)*o) = to_imat2x4v(*((ivec4*)x), *((ivec4*)y));
					return GLM_TMAT2x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
				*o = malloc(sizeof(ivec3));
				*((ivec3*)*o) = to_ivec3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3));
				return GLM_TVEC3;
			}
			void *x, *y, *z;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat3x2));
					*((imat3x2*)*o) = to_imat3x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z));
					return GLM_TMAT3x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat3x3));
					*((imat3x3*)*o) = to_imat3x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z));
					return GLM_TMAT3x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat3x4));
					*((imat3x4*)*o) = to_imat3x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z));
					return GLM_TMAT3x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
				*o = malloc(sizeof(ivec4));
				*((ivec4*)*o) = to_ivec4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4));
				return GLM_TVEC4;
			}
			void *x, *y, *z, *w;
			char vecType = unpack_ivec(arg1, &x);
			if (vecType != GLM_NONE && unpack_ivec(arg2, &y) == vecType && unpack_ivec(arg3, &z) == vecType && unpack_ivec(arg4, &w)) {
				if (vecType == GLM_TVEC2) {
					*o = malloc(sizeof(imat4x2));
					*((imat4x2*)*o) = to_imat4x2v(*((ivec2*)x), *((ivec2*)y), *((ivec2*)z), *((ivec2*)w));
					return GLM_TMAT4x2;
				}
				if (vecType == GLM_TVEC3) {
					*o = malloc(sizeof(imat4x3));
					*((imat4x3*)*o) = to_imat4x3v(*((ivec3*)x), *((ivec3*)y), *((ivec3*)z), *((ivec3*)w));
					return GLM_TMAT4x3;
				}
				if (vecType == GLM_TVEC4) {
					*o = malloc(sizeof(imat4x4));
					*((imat4x4*)*o) = to_imat4x4v(*((ivec4*)x), *((ivec4*)y), *((ivec4*)z), *((ivec4*)w));
					return GLM_TMAT4x4;
				}
				return GLM_NONE;
			}
			return GLM_NONE;
		}
		if (len == 6) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
				*o = malloc(sizeof(imat2x3));
				*((imat2x3*)*o) = to_imat2x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6));
				return GLM_TMAT2x3;
			}
		}
		if (len == 8) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8)) {
				*o = malloc(sizeof(imat2x4));
				*((imat2x4*)*o) = to_imat2x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8));
				return GLM_TMAT2x4;
			}
			return GLM_NONE;
		}
		if (len == 9) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9)) {
				*o = malloc(sizeof(imat3x3));
				*((imat3x3*)*o) = to_imat3x3(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9));
				return GLM_TMAT3x3;
			}
			return GLM_NONE;
		}
		if (len == 12) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			arg10 = PyList_GET_ITEM(arg, 9);
			arg11 = PyList_GET_ITEM(arg, 10);
			arg12 = PyList_GET_ITEM(arg, 11);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12)) {
				*o = malloc(sizeof(imat3x4));
				*((imat3x4*)*o) = to_imat3x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12));
				return GLM_TMAT3x4;
			}
			return GLM_NONE;
		}
		if (len == 16) {
			PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6, *arg7, *arg8, *arg9, *arg10, *arg11, *arg12, *arg13, *arg14, *arg15, *arg16;
			arg1 = PyList_GET_ITEM(arg, 0);
			arg2 = PyList_GET_ITEM(arg, 1);
			arg3 = PyList_GET_ITEM(arg, 2);
			arg4 = PyList_GET_ITEM(arg, 3);
			arg5 = PyList_GET_ITEM(arg, 4);
			arg6 = PyList_GET_ITEM(arg, 5);
			arg7 = PyList_GET_ITEM(arg, 6);
			arg8 = PyList_GET_ITEM(arg, 7);
			arg9 = PyList_GET_ITEM(arg, 8);
			arg10 = PyList_GET_ITEM(arg, 9);
			arg11 = PyList_GET_ITEM(arg, 10);
			arg12 = PyList_GET_ITEM(arg, 11);
			arg13 = PyList_GET_ITEM(arg, 12);
			arg14 = PyList_GET_ITEM(arg, 13);
			arg15 = PyList_GET_ITEM(arg, 14);
			arg16 = PyList_GET_ITEM(arg, 15);
			if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12) && IS_NUMERIC(arg13) && IS_NUMERIC(arg14) && IS_NUMERIC(arg15) && IS_NUMERIC(arg16)) {
				*o = malloc(sizeof(imat4x4));
				*((imat4x4*)*o) = to_imat4x4(pyvalue_as_double(arg1), pyvalue_as_double(arg2), pyvalue_as_double(arg3), pyvalue_as_double(arg4), pyvalue_as_double(arg5), pyvalue_as_double(arg6), pyvalue_as_double(arg7), pyvalue_as_double(arg8), pyvalue_as_double(arg9), pyvalue_as_double(arg10), pyvalue_as_double(arg11), pyvalue_as_double(arg12), pyvalue_as_double(arg13), pyvalue_as_double(arg14), pyvalue_as_double(arg15), pyvalue_as_double(arg16));
				return GLM_TMAT4x4;
			}
			return GLM_NONE;
		}
		return GLM_NONE;
	}
	return GLM_NONE;
}

static PyObject * new_pyobject(PyTypeObject* type) {
	PyObject* argList = Py_BuildValue("()");

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

//static tmat2x2 * new_tmat2x2() {
//	tmat2x2 * out = malloc(sizeof(tmat2x2));
//	out->x = new_tvec2();
//	out->y = new_tvec2();
//	return out;
//}
//static tmat2x3 * new_tmat2x3() {
//	tmat2x3 * out = malloc(sizeof(tmat2x3));
//	out->x = new_tvec3();
//	out->y = new_tvec3();
//	return out;
//}
//static tmat2x4 * new_tmat2x4() {
//	tmat2x4 * out = malloc(sizeof(tmat2x4));
//	out->x = new_tvec4();
//	out->y = new_tvec4();
//	return out;
//}
//
//static tmat3x2 * new_tmat3x2() {
//	tmat3x2 * out = malloc(sizeof(tmat3x2));
//	out->x = new_tvec2();
//	out->y = new_tvec2();
//	out->z = new_tvec2();
//	return out;
//}
//static tmat3x3 * new_tmat3x3() {
//	tmat3x3 * out = malloc(sizeof(tmat3x3));
//	out->x = new_tvec3();
//	out->y = new_tvec3();
//	out->z = new_tvec3();
//	return out;
//}
//static tmat3x4 * new_tmat3x4() {
//	tmat3x4 * out = malloc(sizeof(tmat3x4));
//	out->x = new_tvec4();
//	out->y = new_tvec4();
//	out->z = new_tvec4();
//	return out;
//}
//
//static tmat4x2 * new_tmat4x2() {
//	tmat4x2 * out = malloc(sizeof(tmat4x2));
//	out->x = new_tvec2();
//	out->y = new_tvec2();
//	out->z = new_tvec2();
//	out->w = new_tvec2();
//	return out;
//}
//static tmat4x3 * new_tmat4x3() {
//	tmat4x3 * out = malloc(sizeof(tmat4x3));
//	out->x = new_tvec3();
//	out->y = new_tvec3();
//	out->z = new_tvec3();
//	out->w = new_tvec3();
//	return out;
//}
//static tmat4x4 * new_tmat4x4() {
//	tmat4x4 * out = malloc(sizeof(tmat4x4));
//	out->x = new_tvec4();
//	out->y = new_tvec4();
//	out->z = new_tvec4();
//	out->w = new_tvec4();
//	return out;
//}
//
//static tvec2 * to_tvec2(double x, double y) { // internal (doesn't build a PyObject)
//	tvec2 * out = new_tvec2();
//	out->x = x;
//	out->y = y;
//	return out;
//}
//static tvec3 * to_tvec3(double x, double y, double z) { // internal (doesn't build a PyObject)
//	tvec3 * out = new_tvec3();
//	out->x = x;
//	out->y = y;
//	out->z = z;
//	return out;
//}
//static tvec4 * to_tvec4(double x, double y, double z, double w) { // internal (doesn't build a PyObject)
//	tvec4 * out = new_tvec4();
//	out->x = x;
//	out->y = y;
//	out->z = z;
//	out->w = w;
//	return out;
//}
//
//static tmat2x2 * to_tmat2x2(double x0, double x1, double y0, double y1) { // internal (doesn't build a PyObject)
//	tmat2x2 * out = malloc(sizeof(tmat2x2));
//	out->x = to_tvec2(x0,x1);
//	out->y = to_tvec2(y0,y1);
//	return out;
//}
//static tmat2x3 * to_tmat2x3(double x0, double x1, double x2, double y0, double y1, double y2) { // internal (doesn't build a PyObject)
//	tmat2x3 * out = malloc(sizeof(tmat2x3));
//	out->x = to_tvec3(x0, x1, x2);
//	out->y = to_tvec3(y0, y1, y2);
//	return out;
//}
//static tmat2x4 * to_tmat2x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3) { // internal (doesn't build a PyObject)
//	tmat2x4 * out = malloc(sizeof(tmat2x4));
//	out->x = to_tvec4(x0, x1, x2, x3);
//	out->y = to_tvec4(y0, y1, x2, x3);
//	return out;
//}
//
//static tmat3x2 * to_tmat3x2(double x0, double x1, double y0, double y1, double z0, double z1) { // internal (doesn't build a PyObject)
//	tmat3x2 * out = malloc(sizeof(tmat3x2));
//	out->x = to_tvec2(x0, x1);
//	out->y = to_tvec2(y0, y1);
//	out->z = to_tvec2(z0, z1);
//	return out;
//}
//static tmat3x3 * to_tmat3x3(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2) { // internal (doesn't build a PyObject)
//	tmat3x3 * out = malloc(sizeof(tmat3x3));
//	out->x = to_tvec3(x0, x1, x2);
//	out->y = to_tvec3(y0, y1, y2);
//	out->z = to_tvec3(z0, z1, z2);
//	return out;
//}
//static tmat3x4 * to_tmat3x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3) { // internal (doesn't build a PyObject)
//	tmat3x4 * out = malloc(sizeof(tmat3x4));
//	out->x = to_tvec4(x0, x1, x2, x3);
//	out->y = to_tvec4(y0, y1, y2, y3);
//	out->z = to_tvec4(z0, z1, z2, z3);
//	return out;
//}
//
//static tmat4x2 * to_tmat4x2(double x0, double x1, double y0, double y1, double z0, double z1, double w0, double w1) { // internal (doesn't build a PyObject)
//	tmat4x2 * out = malloc(sizeof(tmat4x2));
//	out->x = to_tvec2(x0, x1);
//	out->y = to_tvec2(y0, y1);
//	out->z = to_tvec2(z0, z1);
//	out->w = to_tvec2(w0, w1);
//	return out;
//}
//static tmat4x3 * to_tmat4x3(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2, double w0, double w1, double w2) { // internal (doesn't build a PyObject)
//	tmat4x3 * out = malloc(sizeof(tmat4x3));
//	out->x = to_tvec3(x0, x1, x2);
//	out->y = to_tvec3(y0, y1, y2);
//	out->z = to_tvec3(z0, z1, z2);
//	out->w = to_tvec3(w0, w1, w2);
//	return out;
//}
//static tmat4x4 * to_tmat4x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3, double w0, double w1, double w2, double w3) { // internal (doesn't build a PyObject)
//	tmat4x4 * out = malloc(sizeof(tmat4x4));
//	out->x = to_tvec4(x0, x1, x2, x3);
//	out->y = to_tvec4(y0, y1, y2, y3);
//	out->z = to_tvec4(z0, z1, z2, z3);
//	out->w = to_tvec4(w0, w1, w2, w3);
//	return out;
//}

#define PYTYPE_AS_CSTRING(op) op->ob_type->tp_name

static char * concat_string_and_pyobject_type(char* str, PyObject* obj) {
	char * out = malloc(sizeof(char) * (strlen(str) + strlen(PYTYPE_AS_CSTRING(obj)) + 3));
	strcpy(out, str);
	strcat(out, "'");
	strcat(out, PYTYPE_AS_CSTRING(obj));
	strcat(out, "'");
	return out;
}

static char * concat_string_and_2_pyobject_types(char* str, PyObject* obj1, PyObject* obj2) {
	char * out = malloc(sizeof(char) * (strlen(str) + strlen(PYTYPE_AS_CSTRING(obj1)) + strlen(PYTYPE_AS_CSTRING(obj2)) + 10));
	strcpy(out, str);
	strcat(out, "'");
	strcat(out, PYTYPE_AS_CSTRING(obj1));
	strcat(out, "' and '");
	strcat(out, PYTYPE_AS_CSTRING(obj2));
	strcat(out, "'");
	return out;
}

#define UNPACK_2_VARARGS(args, name, arg1, arg2) if(!PyArg_UnpackTuple(args, name, 2, 2, &arg1, &arg2)) return NULL
#define UNPACK_3_VARARGS(args, name, arg1, arg2, arg3) if(!PyArg_UnpackTuple(args, name, 3, 3, &arg1, &arg2, &arg3)) return NULL

#define PY_TYPEERROR(str, obj) PyErr_SetString(PyExc_TypeError, concat_string_and_pyobject_type(str, obj));
#define PY_TYPEERROR_2O(str, obj1, obj2) PyErr_SetString(PyExc_TypeError, concat_string_and_2_pyobject_types(str, obj1, obj2));

// internal glm type from PyObject
static ivec2 * unpack_ivec2(PyObject * value) {
	if (PyObject_TypeCheck(value, &tvec2Type)) {
		ivec2 * out = (ivec2*)malloc(sizeof(ivec2));
		*out = to_ivec2(((tvec2 *)value)->x, ((tvec2 *)value)->y);
		return out;
	}
	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 2) {
		PyObject * x = PyTuple_GET_ITEM(value, 0);
		PyObject * y = PyTuple_GET_ITEM(value, 1);

		if (IS_NUMERIC(x) && IS_NUMERIC(y)) {
			ivec2 * out = (ivec2*)malloc(sizeof(ivec2));
			*out = to_ivec2(pyvalue_as_double(x), pyvalue_as_double(y));
			return out;
		}
		return NULL;
	}
	if (PyList_Check(value) && PyList_GET_SIZE(value) == 2) {
		PyObject * x = PyList_GET_ITEM(value, 0);
		PyObject * y = PyList_GET_ITEM(value, 1);

		if (IS_NUMERIC(x) && IS_NUMERIC(y)) {
			ivec2 * out = (ivec2*)malloc(sizeof(ivec2));
			*out = to_ivec2(pyvalue_as_double(x), pyvalue_as_double(y));
			return out;
		}
		return NULL;
	}
	return NULL;

}
static ivec3 * unpack_ivec3(PyObject * value) {
	if (PyObject_TypeCheck(value, &tvec3Type)) {
		ivec3 * out = (ivec3*)malloc(sizeof(ivec3));
		*out = to_ivec3(((tvec3 *)value)->x, ((tvec3 *)value)->y, ((tvec3 *)value)->z);
		return out;
	}
	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 3) {
		PyObject * x = PyTuple_GET_ITEM(value, 0);
		PyObject * y = PyTuple_GET_ITEM(value, 1);
		PyObject * z = PyTuple_GET_ITEM(value, 2);

		if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z)) {
			ivec3 * out = (ivec3*)malloc(sizeof(ivec3));
			*out = to_ivec3(pyvalue_as_double(x), pyvalue_as_double(y), pyvalue_as_double(z));
			return out;
		}
		return NULL;
	}
	if (PyList_Check(value) && PyList_GET_SIZE(value) == 3) {
		PyObject * x = PyList_GET_ITEM(value, 0);
		PyObject * y = PyList_GET_ITEM(value, 1);
		PyObject * z = PyList_GET_ITEM(value, 2);

		if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z)) {
			ivec3 * out = (ivec3*)malloc(sizeof(ivec3));
			*out = to_ivec3(pyvalue_as_double(x), pyvalue_as_double(y), pyvalue_as_double(z));
			return out;
		}
		return NULL;
	}
	return NULL;
}
static ivec4 * unpack_ivec4(PyObject * value) {
	if (PyObject_TypeCheck(value, &tvec4Type)) {
		ivec4 * out = (ivec4*)malloc(sizeof(ivec4));
		*out = to_ivec4(((tvec4 *)value)->x, ((tvec4 *)value)->y, ((tvec4 *)value)->z, ((tvec4 *)value)->w);
		return out;
	}
	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 4) {
		PyObject * x = PyTuple_GET_ITEM(value, 0);
		PyObject * y = PyTuple_GET_ITEM(value, 1);
		PyObject * z = PyTuple_GET_ITEM(value, 2);
		PyObject * w = PyTuple_GET_ITEM(value, 3);

		if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z) && IS_NUMERIC(w)) {
			ivec4 * out = (ivec4*)malloc(sizeof(ivec4));
			*out = to_ivec4(pyvalue_as_double(x), pyvalue_as_double(y), pyvalue_as_double(z), pyvalue_as_double(w));
			return out;
		}
		return NULL;
	}
	if (PyList_Check(value) && PyList_GET_SIZE(value) == 4) {
		PyObject * x = PyList_GET_ITEM(value, 0);
		PyObject * y = PyList_GET_ITEM(value, 1);
		PyObject * z = PyList_GET_ITEM(value, 2);
		PyObject * w = PyList_GET_ITEM(value, 3);

		if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z) && IS_NUMERIC(w)) {
			ivec4 * out = (ivec4*)malloc(sizeof(ivec4));
			*out = to_ivec4(pyvalue_as_double(x), pyvalue_as_double(y), pyvalue_as_double(z), pyvalue_as_double(w));
			return out;
		}
		return NULL;
	}
	return NULL;
}

static imat2x2 * unpack_imat2x2(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat2x2Type)) {
		imat2x2 * out = to_imat2x2p(((tmat2x2 *)value)->x->x, ((tmat2x2 *)value)->x->y, ((tmat2x2 *)value)->y->x, ((tmat2x2 *)value)->y->y);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			ivec2 *x = unpack_ivec2(arg1);
			ivec2 *y = unpack_ivec2(arg2);
			if (x != NULL && y != NULL) {
				imat2x2* out = to_imat2x2vp(x,y);
				return out;
			}
			return NULL;
		}
		if (len == 4) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * y0 = PyTuple_GET_ITEM(value, 2);
			PyObject * y1 = PyTuple_GET_ITEM(value, 3);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1)) {
				imat2x2 * out = to_imat2x2p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(y0), pyvalue_as_double(y1));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			ivec2 *x = unpack_ivec2(arg1);
			ivec2 *y = unpack_ivec2(arg2);
			if (x != NULL && y != NULL) {
				imat2x2* out = to_imat2x2vp(x, y);
				return out;
			}
			return NULL;
		}
		if (len == 4) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * y0 = PyList_GET_ITEM(value, 2);
			PyObject * y1 = PyList_GET_ITEM(value, 3);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1)) {
				imat2x2 * out = to_imat2x2p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(y0), pyvalue_as_double(y1));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}
static imat2x3 * unpack_imat2x3(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat2x3Type)) {
		imat2x3 * out = to_imat2x3p(((tmat2x3 *)value)->x->x, ((tmat2x3 *)value)->x->y, ((tmat2x3 *)value)->x->z, ((tmat2x3 *)value)->y->x, ((tmat2x3 *)value)->y->y, ((tmat2x3 *)value)->y->z);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			ivec3 *x = unpack_ivec3(arg1);
			ivec3 *y = unpack_ivec3(arg2);
			if (x != NULL && y != NULL) {
				imat2x3* out = to_imat2x3vp(x, y);
				return out;
			}
			return NULL;
		}
		if (len == 6) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * x2 = PyTuple_GET_ITEM(value, 2);
			PyObject * y0 = PyTuple_GET_ITEM(value, 3);
			PyObject * y1 = PyTuple_GET_ITEM(value, 4);
			PyObject * y2 = PyTuple_GET_ITEM(value, 5);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2)) {
				imat2x3 * out = to_imat2x3p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			ivec3 *x = unpack_ivec3(arg1);
			ivec3 *y = unpack_ivec3(arg2);
			if (x != NULL && y != NULL) {
				imat2x3* out = to_imat2x3vp(x, y);
				return out;
			}
			return NULL;
		}
		if (len == 6) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * x2 = PyList_GET_ITEM(value, 2);
			PyObject * y0 = PyList_GET_ITEM(value, 3);
			PyObject * y1 = PyList_GET_ITEM(value, 4);
			PyObject * y2 = PyList_GET_ITEM(value, 5);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2)) {
				imat2x3 * out = to_imat2x3p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}
static imat2x4 * unpack_imat2x4(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat2x4Type)) {
		imat2x4 * out = to_imat2x4p(((tmat2x4 *)value)->x->x, ((tmat2x4 *)value)->x->y, ((tmat2x4 *)value)->x->z, ((tmat2x4 *)value)->x->w, ((tmat2x4 *)value)->y->x, ((tmat2x4 *)value)->y->y, ((tmat2x4 *)value)->y->z, ((tmat2x4 *)value)->y->w);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			ivec4 *x = unpack_ivec4(arg1);
			ivec4 *y = unpack_ivec4(arg2);
			if (x != NULL && y != NULL) {
				imat2x4* out = to_imat2x4vp(x, y);
				return out;
			}
			return NULL;
		}
		if (len == 8) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * x2 = PyTuple_GET_ITEM(value, 2);
			PyObject * x3 = PyTuple_GET_ITEM(value, 3);
			PyObject * y0 = PyTuple_GET_ITEM(value, 4);
			PyObject * y1 = PyTuple_GET_ITEM(value, 5);
			PyObject * y2 = PyTuple_GET_ITEM(value, 6);
			PyObject * y3 = PyTuple_GET_ITEM(value, 7);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3)) {
				imat2x4 * out = to_imat2x4p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(x3), pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), pyvalue_as_double(y3));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 2) {
			PyObject *arg1, *arg2;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			ivec4 *x = unpack_ivec4(arg1);
			ivec4 *y = unpack_ivec4(arg2);
			if (x != NULL && y != NULL) {
				imat2x4* out = to_imat2x4vp(x, y);
				return out;
			}
			return NULL;
		}
		if (len == 8) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * x2 = PyList_GET_ITEM(value, 2);
			PyObject * x3 = PyList_GET_ITEM(value, 3);
			PyObject * y0 = PyList_GET_ITEM(value, 4);
			PyObject * y1 = PyList_GET_ITEM(value, 5);
			PyObject * y2 = PyList_GET_ITEM(value, 6);
			PyObject * y3 = PyList_GET_ITEM(value, 7);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3)) {
				imat2x4 * out = to_imat2x4p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(x3), pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), pyvalue_as_double(y3));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}


// CONTINUE HERE
static imat3x2 * unpack_imat3x2(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat3x2Type)) {
		imat3x2 * out = to_imat3x2p(((tmat3x2 *)value)->x->x, ((tmat3x2 *)value)->x->y, ((tmat3x2 *)value)->y->x, ((tmat3x2 *)value)->y->y, ((tmat3x2 *)value)->z->x, ((tmat3x2 *)value)->z->y);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			arg3 = PyTuple_GET_ITEM(value, 2);
			ivec2 *x = unpack_ivec2(arg1);
			ivec2 *y = unpack_ivec2(arg2);
			ivec2 *z = unpack_ivec2(arg3);
			if (x != NULL && y != NULL && z != NULL) {
				imat3x2* out = to_imat3x2vp(x, y, z);
				return out;
			}
			return NULL;
		}
		if (len == 6) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * y0 = PyTuple_GET_ITEM(value, 2);
			PyObject * y1 = PyTuple_GET_ITEM(value, 3);
			PyObject * z0 = PyTuple_GET_ITEM(value, 4);
			PyObject * z1 = PyTuple_GET_ITEM(value, 5);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(z0) && IS_NUMERIC(z1)) {
				imat3x2 * out = to_imat3x2p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(z0), pyvalue_as_double(z1));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			arg3 = PyList_GET_ITEM(value, 2);
			ivec2 *x = unpack_ivec2(arg1);
			ivec2 *y = unpack_ivec2(arg2);
			ivec2 *z = unpack_ivec2(arg3);
			if (x != NULL && y != NULL && z != NULL) {
				imat3x2* out = to_imat3x2vp(x, y, z);
				return out;
			}
			return NULL;
		}
		if (len == 6) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * y0 = PyList_GET_ITEM(value, 2);
			PyObject * y1 = PyList_GET_ITEM(value, 3);
			PyObject * z0 = PyList_GET_ITEM(value, 4);
			PyObject * z1 = PyList_GET_ITEM(value, 5);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(z0) && IS_NUMERIC(z1)) {
				imat3x2 * out = to_imat3x2p(pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(z0), pyvalue_as_double(z1));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}
static imat3x3 * unpack_imat3x3(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat3x3Type)) {
		imat3x3 * out = to_imat3x3p(((tmat3x3 *)value)->x->x, ((tmat3x3 *)value)->x->y, ((tmat3x3 *)value)->x->z, ((tmat3x3 *)value)->y->x, ((tmat3x3 *)value)->y->y, ((tmat3x3 *)value)->y->z, ((tmat3x3 *)value)->z->x, ((tmat3x3 *)value)->z->y, ((tmat3x3 *)value)->z->z);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			arg3 = PyTuple_GET_ITEM(value, 2);
			ivec3 *x = unpack_ivec3(arg1);
			ivec3 *y = unpack_ivec3(arg2);
			ivec3 *z = unpack_ivec3(arg3);
			if (x != NULL && y != NULL && z != NULL) {
				imat3x3* out = to_imat3x3vp(x, y, z);
				return out;
			}
			return NULL;
		}
		if (len == 9) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * x2 = PyTuple_GET_ITEM(value, 2);
			PyObject * y0 = PyTuple_GET_ITEM(value, 3);
			PyObject * y1 = PyTuple_GET_ITEM(value, 4);
			PyObject * y2 = PyTuple_GET_ITEM(value, 5);
			PyObject * z0 = PyTuple_GET_ITEM(value, 6);
			PyObject * z1 = PyTuple_GET_ITEM(value, 7);
			PyObject * z2 = PyTuple_GET_ITEM(value, 8);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2)) {
				imat3x3 * out = to_imat3x3p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), 
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), 
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			arg3 = PyList_GET_ITEM(value, 2);
			ivec3 *x = unpack_ivec3(arg1);
			ivec3 *y = unpack_ivec3(arg2);
			ivec3 *z = unpack_ivec3(arg3);
			if (x != NULL && y != NULL && z != NULL) {
				imat3x3* out = to_imat3x3vp(x, y, z);
				return out;
			}
			return NULL;
		}
		if (len == 9) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * x2 = PyList_GET_ITEM(value, 2);
			PyObject * y0 = PyList_GET_ITEM(value, 3);
			PyObject * y1 = PyList_GET_ITEM(value, 4);
			PyObject * y2 = PyList_GET_ITEM(value, 5);
			PyObject * z0 = PyList_GET_ITEM(value, 6);
			PyObject * z1 = PyList_GET_ITEM(value, 7);
			PyObject * z2 = PyList_GET_ITEM(value, 8);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2)) {
				imat3x3 * out = to_imat3x3p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}
static imat3x4 * unpack_imat3x4(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat3x4Type)) {
		imat3x4 * out = to_imat3x4p(
			((tmat3x4 *)value)->x->x, ((tmat3x4 *)value)->x->y, ((tmat3x4 *)value)->x->z, ((tmat3x4 *)value)->x->w,
			((tmat3x4 *)value)->y->x, ((tmat3x4 *)value)->y->y, ((tmat3x4 *)value)->y->z, ((tmat3x4 *)value)->y->w,
			((tmat3x4 *)value)->z->x, ((tmat3x4 *)value)->z->y, ((tmat3x4 *)value)->z->z, ((tmat3x4 *)value)->z->w);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			arg3 = PyTuple_GET_ITEM(value, 2);
			ivec4 *x = unpack_ivec4(arg1);
			ivec4 *y = unpack_ivec4(arg2);
			ivec4 *z = unpack_ivec4(arg3);
			if (x != NULL && y != NULL && z != NULL) {
				imat3x4* out = to_imat3x4vp(x, y, z);
				return out;
			}
			return NULL;
		}
		if (len == 12) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * x2 = PyTuple_GET_ITEM(value, 2);
			PyObject * x3 = PyTuple_GET_ITEM(value, 3);
			PyObject * y0 = PyTuple_GET_ITEM(value, 4);
			PyObject * y1 = PyTuple_GET_ITEM(value, 5);
			PyObject * y2 = PyTuple_GET_ITEM(value, 6);
			PyObject * y3 = PyTuple_GET_ITEM(value, 7);
			PyObject * z0 = PyTuple_GET_ITEM(value, 8);
			PyObject * z1 = PyTuple_GET_ITEM(value, 9);
			PyObject * z2 = PyTuple_GET_ITEM(value, 10);
			PyObject * z3 = PyTuple_GET_ITEM(value, 11);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3)) {
				imat3x4 * out = to_imat3x4p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(x3),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), pyvalue_as_double(y3),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2), pyvalue_as_double(z3));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 3) {
			PyObject *arg1, *arg2, *arg3;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			arg3 = PyList_GET_ITEM(value, 2);
			ivec4 *x = unpack_ivec4(arg1);
			ivec4 *y = unpack_ivec4(arg2);
			ivec4 *z = unpack_ivec4(arg3);
			if (x != NULL && y != NULL && z != NULL) {
				imat3x4* out = to_imat3x4vp(x, y, z);
				return out;
			}
			return NULL;
		}
		if (len == 12) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * x2 = PyList_GET_ITEM(value, 2);
			PyObject * x3 = PyList_GET_ITEM(value, 3);
			PyObject * y0 = PyList_GET_ITEM(value, 4);
			PyObject * y1 = PyList_GET_ITEM(value, 5);
			PyObject * y2 = PyList_GET_ITEM(value, 6);
			PyObject * y3 = PyList_GET_ITEM(value, 7);
			PyObject * z0 = PyList_GET_ITEM(value, 8);
			PyObject * z1 = PyList_GET_ITEM(value, 9);
			PyObject * z2 = PyList_GET_ITEM(value, 10);
			PyObject * z3 = PyList_GET_ITEM(value, 11);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3)) {
				imat3x4 * out = to_imat3x4p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(x3),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), pyvalue_as_double(y3),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2), pyvalue_as_double(z3));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}

static imat4x2 * unpack_imat4x2(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat4x2Type)) {
		imat4x2 * out = to_imat4x2p(
			((tmat4x2 *)value)->x->x, ((tmat4x2 *)value)->x->y, 
			((tmat4x2 *)value)->y->x, ((tmat4x2 *)value)->y->y, 
			((tmat4x2 *)value)->z->x, ((tmat4x2 *)value)->z->y,
			((tmat4x2 *)value)->w->x, ((tmat4x2 *)value)->w->y);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, * arg4;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			arg3 = PyTuple_GET_ITEM(value, 2);
			arg4 = PyTuple_GET_ITEM(value, 3);
			ivec2 *x = unpack_ivec2(arg1);
			ivec2 *y = unpack_ivec2(arg2);
			ivec2 *z = unpack_ivec2(arg3);
			ivec2 *w = unpack_ivec2(arg4);
			if (x != NULL && y != NULL && z != NULL && w != NULL) {
				imat4x2* out = to_imat4x2vp(x, y, z, w);
				return out;
			}
			return NULL;
		}
		if (len == 8) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * y0 = PyTuple_GET_ITEM(value, 2);
			PyObject * y1 = PyTuple_GET_ITEM(value, 3);
			PyObject * z0 = PyTuple_GET_ITEM(value, 4);
			PyObject * z1 = PyTuple_GET_ITEM(value, 5);
			PyObject * w0 = PyTuple_GET_ITEM(value, 6);
			PyObject * w1 = PyTuple_GET_ITEM(value, 7);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && 
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && 
				IS_NUMERIC(z0) && IS_NUMERIC(z1) &&
				IS_NUMERIC(w0) && IS_NUMERIC(w1)) {
				imat4x2 * out = to_imat4x2p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), 
					pyvalue_as_double(y0), pyvalue_as_double(y1), 
					pyvalue_as_double(z0), pyvalue_as_double(z1),
					pyvalue_as_double(w0), pyvalue_as_double(w1));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			arg3 = PyList_GET_ITEM(value, 2);
			arg4 = PyList_GET_ITEM(value, 3);
			ivec2 *x = unpack_ivec2(arg1);
			ivec2 *y = unpack_ivec2(arg2);
			ivec2 *z = unpack_ivec2(arg3);
			ivec2 *w = unpack_ivec2(arg4);
			if (x != NULL && y != NULL && z != NULL && w != NULL) {
				imat4x2* out = to_imat4x2vp(x, y, z, w);
				return out;
			}
			return NULL;
		}
		if (len == 8) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * y0 = PyList_GET_ITEM(value, 2);
			PyObject * y1 = PyList_GET_ITEM(value, 3);
			PyObject * z0 = PyList_GET_ITEM(value, 4);
			PyObject * z1 = PyList_GET_ITEM(value, 5);
			PyObject * w0 = PyList_GET_ITEM(value, 6);
			PyObject * w1 = PyList_GET_ITEM(value, 7);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) &&
				IS_NUMERIC(w0) && IS_NUMERIC(w1)) {
				imat4x2 * out = to_imat4x2p(
					pyvalue_as_double(x0), pyvalue_as_double(x1),
					pyvalue_as_double(y0), pyvalue_as_double(y1),
					pyvalue_as_double(z0), pyvalue_as_double(z1),
					pyvalue_as_double(w0), pyvalue_as_double(w1));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}
static imat4x3 * unpack_imat4x3(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat4x3Type)) {
		imat4x3 * out = to_imat4x3p(
			((tmat4x3 *)value)->x->x, ((tmat4x3 *)value)->x->y, ((tmat4x3 *)value)->x->z,
			((tmat4x3 *)value)->y->x, ((tmat4x3 *)value)->y->y, ((tmat4x3 *)value)->y->z,
			((tmat4x3 *)value)->z->x, ((tmat4x3 *)value)->z->y, ((tmat4x3 *)value)->z->z,
			((tmat4x3 *)value)->w->x, ((tmat4x3 *)value)->w->y, ((tmat4x3 *)value)->w->z);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			arg3 = PyTuple_GET_ITEM(value, 2);
			arg4 = PyTuple_GET_ITEM(value, 3);
			ivec3 *x = unpack_ivec3(arg1);
			ivec3 *y = unpack_ivec3(arg2);
			ivec3 *z = unpack_ivec3(arg3);
			ivec3 *w = unpack_ivec3(arg4);
			if (x != NULL && y != NULL && z != NULL && w != NULL) {
				imat4x3* out = to_imat4x3vp(x, y, z, w);
				return out;
			}
			return NULL;
		}
		if (len == 12) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * x2 = PyTuple_GET_ITEM(value, 2);
			PyObject * y0 = PyTuple_GET_ITEM(value, 3);
			PyObject * y1 = PyTuple_GET_ITEM(value, 4);
			PyObject * y2 = PyTuple_GET_ITEM(value, 5);
			PyObject * z0 = PyTuple_GET_ITEM(value, 6);
			PyObject * z1 = PyTuple_GET_ITEM(value, 7);
			PyObject * z2 = PyTuple_GET_ITEM(value, 8);
			PyObject * w0 = PyTuple_GET_ITEM(value, 9);
			PyObject * w1 = PyTuple_GET_ITEM(value, 10);
			PyObject * w2 = PyTuple_GET_ITEM(value, 11);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) &&
				IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2)) {
				imat4x3 * out = to_imat4x3p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2),
					pyvalue_as_double(w0), pyvalue_as_double(w1), pyvalue_as_double(w2));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			arg3 = PyList_GET_ITEM(value, 2);
			arg4 = PyList_GET_ITEM(value, 3);
			ivec3 *x = unpack_ivec3(arg1);
			ivec3 *y = unpack_ivec3(arg2);
			ivec3 *z = unpack_ivec3(arg3);
			ivec3 *w = unpack_ivec3(arg4);
			if (x != NULL && y != NULL && z != NULL && w != NULL) {
				imat4x3* out = to_imat4x3vp(x, y, z, w);
				return out;
			}
			return NULL;
		}
		if (len == 12) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * x2 = PyList_GET_ITEM(value, 2);
			PyObject * y0 = PyList_GET_ITEM(value, 3);
			PyObject * y1 = PyList_GET_ITEM(value, 4);
			PyObject * y2 = PyList_GET_ITEM(value, 5);
			PyObject * z0 = PyList_GET_ITEM(value, 6);
			PyObject * z1 = PyList_GET_ITEM(value, 7);
			PyObject * z2 = PyList_GET_ITEM(value, 8);
			PyObject * w0 = PyList_GET_ITEM(value, 9);
			PyObject * w1 = PyList_GET_ITEM(value, 10);
			PyObject * w2 = PyList_GET_ITEM(value, 11);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) &&
				IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2)) {
				imat4x3 * out = to_imat4x3p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2),
					pyvalue_as_double(w0), pyvalue_as_double(w1), pyvalue_as_double(w2));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}
static imat4x4 * unpack_imat4x4(PyObject * value) {
	if (PyObject_TypeCheck(value, &tmat4x4Type)) {
		imat4x4 * out = to_imat4x4p(
			((tmat4x4 *)value)->x->x, ((tmat4x4 *)value)->x->y, ((tmat4x4 *)value)->x->z, ((tmat4x4 *)value)->x->w,
			((tmat4x4 *)value)->y->x, ((tmat4x4 *)value)->y->y, ((tmat4x4 *)value)->y->z, ((tmat4x4 *)value)->y->w,
			((tmat4x4 *)value)->z->x, ((tmat4x4 *)value)->z->y, ((tmat4x4 *)value)->z->z, ((tmat4x4 *)value)->z->w,
			((tmat4x4 *)value)->w->x, ((tmat4x4 *)value)->w->y, ((tmat4x4 *)value)->w->z, ((tmat4x4 *)value)->w->w);
		return out;
	}
	if (PyTuple_Check(value)) {
		Py_ssize_t len = PyTuple_GET_SIZE(value);
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyTuple_GET_ITEM(value, 0);
			arg2 = PyTuple_GET_ITEM(value, 1);
			arg3 = PyTuple_GET_ITEM(value, 2);
			arg4 = PyTuple_GET_ITEM(value, 3);
			ivec4 *x = unpack_ivec4(arg1);
			ivec4 *y = unpack_ivec4(arg2);
			ivec4 *z = unpack_ivec4(arg3);
			ivec4 *w = unpack_ivec4(arg4);
			if (x != NULL && y != NULL && z != NULL && w != NULL) {
				imat4x4* out = to_imat4x4vp(x, y, z, w);
				return out;
			}
			return NULL;
		}
		if (len == 16) {
			PyObject * x0 = PyTuple_GET_ITEM(value, 0);
			PyObject * x1 = PyTuple_GET_ITEM(value, 1);
			PyObject * x2 = PyTuple_GET_ITEM(value, 2);
			PyObject * x3 = PyTuple_GET_ITEM(value, 3);
			PyObject * y0 = PyTuple_GET_ITEM(value, 4);
			PyObject * y1 = PyTuple_GET_ITEM(value, 5);
			PyObject * y2 = PyTuple_GET_ITEM(value, 6);
			PyObject * y3 = PyTuple_GET_ITEM(value, 7);
			PyObject * z0 = PyTuple_GET_ITEM(value, 8);
			PyObject * z1 = PyTuple_GET_ITEM(value, 9);
			PyObject * z2 = PyTuple_GET_ITEM(value, 10);
			PyObject * z3 = PyTuple_GET_ITEM(value, 11);
			PyObject * w0 = PyTuple_GET_ITEM(value, 12);
			PyObject * w1 = PyTuple_GET_ITEM(value, 13);
			PyObject * w2 = PyTuple_GET_ITEM(value, 14);
			PyObject * w3 = PyTuple_GET_ITEM(value, 15);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3) &&
				IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2) && IS_NUMERIC(w3)) {
				imat4x4 * out = to_imat4x4p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(x3),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), pyvalue_as_double(y3),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2), pyvalue_as_double(z3),
					pyvalue_as_double(w0), pyvalue_as_double(w1), pyvalue_as_double(w2), pyvalue_as_double(w3));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	if (PyList_Check(value)) {
		Py_ssize_t len = PyList_GET_SIZE(value);
		if (len == 4) {
			PyObject *arg1, *arg2, *arg3, *arg4;
			arg1 = PyList_GET_ITEM(value, 0);
			arg2 = PyList_GET_ITEM(value, 1);
			arg3 = PyList_GET_ITEM(value, 2);
			arg4 = PyList_GET_ITEM(value, 3);
			ivec4 *x = unpack_ivec4(arg1);
			ivec4 *y = unpack_ivec4(arg2);
			ivec4 *z = unpack_ivec4(arg3);
			ivec4 *w = unpack_ivec4(arg4);
			if (x != NULL && y != NULL && z != NULL && w != NULL) {
				imat4x4* out = to_imat4x4vp(x, y, z, w);
				return out;
			}
			return NULL;
		}
		if (len == 16) {
			PyObject * x0 = PyList_GET_ITEM(value, 0);
			PyObject * x1 = PyList_GET_ITEM(value, 1);
			PyObject * x2 = PyList_GET_ITEM(value, 2);
			PyObject * x3 = PyList_GET_ITEM(value, 3);
			PyObject * y0 = PyList_GET_ITEM(value, 4);
			PyObject * y1 = PyList_GET_ITEM(value, 5);
			PyObject * y2 = PyList_GET_ITEM(value, 6);
			PyObject * y3 = PyList_GET_ITEM(value, 7);
			PyObject * z0 = PyList_GET_ITEM(value, 8);
			PyObject * z1 = PyList_GET_ITEM(value, 9);
			PyObject * z2 = PyList_GET_ITEM(value, 10);
			PyObject * z3 = PyList_GET_ITEM(value, 11);
			PyObject * w0 = PyList_GET_ITEM(value, 12);
			PyObject * w1 = PyList_GET_ITEM(value, 13);
			PyObject * w2 = PyList_GET_ITEM(value, 14);
			PyObject * w3 = PyList_GET_ITEM(value, 15);

			if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) &&
				IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) &&
				IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3) &&
				IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2) && IS_NUMERIC(w3)) {
				imat4x4 * out = to_imat4x4p(
					pyvalue_as_double(x0), pyvalue_as_double(x1), pyvalue_as_double(x2), pyvalue_as_double(x3),
					pyvalue_as_double(y0), pyvalue_as_double(y1), pyvalue_as_double(y2), pyvalue_as_double(y3),
					pyvalue_as_double(z0), pyvalue_as_double(z1), pyvalue_as_double(z2), pyvalue_as_double(z3),
					pyvalue_as_double(w0), pyvalue_as_double(w1), pyvalue_as_double(w2), pyvalue_as_double(w3));
				return out;
			}
			return NULL;
		}
		return NULL;
	}
	return NULL;
}

//static tvec2 * unpack_to_tvec2(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tvec2Type)) {
//		tvec2 * out = new_tvec2();
//		out->x = ((tvec2 *)value)->x;
//		out->y = ((tvec2 *)value)->y;
//		return out;
//	}
//	if (PyTuple_Check(value)) {
//		if (PyTuple_GET_SIZE(value) == 2) {
//			PyObject * x = PyTuple_GET_ITEM(value, 0);
//			PyObject * y = PyTuple_GET_ITEM(value, 1);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y)) {
//				tvec2 * out = new_tvec2();
//				out->x = pyvalue_as_double(x);
//				out->y = pyvalue_as_double(y);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	if (PyList_Check(value)) {
//		if (PyList_GET_SIZE(value) == 2) {
//			PyObject * x = PyList_GET_ITEM(value, 0);
//			PyObject * y = PyList_GET_ITEM(value, 1);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y)) {
//				tvec2 * out = new_tvec2();
//				out->x = pyvalue_as_double(x);
//				out->y = pyvalue_as_double(y);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	return NULL;
//
//}
//static tvec3 * unpack_to_tvec3(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tvec3Type)) {
//		tvec3 * out = new_tvec3();
//		out->x = ((tvec3 *)value)->x;
//		out->y = ((tvec3 *)value)->y;
//		out->z = ((tvec3 *)value)->z;
//		return out;
//	}
//	if (PyTuple_Check(value)) {
//		if (PyTuple_GET_SIZE(value) == 3) {
//			PyObject * x = PyTuple_GET_ITEM(value, 0);
//			PyObject * y = PyTuple_GET_ITEM(value, 1);
//			PyObject * z = PyTuple_GET_ITEM(value, 2);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z)) {
//				tvec3 * out = new_tvec3();
//				out->x = pyvalue_as_double(x);
//				out->y = pyvalue_as_double(y);
//				out->z = pyvalue_as_double(z);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	if (PyList_Check(value)) {
//		if (PyList_GET_SIZE(value) == 3) {
//			PyObject * x = PyList_GET_ITEM(value, 0);
//			PyObject * y = PyList_GET_ITEM(value, 1);
//			PyObject * z = PyList_GET_ITEM(value, 2);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z)) {
//				tvec3 * out = new_tvec3();
//				out->x = pyvalue_as_double(x);
//				out->y = pyvalue_as_double(y);
//				out->z = pyvalue_as_double(z);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	return NULL;
//}
//static tvec4 * unpack_to_tvec4(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tvec4Type)) {
//		tvec4 * out = new_tvec4();
//		out->x = ((tvec4 *)value)->x;
//		out->y = ((tvec4 *)value)->y;
//		out->z = ((tvec4 *)value)->z;
//		out->w = ((tvec4 *)value)->w;
//		return out;
//	}
//	if (PyTuple_Check(value)) {
//		if (PyTuple_GET_SIZE(value) == 4) {
//			PyObject * x = PyTuple_GET_ITEM(value, 0);
//			PyObject * y = PyTuple_GET_ITEM(value, 1);
//			PyObject * z = PyTuple_GET_ITEM(value, 2);
//			PyObject * w = PyTuple_GET_ITEM(value, 3);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z) && IS_NUMERIC(w)) {
//				tvec4 * out = new_tvec4();
//				out->x = pyvalue_as_double(x);
//				out->y = pyvalue_as_double(y);
//				out->z = pyvalue_as_double(z);
//				out->w = pyvalue_as_double(w);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	if (PyList_Check(value)) {
//		if (PyList_GET_SIZE(value) == 4) {
//			PyObject * x = PyList_GET_ITEM(value, 0);
//			PyObject * y = PyList_GET_ITEM(value, 1);
//			PyObject * z = PyList_GET_ITEM(value, 2);
//			PyObject * w = PyList_GET_ITEM(value, 3);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z) && IS_NUMERIC(w)) {
//				tvec4 * out = new_tvec4();
//				out->x = pyvalue_as_double(x);
//				out->y = pyvalue_as_double(y);
//				out->z = pyvalue_as_double(z);
//				out->w = pyvalue_as_double(w);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	/*if (PyObject_TypeCheck(value, &tmat2x2Type)) {
//		tvec4 * out = new_tvec4();
//		out->x = ((tmat2x2 *)value)->x->x;
//		out->y = ((tmat2x2 *)value)->x->y;
//		out->z = ((tmat2x2 *)value)->y->x;
//		out->w = ((tmat2x2 *)value)->y->y;
//		return out;
//	}*/
//	return NULL;
//}
//
//static tmat2x2 * unpack_to_tmat2x2(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat2x2Type)) {
//		tmat2x2 * out = new_tmat2x2();
//		out->x->x = ((tmat2x2 *)value)->x->x;
//		out->x->y = ((tmat2x2 *)value)->x->y;
//		out->y->x = ((tmat2x2 *)value)->y->x;
//		out->y->y = ((tmat2x2 *)value)->y->y;
//		return out;
//	}
//	if (PyTuple_Check(value)) {
//		if (PyTuple_GET_SIZE(value) == 4) {
//			PyObject * x = PyTuple_GET_ITEM(value, 0);
//			PyObject * y = PyTuple_GET_ITEM(value, 1);
//			PyObject * z = PyTuple_GET_ITEM(value, 2);
//			PyObject * w = PyTuple_GET_ITEM(value, 3);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z) && IS_NUMERIC(w)) {
//				tmat2x2 * out = new_tmat2x2();
//				out->x->x = pyvalue_as_double(x);
//				out->x->y = pyvalue_as_double(y);
//				out->y->x = pyvalue_as_double(z);
//				out->y->y = pyvalue_as_double(w);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	if (PyList_Check(value)) {
//		if (PyList_GET_SIZE(value) == 4) {
//			PyObject * x = PyList_GET_ITEM(value, 0);
//			PyObject * y = PyList_GET_ITEM(value, 1);
//			PyObject * z = PyList_GET_ITEM(value, 2);
//			PyObject * w = PyList_GET_ITEM(value, 3);
//
//			if (IS_NUMERIC(x) && IS_NUMERIC(y) && IS_NUMERIC(z) && IS_NUMERIC(w)) {
//				tmat2x2 * out = new_tmat2x2();
//				out->x->x = pyvalue_as_double(x);
//				out->x->y = pyvalue_as_double(y);
//				out->y->x = pyvalue_as_double(z);
//				out->y->y = pyvalue_as_double(w);
//				return out;
//			}
//			return NULL;
//		}
//	}
//	return NULL;
//}
//static tmat2x3 * unpack_to_tmat2x3(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat2x3Type)) {
//		tmat2x3 * out = new_tmat2x3();
//		out->x->x = ((tmat2x3 *)value)->x->x;
//		out->x->y = ((tmat2x3 *)value)->x->y;
//		out->x->z = ((tmat2x3 *)value)->x->z;
//		out->y->x = ((tmat2x3 *)value)->y->x;
//		out->y->y = ((tmat2x3 *)value)->y->y;
//		out->y->z = ((tmat2x3 *)value)->y->z;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 6) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * x2 = PyTuple_GET_ITEM(value, 2);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 3);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 4);
//		PyObject * y2 = PyTuple_GET_ITEM(value, 5);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2)) {
//			tmat2x3 * out = new_tmat2x3();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 6) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * x2 = PyList_GET_ITEM(value, 2);
//		PyObject * y0 = PyList_GET_ITEM(value, 3);
//		PyObject * y1 = PyList_GET_ITEM(value, 4);
//		PyObject * y2 = PyList_GET_ITEM(value, 5);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2)) {
//			tmat2x3 * out = new_tmat2x3();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//static tmat2x4 * unpack_to_tmat2x4(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat2x4Type)) {
//		tmat2x4 * out = new_tmat2x4();
//		out->x->x = ((tmat2x4 *)value)->x->x;
//		out->x->y = ((tmat2x4 *)value)->x->y;
//		out->x->z = ((tmat2x4 *)value)->x->z;
//		out->x->w = ((tmat2x4 *)value)->x->w;
//		out->y->x = ((tmat2x4 *)value)->y->x;
//		out->y->y = ((tmat2x4 *)value)->y->y;
//		out->y->z = ((tmat2x4 *)value)->y->z;
//		out->y->w = ((tmat2x4 *)value)->y->w;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 8) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * x2 = PyTuple_GET_ITEM(value, 2);
//		PyObject * x3 = PyTuple_GET_ITEM(value, 3);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 4);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 5);
//		PyObject * y2 = PyTuple_GET_ITEM(value, 6);
//		PyObject * y3 = PyTuple_GET_ITEM(value, 7);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3)) {
//			tmat2x4 * out = new_tmat2x4();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->x->w = pyvalue_as_double(x3);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->y->w = pyvalue_as_double(y3);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 8) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * x2 = PyList_GET_ITEM(value, 2);
//		PyObject * x3 = PyList_GET_ITEM(value, 3);
//		PyObject * y0 = PyList_GET_ITEM(value, 4);
//		PyObject * y1 = PyList_GET_ITEM(value, 5);
//		PyObject * y2 = PyList_GET_ITEM(value, 6);
//		PyObject * y3 = PyList_GET_ITEM(value, 7);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3)) {
//			tmat2x4 * out = new_tmat2x4();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->x->w = pyvalue_as_double(x3);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->y->w = pyvalue_as_double(y3);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//
//static tmat3x2 * unpack_to_tmat3x2(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat3x2Type)) {
//		tmat3x2 * out = new_tmat3x2();
//		out->x->x = ((tmat3x2 *)value)->x->x;
//		out->x->y = ((tmat3x2 *)value)->x->y;
//		out->y->x = ((tmat3x2 *)value)->y->x;
//		out->y->y = ((tmat3x2 *)value)->y->y;
//		out->z->x = ((tmat3x2 *)value)->z->x;
//		out->z->y = ((tmat3x2 *)value)->z->y;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 6) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 2);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 3);
//		PyObject * z0 = PyTuple_GET_ITEM(value, 4);
//		PyObject * z1 = PyTuple_GET_ITEM(value, 5);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(z0) && IS_NUMERIC(z1)) {
//			tmat3x2 * out = new_tmat3x2();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 6) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * y0 = PyList_GET_ITEM(value, 2);
//		PyObject * y1 = PyList_GET_ITEM(value, 3);
//		PyObject * z0 = PyList_GET_ITEM(value, 4);
//		PyObject * z1 = PyList_GET_ITEM(value, 5);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(z0) && IS_NUMERIC(z1)) {
//			tmat3x2 * out = new_tmat3x2();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//static tmat3x3 * unpack_to_tmat3x3(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat3x3Type)) {
//		tmat3x3 * out = new_tmat3x3();
//		out->x->x = ((tmat3x3 *)value)->x->x;
//		out->x->y = ((tmat3x3 *)value)->x->y;
//		out->x->z = ((tmat3x3 *)value)->x->z;
//		out->y->x = ((tmat3x3 *)value)->y->x;
//		out->y->y = ((tmat3x3 *)value)->y->y;
//		out->y->z = ((tmat3x3 *)value)->y->z;
//		out->z->x = ((tmat3x3 *)value)->z->x;
//		out->z->y = ((tmat3x3 *)value)->z->y;
//		out->z->z = ((tmat3x3 *)value)->z->z;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 9) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * x2 = PyTuple_GET_ITEM(value, 2);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 3);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 4);
//		PyObject * y2 = PyTuple_GET_ITEM(value, 5);
//		PyObject * z0 = PyTuple_GET_ITEM(value, 6);
//		PyObject * z1 = PyTuple_GET_ITEM(value, 7);
//		PyObject * z2 = PyTuple_GET_ITEM(value, 8);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2)) {
//			tmat3x3 * out = new_tmat3x3();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 9) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * x2 = PyList_GET_ITEM(value, 2);
//		PyObject * y0 = PyList_GET_ITEM(value, 3);
//		PyObject * y1 = PyList_GET_ITEM(value, 4);
//		PyObject * y2 = PyList_GET_ITEM(value, 5);
//		PyObject * z0 = PyList_GET_ITEM(value, 6);
//		PyObject * z1 = PyList_GET_ITEM(value, 7);
//		PyObject * z2 = PyList_GET_ITEM(value, 8);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2)) {
//			tmat3x3 * out = new_tmat3x3();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//static tmat3x4 * unpack_to_tmat3x4(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat3x4Type)) {
//		tmat3x4 * out = new_tmat3x4();
//		out->x->x = ((tmat3x4 *)value)->x->x;
//		out->x->y = ((tmat3x4 *)value)->x->y;
//		out->x->z = ((tmat3x4 *)value)->x->z;
//		out->x->w = ((tmat3x4 *)value)->x->w;
//		out->y->x = ((tmat3x4 *)value)->y->x;
//		out->y->y = ((tmat3x4 *)value)->y->y;
//		out->y->z = ((tmat3x4 *)value)->y->z;
//		out->y->w = ((tmat3x4 *)value)->y->w;
//		out->z->x = ((tmat3x4 *)value)->z->x;
//		out->z->y = ((tmat3x4 *)value)->z->y;
//		out->z->z = ((tmat3x4 *)value)->z->z;
//		out->z->w = ((tmat3x4 *)value)->z->w;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 12) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * x2 = PyTuple_GET_ITEM(value, 2);
//		PyObject * x3 = PyTuple_GET_ITEM(value, 3);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 4);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 5);
//		PyObject * y2 = PyTuple_GET_ITEM(value, 6);
//		PyObject * y3 = PyTuple_GET_ITEM(value, 7);
//		PyObject * z0 = PyTuple_GET_ITEM(value, 8);
//		PyObject * z1 = PyTuple_GET_ITEM(value, 9);
//		PyObject * z2 = PyTuple_GET_ITEM(value, 10);
//		PyObject * z3 = PyTuple_GET_ITEM(value, 11);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3)) {
//			tmat3x4 * out = new_tmat3x4();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->x->w = pyvalue_as_double(x3);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->y->w = pyvalue_as_double(y3);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			out->z->w = pyvalue_as_double(z3);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 9) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * x2 = PyList_GET_ITEM(value, 2);
//		PyObject * x3 = PyList_GET_ITEM(value, 3);
//		PyObject * y0 = PyList_GET_ITEM(value, 4);
//		PyObject * y1 = PyList_GET_ITEM(value, 5);
//		PyObject * y2 = PyList_GET_ITEM(value, 6);
//		PyObject * y3 = PyList_GET_ITEM(value, 7);
//		PyObject * z0 = PyList_GET_ITEM(value, 8);
//		PyObject * z1 = PyList_GET_ITEM(value, 9);
//		PyObject * z2 = PyList_GET_ITEM(value, 10);
//		PyObject * z3 = PyList_GET_ITEM(value, 11);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3)) {
//			tmat3x4 * out = new_tmat3x4();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->x->w = pyvalue_as_double(x3);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->y->w = pyvalue_as_double(y3);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			out->z->w = pyvalue_as_double(z3);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//
//static tmat4x2 * unpack_to_tmat4x2(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat4x2Type)) {
//		tmat4x2 * out = new_tmat4x2();
//		out->x->x = ((tmat4x2 *)value)->x->x;
//		out->x->y = ((tmat4x2 *)value)->x->y;
//		out->y->x = ((tmat4x2 *)value)->y->x;
//		out->y->y = ((tmat4x2 *)value)->y->y;
//		out->z->x = ((tmat4x2 *)value)->z->x;
//		out->z->y = ((tmat4x2 *)value)->z->y;
//		out->w->x = ((tmat4x2 *)value)->w->x;
//		out->w->y = ((tmat4x2 *)value)->w->y;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 8) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 2);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 3);
//		PyObject * z0 = PyTuple_GET_ITEM(value, 4);
//		PyObject * z1 = PyTuple_GET_ITEM(value, 5);
//		PyObject * w0 = PyTuple_GET_ITEM(value, 6);
//		PyObject * w1 = PyTuple_GET_ITEM(value, 7);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(w0) && IS_NUMERIC(w1)) {
//			tmat4x2 * out = new_tmat4x2();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->w->x = pyvalue_as_double(w0);
//			out->w->y = pyvalue_as_double(w1);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 8) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * y0 = PyList_GET_ITEM(value, 2);
//		PyObject * y1 = PyList_GET_ITEM(value, 3);
//		PyObject * z0 = PyList_GET_ITEM(value, 4);
//		PyObject * z1 = PyList_GET_ITEM(value, 5);
//		PyObject * w0 = PyList_GET_ITEM(value, 6);
//		PyObject * w1 = PyList_GET_ITEM(value, 7);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(w0) && IS_NUMERIC(w1)) {
//			tmat4x2 * out = new_tmat4x2();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->w->x = pyvalue_as_double(w0);
//			out->w->y = pyvalue_as_double(w1);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//static tmat4x3 * unpack_to_tmat4x3(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat4x3Type)) {
//		tmat4x3 * out = new_tmat4x3();
//		out->x->x = ((tmat4x3 *)value)->x->x;
//		out->x->y = ((tmat4x3 *)value)->x->y;
//		out->x->z = ((tmat4x3 *)value)->x->z;
//		out->y->x = ((tmat4x3 *)value)->y->x;
//		out->y->y = ((tmat4x3 *)value)->y->y;
//		out->y->z = ((tmat4x3 *)value)->y->z;
//		out->z->x = ((tmat4x3 *)value)->z->x;
//		out->z->y = ((tmat4x3 *)value)->z->y;
//		out->z->z = ((tmat4x3 *)value)->z->z;
//		out->w->x = ((tmat4x3 *)value)->w->x;
//		out->w->y = ((tmat4x3 *)value)->w->y;
//		out->w->z = ((tmat4x3 *)value)->w->z;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 12) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * x2 = PyTuple_GET_ITEM(value, 2);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 3);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 4);
//		PyObject * y2 = PyTuple_GET_ITEM(value, 5);
//		PyObject * z0 = PyTuple_GET_ITEM(value, 6);
//		PyObject * z1 = PyTuple_GET_ITEM(value, 7);
//		PyObject * z2 = PyTuple_GET_ITEM(value, 8);
//		PyObject * w0 = PyTuple_GET_ITEM(value, 9);
//		PyObject * w1 = PyTuple_GET_ITEM(value, 10);
//		PyObject * w2 = PyTuple_GET_ITEM(value, 11);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2)) {
//			tmat4x3 * out = new_tmat4x3();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			out->w->x = pyvalue_as_double(w0);
//			out->w->y = pyvalue_as_double(w1);
//			out->w->z = pyvalue_as_double(w2);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 12) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * x2 = PyList_GET_ITEM(value, 2);
//		PyObject * y0 = PyList_GET_ITEM(value, 3);
//		PyObject * y1 = PyList_GET_ITEM(value, 4);
//		PyObject * y2 = PyList_GET_ITEM(value, 5);
//		PyObject * z0 = PyList_GET_ITEM(value, 6);
//		PyObject * z1 = PyList_GET_ITEM(value, 7);
//		PyObject * z2 = PyList_GET_ITEM(value, 8);
//		PyObject * w0 = PyList_GET_ITEM(value, 9);
//		PyObject * w1 = PyList_GET_ITEM(value, 10);
//		PyObject * w2 = PyList_GET_ITEM(value, 11);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2)) {
//			tmat4x3 * out = new_tmat4x3();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			out->w->x = pyvalue_as_double(w0);
//			out->w->y = pyvalue_as_double(w1);
//			out->w->z = pyvalue_as_double(w2);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}
//static tmat4x4 * unpack_to_tmat4x4(PyObject * value) {
//	if (PyObject_TypeCheck(value, &tmat4x4Type)) {
//		tmat4x4 * out = new_tmat4x4();
//		out->x->x = ((tmat4x4 *)value)->x->x;
//		out->x->y = ((tmat4x4 *)value)->x->y;
//		out->x->z = ((tmat4x4 *)value)->x->z;
//		out->x->w = ((tmat4x4 *)value)->x->w;
//		out->y->x = ((tmat4x4 *)value)->y->x;
//		out->y->y = ((tmat4x4 *)value)->y->y;
//		out->y->z = ((tmat4x4 *)value)->y->z;
//		out->y->w = ((tmat4x4 *)value)->y->w;
//		out->z->x = ((tmat4x4 *)value)->z->x;
//		out->z->y = ((tmat4x4 *)value)->z->y;
//		out->z->z = ((tmat4x4 *)value)->z->z;
//		out->z->w = ((tmat4x4 *)value)->z->w;
//		out->w->x = ((tmat4x4 *)value)->w->x;
//		out->w->y = ((tmat4x4 *)value)->w->y;
//		out->w->z = ((tmat4x4 *)value)->w->z;
//		out->w->w = ((tmat4x4 *)value)->w->w;
//		return out;
//	}
//	if (PyTuple_Check(value) && PyTuple_GET_SIZE(value) == 16) {
//		PyObject * x0 = PyTuple_GET_ITEM(value, 0);
//		PyObject * x1 = PyTuple_GET_ITEM(value, 1);
//		PyObject * x2 = PyTuple_GET_ITEM(value, 2);
//		PyObject * x3 = PyTuple_GET_ITEM(value, 3);
//		PyObject * y0 = PyTuple_GET_ITEM(value, 4);
//		PyObject * y1 = PyTuple_GET_ITEM(value, 5);
//		PyObject * y2 = PyTuple_GET_ITEM(value, 6);
//		PyObject * y3 = PyTuple_GET_ITEM(value, 7);
//		PyObject * z0 = PyTuple_GET_ITEM(value, 8);
//		PyObject * z1 = PyTuple_GET_ITEM(value, 9);
//		PyObject * z2 = PyTuple_GET_ITEM(value, 10);
//		PyObject * z3 = PyTuple_GET_ITEM(value, 11);
//		PyObject * w0 = PyTuple_GET_ITEM(value, 12);
//		PyObject * w1 = PyTuple_GET_ITEM(value, 13);
//		PyObject * w2 = PyTuple_GET_ITEM(value, 14);
//		PyObject * w3 = PyTuple_GET_ITEM(value, 15);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3) && IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2) && IS_NUMERIC(w3)) {
//			tmat4x4 * out = new_tmat4x4();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->x->w = pyvalue_as_double(x3);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->y->w = pyvalue_as_double(y3);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			out->z->w = pyvalue_as_double(z3);
//			out->w->x = pyvalue_as_double(w0);
//			out->w->y = pyvalue_as_double(w1);
//			out->w->z = pyvalue_as_double(w2);
//			out->w->w = pyvalue_as_double(w3);
//			return out;
//		}
//		return NULL;
//	}
//	if (PyList_Check(value) && PyList_GET_SIZE(value) == 16) {
//		PyObject * x0 = PyList_GET_ITEM(value, 0);
//		PyObject * x1 = PyList_GET_ITEM(value, 1);
//		PyObject * x2 = PyList_GET_ITEM(value, 2);
//		PyObject * x3 = PyList_GET_ITEM(value, 3);
//		PyObject * y0 = PyList_GET_ITEM(value, 4);
//		PyObject * y1 = PyList_GET_ITEM(value, 5);
//		PyObject * y2 = PyList_GET_ITEM(value, 6);
//		PyObject * y3 = PyList_GET_ITEM(value, 7);
//		PyObject * z0 = PyList_GET_ITEM(value, 8);
//		PyObject * z1 = PyList_GET_ITEM(value, 9);
//		PyObject * z2 = PyList_GET_ITEM(value, 10);
//		PyObject * z3 = PyList_GET_ITEM(value, 11);
//		PyObject * w0 = PyList_GET_ITEM(value, 12);
//		PyObject * w1 = PyList_GET_ITEM(value, 13);
//		PyObject * w2 = PyList_GET_ITEM(value, 14);
//		PyObject * w3 = PyList_GET_ITEM(value, 15);
//
//		if (IS_NUMERIC(x0) && IS_NUMERIC(x1) && IS_NUMERIC(x2) && IS_NUMERIC(x3) && IS_NUMERIC(y0) && IS_NUMERIC(y1) && IS_NUMERIC(y2) && IS_NUMERIC(y3) && IS_NUMERIC(z0) && IS_NUMERIC(z1) && IS_NUMERIC(z2) && IS_NUMERIC(z3) && IS_NUMERIC(w0) && IS_NUMERIC(w1) && IS_NUMERIC(w2) && IS_NUMERIC(w3)) {
//			tmat4x4 * out = new_tmat4x4();
//			out->x->x = pyvalue_as_double(x0);
//			out->x->y = pyvalue_as_double(x1);
//			out->x->z = pyvalue_as_double(x2);
//			out->x->w = pyvalue_as_double(x3);
//			out->y->x = pyvalue_as_double(y0);
//			out->y->y = pyvalue_as_double(y1);
//			out->y->z = pyvalue_as_double(y2);
//			out->y->w = pyvalue_as_double(y3);
//			out->z->x = pyvalue_as_double(z0);
//			out->z->y = pyvalue_as_double(z1);
//			out->z->z = pyvalue_as_double(z2);
//			out->z->w = pyvalue_as_double(z3);
//			out->w->x = pyvalue_as_double(w0);
//			out->w->y = pyvalue_as_double(w1);
//			out->w->z = pyvalue_as_double(w2);
//			out->w->w = pyvalue_as_double(w3);
//			return out;
//		}
//		return NULL;
//	}
//	return NULL;
//}

// glm types from double values
static PyObject * pack_tvec2(double x, double y) {
	PyObject* argList = Py_BuildValue("dd", x, y);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tvec2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tvec3(double x, double y, double z) {
	PyObject* argList = Py_BuildValue("ddd", x, y, z);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tvec3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tvec4(double x, double y, double z, double w) {
	PyObject* argList = Py_BuildValue("dddd", x, y, z, w);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tvec4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject * pack_tmat2x2(double x0, double x1, double y0, double y1) {
	PyObject* argList = Py_BuildValue("OO", pack_tvec2(x0,x1), pack_tvec2(y0,y1));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tmat2x3(double x0, double x1, double x2, double y0, double y1, double y2) {
	PyObject* argList = Py_BuildValue("OO", pack_tvec3(x0, x1, x2), pack_tvec3(y0, y1, y2));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tmat2x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3) {
	PyObject* argList = Py_BuildValue("OO", pack_tvec4(x0, x1, x2, x3), pack_tvec4(y0, y1, y2, y3));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject * pack_tmat3x2(double x0, double x1, double y0, double y1, double z0, double z1) {
	PyObject* argList = Py_BuildValue("OOO", pack_tvec2(x0, x1), pack_tvec2(y0, y1), pack_tvec2(z0, z1));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tmat3x3(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2) {
	PyObject* argList = Py_BuildValue("OOO", pack_tvec3(x0, x1, x2), pack_tvec3(y0, y1, y2), pack_tvec3(z0, z1, z2));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tmat3x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3) {
	PyObject* argList = Py_BuildValue("OOO", pack_tvec4(x0, x1, x2, x3), pack_tvec4(y0, y1, y2, y3), pack_tvec4(z0, z1, z2, z3));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject * pack_tmat4x2(double x0, double x1, double y0, double y1, double z0, double z1, double w0, double w1) {
	PyObject* argList = Py_BuildValue("OOOO", pack_tvec2(x0, x1), pack_tvec2(y0, y1), pack_tvec2(z0, z1), pack_tvec2(w0, w1));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat4x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tmat4x3(double x0, double x1, double x2, double y0, double y1, double y2, double z0, double z1, double z2, double w0, double w1, double w2) {
	PyObject* argList = Py_BuildValue("OOOO", pack_tvec3(x0, x1, x2), pack_tvec3(y0, y1, y2), pack_tvec3(z0, z1, z2), pack_tvec3(w0, w1, w2));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat4x3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}
static PyObject * pack_tmat4x4(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3, double z0, double z1, double z2, double z3, double w0, double w1, double w2, double w3) {
	PyObject* argList = Py_BuildValue("OOOO", pack_tvec4(x0, x1, x2, x3), pack_tvec4(y0, y1, y2, y3), pack_tvec4(z0, z1, z2, z3), pack_tvec4(w0, w1, w2, w3));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat4x4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

//#define build_tmat2x2(o) pack_tmat2x2(((tmat2x2*)o)->x->x, ((tmat2x2*)o)->x->y, ((tmat2x2*)o)->y->x, ((tmat2x2*)o)->y->y)
//#define build_tmat2x3(o) pack_tmat2x3(((tmat2x3*)o)->x->x, ((tmat2x3*)o)->x->y, ((tmat2x3*)o)->x->z, ((tmat2x3*)o)->y->x, ((tmat2x3*)o)->y->y, ((tmat2x3*)o)->y->z)
//#define build_tmat2x4(o) pack_tmat2x4(((tmat2x4*)o)->x->x, ((tmat2x4*)o)->x->y, ((tmat2x4*)o)->x->z, ((tmat2x4*)o)->x->w, ((tmat2x4*)o)->y->x, ((tmat2x4*)o)->y->y, ((tmat2x4*)o)->y->z, ((tmat2x4*)o)->y->w)
//
//#define build_tmat3x2(o) pack_tmat3x2(((tmat3x2*)o)->x->x, ((tmat3x2*)o)->x->y, ((tmat3x2*)o)->y->x, ((tmat3x2*)o)->y->y, ((tmat3x2*)o)->z->x, ((tmat3x2*)o)->z->y)
//#define build_tmat3x3(o) pack_tmat3x3(((tmat3x3*)o)->x->x, ((tmat3x3*)o)->x->y, ((tmat3x3*)o)->x->z, ((tmat3x3*)o)->y->x, ((tmat3x3*)o)->y->y, ((tmat3x3*)o)->y->z, ((tmat3x3*)o)->z->x, ((tmat3x3*)o)->z->y, ((tmat3x3*)o)->z->z)
//#define build_tmat3x4(o) pack_tmat3x4(((tmat3x4*)o)->x->x, ((tmat3x4*)o)->x->y, ((tmat3x4*)o)->x->z, ((tmat3x4*)o)->x->w, ((tmat3x4*)o)->y->x, ((tmat3x4*)o)->y->y, ((tmat3x4*)o)->y->z, ((tmat3x4*)o)->y->w, ((tmat3x4*)o)->z->x, ((tmat3x4*)o)->z->y, ((tmat3x4*)o)->z->z, ((tmat3x4*)o)->z->w)
//
//#define build_tmat4x2(o) pack_tmat4x2(((tmat4x2*)o)->x->x, ((tmat4x2*)o)->x->y, ((tmat4x2*)o)->y->x, ((tmat4x2*)o)->y->y, ((tmat4x2*)o)->z->x, ((tmat4x2*)o)->z->y, ((tmat4x2*)o)->w->x, ((tmat4x2*)o)->w->y)
//#define build_tmat4x3(o) pack_tmat4x3(((tmat4x3*)o)->x->x, ((tmat4x3*)o)->x->y, ((tmat4x3*)o)->x->z, ((tmat4x3*)o)->y->x, ((tmat4x3*)o)->y->y, ((tmat4x3*)o)->y->z, ((tmat4x3*)o)->z->x, ((tmat4x3*)o)->z->y, ((tmat4x3*)o)->z->z, ((tmat4x3*)o)->w->x, ((tmat4x3*)o)->w->y, ((tmat4x3*)o)->w->z)
//#define build_tmat4x4(o) pack_tmat4x4(((tmat4x4*)o)->x->x, ((tmat4x4*)o)->x->y, ((tmat4x4*)o)->x->z, ((tmat4x4*)o)->x->w, ((tmat4x4*)o)->y->x, ((tmat4x4*)o)->y->y, ((tmat4x4*)o)->y->z, ((tmat4x4*)o)->y->w, ((tmat4x4*)o)->z->x, ((tmat4x4*)o)->z->y, ((tmat4x4*)o)->z->z, ((tmat4x4*)o)->z->w, ((tmat4x4*)o)->w->x, ((tmat4x4*)o)->w->y, ((tmat4x4*)o)->w->z, ((tmat4x4*)o)->w->w)

#define build_ivec2(o) pack_tvec2(o.x, o.y)
#define build_ivec3(o) pack_tvec3(o.x, o.y, o.z)
#define build_ivec4(o) pack_tvec4(o.x, o.y, o.z, o.w)

#define build_imat2x2(o) pack_tmat2x2(o.x.x, o.x.y, o.y.x, o.y.y)
#define build_imat2x3(o) pack_tmat2x3(o.x.x, o.x.y, o.x.z, o.y.x, o.y.y, o.y.z)
#define build_imat2x4(o) pack_tmat2x4(o.x.x, o.x.y, o.x.z, o.x.w, o.y.x, o.y.y, o.y.z, o.y.w)

#define build_imat3x2(o) pack_tmat3x2(o.x.x, o.x.y, o.y.x, o.y.y, o.z.x, o.z.y)
#define build_imat3x3(o) pack_tmat3x3(o.x.x, o.x.y, o.x.z, o.y.x, o.y.y, o.y.z, o.z.x, o.z.y, o.z.z)
#define build_imat3x4(o) pack_tmat3x4(o.x.x, o.x.y, o.x.z, o.x.w, o.y.x, o.y.y, o.y.z, o.y.w, o.z.x, o.z.y, o.z.z, o.z.w)

#define build_imat4x2(o) pack_tmat4x2(o.x.x, o.x.y, o.y.x, o.y.y, o.z.x, o.z.y, o.w.x, o.w.y)
#define build_imat4x3(o) pack_tmat4x3(o.x.x, o.x.y, o.x.z, o.y.x, o.y.y, o.y.z, o.z.x, o.z.y, o.z.z, o.w.x, o.w.y, o.w.z)
#define build_imat4x4(o) pack_tmat4x4(o.x.x, o.x.y, o.x.z, o.x.w, o.y.x, o.y.y, o.y.z, o.y.w, o.z.x, o.z.y, o.z.z, o.z.w, o.w.x, o.w.y, o.w.z, o.w.w)

#define build_ivec2p(o) pack_tvec2(((ivec2*)o)->x, ((ivec2*)o)->y)
#define build_ivec3p(o) pack_tvec3(((ivec3*)o)->x, ((ivec3*)o)->y, ((ivec3*)o)->z)
#define build_ivec4p(o) pack_tvec4(((ivec4*)o)->x, ((ivec4*)o)->y, ((ivec4*)o)->z, ((ivec4*)o)->w)

#define build_imat2x2p(o) pack_tmat2x2(((imat2x2*)o)->x.x, ((imat2x2*)o)->x.y, ((imat2x2*)o)->y.x, ((imat2x2*)o)->y.y)
#define build_imat2x3p(o) pack_tmat2x3(((imat2x3*)o)->x.x, ((imat2x3*)o)->x.y, ((imat2x3*)o)->x.z, ((imat2x3*)o)->y.x, ((imat2x3*)o)->y.y, ((imat2x3*)o)->y.z)
#define build_imat2x4p(o) pack_tmat2x4(((imat2x4*)o)->x.x, ((imat2x4*)o)->x.y, ((imat2x4*)o)->x.z, ((imat2x4*)o)->x.w, ((imat2x4*)o)->y.x, ((imat2x4*)o)->y.y, ((imat2x4*)o)->y.z, ((imat2x4*)o)->y.w)

#define build_imat3x2p(o) pack_tmat3x2(((imat3x2*)o)->x.x, ((imat3x2*)o)->x.y, ((imat3x2*)o)->y.x, ((imat3x2*)o)->y.y, ((imat3x2*)o)->z.x, ((imat3x2*)o)->z.y)
#define build_imat3x3p(o) pack_tmat3x3(((imat3x3*)o)->x.x, ((imat3x3*)o)->x.y, ((imat3x3*)o)->x.z, ((imat3x3*)o)->y.x, ((imat3x3*)o)->y.y, ((imat3x3*)o)->y.z, ((imat3x3*)o)->z.x, ((imat3x3*)o)->z.y, ((imat3x3*)o)->z.z)
#define build_imat3x4p(o) pack_tmat3x4(((imat3x4*)o)->x.x, ((imat3x4*)o)->x.y, ((imat3x4*)o)->x.z, ((imat3x4*)o)->x.w, ((imat3x4*)o)->y.x, ((imat3x4*)o)->y.y, ((imat3x4*)o)->y.z, ((imat3x4*)o)->y.w, ((imat3x4*)o)->z.x, ((imat3x4*)o)->z.y, ((imat3x4*)o)->z.z, ((imat3x4*)o)->z.w)

#define build_imat4x2p(o) pack_tmat4x2(((imat4x2*)o)->x.x, ((imat4x2*)o)->x.y, ((imat4x2*)o)->y.x, ((imat4x2*)o)->y.y, ((imat4x2*)o)->z.x, ((imat4x2*)o)->z.y, ((imat4x2*)o)->w.x, ((imat4x2*)o)->w.y)
#define build_imat4x3p(o) pack_tmat4x3(((imat4x3*)o)->x.x, ((imat4x3*)o)->x.y, ((imat4x3*)o)->x.z, ((imat4x3*)o)->y.x, ((imat4x3*)o)->y.y, ((imat4x3*)o)->y.z, ((imat4x3*)o)->z.x, ((imat4x3*)o)->z.y, ((imat4x3*)o)->z.z, ((imat4x3*)o)->w.x, ((imat4x3*)o)->w.y, ((imat4x3*)o)->w.z)
#define build_imat4x4p(o) pack_tmat4x4(((imat4x4*)o)->x.x, ((imat4x4*)o)->x.y, ((imat4x4*)o)->x.z, ((imat4x4*)o)->x.w, ((imat4x4*)o)->y.x, ((imat4x4*)o)->y.y, ((imat4x4*)o)->y.z, ((imat4x4*)o)->y.w, ((imat4x4*)o)->z.x, ((imat4x4*)o)->z.y, ((imat4x4*)o)->z.z, ((imat4x4*)o)->z.w, ((imat4x4*)o)->w.x, ((imat4x4*)o)->w.y, ((imat4x4*)o)->w.z, ((imat4x4*)o)->w.w)

//static PyObject * reinterpret_matrix(PyObject * arg) {
//	void* out = unpack_to_tmat2x2(arg);
//	if (out != NULL) return build_tmat2x2(out);
//	out = unpack_to_tmat2x3(arg);
//	if (out != NULL) return build_tmat2x3(out);
//	out = unpack_to_tmat2x4(arg);
//	if (out != NULL) return build_tmat2x4(out);
//	out = unpack_to_tmat3x2(arg);
//	if (out != NULL) return build_tmat3x2(out);
//	out = unpack_to_tmat3x3(arg);
//	if (out != NULL) return build_tmat3x3(out);
//	out = unpack_to_tmat3x4(arg);
//	if (out != NULL) return build_tmat3x4(out);
//	out = unpack_to_tmat4x2(arg);
//	if (out != NULL) return build_tmat4x2(out);
//	out = unpack_to_tmat4x3(arg);
//	if (out != NULL) return build_tmat4x3(out);
//	out = unpack_to_tmat4x4(arg);
//	if (out != NULL) return build_tmat4x4(out);
//	return NULL;
//}

//static int unpack_vec(PyObject* arg, void ** o) {
//	*o = unpack_to_tvec2(arg);
//	if (*o != NULL) return GLM_TVEC2;
//	*o = unpack_to_tvec3(arg);
//	if (*o != NULL) return GLM_TVEC3;
//	*o = unpack_to_tvec4(arg);
//	if (*o != NULL) return GLM_TVEC4;
//	return GLM_NONE;
//}
//
//static int unpack_mat(PyObject* arg, void ** o) {
//	*o = unpack_to_tmat2x2(arg);
//	if (*o != NULL) return GLM_TMAT2x2;
//	*o = unpack_to_tmat2x3(arg);
//	if (*o != NULL) return GLM_TMAT2x3;
//	*o = unpack_to_tmat2x4(arg);
//	if (*o != NULL) return GLM_TMAT2x4;
//	*o = unpack_to_tmat3x2(arg);
//	if (*o != NULL) return GLM_TMAT3x2;
//	*o = unpack_to_tmat3x3(arg);
//	if (*o != NULL) return GLM_TMAT3x3;
//	*o = unpack_to_tmat3x4(arg);
//	if (*o != NULL) return GLM_TMAT3x4;
//	*o = unpack_to_tmat4x2(arg);
//	if (*o != NULL) return GLM_TMAT4x2;
//	*o = unpack_to_tmat4x3(arg);
//	if (*o != NULL) return GLM_TMAT4x3;
//	*o = unpack_to_tmat4x4(arg);
//	if (*o != NULL) return GLM_TMAT4x4;
//	return GLM_NONE;
//}
//
//static int unpack_sqmat(PyObject* arg, void ** o) {
//	*o = unpack_to_tmat2x2(arg);
//	if (*o != NULL) return GLM_TMAT2x2;
//	*o = unpack_to_tmat3x3(arg);
//	if (*o != NULL) return GLM_TMAT3x3;
//	*o = unpack_to_tmat4x4(arg);
//	if (*o != NULL) return GLM_TMAT4x4;
//	return GLM_NONE;
//}
//
//static int unpack_pyglm_type(PyObject* arg, void ** o) {
//	int out = unpack_vec(arg, o);
//	if (out == GLM_NONE) {
//		return unpack_mat(arg, o);
//	}
//	return out;
//}
//
//static tvec2* VM2(tvec2* v0, tvec2* v1) {
//	return to_tvec2(((tvec2*)v0)->x * ((tvec2*)v1)->x, ((tvec2*)v0)->y * ((tvec2*)v1)->y);
//}
//static tvec3* VM3(tvec3* v0, tvec3* v1) {
//	return  to_tvec3(((tvec3*)v0)->x * ((tvec3*)v1)->x, ((tvec3*)v0)->y * ((tvec3*)v1)->y, ((tvec3*)v0)->z * ((tvec3*)v1)->z);
//}
//static tvec4* VM4(tvec4* v0, tvec4* v1) {
//	return to_tvec4(((tvec4*)v0)->x * ((tvec4*)v1)->x, ((tvec4*)v0)->y * ((tvec4*)v1)->y, ((tvec4*)v0)->z * ((tvec4*)v1)->z, ((tvec4*)v0)->w * ((tvec4*)v1)->w);
//}
//
//static tvec2* VA2(tvec2* v0, tvec2* v1) {
//	return to_tvec2(((tvec2*)v0)->x + ((tvec2*)v1)->x, ((tvec2*)v0)->y + ((tvec2*)v1)->y);
//}
//static tvec3* VA3(tvec3* v0, tvec3* v1) {
//	return  to_tvec3(((tvec3*)v0)->x + ((tvec3*)v1)->x, ((tvec3*)v0)->y + ((tvec3*)v1)->y, ((tvec3*)v0)->z + ((tvec3*)v1)->z);
//}
//static tvec4* VA4(tvec4* v0, tvec4* v1) {
//	return to_tvec4(((tvec4*)v0)->x + ((tvec4*)v1)->x, ((tvec4*)v0)->y + ((tvec4*)v1)->y, ((tvec4*)v0)->z + ((tvec4*)v1)->z, ((tvec4*)v0)->w + ((tvec4*)v1)->w);
//}
//
//static tvec2* VS2(tvec2* v0, tvec2* v1) {
//	return to_tvec2(((tvec2*)v0)->x - ((tvec2*)v1)->x, ((tvec2*)v0)->y - ((tvec2*)v1)->y);
//}
//static tvec3* VS3(tvec3* v0, tvec3* v1) {
//	return  to_tvec3(((tvec3*)v0)->x - ((tvec3*)v1)->x, ((tvec3*)v0)->y - ((tvec3*)v1)->y, ((tvec3*)v0)->z - ((tvec3*)v1)->z);
//}
//static tvec4* VS4(tvec4* v0, tvec4* v1) {
//	return to_tvec4(((tvec4*)v0)->x - ((tvec4*)v1)->x, ((tvec4*)v0)->y - ((tvec4*)v1)->y, ((tvec4*)v0)->z - ((tvec4*)v1)->z, ((tvec4*)v0)->w - ((tvec4*)v1)->w);
//}
//
//static tvec2* VD2(tvec2* v0, tvec2* v1) {
//	return to_tvec2(((tvec2*)v0)->x / ((tvec2*)v1)->x, ((tvec2*)v0)->y / ((tvec2*)v1)->y);
//}
//static tvec3* VD3(tvec3* v0, tvec3* v1) {
//	return  to_tvec3(((tvec3*)v0)->x / ((tvec3*)v1)->x, ((tvec3*)v0)->y / ((tvec3*)v1)->y, ((tvec3*)v0)->z / ((tvec3*)v1)->z);
//}
//static tvec4* VD4(tvec4* v0, tvec4* v1) {
//	return to_tvec4(((tvec4*)v0)->x / ((tvec4*)v1)->x, ((tvec4*)v0)->y / ((tvec4*)v1)->y, ((tvec4*)v0)->z / ((tvec4*)v1)->z, ((tvec4*)v0)->w / ((tvec4*)v1)->w);
//}
