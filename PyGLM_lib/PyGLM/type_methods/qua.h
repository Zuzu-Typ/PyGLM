#pragma once

#include "../compiler_setup.h"

#include "../internal_functions/all.h"

#include "../types/qua/all.h"

static PyObject* qua_length(PyObject*, PyObject*) {
	return PyLong_FromLong(4);
}

static void
qua_dealloc(PyObject* self)
{
	if (self != NULL) Py_TYPE(self)->tp_free(self);
}

template<typename T>
static PyObject *
qua_new(PyTypeObject *type, PyObject *, PyObject *)
{
	qua<T> *self = (qua<T> *)type->tp_alloc(type, 0);
	if (self != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = 4 | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		//self->info = info;
		self->super_type = glm::qua<T>();
	}

	return (PyObject *)self;
}

template<typename T>
static int
qua_init(qua<T> *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "w", "x", "y", "z", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;
	PyObject * arg4 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOOO", const_cast<char**>(kwlist),
		&arg1, &arg2, &arg3, &arg4)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			PyGLM_PTI_Init0(arg1, PyGLM_T_ALL | PyGLM_SHAPE_3 | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4 | PyGLM_PTI_GetDT(T));
			if (PyGLM_Qua_PTI_Check0(T, arg1)) {
				self->super_type = PyGLM_Qua_PTI_Get0(T, arg1);
				return 0;
			}
			else if (PyGLM_Vec_PTI_Check0(3, T, arg1)) {
				self->super_type = glm::qua<T>(PyGLM_Vec_PTI_Get0(3, T, arg1));
				return 0;
			}
			else if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
				self->super_type = glm::qua<T>(PyGLM_Mat_PTI_Get0(3, 3, T, arg1));
				return 0;
			}
			else if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
				self->super_type = glm::qua<T>(PyGLM_Mat_PTI_Get0(4, 4, T, arg1));
				return 0;
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_DT_ALL);
			if (PyGLM_Qua_PTI_Check0(float, arg1)) {
				self->super_type = PyGLM_Qua_PTI_Get0(float, arg1);
				return 0;
			}
			else if (PyGLM_Qua_PTI_Check0(double, arg1)) {
				self->super_type = PyGLM_Qua_PTI_Get0(double, arg1);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<3, T>()));
				if (PyGLM_PTI_IsNone(1)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
					return -1;
				}
				glm::vec<3, T> o = PyGLM_Vec_PTI_Get1(3, T, arg2);
				self->super_type = glm::qua<T>(PyGLM_Number_FromPyObject<T>(arg1), o);
				return 0;
			}
			PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<3, T>()));
			PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<3, T>()));
			if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}
			PyGLM_Vec_PTI_Assign0(3, T);
			PyGLM_Vec_PTI_Assign1(3, T);
			self->super_type = glm::qua<T>(o, o2);
			return 0;
		}
		if (arg4 == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
			self->super_type = glm::qua<T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
	return -1;
}

// unaryfunc
template<typename T>
static PyObject *
qua_neg(qua<T> *obj)
{
	return pack_qua<T>(-obj->super_type);
}

template<typename T>
static PyObject *
qua_pos(qua<T> *obj)
{
	return pack_qua<T>(obj->super_type);
}

