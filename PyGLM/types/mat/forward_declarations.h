#pragma once

#include "../forward_declarations.h"

template<int C>
PyObject* mat_length(PyObject * self, PyObject* arg);

template<int C, int R, typename T>
int mat_getbuffer(mat<C, R, T>* self, Py_buffer* view, int flags);

void mat_releasebuffer(PyObject* self, Py_buffer* view);

template<int C>
Py_ssize_t mat_len(PyObject* self);

template<typename T>
PyObject* mat2x2_mp_item(mat<2, 2, T> * self, PyObject* key);
template<typename T>
PyObject* mat2x3_mp_item(mat<2, 3, T> * self, PyObject* key);
template<typename T>
PyObject* mat2x4_mp_item(mat<2, 4, T> * self, PyObject* key);
template<typename T>
PyObject* mat3x2_mp_item(mat<3, 2, T> * self, PyObject* key);
template<typename T>
PyObject* mat3x3_mp_item(mat<3, 3, T> * self, PyObject* key);
template<typename T>
PyObject* mat3x4_mp_item(mat<3, 4, T> * self, PyObject* key);
template<typename T>
PyObject* mat4x2_mp_item(mat<4, 2, T> * self, PyObject* key);
template<typename T>
PyObject* mat4x3_mp_item(mat<4, 3, T> * self, PyObject* key);
template<typename T>
PyObject* mat4x4_mp_item(mat<4, 4, T> * self, PyObject* key);

