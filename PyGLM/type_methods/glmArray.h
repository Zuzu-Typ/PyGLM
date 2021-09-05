#pragma once

#include "../compiler_setup.h"

#include "../internal_functions/all.h"

#include "../types/glmArray/glmArray.h"

#include "../internal_functions/type_checkers.h"

static PyObject*
glmArray_getPtr(glmArray* self, void*) {
	return PyGLM_CtypesVoidP_FromVoidP(self->data);
}

static PyObject*
glmArray_to_bytes(glmArray* self, PyObject*) {
	return PyBytes_FromStringAndSize((char*)self->data, self->nBytes);
}

static PyObject*
glmArray_from_bytes(PyObject*, PyObject* args) {
	PyObject* bytesObj, *typeObj = NULL;

	if (!PyArg_UnpackTuple(args, "from_bytes", 1, 2, &bytesObj, &typeObj)) return NULL;

	if (typeObj == NULL) {
		typeObj = ctypes_uint8;
	}

	if (PyBytes_Check(bytesObj) && PyType_Check(typeObj)) {
		if (PyGLM_Is_PyGLM_Type(typeObj)) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)typeObj;

			Py_ssize_t& nBytes = PyBytes_GET_SIZE(bytesObj);

			PyGLM_ASSERT((nBytes > 0 && nBytes % pto->itemSize == 0), "Invalid bytes string length");

			glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

			if (out == NULL) {
				PyErr_SetString(PyExc_MemoryError, "Out of memory");
				return NULL;
			}

			out->data = reinterpret_cast<void*>(PyBytes_AS_STRING(bytesObj));

			out->dtSize = pto->dtSize;

			out->format = pto->format;

			out->glmType = pto->glmType;

			out->itemSize = pto->itemSize;

			out->nBytes = PyBytes_GET_SIZE(bytesObj);

			out->itemCount = out->nBytes / out->itemSize;

			out->readonly = 0;

			out->reference = PyGLM_INCREF(bytesObj);

			out->subtype = pto->subtype;

			out->setShape(pto->C, pto->R);

			return (PyObject*)out;
		}

		if (PyGLM_Ctypes_Check(typeObj)) {
			glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

			if (out == NULL) {
				PyErr_SetString(PyExc_MemoryError, "Out of memory");
				return NULL;
			}

			out->data = reinterpret_cast<void*>(PyBytes_AS_STRING(bytesObj));

			out->reference = PyGLM_INCREF(bytesObj);

			out->subtype = (PyTypeObject*)typeObj;

			if (typeObj == ctypes_double) {
				out->dtSize = sizeof(double);
				out->format = PyGLM_FS_DOUBLE;
			} 
			else if (typeObj == ctypes_float) {
				out->dtSize = sizeof(float);
				out->format = PyGLM_FS_FLOAT;
			} 
			else if (typeObj == ctypes_int64) {
				out->dtSize = sizeof(int64);
				out->format = PyGLM_FS_INT64;
			}
			else if (typeObj == ctypes_int32) {
				out->dtSize = sizeof(int32);
				out->format = PyGLM_FS_INT32;
			}
			else if (typeObj == ctypes_int16) {
				out->dtSize = sizeof(int16);
				out->format = PyGLM_FS_INT16;
			}
			else if (typeObj == ctypes_int8) {
				out->dtSize = sizeof(int8);
				out->format = PyGLM_FS_INT8;
			}
			else if (typeObj == ctypes_uint64) {
				out->dtSize = sizeof(uint64);
				out->format = PyGLM_FS_UINT64;
			}
			else if (typeObj == ctypes_uint32) {
				out->dtSize = sizeof(uint32);
				out->format = PyGLM_FS_UINT32;
			}
			else if (typeObj == ctypes_uint16) {
				out->dtSize = sizeof(uint16);
				out->format = PyGLM_FS_UINT16;
			}
			else if (typeObj == ctypes_uint8) {
				out->dtSize = sizeof(uint8);
				out->format = PyGLM_FS_UINT8;
			}
			else if (typeObj == ctypes_bool) {
				out->dtSize = sizeof(bool);
				out->format = PyGLM_FS_BOOL;
			}
			else {
				Py_DECREF(out);
				PyGLM_TYPEERROR_O("from_bytes() expects a GLM or ctypes number type, not ", typeObj);
				return NULL;
			}

			out->itemSize = out->dtSize;

			out->glmType = PyGLM_TYPE_CTYPES;

			out->nBytes = PyBytes_GET_SIZE(bytesObj);

			out->itemCount = out->nBytes / out->itemSize;

			out->readonly = 0;

			out->setShape(0);

			if ((out->nBytes == 0 || out->nBytes % out->itemSize != 0)) {
				Py_DECREF(out);
				PyErr_SetString(PyExc_AssertionError, "Invalid bytes string length");
				return NULL;
			}

			return (PyObject*)out;
		}
	}
	PyGLM_TYPEERROR_2O("from_bytes() expects a bytes string and a GLM or ctypes type, not ", bytesObj, typeObj);
	return NULL;
}

static PyObject*
glmArray_reinterpret_cast(glmArray* self, PyObject* arg) {
	if (PyType_Check(arg)) {
		if (PyGLM_Is_PyGLM_Type(arg)) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)arg;

			PyGLM_ASSERT((self->nBytes % pto->itemSize == 0), "Invalid bytes string length");

			glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

			if (out == NULL) {
				PyErr_SetString(PyExc_MemoryError, "Out of memory");
				return NULL;
			}

			out->data = self->data;

			out->dtSize = pto->dtSize;

			out->format = pto->format;

			out->glmType = pto->glmType;

			out->itemSize = pto->itemSize;

			out->nBytes = self->nBytes;

			out->itemCount = out->nBytes / out->itemSize;

			out->readonly = 0;

			out->reference = PyGLM_INCREF(((PyObject*)self));

			out->subtype = pto->subtype;

			out->setShape(pto->C, pto->R);

			return (PyObject*)out;
		}

		if (PyGLM_Ctypes_Check(arg)) {
			glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

			if (out == NULL) {
				PyErr_SetString(PyExc_MemoryError, "Out of memory");
				return NULL;
			}

			out->data = self->data;

			out->reference = PyGLM_INCREF(((PyObject*)self));

			out->subtype = (PyTypeObject*)arg;

			if (arg == ctypes_double) {
				out->dtSize = sizeof(double);
				out->format = PyGLM_FS_DOUBLE;
			}
			else if (arg == ctypes_float) {
				out->dtSize = sizeof(float);
				out->format = PyGLM_FS_FLOAT;
			}
			else if (arg == ctypes_int64) {
				out->dtSize = sizeof(int64);
				out->format = PyGLM_FS_INT64;
			}
			else if (arg == ctypes_int32) {
				out->dtSize = sizeof(int32);
				out->format = PyGLM_FS_INT32;
			}
			else if (arg == ctypes_int16) {
				out->dtSize = sizeof(int16);
				out->format = PyGLM_FS_INT16;
			}
			else if (arg == ctypes_int8) {
				out->dtSize = sizeof(int8);
				out->format = PyGLM_FS_INT8;
			}
			else if (arg == ctypes_uint64) {
				out->dtSize = sizeof(uint64);
				out->format = PyGLM_FS_UINT64;
			}
			else if (arg == ctypes_uint32) {
				out->dtSize = sizeof(uint32);
				out->format = PyGLM_FS_UINT32;
			}
			else if (arg == ctypes_uint16) {
				out->dtSize = sizeof(uint16);
				out->format = PyGLM_FS_UINT16;
			}
			else if (arg == ctypes_uint8) {
				out->dtSize = sizeof(uint8);
				out->format = PyGLM_FS_UINT8;
			}
			else if (arg == ctypes_bool) {
				out->dtSize = sizeof(bool);
				out->format = PyGLM_FS_BOOL;
			}
			else {
				Py_DECREF(out);
				PyGLM_TYPEERROR_O("reinterpret_cast() expects a GLM or ctypes number type, not ", arg);
				return NULL;
			}

			out->itemSize = out->dtSize;

			out->glmType = PyGLM_TYPE_CTYPES;

			out->nBytes = self->nBytes;

			out->itemCount = out->nBytes / out->itemSize;

			out->readonly = 0;

			out->setShape(0);

			if ((out->nBytes == 0 || out->nBytes % out->itemSize != 0)) {
				Py_DECREF(out);
				PyErr_SetString(PyExc_AssertionError, "Invalid bytes string length");
				return NULL;
			}

			return (PyObject*)out;
		}
	}
	PyGLM_TYPEERROR_O("reinterpret_cast() expects a GLM or ctypes type, not ", arg);
	return NULL;
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

static PyObject*
glmArray_getCtype(glmArray* self, void*) {
	switch (self->format) {
	case 'f':
		Py_INCREF(ctypes_float);
		return ctypes_float;
	case 'd':
		Py_INCREF(ctypes_double);
		return ctypes_double;
	case 'i':
		Py_INCREF(ctypes_int32);
		return ctypes_int32;
	case 'I':
		Py_INCREF(ctypes_uint32);
		return ctypes_uint32;
	case 'b':
		Py_INCREF(ctypes_int8);
		return ctypes_int8;
	case 'B':
		Py_INCREF(ctypes_uint8);
		return ctypes_uint8;
	case 'h':
		Py_INCREF(ctypes_int16);
		return ctypes_int16;
	case 'H':
		Py_INCREF(ctypes_uint16);
		return ctypes_uint16;
	case 'q':
		Py_INCREF(ctypes_int64);
		return ctypes_int64;
	case 'Q':
		Py_INCREF(ctypes_uint64);
		return ctypes_uint64;
	case '?':
		Py_INCREF(ctypes_bool);
		return ctypes_bool;
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

#define GLM_ARRAY_SET_IF_IS_CTYPES(T)\
if (PyObject_TypeCheck(value, (PyGLM_CTYPES_TYPE<T>()))) {\
	*(((T*)self->data) + index) = *reinterpret_cast<T*>(((ctypes_helper*)value)->b_ptr);\
	return 0;\
}\
if (PyGLM_Number_Check(value)) {\
	*(((T*)self->data) + index) = PyGLM_Number_FromPyObject<T>(value);\
	return 0;\
}\
PyGLM_TYPEERROR_O("invalid assignment type ", value); \
return -1;

int glmArray_set(glmArray* self, Py_ssize_t index, PyObject* value) {
	if (index >= self->itemCount || index < -self->itemCount) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
	if (index < 0) {
		return glmArray_set(self, self->itemCount + index, value);
	}
	if (value == NULL) {
		void* tempDataCopy = PyMem_Malloc(self->nBytes);
		if (tempDataCopy == NULL) {
			PyErr_SetString(PyExc_MemoryError, "out of memory");
			return -1;
		}

		memcpy(tempDataCopy, self->data, self->nBytes);

		Py_ssize_t outItemCount = (self->itemCount - 1);

		self->data = PyMem_Realloc(self->data, outItemCount * self->itemSize);

		memcpy(self->data, tempDataCopy, index * self->itemSize);
		memcpy(((char*)self->data) + index * self->itemSize, ((char*)tempDataCopy) + (index + 1) * self->itemSize, (self->itemCount - index - 1) * self->itemSize);

		self->itemCount = outItemCount;
		self->nBytes = outItemCount * self->itemSize;
		return 0;
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
			PyErr_SetString(PyExc_AssertionError, "Invalid format specifier. This should not have happened."); 
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
			PyErr_SetString(PyExc_AssertionError, "Invalid format specifier. This should not have happened.");
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
			PyErr_SetString(PyExc_AssertionError, "Invalid format specifier. This should not have happened.");
			return -1;
		}
	}
	if (self->glmType == PyGLM_TYPE_CTYPES) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_SET_IF_IS_CTYPES(float);
		case 'd':
			GLM_ARRAY_SET_IF_IS_CTYPES(double);
		case 'i':
			GLM_ARRAY_SET_IF_IS_CTYPES(int32);
		case 'I':
			GLM_ARRAY_SET_IF_IS_CTYPES(uint32);
		case 'b':
			GLM_ARRAY_SET_IF_IS_CTYPES(int8);
		case 'B':
			GLM_ARRAY_SET_IF_IS_CTYPES(uint8);
		case 'h':
			GLM_ARRAY_SET_IF_IS_CTYPES(int16);
		case 'H':
			GLM_ARRAY_SET_IF_IS_CTYPES(uint16);
		case 'q':
			GLM_ARRAY_SET_IF_IS_CTYPES(int64);
		case 'Q':
			GLM_ARRAY_SET_IF_IS_CTYPES(uint64);
		case '?':
			GLM_ARRAY_SET_IF_IS_CTYPES(bool);
		default:
			PyErr_SetString(PyExc_AssertionError, "Invalid format specifier. This should not have happened.");
			return -1;
		}
	}
	return -1;
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

#define GLM_ARRAY_GET_IF_IS_CTYPES(T) \
return PyGLM_PyObject_FromNumber<T>(*(((T*)self->data) + index));

#define GLM_ARRAY_GET_IF_IS_QUA(T) return pack(*(((glm::qua<T>*)self->data) + index));

