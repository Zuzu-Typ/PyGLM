#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::u64> vec2_uint64_t;

static PyMemberDef hu64vec2_members[] = {
	{ (char*)"x", T_ULONGLONG, offsetof(vec2_uint64_t, super_type.x), 0, (char*)"u64vec2.x" },
	{ (char*)"y", T_ULONGLONG, offsetof(vec2_uint64_t, super_type.y), 0, (char*)"u64vec2.y" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hu64vec2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec2_to_tuple<glm::u64>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec2_setstate<glm::u64>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec2_to_list<glm::u64>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec2_to_tuple<glm::u64>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<2, glm::u64>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hu64vec2BufferMethods = {
	(getbufferproc)vec_getbuffer<2, glm::u64>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hu64vec2SeqMethods = {
	(lenfunc)vec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec2_sq_item<glm::u64>, // sq_item
	0,
	(ssizeobjargproc)vec2_sq_ass_item<glm::u64>, // sq_ass_item
	0,
	(objobjproc)vec_contains<2, glm::u64>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hu64vec2NumMethods = {
	(binaryfunc)vec_add<2, glm::u64>, //nb_add
	(binaryfunc)vec_sub<2, glm::u64>, //nb_subtract
	(binaryfunc)vec_mul<2, glm::u64>, //nb_multiply
	(binaryfunc)vec_mod<2, glm::u64>, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	0, //nb_negative
	(unaryfunc)vec_pos<2, glm::u64>, //nb_positive
	(unaryfunc)vec_abs<2, glm::u64>, //nb_absolute
	0, //nb_bool
	(unaryfunc)vec_invert<2, glm::u64>, //nb_invert
	(binaryfunc)vec_lshift<2, glm::u64>, //nb_lshift
	(binaryfunc)vec_rshift<2, glm::u64>, //nb_rshift
	(binaryfunc)vec_and<2, glm::u64>, //nb_and
	(binaryfunc)vec_xor<2, glm::u64>, //nb_xor
	(binaryfunc)vec_or<2, glm::u64>, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)vec_iadd<2, glm::u64>, //nb_inplace_add
	(binaryfunc)vec_isub<2, glm::u64>, //nb_inplace_subtract
	(binaryfunc)vec_imul<2, glm::u64>, //nb_inplace_multiply
	(binaryfunc)vec_imod<2, glm::u64>, //nb_inplace_remainder
	0, //nb_inplace_power
	(binaryfunc)vec_ilshift<2, glm::u64>, //nb_inplace_lshift
	(binaryfunc)vec_irshift<2, glm::u64>, //nb_inplace_rshift
	(binaryfunc)vec_iand<2, glm::u64>, //nb_inplace_and
	(binaryfunc)vec_ixor<2, glm::u64>, //nb_inplace_xor
	(binaryfunc)vec_ior<2, glm::u64>, //nb_inplace_or
	(binaryfunc)vec_div<2, glm::u64>, //nb_floor_divide
	(binaryfunc)vec_div<2, glm::u64>,
	(binaryfunc)vec_idiv<2, glm::u64>, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<2, glm::u64>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<2, glm::u64>, //nb_inplace_matrix_multiply
};
static PyTypeObject hu64vec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"u64vec2Iter",             /* tp_name */
	sizeof(vecIter<2, glm::u64>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<2, glm::u64>, /* tp_dealloc */
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
	"u64vec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec2Iter_next<glm::u64>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<2, glm::u64>,                 /* tp_new */
};

static PyGLMTypeObject hu64vec2GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.u64vec2",             /* tp_name */
		sizeof(vec<2, glm::u64>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)vec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)vec2_repr<glm::u64>,                         /* tp_repr */
		& hu64vec2NumMethods,             /* tp_as_number */
		& hu64vec2SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)vec_hash<2, glm::u64>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)vec2_str<glm::u64>,                         /* tp_str */
		(getattrofunc)vec_getattr<2, glm::u64>,                         /* tp_getattro */
		(setattrofunc)vec_setattr<2, glm::u64>,                         /* tp_setattro */
		& hu64vec2BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"u64vec2( <vec2 compatible type(s)> )\n2 components vector of high qualifier 64 bit unsigned integer numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)vec_richcompare<2, glm::u64>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)vec_geniter<2, glm::u64>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hu64vec2_methods,             /* tp_methods */
		hu64vec2_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)vec2_init<glm::u64>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)vec_new<2, glm::u64>,                 /* tp_new */
	},
	PyGLM_TYPE_VEC,
	2,
	0,
	sizeof(uint64),
	sizeof(glm::vec<2, uint64>),
	PyGLM_FS_UINT64
};

static PyTypeObject& hu64vec2Type = *((PyTypeObject*)&hu64vec2GLMType);