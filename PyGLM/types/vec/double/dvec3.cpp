#include "vec3.h"

#include <structmember.h>

#include <glm/detail/type_vec3.hpp>

#include "../../vec.hpp"
#include "../../vecIter.hpp"

#include "../../PyGLMTypeObject.hpp"

PyMemberDef hdvec3_members[] = {
	{ (char*)"x", T_DOUBLE, offsetof(vec3_double_t, super_type.x), 0, (char*)"dvec3.x" },
	{ (char*)"y", T_DOUBLE, offsetof(vec3_double_t, super_type.y), 0, (char*)"dvec3.y" },
	{ (char*)"z", T_DOUBLE, offsetof(vec3_double_t, super_type.z), 0, (char*)"dvec3.z" },
	{ NULL }  /* Sentinel */
};
PyMethodDef hdvec3_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{ "__getstate__", (PyCFunction)vec3_to_tuple<double>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)vec3_setstate<double>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)vec3_to_list<double>, METH_NOARGS, "Return the components of this vector as a list"},
	{ "to_tuple", (PyCFunction)vec3_to_tuple<double>, METH_NOARGS, "Return the components of this vector as a tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)vec_from_bytes<3, double>, METH_O | METH_STATIC, "Create a vector from a bytes string"},
	{ NULL }  /* Sentinel */
};
PyBufferProcs hdvec3BufferMethods = {
	(getbufferproc)vec_getbuffer<3, double>,
	(releasebufferproc)vec_releasebuffer,
};
PySequenceMethods hdvec3SeqMethods = {
	(lenfunc)vec_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)vec3_sq_item<double>, // sq_item
	0,
	(ssizeobjargproc)vec3_sq_ass_item<double>, // sq_ass_item
	0,
	(objobjproc)vec_contains<3, double>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
PyNumberMethods hdvec3NumMethods = {
	(binaryfunc)vec_add<3, double>, //nb_add
	(binaryfunc)vec_sub<3, double>, //nb_subtract
	(binaryfunc)vec_mul<3, double>, //nb_multiply
	(binaryfunc)vec_mod<3, double>, //nb_remainder
	(binaryfunc)vec_divmod<3, double>, //nb_divmod
	(ternaryfunc)vec_pow<3, double>, //nb_power
	(unaryfunc)vec_neg<3, double>, //nb_negative
	(unaryfunc)vec_pos<3, double>, //nb_positive
	(unaryfunc)vec_abs<3, double>, //nb_absolute
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
	(binaryfunc)vec_iadd<3, double>, //nb_inplace_add
	(binaryfunc)vec_isub<3, double>, //nb_inplace_subtract
	(binaryfunc)vec_imul<3, double>, //nb_inplace_multiply
	(binaryfunc)vec_imod<3, double>, //nb_inplace_remainder
	(ternaryfunc)vec_ipow<3, double>, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	(binaryfunc)vec_floordiv<3, double>, //nb_floor_divide
	(binaryfunc)vec_div<3, double>,
	(binaryfunc)vec_ifloordiv<3, double>, //nb_inplace_floor_divide
	(binaryfunc)vec_idiv<3, double>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)vec_matmul, //nb_matrix_multiply
	(binaryfunc)vec_imatmul<3, double>, //nb_inplace_matrix_multiply
};
PyTypeObject hdvec3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"dvec3Iter",             /* tp_name */
	sizeof(vecIter<3, double>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)vecIter_dealloc<3, double>, /* tp_dealloc */
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
	"dvec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)generic_id,  /* tp_iter */
	(iternextfunc)vec3Iter_next<double>,                         /* tp_iternext */
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
	(newfunc)vecIter_new<3, double>,                 /* tp_new */
};

PyGLMTypeObject hdvec3GLMType = _PyGLM_TYPE_DEF_DVEC(3);

PyTypeObject& hdvec3Type = *((PyTypeObject*)&hdvec3GLMType);
