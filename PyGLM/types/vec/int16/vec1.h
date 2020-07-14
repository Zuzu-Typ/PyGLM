#pragma once

#include "../forward_declarations.h"

static PyMemberDef hi16vec1_members[] = {
	{ (char*)"x", T_SHORT, offsetof(UNBRACKET(vec<1, glm::i16>), super_type.x), 0, (char*)"i16vec1.x" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hi16vec1_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "to_list", (PyCFunction)vec1_to_list<glm::i16>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec1_to_tuple<glm::i16>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hi16vec1BufferMethods = {
	(getbufferproc)vec_getbuffer<1, glm::i16>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hi16vec1SeqMethods = {
	(lenfunc)vec_len<1>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec1_sq_item<glm::i16>, // sq_item
	0,
	(ssizeobjargproc)vec1_sq_ass_item<glm::i16>, // sq_ass_item
	0,
	(objobjproc)vec_contains<1, glm::i16>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hi16vec1NumMethods = {
	(binaryfunc)vec_add<1, glm::i16>, //nb_add
	(binaryfunc)vec_sub<1, glm::i16>, //nb_subtract
	(binaryfunc)vec_mul<1, glm::i16>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)vec_neg<1, glm::i16>, //nb_negative
	(unaryfunc)vec_pos<1, glm::i16>, //nb_positive
	(unaryfunc)vec_abs<1, glm::i16>, //nb_absolute
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
	(binaryfunc)vec_iadd<1, glm::i16>, //nb_inplace_add
	(binaryfunc)vec_isub<1, glm::i16>, //nb_inplace_subtract
	(binaryfunc)vec_imul<1, glm::i16>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)vec_div<1, glm::i16>,
	0, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<1, glm::i16>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<1, glm::i16>, //nb_inplace_matrix_multiply
};
static PyTypeObject hi16vec1Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.i16vec1",             /* tp_name */
	sizeof(vec<1, glm::i16>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)vec1_repr<glm::i16>,                         /* tp_repr */
	&hi16vec1NumMethods,             /* tp_as_number */
	&hi16vec1SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	(hashfunc)vec_hash<1, glm::i16>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)vec1_str<glm::i16>,                         /* tp_str */
	(getattrofunc)vec_getattr<1, glm::i16>,                         /* tp_getattro */
	(setattrofunc)vec_setattr<1, glm::i16>,                         /* tp_setattro */
	&hi16vec1BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"i16vec1( <vec1 compatible type(s)> )\n1 component vector of high qualifier 16 bit integer numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)vec_richcompare<1, glm::i16>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)vec_geniter<1, glm::i16>,                         /* tp_iter */
	0,                         /* tp_iternext */
	hi16vec1_methods,             /* tp_methods */
	hi16vec1_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)vec1_init<glm::i16>,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)vec_new<1, glm::i16>,                 /* tp_new */
};
static PyTypeObject hi16vec1IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"i16vec1Iter",             /* tp_name */
	sizeof(vecIter<1, glm::i16>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<1, glm::i16>, /* tp_dealloc */
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
	"i16vec1 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)vec1Iter_next<glm::i16>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<1, glm::i16>,                 /* tp_new */
};