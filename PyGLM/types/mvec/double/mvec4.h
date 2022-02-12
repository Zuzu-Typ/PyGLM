#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef hdmvec4_methods[];
extern PyBufferProcs hdmvec4BufferMethods;
extern PySequenceMethods hdmvec4SeqMethods;
extern PyNumberMethods hdmvec4NumMethods;

extern PyTypeObject hdmvec4IterType;
extern PyGLMTypeObject hdmvec4GLMType;
extern PyTypeObject& hdmvec4Type;

// cpp

PyMethodDef hdmvec4_methods[] = {
	{ "__copy__", (PyCFunction)mvec_copy<4, double>, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)mvec_deepcopy<4, double>, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)mvec4_to_tuple<double>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mvec4_setstate<double>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mvec4_to_list<double>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)mvec4_to_tuple<double>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ NULL }  /* Sentinel */
};
PyBufferProcs hdmvec4BufferMethods = {
	(getbufferproc)mvec_getbuffer<4, double>,
	(releasebufferproc)mvec_releasebuffer,
};
PySequenceMethods hdmvec4SeqMethods = {
	(lenfunc)mvec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)mvec4_sq_item<double>, // sq_item
	0,
	(ssizeobjargproc)mvec4_sq_ass_item<double>, // sq_ass_item
	0,
	(objobjproc)mvec_contains<4, double>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyNumberMethods hdmvec4NumMethods = {
	(binaryfunc)mvec_add<4, double>, //nb_add
	(binaryfunc)mvec_sub<4, double>, //nb_subtract
	(binaryfunc)mvec_mul<4, double>, //nb_multiply
	(binaryfunc)mvec_mod<4, double>, //nb_remainder
	(binaryfunc)mvec_divmod<4, double>, //nb_divmod
	(ternaryfunc)mvec_pow<4, double>, //nb_power
	(unaryfunc)mvec_neg<4, double>, //nb_negative
	(unaryfunc)mvec_pos<4, double>, //nb_positive
	(unaryfunc)mvec_abs<4, double>, //nb_absolute
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
	(binaryfunc)mvec_iadd<4, double>, //nb_inplace_add
	(binaryfunc)mvec_isub<4, double>, //nb_inplace_subtract
	(binaryfunc)mvec_imul<4, double>, //nb_inplace_multiply
	(binaryfunc)mvec_imod<4, double>, //nb_inplace_remainder
	(ternaryfunc)mvec_ipow<4, double>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)mvec_floordiv<4, double>, //nb_floor_divide
	(binaryfunc)mvec_div<4, double>,
	(binaryfunc)mvec_ifloordiv<4, double>, //nb_inplace_floor_divide
	(binaryfunc)mvec_idiv<4, double>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mvec_matmul, //nb_matrix_multiply
	(binaryfunc)mvec_imatmul<4, double>, //nb_inplace_matrix_multiply
};
PyTypeObject hdmvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"dmvec4Iter",             /* tp_name */
	sizeof(mvecIter<4, double>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mvecIter_dealloc<4, double>, /* tp_dealloc */
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
	"dmvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)mvec4Iter_next<double>,                         /* tp_iternext */
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
	(newfunc)mvecIter_new<4, double>,                 /* tp_new */
};

PyGLMTypeObject hdmvec4GLMType = _PyGLM_TYPE_DEF_DMVEC(4);

PyTypeObject& hdmvec4Type = *((PyTypeObject*)&hdmvec4GLMType);