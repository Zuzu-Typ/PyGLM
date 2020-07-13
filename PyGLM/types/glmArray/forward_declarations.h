#pragma once

#include "../forward_declarations.h"


static int glmArray_getbuffer(glmArray* self, Py_buffer* view, int flags);

void glmArray_releasebuffer(PyObject* self, Py_buffer* view);


static PyObject* glmArray_to_list(glmArray* self, PyObject*);


static PyObject* glmArray_to_tuple(glmArray* self, PyObject*);

static PyObject* glmArray_getPtr(glmArray* self, void*);

static PyObject* glmArray_getDtype(glmArray* self, void*);

static Py_ssize_t glmArray_len(glmArray* self);

static PyObject* glmArray_concat(PyObject* obj1, PyObject* obj2);

static PyObject* glmArray_repeat(glmArray* self, Py_ssize_t count);

static PyObject* glmArray_inplace_concat(glmArray* self, PyObject* obj);

static PyObject* glmArray_inplace_repeat(glmArray* self, Py_ssize_t count);


static PyObject* glmArray_sq_item(glmArray * self, Py_ssize_t index);

static int glmArray_sq_ass_item(glmArray * self, Py_ssize_t index, PyObject * value);


static PyObject* glmArray_mp_subscript(glmArray* self, PyObject* key);

static int glmArray_mp_ass_subscript(glmArray* self, PyObject* key, PyObject* value);

static int glmArray_contains(glmArray * self, PyObject * value);

static void glmArray_dealloc(glmArray* self);


static PyObject* glmArray_str(glmArray* self);


static PyObject* glmArray_repr(glmArray* self);


static PyObject* glmArray_richcompare(glmArray* self, PyObject* other, int comp_type);


static PyObject* glmArray_geniter(glmArray* self);


static int glmArray_init(glmArray *self, PyObject *args, PyObject *kwds);


static PyObject* glmArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds);


static void glmArrayIter_dealloc(glmArrayIter *rgstate);


static PyObject* glmArrayIter_next(glmArrayIter *rgstate);


static PyObject* glmArrayIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

static Py_hash_t array_hash(glmArray* self, PyObject*);