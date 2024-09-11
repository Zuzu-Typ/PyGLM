#pragma once

#include "../forward_declarations.h"

typedef vec<1, bool> vec1_bool_t;

static PyMemberDef hbvec1_members[] = {
	{ (char*)"x", T_BOOL, offsetof(vec1_bool_t, super_type.x), 0, (char*)"bvec1.x" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hbvec1_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec1_to_tuple<bool>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec1_setstate<bool>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec1_to_list<bool>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec1_to_tuple<bool>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<1, bool>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hbvec1BufferMethods = {
	(getbufferproc)vec_getbuffer<1, bool>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hbvec1SeqMethods = {
	(lenfunc)vec_len<1>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec1_sq_item<bool>, // sq_item
	0,
	(ssizeobjargproc)vec1_sq_ass_item<bool>, // sq_ass_item
	0,
	(objobjproc)vec_contains<1, bool>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hbvec1NumMethods = {
	(binaryfunc)bvec_add<1>, //nb_add
	0, //nb_subtract
	(binaryfunc)bvec_mul<1>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)bvec_neg<1>, //nb_negative
	0, //nb_positive
	0, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	vec_and<1, bool>, //nb_and
	vec_xor<1, bool>, //nb_xor
	vec_or<1, bool>, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)bvec_iadd<1>, //nb_inplace_add
	0, //nb_inplace_subtract
	(binaryfunc)bvec_imul<1>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	0,
	0, //nb_inplace_floor_divide
	0, //nb_inplace_true_divide
	0, //nb_index
	0, //nb_matrix_multiply
	0, //nb_inplace_matrix_multiply
};
static PyTypeObject hbvec1IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"bvec1Iter",             /* tp_name */
	sizeof(vecIter<1, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<1, bool>, /* tp_dealloc */
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
	"bvec1 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec1Iter_next<bool>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<1, bool>,                 /* tp_new */
};

static PyGLMTypeObject hbvec1GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.bvec1",             /* tp_name */
		sizeof(vec<1, bool>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)vec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)vec1_repr<bool>,                         /* tp_repr */
		&hbvec1NumMethods,             /* tp_as_number */
		&hbvec1SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)vec_hash<1, bool>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)vec1_str<bool>,                         /* tp_str */
		(getattrofunc)vec_getattr<1, bool>,                         /* tp_getattro */
		(setattrofunc)vec_setattr<1, bool>,                         /* tp_setattro */
		&hbvec1BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"bvec1( <vec1 compatible type(s)> )\n1 component vector of high qualifier boolean values.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)vec_richcompare<1, bool>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)vec_geniter<1, bool>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hbvec1_methods,             /* tp_methods */
		hbvec1_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)vec1_init<bool>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)vec_new<1, bool>,                 /* tp_new */
	},
	PyGLM_TYPE_VEC,
	1,
	0,
	sizeof(bool),
	sizeof(glm::vec<1, bool>),
	PyGLM_FS_BOOL
};

static PyTypeObject& hbvec1Type = *((PyTypeObject*)&hbvec1GLMType);