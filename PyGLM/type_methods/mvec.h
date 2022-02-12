#pragma once

#include "../compiler_setup.h"

#include "../internal_functions/all.h"

#include "../types/mvec/all.h"

void mvec_dealloc(PyObject* self);

template<int L, typename T>
PyObject* mvec_new(PyTypeObject* type, PyObject*, PyObject*)
{
	mvec<L, T>* self = (mvec<L, T>*)type->tp_alloc(type, 0);
	if (self != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = L | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		//self->info = info;
		self->master = NULL;
		self->super_type = NULL;
	}

	return (PyObject*)self;
}

#define mvec_new_TEMPLATE(L, T) template PyObject* mvec_new<L, T>(PyTypeObject* type, PyObject*, PyObject*)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_new_TEMPLATE);

template<int L, typename T>
int mvec_init(mvec<L, T>* self, PyObject* args, PyObject* kwds)
{
	if (PyTuple_GET_SIZE(args) == 1 && Py_TYPE(PyTuple_GET_ITEM(args, 0)) == PyGLM_VEC_TYPE<L, T>()) {
		self->master = PyGLM_INCREF(PyTuple_GET_ITEM(args, 0));
	}
	else {
		if (PyTuple_GET_SIZE(args) || kwds) {
			PyErr_SetString(PyExc_TypeError, "Invalid arguments for mvec(). Expected no arguments or a vector to reference.");
			return -1;
		}
		self->master = vec_new<L, T>(PyGLM_VEC_TYPE<L, T>(), NULL, NULL);
	}
	
	self->super_type = &((vec<L, T>*)self->master)->super_type;

	return 0;
}

#define mvec_init_TEMPLATE(L, T) template int mvec_init(mvec<L, T>* self, PyObject* args, PyObject* kwds)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_init_TEMPLATE);

// unaryfunc
template<int L, typename T>
PyObject* mvec_neg(mvec<L, T> *obj)
{
	return pack_vec<L, T>(-*obj->super_type);
}

#define mvec_neg_TEMPLATE(L, T) template PyObject* mvec_neg(mvec<L, T> *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_SIGNED(mvec_neg_TEMPLATE);

template<int L, typename T>
PyObject* mvec_pos(mvec<L, T> *obj)
{
	return pack_vec<L, T>(*obj->super_type);
}

#define mvec_pos_TEMPLATE(L, T) template PyObject* mvec_pos(mvec<L, T> *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_pos_TEMPLATE);

template<int L, typename T>
PyObject* mvec_abs(mvec<L, T> *obj)
{
	return pack_vec<L, T>(glm::abs(*obj->super_type));
}

#define mvec_abs_TEMPLATE(L, T) template PyObject* mvec_abs(mvec<L, T> *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_abs_TEMPLATE);

template<int L, typename T>
PyObject* mvec_invert(mvec<L, T>* obj)
{
	return pack_vec<L, T>(~*obj->super_type);
}

#define mvec_invert_TEMPLATE(L, T) template PyObject* mvec_invert(mvec<L, T> *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_invert_TEMPLATE);

// binaryfunc
template<int L, typename T>
PyObject* mvec_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) + *(((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o + PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o + o2);
}

#define mvec_add_TEMPLATE(L, T) template PyObject* mvec_add<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_add_TEMPLATE);

template<int L, typename T>
PyObject* mvec_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) - *((mvec<L, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o - PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o - o2);
}

#define mvec_sub_TEMPLATE(L, T) template PyObject* mvec_sub<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_sub_TEMPLATE);

template<int L, typename T>
PyObject* mvec_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) * *((mvec<L, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o * PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o * o2);
}

#define mvec_mul_TEMPLATE(L, T) template PyObject* mvec_mul<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_mul_TEMPLATE);

