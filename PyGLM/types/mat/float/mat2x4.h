#pragma once

#include "../forward_declarations.h"

static PyMethodDef hfmat2x4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<2>, METH_NOARGS, "returns the length of glm::mat2x4"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<2, 4, float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<2, 4, float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<2, 4, float>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<2, 4, float>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<2, 4, float>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
static PyBufferProcs hfmat2x4BufferMethods = {
	(getbufferproc)mat_getbuffer<2, 4, float>,
	(releasebufferproc)mat_releasebuffer,
};
static PySequenceMethods hfmat2x4SeqMethods = {
	(lenfunc)mat_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<2, 4, float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyMappingMethods hfmat2x4MapMethods = {
	(lenfunc)mat_len<2>, // mp_length
	(binaryfunc)mat2x4_mp_item<float>, // mp_subscript
	(objobjargproc)mat2x4_mp_ass_item<float>, // mp_ass_subscript
};
static PyNumberMethods hfmat2x4NumMethods = {
	(binaryfunc)mat_add<2, 4, float>, //nb_add
	(binaryfunc)mat_sub<2, 4, float>, //nb_subtract
	(binaryfunc)mat_mul<2, 4, float>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat_neg<2, 4, float>, //nb_negative
	(unaryfunc)mat_pos<2, 4, float>, //nb_positive
	0, //nb_absolute
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
	(binaryfunc)mat_iadd<2, 4, float>, //nb_inplace_add
	(binaryfunc)mat_isub<2, 4, float>, //nb_inplace_subtract
	(binaryfunc)mat_imul<2, 4, float>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mat_div<2, 4, float>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat_idiv<2, 4, float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<2, 4, float>, //nb_inplace_matrix_multiply
};
static PyTypeObject hfmat2x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat2x4Iter",             /* tp_name */
	sizeof(matIter<2, 4, float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<2, 4, float>, /* tp_dealloc */
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
	"mat2x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)matIter_next<2, 4, float>,                         /* tp_iternext */
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
	(newfunc)matIter_new<2, 4, float>,                 /* tp_new */
};

static PyGLMTypeObject hfmat2x4GLMType = {
	{
		PyObject_HEAD_INIT(NULL)
		"glm.mat2x4",             /* tp_name */
		sizeof(mat<2, 4, float>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mat_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mat2x4_repr<float>,                         /* tp_repr */
		& hfmat2x4NumMethods,             /* tp_as_number */
		& hfmat2x4SeqMethods,                         /* tp_as_sequence */
		& hfmat2x4MapMethods,                         /* tp_as_mapping */
		(hashfunc)mat_hash<2, 4, float>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mat2x4_str<float>,                         /* tp_str */
		0,                         /* tp_getattro */
		0,                         /* tp_setattro */
		& hfmat2x4BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"mat2x4( <mat2x4 compatible type(s)> )\n2 columns of 4 components matrix of floating-point numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mat_richcompare<2, 4, float>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mat_geniter<2, 4, float>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hfmat2x4_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mat2x4_init<float>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mat_new<2, 4, float>,                 /* tp_new */
	},
	PyGLM_TYPE_MAT,
	2,
	4,
	sizeof(float),
	sizeof(glm::mat<2, 4, float>),
	PyGLM_FS_FLOAT
};

static PyTypeObject& hfmat2x4Type = *((PyTypeObject*)&hfmat2x4GLMType);