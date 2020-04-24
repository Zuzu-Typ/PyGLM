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
	Py_TYPE(self)->tp_free(self);
}

template<typename T>
static PyObject *
qua_new(PyTypeObject *type, PyObject *, PyObject *)
{
	qua<T> *self = (qua<T> *)type->tp_alloc(type, 0);
	if (self != NULL) {
		constexpr uint8_t info_type = get_type_helper_type<T>();
		constexpr uint8_t info = 4 | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		self->info = info;
		self->super_type = glm::qua<T>();
	}

	return (PyObject *)self;
}

template<typename T>
static int
qua_init(qua<T> *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", "z", "w", NULL };

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
			if (PyGLM_Qua_Check(T, arg1)) {
				glm::qua<T> o;
				if (unpack_qua(arg1, o)) {
					self->super_type = o;
					return 0;
				}
			}
			else if (PyGLM_Vec_Check(3, T, arg1)) {
				glm::vec<3, T> o;
				if (unpack_vec(arg1, o)) {
					self->super_type = glm::qua<T>(o);
					return 0;
				}
			}
			else if (PyGLM_Mat_Check(3, 3, T, arg1)) {
				glm::mat<3, 3, T> o;
				if (unpack_mat(arg1, o)) {
					self->super_type = glm::qua<T>(o);
					return 0;
				}
			}
			else if (PyGLM_Mat_Check(4, 4, T, arg1)) {
				glm::mat<4, 4, T> o;
				if (unpack_mat(arg1, o)) {
					self->super_type = glm::qua<T>(o);
					return 0;
				}
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				glm::vec<3, T> o;
				if (!unpack_vec(arg2, o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
					return -1;
				}
				self->super_type = glm::qua<T>(PyGLM_Number_FromPyObject<T>(arg1), o);
				return 0;
			}
			glm::vec<3, T> o;
			if (!unpack_vec(arg1, o)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}
			glm::vec<3, T> o2;
			if (!unpack_vec(arg2, o2)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}
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
	glm::qua<T> o;

	if (!unpack_qua(obj1, o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.qua' and ", obj1);
		return NULL;
	}

	glm::qua<T> o2;

	if (!unpack_qua(obj2, o2)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a qua
	return pack_qua<T>(o + o2);
}

template<typename T>
static PyObject *
qua_sub(PyObject *obj1, PyObject *obj2)
{
	glm::qua<T> o;

	if (!unpack_qua(obj1, o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm.qua' and ", obj1);
		return NULL;
	}

	glm::qua<T> o2;

	if (!unpack_qua(obj2, o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

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

	if (PyGLM_Vec_Check(3, T, obj1)) {
		return pack_vec<3, T>(unpack_vec<3, T>(obj1) * ((qua<T>*)obj2)->super_type);
	}

	if (PyGLM_Vec_Check(4, T, obj1)) {
		return pack_vec<4, T>(unpack_vec<4, T>(obj1) * ((qua<T>*)obj2)->super_type);
	}

	glm::qua<T> o;

	if (!unpack_qua(obj1, o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm.qua' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_qua<T>(o * PyGLM_Number_FromPyObject<T>(obj2));
	}

	if (PyGLM_Vec_Check(3, T, obj2)) {
		return pack_vec<3, T>(o * unpack_vec<3, T>(obj2));
	}

	if (PyGLM_Vec_Check(4, T, obj2)) {
		return pack_vec<4, T>(o * unpack_vec<4, T>(obj2));
	}

	glm::qua<T> o2;

	if (!unpack_qua(obj2, o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a qua
	return pack_qua<T>(o * o2);
}

template<typename T>
static PyObject *
qua_div(PyObject *obj1, PyObject *obj2)
{
	glm::qua<T> o;

	if (!unpack_qua(obj1, o)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm.qua' and ", obj1);
		return NULL;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_qua<T>(o / o2);
	}

	Py_RETURN_NOTIMPLEMENTED;
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
static PyObject *
qua_str(qua<T>* self)
{
	const char* name = ((PyObject*)self)->ob_type->tp_name;
	size_t required_space = 59 + strlen(name) - 4;
	char * out = (char*)malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g, %12.6g, %12.6g )", &name[4], (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z, (double)self->super_type.w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

template<typename T>
static PyObject *
qua_repr(qua<T>* self)
{
	const char* name = ((PyObject*)self)->ob_type->tp_name;
	size_t required_space = 59 + strlen(name) - 4;
	char * out = (char*)malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %.6g, %.6g, %.6g, %.6g )", &name[4], (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z, (double)self->super_type.w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
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
	glm::qua<T> o2;

	if (!unpack_qua(other, o2)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

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
	if ((flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS) {
		PyErr_SetString(PyExc_BufferError, "This type of buffer is not supported.");
		view->obj = NULL;
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
		view->shape = (Py_ssize_t*)malloc(sizeof(Py_ssize_t));
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

void
qua_releasebuffer(PyObject*, Py_buffer* view) {
	free(view->shape);
}

template<typename T>
static PyObject*
qua_to_list(qua<T>* self, PyObject*) {
	PyObject* out = PyList_New(4);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type.x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type.y));
	PyList_SET_ITEM(out, 2, PyGLM_PyObject_FromNumber<T>(self->super_type.z));
	PyList_SET_ITEM(out, 3, PyGLM_PyObject_FromNumber<T>(self->super_type.w));
	return out;
}

template<typename T>
static PyObject*
qua_to_tuple(qua<T>* self, PyObject*) {
	return PyTuple_Pack(4,
		PyGLM_PyObject_FromNumber<T>(self->super_type.x),
		PyGLM_PyObject_FromNumber<T>(self->super_type.y),
		PyGLM_PyObject_FromNumber<T>(self->super_type.z),
		PyGLM_PyObject_FromNumber<T>(self->super_type.w));
}