template<int L, typename T>
PyObject* mvec_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		if (!glm::all((glm::vec<L, bool>)(((mvec<L, T>*)obj2)->super_type))) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) / *((mvec<L, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(o / o2);
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a mvec
	return  pack_vec<L, T>(o / o2);
}

#define mvec_div_TEMPLATE(L, T) template PyObject* mvec_div<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_div_TEMPLATE);

template<int L, typename T>
PyObject* mvec_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		if (!glm::all((glm::vec<L, bool>)(((mvec<L, T>*)obj2)->super_type))) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(glm::mod(glm::vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1)), *((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(glm::mod(o, glm::vec<L, T>(o2)));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(glm::mod(o, o2));
}

#define mvec_mod_TEMPLATE(L, T) template PyObject* mvec_mod<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_FD(mvec_mod_TEMPLATE);

template<int L, typename T>
PyObject* mvec_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		if (!glm::all((glm::vec<L, bool>)(((mvec<L, T>*)obj2)->super_type))) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(floor(PyGLM_Number_FromPyObject<T>(obj1) / *((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(floor(o / o2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(floor(o / o2));
}

#define mvec_floordiv_TEMPLATE(L, T) template PyObject* mvec_floordiv<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_FD(mvec_floordiv_TEMPLATE);

template<int L, typename T>
PyObject* mvec_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = mvec_floordiv<L, T>(obj1, obj2);
	arg2 = mvec_mod<L, T>(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

#define mvec_divmod_TEMPLATE(L, T) template PyObject* mvec_divmod<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_FD(mvec_divmod_TEMPLATE);

template<int L, typename T>
PyObject* mvec_lshift(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) << *(((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for <<: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o << PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o << o2);
}

#define mvec_lshift_TEMPLATE(L, T) template PyObject* mvec_lshift<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_lshift_TEMPLATE);

template<int L, typename T>
PyObject* mvec_rshift(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) >> *(((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for >>: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o >> PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o >> o2);
}

#define mvec_rshift_TEMPLATE(L, T) template PyObject* mvec_rshift<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_rshift_TEMPLATE);

template<int L, typename T>
PyObject* mvec_and(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) & *(((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for &: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o & PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o & o2);
}

#define mvec_and_TEMPLATE(L, T) template PyObject* mvec_and<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_and_TEMPLATE);

template<int L, typename T>
PyObject* mvec_or(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) | *(((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for |: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o | PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o | o2);
}

#define mvec_or_TEMPLATE(L, T) template PyObject* mvec_or<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_or_TEMPLATE);

template<int L, typename T>
PyObject* mvec_xor(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) ^ *(((mvec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for ^: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o ^ PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	return pack_vec<L, T>(o ^ o2);
}

#define mvec_xor_TEMPLATE(L, T) template PyObject* mvec_xor<L, T>(PyObject *obj1, PyObject *obj2)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_xor_TEMPLATE);

// ternaryfunc
template<int L, typename T>
PyObject* mvec_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		T f = PyGLM_Number_FromPyObject<T>(obj1);

		if (obj3 == Py_None) {
			return pack_vec<L, T>(glm::pow(glm::vec<L, T>(f), *((mvec<L, T>*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			T f2 = PyGLM_Number_FromPyObject<T>(obj3);
			return pack_vec<L, T>(glm::mod(glm::pow(glm::vec<L, T>(f), *((mvec<L, T>*)obj2)->super_type), glm::vec<L, T>(f2)));
		}

		PyGLM_PTI_Init2(obj3, (get_vec_PTI_info<L, T>()));

		if (PyGLM_PTI_IsNone(2)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get2(L, T, obj3);

		return pack_vec<L, T>(glm::mod(glm::pow(glm::vec<L, T>(f), *((mvec<L, T>*)obj2)->super_type), o3));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T f = PyGLM_Number_FromPyObject<T>(obj2);

		if (obj3 == Py_None) {
			return pack_vec<L, T>(glm::pow(o, glm::vec<L, T>(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			T f2 = PyGLM_Number_FromPyObject<T>(obj3);
			return pack_vec<L, T>(glm::mod(glm::pow(o, glm::vec<L, T>(f)), glm::vec<L, T>(f2)));
		}

		PyGLM_PTI_Init2(obj3, (get_vec_PTI_info<L, T>()));

		if (PyGLM_PTI_IsNone(2)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get2(L, T, obj3);

		return pack_vec<L, T>(glm::mod(glm::pow(o, glm::vec<L, T>(f)), o3));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a mvec
	if (obj3 == Py_None) {
		return pack_vec<L, T>(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		T f2 = PyGLM_Number_FromPyObject<T>(obj3);
		return pack_vec<L, T>(glm::mod(glm::pow(o, o2), glm::vec<L, T>(f2)));
	}

	PyGLM_PTI_Init2(obj3, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(2)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get2(L, T, obj3);

	return pack_vec<L, T>(glm::mod(glm::pow(o, o2), o3));
}

#define mvec_pow_TEMPLATE(L, T) template PyObject* mvec_pow<L, T>(PyObject * obj1, PyObject * obj2, PyObject * obj3)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_FD(mvec_pow_TEMPLATE);

PyObject* mvec_matmul(PyObject* obj1, PyObject* obj2);

// inplace
// binaryfunc
template<int L, typename T>
PyObject* mvec_iadd(mvec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)mvec_add<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_iadd_TEMPLATE(L, T) template PyObject* mvec_iadd(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_iadd_TEMPLATE);

template<int L, typename T>
PyObject* mvec_isub(mvec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)mvec_sub<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_isub_TEMPLATE(L, T) template PyObject* mvec_isub(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_isub_TEMPLATE);

template<int L, typename T>
PyObject* mvec_imul(mvec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)mvec_mul<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_imul_TEMPLATE(L, T) template PyObject* mvec_imul(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_imul_TEMPLATE);

template<int L, typename T>
PyObject* mvec_idiv(mvec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)mvec_div<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_idiv_TEMPLATE(L, T) template PyObject* mvec_idiv(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_idiv_TEMPLATE);

template<int L, typename T>
PyObject* mvec_imod(mvec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)mvec_mod<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_imod_TEMPLATE(L, T) template PyObject* mvec_imod(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_imod_TEMPLATE);

template<int L, typename T>
PyObject* mvec_ifloordiv(mvec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)mvec_floordiv<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_ifloordiv_TEMPLATE(L, T) template PyObject* mvec_ifloordiv(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_ifloordiv_TEMPLATE);

template<int L, typename T>
PyObject* mvec_imatmul(mvec<L, T>* self, PyObject* obj)
{
	mvec<L, T>* temp = (mvec<L, T>*)mvec_matmul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Vec_Check(L, T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_imatmul_TEMPLATE(L, T) template PyObject* mvec_imatmul(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_imatmul_TEMPLATE);

template<int L, typename T>
PyObject* mvec_ilshift(mvec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)mvec_lshift<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_ilshift_TEMPLATE(L, T) template PyObject* mvec_ilshift(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_ilshift_TEMPLATE);

template<int L, typename T>
PyObject* mvec_irshift(mvec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)mvec_rshift<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_irshift_TEMPLATE(L, T) template PyObject* mvec_irshift(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_irshift_TEMPLATE);

template<int L, typename T>
PyObject* mvec_iand(mvec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)mvec_and<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_iand_TEMPLATE(L, T) template PyObject* mvec_iand(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_iand_TEMPLATE);

template<int L, typename T>
PyObject* mvec_ixor(mvec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)mvec_xor<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_ixor_TEMPLATE(L, T) template PyObject* mvec_ixor(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_ixor_TEMPLATE);

template<int L, typename T>
PyObject* mvec_ior(mvec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)mvec_or<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_ior_TEMPLATE(L, T) template PyObject* mvec_ior(mvec<L, T> *self, PyObject *obj)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(mvec_ior_TEMPLATE);

// ternaryfunc
template<int L, typename T>
PyObject* mvec_ipow(mvec<L, T> *self, PyObject *obj1, PyObject *) // obj2 is unused. It points to an invalid address!
{
	vec<L, T> * temp = (vec<L, T>*)mvec_pow<L, T>((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	*self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

#define mvec_ipow_TEMPLATE(L, T) template PyObject* mvec_ipow(mvec<L, T> *self, PyObject *obj1, PyObject *)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_FD(mvec_ipow_TEMPLATE);

template<typename T>
PyObject* mvec2_str(mvec<2, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 32 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g )", name, (double)self->super_type->x, (double)self->super_type->y);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
PyObject* mvec3_str(mvec<3, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 46 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g, %12.6g )", name, (double)self->super_type->x, (double)self->super_type->y, (double)self->super_type->z);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
PyObject* mvec4_str(mvec<4, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 60 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g, %12.6g, %12.6g )", name, (double)self->super_type->x, (double)self->super_type->y, (double)self->super_type->z, (double)self->super_type->w);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

#define mvec_str_TEMPLATE(L, T) template PyObject* mvec ## L ## _str(mvec<L, T>* self)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_str_TEMPLATE);

template<int L>
Py_ssize_t mvec_len(PyObject *) {
	return (Py_ssize_t)L;
}

#define mvec_len_TEMPLATE(L) template Py_ssize_t mvec_len<L>(PyObject *)
PyGLM_GENERATE_EXTERN_TEMPLATE_2_THRU_4(mvec_len_TEMPLATE);

template<typename T>
PyObject* mvec2_sq_item(mvec<2, T> * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->x);
	case 1:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->y);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

template<typename T>
PyObject* mvec3_sq_item(mvec<3, T> * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->x);
	case 1:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->y);
	case 2:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->z);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

template<typename T>
PyObject* mvec4_sq_item(mvec<4, T> * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->x);
	case 1:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->y);
	case 2:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->z);
	case 3:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type->w);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

#define mvec_sq_item_TEMPLATE(L, T) template PyObject* mvec ## L ## _sq_item(mvec<L, T> * self, Py_ssize_t index)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_sq_item_TEMPLATE);

template<typename T>
int mvec2_sq_ass_item(mvec<2, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type->x = f;
		return 0;
	case 1:
		self->super_type->y = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

template<typename T>
int mvec3_sq_ass_item(mvec<3, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type->x = f;
		return 0;
	case 1:
		self->super_type->y = f;
		return 0;
	case 2:
		self->super_type->z = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

template<typename T>
int mvec4_sq_ass_item(mvec<4, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type->x = f;
		return 0;
	case 1:
		self->super_type->y = f;
		return 0;
	case 2:
		self->super_type->z = f;
		return 0;
	case 3:
		self->super_type->w = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

#define mvec_sq_ass_item_TEMPLATE(L, T) template int mvec ## L ## _sq_ass_item(mvec<L, T> * self, Py_ssize_t index, PyObject * value)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_sq_ass_item_TEMPLATE);

template<int L, typename T>
int mvec_contains(mvec<L, T> * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		T f = PyGLM_Number_FromPyObject<T>(value);
		bool contains = false;
		for (int i = 0; i < L; i++) {
			if (f == (*self->super_type)[i]) {
				contains = true;
				break;
			}
		}
		return (int)contains;
	}
	return 0;

}

#define mvec_contains_TEMPLATE(L, T) template int mvec_contains(mvec<L, T> * self, PyObject * value)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_contains_TEMPLATE);

template<int L, typename T>
PyObject* mvec_richcompare(mvec<L, T> * self, PyObject * other, int comp_type) {
	PyGLM_PTI_Init1(other, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, other);

	switch (comp_type) {
	case Py_EQ:
		if (*self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (*self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec<L, T>(glm::lessThan(*self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec<L, T>(glm::lessThanEqual(*self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec<L, T>(glm::greaterThan(*self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec<L, T>(glm::greaterThanEqual(*self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

#define mvec_richcompare_TEMPLATE(L, T) template PyObject* mvec_richcompare(mvec<L, T> * self, PyObject * other, int comp_type)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_richcompare_TEMPLATE);

template<typename T>
bool unswizzle_mvec(mvec<2, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		out = self->super_type->y;
		return true;
	}
	return false;
}

template<typename T>
bool unswizzle_mvec(mvec<3, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		out = self->super_type->y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		out = self->super_type->z;
		return true;
	}
	return false;
}

template<typename T>
bool unswizzle_mvec(mvec<4, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		out = self->super_type->y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		out = self->super_type->z;
		return true;
	}
	if (c == 'w' || c == 'a' || c == 'p') {
		out = self->super_type->w;
		return true;
	}
	return false;
}

#define unswizzle_mvec_TEMPLATE(L, T) template bool unswizzle_mvec(mvec<L, T> * self, char c, T& out)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(unswizzle_mvec_TEMPLATE);

template<typename T>
T& unswizzle2_mvec(mvec<2, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type->x;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		success = success && true;
		return self->super_type->y;
	}
	success = false;
	return self->super_type->x;
}

template<typename T>
T& unswizzle2_mvec(mvec<3, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type->x;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		success = success && true;
		return self->super_type->y;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		success = success && true;
		return self->super_type->z;
	}
	success = false;
	return self->super_type->x;
}

template<typename T>
T& unswizzle2_mvec(mvec<4, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type->x;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		success = success && true;
		return self->super_type->y;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		success = success && true;
		return self->super_type->z;
	}
	if (c == 'w' || c == 'a' || c == 'p') {
		success = success && true;
		return self->super_type->w;
	}
	success = false;
	return self->super_type->x;
}

#define unswizzle2_mvec_TEMPLATE(L, T) template T& unswizzle2_mvec(mvec<L, T> * self, char c, bool& success)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(unswizzle2_mvec_TEMPLATE);

template<int L, typename T>
PyObject * mvec_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if (len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_') {
		return PyObject_GenericGetAttr(obj, name);
	}
	if (len == 1) {
		T x;
		if (unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[0], x)) {
			return PyGLM_PyObject_FromNumber<T>((T)x);
		}
	}
	else if (len == 2) {
		T x;
		T y;
		if (unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[0], x) && unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[1], y)) {
			return pack_vec<2, T>(glm::vec<2, T>(x, y));
		}
	}
	else if (len == 3) {
		T x;
		T y;
		T z;
		if (unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[0], x) && unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[1], y) && unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[2], z)) {
			return pack_vec<3, T>(glm::vec<3, T>(x, y, z));
		}
	}
	else if (len == 4) {
		T x;
		T y;
		T z;
		T w;
		if (unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[0], x) && unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[1], y) && unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[2], z) && unswizzle_mvec((mvec<L, T> *)obj, name_as_ccp[3], w)) {
			return pack_vec<4, T>(glm::vec<4, T>(x, y, z, w));
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

#define mvec_getattr_TEMPLATE(L, T) template PyObject * mvec_getattr<L, T>(PyObject * obj, PyObject * name)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_getattr_TEMPLATE);

template<int L, typename T>
int mvec_setattr(PyObject * obj, PyObject * name, PyObject* value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "deleting components is not permitted.");
		return -1;
	}

	char * name_as_ccp = PyGLM_String_AsString(name);
	size_t len = strlen(name_as_ccp);

	if (PyGLM_Number_Check(value)) {
		T v = PyGLM_Number_FromPyObject<T>(value);
		bool success = true;
		if (len == 1) {
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			if (success) {
				x = v;
				return 0;
			}
		}
		else if (len == 2) {
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[1], success);
			if (success) {
				x = v;
				y = v;
				return 0;
			}
		}
		else if (len == 3) {
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[2], success);
			if (success) {
				x = v;
				y = v;
				z = v;
				return 0;
			}
		}
		else if (len == 4) {
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[2], success);
			T& w = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[3], success);
			if (success) {
				x = v;
				y = v;
				z = v;
				w = v;
				return 0;
			}
		}
	}
	else {
		PyGLM_PTI_Init0(value, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_PTI_GetDT(T));
		if (len == 1 && PyGLM_Vec_PTI_Check0(1, T, value)) {
			glm::vec<1, T> v = PyGLM_Vec_PTI_Get0(1, T, value);
			bool success = true;
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			if (success) {
				x = v.x;
				return 0;
			}
		}
		else if (len == 2 && PyGLM_Vec_PTI_Check0(2, T, value)) {
			glm::vec<2, T> v = PyGLM_Vec_PTI_Get0(2, T, value);
			bool success = true;
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[1], success);
			if (success) {
				x = v.x;
				y = v.y;
				return 0;
			}
		}
		else if (len == 3 && PyGLM_Vec_PTI_Check0(3, T, value)) {
			glm::vec<3, T> v = PyGLM_Vec_PTI_Get0(3, T, value);
			bool success = true;
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[2], success);
			if (success) {
				x = v.x;
				y = v.y;
				z = v.z;
				return 0;
			}
		}
		else if (len == 4 && PyGLM_Vec_PTI_Check0(4, T, value)) {
			glm::vec<4, T> v = PyGLM_Vec_PTI_Get0(4, T, value);
			bool success = true;
			T& x = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[2], success);
			T& w = unswizzle2_mvec((mvec<L, T>*)obj, name_as_ccp[3], success);
			if (success) {
				x = v.x;
				y = v.y;
				z = v.z;
				w = v.w;
				return 0;
			}
		}
	}
	
	return PyObject_GenericSetAttr(obj, name, value);
}

#define mvec_setattr_TEMPLATE(L, T) template int mvec_setattr<L, T>(PyObject * obj, PyObject * name, PyObject* value)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_setattr_TEMPLATE);

// iterator
template<int L, typename T>
PyObject* mvecIter_new(PyTypeObject *type, PyObject *args, PyObject *)
{
	mvec<L, T> *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	mvecIter<L, T> *rgstate = (mvecIter<L, T> *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

#define mvecIter_new_TEMPLATE(L, T) template PyObject* mvecIter_new<L, T>(PyTypeObject *type, PyObject *args, PyObject *)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvecIter_new_TEMPLATE);

template<int L, typename T>
void mvecIter_dealloc(mvecIter<L, T> *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

#define mvecIter_dealloc_TEMPLATE(L, T) template void mvecIter_dealloc(mvecIter<L, T> *rgstate)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvecIter_dealloc_TEMPLATE);

template<typename T>
PyObject* mvec2Iter_next(mvecIter<2, T> *rgstate)
{
	if (rgstate->seq_index < 2) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->x);
		case 1:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->y);
		}
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<typename T>
PyObject* mvec3Iter_next(mvecIter<3, T> *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->x);
		case 1:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->y);
		case 2:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<typename T>
PyObject* mvec4Iter_next(mvecIter<4, T> *rgstate)
{
	if (rgstate->seq_index < 4) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->x);
		case 1:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->y);
		case 2:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->z);
		case 3:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type->w);
		}
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

#define mvecIter_next_TEMPLATE(L, T) template PyObject* mvec ## L ## Iter_next(mvecIter<L, T> *rgstate)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvecIter_next_TEMPLATE);

template<int L, typename T>
PyObject * mvec_geniter(mvec<L, T>* self) {
	mvecIter<L, T> *rgstate = (mvecIter<L, T> *)(PyGLM_MVECITER_TYPE<L, T>()->tp_alloc(PyGLM_MVECITER_TYPE<L, T>(), 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

#define mvec_geniter_TEMPLATE(L, T) template PyObject * mvec_geniter(mvec<L, T>* self)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_geniter_TEMPLATE);

template<int L, typename T>
int mvec_getbuffer(mvec<L, T>* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}
	view->obj = (PyObject*)self;
	view->buf = (void*)self->super_type;
	view->len = sizeof(glm::vec<L, T>);
	view->readonly = 0;
	view->itemsize = sizeof(T);
	if (flags & PyBUF_FORMAT) {
		view->format = (std::is_same<T, float>::value) ? const_cast<char*>("f") : \
			(std::is_same <T, double>::value) ? const_cast<char*>("d") : \
			(std::is_same <T, std::int32_t>::value) ? const_cast<char*>("i") : \
			(std::is_same <T, std::uint32_t>::value) ? const_cast<char*>("I") : NULL;
	}
	else {
		view->format = NULL;
	}
	view->ndim = 1;
	if (flags & PyBUF_ND) {
		view->shape = (Py_ssize_t*)PyMem_Malloc(sizeof(Py_ssize_t));
		if (view->shape != NULL) {
			view->shape[0] = L;
		}
	}
	else {
		view->shape = NULL;
	}
	if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
		view->strides = &view->itemsize;
	}
	else {
		view->strides = NULL;
	}
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

#define mvec_getbuffer_TEMPLATE(L, T) template int mvec_getbuffer(mvec<L, T>* self, Py_buffer* view, int flags)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_getbuffer_TEMPLATE);

void mvec_releasebuffer(PyObject*, Py_buffer* view);

template<int L, typename T>
Py_hash_t mvec_hash(mvec<L, T>* self, PyObject*) {
	std::hash<glm::vec<L, T>> hasher;
	Py_hash_t out = (Py_hash_t)hasher(*self->super_type);
	if (out == -1) {
		return -2;
	}
	return out;
}

#define mvec_hash_TEMPLATE(L, T) template Py_hash_t mvec_hash(mvec<L, T>* self, PyObject*)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_hash_TEMPLATE);

template<typename T>
PyObject* mvec2_to_list(mvec<2, T>* self, PyObject*) {
	PyObject* out = PyList_New(2);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type->x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type->y));
	return out;
}

template<typename T>
PyObject* mvec3_to_list(mvec<3, T>* self, PyObject*) {
	PyObject* out = PyList_New(3);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type->x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type->y));
	PyList_SET_ITEM(out, 2, PyGLM_PyObject_FromNumber<T>(self->super_type->z));
	return out;
}

template<typename T>
PyObject* mvec4_to_list(mvec<4, T>* self, PyObject*) {
	PyObject* out = PyList_New(4);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type->x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type->y));
	PyList_SET_ITEM(out, 2, PyGLM_PyObject_FromNumber<T>(self->super_type->z));
	PyList_SET_ITEM(out, 3, PyGLM_PyObject_FromNumber<T>(self->super_type->w));
	return out;
}

#define mvec_to_list_TEMPLATE(L, T) template PyObject* mvec ## L ## _to_list(mvec<L, T>* self, PyObject*)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_to_list_TEMPLATE);

template<typename T>
PyObject* mvec2_to_tuple(mvec<2, T>* self, PyObject*) {
	return PyTuple_Pack(2,
		PyGLM_PyObject_FromNumber<T>(self->super_type->x),
		PyGLM_PyObject_FromNumber<T>(self->super_type->y));
}

template<typename T>
PyObject* mvec3_to_tuple(mvec<3, T>* self, PyObject*) {
	return PyTuple_Pack(3,
		PyGLM_PyObject_FromNumber<T>(self->super_type->x),
		PyGLM_PyObject_FromNumber<T>(self->super_type->y),
		PyGLM_PyObject_FromNumber<T>(self->super_type->z));
}

template<typename T>
PyObject* mvec4_to_tuple(mvec<4, T>* self, PyObject*) {
	return PyTuple_Pack(4,
		PyGLM_PyObject_FromNumber<T>(self->super_type->x),
		PyGLM_PyObject_FromNumber<T>(self->super_type->y),
		PyGLM_PyObject_FromNumber<T>(self->super_type->z),
		PyGLM_PyObject_FromNumber<T>(self->super_type->w));
}

#define mvec_to_tuple_TEMPLATE(L, T) template PyObject* mvec ## L ## _to_tuple(mvec<L, T>* self, PyObject*)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_to_tuple_TEMPLATE);

template<typename T>
PyObject* mvec2_setstate(mvec<2, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 2, "Invalid state. Expected a length 2 tuple.");
	self->super_type = (glm::vec<2, T>*)PyMem_MALLOC(sizeof(glm::vec<2, T>));
	self->super_type->x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type->y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	Py_RETURN_NONE;
}

template<typename T>
PyObject* mvec3_setstate(mvec<3, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 3, "Invalid state. Expected a length 3 tuple.");
	self->super_type = (glm::vec<3, T>*)PyMem_MALLOC(sizeof(glm::vec<3, T>));
	self->super_type->x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type->y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	self->super_type->z = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 2));
	Py_RETURN_NONE;
}

template<typename T>
PyObject* mvec4_setstate(mvec<4, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 4, "Invalid state. Expected a length 4 tuple.");
	self->super_type = (glm::vec<4, T>*)PyMem_MALLOC(sizeof(glm::vec<4, T>));
	self->super_type->x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type->y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	self->super_type->z = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 2));
	self->super_type->w = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 3));
	Py_RETURN_NONE;
}

