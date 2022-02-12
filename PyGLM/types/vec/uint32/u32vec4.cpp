#include "vec4.h"

PyMemberDef huvec4_members[] = {
	{ (char*)"x", T_UINT, offsetof(vec4_uint32_t, super_type.x), 0, (char*)"uvec4.x" },
	{ (char*)"y", T_UINT, offsetof(vec4_uint32_t, super_type.y), 0, (char*)"uvec4.y" },
	{ (char*)"z", T_UINT, offsetof(vec4_uint32_t, super_type.z), 0, (char*)"uvec4.z" },
	{ (char*)"w", T_UINT, offsetof(vec4_uint32_t, super_type.w), 0, (char*)"uvec4.w" },
	{ NULL }  /* Sentinel */
};
PyMethodDef huvec4_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec4_to_tuple<glm::u32>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec4_setstate<glm::u32>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec4_to_list<glm::u32>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec4_to_tuple<glm::u32>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<4, glm::u32>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
PyBufferProcs huvec4BufferMethods = {
	(getbufferproc)vec_getbuffer<4, glm::u32>,
	(releasebufferproc)vec_releasebuffer,
};
PySequenceMethods huvec4SeqMethods = {
	(lenfunc)vec_len<4>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec4_sq_item<glm::u32>, // sq_item
	0,
	(ssizeobjargproc)vec4_sq_ass_item<glm::u32>, // sq_ass_item
	0,
	(objobjproc)vec_contains<4, glm::u32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyNumberMethods huvec4NumMethods = {
	(binaryfunc)vec_add<4, glm::u32>, //nb_add
	(binaryfunc)vec_sub<4, glm::u32>, //nb_subtract
	(binaryfunc)vec_mul<4, glm::u32>, //nb_multiply
	(binaryfunc)vec_mod<4, glm::u32>, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	0, //nb_negative
	(unaryfunc)vec_pos<4, glm::u32>, //nb_positive
	(unaryfunc)vec_abs<4, glm::u32>, //nb_absolute
	0, //nb_bool
	(unaryfunc)vec_invert<4, glm::u32>, //nb_invert
	(binaryfunc)vec_lshift<4, glm::u32>, //nb_lshift
	(binaryfunc)vec_rshift<4, glm::u32>, //nb_rshift
	(binaryfunc)vec_and<4, glm::u32>, //nb_and
	(binaryfunc)vec_xor<4, glm::u32>, //nb_xor
	(binaryfunc)vec_or<4, glm::u32>, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_int
	(binaryfunc)vec_iadd<4, glm::u32>, //nb_inplace_add
	(binaryfunc)vec_isub<4, glm::u32>, //nb_inplace_subtract
	(binaryfunc)vec_imul<4, glm::u32>, //nb_inplace_multiply
	(binaryfunc)vec_imod<4, glm::u32>, //nb_inplace_remainder
	0, //nb_inplace_power
	(binaryfunc)vec_ilshift<4, glm::u32>, //nb_inplace_lshift
	(binaryfunc)vec_irshift<4, glm::u32>, //nb_inplace_rshift
	(binaryfunc)vec_iand<4, glm::u32>, //nb_inplace_and
	(binaryfunc)vec_ixor<4, glm::u32>, //nb_inplace_xor
	(binaryfunc)vec_ior<4, glm::u32>, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)vec_div<4, glm::u32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<4, glm::u32>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<4, glm::u32>, //nb_inplace_matrix_multiply
};
PyTypeObject huvec4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"uvec4Iter",             /* tp_name */
	sizeof(vecIter<4, glm::u32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<4, glm::u32>, /* tp_dealloc */
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
	"uvec4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec4Iter_next<glm::u32>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<4, glm::u32>,                 /* tp_new */
};

PyGLMTypeObject huvec4GLMType = _PyGLM_TYPE_DEF_U32VEC(4);

PyTypeObject& huvec4Type = *((PyTypeObject*)&huvec4GLMType);
