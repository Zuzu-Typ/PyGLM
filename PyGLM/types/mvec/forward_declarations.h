#pragma once

#include "../forward_declarations.h"

template<int L, typename T>
int mvec_getbuffer(mvec<L, T>* self, Py_buffer* view, int flags);

void mvec_releasebuffer(PyObject* self, Py_buffer* view);

template<typename T>
PyObject* mvec2_to_list(mvec<2, T>* self, PyObject*);
template<typename T>
PyObject* mvec3_to_list(mvec<3, T>* self, PyObject*);
template<typename T>
PyObject* mvec4_to_list(mvec<4, T>* self, PyObject*);

template<typename T>
PyObject* mvec2_to_tuple(mvec<2, T>* self, PyObject*);
template<typename T>
PyObject* mvec3_to_tuple(mvec<3, T>* self, PyObject*);
template<typename T>
PyObject* mvec4_to_tuple(mvec<4, T>* self, PyObject*);

template<typename T>
PyObject* mvec2_setstate(mvec<2, T>* self, PyObject* state);
template<typename T>
PyObject* mvec3_setstate(mvec<3, T>* self, PyObject* state);
template<typename T>
PyObject* mvec4_setstate(mvec<4, T>* self, PyObject* state);

template<int L, typename T>
PyObject* mvec_new(PyTypeObject* type, PyObject*, PyObject*);

template<int L, typename T>
int mvec_init(mvec<L, T>* self, PyObject* args, PyObject* kwds);

template<int L>
Py_ssize_t mvec_len(PyObject* self);

template<typename T>
PyObject* mvec2_sq_item(mvec<2, T> * self, Py_ssize_t index);
template<typename T>
PyObject* mvec3_sq_item(mvec<3, T> * self, Py_ssize_t index);
template<typename T>
PyObject* mvec4_sq_item(mvec<4, T> * self, Py_ssize_t index);

