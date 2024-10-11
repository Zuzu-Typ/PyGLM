#pragma once

#include "../forward_declarations.h"

template<int C>
static PyObject* mat_length(PyObject * self, PyObject* arg);

template<int C, int R, typename T>
static int mat_getbuffer(mat<C, R, T>* self, Py_buffer* view, int flags);

static void mat_releasebuffer(PyObject* self, Py_buffer* view);

template<int C>
static Py_ssize_t mat_len(PyObject* self);

template<typename T>
static PyObject* mat2x2_mp_item(mat<2, 2, T> * self, PyObject* key);
template<typename T>
static PyObject* mat2x3_mp_item(mat<2, 3, T> * self, PyObject* key);
template<typename T>
static PyObject* mat2x4_mp_item(mat<2, 4, T> * self, PyObject* key);
template<typename T>
static PyObject* mat3x2_mp_item(mat<3, 2, T> * self, PyObject* key);
template<typename T>
static PyObject* mat3x3_mp_item(mat<3, 3, T> * self, PyObject* key);
template<typename T>
static PyObject* mat3x4_mp_item(mat<3, 4, T> * self, PyObject* key);
template<typename T>
static PyObject* mat4x2_mp_item(mat<4, 2, T> * self, PyObject* key);
template<typename T>
static PyObject* mat4x3_mp_item(mat<4, 3, T> * self, PyObject* key);
template<typename T>
static PyObject* mat4x4_mp_item(mat<4, 4, T> * self, PyObject* key);

template<typename T>
static int mat2x2_mp_ass_item(mat<2, 2, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat2x3_mp_ass_item(mat<2, 3, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat2x4_mp_ass_item(mat<2, 4, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat3x2_mp_ass_item(mat<3, 2, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat3x3_mp_ass_item(mat<3, 3, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat3x4_mp_ass_item(mat<3, 4, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat4x2_mp_ass_item(mat<4, 2, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat4x3_mp_ass_item(mat<4, 3, T> * self, PyObject* key, PyObject * value);
template<typename T>
static int mat4x4_mp_ass_item(mat<4, 4, T> * self, PyObject* key, PyObject * value);

template<int C, int R, typename T>
static int mat_contains(mat<C, R, T> * self, PyObject * value);

template<int C, int R, typename T>
static PyObject * matsq_add(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * mat_add(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * matsq_sub(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * mat_sub(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * mat_mul(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * mat_neg(mat<C, R, T> *obj);

template<int C, int R, typename T>
static PyObject * mat_pos(mat<C, R, T> *obj);

template<int C, int R, typename T>
static PyObject * mat_abs(mat<C, R, T> *obj);

static PyObject* mat_matmul(PyObject* obj1, PyObject* obj2);

template<int C, int R, typename T>
static PyObject * matsq_iadd(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject * mat_iadd(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject * matsq_isub(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject * mat_isub(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject * mat_imul(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject * mat_div(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * matsq_div(PyObject *obj1, PyObject *obj2);

template<int C, int R, typename T>
static PyObject * matsq_idiv(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject * mat_idiv(mat<C, R, T>* self, PyObject *obj);

template<int C, int R, typename T>
static PyObject* mat_imatmul(mat<C, R, T>* self, PyObject* obj);

static void mat_dealloc(PyObject* self);

template<typename T>
static PyObject* mat2x2_str(mat<2, 2, T>* self);
template<typename T>
static PyObject* mat2x3_str(mat<2, 3, T>* self);
template<typename T>
static PyObject* mat2x4_str(mat<2, 4, T>* self);
template<typename T>
static PyObject* mat3x2_str(mat<3, 2, T>* self);
template<typename T>
static PyObject* mat3x3_str(mat<3, 3, T>* self);
template<typename T>
static PyObject* mat3x4_str(mat<3, 4, T>* self);
template<typename T>
static PyObject* mat4x2_str(mat<4, 2, T>* self);
template<typename T>
static PyObject* mat4x3_str(mat<4, 3, T>* self);
template<typename T>
static PyObject* mat4x4_str(mat<4, 4, T>* self);

template<typename T>
static PyObject* mat2x2_repr(mat<2, 2, T>* self);
template<typename T>
static PyObject* mat2x3_repr(mat<2, 3, T>* self);
template<typename T>
static PyObject* mat2x4_repr(mat<2, 4, T>* self);
template<typename T>
static PyObject* mat3x2_repr(mat<3, 2, T>* self);
template<typename T>
static PyObject* mat3x3_repr(mat<3, 3, T>* self);
template<typename T>
static PyObject* mat3x4_repr(mat<3, 4, T>* self);
template<typename T>
static PyObject* mat4x2_repr(mat<4, 2, T>* self);
template<typename T>
static PyObject* mat4x3_repr(mat<4, 3, T>* self);
template<typename T>
static PyObject* mat4x4_repr(mat<4, 4, T>* self);

template<int C, int R, typename T>
static PyObject* mat_richcompare(mat<C, R, T>* self, PyObject* other, int comp_type);

template<int C, int R, typename T>
static PyObject* mat_geniter(mat<C, R, T>* self);

template<typename T>
static int mat2x2_init(mat<2, 2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat2x3_init(mat<2, 3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat2x4_init(mat<2, 4, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat3x2_init(mat<3, 2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat3x3_init(mat<3, 3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat3x4_init(mat<3, 4, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat4x2_init(mat<4, 2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat4x3_init(mat<4, 3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int mat4x4_init(mat<4, 4, T> *self, PyObject *args, PyObject *kwds);

template<int C, int R, typename T>
static PyObject* mat_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

template<int C, int R, typename T>
static void matIter_dealloc(matIter<C, R, T> *rgstate);

template<int C, int R, typename T>
static PyObject* matIter_next(matIter<C, R, T> *rgstate);

template<int C, int R, typename T>
static PyObject* matIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<int C, int R, typename T>
static PyObject* mat_from_bytes(PyObject*, PyObject* arg);

template<int C, int R, typename T>
static Py_hash_t mat_hash(mat<C, R, T>* self, PyObject*);

template<int C, int R, typename T>
static PyObject* mat_to_list(mat<C, R, T>* self, PyObject*);

template<int C, int R, typename T>
static PyObject* mat_to_tuple(mat<C, R, T>* self, PyObject*);

template<int C, int R, typename T>
static PyObject* mat_setstate(mat<C, R, T>* self, PyObject* state);