#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
sizeof_(PyObject*, PyObject* arg) {
	PyObject* argAsType = (PyType_Check(arg)) ? arg : (PyObject*)Py_TYPE(arg);

	destructor& arg_dealloc = ((PyTypeObject*)argAsType)->tp_dealloc;

	if (arg_dealloc == ctypes_dealloc) {
		if (argAsType == ctypes_float) {
			return PyLong_FromLong(sizeof(float));
		}
		if (argAsType == ctypes_double) {
			return PyLong_FromLong(sizeof(double));
		}
		if (argAsType == ctypes_int64) {
			return PyLong_FromLong(sizeof(int64));
		}
		if (argAsType == ctypes_int32) {
			return PyLong_FromLong(sizeof(int32));
		}
		if (argAsType == ctypes_int16) {
			return PyLong_FromLong(sizeof(int16));
		}
		if (argAsType == ctypes_int8) {
			return PyLong_FromLong(sizeof(int8));
		}
		if (argAsType == ctypes_uint64) {
			return PyLong_FromLong(sizeof(uint64));
		}
		if (argAsType == ctypes_uint32) {
			return PyLong_FromLong(sizeof(uint32));
		}
		if (argAsType == ctypes_uint16) {
			return PyLong_FromLong(sizeof(uint16));
		}
		if (argAsType == ctypes_uint8) {
			return PyLong_FromLong(sizeof(uint8));
		}
		if (argAsType == ctypes_bool) {
			return PyLong_FromLong(sizeof(bool));
		}
	}
	if (arg_dealloc == vec_dealloc) {
		if (argAsType == (PyObject*)&hfvec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, float>));
		}
		if (argAsType == (PyObject*)&hdvec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, double>));
		}
		if (argAsType == (PyObject*)&hivec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, int>));
		}
		if (argAsType == (PyObject*)&huvec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfvec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, float>));
		}
		if (argAsType == (PyObject*)&hdvec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, double>));
		}
		if (argAsType == (PyObject*)&hivec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, int>));
		}
		if (argAsType == (PyObject*)&huvec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfvec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, float>));
		}
		if (argAsType == (PyObject*)&hdvec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, double>));
		}
		if (argAsType == (PyObject*)&hivec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, int>));
		}
		if (argAsType == (PyObject*)&huvec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfvec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, float>));
		}
		if (argAsType == (PyObject*)&hdvec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, double>));
		}
		if (argAsType == (PyObject*)&hivec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, int>));
		}
		if (argAsType == (PyObject*)&huvec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::uint>));
		}
		if (argAsType == (PyObject*)&hi64vec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::i64>));
		}
		if (argAsType == (PyObject*)&hu64vec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::u64>));
		}
		if (argAsType == (PyObject*)&hi16vec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::i16>));
		}
		if (argAsType == (PyObject*)&hu16vec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::u16>));
		}
		if (argAsType == (PyObject*)&hi8vec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::i8>));
		}
		if (argAsType == (PyObject*)&hu8vec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, glm::u8>));
		}
		if (argAsType == (PyObject*)&hbvec1Type) {
			return PyLong_FromLong(sizeof(glm::vec<1, bool>));
		}
		if (argAsType == (PyObject*)&hi64vec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::i64>));
		}
		if (argAsType == (PyObject*)&hu64vec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::u64>));
		}
		if (argAsType == (PyObject*)&hi16vec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::i16>));
		}
		if (argAsType == (PyObject*)&hu16vec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::u16>));
		}
		if (argAsType == (PyObject*)&hi8vec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::i8>));
		}
		if (argAsType == (PyObject*)&hu8vec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, glm::u8>));
		}
		if (argAsType == (PyObject*)&hbvec2Type) {
			return PyLong_FromLong(sizeof(glm::vec<2, bool>));
		}
		if (argAsType == (PyObject*)&hi64vec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::i64>));
		}
		if (argAsType == (PyObject*)&hu64vec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::u64>));
		}
		if (argAsType == (PyObject*)&hi16vec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::i16>));
		}
		if (argAsType == (PyObject*)&hu16vec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::u16>));
		}
		if (argAsType == (PyObject*)&hi8vec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::i8>));
		}
		if (argAsType == (PyObject*)&hu8vec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, glm::u8>));
		}
		if (argAsType == (PyObject*)&hbvec3Type) {
			return PyLong_FromLong(sizeof(glm::vec<3, bool>));
		}
		if (argAsType == (PyObject*)&hi64vec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::i64>));
		}
		if (argAsType == (PyObject*)&hu64vec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::u64>));
		}
		if (argAsType == (PyObject*)&hi16vec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::i16>));
		}
		if (argAsType == (PyObject*)&hu16vec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::u16>));
		}
		if (argAsType == (PyObject*)&hi8vec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::i8>));
		}
		if (argAsType == (PyObject*)&hu8vec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, glm::u8>));
		}
		if (argAsType == (PyObject*)&hbvec4Type) {
			return PyLong_FromLong(sizeof(glm::vec<4, bool>));
		}
	}
	
	if (arg_dealloc == qua_dealloc) {
		if (argAsType == (PyObject*)&hfquaType) {
			return PyLong_FromLong(sizeof(glm::qua<float>));
		}
		if (argAsType == (PyObject*)&hdquaType) {
			return PyLong_FromLong(sizeof(glm::qua<double>));
		}
	}
	
	if (arg_dealloc == mat_dealloc) {
		if (argAsType == (PyObject*)&hfmat2x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 2, float>));
		}
		if (argAsType == (PyObject*)&hdmat2x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 2, double>));
		}
		if (argAsType == (PyObject*)&himat2x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 2, int>));
		}
		if (argAsType == (PyObject*)&humat2x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 2, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat3x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 3, float>));
		}
		if (argAsType == (PyObject*)&hdmat3x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 3, double>));
		}
		if (argAsType == (PyObject*)&himat3x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 3, int>));
		}
		if (argAsType == (PyObject*)&humat3x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 3, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat4x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 4, float>));
		}
		if (argAsType == (PyObject*)&hdmat4x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 4, double>));
		}
		if (argAsType == (PyObject*)&himat4x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 4, int>));
		}
		if (argAsType == (PyObject*)&humat4x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 4, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat2x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 3, float>));
		}
		if (argAsType == (PyObject*)&hdmat2x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 3, double>));
		}
		if (argAsType == (PyObject*)&himat2x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 3, int>));
		}
		if (argAsType == (PyObject*)&humat2x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 3, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat2x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 4, float>));
		}
		if (argAsType == (PyObject*)&hdmat2x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 4, double>));
		}
		if (argAsType == (PyObject*)&himat2x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 4, int>));
		}
		if (argAsType == (PyObject*)&humat2x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<2, 4, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat3x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 2, float>));
		}
		if (argAsType == (PyObject*)&hdmat3x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 2, double>));
		}
		if (argAsType == (PyObject*)&himat3x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 2, int>));
		}
		if (argAsType == (PyObject*)&humat3x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 2, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat3x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 4, float>));
		}
		if (argAsType == (PyObject*)&hdmat3x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 4, double>));
		}
		if (argAsType == (PyObject*)&himat3x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 4, int>));
		}
		if (argAsType == (PyObject*)&humat3x4Type) {
			return PyLong_FromLong(sizeof(glm::mat<3, 4, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat4x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 2, float>));
		}
		if (argAsType == (PyObject*)&hdmat4x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 2, double>));
		}
		if (argAsType == (PyObject*)&himat4x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 2, int>));
		}
		if (argAsType == (PyObject*)&humat4x2Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 2, glm::uint>));
		}
		if (argAsType == (PyObject*)&hfmat4x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 3, float>));
		}
		if (argAsType == (PyObject*)&hdmat4x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 3, double>));
		}
		if (argAsType == (PyObject*)&himat4x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 3, int>));
		}
		if (argAsType == (PyObject*)&humat4x3Type) {
			return PyLong_FromLong(sizeof(glm::mat<4, 3, glm::uint>));
		}
	}

	if (argAsType == (PyObject*)&glmArrayType) {
		if (PyType_Check(arg)) {
			PyErr_SetString(PyExc_ValueError, "The array class doesn't have a general size. Use an instance instead.");
			return NULL;
		}
		return PyLong_FromSsize_t(((glmArray*)arg)->nBytes);
	}

	PyGLM_TYPEERROR_O("sizeof() requires the argument to be a glm type, not ", arg);
	return NULL;
}