template<typename T>
int mvec2_sq_ass_item(mvec<2, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
int mvec3_sq_ass_item(mvec<3, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
int mvec4_sq_ass_item(mvec<4, T> * self, Py_ssize_t index, PyObject * value);

template<int L, typename T>
int mvec_contains(mvec<L, T> * self, PyObject * value);

template<int L, typename T>
PyObject * mvec_add(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * mvec_sub(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * mvec_mul(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * mvec_mod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * mvec_divmod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject* mvec_lshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* mvec_rshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* mvec_and(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* mvec_xor(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* mvec_or(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * mvec_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
PyObject * mvec_neg(mvec<L, T> *obj);

template<int L, typename T>
PyObject * mvec_pos(mvec<L, T> *obj);

template<int L, typename T>
PyObject * mvec_abs(mvec<L, T> *obj);

template<int L, typename T>
PyObject* mvec_invert(mvec<L, T>* obj);

PyObject* mvec_matmul(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * mvec_iadd(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * mvec_isub(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * mvec_imul(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * mvec_imod(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * mvec_ipow(mvec<L, T>* self, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
PyObject * mvec_floordiv(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * mvec_div(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * mvec_ifloordiv(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * mvec_idiv(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject* mvec_imatmul(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* mvec_ilshift(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* mvec_irshift(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* mvec_iand(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* mvec_ixor(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* mvec_ior(mvec<L, T>* self, PyObject* obj);

void mvec_dealloc(PyObject* self);

template<int L, typename T>
PyObject* mvec_copy(PyObject* self, PyObject*);

template<int L, typename T>
PyObject* mvec_deepcopy(PyObject* self, PyObject* memo);

template<typename T>
PyObject* mvec2_str(mvec<2, T>* self);
template<typename T>
PyObject* mvec3_str(mvec<3, T>* self);
template<typename T>
PyObject* mvec4_str(mvec<4, T>* self);

template<int L, typename T>
PyObject* mvec_getattr(PyObject* obj, PyObject* name);

template<int L, typename T>
int mvec_setattr(PyObject* obj, PyObject* name, PyObject* value);

template<int L, typename T>
PyObject* mvec_richcompare(mvec<L, T>* self, PyObject* other, int comp_type);

template<int L, typename T>
PyObject* mvec_geniter(mvec<L, T>* self);

template<int L, typename T>
void mvecIter_dealloc(mvecIter<L, T> *rgstate);

template<typename T>
PyObject* mvec2Iter_next(mvecIter<2, T> *rgstate);
template<typename T>
PyObject* mvec3Iter_next(mvecIter<3, T> *rgstate);
template<typename T>
PyObject* mvec4Iter_next(mvecIter<4, T> *rgstate);

template<int L, typename T>
PyObject* mvecIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<int L, typename T>
Py_hash_t mvec_hash(mvec<L, T>* self, PyObject*);

#define _PyGLM_TYPE_DEF_DMVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.dmvec" #L,             /* tp_name */ \
		sizeof(mvec<L, double>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mvec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mvec ## L ## _str<double>,                         /* tp_repr */ \
		& hdmvec ## L ## NumMethods,             /* tp_as_number */ \
		& hdmvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)mvec_hash<L, double>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mvec ## L ## _str<double>,                         /* tp_str */ \
		(getattrofunc)mvec_getattr<2, double>,                         /* tp_getattro */ \
		(setattrofunc)mvec_setattr<2, double>,                         /* tp_setattro */ \
		& hdmvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"dmvec" #L "( <dmvec" #L " compatible type(s)> )\n" #L " components mvector of double precision floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mvec_richcompare<L, double>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mvec_geniter<L, double>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hdmvec ## L ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mvec_init<2, double>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mvec_new<2, double>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MVEC, \
L, \
0, \
sizeof(double), \
sizeof(glm::vec<L, double>), \
PyGLM_FS_DOUBLE, \
& hdvec ## L ## Type \
}

#define _PyGLM_TYPE_DEF_FMVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.mvec" #L,             /* tp_name */ \
		sizeof(mvec<L, float>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mvec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mvec ## L ## _str<float>,                         /* tp_repr */ \
		& hfmvec ## L ## NumMethods,             /* tp_as_number */ \
		& hfmvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)mvec_hash<L, float>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mvec ## L ## _str<float>,                         /* tp_str */ \
		(getattrofunc)mvec_getattr<2, float>,                         /* tp_getattro */ \
		(setattrofunc)mvec_setattr<2, float>,                         /* tp_setattro */ \
		& hfmvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"mvec" #L "( <mvec" #L " compatible type(s)> )\n" #L " components mvector of floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mvec_richcompare<L, float>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mvec_geniter<L, float>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hfmvec ## L ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mvec_init<2, float>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mvec_new<2, float>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MVEC, \
L, \
0, \
sizeof(float), \
sizeof(glm::vec<L, float>), \
PyGLM_FS_FLOAT, \
& hfvec ## L ## Type \
}

#define _PyGLM_TYPE_DEF_IMVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.imvec" #L,             /* tp_name */ \
		sizeof(mvec<L, int32>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mvec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mvec ## L ## _str<int32>,                         /* tp_repr */ \
		& himvec ## L ## NumMethods,             /* tp_as_number */ \
		& himvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)mvec_hash<L, int32>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mvec ## L ## _str<int32>,                         /* tp_str */ \
		(getattrofunc)mvec_getattr<2, int32>,                         /* tp_getattro */ \
		(setattrofunc)mvec_setattr<2, int32>,                         /* tp_setattro */ \
		& himvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"imvec" #L "( <imvec" #L " compatible type(s)> )\n" #L " components mvector of signed integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mvec_richcompare<L, int32>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mvec_geniter<L, int32>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		himvec ## L ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mvec_init<2, int32>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mvec_new<2, int32>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MVEC, \
L, \
0, \
sizeof(int32), \
sizeof(glm::vec<L, int32>), \
PyGLM_FS_INT32, \
& hivec ## L ## Type \
}

#define _PyGLM_TYPE_DEF_UMVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.umvec" #L,             /* tp_name */ \
		sizeof(mvec<L, uint32>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mvec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mvec ## L ## _str<uint32>,                         /* tp_repr */ \
		& humvec ## L ## NumMethods,             /* tp_as_number */ \
		& humvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)mvec_hash<L, uint32>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mvec ## L ## _str<uint32>,                         /* tp_str */ \
		(getattrofunc)mvec_getattr<2, uint32>,                         /* tp_getattro */ \
		(setattrofunc)mvec_setattr<2, uint32>,                         /* tp_setattro */ \
		& humvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"umvec" #L "( <umvec" #L " compatible type(s)> )\n" #L " components mvector of unsigned integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mvec_richcompare<L, uint32>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mvec_geniter<L, uint32>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		humvec ## L ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mvec_init<2, uint32>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mvec_new<2, uint32>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MVEC, \
L, \
0, \
sizeof(uint32), \
sizeof(glm::vec<L, uint32>), \
PyGLM_FS_UINT32, \
& hivec ## L ## Type \
}

