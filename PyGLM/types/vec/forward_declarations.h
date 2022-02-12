#pragma once

#include "../forward_declarations.h"

template<int L, typename T>
int vec_getbuffer(vec<L, T>* self, Py_buffer* view, int flags);

void vec_releasebuffer(PyObject* self, Py_buffer* view);

template<typename T>
PyObject* vec1_to_list(vec<1, T>* self, PyObject*);
template<typename T>
PyObject* vec2_to_list(vec<2, T>* self, PyObject*);
template<typename T>
PyObject* vec3_to_list(vec<3, T>* self, PyObject*);
template<typename T>
PyObject* vec4_to_list(vec<4, T>* self, PyObject*);

template<typename T>
PyObject* vec1_to_tuple(vec<1, T>* self, PyObject*);
template<typename T>
PyObject* vec2_to_tuple(vec<2, T>* self, PyObject*);
template<typename T>
PyObject* vec3_to_tuple(vec<3, T>* self, PyObject*);
template<typename T>
PyObject* vec4_to_tuple(vec<4, T>* self, PyObject*);

template<typename T>
PyObject* vec1_setstate(vec<1, T>* self, PyObject* state);
template<typename T>
PyObject* vec2_setstate(vec<2, T>* self, PyObject* state);
template<typename T>
PyObject* vec3_setstate(vec<3, T>* self, PyObject* state);
template<typename T>
PyObject* vec4_setstate(vec<4, T>* self, PyObject* state);

template<int L>
Py_ssize_t vec_len(PyObject* self);

template<typename T>
PyObject* vec1_sq_item(vec<1, T> * self, Py_ssize_t index);
template<typename T>
PyObject* vec2_sq_item(vec<2, T> * self, Py_ssize_t index);
template<typename T>
PyObject* vec3_sq_item(vec<3, T> * self, Py_ssize_t index);
template<typename T>
PyObject* vec4_sq_item(vec<4, T> * self, Py_ssize_t index);

