#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

static PyMethodDef hfmvec4_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<4, float>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<4, float>, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)mvec4_to_tuple<float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mvec4_setstate<float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mvec4_to_list<float>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)mvec4_to_tuple<float>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hfmvec4BufferMethods = {
	(getbufferproc)mvec_getbuffer<4, float>,
	(releasebufferproc)mvec_releasebuffer,
};
static PySequenceMethods hfmvec4SeqMethods = {
	(lenfunc)mvec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec4_sq_item<float>, // sq_item
	0,
	(ssizeobjargproc)mvec4_sq_ass_item<float>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<4, float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hfmvec4NumMethods = {
	(binaryfunc)mvec_add<4, float>, //nb_add
	(binaryfunc)mvec_sub<4, float>, //nb_subtract
	(binaryfunc)mvec_mul<4, float>, //nb_multiply
	(binaryfunc)mvec_mod<4, float>, //nb_remainder
	(binaryfunc)mvec_divmod<4, float>, //nb_divmod
	(ternaryfunc)mvec_pow<4, float>, //nb_power
	(unaryfunc)mvec_neg<4, float>, //nb_negative
	(unaryfunc)mvec_pos<4, float>, //nb_positive
	(unaryfunc)mvec_abs<4, float>, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float
	(binaryfunc)mvec_iadd<4, float>, //nb_inplace_add
	(binaryfunc)mvec_isub<4, float>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<4, float>, //nb_inplace_multiply
	(binaryfunc)mvec_imod<4, float>, //nb_inplace_remainder
	(ternaryfunc)mvec_ipow<4, float>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)mvec_floordiv<4, float>, //nb_floor_divide
	(binaryfunc)mvec_div<4, float>,
	(binaryfunc)mvec_ifloordiv<4, float>, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<4, float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mvec_matmul, //nb_matrix_multiply
	(binaryfunc)mvec_imatmul<4, float>, //nb_inplace_matrix_multiply
};
static PyTypeObject hfmvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mvec4Iter",             /* tp_name */
	sizeof(mvecIter<4, float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<4, float>, /* tp_dealloc */
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
	"mvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)mvec4Iter_next<float>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<4, float>,                 /* tp_new */
};

static PyGLMTypeObject hfmvec4GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.mvec4",             /* tp_name */
		sizeof(mvec<4, float>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mvec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mvec4_str<float>,                         /* tp_repr */
		& hfmvec4NumMethods,             /* tp_as_number */
		& hfmvec4SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)mvec_hash<4, float>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mvec4_str<float>,                         /* tp_str */
		(getattrofunc)mvec_getattr<4, float>,                         /* tp_getattro */
		(setattrofunc)mvec_setattr<4, float>,                         /* tp_setattro */
		& hfmvec4BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"mvec4( <mvec4 compatible type(s)> )\n4 components mvector of high qualifier float numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mvec_richcompare<4, float>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mvec_geniter<4, float>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hfmvec4_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mvec_init<4, float>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mvec_new<4, float>,                 /* tp_new */
	},
	PyGLM_TYPE_MVEC,
	4,
	0,
	sizeof(float),
	sizeof(glm::vec<4, float>),
	PyGLM_FS_FLOAT,
	&hfvec4Type
};

static PyTypeObject& hfmvec4Type = *((PyTypeObject*)&hfmvec4GLMType);