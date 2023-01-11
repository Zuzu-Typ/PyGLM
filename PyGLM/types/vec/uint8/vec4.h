#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::u8> vec4_uint8_t;

static PyMemberDef hu8vec4_members[] = {
	{ (char*)"x", T_UBYTE, offsetof(vec4_uint8_t, super_type.x), 0, (char*)"u8vec4.x" },
	{ (char*)"y", T_UBYTE, offsetof(vec4_uint8_t, super_type.y), 0, (char*)"u8vec4.y" },
	{ (char*)"z", T_UBYTE, offsetof(vec4_uint8_t, super_type.z), 0, (char*)"u8vec4.z" },
	{ (char*)"w", T_UBYTE, offsetof(vec4_uint8_t, super_type.w), 0, (char*)"u8vec4.w" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hu8vec4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec4_to_tuple<glm::u8>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec4_setstate<glm::u8>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec4_to_list<glm::u8>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec4_to_tuple<glm::u8>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<4, glm::u8>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hu8vec4BufferMethods = {
	(getbufferproc)vec_getbuffer<4, glm::u8>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hu8vec4SeqMethods = {
	(lenfunc)vec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec4_sq_item<glm::u8>, // sq_item
	0,
	(ssizeobjargproc)vec4_sq_ass_item<glm::u8>, // sq_ass_item
	0,
	(objobjproc)vec_contains<4, glm::u8>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hu8vec4NumMethods = {
	(binaryfunc)vec_add<4, glm::u8>, //nb_add
	(binaryfunc)vec_sub<4, glm::u8>, //nb_subtract
	(binaryfunc)vec_mul<4, glm::u8>, //nb_multiply
	(binaryfunc)vec_mod<4, glm::u8>, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	0, //nb_negative
	(unaryfunc)vec_pos<4, glm::u8>, //nb_positive
	(unaryfunc)vec_abs<4, glm::u8>, //nb_absolute
	0, //nb_bool
	(unaryfunc)vec_invert<4, glm::u8>, //nb_invert
	(binaryfunc)vec_lshift<4, glm::u8>, //nb_lshift
	(binaryfunc)vec_rshift<4, glm::u8>, //nb_rshift
	(binaryfunc)vec_and<4, glm::u8>, //nb_and
	(binaryfunc)vec_xor<4, glm::u8>, //nb_xor
	(binaryfunc)vec_or<4, glm::u8>, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)vec_iadd<4, glm::u8>, //nb_inplace_add
	(binaryfunc)vec_isub<4, glm::u8>, //nb_inplace_subtract
	(binaryfunc)vec_imul<4, glm::u8>, //nb_inplace_multiply
	(binaryfunc)vec_imod<4, glm::u8>, //nb_inplace_remainder
	0, //nb_inplace_power
	(binaryfunc)vec_ilshift<4, glm::u8>, //nb_inplace_lshift
	(binaryfunc)vec_irshift<4, glm::u8>, //nb_inplace_rshift
	(binaryfunc)vec_iand<4, glm::u8>, //nb_inplace_and
	(binaryfunc)vec_ixor<4, glm::u8>, //nb_inplace_xor
	(binaryfunc)vec_ior<4, glm::u8>, //nb_inplace_or
	(binaryfunc)vec_div<4, glm::u8>, //nb_floor_divide
	(binaryfunc)vec_div<4, glm::u8>,
	(binaryfunc)vec_idiv<4, glm::u8>, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<4, glm::u8>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<4, glm::u8>, //nb_inplace_matrix_multiply
};
static PyTypeObject hu8vec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"u8vec4Iter",             /* tp_name */
	sizeof(vecIter<4, glm::u8>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<4, glm::u8>, /* tp_dealloc */
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
	"u8vec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec4Iter_next<glm::u8>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<4, glm::u8>,                 /* tp_new */
};

static PyGLMTypeObject hu8vec4GLMType = {
	{
		PyObject_HEAD_INIT(NULL)
		"glm.u8vec4",             /* tp_name */
		sizeof(vec<4, glm::u8>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)vec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)vec4_repr<glm::u8>,                         /* tp_repr */
		& hu8vec4NumMethods,             /* tp_as_number */
		& hu8vec4SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)vec_hash<4, glm::u8>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)vec4_str<glm::u8>,                         /* tp_str */
		(getattrofunc)vec_getattr<4, glm::u8>,                         /* tp_getattro */
		(setattrofunc)vec_setattr<4, glm::u8>,                         /* tp_setattro */
		& hu8vec4BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"u8vec4( <vec4 compatible type(s)> )\n4 components vector of high qualifier 8 bit unsigned integer numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)vec_richcompare<4, glm::u8>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)vec_geniter<4, glm::u8>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hu8vec4_methods,             /* tp_methods */
		hu8vec4_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)vec4_init<glm::u8>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)vec_new<4, glm::u8>,                 /* tp_new */
	},
	PyGLM_TYPE_VEC,
	4,
	0,
	sizeof(uint8),
	sizeof(glm::vec<4, uint8>),
	PyGLM_FS_UINT8
};

static PyTypeObject& hu8vec4Type = *((PyTypeObject*)&hu8vec4GLMType);