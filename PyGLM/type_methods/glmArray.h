#pragma once

#include "../compiler_setup.h"

#include "../internal_functions/all.h"

#include "../types/glmArray/glmArray.h"

static PyObject*
glmArray_getPtr(glmArray* self, void*) {
	return PyGLM_CtypesVoidP_FromVoidP(self->data);
}

static PyObject* 
glmArray_getDtype(glmArray* self, void*) {
	switch (self->format) {
	case 'f':
		return PyUnicode_FromString("float32");
	case 'd':
		return PyUnicode_FromString("float64");
	case 'i':
		return PyUnicode_FromString("int32");
	case 'I':
		return PyUnicode_FromString("uint32");
	case 'b':
		return PyUnicode_FromString("int8");
	case 'B':
		return PyUnicode_FromString("uint8");
	case 'h':
		return PyUnicode_FromString("int16");
	case 'H':
		return PyUnicode_FromString("uint16");
	case 'q':
		return PyUnicode_FromString("int64");
	case 'Q':
		return PyUnicode_FromString("uint64");
	case '?':
		return PyUnicode_FromString("bool");
	default:
		PyGLM_ASSERT(0, "Invalid format specifier. This should not have happened.");
	}
}

#define GLM_ARRAY_SET_IF_IS_MAT(T) switch (self->shape[0]) {\
case 2:\
	switch (self->shape[1]) {\
	case 2:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<2, 2, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<2, 2, T>*)self->data) + index) = ((mat<2, 2, T>*)value)->super_type;\
		return 0;\
	case 3:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<2, 3, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<2, 3, T>*)self->data) + index) = ((mat<2, 3, T>*)value)->super_type;\
		return 0;\
	case 4:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<2, 4, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<2, 4, T>*)self->data) + index) = ((mat<2, 4, T>*)value)->super_type;\
		return 0;\
	default:\
		PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");\
		return -1;\
	}\
case 3:\
	switch (self->shape[1]) {\
	case 2:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<3, 2, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<3, 2, T>*)self->data) + index) = ((mat<3, 2, T>*)value)->super_type;\
		return 0;\
	case 3:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<3, 3, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<3, 3, T>*)self->data) + index) = ((mat<3, 3, T>*)value)->super_type;\
		return 0;\
	case 4:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<3, 4, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<3, 4, T>*)self->data) + index) = ((mat<3, 4, T>*)value)->super_type;\
		return 0;\
	default:\
		PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");\
		return -1;\
	}\
case 4:\
	switch (self->shape[1]) {\
	case 2:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<4, 2, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<4, 2, T>*)self->data) + index) = ((mat<4, 2, T>*)value)->super_type;\
		return 0;\
	case 3:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<4, 3, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<4, 3, T>*)self->data) + index) = ((mat<4, 3, T>*)value)->super_type;\
		return 0;\
	case 4:\
		if (!PyObject_TypeCheck(value, (PyGLM_MAT_TYPE<4, 4, T>()))) {\
			PyGLM_TYPEERROR_O("invalid assignment type ", value);\
			return -1;\
		}\
		*(((glm::mat<4, 4, T>*)self->data) + index) = ((mat<4, 4, T>*)value)->super_type;\
		return 0;\
	default:\
		PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");\
		return -1;\
	}\
default:\
	PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");\
	return -1;\
}

#define GLM_ARRAY_SET_IF_IS_VEC(T) switch (self->shape[0]) {\
case 1:\
	if (PyObject_TypeCheck(value, (PyGLM_VEC_TYPE<1, T>()))) {\
		*(((glm::vec<1, T>*)self->data) + index) = ((vec<1, T>*)value)->super_type;\
	}\
	else if (PyObject_TypeCheck(value, (PyGLM_MVEC_TYPE<1, T>()))) {\
		*(((glm::vec<1, T>*)self->data) + index) = *((mvec<1, T>*)value)->super_type;\
	}\
	else {\
		PyGLM_TYPEERROR_O("invalid assignment type ", value);\
		return -1;\
	}\
	return 0;\
case 2:\
	if (PyObject_TypeCheck(value, (PyGLM_VEC_TYPE<2, T>()))) {\
		*(((glm::vec<2, T>*)self->data) + index) = ((vec<2, T>*)value)->super_type;\
	}\
	else if (PyObject_TypeCheck(value, (PyGLM_MVEC_TYPE<2, T>()))) {\
		*(((glm::vec<2, T>*)self->data) + index) = *((mvec<2, T>*)value)->super_type;\
	}\
	else {\
		PyGLM_TYPEERROR_O("invalid assignment type ", value);\
		return -1;\
	}\
	return 0;\
case 3:\
	if (PyObject_TypeCheck(value, (PyGLM_VEC_TYPE<3, T>()))) {\
		*(((glm::vec<3, T>*)self->data) + index) = ((vec<3, T>*)value)->super_type;\
	}\
	else if (PyObject_TypeCheck(value, (PyGLM_MVEC_TYPE<3, T>()))) {\
		*(((glm::vec<3, T>*)self->data) + index) = *((mvec<3, T>*)value)->super_type;\
	}\
	else {\
		PyGLM_TYPEERROR_O("invalid assignment type ", value);\
		return -1;\
	}\
	return 0;\
case 4:\
	if (PyObject_TypeCheck(value, (PyGLM_VEC_TYPE<4, T>()))) {\
		*(((glm::vec<4, T>*)self->data) + index) = ((vec<4, T>*)value)->super_type;\
	}\
	else if (PyObject_TypeCheck(value, (PyGLM_MVEC_TYPE<4, T>()))) {\
		*(((glm::vec<4, T>*)self->data) + index) = *((mvec<4, T>*)value)->super_type;\
	}\
	else {\
		PyGLM_TYPEERROR_O("invalid assignment type ", value);\
		return -1;\
	}\
	return 0;\
default:\
	PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");\
	return -1;\
}

#define GLM_ARRAY_SET_IF_IS_QUA(T) if (!PyObject_TypeCheck(value, (PyGLM_QUA_TYPE<T>()))) {\
	PyGLM_TYPEERROR_O("invalid assignment type ", value);\
	return -1; \
}\
*(((glm::qua<T>*)self->data) + index) = ((qua<T>*)value)->super_type;\
return 0;

