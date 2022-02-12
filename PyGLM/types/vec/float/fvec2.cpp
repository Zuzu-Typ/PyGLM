#include "vec2.h"

PyMemberDef hfvec2_members[] = {
	{ (char*)"x", T_FLOAT, offsetof(vec2_float_t, super_type.x), 0, (char*)"vec2.x" },
	{ (char*)"y", T_FLOAT, offsetof(vec2_float_t, super_type.y), 0, (char*)"vec2.y" },
	{ NULL }  /* Sentinel */
};
PyMethodDef hfvec2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec2_to_tuple<float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec2_setstate<float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec2_to_list<float>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec2_to_tuple<float>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<2, float>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
PyBufferProcs hfvec2BufferMethods = {
	(getbufferproc)vec_getbuffer<2, float>,
	(releasebufferproc)vec_releasebuffer,
};
PySequenceMethods hfvec2SeqMethods = {
	(lenfunc)vec_len<2>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec2_sq_item<float>, // sq_item
	0,
	(ssizeobjargproc)vec2_sq_ass_item<float>, // sq_ass_item
	0,
	(objobjproc)vec_contains<2, float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyNumberMethods hfvec2NumMethods = {
	(binaryfunc)vec_add<2, float>, //nb_add
	(binaryfunc)vec_sub<2, float>, //nb_subtract
	(binaryfunc)vec_mul<2, float>, //nb_multiply
	(binaryfunc)vec_mod<2, float>, //nb_remainder
	(binaryfunc)vec_divmod<2, float>, //nb_divmod
	(ternaryfunc)vec_pow<2, float>, //nb_power
	(unaryfunc)vec_neg<2, float>, //nb_negative
	(unaryfunc)vec_pos<2, float>, //nb_positive
	(unaryfunc)vec_abs<2, float>, //nb_absolute
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
	(binaryfunc)vec_iadd<2, float>, //nb_inplace_add
	(binaryfunc)vec_isub<2, float>, //nb_inplace_subtract
	(binaryfunc)vec_imul<2, float>, //nb_inplace_multiply
	(binaryfunc)vec_imod<2, float>, //nb_inplace_remainder
	(ternaryfunc)vec_ipow<2, float>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)vec_floordiv<2, float>, //nb_floor_divide
	(binaryfunc)vec_div<2, float>,
	(binaryfunc)vec_ifloordiv<2, float>, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<2, float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<2, float>, //nb_inplace_matrix_multiply
};
PyTypeObject hfvec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"vec2Iter",             /* tp_name */
	sizeof(vecIter<2, float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<2, float>, /* tp_dealloc */
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
	"vec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec2Iter_next<float>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<2, float>,                 /* tp_new */
};

PyGLMTypeObject hfvec2GLMType = _PyGLM_TYPE_DEF_FVEC(2);

PyTypeObject& hfvec2Type = *((PyTypeObject*)&hfvec2GLMType);
