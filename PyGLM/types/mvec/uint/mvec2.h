#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

static PyMethodDef humvec2_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<2, glm::u32>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<2, glm::u32>, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)mvec2_to_tuple<glm::u32>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mvec2_setstate<glm::u32>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mvec2_to_list<glm::u32>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)mvec2_to_tuple<glm::u32>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs humvec2BufferMethods = {
	(getbufferproc)mvec_getbuffer<2, glm::u32>,
	(releasebufferproc)mvec_releasebuffer,
};
static PySequenceMethods humvec2SeqMethods = {
	(lenfunc)mvec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec2_sq_item<glm::u32>, // sq_item
	0,
	(ssizeobjargproc)mvec2_sq_ass_item<glm::u32>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<2, glm::u32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods humvec2NumMethods = {
	(binaryfunc)mvec_add<2, glm::u32>, //nb_add
	(binaryfunc)mvec_sub<2, glm::u32>, //nb_subtract
	(binaryfunc)mvec_mul<2, glm::u32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	0, //nb_negative
	(unaryfunc)mvec_pos<2, glm::u32>, //nb_positive
	(unaryfunc)mvec_abs<2, glm::u32>, //nb_absolute
	0, //nb_bool
	(unaryfunc)mvec_invert<2, glm::u32>, //nb_invert
	(binaryfunc)mvec_lshift<2, glm::u32>, //nb_lshift
	(binaryfunc)mvec_rshift<2, glm::u32>, //nb_rshift
	(binaryfunc)mvec_and<2, glm::u32>, //nb_and
	(binaryfunc)mvec_xor<2, glm::u32>, //nb_xor
	(binaryfunc)mvec_or<2, glm::u32>, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)mvec_iadd<2, glm::u32>, //nb_inplace_add
	(binaryfunc)mvec_isub<2, glm::u32>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<2, glm::u32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	(binaryfunc)mvec_ilshift<2, glm::u32>, //nb_inplace_lshift
	(binaryfunc)mvec_irshift<2, glm::u32>, //nb_inplace_rshift
	(binaryfunc)mvec_iand<2, glm::u32>, //nb_inplace_and
	(binaryfunc)mvec_ixor<2, glm::u32>, //nb_inplace_xor
	(binaryfunc)mvec_ior<2, glm::u32>, //nb_inplace_or
	(binaryfunc)mvec_div<2, glm::u32>, //nb_floor_divide
	(binaryfunc)mvec_div<2, glm::u32>,
	(binaryfunc)mvec_idiv<2, glm::u32>, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<2, glm::u32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mvec_matmul, //nb_matrix_multiply
	(binaryfunc)mvec_imatmul<2, glm::u32>, //nb_inplace_matrix_multiply
};
static PyTypeObject humvec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"umvec2Iter",             /* tp_name */
	sizeof(mvecIter<2, glm::u32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<2, glm::u32>, /* tp_dealloc */
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
	"umvec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)mvec2Iter_next<glm::u32>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<2, glm::u32>,                 /* tp_new */
};

static PyGLMTypeObject humvec2GLMType = {
	{
		PyObject_HEAD_INIT(NULL)
		"glm.umvec2",             /* tp_name */
		sizeof(mvec<2, glm::u32>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mvec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mvec2_str<glm::u32>,                         /* tp_repr */
		& humvec2NumMethods,             /* tp_as_number */
		& humvec2SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)mvec_hash<2, glm::u32>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mvec2_str<glm::u32>,                         /* tp_str */
		(getattrofunc)mvec_getattr<2, glm::u32>,                         /* tp_getattro */
		(setattrofunc)mvec_setattr<2, glm::u32>,                         /* tp_setattro */
		& humvec2BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"umvec2( <mvec2 compatible type(s)> )\n2 components mvector of high qualifier unsigned integer numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mvec_richcompare<2, glm::u32>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mvec_geniter<2, glm::u32>,                         /* tp_iter */
		0,                         /* tp_iternext */
		humvec2_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mvec_init<2, glm::u32>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mvec_new<2, glm::u32>,                 /* tp_new */
	},
	PyGLM_TYPE_MVEC,
	2,
	0,
	sizeof(uint32),
	sizeof(glm::vec<2, uint32>),
	PyGLM_FS_UINT32,
	&huvec2Type
};

static PyTypeObject& humvec2Type = *((PyTypeObject*)&humvec2GLMType);