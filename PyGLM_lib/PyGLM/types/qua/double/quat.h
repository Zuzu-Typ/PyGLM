#pragma once

#include "../forward_declarations.h"

static PyMethodDef hdqua_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)qua_length, METH_NOARGS, "returns the length of glm::dquat"},
	{ "__getstate__", (PyCFunction)qua_to_tuple<double>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)qua_setstate<double>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)qua_to_list<double>, METH_NOARGS, "Return the components of this quaterion as a list"},
	{ "to_tuple", (PyCFunction)qua_to_tuple<double>, METH_NOARGS, "Return the components of this quaterion as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)qua_from_bytes<double>, METH_O | METH_STATIC, "Create a quaternion from a bytes string"},
	{ NULL }
};

static PyMemberDef hdqua_members[] = {
	{ (char*)"x", T_DOUBLE, offsetof(UNBRACKET(qua<double>), super_type.x), 0, (char*)"dquat.x" },
	{ (char*)"y", T_DOUBLE, offsetof(UNBRACKET(qua<double>), super_type.y), 0, (char*)"dquat.y" },
	{ (char*)"z", T_DOUBLE, offsetof(UNBRACKET(qua<double>), super_type.z), 0, (char*)"dquat.z" },
	{ (char*)"w", T_DOUBLE, offsetof(UNBRACKET(qua<double>), super_type.w), 0, (char*)"dquat.w" },
	{ NULL }  /* Sentinel */
};
static PyBufferProcs hdquaBufferMethods = {
	(getbufferproc)qua_getbuffer<double>,
	(releasebufferproc)qua_releasebuffer,
};
static PySequenceMethods hdquaSeqMethods = {
	(lenfunc)qua_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)qua_sq_item<double>, // sq_item
	0,
	(ssizeobjargproc)qua_sq_ass_item<double>, // sq_ass_item
	0,
	(objobjproc)qua_contains<double>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyNumberMethods hdquaNumMethods = {
	(binaryfunc)qua_add<double>, //nb_add
	(binaryfunc)qua_sub<double>, //nb_subtract
	(binaryfunc)qua_mul<double>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)qua_neg<double>, //nb_negative
	(unaryfunc)qua_pos<double>, //nb_positive
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
	(binaryfunc)qua_iadd<double>, //nb_inplace_add
	(binaryfunc)qua_isub<double>, //nb_inplace_subtract
	(binaryfunc)qua_imul<double>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)qua_div<double>,
	0, //nb_inplace_floor_divide
	(binaryfunc)qua_idiv<double>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)qua_matmul, //nb_matrix_multiply
	(binaryfunc)qua_imatmul<double>, //nb_inplace_matrix_multiply
};
static PyTypeObject hdquaIterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"dquatIter",             /* tp_name */
	sizeof(quaIter<double>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)quaIter_dealloc<double>, /* tp_dealloc */
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
	"dquat iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,                         /* tp_iter */
	(iternextfunc)quaIter_next<double>,                         /* tp_iternext */
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
	(newfunc)quaIter_new<double>,                 /* tp_new */
};

static PyGLMTypeObject hdquaGLMType = {
	{
		PyVarObject_HEAD_INIT(NULL, 0)
		"glm.dquat",             /* tp_name */
		sizeof(qua<double>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)qua_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)qua_repr<double>,                         /* tp_repr */
		& hdquaNumMethods,             /* tp_as_number */
		& hdquaSeqMethods,                         /* tp_as_sequence */
		0,                         /* tp_as_mapping */
		(hashfunc)qua_hash<double>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)qua_str<double>,                         /* tp_str */
		0,                         /* tp_getattro */
		0,                         /* tp_setattro */
		& hdquaBufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"dquat( <dquat compatible type(s)> )\n4 components quaternion of double numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)qua_richcompare<double>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)qua_geniter<double>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hdqua_methods,             /* tp_methods */
		hdqua_members,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)qua_init<double>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)qua_new<double>,                 /* tp_new */
	},
	PyGLM_TYPE_QUA,
	4,
	0,
	sizeof(double),
	sizeof(glm::qua<double>),
	PyGLM_FS_DOUBLE
};

static PyTypeObject& hdquaType = *((PyTypeObject*)&hdquaGLMType);