int glmArray_set(glmArray* self, ssize_t index, PyObject* value) {
	if (index >= self->itemCount) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (index < 0) {
		return glmArray_set(self, self->itemCount - index, value);
	}
	if (self->glmType == PyGLM_TYPE_VEC) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_SET_IF_IS_VEC(float);
		case 'd':
			GLM_ARRAY_SET_IF_IS_VEC(double);
		case 'i':
			GLM_ARRAY_SET_IF_IS_VEC(int32);
		case 'I':
			GLM_ARRAY_SET_IF_IS_VEC(uint32);
		case 'b':
			GLM_ARRAY_SET_IF_IS_VEC(int8);
		case 'B':
			GLM_ARRAY_SET_IF_IS_VEC(uint8);
		case 'h':
			GLM_ARRAY_SET_IF_IS_VEC(int16);
		case 'H':
			GLM_ARRAY_SET_IF_IS_VEC(uint16);
		case 'q':
			GLM_ARRAY_SET_IF_IS_VEC(int64);
		case 'Q':
			GLM_ARRAY_SET_IF_IS_VEC(uint64);
		case '?':
			GLM_ARRAY_SET_IF_IS_VEC(bool);
		default:
			PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened."); 
			return -1; 
		}
	}
	if (self->glmType == PyGLM_TYPE_MAT) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_SET_IF_IS_MAT(float);
		case 'd':
			GLM_ARRAY_SET_IF_IS_MAT(double);
		case 'i':
			GLM_ARRAY_SET_IF_IS_MAT(int32);
		case 'I':
			GLM_ARRAY_SET_IF_IS_MAT(uint32);
		default:
			PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");
			return -1;
		}
	}
	if (self->glmType == PyGLM_TYPE_QUA) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_SET_IF_IS_QUA(float);
		case 'd':
			GLM_ARRAY_SET_IF_IS_QUA(double);
		default:
			PyErr_SetString(PyExc_AssertionError, "Invalid shape occured. This should not have happened.");
			return -1;
		}
	}
	return NULL;
}

#define GLM_ARRAY_GET_IF_IS_MAT(T) switch (self->shape[0]) {\
case 2:\
	switch (self->shape[1]) {\
	case 2:\
		return pack(*(((glm::mat<2, 2, T>*)self->data) + index));\
	case 3:\
		return pack(*(((glm::mat<2, 3, T>*)self->data) + index));\
	case 4:\
		return pack(*(((glm::mat<2, 4, T>*)self->data) + index));\
	default:\
		PyGLM_ASSERT(0, "Invalid shape occured. This should not have happened.");\
	}\
case 3:\
	switch (self->shape[1]) {\
	case 2:\
		return pack(*(((glm::mat<3, 2, T>*)self->data) + index));\
	case 3:\
		return pack(*(((glm::mat<3, 3, T>*)self->data) + index));\
	case 4:\
		return pack(*(((glm::mat<3, 4, T>*)self->data) + index));\
	default:\
		PyGLM_ASSERT(0, "Invalid shape occured. This should not have happened.");\
	}\
case 4:\
	switch (self->shape[1]) {\
	case 2:\
		return pack(*(((glm::mat<4, 2, T>*)self->data) + index));\
	case 3:\
		return pack(*(((glm::mat<4, 3, T>*)self->data) + index));\
	case 4:\
		return pack(*(((glm::mat<4, 4, T>*)self->data) + index));\
	default:\
		PyGLM_ASSERT(0, "Invalid shape occured. This should not have happened.");\
	}\
default:\
	PyGLM_ASSERT(0, "Invalid shape occured. This should not have happened.");\
}

#define GLM_ARRAY_GET_IF_IS_VEC(T) switch (self->shape[0]) {\
case 1:\
	return pack(*(((glm::vec<1, T>*)self->data) + index));\
case 2:\
	return pack(*(((glm::vec<2, T>*)self->data) + index));\
case 3:\
	return pack(*(((glm::vec<3, T>*)self->data) + index));\
case 4:\
	return pack(*(((glm::vec<4, T>*)self->data) + index));\
default:\
	PyGLM_ASSERT(0, "Invalid shape occured. This should not have happened.");\
}

#define GLM_ARRAY_GET_IF_IS_QUA(T) return pack(*(((glm::qua<T>*)self->data) + index));

PyObject* glmArray_get(glmArray* self, ssize_t index) {
	if (index >= self->itemCount) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (index < 0) {
		return glmArray_get(self, self->itemCount - index);
	}
	if (self->glmType == PyGLM_TYPE_VEC) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_GET_IF_IS_VEC(float);
		case 'd':
			GLM_ARRAY_GET_IF_IS_VEC(double);
		case 'i':
			GLM_ARRAY_GET_IF_IS_VEC(int32);
		case 'I':
			GLM_ARRAY_GET_IF_IS_VEC(uint32);
		case 'b':
			GLM_ARRAY_GET_IF_IS_VEC(int8);
		case 'B':
			GLM_ARRAY_GET_IF_IS_VEC(uint8);
		case 'h':
			GLM_ARRAY_GET_IF_IS_VEC(int16);
		case 'H':
			GLM_ARRAY_GET_IF_IS_VEC(uint16);
		case 'q':
			GLM_ARRAY_GET_IF_IS_VEC(int64);
		case 'Q':
			GLM_ARRAY_GET_IF_IS_VEC(uint64);
		case '?':
			GLM_ARRAY_GET_IF_IS_VEC(bool);
		default:
			PyGLM_ASSERT(0, "Invalid format specifier. This should not have happened.");
		}
	}
	if (self->glmType == PyGLM_TYPE_MAT) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_GET_IF_IS_MAT(float);
		case 'd':
			GLM_ARRAY_GET_IF_IS_MAT(double);
		case 'i':
			GLM_ARRAY_GET_IF_IS_MAT(int32);
		case 'I':
			GLM_ARRAY_GET_IF_IS_MAT(uint32);
		default:
			PyGLM_ASSERT(0, "Invalid format specifier. This should not have happened.");
		}
	}
	if (self->glmType == PyGLM_TYPE_QUA) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_GET_IF_IS_QUA(float);
		case 'd':
			GLM_ARRAY_GET_IF_IS_QUA(double);
		default:
			PyGLM_ASSERT(0, "Invalid format specifier. This should not have happened.");
		}
	}
	return NULL;
}