PyObject* glmArray_get(glmArray* self, Py_ssize_t index) {
	if (index >= self->itemCount || index < -self->itemCount) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (index < 0) {
		return glmArray_get(self, self->itemCount + index);
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
	if (self->glmType == PyGLM_TYPE_CTYPES) {
		switch (self->format) {
		case 'f':
			GLM_ARRAY_GET_IF_IS_CTYPES(float);
		case 'd':
			GLM_ARRAY_GET_IF_IS_CTYPES(double);
		case 'i':
			GLM_ARRAY_GET_IF_IS_CTYPES(int32);
		case 'I':
			GLM_ARRAY_GET_IF_IS_CTYPES(uint32);
		case 'b':
			GLM_ARRAY_GET_IF_IS_CTYPES(int8);
		case 'B':
			GLM_ARRAY_GET_IF_IS_CTYPES(uint8);
		case 'h':
			GLM_ARRAY_GET_IF_IS_CTYPES(int16);
		case 'H':
			GLM_ARRAY_GET_IF_IS_CTYPES(uint16);
		case 'q':
			GLM_ARRAY_GET_IF_IS_CTYPES(int64);
		case 'Q':
			GLM_ARRAY_GET_IF_IS_CTYPES(uint64);
		case '?':
			GLM_ARRAY_GET_IF_IS_CTYPES(bool);
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

	view->obj = (PyObject*)self;
	view->buf = self->data;
	view->len = self->nBytes;
	view->readonly = 0;
	view->itemsize = self->dtSize;
	if (flags & PyBUF_FORMAT) {
		view->format = (char*)PyMem_Malloc(sizeof(char)*2);
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
		if (flags == 0 || (flags & (PyBUF_ANY_CONTIGUOUS | PyBUF_F_CONTIGUOUS | PyBUF_C_CONTIGUOUS)) == PyBUF_STRIDES) { // strided, non contiguous buffer
			view->shape = (Py_ssize_t*)PyMem_Malloc(3 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = R;
				view->shape[2] = C;
			}

			view->strides = (Py_ssize_t*)PyMem_Malloc(3 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = self->dtSize * C * R;
				view->strides[1] = self->dtSize;
				view->strides[2] = R * self->dtSize;
			}
		}
		else if ((flags & PyBUF_WRITABLE) == 0 && ((flags & PyBUF_STRIDES) == PyBUF_ND || (flags & PyBUF_ANY_CONTIGUOUS) == PyBUF_ANY_CONTIGUOUS || (flags & PyBUF_C_CONTIGUOUS) == PyBUF_C_CONTIGUOUS)) {
			view->shape = (Py_ssize_t*)PyMem_Malloc(3 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = R;
				view->shape[2] = C;
			}

			view->strides = (Py_ssize_t*)PyMem_Malloc(3 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = self->dtSize * C * R;
				view->strides[1] = C * self->dtSize;
				view->strides[2] = self->dtSize;
			}

			view->readonly = 1;
			view->buf = PyMem_Malloc(self->nBytes);
			if (view->buf != NULL) {
				const Py_ssize_t dataStride0 = self->dtSize * C * R;
				const Py_ssize_t bufStride0 = self->dtSize * C * R;
				const Py_ssize_t dataStride1 = self->dtSize;
				const Py_ssize_t bufStride1 = self->dtSize * C;
				const Py_ssize_t dataStride2 = self->dtSize * R;
				const Py_ssize_t bufStride2 = self->dtSize;

				for (Py_ssize_t i = 0; i < self->itemCount; i++) {
					for (Py_ssize_t c = 0; c < C; c++) {
						for (Py_ssize_t r = 0; r < R; r++) {
							memcpy(((char*)view->buf) + (i * bufStride0 + r * bufStride1 + c * bufStride2), ((char*)self->data) + (i * dataStride0 + r * dataStride1 + c * dataStride2), self->dtSize);
						}
					}
				}
			}
		}
		else if ((flags & PyBUF_WRITABLE) == 0 && (flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS) {
			view->shape = (Py_ssize_t*)PyMem_Malloc(3 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = R;
				view->shape[2] = C;
			}

			view->strides = (Py_ssize_t*)PyMem_Malloc(3 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = self->dtSize;
				view->strides[1] = C * self->dtSize;
				view->strides[2] = self->dtSize * C * R;
			}

			view->readonly = 1;
			view->buf = PyMem_Malloc(self->nBytes);
			if (view->buf != NULL) {
				const Py_ssize_t dataStride0 = self->dtSize * C * R;
				const Py_ssize_t bufStride0 = self->dtSize;
				const Py_ssize_t dataStride1 = self->dtSize;
				const Py_ssize_t bufStride1 = self->dtSize * C;
				const Py_ssize_t dataStride2 = self->dtSize * R;
				const Py_ssize_t bufStride2 = self->dtSize * C * R;

				for (Py_ssize_t i = 0; i < self->itemCount; i++) {
					for (Py_ssize_t c = 0; c < C; c++) {
						for (Py_ssize_t r = 0; r < R; r++) {
							memcpy(((char*)view->buf) + (i * bufStride0 + r * bufStride1 + c * bufStride2), ((char*)self->data) + (i * dataStride0 + r * dataStride1 + c * dataStride2), self->dtSize);
						}
					}
				}
			}
		}
		else {
			PyErr_SetString(PyExc_BufferError, "This type of buffer is not supported.");
			PyMem_Free(view->format);
			view->format = NULL;
			view->obj = NULL;
			view->buf = NULL;
			return -1;
		}
	}
	else if (self->glmType == PyGLM_TYPE_VEC || self->glmType == PyGLM_TYPE_QUA) {
		const int L = (self->glmType == PyGLM_TYPE_VEC) ? self->getShape() : 4;

		view->ndim = 2;
		if ((flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS && ((flags & PyBUF_WRITABLE) || L == 1)) {
			view->shape = (Py_ssize_t*)PyMem_Malloc(2 * sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
				view->shape[1] = L;
			}
			view->strides = (Py_ssize_t*)PyMem_Malloc(2 * sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = self->dtSize;
				view->strides[1] = L * self->dtSize;
			}

			if (L != 1) {
				view->readonly = 1;
				view->buf = PyMem_Malloc(view->len);
				if (view->buf != NULL) {
					const Py_ssize_t dataStride0 = self->dtSize * L;
					const Py_ssize_t bufStride0 = self->dtSize;
					const Py_ssize_t dataStride1 = self->dtSize;
					const Py_ssize_t bufStride1 = self->dtSize * L;

					for (Py_ssize_t i = 0; i < self->itemCount; i++) {
						for (Py_ssize_t l = 0; l < L; l++) {
							memcpy(((char*)view->buf) + (i * bufStride0 + l * bufStride1), ((char*)self->data) + (i * dataStride0 + l * dataStride1), self->dtSize);
						}
					}
				}
			}
		}
		else {
			if (flags & PyBUF_ND) {
				view->shape = (Py_ssize_t*)PyMem_Malloc(2 * sizeof(Py_ssize_t));
				if (view->shape != NULL) {
					view->shape[0] = self->itemCount;
					view->shape[1] = L;
				}
			}
			else {
				view->shape = NULL;
			}
			if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
				view->strides = (Py_ssize_t*)PyMem_Malloc(2 * sizeof(Py_ssize_t));
				if (view->strides != NULL) {
					view->strides[0] = L * self->dtSize;
					view->strides[1] = self->dtSize;
				}
			}
			else {
				view->strides = NULL;
			}
		}
	}
	else if (self->glmType == PyGLM_TYPE_CTYPES) {
		view->ndim = 1;
		if (flags & PyBUF_ND) {
			view->shape = (Py_ssize_t*)PyMem_Malloc(sizeof(Py_ssize_t));
			if (view->shape != NULL) {
				view->shape[0] = self->itemCount;
			}
		}
		else {
			view->shape = NULL;
		}
		if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
			view->strides = (Py_ssize_t*)PyMem_Malloc(sizeof(Py_ssize_t));
			if (view->strides != NULL) {
				view->strides[0] = self->dtSize;
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
	PyMem_Free(view->shape);
	PyMem_Free(view->strides);
	PyMem_Free(view->format);

	if (view->readonly) {
		PyMem_Free(view->buf);
	}
}




static PyObject* 
glmArray_to_list(glmArray* self, PyObject*) {
	PyObject* out = PyList_New(self->itemCount);
	for (Py_ssize_t i = 0; i < self->itemCount; i++) {
		PyList_SET_ITEM(out, i, glmArray_get(self, i));
	}
	return out;
}




static PyObject* 
glmArray_to_tuple(glmArray* self, PyObject*) {
	PyObject* out = PyTuple_New(self->itemCount);
	for (Py_ssize_t i = 0; i < self->itemCount; i++) {
		PyTuple_SET_ITEM(out, i, glmArray_get(self, i));
	}
	return out;
}

static PyObject* 
glmArray_split_components(glmArray* self, PyObject*) {
	if (self->glmType == PyGLM_TYPE_CTYPES) {
		PyErr_SetString(PyExc_NotImplementedError, "split_components() is not defined for ctypes arrays");
		return NULL;
	}

	const uint8 componentCount = self->shape[0];

	PyTypeObject* subtype = (self->glmType == PyGLM_TYPE_MAT) ? PyGLM_PYOBJECT_MAT_GET_COLUMN_TYPE((PyGLMTypeObject*)(self->subtype)) :
		PyGLM_PYOBJECT_VEC_QUAT_COMPONENT_TYPE((PyGLMTypeObject*)(self->subtype));

	const uint8 glmType = (self->glmType == PyGLM_TYPE_MAT) ? PyGLM_TYPE_VEC : PyGLM_TYPE_CTYPES;

	PyObject* out = PyTuple_New(componentCount);
	for (uint8 i = 0; i < componentCount; i++) {
		glmArray* arr = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

		if (arr == NULL) {
			PyErr_SetString(PyExc_MemoryError, "Out of memory");
			Py_DECREF(out);
			return NULL;
		}

		arr->subtype = subtype;
		arr->glmType = glmType;
		arr->readonly = false;
		arr->reference = NULL;

		arr->dtSize = self->dtSize;
		arr->format = self->format;
		arr->itemCount = self->itemCount;
		arr->itemSize = self->itemSize / componentCount;
		arr->nBytes = self->nBytes / componentCount;

		arr->shape[0] = self->shape[1];

		arr->data = PyMem_Malloc(arr->nBytes);

		if (arr->data == NULL) {
			PyErr_SetString(PyExc_MemoryError, "Out of memory");
			Py_DECREF(arr);
			Py_DECREF(out);
			return NULL;
		}

		char* selfDataPtr = (char*)self->data + (i * arr->itemSize);
		char* arrDataPtr = (char*)arr->data;
		for (Py_ssize_t j = 0; j < self->itemCount; j++) {
			memcpy(arrDataPtr, selfDataPtr, arr->itemSize);
			selfDataPtr += self->itemSize;
			arrDataPtr += arr->itemSize;
		}

		PyTuple_SET_ITEM(out, i, ((PyObject*)arr));
	}
	return out;
}

static PyObject* do_reduce(std::vector<PyObject*> objects, PyObject* callable) {
	const size_t object_count = objects.size();

	PyObject* result = objects[0];

	PyObject* args = PyTuple_New(2);

	for (size_t i = 1; i < object_count; i++) {
		PyObject* nextObj = objects[i];

		PyTuple_SET_ITEM(args, 0, result);

		PyTuple_SET_ITEM(args, 1, nextObj);

		PyObject* newResult = PyObject_Call(callable, args, NULL);

		Py_DECREF(result);
		Py_DECREF(nextObj);

		if (newResult == NULL) {
			PyTuple_SET_ITEM(args, 0, NULL);
			PyTuple_SET_ITEM(args, 1, NULL);
			Py_DECREF(args);
			return NULL;
		}

		result = newResult;
	}

	PyTuple_SET_ITEM(args, 0, NULL);
	PyTuple_SET_ITEM(args, 1, NULL);
	Py_DECREF(args);

	return result;
}

static PyObject* glmArray_reduce(glmArray* self, PyObject* args) {
	PyObject* arg1, * arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "reduce", 1, 2, &arg1, &arg2)) return NULL;

	if (!PyCallable_Check(arg1)) {
		PyGLM_TYPEERROR_O("reduce() requires a function or callable as it's first argument. Got ", arg1);
		return NULL;
	}

	std::vector<PyObject*> objects;

	if (arg2 != NULL) { // initializer
		if (!((self->glmType == PyGLM_TYPE_CTYPES && PyGLM_Number_Check(arg2)) || PyObject_TypeCheck(arg2, self->subtype))) {
			PyGLM_TYPEERROR_O("Invalid argument type for initializer of reduce(): ", arg2);
			return NULL;
		}
		Py_INCREF(arg2);
		objects.push_back(arg2);
	}

	PyGLM_ASSERT((self->itemCount + objects.size() > 0), "Cannot reduce an empty array with no initializer.");

	for (Py_ssize_t i = 0; i < self->itemCount; i++) {
		objects.push_back(glmArray_get(self, i));
	}

	return do_reduce(objects, arg1);
}

template<typename T>
static bool
glmArray_from_numbers_init_iter(glmArray* out, PyObject* iterator, Py_ssize_t& argCount) {
	out->dtSize = sizeof(T);
	out->itemSize = sizeof(T);
	out->itemCount = argCount - 1;
	out->nBytes = out->itemSize * out->itemCount;
	out->format = get_format_specifier<T>();
	out->data = PyMem_Malloc(out->nBytes);

	if (out->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "Out of memory");
		return false;
	}

	T* values = reinterpret_cast<T*>(out->data);

	for (Py_ssize_t i = 1; i < argCount; i++) {
		PyObject* element = PyIter_Next(iterator);
		if (!PyGLM_Number_Check(element)) {
			PyGLM_TYPEERROR_O("Invalid argument type(s) for from_number(). Expected only numbers, got ", element);
			return false;
		}
		values[i - 1] = PyGLM_Number_FromPyObject<T>(element);
	}

	return true;
}

template<typename T>
static bool
glmArray_from_numbers_init(glmArray* out, PyObject* tuple, Py_ssize_t& argCount) {
	out->dtSize = sizeof(T);
	out->itemSize = sizeof(T);
	out->itemCount = argCount - 1;
	out->nBytes = out->itemSize * out->itemCount;
	out->format = get_format_specifier<T>();
	out->data = PyMem_Malloc(out->nBytes);

	if (out->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "Out of memory");
		return false;
	}

	T* values = reinterpret_cast<T*>(out->data);

	for (Py_ssize_t i = 1; i < argCount; i++) {
		PyObject* element = PyGLM_TupleOrList_GET_ITEM(tuple, i);
		if (!PyGLM_Number_Check(element)) {
			PyGLM_TYPEERROR_O("Invalid argument type(s) for from_number(). Expected only numbers, got ", element);
			return false;
		}
		values[i - 1] = PyGLM_Number_FromPyObject<T>(element);
	}

	return true;
}



static PyObject*
glmArray_from_numbers(PyObject*, PyObject* args) {
	Py_ssize_t argCount = PyTuple_GET_SIZE(args);
	PyGLM_ASSERT((argCount >= 1), "Invalid argument count for from_number(), expected at least 1, got 0");

	PyObject* formatType = PyTuple_GET_ITEM(args, 0);
	if (!PyType_Check(formatType)) {
		PyGLM_TYPEERROR_O("Invalid argument type for from_number(), expected a data type as the first argument. Got ", formatType);
		return NULL;
	}

	glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "Out of memory");
		return NULL;
	}

	out->subtype = (PyTypeObject*)formatType;
	out->glmType = PyGLM_TYPE_CTYPES;
	out->readonly = false;
	out->reference = NULL;

	if (formatType == ctypes_float) {
		if (glmArray_from_numbers_init<float>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_double) {
		if (glmArray_from_numbers_init<double>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_int8) {
		if (glmArray_from_numbers_init<int8>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_int16) {
		if (glmArray_from_numbers_init<int16>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_int32) {
		if (glmArray_from_numbers_init<int32>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_int64) {
		if (glmArray_from_numbers_init<int64>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_uint8) {
		if (glmArray_from_numbers_init<uint8>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_uint16) {
		if (glmArray_from_numbers_init<uint16>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_uint32) {
		if (glmArray_from_numbers_init<uint32>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_uint64) {
		if (glmArray_from_numbers_init<uint64>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}
	if (formatType == ctypes_bool) {
		if (glmArray_from_numbers_init<bool>(out, args, argCount))
			return (PyObject*)out;
		return NULL;
	}

	PyGLM_TYPEERROR_O("Invalid argument type for from_number(), expected a ctypes data type as the first argument. Got ", formatType);
	return NULL;
}

#define GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(T) \
out->dtSize = sizeof(T);\
out->itemSize = L * out->dtSize;\
out->nBytes = out->itemSize * out->itemCount;\
out->subtype = (L == 1) ? PyGLM_VEC_TYPE<1, T>() : (L == 2) ? PyGLM_VEC_TYPE<2, T>() : (L == 3) ? PyGLM_VEC_TYPE<3, T>() : PyGLM_VEC_TYPE<4, T>();\
PyBuffer_Release(&view);\
return (PyObject*)out

#define GLM_ARRAY_AS_REFERENCE_IF_IS_MAT_BUFFER(T) \
out->itemSize = (Py_ssize_t)C * (Py_ssize_t)R * out->dtSize;\
out->subtype = (C == 2) ? (R == 2) ? PyGLM_MAT_TYPE<2, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<2, 3, T>() : PyGLM_MAT_TYPE<2, 4, T>() :\
(C == 3) ? (R == 2) ? PyGLM_MAT_TYPE<3, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<3, 3, T>() : PyGLM_MAT_TYPE<3, 4, T>() :\
(R == 2) ? PyGLM_MAT_TYPE<4, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<4, 3, T>() : PyGLM_MAT_TYPE<4, 4, T>();\
PyBuffer_Release(&view);\
return (PyObject*)out

#define GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(T) \
out->dtSize = sizeof(T);\
out->itemSize = out->dtSize;\
out->nBytes = out->itemSize * out->itemCount;\
out->subtype = PyGLM_CTYPES_TYPE<T>();\
PyBuffer_Release(&view);\
return (PyObject*)out



static PyObject*
glmArray_as_reference(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, &glmArrayType)) {
		glmArray* other = (glmArray*)arg;
		glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

		if (out == NULL) {
			PyErr_SetString(PyExc_MemoryError, "Out of memory");
			return NULL;
		}

		out->format = other->format;
		out->shape[0] = other->shape[0];
		out->shape[1] = other->shape[1];
		out->glmType = other->glmType;
		out->nBytes = other->nBytes;
		out->itemCount = other->itemCount;
		out->dtSize = other->dtSize;
		out->itemSize = other->itemSize;
		out->subtype = other->subtype;
		out->data = other->data;
		out->readonly = other->readonly;
		Py_INCREF(arg);
		out->reference = arg;

		return (PyObject*)out;
	}
	if (PyObject_CheckBuffer(arg)) {
		Py_buffer view;
		if (PyObject_GetBuffer(arg, &view, PyBUF_RECORDS_RO) == -1) {
			PyBuffer_Release(&view);
			return NULL;
		}
		glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

		if (out == NULL) {
			PyErr_SetString(PyExc_MemoryError, "Out of memory");
			return NULL;
		}

		out->data = view.buf;
		out->readonly = (bool)view.readonly;
		Py_INCREF(arg);
		out->reference = arg;

		if (view.ndim == 1) {
			out->itemCount = view.shape[0];
			out->format = view.format[0];

			if (out->format == 'l') out->format = 'i';
			else if (out->format == 'L') out->format = 'I';

			out->glmType = PyGLM_TYPE_CTYPES;
			switch (out->format) {
			case 'f':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(float);
			case 'd':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(double);
			case 'i':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(int32);
			case 'I':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(uint32);
			case 'b':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(int8);
			case 'B':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(uint8);
			case 'h':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(int16);
			case 'H':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(uint16);
			case 'q':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(int64);
			case 'Q':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(uint64);
			case '?':
				GLM_ARRAY_AS_REFERENCE_IF_IS_CTYPES_BUFFER(bool);
			default:
				PyGLM_TYPEERROR_O("invalid argument type ", arg);
				PyBuffer_Release(&view);
				return NULL;
			}
		}
		else if (view.ndim == 2) {
			if (view.shape[1] < 1 || view.shape[1] > 4) {
				PyErr_SetString(PyExc_ValueError, "invalid buffer shape");
				return NULL;
			}
			out->itemCount = view.shape[0];
			int L = static_cast<int>(view.shape[1]);
			out->shape[0] = static_cast<uint8>(L);
			out->format = view.format[0];

			if (out->format == 'l') out->format = 'i';
			else if (out->format == 'L') out->format = 'I';

			out->glmType = PyGLM_TYPE_VEC;
			switch (out->format) {
			case 'f':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(float);
			case 'd':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(double);
			case 'i':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(int32);
			case 'I':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(uint32);
			case 'b':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(int8);
			case 'B':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(uint8);
			case 'h':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(int16);
			case 'H':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(uint16);
			case 'q':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(int64);
			case 'Q':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(uint64);
			case '?':
				GLM_ARRAY_AS_REFERENCE_IF_IS_VEC_BUFFER(bool);
			default:
				PyGLM_TYPEERROR_O("invalid argument type ", arg);
				PyBuffer_Release(&view);
				return NULL;
			}
		}
		else if (view.ndim == 3) {
			if (view.shape[1] < 2 || view.shape[1] > 4 || view.shape[2] < 2 || view.shape[2] > 4) {
				PyErr_SetString(PyExc_ValueError, "invalid buffer shape");
				return NULL;
			}
			out->itemCount = view.shape[0];
			int R = static_cast<int>(view.shape[1]);
			int C = static_cast<int>(view.shape[2]);

			if (view.strides[0] != view.itemsize * C * R || view.strides[1] != view.itemsize || view.strides[2] != view.itemsize * R) {
				if (PyGLM_SHOW_WARNINGS & PyGLM_NO_REFERENCE_POSSIBLE_WARNING) {
					PyErr_WarnEx(PyExc_UserWarning, "The given array has an incompatible memory layout, therefore it will be copied!\n(You can silence this warning using glm.silence(3))", 1);
				}

				Py_DECREF(out->reference);
				out->reference = NULL;
				out->readonly = 0;

				out->data = PyMem_Malloc(view.len);
				if (out->data == NULL) {
					PyErr_SetString(PyExc_MemoryError, "out of memory");
					return NULL;
				}

				char* dataPtr = (char*)out->data;
				char* bufPtr = (char*)view.buf;

				for (Py_ssize_t i0 = 0; i0 < out->itemCount; i0++) {
					for (Py_ssize_t i1 = 0; i1 < R; i1++) {
						for (Py_ssize_t i2 = 0; i2 < C; i2++) {
							Py_ssize_t origOffset = (view.strides[0] * i0 + view.strides[1] * i1 + view.strides[2] * i2);
							Py_ssize_t targetOffset = (out->itemCount * C * R * i0 + view.itemsize * i1 + view.itemsize * R * i2);
							memcpy(dataPtr + targetOffset, bufPtr + origOffset, view.itemsize);
						}
					}
				}
			}

			out->shape[0] = static_cast<uint8>(C);
			out->shape[1] = static_cast<uint8>(R);
			out->format = view.format[0];

			out->dtSize = view.itemsize;
			out->nBytes = view.len;

			if (out->format == 'l') out->format = 'i';
			else if (out->format == 'L') out->format = 'I';

			out->glmType = PyGLM_TYPE_MAT;
			switch (out->format) {
			case 'f':
				GLM_ARRAY_AS_REFERENCE_IF_IS_MAT_BUFFER(float);
			case 'd':
				GLM_ARRAY_AS_REFERENCE_IF_IS_MAT_BUFFER(double);
			case 'i':
				GLM_ARRAY_AS_REFERENCE_IF_IS_MAT_BUFFER(int32);
			case 'I':
				GLM_ARRAY_AS_REFERENCE_IF_IS_MAT_BUFFER(uint32);
			default:
				PyGLM_TYPEERROR_O("invalid argument type ", arg);
				PyBuffer_Release(&view);
				return NULL;
			}
		}
		else {
			PyGLM_TYPEERROR_O("invalid argument type ", arg);
			PyBuffer_Release(&view);
			return NULL;
		}
	}
	PyGLM_TYPEERROR_O("invalid argument type ", arg);
	return NULL;
}



static PyObject*
glmArray_zeros_return(glmArray*& out, long& count) {
	out->nBytes = out->itemSize * count;
	out->data = PyMem_Calloc(count, out->itemSize);

	if (out->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "Out of memory");
		return NULL;
	}

	return (PyObject*)out;
}
#define GLM_ARRAY_ZEROS_IF_IS_CTYPES(T)\
if (type == PyGLM_CTYPES_TYPE<T>()) {\
	out->dtSize = sizeof(T);\
	out->itemSize = sizeof(T);\
	out->format = get_format_specifier<T>();\
	return glmArray_zeros_return(out, count);\
}



static PyObject*
glmArray_zeros(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "zeros", arg1, arg2);
	if (PyLong_Check(arg1) && PyType_Check(arg2)) {
		long count = PyLong_AS_LONG(arg1);

		PyTypeObject* type = (PyTypeObject*)arg2;

		glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);

		if (out == NULL) {
			PyErr_SetString(PyExc_MemoryError, "Out of memory");
			return NULL;
		}

		out->subtype = type;
		out->itemCount = count;

		out->readonly = false;
		out->reference = NULL;

		if (PyGLM_Is_PyGLM_Type(type)) {
			PyGLMTypeObject* asPyGLMType = (PyGLMTypeObject*)type;
			out->glmType = asPyGLMType->glmType & PyGLM_TYPE_MVEC_FILTER;
			out->dtSize = asPyGLMType->dtSize;
			out->itemSize = asPyGLMType->itemSize;
			out->shape[0] = asPyGLMType->C;
			out->shape[1] = asPyGLMType->R;
			out->format = asPyGLMType->format;
			out->nBytes = out->itemSize * count;
			out->data = PyMem_Calloc(count, out->itemSize);

			if (out->data == NULL) {
				PyErr_SetString(PyExc_MemoryError, "Out of memory");
				return NULL;
			}

			return (PyObject*)out;
		}

		if (type->tp_dealloc == ctypes_dealloc) {
			out->glmType = PyGLM_TYPE_CTYPES;

			GLM_ARRAY_ZEROS_IF_IS_CTYPES(float);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(double);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(int32);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(int64);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(int16);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(int8);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(uint32);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(uint64);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(uint16);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(uint8);
			GLM_ARRAY_ZEROS_IF_IS_CTYPES(bool);
		}
		PyErr_SetString(PyExc_ValueError, "Invalid data type.");
		return NULL;
	}
	PyGLM_TYPEERROR_2O("Invalid argument type(s) for zeros(): Expected int and type, got ", arg1, arg2);
	return NULL;
}



static PyObject*
glmArray_getstate(glmArray* self, PyObject*) {
	return PyTuple_Pack(10,
		glmArray_to_tuple(self, NULL),
		PyGLM_PyObject_FromNumber<Py_ssize_t>(self->dtSize),
		PyGLM_PyObject_FromNumber<char>(self->format),
		PyGLM_PyObject_FromNumber<uint8>(self->glmType),
		PyGLM_PyObject_FromNumber<Py_ssize_t>(self->itemCount),
		PyGLM_PyObject_FromNumber<Py_ssize_t>(self->itemSize),
		PyGLM_PyObject_FromNumber<Py_ssize_t>(self->nBytes),
		PyGLM_PyObject_FromNumber<uint8>(self->shape[0]),
		PyGLM_PyObject_FromNumber<uint8>(self->shape[1]),
		self->subtype
		);
}



static PyObject*
glmArray_setstate(glmArray* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 10, "Invalid state. Expected length 10 tuple.");
	PyObject* dataTuple = PyTuple_GET_ITEM(state, 0);
	self->dtSize = PyGLM_Number_FromPyObject<Py_ssize_t>(PyTuple_GET_ITEM(state, 1));
	self->format = PyGLM_Number_FromPyObject<char>(PyTuple_GET_ITEM(state, 2));
	self->glmType = PyGLM_Number_FromPyObject<uint8>(PyTuple_GET_ITEM(state, 3));
	self->itemCount = PyGLM_Number_FromPyObject<Py_ssize_t>(PyTuple_GET_ITEM(state, 4));
	self->itemSize = PyGLM_Number_FromPyObject<Py_ssize_t>(PyTuple_GET_ITEM(state, 5));
	self->nBytes = PyGLM_Number_FromPyObject<Py_ssize_t>(PyTuple_GET_ITEM(state, 6));
	self->shape[0] = PyGLM_Number_FromPyObject<uint8>(PyTuple_GET_ITEM(state, 7));
	self->shape[1] = PyGLM_Number_FromPyObject<uint8>(PyTuple_GET_ITEM(state, 8));
	self->subtype = (PyTypeObject*)PyTuple_GET_ITEM(state, 9);
	self->readonly = false;
	self->reference = NULL;

	self->data = PyMem_MALLOC(self->nBytes);

	for (Py_ssize_t i = 0; i < self->itemCount; i++) {
		glmArray_set(self, i, PyTuple_GET_ITEM(dataTuple, i));
	}
	Py_RETURN_NONE;
}

static Py_ssize_t 
glmArray_len(glmArray* self) { 
	return self->itemCount;
}

static PyObject* glmArray_concat(PyObject* obj1, PyObject* obj2) {
	if (!PyObject_TypeCheck(obj1, &glmArrayType) || !PyObject_TypeCheck(obj2, &glmArrayType)) {
		PyGLM_TYPEERROR_2O("invalid argument type(s) for concat(): ", obj1, obj2);
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

	out->data = PyMem_Malloc(out->nBytes);
	if (out->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	memcpy(out->data, arr1->data, arr1->nBytes);
	memcpy(((char*)out->data) + arr1->nBytes, arr2->data, arr2->nBytes);

	return (PyObject*)out;
}

static PyObject* glmArray_repeat(glmArray* self, PyObject* count) {
	if (PyLong_Check(count)) {
		glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);
		PyGLM_ASSERT((out != NULL), "generated array was NULL. (maybe we're out of memory?)");

		Py_ssize_t countAsSsizet = PyLong_AsSsize_t(count);

		PyGLM_ASSERT((countAsSsizet >= 0), "count must not be negative");

		out->dtSize = self->dtSize;
		out->format = self->format;
		out->glmType = self->glmType;
		out->itemCount = self->itemCount * countAsSsizet;
		out->itemSize = self->itemSize;
		out->nBytes = self->nBytes * countAsSsizet;
		memcpy(out->shape, self->shape, sizeof(out->shape));
		out->subtype = self->subtype;

		out->data = PyMem_Malloc(out->nBytes);
		if (out->data == NULL) {
			PyErr_SetString(PyExc_MemoryError, "out of memory");
			return NULL;
		}
		if (countAsSsizet >= 1) {
			memcpy(out->data, self->data, self->nBytes);
		}
		for (Py_ssize_t i = 1; i < countAsSsizet;) {
			Py_ssize_t destOffset = i * self->nBytes;
			Py_ssize_t copyCount = std::min(i, countAsSsizet - i);
			size_t copySize = (size_t)copyCount * (size_t)self->nBytes;
			memcpy(((char*)out->data) + destOffset, out->data, copySize);
			i += copyCount;
		}

		return (PyObject*)out;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for repeat(): Expected int, got ", count);
	return NULL;
}

static PyObject* glmArray_inplace_concat(glmArray* self, PyObject* obj) {
	glmArray* temp = (glmArray*)glmArray_concat((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	memcpy(((char*)self) + PyGLM_ARRAY_OFFSET, ((char*)temp) + PyGLM_ARRAY_OFFSET, PyGLM_ARRAY_SIZE - sizeof(self->data));
	self->data = PyMem_Malloc(self->nBytes);
	memcpy(self->data, temp->data, self->nBytes);

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject* glmArray_inplace_repeat(glmArray* self, PyObject* count) {
	glmArray* temp = (glmArray*)glmArray_repeat(self, count);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	memcpy(((char*)self) + PyGLM_ARRAY_OFFSET, ((char*)temp) + PyGLM_ARRAY_OFFSET, PyGLM_ARRAY_SIZE - sizeof(self->data));
	self->data = PyMem_Malloc(self->nBytes);
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
	if (self->readonly) {
		PyErr_SetString(PyExc_Exception, "This array is read-only.");
		return -1;
	}
	return glmArray_set(self, index, value);
}

static PyObject*
glmArray_mp_subscript(glmArray* self, PyObject* key) {
	if (PyLong_Check(key)) {
		return glmArray_get(self, PyLong_AsSsize_t(key));
	}
	if (PySlice_Check(key)) {
		Py_ssize_t start, stop, step, slicelength;
		if (PySlice_GetIndicesEx(key, self->itemCount, &start, &stop, &step, &slicelength) < 0) {
			return NULL;
		}
		glmArray* out = (glmArray*)glmArrayType.tp_alloc(&glmArrayType, 0);
		PyGLM_ASSERT((out != NULL), "generated array was NULL. (maybe we're out of memory?)");

		out->dtSize = self->dtSize;
		out->format = self->format;
		out->glmType = self->glmType;
		out->itemCount = slicelength;
		out->itemSize = self->itemSize;
		out->nBytes = slicelength * self->itemSize;
		memcpy(out->shape, self->shape, sizeof(out->shape));
		out->subtype = self->subtype;

		if (step == 1) {
			out->data = ((char*)self->data) + (start * self->itemSize);
			out->readonly = self->readonly;
			Py_INCREF(self);
			out->reference = (PyObject*)self;
		}
		else {
			out->readonly = false;
			out->reference = NULL;
			out->data = PyMem_Malloc(out->nBytes);
			if (out->data == NULL) {
				PyErr_SetString(PyExc_MemoryError, "out of memory");
				return NULL;
			}
			Py_ssize_t outIndex = 0;
			for (Py_ssize_t i = start; i < stop; i += step) {
				memcpy(((char*)out->data) + (outIndex++ * self->itemSize), ((char*)self->data) + (i * self->itemSize), self->itemSize);
			}
		}

		
		return (PyObject*)out;
	}
	PyGLM_TYPEERROR_O("invalid operand type for []: ", key);
	return NULL;
}

static int
glmArray_mp_ass_subscript(glmArray* self, PyObject* key, PyObject* value) {
	if (self->readonly) {
		PyErr_SetString(PyExc_Exception, "This array is read-only.");
		return -1;
	}
	if (PyLong_Check(key)) {
		return glmArray_set(self, PyLong_AsSsize_t(key), value);
	}
	if (PySlice_Check(key)) {
		Py_ssize_t start, stop, step, slicelength;
		if (PySlice_GetIndicesEx(key, self->itemCount, &start, &stop, &step, &slicelength) < 0) {
			return -1;
		}

		if (value == NULL) {
			void* tempDataCopy = PyMem_Malloc(self->nBytes);
			if (tempDataCopy == NULL) {
				PyErr_SetString(PyExc_MemoryError, "out of memory");
				return -1;
			}

			memcpy(tempDataCopy, self->data, self->nBytes);

			Py_ssize_t outItemCount = (self->itemCount - slicelength);

			self->data = PyMem_Realloc(self->data, outItemCount * self->itemSize);

			Py_ssize_t outIndex = 0;
			for (Py_ssize_t i = 0; i < self->itemCount; i++) {
				if (i < start || i >= stop || (i - start) % step != 0)
					memcpy(((char*)self->data) + (outIndex++ * self->itemSize), ((char*)tempDataCopy) + (i * self->itemSize), self->itemSize);
			}
			self->itemCount = outItemCount;
			self->nBytes = outItemCount * self->itemSize;
			return 0;
		}

		if (!PyObject_TypeCheck(value, &glmArrayType)) {
			PyGLM_TYPEERROR_O("invalid operand type for []=: ", value);
			return -1;
		}
		glmArray* valueArr = (glmArray*)value;
		if (valueArr->itemCount != slicelength) {
			PyErr_SetString(PyExc_ValueError, "array and slice don't have the same length");
			return -1;
		}
		if (valueArr->subtype != self->subtype) {
			PyErr_SetString(PyExc_ValueError, "incompatible array data types");
			return -1;
		}
		Py_ssize_t inValueIndex = 0;
		for (Py_ssize_t i = start; i < stop; i += step) {
			memcpy(((char*)self->data) + (i * self->itemSize), ((char*)valueArr->data) + (inValueIndex++ * self->itemSize), self->itemSize);
		}
		return 0;
	}
	PyGLM_TYPEERROR_O("invalid operand type for []: ", key);
	return -1;
}

static int 
glmArray_contains(glmArray* self, PyObject* value) {
	for (Py_ssize_t i = 0; i < self->itemCount; i++) {
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
	if (self->reference == NULL) {
		PyMem_Free(self->data);
		self->data = NULL;
	}
	else {
		Py_DECREF(self->reference);
	}
	Py_TYPE(self)->tp_free(self);
}

template<typename T>
static PyObject*
glmArray_str_vec(glmArray* self) {
	const int L = self->getShape();

	uint64 itemSize = (7 + 12 + (L - 1) * (12 + 2));
	uint64 outLength = 1 + 3 + self->itemCount * itemSize;

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;

	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		T* values = &((T*)self->data)[itemIndex * L];
		snprintf(currentIndex, 3 + 12 + 1, " [ %12.6g", static_cast<double>(values[0]));
		currentIndex += 3 + 12;

		for (Py_ssize_t valueIndex = 1; valueIndex < L; valueIndex++) {
			snprintf(currentIndex, 2 + 12 + 1, ", %12.6g", static_cast<double>(values[valueIndex]));
			currentIndex += 2 + 12;
		}

		snprintf(currentIndex, 4 + 1, " ],\n");
		currentIndex += 4;
	}

	snprintf(currentIndex, 1 + 1, "]");

	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_vec(glmArray* self) {
	const int L = self->getShape();

	const char* subtypeName = PyGLM_GET_NAME(self->subtype->tp_name);

	const char* arrayTypeName = PyGLM_GET_NAME(glmArrayType.tp_name);

	const uint64 arrayNameLength = strlen(arrayTypeName);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 itemSize = (subtypeNameLength + 2 + 12 + (L - 1) * (12 + 2));
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize + (itemSize + 2) * (self->itemCount - 1);

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", arrayTypeName);
	currentIndex += arrayNameLength + 1;

	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		T* values = &((T*)self->data)[itemIndex * L];
		snprintf(currentIndex, subtypeNameLength + 1 + 12 + 1, "%s(%g", subtypeName, static_cast<double>(values[0]));
		currentIndex += strlen(currentIndex);

		for (Py_ssize_t valueIndex = 1; valueIndex < L; valueIndex++) {
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
	PyMem_Free(out);
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

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;
	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		snprintf(currentIndex, 3 + 1, " [\n");
		currentIndex += 3;

		T* values = &((T*)self->data)[itemIndex * (C * R)];

		for (Py_ssize_t rowIndex = 0; rowIndex < R; rowIndex++) {
			snprintf(currentIndex, 4 + 12 + 1, "  [ %12.6g", static_cast<double>(values[rowIndex]));
			currentIndex += 4 + 12;

			for (Py_ssize_t valueIndex = 1; valueIndex < C; valueIndex++) {
				snprintf(currentIndex, 2 + 12 + 1, ", %12.6g", static_cast<double>(values[valueIndex * R + rowIndex]));
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
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_mat(glmArray* self) {
	const int C = self->getShape(0);
	const int R = self->getShape(1);

	const char* subtypeName = self->subtype->tp_name + 4;

	const char* arrayTypeName = glmArrayType.tp_name + 4;

	const uint64 arrayNameLength = strlen(arrayTypeName);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 subItemSize = (2 + 12 + (R - 1) * (12 + 2));
	const uint64 itemSize = subtypeNameLength + 2 + subItemSize  + (subItemSize + 2) * (C - 1);
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize + (2 + itemSize) * (self->itemCount - 1);

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", arrayTypeName);
	currentIndex += arrayNameLength + 1;
	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		snprintf(currentIndex, subtypeNameLength + 1 + 1, "%s(", subtypeName);
		currentIndex += subtypeNameLength + 1;

		for (Py_ssize_t columnIndex = 0; columnIndex < C; columnIndex++) {
			T* values = &((T*)self->data)[itemIndex * (C * R) + columnIndex * R];
			snprintf(currentIndex, 1 + 12 + 1, "(%g", static_cast<double>(values[0]));
			currentIndex += strlen(currentIndex);

			for (Py_ssize_t valueIndex = 1; valueIndex < R; valueIndex++) {
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
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_str_qua(glmArray* self) {
	uint64 itemSize = (13 + 12 * 4);
	uint64 outLength = 1 + 3 + itemSize * self->itemCount;

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;

	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
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
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_qua(glmArray* self) {
	const char* subtypeName = self->subtype->tp_name + 4;

	const char* arrayTypeName = glmArrayType.tp_name + 4;

	const uint64 arrayNameLength = strlen(arrayTypeName);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 itemSize = (subtypeNameLength + 8 + 12 * 4);
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize + (itemSize + 2) * (self->itemCount - 1);

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", arrayTypeName);
	currentIndex += arrayNameLength + 1;

	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
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
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_str_ctypes(glmArray* self) {
	constexpr uint64 itemSize = (1 + 12 + 2);
	uint64 outLength = 1 + 3 + self->itemCount * itemSize;

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, 2 + 1, "[\n");
	currentIndex += 2;

	T* values = reinterpret_cast<T*>(self->data);

	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		snprintf(currentIndex, 1 + 12 + 2 + 1, " %12.6g,\n", static_cast<double>(values[itemIndex]));
		currentIndex += 1 + 12 + 2;
	}

	snprintf(currentIndex, 1 + 1, "]");

	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject*
glmArray_repr_ctypes(glmArray* self) {
	const char* subtypeName = PyGLM_CTYPES_TYPE_STRING<T>();

	const char* arrayTypeName = glmArrayType.tp_name + 4;

	const uint64 arrayNameLength = strlen(arrayTypeName);
	const uint64 subtypeNameLength = strlen(subtypeName);

	const uint64 itemSize = (subtypeNameLength + 2 + 12);
	const uint64 outLength = 1 + arrayNameLength + 2 + itemSize + (itemSize + 2) * (self->itemCount - 1);

	char* out = (char*)PyMem_Malloc(outLength * sizeof(char));
	if (out == NULL) {
		PyErr_SetString(PyExc_MemoryError, "out of memory");
		return NULL;
	}
	char* currentIndex = out;

	snprintf(currentIndex, arrayNameLength + 1 + 1, "%s(", arrayTypeName);
	currentIndex += arrayNameLength + 1;

	T* values = reinterpret_cast<T*>(self->data);

	for (Py_ssize_t itemIndex = 0; itemIndex < self->itemCount; itemIndex++) {
		snprintf(currentIndex, subtypeNameLength + 1 + 12 + 1, "%s(%g", subtypeName, static_cast<double>(values[itemIndex]));
		currentIndex += strlen(currentIndex);

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
	PyMem_Free(out);
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
	case PyGLM_TYPE_CTYPES:
		switch (self->format) {
		case 'f':
			return glmArray_str_ctypes<float>(self);
		case 'd':
			return glmArray_str_ctypes<double>(self);
		case 'i':
			return glmArray_str_ctypes<int32>(self);
		case 'I':
			return glmArray_str_ctypes<uint32>(self);
		case 'b':
			return glmArray_str_ctypes<int8>(self);
		case 'B':
			return glmArray_str_ctypes<uint8>(self);
		case 'h':
			return glmArray_str_ctypes<int16>(self);
		case 'H':
			return glmArray_str_ctypes<uint16>(self);
		case 'q':
			return glmArray_str_ctypes<int64>(self);
		case 'Q':
			return glmArray_str_ctypes<uint64>(self);
		case '?':
			return glmArray_str_ctypes<bool>(self);
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
	case PyGLM_TYPE_CTYPES:
		switch (self->format) {
		case 'f':
			return glmArray_repr_ctypes<float>(self);
		case 'd':
			return glmArray_repr_ctypes<double>(self);
		case 'i':
			return glmArray_repr_ctypes<int32>(self);
		case 'I':
			return glmArray_repr_ctypes<uint32>(self);
		case 'b':
			return glmArray_repr_ctypes<int8>(self);
		case 'B':
			return glmArray_repr_ctypes<uint8>(self);
		case 'h':
			return glmArray_repr_ctypes<int16>(self);
		case 'H':
			return glmArray_repr_ctypes<uint16>(self);
		case 'q':
			return glmArray_repr_ctypes<int64>(self);
		case 'Q':
			return glmArray_repr_ctypes<uint64>(self);
		case '?':
			return glmArray_repr_ctypes<bool>(self);
		default:
			return NULL;
		}
	default:
		return NULL;
	}
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

#define GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(T) if (firstElementType == UNBRACKET (PyGLM_CTYPES_TYPE<T>())) {return UNBRACKET (glmArray_init_ctypes_iter<T>(self, firstElement, iterator, argCount));}

template<typename T>
static int
glmArray_init_ctypes_iter(glmArray* self, PyObject* firstElement, PyObject* iterator, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(T);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_CTYPES_TYPE<T>();
	self->glmType = PyGLM_TYPE_CTYPES;
	self->format = get_format_specifier<T>();
	self->data = PyMem_Malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		Py_DECREF(iterator);
		Py_DECREF(firstElement);
		return -1;
	}
	T* dataAsTPtr = (T*)self->data;
	dataAsTPtr[0] = *reinterpret_cast<T*>(((ctypes_helper*)firstElement)->b_ptr);
	Py_DECREF(firstElement);
	for (Py_ssize_t i = 1; i < argCount; i++) {
		ctypes_helper* currentArg = (ctypes_helper*)PyIter_Next(iterator);
		if (Py_TYPE(currentArg) != self->subtype) {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
			Py_DECREF(iterator);
			Py_DECREF(currentArg);
			return -1;
		}
		dataAsTPtr[i] = *reinterpret_cast<T*>(currentArg->b_ptr);
		Py_DECREF(currentArg);
	}
	Py_DECREF(iterator);
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(T) if (firstElementType == UNBRACKET (PyGLM_CTYPES_TYPE<T>())) {return UNBRACKET (glmArray_init_ctypes_tuple_or_list<T>(self, args, argCount));}

template<typename T>
static int
glmArray_init_ctypes_tuple_or_list(glmArray* self, PyObject* args, Py_ssize_t argCount) {
	self->itemCount = argCount;
	self->dtSize = sizeof(T);
	self->itemSize = sizeof(T);
	self->nBytes = self->itemSize * argCount;
	self->subtype = PyGLM_CTYPES_TYPE<T>();
	self->glmType = PyGLM_TYPE_CTYPES;
	self->format = get_format_specifier<T>();
	self->data = PyMem_Malloc(self->nBytes);

	if (self->data == NULL) {
		PyErr_SetString(PyExc_MemoryError, "array creation failed");
		return -1;
	}
	T* dataAsTPtr = (T*)self->data;
	for (Py_ssize_t i = 0; i < argCount; i++) {
		ctypes_helper* currentArg = (ctypes_helper*)PyGLM_TupleOrList_GET_ITEM(args, i);
		if (Py_TYPE(currentArg) != self->subtype) {
			PyGLM_free(self->data);
			PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same type");
			return -1;
		}
		dataAsTPtr[i] = *reinterpret_cast<T*>(currentArg->b_ptr);
	}
	return 0;
}

#define GLM_ARRAY_INIT_IF_IS_VEC_BUFFER(T) self->dtSize = sizeof(T);\
self->itemSize = L * self->dtSize;\
self->nBytes = self->itemSize * self->itemCount;\
self->subtype = (L == 1) ? PyGLM_VEC_TYPE<1, T>() : (L == 2) ? PyGLM_VEC_TYPE<2, T>() : (L == 3) ? PyGLM_VEC_TYPE<3, T>() : PyGLM_VEC_TYPE<4, T>();\
self->data = PyMem_Malloc(self->nBytes);\
if (self->data == NULL) {\
	PyErr_SetString(PyExc_MemoryError, "out of memory");\
	return -1;\
}\
memcpy(self->data, view.buf, self->nBytes);\
PyBuffer_Release(&view);\
return 0

#define GLM_ARRAY_INIT_IF_IS_MAT_BUFFER(T) self->itemSize = self->dtSize * C * R;\
self->subtype = (C == 2) ? (R == 2) ? PyGLM_MAT_TYPE<2, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<2, 3, T>() : PyGLM_MAT_TYPE<2, 4, T>() :\
(C == 3) ? (R == 2) ? PyGLM_MAT_TYPE<3, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<3, 3, T>() : PyGLM_MAT_TYPE<3, 4, T>() :\
(R == 2) ? PyGLM_MAT_TYPE<4, 2, T>() : (R == 3) ? PyGLM_MAT_TYPE<4, 3, T>() : PyGLM_MAT_TYPE<4, 4, T>();\
PyBuffer_Release(&view);\
return 0

#define GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(T) self->dtSize = sizeof(T);\
self->itemSize = self->dtSize;\
self->nBytes = self->itemSize * self->itemCount;\
self->subtype = PyGLM_CTYPES_TYPE<T>();\
self->data = PyMem_Malloc(self->nBytes);\
if (self->data == NULL) {\
	PyErr_SetString(PyExc_MemoryError, "out of memory");\
	return -1;\
}\
memcpy(self->data, view.buf, self->nBytes);\
PyBuffer_Release(&view);\
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

	// PyGLM types
	if (PyGLM_Is_PyGLM_Type(firstElementType)) {
		PyGLMTypeObject* pto = (PyGLMTypeObject*)firstElementType;

		self->itemCount = argCount;
		self->dtSize = pto->dtSize;
		self->itemSize = pto->itemSize;
		self->nBytes = self->itemSize * argCount;
		self->subtype = pto->subtype;
		self->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		self->shape[0] = pto->C;
		self->shape[1] = pto->R;
		self->format = pto->format;
		self->data = PyMem_Malloc(self->nBytes);

		if (self->data == NULL) {
			PyErr_SetString(PyExc_MemoryError, "array creation failed");
			return -1;
		}
		char* dataAsCharPtr = reinterpret_cast<char*>(self->data);
		for (Py_ssize_t i = 0; i < argCount; i++) {
			PyObject* currentArg = PyGLM_TupleOrList_GET_ITEM(args, i);
			if (Py_TYPE(currentArg) == self->subtype) {
				memcpy(dataAsCharPtr + (i * self->itemSize), pto->getDataOf(currentArg), self->itemSize);
			}
			else if (self->glmType == PyGLM_TYPE_VEC && (((PyGLMTypeObject*)(Py_TYPE(currentArg)))->PTI_info & (pto->PTI_info | PyGLM_T_MVEC)) == ((PyGLMTypeObject*)(Py_TYPE(currentArg)))->PTI_info) {
				memcpy(dataAsCharPtr + (i * self->itemSize), ((PyGLMTypeObject*)(Py_TYPE(currentArg)))->getDataOf(currentArg), self->itemSize);
			}
			else {
				PyGLM_free(self->data);
				PyErr_SetString(PyExc_TypeError, "arrays have to be initialized with arguments of the same glm type");
				return -1;
			}
		}
		return 0;
	}

	// ctypes
	if (PyGLM_Ctypes_Check(firstElementType)) {
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(float);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(double);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(int8);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(int16);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(int32);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(int64);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(uint8);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(uint16);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(uint32);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(uint64);
		GLM_ARRAY_INIT_IF_IS_CTYPES_TUPLE_OR_LIST(bool);
	}

	if (PyType_FastSubclass(firstElementType, Py_TPFLAGS_TYPE_SUBCLASS)) {
		if (firstElement == ctypes_float) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<float>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_double) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<double>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_int8) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<int8>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_int16) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<int16>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_int32) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<int32>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_int64) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<int64>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_uint8) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<uint8>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_uint16) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<uint16>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_uint32) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<uint32>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_uint64) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<uint64>(self, args, argCount))
				return 0;
			return -1;
		}
		if (firstElement == ctypes_bool) {
			self->subtype = (PyTypeObject*)firstElement;
			self->glmType = PyGLM_TYPE_CTYPES;
			if (glmArray_from_numbers_init<bool>(self, args, argCount))
				return 0;
			return -1;
		}
	}

	// others
	if (argCount == 1) {
		// arrays
		if (PyGLM_Array_Check(firstElementType)) {
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
			self->data = PyMem_Malloc(self->nBytes);
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
			if (PyObject_GetBuffer(firstElement, &view, PyBUF_RECORDS_RO) == -1 || view.buf == NULL || view.format == NULL || view.shape == NULL || view.strides == NULL) {
				PyBuffer_Release(&view);
				PyErr_SetString(PyExc_BufferError, "invalid buffer");
				return -1;
			}
			if (view.ndim == 1) {
				self->itemCount = view.shape[0];
				self->format = view.format[0];

				if (self->format == 'l') self->format = 'i';
				else if (self->format == 'L') self->format = 'I';

				self->glmType = PyGLM_TYPE_CTYPES;
				switch (self->format) {
				case 'f':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(float);
				case 'd':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(double);
				case 'i':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(int32);
				case 'I':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(uint32);
				case 'b':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(int8);
				case 'B':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(uint8);
				case 'h':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(int16);
				case 'H':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(uint16);
				case 'q':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(int64);
				case 'Q':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(uint64);
				case '?':
					GLM_ARRAY_INIT_IF_IS_CTYPES_BUFFER(bool);
				default:
					PyGLM_TYPEERROR_O("invalid argument type ", firstElement);
					PyBuffer_Release(&view);
					return -1;
				}
			}
			else if (view.ndim == 2) {
				if (view.shape[1] < 1 || view.shape[1] > 4) {
					PyErr_SetString(PyExc_ValueError, "invalid buffer shape");
					return -1;
				}
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
				if (view.shape[1] < 2 || view.shape[1] > 4 || view.shape[2] < 2 || view.shape[2] > 4) {
					PyErr_SetString(PyExc_ValueError, "invalid buffer shape");
					return -1;
				}
				self->itemCount = view.shape[0];
				int R = static_cast<int>(view.shape[1]);
				int C = static_cast<int>(view.shape[2]);

				self->nBytes = view.len;
				self->dtSize = view.itemsize;

				self->data = PyMem_Malloc(view.len);
				if (self->data == NULL) {
					PyErr_SetString(PyExc_MemoryError, "out of memory");
					return -1;
				}

				if (view.strides[0] == view.itemsize * C * R && view.strides[1] == view.itemsize && view.strides[2] == view.itemsize * R) {
					memcpy(self->data, view.buf, view.len);
				}
				else {
					char* dataPtr = (char*)self->data;
					char* bufPtr = (char*)view.buf;

					for (Py_ssize_t i0 = 0; i0 < self->itemCount; i0++) {
						for (Py_ssize_t i1 = 0; i1 < R; i1++) {
							for (Py_ssize_t i2 = 0; i2 < C; i2++) {
								Py_ssize_t origOffset = (view.strides[0] * i0 + view.strides[1] * i1 + view.strides[2] * i2);
								Py_ssize_t targetOffset = (view.itemsize * C * R * i0 + view.itemsize * i1 + view.itemsize * R * i2);
								memcpy(dataPtr + targetOffset, bufPtr + origOffset, view.itemsize);
							}
						}
					}
				}

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
			PyGLM_ASSERT_NO((argCount >= 1), "Iterable needs to have at least one element");
			PyObject* iterator = PyObject_GetIter(firstElement);
			PyObject* firstElement = PyIter_Next(iterator);
			PyTypeObject* firstElementType = Py_TYPE(firstElement);

			// PyGLM types
			if (PyGLM_Is_PyGLM_Type(firstElementType)) {
				PyGLMTypeObject* pto = (PyGLMTypeObject*)firstElementType;

				self->itemCount = argCount;
				self->dtSize = pto->dtSize;
				self->itemSize = pto->itemSize;
				self->nBytes = self->itemSize * argCount;
				self->subtype = pto->subtype;
				self->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
				self->shape[0] = pto->C;
				self->shape[1] = pto->R;
				self->format = pto->format;
				self->data = PyMem_Malloc(self->nBytes);

				if (self->data == NULL) {
					PyErr_SetString(PyExc_MemoryError, "array creation failed");
					Py_DECREF(iterator);
					Py_DECREF(firstElement);
					return -1;
				}
				char* dataAsCharPtr = reinterpret_cast<char*>(self->data);
				if (Py_TYPE(firstElement) == self->subtype) {
					memcpy(dataAsCharPtr, pto->getDataOf(firstElement), self->itemSize);
				}
				else if (self->glmType == PyGLM_TYPE_VEC && (((PyGLMTypeObject*)(Py_TYPE(firstElement)))->PTI_info & (pto->PTI_info | PyGLM_T_MVEC)) == ((PyGLMTypeObject*)(Py_TYPE(firstElement)))->PTI_info) {
					memcpy(dataAsCharPtr, ((PyGLMTypeObject*)(Py_TYPE(firstElement)))->getDataOf(firstElement), self->itemSize);
				}
				Py_DECREF(firstElement);
				for (Py_ssize_t i = 1; i < argCount; i++) {
					PyObject* currentArg = PyIter_Next(iterator);
					if (currentArg == NULL) {
						break;
					}
					if (Py_TYPE(currentArg) == self->subtype) {
						memcpy(dataAsCharPtr + (i * self->itemSize), pto->getDataOf(currentArg), self->itemSize);
					}
					else if (self->glmType == PyGLM_TYPE_VEC && (((PyGLMTypeObject*)(Py_TYPE(currentArg)))->PTI_info & (pto->PTI_info | PyGLM_T_MVEC)) == ((PyGLMTypeObject*)(Py_TYPE(currentArg)))->PTI_info) {
						memcpy(dataAsCharPtr + (i * self->itemSize), ((PyGLMTypeObject*)(Py_TYPE(currentArg)))->getDataOf(currentArg), self->itemSize);
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

			// ctypes
			if (PyGLM_Ctypes_Check(firstElementType)) {
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(float);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(double);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(int8);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(int16);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(int32);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(int64);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(uint8);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(uint16);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(uint32);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(uint64);
				GLM_ARRAY_INIT_IF_IS_CTYPES_ITER(bool);
			}

			if (PyType_FastSubclass(firstElementType, Py_TPFLAGS_TYPE_SUBCLASS)) {
				if (firstElement == ctypes_float) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<float>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_double) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<double>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_int8) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<int8>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_int16) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<int16>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_int32) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<int32>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_int64) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<int64>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_uint8) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<uint8>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_uint16) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<uint16>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_uint32) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<uint32>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_uint64) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<uint64>(self, iterator, argCount))
						return 0;
					return -1;
				}
				if (firstElement == ctypes_bool) {
					self->subtype = firstElementType;
					self->glmType = PyGLM_TYPE_CTYPES;
					if (glmArray_from_numbers_init_iter<bool>(self, iterator, argCount))
						return 0;
					return -1;
				}
			}
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
		self->readonly = false;
		self->reference = NULL;
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
	if (rgstate->sequence != NULL) {
		if (rgstate->seq_index < rgstate->sequence->itemCount)
			return glmArray_get(rgstate->sequence, rgstate->seq_index++);
		rgstate->seq_index = rgstate->sequence->itemCount;
	}
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

template<typename T>
static Py_hash_t
array_hash_ctypes(T* data, Py_ssize_t count) {
	std::hash<T> hasher;

	size_t seed = 0;

	for (Py_ssize_t i = 0; i < count; i++) {
		glm::detail::hash_combine(seed, hasher(data[i]));
	}

	if (seed == static_cast<size_t>(-1)) {
		return static_cast<Py_hash_t>(-2);
	}

	return  static_cast<Py_hash_t>(seed);
}

template<int L, typename T>
static Py_hash_t
array_hash_vec(glm::vec<L, T>* data, Py_ssize_t count) {
	std::hash<glm::vec<L, T>> hasher;

	size_t seed = 0;

	for (Py_ssize_t i = 0; i < count; i++) {
		glm::detail::hash_combine(seed, hasher(data[i]));
	}

	if (seed == static_cast<size_t>(-1)) {
		return static_cast<Py_hash_t>(-2);
	}

	return  static_cast<Py_hash_t>(seed);
}

template<int C, int R, typename T>
static Py_hash_t
array_hash_mat(glm::mat<C, R, T>* data, Py_ssize_t count) {
	std::hash<glm::mat<C, R, T>> hasher;

	size_t seed = 0;

	for (Py_ssize_t i = 0; i < count; i++) {
		glm::detail::hash_combine(seed, hasher(data[i]));
	}

	if (seed == static_cast<size_t>(-1)) {
		return static_cast<Py_hash_t>(-2);
	}

	return  static_cast<Py_hash_t>(seed);
}

template<typename T>
static Py_hash_t
array_hash_qua(glm::qua<T>* data, Py_ssize_t count) {
	std::hash<glm::qua<T>> hasher;

	size_t seed = 0;

	for (Py_ssize_t i = 0; i < count; i++) {
		glm::detail::hash_combine(seed, hasher(data[i]));
	}

	if (seed == static_cast<size_t>(-1)) {
		return static_cast<Py_hash_t>(-2);
	}

	return  static_cast<Py_hash_t>(seed);
}

static Py_hash_t
array_hash(glmArray* self, PyObject*) {
	uint8& glmType = self->glmType;
	PyTypeObject*& subtype = self->subtype;

	if (glmType == PyGLM_TYPE_VEC) {
		switch (self->shape[0]) {
		case 1:
			switch (self->format) {
			case get_format_specifier<float>() :
				return array_hash_vec<1, float>(reinterpret_cast<glm::vec<1, float>*>(self->data), self->itemCount);
			case get_format_specifier<double>() :
				return array_hash_vec<1, double>(reinterpret_cast<glm::vec<1, double>*>(self->data), self->itemCount);
			case get_format_specifier<int64>() :
				return array_hash_vec<1, int64>(reinterpret_cast<glm::vec<1, int64>*>(self->data), self->itemCount);
			case get_format_specifier<uint64>() :
				return array_hash_vec<1, uint64>(reinterpret_cast<glm::vec<1, uint64>*>(self->data), self->itemCount);
			case get_format_specifier<int32>() :
				return array_hash_vec<1, int32>(reinterpret_cast<glm::vec<1, int32>*>(self->data), self->itemCount);
			case get_format_specifier<uint32>() :
				return array_hash_vec<1, uint32>(reinterpret_cast<glm::vec<1, uint32>*>(self->data), self->itemCount);
			case get_format_specifier<int16>() :
				return array_hash_vec<1, int16>(reinterpret_cast<glm::vec<1, int16>*>(self->data), self->itemCount);
			case get_format_specifier<uint16>() :
				return array_hash_vec<1, uint16>(reinterpret_cast<glm::vec<1, uint16>*>(self->data), self->itemCount);
			case get_format_specifier<int8>() :
				return array_hash_vec<1, int8>(reinterpret_cast<glm::vec<1, int8>*>(self->data), self->itemCount);
			case get_format_specifier<uint8>() :
				return array_hash_vec<1, uint8>(reinterpret_cast<glm::vec<1, uint8>*>(self->data), self->itemCount);
			case get_format_specifier<bool>() :
				return array_hash_vec<1, bool>(reinterpret_cast<glm::vec<1, bool>*>(self->data), self->itemCount);
			}
		case 2:
			switch (self->format) {
			case get_format_specifier<float>() :
				return array_hash_vec<2, float>(reinterpret_cast<glm::vec<2, float>*>(self->data), self->itemCount);
			case get_format_specifier<double>() :
				return array_hash_vec<2, double>(reinterpret_cast<glm::vec<2, double>*>(self->data), self->itemCount);
			case get_format_specifier<int64>() :
				return array_hash_vec<2, int64>(reinterpret_cast<glm::vec<2, int64>*>(self->data), self->itemCount);
			case get_format_specifier<uint64>() :
				return array_hash_vec<2, uint64>(reinterpret_cast<glm::vec<2, uint64>*>(self->data), self->itemCount);
			case get_format_specifier<int32>() :
				return array_hash_vec<2, int32>(reinterpret_cast<glm::vec<2, int32>*>(self->data), self->itemCount);
			case get_format_specifier<uint32>() :
				return array_hash_vec<2, uint32>(reinterpret_cast<glm::vec<2, uint32>*>(self->data), self->itemCount);
			case get_format_specifier<int16>() :
				return array_hash_vec<2, int16>(reinterpret_cast<glm::vec<2, int16>*>(self->data), self->itemCount);
			case get_format_specifier<uint16>() :
				return array_hash_vec<2, uint16>(reinterpret_cast<glm::vec<2, uint16>*>(self->data), self->itemCount);
			case get_format_specifier<int8>() :
				return array_hash_vec<2, int8>(reinterpret_cast<glm::vec<2, int8>*>(self->data), self->itemCount);
			case get_format_specifier<uint8>() :
				return array_hash_vec<2, uint8>(reinterpret_cast<glm::vec<2, uint8>*>(self->data), self->itemCount);
			case get_format_specifier<bool>() :
				return array_hash_vec<2, bool>(reinterpret_cast<glm::vec<2, bool>*>(self->data), self->itemCount);
			}
		case 3:
			switch (self->format) {
			case get_format_specifier<float>() :
				return array_hash_vec<3, float>(reinterpret_cast<glm::vec<3, float>*>(self->data), self->itemCount);
			case get_format_specifier<double>() :
				return array_hash_vec<3, double>(reinterpret_cast<glm::vec<3, double>*>(self->data), self->itemCount);
			case get_format_specifier<int64>() :
				return array_hash_vec<3, int64>(reinterpret_cast<glm::vec<3, int64>*>(self->data), self->itemCount);
			case get_format_specifier<uint64>() :
				return array_hash_vec<3, uint64>(reinterpret_cast<glm::vec<3, uint64>*>(self->data), self->itemCount);
			case get_format_specifier<int32>() :
				return array_hash_vec<3, int32>(reinterpret_cast<glm::vec<3, int32>*>(self->data), self->itemCount);
			case get_format_specifier<uint32>() :
				return array_hash_vec<3, uint32>(reinterpret_cast<glm::vec<3, uint32>*>(self->data), self->itemCount);
			case get_format_specifier<int16>() :
				return array_hash_vec<3, int16>(reinterpret_cast<glm::vec<3, int16>*>(self->data), self->itemCount);
			case get_format_specifier<uint16>() :
				return array_hash_vec<3, uint16>(reinterpret_cast<glm::vec<3, uint16>*>(self->data), self->itemCount);
			case get_format_specifier<int8>() :
				return array_hash_vec<3, int8>(reinterpret_cast<glm::vec<3, int8>*>(self->data), self->itemCount);
			case get_format_specifier<uint8>() :
				return array_hash_vec<3, uint8>(reinterpret_cast<glm::vec<3, uint8>*>(self->data), self->itemCount);
			case get_format_specifier<bool>() :
				return array_hash_vec<3, bool>(reinterpret_cast<glm::vec<3, bool>*>(self->data), self->itemCount);
			}
		case 4:
			switch (self->format) {
			case get_format_specifier<float>() :
				return array_hash_vec<4, float>(reinterpret_cast<glm::vec<4, float>*>(self->data), self->itemCount);
			case get_format_specifier<double>() :
				return array_hash_vec<4, double>(reinterpret_cast<glm::vec<4, double>*>(self->data), self->itemCount);
			case get_format_specifier<int64>() :
				return array_hash_vec<4, int64>(reinterpret_cast<glm::vec<4, int64>*>(self->data), self->itemCount);
			case get_format_specifier<uint64>() :
				return array_hash_vec<4, uint64>(reinterpret_cast<glm::vec<4, uint64>*>(self->data), self->itemCount);
			case get_format_specifier<int32>() :
				return array_hash_vec<4, int32>(reinterpret_cast<glm::vec<4, int32>*>(self->data), self->itemCount);
			case get_format_specifier<uint32>() :
				return array_hash_vec<4, uint32>(reinterpret_cast<glm::vec<4, uint32>*>(self->data), self->itemCount);
			case get_format_specifier<int16>() :
				return array_hash_vec<4, int16>(reinterpret_cast<glm::vec<4, int16>*>(self->data), self->itemCount);
			case get_format_specifier<uint16>() :
				return array_hash_vec<4, uint16>(reinterpret_cast<glm::vec<4, uint16>*>(self->data), self->itemCount);
			case get_format_specifier<int8>() :
				return array_hash_vec<4, int8>(reinterpret_cast<glm::vec<4, int8>*>(self->data), self->itemCount);
			case get_format_specifier<uint8>() :
				return array_hash_vec<4, uint8>(reinterpret_cast<glm::vec<4, uint8>*>(self->data), self->itemCount);
			case get_format_specifier<bool>() :
				return array_hash_vec<4, bool>(reinterpret_cast<glm::vec<4, bool>*>(self->data), self->itemCount);
			}
		}
	}
	if (glmType == PyGLM_TYPE_MAT) {
		switch (self->shape[0]) {
		case 2:
			switch (self->shape[1]) {
			case 2:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<2, 2, float>(reinterpret_cast<glm::mat<2, 2, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<2, 2, double>(reinterpret_cast<glm::mat<2, 2, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<2, 2, int32>(reinterpret_cast<glm::mat<2, 2, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<2, 2, uint32>(reinterpret_cast<glm::mat<2, 2, uint32>*>(self->data), self->itemCount);
				}
			case 3:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<2, 3, float>(reinterpret_cast<glm::mat<2, 3, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<2, 3, double>(reinterpret_cast<glm::mat<2, 3, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<2, 3, int32>(reinterpret_cast<glm::mat<2, 3, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<2, 3, uint32>(reinterpret_cast<glm::mat<2, 3, uint32>*>(self->data), self->itemCount);
				}
			case 4:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<2, 4, float>(reinterpret_cast<glm::mat<2, 4, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<2, 4, double>(reinterpret_cast<glm::mat<2, 4, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<2, 4, int32>(reinterpret_cast<glm::mat<2, 4, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<2, 4, uint32>(reinterpret_cast<glm::mat<2, 4, uint32>*>(self->data), self->itemCount);
				}
			}
		case 3:
			switch (self->shape[1]) {
			case 2:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<3, 2, float>(reinterpret_cast<glm::mat<3, 2, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<3, 2, double>(reinterpret_cast<glm::mat<3, 2, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<3, 2, int32>(reinterpret_cast<glm::mat<3, 2, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<3, 2, uint32>(reinterpret_cast<glm::mat<3, 2, uint32>*>(self->data), self->itemCount);
				}
			case 3:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<3, 3, float>(reinterpret_cast<glm::mat<3, 3, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<3, 3, double>(reinterpret_cast<glm::mat<3, 3, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<3, 3, int32>(reinterpret_cast<glm::mat<3, 3, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<3, 3, uint32>(reinterpret_cast<glm::mat<3, 3, uint32>*>(self->data), self->itemCount);
				}
			case 4:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<3, 4, float>(reinterpret_cast<glm::mat<3, 4, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<3, 4, double>(reinterpret_cast<glm::mat<3, 4, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<3, 4, int32>(reinterpret_cast<glm::mat<3, 4, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<3, 4, uint32>(reinterpret_cast<glm::mat<3, 4, uint32>*>(self->data), self->itemCount);
				}
			}
		case 4:
			switch (self->shape[1]) {
			case 2:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<4, 2, float>(reinterpret_cast<glm::mat<4, 2, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<4, 2, double>(reinterpret_cast<glm::mat<4, 2, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<4, 2, int32>(reinterpret_cast<glm::mat<4, 2, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<4, 2, uint32>(reinterpret_cast<glm::mat<4, 2, uint32>*>(self->data), self->itemCount);
				}
			case 3:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<4, 3, float>(reinterpret_cast<glm::mat<4, 3, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<4, 3, double>(reinterpret_cast<glm::mat<4, 3, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<4, 3, int32>(reinterpret_cast<glm::mat<4, 3, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<4, 3, uint32>(reinterpret_cast<glm::mat<4, 3, uint32>*>(self->data), self->itemCount);
				}
			case 4:
				switch (self->format) {
				case get_format_specifier<float>():
					return array_hash_mat<4, 4, float>(reinterpret_cast<glm::mat<4, 4, float>*>(self->data), self->itemCount);
				case get_format_specifier<double>():
					return array_hash_mat<4, 4, double>(reinterpret_cast<glm::mat<4, 4, double>*>(self->data), self->itemCount);
				case get_format_specifier<int32>():
					return array_hash_mat<4, 4, int32>(reinterpret_cast<glm::mat<4, 4, int32>*>(self->data), self->itemCount);
				case get_format_specifier<uint32>():
					return array_hash_mat<4, 4, uint32>(reinterpret_cast<glm::mat<4, 4, uint32>*>(self->data), self->itemCount);
				}
			}
		}
	}
	if (glmType == PyGLM_TYPE_QUA) {
		if (subtype == PyGLM_QUA_TYPE<float>())
			return array_hash_qua<float>(reinterpret_cast<glm::qua<float>*>(self->data), self->itemCount);

		if (subtype == PyGLM_QUA_TYPE<double>())
			return array_hash_qua<double>(reinterpret_cast<glm::qua<double>*>(self->data), self->itemCount);
	}
	if (glmType == PyGLM_TYPE_CTYPES) {
		if (subtype == PyGLM_CTYPES_TYPE<float>())
			return array_hash_ctypes<float>(reinterpret_cast<float*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<double>())
			return array_hash_ctypes<double>(reinterpret_cast<double*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<int8>())
			return array_hash_ctypes<int8>(reinterpret_cast<int8*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<int16>())
			return array_hash_ctypes<int16>(reinterpret_cast<int16*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<int32>())
			return array_hash_ctypes<int32>(reinterpret_cast<int32*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<int64>())
			return array_hash_ctypes<int64>(reinterpret_cast<int64*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<uint8>())
			return array_hash_ctypes<uint8>(reinterpret_cast<uint8*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<uint16>())
			return array_hash_ctypes<uint16>(reinterpret_cast<uint16*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<uint32>())
			return array_hash_ctypes<uint32>(reinterpret_cast<uint32*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<uint64>())
			return array_hash_ctypes<uint64>(reinterpret_cast<uint64*>(self->data), self->itemCount);
		if (subtype == PyGLM_CTYPES_TYPE<bool>())
			return array_hash_ctypes<bool>(reinterpret_cast<bool*>(self->data), self->itemCount);
	}
	return -1;
}




static PyObject* glmArray_filter(glmArray* self, PyObject* func) {
	std::vector<PyObject*> outObjects{};

	if (PyCallable_Check(func)) {
		PyObject* argTuple = PyTuple_New(1);

		for (Py_ssize_t i = 0; i < self->itemCount; i++) {
			PyObject* currentItem = glmArray_get(self, i);

			// Abusing the SET_ITEM macro for increased performance
			PyTuple_SET_ITEM(argTuple, 0, currentItem);

			PyObject* filterResult = PyObject_CallObject(func, argTuple);

			if (filterResult == NULL) {
				Py_DECREF(currentItem);
				Py_DECREF(argTuple);
				return NULL;
			}

			bool filterResultAsBool;

			if (PyBool_Check(filterResult)) {
				filterResultAsBool = (filterResult == Py_True);
			}
			else {
				int filterResultAsInt = PyObject_IsTrue(filterResult);
				if (filterResultAsInt == -1) {
					PyErr_SetString(PyExc_ValueError, "The result of the filter function could not be interpreted as bool.");
					return NULL;
				}
				filterResultAsBool = static_cast<bool>(filterResultAsInt);
			}

			Py_DECREF(filterResult);

			if (filterResultAsBool) {
				outObjects.push_back(currentItem);
			}
			else {
				Py_DECREF(currentItem);
			}
		}
		// Setting the first argument of the abused tuple to NULL to avoid memory corruption when DECREF is called
		PyTuple_SET_ITEM(argTuple, 0, NULL);

		Py_DECREF(argTuple);

		const size_t outObjectsSize = outObjects.size();
		
		if (outObjectsSize) {
			PyObject* firstOutObject = outObjects[0];
			if (PyLong_CheckExact(firstOutObject) || PyFloat_CheckExact(firstOutObject) || PyBool_Check(firstOutObject)) {
				// for number values

				PyObject* fromNumbersArgs = PyTuple_New(outObjectsSize + 1);
				PyTuple_SET_ITEM(fromNumbersArgs, 0, PyGLM_INCREF((PyObject*)self->subtype));

				for (size_t i = 0; i < outObjectsSize; i++) {
					PyTuple_SET_ITEM(fromNumbersArgs, i + 1, outObjects[i]);
				}

				PyObject* out = glmArray_from_numbers(NULL, fromNumbersArgs);
				Py_DECREF(fromNumbersArgs);
				if (out == NULL) {
					PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the filtered values. This should not occur.");
					return NULL;
				}
				return out;
			}
			// for other values
			PyObject* args = PyTuple_New(outObjectsSize);
			for (size_t i = 0; i < outObjectsSize; i++) {
				PyTuple_SET_ITEM(args, i, outObjects[i]);
			}
			glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
			int initResult = glmArray_init(outArray, args, NULL);
			Py_DECREF(args);
			if (initResult == 0) {
				return (PyObject*)outArray;
			}
			PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the filtered values. This should not occur.");
			return NULL;
		}

		// for empty results
		glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
		outArray->dtSize = self->dtSize;
		outArray->format = self->format;
		outArray->glmType = self->glmType;
		outArray->itemSize = self->itemSize;
		outArray->shape[0] = self->shape[0];
		outArray->shape[1] = self->shape[1];
		outArray->subtype = self->subtype;
		return (PyObject*)outArray;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for filter(). Expected callable, got ", func);
	return NULL;
}

static PyObject* glmArray_map_binary(glmArray* self, PyObject* func, PyObject* arg, PyObject* requested_ctypes_type) {
	std::vector<PyObject*> outObjects{};

	PyObject* argTuple = PyTuple_New(2);

	if (PyCallable_Check(func)) {
		if (PyObject_TypeCheck(arg, &glmArrayType)) { // arg is an array
			glmArray* other = (glmArray*)arg;

			if (other->itemCount != self->itemCount) {
				PyErr_SetString(PyExc_ValueError, "Invalid argument value for 'map_binary()'. The supplied array doesn't have the same item count as this one.");
				return NULL;
			}

			for (Py_ssize_t i = 0; i < self->itemCount; i++) {
				PyObject* currentItem1 = glmArray_get(self, i);
				PyObject* currentItem2 = glmArray_get(other, i);

				// Abusing the SET_ITEM macro for increased performance
				PyTuple_SET_ITEM(argTuple, 0, currentItem1);
				PyTuple_SET_ITEM(argTuple, 1, currentItem2);

				PyObject* mapResult = PyObject_CallObject(func, argTuple);

				if (mapResult == NULL) {
					return NULL;
				}

				if (mapResult != Py_None) {
					if (PyTuple_Check(mapResult)) {
						for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
							outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
						}
						Py_DECREF(mapResult);
					}
					else {
						outObjects.push_back(mapResult);
					}
				}
				else {
					Py_DECREF(mapResult);
				}
				Py_DECREF(currentItem1);
				Py_DECREF(currentItem2);
			}
		}
		else { // arg is a constant second argument
			PyTuple_SET_ITEM(argTuple, 1, arg);
			for (Py_ssize_t i = 0; i < self->itemCount; i++) {
				PyObject* currentItem = glmArray_get(self, i);

				// Abusing the SET_ITEM macro for increased performance
				PyTuple_SET_ITEM(argTuple, 0, currentItem);

				PyObject* mapResult = PyObject_CallObject(func, argTuple);

				if (mapResult == NULL) {
					return NULL;
				}

				if (mapResult != Py_None) {
					if (PyTuple_Check(mapResult)) {
						for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
							outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
						}
						Py_DECREF(mapResult);
					}
					else {
						outObjects.push_back(mapResult);
					}
				}
				else {
					Py_DECREF(mapResult);
				}
				Py_DECREF(currentItem);
			}
		}


		// Setting the items of the abused tuple to NULL to avoid memory corruption when DECREF is called
		PyTuple_SET_ITEM(argTuple, 0, NULL);
		PyTuple_SET_ITEM(argTuple, 1, NULL);

		Py_DECREF(argTuple);

		const size_t outObjectsSize = outObjects.size();

		if (outObjectsSize) {
			PyObject* firstOutObject = outObjects[0];
			if (PyLong_CheckExact(firstOutObject) || PyFloat_CheckExact(firstOutObject) || PyBool_Check(firstOutObject)) {
				// for number values
				if (requested_ctypes_type == NULL) {
					requested_ctypes_type = glmArray_getCtype(self, NULL);
				}
				PyObject* fromNumbersArgs = PyTuple_New(outObjectsSize + 1);
				PyTuple_SET_ITEM(fromNumbersArgs, 0, requested_ctypes_type);

				for (size_t i = 0; i < outObjectsSize; i++) {
					PyTuple_SET_ITEM(fromNumbersArgs, i + 1, outObjects[i]);
				}

				PyObject* out = glmArray_from_numbers(NULL, fromNumbersArgs);
				Py_DECREF(fromNumbersArgs);
				if (out == NULL) {
					PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
					return NULL;
				}
				return out;
			}
			// for other values
			PyObject* args = PyTuple_New(outObjectsSize);
			for (size_t i = 0; i < outObjectsSize; i++) {
				PyTuple_SET_ITEM(args, i, outObjects[i]);
			}
			glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
			int initResult = glmArray_init(outArray, args, NULL);
			Py_DECREF(args);
			if (initResult == 0) {
				return (PyObject*)outArray;
			}
			PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
			return NULL;
		}
		// for empty results
		glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
		outArray->dtSize = self->dtSize;
		outArray->format = self->format;
		outArray->glmType = self->glmType;
		outArray->itemSize = self->itemSize;
		outArray->shape[0] = self->shape[0];
		outArray->shape[1] = self->shape[1];
		outArray->subtype = self->subtype;
		return (PyObject*)outArray;
	}
	PyGLM_TYPEERROR_2O("Invalid argument type for map_binary(). Expected callable, got ", func, arg);
	return NULL;
}

static PyObject* glmArray_map_ternary(glmArray* self, PyObject* func, PyObject* arg1, PyObject* arg2, PyObject* requested_ctypes_type) {
	std::vector<PyObject*> outObjects{};

	PyObject* argTuple = PyTuple_New(3);

	if (PyCallable_Check(func)) {
		if (PyObject_TypeCheck(arg1, &glmArrayType)) { // arg1 is an array
			glmArray* other1 = (glmArray*)arg1;

			if (other1->itemCount != self->itemCount) {
				PyErr_SetString(PyExc_ValueError, "Invalid argument value for 'map_ternary()'. One of the supplied arrays doesn't have the same item count as this one.");
				return NULL;
			}

			if (PyObject_TypeCheck(arg2, &glmArrayType)) { // arg2 is an array
				glmArray* other2 = (glmArray*)arg2;

				if (other2->itemCount != self->itemCount) {
					PyErr_SetString(PyExc_ValueError, "Invalid argument value for 'map_ternary()'. One of the supplied arrays doesn't have the same item count as this one.");
					return NULL;
				}

				for (Py_ssize_t i = 0; i < self->itemCount; i++) {
					PyObject* currentItem1 = glmArray_get(self, i);
					PyObject* currentItem2 = glmArray_get(other1, i);
					PyObject* currentItem3 = glmArray_get(other2, i);

					// Abusing the SET_ITEM macro for increased performance
					PyTuple_SET_ITEM(argTuple, 0, currentItem1);
					PyTuple_SET_ITEM(argTuple, 1, currentItem2);
					PyTuple_SET_ITEM(argTuple, 2, currentItem3);

					PyObject* mapResult = PyObject_CallObject(func, argTuple);

					if (mapResult == NULL) {
						return NULL;
					}

					if (mapResult != Py_None) {
						if (PyTuple_Check(mapResult)) {
							for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
								outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
							}
							Py_DECREF(mapResult);
						}
						else {
							outObjects.push_back(mapResult);
						}
					}
					else {
						Py_DECREF(mapResult);
					}
					Py_DECREF(currentItem1);
					Py_DECREF(currentItem2);
					Py_DECREF(currentItem3);
				}
			}
			else { // arg2 is a constant third argument
				PyTuple_SET_ITEM(argTuple, 2, arg2);

				for (Py_ssize_t i = 0; i < self->itemCount; i++) {
					PyObject* currentItem1 = glmArray_get(self, i);
					PyObject* currentItem2 = glmArray_get(other1, i);

					// Abusing the SET_ITEM macro for increased performance
					PyTuple_SET_ITEM(argTuple, 0, currentItem1);
					PyTuple_SET_ITEM(argTuple, 1, currentItem2);

					PyObject* mapResult = PyObject_CallObject(func, argTuple);

					if (mapResult == NULL) {
						return NULL;
					}

					if (mapResult != Py_None) {
						if (PyTuple_Check(mapResult)) {
							for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
								outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
							}
							Py_DECREF(mapResult);
						}
						else {
							outObjects.push_back(mapResult);
						}
					}
					else {
						Py_DECREF(mapResult);
					}
					Py_DECREF(currentItem1);
					Py_DECREF(currentItem2);
				}
			}
		}
		else { // arg1 is a constant second argument
			PyTuple_SET_ITEM(argTuple, 1, arg1);

			if (PyObject_TypeCheck(arg2, &glmArrayType)) {
				glmArray* other = (glmArray*)arg2;

				if (other->itemCount != self->itemCount) {
					PyErr_SetString(PyExc_ValueError, "Invalid argument value for 'map_ternary()'. The supplied array doesn't have the same item count as this one.");
					return NULL;
				}

				for (Py_ssize_t i = 0; i < self->itemCount; i++) {
					PyObject* currentItem1 = glmArray_get(self, i);
					PyObject* currentItem3 = glmArray_get(other, i);

					// Abusing the SET_ITEM macro for increased performance
					PyTuple_SET_ITEM(argTuple, 0, currentItem1);
					PyTuple_SET_ITEM(argTuple, 2, currentItem3);

					PyObject* mapResult = PyObject_CallObject(func, argTuple);

					if (mapResult == NULL) {
						return NULL;
					}

					if (mapResult != Py_None) {
						if (PyTuple_Check(mapResult)) {
							for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
								outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
							}
							Py_DECREF(mapResult);
						}
						else {
							outObjects.push_back(mapResult);
						}
					}
					else {
						Py_DECREF(mapResult);
					}
					Py_DECREF(currentItem1);
					Py_DECREF(currentItem3);
				}
			}
			else {
				PyTuple_SET_ITEM(argTuple, 2, arg2);

				for (Py_ssize_t i = 0; i < self->itemCount; i++) {
					PyObject* currentItem = glmArray_get(self, i);

					// Abusing the SET_ITEM macro for increased performance
					PyTuple_SET_ITEM(argTuple, 0, currentItem);

					PyObject* mapResult = PyObject_CallObject(func, argTuple);

					if (mapResult == NULL) {
						return NULL;
					}

					if (mapResult != Py_None) {
						if (PyTuple_Check(mapResult)) {
							for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
								outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
							}
							Py_DECREF(mapResult);
						}
						else {
							outObjects.push_back(mapResult);
						}
					}
					else {
						Py_DECREF(mapResult);
					}
					Py_DECREF(currentItem);
				}
			}
		}


		// Setting the items of the abused tuple to NULL to avoid memory corruption when DECREF is called
		PyTuple_SET_ITEM(argTuple, 0, NULL);
		PyTuple_SET_ITEM(argTuple, 1, NULL);
		PyTuple_SET_ITEM(argTuple, 2, NULL);

		Py_DECREF(argTuple);

		const size_t outObjectsSize = outObjects.size();

		if (outObjectsSize) {
			PyObject* firstOutObject = outObjects[0];
			if (PyLong_CheckExact(firstOutObject) || PyFloat_CheckExact(firstOutObject) || PyBool_Check(firstOutObject)) {
				// for number values
				if (requested_ctypes_type == NULL) {
					requested_ctypes_type = glmArray_getCtype(self, NULL);
				}
				PyObject* fromNumbersArgs = PyTuple_New(outObjectsSize + 1);
				PyTuple_SET_ITEM(fromNumbersArgs, 0, requested_ctypes_type);

				for (size_t i = 0; i < outObjectsSize; i++) {
					PyTuple_SET_ITEM(fromNumbersArgs, i + 1, outObjects[i]);
				}

				PyObject* out = glmArray_from_numbers(NULL, fromNumbersArgs);
				Py_DECREF(fromNumbersArgs);
				if (out == NULL) {
					PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
					return NULL;
				}
				return out;
			}
			// for other values
			PyObject* args = PyTuple_New(outObjectsSize);
			for (size_t i = 0; i < outObjectsSize; i++) {
				PyTuple_SET_ITEM(args, i, outObjects[i]);
			}
			glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
			int initResult = glmArray_init(outArray, args, NULL);
			Py_DECREF(args);
			if (initResult == 0) {
				return (PyObject*)outArray;
			}
			PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
			return NULL;
		}
		// for empty results
		glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
		outArray->dtSize = self->dtSize;
		outArray->format = self->format;
		outArray->glmType = self->glmType;
		outArray->itemSize = self->itemSize;
		outArray->shape[0] = self->shape[0];
		outArray->shape[1] = self->shape[1];
		outArray->subtype = self->subtype;
		return (PyObject*)outArray;
	}
	PyErr_SetString(PyExc_TypeError, "Invalid argument type(s) for 'map_ternary()'. Expected a function and two other objects.");
	return NULL;
}

static PyObject* glmArray_map_varargs(glmArray* self, PyObject* args, PyObject* requested_ctypes_type) {
	Py_ssize_t argsSize = PyTuple_GET_SIZE(args);

	PyObject* func = PyTuple_GET_ITEM(args, 0);

	std::vector<PyObject*> outObjects{};

	PyObject* argTuple = PyTuple_New(argsSize);

	if (PyCallable_Check(func)) {

		std::vector<Py_ssize_t> arrayArgumentIndices{};

		for (Py_ssize_t i = 1; i < argsSize; i++) {
			PyObject* currentItem = PyTuple_GET_ITEM(args, i);
			if (PyObject_TypeCheck(currentItem, &glmArrayType)) {
				if (((glmArray*)currentItem)->itemCount != self->itemCount) {
					PyErr_SetString(PyExc_ValueError, "Invalid argument value for 'map_varargs()'. One of the supplied arrays doesn't have the same item count as this one.");
					return NULL;
				}
				arrayArgumentIndices.push_back(i);
			}
			else {
				PyTuple_SET_ITEM(argTuple, i, currentItem);
			}
		}

		for (Py_ssize_t i = 0; i < self->itemCount; i++) {
			PyObject* currentItemSelf = glmArray_get(self, i);

			// Abusing the SET_ITEM macro for increased performance
			PyTuple_SET_ITEM(argTuple, 0, currentItemSelf);

			for (Py_ssize_t arrayArgumentIndex : arrayArgumentIndices) {
				glmArray* currentArray = (glmArray*)PyTuple_GET_ITEM(args, arrayArgumentIndex);

				PyObject* currentArrayItem = glmArray_get(currentArray, i);

				PyTuple_SET_ITEM(argTuple, arrayArgumentIndex, currentArrayItem);
			}

			PyObject* mapResult = PyObject_CallObject(func, argTuple);

			if (mapResult == NULL) {
				return NULL;
			}

			if (mapResult != Py_None) {
				if (PyTuple_Check(mapResult)) {
					for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
						outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
					}
					Py_DECREF(mapResult);
				}
				else {
					outObjects.push_back(mapResult);
				}
			}
			else {
				Py_DECREF(mapResult);
			}
			Py_DECREF(currentItemSelf);

			for (Py_ssize_t arrayArgumentIndex : arrayArgumentIndices) {
				Py_DECREF(PyTuple_GET_ITEM(argTuple, arrayArgumentIndex));
			}
		}

		// Setting the items of the abused tuple to NULL to avoid memory corruption when DECREF is called

		for (Py_ssize_t i = 0; i < argsSize; i++) {
			PyTuple_SET_ITEM(argTuple, i, NULL);
		}

		Py_DECREF(argTuple);

		const size_t outObjectsSize = outObjects.size();

		if (outObjectsSize) {
			PyObject* firstOutObject = outObjects[0];
			if (PyLong_CheckExact(firstOutObject) || PyFloat_CheckExact(firstOutObject) || PyBool_Check(firstOutObject)) {
				// for number values
				if (requested_ctypes_type == NULL) {
					requested_ctypes_type = glmArray_getCtype(self, NULL);
				}
				PyObject* fromNumbersArgs = PyTuple_New(outObjectsSize + 1);
				PyTuple_SET_ITEM(fromNumbersArgs, 0, requested_ctypes_type);

				for (size_t i = 0; i < outObjectsSize; i++) {
					PyTuple_SET_ITEM(fromNumbersArgs, i + 1, outObjects[i]);
				}

				PyObject* out = glmArray_from_numbers(NULL, fromNumbersArgs);
				Py_DECREF(fromNumbersArgs);
				if (out == NULL) {
					PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
					return NULL;
				}
				return out;
			}
			// for other values
			PyObject* args = PyTuple_New(outObjectsSize);
			for (size_t i = 0; i < outObjectsSize; i++) {
				PyTuple_SET_ITEM(args, i, outObjects[i]);
			}
			glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
			int initResult = glmArray_init(outArray, args, NULL);
			Py_DECREF(args);
			if (initResult == 0) {
				return (PyObject*)outArray;
			}
			PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
			return NULL;
		}
		// for empty results
		glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
		outArray->dtSize = self->dtSize;
		outArray->format = self->format;
		outArray->glmType = self->glmType;
		outArray->itemSize = self->itemSize;
		outArray->shape[0] = self->shape[0];
		outArray->shape[1] = self->shape[1];
		outArray->subtype = self->subtype;
		return (PyObject*)outArray;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for map_varargs(). Expected callable, got ", func);
	return NULL;
}



static PyObject* glmArray_map(glmArray* self, PyObject* args, PyObject* kwargs) {
	PyObject* requested_ctypes_type = NULL;

	if (kwargs != NULL && PyDict_Size(kwargs) != 0) {
		PyGLM_ASSERT(PyDict_Size(kwargs) == 1, "Invalid keyword arguments for map()");

		requested_ctypes_type = PyDict_GetItemString(kwargs, "ctype");

		PyGLM_ASSERT(requested_ctypes_type != NULL, "Invalid keyword argument for map()");

		PyGLM_ASSERT(PyType_Check(requested_ctypes_type) && ((PyTypeObject*)requested_ctypes_type)->tp_dealloc == ctypes_dealloc, "Invalid argument value for 'ctype'. Expected a ctypes data type.");
	}

	Py_ssize_t argsSize = PyTuple_GET_SIZE(args);

	switch (argsSize) {
	case 0:
		PyErr_SetString(PyExc_TypeError, "Invalid argument count for map(). Expected one or more arguments, got 0");
		return NULL;
	case 1:
		break;
	case 2:
		return glmArray_map_binary(self, PyTuple_GET_ITEM(args, 0), PyTuple_GET_ITEM(args, 1), requested_ctypes_type);
	case 3:
		return glmArray_map_ternary(self, PyTuple_GET_ITEM(args, 0), PyTuple_GET_ITEM(args, 1), PyTuple_GET_ITEM(args, 2), requested_ctypes_type);
	default:
		return glmArray_map_varargs(self, args, requested_ctypes_type);
	}

	PyObject* func = PyTuple_GET_ITEM(args, 0);

	std::vector<PyObject*> outObjects{};

	PyObject* argTuple = PyTuple_New(1);

	if (PyCallable_Check(func)) {
		for (Py_ssize_t i = 0; i < self->itemCount; i++) {
			PyObject* currentItem = glmArray_get(self, i);

			// Abusing the SET_ITEM macro for increased performance
			PyTuple_SET_ITEM(argTuple, 0, currentItem);

			PyObject* mapResult = PyObject_CallObject(func, argTuple);

			if (mapResult == NULL) {
				return NULL;
			}

			if (mapResult != Py_None) {
				if (PyTuple_Check(mapResult)) {
					for (Py_ssize_t i = 0; i < PyTuple_GET_SIZE(mapResult); i++) {
						outObjects.push_back(PyGLM_INCREF(PyTuple_GET_ITEM(mapResult, i)));
					}
					Py_DECREF(mapResult);
				}
				else {
					outObjects.push_back(mapResult);
				}
			}
			else {
				Py_DECREF(mapResult);
			}
			Py_DECREF(currentItem);
		}

		// Setting the first argument of the abused tuple to NULL to avoid memory corruption when DECREF is called
		PyTuple_SET_ITEM(argTuple, 0, NULL);

		Py_DECREF(argTuple);

		const size_t outObjectsSize = outObjects.size();

		if (outObjectsSize) {
			PyObject* firstOutObject = outObjects[0];
			if (PyLong_CheckExact(firstOutObject) || PyFloat_CheckExact(firstOutObject) || PyBool_Check(firstOutObject)) {
				// for number values
				if (requested_ctypes_type == NULL) {
					requested_ctypes_type = glmArray_getCtype(self, NULL);
				}
				PyObject* fromNumbersArgs = PyTuple_New(outObjectsSize + 1);
				PyTuple_SET_ITEM(fromNumbersArgs, 0, requested_ctypes_type);

				for (size_t i = 0; i < outObjectsSize; i++) {
					PyTuple_SET_ITEM(fromNumbersArgs, i + 1, outObjects[i]);
				}

				PyObject* out = glmArray_from_numbers(NULL, fromNumbersArgs);
				Py_DECREF(fromNumbersArgs);
				if (out == NULL) {
					PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
					return NULL;
				}
				return out;
			}
			// for other values
			PyObject* args = PyTuple_New(outObjectsSize);
			for (size_t i = 0; i < outObjectsSize; i++) {
				PyTuple_SET_ITEM(args, i, outObjects[i]);
			}
			glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
			int initResult = glmArray_init(outArray, args, NULL);
			Py_DECREF(args);
			if (initResult == 0) {
				return (PyObject*)outArray;
			}
			PyErr_SetString(PyExc_ValueError, "Failed to construct the array from the mapped values. They're probably not of the same type!");
			return NULL;
		}
		// for empty results
		glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
		outArray->dtSize = self->dtSize;
		outArray->format = self->format;
		outArray->glmType = self->glmType;
		outArray->itemSize = self->itemSize;
		outArray->shape[0] = self->shape[0];
		outArray->shape[1] = self->shape[1];
		outArray->subtype = self->subtype;
		return (PyObject*)outArray;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for map(). Expected callable, got ", func);
	return NULL;
}

static int compare(PyObject* func, PyObject* funcArgs, long& cmp) {
	PyObject* comparisonResult = PyObject_CallObject(func, funcArgs);
	if (comparisonResult == NULL) {
		PyTuple_SET_ITEM(funcArgs, 0, NULL);
		PyTuple_SET_ITEM(funcArgs, 1, NULL);
		Py_DECREF(funcArgs);
		return -1;
	}
	if (!PyLong_Check(comparisonResult)) {
		PyGLM_TYPEERROR_O("The ordering function returned an invalid argument of type ", comparisonResult);
		Py_DECREF(comparisonResult);
		PyTuple_SET_ITEM(funcArgs, 0, NULL);
		PyTuple_SET_ITEM(funcArgs, 1, NULL);
		Py_DECREF(funcArgs);
		return -1;
	}

	cmp = PyLong_AS_LONG(comparisonResult);
	Py_DECREF(comparisonResult);

	return 0;
}

static int insertionSort(std::vector<PyObject*>& in, PyObject* func) {
	const size_t inSize = in.size();

	PyObject* x, * y;

	PyObject* funcArgs = PyTuple_New(2);

	int i, j;
	long cmp;
	for (i = 1; i < inSize; i++)
	{
		x = in[i];
		j = i - 1;

		PyTuple_SET_ITEM(funcArgs, 0, x);

		while (j >= 0)
		{
			y = in[j];
			PyTuple_SET_ITEM(funcArgs, 1, y);

			if (compare(func, funcArgs, cmp) < 0) {
				return -1;
			}
			if (cmp < 0) {
				in[j + 1] = in[j];
				j--;
			}
			else {
				break;
			}
		}
		in[j + 1] = x;
	}

	PyTuple_SET_ITEM(funcArgs, 0, NULL);
	PyTuple_SET_ITEM(funcArgs, 1, NULL);
	Py_DECREF(funcArgs);

	return 0;
}


static inline void qs_swap(std::vector<PyObject*>& in, int i, int j) {
	if (i != j) {
		PyObject* t = in[i];
		in[i] = in[j];
		in[j] = t;
	}
}

static int iquickSort(std::vector<PyObject*>& in, PyObject* func) {
	const size_t inSize = in.size();

	int l = 0;
	int h = static_cast<int>(inSize) - 1;

	if (inSize <= 1) {
		return 0;
	}

	int* stack = reinterpret_cast<int*>(PyMem_Malloc(inSize * sizeof(int)));

	if (stack == NULL) {
		PyErr_SetString(PyExc_MemoryError, "Out of memory");
		return -1;
	}

	int top = 0;

	stack[top] = l;
	stack[++top] = h;

	int p, i, pivot;
	long cmp;
	PyObject* x, *y;

	PyObject* funcArgs = PyTuple_New(2);

	while (top >= 0) {
		h = stack[top--];
		l = stack[top--];

		pivot = (h + l) / 2;

		qs_swap(in, pivot, h);

		y = in[h];

		i = l;

		PyTuple_SET_ITEM(funcArgs, 1, y);

		for (int j = l; j < h; j++) {
			x = in[j];
			PyTuple_SET_ITEM(funcArgs, 0, x);

			if (compare(func, funcArgs, cmp) < 0) {
				PyMem_Free(stack);
				return -1;
			}

			if (cmp < 0) {
				qs_swap(in, i++, j);
			}
		}

		p = i;
		qs_swap(in, p, h);

		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}

	PyTuple_SET_ITEM(funcArgs, 0, NULL);
	PyTuple_SET_ITEM(funcArgs, 1, NULL);
	Py_DECREF(funcArgs);

	PyMem_Free(stack);

	return 0;
}

static Py_ssize_t getSortedElementCount(std::vector<PyObject*>& in, PyObject* func) {
	const size_t inSize = in.size();

	Py_ssize_t sortedCount = 0;

	PyObject* funcArgs = PyTuple_New(2);

	long cmp;

	for (size_t i = 0; i < inSize - 1; i++) {
		PyTuple_SET_ITEM(funcArgs, 0, in[i]);
		PyTuple_SET_ITEM(funcArgs, 1, in[i + 1]);

		if (compare(func, funcArgs, cmp) < 0) {
			return -1;
		}

		if (cmp <= 0) {
			sortedCount++;
		}
	}

	PyTuple_SET_ITEM(funcArgs, 0, NULL);
	PyTuple_SET_ITEM(funcArgs, 1, NULL);
	Py_DECREF(funcArgs);

	return sortedCount;
}

static PyObject* glmArray_sort(glmArray* self, PyObject* func) {
	if (PyCallable_Check(func)) {
		std::vector<PyObject*> inObjects{};

		for (Py_ssize_t i = 0; i < self->itemCount; i++) {
			PyObject* tmp = glmArray_get(self, i);
			if (tmp == NULL) {
				for (size_t i = 0; i < inObjects.size(); i++) {
					Py_DECREF(inObjects[i]);
				}
				return NULL;
			}
			inObjects.push_back(tmp);
		}

		Py_ssize_t sortedCount = getSortedElementCount(inObjects, func);

		Py_ssize_t toBeSortedCount = (self->itemCount - 1) - sortedCount;

		if (sortedCount == -1) {
			for (Py_ssize_t i = 0; i < self->itemCount; i++) {
				Py_DECREF(inObjects[i]);
			}
			return NULL;
		}

		if (toBeSortedCount == 0) {
			// already sorted
		}
		else if (sortedCount == 0) {
			std::reverse(inObjects.begin(), inObjects.end());
		}
		else {
			if (std::min(sortedCount, toBeSortedCount) <= 100) { // little to sort. Use insertion sort
				if (sortedCount < toBeSortedCount) { // reverse if fewer sorted than to be sorted
					std::reverse(inObjects.begin(), inObjects.end());
				}
				if (insertionSort(inObjects, func) == -1) {
					for (Py_ssize_t i = 0; i < self->itemCount; i++) {
						Py_DECREF(inObjects[i]);
					}
					return NULL;
				}
			}
			
			else { // otherwise, use quicksort
				if (iquickSort(inObjects, func) == -1) {
					for (Py_ssize_t i = 0; i < self->itemCount; i++) {
						Py_DECREF(inObjects[i]);
					}
					return NULL;
				}
			}
		}

		for (Py_ssize_t i = 0; i < self->itemCount; i++) {
			glmArray_set(self, i, inObjects[i]);
			Py_DECREF(inObjects[i]);
		}

		Py_RETURN_NONE;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for sort(). Expected callable, got ", func);
	return NULL;
}

template<typename T>
static PyObject* glmArray_add_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] + arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_addO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] + o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_add(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_add_T<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_add_T<double>(arr1, arr2);
					case get_format_specifier<int64>() :
						return glmArray_add_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_add_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_add_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_add_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_add_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_add_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_add_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_add_T<uint8>(arr1, arr2);
					case get_format_specifier<bool>() :
						return glmArray_add_T<bool>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
				bool b;
			};
			switch (arr1->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj2);
				return glmArray_addO_T<float>(arr1, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj2);
				return glmArray_addO_T<double>(arr1, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_addO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_addO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_addO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_addO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_addO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_addO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_addO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_addO_T<uint8>(arr1, &u8, 1, NULL);
			case get_format_specifier<bool>() :
				b = PyGLM_Number_FromPyObject<bool>(obj2);
				return glmArray_addO_T<bool>(arr1, &b, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<float>() :
					return glmArray_addO_T<float>(arr1, (float*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_addO_T<double>(arr1, (double*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_addO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_addO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_addO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_addO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_addO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_addO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_addO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_addO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<bool>() :
					return glmArray_addO_T<bool>(arr1, (bool*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	
		Py_RETURN_NOTIMPLEMENTED;
}
	else {
		return glmArray_add(obj2, obj1);
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '+': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_sub_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] - arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_subO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] - o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rsubO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = o[j % o_size] - arrDataPtr[i * arrRatio + (j % arrRatio)];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_sub(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_sub_T<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_sub_T<double>(arr1, arr2);
					case get_format_specifier<int64>() :
						return glmArray_sub_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_sub_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_sub_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_sub_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_sub_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_sub_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_sub_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_sub_T<uint8>(arr1, arr2);
					case get_format_specifier<bool>() :
						return glmArray_sub_T<bool>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
				bool b;
			};
			switch (arr1->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj2);
				return glmArray_subO_T<float>(arr1, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj2);
				return glmArray_subO_T<double>(arr1, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_subO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_subO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_subO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_subO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_subO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_subO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_subO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_subO_T<uint8>(arr1, &u8, 1, NULL);
			case get_format_specifier<bool>() :
				b = PyGLM_Number_FromPyObject<bool>(obj2);
				return glmArray_subO_T<bool>(arr1, &b, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<float>() :
					return glmArray_subO_T<float>(arr1, (float*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_subO_T<double>(arr1, (double*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_subO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_subO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_subO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_subO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_subO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_subO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_subO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_subO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<bool>() :
					return glmArray_subO_T<bool>(arr1, (bool*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	
		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (PyGLM_Number_Check(obj1)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
				bool b;
			};
			switch (arr2->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj1);
				return glmArray_rsubO_T<float>(arr2, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj1);
				return glmArray_rsubO_T<double>(arr2, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rsubO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rsubO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rsubO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rsubO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rsubO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rsubO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rsubO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rsubO_T<uint8>(arr2, &u8, 1, NULL);
			case get_format_specifier<bool>() :
				b = PyGLM_Number_FromPyObject<bool>(obj1);
				return glmArray_rsubO_T<bool>(arr2, &b, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<float>() :
					return glmArray_rsubO_T<float>(arr2, (float*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_rsubO_T<double>(arr2, (double*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_rsubO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rsubO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rsubO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rsubO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rsubO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rsubO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rsubO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rsubO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<bool>() :
					return glmArray_rsubO_T<bool>(arr2, (bool*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '-': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_mul_T_SEQ(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] * arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_mul_T_MMUL(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	Py_ssize_t n, arr1Stride, arr2Stride, trueShape1;

	if (arr1->glmType == PyGLM_TYPE_VEC) {
		n = arr1->shape[0];
		arr1Stride = 1;
		arr2Stride = arr2->shape[1];

		trueShape1 = 1;

		outArray->glmType = PyGLM_TYPE_VEC;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = 0;
		outArray->itemSize = outArray->shape[0] * outArray->dtSize;
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_VEC_TYPE_T_ONLY<T>(outArray->shape[0]);
	}
	else if (arr2->glmType == PyGLM_TYPE_VEC) {
		n = arr2->shape[0];
		arr1Stride = arr1->shape[1];
		arr2Stride = 0;

		trueShape1 = arr1->shape[1];

		outArray->glmType = PyGLM_TYPE_VEC;
		outArray->shape[0] = arr1->shape[1];
		outArray->shape[1] = 0;
		outArray->itemSize = outArray->shape[0] * outArray->dtSize;
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_VEC_TYPE_T_ONLY<T>(outArray->shape[0]);
	}
	else {
		n = arr1->shape[0];
		arr1Stride = arr1->shape[1];
		arr2Stride = arr2->shape[1];

		trueShape1 = arr1->shape[1];

		outArray->glmType = PyGLM_TYPE_MAT;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr1->shape[1];
		outArray->itemSize = outArray->dtSize * outArray->shape[0] * outArray->shape[1];
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_MAT_TYPE_T_ONLY<T>(outArray->shape[0], outArray->shape[1]);
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;
	Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T result = (T)0;
			for (Py_ssize_t k = 0; k < n; k++) {
				T a = arr1DataPtr[k * arr1Stride + j % trueShape1];
				T b = arr2DataPtr[k + (j / trueShape1) * arr2Stride];

				result += a * b;
			}
			outArrayDataPtr[outArrayIndex++] = result;
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_mulO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (pto == NULL || (arr->glmType == PyGLM_TYPE_VEC && ((pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC))) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];

		outArray->data = PyMem_Malloc(outArray->nBytes);
		if (outArray->data == NULL) {
			Py_DECREF(outArray);
			PyErr_SetString(PyExc_MemoryError, "Out of memory.");
			return NULL;
		}

		T* arrDataPtr = (T*)arr->data;

		T* outArrayDataPtr = (T*)outArray->data;

		Py_ssize_t outArrayIndex = 0;
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
			for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
				outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] * o[j % o_size];
			}
		}

		return (PyObject*)outArray;
	}

	if (arr->glmType == PyGLM_TYPE_CTYPES) {
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemSize * outArray->dtSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;

		outArray->data = PyMem_Malloc(outArray->nBytes);
		if (outArray->data == NULL) {
			Py_DECREF(outArray);
			PyErr_SetString(PyExc_MemoryError, "Out of memory.");
			return NULL;
		}

		T* arrDataPtr = (T*)arr->data;

		T* outArrayDataPtr = (T*)outArray->data;

		Py_ssize_t outArrayIndex = 0;
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
			for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
				outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] * o[j % o_size];
			}
		}

		return (PyObject*)outArray;
	}

	Py_ssize_t n, arrStride, oStride, trueShape1;

	if (arr->glmType == PyGLM_TYPE_VEC) {
		n = arr->shape[0];
		arrStride = 1;
		oStride = pto->R;

		trueShape1 = 1;

		outArray->glmType = PyGLM_TYPE_VEC;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = 0;
		outArray->itemSize = outArray->shape[0] * outArray->dtSize;
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_VEC_TYPE_T_ONLY<T>(outArray->shape[0]);
	}
	else if ((pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC) {
		n = pto->C;
		arrStride = arr->shape[1];
		oStride = 0;

		trueShape1 = arr->shape[1];

		outArray->glmType = PyGLM_TYPE_VEC;
		outArray->shape[0] = arr->shape[1];
		outArray->shape[1] = 0;
		outArray->itemSize = outArray->shape[0] * outArray->dtSize;
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_VEC_TYPE_T_ONLY<T>(outArray->shape[0]);
	}
	else {
		n = arr->shape[0];
		arrStride = arr->shape[1];
		oStride = pto->R;

		trueShape1 = arr->shape[1];

		outArray->glmType = PyGLM_TYPE_MAT;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = arr->shape[1];
		outArray->itemSize = outArray->dtSize * outArray->shape[0] * outArray->shape[1];
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_MAT_TYPE_T_ONLY<T>(outArray->shape[0], outArray->shape[1]);
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;
	Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T result = (T)0;
			for (Py_ssize_t k = 0; k < n; k++) {
				T a = arrDataPtr[k * arrStride + j % trueShape1];
				T b = o[k + (j / trueShape1) * oStride];

				result = result + a * b;
			}
			outArrayDataPtr[outArrayIndex++] = result;
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rmulO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	if (pto == NULL || arr->glmType == PyGLM_TYPE_CTYPES || (arr->glmType == PyGLM_TYPE_VEC && (pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC)) {
		return glmArray_mulO_T(arr, o, o_size, pto);
	}

	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	Py_ssize_t n, arrStride, oStride, trueShape1;

	if ((pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC) {
		n = pto->C;
		oStride = 1;
		arrStride = arr->shape[1];

		trueShape1 = 1;

		outArray->glmType = PyGLM_TYPE_VEC;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = 0;
		outArray->itemSize = outArray->shape[0] * outArray->dtSize;
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_VEC_TYPE_T_ONLY<T>(outArray->shape[0]);
	}
	else if (arr->glmType == PyGLM_TYPE_VEC) {
		n = arr->shape[0];
		oStride = pto->R;
		arrStride = 0;

		trueShape1 = pto->R;

		outArray->glmType = PyGLM_TYPE_VEC;
		outArray->shape[0] = pto->R;
		outArray->shape[1] = 0;
		outArray->itemSize = outArray->shape[0] * outArray->dtSize;
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_VEC_TYPE_T_ONLY<T>(outArray->shape[0]);
	}
	else {
		n = pto->C;
		arrStride = pto->R;
		oStride = arr->shape[1];

		trueShape1 = pto->R;

		outArray->glmType = PyGLM_TYPE_MAT;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = pto->R;
		outArray->itemSize = outArray->dtSize * outArray->shape[0] * outArray->shape[1];
		outArray->nBytes = outArray->itemSize * outArray->itemCount;
		outArray->subtype = PyGLM_MAT_TYPE_T_ONLY<T>(outArray->shape[0], outArray->shape[1]);
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;
	Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T result = (T)0;
			for (Py_ssize_t k = 0; k < n; k++) {
				T a = o[k * oStride + j % trueShape1];
				T b = arrDataPtr[k + (j / trueShape1) * arrStride];

				result = result + a * b;
			}
			outArrayDataPtr[outArrayIndex++] = result;
		}
	}

	return (PyObject*)outArray;
}

template<typename V, typename Q>
static void glmArray_mul_Q(V* vecs, Q* quas, V* out, Py_ssize_t len) {
	for (Py_ssize_t i = 0; i < len; i++) {
		out[i] = vecs[i] * quas[i];
	}
}

template<typename V, typename Q>
static void glmArray_rmul_Q(Q* quas, V* vecs, V* out, Py_ssize_t len) {
	for (Py_ssize_t i = 0; i < len; i++) {
		out[i] = quas[i] * vecs[i];
	}
}

template<typename V, typename Q>
static void glmArray_mul_Q(V vec, Q* quas, V* out, Py_ssize_t len) {
	for (Py_ssize_t i = 0; i < len; i++) {
		out[i] = vec * quas[i];
	}
}

template<typename V, typename Q>
static void glmArray_mul_Q(V* vecs, Q qua, V* out, Py_ssize_t len) {
	for (Py_ssize_t i = 0; i < len; i++) {
		out[i] = vecs[i] * qua;
	}
}

template<typename V, typename Q>
static void glmArray_rmul_Q(Q* quas, V vec, V* out, Py_ssize_t len) {
	for (Py_ssize_t i = 0; i < len; i++) {
		out[i] = quas[i] * vec;
	}
}

template<typename V, typename Q>
static void glmArray_rmul_Q(Q qua, V* vecs, V* out, Py_ssize_t len) {
	for (Py_ssize_t i = 0; i < len; i++) {
		out[i] = qua * vecs[i];
	}
}

static PyObject* glmArray_mul(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || (arr1->subtype == arr2->subtype && arr1->glmType == PyGLM_TYPE_VEC)) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_mul_T_SEQ<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_mul_T_SEQ<double>(arr1, arr2);
					case get_format_specifier<int64>() :
						return glmArray_mul_T_SEQ<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_mul_T_SEQ<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_mul_T_SEQ<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_mul_T_SEQ<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_mul_T_SEQ<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_mul_T_SEQ<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_mul_T_SEQ<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_mul_T_SEQ<uint8>(arr1, arr2);
					case get_format_specifier<bool>() :
						return glmArray_mul_T_SEQ<bool>(arr1, arr2);
				}
			}
			if ((arr1->glmType == PyGLM_TYPE_VEC && arr2->glmType == PyGLM_TYPE_MAT && arr1->shape[0] == arr2->shape[1])
				|| (arr1->glmType == PyGLM_TYPE_MAT && arr2->glmType == PyGLM_TYPE_VEC && arr1->shape[0] == arr2->shape[0])
				|| (arr1->glmType == PyGLM_TYPE_MAT && arr2->glmType == PyGLM_TYPE_MAT && arr1->shape[0] == arr2->shape[1])) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_mul_T_MMUL<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_mul_T_MMUL<double>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_mul_T_MMUL<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_mul_T_MMUL<uint32>(arr1, arr2);
				}
			}
			if (arr1->glmType == PyGLM_TYPE_QUA || arr2->glmType == PyGLM_TYPE_QUA) {
				glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
				outArray->dtSize = arr1->dtSize;
				outArray->format = arr1->format;
				outArray->itemCount = arr1->itemCount;
				outArray->readonly = false;
				outArray->reference = NULL;
				outArray->glmType = (arr1->glmType == PyGLM_TYPE_QUA && arr2->glmType == PyGLM_TYPE_QUA) ? PyGLM_TYPE_QUA : PyGLM_TYPE_VEC;

				if (arr1->glmType == PyGLM_TYPE_VEC) {
					if (arr1->shape[0] < 3) {
						PyErr_SetString(PyExc_ValueError, "Invalid operands.");
						Py_DECREF(outArray);
						return NULL;
					}

					outArray->itemSize = arr1->itemSize;
					outArray->nBytes = arr1->nBytes;
					outArray->shape[0] = arr1->shape[0];
					outArray->shape[1] = 0;
					outArray->subtype = arr1->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (arr1->shape[0] == 3) {
						if (arr1->format == 'f') {
							auto vp = (glm::vec<3, float>*)(arr1->data);
							auto qp = (glm::qua<float>*)(arr2->data);
							auto outp = (glm::vec<3, float>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr1->format == 'd') {
							auto vp = (glm::vec<3, double>*)(arr1->data);
							auto qp = (glm::qua<double>*)(arr2->data);
							auto outp = (glm::vec<3, double>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					else if (arr1->shape[0] == 4) {
						if (arr1->format == 'f') {
							auto vp = (glm::vec<4, float>*)(arr1->data);
							auto qp = (glm::qua<float>*)(arr2->data);
							auto outp = (glm::vec<4, float>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr1->format == 'd') {
							auto vp = (glm::vec<4, double>*)(arr1->data);
							auto qp = (glm::qua<double>*)(arr2->data);
							auto outp = (glm::vec<4, double>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					
				}
				else if (arr2->glmType == PyGLM_TYPE_VEC) {
					if (arr2->shape[0] < 3) {
						PyErr_SetString(PyExc_ValueError, "Invalid operands.");
						Py_DECREF(outArray);
						return NULL;
					}

					outArray->itemSize = arr2->itemSize;
					outArray->nBytes = arr2->nBytes;
					outArray->shape[0] = arr2->shape[0];
					outArray->shape[1] = 0;
					outArray->subtype = arr2->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (arr2->shape[0] == 3) {
						if (arr2->format == 'f') {
							auto vp = (glm::vec<3, float>*)(arr2->data);
							auto qp = (glm::qua<float>*)(arr1->data);
							auto outp = (glm::vec<3, float>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr2->format == 'd') {
							auto vp = (glm::vec<3, double>*)(arr2->data);
							auto qp = (glm::qua<double>*)(arr1->data);
							auto outp = (glm::vec<3, double>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					else if (arr2->shape[0] == 4) {
						if (arr2->format == 'f') {
							auto vp = (glm::vec<4, float>*)(arr2->data);
							auto qp = (glm::qua<float>*)(arr1->data);
							auto outp = (glm::vec<4, float>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr2->format == 'd') {
							auto vp = (glm::vec<4, double>*)(arr2->data);
							auto qp = (glm::qua<double>*)(arr1->data);
							auto outp = (glm::vec<4, double>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
				}
				else {
					outArray->itemSize = arr1->itemSize;
					outArray->nBytes = arr1->nBytes;
					outArray->shape[0] = 4;
					outArray->shape[1] = 0;
					outArray->subtype = arr1->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (arr1->format == 'f') {
						auto vp = (glm::qua<float>*)(arr1->data);
						auto qp = (glm::qua<float>*)(arr2->data);
						auto outp = (glm::qua<float>*)(outArray->data);
						glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
						return (PyObject*)outArray;
					}
					if (arr1->format == 'd') {
						auto vp = (glm::qua<double>*)(arr1->data);
						auto qp = (glm::qua<double>*)(arr2->data);
						auto outp = (glm::qua<double>*)(outArray->data);
						glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
						return (PyObject*)outArray;
					}
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
				bool b;
			};
			switch (arr1->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj2);
				return glmArray_mulO_T<float>(arr1, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj2);
				return glmArray_mulO_T<double>(arr1, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_mulO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_mulO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_mulO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_mulO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_mulO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_mulO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_mulO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_mulO_T<uint8>(arr1, &u8, 1, NULL);
			case get_format_specifier<bool>() :
				b = PyGLM_Number_FromPyObject<bool>(obj2);
				return glmArray_mulO_T<bool>(arr1, &b, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || (arr1->glmType == PyGLM_TYPE_VEC && ((pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC || (pto->glmType == PyGLM_TYPE_MAT && arr1->shape[0] == pto->R)))
				|| (arr1->glmType == PyGLM_TYPE_MAT && (pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC && arr1->shape[0] == pto->C)
				|| (arr1->glmType == PyGLM_TYPE_MAT && pto->glmType == PyGLM_TYPE_MAT && arr1->shape[0] == pto->R)) {
				switch (arr1->format) {
				case get_format_specifier<float>() :
					return glmArray_mulO_T<float>(arr1, (float*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_mulO_T<double>(arr1, (double*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_mulO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_mulO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_mulO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_mulO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_mulO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_mulO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_mulO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_mulO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<bool>() :
					return glmArray_mulO_T<bool>(arr1, (bool*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}

			if (arr1->glmType == PyGLM_TYPE_QUA || pto->glmType == PyGLM_TYPE_QUA) {
				glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
				outArray->dtSize = arr1->dtSize;
				outArray->format = arr1->format;
				outArray->itemCount = arr1->itemCount;
				outArray->readonly = false;
				outArray->reference = NULL;
				outArray->glmType = (arr1->glmType == PyGLM_TYPE_QUA && pto->glmType == PyGLM_TYPE_QUA) ? PyGLM_TYPE_QUA : PyGLM_TYPE_VEC;

				if (arr1->glmType == PyGLM_TYPE_VEC) {
					if (arr1->shape[0] < 3) {
						PyErr_SetString(PyExc_ValueError, "Invalid operands.");
						Py_DECREF(outArray);
						return NULL;
					}

					outArray->itemSize = arr1->itemSize;
					outArray->nBytes = arr1->nBytes;
					outArray->shape[0] = arr1->shape[0];
					outArray->shape[1] = 0;
					outArray->subtype = arr1->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (arr1->shape[0] == 3) {
						if (arr1->format == 'f') {
							auto vp = (glm::vec<3, float>*)(arr1->data);
							auto qp = ((qua<float>*)obj2)->super_type;
							auto outp = (glm::vec<3, float>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr1->format == 'd') {
							auto vp = (glm::vec<3, double>*)(arr1->data);
							auto qp = ((qua<double>*)obj2)->super_type;
							auto outp = (glm::vec<3, double>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					else if (arr1->shape[0] == 4) {
						if (arr1->format == 'f') {
							auto vp = (glm::vec<4, float>*)(arr1->data);
							auto qp = ((qua<float>*)obj2)->super_type;
							auto outp = (glm::vec<4, float>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr1->format == 'd') {
							auto vp = (glm::vec<4, double>*)(arr1->data);
							auto qp = ((qua<double>*)obj2)->super_type;
							auto outp = (glm::vec<4, double>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
				}
				else if (pto->glmType == PyGLM_TYPE_VEC) {
					if (pto->C < 3) {
						PyErr_SetString(PyExc_ValueError, "Invalid operands.");
						Py_DECREF(outArray);
						return NULL;
					}

					outArray->itemSize = pto->itemSize;
					outArray->nBytes = outArray->itemSize * outArray->itemCount;
					outArray->shape[0] = pto->C;
					outArray->shape[1] = 0;
					outArray->subtype = pto->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (pto->C == 3) {
						if (pto->format == 'f') {
							auto vp = ((vec<3, float>*)obj2)->super_type;
							auto qp = (glm::qua<float>*)(arr1->data);
							auto outp = (glm::vec<3, float>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (pto->format == 'd') {
							auto vp = ((vec<3, double>*)obj2)->super_type;
							auto qp = (glm::qua<double>*)(arr1->data);
							auto outp = (glm::vec<3, double>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					else if (pto->C == 4) {
						if (pto->format == 'f') {
							auto vp = ((vec<4, float>*)obj2)->super_type;
							auto qp = (glm::qua<float>*)(arr1->data);
							auto outp = (glm::vec<4, float>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (pto->format == 'd') {
							auto vp = ((vec<4, double>*)obj2)->super_type;
							auto qp = (glm::qua<double>*)(arr1->data);
							auto outp = (glm::vec<4, double>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
				}
				else {
					outArray->itemSize = arr1->itemSize;
					outArray->nBytes = arr1->nBytes;
					outArray->shape[0] = 4;
					outArray->shape[1] = 0;
					outArray->subtype = arr1->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (arr1->format == 'f') {
						auto vp = (glm::qua<float>*)(arr1->data);
						auto qp = ((qua<float>*)obj2)->super_type;
						auto outp = (glm::qua<float>*)(outArray->data);
						glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
						return (PyObject*)outArray;
					}
					if (arr1->format == 'd') {
						auto vp = (glm::qua<double>*)(arr1->data);
						auto qp = ((qua<double>*)obj2)->super_type;
						auto outp = (glm::qua<double>*)(outArray->data);
						glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
						return (PyObject*)outArray;
					}
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (PyGLM_Number_Check(obj1)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
				bool b;
			};
			switch (arr2->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj1);
				return glmArray_mulO_T<float>(arr2, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj1);
				return glmArray_mulO_T<double>(arr2, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_mulO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_mulO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_mulO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_mulO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_mulO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_mulO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_mulO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_mulO_T<uint8>(arr2, &u8, 1, NULL);
			case get_format_specifier<bool>() :
				b = PyGLM_Number_FromPyObject<bool>(obj1);
				return glmArray_mulO_T<bool>(arr2, &b, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || ((pto->glmType & PyGLM_TYPE_VEC) == PyGLM_TYPE_VEC && (arr2->glmType == PyGLM_TYPE_VEC || (arr2->glmType == PyGLM_TYPE_MAT && pto->C == arr2->shape[1])))
				|| (pto->glmType == PyGLM_TYPE_MAT && arr2->glmType == PyGLM_TYPE_VEC && pto->C == arr2->shape[0])
				|| (pto->glmType == PyGLM_TYPE_MAT && arr2->glmType == PyGLM_TYPE_MAT && pto->C == arr2->shape[1])) {
				switch (arr2->format) {
				case get_format_specifier<float>() :
					return glmArray_rmulO_T<float>(arr2, (float*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_rmulO_T<double>(arr2, (double*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_rmulO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rmulO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rmulO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rmulO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rmulO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rmulO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rmulO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rmulO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<bool>() :
					return glmArray_rmulO_T<bool>(arr2, (bool*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}

			if (pto->glmType == PyGLM_TYPE_QUA || arr2->glmType == PyGLM_TYPE_QUA) {
				glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
				outArray->dtSize = arr2->dtSize;
				outArray->format = arr2->format;
				outArray->itemCount = arr2->itemCount;
				outArray->readonly = false;
				outArray->reference = NULL;
				outArray->glmType = (pto->glmType == PyGLM_TYPE_QUA && arr2->glmType == PyGLM_TYPE_QUA) ? PyGLM_TYPE_QUA : PyGLM_TYPE_VEC;

				if (pto->glmType == PyGLM_TYPE_VEC) {
					if (pto->C < 3) {
						PyErr_SetString(PyExc_ValueError, "Invalid operands.");
						Py_DECREF(outArray);
						return NULL;
					}

					outArray->itemSize = pto->itemSize;
					outArray->nBytes = outArray->itemSize * outArray->itemCount;
					outArray->shape[0] = pto->C;
					outArray->shape[1] = 0;
					outArray->subtype = pto->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (pto->C == 3) {
						if (pto->format == 'f') {
							auto vp = ((vec<3, float>*)obj1)->super_type;
							auto qp = (glm::qua<float>*)(arr2->data);
							auto outp = (glm::vec<3, float>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (pto->format == 'd') {
							auto vp = ((vec<3, double>*)obj1)->super_type;
							auto qp = (glm::qua<double>*)(arr2->data);
							auto outp = (glm::vec<3, double>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					else if (pto->C == 4) {
						if (pto->format == 'f') {
							auto vp = ((vec<4, float>*)obj1)->super_type;
							auto qp = (glm::qua<float>*)(arr2->data);
							auto outp = (glm::vec<4, float>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (pto->format == 'd') {
							auto vp = ((vec<4, double>*)obj1)->super_type;
							auto qp = (glm::qua<double>*)(arr2->data);
							auto outp = (glm::vec<4, double>*)(outArray->data);
							glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
				}
				else if (arr2->glmType == PyGLM_TYPE_VEC) {
					if (arr2->shape[0] < 3) {
						PyErr_SetString(PyExc_ValueError, "Invalid operands.");
						Py_DECREF(outArray);
						return NULL;
					}

					outArray->itemSize = arr2->itemSize;
					outArray->nBytes = arr2->nBytes;
					outArray->shape[0] = arr2->shape[0];
					outArray->shape[1] = 0;
					outArray->subtype = arr2->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (arr2->shape[0] == 3) {
						if (arr2->format == 'f') {
							auto vp = (glm::vec<3, float>*)(arr2->data);
							auto qp = ((qua<float>*)obj1)->super_type;
							auto outp = (glm::vec<3, float>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr2->format == 'd') {
							auto vp = (glm::vec<3, double>*)(arr2->data);
							auto qp = ((qua<double>*)obj1)->super_type;
							auto outp = (glm::vec<3, double>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
					else if (arr2->shape[0] == 4) {
						if (arr2->format == 'f') {
							auto vp = (glm::vec<4, float>*)(arr2->data);
							auto qp = ((qua<float>*)obj1)->super_type;
							auto outp = (glm::vec<4, float>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
						if (arr2->format == 'd') {
							auto vp = (glm::vec<4, double>*)(arr2->data);
							auto qp = ((qua<double>*)obj1)->super_type;
							auto outp = (glm::vec<4, double>*)(outArray->data);
							glmArray_rmul_Q(qp, vp, outp, outArray->itemCount);
							return (PyObject*)outArray;
						}
					}
				}
				else {
					outArray->itemSize = arr2->itemSize;
					outArray->nBytes = arr2->nBytes;
					outArray->shape[0] = 4;
					outArray->shape[1] = 0;
					outArray->subtype = arr2->subtype;

					outArray->data = PyMem_Malloc(outArray->nBytes);

					if (outArray->data == NULL) {
						Py_DECREF(outArray);
						PyErr_SetString(PyExc_MemoryError, "out of memory.");
						return NULL;
					}

					if (pto->format == 'f') {
						auto vp = ((qua<float>*)obj1)->super_type;
						auto qp = (glm::qua<float>*)(arr2->data);
						auto outp = (glm::qua<float>*)(outArray->data);
						glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
						return (PyObject*)outArray;
					}
					if (pto->format == 'd') {
						auto vp = ((qua<double>*)obj1)->super_type;
						auto qp = (glm::qua<double>*)(arr2->data);
						auto outp = (glm::qua<double>*)(outArray->data);
						glmArray_mul_Q(vp, qp, outp, outArray->itemCount);
						return (PyObject*)outArray;
					}
				}
			}

			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '*': ", obj1, obj2);
	return NULL;
}

static float modT(float a, float b) {
	return glm::mod(a, b);
}

static double modT(double a, double b) {
	return glm::mod(a, b);
}

template<typename T>
static T modT(T a, T b) {
	return a % b;
}

template<typename T>
static PyObject* glmArray_mod_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T b = arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];

			if (b == (T)0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}

			outArrayDataPtr[outArrayIndex++] = modT(arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)], b);
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_modO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T b = o[j % o_size];

			if (b == (T)0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}

			outArrayDataPtr[outArrayIndex++] = modT(arrDataPtr[i * arrRatio + (j % arrRatio)], b);
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rmodO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T b = arrDataPtr[i * arrRatio + (j % arrRatio)];
			
			if (b == (T)0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}

			outArrayDataPtr[outArrayIndex++] = modT(o[j % o_size], b);
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_mod(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_mod_T<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_mod_T<double>(arr1, arr2);
					case get_format_specifier<int64>() :
						return glmArray_mod_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_mod_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_mod_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_mod_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_mod_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_mod_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_mod_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_mod_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj2);
				return glmArray_modO_T<float>(arr1, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj2);
				return glmArray_modO_T<double>(arr1, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_modO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_modO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_modO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_modO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_modO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_modO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_modO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_modO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<float>() :
					return glmArray_modO_T<float>(arr1, (float*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_modO_T<double>(arr1, (double*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_modO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_modO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_modO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_modO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_modO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_modO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_modO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_modO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj1);
				return glmArray_rmodO_T<float>(arr2, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj1);
				return glmArray_rmodO_T<double>(arr2, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rmodO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rmodO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rmodO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rmodO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rmodO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rmodO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rmodO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rmodO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<float>() :
					return glmArray_rmodO_T<float>(arr2, (float*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_rmodO_T<double>(arr2, (double*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_rmodO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rmodO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rmodO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rmodO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rmodO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rmodO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rmodO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rmodO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '%': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_pow_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			
			outArrayDataPtr[outArrayIndex++] = std::pow(arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)], arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)]);
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_powO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = std::pow(arrDataPtr[i * arrRatio + (j % arrRatio)], o[j % o_size]);
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rpowO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = std::pow(o[j % o_size], arrDataPtr[i * arrRatio + (j % arrRatio)]);
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_pow(PyObject* obj1, PyObject* obj2, PyObject* obj3) {
	PyGLM_ASSERT((obj3 == NULL || obj3 == Py_None), "Only binary pow is implemented.");

	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_pow_T<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_pow_T<double>(arr1, arr2);
				}
				PyErr_SetString(PyExc_ValueError, "Expected floating point values.");
				return NULL;
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				float f;
				double d;
			};
			switch (arr1->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj2);
				return glmArray_powO_T<float>(arr1, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj2);
				return glmArray_powO_T<double>(arr1, &d, 1, NULL);
			}
			PyErr_SetString(PyExc_ValueError, "Expected floating point values.");
			return NULL;
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<float>() :
					return glmArray_powO_T<float>(arr1, (float*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_powO_T<double>(arr1, (double*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
				PyErr_SetString(PyExc_ValueError, "Expected floating point values.");
				return NULL;
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				float f;
				double d;
			};
			switch (arr2->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj1);
				return glmArray_rpowO_T<float>(arr2, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj1);
				return glmArray_rpowO_T<double>(arr2, &d, 1, NULL);
			}
			PyErr_SetString(PyExc_ValueError, "Expected floating point values.");
			return NULL;
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<float>() :
					return glmArray_rpowO_T<float>(arr2, (float*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_rpowO_T<double>(arr2, (double*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
				PyErr_SetString(PyExc_ValueError, "Expected floating point values.");
				return NULL;
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '**': ", obj1, obj2);
	return NULL;
}

static inline bool negT(bool v) {
	return !v;
}

template<typename T>
static inline T negT(T v) {
	return -v;
}

template<typename T>
static PyObject* glmArray_neg_T(glmArray* arr) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;
	outArray->glmType = arr->glmType;
	outArray->itemSize = arr->itemSize;
	outArray->nBytes = arr->nBytes;
	outArray->subtype = arr->subtype;
	outArray->shape[0] = arr->shape[0];
	outArray->shape[1] = arr->shape[1];

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;

	for (Py_ssize_t i = 0; i < outArray->itemCount * outArrayRatio; i++) {
		outArrayDataPtr[i] = negT(arrDataPtr[i]);
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_neg(glmArray* arr) {
	switch (arr->format) {
	case get_format_specifier<float>() :
		return glmArray_neg_T<float>(arr);
	case get_format_specifier<double>() :
		return glmArray_neg_T<double>(arr);
	case get_format_specifier<int64>() :
		return glmArray_neg_T<int64>(arr);
	case get_format_specifier<int32>() :
		return glmArray_neg_T<int32>(arr);
	case get_format_specifier<int16>() :
		return glmArray_neg_T<int16>(arr);
	case get_format_specifier<int8>() :
		return glmArray_neg_T<int8>(arr);
	case get_format_specifier<bool>() :
		return glmArray_neg_T<bool>(arr);
	}
	PyGLM_TYPEERROR_O("Invalid operand type for '-': ", ((PyObject*)arr));
	return NULL;
}

static PyObject* glmArray_pos(glmArray* arr) {
	return PyGLM_INCREF((PyObject*)arr);
}

static inline float glmArray_abs_f(float v) {
	return fabs(v);
}

static inline double glmArray_abs_f(double v) {
	return fabs(v);
}

static inline int glmArray_abs_f(int v) {
	return abs(v);
}

static inline long glmArray_abs_f(long v) {
	return labs(v);
}

static inline long long glmArray_abs_f(long long v) {
	return llabs(v);
}

template<typename T>
static PyObject* glmArray_abs_T(glmArray* arr) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;
	outArray->glmType = arr->glmType;
	outArray->itemSize = arr->itemSize;
	outArray->nBytes = arr->nBytes;
	outArray->subtype = arr->subtype;
	outArray->shape[0] = arr->shape[0];
	outArray->shape[1] = arr->shape[1];

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;

	for (Py_ssize_t i = 0; i < outArray->itemCount * outArrayRatio; i++) {
		outArrayDataPtr[i] = glmArray_abs_f(arrDataPtr[i]);
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_abs(glmArray* arr) {
	switch (arr->format) {
	case get_format_specifier<float>() :
		return glmArray_abs_T<float>(arr);
	case get_format_specifier<double>() :
		return glmArray_abs_T<double>(arr);
	case get_format_specifier<int64>() :
		return glmArray_abs_T<int64>(arr);
	case get_format_specifier<int32>() :
		return glmArray_abs_T<int32>(arr);
	case get_format_specifier<int16>() :
		return glmArray_abs_T<int16>(arr);
	case get_format_specifier<int8>() :
		return glmArray_abs_T<int8>(arr);
	case get_format_specifier<uint8>() :
	case get_format_specifier<uint16>() :
	case get_format_specifier<uint32>() :
	case get_format_specifier<uint64>() :
	case get_format_specifier<bool>() :
		return PyGLM_INCREF((PyObject*)arr);
	}
	PyGLM_TYPEERROR_O("Invalid operand type for 'abs()': ", ((PyObject*)arr));
	return NULL;
}

template<typename T>
static PyObject* glmArray_inv_T(glmArray* arr) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;
	outArray->glmType = arr->glmType;
	outArray->itemSize = arr->itemSize;
	outArray->nBytes = arr->nBytes;
	outArray->subtype = arr->subtype;
	outArray->shape[0] = arr->shape[0];
	outArray->shape[1] = arr->shape[1];

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;

	for (Py_ssize_t i = 0; i < outArray->itemCount * outArrayRatio; i++) {
		outArrayDataPtr[i] = ~(arrDataPtr[i]);
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_inv(glmArray* arr) {
	switch (arr->format) {
	case get_format_specifier<int64>() :
		return glmArray_inv_T<int64>(arr);
	case get_format_specifier<uint64>() :
		return glmArray_inv_T<uint64>(arr);
	case get_format_specifier<int32>() :
		return glmArray_inv_T<int32>(arr);
	case get_format_specifier<uint32>() :
		return glmArray_inv_T<uint32>(arr);
	case get_format_specifier<int16>() :
		return glmArray_inv_T<int16>(arr);
	case get_format_specifier<uint16>() :
		return glmArray_inv_T<uint16>(arr);
	case get_format_specifier<int8>() :
		return glmArray_inv_T<int8>(arr);
	case get_format_specifier<uint8>() :
		return glmArray_inv_T<uint8>(arr);
	}
	PyGLM_TYPEERROR_O("Invalid operand type for '~': ", ((PyObject*)arr));
	return NULL;
}

template<typename T>
static PyObject* glmArray_lshift_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] << arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_lshiftO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] << o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rlshiftO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = o[j % o_size] << arrDataPtr[i * arrRatio + (j % arrRatio)];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_lshift(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<int64>() :
						return glmArray_lshift_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_lshift_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_lshift_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_lshift_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_lshift_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_lshift_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_lshift_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_lshift_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_lshiftO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_lshiftO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_lshiftO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_lshiftO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_lshiftO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_lshiftO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_lshiftO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_lshiftO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<int64>() :
					return glmArray_lshiftO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_lshiftO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_lshiftO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_lshiftO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_lshiftO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_lshiftO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_lshiftO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_lshiftO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rlshiftO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rlshiftO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rlshiftO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rlshiftO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rlshiftO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rlshiftO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rlshiftO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rlshiftO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<int64>() :
					return glmArray_rlshiftO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rlshiftO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rlshiftO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rlshiftO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rlshiftO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rlshiftO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rlshiftO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rlshiftO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '<<': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_rshift_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] >> arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rshiftO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] >> o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rrshiftO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = o[j % o_size] >> arrDataPtr[i * arrRatio + (j % arrRatio)];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_rshift(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<int64>() :
						return glmArray_rshift_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_rshift_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_rshift_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_rshift_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_rshift_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_rshift_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_rshift_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_rshift_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_rshiftO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_rshiftO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_rshiftO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_rshiftO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_rshiftO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_rshiftO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_rshiftO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_rshiftO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<int64>() :
					return glmArray_rshiftO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rshiftO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rshiftO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rshiftO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rshiftO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rshiftO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rshiftO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rshiftO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rrshiftO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rrshiftO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rrshiftO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rrshiftO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rrshiftO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rrshiftO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rrshiftO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rrshiftO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<int64>() :
					return glmArray_rrshiftO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rrshiftO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rrshiftO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rrshiftO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rrshiftO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rrshiftO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rrshiftO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rrshiftO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '>>': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_and_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] & arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_andO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] & o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_randO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = o[j % o_size] & arrDataPtr[i * arrRatio + (j % arrRatio)];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_and(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<int64>() :
						return glmArray_and_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_and_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_and_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_and_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_and_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_and_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_and_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_and_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_andO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_andO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_andO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_andO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_andO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_andO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_andO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_andO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<int64>() :
					return glmArray_andO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_andO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_andO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_andO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_andO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_andO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_andO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_andO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_randO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_randO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_randO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_randO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_randO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_randO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_randO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_randO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<int64>() :
					return glmArray_randO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_randO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_randO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_randO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_randO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_randO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_randO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_randO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '&': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_xor_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] ^ arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_xorO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] ^ o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rxorO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = o[j % o_size] ^ arrDataPtr[i * arrRatio + (j % arrRatio)];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_xor(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<int64>() :
						return glmArray_xor_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_xor_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_xor_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_xor_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_xor_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_xor_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_xor_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_xor_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_xorO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_xorO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_xorO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_xorO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_xorO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_xorO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_xorO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_xorO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<int64>() :
					return glmArray_xorO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_xorO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_xorO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_xorO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_xorO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_xorO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_xorO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_xorO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rxorO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rxorO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rxorO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rxorO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rxorO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rxorO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rxorO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rxorO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<int64>() :
					return glmArray_rxorO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rxorO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rxorO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rxorO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rxorO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rxorO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rxorO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rxorO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '^': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_or_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] | arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_orO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] | o[j % o_size];
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rorO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			outArrayDataPtr[outArrayIndex++] = o[j % o_size] | arrDataPtr[i * arrRatio + (j % arrRatio)];
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_or(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<int64>() :
						return glmArray_or_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_or_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_or_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_or_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_or_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_or_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_or_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_or_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_orO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_orO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_orO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_orO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_orO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_orO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_orO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_orO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<int64>() :
					return glmArray_orO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_orO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_orO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_orO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_orO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_orO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_orO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_orO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rorO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rorO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rorO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rorO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rorO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rorO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rorO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rorO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<int64>() :
					return glmArray_rorO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rorO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rorO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rorO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rorO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rorO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rorO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rorO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '|': ", obj1, obj2);
	return NULL;
}

template<typename T>
static PyObject* glmArray_div_T(glmArray* arr1, glmArray* arr2) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr1->dtSize;
	outArray->format = arr1->format;
	outArray->itemCount = arr1->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if (arr1->nBytes > arr2->nBytes || arr1->glmType == PyGLM_TYPE_VEC) {
		outArray->glmType = arr1->glmType;
		outArray->itemSize = arr1->itemSize;
		outArray->nBytes = arr1->nBytes;
		outArray->subtype = arr1->subtype;
		outArray->shape[0] = arr1->shape[0];
		outArray->shape[1] = arr1->shape[1];
	}
	else {
		outArray->glmType = arr2->glmType;
		outArray->itemSize = arr2->itemSize;
		outArray->nBytes = arr2->nBytes;
		outArray->subtype = arr2->subtype;
		outArray->shape[0] = arr2->shape[0];
		outArray->shape[1] = arr2->shape[1];
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arr1DataPtr = (T*)arr1->data;
	T* arr2DataPtr = (T*)arr2->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arr1Ratio = arr1->itemSize / outArray->dtSize;
		Py_ssize_t arr2Ratio = arr2->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T b = arr2DataPtr[i * arr2Ratio + (j % arr2Ratio)];

			if (b == (T)0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}

			outArrayDataPtr[outArrayIndex++] = arr1DataPtr[i * arr1Ratio + (j % arr1Ratio)] / b;
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_divO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T b = o[j % o_size];

			if (b == (T)0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}

			outArrayDataPtr[outArrayIndex++] = arrDataPtr[i * arrRatio + (j % arrRatio)] / b;
		}
	}

	return (PyObject*)outArray;
}

template<typename T>
static PyObject* glmArray_rdivO_T(glmArray* arr, T* o, Py_ssize_t o_size, PyGLMTypeObject* pto) {
	glmArray* outArray = (glmArray*)glmArray_new(&glmArrayType, NULL, NULL);
	outArray->dtSize = arr->dtSize;
	outArray->format = arr->format;
	outArray->itemCount = arr->itemCount;
	outArray->readonly = false;
	outArray->reference = NULL;

	if ((size_t)arr->itemSize / sizeof(T) > (size_t)o_size || arr->glmType == PyGLM_TYPE_VEC || pto == NULL) {
		outArray->glmType = arr->glmType;
		outArray->itemSize = arr->itemSize;
		outArray->nBytes = arr->nBytes;
		outArray->subtype = arr->subtype;
		outArray->shape[0] = arr->shape[0];
		outArray->shape[1] = arr->shape[1];
	}
	else {
		PyGLM_ASSERT(pto != ((PyGLMTypeObject *) NULL), "pto is NULL. This should never occur!");
		outArray->glmType = pto->glmType & PyGLM_TYPE_MVEC_FILTER;
		outArray->itemSize = pto->itemSize;
		outArray->nBytes = outArray->itemCount * outArray->itemSize;
		outArray->subtype = pto->subtype;
		outArray->shape[0] = pto->C;
		outArray->shape[1] = pto->R;
	}

	outArray->data = PyMem_Malloc(outArray->nBytes);
	if (outArray->data == NULL) {
		Py_DECREF(outArray);
		PyErr_SetString(PyExc_MemoryError, "Out of memory.");
		return NULL;
	}

	T* arrDataPtr = (T*)arr->data;

	T* outArrayDataPtr = (T*)outArray->data;

	Py_ssize_t outArrayIndex = 0;

	for (Py_ssize_t i = 0; i < outArray->itemCount; i++) {
		Py_ssize_t outArrayRatio = outArray->itemSize / outArray->dtSize;
		Py_ssize_t arrRatio = arr->itemSize / outArray->dtSize;

		for (Py_ssize_t j = 0; j < outArrayRatio; j++) {
			T b = arrDataPtr[i * arrRatio + (j % arrRatio)];
			
			if (b == (T)0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}

			outArrayDataPtr[outArrayIndex++] = o[j % o_size] / b;
		}
	}

	return (PyObject*)outArray;
}

static PyObject* glmArray_div(PyObject* obj1, PyObject* obj2) {
	if (PyObject_TypeCheck(obj1, &glmArrayType)) {
		// obj1 is an array

		glmArray* arr1 = (glmArray*)obj1;

		if (arr1->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyObject_TypeCheck(obj2, &glmArrayType)) {
			// obj2 is an array
			glmArray* arr2 = (glmArray*)obj2;

			if (arr1->itemCount != arr2->itemCount) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same amount of elements.");
				return NULL;
			}

			if (arr1->format != arr2->format) {
				PyErr_SetString(PyExc_ValueError, "The given arrays don't have the same data type.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || arr2->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == arr2->subtype) {
				switch (arr1->format) {
					case get_format_specifier<float>() :
						return glmArray_div_T<float>(arr1, arr2);
					case get_format_specifier<double>() :
						return glmArray_div_T<double>(arr1, arr2);
					case get_format_specifier<int64>() :
						return glmArray_div_T<int64>(arr1, arr2);
					case get_format_specifier<uint64>() :
						return glmArray_div_T<uint64>(arr1, arr2);
					case get_format_specifier<int32>() :
						return glmArray_div_T<int32>(arr1, arr2);
					case get_format_specifier<uint32>() :
						return glmArray_div_T<uint32>(arr1, arr2);
					case get_format_specifier<int16>() :
						return glmArray_div_T<int16>(arr1, arr2);
					case get_format_specifier<uint16>() :
						return glmArray_div_T<uint16>(arr1, arr2);
					case get_format_specifier<int8>() :
						return glmArray_div_T<int8>(arr1, arr2);
					case get_format_specifier<uint8>() :
						return glmArray_div_T<uint8>(arr1, arr2);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given arrays are not compatible.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj2)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr1->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj2);
				return glmArray_divO_T<float>(arr1, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj2);
				return glmArray_divO_T<double>(arr1, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj2);
				return glmArray_divO_T<int64>(arr1, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj2);
				return glmArray_divO_T<uint64>(arr1, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj2);
				return glmArray_divO_T<int32>(arr1, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj2);
				return glmArray_divO_T<uint32>(arr1, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj2);
				return glmArray_divO_T<int16>(arr1, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj2);
				return glmArray_divO_T<uint16>(arr1, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj2);
				return glmArray_divO_T<int8>(arr1, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj2);
				return glmArray_divO_T<uint8>(arr1, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj2))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj2));

			if (arr1->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr1->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr1->subtype == pto->subtype) {
				switch (arr1->format) {
				case get_format_specifier<float>() :
					return glmArray_divO_T<float>(arr1, (float*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_divO_T<double>(arr1, (double*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_divO_T<int64>(arr1, (int64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_divO_T<uint64>(arr1, (uint64*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_divO_T<int32>(arr1, (int32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_divO_T<uint32>(arr1, (uint32*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_divO_T<int16>(arr1, (int16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_divO_T<uint16>(arr1, (uint16*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_divO_T<int8>(arr1, (int8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_divO_T<uint8>(arr1, (uint8*)(pto->getDataOf(obj2)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}

		Py_RETURN_NOTIMPLEMENTED;
	}
	else {
		glmArray* arr2 = (glmArray*)obj2;

		if (arr2->glmType == PyGLM_TYPE_MAT) {
			PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
			return NULL;
		}

		if (PyGLM_Number_Check(obj1)) {
			union {
				float f;
				double d;
				int64 i64;
				uint64 u64;
				int32 i32;
				uint32 u32;
				int16 i16;
				uint16 u16;
				int8 i8;
				uint8 u8;
			};
			switch (arr2->format) {
			case get_format_specifier<float>() :
				f = PyGLM_Number_FromPyObject<float>(obj1);
				return glmArray_rdivO_T<float>(arr2, &f, 1, NULL);
			case get_format_specifier<double>() :
				d = PyGLM_Number_FromPyObject<double>(obj1);
				return glmArray_rdivO_T<double>(arr2, &d, 1, NULL);
			case get_format_specifier<int64>() :
				i64 = PyGLM_Number_FromPyObject<int64>(obj1);
				return glmArray_rdivO_T<int64>(arr2, &i64, 1, NULL);
			case get_format_specifier<uint64>() :
				u64 = PyGLM_Number_FromPyObject<uint64>(obj1);
				return glmArray_rdivO_T<uint64>(arr2, &u64, 1, NULL);
			case get_format_specifier<int32>() :
				i32 = PyGLM_Number_FromPyObject<int32>(obj1);
				return glmArray_rdivO_T<int32>(arr2, &i32, 1, NULL);
			case get_format_specifier<uint32>() :
				u32 = PyGLM_Number_FromPyObject<uint32>(obj1);
				return glmArray_rdivO_T<uint32>(arr2, &u32, 1, NULL);
			case get_format_specifier<int16>() :
				i16 = PyGLM_Number_FromPyObject<int16>(obj1);
				return glmArray_rdivO_T<int16>(arr2, &i16, 1, NULL);
			case get_format_specifier<uint16>() :
				u16 = PyGLM_Number_FromPyObject<uint16>(obj1);
				return glmArray_rdivO_T<uint16>(arr2, &u16, 1, NULL);
			case get_format_specifier<int8>() :
				i8 = PyGLM_Number_FromPyObject<int8>(obj1);
				return glmArray_rdivO_T<int8>(arr2, &i8, 1, NULL);
			case get_format_specifier<uint8>() :
				u8 = PyGLM_Number_FromPyObject<uint8>(obj1);
				return glmArray_rdivO_T<uint8>(arr2, &u8, 1, NULL);
			}
		}

		if (PyGLM_Is_PyGLM_Type(Py_TYPE(obj1))) {
			PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(obj1));

			if (arr2->format != pto->format) {
				PyErr_SetString(PyExc_ValueError, "The given array and object don't have the same data type.");
				return NULL;
			}

			if (pto->glmType == PyGLM_TYPE_MAT) {
				PyErr_SetString(PyExc_TypeError, "Matrices don't support this operation.");
				return NULL;
			}

			if (arr2->glmType == PyGLM_TYPE_CTYPES || pto->glmType == PyGLM_TYPE_CTYPES || arr2->subtype == pto->subtype) {
				switch (arr2->format) {
				case get_format_specifier<float>() :
					return glmArray_rdivO_T<float>(arr2, (float*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<double>() :
					return glmArray_rdivO_T<double>(arr2, (double*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int64>() :
					return glmArray_rdivO_T<int64>(arr2, (int64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint64>() :
					return glmArray_rdivO_T<uint64>(arr2, (uint64*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int32>() :
					return glmArray_rdivO_T<int32>(arr2, (int32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint32>() :
					return glmArray_rdivO_T<uint32>(arr2, (uint32*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int16>() :
					return glmArray_rdivO_T<int16>(arr2, (int16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint16>() :
					return glmArray_rdivO_T<uint16>(arr2, (uint16*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<int8>() :
					return glmArray_rdivO_T<int8>(arr2, (int8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				case get_format_specifier<uint8>() :
					return glmArray_rdivO_T<uint8>(arr2, (uint8*)(pto->getDataOf(obj1)), pto->itemSize / pto->dtSize, pto);
				}
			}
			PyErr_SetString(PyExc_ValueError, "The given array and object are not compatible.");
			return NULL;
		}
	}
	PyGLM_TYPEERROR_2O("Invalid operand type(s) for '/': ", obj1, obj2);
	return NULL;
}
