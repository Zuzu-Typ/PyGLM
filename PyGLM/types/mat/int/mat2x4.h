#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat2x4_methods[];
extern PyBufferProcs himat2x4BufferMethods;
extern PySequenceMethods himat2x4SeqMethods;
extern PyMappingMethods himat2x4MapMethods;
extern PyNumberMethods himat2x4NumMethods;

extern PyTypeObject himat2x4IterType;
extern PyGLMTypeObject himat2x4GLMType;
extern PyTypeObject& himat2x4Type;

// cpp

PyMethodDef himat2x4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<2>, METH_NOARGS, "returns the length of glm::imat2x4"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<2, 4, glm::i32>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<2, 4, glm::i32>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<2, 4, glm::i32>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<2, 4, glm::i32>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<2, 4, glm::i32>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
PyBufferProcs himat2x4BufferMethods = {
	(getbufferproc)mat_getbuffer<2, 4, glm::i32>,
	(releasebufferproc)mat_releasebuffer,
};
PySequenceMethods himat2x4SeqMethods = {
	(lenfunc)mat_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<2, 4, glm::i32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyMappingMethods himat2x4MapMethods = {
	(lenfunc)mat_len<2>, // mp_length
	(binaryfunc)mat2x4_mp_item<glm::i32>, // mp_subscript
	(objobjargproc)mat2x4_mp_ass_item<glm::i32>, // mp_ass_subscript
};
PyNumberMethods himat2x4NumMethods = {
	(binaryfunc)mat_add<2, 4, glm::i32>, //nb_add
	(binaryfunc)mat_sub<2, 4, glm::i32>, //nb_subtract
	(binaryfunc)mat_mul<2, 4, glm::i32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat_neg<2, 4, glm::i32>, //nb_negative
	(unaryfunc)mat_pos<2, 4, glm::i32>, //nb_positive
	(unaryfunc)mat_abs<2, 4, glm::i32>, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_glm::i32
	(binaryfunc)mat_iadd<2, 4, glm::i32>, //nb_inplace_add
	(binaryfunc)mat_isub<2, 4, glm::i32>, //nb_inplace_subtract
	(binaryfunc)mat_imul<2, 4, glm::i32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mat_div<2, 4, glm::i32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat_idiv<2, 4, glm::i32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<2, 4, glm::i32>, //nb_inplace_matrix_multiply
};
PyTypeObject himat2x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"imat2x4Iter",             /* tp_name */
	sizeof(matIter<2, 4, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<2, 4, glm::i32>, /* tp_dealloc */
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
	"imat2x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)matIter_next<2, 4, glm::i32>,                         /* tp_iternext */
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
	(newfunc)matIter_new<2, 4, glm::i32>,                 /* tp_new */
};

PyGLMTypeObject himat2x4GLMType = _PyGLM_TYPE_DEF_IMAT(2, 4);

PyTypeObject& himat2x4Type = *((PyTypeObject*)&himat2x4GLMType);