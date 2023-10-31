#pragma once

#include "../forward_declarations.h"

template<int L, typename T>
static int vec_getbuffer(vec<L, T>* self, Py_buffer* view, int flags);

static void vec_releasebuffer(PyObject* self, Py_buffer* view);

template<typename T>
static PyObject* vec1_to_list(vec<1, T>* self, PyObject*);
template<typename T>
static PyObject* vec2_to_list(vec<2, T>* self, PyObject*);
template<typename T>
static PyObject* vec3_to_list(vec<3, T>* self, PyObject*);
template<typename T>
static PyObject* vec4_to_list(vec<4, T>* self, PyObject*);

template<typename T>
static PyObject* vec1_to_tuple(vec<1, T>* self, PyObject*);
template<typename T>
static PyObject* vec2_to_tuple(vec<2, T>* self, PyObject*);
template<typename T>
static PyObject* vec3_to_tuple(vec<3, T>* self, PyObject*);
template<typename T>
static PyObject* vec4_to_tuple(vec<4, T>* self, PyObject*);

template<typename T>
static PyObject* vec1_setstate(vec<1, T>* self, PyObject* state);
template<typename T>
static PyObject* vec2_setstate(vec<2, T>* self, PyObject* state);
template<typename T>
static PyObject* vec3_setstate(vec<3, T>* self, PyObject* state);
template<typename T>
static PyObject* vec4_setstate(vec<4, T>* self, PyObject* state);

template<int L>
static Py_ssize_t vec_len(PyObject* self);

template<typename T>
static PyObject* vec1_sq_item(vec<1, T> * self, Py_ssize_t index);
template<typename T>
static PyObject* vec2_sq_item(vec<2, T> * self, Py_ssize_t index);
template<typename T>
static PyObject* vec3_sq_item(vec<3, T> * self, Py_ssize_t index);
template<typename T>
static PyObject* vec4_sq_item(vec<4, T> * self, Py_ssize_t index);

template<typename T>
static int vec1_sq_ass_item(vec<1, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
static int vec2_sq_ass_item(vec<2, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
static int vec3_sq_ass_item(vec<3, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
static int vec4_sq_ass_item(vec<4, T> * self, Py_ssize_t index, PyObject * value);

template<int L, typename T>
static int vec_contains(vec<L, T> * self, PyObject * value);

template<int L, typename T>
static PyObject * vec_add(PyObject *obj1, PyObject *obj2);

template<int L>
static PyObject* bvec_add(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * vec_sub(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * vec_mul(PyObject *obj1, PyObject *obj2);

template<int L>
static PyObject* bvec_mul(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * vec_mod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * vec_divmod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject* vec_lshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* vec_rshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* vec_and(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* vec_xor(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * vec_or(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * vec_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
static PyObject * vec_neg(vec<L, T> *obj);

template<int L>
static PyObject* bvec_neg(vec<L, bool>* obj);

template<int L, typename T>
static PyObject * vec_pos(vec<L, T> *obj);

template<int L, typename T>
static PyObject * vec_abs(vec<L, T> *obj);

template<int L, typename T>
static PyObject* vec_invert(vec<L, T>* obj);

static PyObject* vec_matmul(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * vec_iadd(vec<L, T>* self, PyObject *obj);

template<int L>
static PyObject* bvec_iadd(vec<L, bool>* self, PyObject* obj);

template<int L, typename T>
static PyObject * vec_isub(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject * vec_imul(vec<L, T>* self, PyObject *obj);

template<int L>
static PyObject* bvec_imul(vec<L, bool>* self, PyObject* obj);

template<int L, typename T>
static PyObject * vec_imod(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject* vec_ilshift(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* vec_irshift(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* vec_iand(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* vec_ixor(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* vec_ior(vec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject * vec_ipow(vec<L, T>* self, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
static PyObject * vec_floordiv(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * ivec_floordiv(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * vec_div(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * vec_ifloordiv(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject * ivec_ifloordiv(vec<L, T> *self, PyObject *obj);

template<int L, typename T>
static PyObject * vec_idiv(vec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject* vec_imatmul(vec<L, T>* self, PyObject* obj);

static void vec_dealloc(PyObject* self);

template<typename T>
static PyObject* vec1_str(vec<1, T>* self);
template<typename T>
static PyObject* vec2_str(vec<2, T>* self);
template<typename T>
static PyObject* vec3_str(vec<3, T>* self);
template<typename T>
static PyObject* vec4_str(vec<4, T>* self);

template<typename T>
static PyObject* vec1_repr(vec<1, T>* self);
template<typename T>
static PyObject* vec2_repr(vec<2, T>* self);
template<typename T>
static PyObject* vec3_repr(vec<3, T>* self);
template<typename T>
static PyObject* vec4_repr(vec<4, T>* self);

template<int L, typename T>
static PyObject* vec_getattr(PyObject* obj, PyObject* name);
template<int L, typename T>
static int vec_setattr(PyObject* obj, PyObject* name, PyObject* value);

template<int L, typename T>
static PyObject* vec_richcompare(vec<L, T>* self, PyObject* other, int comp_type);

template<int L, typename T>
static PyObject* vec_geniter(vec<L, T>* self);

template<typename T>
static int vec1_init(vec<1, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int vec2_init(vec<2, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int vec3_init(vec<3, T> *self, PyObject *args, PyObject *kwds);
template<typename T>
static int vec4_init(vec<4, T> *self, PyObject *args, PyObject *kwds);

template<int L, typename T>
static PyObject* vec_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

template<int L, typename T>
static void vecIter_dealloc(vecIter<L, T> *rgstate);

template<typename T>
static PyObject* vec1Iter_next(vecIter<1, T> *rgstate);
template<typename T>
static PyObject* vec2Iter_next(vecIter<2, T> *rgstate);
template<typename T>
static PyObject* vec3Iter_next(vecIter<3, T> *rgstate);
template<typename T>
static PyObject* vec4Iter_next(vecIter<4, T> *rgstate);

template<int L, typename T>
static PyObject* vecIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<int L, typename T>
static PyObject* vec_from_bytes(PyObject*, PyObject* arg);

template<int L, typename T>
static Py_hash_t vec_hash(vec<L, T>* self, PyObject*);