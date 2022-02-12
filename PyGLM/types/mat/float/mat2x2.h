#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat2x2_methods[];
extern PyBufferProcs hfmat2x2BufferMethods;
extern PySequenceMethods hfmat2x2SeqMethods;
extern PyMappingMethods hfmat2x2MapMethods;
extern PyNumberMethods hfmat2x2NumMethods;

extern PyTypeObject hfmat2x2IterType;
extern PyGLMTypeObject hfmat2x2GLMType;
extern PyTypeObject& hfmat2x2Type;

// cpp

PyMethodDef hfmat2x2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<2>, METH_NOARGS, "returns the length of glm::mat2x2"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<2, 2, float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<2, 2, float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<2, 2, float>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<2, 2, float>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<2, 2, float>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
PyBufferProcs hfmat2x2BufferMethods = {
	(getbufferproc)mat_getbuffer<2, 2, float>,
	(releasebufferproc)mat_releasebuffer,
};
PySequenceMethods hfmat2x2SeqMethods = {
	(lenfunc)mat_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<2, 2, float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyMappingMethods hfmat2x2MapMethods = {
	(lenfunc)mat_len<2>, // mp_length
	(binaryfunc)mat2x2_mp_item<float>, // mp_subscript
	(objobjargproc)mat2x2_mp_ass_item<float>, // mp_ass_subscript
};
PyNumberMethods hfmat2x2NumMethods = {
	(binaryfunc)matsq_add<2, 2, float>, //nb_add
	(binaryfunc)matsq_sub<2, 2, float>, //nb_subtract
	(binaryfunc)mat_mul<2, 2, float>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat_neg<2, 2, float>, //nb_negative
	(unaryfunc)mat_pos<2, 2, float>, //nb_positive
	(unaryfunc)mat_abs<2, 2, float>, //nb_absolute
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
	(binaryfunc)matsq_iadd<2, 2, float>, //nb_inplace_add
	(binaryfunc)matsq_isub<2, 2, float>, //nb_inplace_subtract
	(binaryfunc)mat_imul<2, 2, float>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)matsq_div<2, 2, float>,
	0, //nb_inplace_floor_divide
	(binaryfunc)matsq_idiv<2, 2, float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<2, 2, float>, //nb_inplace_matrix_multiply
};
PyTypeObject hfmat2x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat2x2Iter",             /* tp_name */
	sizeof(matIter<2, 2, float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<2, 2, float>, /* tp_dealloc */
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
	"mat2x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)matIter_next<2, 2, float>,                         /* tp_iternext */
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
	(newfunc)matIter_new<2, 2, float>,                 /* tp_new */
};

PyGLMTypeObject hfmat2x2GLMType = _PyGLM_TYPE_DEF_FMAT(2, 2);

PyTypeObject& hfmat2x2Type = *((PyTypeObject*)&hfmat2x2GLMType);