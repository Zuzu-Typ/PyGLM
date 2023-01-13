#pragma once

#include "../forward_declarations.h"

static PyMethodDef hdmat3x4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<3>, METH_NOARGS, "returns the length of glm::dmat3x4"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<3, 4, double>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<3, 4, double>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<3, 4, double>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<3, 4, double>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<3, 4, double>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
static PyBufferProcs hdmat3x4BufferMethods = {
	(getbufferproc)mat_getbuffer<3, 4, double>,
	(releasebufferproc)mat_releasebuffer,
};
static PySequenceMethods hdmat3x4SeqMethods = {
	(lenfunc)mat_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<3, 4, double>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyMappingMethods hdmat3x4MapMethods = {
	(lenfunc)mat_len<3>, // mp_length
	(binaryfunc)mat3x4_mp_item<double>, // mp_subscript
	(objobjargproc)mat3x4_mp_ass_item<double>, // mp_ass_subscript
};
static PyNumberMethods hdmat3x4NumMethods = {
	(binaryfunc)mat_add<3, 4, double>, //nb_add
	(binaryfunc)mat_sub<3, 4, double>, //nb_subtract
	(binaryfunc)mat_mul<3, 4, double>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat_neg<3, 4, double>, //nb_negative
	(unaryfunc)mat_pos<3, 4, double>, //nb_positive
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
	0, //nb_double
	(binaryfunc)mat_iadd<3, 4, double>, //nb_inplace_add
	(binaryfunc)mat_isub<3, 4, double>, //nb_inplace_subtract
	(binaryfunc)mat_imul<3, 4, double>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mat_div<3, 4, double>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat_idiv<3, 4, double>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<3, 4, double>, //nb_inplace_matrix_multiply
};
static PyTypeObject hdmat3x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"dmat3x4Iter",             /* tp_name */
	sizeof(matIter<3, 4, double>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<3, 4, double>, /* tp_dealloc */
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
	"dmat3x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)matIter_next<3, 4, double>,                         /* tp_iternext */
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
	(newfunc)matIter_new<3, 4, double>,                 /* tp_new */
};

static PyGLMTypeObject hdmat3x4GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.dmat3x4",             /* tp_name */
		sizeof(mat<3, 4, double>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mat_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mat3x4_repr<double>,                         /* tp_repr */
		& hdmat3x4NumMethods,             /* tp_as_number */
		& hdmat3x4SeqMethods,                         /* tp_as_sequence */
		& hdmat3x4MapMethods,                         /* tp_as_mapping */
		(hashfunc)mat_hash<3, 4, double>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mat3x4_str<double>,                         /* tp_str */
		0,                         /* tp_getattro */
		0,                         /* tp_setattro */
		& hdmat3x4BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"dmat3x4( <dmat3x4 compatible type(s)> )\n3 columns of 4 components matrix of double numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mat_richcompare<3, 4, double>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mat_geniter<3, 4, double>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hdmat3x4_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mat3x4_init<double>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mat_new<3, 4, double>,                 /* tp_new */
	},
	PyGLM_TYPE_MAT,
	3,
	4,
	sizeof(double),
	sizeof(glm::mat<3, 4, double>),
	PyGLM_FS_DOUBLE
};

static PyTypeObject& hdmat3x4Type = *((PyTypeObject*)&hdmat3x4GLMType);