static PyObject*
value_ptr_(PyObject*, PyObject* arg) {
	if (PyGLM_Is_PyGLM_Type(Py_TYPE(arg))) {
		PyGLMTypeObject* pto = (PyGLMTypeObject*)(Py_TYPE(arg));

		char* data = pto->getDataOf(arg);

		switch (pto->format) {
		case get_format_specifier<float>() :
			return PyGLM_ToCtypesP((float*)data);
		case get_format_specifier<double>() :
			return PyGLM_ToCtypesP((double*)data);
		case get_format_specifier<int64>() :
			return PyGLM_ToCtypesP((int64*)data);
		case get_format_specifier<uint64>() :
			return PyGLM_ToCtypesP((uint64*)data);
		case get_format_specifier<int32>() :
			return PyGLM_ToCtypesP((int32*)data);
		case get_format_specifier<uint32>() :
			return PyGLM_ToCtypesP((uint32*)data);
		case get_format_specifier<int16>() :
			return PyGLM_ToCtypesP((int16*)data);
		case get_format_specifier<uint16>() :
			return PyGLM_ToCtypesP((uint16*)data);
		case get_format_specifier<int8>() :
			return PyGLM_ToCtypesP((int8*)data);
		case get_format_specifier<uint8>() :
			return PyGLM_ToCtypesP((uint8*)data);
		case get_format_specifier<bool>() :
			return PyGLM_ToCtypesP((bool*)data);
		}
	}

	PyGLM_TYPEERROR_O("value_ptr() requires the argument to be a glm type, not ", arg);
	return NULL;
}

