#pragma once

#include "../forward_declarations.h"

PyObject* qua_length(PyObject * self, PyObject* arg);

template<typename T>
int qua_getbuffer(qua<T>* self, Py_buffer* view, int flags);

void qua_releasebuffer(PyObject* self, Py_buffer* view);

Py_ssize_t qua_len(PyObject* self);

template<typename T>
PyObject* qua_sq_item(qua<T> * self, Py_ssize_t index);

template<typename T>
int qua_sq_ass_item(qua<T> * self, Py_ssize_t index, PyObject * value);

template<typename T>
int qua_contains(qua<T> * self, PyObject * value);

template<typename T>
PyObject * qua_add(PyObject *obj1, PyObject *obj2);

template<typename T>
PyObject * qua_sub(PyObject *obj1, PyObject *obj2);

template<typename T>
PyObject * qua_mul(PyObject *obj1, PyObject *obj2);

template<typename T>
PyObject * qua_neg(qua<T> *obj);

template<typename T>
PyObject * qua_pos(qua<T> *obj);

PyObject* qua_matmul(PyObject* obj1, PyObject* obj2);

template<typename T>
PyObject * qua_iadd(qua<T>* self, PyObject *obj);

template<typename T>
PyObject * qua_isub(qua<T>* self, PyObject *obj);

template<typename T>
PyObject * qua_imul(qua<T>* self, PyObject *obj);

template<typename T>
PyObject * qua_div(PyObject *obj1, PyObject *obj2);

template<typename T>
PyObject * qua_idiv(qua<T>* self, PyObject *obj);

template<typename T>
PyObject* qua_imatmul(qua<T>* self, PyObject* obj);

void qua_dealloc(PyObject* self);

template<typename T>
PyObject* qua_str(qua<T>* self);

template<typename T>
PyObject* qua_repr(qua<T>* self);

template<typename T>
PyObject* qua_richcompare(qua<T>* self, PyObject* other, int comp_type);

template<typename T>
PyObject* qua_geniter(qua<T>* self);

template<typename T>
int qua_init(qua<T> *self, PyObject *args, PyObject *kwds);

template<typename T>
PyObject* qua_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

template<typename T>
void quaIter_dealloc(quaIter<T> *rgstate);

template<typename T>
PyObject* quaIter_next(quaIter<T> *rgstate);

template<typename T>
PyObject* quaIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<typename T>
PyObject* qua_from_bytes(PyObject*, PyObject* arg);

template<typename T>
Py_hash_t qua_hash(qua<T>* self, PyObject*);

template<typename T>
PyObject* qua_to_list(qua<T>* self, PyObject*);

template<typename T>
PyObject* qua_to_tuple(qua<T>* self, PyObject*);

template<typename T>
PyObject* qua_setstate(qua<T>* self, PyObject* state);

#define _PyGLM_TYPE_DEF_DQUA { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.dquat",             /* tp_name */ \
		sizeof(qua<double>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)qua_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)qua_repr<double>,                         /* tp_repr */ \
		& hdquaNumMethods,             /* tp_as_number */ \
		& hdquaSeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)qua_hash<double>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)qua_str<double>,                         /* tp_str */ \
		0,                         /* tp_getattro */ \
		0,                         /* tp_setattro */ \
		& hdquaBufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"dquat( <dquat compatible type(s)> )\n4 components quaternion of double numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)qua_richcompare<double>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)qua_geniter<double>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hdqua_methods,             /* tp_methods */ \
		hdqua_members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)qua_init<double>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)qua_new<double>,                 /* tp_new */ \
}, \
PyGLM_TYPE_QUA, \
4, \
0, \
sizeof(double), \
sizeof(glm::qua<double>), \
PyGLM_FS_DOUBLE \
}

#define _PyGLM_TYPE_DEF_FQUA { \
{ \
	PyObject_HEAD_INIT(NULL) \
		"glm.quat",             /* tp_name */ \
		sizeof(qua<float>),             /* tp_basicsize */ \
		0,                         /* tp_itemsize */ \
		(destructor)qua_dealloc, /* tp_dealloc */ \
		0,                         /* tp_print */ \
		0,                         /* tp_getattr */ \
		0,                         /* tp_setattr */ \
		0,                         /* tp_reserved */ \
		(reprfunc)qua_repr<float>,                         /* tp_repr */ \
		& hfquaNumMethods,             /* tp_as_number */ \
		& hfquaSeqMethods,                         /* tp_as_sequence */ \
		0,                         /* tp_as_mapping */ \
		(hashfunc)qua_hash<float>,                         /* tp_hash  */ \
		0,                         /* tp_call */ \
		(reprfunc)qua_str<float>,                         /* tp_str */ \
		0,                         /* tp_getattro */ \
		0,                         /* tp_setattro */ \
		& hfquaBufferMethods,                         /* tp_as_buffer */ \
		Py_TPFLAGS_DEFAULT | \
		Py_TPFLAGS_BASETYPE,   /* tp_flags */ \
		"quat( <quat compatible type(s)> )\n4 components quaternion of floating-point numbers.",           /* tp_doc */ \
		0,                         /* tp_traverse */ \
		0,                         /* tp_clear */ \
		(richcmpfunc)qua_richcompare<float>,                         /* tp_richcompare */ \
		0,                         /* tp_weaklistoffset */ \
		(getiterfunc)qua_geniter<float>,                         /* tp_iter */ \
		0,                         /* tp_iternext */ \
		hfqua_methods,             /* tp_methods */ \
		hfqua_members,             /* tp_members */ \
		0,           			/* tp_getset */ \
		0,                         /* tp_base */ \
		0,                         /* tp_dict */ \
		0,                         /* tp_descr_get */ \
		0,                         /* tp_descr_set */ \
		0,                         /* tp_dictoffset */ \
		(initproc)qua_init<float>,      /* tp_init */ \
		0,                         /* tp_alloc */ \
		(newfunc)qua_new<float>,                 /* tp_new */ \
}, \
PyGLM_TYPE_QUA, \
4, \
0, \
sizeof(float), \
sizeof(glm::qua<float>), \
PyGLM_FS_FLOAT \
}
