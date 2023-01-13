#pragma once

#include "../forward_declarations.h"

static PyObject* qua_length(PyObject * self, PyObject* arg);

template<typename T>
static int qua_getbuffer(qua<T>* self, Py_buffer* view, int flags);

void qua_releasebuffer(PyObject* self, Py_buffer* view);

static Py_ssize_t qua_len(PyObject* self);

template<typename T>
static PyObject* qua_sq_item(qua<T> * self, Py_ssize_t index);

template<typename T>
static int qua_sq_ass_item(qua<T> * self, Py_ssize_t index, PyObject * value);

template<typename T>
static int qua_contains(qua<T> * self, PyObject * value);

template<typename T>
static PyObject * qua_add(PyObject *obj1, PyObject *obj2);

template<typename T>
static PyObject * qua_sub(PyObject *obj1, PyObject *obj2);

template<typename T>
static PyObject * qua_mul(PyObject *obj1, PyObject *obj2);

template<typename T>
static PyObject * qua_neg(qua<T> *obj);

template<typename T>
static PyObject * qua_pos(qua<T> *obj);

template<typename T>
static PyObject * qua_iadd(qua<T>* self, PyObject *obj);

template<typename T>
static PyObject * qua_isub(qua<T>* self, PyObject *obj);

template<typename T>
static PyObject * qua_imul(qua<T>* self, PyObject *obj);

template<typename T>
static PyObject * qua_div(PyObject *obj1, PyObject *obj2);

template<typename T>
static PyObject * qua_idiv(qua<T>* self, PyObject *obj);

static void qua_dealloc(PyObject* self);

template<typename T>
static PyObject* qua_str(qua<T>* self);

template<typename T>
static PyObject* qua_repr(qua<T>* self);

template<typename T>
static PyObject* qua_richcompare(qua<T>* self, PyObject* other, int comp_type);

template<typename T>
static PyObject* qua_geniter(qua<T>* self);

template<typename T>
static int qua_init(qua<T> *self, PyObject *args, PyObject *kwds);

template<typename T>
static PyObject* qua_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

template<typename T>
static void quaIter_dealloc(quaIter<T> *rgstate);

template<typename T>
static PyObject* quaIter_next(quaIter<T> *rgstate);

template<typename T>
static PyObject* quaIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<typename T>
static PyObject* qua_to_list(qua<T>* self, PyObject*);

template<typename T>
static PyObject* qua_to_tuple(qua<T>* self, PyObject*);