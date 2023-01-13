#pragma once

#include "../forward_declarations.h"

typedef vec<4, double> vec4_double_t;

static PyMemberDef hdvec4_members[] = {
	{ (char*)"x", T_DOUBLE, offsetof(vec4_double_t, super_type.x), 0, (char*)"dvec4.x" },
	{ (char*)"y", T_DOUBLE, offsetof(vec4_double_t, super_type.y), 0, (char*)"dvec4.y" },
	{ (char*)"z", T_DOUBLE, offsetof(vec4_double_t, super_type.z), 0, (char*)"dvec4.z" },
	{ (char*)"w", T_DOUBLE, offsetof(vec4_double_t, super_type.w), 0, (char*)"dvec4.w" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hdvec4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec4_to_tuple<double>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec4_setstate<double>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec4_to_list<double>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec4_to_tuple<double>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<4, double>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hdvec4BufferMethods = {
	(getbufferproc)vec_getbuffer<4, double>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hdvec4SeqMethods = {
	(lenfunc)vec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec4_sq_item<double>, // sq_item
	0,
	(ssizeobjargproc)vec4_sq_ass_item<double>, // sq_ass_item
	0,
	(objobjproc)vec_contains<4, double>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hdvec4NumMethods = {
	(binaryfunc)vec_add<4, double>, //nb_add
	(binaryfunc)vec_sub<4, double>, //nb_subtract
	(binaryfunc)vec_mul<4, double>, //nb_multiply
	(binaryfunc)vec_mod<4, double>, //nb_remainder
	(binaryfunc)vec_divmod<4, double>, //nb_divmod
	(ternaryfunc)vec_pow<4, double>, //nb_power
	(unaryfunc)vec_neg<4, double>, //nb_negative
	(unaryfunc)vec_pos<4, double>, //nb_positive
	(unaryfunc)vec_abs<4, double>, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_double
	(binaryfunc)vec_iadd<4, double>, //nb_inplace_add
	(binaryfunc)vec_isub<4, double>, //nb_inplace_subtract
	(binaryfunc)vec_imul<4, double>, //nb_inplace_multiply
	(binaryfunc)vec_imod<4, double>, //nb_inplace_remainder
	(ternaryfunc)vec_ipow<4, double>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)vec_floordiv<4, double>, //nb_floor_divide
	(binaryfunc)vec_div<4, double>,
	(binaryfunc)vec_ifloordiv<4, double>, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<4, double>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<4, double>, //nb_inplace_matrix_multiply
};
static PyTypeObject hdvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"dvec4Iter",             /* tp_name */
	sizeof(vecIter<4, double>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<4, double>, /* tp_dealloc */
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
	"dvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec4Iter_next<double>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<4, double>,                 /* tp_new */
};

static PyGLMTypeObject hdvec4GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.dvec4",             /* tp_name */
		sizeof(vec<4, double>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)vec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)vec4_repr<double>,                         /* tp_repr */
		& hdvec4NumMethods,             /* tp_as_number */
		& hdvec4SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)vec_hash<4, double>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)vec4_str<double>,                         /* tp_str */
		(getattrofunc)vec_getattr<4, double>,                         /* tp_getattro */
		(setattrofunc)vec_setattr<4, double>,                         /* tp_setattro */
		& hdvec4BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"dvec4( <vec4 compatible type(s)> )\n4 components vector of high qualifier double numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)vec_richcompare<4, double>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)vec_geniter<4, double>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hdvec4_methods,             /* tp_methods */
		hdvec4_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)vec4_init<double>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)vec_new<4, double>,                 /* tp_new */
	},
	PyGLM_TYPE_VEC,
	4,
	0,
	sizeof(double),
	sizeof(glm::vec<4, double>),
	PyGLM_FS_DOUBLE
};

static PyTypeObject& hdvec4Type = *((PyTypeObject*)&hdvec4GLMType);