static int 
glmArray_getbuffer(glmArray* self, Py_buffer* view, int flags) {
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
	view->buf = self->data;
	view->len = self->nBytes;
	view->readonly = 0;
	view->itemsize = self->dtSize;
	if (flags & PyBUF_FORMAT) {
		view->format = (char*)malloc(sizeof(char)*2);
		view->format[0] = self->format;
		view->format[1] = '\x00';
	}
	else {
		view->format = NULL;
	}
	if (self->glmType == PyGLM_TYPE_MAT) {
		const int C = self->getShape(0);
		const int R = self->getShape(1);

		view->ndim = 3;
		if (flags & PyBUF_ND) {
			view->shape = (Py_ssize_t*)malloc(3 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = C;
				view->shape[2] = R;
			}
		}
		else {
			view->shape = NULL;
		}
		if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
			view->strides = (Py_ssize_t*)malloc(3 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = C * R * self->dtSize;
				view->strides[1] = R * self->dtSize;
				view->strides[2] = self->dtSize;
			}
		}
		else {
			view->strides = NULL;
		}
	}
	else if (self->glmType == PyGLM_TYPE_VEC) {
		const int L = self->getShape();

		view->ndim = 2;
		if (flags & PyBUF_ND) {
			view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = L;
			}
		}
		else {
			view->shape = NULL;
		}
		if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
			view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = L * self->dtSize;
				view->strides[1] = self->dtSize;
			}
		}
		else {
			view->strides = NULL;
		}
	}
	else if (self->glmType == PyGLM_TYPE_QUA) {
		view->ndim = 2;
		if (flags & PyBUF_ND) {
			view->shape = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = 4;
			}
		}
		else {
			view->shape = NULL;
		}
		if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
			view->strides = (Py_ssize_t*)malloc(2 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = 4 * self->dtSize;
				view->strides[1] = self->dtSize;
			}
		}
		else {
			view->strides = NULL;
		}
	}
	
	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

void 
glmArray_releasebuffer(PyObject* self, Py_buffer* view) {
	free(view->shape);
	free(view->strides);
	free(view->format);
}


static PyObject* 
glmArray_to_list(glmArray* self, PyObject*) {
	PyObject* out = PyList_New(self->itemCount);
	for (ssize_t i = 0; i < self->itemCount; i++) {
		PyList_SET_ITEM(out, i, glmArray_get(self, i));
	}
	return out;
}


static PyObject* 
glmArray_to_tuple(glmArray* self, PyObject*) {
	PyObject* out = PyTuple_New(self->itemCount);
	for (ssize_t i = 0; i < self->itemCount; i++) {
		PyTuple_SET_ITEM(out, i, glmArray_get(self, i));
	}
	return out;
}

static Py_ssize_t 
glmArray_len(glmArray* self) { 
	return self->itemCount;
}

static PyObject* glmArray_concat(PyObject* obj1, PyObject* obj2) {
	if (!PyObject_TypeCheck(obj1, &glmArrayType) || !PyObject_TypeCheck(obj2, &glmArrayType)) {
		PyGLM_TYPEERROR_2O("invalid operand type(s) for +: ", obj1, obj2);
		return NULL;
	}

	glmArray* arr1 = (glmArray*)obj1;
	glmArray* arr2 = (glmArray*)obj2;

	if (arr1->subtype != arr2->subtype) {
		PyErr_SetString(PyExc_ValueError, "the given arrays are incompatible");
		return NULL;
	}
	PyGLM_ASSERT((
		arr1->format == arr2->format && 
		arr1->glmType == arr2->glmType && 
		arr1->itemSize == arr2->itemSize && 
		arr1->dtSize == arr2->dtSize && 
		memcmp(arr1->shape, arr2->shape, sizeof(arr1->shape)) == 0
		),
		"the given arrays are incompatible. (though this error shouldn't have been caught by this assertion)");

	glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);
	PyGLM_ASSERT((out != NULL), "generated array was NULL. (maybe we're out of memory?)");

	out->dtSize = arr1->dtSize;
	out->format = arr1->format;
	out->glmType = arr1->glmType;
	out->itemCount = arr1->itemCount + arr2->itemCount;
	out->itemSize = arr1->itemSize;
	out->nBytes = arr1->nBytes + arr2->nBytes;
	memcpy(out->shape, arr1->shape, sizeof(out->shape));
	out->subtype = arr1->subtype;

	out->data = malloc(out->nBytes);
	if (out->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	memcpy(out->data, arr1->data, arr1->nBytes);
	memcpy(((char*)out->data) + arr1->nBytes, arr2->data, arr2->nBytes);

	return (PyObject*)out;
}

static PyObject* glmArray_repeat(glmArray* self, Py_ssize_t count) {
	glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);
	PyGLM_ASSERT((out != NULL), "generated array was NULL. (maybe we're out of memory?)");

	out->dtSize = self->dtSize;
	out->format = self->format;
	out->glmType = self->glmType;
	out->itemCount = self->itemCount * count;
	out->itemSize = self->itemSize;
	out->nBytes = self->nBytes * count;
	memcpy(out->shape, self->shape, sizeof(out->shape));
	out->subtype = self->subtype;

	out->data = malloc(out->nBytes);
	if (out->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	for (ssize_t i = 0; i < count; i++) {
		ssize_t offset = i * self->nBytes;
		memcpy(((char*)out->data) + offset, self->data, self->nBytes);
	}

	return (PyObject*)out;
}

