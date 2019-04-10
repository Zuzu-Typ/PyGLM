#include <Python.h>
#include "structmember.h"

#include <cstdlib>
#include <cmath>

#include <stdbool.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/color_space.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/reciprocal.hpp>
#include <glm/gtc/type_ptr.hpp>

//TYPES

// type identifiers
#pragma region type identifiers
#define PyGLM_TYPE_NONE (char)0

#define PyGLM_TYPE_VEC2 (char)1
#define PyGLM_TYPE_VEC3 (char)2
#define PyGLM_TYPE_VEC4 (char)3

#define PyGLM_TYPE_MAT2x2 (char)4
#define PyGLM_TYPE_MAT2x3 (char)5
#define PyGLM_TYPE_MAT2x4 (char)6
#define PyGLM_TYPE_MAT3x2 (char)7
#define PyGLM_TYPE_MAT3x3 (char)8
#define PyGLM_TYPE_MAT3x4 (char)9
#define PyGLM_TYPE_MAT4x2 (char)10
#define PyGLM_TYPE_MAT4x3 (char)11
#define PyGLM_TYPE_MAT4x4 (char)12

#define PyGLM_TYPE_QUAT (char)13
#pragma endregion



// type definitions
#pragma region type definitions
typedef struct {
	PyObject_HEAD
	glm::vec2 super_type;
} vec2;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	vec2 *sequence;
} vec2Iter;

typedef struct {
	PyObject_HEAD
	glm::vec3 super_type;
} vec3;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	vec3 *sequence;
} vec3Iter;

typedef struct {
	PyObject_HEAD
	glm::vec4 super_type;
} vec4;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	vec4 *sequence;
} vec4Iter;

typedef struct {
	PyObject_HEAD
		glm::vec2* super_type;
	PyObject* master;
} mvec2;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	mvec2 *sequence;
} mvec2Iter;

typedef struct {
	PyObject_HEAD
		glm::vec3* super_type;
	PyObject* master;
} mvec3;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	mvec3 *sequence;
} mvec3Iter;

typedef struct {
	PyObject_HEAD
		glm::vec4* super_type;
	PyObject* master;
} mvec4;

typedef struct {
	PyObject_HEAD
		Py_ssize_t seq_index;
	mvec4 *sequence;
} mvec4Iter;

typedef struct {
	PyObject_HEAD
	glm::mat2x2 super_type;
} mat2x2;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat2x2 *sequence;
} mat2x2Iter;

typedef struct {
	PyObject_HEAD
	glm::mat2x3 super_type;
} mat2x3;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat2x3 *sequence;
} mat2x3Iter;

typedef struct {
	PyObject_HEAD
	glm::mat2x4 super_type;
} mat2x4;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat2x4 *sequence;
} mat2x4Iter;

typedef struct {
	PyObject_HEAD
	glm::mat3x2 super_type;
} mat3x2;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat3x2 *sequence;
} mat3x2Iter;

typedef struct {
	PyObject_HEAD
	glm::mat3x3 super_type;
} mat3x3;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat3x3 *sequence;
} mat3x3Iter;

typedef struct {
	PyObject_HEAD
	glm::mat3x4 super_type;
} mat3x4;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat3x4 *sequence;
} mat3x4Iter;

typedef struct {
	PyObject_HEAD
	glm::mat4x2 super_type;
} mat4x2;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat4x2 *sequence;
} mat4x2Iter;

typedef struct {
	PyObject_HEAD
	glm::mat4x3 super_type;
} mat4x3;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat4x3 *sequence;
} mat4x3Iter;

typedef struct {
	PyObject_HEAD
	glm::mat4x4 super_type;
} mat4x4;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	mat4x4 *sequence;
} mat4x4Iter;

typedef struct {
	PyObject_HEAD
	glm::quat super_type;
} quat;

typedef struct {
	PyObject_HEAD
	Py_ssize_t seq_index;
	quat *sequence;
} quatIter;
#pragma endregion

// forward declarations
#pragma region forward declarations
#pragma region vec2
static int vec2_getbuffer(vec2* self, Py_buffer* view, int flags);
void vec2_releasebuffer(vec2* self, Py_buffer* view);

static Py_ssize_t vec2_len(vec2 * self);
static PyObject* vec2_sq_item(vec2 * self, Py_ssize_t index);
static int vec2_sq_ass_item(vec2 * self, Py_ssize_t index, PyObject * value);
static int vec2_contains(vec2 * self, PyObject * value);

static PyObject * vec2_add(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_sub(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_mul(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_mod(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_divmod(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);
static PyObject * vec2_neg(vec2 *obj);
static PyObject * vec2_pos(vec2 *obj);
static PyObject * vec2_abs(vec2 *obj);
static PyObject * vec2_iadd(vec2* self, PyObject *obj);
static PyObject * vec2_isub(vec2* self, PyObject *obj);
static PyObject * vec2_imul(vec2* self, PyObject *obj);
static PyObject * vec2_imod(vec2* self, PyObject *obj);
static PyObject * vec2_ipow(vec2* self, PyObject * obj2, PyObject * obj3);
static PyObject * vec2_floordiv(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_div(PyObject *obj1, PyObject *obj2);
static PyObject * vec2_ifloordiv(vec2* self, PyObject *obj);
static PyObject * vec2_idiv(vec2* self, PyObject *obj);

static void vec2_dealloc(vec2* self);
static PyObject* vec2_str(vec2* self);
static PyObject* vec2_getattr(PyObject* obj, PyObject* name);
static PyObject* vec2_richcompare(vec2* self, PyObject* other, int comp_type);
static PyObject* vec2_geniter(vec2* self);
static int vec2_init(vec2 *self, PyObject *args, PyObject *kwds);
static PyObject* vec2_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void vec2Iter_dealloc(vec2Iter *rgstate);
static PyObject* vec2Iter_next(vec2Iter *rgstate);
static PyObject* vec2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyMemberDef vec2_members[] = {
	{ "x", T_FLOAT, offsetof(vec2, super_type.x), 0,
	"vec x" },
{ "y", T_FLOAT, offsetof(vec2, super_type.y), 0,
"vec y" },
{ NULL }  /* Sentinel */
};

static PyBufferProcs vec2BufferMethods = {
	(getbufferproc)vec2_getbuffer,
	(releasebufferproc)vec2_releasebuffer,
};

static PySequenceMethods vec2SeqMethods = {
	(lenfunc)vec2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec2_sq_item, // sq_item
	0,
	(ssizeobjargproc)vec2_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)vec2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods vec2NumMethods = {
	(binaryfunc)vec2_add, //nb_add
	(binaryfunc)vec2_sub, //nb_subtract
	(binaryfunc)vec2_mul, //nb_multiply
	(binaryfunc)vec2_mod, //nb_remainder
	(binaryfunc)vec2_divmod, //nb_divmod
	(ternaryfunc)vec2_pow, //nb_power
	(unaryfunc)vec2_neg, //nb_negative
	(unaryfunc)vec2_pos, //nb_positive
	(unaryfunc)vec2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)vec2_iadd, //nb_inplace_add
	(binaryfunc)vec2_isub, //nb_inplace_subtract
	(binaryfunc)vec2_imul, //nb_inplace_multiply
	(binaryfunc)vec2_imod, //nb_inplace_remainder
	(ternaryfunc)vec2_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)vec2_floordiv, //nb_floor_divide
	(binaryfunc)vec2_div,
	(binaryfunc)vec2_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)vec2_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject vec2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::vec2",             /* tp_name */
	sizeof(vec2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec2_str,                         /* tp_repr */
	&vec2NumMethods,             /* tp_as_number */
	&vec2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec2_str,                         /* tp_str */
	(getattrofunc)vec2_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&vec2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"vec2( <vec2 compatible type(s)> )\n2 components vector of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	vec2_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec2_new,                 /* tp_new */
};

static PyTypeObject vec2IterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"vec2Iter",             /* tp_name */
	sizeof(vec2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"vec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec2Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region vec3
static int vec3_getbuffer(vec3* self, Py_buffer* view, int flags);
void vec3_releasebuffer(vec3* self, Py_buffer* view);

static Py_ssize_t vec3_len(vec3 * self);
static PyObject* vec3_sq_item(vec3 * self, Py_ssize_t index);
static int vec3_sq_ass_item(vec3 * self, Py_ssize_t index, PyObject * value);
static int vec3_contains(vec3 * self, PyObject * value);

static PyObject * vec3_add(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_sub(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_mul(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_mod(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_divmod(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);
static PyObject * vec3_neg(vec3 *obj);
static PyObject * vec3_pos(vec3 *obj);
static PyObject * vec3_abs(vec3 *obj);
static PyObject * vec3_iadd(vec3* self, PyObject *obj);
static PyObject * vec3_isub(vec3* self, PyObject *obj);
static PyObject * vec3_imul(vec3* self, PyObject *obj);
static PyObject * vec3_imod(vec3* self, PyObject *obj);
static PyObject * vec3_ipow(vec3* self, PyObject * obj2, PyObject * obj3);
static PyObject * vec3_floordiv(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_div(PyObject *obj1, PyObject *obj2);
static PyObject * vec3_ifloordiv(vec3* self, PyObject *obj);
static PyObject * vec3_idiv(vec3* self, PyObject *obj);

static void vec3_dealloc(vec3* self);
static PyObject* vec3_str(vec3* self);
static PyObject* vec3_getattr(PyObject* obj, PyObject* name);
static PyObject* vec3_richcompare(vec3* self, PyObject* other, int comp_type);
static PyObject* vec3_geniter(vec3* self);
static int vec3_init(vec3 *self, PyObject *args, PyObject *kwds);
static PyObject* vec3_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void vec3Iter_dealloc(vec3Iter *rgstate);
static PyObject* vec3Iter_next(vec3Iter *rgstate);
static PyObject* vec3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyMemberDef vec3_members[] = {
	{ "x", T_FLOAT, offsetof(vec3, super_type.x), 0,
	"vec x" },
{ "y", T_FLOAT, offsetof(vec3, super_type.y), 0,
"vec y" },
{ "z", T_FLOAT, offsetof(vec3, super_type.z), 0,
"vec z" },
{ NULL }  /* Sentinel */
};

static PyBufferProcs vec3BufferMethods = {
	(getbufferproc)vec3_getbuffer,
	(releasebufferproc)vec3_releasebuffer,
};

static PySequenceMethods vec3SeqMethods = {
	(lenfunc)vec3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec3_sq_item, // sq_item
	0,
	(ssizeobjargproc)vec3_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)vec3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods vec3NumMethods = {
	(binaryfunc)vec3_add, //nb_add
	(binaryfunc)vec3_sub, //nb_subtract
	(binaryfunc)vec3_mul, //nb_multiply
	(binaryfunc)vec3_mod, //nb_remainder
	(binaryfunc)vec3_divmod, //nb_divmod
	(ternaryfunc)vec3_pow, //nb_power
	(unaryfunc)vec3_neg, //nb_negative
	(unaryfunc)vec3_pos, //nb_positive
	(unaryfunc)vec3_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)vec3_iadd, //nb_inplace_add
	(binaryfunc)vec3_isub, //nb_inplace_subtract
	(binaryfunc)vec3_imul, //nb_inplace_multiply
	(binaryfunc)vec3_imod, //nb_inplace_remainder
	(ternaryfunc)vec3_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)vec3_floordiv, //nb_floor_divide
	(binaryfunc)vec3_div,
	(binaryfunc)vec3_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)vec3_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject vec3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::vec3",             /* tp_name */
	sizeof(vec3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec3_str,                         /* tp_repr */
	&vec3NumMethods,             /* tp_as_number */
	&vec3SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec3_str,                         /* tp_str */
	(getattrofunc)vec3_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&vec3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"vec3( <vec3 compatible type(s)> )\n3 components vector of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	vec3_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec3_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec3_new,                 /* tp_new */
};

static PyTypeObject vec3IterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"vec3Iter",             /* tp_name */
	sizeof(vec3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec3Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"vec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec3Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec3Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region vec4
static int vec4_getbuffer(vec4* self, Py_buffer* view, int flags);
void vec4_releasebuffer(vec4* self, Py_buffer* view);

static Py_ssize_t vec4_len(vec4 * self);
static PyObject* vec4_sq_item(vec4 * self, Py_ssize_t index);
static int vec4_sq_ass_item(vec4 * self, Py_ssize_t index, PyObject * value);
static int vec4_contains(vec4 * self, PyObject * value);

static PyObject * vec4_add(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_sub(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_mul(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_mod(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_divmod(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);
static PyObject * vec4_neg(vec4 *obj);
static PyObject * vec4_pos(vec4 *obj);
static PyObject * vec4_abs(vec4 *obj);
static PyObject * vec4_iadd(vec4* self, PyObject *obj);
static PyObject * vec4_isub(vec4* self, PyObject *obj);
static PyObject * vec4_imul(vec4* self, PyObject *obj);
static PyObject * vec4_imod(vec4* self, PyObject *obj);
static PyObject * vec4_ipow(vec4* self, PyObject * obj2, PyObject * obj3);
static PyObject * vec4_floordiv(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_div(PyObject *obj1, PyObject *obj2);
static PyObject * vec4_ifloordiv(vec4* self, PyObject *obj);
static PyObject * vec4_idiv(vec4* self, PyObject *obj);

static void vec4_dealloc(vec4* self);
static PyObject* vec4_str(vec4* self);
static PyObject* vec4_getattr(PyObject* obj, PyObject* name);
static PyObject* vec4_richcompare(vec4* self, PyObject* other, int comp_type);
static PyObject* vec4_geniter(vec4* self);
static int vec4_init(vec4 *self, PyObject *args, PyObject *kwds);
static PyObject* vec4_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void vec4Iter_dealloc(vec4Iter *rgstate);
static PyObject* vec4Iter_next(vec4Iter *rgstate);
static PyObject* vec4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyMemberDef vec4_members[] = {
	{ "x", T_FLOAT, offsetof(vec4, super_type.x), 0,
	"vec x" },
{ "y", T_FLOAT, offsetof(vec4, super_type.y), 0,
"vec y" },
{ "z", T_FLOAT, offsetof(vec4, super_type.z), 0,
"vec z" },
{ "w", T_FLOAT, offsetof(vec4, super_type.w), 0,
"vec w" },
{ NULL }  /* Sentinel */
};

static PyBufferProcs vec4BufferMethods = {
	(getbufferproc)vec4_getbuffer,
	(releasebufferproc)vec4_releasebuffer,
};

static PySequenceMethods vec4SeqMethods = {
	(lenfunc)vec4_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec4_sq_item, // sq_item
	0,
	(ssizeobjargproc)vec4_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)vec4_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods vec4NumMethods = {
	(binaryfunc)vec4_add, //nb_add
	(binaryfunc)vec4_sub, //nb_subtract
	(binaryfunc)vec4_mul, //nb_multiply
	(binaryfunc)vec4_mod, //nb_remainder
	(binaryfunc)vec4_divmod, //nb_divmod
	(ternaryfunc)vec4_pow, //nb_power
	(unaryfunc)vec4_neg, //nb_negative
	(unaryfunc)vec4_pos, //nb_positive
	(unaryfunc)vec4_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)vec4_iadd, //nb_inplace_add
	(binaryfunc)vec4_isub, //nb_inplace_subtract
	(binaryfunc)vec4_imul, //nb_inplace_multiply
	(binaryfunc)vec4_imod, //nb_inplace_remainder
	(ternaryfunc)vec4_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)vec4_floordiv, //nb_floor_divide
	(binaryfunc)vec4_div,
	(binaryfunc)vec4_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)vec4_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject vec4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::vec4",             /* tp_name */
	sizeof(vec4),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec4_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec4_str,                         /* tp_repr */
	&vec4NumMethods,             /* tp_as_number */
	&vec4SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec4_str,                         /* tp_str */
	(getattrofunc)vec4_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&vec4BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"vec4( <vec4 compatible type(s)> )\n4 components vector of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec4_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec4_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	vec4_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec4_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec4_new,                 /* tp_new */
};

static PyTypeObject vec4IterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"vec4Iter",             /* tp_name */
	sizeof(vec4Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec4Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"vec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec4Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec4Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mvec2
static int mvec2_getbuffer(mvec2* self, Py_buffer* view, int flags);
void mvec2_releasebuffer(mvec2* self, Py_buffer* view);

static Py_ssize_t mvec2_len(mvec2 * self);
static PyObject* mvec2_sq_item(mvec2 * self, Py_ssize_t index);
static int mvec2_sq_ass_item(mvec2 * self, Py_ssize_t index, PyObject * value);
static int mvec2_contains(mvec2 * self, PyObject * value);

static PyObject * mvec2_add(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_mod(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_divmod(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);
static PyObject * mvec2_neg(mvec2 *obj);
static PyObject * mvec2_pos(mvec2 *obj);
static PyObject * mvec2_abs(mvec2 *obj);
static PyObject * mvec2_iadd(mvec2* self, PyObject *obj);
static PyObject * mvec2_isub(mvec2* self, PyObject *obj);
static PyObject * mvec2_imul(mvec2* self, PyObject *obj);
static PyObject * mvec2_imod(mvec2* self, PyObject *obj);
static PyObject * mvec2_ipow(mvec2* self, PyObject * obj2, PyObject * obj3);
static PyObject * mvec2_floordiv(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_div(PyObject *obj1, PyObject *obj2);
static PyObject * mvec2_ifloordiv(mvec2* self, PyObject *obj);
static PyObject * mvec2_idiv(mvec2* self, PyObject *obj);

static void mvec2_dealloc(mvec2* self);
static PyObject* mvec2_str(mvec2* self);
static PyObject* mvec2_getattr(PyObject* obj, PyObject* name);
static int mvec2_setattr(mvec2* obj, PyObject* name, PyObject* value);
static PyObject* mvec2_richcompare(mvec2* self, PyObject* other, int comp_type);
static PyObject* mvec2_geniter(mvec2* self);

static void mvec2Iter_dealloc(mvec2Iter *rgstate);
static PyObject* mvec2Iter_next(mvec2Iter *rgstate);
static PyObject* mvec2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyBufferProcs mvec2BufferMethods = {
	(getbufferproc)mvec2_getbuffer,
	(releasebufferproc)mvec2_releasebuffer,
};

static PySequenceMethods mvec2SeqMethods = {
	(lenfunc)mvec2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec2_sq_item, // sq_item
	0,
	(ssizeobjargproc)mvec2_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mvec2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods mvec2NumMethods = {
	(binaryfunc)mvec2_add, //nb_add
	(binaryfunc)mvec2_sub, //nb_subtract
	(binaryfunc)mvec2_mul, //nb_multiply
	(binaryfunc)mvec2_mod, //nb_remainder
	(binaryfunc)mvec2_divmod, //nb_divmod
	(ternaryfunc)mvec2_pow, //nb_power
	(unaryfunc)mvec2_neg, //nb_negative
	(unaryfunc)mvec2_pos, //nb_positive
	(unaryfunc)mvec2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mvec2_iadd, //nb_inplace_add
	(binaryfunc)mvec2_isub, //nb_inplace_subtract
	(binaryfunc)mvec2_imul, //nb_inplace_multiply
	(binaryfunc)mvec2_imod, //nb_inplace_remainder
	(ternaryfunc)mvec2_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)mvec2_floordiv, //nb_floor_divide
	(binaryfunc)mvec2_div,
	(binaryfunc)mvec2_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)mvec2_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mvec2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::mvec2",             /* tp_name */
	sizeof(mvec2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mvec2_str,                         /* tp_repr */
	&mvec2NumMethods,             /* tp_as_number */
	&mvec2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mvec2_str,                         /* tp_str */
	(getattrofunc)mvec2_getattr,                         /* tp_getattro */
	(setattrofunc)mvec2_setattr,                         /* tp_setattro */
	&mvec2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mvec2( <mvec2 compatible type(s)> )\n2 components mvector of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mvec2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mvec2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	0,                 /* tp_new */
};

static PyTypeObject mvec2IterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"mvec2Iter",             /* tp_name */
	sizeof(mvec2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mvec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mvec2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mvec2Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mvec3
static int mvec3_getbuffer(mvec3* self, Py_buffer* view, int flags);
void mvec3_releasebuffer(mvec3* self, Py_buffer* view);

static Py_ssize_t mvec3_len(mvec3 * self);
static PyObject* mvec3_sq_item(mvec3 * self, Py_ssize_t index);
static int mvec3_sq_ass_item(mvec3 * self, Py_ssize_t index, PyObject * value);
static int mvec3_contains(mvec3 * self, PyObject * value);

static PyObject * mvec3_add(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_mod(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_divmod(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);
static PyObject * mvec3_neg(mvec3 *obj);
static PyObject * mvec3_pos(mvec3 *obj);
static PyObject * mvec3_abs(mvec3 *obj);
static PyObject * mvec3_iadd(mvec3* self, PyObject *obj);
static PyObject * mvec3_isub(mvec3* self, PyObject *obj);
static PyObject * mvec3_imul(mvec3* self, PyObject *obj);
static PyObject * mvec3_imod(mvec3* self, PyObject *obj);
static PyObject * mvec3_ipow(mvec3* self, PyObject * obj2, PyObject * obj3);
static PyObject * mvec3_floordiv(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_div(PyObject *obj1, PyObject *obj2);
static PyObject * mvec3_ifloordiv(mvec3* self, PyObject *obj);
static PyObject * mvec3_idiv(mvec3* self, PyObject *obj);

static void mvec3_dealloc(mvec3* self);
static PyObject* mvec3_str(mvec3* self);
static PyObject* mvec3_getattr(PyObject* obj, PyObject* name);
static int mvec3_setattr(mvec3* obj, PyObject* name, PyObject* value);
static PyObject* mvec3_richcompare(mvec3* self, PyObject* other, int comp_type);
static PyObject* mvec3_geniter(mvec3* self);

static void mvec3Iter_dealloc(mvec3Iter *rgstate);
static PyObject* mvec3Iter_next(mvec3Iter *rgstate);
static PyObject* mvec3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyBufferProcs mvec3BufferMethods = {
	(getbufferproc)mvec3_getbuffer,
	(releasebufferproc)mvec3_releasebuffer,
};

static PySequenceMethods mvec3SeqMethods = {
	(lenfunc)mvec3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec3_sq_item, // sq_item
	0,
	(ssizeobjargproc)mvec3_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mvec3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods mvec3NumMethods = {
	(binaryfunc)mvec3_add, //nb_add
	(binaryfunc)mvec3_sub, //nb_subtract
	(binaryfunc)mvec3_mul, //nb_multiply
	(binaryfunc)mvec3_mod, //nb_remainder
	(binaryfunc)mvec3_divmod, //nb_divmod
	(ternaryfunc)mvec3_pow, //nb_power
	(unaryfunc)mvec3_neg, //nb_negative
	(unaryfunc)mvec3_pos, //nb_positive
	(unaryfunc)mvec3_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mvec3_iadd, //nb_inplace_add
	(binaryfunc)mvec3_isub, //nb_inplace_subtract
	(binaryfunc)mvec3_imul, //nb_inplace_multiply
	(binaryfunc)mvec3_imod, //nb_inplace_remainder
	(ternaryfunc)mvec3_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)mvec3_floordiv, //nb_floor_divide
	(binaryfunc)mvec3_div,
	(binaryfunc)mvec3_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)mvec3_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mvec3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::mvec3",             /* tp_name */
	sizeof(mvec3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mvec3_str,                         /* tp_repr */
	&mvec3NumMethods,             /* tp_as_number */
	&mvec3SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mvec3_str,                         /* tp_str */
	(getattrofunc)mvec3_getattr,                         /* tp_getattro */
	(setattrofunc)mvec3_setattr,                         /* tp_setattro */
	&mvec3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mvec3( <mvec3 compatible type(s)> )\n3 components mvector of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mvec3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mvec3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	0,                 /* tp_new */
};

static PyTypeObject mvec3IterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"mvec3Iter",             /* tp_name */
	sizeof(mvec3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec3Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mvec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mvec3Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mvec3Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mvec4
static int mvec4_getbuffer(mvec4* self, Py_buffer* view, int flags);
void mvec4_releasebuffer(mvec4* self, Py_buffer* view);

static Py_ssize_t mvec4_len(mvec4 * self);
static PyObject* mvec4_sq_item(mvec4 * self, Py_ssize_t index);
static int mvec4_sq_ass_item(mvec4 * self, Py_ssize_t index, PyObject * value);
static int mvec4_contains(mvec4 * self, PyObject * value);

static PyObject * mvec4_add(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_mod(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_divmod(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);
static PyObject * mvec4_neg(mvec4 *obj);
static PyObject * mvec4_pos(mvec4 *obj);
static PyObject * mvec4_abs(mvec4 *obj);
static PyObject * mvec4_iadd(mvec4* self, PyObject *obj);
static PyObject * mvec4_isub(mvec4* self, PyObject *obj);
static PyObject * mvec4_imul(mvec4* self, PyObject *obj);
static PyObject * mvec4_imod(mvec4* self, PyObject *obj);
static PyObject * mvec4_ipow(mvec4* self, PyObject * obj2, PyObject * obj3);
static PyObject * mvec4_floordiv(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_div(PyObject *obj1, PyObject *obj2);
static PyObject * mvec4_ifloordiv(mvec4* self, PyObject *obj);
static PyObject * mvec4_idiv(mvec4* self, PyObject *obj);

static void mvec4_dealloc(mvec4* self);
static PyObject* mvec4_str(mvec4* self);
static PyObject* mvec4_getattr(PyObject* obj, PyObject* name);
static int mvec4_setattr(mvec4* obj, PyObject* name, PyObject* value);
static PyObject* mvec4_richcompare(mvec4* self, PyObject* other, int comp_type);
static PyObject* mvec4_geniter(mvec4* self);

static void mvec4Iter_dealloc(mvec4Iter *rgstate);
static PyObject* mvec4Iter_next(mvec4Iter *rgstate);
static PyObject* mvec4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyBufferProcs mvec4BufferMethods = {
	(getbufferproc)mvec4_getbuffer,
	(releasebufferproc)mvec4_releasebuffer,
};

static PySequenceMethods mvec4SeqMethods = {
	(lenfunc)mvec4_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec4_sq_item, // sq_item
	0,
	(ssizeobjargproc)mvec4_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mvec4_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods mvec4NumMethods = {
	(binaryfunc)mvec4_add, //nb_add
	(binaryfunc)mvec4_sub, //nb_subtract
	(binaryfunc)mvec4_mul, //nb_multiply
	(binaryfunc)mvec4_mod, //nb_remainder
	(binaryfunc)mvec4_divmod, //nb_divmod
	(ternaryfunc)mvec4_pow, //nb_power
	(unaryfunc)mvec4_neg, //nb_negative
	(unaryfunc)mvec4_pos, //nb_positive
	(unaryfunc)mvec4_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mvec4_iadd, //nb_inplace_add
	(binaryfunc)mvec4_isub, //nb_inplace_subtract
	(binaryfunc)mvec4_imul, //nb_inplace_multiply
	(binaryfunc)mvec4_imod, //nb_inplace_remainder
	(ternaryfunc)mvec4_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)mvec4_floordiv, //nb_floor_divide
	(binaryfunc)mvec4_div,
	(binaryfunc)mvec4_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)mvec4_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mvec4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::mvec4",             /* tp_name */
	sizeof(mvec4),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec4_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mvec4_str,                         /* tp_repr */
	&mvec4NumMethods,             /* tp_as_number */
	&mvec4SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mvec4_str,                         /* tp_str */
	(getattrofunc)mvec4_getattr,                         /* tp_getattro */
	(setattrofunc)mvec4_setattr,                         /* tp_setattro */
	&mvec4BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mvec4( <mvec4 compatible type(s)> )\n4 components mvector of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mvec4_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mvec4_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	0,                 /* tp_new */
};

static PyTypeObject mvec4IterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"mvec4Iter",             /* tp_name */
	sizeof(mvec4Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec4Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mvec4Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mvec4Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat2x2
static int mat2x2_getbuffer(mat2x2* self, Py_buffer* view, int flags);
void mat2x2_releasebuffer(mat2x2* self, Py_buffer* view);

static Py_ssize_t mat2x2_len(mat2x2 * self);
static PyObject* mat2x2_sq_item(mat2x2 * self, Py_ssize_t index);
static int mat2x2_sq_ass_item(mat2x2 * self, Py_ssize_t index, PyObject * value);
static int mat2x2_contains(mat2x2 * self, PyObject * value);

static PyObject* mat2x2_mp_item(mat2x2 * self, PyObject* key);
static int mat2x2_mp_ass_item(mat2x2 * self, PyObject* key, PyObject * value);

static PyObject * mat2x2_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x2_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x2_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x2_neg(mat2x2 *obj);
static PyObject * mat2x2_pos(mat2x2 *obj);
static PyObject * mat2x2_abs(mat2x2 *obj);
static PyObject * mat2x2_iadd(mat2x2* self, PyObject *obj);
static PyObject * mat2x2_isub(mat2x2* self, PyObject *obj);
static PyObject * mat2x2_imul(mat2x2* self, PyObject *obj);
static PyObject * mat2x2_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x2_idiv(mat2x2* self, PyObject *obj);

static void mat2x2_dealloc(mat2x2* self);
static PyObject* mat2x2_repr(mat2x2* self);
static PyObject* mat2x2_str(mat2x2* self);
static PyObject* mat2x2_richcompare(mat2x2* self, PyObject* other, int comp_type);
static PyObject* mat2x2_geniter(mat2x2* self);
static int mat2x2_init(mat2x2 *self, PyObject *args, PyObject *kwds);
static PyObject* mat2x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat2x2Iter_dealloc(mat2x2Iter *rgstate);
static PyObject* mat2x2Iter_next(mat2x2Iter *rgstate);
static PyObject* mat2x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat2x2_length(mat2x2 * self, PyObject* arg);

static PyBufferProcs mat2x2BufferMethods = {
	(getbufferproc)mat2x2_getbuffer,
	(releasebufferproc)mat2x2_releasebuffer,
};

static PySequenceMethods mat2x2SeqMethods = {
	(lenfunc)mat2x2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat2x2_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat2x2_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat2x2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat2x2MapMethods = {
	(lenfunc)mat2x2_len, // mp_length
	(binaryfunc)mat2x2_mp_item, // mp_subscript
	(objobjargproc)mat2x2_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat2x2_methods[] = {
	{"length", (PyCFunction)mat2x2_length, METH_NOARGS, "returns the length of glm::mat2x2"},
	{ NULL }
};

static PyNumberMethods mat2x2NumMethods = {
	(binaryfunc)mat2x2_add,
	(binaryfunc)mat2x2_sub,
	(binaryfunc)mat2x2_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat2x2_neg, //nb_negative
	(unaryfunc)mat2x2_pos, //nb_positive
	(unaryfunc)mat2x2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat2x2_iadd, //nb_inplace_add
	(binaryfunc)mat2x2_isub, //nb_inplace_subtract
	(binaryfunc)mat2x2_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat2x2_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat2x2_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat2x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat2x2",             /* tp_name */
	sizeof(mat2x2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat2x2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat2x2_repr,                         /* tp_repr */
	&mat2x2NumMethods,             /* tp_as_number */
	&mat2x2SeqMethods,                         /* tp_as_sequence */
	&mat2x2MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat2x2_str,                         /* tp_str */
	0,//(getattrofunc)mat2x2_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat2x2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat2x2( <mat2x2 compatible type(s)> )\n2 columns of 2 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat2x2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat2x2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat2x2_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat2x2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat2x2_new,                 /* tp_new */
};

static PyTypeObject mat2x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat2x2Iter",             /* tp_name */
	sizeof(mat2x2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat2x2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat2x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat2x2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat2x2Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat2x3
static int mat2x3_getbuffer(mat2x3* self, Py_buffer* view, int flags);
void mat2x3_releasebuffer(mat2x3* self, Py_buffer* view);

static Py_ssize_t mat2x3_len(mat2x3 * self);
static PyObject* mat2x3_sq_item(mat2x3 * self, Py_ssize_t index);
static int mat2x3_sq_ass_item(mat2x3 * self, Py_ssize_t index, PyObject * value);
static int mat2x3_contains(mat2x3 * self, PyObject * value);

static PyObject* mat2x3_mp_item(mat2x3 * self, PyObject* key);
static int mat2x3_mp_ass_item(mat2x3 * self, PyObject* key, PyObject * value);

static PyObject * mat2x3_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x3_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x3_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x3_neg(mat2x3 *obj);
static PyObject * mat2x3_pos(mat2x3 *obj);
static PyObject * mat2x3_abs(mat2x3 *obj);
static PyObject * mat2x3_iadd(mat2x3* self, PyObject *obj);
static PyObject * mat2x3_isub(mat2x3* self, PyObject *obj);
static PyObject * mat2x3_imul(mat2x3* self, PyObject *obj);
static PyObject * mat2x3_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x3_idiv(mat2x3* self, PyObject *obj);

static void mat2x3_dealloc(mat2x3* self);
static PyObject* mat2x3_repr(mat2x3* self);
static PyObject* mat2x3_str(mat2x3* self);
static PyObject* mat2x3_richcompare(mat2x3* self, PyObject* other, int comp_type);
static PyObject* mat2x3_geniter(mat2x3* self);
static int mat2x3_init(mat2x3 *self, PyObject *args, PyObject *kwds);
static PyObject* mat2x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat2x3Iter_dealloc(mat2x3Iter *rgstate);
static PyObject* mat2x3Iter_next(mat2x3Iter *rgstate);
static PyObject* mat2x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat2x3_length(mat2x3 * self, PyObject* arg);

static PyBufferProcs mat2x3BufferMethods = {
	(getbufferproc)mat2x3_getbuffer,
	(releasebufferproc)mat2x3_releasebuffer,
};

static PySequenceMethods mat2x3SeqMethods = {
	(lenfunc)mat2x3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat2x3_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat2x3_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat2x3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat2x3MapMethods = {
	(lenfunc)mat2x3_len, // mp_length
	(binaryfunc)mat2x3_mp_item, // mp_subscript
	(objobjargproc)mat2x3_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat2x3_methods[] = {
	{"length", (PyCFunction)mat2x3_length, METH_NOARGS, "returns the length of glm::mat2x3"},
	{ NULL }
};

static PyNumberMethods mat2x3NumMethods = {
	(binaryfunc)mat2x3_add,
	(binaryfunc)mat2x3_sub,
	(binaryfunc)mat2x3_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat2x3_neg, //nb_negative
	(unaryfunc)mat2x3_pos, //nb_positive
	(unaryfunc)mat2x3_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat2x3_iadd, //nb_inplace_add
	(binaryfunc)mat2x3_isub, //nb_inplace_subtract
	(binaryfunc)mat2x3_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat2x3_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat2x3_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat2x3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat2x3",             /* tp_name */
	sizeof(mat2x3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat2x3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat2x3_repr,                         /* tp_repr */
	&mat2x3NumMethods,             /* tp_as_number */
	&mat2x3SeqMethods,                         /* tp_as_sequence */
	&mat2x3MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat2x3_str,                         /* tp_str */
	0,//(getattrofunc)mat2x3_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat2x3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat2x3( <mat2x3 compatible type(s)> )\n2 columns of 3 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat2x3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat2x3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat2x3_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat2x3_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat2x3_new,                 /* tp_new */
};

static PyTypeObject mat2x3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat2x3Iter",             /* tp_name */
	sizeof(mat2x3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat2x3Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat2x3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat2x3Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat2x3Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat2x4
static int mat2x4_getbuffer(mat2x4* self, Py_buffer* view, int flags);
void mat2x4_releasebuffer(mat2x4* self, Py_buffer* view);

static Py_ssize_t mat2x4_len(mat2x4 * self);
static PyObject* mat2x4_sq_item(mat2x4 * self, Py_ssize_t index);
static int mat2x4_sq_ass_item(mat2x4 * self, Py_ssize_t index, PyObject * value);
static int mat2x4_contains(mat2x4 * self, PyObject * value);

static PyObject* mat2x4_mp_item(mat2x4 * self, PyObject* key);
static int mat2x4_mp_ass_item(mat2x4 * self, PyObject* key, PyObject * value);

static PyObject * mat2x4_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x4_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x4_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x4_neg(mat2x4 *obj);
static PyObject * mat2x4_pos(mat2x4 *obj);
static PyObject * mat2x4_abs(mat2x4 *obj);
static PyObject * mat2x4_iadd(mat2x4* self, PyObject *obj);
static PyObject * mat2x4_isub(mat2x4* self, PyObject *obj);
static PyObject * mat2x4_imul(mat2x4* self, PyObject *obj);
static PyObject * mat2x4_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat2x4_idiv(mat2x4* self, PyObject *obj);

static void mat2x4_dealloc(mat2x4* self);
static PyObject* mat2x4_repr(mat2x4* self);
static PyObject* mat2x4_str(mat2x4* self);
static PyObject* mat2x4_richcompare(mat2x4* self, PyObject* other, int comp_type);
static PyObject* mat2x4_geniter(mat2x4* self);
static int mat2x4_init(mat2x4 *self, PyObject *args, PyObject *kwds);
static PyObject* mat2x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat2x4Iter_dealloc(mat2x4Iter *rgstate);
static PyObject* mat2x4Iter_next(mat2x4Iter *rgstate);
static PyObject* mat2x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat2x4_length(mat2x4 * self, PyObject* arg);

static PyBufferProcs mat2x4BufferMethods = {
	(getbufferproc)mat2x4_getbuffer,
	(releasebufferproc)mat2x4_releasebuffer,
};

static PySequenceMethods mat2x4SeqMethods = {
	(lenfunc)mat2x4_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat2x4_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat2x4_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat2x4_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat2x4MapMethods = {
	(lenfunc)mat2x4_len, // mp_length
	(binaryfunc)mat2x4_mp_item, // mp_subscript
	(objobjargproc)mat2x4_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat2x4_methods[] = {
	{"length", (PyCFunction)mat2x4_length, METH_NOARGS, "returns the length of glm::mat2x4"},
	{ NULL }
};

static PyNumberMethods mat2x4NumMethods = {
	(binaryfunc)mat2x4_add,
	(binaryfunc)mat2x4_sub,
	(binaryfunc)mat2x4_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat2x4_neg, //nb_negative
	(unaryfunc)mat2x4_pos, //nb_positive
	(unaryfunc)mat2x4_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat2x4_iadd, //nb_inplace_add
	(binaryfunc)mat2x4_isub, //nb_inplace_subtract
	(binaryfunc)mat2x4_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat2x4_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat2x4_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat2x4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat2x4",             /* tp_name */
	sizeof(mat2x4),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat2x4_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat2x4_repr,                         /* tp_repr */
	&mat2x4NumMethods,             /* tp_as_number */
	&mat2x4SeqMethods,                         /* tp_as_sequence */
	&mat2x4MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat2x4_str,                         /* tp_str */
	0,//(getattrofunc)mat2x4_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat2x4BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat2x4( <mat2x4 compatible type(s)> )\n2 columns of 4 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat2x4_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat2x4_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat2x4_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat2x4_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat2x4_new,                 /* tp_new */
};

static PyTypeObject mat2x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat2x4Iter",             /* tp_name */
	sizeof(mat2x4Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat2x4Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat2x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat2x4Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat2x4Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat3x2
static int mat3x2_getbuffer(mat3x2* self, Py_buffer* view, int flags);
void mat3x2_releasebuffer(mat3x2* self, Py_buffer* view);

static Py_ssize_t mat3x2_len(mat3x2 * self);
static PyObject* mat3x2_sq_item(mat3x2 * self, Py_ssize_t index);
static int mat3x2_sq_ass_item(mat3x2 * self, Py_ssize_t index, PyObject * value);
static int mat3x2_contains(mat3x2 * self, PyObject * value);

static PyObject* mat3x2_mp_item(mat3x2 * self, PyObject* key);
static int mat3x2_mp_ass_item(mat3x2 * self, PyObject* key, PyObject * value);

static PyObject * mat3x2_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x2_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x2_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x2_neg(mat3x2 *obj);
static PyObject * mat3x2_pos(mat3x2 *obj);
static PyObject * mat3x2_abs(mat3x2 *obj);
static PyObject * mat3x2_iadd(mat3x2* self, PyObject *obj);
static PyObject * mat3x2_isub(mat3x2* self, PyObject *obj);
static PyObject * mat3x2_imul(mat3x2* self, PyObject *obj);
static PyObject * mat3x2_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x2_idiv(mat3x2* self, PyObject *obj);

static void mat3x2_dealloc(mat3x2* self);
static PyObject* mat3x2_repr(mat3x2* self);
static PyObject* mat3x2_str(mat3x2* self);
static PyObject* mat3x2_richcompare(mat3x2* self, PyObject* other, int comp_type);
static PyObject* mat3x2_geniter(mat3x2* self);
static int mat3x2_init(mat3x2 *self, PyObject *args, PyObject *kwds);
static PyObject* mat3x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat3x2Iter_dealloc(mat3x2Iter *rgstate);
static PyObject* mat3x2Iter_next(mat3x2Iter *rgstate);
static PyObject* mat3x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat3x2_length(mat3x2 * self, PyObject* arg);

static PyBufferProcs mat3x2BufferMethods = {
	(getbufferproc)mat3x2_getbuffer,
	(releasebufferproc)mat3x2_releasebuffer,
};

static PySequenceMethods mat3x2SeqMethods = {
	(lenfunc)mat3x2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat3x2_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat3x2_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat3x2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat3x2MapMethods = {
	(lenfunc)mat3x2_len, // mp_length
	(binaryfunc)mat3x2_mp_item, // mp_subscript
	(objobjargproc)mat3x2_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat3x2_methods[] = {
	{"length", (PyCFunction)mat3x2_length, METH_NOARGS, "returns the length of glm::mat3x2"},
	{ NULL }
};

static PyNumberMethods mat3x2NumMethods = {
	(binaryfunc)mat3x2_add,
	(binaryfunc)mat3x2_sub,
	(binaryfunc)mat3x2_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat3x2_neg, //nb_negative
	(unaryfunc)mat3x2_pos, //nb_positive
	(unaryfunc)mat3x2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat3x2_iadd, //nb_inplace_add
	(binaryfunc)mat3x2_isub, //nb_inplace_subtract
	(binaryfunc)mat3x2_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat3x2_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat3x2_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat3x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat3x2",             /* tp_name */
	sizeof(mat3x2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat3x2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat3x2_repr,                         /* tp_repr */
	&mat3x2NumMethods,             /* tp_as_number */
	&mat3x2SeqMethods,                         /* tp_as_sequence */
	&mat3x2MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat3x2_str,                         /* tp_str */
	0,//(getattrofunc)mat3x2_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat3x2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat3x2( <mat3x2 compatible type(s)> )\n3 columns of 2 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat3x2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat3x2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat3x2_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat3x2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat3x2_new,                 /* tp_new */
};

static PyTypeObject mat3x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat3x2Iter",             /* tp_name */
	sizeof(mat3x2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat3x2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat3x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat3x2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat3x2Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat3x3
static int mat3x3_getbuffer(mat3x3* self, Py_buffer* view, int flags);
void mat3x3_releasebuffer(mat3x3* self, Py_buffer* view);

static Py_ssize_t mat3x3_len(mat3x3 * self);
static PyObject* mat3x3_sq_item(mat3x3 * self, Py_ssize_t index);
static int mat3x3_sq_ass_item(mat3x3 * self, Py_ssize_t index, PyObject * value);
static int mat3x3_contains(mat3x3 * self, PyObject * value);

static PyObject* mat3x3_mp_item(mat3x3 * self, PyObject* key);
static int mat3x3_mp_ass_item(mat3x3 * self, PyObject* key, PyObject * value);

static PyObject * mat3x3_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x3_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x3_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x3_neg(mat3x3 *obj);
static PyObject * mat3x3_pos(mat3x3 *obj);
static PyObject * mat3x3_abs(mat3x3 *obj);
static PyObject * mat3x3_iadd(mat3x3* self, PyObject *obj);
static PyObject * mat3x3_isub(mat3x3* self, PyObject *obj);
static PyObject * mat3x3_imul(mat3x3* self, PyObject *obj);
static PyObject * mat3x3_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x3_idiv(mat3x3* self, PyObject *obj);

static void mat3x3_dealloc(mat3x3* self);
static PyObject* mat3x3_repr(mat3x3* self);
static PyObject* mat3x3_str(mat3x3* self);
static PyObject* mat3x3_richcompare(mat3x3* self, PyObject* other, int comp_type);
static PyObject* mat3x3_geniter(mat3x3* self);
static int mat3x3_init(mat3x3 *self, PyObject *args, PyObject *kwds);
static PyObject* mat3x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat3x3Iter_dealloc(mat3x3Iter *rgstate);
static PyObject* mat3x3Iter_next(mat3x3Iter *rgstate);
static PyObject* mat3x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat3x3_length(mat3x3 * self, PyObject* arg);

static PyBufferProcs mat3x3BufferMethods = {
	(getbufferproc)mat3x3_getbuffer,
	(releasebufferproc)mat3x3_releasebuffer,
};

static PySequenceMethods mat3x3SeqMethods = {
	(lenfunc)mat3x3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat3x3_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat3x3_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat3x3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat3x3MapMethods = {
	(lenfunc)mat3x3_len, // mp_length
	(binaryfunc)mat3x3_mp_item, // mp_subscript
	(objobjargproc)mat3x3_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat3x3_methods[] = {
	{"length", (PyCFunction)mat3x3_length, METH_NOARGS, "returns the length of glm::mat3x3"},
	{ NULL }
};

static PyNumberMethods mat3x3NumMethods = {
	(binaryfunc)mat3x3_add,
	(binaryfunc)mat3x3_sub,
	(binaryfunc)mat3x3_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat3x3_neg, //nb_negative
	(unaryfunc)mat3x3_pos, //nb_positive
	(unaryfunc)mat3x3_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat3x3_iadd, //nb_inplace_add
	(binaryfunc)mat3x3_isub, //nb_inplace_subtract
	(binaryfunc)mat3x3_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat3x3_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat3x3_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat3x3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat3x3",             /* tp_name */
	sizeof(mat3x3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat3x3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat3x3_repr,                         /* tp_repr */
	&mat3x3NumMethods,             /* tp_as_number */
	&mat3x3SeqMethods,                         /* tp_as_sequence */
	&mat3x3MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat3x3_str,                         /* tp_str */
	0,//(getattrofunc)mat3x3_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat3x3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat3x3( <mat3x3 compatible type(s)> )\n3 columns of 3 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat3x3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat3x3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat3x3_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat3x3_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat3x3_new,                 /* tp_new */
};

static PyTypeObject mat3x3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat3x3Iter",             /* tp_name */
	sizeof(mat3x3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat3x3Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat3x3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat3x3Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat3x3Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat3x4
static int mat3x4_getbuffer(mat3x4* self, Py_buffer* view, int flags);
void mat3x4_releasebuffer(mat3x4* self, Py_buffer* view);

static Py_ssize_t mat3x4_len(mat3x4 * self);
static PyObject* mat3x4_sq_item(mat3x4 * self, Py_ssize_t index);
static int mat3x4_sq_ass_item(mat3x4 * self, Py_ssize_t index, PyObject * value);
static int mat3x4_contains(mat3x4 * self, PyObject * value);

static PyObject* mat3x4_mp_item(mat3x4 * self, PyObject* key);
static int mat3x4_mp_ass_item(mat3x4 * self, PyObject* key, PyObject * value);

static PyObject * mat3x4_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x4_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x4_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x4_neg(mat3x4 *obj);
static PyObject * mat3x4_pos(mat3x4 *obj);
static PyObject * mat3x4_abs(mat3x4 *obj);
static PyObject * mat3x4_iadd(mat3x4* self, PyObject *obj);
static PyObject * mat3x4_isub(mat3x4* self, PyObject *obj);
static PyObject * mat3x4_imul(mat3x4* self, PyObject *obj);
static PyObject * mat3x4_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat3x4_idiv(mat3x4* self, PyObject *obj);

static void mat3x4_dealloc(mat3x4* self);
static PyObject* mat3x4_repr(mat3x4* self);
static PyObject* mat3x4_str(mat3x4* self);
static PyObject* mat3x4_richcompare(mat3x4* self, PyObject* other, int comp_type);
static PyObject* mat3x4_geniter(mat3x4* self);
static int mat3x4_init(mat3x4 *self, PyObject *args, PyObject *kwds);
static PyObject* mat3x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat3x4Iter_dealloc(mat3x4Iter *rgstate);
static PyObject* mat3x4Iter_next(mat3x4Iter *rgstate);
static PyObject* mat3x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat3x4_length(mat3x4 * self, PyObject* arg);

static PyBufferProcs mat3x4BufferMethods = {
	(getbufferproc)mat3x4_getbuffer,
	(releasebufferproc)mat3x4_releasebuffer,
};

static PySequenceMethods mat3x4SeqMethods = {
	(lenfunc)mat3x4_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat3x4_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat3x4_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat3x4_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat3x4MapMethods = {
	(lenfunc)mat3x4_len, // mp_length
	(binaryfunc)mat3x4_mp_item, // mp_subscript
	(objobjargproc)mat3x4_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat3x4_methods[] = {
	{"length", (PyCFunction)mat3x4_length, METH_NOARGS, "returns the length of glm::mat3x4"},
	{ NULL }
};

static PyNumberMethods mat3x4NumMethods = {
	(binaryfunc)mat3x4_add,
	(binaryfunc)mat3x4_sub,
	(binaryfunc)mat3x4_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat3x4_neg, //nb_negative
	(unaryfunc)mat3x4_pos, //nb_positive
	(unaryfunc)mat3x4_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat3x4_iadd, //nb_inplace_add
	(binaryfunc)mat3x4_isub, //nb_inplace_subtract
	(binaryfunc)mat3x4_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat3x4_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat3x4_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat3x4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat3x4",             /* tp_name */
	sizeof(mat3x4),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat3x4_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat3x4_repr,                         /* tp_repr */
	&mat3x4NumMethods,             /* tp_as_number */
	&mat3x4SeqMethods,                         /* tp_as_sequence */
	&mat3x4MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat3x4_str,                         /* tp_str */
	0,//(getattrofunc)mat3x4_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat3x4BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat3x4( <mat3x4 compatible type(s)> )\n3 columns of 4 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat3x4_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat3x4_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat3x4_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat3x4_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat3x4_new,                 /* tp_new */
};

static PyTypeObject mat3x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat3x4Iter",             /* tp_name */
	sizeof(mat3x4Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat3x4Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat3x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat3x4Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat3x4Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat4x2
static int mat4x2_getbuffer(mat4x2* self, Py_buffer* view, int flags);
void mat4x2_releasebuffer(mat4x2* self, Py_buffer* view);

static Py_ssize_t mat4x2_len(mat4x2 * self);
static PyObject* mat4x2_sq_item(mat4x2 * self, Py_ssize_t index);
static int mat4x2_sq_ass_item(mat4x2 * self, Py_ssize_t index, PyObject * value);
static int mat4x2_contains(mat4x2 * self, PyObject * value);

static PyObject* mat4x2_mp_item(mat4x2 * self, PyObject* key);
static int mat4x2_mp_ass_item(mat4x2 * self, PyObject* key, PyObject * value);

static PyObject * mat4x2_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x2_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x2_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x2_neg(mat4x2 *obj);
static PyObject * mat4x2_pos(mat4x2 *obj);
static PyObject * mat4x2_abs(mat4x2 *obj);
static PyObject * mat4x2_iadd(mat4x2* self, PyObject *obj);
static PyObject * mat4x2_isub(mat4x2* self, PyObject *obj);
static PyObject * mat4x2_imul(mat4x2* self, PyObject *obj);
static PyObject * mat4x2_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x2_idiv(mat4x2* self, PyObject *obj);

static void mat4x2_dealloc(mat4x2* self);
static PyObject* mat4x2_repr(mat4x2* self);
static PyObject* mat4x2_str(mat4x2* self);
static PyObject* mat4x2_richcompare(mat4x2* self, PyObject* other, int comp_type);
static PyObject* mat4x2_geniter(mat4x2* self);
static int mat4x2_init(mat4x2 *self, PyObject *args, PyObject *kwds);
static PyObject* mat4x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat4x2Iter_dealloc(mat4x2Iter *rgstate);
static PyObject* mat4x2Iter_next(mat4x2Iter *rgstate);
static PyObject* mat4x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat4x2_length(mat4x2 * self, PyObject* arg);

static PyBufferProcs mat4x2BufferMethods = {
	(getbufferproc)mat4x2_getbuffer,
	(releasebufferproc)mat4x2_releasebuffer,
};

static PySequenceMethods mat4x2SeqMethods = {
	(lenfunc)mat4x2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat4x2_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat4x2_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat4x2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat4x2MapMethods = {
	(lenfunc)mat4x2_len, // mp_length
	(binaryfunc)mat4x2_mp_item, // mp_subscript
	(objobjargproc)mat4x2_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat4x2_methods[] = {
	{"length", (PyCFunction)mat4x2_length, METH_NOARGS, "returns the length of glm::mat4x2"},
	{ NULL }
};

static PyNumberMethods mat4x2NumMethods = {
	(binaryfunc)mat4x2_add,
	(binaryfunc)mat4x2_sub,
	(binaryfunc)mat4x2_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat4x2_neg, //nb_negative
	(unaryfunc)mat4x2_pos, //nb_positive
	(unaryfunc)mat4x2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat4x2_iadd, //nb_inplace_add
	(binaryfunc)mat4x2_isub, //nb_inplace_subtract
	(binaryfunc)mat4x2_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat4x2_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat4x2_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat4x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat4x2",             /* tp_name */
	sizeof(mat4x2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat4x2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat4x2_repr,                         /* tp_repr */
	&mat4x2NumMethods,             /* tp_as_number */
	&mat4x2SeqMethods,                         /* tp_as_sequence */
	&mat4x2MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat4x2_str,                         /* tp_str */
	0,//(getattrofunc)mat4x2_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat4x2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat4x2( <mat4x2 compatible type(s)> )\n4 columns of 2 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat4x2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat4x2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat4x2_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat4x2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat4x2_new,                 /* tp_new */
};

static PyTypeObject mat4x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat4x2Iter",             /* tp_name */
	sizeof(mat4x2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat4x2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat4x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat4x2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat4x2Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat4x3
static int mat4x3_getbuffer(mat4x3* self, Py_buffer* view, int flags);
void mat4x3_releasebuffer(mat4x3* self, Py_buffer* view);

static Py_ssize_t mat4x3_len(mat4x3 * self);
static PyObject* mat4x3_sq_item(mat4x3 * self, Py_ssize_t index);
static int mat4x3_sq_ass_item(mat4x3 * self, Py_ssize_t index, PyObject * value);
static int mat4x3_contains(mat4x3 * self, PyObject * value);

static PyObject* mat4x3_mp_item(mat4x3 * self, PyObject* key);
static int mat4x3_mp_ass_item(mat4x3 * self, PyObject* key, PyObject * value);

static PyObject * mat4x3_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x3_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x3_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x3_neg(mat4x3 *obj);
static PyObject * mat4x3_pos(mat4x3 *obj);
static PyObject * mat4x3_abs(mat4x3 *obj);
static PyObject * mat4x3_iadd(mat4x3* self, PyObject *obj);
static PyObject * mat4x3_isub(mat4x3* self, PyObject *obj);
static PyObject * mat4x3_imul(mat4x3* self, PyObject *obj);
static PyObject * mat4x3_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x3_idiv(mat4x3* self, PyObject *obj);

static void mat4x3_dealloc(mat4x3* self);
static PyObject* mat4x3_repr(mat4x3* self);
static PyObject* mat4x3_str(mat4x3* self);
static PyObject* mat4x3_richcompare(mat4x3* self, PyObject* other, int comp_type);
static PyObject* mat4x3_geniter(mat4x3* self);
static int mat4x3_init(mat4x3 *self, PyObject *args, PyObject *kwds);
static PyObject* mat4x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat4x3Iter_dealloc(mat4x3Iter *rgstate);
static PyObject* mat4x3Iter_next(mat4x3Iter *rgstate);
static PyObject* mat4x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat4x3_length(mat4x3 * self, PyObject* arg);

static PyBufferProcs mat4x3BufferMethods = {
	(getbufferproc)mat4x3_getbuffer,
	(releasebufferproc)mat4x3_releasebuffer,
};

static PySequenceMethods mat4x3SeqMethods = {
	(lenfunc)mat4x3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat4x3_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat4x3_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat4x3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat4x3MapMethods = {
	(lenfunc)mat4x3_len, // mp_length
	(binaryfunc)mat4x3_mp_item, // mp_subscript
	(objobjargproc)mat4x3_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat4x3_methods[] = {
	{"length", (PyCFunction)mat4x3_length, METH_NOARGS, "returns the length of glm::mat4x3"},
	{ NULL }
};

static PyNumberMethods mat4x3NumMethods = {
	(binaryfunc)mat4x3_add,
	(binaryfunc)mat4x3_sub,
	(binaryfunc)mat4x3_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat4x3_neg, //nb_negative
	(unaryfunc)mat4x3_pos, //nb_positive
	(unaryfunc)mat4x3_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat4x3_iadd, //nb_inplace_add
	(binaryfunc)mat4x3_isub, //nb_inplace_subtract
	(binaryfunc)mat4x3_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat4x3_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat4x3_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat4x3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat4x3",             /* tp_name */
	sizeof(mat4x3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat4x3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat4x3_repr,                         /* tp_repr */
	&mat4x3NumMethods,             /* tp_as_number */
	&mat4x3SeqMethods,                         /* tp_as_sequence */
	&mat4x3MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat4x3_str,                         /* tp_str */
	0,//(getattrofunc)mat4x3_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat4x3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat4x3( <mat4x3 compatible type(s)> )\n4 columns of 3 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat4x3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat4x3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat4x3_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat4x3_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat4x3_new,                 /* tp_new */
};

static PyTypeObject mat4x3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat4x3Iter",             /* tp_name */
	sizeof(mat4x3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat4x3Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat4x3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat4x3Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat4x3Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region mat4x4
static int mat4x4_getbuffer(mat4x4* self, Py_buffer* view, int flags);
void mat4x4_releasebuffer(mat4x4* self, Py_buffer* view);

static Py_ssize_t mat4x4_len(mat4x4 * self);
static PyObject* mat4x4_sq_item(mat4x4 * self, Py_ssize_t index);
static int mat4x4_sq_ass_item(mat4x4 * self, Py_ssize_t index, PyObject * value);
static int mat4x4_contains(mat4x4 * self, PyObject * value);

static PyObject* mat4x4_mp_item(mat4x4 * self, PyObject* key);
static int mat4x4_mp_ass_item(mat4x4 * self, PyObject* key, PyObject * value);

static PyObject * mat4x4_add(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x4_sub(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x4_mul(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x4_neg(mat4x4 *obj);
static PyObject * mat4x4_pos(mat4x4 *obj);
static PyObject * mat4x4_abs(mat4x4 *obj);
static PyObject * mat4x4_iadd(mat4x4* self, PyObject *obj);
static PyObject * mat4x4_isub(mat4x4* self, PyObject *obj);
static PyObject * mat4x4_imul(mat4x4* self, PyObject *obj);
static PyObject * mat4x4_div(PyObject *obj1, PyObject *obj2);
static PyObject * mat4x4_idiv(mat4x4* self, PyObject *obj);

static void mat4x4_dealloc(mat4x4* self);
static PyObject* mat4x4_repr(mat4x4* self);
static PyObject* mat4x4_str(mat4x4* self);
static PyObject* mat4x4_richcompare(mat4x4* self, PyObject* other, int comp_type);
static PyObject* mat4x4_geniter(mat4x4* self);
static int mat4x4_init(mat4x4 *self, PyObject *args, PyObject *kwds);
static PyObject* mat4x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void mat4x4Iter_dealloc(mat4x4Iter *rgstate);
static PyObject* mat4x4Iter_next(mat4x4Iter *rgstate);
static PyObject* mat4x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyObject* mat4x4_length(mat4x4 * self, PyObject* arg);

static PyBufferProcs mat4x4BufferMethods = {
	(getbufferproc)mat4x4_getbuffer,
	(releasebufferproc)mat4x4_releasebuffer,
};

static PySequenceMethods mat4x4SeqMethods = {
	(lenfunc)mat4x4_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mat4x4_sq_item, // sq_item
	0,
	(ssizeobjargproc)mat4x4_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)mat4x4_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMappingMethods mat4x4MapMethods = {
	(lenfunc)mat4x4_len, // mp_length
	(binaryfunc)mat4x4_mp_item, // mp_subscript
	(objobjargproc)mat4x4_mp_ass_item, // mp_ass_subscript
};

static PyMethodDef mat4x4_methods[] = {
	{"length", (PyCFunction)mat4x4_length, METH_NOARGS, "returns the length of glm::mat4x4"},
	{ NULL }
};

static PyNumberMethods mat4x4NumMethods = {
	(binaryfunc)mat4x4_add,
	(binaryfunc)mat4x4_sub,
	(binaryfunc)mat4x4_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat4x4_neg, //nb_negative
	(unaryfunc)mat4x4_pos, //nb_positive
	(unaryfunc)mat4x4_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)mat4x4_iadd, //nb_inplace_add
	(binaryfunc)mat4x4_isub, //nb_inplace_subtract
	(binaryfunc)mat4x4_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)mat4x4_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat4x4_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject mat4x4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::mat4x4",             /* tp_name */
	sizeof(mat4x4),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat4x4_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat4x4_repr,                         /* tp_repr */
	&mat4x4NumMethods,             /* tp_as_number */
	&mat4x4SeqMethods,                         /* tp_as_sequence */
	&mat4x4MapMethods,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat4x4_str,                         /* tp_str */
	0,//(getattrofunc)mat4x4_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&mat4x4BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"mat4x4( <mat4x4 compatible type(s)> )\n4 columns of 4 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat4x4_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat4x4_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	mat4x4_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat4x4_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat4x4_new,                 /* tp_new */
};

static PyTypeObject mat4x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat4x4Iter",             /* tp_name */
	sizeof(mat4x4Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat4x4Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat4x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mat4x4Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat4x4Iter_new,                 /* tp_new */
};
#pragma endregion
#pragma region quat
static int quat_getbuffer(quat* self, Py_buffer* view, int flags);
void quat_releasebuffer(quat* self, Py_buffer* view);

static Py_ssize_t quat_len(quat * self);
static PyObject* quat_sq_item(quat * self, Py_ssize_t index);
static int quat_sq_ass_item(quat * self, Py_ssize_t index, PyObject * value);
static int quat_contains(quat * self, PyObject * value);

static PyObject * quat_add(PyObject *obj1, PyObject *obj2);
static PyObject * quat_sub(PyObject *obj1, PyObject *obj2);
static PyObject * quat_mul(PyObject *obj1, PyObject *obj2);
static PyObject * quat_neg(quat *obj);
static PyObject * quat_pos(quat *obj);
static PyObject * quat_abs(quat *obj);
static PyObject * quat_iadd(quat* self, PyObject *obj);
static PyObject * quat_isub(quat* self, PyObject *obj);
static PyObject * quat_imul(quat* self, PyObject *obj);
static PyObject * quat_div(PyObject *obj1, PyObject *obj2);
static PyObject * quat_idiv(quat* self, PyObject *obj);

static void quat_dealloc(quat* self);
static PyObject* quat_str(quat* self);
static PyObject* quat_richcompare(quat* self, PyObject* other, int comp_type);
static PyObject* quat_geniter(quat* self);
static int quat_init(quat *self, PyObject *args, PyObject *kwds);
static PyObject* quat_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static void quatIter_dealloc(quatIter *rgstate);
static PyObject* quatIter_next(quatIter *rgstate);
static PyObject* quatIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static PyMemberDef quat_members[] = {
	{ "x", T_FLOAT, offsetof(quat, super_type.x), 0,
	"quat x" },
{ "y", T_FLOAT, offsetof(quat, super_type.y), 0,
"quat y" },
{ "z", T_FLOAT, offsetof(quat, super_type.z), 0,
"quat z" },
{ "w", T_FLOAT, offsetof(quat, super_type.w), 0,
"quat w" },
{ NULL }  /* Sentinel */
};

static PyBufferProcs quatBufferMethods = {
	(getbufferproc)quat_getbuffer,
	(releasebufferproc)quat_releasebuffer,
};

static PySequenceMethods quatSeqMethods = {
	(lenfunc)quat_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)quat_sq_item, // sq_item
	0,
	(ssizeobjargproc)quat_sq_ass_item, // sq_ass_item
	0,
	(objobjproc)quat_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyNumberMethods quatNumMethods = {
	(binaryfunc)quat_add, //nb_add
	(binaryfunc)quat_sub, //nb_subtract
	(binaryfunc)quat_mul, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)quat_neg, //nb_negative
	(unaryfunc)quat_pos, //nb_positive
	(unaryfunc)quat_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)quat_iadd, //nb_inplace_add
	(binaryfunc)quat_isub, //nb_inplace_subtract
	(binaryfunc)quat_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)quat_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)quat_idiv, //nb_inplace_true_divide

	0, //nb_index
};

static PyTypeObject quatType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::quat",             /* tp_name */
	sizeof(quat),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)quat_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)quat_str,                         /* tp_repr */
	&quatNumMethods,             /* tp_as_number */
	&quatSeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)quat_str,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&quatBufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"quat( <quat compatible type(s)> )\n4 components quaternion of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)quat_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)quat_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	quat_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)quat_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)quat_new,                 /* tp_new */
};

static PyTypeObject quatIterType{
	PyVarObject_HEAD_INIT(NULL, 0)
	"quatIter",             /* tp_name */
	sizeof(quatIter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)quatIter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"quat iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)quatIter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)quatIter_new,                 /* tp_new */
};
#pragma endregion
#pragma endregion

// INTERNAL FUNCTIONS
#pragma region internal functions

PyObject* c_void_p = NULL;

#if defined(_M_IX86) || defined(__i386__)
PyObject* Ctypes_C_VOID_P(void* p) {
	PyObject* argList = Py_BuildValue("(K)", (unsigned long)p);
	PyObject* out = PyObject_CallObject(c_void_p, argList);
	Py_DECREF(argList);
	return out;
}
#else
PyObject* Ctypes_C_VOID_P(void* p) {
	PyObject* argList = Py_BuildValue("(K)", (unsigned long long)p);
	PyObject* out = PyObject_CallObject(c_void_p, argList);
	Py_DECREF(argList);
	return out;
}
#endif

#define Py_IS_NOTIMPLEMENTED(op) (op == NULL || (PyObject*)op == Py_NotImplemented) // find out if op is NULL or NotImplemented

#define PyObject_IterCheck(op) ((op)->ob_type->tp_iter != 0)

#define PyGLM_TYPE_AS_CSTRING(op) op->ob_type->tp_name

#define PyGLM_TypeCheck(op, tp) (Py_TYPE(op) == tp) 

#define PyGLM_String_AsString(name) PyBytes_AsString(PyUnicode_AsASCIIString(name));

// error functions
#define PyGLM_TYPEERROR_O(str, obj) PyErr_Format(PyExc_TypeError, "%s'%s'", str, PyGLM_TYPE_AS_CSTRING(obj));
#define PyGLM_TYPEERROR_2O(str, obj1, obj2) PyErr_Format(PyExc_TypeError, "%s'%s' and '%s'", str, PyGLM_TYPE_AS_CSTRING(obj1), PyGLM_TYPE_AS_CSTRING(obj2));

#define PyGLM_Arg_Unpack_1O(args, name, arg1) if(!PyArg_UnpackTuple(args, name, 1, 1, &arg1)) return NULL
#define PyGLM_Arg_Unpack_2O(args, name, arg1, arg2) if(!PyArg_UnpackTuple(args, name, 2, 2, &arg1, &arg2)) return NULL
#define PyGLM_Arg_Unpack_3O(args, name, arg1, arg2, arg3) if(!PyArg_UnpackTuple(args, name, 3, 3, &arg1, &arg2, &arg3)) return NULL
#define PyGLM_Arg_Unpack_4O(args, name, arg1, arg2, arg3, arg4) if(!PyArg_UnpackTuple(args, name, 4, 4, &arg1, &arg2, &arg3, &arg4)) return NULL
#define PyGLM_Arg_Unpack_5O(args, name, arg1, arg2, arg3, arg4, arg5) if(!PyArg_UnpackTuple(args, name, 5, 5, &arg1, &arg2, &arg3, &arg4, &arg5)) return NULL
#define PyGLM_Arg_Unpack_6O(args, name, arg1, arg2, arg3, arg4, arg5, arg6) if(!PyArg_UnpackTuple(args, name, 6, 6, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) return NULL


bool PyGLM_Number_Check(PyObject* arg) {
	if (PyFloat_Check(arg) || PyLong_Check(arg) || PyBool_Check(arg)) {
		return true;
	}
	if (arg->ob_type->tp_as_number != NULL && arg->ob_type->tp_as_number->nb_float != NULL) {
		PyObject* temp = PyNumber_Float(arg);
		if (temp != NULL) {
			Py_DECREF(temp);
			return true;
		}
		PyErr_Clear();
	}
	return false;
}

double PyGLM_Number_AsDouble(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyFloat_AS_DOUBLE(arg);
	}
	if (PyLong_Check(arg)) {
		return PyLong_AsDouble(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.0 : 0.0;
	}
	PyObject* arg_as_float = PyNumber_Float(arg);
	double out = PyFloat_AS_DOUBLE(arg_as_float);
	Py_DECREF(arg_as_float);
	return out;
}

long PyGLM_Number_AsLong(PyObject* arg) {
	if (PyLong_Check(arg)) {
		return PyLong_AS_LONG(arg);
	}
	if (PyFloat_Check(arg)) {
		return (long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1 : 0;
	}
	PyObject* arg_as_long = PyNumber_Long(arg);
	long out = PyLong_AS_LONG(arg_as_long);
	Py_DECREF(arg_as_long);
	return out;
}

float PyGLM_Number_AsFloat(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return (float)PyFloat_AS_DOUBLE(arg);
	}
	if (PyLong_Check(arg)) {
		return (float)PyLong_AS_LONG(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.f : 0.f;
	}
	PyObject* arg_as_float = PyNumber_Float(arg);
	float out = (float)PyFloat_AS_DOUBLE(arg_as_float);
	Py_DECREF(arg_as_float);
	return out;
}


//static char uniterize(PyObject* iterable, void** out, int level = 0) {
//	PyObject* iterator = PyObject_GetIter(iterable);
//	if (iterator != NULL) {
//		Py_ssize_t iterator_length = PyObject_Length(iterable);
//		if (iterator_length == 2) {
//			PyObject* value0 = PyIter_Next(iterator);
//			PyObject* value1 = PyIter_Next(iterator);
//
//
//			Py_DECREF(iterator);
//
//
//			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1)) {
//
//				Py_DECREF(value0);
//				Py_DECREF(value1);
//
//				return PyGLM_TYPE_NONE;
//			}
//
//			float value0_as_double = PyGLM_Number_AsFloat(value0);
//			float value1_as_double = PyGLM_Number_AsFloat(value1);
//
//			*out = malloc(sizeof(glm::vec2));
//			*((glm::vec2*)*out) = glm::vec2(value0_as_double, value1_as_double);
//
//
//			Py_DECREF(value0);
//			Py_DECREF(value1);
//
//			return PyGLM_TYPE_VEC2;
//
//		}
//		if (iterator_length == 3) {
//			PyObject* value0 = PyIter_Next(iterator);
//			PyObject* value1 = PyIter_Next(iterator);
//			PyObject* value2 = PyIter_Next(iterator);
//
//
//			Py_DECREF(iterator);
//
//
//			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2)) {
//
//				Py_DECREF(value0);
//				Py_DECREF(value1);
//				Py_DECREF(value2);
//
//				return PyGLM_TYPE_NONE;
//			}
//
//			float value0_as_double = PyGLM_Number_AsFloat(value0);
//			float value1_as_double = PyGLM_Number_AsFloat(value1);
//			float value2_as_double = PyGLM_Number_AsFloat(value2);
//
//			*out = malloc(sizeof(glm::vec3));
//			*((glm::vec3*)*out) = glm::vec3(value0_as_double, value1_as_double, value2_as_double);
//
//
//			Py_DECREF(value0);
//			Py_DECREF(value1);
//			Py_DECREF(value2);
//
//			return PyGLM_TYPE_VEC3;
//		}
//		if (iterator_length == 4) {
//			PyObject* value0 = PyIter_Next(iterator);
//			PyObject* value1 = PyIter_Next(iterator);
//			PyObject* value2 = PyIter_Next(iterator);
//			PyObject* value3 = PyIter_Next(iterator);
//
//
//			Py_DECREF(iterator);
//
//
//			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2) || value3 == NULL || !PyGLM_Number_Check(value3)) {
//
//				Py_DECREF(value0);
//				Py_DECREF(value1);
//				Py_DECREF(value2);
//				Py_DECREF(value3);
//
//				return PyGLM_TYPE_NONE;
//			}
//
//			float value0_as_double = PyGLM_Number_AsFloat(value0);
//			float value1_as_double = PyGLM_Number_AsFloat(value1);
//			float value2_as_double = PyGLM_Number_AsFloat(value2);
//			float value3_as_double = PyGLM_Number_AsFloat(value3);
//
//			*out = malloc(sizeof(glm::vec4));
//			*((glm::vec4*)*out) = glm::vec4(value0_as_double, value1_as_double, value2_as_double, value3_as_double);
//
//
//			Py_DECREF(value0);
//			Py_DECREF(value1);
//			Py_DECREF(value2);
//			Py_DECREF(value3);
//
//			return PyGLM_TYPE_VEC4;
//		}
//	}
//
//	return PyGLM_TYPE_NONE;
//}

// type checkers
#pragma region type checkers
bool PyGLM_Vec2i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 2 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 1))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 2) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);
	PyObject* value1 = PyIter_Next(iterator);

	Py_DECREF(iterator);

	if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1)) {
		Py_DECREF(value0);
		Py_DECREF(value1);

		return false;
	}
	Py_DECREF(value0);
	Py_DECREF(value1);

	return true;
}

bool PyGLM_Vec3i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 3 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 1)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 2))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 3) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);
	PyObject* value1 = PyIter_Next(iterator);
	PyObject* value2 = PyIter_Next(iterator);


	Py_DECREF(iterator);


	if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2)) {

		Py_DECREF(value0);
		Py_DECREF(value1);
		Py_DECREF(value2);

		return false;
	}
	Py_DECREF(value0);
	Py_DECREF(value1);
	Py_DECREF(value2);

	return true;
}

bool PyGLM_Vec4i_Check(PyObject* o) {
	if (!PyObject_IterCheck(o)) {
		return false;
	}
	if (PyTuple_Check(o)) {
		if (Py_SIZE(o) == 4 && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 0)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 1)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 2)) && PyGLM_Number_Check(PyTuple_GET_ITEM(o, 3))) {
			return true;
		}
		return false;
	}
	if (PyObject_Length(o) != 4) {
		return false;
	}

	PyObject* iterator = PyObject_GetIter(o);

	PyObject* value0 = PyIter_Next(iterator);
	PyObject* value1 = PyIter_Next(iterator);
	PyObject* value2 = PyIter_Next(iterator);
	PyObject* value3 = PyIter_Next(iterator);


	Py_DECREF(iterator);


	if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2) || value3 == NULL || !PyGLM_Number_Check(value3)) {

		Py_DECREF(value0);
		Py_DECREF(value1);
		Py_DECREF(value2);
		Py_DECREF(value3);

		return false;
	}
	Py_DECREF(value0);
	Py_DECREF(value1);
	Py_DECREF(value2);
	Py_DECREF(value3);

	return true;
}

#define PyGLM_Vec2_Check(o) (PyObject_TypeCheck(o, &vec2Type) || Py_TYPE(o) == &mvec2Type || (!(PyObject_TypeCheck(o, &mat2x2Type) || PyObject_TypeCheck(o, &mat3x2Type) || PyObject_TypeCheck(o, &mat4x2Type)) && PyGLM_Vec2i_Check(o)))
#define PyGLM_Vec3_Check(o) (PyObject_TypeCheck(o, &vec3Type) || Py_TYPE(o) == &mvec3Type || (!(PyObject_TypeCheck(o, &mat2x3Type) || PyObject_TypeCheck(o, &mat3x3Type) || PyObject_TypeCheck(o, &mat4x3Type)) && PyGLM_Vec3i_Check(o)))
#define PyGLM_Vec4_Check(o) (PyObject_TypeCheck(o, &vec4Type) || Py_TYPE(o) == &mvec4Type || (!(PyObject_TypeCheck(o, &mat2x4Type) || PyObject_TypeCheck(o, &mat3x4Type) || PyObject_TypeCheck(o, &mat4x4Type)) && PyGLM_Vec4i_Check(o)))

#define PyGLM_Vec_GetTypeCheck(o) (PyGLM_Vec2_Check(o)) ? PyGLM_TYPE_VEC2 : (PyGLM_Vec3_Check(o)) ? PyGLM_TYPE_VEC3 : (PyGLM_Vec4_Check(o)) ? PyGLM_TYPE_VEC4 : PyGLM_TYPE_NONE

#define PyGLM_Vec_GetType PyGLM_Vec_GetTypeCheck

#define PyGLM_Quat_Check(o) (PyObject_TypeCheck(o, &quatType))

#define PyGLM_Mat_GetType(o)  (PyObject_TypeCheck(o, &mat2x2Type)) ? PyGLM_TYPE_MAT2x2 : \
	(PyObject_TypeCheck(o, &mat3x3Type)) ? PyGLM_TYPE_MAT3x3 : \
	(PyObject_TypeCheck(o, &mat4x4Type)) ? PyGLM_TYPE_MAT4x4 : \
	(PyObject_TypeCheck(o, &mat2x3Type)) ? PyGLM_TYPE_MAT2x3 : \
	(PyObject_TypeCheck(o, &mat2x4Type)) ? PyGLM_TYPE_MAT2x4 : \
	(PyObject_TypeCheck(o, &mat3x2Type)) ? PyGLM_TYPE_MAT3x2 : \
	(PyObject_TypeCheck(o, &mat3x4Type)) ? PyGLM_TYPE_MAT3x4 : \
	(PyObject_TypeCheck(o, &mat4x2Type)) ? PyGLM_TYPE_MAT4x2 : \
	(PyObject_TypeCheck(o, &mat4x3Type)) ? PyGLM_TYPE_MAT4x3 : \
	PyGLM_TYPE_NONE

#define PyGLM_Mat2x2_Check(o) PyObject_TypeCheck(o, &mat2x2Type)
#define PyGLM_Mat2x3_Check(o) PyObject_TypeCheck(o, &mat2x3Type)
#define PyGLM_Mat2x4_Check(o) PyObject_TypeCheck(o, &mat2x4Type)
#define PyGLM_Mat3x2_Check(o) PyObject_TypeCheck(o, &mat3x2Type)
#define PyGLM_Mat3x3_Check(o) PyObject_TypeCheck(o, &mat3x3Type)
#define PyGLM_Mat3x4_Check(o) PyObject_TypeCheck(o, &mat3x4Type)
#define PyGLM_Mat4x2_Check(o) PyObject_TypeCheck(o, &mat4x2Type)
#define PyGLM_Mat4x3_Check(o) PyObject_TypeCheck(o, &mat4x3Type)
#define PyGLM_Mat4x4_Check(o) PyObject_TypeCheck(o, &mat4x4Type)
#pragma endregion

// unpackers
#pragma region unpackers
static bool unpack_vec2(PyObject* value, glm::vec2* out) {
	if (PyObject_TypeCheck(value, &vec2Type)) {
		*out = ((vec2*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == &mvec2Type) {
		*out = *((mvec2*)value)->super_type;
		return true;
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 2) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);
			PyObject* value1 = PyIter_Next(value_iter);

			
			Py_DECREF(value_iter);

			
			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1)) {
			
				Py_DECREF(value0);
				Py_DECREF(value1);

				return false;
			}
			
			float value0_as_double = PyGLM_Number_AsFloat(value0);
 			float value1_as_double = PyGLM_Number_AsFloat(value1);

			*out = glm::vec2(value0_as_double, value1_as_double);


			Py_DECREF(value0);
			Py_DECREF(value1);

			return true;
		}
	}
	return false;
}

static bool unpack_vec3(PyObject* value, glm::vec3* out) {
	if (PyObject_TypeCheck(value, &vec3Type)) {
		*out = ((vec3*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == &mvec3Type) {
		*out = *((mvec3*)value)->super_type;
		return true;
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 3) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);
			PyObject* value1 = PyIter_Next(value_iter);
			PyObject* value2 = PyIter_Next(value_iter);

			
			Py_DECREF(value_iter);

			
			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2)) {
			
				Py_DECREF(value0);
				Py_DECREF(value1);
				Py_DECREF(value2);

				return false;
			}
			
			float value0_as_double = PyGLM_Number_AsFloat(value0);
 			float value1_as_double = PyGLM_Number_AsFloat(value1);
 			float value2_as_double = PyGLM_Number_AsFloat(value2);

			*out = glm::vec3(value0_as_double, value1_as_double, value2_as_double);


			Py_DECREF(value0);
			Py_DECREF(value1);
			Py_DECREF(value2);

			return true;
		}
	}
	return false;
}

static bool unpack_vec4(PyObject* value, glm::vec4* out) {
	if (PyObject_TypeCheck(value, &vec4Type)) {
		*out = ((vec4*)value)->super_type;
		return true;
	}
	if (Py_TYPE(value) == &mvec4Type) {
		*out = *((mvec4*)value)->super_type;
		return true;
	}
	if (PyObject_IterCheck(value) && PyObject_Length(value) == 4) {
		PyObject* value_iter = PyObject_GetIter(value);
		if (value_iter != NULL) {
			PyObject* value0 = PyIter_Next(value_iter);
			PyObject* value1 = PyIter_Next(value_iter);
			PyObject* value2 = PyIter_Next(value_iter);
			PyObject* value3 = PyIter_Next(value_iter);

			
			Py_DECREF(value_iter);

			
			if (value0 == NULL || !PyGLM_Number_Check(value0) || value1 == NULL || !PyGLM_Number_Check(value1) || value2 == NULL || !PyGLM_Number_Check(value2) || value3 == NULL || !PyGLM_Number_Check(value3)) {
			
				Py_DECREF(value0);
				Py_DECREF(value1);
				Py_DECREF(value2);
				Py_DECREF(value3);

				return false;
			}
			
			float value0_as_double = PyGLM_Number_AsFloat(value0);
 			float value1_as_double = PyGLM_Number_AsFloat(value1);
 			float value2_as_double = PyGLM_Number_AsFloat(value2);
			float value3_as_double = PyGLM_Number_AsFloat(value3);

			*out = glm::vec4(value0_as_double, value1_as_double, value2_as_double, value3_as_double);


			Py_DECREF(value0);
			Py_DECREF(value1);
			Py_DECREF(value2);
			Py_DECREF(value3);

			return true;
		}
	}
	return false;
}

static char unpack_vec(PyObject* value, void** out) {
	char vec_type = PyGLM_Vec_GetType(value);
	bool success;
	switch(vec_type) {
	case PyGLM_TYPE_VEC2 :
		*out = malloc(sizeof(glm::vec2));
		success = unpack_vec2(value, (glm::vec2*)*out);
		if (success) return PyGLM_TYPE_VEC2;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_VEC3 : 
		*out = malloc(sizeof(glm::vec3));
		success = unpack_vec3(value, (glm::vec3*)*out);
		if (success) return PyGLM_TYPE_VEC3;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_VEC4 :
		*out = malloc(sizeof(glm::vec4));
		success = unpack_vec4(value, (glm::vec4*)*out);
		if (success) return PyGLM_TYPE_VEC4;
		free(*out);
		return PyGLM_TYPE_NONE;

	default :
		return PyGLM_TYPE_NONE;
	}
}

static bool unpack_quat(PyObject* value, glm::quat* out) {
	if (PyObject_TypeCheck(value, &quatType)) {
		*out = ((quat*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat2x2(PyObject* value, glm::mat2x2* out) {
	if (PyObject_TypeCheck(value, &mat2x2Type)) {
		*out = ((mat2x2*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat2x3(PyObject* value, glm::mat2x3* out) {
	if (PyObject_TypeCheck(value, &mat2x3Type)) {
		*out = ((mat2x3*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat2x4(PyObject* value, glm::mat2x4* out) {
	if (PyObject_TypeCheck(value, &mat2x4Type)) {
		*out = ((mat2x4*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat3x2(PyObject* value, glm::mat3x2* out) {
	if (PyObject_TypeCheck(value, &mat3x2Type)) {
		*out = ((mat3x2*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat3x3(PyObject* value, glm::mat3x3* out) {
	if (PyObject_TypeCheck(value, &mat3x3Type)) {
		*out = ((mat3x3*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat3x4(PyObject* value, glm::mat3x4* out) {
	if (PyObject_TypeCheck(value, &mat3x4Type)) {
		*out = ((mat3x4*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat4x2(PyObject* value, glm::mat4x2* out) {
	if (PyObject_TypeCheck(value, &mat4x2Type)) {
		*out = ((mat4x2*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat4x3(PyObject* value, glm::mat4x3* out) {
	if (PyObject_TypeCheck(value, &mat4x3Type)) {
		*out = ((mat4x3*)value)->super_type;
		return true;
	}
	return false;
}

static bool unpack_mat4x4(PyObject* value, glm::mat4x4* out) {
	if (PyObject_TypeCheck(value, &mat4x4Type)) {
		*out = ((mat4x4*)value)->super_type;
		return true;
	}
	return false;
}

static char unpack_mat(PyObject* value, void** out) {
	char mat_type = PyGLM_Mat_GetType(value);
	bool success;
	switch (mat_type) {
	case PyGLM_TYPE_MAT2x2:
		*out = malloc(sizeof(glm::mat2x2));
		success = unpack_mat2x2(value, (glm::mat2x2*)*out);
		if (success) return PyGLM_TYPE_MAT2x2;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT2x3:
		*out = malloc(sizeof(glm::mat2x3));
		success = unpack_mat2x3(value, (glm::mat2x3*)*out);
		if (success) return PyGLM_TYPE_MAT2x3;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT2x4:
		*out = malloc(sizeof(glm::mat2x4));
		success = unpack_mat2x4(value, (glm::mat2x4*)*out);
		if (success) return PyGLM_TYPE_MAT2x4;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT3x2:
		*out = malloc(sizeof(glm::mat3x2));
		success = unpack_mat3x2(value, (glm::mat3x2*)*out);
		if (success) return PyGLM_TYPE_MAT3x2;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT3x3:
		*out = malloc(sizeof(glm::mat3x3));
		success = unpack_mat3x3(value, (glm::mat3x3*)*out);
		if (success) return PyGLM_TYPE_MAT3x3;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT3x4:
		*out = malloc(sizeof(glm::mat3x4));
		success = unpack_mat3x4(value, (glm::mat3x4*)*out);
		if (success) return PyGLM_TYPE_MAT3x4;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT4x2:
		*out = malloc(sizeof(glm::mat4x2));
		success = unpack_mat4x2(value, (glm::mat4x2*)*out);
		if (success) return PyGLM_TYPE_MAT4x2;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT4x3:
		*out = malloc(sizeof(glm::mat4x3));
		success = unpack_mat4x3(value, (glm::mat4x3*)*out);
		if (success) return PyGLM_TYPE_MAT4x3;
		free(*out);
		return PyGLM_TYPE_NONE;

	case PyGLM_TYPE_MAT4x4:
		*out = malloc(sizeof(glm::mat4x4));
		success = unpack_mat4x4(value, (glm::mat4x4*)*out);
		if (success) return PyGLM_TYPE_MAT4x4;
		free(*out);
		return PyGLM_TYPE_NONE;

	default:
		return PyGLM_TYPE_NONE;
	}
}
#pragma endregion

// packers
#pragma region packers
static PyObject*
pack_vec2(glm::vec2 value) {
	vec2* out = (vec2*)vec2Type.tp_alloc(&vec2Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_vec3(glm::vec3 value) {
	vec3* out = (vec3*)vec3Type.tp_alloc(&vec3Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_vec4(glm::vec4 value) {
	vec4* out = (vec4*)vec4Type.tp_alloc(&vec4Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mvec2p(glm::vec2* value, PyObject* master) {
	mvec2* out = (mvec2*)mvec2Type.tp_alloc(&mvec2Type, 0);

	if (out != NULL) {
		out->super_type = value;
		Py_INCREF(master);
		out->master = master;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mvec3p(glm::vec3* value, PyObject* master) {
	mvec3* out = (mvec3*)mvec3Type.tp_alloc(&mvec3Type, 0);

	if (out != NULL) {
		out->super_type = value;
		Py_INCREF(master);
		out->master = master;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mvec4p(glm::vec4* value, PyObject* master) {
	mvec4* out = (mvec4*)mvec4Type.tp_alloc(&mvec4Type, 0);

	if (out != NULL) {
		out->super_type = value;
		Py_INCREF(master);
		out->master = master;
	}

	return (PyObject*)out;
}

static PyObject*
pack_quat(glm::quat value) {
	quat* out = (quat*)quatType.tp_alloc(&quatType, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat2x2(glm::mat2x2 value) {
	mat2x2* out = (mat2x2*)mat2x2Type.tp_alloc(&mat2x2Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat2x3(glm::mat2x3 value) {
	mat2x3* out = (mat2x3*)mat2x3Type.tp_alloc(&mat2x3Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat2x4(glm::mat2x4 value) {
	mat2x4* out = (mat2x4*)mat2x4Type.tp_alloc(&mat2x4Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat3x2(glm::mat3x2 value) {
	mat3x2* out = (mat3x2*)mat3x2Type.tp_alloc(&mat3x2Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat3x3(glm::mat3x3 value) {
	mat3x3* out = (mat3x3*)mat3x3Type.tp_alloc(&mat3x3Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat3x4(glm::mat3x4 value) {
	mat3x4* out = (mat3x4*)mat3x4Type.tp_alloc(&mat3x4Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat4x2(glm::mat4x2 value) {
	mat4x2* out = (mat4x2*)mat4x2Type.tp_alloc(&mat4x2Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat4x3(glm::mat4x3 value) {
	mat4x3* out = (mat4x3*)mat4x3Type.tp_alloc(&mat4x3Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

static PyObject*
pack_mat4x4(glm::mat4x4 value) {
	mat4x4* out = (mat4x4*)mat4x4Type.tp_alloc(&mat4x4Type, 0);

	if (out != NULL) {
		out->super_type = value;
	}

	return (PyObject*)out;
}

#pragma endregion

#pragma endregion

// TYPE DEFINITIONS

// type vec2
#pragma region type vec2
static void 
vec2_dealloc(vec2* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
vec2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	vec2 *self = (vec2 *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->super_type = glm::vec2();
	}

	return (PyObject *)self;
}

static int
vec2_init(vec2 *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OO", const_cast<char**>(kwlist),
		&arg1, &arg2)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				self->super_type = glm::vec2(PyGLM_Number_AsFloat(arg1));
				return 0;
			}

			void* o = NULL;
			char vecType = unpack_vec(arg1, &o);
			if (vecType == PyGLM_TYPE_VEC2) {
				self->super_type = *((glm::vec2*)o);
				free(o);
				return 0;
			}
			if (vecType == PyGLM_TYPE_VEC3) {
				self->super_type = *((glm::vec3*)o);
				free(o);
				return 0;
			}
			if (vecType == PyGLM_TYPE_VEC4) {
				self->super_type = *((glm::vec4*)o);
				free(o);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec2()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			self->super_type.x = PyGLM_Number_AsFloat(arg1);
			self->super_type.y = PyGLM_Number_AsFloat(arg2);
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec2()");
	return -1;
}

// unaryfunc
static PyObject *
vec2_neg(vec2 *obj)
{
	return pack_vec2(-obj->super_type);
}

static PyObject *
vec2_pos(vec2 *obj)
{
	return pack_vec2(obj->super_type);
}

static PyObject *
vec2_abs(vec2 *obj)
{
	return pack_vec2(glm::abs(obj->super_type));
}

// binaryfunc
static PyObject *
vec2_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) + (((vec2*)obj2)->super_type));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec2
	return pack_vec2(o + o2);
}

static PyObject *
vec2_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) - ((vec2*)obj2)->super_type);
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec2
	return pack_vec2(o - o2);
}

static PyObject *
vec2_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) * ((vec2*)obj2)->super_type);
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o * PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec2
	return pack_vec2(o * o2);
}

static PyObject *
vec2_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) / ((vec2*)obj2)->super_type);
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o / PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec2
	return  pack_vec2(o / o2);
}

static PyObject *
vec2_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(glm::mod(glm::vec2(PyGLM_Number_AsFloat(obj1)), ((vec2*)obj2)->super_type));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(glm::mod(o, glm::vec2(PyGLM_Number_AsFloat(obj2))));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec2
	return pack_vec2(glm::mod(o, o2));
}

static PyObject *
vec2_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(floor(PyGLM_Number_AsFloat(obj1) / ((vec2*)obj2)->super_type));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(floor(o / PyGLM_Number_AsFloat(obj2)));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec2
	return pack_vec2(floor(o / o2));
}

static PyObject *
vec2_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = vec2_floordiv(obj1, obj2);
	arg2 = vec2_mod(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

// ternaryfunc
static PyObject *
vec2_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		if (obj3 == Py_None) {
			return pack_vec2(glm::pow(glm::vec2(f), ((vec2*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec2(glm::mod(glm::pow(glm::vec2(f), ((vec2*)obj2)->super_type), glm::vec2(f2)));
		}

		glm::vec2 o3;

		if (!unpack_vec2(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec2(glm::mod(glm::pow(glm::vec2(f), ((vec2*)obj2)->super_type), o3));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm::vec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);

		if (obj3 == Py_None) {
			return pack_vec2(glm::pow(o, glm::vec2(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec2(glm::mod(glm::pow(o, glm::vec2(f)), glm::vec2(f2)));
		}

		glm::vec2 o3;

		if (!unpack_vec2(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec2(glm::mod(glm::pow(o, glm::vec2(f)), o3));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}



	// obj1 and obj2 can be interpreted as a vec2
	if (obj3 == Py_None) {
		return pack_vec2(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		float f2 = PyGLM_Number_AsFloat(obj3);
		return pack_vec2(glm::mod(glm::pow(o, o2), glm::vec2(f2)));
	}

	glm::vec2 o3;

	if (!unpack_vec2(obj3, &o3)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	return pack_vec2(glm::mod(glm::pow(o, o2), o3));
}

// inplace
// binaryfunc
static PyObject *
vec2_iadd(vec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)vec2_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec2_isub(vec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)vec2_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec2_imul(vec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)vec2_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec2_idiv(vec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)vec2_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec2_imod(vec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)vec2_mod((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec2_ifloordiv(vec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)vec2_floordiv((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
vec2_ipow(vec2 *self, PyObject *obj1, PyObject * obj2) // obj2 is unused. It points to an invalid address!
{
	vec2 * temp = (vec2*)vec2_pow((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}



static PyObject *
vec2_str(vec2* self)
{
	char * out = (char*)malloc((36) * sizeof(char));
	snprintf(out, 36, "vec2( %12.6g, %12.6g )", self->super_type.x, self->super_type.y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t vec2_len(vec2 * self) {
	return (Py_ssize_t)2;
}

static PyObject* vec2_sq_item(vec2 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type.x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type.y);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int vec2_sq_ass_item(vec2 * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int vec2_contains(vec2 * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type.x || f == self->super_type.y);
	}
	return 0;

}

static PyObject * vec2_richcompare(vec2 * self, PyObject * other, int comp_type) {
	glm::vec2 o2;

	if (!unpack_vec2(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec2(glm::lessThan(self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec2(glm::lessThanEqual(self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec2(glm::greaterThan(self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec2(glm::greaterThanEqual(self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

static bool unswizzle_vec2(vec2 * self, char c, float * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->super_type.x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->super_type.y;
		return true;
	}
	return false;
}

static PyObject * vec2_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')
		|| strcmp(name_as_ccp, "x") == 0 || strcmp(name_as_ccp, "y") == 0) {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		float x;
		if (unswizzle_vec2((vec2 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble((double)x);
		}
	}
	else if (len == 2) {
		float x;
		float y;
		if (unswizzle_vec2((vec2 *)obj, name_as_ccp[0], &x) && unswizzle_vec2((vec2 *)obj, name_as_ccp[1], &y)) {
			return pack_vec2(glm::vec2(x, y));
		}
	}
	else if (len == 3) {
		float x;
		float y;
		float z;
		if (unswizzle_vec2((vec2 *)obj, name_as_ccp[0], &x) && unswizzle_vec2((vec2 *)obj, name_as_ccp[1], &y) && unswizzle_vec2((vec2 *)obj, name_as_ccp[2], &z)) {
			return pack_vec3(glm::vec3(x, y, z));
		}
	}
	else if (len == 4) {
		float x;
		float y;
		float z;
		float w;
		if (unswizzle_vec2((vec2 *)obj, name_as_ccp[0], &x) && unswizzle_vec2((vec2 *)obj, name_as_ccp[1], &y) && unswizzle_vec2((vec2 *)obj, name_as_ccp[2], &z) && unswizzle_vec2((vec2 *)obj, name_as_ccp[3], &w)) {
			return pack_vec4(glm::vec4(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
vec2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	vec2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new vec2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	vec2Iter *rgstate = (vec2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
vec2Iter_dealloc(vec2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
vec2Iter_next(vec2Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.y);
		}
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * vec2_geniter(vec2 * self) {
	vec2Iter *rgstate = (vec2Iter *)((&vec2IterType)->tp_alloc(&vec2IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
vec2_getbuffer(vec2* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}
	
	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0];
	view->len = sizeof(glm::vec2);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 2;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
vec2_releasebuffer(vec2* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion 

// type vec3
#pragma region type vec3
static void
vec3_dealloc(vec3* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
vec3_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	vec3 *self = (vec3 *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->super_type = glm::vec3();
	}

	return (PyObject *)self;
}

static int
vec3_init(vec3 *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", "z", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOO", const_cast<char**>(kwlist),
		&arg1, &arg2, &arg3)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				self->super_type = glm::vec3(PyGLM_Number_AsFloat(arg1));
				return 0;
			}

			if (PyGLM_Vec3i_Check(arg1)) {
				glm::vec3 o;
				if (unpack_vec3(arg1, &o)) {
					self->super_type = o;
					return 0;
				}
			}
			else if (PyGLM_Vec4i_Check(arg1)) {
				glm::vec4 o;
				if (unpack_vec4(arg1, &o)) {
					self->super_type = o;
					return 0;
				}
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				glm::vec2 o;
				if (!unpack_vec2(arg2, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
					return -1;
				}
				self->super_type = glm::vec3(PyGLM_Number_AsFloat(arg1), o);
				return 0;
			}
			if (PyGLM_Number_Check(arg2)) {
				glm::vec2 o;
				if (!unpack_vec2(arg1, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
					return -1;
				}
				self->super_type = glm::vec3(o, PyGLM_Number_AsFloat(arg2));
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
			self->super_type = glm::vec3(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
	return -1;
}

// unaryfunc
static PyObject *
vec3_neg(vec3 *obj)
{
	return pack_vec3(-obj->super_type);
}

static PyObject *
vec3_pos(vec3 *obj)
{
	return pack_vec3(obj->super_type);
}

static PyObject *
vec3_abs(vec3 *obj)
{
	return pack_vec3(glm::abs(obj->super_type));
}

// binaryfunc
static PyObject *
vec3_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec3(f + (((vec3*)obj2)->super_type));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec3(o + f);
		return out;
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec3
	PyObject* out = pack_vec3(o + o2);
	return out;
}

static PyObject *
vec3_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec3(f - ((vec3*)obj2)->super_type);
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec3(o - f);
		return out;
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec3
	return pack_vec3(o - o2);
}

static PyObject *
vec3_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec3(f * ((vec3*)obj2)->super_type);
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		return pack_vec3(o * f);
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec3
	return pack_vec3(o * o2);
}

static PyObject *
vec3_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec3(f / ((vec3*)obj2)->super_type);
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec3(o / f);
		return out;
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec3
	PyObject* out = pack_vec3(o / o2);
	return out;
}

static PyObject *
vec3_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec3(glm::mod(glm::vec3(f), ((vec3*)obj2)->super_type));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec3(glm::mod(o, glm::vec3(f)));
		return out;
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec3
	return pack_vec3(glm::mod(o, o2));
}

static PyObject *
vec3_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec3(floor(f / ((vec3*)obj2)->super_type));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		return  pack_vec3(floor(o / f));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec3
	return pack_vec3(floor(o / o2));
}

static PyObject *
vec3_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = vec3_floordiv(obj1, obj2);
	arg2 = vec3_mod(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

// ternaryfunc
static PyObject *
vec3_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		if (obj3 == Py_None) {
			return pack_vec3(glm::pow(glm::vec3(f), ((vec3*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec3(glm::mod(glm::pow(glm::vec3(f), ((vec3*)obj2)->super_type), glm::vec3(f2)));
		}

		glm::vec3 o3;

		if (!unpack_vec3(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec3(glm::mod(glm::pow(glm::vec3(f), ((vec3*)obj2)->super_type), o3));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm::vec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);

		if (obj3 == Py_None) {
			return pack_vec3(glm::pow(o, glm::vec3(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec3(glm::mod(glm::pow(o, glm::vec3(f)), glm::vec3(f2)));
		}

		glm::vec3 o3;

		if (!unpack_vec3(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec3(glm::mod(glm::pow(o, glm::vec3(f)), o3));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}



	// obj1 and obj2 can be interpreted as a vec3
	if (obj3 == Py_None) {
		return pack_vec3(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		float f2 = PyGLM_Number_AsFloat(obj3);
		return pack_vec3(glm::mod(glm::pow(o, o2), glm::vec3(f2)));
	}

	glm::vec3 o3;

	if (!unpack_vec3(obj3, &o3)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	return pack_vec3(glm::mod(glm::pow(o, o2), o3));
}

// inplace
// binaryfunc
static PyObject *
vec3_iadd(vec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)vec3_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec3_isub(vec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)vec3_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec3_imul(vec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)vec3_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec3_idiv(vec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)vec3_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec3_imod(vec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)vec3_mod((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec3_ifloordiv(vec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)vec3_floordiv((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
vec3_ipow(vec3 *self, PyObject *obj1, PyObject * obj2) // obj2 is unused. It points to an invalid address!
{
	vec3 * temp = (vec3*)vec3_pow((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec3_str(vec3* self)
{
	char * out = (char*)malloc((50) * sizeof(char));
	snprintf(out, 50, "vec3( %12.6g, %12.6g, %12.6g )", self->super_type.x, self->super_type.y, self->super_type.z);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t vec3_len(vec3 * self) {
	return (Py_ssize_t)3;
}

static PyObject* vec3_sq_item(vec3 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type.x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type.y);
	case 2:
		return PyFloat_FromDouble((double)self->super_type.z);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int vec3_sq_ass_item(vec3 * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	case 2:
		self->super_type.z = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int vec3_contains(vec3 * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type.x || f == self->super_type.y || f == self->super_type.z);
	}
	return 0;

}

static PyObject * vec3_richcompare(vec3 * self, PyObject * other, int comp_type) {
	glm::vec3 o2;

	if (!unpack_vec3(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec3(glm::lessThan(self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec3(glm::lessThanEqual(self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec3(glm::greaterThan(self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec3(glm::greaterThanEqual(self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

static bool unswizzle_vec3(vec3 * self, char c, float * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->super_type.x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->super_type.y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		*out = self->super_type.z;
		return true;
	}
	return false;
}

static PyObject * vec3_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')
		|| strcmp(name_as_ccp, "x") == 0 || strcmp(name_as_ccp, "y") == 0 || strcmp(name_as_ccp, "z") == 0) {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		float x;
		if (unswizzle_vec3((vec3 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble((double)x);
		}
	}
	else if (len == 2) {
		float x;
		float y;
		if (unswizzle_vec3((vec3 *)obj, name_as_ccp[0], &x) && unswizzle_vec3((vec3 *)obj, name_as_ccp[1], &y)) {
			return pack_vec2(glm::vec2(x, y));
		}
	}
	else if (len == 3) {
		float x;
		float y;
		float z;
		if (unswizzle_vec3((vec3 *)obj, name_as_ccp[0], &x) && unswizzle_vec3((vec3 *)obj, name_as_ccp[1], &y) && unswizzle_vec3((vec3 *)obj, name_as_ccp[2], &z)) {
			return pack_vec3(glm::vec3(x, y, z));
		}
	}
	else if (len == 4) {
		float x;
		float y;
		float z;
		float w;
		if (unswizzle_vec3((vec3 *)obj, name_as_ccp[0], &x) && unswizzle_vec3((vec3 *)obj, name_as_ccp[1], &y) && unswizzle_vec3((vec3 *)obj, name_as_ccp[2], &z) && unswizzle_vec3((vec3 *)obj, name_as_ccp[3], &w)) {
			return pack_vec4(glm::vec4(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
vec3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	vec3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new vec3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	vec3Iter *rgstate = (vec3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
vec3Iter_dealloc(vec3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
vec3Iter_next(vec3Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.y);
		case 2:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * vec3_geniter(vec3 * self) {
	vec3Iter *rgstate = (vec3Iter *)((&vec3IterType)->tp_alloc(&vec3IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
vec3_getbuffer(vec3* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0];
	view->len = sizeof(glm::vec3);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 3;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
vec3_releasebuffer(vec3* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion 

// type vec4
#pragma region type vec4
static void
vec4_dealloc(vec4* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
vec4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	vec4 *self = (vec4 *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->super_type = glm::vec4();
	}

	return (PyObject *)self;
}

static int
vec4_init(vec4 *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", "z", "w", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;
	PyObject * arg4 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOOO", const_cast<char**>(kwlist),
		&arg1, &arg2, &arg3, &arg4)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				self->super_type = glm::vec4(PyGLM_Number_AsFloat(arg1));
				return 0;
			}

			glm::vec4 o;

			if (unpack_vec4(arg1, &o)) {
				self->super_type = o;
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				glm::vec3 o;
				if (!unpack_vec3(arg2, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
					return -1;
				}
				self->super_type = glm::vec4(PyGLM_Number_AsFloat(arg1), o);
				return 0;
			}
			if (PyGLM_Number_Check(arg2)) {
				glm::vec3 o;
				if (!unpack_vec3(arg1, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
					return -1;
				}
				self->super_type = glm::vec4(o, PyGLM_Number_AsFloat(arg2));
				return 0;
			}
			glm::vec2 o;
			if (!unpack_vec2(arg1, &o)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
				return -1;
			}
			glm::vec2 o2;
			if (!unpack_vec2(arg2, &o2)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
				return -1;
			}
			self->super_type = glm::vec4(o, o2);
			return 0;
		}
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				if (PyGLM_Number_Check(arg2)) {
					glm::vec2 o;
					if (!unpack_vec2(arg3, &o)) {
						PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
						return -1;
					}
					self->super_type = glm::vec4(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), o);
					return 0;
				}
				if (PyGLM_Number_Check(arg3)) {
					glm::vec2 o;
					if (!unpack_vec2(arg2, &o)) {
						PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
						return -1;
					}
					self->super_type = glm::vec4(PyGLM_Number_AsFloat(arg1), o, PyGLM_Number_AsFloat(arg3));
					return 0;
				}
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
				return -1;
			}
			if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				glm::vec2 o;
				if (!unpack_vec2(arg1, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
					return -1;
				}
				self->super_type = glm::vec4(o, PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3));
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
			self->super_type = glm::vec4(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
	return -1;
}

// unaryfunc
static PyObject *
vec4_neg(vec4 *obj)
{
	return pack_vec4(-obj->super_type);
}

static PyObject *
vec4_pos(vec4 *obj)
{
	return pack_vec4(obj->super_type);
}

static PyObject *
vec4_abs(vec4 *obj)
{
	return pack_vec4(glm::abs(obj->super_type));
}

// binaryfunc
static PyObject *
vec4_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(f + (((vec4*)obj2)->super_type));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec4(o + f);
		return out;
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec4
	PyObject* out = pack_vec4(o + o2);
	return out;
}

static PyObject *
vec4_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(f - ((vec4*)obj2)->super_type);
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec4(o - f);
		return out;
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec4
	return pack_vec4(o - o2);
}

static PyObject *
vec4_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(f * ((vec4*)obj2)->super_type);
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		return pack_vec4(o * f);
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec4
	return pack_vec4(o * o2);
}

static PyObject *
vec4_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(f / ((vec4*)obj2)->super_type);
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec4(o / f);
		return out;
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec4
	PyObject* out = pack_vec4(o / o2);
	return out;
}

static PyObject *
vec4_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(glm::mod(glm::vec4(f), ((vec4*)obj2)->super_type));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec4(glm::mod(o, glm::vec4(f)));
		return out;
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec4
	return pack_vec4(glm::mod(o, o2));
}

static PyObject *
vec4_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(floor(f / ((vec4*)obj2)->super_type));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		return  pack_vec4(floor(o / f));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a vec4
	return pack_vec4(floor(o / o2));
}

static PyObject *
vec4_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = vec4_floordiv(obj1, obj2);
	arg2 = vec4_mod(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

// ternaryfunc
static PyObject *
vec4_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		if (obj3 == Py_None) {
			return pack_vec4(glm::pow(glm::vec4(f), ((vec4*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec4(glm::mod(glm::pow(glm::vec4(f), ((vec4*)obj2)->super_type), glm::vec4(f2)));
		}

		glm::vec4 o3;

		if (!unpack_vec4(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec4(glm::mod(glm::pow(glm::vec4(f), ((vec4*)obj2)->super_type), o3));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm::vec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);

		if (obj3 == Py_None) {
			return pack_vec4(glm::pow(o, glm::vec4(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec4(glm::mod(glm::pow(o, glm::vec4(f)), glm::vec4(f2)));
		}

		glm::vec4 o3;

		if (!unpack_vec4(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec4(glm::mod(glm::pow(o, glm::vec4(f)), o3));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}



	// obj1 and obj2 can be interpreted as a vec4
	if (obj3 == Py_None) {
		return pack_vec4(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		float f2 = PyGLM_Number_AsFloat(obj3);
		return pack_vec4(glm::mod(glm::pow(o, o2), glm::vec4(f2)));
	}

	glm::vec4 o3;

	if (!unpack_vec4(obj3, &o3)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	return pack_vec4(glm::mod(glm::pow(o, o2), o3));
}

// inplace
// binaryfunc
static PyObject *
vec4_iadd(vec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)vec4_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec4_isub(vec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)vec4_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec4_imul(vec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)vec4_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec4_idiv(vec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)vec4_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec4_imod(vec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)vec4_mod((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec4_ifloordiv(vec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)vec4_floordiv((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
vec4_ipow(vec4 *self, PyObject *obj1, PyObject * obj2) // obj2 is unused. It points to an invalid address!
{
	vec4 * temp = (vec4*)vec4_pow((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
vec4_str(vec4* self)
{
	char * out = (char*)malloc((64) * sizeof(char));
	snprintf(out, 64, "vec4( %12.6g, %12.6g, %12.6g, %12.6g )", self->super_type.x, self->super_type.y, self->super_type.z, self->super_type.w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t vec4_len(vec4 * self) {
	return (Py_ssize_t)4;
}

static PyObject* vec4_sq_item(vec4 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type.x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type.y);
	case 2:
		return PyFloat_FromDouble((double)self->super_type.z);
	case 3:
		return PyFloat_FromDouble((double)self->super_type.w);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int vec4_sq_ass_item(vec4 * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	case 2:
		self->super_type.z = f;
		return 0;
	case 3:
		self->super_type.w = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int vec4_contains(vec4 * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type.x || f == self->super_type.y || f == self->super_type.z || f == self->super_type.w);
	}
	return 0;

}

static PyObject * vec4_richcompare(vec4 * self, PyObject * other, int comp_type) {
	glm::vec4 o2;

	if (!unpack_vec4(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec4(glm::lessThan(self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec4(glm::lessThanEqual(self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec4(glm::greaterThan(self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec4(glm::greaterThanEqual(self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

static bool unswizzle_vec4(vec4 * self, char c, float * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->super_type.x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->super_type.y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		*out = self->super_type.z;
		return true;
	}
	if (c == 'w' || c == 'a' || c == 'p') {
		*out = self->super_type.w;
		return true;
	}
	return false;
}

static PyObject * vec4_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')
		|| strcmp(name_as_ccp, "x") == 0 || strcmp(name_as_ccp, "y") == 0 || strcmp(name_as_ccp, "z") == 0 || strcmp(name_as_ccp, "w") == 0) {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		float x;
		if (unswizzle_vec4((vec4 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble((double)x);
		}
	}
	else if (len == 2) {
		float x;
		float y;
		if (unswizzle_vec4((vec4 *)obj, name_as_ccp[0], &x) && unswizzle_vec4((vec4 *)obj, name_as_ccp[1], &y)) {
			return pack_vec2(glm::vec2(x, y));
		}
	}
	else if (len == 3) {
		float x;
		float y;
		float z;
		if (unswizzle_vec4((vec4 *)obj, name_as_ccp[0], &x) && unswizzle_vec4((vec4 *)obj, name_as_ccp[1], &y) && unswizzle_vec4((vec4 *)obj, name_as_ccp[2], &z)) {
			return pack_vec3(glm::vec3(x, y, z));
		}
	}
	else if (len == 4) {
		float x;
		float y;
		float z;
		float w;
		if (unswizzle_vec4((vec4 *)obj, name_as_ccp[0], &x) && unswizzle_vec4((vec4 *)obj, name_as_ccp[1], &y) && unswizzle_vec4((vec4 *)obj, name_as_ccp[2], &z) && unswizzle_vec4((vec4 *)obj, name_as_ccp[3], &w)) {
			return pack_vec4(glm::vec4(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
vec4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	vec4 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new vec4Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	vec4Iter *rgstate = (vec4Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
vec4Iter_dealloc(vec4Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
vec4Iter_next(vec4Iter *rgstate)
{
	if (rgstate->seq_index < 4) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.y);
		case 2:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.z);
		case 3:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.w);
		}
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * vec4_geniter(vec4 * self) {
	vec4Iter *rgstate = (vec4Iter *)((&vec4IterType)->tp_alloc(&vec4IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
vec4_getbuffer(vec4* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0];
	view->len = sizeof(glm::vec4);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 4;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
vec4_releasebuffer(vec4* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion

// type mvec2
#pragma region type mvec2
static void
mvec2_dealloc(mvec2* self)
{
	Py_DECREF(self->master);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

// unaryfunc
static PyObject *
mvec2_neg(mvec2 *obj)
{
	return pack_vec2(-*obj->super_type);
}

static PyObject *
mvec2_pos(mvec2 *obj)
{
	return pack_vec2(*obj->super_type);
}

static PyObject *
mvec2_abs(mvec2 *obj)
{
	return pack_vec2(glm::abs(*obj->super_type));
}

// binaryfunc
static PyObject *
mvec2_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) + *(((mvec2*)obj2)->super_type));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec2
	return pack_vec2(o + o2);
}

static PyObject *
mvec2_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) - *((mvec2*)obj2)->super_type);
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec2
	return pack_vec2(o - o2);
}

static PyObject *
mvec2_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) * *((mvec2*)obj2)->super_type);
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o * PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec2
	return pack_vec2(o * o2);
}

static PyObject *
mvec2_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(PyGLM_Number_AsFloat(obj1) / *((mvec2*)obj2)->super_type);
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(o / PyGLM_Number_AsFloat(obj2));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec2
	return  pack_vec2(o / o2);
}

static PyObject *
mvec2_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(glm::mod(glm::vec2(PyGLM_Number_AsFloat(obj1)), *((mvec2*)obj2)->super_type));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(glm::mod(o, glm::vec2(PyGLM_Number_AsFloat(obj2))));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec2
	return pack_vec2(glm::mod(o, o2));
}

static PyObject *
mvec2_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec2(floor(PyGLM_Number_AsFloat(obj1) / *((mvec2*)obj2)->super_type));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec2(floor(o / PyGLM_Number_AsFloat(obj2)));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec2
	return pack_vec2(floor(o / o2));
}

static PyObject *
mvec2_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = mvec2_floordiv(obj1, obj2);
	arg2 = mvec2_mod(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

// ternaryfunc
static PyObject *
mvec2_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		if (obj3 == Py_None) {
			return pack_vec2(glm::pow(glm::vec2(f), *((mvec2*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec2(glm::mod(glm::pow(glm::vec2(f), *((mvec2*)obj2)->super_type), glm::vec2(f2)));
		}

		glm::vec2 o3;

		if (!unpack_vec2(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec2(glm::mod(glm::pow(glm::vec2(f), *((mvec2*)obj2)->super_type), o3));
	}

	glm::vec2 o;

	if (!unpack_vec2(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm::mvec2' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);

		if (obj3 == Py_None) {
			return pack_vec2(glm::pow(o, glm::vec2(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec2(glm::mod(glm::pow(o, glm::vec2(f)), glm::vec2(f2)));
		}

		glm::vec2 o3;

		if (!unpack_vec2(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec2(glm::mod(glm::pow(o, glm::vec2(f)), o3));
	}

	glm::vec2 o2;

	if (!unpack_vec2(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}



	// obj1 and obj2 can be interpreted as a mvec2
	if (obj3 == Py_None) {
		return pack_vec2(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		float f2 = PyGLM_Number_AsFloat(obj3);
		return pack_vec2(glm::mod(glm::pow(o, o2), glm::vec2(f2)));
	}

	glm::vec2 o3;

	if (!unpack_vec2(obj3, &o3)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	return pack_vec2(glm::mod(glm::pow(o, o2), o3));
}

// inplace
// binaryfunc
static PyObject *
mvec2_iadd(mvec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)mvec2_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec2_isub(mvec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)mvec2_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec2_imul(mvec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)mvec2_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec2_idiv(mvec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)mvec2_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec2_imod(mvec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)mvec2_mod((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec2_ifloordiv(mvec2 *self, PyObject *obj)
{
	vec2 * temp = (vec2*)mvec2_floordiv((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
mvec2_ipow(mvec2 *self, PyObject *obj1, PyObject * obj2) // obj2 is unused. It points to an invalid address!
{
	vec2 * temp = (vec2*)mvec2_pow((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec2_str(mvec2* self)
{
	char * out = (char*)malloc((36) * sizeof(char));
	snprintf(out, 36, "mvec2( %12.6g, %12.6g )", self->super_type->x, self->super_type->y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mvec2_len(mvec2 * self) {
	return (Py_ssize_t)2;
}

static PyObject* mvec2_sq_item(mvec2 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type->x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type->y);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int mvec2_sq_ass_item(mvec2 * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type->x = f;
		return 0;
	case 1:
		self->super_type->y = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int mvec2_contains(mvec2 * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type->x || f == self->super_type->y);
	}
	return 0;

}

static PyObject * mvec2_richcompare(mvec2 * self, PyObject * other, int comp_type) {
	glm::vec2 o2;

	if (!unpack_vec2(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (*self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (*self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec2(glm::lessThan(*self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec2(glm::lessThanEqual(*self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec2(glm::greaterThan(*self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec2(glm::greaterThanEqual(*self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

static bool unswizzle_mvec2(mvec2 * self, char c, float * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->super_type->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->super_type->y;
		return true;
	}
	return false;
}

static int mvec2_setattr(mvec2* obj, PyObject* name, PyObject* value) {
	const char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);
	if (!PyGLM_Number_Check(value) || len != 1) {
		return PyObject_GenericSetAttr((PyObject*)obj, name, value);
	}
	if (name_as_ccp[0] == 'x') {
		obj->super_type->x = PyGLM_Number_AsFloat(value);
		return 0;
	}
	if (name_as_ccp[1] == 'y') {
		obj->super_type->y = PyGLM_Number_AsFloat(value);
		return 0;
	}
	return PyObject_GenericSetAttr((PyObject*)obj, name, value);
}

static PyObject * mvec2_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')) {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		float x;
		if (unswizzle_mvec2((mvec2 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble((double)x);
		}
	}
	else if (len == 2) {
		float x;
		float y;
		if (unswizzle_mvec2((mvec2 *)obj, name_as_ccp[0], &x) && unswizzle_mvec2((mvec2 *)obj, name_as_ccp[1], &y)) {
			return pack_vec2(glm::vec2(x, y));
		}
	}
	else if (len == 3) {
		float x;
		float y;
		float z;
		if (unswizzle_mvec2((mvec2 *)obj, name_as_ccp[0], &x) && unswizzle_mvec2((mvec2 *)obj, name_as_ccp[1], &y) && unswizzle_mvec2((mvec2 *)obj, name_as_ccp[2], &z)) {
			return pack_vec3(glm::vec3(x, y, z));
		}
	}
	else if (len == 4) {
		float x;
		float y;
		float z;
		float w;
		if (unswizzle_mvec2((mvec2 *)obj, name_as_ccp[0], &x) && unswizzle_mvec2((mvec2 *)obj, name_as_ccp[1], &y) && unswizzle_mvec2((mvec2 *)obj, name_as_ccp[2], &z) && unswizzle_mvec2((mvec2 *)obj, name_as_ccp[3], &w)) {
			return pack_vec4(glm::vec4(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
mvec2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mvec2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mvec2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mvec2Iter *rgstate = (mvec2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mvec2Iter_dealloc(mvec2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mvec2Iter_next(mvec2Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->y);
		}
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mvec2_geniter(mvec2 * self) {
	mvec2Iter *rgstate = (mvec2Iter *)((&mvec2IterType)->tp_alloc(&mvec2IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mvec2_getbuffer(mvec2* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)self->super_type;
	view->len = sizeof(glm::vec2);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 2;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mvec2_releasebuffer(mvec2* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion 

// type mvec3
#pragma region type mvec3
static void
mvec3_dealloc(mvec3* self)
{
	Py_DECREF(self->master);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

// unaryfunc
static PyObject *
mvec3_neg(mvec3 *obj)
{
	return pack_vec3(-*obj->super_type);
}

static PyObject *
mvec3_pos(mvec3 *obj)
{
	return pack_vec3(*obj->super_type);
}

static PyObject *
mvec3_abs(mvec3 *obj)
{
	return pack_vec3(glm::abs(*obj->super_type));
}

// binaryfunc
static PyObject *
mvec3_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec3(PyGLM_Number_AsFloat(obj1) + *(((mvec3*)obj2)->super_type));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec3(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec3
	return pack_vec3(o + o2);
}

static PyObject *
mvec3_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec3(PyGLM_Number_AsFloat(obj1) - *((mvec3*)obj2)->super_type);
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec3(o - f);
		return out;
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec3
	return pack_vec3(o - o2);
}

static PyObject *
mvec3_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec3(PyGLM_Number_AsFloat(obj1) * *((mvec3*)obj2)->super_type);
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec3(o * PyGLM_Number_AsFloat(obj2));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec3
	return pack_vec3(o * o2);
}

static PyObject *
mvec3_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec3(PyGLM_Number_AsFloat(obj1) / *((mvec3*)obj2)->super_type);
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec3(o / PyGLM_Number_AsFloat(obj2));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec3
	return pack_vec3(o / o2);
}

static PyObject *
mvec3_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec3(glm::mod(glm::vec3(PyGLM_Number_AsFloat(obj1)), *((mvec3*)obj2)->super_type));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec3(glm::mod(o, glm::vec3(PyGLM_Number_AsFloat(obj2))));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec3
	return pack_vec3(glm::mod(o, o2));
}

static PyObject *
mvec3_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec3(floor(PyGLM_Number_AsFloat(obj1) / *((mvec3*)obj2)->super_type));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec3(floor(o / PyGLM_Number_AsFloat(obj2)));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec3
	return pack_vec3(floor(o / o2));
}

static PyObject *
mvec3_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = mvec3_floordiv(obj1, obj2);
	arg2 = mvec3_mod(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

// ternaryfunc
static PyObject *
mvec3_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		if (obj3 == Py_None) {
			return pack_vec3(glm::pow(glm::vec3(f), *((mvec3*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec3(glm::mod(glm::pow(glm::vec3(f), *((mvec3*)obj2)->super_type), glm::vec3(f2)));
		}

		glm::vec3 o3;

		if (!unpack_vec3(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec3(glm::mod(glm::pow(glm::vec3(f), *((mvec3*)obj2)->super_type), o3));
	}

	glm::vec3 o;

	if (!unpack_vec3(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm::mvec3' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);

		if (obj3 == Py_None) {
			return pack_vec3(glm::pow(o, glm::vec3(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec3(glm::mod(glm::pow(o, glm::vec3(f)), glm::vec3(f2)));
		}

		glm::vec3 o3;

		if (!unpack_vec3(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec3(glm::mod(glm::pow(o, glm::vec3(f)), o3));
	}

	glm::vec3 o2;

	if (!unpack_vec3(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}



	// obj1 and obj2 can be interpreted as a mvec3
	if (obj3 == Py_None) {
		return pack_vec3(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		float f2 = PyGLM_Number_AsFloat(obj3);
		return pack_vec3(glm::mod(glm::pow(o, o2), glm::vec3(f2)));
	}

	glm::vec3 o3;

	if (!unpack_vec3(obj3, &o3)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	return pack_vec3(glm::mod(glm::pow(o, o2), o3));
}

// inplace
// binaryfunc
static PyObject *
mvec3_iadd(mvec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)mvec3_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec3_isub(mvec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)mvec3_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec3_imul(mvec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)mvec3_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec3_idiv(mvec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)mvec3_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec3_imod(mvec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)mvec3_mod((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec3_ifloordiv(mvec3 *self, PyObject *obj)
{
	vec3 * temp = (vec3*)mvec3_floordiv((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
mvec3_ipow(mvec3 *self, PyObject *obj1, PyObject * obj2) // obj2 is unused. It points to an invalid address!
{
	vec3 * temp = (vec3*)mvec3_pow((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec3_str(mvec3* self)
{
	char * out = (char*)malloc((50) * sizeof(char));
	snprintf(out, 50, "mvec3( %12.6g, %12.6g, %12.6g )", self->super_type->x, self->super_type->y, self->super_type->z);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mvec3_len(mvec3 * self) {
	return (Py_ssize_t)3;
}

static PyObject* mvec3_sq_item(mvec3 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type->x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type->y);
	case 2:
		return PyFloat_FromDouble((double)self->super_type->z);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int mvec3_sq_ass_item(mvec3 * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type->x = f;
		return 0;
	case 1:
		self->super_type->y = f;
		return 0;
	case 2:
		self->super_type->z = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int mvec3_contains(mvec3 * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type->x || f == self->super_type->y || f == self->super_type->z);
	}
	return 0;

}

static PyObject * mvec3_richcompare(mvec3 * self, PyObject * other, int comp_type) {
	glm::vec3 o2;

	if (!unpack_vec3(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (*self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (*self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec3(glm::lessThan(*self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec3(glm::lessThanEqual(*self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec3(glm::greaterThan(*self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec3(glm::greaterThanEqual(*self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

static bool unswizzle_mvec3(mvec3 * self, char c, float * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->super_type->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->super_type->y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		*out = self->super_type->z;
		return true;
	}
	return false;
}

static int mvec3_setattr(mvec3* obj, PyObject* name, PyObject* value) {
	const char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);
	if (!PyGLM_Number_Check(value) || len != 1) {
		return PyObject_GenericSetAttr((PyObject*)obj, name, value);
	}
	if (name_as_ccp[0] == 'x') {
		obj->super_type->x = PyGLM_Number_AsFloat(value);
		return 0;
	}
	if (name_as_ccp[1] == 'y') {
		obj->super_type->y = PyGLM_Number_AsFloat(value);
		return 0;
	}
	if (name_as_ccp[2] == 'z') {
		obj->super_type->z = PyGLM_Number_AsFloat(value);
		return 0;
	}
	return PyObject_GenericSetAttr((PyObject*)obj, name, value);
}

static PyObject * mvec3_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')) {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		float x;
		if (unswizzle_mvec3((mvec3 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble((double)x);
		}
	}
	else if (len == 2) {
		float x;
		float y;
		if (unswizzle_mvec3((mvec3 *)obj, name_as_ccp[0], &x) && unswizzle_mvec3((mvec3 *)obj, name_as_ccp[1], &y)) {
			return pack_vec2(glm::vec2(x, y));
		}
	}
	else if (len == 3) {
		float x;
		float y;
		float z;
		if (unswizzle_mvec3((mvec3 *)obj, name_as_ccp[0], &x) && unswizzle_mvec3((mvec3 *)obj, name_as_ccp[1], &y) && unswizzle_mvec3((mvec3 *)obj, name_as_ccp[2], &z)) {
			return pack_vec3(glm::vec3(x, y, z));
		}
	}
	else if (len == 4) {
		float x;
		float y;
		float z;
		float w;
		if (unswizzle_mvec3((mvec3 *)obj, name_as_ccp[0], &x) && unswizzle_mvec3((mvec3 *)obj, name_as_ccp[1], &y) && unswizzle_mvec3((mvec3 *)obj, name_as_ccp[2], &z) && unswizzle_mvec3((mvec3 *)obj, name_as_ccp[3], &w)) {
			return pack_vec4(glm::vec4(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
mvec3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mvec3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mvec3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mvec3Iter *rgstate = (mvec3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mvec3Iter_dealloc(mvec3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mvec3Iter_next(mvec3Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->y);
		case 2:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mvec3_geniter(mvec3 * self) {
	mvec3Iter *rgstate = (mvec3Iter *)((&mvec3IterType)->tp_alloc(&mvec3IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mvec3_getbuffer(mvec3* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)self->super_type;
	view->len = sizeof(glm::vec3);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 3;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mvec3_releasebuffer(mvec3* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion 

// type mvec4
#pragma region type mvec4
static void
mvec4_dealloc(mvec4* self)
{
	Py_DECREF(self->master);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

// unaryfunc
static PyObject *
mvec4_neg(mvec4 *obj)
{
	return pack_vec4(-*obj->super_type);
}

static PyObject *
mvec4_pos(mvec4 *obj)
{
	return pack_vec4(*obj->super_type);
}

static PyObject *
mvec4_abs(mvec4 *obj)
{
	return pack_vec4(glm::abs(*obj->super_type));
}

// binaryfunc
static PyObject *
mvec4_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec4(PyGLM_Number_AsFloat(obj1) + *(((mvec4*)obj2)->super_type));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec4(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec4
	return pack_vec4(o + o2);
}

static PyObject *
mvec4_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec4(PyGLM_Number_AsFloat(obj1) - *((mvec4*)obj2)->super_type);
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec4(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec4
	return pack_vec4(o - o2);
}

static PyObject *
mvec4_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec4(PyGLM_Number_AsFloat(obj1) * *((mvec4*)obj2)->super_type);
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec4(o * PyGLM_Number_AsFloat(obj2));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec4
	return pack_vec4(o * o2);
}

static PyObject *
mvec4_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec4(PyGLM_Number_AsFloat(obj1) / *((mvec4*)obj2)->super_type);
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec4(o / PyGLM_Number_AsFloat(obj2));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec4
	PyObject* out = pack_vec4(o / o2);
	return out;
}

static PyObject *
mvec4_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_vec4(glm::mod(glm::vec4(f), *((mvec4*)obj2)->super_type));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_vec4(glm::mod(o, glm::vec4(f)));
		return out;
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec4
	return pack_vec4(glm::mod(o, o2));
}

static PyObject *
mvec4_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec4(floor(PyGLM_Number_AsFloat(obj1) / *((mvec4*)obj2)->super_type));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return  pack_vec4(floor(o / PyGLM_Number_AsFloat(obj2)));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a mvec4
	return pack_vec4(floor(o / o2));
}

static PyObject *
mvec4_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = mvec4_floordiv(obj1, obj2);
	arg2 = mvec4_mod(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

// ternaryfunc
static PyObject *
mvec4_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		if (obj3 == Py_None) {
			return pack_vec4(glm::pow(glm::vec4(f), *((mvec4*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec4(glm::mod(glm::pow(glm::vec4(f), *((mvec4*)obj2)->super_type), glm::vec4(f2)));
		}

		glm::vec4 o3;

		if (!unpack_vec4(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec4(glm::mod(glm::pow(glm::vec4(f), *((mvec4*)obj2)->super_type), o3));
	}

	glm::vec4 o;

	if (!unpack_vec4(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm::mvec4' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);

		if (obj3 == Py_None) {
			return pack_vec4(glm::pow(o, glm::vec4(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			float f2 = PyGLM_Number_AsFloat(obj3);
			return pack_vec4(glm::mod(glm::pow(o, glm::vec4(f)), glm::vec4(f2)));
		}

		glm::vec4 o3;

		if (!unpack_vec4(obj3, &o3)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		return pack_vec4(glm::mod(glm::pow(o, glm::vec4(f)), o3));
	}

	glm::vec4 o2;

	if (!unpack_vec4(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}



	// obj1 and obj2 can be interpreted as a mvec4
	if (obj3 == Py_None) {
		return pack_vec4(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		float f2 = PyGLM_Number_AsFloat(obj3);
		return pack_vec4(glm::mod(glm::pow(o, o2), glm::vec4(f2)));
	}

	glm::vec4 o3;

	if (!unpack_vec4(obj3, &o3)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	return pack_vec4(glm::mod(glm::pow(o, o2), o3));
}

// inplace
// binaryfunc
static PyObject *
mvec4_iadd(mvec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)mvec4_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec4_isub(mvec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)mvec4_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec4_imul(mvec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)mvec4_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec4_idiv(mvec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)mvec4_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec4_imod(mvec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)mvec4_mod((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec4_ifloordiv(mvec4 *self, PyObject *obj)
{
	vec4 * temp = (vec4*)mvec4_floordiv((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
mvec4_ipow(mvec4 *self, PyObject *obj1, PyObject * obj2) // obj2 is unused. It points to an invalid address!
{
	vec4 * temp = (vec4*)mvec4_pow((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type =temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mvec4_str(mvec4* self)
{
	char * out = (char*)malloc((64) * sizeof(char));
	snprintf(out, 64, "mvec4( %12.6g, %12.6g, %12.6g, %12.6g )", self->super_type->x, self->super_type->y, self->super_type->z, self->super_type->w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mvec4_len(mvec4 * self) {
	return (Py_ssize_t)4;
}

static PyObject* mvec4_sq_item(mvec4 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type->x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type->y);
	case 2:
		return PyFloat_FromDouble((double)self->super_type->z);
	case 3:
		return PyFloat_FromDouble((double)self->super_type->w);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int mvec4_sq_ass_item(mvec4 * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type->x = f;
		return 0;
	case 1:
		self->super_type->y = f;
		return 0;
	case 2:
		self->super_type->z = f;
		return 0;
	case 3:
		self->super_type->w = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int mvec4_contains(mvec4 * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type->x || f == self->super_type->y || f == self->super_type->z || f == self->super_type->w);
	}
	return 0;

}

static PyObject * mvec4_richcompare(mvec4 * self, PyObject * other, int comp_type) {
	glm::vec4 o2;

	if (!unpack_vec4(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (*self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (*self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec4(glm::lessThan(*self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec4(glm::lessThanEqual(*self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec4(glm::greaterThan(*self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec4(glm::greaterThanEqual(*self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

static bool unswizzle_mvec4(mvec4 * self, char c, float * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->super_type->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->super_type->y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		*out = self->super_type->z;
		return true;
	}
	if (c == 'w' || c == 'a' || c == 'p') {
		*out = self->super_type->w;
		return true;
	}
	return false;
}

static int mvec4_setattr(mvec4* obj, PyObject* name, PyObject* value) {
	const char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);
	if (!PyGLM_Number_Check(value) || len != 1) {
		return PyObject_GenericSetAttr((PyObject*)obj, name, value);
	}
	if (name_as_ccp[0] == 'x') {
		obj->super_type->x = PyGLM_Number_AsFloat(value);
		return 0;
	}
	if (name_as_ccp[1] == 'y') {
		obj->super_type->y = PyGLM_Number_AsFloat(value);
		return 0;
	}
	if (name_as_ccp[2] == 'z') {
		obj->super_type->z = PyGLM_Number_AsFloat(value);
		return 0;
	}
	if (name_as_ccp[3] == 'w') {
		obj->super_type->w = PyGLM_Number_AsFloat(value);
		return 0;
	}
	return PyObject_GenericSetAttr((PyObject*)obj, name, value);
}

static PyObject * mvec4_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')) {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		float x;
		if (unswizzle_mvec4((mvec4 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble((double)x);
		}
	}
	else if (len == 2) {
		float x;
		float y;
		if (unswizzle_mvec4((mvec4 *)obj, name_as_ccp[0], &x) && unswizzle_mvec4((mvec4 *)obj, name_as_ccp[1], &y)) {
			return pack_vec2(glm::vec2(x, y));
		}
	}
	else if (len == 3) {
		float x;
		float y;
		float z;
		if (unswizzle_mvec4((mvec4 *)obj, name_as_ccp[0], &x) && unswizzle_mvec4((mvec4 *)obj, name_as_ccp[1], &y) && unswizzle_mvec4((mvec4 *)obj, name_as_ccp[2], &z)) {
			return pack_vec3(glm::vec3(x, y, z));
		}
	}
	else if (len == 4) {
		float x;
		float y;
		float z;
		float w;
		if (unswizzle_mvec4((mvec4 *)obj, name_as_ccp[0], &x) && unswizzle_mvec4((mvec4 *)obj, name_as_ccp[1], &y) && unswizzle_mvec4((mvec4 *)obj, name_as_ccp[2], &z) && unswizzle_mvec4((mvec4 *)obj, name_as_ccp[3], &w)) {
			return pack_vec4(glm::vec4(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
mvec4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mvec4 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mvec4Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mvec4Iter *rgstate = (mvec4Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mvec4Iter_dealloc(mvec4Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mvec4Iter_next(mvec4Iter *rgstate)
{
	if (rgstate->seq_index < 4) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->y);
		case 2:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->z);
		case 3:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type->w);
		}
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mvec4_geniter(mvec4 * self) {
	mvec4Iter *rgstate = (mvec4Iter *)((&mvec4IterType)->tp_alloc(&mvec4IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mvec4_getbuffer(mvec4* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)self->super_type;
	view->len = sizeof(glm::vec4);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 4;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mvec4_releasebuffer(mvec4* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion

// type mat2x2
#pragma region type mat2x2
static void
mat2x2_dealloc(mat2x2* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat2x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat2x2 *self;

	self = (mat2x2 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat2x2();
	}

	return (PyObject *)self;
}

static int
mat2x2_init(mat2x2 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;

	if (!PyArg_UnpackTuple(args, "mat2x2", 0, 4,
		&arg1, &arg2, &arg3, &arg4)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
		return -1;
	}
	
	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat2x2(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		glm::vec2 o;
		if (!unpack_vec2(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
			return -1;
		}
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
			return -1;
		}
		self->super_type = glm::mat2x2(o, o2);
		return 0;
	}

	if (arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
		self->super_type = glm::mat2x2(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
	return -1;
}

// unaryfunc
static PyObject *
mat2x2_neg(mat2x2 *obj)
{
	return pack_mat2x2(-obj->super_type);
}

static PyObject *
mat2x2_pos(mat2x2 *obj)
{
	return pack_mat2x2(+obj->super_type);
}

static PyObject *
mat2x2_abs(mat2x2 *obj)
{
	return pack_mat2x2(glm::mat2x2(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1])));
}

// binaryfunc
static PyObject *
mat2x2_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x2(PyGLM_Number_AsFloat(obj1) + ((mat2x2*)obj2)->super_type);
	}
		
	glm::mat2x2 o;

	if (!unpack_mat2x2(obj1, &o)) { // obj1 can't be interpreted as mat2x2
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat2x2'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x2(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat2x2 o2;

	if (!unpack_mat2x2(obj2, &o2)) { // obj2 can't be interpreted as mat2x2
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat2x2(o + o2);
}

static PyObject *
mat2x2_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x2(PyGLM_Number_AsFloat(obj1) - ((mat2x2*)obj2)->super_type);
	}

	glm::mat2x2 o;

	if (!unpack_mat2x2(obj1, &o)) { // obj1 can't be interpreted as mat2x2
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat2x2'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x2(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat2x2 o2;

	if (!unpack_mat2x2(obj2, &o2)) { // obj2 can't be interpreted as mat2x2
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat2x2(o - o2);
}

static PyObject *
mat2x2_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x2(PyGLM_Number_AsFloat(obj1) * ((mat2x2*)obj2)->super_type);
	}


	if (PyGLM_Vec2_Check(obj1)) { // obj1 is a col_type
		glm::vec2 o;
		unpack_vec2(obj1, &o);

		return pack_vec2(o * ((mat2x2*)obj2)->super_type);
	}

	glm::mat2x2 o;

	if (!unpack_mat2x2(obj1, &o)) { // obj1 can't be interpreted as mat2x2
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x2(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec2_Check(obj2)) { // obj2 is a row_type
		glm::vec2 o2;
		unpack_vec2(obj2, &o2);

		return pack_vec2(o * o2);
	}

	if (PyGLM_Mat2x2_Check(obj2)) { // obj2 is a mat2x2
		glm::mat2x2 o2;
		unpack_mat2x2(obj2, &o2);

		return pack_mat2x2(o * o2);
	}

	if (PyGLM_Mat3x2_Check(obj2)) {// obj2 is a mat3x2
		glm::mat3x2 o2;
		unpack_mat3x2(obj2, &o2);

		return pack_mat3x2(o * o2);
	}

	if (PyGLM_Mat4x2_Check(obj2)) {// obj2 is a mat4x2
		glm::mat4x2 o2;
		unpack_mat4x2(obj2, &o2);

		return pack_mat4x2(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat2x2_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x2(PyGLM_Number_AsFloat(obj1) / ((mat2x2*)obj2)->super_type);
	}

	if (PyGLM_Vec2_Check(obj1)) { // obj1 is a col_type
		glm::vec2 o;
		unpack_vec2(obj1, &o);

		return pack_vec2(o / ((mat2x2*)obj2)->super_type);
	}

	glm::mat2x2 o;

	if (!unpack_mat2x2(obj1, &o)) { // obj1 can't be interpreted as mat2x2
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x2(o / PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec2_Check(obj2)) { // obj2 is a row_type
		glm::vec2 o2;
		unpack_vec2(obj2, &o2);

		return pack_vec2(o / o2);
	}

	if (PyGLM_Mat2x2_Check(obj2)) { // obj2 is a mat2x2
		glm::mat2x2 o2;
		unpack_mat2x2(obj2, &o2);

		return pack_mat2x2(o / o2);
	}
	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat2x2_iadd(mat2x2 *self, PyObject *obj)
{
	mat2x2 * temp = (mat2x2*)mat2x2_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x2_isub(mat2x2 *self, PyObject *obj)
{
	mat2x2 * temp = (mat2x2*)mat2x2_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x2_imul(mat2x2 *self, PyObject *obj)
{
	mat2x2* temp = (mat2x2*)mat2x2_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat2x2Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x2_idiv(mat2x2 *self, PyObject *obj)
{
	mat2x2 * temp = (mat2x2*)mat2x2_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat2x2Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x2_repr(mat2x2* self)
{
	char * out = (char*)malloc((72) * sizeof(char));
	snprintf(out, 72, "mat2x2\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[1][0], self->super_type[1][1]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat2x2_str(mat2x2* self)
{
	char * out = (char*)malloc((64) * sizeof(char));
	snprintf(out, 64, "[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[1][0], self->super_type[1][1]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat2x2_len(mat2x2 * self) {
	return (Py_ssize_t)2;
}

static PyObject* mat2x2_length(mat2x2 * self, PyObject* arg) {
	return PyLong_FromLong(2);
}

static PyObject* mat2x2_sq_item(mat2x2 * self, Py_ssize_t index) {
	if (index < 0 || index > 1) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec2p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat2x2_sq_ass_item(mat2x2 * self, Py_ssize_t index, PyObject * value) {
	glm::vec2 o;
	if (!unpack_vec2(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec2, got ", value);
		return -1;
	}
	if (index < 0 || index > 1) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat2x2_mp_item(mat2x2 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec2p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat2x2_mp_ass_item(mat2x2 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec2 o;

		if (!unpack_vec2(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec2, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat2x2_contains(mat2x2 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[1][0] || d == self->super_type[1][1]);
	}
	glm::vec2 o;
	if (!unpack_vec2(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1]));
	return out;
}

static PyObject * mat2x2_richcompare(mat2x2 * self, PyObject * other, int comp_type) {
	glm::mat2x2 o2;

	if (!unpack_mat2x2(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat2x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat2x2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat2x2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat2x2Iter *rgstate = (mat2x2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat2x2Iter_dealloc(mat2x2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat2x2Iter_next(mat2x2Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		return pack_mvec2p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat2x2_geniter(mat2x2 * self) {
	mat2x2Iter *rgstate = (mat2x2Iter *)((&mat2x2IterType)->tp_alloc(&mat2x2IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat2x2_getbuffer(mat2x2* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat2x2);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2*sizeof(Py_ssize_t));
	view->shape[0] = 2;
	view->shape[1] = 2;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat2x2::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat2x2_releasebuffer(mat2x2* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat2x3
#pragma region type mat2x3
static void
mat2x3_dealloc(mat2x3* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat2x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat2x3 *self;

	self = (mat2x3 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat2x3();
	}

	return (PyObject *)self;
}

static int
mat2x3_init(mat2x3 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;

	if (!PyArg_UnpackTuple(args, "mat2x3", 0, 6,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat2x3(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = glm::mat2x3(*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = glm::mat2x3(*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = glm::mat2x3(*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = glm::mat2x3(*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = glm::mat2x3(*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = glm::mat2x3(*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = glm::mat2x3(*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = glm::mat2x3(*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = glm::mat2x3(*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		glm::vec3 o;
		if (!unpack_vec3(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
			return -1;
		}
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
			return -1;
		}
		self->super_type = glm::mat2x3(o, o2);
		return 0;
	}

	if (arg4 == NULL || arg5 == NULL || arg6 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) {
		self->super_type = glm::mat2x3(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
	return -1;
}

// unaryfunc
static PyObject *
mat2x3_neg(mat2x3 *obj)
{
	return pack_mat2x3(-obj->super_type);
}

static PyObject *
mat2x3_pos(mat2x3 *obj)
{
	return pack_mat2x3(+obj->super_type);
}

static PyObject *
mat2x3_abs(mat2x3 *obj)
{
	return pack_mat2x3(glm::mat2x3(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1])));
}

// binaryfunc
static PyObject *
mat2x3_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x3(((mat2x3*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat2x3 o;

	if (!unpack_mat2x3(obj1, &o)) { // obj1 can't be interpreted as mat2x3
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat2x3'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x3(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat2x3 o2;

	if (!unpack_mat2x3(obj2, &o2)) { // obj2 can't be interpreted as mat2x3
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat2x3(o + o2);
}

static PyObject *
mat2x3_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x3(glm::mat2x3(PyGLM_Number_AsFloat(obj1)) - ((mat2x3*)obj2)->super_type);
	}

	glm::mat2x3 o;

	if (!unpack_mat2x3(obj1, &o)) { // obj1 can't be interpreted as mat2x3
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat2x3'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x3(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat2x3 o2;

	if (!unpack_mat2x3(obj2, &o2)) { // obj2 can't be interpreted as mat2x3
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat2x3(o - o2);
}

static PyObject *
mat2x3_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x3(PyGLM_Number_AsFloat(obj1) * ((mat2x3*)obj2)->super_type);
	}




	if (PyGLM_Vec3_Check(obj1)) { // obj1 is a col_type
		glm::vec3 o;
		unpack_vec3(obj1, &o);

		return pack_vec2(o * ((mat2x3*)obj2)->super_type);
	}

	glm::mat2x3 o;

	if (!unpack_mat2x3(obj1, &o)) { // obj1 can't be interpreted as mat2x3
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x3(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec2_Check(obj2)) { // obj2 is a row_type
		glm::vec2 o2;
		unpack_vec2(obj2, &o2);

		return pack_vec3(o * o2);
	}

	if (PyGLM_Mat2x2_Check(obj2)) { // obj2 is a mat2x2
		glm::mat2x2 o2;
		unpack_mat2x2(obj2, &o2);

		return pack_mat2x3(o * o2);
	}

	if (PyGLM_Mat3x2_Check(obj2)) {// obj2 is a mat3x2
		glm::mat3x2 o2;
		unpack_mat3x2(obj2, &o2);

		return pack_mat3x3(o * o2);
	}

	if (PyGLM_Mat4x2_Check(obj2)) {// obj2 is a mat4x2
		glm::mat4x2 o2;
		unpack_mat4x2(obj2, &o2);

		return pack_mat4x3(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat2x3_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x3(PyGLM_Number_AsFloat(obj1) / ((mat2x3*)obj2)->super_type);
	}

	glm::mat2x3 o;

	if (!unpack_mat2x3(obj1, &o)) { // obj1 can't be interpreted as mat2x3
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x3(o / PyGLM_Number_AsFloat(obj2));
	}
	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat2x3_iadd(mat2x3 *self, PyObject *obj)
{
	mat2x3 * temp = (mat2x3*)mat2x3_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x3_isub(mat2x3 *self, PyObject *obj)
{
	mat2x3 * temp = (mat2x3*)mat2x3_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x3_imul(mat2x3 *self, PyObject *obj)
{
	mat2x3* temp = (mat2x3*)mat2x3_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat2x3Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x3_idiv(mat2x3 *self, PyObject *obj)
{
	mat2x3 * temp = (mat2x3*)mat2x3_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x3_repr(mat2x3* self)
{
	char * out = (char*)malloc((102) * sizeof(char));
	snprintf(out, 102, "mat2x3\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat2x3_str(mat2x3* self)
{
	char * out = (char*)malloc((94) * sizeof(char));
	snprintf(out, 94, "[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat2x3_len(mat2x3 * self) {
	return (Py_ssize_t)2;
}

static PyObject* mat2x3_length(mat2x3 * self, PyObject* arg) {
	return PyLong_FromLong(2);
}

static PyObject* mat2x3_sq_item(mat2x3 * self, Py_ssize_t index) {
	if (index < 0 || index > 1) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec3p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat2x3_sq_ass_item(mat2x3 * self, Py_ssize_t index, PyObject * value) {
	glm::vec3 o;
	if (!unpack_vec3(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec3, got ", value);
		return -1;
	}
	if (index < 0 || index > 1) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat2x3_mp_item(mat2x3 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec3p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat2x3_mp_ass_item(mat2x3 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec3 o;

		if (!unpack_vec3(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec3, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat2x3_contains(mat2x3 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[0][2] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[1][2]);
	}
	glm::vec3 o;
	if (!unpack_vec3(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1] && self->super_type[0][2] == o[2]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1] && self->super_type[1][2] == o[2]));
	return out;
}

static PyObject * mat2x3_richcompare(mat2x3 * self, PyObject * other, int comp_type) {
	glm::mat2x3 o2;

	if (!unpack_mat2x3(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat2x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat2x3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat2x3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat2x3Iter *rgstate = (mat2x3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat2x3Iter_dealloc(mat2x3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat2x3Iter_next(mat2x3Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		return pack_mvec3p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat2x3_geniter(mat2x3 * self) {
	mat2x3Iter *rgstate = (mat2x3Iter *)((&mat2x3IterType)->tp_alloc(&mat2x3IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat2x3_getbuffer(mat2x3* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat2x3);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 2;
	view->shape[1] = 3;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat2x3::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat2x3_releasebuffer(mat2x3* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat2x4
#pragma region type mat2x4
static void
mat2x4_dealloc(mat2x4* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat2x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat2x4 *self;

	self = (mat2x4 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat2x4();
	}

	return (PyObject *)self;
}

static int
mat2x4_init(mat2x4 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;

	if (!PyArg_UnpackTuple(args, "mat2x4", 0, 8,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat2x4(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = glm::mat2x4(*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = glm::mat2x4(*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = glm::mat2x4(*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = glm::mat2x4(*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = glm::mat2x4(*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = glm::mat2x4(*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = glm::mat2x4(*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = glm::mat2x4(*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = glm::mat2x4(*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		glm::vec4 o;
		if (!unpack_vec4(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
			return -1;
		}
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
			return -1;
		}
		self->super_type = glm::mat2x4(o, o2);
		return 0;
	}

	if (arg4 == NULL || arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8)) {
		self->super_type = glm::mat2x4(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6), PyGLM_Number_AsFloat(arg7), PyGLM_Number_AsFloat(arg8));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
	return -1;
}

// unaryfunc
static PyObject *
mat2x4_neg(mat2x4 *obj)
{
	return pack_mat2x4(-obj->super_type);
}

static PyObject *
mat2x4_pos(mat2x4 *obj)
{
	return pack_mat2x4(+obj->super_type);
}

static PyObject *
mat2x4_abs(mat2x4 *obj)
{
	return pack_mat2x4(glm::mat2x4(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1])));
}

// binaryfunc
static PyObject *
mat2x4_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x4(((mat2x4*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat2x4 o;

	if (!unpack_mat2x4(obj1, &o)) { // obj1 can't be interpreted as mat2x4
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat2x4'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x4(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat2x4 o2;

	if (!unpack_mat2x4(obj2, &o2)) { // obj2 can't be interpreted as mat2x4
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat2x4(o + o2);
}

static PyObject *
mat2x4_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x4(glm::mat2x4(PyGLM_Number_AsFloat(obj1)) - ((mat2x4*)obj2)->super_type);
	}

	glm::mat2x4 o;

	if (!unpack_mat2x4(obj1, &o)) { // obj1 can't be interpreted as mat2x4
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat2x4'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x4(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat2x4 o2;

	if (!unpack_mat2x4(obj2, &o2)) { // obj2 can't be interpreted as mat2x4
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat2x4(o - o2);
}

static PyObject *
mat2x4_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x4(PyGLM_Number_AsFloat(obj1) * ((mat2x4*)obj2)->super_type);
	}


	if (PyGLM_Vec4_Check(obj1)) { // obj1 is a col_type
		glm::vec4 o;
		unpack_vec4(obj1, &o);

		return pack_vec2(o * ((mat2x4*)obj2)->super_type);
	}

	glm::mat2x4 o;

	if (!unpack_mat2x4(obj1, &o)) { // obj1 can't be interpreted as mat2x4
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x4(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec2_Check(obj2)) { // obj2 is a row_type
		glm::vec2 o2;
		unpack_vec2(obj2, &o2);

		return pack_vec4(o * o2);
	}

	if (PyGLM_Mat2x2_Check(obj2)) { // obj2 is a mat2x2
		glm::mat2x2 o2;
		unpack_mat2x2(obj2, &o2);

		return pack_mat2x4(o * o2);
	}

	if (PyGLM_Mat3x2_Check(obj2)) {// obj2 is a mat3x2
		glm::mat3x2 o2;
		unpack_mat3x2(obj2, &o2);

		return pack_mat3x4(o * o2);
	}

	if (PyGLM_Mat4x2_Check(obj2)) {// obj2 is a mat4x2
		glm::mat4x2 o2;
		unpack_mat4x2(obj2, &o2);

		return pack_mat4x4(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat2x4_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat2x4(PyGLM_Number_AsFloat(obj1) / ((mat2x4*)obj2)->super_type);
	}

	glm::mat2x4 o;

	if (!unpack_mat2x4(obj1, &o)) { // obj1 can't be interpreted as mat2x4
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat2x4(o / PyGLM_Number_AsFloat(obj2));
	}
	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat2x4_iadd(mat2x4 *self, PyObject *obj)
{
	mat2x4 * temp = (mat2x4*)mat2x4_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x4_isub(mat2x4 *self, PyObject *obj)
{
	mat2x4 * temp = (mat2x4*)mat2x4_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x4_imul(mat2x4 *self, PyObject *obj)
{
	mat2x4* temp = (mat2x4*)mat2x4_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat2x4Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x4_idiv(mat2x4 *self, PyObject *obj)
{
	mat2x4 * temp = (mat2x4*)mat2x4_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat2x4_repr(mat2x4* self)
{
	char * out = (char*)malloc((132) * sizeof(char));
	snprintf(out, 132, "mat2x4\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[0][3], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[1][3]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat2x4_str(mat2x4* self)
{
	char * out = (char*)malloc((124) * sizeof(char));
	snprintf(out, 124, "[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[0][3], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[1][3]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat2x4_len(mat2x4 * self) {
	return (Py_ssize_t)2;
}

static PyObject* mat2x4_length(mat2x4 * self, PyObject* arg) {
	return PyLong_FromLong(2);
}

static PyObject* mat2x4_sq_item(mat2x4 * self, Py_ssize_t index) {
	if (index < 0 || index > 1) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec4p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat2x4_sq_ass_item(mat2x4 * self, Py_ssize_t index, PyObject * value) {
	glm::vec4 o;
	if (!unpack_vec4(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec4, got ", value);
		return -1;
	}
	if (index < 0 || index > 1) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat2x4_mp_item(mat2x4 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec4p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat2x4_mp_ass_item(mat2x4 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec4 o;

		if (!unpack_vec4(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec4, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat2x4_contains(mat2x4 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[0][2] || d == self->super_type[0][3] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[1][2] || d == self->super_type[1][3]);
	}
	glm::vec4 o;
	if (!unpack_vec4(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1] && self->super_type[0][2] == o[2] && self->super_type[0][3] == o[3]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1] && self->super_type[1][2] == o[2] && self->super_type[1][3] == o[3]));
	return out;
}

static PyObject * mat2x4_richcompare(mat2x4 * self, PyObject * other, int comp_type) {
	glm::mat2x4 o2;

	if (!unpack_mat2x4(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat2x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat2x4 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat2x4Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat2x4Iter *rgstate = (mat2x4Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat2x4Iter_dealloc(mat2x4Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat2x4Iter_next(mat2x4Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		return pack_mvec4p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat2x4_geniter(mat2x4 * self) {
	mat2x4Iter *rgstate = (mat2x4Iter *)((&mat2x4IterType)->tp_alloc(&mat2x4IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat2x4_getbuffer(mat2x4* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat2x4);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 2;
	view->shape[1] = 4;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat2x4::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat2x4_releasebuffer(mat2x4* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat3x2
#pragma region type mat3x2
static void
mat3x2_dealloc(mat3x2* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat3x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat3x2 *self;

	self = (mat3x2 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat3x2();
	}

	return (PyObject *)self;
}

static int
mat3x2_init(mat3x2 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;

	if (!PyArg_UnpackTuple(args, "mat3x2", 0, 6,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat3x2(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (arg4 == NULL) {
		glm::vec2 o;
		if (!unpack_vec2(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
			return -1;
		}
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
			return -1;
		}
		glm::vec2 o3;
		if (!unpack_vec2(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
			return -1;
		}
		self->super_type = glm::mat3x2(o, o2, o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) {
		self->super_type = glm::mat3x2(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
	return -1;
}

// unaryfunc
static PyObject *
mat3x2_neg(mat3x2 *obj)
{
	return pack_mat3x2(-obj->super_type);
}

static PyObject *
mat3x2_pos(mat3x2 *obj)
{
	return pack_mat3x2(+obj->super_type);
}

static PyObject *
mat3x2_abs(mat3x2 *obj)
{
	return pack_mat3x2(glm::mat3x2(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1]), glm::abs(obj->super_type[2])));
}

// binaryfunc
static PyObject *
mat3x2_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x2(((mat3x2*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat3x2 o;

	if (!unpack_mat3x2(obj1, &o)) { // obj1 can't be interpreted as mat3x2
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat3x2'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x2(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat3x2 o2;

	if (!unpack_mat3x2(obj2, &o2)) { // obj2 can't be interpreted as mat3x2
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat3x2(o + o2);
}

static PyObject *
mat3x2_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x2(glm::mat3x2(PyGLM_Number_AsFloat(obj1)) - ((mat3x2*)obj2)->super_type);
	}

	glm::mat3x2 o;

	if (!unpack_mat3x2(obj1, &o)) { // obj1 can't be interpreted as mat3x2
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat3x2'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x2(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat3x2 o2;

	if (!unpack_mat3x2(obj2, &o2)) { // obj2 can't be interpreted as mat3x2
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat3x2(o - o2);
}

static PyObject *
mat3x2_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x2(PyGLM_Number_AsFloat(obj1) * ((mat3x2*)obj2)->super_type);
	}


	if (PyGLM_Vec2_Check(obj1)) { // obj1 is a col_type
		glm::vec2 o;
		unpack_vec2(obj1, &o);

		return pack_vec3(o * ((mat3x2*)obj2)->super_type);
	}

	glm::mat3x2 o;

	if (!unpack_mat3x2(obj1, &o)) { // obj1 can't be interpreted as mat3x2
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x2(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec3_Check(obj2)) { // obj2 is a row_type
		glm::vec3 o2;
		unpack_vec3(obj2, &o2);

		return pack_vec2(o * o2);
	}

	if (PyGLM_Mat2x3_Check(obj2)) { // obj2 is a mat3x3
		glm::mat2x3 o2;
		unpack_mat2x3(obj2, &o2);

		return pack_mat2x2(o * o2);
	}

	if (PyGLM_Mat3x3_Check(obj2)) {// obj2 is a mat3x3
		glm::mat3x3 o2;
		unpack_mat3x3(obj2, &o2);

		return pack_mat3x2(o * o2);
	}

	if (PyGLM_Mat4x3_Check(obj2)) {// obj2 is a mat4x3
		glm::mat4x3 o2;
		unpack_mat4x3(obj2, &o2);

		return pack_mat4x3(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat3x2_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x2(PyGLM_Number_AsFloat(obj1) / ((mat3x2*)obj2)->super_type);
	}

	glm::mat3x2 o;

	if (!unpack_mat3x2(obj1, &o)) { // obj1 can't be interpreted as mat3x2
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x2(o / PyGLM_Number_AsFloat(obj2));
	}

	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat3x2_iadd(mat3x2 *self, PyObject *obj)
{
	mat3x2 * temp = (mat3x2*)mat3x2_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x2_isub(mat3x2 *self, PyObject *obj)
{
	mat3x2 * temp = (mat3x2*)mat3x2_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x2_imul(mat3x2 *self, PyObject *obj)
{
	mat3x2* temp = (mat3x2*)mat3x2_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat3x2Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x2_idiv(mat3x2 *self, PyObject *obj)
{
	mat3x2 * temp = (mat3x2*)mat3x2_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x2_repr(mat3x2* self)
{
	char * out = (char*)malloc((104) * sizeof(char));
	snprintf(out, 104, "mat3x2\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[1][0], self->super_type[1][1], self->super_type[2][0], self->super_type[2][1]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat3x2_str(mat3x2* self)
{
	char * out = (char*)malloc((96) * sizeof(char));
	snprintf(out, 96, "[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[1][0], self->super_type[1][1], self->super_type[2][0], self->super_type[2][1]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat3x2_len(mat3x2 * self) {
	return (Py_ssize_t)3;
}

static PyObject* mat3x2_length(mat3x2 * self, PyObject* arg) {
	return PyLong_FromLong(3);
}

static PyObject* mat3x2_sq_item(mat3x2 * self, Py_ssize_t index) {
	if (index < 0 || index > 2) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec2p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat3x2_sq_ass_item(mat3x2 * self, Py_ssize_t index, PyObject * value) {
	glm::vec2 o;
	if (!unpack_vec2(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec2, got ", value);
		return -1;
	}
	if (index < 0 || index > 2) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat3x2_mp_item(mat3x2 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec2p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat3x2_mp_ass_item(mat3x2 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec2 o;

		if (!unpack_vec2(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec2, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}



static int mat3x2_contains(mat3x2 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[2][0] || d == self->super_type[2][1]);
	}
	glm::vec2 o;
	if (!unpack_vec2(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1]) || (self->super_type[2][0] == o[0] && self->super_type[2][1] == o[1]));
	return out;
}

static PyObject * mat3x2_richcompare(mat3x2 * self, PyObject * other, int comp_type) {
	glm::mat3x2 o2;

	if (!unpack_mat3x2(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat3x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat3x2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat3x2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat3x2Iter *rgstate = (mat3x2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat3x2Iter_dealloc(mat3x2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat3x2Iter_next(mat3x2Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		return pack_mvec2p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat3x2_geniter(mat3x2 * self) {
	mat3x2Iter *rgstate = (mat3x2Iter *)((&mat3x2IterType)->tp_alloc(&mat3x2IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat3x2_getbuffer(mat3x2* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat3x2);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 3;
	view->shape[1] = 2;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat3x2::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat3x2_releasebuffer(mat3x2* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat3x3
#pragma region type mat3x3
static void
mat3x3_dealloc(mat3x3* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat3x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat3x3 *self;

	self = (mat3x3 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat3x3();
	}

	return (PyObject *)self;
}

static int
mat3x3_init(mat3x3 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;

	if (!PyArg_UnpackTuple(args, "mat3x3", 0, 9,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat3x3(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (arg4 == NULL) {
		glm::vec3 o;
		if (!unpack_vec3(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
			return -1;
		}
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
			return -1;
		}
		glm::vec3 o3;
		if (!unpack_vec3(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
			return -1;
		}
		self->super_type = glm::mat3x3(o, o2, o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9)) {
		self->super_type = glm::mat3x3(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6), PyGLM_Number_AsFloat(arg7), PyGLM_Number_AsFloat(arg8), PyGLM_Number_AsFloat(arg9));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
	return -1;
}

// unaryfunc
static PyObject *
mat3x3_neg(mat3x3 *obj)
{
	return pack_mat3x3(-obj->super_type);
}

static PyObject *
mat3x3_pos(mat3x3 *obj)
{
	return pack_mat3x3(+obj->super_type);
}

static PyObject *
mat3x3_abs(mat3x3 *obj)
{
	return pack_mat3x3(glm::mat3x3(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1]), glm::abs(obj->super_type[2])));
}

// binaryfunc
static PyObject *
mat3x3_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x3(((mat3x3*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat3x3 o;

	if (!unpack_mat3x3(obj1, &o)) { // obj1 can't be interpreted as mat3x3
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat3x3'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x3(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat3x3 o2;

	if (!unpack_mat3x3(obj2, &o2)) { // obj2 can't be interpreted as mat3x3
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat3x3(o + o2);
}

static PyObject *
mat3x3_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x3(glm::mat3x3(PyGLM_Number_AsFloat(obj1)) - ((mat3x3*)obj2)->super_type);
	}

	glm::mat3x3 o;

	if (!unpack_mat3x3(obj1, &o)) { // obj1 can't be interpreted as mat3x3
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat3x3'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x3(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat3x3 o2;

	if (!unpack_mat3x3(obj2, &o2)) { // obj2 can't be interpreted as mat3x3
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat3x3(o - o2);
}

static PyObject *
mat3x3_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x3(PyGLM_Number_AsFloat(obj1) * ((mat3x3*)obj2)->super_type);
	}


	if (PyGLM_Vec3_Check(obj1)) { // obj1 is a col_type
		glm::vec3 o;
		unpack_vec3(obj1, &o);

		return pack_vec3(o * ((mat3x3*)obj2)->super_type);
	}

	glm::mat3x3 o;

	if (!unpack_mat3x3(obj1, &o)) { // obj1 can't be interpreted as mat3x3
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x3(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec3_Check(obj2)) { // obj2 is a row_type
		glm::vec3 o2;
		unpack_vec3(obj2, &o2);

		return pack_vec2(o * o2);
	}

	if (PyGLM_Mat2x3_Check(obj2)) { // obj2 is a mat3x3
		glm::mat2x3 o2;
		unpack_mat2x3(obj2, &o2);

		return pack_mat2x3(o * o2);
	}

	if (PyGLM_Mat3x3_Check(obj2)) {// obj2 is a mat3x3
		glm::mat3x3 o2;
		unpack_mat3x3(obj2, &o2);

		return pack_mat3x3(o * o2);
	}

	if (PyGLM_Mat4x3_Check(obj2)) {// obj2 is a mat4x3
		glm::mat4x3 o2;
		unpack_mat4x3(obj2, &o2);

		return pack_mat4x3(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat3x3_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x3(PyGLM_Number_AsFloat(obj1) / ((mat3x3*)obj2)->super_type);
	}

	if (PyGLM_Vec3_Check(obj1)) { // obj1 is a col_type
		glm::vec3 o;
		unpack_vec3(obj1, &o);

		return pack_vec3(o / ((mat3x3*)obj2)->super_type);
	}

	glm::mat3x3 o;

	if (!unpack_mat3x3(obj1, &o)) { // obj1 can't be interpreted as mat3x3
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x3(o / PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec3_Check(obj2)) { // obj2 is a row_type
		glm::vec3 o2;
		unpack_vec3(obj2, &o2);

		return pack_vec3(o / o2);
	}

	if (PyGLM_Mat3x3_Check(obj2)) { // obj2 is a mat3x3
		glm::mat3x3 o2;
		unpack_mat3x3(obj2, &o2);

		return pack_mat3x3(o / o2);
	}
	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat3x3_iadd(mat3x3 *self, PyObject *obj)
{
	mat3x3 * temp = (mat3x3*)mat3x3_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x3_isub(mat3x3 *self, PyObject *obj)
{
	mat3x3 * temp = (mat3x3*)mat3x3_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x3_imul(mat3x3 *self, PyObject *obj)
{
	mat3x3* temp = (mat3x3*)mat3x3_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat3x3Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x3_idiv(mat3x3 *self, PyObject *obj)
{
	mat3x3 * temp = (mat3x3*)mat3x3_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat3x3Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x3_repr(mat3x3* self)
{
	char * out = (char*)malloc((149) * sizeof(char));
	snprintf(out, 149, "mat3x3\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat3x3_str(mat3x3* self)
{
	char * out = (char*)malloc((141) * sizeof(char));
	snprintf(out, 141, "[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat3x3_len(mat3x3 * self) {
	return (Py_ssize_t)3;
}

static PyObject* mat3x3_length(mat3x3 * self, PyObject* arg) {
	return PyLong_FromLong(3);
}

static PyObject* mat3x3_sq_item(mat3x3 * self, Py_ssize_t index) {
	if (index < 0 || index > 2) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec3p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat3x3_sq_ass_item(mat3x3 * self, Py_ssize_t index, PyObject * value) {
	glm::vec3 o;
	if (!unpack_vec3(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec3, got ", value);
		return -1;
	}
	if (index < 0 || index > 2) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat3x3_mp_item(mat3x3 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec3p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat3x3_mp_ass_item(mat3x3 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec3 o;

		if (!unpack_vec3(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec3, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat3x3_contains(mat3x3 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[0][2] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[1][2] || d == self->super_type[2][0] || d == self->super_type[2][1] || d == self->super_type[2][2]);
	}
	glm::vec3 o;
	if (!unpack_vec3(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1] && self->super_type[0][2] == o[2]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1] && self->super_type[1][2] == o[2]) || (self->super_type[2][0] == o[0] && self->super_type[2][1] == o[1] && self->super_type[2][2] == o[2]));
	return out;
}

static PyObject * mat3x3_richcompare(mat3x3 * self, PyObject * other, int comp_type) {
	glm::mat3x3 o2;

	if (!unpack_mat3x3(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat3x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat3x3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat3x3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat3x3Iter *rgstate = (mat3x3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat3x3Iter_dealloc(mat3x3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat3x3Iter_next(mat3x3Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		return pack_mvec3p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat3x3_geniter(mat3x3 * self) {
	mat3x3Iter *rgstate = (mat3x3Iter *)((&mat3x3IterType)->tp_alloc(&mat3x3IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat3x3_getbuffer(mat3x3* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat3x3);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 3;
	view->shape[1] = 3;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat3x3::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat3x3_releasebuffer(mat3x3* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat3x4
#pragma region type mat3x4
static void
mat3x4_dealloc(mat3x4* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat3x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat3x4 *self;

	self = (mat3x4 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat3x4();
	}

	return (PyObject *)self;
}

static int
mat3x4_init(mat3x4 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;

	if (!PyArg_UnpackTuple(args, "mat3x4", 0, 12,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat3x4(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (arg4 == NULL) {
		glm::vec4 o;
		if (!unpack_vec4(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
			return -1;
		}
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
			return -1;
		}
		glm::vec4 o3;
		if (!unpack_vec4(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
			return -1;
		}
		self->super_type = glm::mat3x4(o, o2, o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9) && PyGLM_Number_Check(arg10) && PyGLM_Number_Check(arg11) && PyGLM_Number_Check(arg12)) {
		self->super_type = glm::mat3x4(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6), PyGLM_Number_AsFloat(arg7), PyGLM_Number_AsFloat(arg8), PyGLM_Number_AsFloat(arg9), PyGLM_Number_AsFloat(arg10), PyGLM_Number_AsFloat(arg11), PyGLM_Number_AsFloat(arg12));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
	return -1;
}

// unaryfunc
static PyObject *
mat3x4_neg(mat3x4 *obj)
{
	return pack_mat3x4(-obj->super_type);
}

static PyObject *
mat3x4_pos(mat3x4 *obj)
{
	return pack_mat3x4(+obj->super_type);
}

static PyObject *
mat3x4_abs(mat3x4 *obj)
{
	return pack_mat3x4(glm::mat3x4(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1]), glm::abs(obj->super_type[2])));
}

// binaryfunc
static PyObject *
mat3x4_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x4(((mat3x4*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat3x4 o;

	if (!unpack_mat3x4(obj1, &o)) { // obj1 can't be interpreted as mat3x4
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat3x4'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x4(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat3x4 o2;

	if (!unpack_mat3x4(obj2, &o2)) { // obj2 can't be interpreted as mat3x4
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat3x4(o + o2);
}

static PyObject *
mat3x4_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x4(glm::mat3x4(PyGLM_Number_AsFloat(obj1)) - ((mat3x4*)obj2)->super_type);
	}

	glm::mat3x4 o;

	if (!unpack_mat3x4(obj1, &o)) { // obj1 can't be interpreted as mat3x4
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat3x4'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x4(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat3x4 o2;

	if (!unpack_mat3x4(obj2, &o2)) { // obj2 can't be interpreted as mat3x4
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat3x4(o - o2);
}

static PyObject *
mat3x4_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x4(PyGLM_Number_AsFloat(obj1) * ((mat3x4*)obj2)->super_type);
	}


	if (PyGLM_Vec4_Check(obj1)) { // obj1 is a col_type
		glm::vec4 o;
		unpack_vec4(obj1, &o);

		return pack_vec3(o * ((mat3x4*)obj2)->super_type);
	}

	glm::mat3x4 o;

	if (!unpack_mat3x4(obj1, &o)) { // obj1 can't be interpreted as mat3x4
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x4(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec3_Check(obj2)) { // obj2 is a row_type
		glm::vec3 o2;
		unpack_vec3(obj2, &o2);

		return pack_vec4(o * o2);
	}

	if (PyGLM_Mat2x3_Check(obj2)) { // obj2 is a mat3x3
		glm::mat2x3 o2;
		unpack_mat2x3(obj2, &o2);

		return pack_mat2x4(o * o2);
	}

	if (PyGLM_Mat3x3_Check(obj2)) {// obj2 is a mat3x3
		glm::mat3x3 o2;
		unpack_mat3x3(obj2, &o2);

		return pack_mat3x4(o * o2);
	}

	if (PyGLM_Mat4x3_Check(obj2)) {// obj2 is a mat4x3
		glm::mat4x3 o2;
		unpack_mat4x3(obj2, &o2);

		return pack_mat4x4(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat3x4_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat3x4(PyGLM_Number_AsFloat(obj1) / ((mat3x4*)obj2)->super_type);
	}

	glm::mat3x4 o;

	if (!unpack_mat3x4(obj1, &o)) { // obj1 can't be interpreted as mat3x4
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat3x4(o / PyGLM_Number_AsFloat(obj2));
	}

	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat3x4_iadd(mat3x4 *self, PyObject *obj)
{
	mat3x4 * temp = (mat3x4*)mat3x4_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x4_isub(mat3x4 *self, PyObject *obj)
{
	mat3x4 * temp = (mat3x4*)mat3x4_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x4_imul(mat3x4 *self, PyObject *obj)
{
	mat3x4* temp = (mat3x4*)mat3x4_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat3x4Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x4_idiv(mat3x4 *self, PyObject *obj)
{
	mat3x4 * temp = (mat3x4*)mat3x4_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat3x4_repr(mat3x4* self)
{
	char * out = (char*)malloc((194) * sizeof(char));
	snprintf(out, 194, "mat3x4\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[0][3], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[1][3], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2], self->super_type[2][3]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat3x4_str(mat3x4* self)
{
	char * out = (char*)malloc((186) * sizeof(char));
	snprintf(out, 186, "[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[0][3], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[1][3], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2], self->super_type[2][3]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat3x4_len(mat3x4 * self) {
	return (Py_ssize_t)3;
}

static PyObject* mat3x4_length(mat3x4 * self, PyObject* arg) {
	return PyLong_FromLong(3);
}

static PyObject* mat3x4_sq_item(mat3x4 * self, Py_ssize_t index) {
	if (index < 0 || index > 2) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec4p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat3x4_sq_ass_item(mat3x4 * self, Py_ssize_t index, PyObject * value) {
	glm::vec4 o;
	if (!unpack_vec4(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec4, got ", value);
		return -1;
	}
	if (index < 0 || index > 2) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat3x4_mp_item(mat3x4 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec4p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat3x4_mp_ass_item(mat3x4 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec4 o;

		if (!unpack_vec4(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec4, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}



static int mat3x4_contains(mat3x4 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[0][2] || d == self->super_type[0][3] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[1][2] || d == self->super_type[1][3] || d == self->super_type[2][0] || d == self->super_type[2][1] || d == self->super_type[2][2] || d == self->super_type[2][3]);
	}
	glm::vec4 o;
	if (!unpack_vec4(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1] && self->super_type[0][2] == o[2] && self->super_type[0][3] == o[3]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1] && self->super_type[1][2] == o[2] && self->super_type[1][3] == o[3]) || (self->super_type[2][0] == o[0] && self->super_type[2][1] == o[1] && self->super_type[2][2] == o[2] && self->super_type[2][3] == o[3]));
	return out;
}

static PyObject * mat3x4_richcompare(mat3x4 * self, PyObject * other, int comp_type) {
	glm::mat3x4 o2;

	if (!unpack_mat3x4(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat3x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat3x4 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat3x4Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat3x4Iter *rgstate = (mat3x4Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat3x4Iter_dealloc(mat3x4Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat3x4Iter_next(mat3x4Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		return pack_mvec4p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat3x4_geniter(mat3x4 * self) {
	mat3x4Iter *rgstate = (mat3x4Iter *)((&mat3x4IterType)->tp_alloc(&mat3x4IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat3x4_getbuffer(mat3x4* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat3x4);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 3;
	view->shape[1] = 4;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat3x4::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat3x4_releasebuffer(mat3x4* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat4x2
#pragma region type mat4x2
static void
mat4x2_dealloc(mat4x2* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat4x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat4x2 *self;

	self = (mat4x2 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat4x2();
	}

	return (PyObject *)self;
}

static int
mat4x2_init(mat4x2 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;

	if (!PyArg_UnpackTuple(args, "mat4x2", 0, 8,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat4x2(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
			return -1;
		}
	}

	if (arg3 == NULL || arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (arg5 == NULL) {
		glm::vec2 o;
		if (!unpack_vec2(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
			return -1;
		}
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
			return -1;
		}
		glm::vec2 o3;
		if (!unpack_vec2(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
			return -1;
		}
		glm::vec2 o4;
		if (!unpack_vec2(arg4, &o4)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
			return -1;
		}
		self->super_type = glm::mat4x2(o, o2, o3, o4);
		return 0;
	}

	if (arg6 == NULL || arg7 == NULL || arg8 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8)) {
		self->super_type = glm::mat4x2(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6), PyGLM_Number_AsFloat(arg7), PyGLM_Number_AsFloat(arg8));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
	return -1;
}

// unaryfunc
static PyObject *
mat4x2_neg(mat4x2 *obj)
{
	return pack_mat4x2(-obj->super_type);
}

static PyObject *
mat4x2_pos(mat4x2 *obj)
{
	return pack_mat4x2(+obj->super_type);
}

static PyObject *
mat4x2_abs(mat4x2 *obj)
{
	return pack_mat4x2(glm::mat4x2(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1]), glm::abs(obj->super_type[2]), glm::abs(obj->super_type[3])));
}

// binaryfunc
static PyObject *
mat4x2_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x2(((mat4x2*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat4x2 o;

	if (!unpack_mat4x2(obj1, &o)) { // obj1 can't be interpreted as mat4x2
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat4x2'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x2(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat4x2 o2;

	if (!unpack_mat4x2(obj2, &o2)) { // obj2 can't be interpreted as mat4x2
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat4x2(o + o2);
}

static PyObject *
mat4x2_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x2(glm::mat4x2(PyGLM_Number_AsFloat(obj1)) - ((mat4x2*)obj2)->super_type);
	}

	glm::mat4x2 o;

	if (!unpack_mat4x2(obj1, &o)) { // obj1 can't be interpreted as mat4x2
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat4x2'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x2(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat4x2 o2;

	if (!unpack_mat4x2(obj2, &o2)) { // obj2 can't be interpreted as mat4x2
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat4x2(o - o2);
}

static PyObject *
mat4x2_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x2(PyGLM_Number_AsFloat(obj1) * ((mat4x2*)obj2)->super_type);
	}


	if (PyGLM_Vec2_Check(obj1)) { // obj1 is a col_type
		glm::vec2 o;
		unpack_vec2(obj1, &o);

		return pack_vec3(o * ((mat4x2*)obj2)->super_type);
	}

	glm::mat4x2 o;

	if (!unpack_mat4x2(obj1, &o)) { // obj1 can't be interpreted as mat4x2
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x2(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec4_Check(obj2)) { // obj2 is a row_type
		glm::vec4 o2;
		unpack_vec4(obj2, &o2);

		return pack_vec2(o * o2);
	}

	if (PyGLM_Mat2x4_Check(obj2)) { // obj2 is a mat3x3
		glm::mat2x4 o2;
		unpack_mat2x4(obj2, &o2);

		return pack_mat2x2(o * o2);
	}

	if (PyGLM_Mat3x4_Check(obj2)) {// obj2 is a mat3x3
		glm::mat3x4 o2;
		unpack_mat3x4(obj2, &o2);

		return pack_mat3x2(o * o2);
	}

	if (PyGLM_Mat4x4_Check(obj2)) {// obj2 is a mat4x3
		glm::mat4x4 o2;
		unpack_mat4x4(obj2, &o2);

		return pack_mat4x2(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat4x2_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x2(PyGLM_Number_AsFloat(obj1) / ((mat4x2*)obj2)->super_type);
	}

	glm::mat4x2 o;

	if (!unpack_mat4x2(obj1, &o)) { // obj1 can't be interpreted as mat4x2
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x2(o / PyGLM_Number_AsFloat(obj2));
	}

	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat4x2_iadd(mat4x2 *self, PyObject *obj)
{
	mat4x2 * temp = (mat4x2*)mat4x2_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x2_isub(mat4x2 *self, PyObject *obj)
{
	mat4x2 * temp = (mat4x2*)mat4x2_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x2_imul(mat4x2 *self, PyObject *obj)
{
	mat4x2* temp = (mat4x2*)mat4x2_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat4x2Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x2_idiv(mat4x2 *self, PyObject *obj)
{
	mat4x2 * temp = (mat4x2*)mat4x2_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x2_repr(mat4x2* self)
{
	char * out = (char*)malloc((136) * sizeof(char));
	snprintf(out, 136, "mat4x2\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[1][0], self->super_type[1][1], self->super_type[2][0], self->super_type[2][1], self->super_type[3][0], self->super_type[3][1]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat4x2_str(mat4x2* self)
{
	char * out = (char*)malloc((128) * sizeof(char));
	snprintf(out, 128, "[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[1][0], self->super_type[1][1], self->super_type[2][0], self->super_type[2][1], self->super_type[3][0], self->super_type[3][1]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat4x2_len(mat4x2 * self) {
	return (Py_ssize_t)4;
}

static PyObject* mat4x2_length(mat4x2 * self, PyObject* arg) {
	return PyLong_FromLong(4);
}

static PyObject* mat4x2_sq_item(mat4x2 * self, Py_ssize_t index) {
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec2p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat4x2_sq_ass_item(mat4x2 * self, Py_ssize_t index, PyObject * value) {
	glm::vec2 o;
	if (!unpack_vec2(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec2, got ", value);
		return -1;
	}
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat4x2_mp_item(mat4x2 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec2p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat4x2_mp_ass_item(mat4x2 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec2 o;

		if (!unpack_vec2(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec2, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat4x2_contains(mat4x2 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[2][0] || d == self->super_type[2][1] || d == self->super_type[3][0] || d == self->super_type[3][1]);
	}
	glm::vec2 o;
	if (!unpack_vec2(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1]) || (self->super_type[2][0] == o[0] && self->super_type[2][1] == o[1]) || (self->super_type[3][0] == o[0] && self->super_type[3][1] == o[1]));
	return out;
}

static PyObject * mat4x2_richcompare(mat4x2 * self, PyObject * other, int comp_type) {
	glm::mat4x2 o2;

	if (!unpack_mat4x2(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat4x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat4x2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat4x2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat4x2Iter *rgstate = (mat4x2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat4x2Iter_dealloc(mat4x2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat4x2Iter_next(mat4x2Iter *rgstate)
{
	if (rgstate->seq_index < 4) {
		return pack_mvec2p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat4x2_geniter(mat4x2 * self) {
	mat4x2Iter *rgstate = (mat4x2Iter *)((&mat4x2IterType)->tp_alloc(&mat4x2IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat4x2_getbuffer(mat4x2* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat4x2);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 4;
	view->shape[1] = 2;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat4x2::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat4x2_releasebuffer(mat4x2* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat4x3
#pragma region type mat4x3
static void
mat4x3_dealloc(mat4x3* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat4x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat4x3 *self;

	self = (mat4x3 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat4x3();
	}

	return (PyObject *)self;
}

static int
mat4x3_init(mat4x3 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;

	if (!PyArg_UnpackTuple(args, "mat4x3", 0, 12,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat4x3(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
			return -1;
		}
	}

	if (arg3 == NULL || arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (arg5 == NULL) {
		glm::vec3 o;
		if (!unpack_vec3(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
			return -1;
		}
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
			return -1;
		}
		glm::vec3 o3;
		if (!unpack_vec3(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
			return -1;
		}
		glm::vec3 o4;
		if (!unpack_vec3(arg4, &o4)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
			return -1;
		}
		self->super_type = glm::mat4x3(o, o2, o3, o4);
		return 0;
	}

	if (arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9) && PyGLM_Number_Check(arg10) && PyGLM_Number_Check(arg11) && PyGLM_Number_Check(arg12)) {
		self->super_type = glm::mat4x3(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6), PyGLM_Number_AsFloat(arg7), PyGLM_Number_AsFloat(arg8), PyGLM_Number_AsFloat(arg9), PyGLM_Number_AsFloat(arg10), PyGLM_Number_AsFloat(arg11), PyGLM_Number_AsFloat(arg12));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
	return -1;
}

// unaryfunc
static PyObject *
mat4x3_neg(mat4x3 *obj)
{
	return pack_mat4x3(-obj->super_type);
}

static PyObject *
mat4x3_pos(mat4x3 *obj)
{
	return pack_mat4x3(+obj->super_type);
}

static PyObject *
mat4x3_abs(mat4x3 *obj)
{
	return pack_mat4x3(glm::mat4x3(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1]), glm::abs(obj->super_type[2]), glm::abs(obj->super_type[3])));
}

// binaryfunc
static PyObject *
mat4x3_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x3(((mat4x3*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat4x3 o;

	if (!unpack_mat4x3(obj1, &o)) { // obj1 can't be interpreted as mat4x3
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat4x3'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x3(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat4x3 o2;

	if (!unpack_mat4x3(obj2, &o2)) { // obj2 can't be interpreted as mat4x3
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat4x3(o + o2);
}

static PyObject *
mat4x3_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x3(glm::mat4x3(PyGLM_Number_AsFloat(obj1)) - ((mat4x3*)obj2)->super_type);
	}

	glm::mat4x3 o;

	if (!unpack_mat4x3(obj1, &o)) { // obj1 can't be interpreted as mat4x3
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat4x3'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x3(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat4x3 o2;

	if (!unpack_mat4x3(obj2, &o2)) { // obj2 can't be interpreted as mat4x3
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat4x3(o - o2);
}

static PyObject *
mat4x3_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x3(PyGLM_Number_AsFloat(obj1) * ((mat4x3*)obj2)->super_type);
	}


	if (PyGLM_Vec3_Check(obj1)) { // obj1 is a col_type
		glm::vec3 o;
		unpack_vec3(obj1, &o);

		return pack_vec4(o * ((mat4x3*)obj2)->super_type);
	}

	glm::mat4x3 o;

	if (!unpack_mat4x3(obj1, &o)) { // obj1 can't be interpreted as mat4x3
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x3(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec4_Check(obj2)) { // obj2 is a row_type
		glm::vec4 o2;
		unpack_vec4(obj2, &o2);

		return pack_vec3(o * o2);
	}

	if (PyGLM_Mat2x4_Check(obj2)) { // obj2 is a mat3x3
		glm::mat2x4 o2;
		unpack_mat2x4(obj2, &o2);

		return pack_mat2x3(o * o2);
	}

	if (PyGLM_Mat3x4_Check(obj2)) {// obj2 is a mat3x3
		glm::mat3x4 o2;
		unpack_mat3x4(obj2, &o2);

		return pack_mat3x3(o * o2);
	}

	if (PyGLM_Mat4x4_Check(obj2)) {// obj2 is a mat4x3
		glm::mat4x4 o2;
		unpack_mat4x4(obj2, &o2);

		return pack_mat4x3(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat4x3_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x3(PyGLM_Number_AsFloat(obj1) / ((mat4x3*)obj2)->super_type);
	}

	glm::mat4x3 o;

	if (!unpack_mat4x3(obj1, &o)) { // obj1 can't be interpreted as mat4x3
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x3(o / PyGLM_Number_AsFloat(obj2));
	}

	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat4x3_iadd(mat4x3 *self, PyObject *obj)
{
	mat4x3 * temp = (mat4x3*)mat4x3_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x3_isub(mat4x3 *self, PyObject *obj)
{
	mat4x3 * temp = (mat4x3*)mat4x3_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x3_imul(mat4x3 *self, PyObject *obj)
{
	mat4x3* temp = (mat4x3*)mat4x3_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat4x3Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x3_idiv(mat4x3 *self, PyObject *obj)
{
	mat4x3 * temp = (mat4x3*)mat4x3_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x3_repr(mat4x3* self)
{
	char * out = (char*)malloc((196) * sizeof(char));
	snprintf(out, 196, "mat4x3\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2], self->super_type[3][0], self->super_type[3][1], self->super_type[3][2]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat4x3_str(mat4x3* self)
{
	char * out = (char*)malloc((188) * sizeof(char));
	snprintf(out, 188, "[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2], self->super_type[3][0], self->super_type[3][1], self->super_type[3][2]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat4x3_len(mat4x3 * self) {
	return (Py_ssize_t)4;
}

static PyObject* mat4x3_length(mat4x3 * self, PyObject* arg) {
	return PyLong_FromLong(4);
}

static PyObject* mat4x3_sq_item(mat4x3 * self, Py_ssize_t index) {
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec3p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat4x3_sq_ass_item(mat4x3 * self, Py_ssize_t index, PyObject * value) {
	glm::vec3 o;
	if (!unpack_vec3(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec3, got ", value);
		return -1;
	}
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat4x3_mp_item(mat4x3 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec3p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat4x3_mp_ass_item(mat4x3 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec3 o;

		if (!unpack_vec3(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec3, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat4x3_contains(mat4x3 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[0][2] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[1][2] || d == self->super_type[2][0] || d == self->super_type[2][1] || d == self->super_type[2][2] || d == self->super_type[3][0] || d == self->super_type[3][1] || d == self->super_type[3][2]);
	}
	glm::vec3 o;
	if (!unpack_vec3(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1] && self->super_type[0][2] == o[2]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1] && self->super_type[1][2] == o[2]) || (self->super_type[2][0] == o[0] && self->super_type[2][1] == o[1] && self->super_type[2][2] == o[2]) || (self->super_type[3][0] == o[0] && self->super_type[3][1] == o[1] && self->super_type[3][2] == o[2]));
	return out;
}

static PyObject * mat4x3_richcompare(mat4x3 * self, PyObject * other, int comp_type) {
	glm::mat4x3 o2;

	if (!unpack_mat4x3(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat4x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat4x3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat4x3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat4x3Iter *rgstate = (mat4x3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat4x3Iter_dealloc(mat4x3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat4x3Iter_next(mat4x3Iter *rgstate)
{
	if (rgstate->seq_index < 4) {
		return pack_mvec3p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat4x3_geniter(mat4x3 * self) {
	mat4x3Iter *rgstate = (mat4x3Iter *)((&mat4x3IterType)->tp_alloc(&mat4x3IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat4x3_getbuffer(mat4x3* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat4x3);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 4;
	view->shape[1] = 3;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat4x3::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat4x3_releasebuffer(mat4x3* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type mat4x4
#pragma region type mat4x4
static void
mat4x4_dealloc(mat4x4* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
mat4x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	mat4x4 *self;

	self = (mat4x4 *)type->tp_alloc(type, 0);

	if (self != NULL) {
		self->super_type = glm::mat4x4();
	}

	return (PyObject *)self;
}

static int
mat4x4_init(mat4x4 *self, PyObject *args, PyObject *kwds)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;
	PyObject *arg13 = NULL;
	PyObject *arg14 = NULL;
	PyObject *arg15 = NULL;
	PyObject *arg16 = NULL;

	if (!PyArg_UnpackTuple(args, "mat4x4", 0, 16,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12, &arg13, &arg14, &arg15, &arg16)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat4x4(PyGLM_Number_AsFloat(arg1));
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_mat(arg1, &o);
		switch (vecType) {
		case PyGLM_TYPE_MAT2x2:
			self->super_type = (*(glm::mat2x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x3:
			self->super_type = (*(glm::mat2x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT2x4:
			self->super_type = (*(glm::mat2x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x2:
			self->super_type = (*(glm::mat3x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x3:
			self->super_type = (*(glm::mat3x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT3x4:
			self->super_type = (*(glm::mat3x4*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x2:
			self->super_type = (*(glm::mat4x2*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x3:
			self->super_type = (*(glm::mat4x3*)o);
			free(o);
			return 0;
		case PyGLM_TYPE_MAT4x4:
			self->super_type = (*(glm::mat4x4*)o);
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
			return -1;
		}
	}

	if (arg3 == NULL || arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (arg5 == NULL) {
		glm::vec4 o;
		if (!unpack_vec4(arg1, &o)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
			return -1;
		}
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
			return -1;
		}
		glm::vec4 o3;
		if (!unpack_vec4(arg3, &o3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
			return -1;
		}
		glm::vec4 o4;
		if (!unpack_vec4(arg4, &o4)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
			return -1;
		}
		self->super_type = glm::mat4x4(o, o2, o3, o4);
		return 0;
	}

	if (arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL || arg13 == NULL || arg14 == NULL || arg15 == NULL || arg16 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9) && PyGLM_Number_Check(arg10) && PyGLM_Number_Check(arg11) && PyGLM_Number_Check(arg12) && PyGLM_Number_Check(arg13) && PyGLM_Number_Check(arg14) && PyGLM_Number_Check(arg15) && PyGLM_Number_Check(arg16)) {
		self->super_type = glm::mat4x4(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6), PyGLM_Number_AsFloat(arg7), PyGLM_Number_AsFloat(arg8), PyGLM_Number_AsFloat(arg9), PyGLM_Number_AsFloat(arg10), PyGLM_Number_AsFloat(arg11), PyGLM_Number_AsFloat(arg12), PyGLM_Number_AsFloat(arg13), PyGLM_Number_AsFloat(arg14), PyGLM_Number_AsFloat(arg15), PyGLM_Number_AsFloat(arg16));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
	return -1;
}

// unaryfunc
static PyObject *
mat4x4_neg(mat4x4 *obj)
{
	return pack_mat4x4(-obj->super_type);
}

static PyObject *
mat4x4_pos(mat4x4 *obj)
{
	return pack_mat4x4(+obj->super_type);
}

static PyObject *
mat4x4_abs(mat4x4 *obj)
{
	return pack_mat4x4(glm::mat4x4(glm::abs(obj->super_type[0]), glm::abs(obj->super_type[1]), glm::abs(obj->super_type[2]), glm::abs(obj->super_type[3])));
}

// binaryfunc
static PyObject *
mat4x4_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x4(((mat4x4*)obj2)->super_type + PyGLM_Number_AsFloat(obj1));
	}

	glm::mat4x4 o;

	if (!unpack_mat4x4(obj1, &o)) { // obj1 can't be interpreted as mat4x4
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::mat4x4'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x4(o + PyGLM_Number_AsFloat(obj2));
	}

	glm::mat4x4 o2;

	if (!unpack_mat4x4(obj2, &o2)) { // obj2 can't be interpreted as mat4x4
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat4x4(o + o2);
}

static PyObject *
mat4x4_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x4(PyGLM_Number_AsFloat(obj1) - ((mat4x4*)obj2)->super_type);
	}

	glm::mat4x4 o;

	if (!unpack_mat4x4(obj1, &o)) { // obj1 can't be interpreted as mat4x4
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for - of 'glm::detail::mat4x4'");
		return NULL;
	}


	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x4(o - PyGLM_Number_AsFloat(obj2));
	}

	glm::mat4x4 o2;

	if (!unpack_mat4x4(obj2, &o2)) { // obj2 can't be interpreted as mat4x4
		Py_RETURN_NOTIMPLEMENTED;
	}
	return pack_mat4x4(o - o2);
}

static PyObject *
mat4x4_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x4(PyGLM_Number_AsFloat(obj1) * ((mat4x4*)obj2)->super_type);
	}


	if (PyGLM_Vec4_Check(obj1)) { // obj1 is a col_type
		glm::vec4 o;
		unpack_vec4(obj1, &o);

		return pack_vec4(o * ((mat4x4*)obj2)->super_type);
	}

	glm::mat4x4 o;

	if (!unpack_mat4x4(obj1, &o)) { // obj1 can't be interpreted as mat4x4
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x4(o * PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec4_Check(obj2)) { // obj2 is a row_type
		glm::vec4 o2;
		unpack_vec4(obj2, &o2);

		return pack_vec4(o * o2);
	}

	if (PyGLM_Mat2x4_Check(obj2)) { // obj2 is a mat3x3
		glm::mat2x4 o2;
		unpack_mat2x4(obj2, &o2);

		return pack_mat2x4(o * o2);
	}

	if (PyGLM_Mat3x4_Check(obj2)) {// obj2 is a mat3x3
		glm::mat3x4 o2;
		unpack_mat3x4(obj2, &o2);

		return pack_mat3x4(o * o2);
	}

	if (PyGLM_Mat4x4_Check(obj2)) {// obj2 is a mat4x4
		glm::mat4x4 o2;
		unpack_mat4x4(obj2, &o2);

		return pack_mat4x4(o * o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject *
mat4x4_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat4x4(PyGLM_Number_AsFloat(obj1) / ((mat4x4*)obj2)->super_type);
	}

	if (PyGLM_Vec4_Check(obj1)) { // obj1 is a col_type
		glm::vec4 o;
		unpack_vec4(obj1, &o);

		return pack_vec4(o / ((mat4x4*)obj2)->super_type);
	}

	glm::mat4x4 o;

	if (!unpack_mat4x4(obj1, &o)) { // obj1 can't be interpreted as mat4x4
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat4x4(o / PyGLM_Number_AsFloat(obj2));
	}

	if (PyGLM_Vec4_Check(obj2)) { // obj2 is a row_type
		glm::vec4 o2;
		unpack_vec4(obj2, &o2);

		return pack_vec4(o / o2);
	}

	if (PyGLM_Mat4x4_Check(obj2)) { // obj2 is a mat4x4
		glm::mat4x4 o2;
		unpack_mat4x4(obj2, &o2);

		return pack_mat4x4(o / o2);
	}
	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
mat4x4_iadd(mat4x4 *self, PyObject *obj)
{
	mat4x4 * temp = (mat4x4*)mat4x4_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x4_isub(mat4x4 *self, PyObject *obj)
{
	mat4x4 * temp = (mat4x4*)mat4x4_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x4_imul(mat4x4 *self, PyObject *obj)
{
	mat4x4* temp = (mat4x4*)mat4x4_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat4x4Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x4_idiv(mat4x4 *self, PyObject *obj)
{
	mat4x4 * temp = (mat4x4*)mat4x4_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyObject_TypeCheck(temp, &mat4x4Type)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
mat4x4_repr(mat4x4* self)
{
	char * out = (char*)malloc((256) * sizeof(char));
	snprintf(out, 256, "mat4x4\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[0][3], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[1][3], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2], self->super_type[2][3], self->super_type[3][0], self->super_type[3][1], self->super_type[3][2], self->super_type[3][3]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
mat4x4_str(mat4x4* self)
{
	char * out = (char*)malloc((248) * sizeof(char));
	snprintf(out, 248, "[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->super_type[0][0], self->super_type[0][1], self->super_type[0][2], self->super_type[0][3], self->super_type[1][0], self->super_type[1][1], self->super_type[1][2], self->super_type[1][3], self->super_type[2][0], self->super_type[2][1], self->super_type[2][2], self->super_type[2][3], self->super_type[3][0], self->super_type[3][1], self->super_type[3][2], self->super_type[3][3]);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t mat4x4_len(mat4x4 * self) {
	return (Py_ssize_t)4;
}

static PyObject* mat4x4_length(mat4x4 * self, PyObject* arg) {
	return PyLong_FromLong(4);
}

static PyObject* mat4x4_sq_item(mat4x4 * self, Py_ssize_t index) {
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return pack_mvec4p(&self->super_type[(int)index], (PyObject*)self);
}

static int mat4x4_sq_ass_item(mat4x4 * self, Py_ssize_t index, PyObject * value) {
	glm::vec4 o;
	if (!unpack_vec4(value, &o)) {
		PyGLM_TYPEERROR_O("expected vec4, got ", value);
		return -1;
	}
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}

	self->super_type[(int)index] = o;

	return 0;
}

static PyObject* mat4x4_mp_item(mat4x4 * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec4p(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyFloat_FromDouble((float)self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

static int mat4x4_mp_ass_item(mat4x4 * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		glm::vec4 o;

		if (!unpack_vec4(value, &o)) {
			PyGLM_TYPEERROR_O("expected vec4, got ", value);
			return -1;
		}

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			Py_DECREF(value0);
			Py_DECREF(value1);

			PyGLM_TYPEERROR_2O("indices must be a pair of integers, got ", value0, value1);
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		Py_DECREF(value0);
		Py_DECREF(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_AsFloat(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

static int mat4x4_contains(mat4x4 * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		float d = PyGLM_Number_AsFloat(value);
		return (int)(d == self->super_type[0][0] || d == self->super_type[0][1] || d == self->super_type[0][2] || d == self->super_type[0][3] || d == self->super_type[1][0] || d == self->super_type[1][1] || d == self->super_type[1][2] || d == self->super_type[1][3] || d == self->super_type[2][0] || d == self->super_type[2][1] || d == self->super_type[2][2] || d == self->super_type[2][3] || d == self->super_type[3][0] || d == self->super_type[3][1] || d == self->super_type[3][2] || d == self->super_type[3][3]);
	}
	glm::vec4 o;
	if (!unpack_vec4(value, &o)) {
		return 0;
	}

	int out = (int)((self->super_type[0][0] == o[0] && self->super_type[0][1] == o[1] && self->super_type[0][2] == o[2] && self->super_type[0][3] == o[3]) || (self->super_type[1][0] == o[0] && self->super_type[1][1] == o[1] && self->super_type[1][2] == o[2] && self->super_type[1][3] == o[3]) || (self->super_type[2][0] == o[0] && self->super_type[2][1] == o[1] && self->super_type[2][2] == o[2] && self->super_type[2][3] == o[3]) || (self->super_type[3][0] == o[0] && self->super_type[3][1] == o[1] && self->super_type[3][2] == o[2] && self->super_type[3][3] == o[3]));
	return out;
}

static PyObject * mat4x4_richcompare(mat4x4 * self, PyObject * other, int comp_type) {
	glm::mat4x4 o2;

	if (!unpack_mat4x4(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
mat4x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	mat4x4 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new mat4x4Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	mat4x4Iter *rgstate = (mat4x4Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
mat4x4Iter_dealloc(mat4x4Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
mat4x4Iter_next(mat4x4Iter *rgstate)
{
	if (rgstate->seq_index < 4) {
		return pack_mvec4p(&rgstate->sequence->super_type[(int)rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * mat4x4_geniter(mat4x4 * self) {
	mat4x4Iter *rgstate = (mat4x4Iter *)((&mat4x4IterType)->tp_alloc(&mat4x4IterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
mat4x4_getbuffer(mat4x4* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat4x4);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 2;
	view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->shape[0] = 4;
	view->shape[1] = 4;
	view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
	view->strides[0] = sizeof(glm::mat4x4::col_type);
	view->strides[1] = sizeof(float);
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
mat4x4_releasebuffer(mat4x4* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
}
#pragma endregion

// type quat
#pragma region type quat
static void
quat_dealloc(quat* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
quat_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	quat *self = (quat *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->super_type = glm::quat();
	}

	return (PyObject *)self;
}

static int
quat_init(quat *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", "z", "w", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;
	PyObject * arg4 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOOO", const_cast<char**>(kwlist),
		&arg1, &arg2, &arg3, &arg4)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Quat_Check(arg1)) {
				glm::quat o;
				if (unpack_quat(arg1, &o)) {
					self->super_type = o;
					return 0;
				}
			}
			else if (PyGLM_Vec3_Check(arg1)) {
				glm::vec3 o;
				if (unpack_vec3(arg1, &o)) {
					self->super_type = glm::quat(o);
					return 0;
				}
			}
			else if (PyGLM_Mat3x3_Check(arg1)) {
				glm::mat3x3 o;
				if (unpack_mat3x3(arg1, &o)) {
					self->super_type = glm::quat(o);
					return 0;
				}
			}
			else if (PyGLM_Mat4x4_Check(arg1)) {
				glm::mat4x4 o;
				if (unpack_mat4x4(arg1, &o)) {
					self->super_type = glm::quat(o);
					return 0;
				}
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				glm::vec3 o;
				if (!unpack_vec3(arg2, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
					return -1;
				}
				self->super_type = glm::quat(PyGLM_Number_AsFloat(arg1), o);
				return 0;
			}
			glm::vec3 o;
			if (!unpack_vec3(arg1, &o)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}
			glm::vec3 o2;
			if (!unpack_vec3(arg2, &o2)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}
			self->super_type = glm::quat(o, o2);
			return 0;
		}
		if (arg4 == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
			self->super_type = glm::quat(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
	return -1;
}

// unaryfunc
static PyObject *
quat_neg(quat *obj)
{
	return pack_quat(-obj->super_type);
}

static PyObject *
quat_pos(quat *obj)
{
	return pack_quat(obj->super_type);
}

static PyObject *
quat_abs(quat *obj)
{
	return pack_quat(glm::quat(fabs(obj->super_type[3]), fabs(obj->super_type[0]), fabs(obj->super_type[1]), fabs(obj->super_type[2])));
}

// binaryfunc
static PyObject *
quat_add(PyObject *obj1, PyObject *obj2)
{
	glm::quat o;

	if (!unpack_quat(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm::quat' and ", obj1);
		return NULL;
	}

	glm::quat o2;

	if (!unpack_quat(obj2, &o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a quat
	return pack_quat(o + o2);
}

static PyObject *
quat_sub(PyObject *obj1, PyObject *obj2)
{
	glm::quat o;

	if (!unpack_quat(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm::quat' and ", obj1);
		return NULL;
	}

	glm::quat o2;

	if (!unpack_quat(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a quat
	return pack_quat(o - o2);
}

static PyObject *
quat_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		float f = PyGLM_Number_AsFloat(obj1);

		return pack_quat(f * ((quat*)obj2)->super_type);
	}

	if (PyGLM_Vec3_Check(obj1)) {
		glm::vec3 o;
		if (!unpack_vec3(obj1, &o)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::quat' and ", obj1);
			return NULL;
		}
		return pack_vec3(o * ((quat*)obj2)->super_type);
	}
	if (PyGLM_Vec4_Check(obj1)) {
		glm::vec4 o;
		if (!unpack_vec4(obj1, &o)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::quat' and ", obj1);
			return NULL;
		}
		return pack_vec4(o * ((quat*)obj2)->super_type);
	}

	glm::quat o;

	if (!unpack_quat(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::quat' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		return pack_quat(o * f);
	}

	if (PyGLM_Vec3_Check(obj2)) {
		glm::vec3 o2;
		if (!unpack_vec3(obj2, &o2)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::quat' and ", obj2);
			return NULL;
		}
		return pack_vec3(o * o2);
	}
	if (PyGLM_Vec4_Check(obj2)) {
		glm::vec4 o2;
		if (!unpack_vec4(obj2, &o2)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm::quat' and ", obj2);
			return NULL;
		}
		return pack_vec4(o * o2);
	}

	glm::quat o2;

	if (!unpack_quat(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a quat
	return pack_quat(o * o2);
}

static PyObject *
quat_div(PyObject *obj1, PyObject *obj2)
{
	glm::quat o;

	if (!unpack_quat(obj1, &o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm::quat' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		float f = PyGLM_Number_AsFloat(obj2);
		PyObject* out = pack_quat(o / f);
		return out;
	}
	Py_RETURN_NOTIMPLEMENTED;
}

// inplace
// binaryfunc
static PyObject *
quat_iadd(quat *self, PyObject *obj)
{
	quat * temp = (quat*)quat_add((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
quat_isub(quat *self, PyObject *obj)
{
	quat * temp = (quat*)quat_sub((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
quat_imul(quat *self, PyObject *obj)
{
	quat * temp = (quat*)quat_mul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
quat_idiv(quat *self, PyObject *obj)
{
	quat * temp = (quat*)quat_div((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
quat_str(quat* self)
{
	char * out = (char*)malloc((64) * sizeof(char));
	snprintf(out, 64, "quat( %12.6g, %12.6g, %12.6g, %12.6g )", self->super_type.x, self->super_type.y, self->super_type.z, self->super_type.w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t quat_len(quat * self) {
	return (Py_ssize_t)4;
}

static PyObject* quat_sq_item(quat * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble((double)self->super_type.x);
	case 1:
		return PyFloat_FromDouble((double)self->super_type.y);
	case 2:
		return PyFloat_FromDouble((double)self->super_type.z);
	case 3:
		return PyFloat_FromDouble((double)self->super_type.w);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int quat_sq_ass_item(quat * self, Py_ssize_t index, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	case 2:
		self->super_type.z = f;
		return 0;
	case 3:
		self->super_type.w = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int quat_contains(quat * self, PyObject * value) {
	float f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_AsFloat(value);
		return (int)(f == self->super_type.x || f == self->super_type.y || f == self->super_type.z || f == self->super_type.w);
	}
	return 0;

}

static PyObject * quat_richcompare(quat * self, PyObject * other, int comp_type) {
	glm::quat o2;

	if (!unpack_quat(other, &o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

static PyObject *
quatIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	quat *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new quatIter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	quatIter *rgstate = (quatIter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
quatIter_dealloc(quatIter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
quatIter_next(quatIter *rgstate)
{
	if (rgstate->seq_index < 4) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.x);
		case 1:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.y);
		case 2:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.z);
		case 3:
			return PyFloat_FromDouble((double)rgstate->sequence->super_type.w);
		}
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * quat_geniter(quat * self) {
	quatIter *rgstate = (quatIter *)((&quatIterType)->tp_alloc(&quatIterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static int
quat_getbuffer(quat* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}

	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0];
	view->len = sizeof(glm::quat);
	view->readonly = 0;
	view->itemsize = sizeof(float);
	view->format = const_cast<char*>("f");
	view->ndim = 1;
	view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
	view->shape[0] = 4;
	view->strides = &view->itemsize;
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void
quat_releasebuffer(quat* self, Py_buffer* view) {
	free(view->shape);
}
#pragma endregion


#pragma region macro generator functions
#define PyGLM_MAKE_GLM_FUNC_VF_VF(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2)));\
	}\
	char vecType = PyGLM_Vec_GetTypeCheck(arg1);\
	char vecType2 = PyGLM_Vec_GetTypeCheck(arg2);\
	if (vecType != vecType2 || vecType == PyGLM_TYPE_NONE) {\
		PyGLM_TYPEERROR_2O("invalid argument types for " #NAME "(): ", arg1, arg2);\
		return NULL;\
	}\
	if (vecType == PyGLM_TYPE_VEC2) {\
		glm::vec2 o, o2;\
		unpack_vec2(arg1, &o);\
		unpack_vec2(arg2, &o2);\
		return pack_vec2(glm::NAME(o, o2));\
	}\
	if (vecType == PyGLM_TYPE_VEC3) {\
		glm::vec3 o, o2;\
		unpack_vec3(arg1, &o);\
		unpack_vec3(arg2, &o2);\
		return pack_vec3(glm::NAME(o, o2));\
	}\
	glm::vec4 o, o2;\
	unpack_vec4(arg1, &o);\
	unpack_vec4(arg2, &o2);\
	return pack_vec4(glm::NAME(o, o2));\
}

#define PyGLM_MAKE_GLM_FUNC_VF(NAME) \
static PyObject* NAME##_(PyObject* self, PyObject* arg) { \
	if (PyGLM_Number_Check(arg)) { \
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg))); \
	} \
	void* o = NULL; \
	char vecType = unpack_vec(arg, &o); \
	if (vecType == PyGLM_TYPE_VEC2) { \
		PyObject* out = pack_vec2(glm::NAME(*(glm::vec2*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC3) { \
		PyObject* out = pack_vec3(glm::NAME(*(glm::vec3*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC4) { \
		PyObject* out = pack_vec4(glm::NAME(*(glm::vec4*)o)); \
		free(o); \
		return out; \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg); \
	return NULL; \
}
#define PyGLM_MAKE_GLM_FUNC_Q4VF(NAME) \
static PyObject* NAME##_(PyObject* self, PyObject* arg) { \
	if (PyGLM_Number_Check(arg)) { \
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg))); \
	} \
	if (PyGLM_Quat_Check(arg)) { \
		glm::quat o; \
		unpack_quat(arg, &o); \
		return pack_vec4(glm::NAME(o)); \
	} \
	void* o = NULL; \
	char vecType = unpack_vec(arg, &o); \
	if (vecType == PyGLM_TYPE_VEC2) { \
		PyObject* out = pack_vec2(glm::NAME(*(glm::vec2*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC3) { \
		PyObject* out = pack_vec3(glm::NAME(*(glm::vec3*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC4) { \
		PyObject* out = pack_vec4(glm::NAME(*(glm::vec4*)o)); \
		free(o); \
		return out; \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg); \
	return NULL; \
}

#define PyGLM_MAKE_GLM_FUNC_QV(NAME) \
static PyObject* NAME##_(PyObject* self, PyObject* arg) { \
	if (PyGLM_Quat_Check(arg)) { \
		glm::quat o; \
		unpack_quat(arg, &o); \
		return pack_quat(glm::NAME(o)); \
	} \
	void* o = NULL; \
	char vecType = unpack_vec(arg, &o); \
	if (vecType == PyGLM_TYPE_VEC2) { \
		PyObject* out = pack_vec2(glm::NAME(*(glm::vec2*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC3) { \
		PyObject* out = pack_vec3(glm::NAME(*(glm::vec3*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC4) { \
		PyObject* out = pack_vec4(glm::NAME(*(glm::vec4*)o)); \
		free(o); \
		return out; \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg); \
	return NULL; \
}
#define PyGLM_MAKE_GLM_FUNC_VVF_VFF(NAME) \
static PyObject* \
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {\
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2)));\
	}\
	char vecType = PyGLM_Vec_GetTypeCheck(arg1); \
	if (vecType == PyGLM_TYPE_VEC2) {\
		glm::vec2 o;\
		unpack_vec2(arg1, &o);\
		if (PyGLM_Number_Check(arg2)) {\
			return pack_vec2(glm::NAME(o, PyGLM_Number_AsFloat(arg2)));\
		}\
		if (PyGLM_Vec2_Check(arg2)) {\
			glm::vec2 o2;\
			unpack_vec2(arg2, &o2);\
			return pack_vec2(glm::NAME(o, o2));\
		}\
	}\
	if (vecType == PyGLM_TYPE_VEC3) {\
		glm::vec3 o;\
		unpack_vec3(arg1, &o);\
		if (PyGLM_Number_Check(arg2)) {\
			return pack_vec3(glm::NAME(o, PyGLM_Number_AsFloat(arg2)));\
		}\
		if (PyGLM_Vec3_Check(arg2)) {\
			glm::vec3 o2;\
			unpack_vec3(arg2, &o2);\
			return pack_vec3(glm::NAME(o, o2));\
		}\
	}\
	if (vecType == PyGLM_TYPE_VEC4) {\
		glm::vec4 o;\
		unpack_vec4(arg1, &o);\
		if (PyGLM_Number_Check(arg2)) {\
			return pack_vec4(glm::NAME(o, PyGLM_Number_AsFloat(arg2)));\
		}\
		if (PyGLM_Vec4_Check(arg2)) {\
			glm::vec4 o2;\
			unpack_vec4(arg2, &o2);\
			return pack_vec4(glm::NAME(o, o2));\
		}\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_VVF_VFF_VFF(NAME) \
static PyObject* \
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));\
	}\
	char vecType = PyGLM_Vec_GetTypeCheck(arg1);\
	if (vecType == PyGLM_TYPE_VEC2) {\
		glm::vec2 o;\
		unpack_vec2(arg1, &o);\
		if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
			return pack_vec2(glm::NAME(o, PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));\
		}\
		if (PyGLM_Vec2_Check(arg2) && PyGLM_Vec2_Check(arg3)) {\
			glm::vec2 o2, o3;\
			unpack_vec2(arg2, &o2);\
			unpack_vec2(arg3, &o3);\
			return pack_vec2(glm::NAME(o, o2, o3));\
		}\
	}\
	if (vecType == PyGLM_TYPE_VEC3) {\
		glm::vec3 o;\
		unpack_vec3(arg1, &o);\
		if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
			return pack_vec3(glm::NAME(o, PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));\
		}\
		if (PyGLM_Vec3_Check(arg2) && PyGLM_Vec3_Check(arg3)) {\
			glm::vec3 o2, o3;\
			unpack_vec3(arg2, &o2);\
			unpack_vec3(arg3, &o3);\
			return pack_vec3(glm::NAME(o, o2, o3));\
		}\
	}\
	if (vecType == PyGLM_TYPE_VEC4) {\
		glm::vec4 o;\
		unpack_vec4(arg1, &o);\
		if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
			return pack_vec4(glm::NAME(o, PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));\
		}\
		if (PyGLM_Vec4_Check(arg2) && PyGLM_Vec4_Check(arg3)) {\
			glm::vec4 o2, o3;\
			unpack_vec4(arg2, &o2);\
			unpack_vec4(arg3, &o3);\
			return pack_vec4(glm::NAME(o, o2, o3));\
		}\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_VF_VF_VF(NAME) \
static PyObject* \
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));\
	}\
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && PyGLM_Vec2_Check(arg3)) {\
		glm::vec2 o, o2, o3;\
		unpack_vec2(arg1, &o);\
		unpack_vec2(arg2, &o2);\
		unpack_vec2(arg3, &o3);\
		return pack_vec2(glm::NAME(o, o2, o3));\
	}\
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && PyGLM_Vec3_Check(arg3)) {\
		glm::vec3 o, o2, o3;\
		unpack_vec3(arg1, &o);\
		unpack_vec3(arg2, &o2);\
		unpack_vec3(arg3, &o3);\
		return pack_vec3(glm::NAME(o, o2, o3));\
	}\
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && PyGLM_Vec4_Check(arg3)) {\
		glm::vec4 o, o2, o3;\
		unpack_vec4(arg1, &o);\
		unpack_vec4(arg2, &o2);\
		unpack_vec4(arg3, &o3);\
		return pack_vec4(glm::NAME(o, o2, o3));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_VFrF(NAME) \
static PyObject* NAME##_(PyObject* self, PyObject* arg) { \
	if (PyGLM_Number_Check(arg)) { \
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg))); \
	} \
	void* o = NULL; \
	char vecType = unpack_vec(arg, &o); \
	if (vecType == PyGLM_TYPE_VEC2) { \
		PyObject* out = PyFloat_FromDouble((double)glm::NAME(*(glm::vec2*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC3) { \
		PyObject* out = PyFloat_FromDouble((double)glm::NAME(*(glm::vec3*)o)); \
		free(o); \
		return out; \
	} \
	if (vecType == PyGLM_TYPE_VEC4) { \
		PyObject* out = PyFloat_FromDouble((double)glm::NAME(*(glm::vec4*)o)); \
		free(o); \
		return out; \
	} \
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg); \
	return NULL; \
}
#define PyGLM_MAKE_GLM_FUNC_VF_VFrF(NAME)\
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {\
		return PyFloat_FromDouble((double)glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2)));\
	}\
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {\
		glm::vec2 o, o2;\
		unpack_vec2(arg1, &o);\
		unpack_vec2(arg2, &o2);\
		return PyFloat_FromDouble((double)glm::NAME(o, o2));\
	}\
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {\
		glm::vec3 o, o2;\
		unpack_vec3(arg1, &o);\
		unpack_vec3(arg2, &o2);\
		return PyFloat_FromDouble((double)glm::NAME(o, o2));\
	}\
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {\
		glm::vec4 o, o2;\
		unpack_vec4(arg1, &o);\
		unpack_vec4(arg2, &o2);\
		return PyFloat_FromDouble((double)glm::NAME(o, o2));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_M(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	if (PyGLM_Mat2x2_Check(arg)) {\
		glm::mat2x2 o;\
		unpack_mat2x2(arg, &o);\
		return pack_mat2x2(glm::NAME(o));\
	}\
	if (PyGLM_Mat2x3_Check(arg)) {\
		glm::mat2x3 o;\
		unpack_mat2x3(arg, &o);\
		return pack_mat2x3(glm::NAME(o));\
	}\
	if (PyGLM_Mat2x4_Check(arg)) {\
		glm::mat2x4 o;\
		unpack_mat2x4(arg, &o);\
		return pack_mat2x4(glm::NAME(o));\
	}\
	if (PyGLM_Mat3x2_Check(arg)) {\
		glm::mat3x2 o;\
		unpack_mat3x2(arg, &o);\
		return pack_mat3x2(glm::NAME(o));\
	}\
	if (PyGLM_Mat3x3_Check(arg)) {\
		glm::mat3x3 o;\
		unpack_mat3x3(arg, &o);\
		return pack_mat3x3(glm::NAME(o));\
	}\
	if (PyGLM_Mat3x4_Check(arg)) {\
		glm::mat3x4 o;\
		unpack_mat3x4(arg, &o);\
		return pack_mat3x4(glm::NAME(o));\
	}\
	if (PyGLM_Mat4x2_Check(arg)) {\
		glm::mat4x2 o;\
		unpack_mat4x2(arg, &o);\
		return pack_mat4x2(glm::NAME(o));\
	}\
	if (PyGLM_Mat4x3_Check(arg)) {\
		glm::mat4x3 o;\
		unpack_mat4x3(arg, &o);\
		return pack_mat4x3(glm::NAME(o));\
	}\
	if (PyGLM_Mat4x4_Check(arg)) {\
		glm::mat4x4 o;\
		unpack_mat4x4(arg, &o);\
		return pack_mat4x4(glm::NAME(o));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_MsqQ(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	if (PyGLM_Mat2x2_Check(arg)) {\
		glm::mat2x2 o;\
		unpack_mat2x2(arg, &o);\
		return pack_mat2x2(glm::NAME(o));\
	}\
	if (PyGLM_Mat3x3_Check(arg)) {\
		glm::mat3x3 o;\
		unpack_mat3x3(arg, &o);\
		return pack_mat3x3(glm::NAME(o));\
	}\
	if (PyGLM_Mat4x4_Check(arg)) {\
		glm::mat4x4 o;\
		unpack_mat4x4(arg, &o);\
		return pack_mat4x4(glm::NAME(o));\
	}\
	if (PyGLM_Quat_Check(arg)) {\
		glm::quat o;\
		unpack_quat(arg, &o);\
		return pack_quat(glm::NAME(o));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_MrF(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	if (PyGLM_Mat2x2_Check(arg)) {\
		glm::mat2x2 o;\
		unpack_mat2x2(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat2x3_Check(arg)) {\
		glm::mat2x3 o;\
		unpack_mat2x3(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat2x4_Check(arg)) {\
		glm::mat2x4 o;\
		unpack_mat2x4(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat3x2_Check(arg)) {\
		glm::mat3x2 o;\
		unpack_mat3x2(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat3x3_Check(arg)) {\
		glm::mat3x3 o;\
		unpack_mat3x3(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat3x4_Check(arg)) {\
		glm::mat3x4 o;\
		unpack_mat3x4(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat4x2_Check(arg)) {\
		glm::mat4x2 o;\
		unpack_mat4x2(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat4x3_Check(arg)) {\
		glm::mat4x3 o;\
		unpack_mat4x3(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat4x4_Check(arg)) {\
		glm::mat4x4 o;\
		unpack_mat4x4(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_MsqrF(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	if (PyGLM_Mat2x2_Check(arg)) {\
		glm::mat2x2 o;\
		unpack_mat2x2(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat3x3_Check(arg)) {\
		glm::mat3x3 o;\
		unpack_mat3x3(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	if (PyGLM_Mat4x4_Check(arg)) {\
		glm::mat4x4 o;\
		unpack_mat4x4(arg, &o);\
		return PyFloat_FromDouble((double)glm::NAME(o));\
	}\
	PyGLM_TYPEERROR_O("invalid argument type for " #NAME "(): ", arg);\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_M_M(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	if (PyGLM_Mat2x2_Check(arg1) && PyGLM_Mat2x2_Check(arg2)) {\
		glm::mat2x2 o, o2;\
		unpack_mat2x2(arg1, &o);\
		unpack_mat2x2(arg2, &o2);\
		return pack_mat2x2(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat2x3_Check(arg1) && PyGLM_Mat2x3_Check(arg2)) {\
		glm::mat2x3 o, o2;\
		unpack_mat2x3(arg1, &o);\
		unpack_mat2x3(arg2, &o2);\
		return pack_mat2x3(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat2x4_Check(arg1) && PyGLM_Mat2x4_Check(arg2)) {\
		glm::mat2x4 o, o2;\
		unpack_mat2x4(arg1, &o);\
		unpack_mat2x4(arg2, &o2);\
		return pack_mat2x4(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat3x2_Check(arg1) && PyGLM_Mat3x2_Check(arg2)) {\
		glm::mat3x2 o, o2;\
		unpack_mat3x2(arg1, &o);\
		unpack_mat3x2(arg2, &o2);\
		return pack_mat3x2(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat3x3_Check(arg1) && PyGLM_Mat3x3_Check(arg2)) {\
		glm::mat3x3 o, o2;\
		unpack_mat3x3(arg1, &o);\
		unpack_mat3x3(arg2, &o2);\
		return pack_mat3x3(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat3x4_Check(arg1) && PyGLM_Mat3x4_Check(arg2)) {\
		glm::mat3x4 o, o2;\
		unpack_mat3x4(arg1, &o);\
		unpack_mat3x4(arg2, &o2);\
		return pack_mat3x4(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat4x2_Check(arg1) && PyGLM_Mat4x2_Check(arg2)) {\
		glm::mat4x2 o, o2;\
		unpack_mat4x2(arg1, &o);\
		unpack_mat4x2(arg2, &o2);\
		return pack_mat4x2(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat4x3_Check(arg1) && PyGLM_Mat4x3_Check(arg2)) {\
		glm::mat4x3 o, o2;\
		unpack_mat4x3(arg1, &o);\
		unpack_mat4x3(arg2, &o2);\
		return pack_mat4x3(glm::NAME(o, o2));\
	}\
	if (PyGLM_Mat4x4_Check(arg1) && PyGLM_Mat4x4_Check(arg2)) {\
		glm::mat4x4 o, o2;\
		unpack_mat4x4(arg1, &o);\
		unpack_mat4x4(arg2, &o2);\
		return pack_mat4x4(glm::NAME(o, o2));\
	}\
	PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_rF(NAME)\
static PyObject* NAME##_(PyObject* self, PyObject* narg) { return PyFloat_FromDouble(glm::NAME<double>()); }

#define PyGLM_MAKE_GLM_FUNC_M4_V3rM4(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	glm::mat4x4 m;\
	glm::vec3 v;\
	if (!unpack_mat4x4(arg1, &m) || !unpack_vec3(arg2, &v)) {\
		PyGLM_TYPEERROR_2O("invalid argument type(s) for " #NAME "(): ", arg1, arg2);\
		return NULL;\
	}\
	return pack_mat4x4(glm::NAME(m, v));\
}
#define PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;\
	PyGLM_Arg_Unpack_6O(args, #NAME, arg1, arg2, arg3, arg4, arg5, arg6);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) {\
		return pack_mat4x4(glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4;\
	PyGLM_Arg_Unpack_4O(args, #NAME, arg1, arg2, arg3, arg4);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {\
		return pack_mat4x4(glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}

#define PyGLM_MAKE_GLM_FUNC_F_F_F_F_FrM4(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;\
	PyGLM_Arg_Unpack_5O(args, #NAME, arg1, arg2, arg3, arg4, arg5);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)&& PyGLM_Number_Check(arg5)) {\
		return pack_mat4x4(glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_F_F_FrM4(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {\
		return pack_mat4x4(glm::NAME(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(NAME)\
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3, *arg4;\
	PyGLM_Arg_Unpack_4O(args, #NAME, arg1, arg2, arg3, arg4);\
	glm::vec3 o;\
	glm::mat4x4 o2, o3;\
	glm::vec4 o4;\
	if (!unpack_vec3(arg1, &o) || !unpack_mat4x4(arg2, &o2) || !unpack_mat4x4(arg3, &o3) || !unpack_vec4(arg4, &o4)) {\
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
		return NULL;\
	}\
	return pack_vec3(glm::NAME(o, o2, o3, o4));\
}
#define PyGLM_MAKE_GLM_FUNC_V3_V3_V3rM4(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	glm::vec3 o, o2, o3;\
	if (!unpack_vec3(arg1, &o) || !unpack_vec3(arg2, &o2) || !unpack_vec3(arg3, &o3)) {\
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
		return NULL;\
	}\
	return pack_mat4x4(glm::NAME(o, o2, o3));\
}
#define PyGLM_MAKE_GLM_FUNC_V3_V3rQ(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2;\
	PyGLM_Arg_Unpack_2O(args, #NAME, arg1, arg2);\
	glm::vec3 o, o2;\
	if (!unpack_vec3(arg1, &o) || !unpack_vec3(arg2, &o2)) {\
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
		return NULL;\
	}\
	return pack_quat(glm::NAME(o, o2));\
}
#define PyGLM_MAKE_GLM_FUNC_Q_Q_FrQ(NAME) \
static PyObject*\
NAME##_(PyObject* self, PyObject* args) {\
	PyObject *arg1, *arg2, *arg3;\
	PyGLM_Arg_Unpack_3O(args, #NAME, arg1, arg2, arg3);\
	glm::quat o, o2;\
	if (!unpack_quat(arg1, &o) || !unpack_quat(arg2, &o2) || !PyGLM_Number_Check(arg3)) {\
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
		return NULL;\
	}\
	return pack_quat(glm::NAME(o, o2, PyGLM_Number_AsFloat(arg3)));\
}
#define PyGLM_MAKE_GLM_FUNC_Q(NAME)\
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	glm::quat q;\
	if (unpack_quat(arg, &q)) {\
		return pack_quat(glm::NAME(q));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_QrV3(NAME)\
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	glm::quat q;\
	if (unpack_quat(arg, &q)) {\
		return pack_vec3(glm::NAME(q));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#define PyGLM_MAKE_GLM_FUNC_QrF(NAME)\
static PyObject*\
NAME##_(PyObject* self, PyObject* arg) {\
	glm::quat q;\
	if (unpack_quat(arg, &q)) {\
		return PyFloat_FromDouble((double)glm::NAME(q));\
	}\
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " #NAME "()");\
	return NULL;\
}
#pragma endregion

static PyObject*
packDouble2x32_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return PyFloat_FromDouble(glm::packDouble2x32((glm::uvec2)o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packDouble2x32(): ", arg);
	return NULL;
}

static PyObject*
packHalf2x16_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return PyLong_FromLong((long)glm::packHalf2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packHalf2x16(): ", arg);
	return NULL;
}

static PyObject*
packSnorm2x16_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return PyLong_FromLong((long)glm::packSnorm2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
packSnorm4x8_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec4_Check(arg)) {
		glm::vec4 o;
		unpack_vec4(arg, &o);
		return PyLong_FromLong((long)glm::packSnorm4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packSnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
packUnorm2x16_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return PyLong_FromLong((long)glm::packUnorm2x16(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
packUnorm4x8_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec4_Check(arg)) {
		glm::vec4 o;
		unpack_vec4(arg, &o);
		return PyLong_FromLong((long)glm::packUnorm4x8(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for packUnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
unpackDouble2x32_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack_vec2(glm::unpackDouble2x32(PyGLM_Number_AsDouble(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackDouble2x32(): ", arg);
	return NULL;
}

static PyObject*
unpackHalf2x16_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack_vec2(glm::unpackHalf2x16((glm::uint)PyGLM_Number_AsLong(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackHalf2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm2x16_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack_vec2(glm::unpackSnorm2x16((glm::uint)PyGLM_Number_AsLong(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm2x16_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack_vec2(glm::unpackUnorm2x16((glm::uint)PyGLM_Number_AsLong(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm2x16(): ", arg);
	return NULL;
}

static PyObject*
unpackSnorm4x8_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack_vec4(glm::unpackSnorm4x8((glm::uint)PyGLM_Number_AsLong(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackSnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
unpackUnorm4x8_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return pack_vec4(glm::unpackUnorm4x8((glm::uint)PyGLM_Number_AsLong(arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for unpackUnorm4x8(): ", arg);
	return NULL;
}

static PyObject*
uaddCarry_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "uaddCarry", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "uaddCarry() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && Py_TYPE(arg3) == &vec2Type) {
		glm::vec2 o, o2;
		unpack_vec2(arg1, &o);
		unpack_vec2(arg2, &o2);
		glm::uvec2 Carry;
		glm::uvec2 out = glm::uaddCarry((glm::uvec2)o, (glm::uvec2)o2, Carry);
		((vec2*)arg3)->super_type = Carry;
		return pack_vec2(out);
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && Py_TYPE(arg3) == &vec3Type) {
		glm::vec3 o, o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		glm::uvec3 Carry;
		glm::uvec3 out = glm::uaddCarry((glm::uvec3)o, (glm::uvec3)o2, Carry);
		((vec3*)arg3)->super_type = Carry;
		return pack_vec3(out);
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && Py_TYPE(arg3) == &vec4Type) {
		glm::vec4 o, o2;
		unpack_vec4(arg1, &o);
		unpack_vec4(arg2, &o2);
		glm::uvec4 Carry;
		glm::uvec4 out = glm::uaddCarry((glm::uvec4)o, (glm::uvec4)o2, Carry);
		((vec4*)arg3)->super_type = Carry;
		return pack_vec4(out);
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for uaddCarry()");
	return NULL;
}

static PyObject*
usubBorrow_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "usubBorrow", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "usubBorrow() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && Py_TYPE(arg3) == &vec2Type) {
		glm::vec2 o, o2;
		unpack_vec2(arg1, &o);
		unpack_vec2(arg2, &o2);
		glm::uvec2 Borrow;
		glm::uvec2 out = glm::usubBorrow((glm::uvec2)o, (glm::uvec2)o2, Borrow);
		((vec2*)arg3)->super_type = Borrow;
		return pack_vec2(out);
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && Py_TYPE(arg3) == &vec3Type) {
		glm::vec3 o, o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		glm::uvec3 Borrow;
		glm::uvec3 out = glm::usubBorrow((glm::uvec3)o, (glm::uvec3)o2, Borrow);
		((vec3*)arg3)->super_type = Borrow;
		return pack_vec3(out);
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && Py_TYPE(arg3) == &vec4Type) {
		glm::vec4 o, o2;
		unpack_vec4(arg1, &o);
		unpack_vec4(arg2, &o2);
		glm::uvec4 Borrow;
		glm::uvec4 out = glm::usubBorrow((glm::uvec4)o, (glm::uvec4)o2, Borrow);
		((vec4*)arg3)->super_type = Borrow;
		return pack_vec4(out);
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for usubBorrow()");
	return NULL;
}

static PyObject*
umulExtended_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "umulExtended", arg1, arg2, arg3, arg4);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "umulExtended() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && Py_TYPE(arg3) == &vec2Type && Py_TYPE(arg4) == &vec2Type) {
		glm::vec2 o, o2;
		unpack_vec2(arg1, &o);
		unpack_vec2(arg2, &o2);
		glm::uvec2 msb, lsb;
		glm::umulExtended((glm::uvec2)o, (glm::uvec2)o2, msb, lsb);
		((vec2*)arg3)->super_type = msb;
		((vec2*)arg4)->super_type = lsb;
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && Py_TYPE(arg3) == &vec3Type && Py_TYPE(arg4) == &vec3Type) {
		glm::vec3 o, o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		glm::uvec3 msb, lsb;
		glm::umulExtended((glm::uvec3)o, (glm::uvec3)o2, msb, lsb);
		((vec3*)arg3)->super_type = msb;
		((vec3*)arg4)->super_type = lsb;
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && Py_TYPE(arg3) == &vec4Type && Py_TYPE(arg4) == &vec4Type) {
		glm::vec4 o, o2;
		unpack_vec4(arg1, &o);
		unpack_vec4(arg2, &o2);
		glm::uvec4 msb, lsb;
		glm::umulExtended((glm::uvec4)o, (glm::uvec4)o2, msb, lsb);
		((vec4*)arg3)->super_type = msb;
		((vec4*)arg4)->super_type = lsb;
		Py_RETURN_NONE;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for umulExtended()");
	return NULL;
}

static PyObject*
imulExtended_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "imulExtended", arg1, arg2, arg3, arg4);
	if (PyGLM_Number_Check(arg1)) {
		PyErr_SetString(PyExc_TypeError, "imulExtended() doesn't accept integer inputs in PyGLM");
		return NULL;
	}
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && Py_TYPE(arg3) == &vec2Type && Py_TYPE(arg4) == &vec2Type) {
		glm::vec2 o, o2;
		unpack_vec2(arg1, &o);
		unpack_vec2(arg2, &o2);
		glm::ivec2 msb, lsb;
		glm::imulExtended((glm::ivec2)o, (glm::ivec2)o2, msb, lsb);
		((vec2*)arg3)->super_type = msb;
		((vec2*)arg4)->super_type = lsb;
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && Py_TYPE(arg3) == &vec3Type && Py_TYPE(arg4) == &vec3Type) {
		glm::vec3 o, o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		glm::ivec3 msb, lsb;
		glm::imulExtended((glm::ivec3)o, (glm::ivec3)o2, msb, lsb);
		((vec3*)arg3)->super_type = msb;
		((vec3*)arg4)->super_type = lsb;
		Py_RETURN_NONE;
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && Py_TYPE(arg3) == &vec4Type && Py_TYPE(arg4) == &vec4Type) {
		glm::vec4 o, o2;
		unpack_vec4(arg1, &o);
		unpack_vec4(arg2, &o2);
		glm::ivec4 msb, lsb;
		glm::imulExtended((glm::ivec4)o, (glm::ivec4)o2, msb, lsb);
		((vec4*)arg3)->super_type = msb;
		((vec4*)arg4)->super_type = lsb;
		Py_RETURN_NONE;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for imulExtended()");
	return NULL;
}

static PyObject*
bitfieldExtract_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "bitfieldExtract", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		int i = (int)PyGLM_Number_AsLong(arg2), i2 = (int)PyGLM_Number_AsLong(arg3);
		if (PyGLM_Number_Check(arg1)) {
			return PyLong_FromLong(glm::bitfieldExtract(PyGLM_Number_AsLong(arg1), i, i2));
		}
		if (PyGLM_Vec2_Check(arg1)) {
			glm::vec2 o;
			unpack_vec2(arg1, &o);
			return pack_vec2(glm::bitfieldExtract((glm::ivec2)o, i, i2));
		}
		if (PyGLM_Vec3_Check(arg1)) {
			glm::vec3 o;
			unpack_vec3(arg1, &o);
			return pack_vec3(glm::bitfieldExtract((glm::ivec3)o, i, i2));
		}
		if (PyGLM_Vec4_Check(arg1)) {
			glm::vec4 o;
			unpack_vec4(arg1, &o);
			return pack_vec4(glm::bitfieldExtract((glm::ivec4)o, i, i2));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldExtract()");
	return NULL;
}

static PyObject*
bitfieldInsert_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4;
	PyGLM_Arg_Unpack_4O(args, "bitfieldInsert", arg1, arg2, arg3, arg4);
	if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		int i = (int)PyGLM_Number_AsLong(arg3), i2 = (int)PyGLM_Number_AsLong(arg4);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return PyLong_FromLong(glm::bitfieldInsert(PyGLM_Number_AsLong(arg1), PyGLM_Number_AsLong(arg2), i, i2));
		}
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return pack_vec2(glm::bitfieldInsert((glm::ivec2)o, (glm::ivec2)o2, i, i2));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return pack_vec3(glm::bitfieldInsert((glm::ivec3)o, (glm::ivec3)o2, i, i2));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return pack_vec4(glm::bitfieldInsert((glm::ivec4)o, (glm::ivec4)o2, i, i2));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for bitfieldInsert()");
	return NULL;
}

static PyObject* bitfieldReverse_(PyObject* self, PyObject* arg) { 
	if (PyGLM_Number_Check(arg)) { 
		return PyLong_FromLong(glm::bitfieldReverse(static_cast<unsigned long>(PyGLM_Number_AsLong(arg)))); 
	} 

	void* o = NULL; 
	char vecType = unpack_vec(arg, &o); 
	if (vecType == PyGLM_TYPE_VEC2) { 
		PyObject* out = pack_vec2(glm::bitfieldReverse((glm::uvec2)*(glm::vec2*)o)); 
		free(o); 
		return out; 
	} 
	if (vecType == PyGLM_TYPE_VEC3) { 
		PyObject* out = pack_vec3(glm::bitfieldReverse((glm::uvec3)*(glm::vec3*)o));
		free(o); 
		return out; 
	} 
	if (vecType == PyGLM_TYPE_VEC4) { 
		PyObject* out = pack_vec4(glm::bitfieldReverse((glm::uvec4)*(glm::vec4*)o));
		free(o); 
		return out; 
	} 
	PyGLM_TYPEERROR_O("invalid argument type for bitfieldReverse(): ", arg); 
	return NULL; 
}

static PyObject*
bitCount_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return PyLong_FromLong(glm::bitCount(PyGLM_Number_AsLong(arg)));
	}
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return pack_vec2(glm::bitCount((glm::ivec2)o));
	}
	if (PyGLM_Vec3_Check(arg)) {
		glm::vec3 o;
		unpack_vec3(arg, &o);
		return pack_vec3(glm::bitCount((glm::ivec3)o));
	}
	if (PyGLM_Vec4_Check(arg)) {
		glm::vec4 o;
		unpack_vec4(arg, &o);
		return pack_vec4(glm::bitCount((glm::ivec4)o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for bitCount(): ", arg);
	return NULL;
}

static PyObject*
findLSB_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return PyLong_FromLong(glm::findLSB(PyGLM_Number_AsLong(arg)));
	}
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return pack_vec2(glm::findLSB((glm::ivec2)o));
	}
	if (PyGLM_Vec3_Check(arg)) {
		glm::vec3 o;
		unpack_vec3(arg, &o);
		return pack_vec3(glm::findLSB((glm::ivec3)o));
	}
	if (PyGLM_Vec4_Check(arg)) {
		glm::vec4 o;
		unpack_vec4(arg, &o);
		return pack_vec4(glm::findLSB((glm::ivec4)o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for findLSB(): ", arg);
	return NULL;
}

static PyObject*
findMSB_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		return PyLong_FromLong(glm::findMSB(PyGLM_Number_AsLong(arg)));
	}
	if (PyGLM_Vec2_Check(arg)) {
		glm::vec2 o;
		unpack_vec2(arg, &o);
		return pack_vec2(glm::findMSB((glm::ivec2)o));
	}
	if (PyGLM_Vec3_Check(arg)) {
		glm::vec3 o;
		unpack_vec3(arg, &o);
		return pack_vec3(glm::findMSB((glm::ivec3)o));
	}
	if (PyGLM_Vec4_Check(arg)) {
		glm::vec4 o;
		unpack_vec4(arg, &o);
		return pack_vec4(glm::findMSB((glm::ivec4)o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for findMSB(): ", arg);
	return NULL;
}

static PyObject*
equal(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "equal", arg1, arg2);
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec2(glm::equal(*(glm::vec2*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec3(glm::equal(*(glm::vec3*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::equal(*(glm::vec4*)o, o2));
		free(o);
		return out;
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o1, o2;
		if (!unpack_quat(arg1, &o1) || !unpack_quat(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::equal(o1, o2));
		return out;
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
	return NULL;
}

static PyObject*
notEqual(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "notEqual", arg1, arg2);
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec2(glm::notEqual(*(glm::vec2*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec3(glm::notEqual(*(glm::vec3*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::notEqual(*(glm::vec4*)o, o2));
		free(o);
		return out;
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o1, o2;
		if (!unpack_quat(arg1, &o1) || !unpack_quat(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::notEqual(o1, o2));
		return out;
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
	return NULL;
}

static PyObject*
lessThan(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "lessThan", arg1, arg2);
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec2(glm::lessThan(*(glm::vec2*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec3(glm::lessThan(*(glm::vec3*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::lessThan(*(glm::vec4*)o, o2));
		free(o);
		return out;
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o1, o2;
		if (!unpack_quat(arg1, &o1) || !unpack_quat(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::lessThan(o1, o2));
		return out;
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThan(): ", arg1, arg2);
	return NULL;
}

static PyObject*
lessThanEqual(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "lessThanEqual", arg1, arg2);
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec2(glm::lessThanEqual(*(glm::vec2*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec3(glm::lessThanEqual(*(glm::vec3*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::lessThanEqual(*(glm::vec4*)o, o2));
		free(o);
		return out;
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o1, o2;
		if (!unpack_quat(arg1, &o1) || !unpack_quat(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::lessThanEqual(o1, o2));
		return out;
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for lessThanEqual(): ", arg1, arg2);
	return NULL;
}

static PyObject*
greaterThan(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "greaterThan", arg1, arg2);
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec2(glm::greaterThan(*(glm::vec2*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec3(glm::greaterThan(*(glm::vec3*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::greaterThan(*(glm::vec4*)o, o2));
		free(o);
		return out;
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o1, o2;
		if (!unpack_quat(arg1, &o1) || !unpack_quat(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThan(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::greaterThan(o1, o2));
		return out;
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThan(): ", arg1, arg2);
	return NULL;
}

static PyObject*
greaterThanEqual(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "greaterThanEqual", arg1, arg2);
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o2;
		if (!unpack_vec2(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec2(glm::greaterThanEqual(*(glm::vec2*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o2;
		if (!unpack_vec3(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec3(glm::greaterThanEqual(*(glm::vec3*)o, o2));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o2;
		if (!unpack_vec4(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::greaterThanEqual(*(glm::vec4*)o, o2));
		free(o);
		return out;
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o1, o2;
		if (!unpack_quat(arg1, &o1) || !unpack_quat(arg2, &o2)) {
			PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThanEqual(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_vec4(glm::greaterThanEqual(o1, o2));
		return out;
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for greaterThanEqual(): ", arg1, arg2);
	return NULL;
}

static PyObject*
any(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char vecType = unpack_vec(arg, &o);
	switch (vecType) {
	case PyGLM_TYPE_VEC2:
		if (((glm::vec2*)o)->x || ((glm::vec2*)o)->y) {
			free(o);
			Py_RETURN_TRUE;
		}
		free(o);
		Py_RETURN_FALSE;
	case PyGLM_TYPE_VEC3:
		if (((glm::vec3*)o)->x || ((glm::vec3*)o)->y || ((glm::vec3*)o)->z) {
			free(o);
			Py_RETURN_TRUE;
		}
		free(o);
		Py_RETURN_FALSE;
	case PyGLM_TYPE_VEC4:
		if (((glm::vec4*)o)->x || ((glm::vec4*)o)->y || ((glm::vec4*)o)->z || ((glm::vec4*)o)->w) {
			free(o);
			Py_RETURN_TRUE;
		}
		free(o);
		Py_RETURN_FALSE;
	default:
		PyGLM_TYPEERROR_O("invalid argument type for any(): ", arg);
		return NULL;
	}
}

static PyObject*
all(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char vecType = unpack_vec(arg, &o);
	switch (vecType) {
	case PyGLM_TYPE_VEC2:
		if (((glm::vec2*)o)->x && ((glm::vec2*)o)->y) {
			free(o);
			Py_RETURN_TRUE;
		}
		free(o);
		Py_RETURN_FALSE;
	case PyGLM_TYPE_VEC3:
		if (((glm::vec3*)o)->x && ((glm::vec3*)o)->y && ((glm::vec3*)o)->z) {
			free(o);
			Py_RETURN_TRUE;
		}
		free(o);
		Py_RETURN_FALSE;
	case PyGLM_TYPE_VEC4:
		if (((glm::vec4*)o)->x && ((glm::vec4*)o)->y && ((glm::vec4*)o)->z && ((glm::vec4*)o)->w) {
			free(o);
			Py_RETURN_TRUE;
		}
		free(o);
		Py_RETURN_FALSE;
	default:
		PyGLM_TYPEERROR_O("invalid argument type for all(): ", arg);
		return NULL;
	}
}

static PyObject*
not_(PyObject* self, PyObject* arg) {
	PyObject* out = NULL;
	void* o = NULL;
	char vecType = unpack_vec(arg, &o);
	switch (vecType) {
	case PyGLM_TYPE_VEC2:
		out = pack_vec2(glm::vec2((((glm::vec2*)o)->x) ? 0.f : 1.f, (((glm::vec2*)o)->y) ? 0.f : 1.f));
		free(o);
		return out;
	case PyGLM_TYPE_VEC3:
		out = pack_vec3(glm::vec3((((glm::vec3*)o)->x) ? 0.f : 1.f, (((glm::vec3*)o)->y) ? 0.f : 1.f, (((glm::vec3*)o)->z) ? 0.f : 1.f));
		free(o);
		return out;
	case PyGLM_TYPE_VEC4:
		out = pack_vec4(glm::vec4((((glm::vec4*)o)->x) ? 0.f : 1.f, (((glm::vec4*)o)->y) ? 0.f : 1.f, (((glm::vec4*)o)->z) ? 0.f : 1.f, (((glm::vec4*)o)->w) ? 0.f : 1.f));
		free(o);
		return out;
	default:
		PyGLM_TYPEERROR_O("invalid argument type for not(): ", arg);
		return NULL;
	}
}

PyGLM_MAKE_GLM_FUNC_VF_VF(pow)

PyGLM_MAKE_GLM_FUNC_VF(exp)
PyGLM_MAKE_GLM_FUNC_VF(log)
PyGLM_MAKE_GLM_FUNC_VF(exp2)
PyGLM_MAKE_GLM_FUNC_VF(log2)
PyGLM_MAKE_GLM_FUNC_VF(sqrt)
PyGLM_MAKE_GLM_FUNC_VF(inversesqrt)

PyGLM_MAKE_GLM_FUNC_VF(abs)
PyGLM_MAKE_GLM_FUNC_VF(sign)
PyGLM_MAKE_GLM_FUNC_VF(floor)
PyGLM_MAKE_GLM_FUNC_VF(trunc)
PyGLM_MAKE_GLM_FUNC_VF(round)
PyGLM_MAKE_GLM_FUNC_VF(roundEven)
PyGLM_MAKE_GLM_FUNC_VF(ceil)
PyGLM_MAKE_GLM_FUNC_VF(fract)

PyGLM_MAKE_GLM_FUNC_VVF_VFF(mod)
PyGLM_MAKE_GLM_FUNC_VVF_VFF(min)
PyGLM_MAKE_GLM_FUNC_VVF_VFF(max)

PyGLM_MAKE_GLM_FUNC_VVF_VFF_VFF(clamp)

static PyObject*
mix_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "mix", arg1, arg2, arg3);
	
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return PyFloat_FromDouble(glm::mix(PyGLM_Number_AsDouble(arg1), PyGLM_Number_AsDouble(arg2), PyGLM_Number_AsDouble(arg3)));
	}
	
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2) && PyGLM_Number_Check(arg3)) {
		glm::quat o, o2;
		unpack_quat(arg1, &o);
		unpack_quat(arg2, &o2);
		return pack_quat(glm::mix(o, o2, PyGLM_Number_AsFloat(arg3)));
	}

	char vecType = PyGLM_Vec_GetTypeCheck(arg1);
	if (vecType == PyGLM_TYPE_VEC2 && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o, o2;
		unpack_vec2(arg1, &o);
		unpack_vec2(arg2, &o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec2(glm::mix(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec2_Check(arg3)) {
			glm::vec2 o3;
			unpack_vec2(arg3, &o3);
			return pack_vec2(glm::mix(o, o2, o3));
		}
	}
	if (vecType == PyGLM_TYPE_VEC3 && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o, o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec3(glm::mix(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec3_Check(arg3)) {
			glm::vec3 o3;
			unpack_vec3(arg3, &o3);
			return pack_vec3(glm::mix(o, o2, o3));
		}
	}
	if (vecType == PyGLM_TYPE_VEC4 && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o, o2;
		unpack_vec4(arg1, &o);
		unpack_vec4(arg2, &o2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec4(glm::mix(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec4_Check(arg3)) {
			glm::vec4 o3;
			unpack_vec4(arg3, &o3);
			return pack_vec4(glm::mix(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mix()"); 
	return NULL;
}

static PyObject*
step_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "step", arg1, arg2);
	if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg1)) {
		return PyFloat_FromDouble(glm::step(PyGLM_Number_AsDouble(arg1), PyGLM_Number_AsDouble(arg2)));
	}
	char vecType = PyGLM_Vec_GetTypeCheck(arg2);
	if (vecType == PyGLM_TYPE_VEC2) {
		glm::vec2 o2;
		unpack_vec2(arg2, &o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec2(glm::step(PyGLM_Number_AsFloat(arg1), o2));
		}
		if (PyGLM_Vec2_Check(arg1)) {
			glm::vec2 o;
			unpack_vec2(arg1, &o);
			return pack_vec2(glm::step(o, o2));
		}
	}
	if (vecType == PyGLM_TYPE_VEC3) {
		glm::vec3 o2;
		unpack_vec3(arg2, &o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec3(glm::step(PyGLM_Number_AsFloat(arg1), o2));
		}
		if (PyGLM_Vec3_Check(arg1)) {
			glm::vec3 o;
			unpack_vec3(arg1, &o);
			return pack_vec3(glm::step(o, o2));
		}
	}
	if (vecType == PyGLM_TYPE_VEC4) {
		glm::vec4 o2;
		unpack_vec4(arg2, &o2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec4(glm::step(PyGLM_Number_AsFloat(arg1), o2));
		}
		if (PyGLM_Vec4_Check(arg1)) {
			glm::vec4 o;
			unpack_vec4(arg1, &o);
			return pack_vec4(glm::step(o, o2));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for step(): ", arg1, arg2);
	return NULL;
}

static PyObject*
smoothstep_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "smoothstep", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return PyFloat_FromDouble(glm::smoothstep(PyGLM_Number_AsDouble(arg1), PyGLM_Number_AsDouble(arg2), PyGLM_Number_AsDouble(arg3)));
	}
	char vecType = PyGLM_Vec_GetTypeCheck(arg3);
	if (vecType == PyGLM_TYPE_VEC2) {
		glm::vec2 o3;
		unpack_vec2(arg3, &o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec2(glm::smoothstep(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), o3));
		}
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return pack_vec2(glm::smoothstep(o, o2, o3));
		}
	}
	if (vecType == PyGLM_TYPE_VEC3) {
		glm::vec3 o3;
		unpack_vec3(arg3, &o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec3(glm::smoothstep(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), o3));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return pack_vec3(glm::smoothstep(o, o2, o3));
		}
	}
	if (vecType == PyGLM_TYPE_VEC4) {
		glm::vec4 o3;
		unpack_vec4(arg3, &o3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec4(glm::smoothstep(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), o3));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return pack_vec4(glm::smoothstep(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for smoothstep()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_Q4VF(isnan)
PyGLM_MAKE_GLM_FUNC_Q4VF(isinf)

static PyObject*
fma_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "fma", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2), PyGLM_Number_Check(arg3)) {
		return PyFloat_FromDouble(glm::fma(PyGLM_Number_AsDouble(arg1), PyGLM_Number_AsDouble(arg2), PyGLM_Number_AsDouble(arg3)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fma()");
	return NULL;
}

//static PyObject*
//frexp_(PyObject* self, PyObject* args) {
//	PyObject *arg1, *arg2;
//	PyGLM_Arg_Unpack_2O(args, "frexp", arg1, arg2);
//	int i = 0;
//	glm::frexp(9.f,i);
//	if (PyGLM_Vec2_Check(arg1) && PyObject_TypeCheck(arg2, &vec2Type)) {
//		glm::vec2 o;
//		unpack_vec2(arg1, &o);
//		return pack_vec2(glm::frexp(o, ((vec2*)arg2)->super_type));
//	}
//	if (PyGLM_Vec3_Check(arg1) && PyObject_TypeCheck(arg2, &vec3Type)) {
//		glm::vec3 o;
//		unpack_vec3(arg1, &o);
//		return pack_vec3(glm::frexp(o, ((vec3*)arg2)->super_type));
//	}
//	if (PyGLM_Vec4_Check(arg1) && PyObject_TypeCheck(arg2, &vec4Type)) {
//		glm::vec4 o;
//		unpack_vec4(arg1, &o);
//		return pack_vec4(glm::frexp(o, ((vec4*)arg2)->super_type));
//	}
//	PyGLM_TYPEERROR_2O("invalid argument type(s) for frexp(): ", arg1, arg2);
//	return NULL;
//}
//
//static PyObject*
//ldexp_(PyObject* self, PyObject* args) {
//	PyObject *arg1, *arg2;
//	PyGLM_Arg_Unpack_2O(args, "ldexp", arg1, arg2);
//	if (PyGLM_Vec2_Check(arg1) && PyObject_TypeCheck(arg2, &vec2Type)) {
//		glm::vec2 o;
//		unpack_vec2(arg1, &o);
//		return pack_vec2(glm::ldexp(o, ((vec2*)arg2)->super_type));
//	}
//	if (PyGLM_Vec3_Check(arg1) && PyObject_TypeCheck(arg2, &vec3Type)) {
//		glm::vec3 o;
//		unpack_vec3(arg1, &o);
//		return pack_vec3(glm::ldexp(o, ((vec3*)arg2)->super_type));
//	}
//	if (PyGLM_Vec4_Check(arg1) && PyObject_TypeCheck(arg2, &vec4Type)) {
//		glm::vec4 o;
//		unpack_vec4(arg1, &o);
//		return pack_vec4(glm::ldexp(o, ((vec4*)arg2)->super_type));
//	}
//	PyGLM_TYPEERROR_2O("invalid argument type(s) for ldexp(): ", arg1, arg2);
//	return NULL;
//}

PyGLM_MAKE_GLM_FUNC_VFrF(length)

PyGLM_MAKE_GLM_FUNC_VF_VFrF(distance)
PyGLM_MAKE_GLM_FUNC_VF_VFrF(dot)

static PyObject*
cross_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "cross", arg1, arg2);

	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o, o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		return pack_vec3(glm::cross(o, o2));
	}
	if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
		glm::quat o, o2;
		unpack_quat(arg1, &o);
		unpack_quat(arg2, &o2);
		return pack_quat(glm::cross(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for cross(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_QV(normalize)

PyGLM_MAKE_GLM_FUNC_VF_VF_VF(faceforward)

PyGLM_MAKE_GLM_FUNC_VF_VF(reflect)

static PyObject*
refract_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "refract", arg1, arg2, arg3);

	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			return PyFloat_FromDouble((double)glm::refract(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return pack_vec2(glm::refract(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return pack_vec3(glm::refract(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return pack_vec4(glm::refract(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for refract()");
	return NULL;
}

static PyObject*
outerProduct_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "outerProduct", arg1, arg2);
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
		glm::vec2 o;
		glm::vec2 o2;
		unpack_vec2(arg1, &o);
		unpack_vec2(arg2, &o2);
		return pack_mat2x2(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
		glm::vec2 o;
		glm::vec3 o2;
		unpack_vec2(arg1, &o);
		unpack_vec3(arg2, &o2);
		return pack_mat2x3(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
		glm::vec2 o;
		glm::vec4 o2;
		unpack_vec2(arg1, &o);
		unpack_vec4(arg2, &o2);
		return pack_mat2x4(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
		glm::vec3 o;
		glm::vec2 o2;
		unpack_vec3(arg1, &o);
		unpack_vec2(arg2, &o2);
		return pack_mat3x2(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
		glm::vec3 o;
		glm::vec3 o2;
		unpack_vec3(arg1, &o);
		unpack_vec3(arg2, &o2);
		return pack_mat3x3(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
		glm::vec3 o;
		glm::vec4 o2;
		unpack_vec3(arg1, &o);
		unpack_vec4(arg2, &o2);
		return pack_mat3x4(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
		glm::vec4 o;
		glm::vec2 o2;
		unpack_vec4(arg1, &o);
		unpack_vec2(arg2, &o2);
		return pack_mat4x2(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
		glm::vec4 o;
		glm::vec3 o2;
		unpack_vec4(arg1, &o);
		unpack_vec3(arg2, &o2);
		return pack_mat4x3(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
		glm::vec4 o;
		glm::vec4 o2;
		unpack_vec4(arg1, &o);
		unpack_vec4(arg2, &o2);
		return pack_mat4x4(glm::outerProduct(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for outerProduct(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_M_M(matrixCompMult)
PyGLM_MAKE_GLM_FUNC_M(transpose)
PyGLM_MAKE_GLM_FUNC_MsqrF(determinant)
PyGLM_MAKE_GLM_FUNC_MsqQ(inverse)

PyGLM_MAKE_GLM_FUNC_VF(radians)
PyGLM_MAKE_GLM_FUNC_VF(degrees)

PyGLM_MAKE_GLM_FUNC_VF(sin)
PyGLM_MAKE_GLM_FUNC_VF(cos)
PyGLM_MAKE_GLM_FUNC_VF(tan)

PyGLM_MAKE_GLM_FUNC_VF(asin)
PyGLM_MAKE_GLM_FUNC_VF(acos)
static PyObject* 
atan_(PyObject* self, PyObject* args) {
	PyObject* arg1 = NULL, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "atan", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for atan()");
		return NULL;
	}

	if (arg2 != NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return PyFloat_FromDouble(glm::atan(PyGLM_Number_AsDouble(arg1), PyGLM_Number_AsDouble(arg2)));
		}
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return pack_vec2(glm::atan(o, o2));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return pack_vec3(glm::atan(o, o2));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return pack_vec4(glm::atan(o, o2));
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for atan(): ", arg1, arg2);
		return NULL;
	}

	if (PyGLM_Number_Check(arg1)) {
		return PyFloat_FromDouble(glm::atan(PyGLM_Number_AsDouble(arg1)));
	}
	if (PyGLM_Vec2_Check(arg1)) {
		glm::vec2 o;
		unpack_vec2(arg1, &o);
		return pack_vec2(glm::atan(o));
	}
	if (PyGLM_Vec3_Check(arg1)) {
		glm::vec3 o;
		unpack_vec3(arg1, &o);
		return pack_vec3(glm::atan(o));
	}
	if (PyGLM_Vec4_Check(arg1)) {
		glm::vec4 o;
		unpack_vec4(arg1, &o);
		return pack_vec4(glm::atan(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for atan(): ", arg1);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_VF(sinh)
PyGLM_MAKE_GLM_FUNC_VF(cosh)
PyGLM_MAKE_GLM_FUNC_VF(tanh)

PyGLM_MAKE_GLM_FUNC_VF(asinh)
PyGLM_MAKE_GLM_FUNC_VF(acosh)
PyGLM_MAKE_GLM_FUNC_VF(atanh)

static PyObject*
convertLinearToSRGB_(PyObject* self, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertLinearToSRGB", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2) {
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			PyObject* out = pack_vec2(glm::convertLinearToSRGB(*(glm::vec2*)o, PyGLM_Number_AsFloat(arg2)));
			free(o);
			return out;
		}
		PyObject* out = pack_vec2(glm::convertLinearToSRGB(*(glm::vec2*)o));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3) {
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			PyObject* out = pack_vec3(glm::convertLinearToSRGB(*(glm::vec3*)o, PyGLM_Number_AsFloat(arg2)));
			free(o);
			return out;
		}
		PyObject* out = pack_vec3(glm::convertLinearToSRGB(*(glm::vec3*)o));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4) {
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			PyObject* out = pack_vec4(glm::convertLinearToSRGB(*(glm::vec4*)o, PyGLM_Number_AsFloat(arg2)));
			free(o);
			return out;
		}
		PyObject* out = pack_vec4(glm::convertLinearToSRGB(*(glm::vec4*)o));
		free(o);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
	return NULL;
}

static PyObject*
convertSRGBToLinear_(PyObject* self, PyObject* args) {
	PyObject* arg1;
	PyObject* arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "convertSRGBToLinear", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
		return NULL;
	}
	void* o = NULL;
	char vecType = unpack_vec(arg1, &o);
	if (vecType == PyGLM_TYPE_VEC2) {
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			PyObject* out = pack_vec2(glm::convertSRGBToLinear(*(glm::vec2*)o, PyGLM_Number_AsFloat(arg2)));
			free(o);
			return out;
		}
		PyObject* out = pack_vec2(glm::convertSRGBToLinear(*(glm::vec2*)o));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC3) {
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			PyObject* out = pack_vec3(glm::convertSRGBToLinear(*(glm::vec3*)o, PyGLM_Number_AsFloat(arg2)));
			free(o);
			return out;
		}
		PyObject* out = pack_vec3(glm::convertSRGBToLinear(*(glm::vec3*)o));
		free(o);
		return out;
	}
	if (vecType == PyGLM_TYPE_VEC4) {
		if (arg2 != NULL && PyGLM_Number_Check(arg2)) {
			PyObject* out = pack_vec4(glm::convertSRGBToLinear(*(glm::vec4*)o, PyGLM_Number_AsFloat(arg2)));
			free(o);
			return out;
		}
		PyObject* out = pack_vec4(glm::convertSRGBToLinear(*(glm::vec4*)o));
		free(o);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
	return NULL;
}

static PyObject* epsilon_(PyObject* self, PyObject* narg) { return PyFloat_FromDouble(glm::epsilon<float>()); }

PyGLM_MAKE_GLM_FUNC_rF(zero)
PyGLM_MAKE_GLM_FUNC_rF(one)
PyGLM_MAKE_GLM_FUNC_rF(pi)
PyGLM_MAKE_GLM_FUNC_rF(two_pi)
PyGLM_MAKE_GLM_FUNC_rF(root_pi)
PyGLM_MAKE_GLM_FUNC_rF(half_pi)
PyGLM_MAKE_GLM_FUNC_rF(three_over_two_pi)
PyGLM_MAKE_GLM_FUNC_rF(quarter_pi)
PyGLM_MAKE_GLM_FUNC_rF(one_over_pi)
PyGLM_MAKE_GLM_FUNC_rF(one_over_two_pi)
PyGLM_MAKE_GLM_FUNC_rF(two_over_pi)
PyGLM_MAKE_GLM_FUNC_rF(four_over_pi)
PyGLM_MAKE_GLM_FUNC_rF(two_over_root_pi)
PyGLM_MAKE_GLM_FUNC_rF(one_over_root_two)
PyGLM_MAKE_GLM_FUNC_rF(root_half_pi)
PyGLM_MAKE_GLM_FUNC_rF(root_two_pi)
PyGLM_MAKE_GLM_FUNC_rF(root_ln_four)
PyGLM_MAKE_GLM_FUNC_rF(e)
PyGLM_MAKE_GLM_FUNC_rF(euler)
PyGLM_MAKE_GLM_FUNC_rF(root_two)
PyGLM_MAKE_GLM_FUNC_rF(root_three)
PyGLM_MAKE_GLM_FUNC_rF(root_five)
PyGLM_MAKE_GLM_FUNC_rF(ln_two)
PyGLM_MAKE_GLM_FUNC_rF(ln_ten)
PyGLM_MAKE_GLM_FUNC_rF(ln_ln_two)
PyGLM_MAKE_GLM_FUNC_rF(third)
PyGLM_MAKE_GLM_FUNC_rF(two_thirds)
PyGLM_MAKE_GLM_FUNC_rF(golden_ratio)

static PyObject* 
epsilonEqual_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "epsilonEqual", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			if (glm::epsilonEqual(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3))) {
				Py_RETURN_TRUE;
			}
			else {
				Py_RETURN_FALSE;
			}
		}
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return pack_vec2(glm::epsilonEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return pack_vec3(glm::epsilonEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return pack_vec4(glm::epsilonEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
			glm::quat o, o2;
			unpack_quat(arg1, &o);
			unpack_quat(arg2, &o2);
			return pack_vec4(glm::epsilonEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
	}
	else {
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && PyGLM_Vec2_Check(arg3)) {
			glm::vec2 o, o2, o3;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			unpack_vec2(arg3, &o3);
			return pack_vec2(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && PyGLM_Vec3_Check(arg3)) {
			glm::vec3 o, o2, o3;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			unpack_vec3(arg3, &o3);
			return pack_vec3(glm::epsilonEqual(o, o2, o3));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && PyGLM_Vec4_Check(arg3)) {
			glm::vec4 o, o2, o3;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			unpack_vec4(arg3, &o3);
			return pack_vec4(glm::epsilonEqual(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for epsilonEqual()");
	return NULL;
}

static PyObject*
epsilonNotEqual_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "epsilonNotEqual", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
			if (glm::epsilonNotEqual(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3))) {
				Py_RETURN_TRUE;
			}
			else {
				Py_RETURN_FALSE;
			}
		}
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return pack_vec2(glm::epsilonNotEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return pack_vec3(glm::epsilonNotEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return pack_vec4(glm::epsilonNotEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
		if (PyGLM_Quat_Check(arg1) && PyGLM_Quat_Check(arg2)) {
			glm::quat o, o2;
			unpack_quat(arg1, &o);
			unpack_quat(arg2, &o2);
			return pack_vec4(glm::epsilonNotEqual(o, o2, PyGLM_Number_AsFloat(arg3)));
		}
	}
	else {
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2) && PyGLM_Vec2_Check(arg3)) {
			glm::vec2 o, o2, o3;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			unpack_vec2(arg3, &o3);
			return pack_vec2(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2) && PyGLM_Vec3_Check(arg3)) {
			glm::vec3 o, o2, o3;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			unpack_vec3(arg3, &o3);
			return pack_vec3(glm::epsilonNotEqual(o, o2, o3));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2) && PyGLM_Vec4_Check(arg3)) {
			glm::vec4 o, o2, o3;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			unpack_vec4(arg3, &o3);
			return pack_vec4(glm::epsilonNotEqual(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for epsilonNotEqual()");
	return NULL;
}

static PyObject*
identity_(PyObject* self, PyObject* arg) {
	if (!PyType_Check(arg)) {
		PyGLM_TYPEERROR_O("identity() requires a PyGLM matrix type as it's argument, not ", arg);
		return NULL;
	}
	if (arg == (PyObject*)&mat2x2Type) {
		return pack_mat2x2(glm::identity<glm::mat2x2>());
	}
	if (arg == (PyObject*)&mat2x3Type) {
		return pack_mat2x3(glm::identity<glm::mat2x3>());
	}
	if (arg == (PyObject*)&mat2x4Type) {
		return pack_mat2x4(glm::identity<glm::mat2x4>());
	}
	if (arg == (PyObject*)&mat3x2Type) {
		return pack_mat3x2(glm::identity<glm::mat3x2>());
	}
	if (arg == (PyObject*)&mat3x3Type) {
		return pack_mat3x3(glm::identity<glm::mat3x3>());
	}
	if (arg == (PyObject*)&mat3x4Type) {
		return pack_mat3x4(glm::identity<glm::mat3x4>());
	}
	if (arg == (PyObject*)&mat4x2Type) {
		return pack_mat4x2(glm::identity<glm::mat4x2>());
	}
	if (arg == (PyObject*)&mat4x3Type) {
		return pack_mat4x3(glm::identity<glm::mat4x3>());
	}
	if (arg == (PyObject*)&mat4x4Type) {
		return pack_mat4x4(glm::identity<glm::mat4x4>());
	}
	PyErr_Format(PyExc_TypeError, "identity() requires a PyGLM matrix type as it's argument, not '%s'", ((PyTypeObject*)arg)->tp_name);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_M4_V3rM4(translate)

static PyObject*
rotate_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "rotate", arg1, arg2, arg3);
	if (PyGLM_Mat4x4_Check(arg1)) {
		glm::mat4x4 m;
		glm::vec3 axis;
		if (!unpack_mat4x4(arg1, &m) || !PyGLM_Number_Check(arg2) || !unpack_vec3(arg3, &axis)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate()");
			return NULL;
		}
		return pack_mat4x4(glm::rotate(m, PyGLM_Number_AsFloat(arg2), axis));
	}
	if (PyGLM_Quat_Check(arg1)) {
		glm::quat q;
		glm::vec3 axis;
		if (!unpack_quat(arg1, &q) || !PyGLM_Number_Check(arg2) || !unpack_vec3(arg3, &axis)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate()");
			return NULL;
		}
		return pack_quat(glm::rotate(q, PyGLM_Number_AsFloat(arg2), axis));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate()");
	return NULL;
}

static PyObject*
rotate_slow_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "rotate_slow", arg1, arg2, arg3);
	glm::mat4x4 m;
	glm::vec3 axis;
	if (!unpack_mat4x4(arg1, &m) || !PyGLM_Number_Check(arg2) || !unpack_vec3(arg3, &axis)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for rotate_slow()");
		return NULL;
	}
	return pack_mat4x4(glm::rotate_slow(m, PyGLM_Number_AsFloat(arg2), axis));
}

PyGLM_MAKE_GLM_FUNC_M4_V3rM4(scale)
PyGLM_MAKE_GLM_FUNC_M4_V3rM4(scale_slow)

static PyObject*
ortho_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5 = NULL, *arg6 = NULL;
	if (!PyArg_UnpackTuple(args, "ortho", 4, 6, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for ortho()");
		return NULL;
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
		if (arg5 != NULL && arg6 != NULL && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) return pack_mat4x4(glm::ortho(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5), PyGLM_Number_AsFloat(arg6)));
		if (arg5 == NULL && arg6 == NULL) return pack_mat4x4(glm::ortho(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for ortho()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoLH_ZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoLH_NO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoRH_ZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoRH_NO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoLH)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoRH)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(orthoNO)

PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustum)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumLH_ZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumLH_NO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumRH_ZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumRH_NO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumLH)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumRH)
PyGLM_MAKE_GLM_FUNC_F_F_F_F_F_FrM4(frustumNO)

PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspective)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveLH_ZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveLH_NO)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveRH_ZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveRH_NO)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveLH)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveZO)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveRH)
PyGLM_MAKE_GLM_FUNC_F_F_F_FrM4(perspectiveNO)

static PyObject*
perspectiveFov_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFov", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)&& PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFov() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFov(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFov()");
	return NULL;
}
static PyObject*
perspectiveFovLH_ZO_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovLH_ZO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovLH_ZO() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovLH_ZO(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovLH_ZO()");
	return NULL;
}
static PyObject*
perspectiveFovLH_NO_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovLH_NO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovLH_NO() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovLH_NO(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovLH_NO()");
	return NULL;
}
static PyObject*
perspectiveFovRH_ZO_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovRH_ZO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovRH_ZO() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovRH_ZO(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovRH_ZO()");
	return NULL;
}
static PyObject*
perspectiveFovRH_NO_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovRH_NO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovRH_NO() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovRH_NO(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovRH_NO()");
	return NULL;
}
static PyObject*
perspectiveFovLH_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovLH", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovLH() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovLH(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovLH()");
	return NULL;
}
static PyObject*
perspectiveFovZO_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovZO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovZO() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovZO(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovZO()");
	return NULL;
}
static PyObject*
perspectiveFovRH_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovRH", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovRH() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovRH(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovRH()");
	return NULL;
}
static PyObject*
perspectiveFovNO_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4, *arg5;
	PyGLM_Arg_Unpack_5O(args, "perspectiveFovNO", arg1, arg2, arg3, arg4, arg5);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5)) {
		float f = PyGLM_Number_AsFloat(arg1), f2 = PyGLM_Number_AsFloat(arg2), f3 = PyGLM_Number_AsFloat(arg3);
		if (!(f > 0 && f2 > 0 && f3 > 0)) {
			PyErr_SetString(PyExc_ValueError, "fov, width and height arguments of perspectiveFovNO() must be greater than 0");
			return NULL;
		}
		return pack_mat4x4(glm::perspectiveFovNO(f, f2, f3, PyGLM_Number_AsFloat(arg4), PyGLM_Number_AsFloat(arg5)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perspectiveFovNO()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_F_F_FrM4(infinitePerspective)
PyGLM_MAKE_GLM_FUNC_F_F_FrM4(infinitePerspectiveLH)
PyGLM_MAKE_GLM_FUNC_F_F_FrM4(infinitePerspectiveRH)

static PyObject*
tweakedInfinitePerspective_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "tweakedInfinitePerspective", 3, 4, &arg1, &arg2, &arg3, &arg4)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tweakedInfinitePerspective()");
		return NULL;
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		if (arg4 != NULL && PyGLM_Number_Check(arg4)) {
			return pack_mat4x4(glm::tweakedInfinitePerspective(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3), PyGLM_Number_AsFloat(arg4)));
		}
		return pack_mat4x4(glm::tweakedInfinitePerspective(PyGLM_Number_AsFloat(arg1), PyGLM_Number_AsFloat(arg2), PyGLM_Number_AsFloat(arg3)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tweakedInfinitePerspective()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(project)
PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(projectZO)
PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(projectNO)
PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(unProject)
PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(unProjectZO)
PyGLM_MAKE_GLM_FUNC_V3_M4_M4_V4rV3(unProjectNO)

static PyObject*
pickMatrix_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "pickMatrix", arg1, arg2, arg3);
	glm::vec2 o, o2;
	glm::vec4 o3;
	if (!unpack_vec2(arg1, &o) || !unpack_vec2(arg2, &o2) || !unpack_vec4(arg3, &o3)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for pickMatrix()");
		return NULL;
	}
	return pack_mat4x4(glm::pickMatrix(o, o2, o3));
}

PyGLM_MAKE_GLM_FUNC_V3_V3_V3rM4(lookAt)
PyGLM_MAKE_GLM_FUNC_V3_V3_V3rM4(lookAtLH)
PyGLM_MAKE_GLM_FUNC_V3_V3_V3rM4(lookAtRH)

PyGLM_MAKE_GLM_FUNC_V3_V3rQ(quatLookAt)
PyGLM_MAKE_GLM_FUNC_V3_V3rQ(quatLookAtLH)
PyGLM_MAKE_GLM_FUNC_V3_V3rQ(quatLookAtRH)

PyGLM_MAKE_GLM_FUNC_Q_Q_FrQ(lerp)
PyGLM_MAKE_GLM_FUNC_Q_Q_FrQ(slerp)

PyGLM_MAKE_GLM_FUNC_Q(conjugate)

PyGLM_MAKE_GLM_FUNC_QrV3(eulerAngles)

PyGLM_MAKE_GLM_FUNC_QrF(roll)
PyGLM_MAKE_GLM_FUNC_QrF(pitch)
PyGLM_MAKE_GLM_FUNC_QrF(yaw)

static PyObject*
mat3_cast_(PyObject* self, PyObject* arg) {
	
	glm::quat q;
	if (unpack_quat(arg, &q)) {
		return pack_mat3x3(glm::mat3_cast(q));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3_cast()");
	return NULL;
}

static PyObject*
mat4_cast_(PyObject* self, PyObject* arg) {

	glm::quat q;
	if (unpack_quat(arg, &q)) {
		return pack_mat4x4(glm::mat4_cast(q));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4_cast()");
	return NULL;
}

static PyObject*
quat_cast_(PyObject* self, PyObject* arg) {
	if (PyGLM_Mat3x3_Check(arg)) {
		glm::mat3x3 o;
		unpack_mat3x3(arg, &o);
		return pack_quat(glm::quat_cast(o));
	}
	if (PyGLM_Mat4x4_Check(arg)) {
		glm::mat4x4 o;
		unpack_mat4x4(arg, &o);
		return pack_quat(glm::quat_cast(o));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat_cast()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_QrF(angle)
PyGLM_MAKE_GLM_FUNC_QrV3(axis)

static PyObject*
angleAxis_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "angleAxis", arg1, arg2);
	glm::vec3 v;
	if (!PyGLM_Number_Check(arg1) || !unpack_vec3(arg2, &v)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for angleAxis()");
		return NULL;
	}
	return pack_quat(glm::angleAxis(PyGLM_Number_AsFloat(arg1), v));
}

static PyObject*
row_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "row", 2, 3, &arg1, &arg2, &arg3) || !PyGLM_Number_Check(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for row()");
		return NULL;
	}
	glm::length_t index = (glm::length_t)PyGLM_Number_AsLong(arg2);
	if (index < 0) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (arg3 != NULL) {
		if (PyGLM_Vec2_Check(arg3)) {
			glm::vec2 x;
			unpack_vec2(arg3, &x);
			if (PyGLM_Mat2x2_Check(arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat2x2 m;
				unpack_mat2x2(arg1, &m);
				return pack_mat2x2(glm::row(m, index, x));
			}
			if (PyGLM_Mat2x3_Check(arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat2x3 m;
				unpack_mat2x3(arg1, &m);
				return pack_mat2x3(glm::row(m, index, x));
			}
			if (PyGLM_Mat2x4_Check(arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat2x4 m;
				unpack_mat2x4(arg1, &m);
				return pack_mat2x4(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec3_Check(arg3)) {
			glm::vec3 x;
			unpack_vec3(arg3, &x);
			if (PyGLM_Mat3x2_Check(arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat3x2 m;
				unpack_mat3x2(arg1, &m);
				return pack_mat3x2(glm::row(m, index, x));
			}
			if (PyGLM_Mat3x3_Check(arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat3x3 m;
				unpack_mat3x3(arg1, &m);
				return pack_mat3x3(glm::row(m, index, x));
			}
			if (PyGLM_Mat3x4_Check(arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat3x4 m;
				unpack_mat3x4(arg1, &m);
				return pack_mat3x4(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec4_Check(arg3)) {
			glm::vec4 x;
			unpack_vec4(arg3, &x);
			if (PyGLM_Mat4x2_Check(arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat4x2 m;
				unpack_mat4x2(arg1, &m);
				return pack_mat4x2(glm::row(m, index, x));
			}
			if (PyGLM_Mat4x3_Check(arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat4x3 m;
				unpack_mat4x3(arg1, &m);
				return pack_mat4x3(glm::row(m, index, x));
			}
			if (PyGLM_Mat4x4_Check(arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat4x4 m;
				unpack_mat4x4(arg1, &m);
				return pack_mat4x4(glm::row(m, index, x));
			}
		}
	}
	else {
		if (PyGLM_Mat2x2_Check(arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat2x2 m;
			unpack_mat2x2(arg1, &m);
			return pack_vec2(glm::row(m, index));
		}
		if (PyGLM_Mat2x3_Check(arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat2x3 m;
			unpack_mat2x3(arg1, &m);
			return pack_vec2(glm::row(m, index));
		}
		if (PyGLM_Mat2x4_Check(arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat2x4 m;
			unpack_mat2x4(arg1, &m);
			return pack_vec2(glm::row(m, index));
		}

		if (PyGLM_Mat3x2_Check(arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat3x2 m;
			unpack_mat3x2(arg1, &m);
			return pack_vec3(glm::row(m, index));
		}
		if (PyGLM_Mat3x3_Check(arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat3x3 m;
			unpack_mat3x3(arg1, &m);
			return pack_vec3(glm::row(m, index));
		}
		if (PyGLM_Mat3x4_Check(arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat3x4 m;
			unpack_mat3x4(arg1, &m);
			return pack_vec3(glm::row(m, index));
		}

		if (PyGLM_Mat4x2_Check(arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat4x2 m;
			unpack_mat4x2(arg1, &m);
			return pack_vec4(glm::row(m, index));
		}
		if (PyGLM_Mat4x3_Check(arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat4x3 m;
			unpack_mat4x3(arg1, &m);
			return pack_vec4(glm::row(m, index));
		}
		if (PyGLM_Mat4x4_Check(arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat4x4 m;
			unpack_mat4x4(arg1, &m);
			return pack_vec4(glm::row(m, index));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for row()");
	return NULL;
}

static PyObject*
column_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "column", 2, 3, &arg1, &arg2, &arg3) || !PyGLM_Number_Check(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
		return NULL;
	}
	glm::length_t index = (glm::length_t)PyGLM_Number_AsDouble(arg2);
	if (index < 0) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (arg3 != NULL) {
		if (PyGLM_Vec2_Check(arg3)) {
			glm::vec2 x;
			unpack_vec2(arg3, &x);
			if (PyGLM_Mat2x2_Check(arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat2x2 m;
				unpack_mat2x2(arg1, &m);
				return pack_mat2x2(glm::column(m, index, x));
			}
			if (PyGLM_Mat3x2_Check(arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat3x2 m;
				unpack_mat3x2(arg1, &m);
				return pack_mat3x2(glm::column(m, index, x));
			}
			if (PyGLM_Mat4x2_Check(arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat4x2 m;
				unpack_mat4x2(arg1, &m);
				return pack_mat4x2(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec3_Check(arg3)) {
			glm::vec3 x;
			unpack_vec3(arg3, &x);
			if (PyGLM_Mat2x3_Check(arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat2x3 m;
				unpack_mat2x3(arg1, &m);
				return pack_mat2x3(glm::column(m, index, x));
			}
			if (PyGLM_Mat3x3_Check(arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat3x3 m;
				unpack_mat3x3(arg1, &m);
				return pack_mat3x3(glm::column(m, index, x));
			}
			if (PyGLM_Mat4x3_Check(arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat4x3 m;
				unpack_mat4x3(arg1, &m);
				return pack_mat4x3(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec4_Check(arg3)) {
			glm::vec4 x;
			unpack_vec4(arg3, &x);
			if (PyGLM_Mat2x4_Check(arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat2x4 m;
				unpack_mat2x4(arg1, &m);
				return pack_mat2x4(glm::column(m, index, x));
			}
			if (PyGLM_Mat3x4_Check(arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat3x4 m;
				unpack_mat3x4(arg1, &m);
				return pack_mat3x4(glm::column(m, index, x));
			}
			if (PyGLM_Mat4x4_Check(arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat4x4 m;
				unpack_mat4x4(arg1, &m);
				return pack_mat4x4(glm::column(m, index, x));
			}
		}
	}
	else {
		if (PyGLM_Mat2x2_Check(arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat2x2 m;
			unpack_mat2x2(arg1, &m);
			return pack_vec2(m[index]);
		}
		if (PyGLM_Mat2x3_Check(arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat2x3 m;
			unpack_mat2x3(arg1, &m);
			return pack_vec3(m[index]);
		}
		if (PyGLM_Mat2x4_Check(arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat2x4 m;
			unpack_mat2x4(arg1, &m);
			return pack_vec4(m[index]);
		}

		if (PyGLM_Mat3x2_Check(arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat3x2 m;
			unpack_mat3x2(arg1, &m);
			return pack_vec2(m[index]);
		}
		if (PyGLM_Mat3x3_Check(arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat3x3 m;
			unpack_mat3x3(arg1, &m);
			return pack_vec3(m[index]);
		}
		if (PyGLM_Mat3x4_Check(arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat3x4 m;
			unpack_mat3x4(arg1, &m);
			return pack_vec4(m[index]);
		}

		if (PyGLM_Mat4x2_Check(arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat4x2 m;
			unpack_mat4x2(arg1, &m);
			return pack_vec2(m[index]);
		}
		if (PyGLM_Mat4x3_Check(arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat4x3 m;
			unpack_mat4x3(arg1, &m);
			return pack_vec3(m[0]);
		}
		if (PyGLM_Mat4x4_Check(arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat4x4 m;
			unpack_mat4x4(arg1, &m);
			return pack_vec4(m[index]);
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
	return NULL;
}

static PyObject*
perlin_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "perlin", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perlin()");
		return NULL;
	}
	if (arg2 != NULL) {
		if (PyGLM_Vec2_Check(arg1) && PyGLM_Vec2_Check(arg2)) {
			glm::vec2 o, o2;
			unpack_vec2(arg1, &o);
			unpack_vec2(arg2, &o2);
			return PyFloat_FromDouble(glm::perlin(o, o2));
		}
		if (PyGLM_Vec3_Check(arg1) && PyGLM_Vec3_Check(arg2)) {
			glm::vec3 o, o2;
			unpack_vec3(arg1, &o);
			unpack_vec3(arg2, &o2);
			return PyFloat_FromDouble(glm::perlin(o, o2));
		}
		if (PyGLM_Vec4_Check(arg1) && PyGLM_Vec4_Check(arg2)) {
			glm::vec4 o, o2;
			unpack_vec4(arg1, &o);
			unpack_vec4(arg2, &o2);
			return PyFloat_FromDouble(glm::perlin(o, o2));
		}
	}
	else {
		if (PyGLM_Vec2_Check(arg1)) {
			glm::vec2 o;
			unpack_vec2(arg1, &o);
			return PyFloat_FromDouble(glm::perlin(o));
		}
		if (PyGLM_Vec3_Check(arg1)) {
			glm::vec3 o;
			unpack_vec3(arg1, &o);
			return PyFloat_FromDouble(glm::perlin(o));
		}
		if (PyGLM_Vec4_Check(arg1)) {
			glm::vec4 o;
			unpack_vec4(arg1, &o);
			return PyFloat_FromDouble(glm::perlin(o));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for perlin()");
	return NULL;
}

static PyObject* simplex_(PyObject* self, PyObject* arg) {
	void* o = NULL; 
	char vecType = unpack_vec(arg, &o); 
	if (vecType == PyGLM_TYPE_VEC2) { 
		PyObject* out = PyFloat_FromDouble((double)glm::simplex(*(glm::vec2*)o)); 
		free(o); 
		return out; 
	} 
	if (vecType == PyGLM_TYPE_VEC3) { 
		PyObject* out = PyFloat_FromDouble((double)glm::simplex(*(glm::vec3*)o)); 
		free(o); 
		return out; 
	} 
	if (vecType == PyGLM_TYPE_VEC4) { 
		PyObject* out = PyFloat_FromDouble((double)glm::simplex(*(glm::vec4*)o)); 
		free(o); 
		return out; 
	} 
	PyGLM_TYPEERROR_O("invalid argument type for simplex(): ", arg); 
	return NULL; 
}

PyGLM_MAKE_GLM_FUNC_VF_VF(linearRand)
PyGLM_MAKE_GLM_FUNC_VF_VF(gaussRand)

static PyObject*
circularRand_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "circularRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack_vec2(glm::circularRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for circularRand(): ", arg);
	return NULL;
}

static PyObject*
sphericalRand_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "sphericalRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack_vec3(glm::sphericalRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for sphericalRand(): ", arg);
	return NULL;
}

static PyObject*
diskRand_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "diskRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack_vec2(glm::diskRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for diskRand(): ", arg);
	return NULL;
}

static PyObject*
ballRand_(PyObject* self, PyObject* arg) {
	if (PyGLM_Number_Check(arg)) {
		float f = PyGLM_Number_AsFloat(arg);
		if (f <= 0) {
			PyErr_SetString(PyExc_ValueError, "ballRand() requires a Radius greater than 0");
			return NULL;
		}
		return pack_vec3(glm::ballRand(f));
	}
	PyGLM_TYPEERROR_O("invalid argument type for ballRand(): ", arg);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_VF(sec)
PyGLM_MAKE_GLM_FUNC_VF(csc)
PyGLM_MAKE_GLM_FUNC_VF(cot)

PyGLM_MAKE_GLM_FUNC_VF(asec)
PyGLM_MAKE_GLM_FUNC_VF(acsc)
PyGLM_MAKE_GLM_FUNC_VF(acot)

PyGLM_MAKE_GLM_FUNC_VF(sech)
PyGLM_MAKE_GLM_FUNC_VF(csch)
PyGLM_MAKE_GLM_FUNC_VF(coth)

PyGLM_MAKE_GLM_FUNC_VF(asech)
PyGLM_MAKE_GLM_FUNC_VF(acsch)
PyGLM_MAKE_GLM_FUNC_VF(acoth)

static PyObject*
sizeof_(PyObject* self, PyObject* arg) {
	if (PyGLM_Vec2_Check(arg) || arg == (PyObject*)&vec2Type) {
		return PyLong_FromLong(sizeof(glm::vec2));
	}
	if (PyGLM_Vec3_Check(arg) || arg == (PyObject*)&vec3Type) {
		return PyLong_FromLong(sizeof(glm::vec3));
	}
	if (PyGLM_Vec4_Check(arg) || arg == (PyObject*)&vec4Type) {
		return PyLong_FromLong(sizeof(glm::vec4));
	}
	if (PyGLM_Quat_Check(arg) || arg == (PyObject*)&quatType) {
		return PyLong_FromLong(sizeof(glm::vec4));
	}
	if (PyGLM_Mat2x2_Check(arg) || arg == (PyObject*)&mat2x2Type) {
		return PyLong_FromLong(sizeof(glm::mat2x2));
	}
	if (PyGLM_Mat2x3_Check(arg) || arg == (PyObject*)&mat2x3Type) {
		return PyLong_FromLong(sizeof(glm::mat2x3));
	}
	if (PyGLM_Mat2x4_Check(arg) || arg == (PyObject*)&mat2x4Type) {
		return PyLong_FromLong(sizeof(glm::mat2x4));
	}
	if (PyGLM_Mat3x2_Check(arg) || arg == (PyObject*)&mat3x2Type) {
		return PyLong_FromLong(sizeof(glm::mat3x2));
	}
	if (PyGLM_Mat3x3_Check(arg) || arg == (PyObject*)&mat3x3Type) {
		return PyLong_FromLong(sizeof(glm::mat3x3));
	}
	if (PyGLM_Mat3x4_Check(arg) || arg == (PyObject*)&mat3x4Type) {
		return PyLong_FromLong(sizeof(glm::mat3x4));
	}
	if (PyGLM_Mat4x2_Check(arg) || arg == (PyObject*)&mat4x2Type) {
		return PyLong_FromLong(sizeof(glm::mat4x2));
	}
	if (PyGLM_Mat4x3_Check(arg) || arg == (PyObject*)&mat4x3Type) {
		return PyLong_FromLong(sizeof(glm::mat4x3));
	}
	if (PyGLM_Mat4x4_Check(arg) || arg == (PyObject*)&mat4x4Type) {
		return PyLong_FromLong(sizeof(glm::mat4x4));
	}
	PyGLM_TYPEERROR_O("sizeof() requires the argument to be a glm type, not ", arg);
	return NULL;
}

static PyObject*
value_ptr_(PyObject* self, PyObject* arg) {
	if (Py_TYPE(arg) == &vec2Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((vec2*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &vec3Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((vec3*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &vec4Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((vec4*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &quatType) {
		return Ctypes_C_VOID_P(glm::value_ptr(((quat*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat2x2Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat2x2*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat2x3Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat2x3*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat2x4Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat2x4*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat3x2Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat3x2*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat3x3Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat3x3*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat3x4Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat3x4*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat4x2Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat4x2*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat4x3Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat4x3*)arg)->super_type));
	}
	if (Py_TYPE(arg) == &mat4x4Type) {
		return Ctypes_C_VOID_P(glm::value_ptr(((mat4x4*)arg)->super_type));
	}
	PyGLM_TYPEERROR_O("value_ptr() requires the argument to be a glm type, not ", arg);
	return NULL;
}

static PyObject*
make_vec2_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_vec2() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_vec2(glm::make_vec2((float*)vp_as_ull));
}
static PyObject*
make_vec3_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_vec3() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_vec3(glm::make_vec3((float*)vp_as_ull));
}
static PyObject*
make_vec4_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_vec4() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_vec4(glm::make_vec4((float*)vp_as_ull));
}
static PyObject*
make_quat_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_quat() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_quat(glm::make_quat((float*)vp_as_ull));
}
static PyObject*
make_mat2x2_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat2x2() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat2x2(glm::make_mat2x2((float*)vp_as_ull));
}
static PyObject*
make_mat2x3_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat2x3() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat2x3(glm::make_mat2x3((float*)vp_as_ull));
}
static PyObject*
make_mat2x4_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat2x4() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat2x4(glm::make_mat2x4((float*)vp_as_ull));
}
static PyObject*
make_mat3x2_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat3x2() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat3x2(glm::make_mat3x2((float*)vp_as_ull));
}
static PyObject*
make_mat3x3_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat3x3() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat3x3(glm::make_mat3x3((float*)vp_as_ull));
}
static PyObject*
make_mat3x4_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat3x4() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat3x4(glm::make_mat3x4((float*)vp_as_ull));
}
static PyObject*
make_mat4x2_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat4x2() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat4x2(glm::make_mat4x2((float*)vp_as_ull));
}
static PyObject*
make_mat4x3_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat4x3() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat4x3(glm::make_mat4x3((float*)vp_as_ull));
}
static PyObject*
make_mat4x4_(PyObject* self, PyObject* arg) {
	if (!PyObject_TypeCheck(arg, (PyTypeObject*)c_void_p)) {
		PyGLM_TYPEERROR_O("make_mat4x4() requires a ctypes.c_void_p as it's argument, not ", arg);
		return NULL;
	}
	PyObject* vp_as_pyull = PyObject_GetAttrString(arg, "value");
	unsigned long long vp_as_ull = PyLong_AsUnsignedLongLong(vp_as_pyull);
	Py_DECREF(vp_as_pyull);
	return pack_mat4x4(glm::make_mat4x4((float*)vp_as_ull));
}

//static PyObject*
//test(PyObject* self, PyObject* arg) {
//	return pack_mat2x2(glm::identity<glm::mat2>());
//}
//#define HAS_TEST
//#define TEST_FUNC_TYPE METH_NOARGS

static PyMethodDef detailmethods[] = {
	// func_packing
	{ "packDouble2x32", (PyCFunction)packDouble2x32_, METH_O, "packDouble2x32(v) -> float\nReturns a double-qualifier value obtained by packing the components of v into a 64-bit value." },
	{ "packUnorm2x16", (PyCFunction)packUnorm2x16_, METH_O, "packUnorm2x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packSnorm2x16", (PyCFunction)packSnorm2x16_, METH_O, "packSnorm2x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packSnorm4x8", (PyCFunction)packSnorm4x8_, METH_O, "packSnorm4x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packUnorm4x8", (PyCFunction)packUnorm4x8_, METH_O, "packUnorm4x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packHalf2x16", (PyCFunction)packHalf2x16_, METH_O, "packHalf2x16(v) -> int\nReturns an unsigned integer obtained by converting the components of a two - component floating - point vector\nto the 16-bit floating-point representation found in the OpenGL Specification,\nand then packing these two 16- bit integers into a 32-bit unsigned integer." },
	{ "unpackDouble2x32", (PyCFunction)unpackDouble2x32_, METH_O, "unpackDouble2x32(v) -> float\nReturns a two-component unsigned integer vector representation of v." },
	{ "unpackUnorm2x16", (PyCFunction)unpackUnorm2x16_, METH_O, "unpackUnorm2x16(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackSnorm2x16", (PyCFunction)unpackSnorm2x16_, METH_O, "unpackSnorm2x16(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackSnorm4x8", (PyCFunction)unpackSnorm4x8_, METH_O, "unpackSnorm4x8(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackUnorm4x8", (PyCFunction)unpackUnorm4x8_, METH_O, "unpackUnorm4x8(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackHalf2x16", (PyCFunction)unpackHalf2x16_, METH_O, "unpackHalf2x16(v) -> int\nReturns a two - component floating - point vector with components obtained by unpacking a 32 - bit unsigned integer into a pair of 16 - bit values,\ninterpreting those values as 16-bit floating-point numbers according to the OpenGL Specification,\nand converting them to 32-bit floating-point values." },

	// func_integer
	{ "uaddCarry", (PyCFunction)uaddCarry_, METH_VARARGS, "uaddCarry(x, y, Carry) -> vecn\nAdds 32-bit unsigned integer x and y, returning the sum\nmodulo pow(2, 32). The value carry is set to 0 if the sum was\nless than pow(2, 32), or to 1 otherwise." },
	{ "usubBorrow", (PyCFunction)usubBorrow_, METH_VARARGS, "usubBorrow(x, y, Borrow) -> vecn\nSubtracts the 32-bit unsigned integer y from x, returning\nthe difference if non-negative, or pow(2, 32) plus the difference\notherwise. The value borrow is set to 0 if x >= y, or to 1 otherwise." },
	{ "umulExtended", (PyCFunction)umulExtended_, METH_VARARGS, "umulExtended(x, y, msb, lsb) -> None\nMultiplies 32-bit integers x and y, producing a 64-bit\nresult. The 32 least-significant bits are returned in lsb.\nThe 32 most-significant bits are returned in msb." },
	{ "imulExtended", (PyCFunction)imulExtended_, METH_VARARGS, "imulExtended(x, y, msb, lsb) -> None\nMultiplies 32-bit integers x and y, producing a 64-bit\nresult. The 32 least-significant bits are returned in lsb.\nThe 32 most-significant bits are returned in msb." },
	{ "bitfieldExtract", (PyCFunction)bitfieldExtract_, METH_VARARGS, "bitfieldExtract(Value, Offset, Bits) -> vecn or int\nExtracts bits [offset, offset + bits - 1] from value,\nreturning them in the least significant bits of the result." },
	{ "bitfieldInsert", (PyCFunction)bitfieldInsert_, METH_VARARGS, "bitfieldInsert(Base, Insert, Offset, Bits) -> vecn or int\nReturns the insertion the bits least-significant bits of insert into base." },
	{ "bitfieldReverse", (PyCFunction)bitfieldReverse_, METH_O, "bitfieldReverse(v) -> vecn or float\nReturns the reversal of the bits of value." },
	{ "bitCount", (PyCFunction)bitCount_, METH_O, "bitCount(v) -> vecn or int\nReturns the number of bits set to 1 in the binary representation of value." },
	{ "findLSB", (PyCFunction)findLSB_, METH_O, "findLSB(x) -> vecn or int\nReturns the bit number of the least significant bit set to\n1 in the binary representation of value.\nIf value is zero, -1 will be returned." },
	{ "findMSB", (PyCFunction)findMSB_, METH_O, "findMSB(x) -> vecn or int\nReturns the bit number of the most significant bit in the binary representation of value." },

	// func_vector_relational
	{ "equal", (PyCFunction)equal, METH_VARARGS, "equal(x, y) -> (x == y)\nReturns the component-wise comparison of result x == y." },
	{ "notEqual", (PyCFunction)notEqual, METH_VARARGS, "notEqual(x, y) -> (x != y)\nReturns the component-wise comparison of result x != y." },
	{ "lessThan", (PyCFunction)lessThan, METH_VARARGS, "lessThan(x, y) -> (x < y)\nReturns the component-wise comparison of result x < y." },
	{ "lessThanEqual", (PyCFunction)lessThanEqual, METH_VARARGS, "lessThanEqual(x, y) -> (x <= y)\nReturns the component-wise comparison of result x <= y." },
	{ "greaterThan", (PyCFunction)greaterThan, METH_VARARGS, "greaterThan(x, y) -> (x > y)\nReturns the component-wise comparison of result x > y." },
	{ "greaterThanEqual", (PyCFunction)greaterThanEqual, METH_VARARGS, "greaterThanEqual(x, y) -> (x >= y)\nReturns the component-wise comparison of result x >= y." },
	{ "any", (PyCFunction)any, METH_O, "any(x) -> bool\nReturns true if any component of x is true." },
	{ "all", (PyCFunction)all, METH_O, "all(x) -> bool\nReturns true if all components of x are true." },
	{ "not_", (PyCFunction)not_, METH_O, "not(x) -> bool\nReturns the component-wise logical complement of x." },

	// func_exponential
	{ "pow", (PyCFunction)pow_, METH_VARARGS, "pow(base, exponent) -> float or vecn\nReturns 'base' raised to the power 'exponent'." },
	{ "exp", (PyCFunction)exp_, METH_O, "exp(x) -> float or vecn\nReturns the natural exponentiation of x, i.e., e^x." },
	{ "log", (PyCFunction)log_, METH_O, "log(v) -> float or vecn\nReturns the natural logarithm of v, i.e.,\nreturns the value y which satisfies the equation x = e^y.\nResults are undefined if v <= 0." },
	{ "exp2", (PyCFunction)exp2_, METH_O, "exp2(v) -> float or vecn\nReturns 2 raised to the v power." },
	{ "log2", (PyCFunction)log2_, METH_O, "log2(x) -> float or vecn\nReturns the base 2 log of x, i.e., returns the value y,\nwhich satisfies the equation x = 2 ^ y." },
	{ "sqrt", (PyCFunction)sqrt_, METH_O, "sqrt(v) -> float or vecn\nReturns the positive square root of v." },
	{ "inversesqrt", (PyCFunction)inversesqrt_, METH_O, "inversesqrt(v) -> float or vecn\nReturns the reciprocal of the positive square root of v." },

	// func_common
	{ "abs", (PyCFunction)abs_, METH_O, "abs(x) -> float or vecn\nReturns x if x >= 0; otherwise, it returns -x." },
	{ "sign", (PyCFunction)sign_, METH_O, "sign(x) -> float or vecn\nReturns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0. " },
	{ "floor", (PyCFunction)floor_, METH_O, "floor(x) -> float or vecn\nReturns a value equal to the nearest integer that is less then or equal to x." },
	{ "trunc", (PyCFunction)trunc_, METH_O, "trunc(x) -> float or vecn\nReturns a value equal to the nearest integer to x\nwhose absolute value is not larger than the absolute value of x." },
	{ "round", (PyCFunction)round_, METH_O, "round(x) -> float or vecn\nReturns a value equal to the nearest integer to x.\nThe fraction 0.5 will round in a direction chosen by the\nimplementation, presumably the direction that is fastest.\nThis includes the possibility that round(x) returns the\nsame value as roundEven(x) for all values of x." },
	{ "roundEven", (PyCFunction)roundEven_, METH_O, "roundEven(x) -> float or vecn\nReturns a value equal to the nearest integer to x.\nA fractional part of 0.5 will round toward the nearest even\ninteger. (Both 3.5 and 4.5 for x will return 4.0.)" },
	{ "ceil", (PyCFunction)ceil_, METH_O, "ceil(x) -> float or vecn\nReturns a value equal to the nearest integer\nthat is greater than or equal to x." },
	{ "fract", (PyCFunction)fract_, METH_O, "fract(x) -> float or vecn\nReturn x - floor(x)." },
	{ "mod", (PyCFunction)mod_, METH_VARARGS, "mod(x, y) -> float or vecn\nModulus. Returns x - y * floor(x / y)\nfor each component in x using the floating point value y." },
	{ "min", (PyCFunction)min_, METH_VARARGS, "min(x, y) -> float or vecn\nReturns y if y < x; otherwise, it returns x." },
	{ "max", (PyCFunction)max_, METH_VARARGS, "max(x, y) -> float or vecn\nReturns y if x < y; otherwise, it returns x." },
	{ "clamp", (PyCFunction)clamp_, METH_VARARGS, "clamp(x, minVal, maxVal) -> float or vecn\nReturns min(max(x, minVal), maxVal) for each component in x\nusing the floating-point values minVal and maxVal." },
	{ "mix", (PyCFunction)mix_, METH_VARARGS, "mix(x, y, a) -> float, vecn or quat\nReturns x * (1.0 - a) + y * a, i.e., the linear blend of\nx and y using the floating-point value a.\nThe value for a is not restricted to the range [0, 1]." },
	{ "step", (PyCFunction)step_, METH_VARARGS, "step(edge, x) -> Returns 0.0 if x < edge, otherwise it returns 1.0." },
	{ "smoothstep", (PyCFunction)smoothstep_, METH_VARARGS, "smoothstep(edge0, edge1, x) -> float or vecn\nReturns 0.0 if x <= edge0 and 1.0 if x >= edge1 and\nperforms smooth Hermite interpolation between 0 and 1\nwhen edge0 < x < edge1. This is useful in cases where\nyou would want a threshold function with a smooth\ntransition." },
	{ "isnan", (PyCFunction)isnan_, METH_O, "isnan(x) -> bool or vecn\nReturns true if x holds a NaN (not a number)\nrepresentation in the underlying implementation's set of\nfloating point representations. Returns false otherwise,\nincluding for implementations with no NaN\nrepresentations." },
	{ "isinf", (PyCFunction)isinf_, METH_O, "isinf(x) -> bool or vecn\nReturns true if x holds a positive infinity or negative\ninfinity representation in the underlying implementation's\nset of floating point representations. Returns false\notherwise, including for implementations with no infinity\nrepresentations." },
	{ "fma", (PyCFunction)fma_, METH_VARARGS, "fma(a, b, c) -> float\nComputes and returns a * b + c." },
	//{ "frexp", (PyCFunction)frexp_, METH_VARARGS, "frexp(x, exp) -> float or vecn\nSplits x into a floating-point significand in the range\n[0.5, 1.0) and an integral exponent of two, such that:\nx = significand * exp(2, exponent)" },
	//{ "ldexp", (PyCFunction)ldexp_, METH_VARARGS, "ldexp(x, exp) -> float or vecn\nBuilds a floating-point number from x and the\ncorresponding integral exponent of two in exp, returning:\nsignificand * exp(2, exponent)" },

	// func_geometric
	{ "length", (PyCFunction)length_, METH_O, "length(x) -> float\nReturns the length of x, i.e., sqrt(x * x)." },
	{ "distance", (PyCFunction)distance_, METH_VARARGS, "distance(p0, p1) -> float\nReturns the distance betwwen p0 and p1, i.e., length(p0 - p1)." },
	{ "dot", (PyCFunction)dot_, METH_VARARGS, "dot(x, y) -> float\nReturns the dot product of x and y, i.e., result = x * y." },
	{ "cross", (PyCFunction)cross_, METH_VARARGS, "cross(x, y) -> vec3 or quat\nReturns the cross product of x and y." },
	{ "normalize", (PyCFunction)normalize_, METH_O, "normalize(x) -> vecn or quat\nReturns a vector in the same direction as x but with length of 1." },
	{ "faceforward", (PyCFunction)faceforward_, METH_VARARGS, "faceforward(N, I, Nref) -> float or vecn\nIf dot(Nref, I) < 0.0, return N, otherwise, return -N." },
	{ "reflect", (PyCFunction)reflect_, METH_VARARGS, "reflect(I, N) -> float or vecn\nFor the incident vector I and surface orientation N,\nreturns the reflection direction : result = I - 2.0 * dot(N, I) * N." },
	{ "refract", (PyCFunction)refract_, METH_VARARGS, "refract(I, N, eta) -> float or vecn\nFor the incident vector I and surface normal N,\nand the ratio of indices of refraction eta,\nreturn the refraction vector." },

	// func_matrix
	{ "matrixCompMult", (PyCFunction)matrixCompMult_, METH_VARARGS, "matrixCompMult(x, y) -> matnxn\nMultiply matrix x by matrix y component-wise, i.e.,\nresult[i][j] is the scalar product of x[i][j] and y[i][j]." },
	{ "outerProduct", (PyCFunction)outerProduct_, METH_VARARGS, "outerProduct(c, r) -> matnxn\nTreats the first parameter c as a column vector\nand the second parameter r as a row vector\nand does a linear algebraic matrix multiply c * r." },
	{ "transpose", (PyCFunction)transpose_, METH_O, "transpose(x) -> matnxn\nReturns the transposed matrix of x" },
	{ "determinant", (PyCFunction)determinant_, METH_O, "determinant(x) -> float\nReturn the determinant of a squared matrix." },
	{ "inverse", (PyCFunction)inverse_, METH_O, "inverse(x) -> matnxn or quat\nReturn the inverse of a squared matrix or quaternion." },

	// func_trigonometric
	{ "radians", (PyCFunction)radians_, METH_O, "radians(x) -> float or vecn\nConverts degrees to radians and returns the result." },
	{ "degrees", (PyCFunction)degrees_, METH_O, "degrees(x) -> float or vecn\nConverts radians to degrees and returns the result." },
	{ "sin", (PyCFunction)sin_, METH_O, "sin(x) -> vecn\nThe standard trigonometric sine function. \nThe values returned by this function will range from [-1, 1]." },
	{ "cos", (PyCFunction)cos_, METH_O, "cos(x) -> vecn\nThe standard trigonometric cosine function.\nThe values returned by this function will range from [-1, 1]." },
	{ "tan", (PyCFunction)tan_, METH_O, "tan(x) -> vecn\nThe standard trigonometric tangent function." },
	{ "asin", (PyCFunction)asin_, METH_O, "asin(x) -> vecn\nArc sine. Returns an angle whose sine is x. \nThe range of values returned by this function is [-PI/2, PI/2].\nResults are undefined if |x| > 1." },
	{ "acos", (PyCFunction)acos_, METH_O, "acos(x) -> vecn\nArc cosine. Returns an angle whose sine is x.\nThe range of values returned by this function is [0, PI].\nResults are undefined if |x| > 1." },
	{ "atan", (PyCFunction)atan_,  METH_VARARGS | METH_KEYWORDS, "atan(y [,x]) -> float or vecn\nArc tangent. Returns an angle whose tangent is y/x.\nThe signs of x and y are used to determine what\nquadrant the angle is in. The range of values returned\nby this function is [-PI, PI]. Results are undefined\nif x and y are both 0." },
	{ "sinh", (PyCFunction)sinh_, METH_O, "sinh(x) -> vecn\nReturns the hyperbolic sine function, (exp(x) - exp(-x)) / 2" },
	{ "cosh", (PyCFunction)cosh_, METH_O, "cosh(x) -> vecn\nReturns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2" },
	{ "tanh", (PyCFunction)tanh_, METH_O, "tanh(x) -> vecn\nReturns the hyperbolic tangent function, sinh(angle) / cosh(angle)" },
	{ "asinh", (PyCFunction)asinh_, METH_O, "asinh(x) -> float or vecn\nArc hyperbolic sine; returns the inverse of sinh." },
	{ "acosh", (PyCFunction)acosh_, METH_O, "acosh(x) -> float or vecn\nArc hyperbolic cosine; returns the non-negative inverse\nof cosh. Results are undefined if x < 1." },
	{ "atanh", (PyCFunction)atanh_, METH_O, "atanh(x) -> float or vecn\nArc hyperbolic tangent; returns the inverse of tanh.\nResults are undefined if abs(x) >= 1." },
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef detailmodule = {
	PyModuleDef_HEAD_INIT,
	"glm::detail",
	"Features that implement in Python the GLSL specification as closely as necessary.\nglm::detail namespace",
	-1,
	detailmethods, NULL, NULL, NULL, NULL
};

static PyMethodDef gtcmethods[] = {
	// color_space
	{ "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB_, METH_VARARGS | METH_KEYWORDS, "convertLinearToSRGB(ColorLinear[, Gamma]) -> vecn\nConvert a linear color to sRGB color using a standard / custom gamma correction." },
	{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear_, METH_VARARGS | METH_KEYWORDS, "convertSRGBToLinear(ColorLinear[, Gamma]) -> vecn\nConvert a sRGB color to linear color using a standard / custom gamma correction." },

	// constants
	{ "epsilon", (PyCFunction)epsilon_, METH_NOARGS, "epsilon() -> float\nReturn the epsilon constant for floating point types." },
	{ "zero", (PyCFunction)zero_, METH_NOARGS, "zero() -> float\nReturn 0." },
	{ "one", (PyCFunction)one_, METH_NOARGS, "one() -> float\nReturn 1." },
	{ "pi", (PyCFunction)pi_, METH_NOARGS, "pi() -> float\nReturn the pi constant." },
	{ "two_pi", (PyCFunction)two_pi_, METH_NOARGS, "two_pi() -> float\nReturn pi * 2." },
	{ "root_pi", (PyCFunction)root_pi_, METH_NOARGS, "root_pi() -> float\nReturn square root of pi." },
	{ "half_pi", (PyCFunction)half_pi_, METH_NOARGS, "half_pi() -> float\nReturn pi / 2." },
	{ "three_over_two_pi", (PyCFunction)three_over_two_pi_, METH_NOARGS, "three_over_two_pi() -> float\nReturn pi / 2 * 3." },
	{ "quarter_pi", (PyCFunction)quarter_pi_, METH_NOARGS, "quarter_pi() -> float\nReturn pi / 4." },
	{ "one_over_pi", (PyCFunction)one_over_pi_, METH_NOARGS, "one_over_pi() -> float\nReturn 1 / pi." },
	{ "one_over_two_pi", (PyCFunction)one_over_two_pi_, METH_NOARGS, "one_over_two_pi() -> float\nReturn 1 / (pi * 2)." },
	{ "two_over_pi", (PyCFunction)two_over_pi_, METH_NOARGS, "two_over_pi() -> float\nReturn 2 / pi." },
	{ "four_over_pi", (PyCFunction)four_over_pi_, METH_NOARGS, "four_over_pi() -> float\nReturn 4 / pi." },
	{ "two_over_root_pi", (PyCFunction)two_over_root_pi_, METH_NOARGS, "two_over_root_pi() -> float\nReturn 2 / sqrt(pi)." },
	{ "one_over_root_two", (PyCFunction)one_over_root_two_, METH_NOARGS, "one_over_root_two() -> float\nReturn 1 / sqrt(2)." },
	{ "root_half_pi", (PyCFunction)root_half_pi_, METH_NOARGS, "root_half_pi() -> float\nReturn sqrt(pi / 2)." },
	{ "root_two_pi", (PyCFunction)root_two_pi_, METH_NOARGS, "root_two_pi() -> float\nReturn sqrt(2 * pi)." },
	{ "root_ln_four", (PyCFunction)root_ln_four_, METH_NOARGS, "root_ln_four() -> float\nReturn sqrt(ln(4))." },
	{ "e", (PyCFunction)e_, METH_NOARGS, "e() -> float\nReturn e constant." },
	{ "euler", (PyCFunction)euler_, METH_NOARGS, "euler() -> float\nReturn Euler's constant." },
	{ "root_two", (PyCFunction)root_two_, METH_NOARGS, "root_two() -> float\nReturn sqrt(2)." },
	{ "root_three", (PyCFunction)root_three_, METH_NOARGS, "root_three() -> float\nReturn sqrt(3)." },
	{ "root_five", (PyCFunction)root_five_, METH_NOARGS, "root_five() -> float\nReturn sqrt(5)." },
	{ "ln_two", (PyCFunction)ln_two_, METH_NOARGS, "ln_two() -> float\nReturn ln(2)." },
	{ "ln_ten", (PyCFunction)ln_ten_, METH_NOARGS, "ln_ten() -> float\nReturn ln(10)." },
	{ "ln_ln_two", (PyCFunction)ln_ln_two_, METH_NOARGS, "ln_ln_two() -> float\nReturn ln(ln(2))." },
	{ "third", (PyCFunction)third_, METH_NOARGS, "third() -> float\nReturn 1 / 3." },
	{ "two_thirds", (PyCFunction)two_thirds_, METH_NOARGS, "two_thirds() -> float\nReturn 2 / 3." },
	{ "golden_ratio", (PyCFunction)golden_ratio_, METH_NOARGS, "golden_ratio() -> float\nReturn the golden ratio constant." },

	// epsilon
	{ "epsilonEqual", (PyCFunction)epsilonEqual_, METH_VARARGS, "epsilonEqual(x, y, epsilon) -> vecn or quat\nReturns the component-wise comparison of |x - y| < epsilon.\nTrue if this expression is satisfied." },
	{ "epsilonNotEqual", (PyCFunction)epsilonNotEqual_, METH_VARARGS, "epsilonNotEqual(x, y, epsilon) -> vecn or quat\nReturns the component-wise comparison of |x - y| >= epsilon.\nTrue if this expression is satisfied." },

	// matrix_transform
	{ "identity", (PyCFunction)identity_, METH_O, "identity(matrix_type) -> matrix\nBuilds an identity matrix." },
	{ "translate", (PyCFunction)translate_, METH_VARARGS, "translate(m, v) -> mat4x4\nBuilds a translation 4 * 4 matrix created from a vector of 3 components." },
	{ "rotate", (PyCFunction)rotate_, METH_VARARGS, "rotate(m, angle, axis) -> mat4x4 or quat\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle\nor rotates a quaternion from a vector of 3 components axis and an angle." },
	{ "rotate_slow", (PyCFunction)rotate_slow_, METH_VARARGS, "rotate_slow(m, angle, axis) -> mat4x4\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle." },
	{ "scale", (PyCFunction)scale_, METH_VARARGS, "scale(m, v) -> mat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "scale_slow", (PyCFunction)scale_slow_, METH_VARARGS, "scale_slow(m, v) -> mat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "ortho", (PyCFunction)ortho_, METH_VARARGS, "ortho(left, right, bottom, top[, zNear, zFar]) -> mat4x4\nCreates a matrix for projecting two-dimensional coordinates onto the screen." },
	{ "orthoLH_ZO", (PyCFunction)orthoLH_ZO_, METH_VARARGS, "orthoLH_ZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoLH_NO", (PyCFunction)orthoLH_NO_, METH_VARARGS, "orthoLH_NO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH_ZO", (PyCFunction)orthoRH_ZO_, METH_VARARGS, "orthoRH_ZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoRH_NO", (PyCFunction)orthoRH_NO_, METH_VARARGS, "orthoRH_NO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoZO", (PyCFunction)orthoZO_, METH_VARARGS, "orthoZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoNO", (PyCFunction)orthoNO_, METH_VARARGS, "orthoNO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoLH", (PyCFunction)orthoLH_, METH_VARARGS, "orthoLH(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH", (PyCFunction)orthoRH_, METH_VARARGS, "orthoRH(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustum", (PyCFunction)frustum_, METH_VARARGS, "frustum(left, right, bottom, top, near, far) -> mat4x4\nCreates a frustum matrix with default handedness, using right-handedness and -1 to +1 near and far clip planes definition." },
	{ "frustumLH_ZO", (PyCFunction)frustumLH_ZO_, METH_VARARGS, "frustumLH_ZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumLH_NO", (PyCFunction)frustumLH_NO_, METH_VARARGS, "frustumLH_NO(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH_ZO", (PyCFunction)frustumRH_ZO_, METH_VARARGS, "frustumRH_ZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumRH_NO", (PyCFunction)frustumRH_NO_, METH_VARARGS, "frustumRH_NO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumZO", (PyCFunction)frustumZO_, METH_VARARGS, "frustumZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumNO", (PyCFunction)frustumNO_, METH_VARARGS, "frustumNO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumLH", (PyCFunction)frustumLH_, METH_VARARGS, "frustumLH(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH", (PyCFunction)frustumRH_, METH_VARARGS, "frustumRH(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspective", (PyCFunction)perspective_, METH_VARARGS, "perspective(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum." },
	{ "perspectiveLH_ZO", (PyCFunction)perspectiveLH_ZO_, METH_VARARGS, "perspectiveLH_ZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveLH_NO", (PyCFunction)perspectiveLH_NO_, METH_VARARGS, "perspectiveLH_NO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH_ZO", (PyCFunction)perspectiveRH_ZO_, METH_VARARGS, "perspectiveRH_ZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveRH_NO", (PyCFunction)perspectiveRH_NO_, METH_VARARGS, "perspectiveRH_NO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveZO", (PyCFunction)perspectiveZO_, METH_VARARGS, "perspectiveZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveNO", (PyCFunction)perspectiveNO_, METH_VARARGS, "perspectiveNO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveLH", (PyCFunction)perspectiveLH_, METH_VARARGS, "perspectiveLH(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH", (PyCFunction)perspectiveRH_, METH_VARARGS, "perspectiveRH(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFov", (PyCFunction)perspectiveFov_, METH_VARARGS, "perspectiveFov(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates." },
	{ "perspectiveFovLH_ZO", (PyCFunction)perspectiveFovLH_ZO_, METH_VARARGS, "perspectiveFovLH_ZO(fov, width, height, near, far) -> mat4x4\n\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovLH_NO", (PyCFunction)perspectiveFovLH_NO_, METH_VARARGS, "perspectiveFovLH_NO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH_ZO", (PyCFunction)perspectiveFovRH_ZO_, METH_VARARGS, "perspectiveFovRH_ZO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovRH_NO", (PyCFunction)perspectiveFovRH_NO_, METH_VARARGS, "perspectiveFovRH_NO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovZO", (PyCFunction)perspectiveFovZO_, METH_VARARGS, "perspectiveFovZO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovNO", (PyCFunction)perspectiveFovNO_, METH_VARARGS, "perspectiveFovNO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovLH", (PyCFunction)perspectiveFovLH_, METH_VARARGS, "perspectiveFovLH(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH", (PyCFunction)perspectiveFovRH_, METH_VARARGS, "perspectiveFovRH(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "infinitePerspective", (PyCFunction)infinitePerspective_, METH_VARARGS, "infinitePerspective(fovy, aspect, near) -> mat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveRH", (PyCFunction)infinitePerspectiveRH_, METH_VARARGS, "infinitePerspectiveRH(fovy, aspect, near) -> mat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveLH", (PyCFunction)infinitePerspectiveLH_, METH_VARARGS, "infinitePerspectiveLH(fovy, aspect, near) -> mat4x4\nCreates a matrix for a left handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "tweakedInfinitePerspective", (PyCFunction)tweakedInfinitePerspective_, METH_VARARGS, "tweakedInfinitePerspective(fovy, aspect, near[, ep]) -> mat4x4\nCreates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping." },
	{ "project", (PyCFunction)project_, METH_VARARGS, "project(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectNO", (PyCFunction)projectNO_, METH_VARARGS, "projectNO(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectZO", (PyCFunction)projectZO_, METH_VARARGS, "projectZO(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "unProject", (PyCFunction)unProject_, METH_VARARGS, "unProject(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectNO", (PyCFunction)unProjectNO_, METH_VARARGS, "unProjectNO(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectZO", (PyCFunction)unProjectZO_, METH_VARARGS, "unProjectZO(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "pickMatrix", (PyCFunction)pickMatrix_, METH_VARARGS, "pickMatrix(center, delta, viewport) -> mat4x4\nDefine a picking region" },
	{ "lookAt", (PyCFunction)lookAt_, METH_VARARGS, "lookAt(eye, center, up) -> mat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtRH", (PyCFunction)lookAtRH_, METH_VARARGS, "lookAtRH(eye, center, up) -> mat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtLH", (PyCFunction)lookAtLH_, METH_VARARGS, "lookAtLH(eye, center, up) -> mat4x4\nBuild a left handed look at view matrix." },

	// quaternion
	{ "quatLookAt", (PyCFunction)quatLookAt_, METH_VARARGS, "quatLookAt(direction, up) -> quat\nBuild a look at quaternion based on the default handedness." },
	{ "quatLookAtLH", (PyCFunction)quatLookAtLH_, METH_VARARGS, "quatLookAtLH(direction, up) -> quat\nBuild a left-handed look at quaternion." },
	{ "quatLookAtRH", (PyCFunction)quatLookAtRH_, METH_VARARGS, "quatLookAtRH(direction, up) -> quat\nBuild a right-handed look at quaternion." },
	{ "lerp", (PyCFunction)lerp_, METH_VARARGS, "lerp(x, y, a) -> quat\nLinear interpolation of two quaternions.\nThe interpolation is oriented." },
	{ "slerp", (PyCFunction)slerp_, METH_VARARGS, "slerp(x, y, a) -> quat\nSpherical linear interpolation of two quaternions.\nThe interpolation always take the short path and the rotation is performed at constant speed." },
	{ "conjugate", (PyCFunction)conjugate_, METH_O, "conjugate(q) -> quat\nReturns the q conjugate." },
	{ "eulerAngles", (PyCFunction)eulerAngles_, METH_O, "eulerAngles(x) -> vec3\nReturns euler angles, pitch as x, yaw as y, roll as z." },
	{ "roll", (PyCFunction)roll_, METH_O, "roll(x) -> float\nReturns roll value of euler angles expressed in radians." },
	{ "pitch", (PyCFunction)pitch_, METH_O, "pitch(x) -> float\nReturns pitch value of euler angles expressed in radians." },
	{ "yaw", (PyCFunction)yaw_, METH_O, "yaw(x) -> float\nReturns yaw value of euler angles expressed in radians." },
	{ "mat3_cast", (PyCFunction)mat3_cast_, METH_O, "mat3_cast(x) -> mat3x3\nConverts a quaternion to a 3 * 3 matrix." },
	{ "mat4_cast", (PyCFunction)mat4_cast_, METH_O, "mat4_cast(x) -> mat4x4\nConverts a quaternion to a 4 * 4 matrix." },
	{ "quat_cast", (PyCFunction)quat_cast_, METH_O, "quat_cast(m) -> quat\nConverts a 3 * 3 or 4 * 4 matrix to a quaternion." },
	{ "angle", (PyCFunction)angle_, METH_O, "angle(x) -> float\nReturns the quaternion rotation angle." },
	{ "axis", (PyCFunction)axis_, METH_O, "axis(x) -> vec3\nReturns the quaternion rotation axis." },
	{ "angleAxis", (PyCFunction)angleAxis_, METH_VARARGS, "angleAxis(angle, v) -> quat\nBuild a quaternion from an angle and a normalized axis." },

	// matrix_access
	{ "row", (PyCFunction)row_, METH_VARARGS | METH_KEYWORDS, "row(m, index[, x]) -> vecn or matnxn\nGet a specific row of a matrix or set a specific row to a matrix." },
	{ "column", (PyCFunction)column_, METH_VARARGS | METH_KEYWORDS, "column(m, index[, x]) -> vecn or matnxn\nGet a specific column of a matrix or set a specific column to a matrix." },

	// noise
	//{ "grad4", (PyCFunction)grad4_, METH_VARARGS, "grad4(j, ip) -> vec4" },
	{ "perlin", (PyCFunction)perlin_, METH_VARARGS | METH_KEYWORDS, "perlin(p[, rep]) -> float\nClassic or periodic perlin noise." },
	{ "simplex", (PyCFunction)simplex_, METH_O, "simplex(p) -> float\nSimplex noise." },

	// random
	{ "linearRand", (PyCFunction)linearRand_, METH_VARARGS, "linearRand(Min, Max) -> float or vecn\nGenerate random numbers in the interval [Min, Max], according a linear distribution" },
	{ "gaussRand", (PyCFunction)gaussRand_, METH_VARARGS, "gaussRand(Mean, Deviation) -> float\nGenerate random numbers in the interval [Min, Max], according a gaussian distribution" },
	{ "circularRand", (PyCFunction)circularRand_, METH_O, "circularRand(Radius) -> vec2\nGenerate a random 2D vector which coordinates are regulary distributed on a circle of a given radius" },
	{ "sphericalRand", (PyCFunction)sphericalRand_, METH_O, "sphericalRand(Radius) -> vec3\nGenerate a random 3D vector which coordinates are regulary distributed on a sphere of a given radius" },
	{ "diskRand", (PyCFunction)diskRand_, METH_O, "diskRand(Radius) -> vec2\nGenerate a random 2D vector which coordinates are regulary distributed within the area of a disk of a given radius" },
	{ "ballRand", (PyCFunction)ballRand_, METH_O, "ballRand(Radius) -> vec3\nGenerate a random 3D vector which coordinates are regulary distributed within the area of a ball of a given radius" },

	// reciprocal
	{ "sec", (PyCFunction)sec_, METH_O, "sec(x) -> float or vecn\nSecant function.\nhypotenuse / adjacent or 1 / cos(x)" },
	{ "csc", (PyCFunction)csc_, METH_O, "csc(x) -> float or vecn\nCosecant function.\nhypotenuse / opposite or 1 / sin(x)" },
	{ "cot", (PyCFunction)cot_, METH_O, "cot(x) -> float or vecn\nCotangent function.\nadjacent / opposite or 1 / tan(x)" },
	{ "asec", (PyCFunction)asec_, METH_O, "asec(x) -> float or vecn\nInverse secant function." },
	{ "acsc", (PyCFunction)acsc_, METH_O, "acsc(x) -> float or vecn\nInverse cosecant function." },
	{ "acot", (PyCFunction)acot_, METH_O, "acot(x) -> float or vecn\nInverse cotangent function." },
	{ "sech", (PyCFunction)sech_, METH_O, "sech(x) -> float or vecn\nSecant hyperbolic function." },
	{ "csch", (PyCFunction)csch_, METH_O, "csch(x) -> float or vecn\nCosecant hyperbolic function." },
	{ "coth", (PyCFunction)coth_, METH_O, "coth(x) -> float or vecn\nCotangent hyperbolic function." },
	{ "asech", (PyCFunction)asech_, METH_O, "asech(x) -> float or vecn\nInverse secant hyperbolic function." },
	{ "acsch", (PyCFunction)acsch_, METH_O, "acsch(x) -> float or vecn\nInverse cosecant hyperbolic function." },
	{ "acoth", (PyCFunction)acoth_, METH_O, "acoth(x) -> float or vecn\nInverse cotangent hyperbolic function." },

	// type_ptr
	{ "value_ptr", (PyCFunction)value_ptr_, METH_O, "value_ptr(x) -> ctypes.c_void_p\nReturn the constant address to the data of the input parameter." },
	{ "sizeof", (PyCFunction)sizeof_, METH_O, "sizeof(x) -> int\nReturn the size of x in bytes." },
	{ "make_vec2", (PyCFunction)make_vec2_, METH_O, "make_vec2(ctypes.c_void_p) -> vec2\nBuild a vector from a pointer." },
	{ "make_vec3", (PyCFunction)make_vec3_, METH_O, "make_vec3(ctypes.c_void_p) -> vec3\nBuild a vector from a pointer." },
	{ "make_vec4", (PyCFunction)make_vec4_, METH_O, "make_vec4(ctypes.c_void_p) -> vec4\nBuild a vector from a pointer." },
	{ "make_mat2", (PyCFunction)make_mat2x2_, METH_O, "make_mat2(ctypes.c_void_p) -> mat2x2\nBuild a matrix from a pointer." },
	{ "make_mat2x2", (PyCFunction)make_mat2x2_, METH_O, "make_mat2x2(ctypes.c_void_p) -> mat2x2\nBuild a matrix from a pointer." },
	{ "make_mat2x3", (PyCFunction)make_mat2x3_, METH_O, "make_mat2x3(ctypes.c_void_p) -> mat2x3\nBuild a matrix from a pointer." },
	{ "make_mat2x4", (PyCFunction)make_mat2x4_, METH_O, "make_mat2x4(ctypes.c_void_p) -> mat2x4\nBuild a matrix from a pointer." },
	{ "make_mat3x2", (PyCFunction)make_mat3x2_, METH_O, "make_mat3x2(ctypes.c_void_p) -> mat3x2\nBuild a matrix from a pointer." },
	{ "make_mat3", (PyCFunction)make_mat3x3_, METH_O, "make_mat3(ctypes.c_void_p) -> mat3x3\nBuild a matrix from a pointer." },
	{ "make_mat3x3", (PyCFunction)make_mat3x3_, METH_O, "make_mat3x3(ctypes.c_void_p) -> mat3x3\nBuild a matrix from a pointer." },
	{ "make_mat3x4", (PyCFunction)make_mat3x4_, METH_O, "make_mat3x4(ctypes.c_void_p) -> mat3x4\nBuild a matrix from a pointer." },
	{ "make_mat4x2", (PyCFunction)make_mat4x2_, METH_O, "make_mat4x2(ctypes.c_void_p) -> mat4x2\nBuild a matrix from a pointer." },
	{ "make_mat4x3", (PyCFunction)make_mat4x3_, METH_O, "make_mat4x3(ctypes.c_void_p) -> mat4x3\nBuild a matrix from a pointer." },
	{ "make_mat4", (PyCFunction)make_mat4x4_, METH_O, "make_mat4(ctypes.c_void_p) -> mat4x4\nBuild a matrix from a pointer." },
	{ "make_mat4x4", (PyCFunction)make_mat4x4_, METH_O, "make_mat4x4(ctypes.c_void_p) -> mat4x4\nBuild a matrix from a pointer." },
	{ "make_quat", (PyCFunction)make_quat_, METH_O, "make_quat(ctypes.c_void_p) -> quat\nBuild a quaternion from a pointer." },
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef gtcmodule = {
	PyModuleDef_HEAD_INIT,
	"glm::gtc",
	"Features that implement in Python the GLSL specification as closely as necessary.\nglm::gtc namespace",
	-1,
	gtcmethods, NULL, NULL, NULL, NULL
};

static PyMethodDef glmmethods[] = {
	// DETAIL
	// func_packing
	{ "packDouble2x32", (PyCFunction)packDouble2x32_, METH_O, "packDouble2x32(v) -> float\nReturns a double-qualifier value obtained by packing the components of v into a 64-bit value." },
	{ "packUnorm2x16", (PyCFunction)packUnorm2x16_, METH_O, "packUnorm2x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packSnorm2x16", (PyCFunction)packSnorm2x16_, METH_O, "packSnorm2x16(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packSnorm4x8", (PyCFunction)packSnorm4x8_, METH_O, "packSnorm4x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packUnorm4x8", (PyCFunction)packUnorm4x8_, METH_O, "packUnorm4x8(v) -> int\nFirst, converts each component of the normalized floating-point value v into 8- or 16-bit integer values.\nThen, the results are packed into the returned 32-bit unsigned integer." },
	{ "packHalf2x16", (PyCFunction)packHalf2x16_, METH_O, "packHalf2x16(v) -> int\nReturns an unsigned integer obtained by converting the components of a two - component floating - point vector\nto the 16-bit floating-point representation found in the OpenGL Specification,\nand then packing these two 16- bit integers into a 32-bit unsigned integer." },
	{ "unpackDouble2x32", (PyCFunction)unpackDouble2x32_, METH_O, "unpackDouble2x32(v) -> float\nReturns a two-component unsigned integer vector representation of v." },
	{ "unpackUnorm2x16", (PyCFunction)unpackUnorm2x16_, METH_O, "unpackUnorm2x16(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackSnorm2x16", (PyCFunction)unpackSnorm2x16_, METH_O, "unpackSnorm2x16(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackSnorm4x8", (PyCFunction)unpackSnorm4x8_, METH_O, "unpackSnorm4x8(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackUnorm4x8", (PyCFunction)unpackUnorm4x8_, METH_O, "unpackUnorm4x8(v) -> int\nFirst, unpacks a single 32-bit unsigned integer p into a pair of 16-bit unsigned integers, four 8-bit unsigned integers, or four 8-bit signed integers.\nThen, each component is converted to a normalized floating-point value to generate the returned two- or four-component vector." },
	{ "unpackHalf2x16", (PyCFunction)unpackHalf2x16_, METH_O, "unpackHalf2x16(v) -> int\nReturns a two - component floating - point vector with components obtained by unpacking a 32 - bit unsigned integer into a pair of 16 - bit values,\ninterpreting those values as 16-bit floating-point numbers according to the OpenGL Specification,\nand converting them to 32-bit floating-point values." },

	// func_integer
	{ "uaddCarry", (PyCFunction)uaddCarry_, METH_VARARGS, "uaddCarry(x, y, Carry) -> vecn\nAdds 32-bit unsigned integer x and y, returning the sum\nmodulo pow(2, 32). The value carry is set to 0 if the sum was\nless than pow(2, 32), or to 1 otherwise." },
	{ "usubBorrow", (PyCFunction)usubBorrow_, METH_VARARGS, "usubBorrow(x, y, Borrow) -> vecn\nSubtracts the 32-bit unsigned integer y from x, returning\nthe difference if non-negative, or pow(2, 32) plus the difference\notherwise. The value borrow is set to 0 if x >= y, or to 1 otherwise." },
	{ "umulExtended", (PyCFunction)umulExtended_, METH_VARARGS, "umulExtended(x, y, msb, lsb) -> None\nMultiplies 32-bit integers x and y, producing a 64-bit\nresult. The 32 least-significant bits are returned in lsb.\nThe 32 most-significant bits are returned in msb." },
	{ "imulExtended", (PyCFunction)imulExtended_, METH_VARARGS, "imulExtended(x, y, msb, lsb) -> None\nMultiplies 32-bit integers x and y, producing a 64-bit\nresult. The 32 least-significant bits are returned in lsb.\nThe 32 most-significant bits are returned in msb." },
	{ "bitfieldExtract", (PyCFunction)bitfieldExtract_, METH_VARARGS, "bitfieldExtract(Value, Offset, Bits) -> vecn or int\nExtracts bits [offset, offset + bits - 1] from value,\nreturning them in the least significant bits of the result." },
	{ "bitfieldInsert", (PyCFunction)bitfieldInsert_, METH_VARARGS, "bitfieldInsert(Base, Insert, Offset, Bits) -> vecn or int\nReturns the insertion the bits least-significant bits of insert into base." },
	{ "bitfieldReverse", (PyCFunction)bitfieldReverse_, METH_O, "bitfieldReverse(v) -> vecn or float\nReturns the reversal of the bits of value." },
	{ "bitCount", (PyCFunction)bitCount_, METH_O, "bitCount(v) -> vecn or int\nReturns the number of bits set to 1 in the binary representation of value." },
	{ "findLSB", (PyCFunction)findLSB_, METH_O, "findLSB(x) -> vecn or int\nReturns the bit number of the least significant bit set to\n1 in the binary representation of value.\nIf value is zero, -1 will be returned." },
	{ "findMSB", (PyCFunction)findMSB_, METH_O, "findMSB(x) -> vecn or int\nReturns the bit number of the most significant bit in the binary representation of value." },

	// func_vector_relational
	{ "equal", (PyCFunction)equal, METH_VARARGS, "equal(x, y) -> (x == y)\nReturns the component-wise comparison of result x == y." },
	{ "notEqual", (PyCFunction)notEqual, METH_VARARGS, "notEqual(x, y) -> (x != y)\nReturns the component-wise comparison of result x != y." },
	{ "lessThan", (PyCFunction)lessThan, METH_VARARGS, "lessThan(x, y) -> (x < y)\nReturns the component-wise comparison of result x < y." },
	{ "lessThanEqual", (PyCFunction)lessThanEqual, METH_VARARGS, "lessThanEqual(x, y) -> (x <= y)\nReturns the component-wise comparison of result x <= y." },
	{ "greaterThan", (PyCFunction)greaterThan, METH_VARARGS, "greaterThan(x, y) -> (x > y)\nReturns the component-wise comparison of result x > y." },
	{ "greaterThanEqual", (PyCFunction)greaterThanEqual, METH_VARARGS, "greaterThanEqual(x, y) -> (x >= y)\nReturns the component-wise comparison of result x >= y." },
	{ "any", (PyCFunction)any, METH_O, "any(x) -> bool\nReturns true if any component of x is true." },
	{ "all", (PyCFunction)all, METH_O, "all(x) -> bool\nReturns true if all components of x are true." },
	{ "not_", (PyCFunction)not_, METH_O, "not(x) -> bool\nReturns the component-wise logical complement of x." },

	// func_exponential
	{ "pow", (PyCFunction)pow_, METH_VARARGS, "pow(base, exponent) -> float or vecn\nReturns 'base' raised to the power 'exponent'." },
	{ "exp", (PyCFunction)exp_, METH_O, "exp(x) -> float or vecn\nReturns the natural exponentiation of x, i.e., e^x." },
	{ "log", (PyCFunction)log_, METH_O, "log(v) -> float or vecn\nReturns the natural logarithm of v, i.e.,\nreturns the value y which satisfies the equation x = e^y.\nResults are undefined if v <= 0." },
	{ "exp2", (PyCFunction)exp2_, METH_O, "exp2(v) -> float or vecn\nReturns 2 raised to the v power." },
	{ "log2", (PyCFunction)log2_, METH_O, "log2(x) -> float or vecn\nReturns the base 2 log of x, i.e., returns the value y,\nwhich satisfies the equation x = 2 ^ y." },
	{ "sqrt", (PyCFunction)sqrt_, METH_O, "sqrt(v) -> float or vecn\nReturns the positive square root of v." },
	{ "inversesqrt", (PyCFunction)inversesqrt_, METH_O, "inversesqrt(v) -> float or vecn\nReturns the reciprocal of the positive square root of v." },

	// func_common
	{ "abs", (PyCFunction)abs_, METH_O, "abs(x) -> float or vecn\nReturns x if x >= 0; otherwise, it returns -x." },
	{ "sign", (PyCFunction)sign_, METH_O, "sign(x) -> float or vecn\nReturns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0. " },
	{ "floor", (PyCFunction)floor_, METH_O, "floor(x) -> float or vecn\nReturns a value equal to the nearest integer that is less then or equal to x." },
	{ "trunc", (PyCFunction)trunc_, METH_O, "trunc(x) -> float or vecn\nReturns a value equal to the nearest integer to x\nwhose absolute value is not larger than the absolute value of x." },
	{ "round", (PyCFunction)round_, METH_O, "round(x) -> float or vecn\nReturns a value equal to the nearest integer to x.\nThe fraction 0.5 will round in a direction chosen by the\nimplementation, presumably the direction that is fastest.\nThis includes the possibility that round(x) returns the\nsame value as roundEven(x) for all values of x." },
	{ "roundEven", (PyCFunction)roundEven_, METH_O, "roundEven(x) -> float or vecn\nReturns a value equal to the nearest integer to x.\nA fractional part of 0.5 will round toward the nearest even\ninteger. (Both 3.5 and 4.5 for x will return 4.0.)" },
	{ "ceil", (PyCFunction)ceil_, METH_O, "ceil(x) -> float or vecn\nReturns a value equal to the nearest integer\nthat is greater than or equal to x." },
	{ "fract", (PyCFunction)fract_, METH_O, "fract(x) -> float or vecn\nReturn x - floor(x)." },
	{ "mod", (PyCFunction)mod_, METH_VARARGS, "mod(x, y) -> float or vecn\nModulus. Returns x - y * floor(x / y)\nfor each component in x using the floating point value y." },
	{ "min", (PyCFunction)min_, METH_VARARGS, "min(x, y) -> float or vecn\nReturns y if y < x; otherwise, it returns x." },
	{ "max", (PyCFunction)max_, METH_VARARGS, "max(x, y) -> float or vecn\nReturns y if x < y; otherwise, it returns x." },
	{ "clamp", (PyCFunction)clamp_, METH_VARARGS, "clamp(x, minVal, maxVal) -> float or vecn\nReturns min(max(x, minVal), maxVal) for each component in x\nusing the floating-point values minVal and maxVal." },
	{ "mix", (PyCFunction)mix_, METH_VARARGS, "mix(x, y, a) -> float, vecn or quat\nReturns x * (1.0 - a) + y * a, i.e., the linear blend of\nx and y using the floating-point value a.\nThe value for a is not restricted to the range [0, 1]." },
	{ "step", (PyCFunction)step_, METH_VARARGS, "step(edge, x) -> Returns 0.0 if x < edge, otherwise it returns 1.0." },
	{ "smoothstep", (PyCFunction)smoothstep_, METH_VARARGS, "smoothstep(edge0, edge1, x) -> float or vecn\nReturns 0.0 if x <= edge0 and 1.0 if x >= edge1 and\nperforms smooth Hermite interpolation between 0 and 1\nwhen edge0 < x < edge1. This is useful in cases where\nyou would want a threshold function with a smooth\ntransition." },
	{ "isnan", (PyCFunction)isnan_, METH_O, "isnan(x) -> bool or vecn\nReturns true if x holds a NaN (not a number)\nrepresentation in the underlying implementation's set of\nfloating point representations. Returns false otherwise,\nincluding for implementations with no NaN\nrepresentations." },
	{ "isinf", (PyCFunction)isinf_, METH_O, "isinf(x) -> bool or vecn\nReturns true if x holds a positive infinity or negative\ninfinity representation in the underlying implementation's\nset of floating point representations. Returns false\notherwise, including for implementations with no infinity\nrepresentations." },
	{ "fma", (PyCFunction)fma_, METH_VARARGS, "fma(a, b, c) -> float\nComputes and returns a * b + c." },
	//{ "frexp", (PyCFunction)frexp_, METH_VARARGS, "frexp(x, exp) -> float or vecn\nSplits x into a floating-point significand in the range\n[0.5, 1.0) and an integral exponent of two, such that:\nx = significand * exp(2, exponent)" },
	//{ "ldexp", (PyCFunction)ldexp_, METH_VARARGS, "ldexp(x, exp) -> float or vecn\nBuilds a floating-point number from x and the\ncorresponding integral exponent of two in exp, returning:\nsignificand * exp(2, exponent)" },

	// func_geometric
	{ "length", (PyCFunction)length_, METH_O, "length(x) -> float\nReturns the length of x, i.e., sqrt(x * x)." },
	{ "distance", (PyCFunction)distance_, METH_VARARGS, "distance(p0, p1) -> float\nReturns the distance betwwen p0 and p1, i.e., length(p0 - p1)." },
	{ "dot", (PyCFunction)dot_, METH_VARARGS, "dot(x, y) -> float\nReturns the dot product of x and y, i.e., result = x * y." },
	{ "cross", (PyCFunction)cross_, METH_VARARGS, "cross(x, y) -> vec3 or quat\nReturns the cross product of x and y." },
	{ "normalize", (PyCFunction)normalize_, METH_O, "normalize(x) -> vecn or quat\nReturns a vector in the same direction as x but with length of 1." },
	{ "faceforward", (PyCFunction)faceforward_, METH_VARARGS, "faceforward(N, I, Nref) -> float or vecn\nIf dot(Nref, I) < 0.0, return N, otherwise, return -N." },
	{ "reflect", (PyCFunction)reflect_, METH_VARARGS, "reflect(I, N) -> float or vecn\nFor the incident vector I and surface orientation N,\nreturns the reflection direction : result = I - 2.0 * dot(N, I) * N." },
	{ "refract", (PyCFunction)refract_, METH_VARARGS, "refract(I, N, eta) -> float or vecn\nFor the incident vector I and surface normal N,\nand the ratio of indices of refraction eta,\nreturn the refraction vector." },

	// func_matrix
	{ "matrixCompMult", (PyCFunction)matrixCompMult_, METH_VARARGS, "matrixCompMult(x, y) -> matnxn\nMultiply matrix x by matrix y component-wise, i.e.,\nresult[i][j] is the scalar product of x[i][j] and y[i][j]." },
	{ "outerProduct", (PyCFunction)outerProduct_, METH_VARARGS, "outerProduct(c, r) -> matnxn\nTreats the first parameter c as a column vector\nand the second parameter r as a row vector\nand does a linear algebraic matrix multiply c * r." },
	{ "transpose", (PyCFunction)transpose_, METH_O, "transpose(x) -> matnxn\nReturns the transposed matrix of x" },
	{ "determinant", (PyCFunction)determinant_, METH_O, "determinant(x) -> float\nReturn the determinant of a squared matrix." },
	{ "inverse", (PyCFunction)inverse_, METH_O, "inverse(x) -> matnxn or quat\nReturn the inverse of a squared matrix or quaternion." },

	// func_trigonometric
	{ "radians", (PyCFunction)radians_, METH_O, "radians(x) -> float or vecn\nConverts degrees to radians and returns the result." },
	{ "degrees", (PyCFunction)degrees_, METH_O, "degrees(x) -> float or vecn\nConverts radians to degrees and returns the result." },
	{ "sin", (PyCFunction)sin_, METH_O, "sin(x) -> vecn\nThe standard trigonometric sine function. \nThe values returned by this function will range from [-1, 1]." },
	{ "cos", (PyCFunction)cos_, METH_O, "cos(x) -> vecn\nThe standard trigonometric cosine function.\nThe values returned by this function will range from [-1, 1]." },
	{ "tan", (PyCFunction)tan_, METH_O, "tan(x) -> vecn\nThe standard trigonometric tangent function." },
	{ "asin", (PyCFunction)asin_, METH_O, "asin(x) -> vecn\nArc sine. Returns an angle whose sine is x. \nThe range of values returned by this function is [-PI/2, PI/2].\nResults are undefined if |x| > 1." },
	{ "acos", (PyCFunction)acos_, METH_O, "acos(x) -> vecn\nArc cosine. Returns an angle whose sine is x.\nThe range of values returned by this function is [0, PI].\nResults are undefined if |x| > 1." },
	{ "atan", (PyCFunction)atan_,  METH_VARARGS | METH_KEYWORDS, "atan(y [,x]) -> float or vecn\nArc tangent. Returns an angle whose tangent is y/x.\nThe signs of x and y are used to determine what\nquadrant the angle is in. The range of values returned\nby this function is [-PI, PI]. Results are undefined\nif x and y are both 0." },
	{ "sinh", (PyCFunction)sinh_, METH_O, "sinh(x) -> vecn\nReturns the hyperbolic sine function, (exp(x) - exp(-x)) / 2" },
	{ "cosh", (PyCFunction)cosh_, METH_O, "cosh(x) -> vecn\nReturns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2" },
	{ "tanh", (PyCFunction)tanh_, METH_O, "tanh(x) -> vecn\nReturns the hyperbolic tangent function, sinh(angle) / cosh(angle)" },
	{ "asinh", (PyCFunction)asinh_, METH_O, "asinh(x) -> float or vecn\nArc hyperbolic sine; returns the inverse of sinh." },
	{ "acosh", (PyCFunction)acosh_, METH_O, "acosh(x) -> float or vecn\nArc hyperbolic cosine; returns the non-negative inverse\nof cosh. Results are undefined if x < 1." },
	{ "atanh", (PyCFunction)atanh_, METH_O, "atanh(x) -> float or vecn\nArc hyperbolic tangent; returns the inverse of tanh.\nResults are undefined if abs(x) >= 1." },

	// GTC
	// color_space
	{ "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB_, METH_VARARGS | METH_KEYWORDS, "convertLinearToSRGB(ColorLinear[, Gamma]) -> vecn\nConvert a linear color to sRGB color using a standard / custom gamma correction." },
	{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear_, METH_VARARGS | METH_KEYWORDS, "convertSRGBToLinear(ColorLinear[, Gamma]) -> vecn\nConvert a sRGB color to linear color using a standard / custom gamma correction." },

	// constants
	{ "epsilon", (PyCFunction)epsilon_, METH_NOARGS, "epsilon() -> float\nReturn the epsilon constant for floating point types." },
	{ "zero", (PyCFunction)zero_, METH_NOARGS, "zero() -> float\nReturn 0." },
	{ "one", (PyCFunction)one_, METH_NOARGS, "one() -> float\nReturn 1." },
	{ "pi", (PyCFunction)pi_, METH_NOARGS, "pi() -> float\nReturn the pi constant." },
	{ "two_pi", (PyCFunction)two_pi_, METH_NOARGS, "two_pi() -> float\nReturn pi * 2." },
	{ "root_pi", (PyCFunction)root_pi_, METH_NOARGS, "root_pi() -> float\nReturn square root of pi." },
	{ "half_pi", (PyCFunction)half_pi_, METH_NOARGS, "half_pi() -> float\nReturn pi / 2." },
	{ "three_over_two_pi", (PyCFunction)three_over_two_pi_, METH_NOARGS, "three_over_two_pi() -> float\nReturn pi / 2 * 3." },
	{ "quarter_pi", (PyCFunction)quarter_pi_, METH_NOARGS, "quarter_pi() -> float\nReturn pi / 4." },
	{ "one_over_pi", (PyCFunction)one_over_pi_, METH_NOARGS, "one_over_pi() -> float\nReturn 1 / pi." },
	{ "one_over_two_pi", (PyCFunction)one_over_two_pi_, METH_NOARGS, "one_over_two_pi() -> float\nReturn 1 / (pi * 2)." },
	{ "two_over_pi", (PyCFunction)two_over_pi_, METH_NOARGS, "two_over_pi() -> float\nReturn 2 / pi." },
	{ "four_over_pi", (PyCFunction)four_over_pi_, METH_NOARGS, "four_over_pi() -> float\nReturn 4 / pi." },
	{ "two_over_root_pi", (PyCFunction)two_over_root_pi_, METH_NOARGS, "two_over_root_pi() -> float\nReturn 2 / sqrt(pi)." },
	{ "one_over_root_two", (PyCFunction)one_over_root_two_, METH_NOARGS, "one_over_root_two() -> float\nReturn 1 / sqrt(2)." },
	{ "root_half_pi", (PyCFunction)root_half_pi_, METH_NOARGS, "root_half_pi() -> float\nReturn sqrt(pi / 2)." },
	{ "root_two_pi", (PyCFunction)root_two_pi_, METH_NOARGS, "root_two_pi() -> float\nReturn sqrt(2 * pi)." },
	{ "root_ln_four", (PyCFunction)root_ln_four_, METH_NOARGS, "root_ln_four() -> float\nReturn sqrt(ln(4))." },
	{ "e", (PyCFunction)e_, METH_NOARGS, "e() -> float\nReturn e constant." },
	{ "euler", (PyCFunction)euler_, METH_NOARGS, "euler() -> float\nReturn Euler's constant." },
	{ "root_two", (PyCFunction)root_two_, METH_NOARGS, "root_two() -> float\nReturn sqrt(2)." },
	{ "root_three", (PyCFunction)root_three_, METH_NOARGS, "root_three() -> float\nReturn sqrt(3)." },
	{ "root_five", (PyCFunction)root_five_, METH_NOARGS, "root_five() -> float\nReturn sqrt(5)." },
	{ "ln_two", (PyCFunction)ln_two_, METH_NOARGS, "ln_two() -> float\nReturn ln(2)." },
	{ "ln_ten", (PyCFunction)ln_ten_, METH_NOARGS, "ln_ten() -> float\nReturn ln(10)." },
	{ "ln_ln_two", (PyCFunction)ln_ln_two_, METH_NOARGS, "ln_ln_two() -> float\nReturn ln(ln(2))." },
	{ "third", (PyCFunction)third_, METH_NOARGS, "third() -> float\nReturn 1 / 3." },
	{ "two_thirds", (PyCFunction)two_thirds_, METH_NOARGS, "two_thirds() -> float\nReturn 2 / 3." },
	{ "golden_ratio", (PyCFunction)golden_ratio_, METH_NOARGS, "golden_ratio() -> float\nReturn the golden ratio constant." },

	// epsilon
	{ "epsilonEqual", (PyCFunction)epsilonEqual_, METH_VARARGS, "epsilonEqual(x, y, epsilon) -> vecn or quat\nReturns the component-wise comparison of |x - y| < epsilon.\nTrue if this expression is satisfied." },
	{ "epsilonNotEqual", (PyCFunction)epsilonNotEqual_, METH_VARARGS, "epsilonNotEqual(x, y, epsilon) -> vecn or quat\nReturns the component-wise comparison of |x - y| >= epsilon.\nTrue if this expression is satisfied." },

	// matrix_transform
	{ "identity", (PyCFunction)identity_, METH_O, "identity(matrix_type) -> matrix\nBuilds an identity matrix." },
	{ "translate", (PyCFunction)translate_, METH_VARARGS, "translate(m, v) -> mat4x4\nBuilds a translation 4 * 4 matrix created from a vector of 3 components." },
	{ "rotate", (PyCFunction)rotate_, METH_VARARGS, "rotate(m, angle, axis) -> mat4x4 or quat\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle\nor rotates a quaternion from a vector of 3 components axis and an angle." },
	{ "rotate_slow", (PyCFunction)rotate_slow_, METH_VARARGS, "rotate_slow(m, angle, axis) -> mat4x4\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle." },
	{ "scale", (PyCFunction)scale_, METH_VARARGS, "scale(m, v) -> mat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "scale_slow", (PyCFunction)scale_slow_, METH_VARARGS, "scale_slow(m, v) -> mat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "ortho", (PyCFunction)ortho_, METH_VARARGS, "ortho(left, right, bottom, top[, zNear, zFar]) -> mat4x4\nCreates a matrix for projecting two-dimensional coordinates onto the screen." },
	{ "orthoLH_ZO", (PyCFunction)orthoLH_ZO_, METH_VARARGS, "orthoLH_ZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoLH_NO", (PyCFunction)orthoLH_NO_, METH_VARARGS, "orthoLH_NO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH_ZO", (PyCFunction)orthoRH_ZO_, METH_VARARGS, "orthoRH_ZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoRH_NO", (PyCFunction)orthoRH_NO_, METH_VARARGS, "orthoRH_NO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoZO", (PyCFunction)orthoZO_, METH_VARARGS, "orthoZO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoNO", (PyCFunction)orthoNO_, METH_VARARGS, "orthoNO(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoLH", (PyCFunction)orthoLH_, METH_VARARGS, "orthoLH(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH", (PyCFunction)orthoRH_, METH_VARARGS, "orthoRH(left, right, bottom, top, zNear, zFar) -> mat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustum", (PyCFunction)frustum_, METH_VARARGS, "frustum(left, right, bottom, top, near, far) -> mat4x4\nCreates a frustum matrix with default handedness, using right-handedness and -1 to +1 near and far clip planes definition." },
	{ "frustumLH_ZO", (PyCFunction)frustumLH_ZO_, METH_VARARGS, "frustumLH_ZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumLH_NO", (PyCFunction)frustumLH_NO_, METH_VARARGS, "frustumLH_NO(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH_ZO", (PyCFunction)frustumRH_ZO_, METH_VARARGS, "frustumRH_ZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumRH_NO", (PyCFunction)frustumRH_NO_, METH_VARARGS, "frustumRH_NO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumZO", (PyCFunction)frustumZO_, METH_VARARGS, "frustumZO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumNO", (PyCFunction)frustumNO_, METH_VARARGS, "frustumNO(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumLH", (PyCFunction)frustumLH_, METH_VARARGS, "frustumLH(left, right, bottom, top, near, far) -> mat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH", (PyCFunction)frustumRH_, METH_VARARGS, "frustumRH(left, right, bottom, top, near, far) -> mat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspective", (PyCFunction)perspective_, METH_VARARGS, "perspective(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum." },
	{ "perspectiveLH_ZO", (PyCFunction)perspectiveLH_ZO_, METH_VARARGS, "perspectiveLH_ZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveLH_NO", (PyCFunction)perspectiveLH_NO_, METH_VARARGS, "perspectiveLH_NO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH_ZO", (PyCFunction)perspectiveRH_ZO_, METH_VARARGS, "perspectiveRH_ZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveRH_NO", (PyCFunction)perspectiveRH_NO_, METH_VARARGS, "perspectiveRH_NO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveZO", (PyCFunction)perspectiveZO_, METH_VARARGS, "perspectiveZO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveNO", (PyCFunction)perspectiveNO_, METH_VARARGS, "perspectiveNO(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveLH", (PyCFunction)perspectiveLH_, METH_VARARGS, "perspectiveLH(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH", (PyCFunction)perspectiveRH_, METH_VARARGS, "perspectiveRH(fovy, aspect, near, far) -> mat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFov", (PyCFunction)perspectiveFov_, METH_VARARGS, "perspectiveFov(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates." },
	{ "perspectiveFovLH_ZO", (PyCFunction)perspectiveFovLH_ZO_, METH_VARARGS, "perspectiveFovLH_ZO(fov, width, height, near, far) -> mat4x4\n\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovLH_NO", (PyCFunction)perspectiveFovLH_NO_, METH_VARARGS, "perspectiveFovLH_NO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH_ZO", (PyCFunction)perspectiveFovRH_ZO_, METH_VARARGS, "perspectiveFovRH_ZO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovRH_NO", (PyCFunction)perspectiveFovRH_NO_, METH_VARARGS, "perspectiveFovRH_NO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovZO", (PyCFunction)perspectiveFovZO_, METH_VARARGS, "perspectiveFovZO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovNO", (PyCFunction)perspectiveFovNO_, METH_VARARGS, "perspectiveFovNO(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovLH", (PyCFunction)perspectiveFovLH_, METH_VARARGS, "perspectiveFovLH(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH", (PyCFunction)perspectiveFovRH_, METH_VARARGS, "perspectiveFovRH(fov, width, height, near, far) -> mat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "infinitePerspective", (PyCFunction)infinitePerspective_, METH_VARARGS, "infinitePerspective(fovy, aspect, near) -> mat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveRH", (PyCFunction)infinitePerspectiveRH_, METH_VARARGS, "infinitePerspectiveRH(fovy, aspect, near) -> mat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveLH", (PyCFunction)infinitePerspectiveLH_, METH_VARARGS, "infinitePerspectiveLH(fovy, aspect, near) -> mat4x4\nCreates a matrix for a left handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "tweakedInfinitePerspective", (PyCFunction)tweakedInfinitePerspective_, METH_VARARGS, "tweakedInfinitePerspective(fovy, aspect, near[, ep]) -> mat4x4\nCreates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping." },
	{ "project", (PyCFunction)project_, METH_VARARGS, "project(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectNO", (PyCFunction)projectNO_, METH_VARARGS, "projectNO(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectZO", (PyCFunction)projectZO_, METH_VARARGS, "projectZO(obj, model, proj, viewport) -> vec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "unProject", (PyCFunction)unProject_, METH_VARARGS, "unProject(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectNO", (PyCFunction)unProjectNO_, METH_VARARGS, "unProjectNO(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectZO", (PyCFunction)unProjectZO_, METH_VARARGS, "unProjectZO(obj, model, proj, viewport) -> vec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "pickMatrix", (PyCFunction)pickMatrix_, METH_VARARGS, "pickMatrix(center, delta, viewport) -> mat4x4\nDefine a picking region" },
	{ "lookAt", (PyCFunction)lookAt_, METH_VARARGS, "lookAt(eye, center, up) -> mat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtRH", (PyCFunction)lookAtRH_, METH_VARARGS, "lookAtRH(eye, center, up) -> mat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtLH", (PyCFunction)lookAtLH_, METH_VARARGS, "lookAtLH(eye, center, up) -> mat4x4\nBuild a left handed look at view matrix." },

	// quaternion
	{ "quatLookAt", (PyCFunction)quatLookAt_, METH_VARARGS, "quatLookAt(direction, up) -> quat\nBuild a look at quaternion based on the default handedness." },
	{ "quatLookAtLH", (PyCFunction)quatLookAtLH_, METH_VARARGS, "quatLookAtLH(direction, up) -> quat\nBuild a left-handed look at quaternion." },
	{ "quatLookAtRH", (PyCFunction)quatLookAtRH_, METH_VARARGS, "quatLookAtRH(direction, up) -> quat\nBuild a right-handed look at quaternion." },
	{ "lerp", (PyCFunction)lerp_, METH_VARARGS, "lerp(x, y, a) -> quat\nLinear interpolation of two quaternions.\nThe interpolation is oriented." },
	{ "slerp", (PyCFunction)slerp_, METH_VARARGS, "slerp(x, y, a) -> quat\nSpherical linear interpolation of two quaternions.\nThe interpolation always take the short path and the rotation is performed at constant speed." },
	{ "conjugate", (PyCFunction)conjugate_, METH_O, "conjugate(q) -> quat\nReturns the q conjugate." },
	{ "eulerAngles", (PyCFunction)eulerAngles_, METH_O, "eulerAngles(x) -> vec3\nReturns euler angles, pitch as x, yaw as y, roll as z." },
	{ "roll", (PyCFunction)roll_, METH_O, "roll(x) -> float\nReturns roll value of euler angles expressed in radians." },
	{ "pitch", (PyCFunction)pitch_, METH_O, "pitch(x) -> float\nReturns pitch value of euler angles expressed in radians." },
	{ "yaw", (PyCFunction)yaw_, METH_O, "yaw(x) -> float\nReturns yaw value of euler angles expressed in radians." },
	{ "mat3_cast", (PyCFunction)mat3_cast_, METH_O, "mat3_cast(x) -> mat3x3\nConverts a quaternion to a 3 * 3 matrix." },
	{ "mat4_cast", (PyCFunction)mat4_cast_, METH_O, "mat4_cast(x) -> mat4x4\nConverts a quaternion to a 4 * 4 matrix." },
	{ "quat_cast", (PyCFunction)quat_cast_, METH_O, "quat_cast(m) -> quat\nConverts a 3 * 3 or 4 * 4 matrix to a quaternion." },
	{ "angle", (PyCFunction)angle_, METH_O, "angle(x) -> float\nReturns the quaternion rotation angle." },
	{ "axis", (PyCFunction)axis_, METH_O, "axis(x) -> vec3\nReturns the quaternion rotation axis." },
	{ "angleAxis", (PyCFunction)angleAxis_, METH_VARARGS, "angleAxis(angle, v) -> quat\nBuild a quaternion from an angle and a normalized axis." },

	// matrix_access
	{ "row", (PyCFunction)row_, METH_VARARGS | METH_KEYWORDS, "row(m, index[, x]) -> vecn or matnxn\nGet a specific row of a matrix or set a specific row to a matrix." },
	{ "column", (PyCFunction)column_, METH_VARARGS | METH_KEYWORDS, "column(m, index[, x]) -> vecn or matnxn\nGet a specific column of a matrix or set a specific column to a matrix." },

	// noise
	//{ "grad4", (PyCFunction)grad4_, METH_VARARGS, "grad4(j, ip) -> vec4" },
	{ "perlin", (PyCFunction)perlin_, METH_VARARGS, "perlin(p[, rep]) -> float\nClassic or periodic perlin noise." },
	{ "simplex", (PyCFunction)simplex_, METH_O, "simplex(p) -> float\nSimplex noise." },

	// random
	{ "linearRand", (PyCFunction)linearRand_, METH_VARARGS, "linearRand(Min, Max) -> float or vecn\nGenerate random numbers in the interval [Min, Max], according a linear distribution" },
	{ "gaussRand", (PyCFunction)gaussRand_, METH_VARARGS, "gaussRand(Mean, Deviation) -> float\nGenerate random numbers in the interval [Min, Max], according a gaussian distribution" },
	{ "circularRand", (PyCFunction)circularRand_, METH_O, "circularRand(Radius) -> vec2\nGenerate a random 2D vector which coordinates are regulary distributed on a circle of a given radius" },
	{ "sphericalRand", (PyCFunction)sphericalRand_, METH_O, "sphericalRand(Radius) -> vec3\nGenerate a random 3D vector which coordinates are regulary distributed on a sphere of a given radius" },
	{ "diskRand", (PyCFunction)diskRand_, METH_O, "diskRand(Radius) -> vec2\nGenerate a random 2D vector which coordinates are regulary distributed within the area of a disk of a given radius" },
	{ "ballRand", (PyCFunction)ballRand_, METH_O, "ballRand(Radius) -> vec3\nGenerate a random 3D vector which coordinates are regulary distributed within the area of a ball of a given radius" },

	// reciprocal
	{ "sec", (PyCFunction)sec_, METH_O, "sec(x) -> float or vecn\nSecant function.\nhypotenuse / adjacent or 1 / cos(x)" },
	{ "csc", (PyCFunction)csc_, METH_O, "csc(x) -> float or vecn\nCosecant function.\nhypotenuse / opposite or 1 / sin(x)" },
	{ "cot", (PyCFunction)cot_, METH_O, "cot(x) -> float or vecn\nCotangent function.\nadjacent / opposite or 1 / tan(x)" },
	{ "asec", (PyCFunction)asec_, METH_O, "asec(x) -> float or vecn\nInverse secant function." },
	{ "acsc", (PyCFunction)acsc_, METH_O, "acsc(x) -> float or vecn\nInverse cosecant function." },
	{ "acot", (PyCFunction)acot_, METH_O, "acot(x) -> float or vecn\nInverse cotangent function." },
	{ "sech", (PyCFunction)sech_, METH_O, "sech(x) -> float or vecn\nSecant hyperbolic function." },
	{ "csch", (PyCFunction)csch_, METH_O, "csch(x) -> float or vecn\nCosecant hyperbolic function." },
	{ "coth", (PyCFunction)coth_, METH_O, "coth(x) -> float or vecn\nCotangent hyperbolic function." },
	{ "asech", (PyCFunction)asech_, METH_O, "asech(x) -> float or vecn\nInverse secant hyperbolic function." },
	{ "acsch", (PyCFunction)acsch_, METH_O, "acsch(x) -> float or vecn\nInverse cosecant hyperbolic function." },
	{ "acoth", (PyCFunction)acoth_, METH_O, "acoth(x) -> float or vecn\nInverse cotangent hyperbolic function." },

	// type_ptr
	{ "value_ptr", (PyCFunction)value_ptr_, METH_O, "value_ptr(x) -> void* as int\nReturn the constant address to the data of the input parameter." },
	{ "sizeof", (PyCFunction)sizeof_, METH_O, "sizeof(x) -> int\nReturn the size of x in bytes." },
	{ "make_vec2", (PyCFunction)make_vec2_, METH_O, "make_vec2(ctypes.c_void_p) -> vec2\nBuild a vector from a pointer." },
	{ "make_vec3", (PyCFunction)make_vec3_, METH_O, "make_vec3(ctypes.c_void_p) -> vec3\nBuild a vector from a pointer." },
	{ "make_vec4", (PyCFunction)make_vec4_, METH_O, "make_vec4(ctypes.c_void_p) -> vec4\nBuild a vector from a pointer." },
	{ "make_mat2", (PyCFunction)make_mat2x2_, METH_O, "make_mat2(ctypes.c_void_p) -> mat2x2\nBuild a matrix from a pointer." },
	{ "make_mat2x2", (PyCFunction)make_mat2x2_, METH_O, "make_mat2x2(ctypes.c_void_p) -> mat2x2\nBuild a matrix from a pointer." },
	{ "make_mat2x3", (PyCFunction)make_mat2x3_, METH_O, "make_mat2x3(ctypes.c_void_p) -> mat2x3\nBuild a matrix from a pointer." },
	{ "make_mat2x4", (PyCFunction)make_mat2x4_, METH_O, "make_mat2x4(ctypes.c_void_p) -> mat2x4\nBuild a matrix from a pointer." },
	{ "make_mat3x2", (PyCFunction)make_mat3x2_, METH_O, "make_mat3x2(ctypes.c_void_p) -> mat3x2\nBuild a matrix from a pointer." },
	{ "make_mat3", (PyCFunction)make_mat3x3_, METH_O, "make_mat3(ctypes.c_void_p) -> mat3x3\nBuild a matrix from a pointer." },
	{ "make_mat3x3", (PyCFunction)make_mat3x3_, METH_O, "make_mat3x3(ctypes.c_void_p) -> mat3x3\nBuild a matrix from a pointer." },
	{ "make_mat3x4", (PyCFunction)make_mat3x4_, METH_O, "make_mat3x4(ctypes.c_void_p) -> mat3x4\nBuild a matrix from a pointer." },
	{ "make_mat4x2", (PyCFunction)make_mat4x2_, METH_O, "make_mat4x2(ctypes.c_void_p) -> mat4x2\nBuild a matrix from a pointer." },
	{ "make_mat4x3", (PyCFunction)make_mat4x3_, METH_O, "make_mat4x3(ctypes.c_void_p) -> mat4x3\nBuild a matrix from a pointer." },
	{ "make_mat4", (PyCFunction)make_mat4x4_, METH_O, "make_mat4(ctypes.c_void_p) -> mat4x4\nBuild a matrix from a pointer." },
	{ "make_mat4x4", (PyCFunction)make_mat4x4_, METH_O, "make_mat4x4(ctypes.c_void_p) -> mat4x4\nBuild a matrix from a pointer." },
	{ "make_quat", (PyCFunction)make_quat_, METH_O, "make_quat(ctypes.c_void_p) -> quat\nBuild a quaternion from a pointer." },
#ifdef HAS_TEST
	{"test", (PyCFunction)test, TEST_FUNC_TYPE, ""},
#endif
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef glmmodule = {
	PyModuleDef_HEAD_INIT,
	"glm",
	"Features that implement in Python the GLSL specification as closely as necessary.",
	-1,
	glmmethods, NULL, NULL, NULL, NULL
};

extern "C" {
	PyMODINIT_FUNC
		PyInit_glm(void)
	{
		PyObject* mainmod = PyImport_AddModule("__main__");
		PyObject* maindict = PyModule_GetDict(mainmod);

		PyObject* c_void_p_str = Py_BuildValue("(s)", "c_void_p");

		c_void_p = PyObject_GetAttr(PyImport_ImportModuleEx("ctypes", maindict, maindict, c_void_p_str), PyUnicode_FromString("c_void_p"));

		Py_DECREF(c_void_p_str);

		PyObject* module_glm, *detail, *gtc;

		if (PyType_Ready(&vec2Type) < 0 || PyType_Ready(&vec2IterType) < 0
			|| PyType_Ready(&vec3Type) < 0 || PyType_Ready(&vec3IterType) < 0
			|| PyType_Ready(&vec4Type) < 0 || PyType_Ready(&vec4IterType) < 0
			|| PyType_Ready(&mvec2Type) < 0 || PyType_Ready(&mvec2IterType) < 0
			|| PyType_Ready(&mvec3Type) < 0 || PyType_Ready(&mvec3IterType) < 0
			|| PyType_Ready(&mvec4Type) < 0 || PyType_Ready(&mvec4IterType) < 0
			|| PyType_Ready(&mat2x2Type) < 0 || PyType_Ready(&mat2x2IterType) < 0
			|| PyType_Ready(&mat2x3Type) < 0 || PyType_Ready(&mat2x3IterType) < 0
			|| PyType_Ready(&mat2x4Type) < 0 || PyType_Ready(&mat2x4IterType) < 0
			|| PyType_Ready(&mat3x2Type) < 0 || PyType_Ready(&mat3x2IterType) < 0
			|| PyType_Ready(&mat3x3Type) < 0 || PyType_Ready(&mat3x3IterType) < 0
			|| PyType_Ready(&mat3x4Type) < 0 || PyType_Ready(&mat3x4IterType) < 0
			|| PyType_Ready(&mat4x2Type) < 0 || PyType_Ready(&mat4x2IterType) < 0
			|| PyType_Ready(&mat4x3Type) < 0 || PyType_Ready(&mat4x3IterType) < 0
			|| PyType_Ready(&mat4x4Type) < 0 || PyType_Ready(&mat4x4IterType) < 0
			|| PyType_Ready(&quatType) < 0 || PyType_Ready(&quatIterType) < 0)
			return NULL;

		module_glm = PyModule_Create(&glmmodule);
		if (module_glm == NULL)
			return NULL;

		// detail
		// namespace detail
		detail = PyModule_Create(&detailmodule);

		if (detail == NULL)
			return NULL;

		gtc = PyModule_Create(&gtcmodule);

		if (gtc == NULL)
			return NULL;

		// namespace glm
		Py_INCREF(detail);
		PyModule_AddObject(module_glm, "detail", detail);

		Py_INCREF(gtc);
		PyModule_AddObject(module_glm, "gtc", gtc);

		Py_INCREF(&vec2Type);
		PyModule_AddObject(module_glm, "vec2", (PyObject *)&vec2Type);

		Py_INCREF(&vec3Type);
		PyModule_AddObject(module_glm, "vec3", (PyObject *)&vec3Type);

		Py_INCREF(&vec4Type);
		PyModule_AddObject(module_glm, "vec4", (PyObject *)&vec4Type);

		Py_INCREF(&mat2x2Type);
		PyModule_AddObject(module_glm, "mat2x2", (PyObject *)&mat2x2Type);

		Py_INCREF(&mat2x3Type);
		PyModule_AddObject(module_glm, "mat2x3", (PyObject *)&mat2x3Type);

		Py_INCREF(&mat2x4Type);
		PyModule_AddObject(module_glm, "mat2x4", (PyObject *)&mat2x4Type);

		Py_INCREF(&mat3x2Type);
		PyModule_AddObject(module_glm, "mat3x2", (PyObject *)&mat3x2Type);

		Py_INCREF(&mat3x3Type);
		PyModule_AddObject(module_glm, "mat3x3", (PyObject *)&mat3x3Type);

		Py_INCREF(&mat3x4Type);
		PyModule_AddObject(module_glm, "mat3x4", (PyObject *)&mat3x4Type);

		Py_INCREF(&mat4x2Type);
		PyModule_AddObject(module_glm, "mat4x2", (PyObject *)&mat4x2Type);

		Py_INCREF(&mat4x3Type);
		PyModule_AddObject(module_glm, "mat4x3", (PyObject *)&mat4x3Type);

		Py_INCREF(&mat4x4Type);
		PyModule_AddObject(module_glm, "mat4x4", (PyObject *)&mat4x4Type);


		Py_INCREF(&mat2x2Type);
		PyModule_AddObject(module_glm, "mat2", (PyObject *)&mat2x2Type);

		Py_INCREF(&mat3x3Type);
		PyModule_AddObject(module_glm, "mat3", (PyObject *)&mat3x3Type);

		Py_INCREF(&mat4x4Type);
		PyModule_AddObject(module_glm, "mat4", (PyObject *)&mat4x4Type);

		Py_INCREF(&quatType);
		PyModule_AddObject(module_glm, "quat", (PyObject *)&quatType);

		Py_DECREF(gtc);
		Py_DECREF(detail);

		return module_glm;
	}
}