template<typename T>
int vec1_sq_ass_item(vec<1, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
int vec2_sq_ass_item(vec<2, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
int vec3_sq_ass_item(vec<3, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
int vec4_sq_ass_item(vec<4, T> * self, Py_ssize_t index, PyObject * value);

template<int L, typename T>
int vec_contains(vec<L, T> * self, PyObject * value);

template<int L, typename T>
PyObject * vec_add(PyObject *obj1, PyObject *obj2);

template<int L>
PyObject* bvec_add(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * vec_sub(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * vec_mul(PyObject *obj1, PyObject *obj2);

template<int L>
PyObject* bvec_mul(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * vec_mod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * vec_divmod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject* vec_lshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* vec_rshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* vec_and(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject* vec_xor(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * vec_or(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * vec_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
PyObject * vec_neg(vec<L, T> *obj);

template<int L>
PyObject* bvec_neg(vec<L, bool>* obj);

template<int L, typename T>
PyObject * vec_pos(vec<L, T> *obj);

template<int L, typename T>
PyObject * vec_abs(vec<L, T> *obj);

template<int L, typename T>
PyObject* vec_invert(vec<L, T>* obj);

PyObject* vec_matmul(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
PyObject * vec_iadd(vec<L, T>* self, PyObject *obj);

template<int L>
PyObject* bvec_iadd(vec<L, bool>* self, PyObject* obj);

template<int L, typename T>
PyObject * vec_isub(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * vec_imul(vec<L, T>* self, PyObject *obj);

template<int L>
PyObject* bvec_imul(vec<L, bool>* self, PyObject* obj);

template<int L, typename T>
PyObject * vec_imod(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject* vec_ilshift(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* vec_irshift(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* vec_iand(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* vec_ixor(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject* vec_ior(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
PyObject * vec_ipow(vec<L, T>* self, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
PyObject * vec_floordiv(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * vec_div(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
PyObject * vec_ifloordiv(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject * vec_idiv(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
PyObject* vec_imatmul(vec<L, T>* self, PyObject* obj);

void vec_dealloc(PyObject* self);

template<typename T>
PyObject* vec1_str(vec<1, T>* self);
template<typename T>
PyObject* vec2_str(vec<2, T>* self);
template<typename T>
PyObject* vec3_str(vec<3, T>* self);
template<typename T>
PyObject* vec4_str(vec<4, T>* self);

template<typename T>
PyObject* vec1_repr(vec<1, T>* self);
template<typename T>
PyObject* vec2_repr(vec<2, T>* self);
template<typename T>
PyObject* vec3_repr(vec<3, T>* self);
template<typename T>
PyObject* vec4_repr(vec<4, T>* self);

template<int L, typename T>
PyObject* vec_getattr(PyObject* obj, PyObject* name);
template<int L, typename T>
int vec_setattr(PyObject* obj, PyObject* name, PyObject* value);

template<int L, typename T>
PyObject* vec_richcompare(vec<L, T>* self, PyObject* other, int comp_type);

template<int L, typename T>
PyObject* vec_geniter(vec<L, T>* self);

template<typename T>
int vec1_init(vec<1, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int vec2_init(vec<2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int vec3_init(vec<3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int vec4_init(vec<4, T> *self, PyObject *args, PyObject *kwds);

template<int L, typename T>
PyObject* vec_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

template<int L, typename T>
void vecIter_dealloc(vecIter<L, T> *rgstate);

template<typename T>
PyObject* vec1Iter_next(vecIter<1, T> *rgstate);
template<typename T>
PyObject* vec2Iter_next(vecIter<2, T> *rgstate);
template<typename T>
PyObject* vec3Iter_next(vecIter<3, T> *rgstate);
template<typename T>
PyObject* vec4Iter_next(vecIter<4, T> *rgstate);

template<int L, typename T>
PyObject* vecIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<int L, typename T>
PyObject* vec_from_bytes(PyObject*, PyObject* arg);

template<int L, typename T>
Py_hash_t vec_hash(vec<L, T>* self, PyObject*);

#define _PyGLM_TYPE_DEF_DVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.dvec" #L,             /* tp_name */ \
		sizeof(vec<L, double>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<double>,                         /* tp_repr */ \
		& hdvec ## L ## NumMethods,             /* tp_as_number */ \
		& hdvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, double>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<double>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, double>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, double>,                         /* tp_setattro */ \
		& hdvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"dvec" #L "( <vec" #L " compatible type(s)> )\n" #L " components vector of double precision floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, double>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, double>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hdvec ## L ## _methods,             /* tp_methods */ \
		hdvec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<double>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, double>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(double), \
sizeof(glm::vec<L, double>), \
PyGLM_FS_DOUBLE \
}

#define _PyGLM_TYPE_DEF_FVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.vec" #L,             /* tp_name */ \
		sizeof(vec<L, float>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<float>,                         /* tp_repr */ \
		& hfvec ## L ## NumMethods,             /* tp_as_number */ \
		& hfvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, float>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<float>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, float>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, float>,                         /* tp_setattro */ \
		& hfvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"vec" #L "( <vec" #L " compatible type(s)> )\n" #L " components vector of floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, float>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, float>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hfvec ## L ## _methods,             /* tp_methods */ \
		hfvec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<float>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, float>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(float), \
sizeof(glm::vec<L, float>), \
PyGLM_FS_FLOAT \
}

#define _PyGLM_TYPE_DEF_BVEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.bvec" #L,             /* tp_name */ \
		sizeof(vec<L, bool>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<bool>,                         /* tp_repr */ \
		& hbvec ## L ## NumMethods,             /* tp_as_number */ \
		& hbvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, bool>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<bool>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, bool>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, bool>,                         /* tp_setattro */ \
		& hbvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"bvec" #L "( <bvec" #L " compatible type(s)> )\n" #L " components vector of boolean values.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, bool>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, bool>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hbvec ## L ## _methods,             /* tp_methods */ \
		hbvec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<bool>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, bool>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(bool), \
sizeof(glm::vec<L, bool>), \
PyGLM_FS_BOOL \
}

#define _PyGLM_TYPE_DEF_I8VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.i8vec" #L,             /* tp_name */ \
		sizeof(vec<L, int8>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<int8>,                         /* tp_repr */ \
		& hi8vec ## L ## NumMethods,             /* tp_as_number */ \
		& hi8vec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, int8>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<int8>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, int8>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, int8>,                         /* tp_setattro */ \
		& hi8vec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"i8vec" #L "( <i8vec" #L " compatible type(s)> )\n" #L " components vector of 8-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, int8>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, int8>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hi8vec ## L ## _methods,             /* tp_methods */ \
		hi8vec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<int8>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, int8>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(int8), \
sizeof(glm::vec<L, int8>), \
PyGLM_FS_INT8 \
}

#define _PyGLM_TYPE_DEF_I16VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.i16vec" #L,             /* tp_name */ \
		sizeof(vec<L, int16>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<int16>,                         /* tp_repr */ \
		& hi16vec ## L ## NumMethods,             /* tp_as_number */ \
		& hi16vec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, int16>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<int16>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, int16>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, int16>,                         /* tp_setattro */ \
		& hi16vec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"i16vec" #L "( <i16vec" #L " compatible type(s)> )\n" #L " components vector of 16-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, int16>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, int16>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hi16vec ## L ## _methods,             /* tp_methods */ \
		hi16vec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<int16>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, int16>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(int16), \
sizeof(glm::vec<L, int16>), \
PyGLM_FS_INT16 \
}

#define _PyGLM_TYPE_DEF_I32VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.ivec" #L,             /* tp_name */ \
		sizeof(vec<L, int32>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<int32>,                         /* tp_repr */ \
		& hivec ## L ## NumMethods,             /* tp_as_number */ \
		& hivec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, int32>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<int32>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, int32>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, int32>,                         /* tp_setattro */ \
		& hivec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"ivec" #L "( <ivec" #L " compatible type(s)> )\n" #L " components vector of 32-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, int32>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, int32>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hivec ## L ## _methods,             /* tp_methods */ \
		hivec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<int32>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, int32>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(int32), \
sizeof(glm::vec<L, int32>), \
PyGLM_FS_INT32 \
}

#define _PyGLM_TYPE_DEF_I64VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.i64vec" #L,             /* tp_name */ \
		sizeof(vec<L, int64>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<int64>,                         /* tp_repr */ \
		& hi64vec ## L ## NumMethods,             /* tp_as_number */ \
		& hi64vec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, int64>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<int64>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, int64>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, int64>,                         /* tp_setattro */ \
		& hi64vec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"i64vec" #L "( <i64vec" #L " compatible type(s)> )\n" #L " components vector of 64-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, int64>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, int64>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hi64vec ## L ## _methods,             /* tp_methods */ \
		hi64vec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<int64>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, int64>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(int64), \
sizeof(glm::vec<L, int64>), \
PyGLM_FS_INT64 \
}

#define _PyGLM_TYPE_DEF_U8VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.u8vec" #L,             /* tp_name */ \
		sizeof(vec<L, uint8>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<uint8>,                         /* tp_repr */ \
		& hu8vec ## L ## NumMethods,             /* tp_as_number */ \
		& hu8vec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, uint8>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<uint8>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, uint8>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, uint8>,                         /* tp_setattro */ \
		& hu8vec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"u8vec" #L "( <u8vec" #L " compatible type(s)> )\n" #L " components vector of unsigned 8-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, uint8>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, uint8>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hu8vec ## L ## _methods,             /* tp_methods */ \
		hu8vec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<uint8>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, uint8>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(uint8), \
sizeof(glm::vec<L, uint8>), \
PyGLM_FS_UINT8 \
}

#define _PyGLM_TYPE_DEF_U16VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.u16vec" #L,             /* tp_name */ \
		sizeof(vec<L, uint16>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<uint16>,                         /* tp_repr */ \
		& hu16vec ## L ## NumMethods,             /* tp_as_number */ \
		& hu16vec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, uint16>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<uint16>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, uint16>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, uint16>,                         /* tp_setattro */ \
		& hu16vec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"u16vec" #L "( <u16vec" #L " compatible type(s)> )\n" #L " components vector of unsigned 16-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, uint16>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, uint16>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hu16vec ## L ## _methods,             /* tp_methods */ \
		hu16vec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<uint16>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, uint16>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(uint16), \
sizeof(glm::vec<L, uint16>), \
PyGLM_FS_UINT16 \
}

#define _PyGLM_TYPE_DEF_U32VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.uvec" #L,             /* tp_name */ \
		sizeof(vec<L, uint32>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<uint32>,                         /* tp_repr */ \
		& huvec ## L ## NumMethods,             /* tp_as_number */ \
		& huvec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, uint32>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<uint32>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, uint32>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, uint32>,                         /* tp_setattro */ \
		& huvec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"uvec" #L "( <uvec" #L " compatible type(s)> )\n" #L " components vector of unsigned 32-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, uint32>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, uint32>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		huvec ## L ## _methods,             /* tp_methods */ \
		huvec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<uint32>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, uint32>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(uint32), \
sizeof(glm::vec<L, uint32>), \
PyGLM_FS_UINT32 \
}

#define _PyGLM_TYPE_DEF_U64VEC(L) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.u64vec" #L,             /* tp_name */ \
		sizeof(vec<L, uint64>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)vec_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)vec ## L ## _repr<uint64>,                         /* tp_repr */ \
		& hu64vec ## L ## NumMethods,             /* tp_as_number */ \
		& hu64vec ## L ## SeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)vec_hash<L, uint64>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)vec ## L ## _str<uint64>,                         /* tp_str */ \
		(getattrofunc)vec_getattr<L, uint64>,                         /* tp_getattro */ \
		(setattrofunc)vec_setattr<L, uint64>,                         /* tp_setattro */ \
		& hu64vec ## L ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"u64vec" #L "( <u64vec" #L " compatible type(s)> )\n" #L " components vector of unsigned 64-bit integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)vec_richcompare<L, uint64>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)vec_geniter<L, uint64>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hu64vec ## L ## _methods,             /* tp_methods */ \
		hu64vec ## L ## _members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)vec ## L ## _init<uint64>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)vec_new<L, uint64>,                 /* tp_new */ \
}, \
PyGLM_TYPE_VEC, \
L, \
0, \
sizeof(uint64), \
sizeof(glm::vec<L, uint64>), \
PyGLM_FS_UINT64 \
}
