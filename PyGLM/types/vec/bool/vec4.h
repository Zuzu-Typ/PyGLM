#pragma once

#include "../forward_declarations.h"

static PyMemberDef hbvec4_members[] = {
	{ (char*)"x", T_BOOL, offsetof(UNBRACKET(vec<4, bool>), super_type.x), 0, (char*)"bvec4.x" },
	{ (char*)"y", T_BOOL, offsetof(UNBRACKET(vec<4, bool>), super_type.y), 0, (char*)"bvec4.y" },
	{ (char*)"z", T_BOOL, offsetof(UNBRACKET(vec<4, bool>), super_type.z), 0, (char*)"bvec4.z" },
	{ (char*)"w", T_BOOL, offsetof(UNBRACKET(vec<4, bool>), super_type.w), 0, (char*)"bvec4.w" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hbvec4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "to_list", (PyCFunction)vec4_to_list<bool>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec4_to_tuple<bool>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hbvec4BufferMethods = {
	(getbufferproc)vec_getbuffer<4, bool>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hbvec4SeqMethods = {
	(lenfunc)vec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec4_sq_item<bool>, // sq_item
	0,
	(ssizeobjargproc)vec4_sq_ass_item<bool>, // sq_ass_item
	0,
	(objobjproc)vec_contains<4, bool>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyTypeObject hbvec4Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.bvec4",             /* tp_name */
	sizeof(vec<4, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec4_repr<bool>,                         /* tp_repr */
	0,             /* tp_as_number */
	&hbvec4SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	(hashfunc)vec_hash<4, bool>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec4_str<bool>,                         /* tp_str */
	(getattrofunc)vec_getattr<4, bool>,                         /* tp_getattro */
	(setattrofunc)vec_setattr<4, bool>,                         /* tp_setattro */
	&hbvec4BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"bvec4( <vec4 compatible type(s)> )\n4 components vector of high qualifier boolean values.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec_richcompare<4, bool>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec_geniter<4, bool>,                         /* tp_iter */
	0,                         /* tp_iternext */
	hbvec4_methods,             /* tp_methods */
	hbvec4_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec4_init<bool>,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec_new<4, bool>,                 /* tp_new */
};
static PyTypeObject hbvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"bvec4Iter",             /* tp_name */
	sizeof(vecIter<4, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<4, bool>, /* tp_dealloc */
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
	"bvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec4Iter_next<bool>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<4, bool>,                 /* tp_new */
};