static PyObject*
make_vec2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_vec2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_vec2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_vec2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_vec2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int64_p)) {
		return pack(glm::make_vec2((glm::i64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint64_p)) {
		return pack(glm::make_vec2((glm::u64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int16_p)) {
		return pack(glm::make_vec2((glm::i16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint16_p)) {
		return pack(glm::make_vec2((glm::u16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int8_p)) {
		return pack(glm::make_vec2((glm::i8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint8_p)) {
		return pack(glm::make_vec2((glm::u8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_bool_p)) {
		return pack(glm::make_vec2((bool*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_vec2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_vec3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_vec3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_vec3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_vec3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_vec3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int64_p)) {
		return pack(glm::make_vec3((glm::i64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint64_p)) {
		return pack(glm::make_vec3((glm::u64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int16_p)) {
		return pack(glm::make_vec3((glm::i16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint16_p)) {
		return pack(glm::make_vec3((glm::u16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int8_p)) {
		return pack(glm::make_vec3((glm::i8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint8_p)) {
		return pack(glm::make_vec3((glm::u8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_bool_p)) {
		return pack(glm::make_vec3((bool*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_vec3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_vec4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_vec4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_vec4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_vec4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_vec4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int64_p)) {
		return pack(glm::make_vec4((glm::i64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint64_p)) {
		return pack(glm::make_vec4((glm::u64*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int16_p)) {
		return pack(glm::make_vec4((glm::i16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint16_p)) {
		return pack(glm::make_vec4((glm::u16*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int8_p)) {
		return pack(glm::make_vec4((glm::i8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint8_p)) {
		return pack(glm::make_vec4((glm::u8*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_bool_p)) {
		return pack(glm::make_vec4((bool*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_vec4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_mat2x2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat2x2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat2x2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat2x2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat2x2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat2x2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat2x3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat2x3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat2x3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat2x3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat2x3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat2x3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat2x4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat2x4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat2x4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat2x4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat2x4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat2x4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat3x2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat3x2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat3x2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat3x2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat3x2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat3x2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat3x3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat3x3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat3x3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat3x3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat3x3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat3x3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat3x4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat3x4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat3x4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat3x4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat3x4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat3x4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat4x2_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat4x2((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat4x2((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat4x2((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat4x2((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat4x2() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat4x3_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat4x3((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat4x3((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat4x3((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat4x3((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat4x3() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}
static PyObject*
make_mat4x4_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_mat4x4((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_mat4x4((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_int32_p)) {
		return pack(glm::make_mat4x4((int*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_uint32_p)) {
		return pack(glm::make_mat4x4((glm::uint*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_mat4x4() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

static PyObject*
make_quat_(PyObject*, PyObject* arg) {
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_float_p)) {
		return pack(glm::make_quat((float*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	if (PyObject_TypeCheck(arg, (PyTypeObject*)ctypes_double_p)) {
		return pack(glm::make_quat((double*)PyGLM_UnsignedLongLong_FromCtypesP(arg)));
	}
	PyGLM_TYPEERROR_O("make_quat() requires a ctypes pointer as it's argument, not ", arg);
	return NULL;
}

PyDoc_STRVAR(value_ptr_docstr,
	"value_ptr(x) -> ctypes pointer\n"
	"	Return the constant address to the data of the input parameter."
);
PyDoc_STRVAR(sizeof_docstr,
	"sizeof(x: type) -> int\n"
	"	Return the data size of `x` in bytes.\n"
	"	E.g. `sizeof(vec4) == sizeof(float32) * 4 = 4 * 4 = 16`."
);
PyDoc_STRVAR(make_vec2_docstr,
	"make_vec2(x: ctypes pointer) -> vec2\n"
	"	Build a vector from a pointer."
);
PyDoc_STRVAR(make_vec3_docstr,
	"make_vec3(x: ctypes pointer) -> vec3\n"
	"	Build a vector from a pointer."
);
PyDoc_STRVAR(make_vec4_docstr,
	"make_vec4(x: ctypes pointer) -> vec4\n"
	"	Build a vector from a pointer."
);
PyDoc_STRVAR(make_mat2_docstr,
	"make_mat2(x: ctypes pointer) -> mat2\n"
	"	See make_mat2x2()."
);
PyDoc_STRVAR(make_mat3_docstr,
	"make_mat3(x: ctypes pointer) -> mat3\n"
	"	See make_mat3x3()."
);
PyDoc_STRVAR(make_mat4_docstr,
	"make_mat4(x: ctypes pointer) -> mat4\n"
	"	See make_mat4x4()."
);
PyDoc_STRVAR(make_mat2x2_docstr,
	"make_mat2x2(x: ctypes pointer) -> mat2\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat2x3_docstr,
	"make_mat2x3(x: ctypes pointer) -> mat2x3\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat2x4_docstr,
	"make_mat2x4(x: ctypes pointer) -> mat2x4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat3x2_docstr,
	"make_mat3x2(x: ctypes pointer) -> mat3x2\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat3x3_docstr,
	"make_mat3x3(x: ctypes pointer) -> mat3\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat3x4_docstr,
	"make_mat3x4(x: ctypes pointer) -> mat3x4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat4x2_docstr,
	"make_mat4x2(x: ctypes pointer) -> mat4x2\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat4x3_docstr,
	"make_mat4x3(x: ctypes pointer) -> mat4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_mat4x4_docstr,
	"make_mat4x4(x: ctypes pointer) -> mat4x4\n"
	"	Build a matrix from a pointer."
);
PyDoc_STRVAR(make_quat_docstr,
	"make_quat(x: ctypes pointer) -> quat\n"
	"	Build a quaternion from a pointer."
);

#define TYPE_PTR_METHODS \
{ "value_ptr", (PyCFunction)value_ptr_, METH_O, value_ptr_docstr }, \
{ "sizeof", (PyCFunction)sizeof_, METH_O, sizeof_docstr }, \
{ "make_vec2", (PyCFunction)make_vec2_, METH_O, make_vec2_docstr }, \
{ "make_vec3", (PyCFunction)make_vec3_, METH_O, make_vec3_docstr }, \
{ "make_vec4", (PyCFunction)make_vec4_, METH_O, make_vec4_docstr }, \
{ "make_mat2", (PyCFunction)make_mat2x2_, METH_O, make_mat2_docstr }, \
{ "make_mat2x2", (PyCFunction)make_mat2x2_, METH_O, make_mat2x2_docstr }, \
{ "make_mat2x3", (PyCFunction)make_mat2x3_, METH_O, make_mat2x3_docstr }, \
{ "make_mat2x4", (PyCFunction)make_mat2x4_, METH_O, make_mat2x4_docstr }, \
{ "make_mat3x2", (PyCFunction)make_mat3x2_, METH_O, make_mat3x2_docstr }, \
{ "make_mat3", (PyCFunction)make_mat3x3_, METH_O, make_mat3_docstr }, \
{ "make_mat3x3", (PyCFunction)make_mat3x3_, METH_O, make_mat3x3_docstr }, \
{ "make_mat3x4", (PyCFunction)make_mat3x4_, METH_O, make_mat3x4_docstr }, \
{ "make_mat4x2", (PyCFunction)make_mat4x2_, METH_O, make_mat4x2_docstr }, \
{ "make_mat4x3", (PyCFunction)make_mat4x3_, METH_O, make_mat4x3_docstr }, \
{ "make_mat4", (PyCFunction)make_mat4x4_, METH_O, make_mat4_docstr }, \
{ "make_mat4x4", (PyCFunction)make_mat4x4_, METH_O, make_mat4x4_docstr }, \
{ "make_quat", (PyCFunction)make_quat_, METH_O, make_quat_docstr }
