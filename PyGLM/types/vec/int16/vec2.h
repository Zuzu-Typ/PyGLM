#pragma once

#include "../forward_declarations.h"

static PyMemberDef hi16vec2_members[] = {
	{ (char*)"x", T_SHORT, offsetof(UNBRACKET(vec<2, glm::i16>), super_type.x), 0, (char*)"i16vec2.x" },
	{ (char*)"y", T_SHORT, offsetof(UNBRACKET(vec<2, glm::i16>), super_type.y), 0, (char*)"i16vec2.y" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hi16vec2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "to_list", (PyCFunction)vec2_to_list<glm::i16>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec2_to_tuple<glm::i16>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hi16vec2BufferMethods = {
	(getbufferproc)vec_getbuffer<2, glm::i16>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hi16vec2SeqMethods = {
	(lenfunc)vec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec2_sq_item<glm::i16>, // sq_item
	0,
	(ssizeobjargproc)vec2_sq_ass_item<glm::i16>, // sq_ass_item
	0,
	(objobjproc)vec_contains<2, glm::i16>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hi16vec2NumMethods = {
	(binaryfunc)vec_add<2, glm::i16>, //nb_add
	(binaryfunc)vec_sub<2, glm::i16>, //nb_subtract
	(binaryfunc)vec_mul<2, glm::i16>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)vec_neg<2, glm::i16>, //nb_negative
	(unaryfunc)vec_pos<2, glm::i16>, //nb_positive
	(unaryfunc)vec_abs<2, glm::i16>, //nb_absolute
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
	(binaryfunc)vec_iadd<2, glm::i16>, //nb_inplace_add
	(binaryfunc)vec_isub<2, glm::i16>, //nb_inplace_subtract
	(binaryfunc)vec_imul<2, glm::i16>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)vec_div<2, glm::i16>,
	0, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<2, glm::i16>, //nb_inplace_true_divide
	0, //nb_index
};
static PyTypeObject hi16vec2Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.i16vec2",             /* tp_name */
	sizeof(vec<2, glm::i16>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec2_repr<glm::i16>,                         /* tp_repr */
	&hi16vec2NumMethods,             /* tp_as_number */
	&hi16vec2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec2_str<glm::i16>,                         /* tp_str */
	(getattrofunc)vec_getattr<2, glm::i16>,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&hi16vec2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"i16vec2( <vec2 compatible type(s)> )\n2 components vector of high qualifier 16 bit integer numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec_richcompare<2, glm::i16>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec_geniter<2, glm::i16>,                         /* tp_iter */
	0,                         /* tp_iternext */
	hi16vec2_methods,             /* tp_methods */
	hi16vec2_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec2_init<glm::i16>,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec_new<2, glm::i16>,                 /* tp_new */
};
static PyTypeObject hi16vec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"i16vec2Iter",             /* tp_name */
	sizeof(vecIter<2, glm::i16>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<2, glm::i16>, /* tp_dealloc */
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
	"i16vec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec2Iter_next<glm::i16>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<2, glm::i16>,                 /* tp_new */
};