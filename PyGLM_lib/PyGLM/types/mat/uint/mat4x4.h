#pragma once

#include "../forward_declarations.h"

static PyMethodDef humat4x4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<4>, METH_NOARGS, "returns the length of glm::umat4x4"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<4, 4, glm::u32>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<4, 4, glm::u32>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<4, 4, glm::u32>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<4, 4, glm::u32>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<4, 4, glm::u32>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
static PyBufferProcs humat4x4BufferMethods = {
	(getbufferproc)mat_getbuffer<4, 4, glm::u32>,
	(releasebufferproc)mat_releasebuffer,
};
static PySequenceMethods humat4x4SeqMethods = {
	(lenfunc)mat_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<4, 4, glm::u32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyMappingMethods humat4x4MapMethods = {
	(lenfunc)mat_len<4>, // mp_length
	(binaryfunc)mat4x4_mp_item<glm::u32>, // mp_subscript
	(objobjargproc)mat4x4_mp_ass_item<glm::u32>, // mp_ass_subscript
};
static PyNumberMethods humat4x4NumMethods = {
	(binaryfunc)matsq_add<4, 4, glm::u32>, //nb_add
	(binaryfunc)matsq_sub<4, 4, glm::u32>, //nb_subtract
	(binaryfunc)mat_mul<4, 4, glm::u32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	0, //nb_negative
	(unaryfunc)mat_pos<4, 4, glm::u32>, //nb_positive
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
	0, //nb_glm::u32
	(binaryfunc)matsq_iadd<4, 4, glm::u32>, //nb_inplace_add
	(binaryfunc)matsq_isub<4, 4, glm::u32>, //nb_inplace_subtract
	(binaryfunc)mat_imul<4, 4, glm::u32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mat_div<4, 4, glm::u32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat_idiv<4, 4, glm::u32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<4, 4, glm::u32>, //nb_inplace_matrix_multiply
};
static PyTypeObject humat4x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"umat4x4Iter",             /* tp_name */
	sizeof(matIter<4, 4, glm::u32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<4, 4, glm::u32>, /* tp_dealloc */
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
	"umat4x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)matIter_next<4, 4, glm::u32>,                         /* tp_iternext */
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
	(newfunc)matIter_new<4, 4, glm::u32>,                 /* tp_new */
};

static PyGLMTypeObject humat4x4GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.umat4x4",             /* tp_name */
		sizeof(mat<4, 4, glm::u32>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mat_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mat4x4_repr<glm::u32>,                         /* tp_repr */
		& humat4x4NumMethods,             /* tp_as_number */
		& humat4x4SeqMethods,                         /* tp_as_sequence */
		& humat4x4MapMethods,                         /* tp_as_mapping */
		(hashfunc)mat_hash<4, 4, glm::u32>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mat4x4_str<glm::u32>,                         /* tp_str */
		0,                         /* tp_getattro */
		0,                         /* tp_setattro */
		& humat4x4BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"umat4x4( <umat4x4 compatible type(s)> )\n4 columns of 4 components matrix of unsigned integer numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mat_richcompare<4, 4, glm::u32>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mat_geniter<4, 4, glm::u32>,                         /* tp_iter */
		0,                         /* tp_iternext */
		humat4x4_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mat4x4_init<glm::u32>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mat_new<4, 4, glm::u32>,                 /* tp_new */
	},
	PyGLM_TYPE_MAT,
	4,
	4,
	sizeof(uint32),
	sizeof(glm::mat<4, 4, uint32>),
	PyGLM_FS_UINT32
};

static PyTypeObject& humat4x4Type = *((PyTypeObject*)&humat4x4GLMType);