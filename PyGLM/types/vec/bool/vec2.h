#pragma once

#include "../forward_declarations.h"

static PyMemberDef hbvec2_members[] = {
	{ (char*)"x", T_BOOL, offsetof(UNBRACKET(vec<2, bool>), super_type.x), 0, (char*)"bvec2.x" },
	{ (char*)"y", T_BOOL, offsetof(UNBRACKET(vec<2, bool>), super_type.y), 0, (char*)"bvec2.y" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hbvec2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "to_list", (PyCFunction)vec2_to_list<bool>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec2_to_tuple<bool>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hbvec2BufferMethods = {
	(getbufferproc)vec_getbuffer<2, bool>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hbvec2SeqMethods = {
	(lenfunc)vec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec2_sq_item<bool>, // sq_item
	0,
	(ssizeobjargproc)vec2_sq_ass_item<bool>, // sq_ass_item
	0,
	(objobjproc)vec_contains<2, bool>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyTypeObject hbvec2Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.bvec2",             /* tp_name */
	sizeof(vec<2, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec2_repr<bool>,                         /* tp_repr */
	0,             /* tp_as_number */
	&hbvec2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	(hashfunc)vec_hash<2, bool>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec2_str<bool>,                         /* tp_str */
	(getattrofunc)vec_getattr<2, bool>,                         /* tp_getattro */
	(setattrofunc)vec_setattr<2, bool>,                         /* tp_setattro */
	&hbvec2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"bvec2( <vec2 compatible type(s)> )\n2 components vector of high qualifier boolean values.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec_richcompare<2, bool>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec_geniter<2, bool>,                         /* tp_iter */
	0,                         /* tp_iternext */
	hbvec2_methods,             /* tp_methods */
	hbvec2_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec2_init<bool>,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec_new<2, bool>,                 /* tp_new */
};
static PyTypeObject hbvec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"bvec2Iter",             /* tp_name */
	sizeof(vecIter<2, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<2, bool>, /* tp_dealloc */
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
	"bvec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec2Iter_next<bool>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<2, bool>,                 /* tp_new */
};