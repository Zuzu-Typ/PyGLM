#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

static PyMethodDef hdmvec2_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<2, double>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<2, double>, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)mvec2_to_tuple<double>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mvec2_setstate<double>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mvec2_to_list<double>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)mvec2_to_tuple<double>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hdmvec2BufferMethods = {
	(getbufferproc)mvec_getbuffer<2, double>,
	(releasebufferproc)mvec_releasebuffer,
};
static PySequenceMethods hdmvec2SeqMethods = {
	(lenfunc)mvec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec2_sq_item<double>, // sq_item
	0,
	(ssizeobjargproc)mvec2_sq_ass_item<double>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<2, double>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hdmvec2NumMethods = {
	(binaryfunc)mvec_add<2, double>, //nb_add
	(binaryfunc)mvec_sub<2, double>, //nb_subtract
	(binaryfunc)mvec_mul<2, double>, //nb_multiply
	(binaryfunc)mvec_mod<2, double>, //nb_remainder
	(binaryfunc)mvec_divmod<2, double>, //nb_divmod
	(ternaryfunc)mvec_pow<2, double>, //nb_power
	(unaryfunc)mvec_neg<2, double>, //nb_negative
	(unaryfunc)mvec_pos<2, double>, //nb_positive
	(unaryfunc)mvec_abs<2, double>, //nb_absolute
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
	(binaryfunc)mvec_iadd<2, double>, //nb_inplace_add
	(binaryfunc)mvec_isub<2, double>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<2, double>, //nb_inplace_multiply
	(binaryfunc)mvec_imod<2, double>, //nb_inplace_remainder
	(ternaryfunc)mvec_ipow<2, double>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)mvec_floordiv<2, double>, //nb_floor_divide
	(binaryfunc)mvec_div<2, double>,
	(binaryfunc)mvec_ifloordiv<2, double>, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<2, double>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mvec_matmul, //nb_matrix_multiply
	(binaryfunc)mvec_imatmul<2, double>, //nb_inplace_matrix_multiply
};
static PyTypeObject hdmvec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"dmvec2Iter",             /* tp_name */
	sizeof(mvecIter<2, double>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<2, double>, /* tp_dealloc */
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
	"dmvec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)mvec2Iter_next<double>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<2, double>,                 /* tp_new */
};

static PyGLMTypeObject hdmvec2GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.dmvec2",             /* tp_name */
		sizeof(mvec<2, double>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mvec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mvec2_str<double>,                         /* tp_repr */
		& hdmvec2NumMethods,             /* tp_as_number */
		& hdmvec2SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)mvec_hash<2, double>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mvec2_str<double>,                         /* tp_str */
		(getattrofunc)mvec_getattr<2, double>,                         /* tp_getattro */
		(setattrofunc)mvec_setattr<2, double>,                         /* tp_setattro */
		& hdmvec2BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"dmvec2( <mvec2 compatible type(s)> )\n2 components mvector of high qualifier double numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mvec_richcompare<2, double>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mvec_geniter<2, double>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hdmvec2_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mvec_init<2, double>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mvec_new<2, double>,                 /* tp_new */
	},
	PyGLM_TYPE_MVEC,
	2,
	0,
	sizeof(double),
	sizeof(glm::vec<2, double>),
	PyGLM_FS_DOUBLE,
	&hdvec2Type
};

static PyTypeObject& hdmvec2Type = *((PyTypeObject*)&hdmvec2GLMType);