#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef himvec4_methods[];
extern PyBufferProcs himvec4BufferMethods;
extern PySequenceMethods himvec4SeqMethods;
extern PyNumberMethods himvec4NumMethods;

extern PyTypeObject himvec4IterType;
extern PyGLMTypeObject himvec4GLMType;
extern PyTypeObject& himvec4Type;

// cpp

PyMethodDef himvec4_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<4, glm::i32>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<4, glm::i32>, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)mvec4_to_tuple<glm::i32>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mvec4_setstate<glm::i32>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mvec4_to_list<glm::i32>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)mvec4_to_tuple<glm::i32>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ NULL }  /* Sentinel */
};
PyBufferProcs himvec4BufferMethods = {
	(getbufferproc)mvec_getbuffer<4, glm::i32>,
	(releasebufferproc)mvec_releasebuffer,
};
PySequenceMethods himvec4SeqMethods = {
	(lenfunc)mvec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec4_sq_item<glm::i32>, // sq_item
	0,
	(ssizeobjargproc)mvec4_sq_ass_item<glm::i32>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<4, glm::i32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyNumberMethods himvec4NumMethods = {
	(binaryfunc)mvec_add<4, glm::i32>, //nb_add
	(binaryfunc)mvec_sub<4, glm::i32>, //nb_subtract
	(binaryfunc)mvec_mul<4, glm::i32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mvec_neg<4, glm::i32>, //nb_negative
	(unaryfunc)mvec_pos<4, glm::i32>, //nb_positive
	(unaryfunc)mvec_abs<4, glm::i32>, //nb_absolute
	0, //nb_bool
	(unaryfunc)mvec_invert<4, glm::i32>, //nb_invert
	(binaryfunc)mvec_lshift<4, glm::i32>, //nb_lshift
	(binaryfunc)mvec_rshift<4, glm::i32>, //nb_rshift
	(binaryfunc)mvec_and<4, glm::i32>, //nb_and
	(binaryfunc)mvec_xor<4, glm::i32>, //nb_xor
	(binaryfunc)mvec_or<4, glm::i32>, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)mvec_iadd<4, glm::i32>, //nb_inplace_add
	(binaryfunc)mvec_isub<4, glm::i32>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<4, glm::i32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	(binaryfunc)mvec_ilshift<4, glm::i32>, //nb_inplace_lshift
	(binaryfunc)mvec_irshift<4, glm::i32>, //nb_inplace_rshift
	(binaryfunc)mvec_iand<4, glm::i32>, //nb_inplace_and
	(binaryfunc)mvec_ixor<4, glm::i32>, //nb_inplace_xor
	(binaryfunc)mvec_ior<4, glm::i32>, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mvec_div<4, glm::i32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<4, glm::i32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mvec_matmul, //nb_matrix_multiply
	(binaryfunc)mvec_imatmul<4, glm::i32>, //nb_inplace_matrix_multiply
};
PyTypeObject himvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"imvec4Iter",             /* tp_name */
	sizeof(mvecIter<4, glm::i32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<4, glm::i32>, /* tp_dealloc */
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
	"imvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)mvec4Iter_next<glm::i32>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<4, glm::i32>,                 /* tp_new */
};

PyGLMTypeObject himvec4GLMType = _PyGLM_TYPE_DEF_IMVEC(4);

PyTypeObject& himvec4Type = *((PyTypeObject*)&himvec4GLMType);