#define mvec_setstate_TEMPLATE(L, T) template PyObject* mvec ## L ## _setstate(mvec<L, T>* self, PyObject* state)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_setstate_TEMPLATE);

template<int L, typename T>
PyObject* mvec_copy(PyObject* self, PyObject*) {
	return pack_vec(*((mvec<L, T>*)self)->super_type);
}

#define mvec_copy_TEMPLATE(L, T) template PyObject* mvec_copy<L, T>(PyObject* self, PyObject*)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_copy_TEMPLATE);

template<int L, typename T>
PyObject* mvec_deepcopy(PyObject* self, PyObject* memo) {
	PyObject* copy = mvec_copy<L, T>(self, NULL);
	PyDict_SetItem(memo, PyLong_FromVoidPtr((void*)self), copy);
	return copy;
}

#define mvec_deepcopy_TEMPLATE(L, T) template PyObject* mvec_deepcopy<L, T>(PyObject* self, PyObject* memo)
PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(mvec_deepcopy_TEMPLATE);

// cpp
void mvec_dealloc(PyObject* self)
{
	Py_XDECREF(((mvec_helper*)self)->master);
	self->ob_type->tp_free(self);
}

PyObject* mvec_matmul(PyObject* obj1, PyObject* obj2)
{
	PyObject* out = PyNumber_Multiply(obj1, obj2);
	if (out == NULL) {
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for @: ", obj1, obj2);
	}
	return out;
}

void mvec_releasebuffer(PyObject*, Py_buffer* view) {
	PyMem_Free(view->shape);
}

PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_new_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_init_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_SIGNED(mvec_neg_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_pos_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_abs_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_invert_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_add_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_sub_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_mul_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_div_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_mod_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_floordiv_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_divmod_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_lshift_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_rshift_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_and_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_or_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_xor_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_pow_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_iadd_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_isub_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_imul_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_idiv_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_imod_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_ifloordiv_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_imatmul_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_ilshift_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_irshift_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_iand_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_ixor_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(mvec_ior_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(mvec_ipow_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_str_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_2_THRU_4(mvec_len_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_sq_item_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_sq_ass_item_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_contains_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_richcompare_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(unswizzle_mvec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(unswizzle2_mvec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_getattr_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_setattr_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvecIter_new_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvecIter_dealloc_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvecIter_next_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_geniter_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_getbuffer_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_hash_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_to_list_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_to_tuple_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_setstate_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_copy_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(mvec_deepcopy_TEMPLATE);
