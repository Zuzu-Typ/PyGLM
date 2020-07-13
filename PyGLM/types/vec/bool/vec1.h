#pragma once

#include "../forward_declarations.h"

static PyMemberDef hbvec1_members[] = {
	{ (char*)"x", T_BOOL, offsetof(UNBRACKET(vec<1, bool>), super_type.x), 0, (char*)"bvec1.x" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hbvec1_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "to_list", (PyCFunction)vec1_to_list<bool>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec1_to_tuple<bool>, METH_NOARGS, "Return the components of this vector as a tuple"},
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
static PyTypeObject hbvec1Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.bvec1",             /* tp_name */
	sizeof(vec<1, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec1_repr<bool>,                         /* tp_repr */
	0,             /* tp_as_number */
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
	0,                         /* tp_iter */
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