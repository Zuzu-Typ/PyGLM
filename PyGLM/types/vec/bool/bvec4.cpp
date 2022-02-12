#include "vec4.h"

PyMemberDef hbvec4_members[] = {
	{ (char*)"x", T_BOOL, offsetof(vec4_bool_t, super_type.x), 0, (char*)"bvec4.x" },
	{ (char*)"y", T_BOOL, offsetof(vec4_bool_t, super_type.y), 0, (char*)"bvec4.y" },
	{ (char*)"z", T_BOOL, offsetof(vec4_bool_t, super_type.z), 0, (char*)"bvec4.z" },
	{ (char*)"w", T_BOOL, offsetof(vec4_bool_t, super_type.w), 0, (char*)"bvec4.w" },
	{ NULL }  /* Sentinel */
};
PyMethodDef hbvec4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec4_to_tuple<bool>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec4_setstate<bool>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec4_to_list<bool>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec4_to_tuple<bool>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<4, bool>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
PyBufferProcs hbvec4BufferMethods = {
	(getbufferproc)vec_getbuffer<4, bool>,
	(releasebufferproc)vec_releasebuffer,
};
PySequenceMethods hbvec4SeqMethods = {
	(lenfunc)vec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec4_sq_item<bool>, // sq_item
	0,
	(ssizeobjargproc)vec4_sq_ass_item<bool>, // sq_ass_item
	0,
	(objobjproc)vec_contains<4, bool>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyNumberMethods hbvec4NumMethods = {
	(binaryfunc)bvec_add<4>, //nb_add
	0, //nb_subtract
	(binaryfunc)bvec_mul<4>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)bvec_neg<4>, //nb_negative
	0, //nb_positive
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
	0, //nb_int
	(binaryfunc)bvec_iadd<4>, //nb_inplace_add
	0, //nb_inplace_subtract
	(binaryfunc)bvec_imul<4>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	0,
	0, //nb_inplace_floor_divide
	0, //nb_inplace_true_divide
	0, //nb_index
	0, //nb_matrix_multiply
	0, //nb_inplace_matrix_multiply
};
PyTypeObject hbvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"bvec4Iter",             /* tp_name */
	sizeof(vecIter<4, bool>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<4, bool>, /* tp_dealloc */
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
	"bvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec4Iter_next<bool>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<4, bool>,                 /* tp_new */
};

PyGLMTypeObject hbvec4GLMType = _PyGLM_TYPE_DEF_BVEC(4);

PyTypeObject& hbvec4Type = *((PyTypeObject*)&hbvec4GLMType);