static PyObject* glmArray_inplace_concat(glmArray* self, PyObject* obj) {
	glmArray* temp = (glmArray*)glmArray_concat((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	memcpy(((char*)self) + PyGLM_ARRAY_OFFSET, ((char*)temp) + PyGLM_ARRAY_OFFSET, PyGLM_ARRAY_SIZE - sizeof(self->data));
	self->data = malloc(self->nBytes);
	memcpy(self->data, temp->data, self->nBytes);

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject* glmArray_inplace_repeat(glmArray* self, Py_ssize_t count) {
	glmArray* temp = (glmArray*)glmArray_repeat(self, count);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	memcpy(((char*)self) + PyGLM_ARRAY_OFFSET, ((char*)temp) + PyGLM_ARRAY_OFFSET, PyGLM_ARRAY_SIZE - sizeof(self->data));
	self->data = malloc(self->nBytes);
	memcpy(self->data, temp->data, self->nBytes);

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject* 
glmArray_sq_item(glmArray* self, Py_ssize_t index) {
	return glmArray_get(self, index);
}

static int 
glmArray_sq_ass_item(glmArray* self, Py_ssize_t index, PyObject* value) {
	return glmArray_set(self, index, value);
}


static int 
glmArray_contains(glmArray* self, PyObject* value) {
	for (ssize_t i = 0; i < self->itemCount; i++) {
		PyObject* itemAtIndex = glmArray_get(self, i);
		int cmp = PyObject_RichCompareBool(itemAtIndex, value, Py_EQ);
		if (cmp == 1) {
			Py_DECREF(itemAtIndex);
			return 1;
		}
		else if (cmp == -1)
			return -1;

		Py_DECREF(itemAtIndex);
	}
	return 0;
}

static void 
glmArray_dealloc(glmArray* self) {
	free(self->data);
	self->data = NULL;
	Py_TYPE(self)->tp_free(self);
}

template<typename T>
static PyObject*
glmArray_str_vec(glmArray* self) {
	const int L = self->getShape();

	uint64 itemSize = (7 + 12 + (L - 1) * (12 + 2));
	uint64 outLength = 1 + 3 + itemSize * self->itemCount;

	char* out = (char*)malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;

	for (ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		T* values = &((T*)self->data)[itemIndex * L];
		snprintf(currentIndex, 3 + 12 + 1, " [ %12.6g", static_cast<double>(values[0]));
		currentIndex += 3 + 12;

		for (ssize_t valueIndex = 1; valueIndex < L; valueIndex++) {
			snprintf(currentIndex, 2 + 12 + 1, ", %12.6g", static_cast<double>(values[valueIndex]));
			currentIndex += 2 + 12;
		}

		snprintf(currentIndex, 4 + 1, " ],\n");
		currentIndex += 4;
	}

	snprintf(currentIndex, 1 + 1, "]");

	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_vec(glmArray* self) {
	const int L = self->getShape();

	const char*& subtypeName = self->subtype->tp_name;

	const uint64 arrayNameLength = strlen(glmArrayType.tp_name);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 itemSize = (subtypeNameLength + 2 + 12 + (L - 1) * (12 + 2));
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize * self->itemCount;

	char* out = (char*)malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", glmArrayType.tp_name);
	currentIndex += arrayNameLength + 1;

	for (ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		T* values = &((T*)self->data)[itemIndex * L];
		snprintf(currentIndex, subtypeNameLength + 1 + 12 + 1, "%s(%g", subtypeName, static_cast<double>(values[0]));
		currentIndex += strlen(currentIndex);

		for (ssize_t valueIndex = 1; valueIndex < L; valueIndex++) {
			snprintf(currentIndex, 2 + 12 + 1, ", %g", static_cast<double>(values[valueIndex]));
			currentIndex += strlen(currentIndex);
		}

		if (itemIndex < self->itemCount - 1) {
			snprintf(currentIndex, 3 + 1, "), ");
			currentIndex += 3;
		}
		else {
			snprintf(currentIndex, 1 + 1, ")");
			currentIndex += 1;
		}
	}

	snprintf(currentIndex, 1 + 1, ")");

	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_str_mat(glmArray* self) {
	const int C = self->getShape(0);
	const int R = self->getShape(1);

	uint64 subItemSize = (8 + 12 + (R - 1) * (12 + 2));
	uint64 itemSize = 7 + subItemSize * C;
	uint64 outLength = 1 + 3 + itemSize * self->itemCount;

	char* out = (char*)malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;
	for (ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		snprintf(currentIndex, 3 + 1, " [\n");
		currentIndex += 3;

		for (ssize_t columnIndex = 0; columnIndex < C; columnIndex++) {
			T* values = &((T*)self->data)[itemIndex * (C * R) + columnIndex * R];
			snprintf(currentIndex, 4 + 12 + 1, "  [ %12.6g", static_cast<double>(values[0]));
			currentIndex += 4 + 12;

			for (ssize_t valueIndex = 1; valueIndex < R; valueIndex++) {
				snprintf(currentIndex, 2 + 12 + 1, ", %12.6g", static_cast<double>(values[valueIndex]));
				currentIndex += 2 + 12;
			}

			snprintf(currentIndex, 4 + 1, " ],\n");
			currentIndex += 4;
		}
		

		snprintf(currentIndex, 4 + 1, " ],\n");
		currentIndex += 4;
	}

	snprintf(currentIndex, 1 + 1, "]");

	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_mat(glmArray* self) {
	const int C = self->getShape(0);
	const int R = self->getShape(1);

	const char*& subtypeName = self->subtype->tp_name;

	const uint64 arrayNameLength = strlen(glmArrayType.tp_name);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 subItemSize = (2 + 12 + (R - 1) * (12 + 2));
	const uint64 itemSize = subtypeNameLength + 2 + subItemSize  + (subItemSize + 2) * C;
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize * self->itemCount;

	char* out = (char*)malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", glmArrayType.tp_name);
	currentIndex += arrayNameLength + 1;
	for (ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		snprintf(currentIndex, subtypeNameLength + 1 + 1, "%s(", subtypeName);
		currentIndex += subtypeNameLength + 1;

		for (ssize_t columnIndex = 0; columnIndex < C; columnIndex++) {
			T* values = &((T*)self->data)[itemIndex * (C * R) + columnIndex * R];
			snprintf(currentIndex, 1 + 12 + 1, "(%g", static_cast<double>(values[0]));
			currentIndex += strlen(currentIndex);

			for (ssize_t valueIndex = 1; valueIndex < R; valueIndex++) {
				snprintf(currentIndex, 2 + 12 + 1, ", %g", static_cast<double>(values[valueIndex]));
				currentIndex += strlen(currentIndex);
			}

			if (columnIndex < C - 1) {
				snprintf(currentIndex, 3 + 1, "), ");
				currentIndex += 3;
			}
			else {
				snprintf(currentIndex, 1 + 1, ")");
				currentIndex += 1;
			}
		}

		if (itemIndex < self->itemCount - 1) {
			snprintf(currentIndex, 3 + 1, "), ");
			currentIndex += 3;
		}
		else {
			snprintf(currentIndex, 1 + 1, ")");
			currentIndex += 1;
		}
	}

	snprintf(currentIndex, 1 + 1, ")");

	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_str_qua(glmArray* self) {
	uint64 itemSize = (13 + 12 * 4);
	uint64 outLength = 1 + 3 + itemSize * self->itemCount;

	char* out = (char*)malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;

	for (ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		T* values = &((T*)self->data)[itemIndex * 4];
		snprintf(currentIndex, 13 + 12 * 4 + 1, " [ %12.6g, %12.6g, %12.6g, %12.6g ],\n", 
			static_cast<double>(values[0]),
			static_cast<double>(values[1]),
			static_cast<double>(values[2]),
			static_cast<double>(values[3]));
		currentIndex += 13 + 12 * 4;
	}

	snprintf(currentIndex, 1 + 1, "]");

	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_qua(glmArray* self) {
	const char*& subtypeName = self->subtype->tp_name;

	const uint64 arrayNameLength = strlen(glmArrayType.tp_name);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 itemSize = (subtypeNameLength + 8 + 12 * 4);
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize * self->itemCount;

	char* out = (char*)malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", glmArrayType.tp_name);
	currentIndex += arrayNameLength + 1;

	for (ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		T* values = &((T*)self->data)[itemIndex * 4];
		if (itemIndex < self->itemCount - 1) {
			snprintf(currentIndex, itemSize + 2 + 1, "%s(%g, %g, %g, %g), ",
				subtypeName,
				static_cast<double>(values[0]),
				static_cast<double>(values[1]),
				static_cast<double>(values[2]),
				static_cast<double>(values[3]));
		}
		else {
			snprintf(currentIndex, itemSize + 1, "%s(%g, %g, %g, %g)",
				subtypeName,
				static_cast<double>(values[0]),
				static_cast<double>(values[1]),
				static_cast<double>(values[2]),
				static_cast<double>(values[3]));
		}
		currentIndex += strlen(currentIndex);
	}

	snprintf(currentIndex, 1 + 1, ")");

	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject* 
glmArray_str(glmArray* self) {
	switch (self->glmType) {
	case PyGLM_TYPE_VEC:
		switch (self->format) {
		case 'f':
			return glmArray_str_vec<float>(self);
		case 'd':
			return glmArray_str_vec<double>(self);
		case 'i':
			return glmArray_str_vec<int32>(self);
		case 'I':
			return glmArray_str_vec<uint32>(self);
		case 'b':
			return glmArray_str_vec<int8>(self);
		case 'B':
			return glmArray_str_vec<uint8>(self);
		case 'h':
			return glmArray_str_vec<int16>(self);
		case 'H':
			return glmArray_str_vec<uint16>(self);
		case 'q':
			return glmArray_str_vec<int64>(self);
		case 'Q':
			return glmArray_str_vec<uint64>(self);
		case '?':
			return glmArray_str_vec<bool>(self);
		default:
			return NULL;
		}
	case PyGLM_TYPE_MAT:
		switch (self->format) {
		case 'f':
			return glmArray_str_mat<float>(self);
		case 'd':
			return glmArray_str_mat<double>(self);
		case 'i':
			return glmArray_str_mat<int32>(self);
		case 'I':
			return glmArray_str_mat<uint32>(self);
		default:
			return NULL;
		}
	case PyGLM_TYPE_QUA:
		switch (self->format) {
		case 'f':
			return glmArray_str_qua<float>(self);
		case 'd':
			return glmArray_str_qua<double>(self);
		default:
			return NULL;
		}
	default:
		return NULL;
	}
}

static PyObject* glmArray_repr(glmArray* self) {
	switch (self->glmType) {
	case PyGLM_TYPE_VEC:
		switch (self->format) {
		case 'f':
			return glmArray_repr_vec<float>(self);
		case 'd':
			return glmArray_repr_vec<double>(self);
		case 'i':
			return glmArray_repr_vec<int32>(self);
		case 'I':
			return glmArray_repr_vec<uint32>(self);
		case 'b':
			return glmArray_repr_vec<int8>(self);
		case 'B':
			return glmArray_repr_vec<uint8>(self);
		case 'h':
			return glmArray_repr_vec<int16>(self);
		case 'H':
			return glmArray_repr_vec<uint16>(self);
		case 'q':
			return glmArray_repr_vec<int64>(self);
		case 'Q':
			return glmArray_repr_vec<uint64>(self);
		case '?':
			return glmArray_repr_vec<bool>(self);
		default:
			return NULL;
		}
	case PyGLM_TYPE_MAT:
		switch (self->format) {
		case 'f':
			return glmArray_repr_mat<float>(self);
		case 'd':
			return glmArray_repr_mat<double>(self);
		case 'i':
			return glmArray_repr_mat<int32>(self);
		case 'I':
			return glmArray_repr_mat<uint32>(self);
		default:
			return NULL;
		}
	case PyGLM_TYPE_QUA:
		switch (self->format) {
		case 'f':
			return glmArray_repr_qua<float>(self);
		case 'd':
			return glmArray_repr_qua<double>(self);
		default:
			return NULL;
		}
	default:
		return NULL;
	}
}

static PyObject* 
glmArray_getattr(PyObject* obj, PyObject* name) {
	char* name_as_ccp = PyGLM_String_AsString(name);
	if (strcmp(name_as_ccp, "ptr") == 0) {
		return PyGLM_CtypesVoidP_FromVoidP(((glmArray*)obj)->data);
	}
	return PyObject_GenericGetAttr(obj, name);
}

static int 
glmArray_setattr(PyObject* obj, PyObject* name, PyObject* value) {
	char* name_as_ccp = PyGLM_String_AsString(name);
	if (strcmp(name_as_ccp, "ptr") == 0) {
		PyErr_SetString(PyExc_AttributeError, "readonly attribute");
		return -1;
	}
	return PyObject_GenericSetAttr(obj, name, value);
}


static PyObject* 
glmArray_richcompare(glmArray* self, PyObject* other, int comp_type) {
	switch (comp_type) {
	case Py_EQ:
		if (PyObject_TypeCheck(other, &glmArrayType)) {
			if (self->nBytes == ((glmArray*)other)->nBytes && memcmp(self->data, ((glmArray*)other)->data, self->nBytes) == 0) {
				Py_RETURN_TRUE;
			}
			Py_RETURN_FALSE;
		}
		Py_RETURN_FALSE;
	case Py_NE:
		if (PyObject_TypeCheck(other, &glmArrayType)) {
			if (self->nBytes == ((glmArray*)other)->nBytes && memcmp(self->data, ((glmArray*)other)->data, self->nBytes) == 0) {
				Py_RETURN_FALSE;
			}
			Py_RETURN_TRUE;
		}
		Py_RETURN_TRUE;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}


static PyObject* 
glmArray_geniter(glmArray* self) {
	glmArrayIter* rgstate = (glmArrayIter*)(glmArrayIterType.tp_alloc(&glmArrayIterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject*)rgstate;
}

#define GLM_ARRAY_INIT_IF_IS_MAT_ITER(C, R, T) if (firstElementType == UNBRACKET (PyGLM_MAT_TYPE<C, R, T>())) {return UNBRACKET (glmArray_init_mat_iter<C, R, T>(self, firstElement, iterator, argCount));}

template<int C, int R, typename T>
static int
glmArray_init_mat_iter(glmArray* self, PyObject* firstElement, PyObject* iterator, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(glm::mat<C, R, T>);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_MAT_TYPE<C, R, T>();
	self->glmType = PyGLM_TYPE_MAT;
	self->shape[0] = C;
	self->shape[1] = R;
	self->format = get_format_specifier<T>();
	self->data = malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		Py_DECREF(iterator);
		Py_DECREF(firstElement);
		return -1;
	}
	glm::mat<C, R, T>* dataAsVecPtr = (glm::mat<C, R, T>*)self->data;
	dataAsVecPtr[0] = ((mat<C, R, T>*)firstElement)->super_type;
	Py_DECREF(firstElement);
	for (Py_ssize_t i = 1; i < argCount; i++) {
		mat<C, R, T>* currentArg = (mat<C, R, T> *)PyIter_Next(iterator);
		if (Py_TYPE(currentArg) != self->subtype) {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			Py_DECREF(iterator);
			Py_DECREF(currentArg);
			return -1;
		}
		dataAsVecPtr[i] = currentArg->super_type;
		Py_DECREF(currentArg);
	}
	Py_DECREF(iterator);
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_VEC_ITER(L, T) if (firstElementType == UNBRACKET (PyGLM_VEC_TYPE<L, T>()) || firstElementType == UNBRACKET (PyGLM_MVEC_TYPE<L, T>())) {return UNBRACKET (glmArray_init_vec_iter<L, T>(self, firstElement, iterator, argCount));}

template<int L, typename T>
static int
glmArray_init_vec_iter(glmArray* self, PyObject* firstElement, PyObject* iterator, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(glm::vec<L, T>);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_VEC_TYPE<L, T>();
	self->glmType = PyGLM_TYPE_VEC;
	self->shape[0] = L;
	self->format = get_format_specifier<T>();
	self->data = malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		Py_DECREF(iterator);
		Py_DECREF(firstElement);
		return -1;
	}
	glm::vec<L, T>* dataAsVecPtr = (glm::vec<L, T>*)self->data;
	if (Py_TYPE(firstElement) == self->subtype) {
		dataAsVecPtr[0] = ((vec<L, T>*)firstElement)->super_type;
	}
	else if (Py_TYPE(firstElement) == PyGLM_MVEC_TYPE<L, T>()) {
		dataAsVecPtr[0] = *((mvec<L, T>*)firstElement)->super_type;
	}
	Py_DECREF(firstElement);
	for (Py_ssize_t i = 1; i < argCount; i++) {
		vec<L, T>* currentArg = (vec<L, T>*)PyIter_Next(iterator);
		if (currentArg == NULL) {
			break;
		}
		if (Py_TYPE(currentArg) == self->subtype) {
			dataAsVecPtr[i] = currentArg->super_type;
		}
		else if (Py_TYPE(currentArg) == PyGLM_MVEC_TYPE<L, T>()) {
			dataAsVecPtr[i] = *((mvec<L, T>*)currentArg)->super_type;
		}
		else {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			Py_DECREF(iterator);
			Py_DECREF(currentArg);
			return -1;
		}
		Py_DECREF(currentArg);
	}
	Py_DECREF(iterator);
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_QUA_ITER(T) if (firstElementType == UNBRACKET (PyGLM_QUA_TYPE<T>())) {return UNBRACKET (glmArray_init_qua_iter<T>(self, firstElement, iterator, argCount));}

template<typename T>
static int
glmArray_init_qua_iter(glmArray* self, PyObject* firstElement, PyObject* iterator, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(glm::qua<T>);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_QUA_TYPE<T>();
	self->glmType = PyGLM_TYPE_QUA;
	self->format = get_format_specifier<T>();
	self->data = malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		Py_DECREF(iterator);
		Py_DECREF(firstElement);
		return -1;
	}
	glm::qua<T>* dataAsVecPtr = (glm::qua<T>*)self->data;
	dataAsVecPtr[0] = ((qua<T>*)firstElement)->super_type;
	Py_DECREF(firstElement);
	for (Py_ssize_t i = 1; i < argCount; i++) {
		qua<T>* currentArg = (qua<T>*)PyIter_Next(iterator);
		if (Py_TYPE(currentArg) != self->subtype) {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			Py_DECREF(iterator);
			Py_DECREF(currentArg);
			return -1;
		}
		dataAsVecPtr[i] = currentArg->super_type;
		Py_DECREF(currentArg);
	}
	Py_DECREF(iterator);
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(C, R, T) if (firstElementType == UNBRACKET (PyGLM_MAT_TYPE<C, R, T>())) {return UNBRACKET (glmArray_init_mat_tuple_or_list<C, R, T>(self, args, argCount));}

template<int C, int R, typename T>
static int
glmArray_init_mat_tuple_or_list(glmArray* self, PyObject* args, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(glm::mat<C, R, T>);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_MAT_TYPE<C, R, T>();
	self->glmType = PyGLM_TYPE_MAT;
	self->shape[0] = C;
	self->shape[1] = R;
	self->format = get_format_specifier<T>();
	self->data = malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		return -1;
	}
	glm::mat<C, R, T>* dataAsVecPtr = (glm::mat<C, R, T>*)self->data;
	for (Py_ssize_t i = 0; i < argCount; i++) {
		mat<C, R, T>* currentArg = (mat<C, R, T>*)PyGLM_TupleOrList_GET_ITEM(args, i);
		if (Py_TYPE(currentArg) != self->subtype) {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			return -1;
		}
		dataAsVecPtr[i] = currentArg->super_type;
	}
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(L, T) if (firstElementType == UNBRACKET (PyGLM_VEC_TYPE<L, T>()) || firstElementType == UNBRACKET (PyGLM_MVEC_TYPE<L, T>())) {return UNBRACKET (glmArray_init_vec_tuple_or_list<L, T>(self, args, argCount));}

template<int L, typename T>
static int
glmArray_init_vec_tuple_or_list(glmArray* self, PyObject* args, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(glm::vec<L, T>);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_VEC_TYPE<L, T>();
	self->glmType = PyGLM_TYPE_VEC;
	self->shape[0] = L;
	self->format = get_format_specifier<T>();
	self->data = malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		return -1;
	}
	glm::vec<L, T>* dataAsVecPtr = (glm::vec<L, T> *)self->data;
	for (Py_ssize_t i = 0; i < argCount; i++) {
		vec<L, T>* currentArg = (vec<L, T>*)PyGLM_TupleOrList_GET_ITEM(args, i);
		if (Py_TYPE(currentArg) == self->subtype) {
			dataAsVecPtr[i] = currentArg->super_type;
		}
		else if (Py_TYPE(currentArg) == PyGLM_MVEC_TYPE<L, T>()) {
			dataAsVecPtr[i] = *((mvec<L, T>*)currentArg)->super_type;
		}
		else {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			return -1;
		}
	}
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_QUA_TUPLE_OR_LIST(T) if (firstElementType == UNBRACKET (PyGLM_QUA_TYPE<T>())) {return UNBRACKET (glmArray_init_qua_tuple_or_list<T>(self, args, argCount));}

template<typename T>
static int
glmArray_init_qua_tuple_or_list(glmArray* self, PyObject* args, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(glm::qua<T>);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_QUA_TYPE<T>();
	self->glmType = PyGLM_TYPE_QUA;
	self->format = get_format_specifier<T>();
	self->data = malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		return -1;
	}
	glm::qua<T>* dataAsVecPtr = (glm::qua<T>*)self->data;
	for (Py_ssize_t i = 0; i < argCount; i++) {
		qua<T>* currentArg = (qua<T>*)PyGLM_TupleOrList_GET_ITEM(args, i);
		if (Py_TYPE(currentArg) != self->subtype) {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			return -1;
		}
		dataAsVecPtr[i] = currentArg->super_type;
	}
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(T) self->dtSize = sizeof(T);\
self->itemSize = L * self->dtSize;\
self->nBytes = self->itemSize * self->itemCount;\
self->subtype = (L == 1) ? PyGLM_VEC_TYPE<1, T>() : (L == 2) ? PyGLM_VEC_TYPE<2, T>() : (L == 3) ? PyGLM_VEC_TYPE<3, T>() : PyGLM_VEC_TYPE<4, T>();\
self->data = malloc(self->nBytes);\
if (self->data == NULL) {\
	PyErr_SetString(PyExc_MemoryError, "out of memory");\
	return -1;\
}\
memcpy(self->data, view.buf, self->nBytes);\
return 0

#define GLM_ARRAY_INIT_IF_IS_MAT_BUFFER(T) self->dtSize = sizeof(T);\
self->itemSize = C * R * self->dtSize;\
self->nBytes = self->itemSize * self->itemCount;\
self->subtype = (C == 2) ? (R == 2) ? PyGLM_MAT_TYPE<2, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<2, 3, T>() : PyGLM_MAT_TYPE<2, 4, T>() :\
(C == 3) ? (R == 2) ? PyGLM_MAT_TYPE<3, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<3, 3, T>() : PyGLM_MAT_TYPE<3, 4, T>() :\
(R == 2) ? PyGLM_MAT_TYPE<4, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<4, 3, T>() : PyGLM_MAT_TYPE<4, 4, T>();\
self->data = malloc(self->nBytes);\
if (self->data == NULL) {\
	PyErr_SetString(PyExc_MemoryError, "out of memory");\
	return -1;\
}\
memcpy(self->data, view.buf, self->nBytes);\
return 0

static int 
glmArray_init(glmArray* self, PyObject* args, PyObject* kwds) {
	Py_ssize_t argCount = PyGLM_TupleOrList_GET_SIZE(args);
	if (argCount == 0) {
		PyErr_SetString(PyExc_TypeError, "cannot create an empty array");
		return -1;
	}
	PyObject* firstElement = PyGLM_TupleOrList_GET_ITEM(args, 0);
	PyTypeObject*& firstElementType = Py_TYPE(firstElement);

	// vectors
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, float);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, double);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, int32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, uint32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, int64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, uint64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, int16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, uint16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, int8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, uint8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(1, bool);

	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, float);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, double);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, int32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, uint32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, int64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, uint64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, int16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, uint16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, int8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, uint8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(2, bool);


	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, float);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, double);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, int32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, uint32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, int64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, uint64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, int16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, uint16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, int8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, uint8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(3, bool);


	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, float);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, double);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, int32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, uint32);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, int64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, uint64);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, int16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, uint16);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, int8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, uint8);
	GLM_ARRAY_INIT_IF_IS_VEC_TUPLE_OR_LIST(4, bool);

	// matrices
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 2, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 2, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 2, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 2, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 3, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 3, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 3, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 3, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 4, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 4, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 4, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(2, 4, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 2, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 2, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 2, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 2, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 3, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 3, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 3, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 3, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 4, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 4, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 4, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(3, 4, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 2, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 2, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 2, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 2, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 3, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 3, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 3, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 3, uint32);

	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 4, float);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 4, double);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 4, int32);
	GLM_ARRAY_INIT_IF_IS_MAT_TUPLE_OR_LIST(4, 4, uint32);

	// quaternions
	GLM_ARRAY_INIT_IF_IS_QUA_TUPLE_OR_LIST(float);
	GLM_ARRAY_INIT_IF_IS_QUA_TUPLE_OR_LIST(double);

	// others
	if (argCount == 1) {
		// arrays
		if (firstElementType == &glmArrayType) {
			glmArray* other = (glmArray*)firstElement;
			if (other == self) {
				return 0;
			}
			self->dtSize = other->dtSize;
			memcpy(self->shape, other->shape, sizeof(self->shape));
			self->glmType = other->glmType;
			self->itemCount = other->itemCount;
			self->itemSize = other->itemSize;
			self->nBytes = other->nBytes;
			self->subtype = other->subtype;
			self->format = other->format;
			self->data = malloc(self->nBytes);
			if (self->data == NULL) {
				PyErr_SetString(PyExc_MemoryError, "array creation failed");
				return -1;
			}
			memcpy(self->data, other->data, self->nBytes);
			return 0;
		}

		// lists or tuples
		if (PyGLM_TupleOrList_Check(firstElement)) {
			return glmArray_init(self, firstElement, NULL);
		}

		// buffer protocol
		if (PyObject_CheckBuffer(firstElement)) {
			Py_buffer view;
			if (PyObject_GetBuffer(firstElement, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1) {
				PyGLM_TYPEERROR_O("invalid argument type ", firstElement);
				PyBuffer_Release(&view);
				return -1;
			}
			if (view.ndim == 2) {
				self->itemCount = view.shape[0];
				int L = static_cast<int>(view.shape[1]);
				self->shape[0] = static_cast<uint8>(L);
				self->format = view.format[0];

				if (self->format == 'l') self->format = 'i';
				else if (self->format == 'L') self->format = 'I';

				self->glmType = PyGLM_TYPE_VEC;
				switch (self->format) {
				case 'f':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(float);
				case 'd':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(double);
				case 'i':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(int32);
				case 'I':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(uint32);
				case 'b':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(int8);
				case 'B':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(uint8);
				case 'h':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(int16);
				case 'H':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(uint16);
				case 'q':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(int64);
				case 'Q':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(uint64);
				case '?':
					GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(bool);
				default:
					PyGLM_TYPEERROR_O("invalid argument type ", firstElement);
					PyBuffer_Release(&view);
					return -1;
				}
			}
			else if (view.ndim == 3) {
				self->itemCount = view.shape[0];
				int R = static_cast<int>(view.shape[1]);
				int C = static_cast<int>(view.shape[2]);
				self->shape[0] = static_cast<uint8>(C);
				self->shape[1] = static_cast<uint8>(R);
				self->format = view.format[0];

				if (self->format == 'l') self->format = 'i';
				else if (self->format == 'L') self->format = 'I';

				self->glmType = PyGLM_TYPE_MAT;
				switch (self->format) {
				case 'f':
					GLM_ARRAY_INIT_IF_IS_MAT_BUFFER(float);
				case 'd':
					GLM_ARRAY_INIT_IF_IS_MAT_BUFFER(double);
				case 'i':
					GLM_ARRAY_INIT_IF_IS_MAT_BUFFER(int32);
				case 'I':
					GLM_ARRAY_INIT_IF_IS_MAT_BUFFER(uint32);
				default:
					PyGLM_TYPEERROR_O("invalid argument type ", firstElement);
					PyBuffer_Release(&view);
					return -1;
				}
			}
			else {
				PyGLM_TYPEERROR_O("invalid argument type ", firstElement);
				PyBuffer_Release(&view);
				return -1;
			}
		}

		// iterators
		if (PyObject_IterCheck(firstElement)) {
			argCount = PyObject_Length(firstElement);
			PyObject* iterator = PyObject_GetIter(firstElement);
			PyObject* firstElement = PyIter_Next(iterator);
			PyTypeObject* firstElementType = Py_TYPE(firstElement);

			// vectors
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, float);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, double);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, int32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, uint32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, int64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, uint64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, int16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, uint16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, int8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, uint8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(1, bool);

			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, float);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, double);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, int32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, uint32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, int64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, uint64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, int16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, uint16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, int8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, uint8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(2, bool);


			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, float);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, double);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, int32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, uint32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, int64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, uint64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, int16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, uint16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, int8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, uint8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(3, bool);


			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, float);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, double);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, int32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, uint32);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, int64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, uint64);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, int16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, uint16);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, int8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, uint8);
			GLM_ARRAY_INIT_IF_IS_VEC_ITER(4, bool);

			// matrices
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 2, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 2, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 2, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 2, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 3, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 3, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 3, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 3, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 4, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 4, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 4, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(2, 4, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 2, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 2, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 2, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 2, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 3, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 3, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 3, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 3, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 4, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 4, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 4, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(3, 4, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 2, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 2, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 2, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 2, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 3, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 3, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 3, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 3, uint32);

			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 4, float);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 4, double);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 4, int32);
			GLM_ARRAY_INIT_IF_IS_MAT_ITER(4, 4, uint32);

			// quaternions
			GLM_ARRAY_INIT_IF_IS_QUA_ITER(float);
			GLM_ARRAY_INIT_IF_IS_QUA_ITER(double);
		}
	}

	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for array()");
	return -1;
}


static PyObject* 
glmArray_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
	glmArray* self = (glmArray*)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->itemCount = self->nBytes = 0;
		self->data = NULL;
		self->subtype = NULL;
	}
	return (PyObject*)self;
}


static void 
glmArrayIter_dealloc(glmArrayIter* rgstate) {
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}


static PyObject* 
glmArrayIter_next(glmArrayIter* rgstate) {
	if (rgstate->sequence != NULL && rgstate->seq_index < rgstate->sequence->itemCount) {
		return glmArray_get(rgstate->sequence, rgstate->seq_index++);
	}
	rgstate->seq_index = rgstate->sequence->itemCount;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}


static PyObject* 
glmArrayIter_new(PyTypeObject* type, PyObject* args, PyObject* kwargs) {
	glmArray* sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	glmArrayIter* rgstate = (glmArrayIter*)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject*)rgstate;
}