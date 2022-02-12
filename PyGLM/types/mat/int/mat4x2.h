#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat4x2_methods[];
extern PyBufferProcs himat4x2BufferMethods;
extern PySequenceMethods himat4x2SeqMethods;
extern PyMappingMethods himat4x2MapMethods;
extern PyNumberMethods himat4x2NumMethods;

extern PyTypeObject himat4x2IterType;
extern PyGLMTypeObject himat4x2GLMType;
extern PyTypeObject& himat4x2Type;

// cpp

PyMethodDef himat4x2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<4>, METH_NOARGS, "returns the length of glm::imat4x2"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<4, 2, glm::i32>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<4, 2, glm::i32>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<4, 2, glm::i32>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<4, 2, glm::i32>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<4, 2, glm::i32>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
PyBufferProcs himat4x2BufferMethods = {
	(getbufferproc)mat_getbuffer<4, 2, glm::i32>,
	(releasebufferproc)mat_releasebuffer,
};
PySequenceMethods himat4x2SeqMethods = {
	(lenfunc)mat_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<4, 2, glm::i32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyMappingMethods himat4x2MapMethods = {
	(lenfunc)mat_len<4>, // mp_length
	(binaryfunc)mat4x2_mp_item<glm::i32>, // mp_subscript
	(objobjargproc)mat4x2_mp_ass_item<glm::i32>, // mp_ass_subscript
};
PyNumberMethods himat4x2NumMethods = {
	(binaryfunc)mat_add<4, 2, glm::i32>, //nb_add
	(binaryfunc)mat_sub<4, 2, glm::i32>, //nb_subtract
	(binaryfunc)mat_mul<4, 2, glm::i32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat_neg<4, 2, glm::i32>, //nb_negative
	(unaryfunc)mat_pos<4, 2, glm::i32>, //nb_positive
	(unaryfunc)mat_abs<4, 2, glm::i32>, //nb_absolute
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
	(binaryfunc)mat_iadd<4, 2, glm::i32>, //nb_inplace_add
	(binaryfunc)mat_isub<4, 2, glm::i32>, //nb_inplace_subtract
	(binaryfunc)mat_imul<4, 2, glm::i32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mat_div<4, 2, glm::i32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat_idiv<4, 2, glm::i32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<4, 2, glm::i32>, //nb_inplace_matrix_multiply
};
PyTypeObject himat4x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"imat4x2Iter",             /* tp_name */
	sizeof(matIter<4, 2, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<4, 2, glm::i32>, /* tp_dealloc */
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
	"imat4x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)matIter_next<4, 2, glm::i32>,                         /* tp_iternext */
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
	(newfunc)matIter_new<4, 2, glm::i32>,                 /* tp_new */
};

PyGLMTypeObject himat4x2GLMType = _PyGLM_TYPE_DEF_IMAT(4, 2);

PyTypeObject& himat4x2Type = *((PyTypeObject*)&himat4x2GLMType);