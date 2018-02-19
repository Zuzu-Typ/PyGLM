#define GLM_NONE (char)0

#define GLM_TVEC2 (char)1
#define GLM_TVEC3 (char)2
#define GLM_TVEC4 (char)3

#define GLM_TMAT2x2 (char)4
#define GLM_TMAT2x3 (char)5
#define GLM_TMAT2x4 (char)6
#define GLM_TMAT3x2 (char)7
#define GLM_TMAT3x3 (char)8
#define GLM_TMAT3x4 (char)9
#define GLM_TMAT4x2 (char)10
#define GLM_TMAT4x3 (char)11
#define GLM_TMAT4x4 (char)12

#define GLM_TQUAT (char)13

#define GLM_HAS_TVEC2 1
#define GLM_HAS_TVEC3 2
#define GLM_HAS_TVEC4 4

#define GLM_HAS_TMAT2x2 8
#define GLM_HAS_TMAT2x3 16
#define GLM_HAS_TMAT2x4 32

#define GLM_HAS_TMAT3x2 64
#define GLM_HAS_TMAT3x3 128
#define GLM_HAS_TMAT3x4 256

#define GLM_HAS_TMAT4x2 512
#define GLM_HAS_TMAT4x3 1024
#define GLM_HAS_TMAT4x4 2048

#define GLM_HAS_TQUAT 4096

#define GLM_HAS_ALL 8191

static PyTypeObject tvec2Type;
static PyTypeObject tvec2IterType;

static PyTypeObject tvec3Type;
static PyTypeObject tvec3IterType;

static PyTypeObject tvec4Type;
static PyTypeObject tvec4IterType;

static PyTypeObject tmat2x2Type;
static PyTypeObject tmat2x2IterType;

static PyTypeObject tmat2x3Type;
static PyTypeObject tmat2x3IterType;

static PyTypeObject tmat2x4Type;
static PyTypeObject tmat2x4IterType;

static PyTypeObject tmat3x2Type;
static PyTypeObject tmat3x2IterType;

static PyTypeObject tmat3x3Type;
static PyTypeObject tmat3x3IterType;

static PyTypeObject tmat3x4Type;
static PyTypeObject tmat3x4IterType;

static PyTypeObject tmat4x2Type;
static PyTypeObject tmat4x2IterType;

static PyTypeObject tmat4x3Type;
static PyTypeObject tmat4x3IterType;

static PyTypeObject tmat4x4Type;
static PyTypeObject tmat4x4IterType;

static PyTypeObject tquatType;
static PyTypeObject tquatIterType;

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

typedef struct {
	double x, y, z, w;
} iquat;



//float datatypes
typedef struct {
	float x, y;
} fvec2;
typedef struct {
	float x, y, z;
} fvec3;
typedef struct {
	float x, y, z, w;
} fvec4;

typedef struct {
	fvec2 x, y;
} fmat2x2;
typedef struct {
	fvec3 x, y;
} fmat2x3;
typedef struct {
	fvec4 x, y;
} fmat2x4;

typedef struct {
	fvec2 x, y, z;
} fmat3x2;
typedef struct {
	fvec3 x, y, z;
} fmat3x3;
typedef struct {
	fvec4 x, y, z;
} fmat3x4;

typedef struct {
	fvec2 x, y, z, w;
} fmat4x2;
typedef struct {
	fvec3 x, y, z, w;
} fmat4x3;
typedef struct {
	fvec4 x, y, z, w;
} fmat4x4;

typedef struct {
	float x, y, z, w;
} fquat;

// vec
typedef struct {
	PyObject_HEAD
	double x;
	double y;
	fvec2 value_ptr;
} tvec2;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	tvec2 *sequence;
} tvec2Iter;

typedef struct {
	PyObject_HEAD
	double x;
	double y;
	double z;
	fvec3 value_ptr;
} tvec3;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	tvec3 *sequence;
} tvec3Iter;

typedef struct {
	PyObject_HEAD
	double x;
	double y;
	double z;
	double w;
	fvec4 value_ptr;
} tvec4;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	tvec4 *sequence;
} tvec4Iter;

// mat2xX
typedef struct {
	PyObject_HEAD
		tvec2 * x;
	tvec2 * y;
	PyObject * col_type;
	PyObject * row_type;
	fmat2x2 value_ptr;
} tmat2x2;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat2x2 *sequence;
} tmat2x2Iter;

typedef struct {
	PyObject_HEAD
		tvec3 * x;
	tvec3 * y;
	PyObject * col_type;
	PyObject * row_type;
	fmat2x3 value_ptr;
} tmat2x3;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat2x3 *sequence;
} tmat2x3Iter;

typedef struct {
	PyObject_HEAD
		tvec4 * x;
	tvec4 * y;
	PyObject * col_type;
	PyObject * row_type;
	fmat2x4 value_ptr;
} tmat2x4;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat2x4 *sequence;
} tmat2x4Iter;

// mat3xX
typedef struct {
	PyObject_HEAD
		tvec2 * x;
	tvec2 * y;
	tvec2 * z;
	PyObject * col_type;
	PyObject * row_type;
	fmat3x2 value_ptr;
} tmat3x2;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat3x2 *sequence;
} tmat3x2Iter;

typedef struct {
	PyObject_HEAD
		tvec3 * x;
	tvec3 * y;
	tvec3 * z;
	PyObject * col_type;
	PyObject * row_type;
	fmat3x3 value_ptr;
} tmat3x3;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat3x3 *sequence;
} tmat3x3Iter;

typedef struct {
	PyObject_HEAD
		tvec4 * x;
	tvec4 * y;
	tvec4 * z;
	PyObject * col_type;
	PyObject * row_type;
	fmat3x4 value_ptr;
} tmat3x4;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat3x4 *sequence;
} tmat3x4Iter;

// mat4xX
typedef struct {
	PyObject_HEAD
		tvec2 * x;
	tvec2 * y;
	tvec2 * z;
	tvec2 * w;
	PyObject * col_type;
	PyObject * row_type;
	fmat4x2 value_ptr;
} tmat4x2;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat4x2 *sequence;
} tmat4x2Iter;

typedef struct {
	PyObject_HEAD
		tvec3 * x;
	tvec3 * y;
	tvec3 * z;
	tvec3 * w;
	PyObject * col_type;
	PyObject * row_type;
	fmat4x3 value_ptr;
} tmat4x3;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat4x3 *sequence;
} tmat4x3Iter;

typedef struct {
	PyObject_HEAD
		tvec4 * x;
	tvec4 * y;
	tvec4 * z;
	tvec4 * w;
	PyObject * col_type;
	PyObject * row_type;
	fmat4x4 value_ptr;
} tmat4x4;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat4x4 *sequence;
} tmat4x4Iter;

typedef struct {
	PyObject_HEAD
		double x;
	double y;
	double z;
	double w;
	fquat value_ptr;
} tquat;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tquat *sequence;
} tquatIter;