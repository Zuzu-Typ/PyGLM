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

// vec
typedef struct {
	PyObject_HEAD
	double x;
	double y;
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
} tmat4x4;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	tmat4x4 *sequence;
} tmat4x4Iter;