// binaryfunc
template<typename T>
static PyObject *
qua_add(PyObject *obj1, PyObject *obj2)
{
	PyGLM_PTI_Init0(obj1, (get_qua_PTI_info<T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.qua' and ", obj1);
		return NULL;
	}

	PyGLM_PTI_Init1(obj2, (get_qua_PTI_info<T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::qua<T> o = PyGLM_Qua_PTI_Get0(T, obj1);
	glm::qua<T> o2 = PyGLM_Qua_PTI_Get1(T, obj2);

	// obj1 and obj2 can be interpreted as a qua
	return pack_qua<T>(o + o2);
}

template<typename T>
static PyObject *
qua_sub(PyObject *obj1, PyObject *obj2)
{
	PyGLM_PTI_Init0(obj1, (get_qua_PTI_info<T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm.qua' and ", obj1);
		return NULL;
	}

	PyGLM_PTI_Init1(obj2, (get_qua_PTI_info<T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::qua<T> o = PyGLM_Qua_PTI_Get0(T, obj1);
	glm::qua<T> o2 = PyGLM_Qua_PTI_Get1(T, obj2);

	// obj1 and obj2 can be interpreted as a qua
	return pack_qua<T>(o - o2);
}

template<typename T>
static PyObject *
qua_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_qua<T>(PyGLM_Number_FromPyObject<T>(obj1) * ((qua<T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, PyGLM_T_QUA | PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_PTI_GetDT(T));

	if (PyGLM_Vec_PTI_Check0(3, T, obj1)) {
		return pack_vec<3, T>(PyGLM_Vec_PTI_Get0(3, T, obj1) * ((qua<T>*)obj2)->super_type);
	}

	if (PyGLM_Vec_PTI_Check0(4, T, obj1)) {
		return pack_vec<4, T>(PyGLM_Vec_PTI_Get0(4, T, obj1) * ((qua<T>*)obj2)->super_type);
	}

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm.qua' and ", obj1);
		return NULL;
	}

	glm::qua<T> o = PyGLM_Qua_PTI_Get0(T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_qua<T>(o * PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, PyGLM_T_QUA | PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_PTI_GetDT(T));

	if (PyGLM_Vec_PTI_Check1(3, T, obj2)) {
		return pack_vec<3, T>(o * PyGLM_Vec_PTI_Get1(3, T, obj2));
	}

	if (PyGLM_Vec_PTI_Check1(4, T, obj2)) {
		return pack_vec<4, T>(o * PyGLM_Vec_PTI_Get1(4, T, obj2));
	}

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::qua<T> o2 = PyGLM_Qua_PTI_Get1(T, obj2);

	// obj1 and obj2 can be interpreted as a qua
	return pack_qua<T>(o * o2);
}

template<typename T>
static PyObject *
qua_div(PyObject *obj1, PyObject *obj2)
{
	PyGLM_PTI_Init0(obj1, (get_qua_PTI_info<T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm.qua' and ", obj1);
		return NULL;
	}

	glm::qua<T> o = PyGLM_Qua_PTI_Get0(T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_qua<T>(o / o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject*
qua_matmul(PyObject* obj1, PyObject* obj2)
{
	PyObject* out = PyNumber_Multiply(obj1, obj2);
	if (out == NULL) {
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for @: ", obj1, obj2);
	}
	return out;
}

// inplace
// binaryfunc
template<typename T>
static PyObject *
qua_iadd(qua<T> *self, PyObject *obj)
{
	qua<T> * temp = (qua<T>*)qua_add<T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<typename T>
static PyObject *
qua_isub(qua<T> *self, PyObject *obj)
{
	qua<T> * temp = (qua<T>*)qua_sub<T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<typename T>
static PyObject *
qua_imul(qua<T> *self, PyObject *obj)
{
	qua<T> * temp = (qua<T>*)qua_mul<T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Qua_Check(T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<typename T>
static PyObject *
qua_idiv(qua<T> *self, PyObject *obj)
{
	qua<T> * temp = (qua<T>*)qua_div<T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<typename T>
static PyObject*
qua_imatmul(qua<T>* self, PyObject* obj)
{
	qua<T>* temp = (qua<T>*)qua_matmul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Qua_Check(T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<typename T>
static PyObject *
qua_str(qua<T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 59 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g, %12.6g, %12.6g )", name, (double)self->super_type.w, (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
qua_repr(qua<T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 59 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %.6g, %.6g, %.6g, %.6g )", name, (double)self->super_type.w, (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

static Py_ssize_t qua_len(PyObject*) {
	return (Py_ssize_t)4;
}

template<typename T>
static PyObject* qua_sq_item(qua<T> * self, Py_ssize_t index) {
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	return PyGLM_PyObject_FromNumber<T>((T)self->super_type[(glm::length_t)index]);
}

template<typename T>
static int qua_sq_ass_item(qua<T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	if (index < 0 || index > 3) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
	self->super_type[(glm::length_t)index] = f;

	return 0;
}

template<typename T>
static int qua_contains(qua<T> * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		T f = PyGLM_Number_FromPyObject<T>(value);
		bool contains = false;
		for (int i = 0; i < 4; i++) {
			if (f == self->super_type[i]) {
				contains = true;
				break;
			}
		}
		return (int)contains;
	}
	return 0;

}

template<typename T>
static PyObject * qua_richcompare(qua<T> * self, PyObject * other, int comp_type) {
	PyGLM_PTI_Init1(other, (get_qua_PTI_info<T>()));

	if (PyGLM_PTI_IsNone(1)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::qua<T> o2 = PyGLM_Qua_PTI_Get1(T, other);

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

template<typename T>
static PyObject *
quaIter_new(PyTypeObject *type, PyObject *args, PyObject *)
{
	qua<T> *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	quaIter<T> *rgstate = (quaIter<T> *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

template<typename T>
static void
quaIter_dealloc(quaIter<T> *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

template<typename T>
static PyObject *
quaIter_next(quaIter<T> *rgstate)
{
	if (rgstate->seq_index < 4) {
		return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type[rgstate->seq_index++]);
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<typename T>
static PyObject * qua_geniter(qua<T>* self) {
	quaIter<T> *rgstate = (quaIter<T> *)(PyGLM_QUAITER_TYPE<T>()->tp_alloc(PyGLM_QUAITER_TYPE<T>(), 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

template<typename T>
static int
qua_getbuffer(qua<T>* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}
	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0];
	view->len = sizeof(glm::qua<T>);
	view->readonly = 0;
	view->itemsize = sizeof(T);
	if (flags & PyBUF_FORMAT) {
		view->format = (std::is_same<T, float>::value) ? const_cast<char*>("f") : \
			(std::is_same <T, double>::value) ? const_cast<char*>("d") : NULL;
	}
	else {
		view->format = NULL;
	}
	view->ndim = 1;
	if (flags & PyBUF_ND) {
		view->shape = (Py_ssize_t*)PyMem_Malloc(sizeof(Py_ssize_t));
		if (view->shape != NULL) {
			view->shape[0] = 4;
		}
	}
	else {
		view->shape = NULL;
	}
	if (flags & PyBUF_STRIDES) {
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

static void
qua_releasebuffer(PyObject*, Py_buffer* view) {
	PyMem_Free(view->shape);
}

template<typename T>
static PyObject*
qua_from_bytes(PyObject*, PyObject* arg) {
	PyTypeObject* type = PyGLM_QUA_TYPE<T>();
	if (PyBytes_Check(arg) && PyBytes_GET_SIZE(arg) == ((PyGLMTypeObject*)type)->itemSize) {
		char* bytesAsString = PyBytes_AS_STRING(arg);
		qua<T>* self = (qua<T> *)type->tp_alloc(type, 0);
		self->super_type = *(glm::qua<T>*)bytesAsString;
		return (PyObject*)self;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for from_bytes(). Expected bytes, got ", arg);
	return NULL;
}

template<typename T>
static Py_hash_t
qua_hash(qua<T>* self, PyObject*) {
	std::hash<glm::qua<T>> hasher;
	Py_hash_t out = (Py_hash_t)hasher(self->super_type);
	if (out == -1) {
		return -2;
	}
	return out;
}

template<typename T>
static PyObject*
qua_to_list(qua<T>* self, PyObject*) {
	PyObject* out = PyList_New(4);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type.w));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type.x));
	PyList_SET_ITEM(out, 2, PyGLM_PyObject_FromNumber<T>(self->super_type.y));
	PyList_SET_ITEM(out, 3, PyGLM_PyObject_FromNumber<T>(self->super_type.z));
	return out;
}

template<typename T>
static PyObject*
qua_to_tuple(qua<T>* self, PyObject*) {
	return PyTuple_Pack(4,
		PyGLM_PyObject_FromNumber<T>(self->super_type.w),
		PyGLM_PyObject_FromNumber<T>(self->super_type.x),
		PyGLM_PyObject_FromNumber<T>(self->super_type.y),
		PyGLM_PyObject_FromNumber<T>(self->super_type.z));
}

template<typename T>
static PyObject* qua_setstate(qua<T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 4, "Invalid state. Expected a length 4 tuple.");
	self->super_type.w = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type.x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	self->super_type.y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 2));
	self->super_type.z = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 3));
	Py_RETURN_NONE;
}