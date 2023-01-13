#pragma once

#include "../forward_declarations.h"

template<int L, typename T>
static int mvec_getbuffer(mvec<L, T>* self, Py_buffer* view, int flags);

static void mvec_releasebuffer(PyObject* self, Py_buffer* view);

template<typename T>
static PyObject* mvec2_to_list(mvec<2, T>* self, PyObject*);
template<typename T>
static PyObject* mvec3_to_list(mvec<3, T>* self, PyObject*);
template<typename T>
static PyObject* mvec4_to_list(mvec<4, T>* self, PyObject*);

template<typename T>
static PyObject* mvec2_to_tuple(mvec<2, T>* self, PyObject*);
template<typename T>
static PyObject* mvec3_to_tuple(mvec<3, T>* self, PyObject*);
template<typename T>
static PyObject* mvec4_to_tuple(mvec<4, T>* self, PyObject*);

template<typename T>
static PyObject* mvec2_setstate(mvec<2, T>* self, PyObject* state);
template<typename T>
static PyObject* mvec3_setstate(mvec<3, T>* self, PyObject* state);
template<typename T>
static PyObject* mvec4_setstate(mvec<4, T>* self, PyObject* state);

template<int L, typename T>
static PyObject* mvec_new(PyTypeObject* type, PyObject*, PyObject*);

template<int L, typename T>
static int mvec_init(mvec<L, T>* self, PyObject* args, PyObject* kwds);

template<int L>
static Py_ssize_t mvec_len(PyObject* self);

template<typename T>
static PyObject* mvec2_sq_item(mvec<2, T> * self, Py_ssize_t index);
template<typename T>
static PyObject* mvec3_sq_item(mvec<3, T> * self, Py_ssize_t index);
template<typename T>
static PyObject* mvec4_sq_item(mvec<4, T> * self, Py_ssize_t index);

template<typename T>
static int mvec2_sq_ass_item(mvec<2, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
static int mvec3_sq_ass_item(mvec<3, T> * self, Py_ssize_t index, PyObject * value);
template<typename T>
static int mvec4_sq_ass_item(mvec<4, T> * self, Py_ssize_t index, PyObject * value);

template<int L, typename T>
static int mvec_contains(mvec<L, T> * self, PyObject * value);

template<int L, typename T>
static PyObject * mvec_add(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * mvec_sub(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * mvec_mul(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * mvec_mod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * mvec_divmod(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject* mvec_lshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* mvec_rshift(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* mvec_and(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* mvec_xor(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject* mvec_or(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * mvec_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
static PyObject * mvec_neg(mvec<L, T> *obj);

template<int L, typename T>
static PyObject * mvec_pos(mvec<L, T> *obj);

template<int L, typename T>
static PyObject * mvec_abs(mvec<L, T> *obj);

template<int L, typename T>
static PyObject* mvec_invert(mvec<L, T>* obj);

static PyObject* mvec_matmul(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * mvec_iadd(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject * mvec_isub(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject * mvec_imul(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject * mvec_imod(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject * mvec_ipow(mvec<L, T>* self, PyObject * obj2, PyObject * obj3);

template<int L, typename T>
static PyObject * mvec_floordiv(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject * mvec_div(PyObject *obj1, PyObject *obj2);

template<int L, typename T>
static PyObject* imvec_floordiv(PyObject* obj1, PyObject* obj2);

template<int L, typename T>
static PyObject * mvec_ifloordiv(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject* imvec_ifloordiv(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject * mvec_idiv(mvec<L, T>* self, PyObject *obj);

template<int L, typename T>
static PyObject* mvec_imatmul(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* mvec_ilshift(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* mvec_irshift(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* mvec_iand(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* mvec_ixor(mvec<L, T>* self, PyObject* obj);

template<int L, typename T>
static PyObject* mvec_ior(mvec<L, T>* self, PyObject* obj);

static void mvec_dealloc(PyObject* self);

template<int L, typename T>
static PyObject* mvec_copy(PyObject* self, PyObject*);

template<int L, typename T>
static PyObject* mvec_deepcopy(PyObject* self, PyObject* memo);

template<typename T>
static PyObject* mvec2_str(mvec<2, T>* self);
template<typename T>
static PyObject* mvec3_str(mvec<3, T>* self);
template<typename T>
static PyObject* mvec4_str(mvec<4, T>* self);

template<int L, typename T>
static PyObject* mvec_getattr(PyObject* obj, PyObject* name);

template<int L, typename T>
static int mvec_setattr(PyObject* obj, PyObject* name, PyObject* value);

template<int L, typename T>
static PyObject* mvec_richcompare(mvec<L, T>* self, PyObject* other, int comp_type);

template<int L, typename T>
static PyObject* mvec_geniter(mvec<L, T>* self);

template<int L, typename T>
static void mvecIter_dealloc(mvecIter<L, T> *rgstate);

template<typename T>
static PyObject* mvec2Iter_next(mvecIter<2, T> *rgstate);
template<typename T>
static PyObject* mvec3Iter_next(mvecIter<3, T> *rgstate);
template<typename T>
static PyObject* mvec4Iter_next(mvecIter<4, T> *rgstate);

template<int L, typename T>
static PyObject* mvecIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

template<int L, typename T>
static Py_hash_t mvec_hash(mvec<L, T>* self, PyObject*);