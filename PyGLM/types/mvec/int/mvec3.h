#pragma once

#include "../forward_declarations.h"

static PyMethodDef himvec3_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<3, glm::i32>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<3, glm::i32>, METH_O, "Create a (deep)copy of this instance"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs himvec3BufferMethods = {
	(getbufferproc)mvec_getbuffer<3, glm::i32>,
	(releasebufferproc)mvec_releasebuffer,
};
static PySequenceMethods himvec3SeqMethods = {
	(lenfunc)mvec_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec3_sq_item<glm::i32>, // sq_item
	0,
	(ssizeobjargproc)mvec3_sq_ass_item<glm::i32>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<3, glm::i32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods himvec3NumMethods = {
	(binaryfunc)mvec_add<3, glm::i32>, //nb_add
	(binaryfunc)mvec_sub<3, glm::i32>, //nb_subtract
	(binaryfunc)mvec_mul<3, glm::i32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mvec_neg<3, glm::i32>, //nb_negative
	(unaryfunc)mvec_pos<3, glm::i32>, //nb_positive
	(unaryfunc)mvec_abs<3, glm::i32>, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)mvec_iadd<3, glm::i32>, //nb_inplace_add
	(binaryfunc)mvec_isub<3, glm::i32>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<3, glm::i32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mvec_div<3, glm::i32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<3, glm::i32>, //nb_inplace_true_divide
	0, //nb_index
};
static PyTypeObject himvec3Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.imvec3",             /* tp_name */
	sizeof(mvec<3, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mvec3_str<glm::i32>,                         /* tp_repr */
	&himvec3NumMethods,             /* tp_as_number */
	&himvec3SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	(hashfunc)mvec_hash<3, glm::i32>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mvec3_str<glm::i32>,                         /* tp_str */
	(getattrofunc)mvec_getattr<3, glm::i32>,                         /* tp_getattro */
	(setattrofunc)mvec_setattr<3, glm::i32>,                         /* tp_setattro */
	&himvec3BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"imvec3( <mvec3 compatible type(s)> )\n3 components mvector of high qualifier integer numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mvec_richcompare<3, glm::i32>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mvec_geniter<3, glm::i32>,                         /* tp_iter */
	0,                         /* tp_iternext */
	himvec3_methods,             /* tp_methods */
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
static PyTypeObject himvec3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"imvec3Iter",             /* tp_name */
	sizeof(mvecIter<3, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<3, glm::i32>, /* tp_dealloc */
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
	"imvec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mvec3Iter_next<glm::i32>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<3, glm::i32>,                 /* tp_new */
};