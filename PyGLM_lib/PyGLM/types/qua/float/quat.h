#pragma once

#include "../forward_declarations.h"

static PyMethodDef hfqua_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)qua_length, METH_NOARGS, "returns the length of glm::quat"},
	{ "__getstate__", (PyCFunction)qua_to_tuple<float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)qua_setstate<float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)qua_to_list<float>, METH_NOARGS, "Return the components of this quaterion as a list"},
	{ "to_tuple", (PyCFunction)qua_to_tuple<float>, METH_NOARGS, "Return the components of this quaterion as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)qua_from_bytes<float>, METH_O | METH_STATIC, "Create a quaternion from a bytes string"},
	{ NULL }
};

static PyMemberDef hfqua_members[] = {
	{ (char*)"x", T_FLOAT, offsetof(UNBRACKET(qua<float>), super_type.x), 0, (char*)"quat.x" },
	{ (char*)"y", T_FLOAT, offsetof(UNBRACKET(qua<float>), super_type.y), 0, (char*)"quat.y" },
	{ (char*)"z", T_FLOAT, offsetof(UNBRACKET(qua<float>), super_type.z), 0, (char*)"quat.z" },
	{ (char*)"w", T_FLOAT, offsetof(UNBRACKET(qua<float>), super_type.w), 0, (char*)"quat.w" },
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hfquaBufferMethods = {
	(getbufferproc)qua_getbuffer<float>,
	(releasebufferproc)qua_releasebuffer,
};
static PySequenceMethods hfquaSeqMethods = {
	(lenfunc)qua_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)qua_sq_item<float>, // sq_item
	0,
	(ssizeobjargproc)qua_sq_ass_item<float>, // sq_ass_item
	0,
	(objobjproc)qua_contains<float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hfquaNumMethods = {
	(binaryfunc)qua_add<float>, //nb_add
	(binaryfunc)qua_sub<float>, //nb_subtract
	(binaryfunc)qua_mul<float>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)qua_neg<float>, //nb_negative
	(unaryfunc)qua_pos<float>, //nb_positive
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
	(binaryfunc)qua_iadd<float>, //nb_inplace_add
	(binaryfunc)qua_isub<float>, //nb_inplace_subtract
	(binaryfunc)qua_imul<float>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)qua_div<float>,
	0, //nb_inplace_floor_divide
	(binaryfunc)qua_idiv<float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)qua_matmul, //nb_matrix_multiply
	(binaryfunc)qua_imatmul<double>, //nb_inplace_matrix_multiply
};
static PyTypeObject hfquaIterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"quaIter",             /* tp_name */
	sizeof(quaIter<float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)quaIter_dealloc<float>, /* tp_dealloc */
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
	"quat iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,                         /* tp_iter */
	(iternextfunc)quaIter_next<float>,                         /* tp_iternext */
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
	(newfunc)quaIter_new<float>,                 /* tp_new */
};

static PyGLMTypeObject hfquaGLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.quat",             /* tp_name */
		sizeof(qua<float>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)qua_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)qua_repr<float>,                         /* tp_repr */
		& hfquaNumMethods,             /* tp_as_number */
		& hfquaSeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)qua_hash<float>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)qua_str<float>,                         /* tp_str */
		0,                         /* tp_getattro */
		0,                         /* tp_setattro */
		& hfquaBufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"quat( <quat compatible type(s)> )\n4 components quaternion of floating-point numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)qua_richcompare<float>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)qua_geniter<float>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hfqua_methods,             /* tp_methods */
		hfqua_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)qua_init<float>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)qua_new<float>,                 /* tp_new */
	},
	PyGLM_TYPE_QUA,
	4,
	0,
	sizeof(float),
	sizeof(glm::qua<float>),
	PyGLM_FS_FLOAT
};

static PyTypeObject& hfquaType = *((PyTypeObject*)&hfquaGLMType);