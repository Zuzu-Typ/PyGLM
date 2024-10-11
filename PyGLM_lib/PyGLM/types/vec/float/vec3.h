#pragma once

#include "../forward_declarations.h"

typedef vec<3, float> vec3_float_t;

static PyMemberDef hfvec3_members[] = {
	{ (char*)"x", T_FLOAT, offsetof(vec3_float_t, super_type.x), 0, (char*)"vec3.x" },
	{ (char*)"y", T_FLOAT, offsetof(vec3_float_t, super_type.y), 0, (char*)"vec3.y" },
	{ (char*)"z", T_FLOAT, offsetof(vec3_float_t, super_type.z), 0, (char*)"vec3.z" },
	{ NULL }  /* Sentinel */
};
static PyMethodDef hfvec3_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec3_to_tuple<float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec3_setstate<float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec3_to_list<float>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec3_to_tuple<float>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<3, float>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hfvec3BufferMethods = {
	(getbufferproc)vec_getbuffer<3, float>,
	(releasebufferproc)vec_releasebuffer,
};
static PySequenceMethods hfvec3SeqMethods = {
	(lenfunc)vec_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec3_sq_item<float>, // sq_item
	0,
	(ssizeobjargproc)vec3_sq_ass_item<float>, // sq_ass_item
	0,
	(objobjproc)vec_contains<3, float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hfvec3NumMethods = {
	(binaryfunc)vec_add<3, float>, //nb_add
	(binaryfunc)vec_sub<3, float>, //nb_subtract
	(binaryfunc)vec_mul<3, float>, //nb_multiply
	(binaryfunc)vec_mod<3, float>, //nb_remainder
	(binaryfunc)vec_divmod<3, float>, //nb_divmod
	(ternaryfunc)vec_pow<3, float>, //nb_power
	(unaryfunc)vec_neg<3, float>, //nb_negative
	(unaryfunc)vec_pos<3, float>, //nb_positive
	(unaryfunc)vec_abs<3, float>, //nb_absolute
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
	(binaryfunc)vec_iadd<3, float>, //nb_inplace_add
	(binaryfunc)vec_isub<3, float>, //nb_inplace_subtract
	(binaryfunc)vec_imul<3, float>, //nb_inplace_multiply
	(binaryfunc)vec_imod<3, float>, //nb_inplace_remainder
	(ternaryfunc)vec_ipow<3, float>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)vec_floordiv<3, float>, //nb_floor_divide
	(binaryfunc)vec_div<3, float>,
	(binaryfunc)vec_ifloordiv<3, float>, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<3, float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<3, float>, //nb_inplace_matrix_multiply
};
static PyTypeObject hfvec3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"vec3Iter",             /* tp_name */
	sizeof(vecIter<3, float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<3, float>, /* tp_dealloc */
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
	"vec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec3Iter_next<float>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<3, float>,                 /* tp_new */
};

static PyGLMTypeObject hfvec3GLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.vec3",             /* tp_name */
		sizeof(vec<3, float>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)vec_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)vec3_repr<float>,                         /* tp_repr */
		& hfvec3NumMethods,             /* tp_as_number */
		& hfvec3SeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)vec_hash<3, float>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)vec3_str<float>,                         /* tp_str */
		(getattrofunc)vec_getattr<3, float>,                         /* tp_getattro */
		(setattrofunc)vec_setattr<3, float>,                         /* tp_setattro */
		& hfvec3BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"vec3( <vec3 compatible type(s)> )\n3 components vector of high qualifier float numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)vec_richcompare<3, float>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)vec_geniter<3, float>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hfvec3_methods,             /* tp_methods */
		hfvec3_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)vec3_init<float>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)vec_new<3, float>,                 /* tp_new */
	},
	PyGLM_TYPE_VEC,
	3,
	0,
	sizeof(float),
	sizeof(glm::vec<3, float>),
	PyGLM_FS_FLOAT
};

static PyTypeObject& hfvec3Type = *((PyTypeObject*)&hfvec3GLMType);