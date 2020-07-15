#pragma once

#include "../forward_declarations.h"

static PyMethodDef himvec2_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<2, glm::i32>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<2, glm::i32>, METH_O, "Create a (deep)copy of this instance"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs himvec2BufferMethods = {
	(getbufferproc)mvec_getbuffer<2, glm::i32>,
	(releasebufferproc)mvec_releasebuffer,
};
static PySequenceMethods himvec2SeqMethods = {
	(lenfunc)mvec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec2_sq_item<glm::i32>, // sq_item
	0,
	(ssizeobjargproc)mvec2_sq_ass_item<glm::i32>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<2, glm::i32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods himvec2NumMethods = {
	(binaryfunc)mvec_add<2, glm::i32>, //nb_add
	(binaryfunc)mvec_sub<2, glm::i32>, //nb_subtract
	(binaryfunc)mvec_mul<2, glm::i32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mvec_neg<2, glm::i32>, //nb_negative
	(unaryfunc)mvec_pos<2, glm::i32>, //nb_positive
	(unaryfunc)mvec_abs<2, glm::i32>, //nb_absolute
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
	(binaryfunc)mvec_iadd<2, glm::i32>, //nb_inplace_add
	(binaryfunc)mvec_isub<2, glm::i32>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<2, glm::i32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mvec_div<2, glm::i32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<2, glm::i32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mvec_matmul, //nb_matrix_multiply
	(binaryfunc)mvec_imatmul<2, glm::i32>, //nb_inplace_matrix_multiply
};
static PyTypeObject himvec2Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.imvec2",             /* tp_name */
	sizeof(mvec<2, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvec_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mvec2_str<glm::i32>,                         /* tp_repr */
	&himvec2NumMethods,             /* tp_as_number */
	&himvec2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	(hashfunc)mvec_hash<2, glm::i32>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mvec2_str<glm::i32>,                         /* tp_str */
	(getattrofunc)mvec_getattr<2, glm::i32>,                         /* tp_getattro */
	(setattrofunc)mvec_setattr<2, glm::i32>,                         /* tp_setattro */
	&himvec2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"imvec2( <mvec2 compatible type(s)> )\n2 components mvector of high qualifier integer numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mvec_richcompare<2, glm::i32>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mvec_geniter<2, glm::i32>,                         /* tp_iter */
	0,                         /* tp_iternext */
	himvec2_methods,             /* tp_methods */
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
static PyTypeObject himvec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"imvec2Iter",             /* tp_name */
	sizeof(mvecIter<2, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<2, glm::i32>, /* tp_dealloc */
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
	"imvec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)mvec2Iter_next<glm::i32>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<2, glm::i32>,                 /* tp_new */
};