template<typename T>
int mat2x2_mp_ass_item(mat<2, 2, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat2x3_mp_ass_item(mat<2, 3, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat2x4_mp_ass_item(mat<2, 4, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat3x2_mp_ass_item(mat<3, 2, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat3x3_mp_ass_item(mat<3, 3, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat3x4_mp_ass_item(mat<3, 4, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat4x2_mp_ass_item(mat<4, 2, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat4x3_mp_ass_item(mat<4, 3, T> * self, PyObject* key, PyObject * value);
template<typename T>
int mat4x4_mp_ass_item(mat<4, 4, T> * self, PyObject* key, PyObject * value);

template<int C, int R, typename T>
int mat_contains(mat<C, R, T> * self, PyObject * value);

template<int C, int R, typename T>
PyObject * matsq_add(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * mat_add(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * matsq_sub(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * mat_sub(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * mat_mul(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * mat_neg(mat<C, R, T> *obj);

template<int C, int R, typename T>
PyObject * mat_pos(mat<C, R, T> *obj);

template<int C, int R, typename T>
PyObject * mat_abs(mat<C, R, T> *obj);

PyObject* mat_matmul(PyObject* obj1, PyObject* obj2);

template<int C, int R, typename T>
PyObject * matsq_iadd(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject * mat_iadd(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject * matsq_isub(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject * mat_isub(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject * mat_imul(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject * mat_div(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * matsq_div(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
PyObject * matsq_idiv(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject * mat_idiv(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
PyObject* mat_imatmul(mat<C, R, T>* self, PyObject* obj);

void mat_dealloc(PyObject* self);

template<typename T>
PyObject* mat2x2_str(mat<2, 2, T>* self);
template<typename T>
PyObject* mat2x3_str(mat<2, 3, T>* self);
template<typename T>
PyObject* mat2x4_str(mat<2, 4, T>* self);
template<typename T>
PyObject* mat3x2_str(mat<3, 2, T>* self);
template<typename T>
PyObject* mat3x3_str(mat<3, 3, T>* self);
template<typename T>
PyObject* mat3x4_str(mat<3, 4, T>* self);
template<typename T>
PyObject* mat4x2_str(mat<4, 2, T>* self);
template<typename T>
PyObject* mat4x3_str(mat<4, 3, T>* self);
template<typename T>
PyObject* mat4x4_str(mat<4, 4, T>* self);

template<typename T>
PyObject* mat2x2_repr(mat<2, 2, T>* self);
template<typename T>
PyObject* mat2x3_repr(mat<2, 3, T>* self);
template<typename T>
PyObject* mat2x4_repr(mat<2, 4, T>* self);
template<typename T>
PyObject* mat3x2_repr(mat<3, 2, T>* self);
template<typename T>
PyObject* mat3x3_repr(mat<3, 3, T>* self);
template<typename T>
PyObject* mat3x4_repr(mat<3, 4, T>* self);
template<typename T>
PyObject* mat4x2_repr(mat<4, 2, T>* self);
template<typename T>
PyObject* mat4x3_repr(mat<4, 3, T>* self);
template<typename T>
PyObject* mat4x4_repr(mat<4, 4, T>* self);

template<int C, int R, typename T>
PyObject* mat_richcompare(mat<C, R, T>* self, PyObject* other, int comp_type);

template<int C, int R, typename T>
PyObject* mat_geniter(mat<C, R, T>* self);

template<typename T>
int mat2x2_init(mat<2, 2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat2x3_init(mat<2, 3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat2x4_init(mat<2, 4, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat3x2_init(mat<3, 2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat3x3_init(mat<3, 3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat3x4_init(mat<3, 4, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat4x2_init(mat<4, 2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat4x3_init(mat<4, 3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
int mat4x4_init(mat<4, 4, T> *self, PyObject *args, PyObject *kwds);

template<int C, int R, typename T>
PyObject* mat_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

template<int C, int R, typename T>
void matIter_dealloc(matIter<C, R, T> *rgstate);

template<int C, int R, typename T>
PyObject* matIter_next(matIter<C, R, T> *rgstate);

template<int C, int R, typename T>
PyObject* matIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<int C, int R, typename T>
PyObject* mat_from_bytes(PyObject*, PyObject* arg);

template<int C, int R, typename T>
Py_hash_t mat_hash(mat<C, R, T>* self, PyObject*);

template<int C, int R, typename T>
PyObject* mat_to_list(mat<C, R, T>* self, PyObject*);

template<int C, int R, typename T>
PyObject* mat_to_tuple(mat<C, R, T>* self, PyObject*);

template<int C, int R, typename T>
PyObject* mat_setstate(mat<C, R, T>* self, PyObject* state);

#define _PyGLM_TYPE_DEF_DMAT(C, R) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.dmat" #C "x" #R,             /* tp_name */ \
		sizeof(mat<C, R, double>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mat_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mat ## C ## x ## R ## _repr<double>,                         /* tp_repr */ \
		& hdmat ## C ## x ## R ## NumMethods,             /* tp_as_number */ \
		& hdmat ## C ## x ## R ## SeqMethods,                         /* tp_as_sequence */ \
		& hdmat ## C ## x ## R ## MapMethods,                         /* tp_as_mapping */ \
		(hashfunc)mat_hash<C, R, double>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mat ## C ## x ## R ## _str<double>,                         /* tp_str */ \
		0,                         /* tp_getattro */ \
		0,                         /* tp_setattro */ \
		& hdmat ## C ## x ## R ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"dmat" #C "x" #R "( <dmat" #C "x" #R " compatible type(s)> )\n" #C " columns of " #R " components matrix of double precision floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mat_richcompare<C, R, double>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mat_geniter<C, R, double>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hdmat ## C ## x ## R ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mat ## C ## x ## R ## _init<double>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mat_new<C, R, double>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MAT, \
C, \
R, \
sizeof(double), \
sizeof(glm::mat<C, R, double>), \
PyGLM_FS_DOUBLE \
}

#define _PyGLM_TYPE_DEF_FMAT(C, R) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.mat" #C "x" #R,             /* tp_name */ \
		sizeof(mat<C, R, float>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mat_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mat ## C ## x ## R ## _repr<float>,                         /* tp_repr */ \
		& hfmat ## C ## x ## R ## NumMethods,             /* tp_as_number */ \
		& hfmat ## C ## x ## R ## SeqMethods,                         /* tp_as_sequence */ \
		& hfmat ## C ## x ## R ## MapMethods,                         /* tp_as_mapping */ \
		(hashfunc)mat_hash<C, R, float>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mat ## C ## x ## R ## _str<float>,                         /* tp_str */ \
		0,                         /* tp_getattro */ \
		0,                         /* tp_setattro */ \
		& hfmat ## C ## x ## R ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"mat" #C "x" #R "( <mat" #C "x" #R " compatible type(s)> )\n" #C " columns of " #R " components matrix of floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mat_richcompare<C, R, float>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mat_geniter<C, R, float>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hfmat ## C ## x ## R ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mat ## C ## x ## R ## _init<float>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mat_new<C, R, float>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MAT, \
C, \
R, \
sizeof(float), \
sizeof(glm::mat<C, R, float>), \
PyGLM_FS_FLOAT \
}

#define _PyGLM_TYPE_DEF_IMAT(C, R) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.imat" #C "x" #R,             /* tp_name */ \
		sizeof(mat<C, R, int32>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mat_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mat ## C ## x ## R ## _repr<int32>,                         /* tp_repr */ \
		& himat ## C ## x ## R ## NumMethods,             /* tp_as_number */ \
		& himat ## C ## x ## R ## SeqMethods,                         /* tp_as_sequence */ \
		& himat ## C ## x ## R ## MapMethods,                         /* tp_as_mapping */ \
		(hashfunc)mat_hash<C, R, int32>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mat ## C ## x ## R ## _str<int32>,                         /* tp_str */ \
		0,                         /* tp_getattro */ \
		0,                         /* tp_setattro */ \
		& himat ## C ## x ## R ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"imat" #C "x" #R "( <imat" #C "x" #R " compatible type(s)> )\n" #C " columns of " #R " components matrix of signed integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mat_richcompare<C, R, int32>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mat_geniter<C, R, int32>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		himat ## C ## x ## R ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mat ## C ## x ## R ## _init<int32>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mat_new<C, R, int32>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MAT, \
C, \
R, \
sizeof(int32), \
sizeof(glm::mat<C, R, int32>), \
PyGLM_FS_INT32 \
}

#define _PyGLM_TYPE_DEF_UMAT(C, R) { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.umat" #C "x" #R,             /* tp_name */ \
		sizeof(mat<C, R, uint32>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)mat_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)mat ## C ## x ## R ## _repr<uint32>,                         /* tp_repr */ \
		& humat ## C ## x ## R ## NumMethods,             /* tp_as_number */ \
		& humat ## C ## x ## R ## SeqMethods,                         /* tp_as_sequence */ \
		& humat ## C ## x ## R ## MapMethods,                         /* tp_as_mapping */ \
		(hashfunc)mat_hash<C, R, uint32>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)mat ## C ## x ## R ## _str<uint32>,                         /* tp_str */ \
		0,                         /* tp_getattro */ \
		0,                         /* tp_setattro */ \
		& humat ## C ## x ## R ## BufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"umat" #C "x" #R "( <umat" #C "x" #R " compatible type(s)> )\n" #C " columns of " #R " components matrix of unsigned integers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)mat_richcompare<C, R, uint32>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)mat_geniter<C, R, uint32>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		humat ## C ## x ## R ## _methods,             /* tp_methods */ \
		0,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)mat ## C ## x ## R ## _init<uint32>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)mat_new<C, R, uint32>,                 /* tp_new */ \
}, \
PyGLM_TYPE_MAT, \
C, \
R, \
sizeof(uint32), \
sizeof(glm::mat<C, R, uint32>), \
PyGLM_FS_UINT32 \
}


