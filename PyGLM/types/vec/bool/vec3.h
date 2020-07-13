#pragma once

#include "../forward_declarations.h"

static PyMemberDef hbvec3_members[] = {
	{ (char*)"x", T_BOOL, offsetof(UNBRACKET(vec<3, bool>), super_type.x), 0, (char*)"bvec3.x" },
	{ (char*)"y", T_BOOL, offsetof(UNBRACKET(vec<3, bool>), super_type.y), 0, (char*)"bvec3.y" },
	{ (char*)"z", T_BOOL, offsetof(UNBRACKET(vec<3, bool>), super_type.z), 0, (char*)"bvec3.z" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hbvec3_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "to_list", (PyCFunction)vec3_to_list<bool>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec3_to_tuple<bool>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hbvec3BufferMethods = {
	(getbufferproc)vec_getbuffer<3, bool>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hbvec3SeqMethods = {
	(lenfunc)vec_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec3_sq_item<bool>, // sq_item
	0,
	(ssizeobjargproc)vec3_sq_ass_item<bool>, // sq_ass_item
	0,
	(objobjproc)vec_contains<3, bool>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyTypeObject hbvec3Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.bvec3",             /* tp_name */
	sizeof(vec<3, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec3_repr<bool>,                         /* tp_repr */
	0,             /* tp_as_number */
	&hbvec3SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	(hashfunc)vec_hash<3, bool>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec3_str<bool>,                         /* tp_str */
	(getattrofunc)vec_getattr<3, bool>,                         /* tp_getattro */
	(setattrofunc)vec_setattr<3, bool>,                         /* tp_setattro */
	&hbvec3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"bvec3( <vec3 compatible type(s)> )\n3 components vector of high qualifier boolean values.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec_richcompare<3, bool>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec_geniter<3, bool>,                         /* tp_iter */
	0,                         /* tp_iternext */
	hbvec3_methods,             /* tp_methods */
	hbvec3_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec3_init<bool>,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec_new<3, bool>,                 /* tp_new */
};
static PyTypeObject hbvec3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"bvec3Iter",             /* tp_name */
	sizeof(vecIter<3, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<3, bool>, /* tp_dealloc */
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
	"bvec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec3Iter_next<bool>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<3, bool>,                 /* tp_new */
};