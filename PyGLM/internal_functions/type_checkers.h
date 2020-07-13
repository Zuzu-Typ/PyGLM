#pragma once

#include <climits>
//#include <functional>
#include <initializer_list>

#include "../compiler_setup.h"

#include "../types/all.h"

#include "helper_macros.h"
#include "number_functions.h"

#define PyGLM_SHAPE_GET(C, R) (1 << (11 + (3 * (C-2) + (R-2))))

#define PyGLM_TYPE_GET(T) (PyGLMTypeInfo::getDT<T>())

#define PyGLM_PTI_Compare(a, b) (((a) & (b)) == (b))

#define PyGLM_PTI_Number_Check(pti) (pti.info & PyGLM_T_NUMBER)

#define PyGLM_PTI_Number_T_Check(T, pti) (pti.info & (PyGLM_T_NUMBER | PyGLM_TYPE_GET(T)))

#define PyGLM_PTI_Mat_CRT_Check(C, R, T, pti) (pti.info & (PyGLM_SHAPE_GET(C, R) | PyGLM_TYPE_GET(T) | PyGLM_T_MAT))

#define _SUB_PyGLM_PTI_GET_TYPE(o) ((o->ob_type->tp_dealloc == (destructor)vec_dealloc) ? PyGLM_T_VEC : (o->ob_type->tp_dealloc == (destructor)mat_dealloc) ? PyGLM_T_MAT : (o->ob_type->tp_dealloc == (destructor)qua_dealloc) ? PyGLM_T_QUA : (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) ? PyGLM_T_MVEC : PyGLM_UNKNOWN)
#define PyGLM_PTI_GET_TYPE(o) _SUB_PyGLM_PTI_GET_TYPE(((PyObject*)o))

// necessary forward declarations
template<int L, typename T>
static glm::vec<L, T> unpack_vec(PyObject* value);

template<int C, int R, typename T>
static glm::mat<C, R, T> unpack_mat(PyObject* value);

template<typename T>
static glm::qua<T> unpack_qua(PyObject* value);

struct PyGLMSingleTypeHolder { // supposed to only hold a single data type
	enum class DType { NONE, BOOL, INT32, INT64, UINT64, FLOAT, DOUBLE };

	DType dtype;

	void* data = NULL;

	bool needsToBeFreed = false;


	~PyGLMSingleTypeHolder() {
		if (needsToBeFreed) {
			PyMem_Free(data);
			needsToBeFreed = false;
		}
	}

	PyGLMSingleTypeHolder() {
		dtype = DType::NONE;
	}

	PyGLMSingleTypeHolder(PyObject* o) {
		if (PyBool_Check(o)) {
			dtype = DType::BOOL;
			allocate(sizeof(bool));
			*((bool*)data) = (o == Py_True) ? true : false;
		}
		else if (PyFloat_Check(o)) {
			double value = PyFloat_AS_DOUBLE(o);
			if (value > FLT_MAX || (value != 0.0 && value < FLT_MIN && value > - FLT_MIN) || value < - FLT_MAX) { // value doesn't fit in float
				dtype = DType::DOUBLE;
				allocate(sizeof(double));
				*((double*)data) = value;
			}
			else {
				dtype = DType::FLOAT;
				allocate(sizeof(float));
				*((float*)data) = static_cast<float>(value);
			}
		}
		else if (PyLong_Check(o)) {
			int overflow;
			long asLong = PyLong_AsLongAndOverflow(o, &overflow);
			if (overflow != 0) {
				long long asLongLong = PyLong_AsLongLongAndOverflow(o, &overflow);
				if (overflow != 0) {
					unsigned long long asUnsignedLongLong = PyLong_AsUnsignedLongLongMask(o);
					dtype = DType::UINT64;
					allocate(sizeof(unsigned long long));
					*((unsigned long long*)data) = asUnsignedLongLong;
				}
				else {
					dtype = DType::INT64;
					allocate(sizeof(long long));
					*((long long*)data) = asLongLong;
				}
			}
			else {
				dtype = DType::INT32;
				allocate(sizeof(long));
				*((long*)data) = asLong;
			}
		}
		else {
			dtype = DType::NONE;
		}
	}

	static int getMostImportantType(int accepted_types, std::initializer_list<DType> list) {
		DType highest_type = DType::NONE;

		for (DType dt : list) {
			if (highest_type < dt) {
				highest_type = dt;
			}
		}

		if (highest_type == DType::BOOL && (accepted_types & PyGLM_DT_BOOL)) {
			return PyGLM_DT_BOOL;
		}

		if (highest_type == DType::DOUBLE && (accepted_types & PyGLM_DT_DOUBLE)) {
			return PyGLM_DT_DOUBLE;
		}

		if (accepted_types & PyGLM_DT_FLOAT)
			return PyGLM_DT_FLOAT;

		if (accepted_types & PyGLM_DT_DOUBLE)
			return PyGLM_DT_DOUBLE;

		if (highest_type == DType::INT32 && (accepted_types & PyGLM_DT_INT))
			return PyGLM_DT_INT;

		if (highest_type == DType::INT64 && (accepted_types & PyGLM_DT_INT64))
			return PyGLM_DT_INT64;

		if (highest_type == DType::UINT64 && (accepted_types & PyGLM_DT_UINT64))
			return PyGLM_DT_UINT64;

		if (accepted_types & PyGLM_DT_INT)
			return PyGLM_DT_INT;

		if (accepted_types & PyGLM_DT_INT64)
			return PyGLM_DT_INT64;

		if (accepted_types & PyGLM_DT_UINT64)
			return PyGLM_DT_UINT64;

		if (accepted_types & PyGLM_DT_UINT)
			return PyGLM_DT_UINT;

		if (accepted_types & PyGLM_DT_INT16)
			return PyGLM_DT_INT16;

		if (accepted_types & PyGLM_DT_UINT16)
			return PyGLM_DT_UINT16;

		if (accepted_types & PyGLM_DT_INT8)
			return PyGLM_DT_INT8;

		if (accepted_types & PyGLM_DT_UINT8)
			return PyGLM_DT_UINT8;

		if (accepted_types & PyGLM_DT_BOOL)
			return PyGLM_DT_BOOL;

		return 0;
	}

	double asDouble() {
		switch (dtype) {
		case DType::DOUBLE:
			return *(double*)data;
		case DType::FLOAT:
			return static_cast<double>(*(float*)data);
		case DType::INT32:
			return static_cast<double>(*(long*)data);
		case DType::INT64:
			return static_cast<double>(*(long long*)data);
		case DType::UINT64:
			return static_cast<double>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<double>(*(bool*)data);
		default:
			return 0.0;
		}
	}

	float asFloat() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<float>(*(double*)data);
		case DType::FLOAT:
			return (*(float*)data);
		case DType::INT32:
			return static_cast<float>(*(long*)data);
		case DType::INT64:
			return static_cast<float>(*(long long*)data);
		case DType::UINT64:
			return static_cast<float>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<float>(*(bool*)data);
		default:
			return 0.0f;
		}
	}

	glm::i64 asInt64() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::i64>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::i64>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::i64>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::i64>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::i64>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::i64>(*(bool*)data);
		default:
			return 0ll;
		}
	}

	glm::u64 asUint64() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::u64>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::u64>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::u64>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::u64>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::u64>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::u64>(*(bool*)data);
		default:
			return 0ull;
		}
	}

	glm::i32 asInt32() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::i32>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::i32>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::i32>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::i32>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::i32>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::i32>(*(bool*)data);
		default:
			return 0;
		}
	}

	glm::u32 asUint32() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::u32>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::u32>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::u32>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::u32>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::u32>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::u32>(*(bool*)data);
		default:
			return 0u;
		}
	}

	glm::i16 asInt16() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::i16>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::i16>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::i16>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::i16>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::i16>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::i16>(*(bool*)data);
		default:
			return 0;
		}
	}

	glm::u16 asUint16() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::u16>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::u16>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::u16>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::u16>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::u16>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::u16>(*(bool*)data);
		default:
			return 0u;
		}
	}

	glm::i8 asInt8() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::i8>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::i8>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::i8>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::i8>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::i8>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::i8>(*(bool*)data);
		default:
			return 0;
		}
	}

	glm::u8 asUint8() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<glm::u8>(*(double*)data);
		case DType::FLOAT:
			return static_cast<glm::u8>(*(float*)data);
		case DType::INT32:
			return static_cast<glm::u8>(*(long*)data);
		case DType::INT64:
			return static_cast<glm::u8>(*(long long*)data);
		case DType::UINT64:
			return static_cast<glm::u8>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<glm::u8>(*(bool*)data);
		default:
			return 0u;
		}
	}

	bool asBool() {
		switch (dtype) {
		case DType::DOUBLE:
			return static_cast<bool>(*(double*)data);
		case DType::FLOAT:
			return static_cast<bool>(*(float*)data);
		case DType::INT32:
			return static_cast<bool>(*(long*)data);
		case DType::INT64:
			return static_cast<bool>(*(long long*)data);
		case DType::UINT64:
			return static_cast<bool>(*(unsigned long long*)data);
		case DType::BOOL:
			return static_cast<bool>(*(bool*)data);
		default:
			return false;
		}
	}

private:
	void allocate(size_t size) {
		data = PyMem_Malloc(size);
		needsToBeFreed = true;
	}
};

struct PyGLMTypeInfo {
	int info	= 0;
	uint8 dataArray[128]; // maximum of 4 * 4 * 8 = 128 bytes of data

	void* data = &dataArray;

	bool isVec = false;
	bool isMat = false;
	bool isQua = false;

	PyGLMTypeInfo() = default;

	PyGLMTypeInfo(int accepted_types, PyObject* obj) {
		init(accepted_types, obj);
	}

	void init(int accepted_types, PyObject* obj) {
		isVec = false;
		isMat = false;
		isQua = false;
		info = 0;

#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
		if (PyObject_CheckBuffer(obj)) {
			Py_buffer view;
			if (PyObject_GetBuffer(obj, &view, PyBUF_RECORDS_RO | PyBUF_C_CONTIGUOUS) == -1) {
				PyBuffer_Release(&view);
				PyErr_Clear();
				return;
			}
			switch (view.ndim) {
			case 1: // one dimensional array (vec / qua)
				if (view.shape == NULL) {
					PyBuffer_Release(&view);
					return;
				}
				switch (view.shape[0]) {
				case 1: // vec1's
					if (!((accepted_types & PyGLM_T_ANY_VEC) && (accepted_types & PyGLM_SHAPE_1)) || view.format == NULL) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.format[0]) {
					case 'f':
						if (!(accepted_types & PyGLM_DT_FLOAT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FLOAT);
						break;
					case 'd':
						if (!(accepted_types & PyGLM_DT_DOUBLE)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_DOUBLE);
						break;
					case 'b':
						if (!(accepted_types & PyGLM_DT_INT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_INT8);
						break;
					case 'B':
						if (!(accepted_types & PyGLM_DT_UINT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_UINT8);
						break;
					case 'h':
						if (!(accepted_types & PyGLM_DT_INT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_INT16);
						break;
					case 'H':
						if (!(accepted_types & PyGLM_DT_UINT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_UINT16);
						break;
					case 'l':
					case 'i':
						if (!(accepted_types & PyGLM_DT_INT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_INT);
						break;
					case 'L':
					case 'I':
						if (!(accepted_types & PyGLM_DT_UINT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_UINT);
						break;
					case 'q':
						if (!(accepted_types & PyGLM_DT_INT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_INT64);
						break;
					case 'Q':
						if (!(accepted_types & PyGLM_DT_UINT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_UINT64);
						break;
					case '?':
						if (!(accepted_types & PyGLM_DT_BOOL)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_BOOL);
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				case 2: // vec2's
					if (!((accepted_types & PyGLM_T_ANY_VEC) && (accepted_types & PyGLM_SHAPE_2)) || view.format == NULL) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.format[0]) {
					case 'f':
						if (!(accepted_types & PyGLM_DT_FLOAT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
						break;
					case 'd':
						if (!(accepted_types & PyGLM_DT_DOUBLE)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_DOUBLE);
						break;
					case 'b':
						if (!(accepted_types & PyGLM_DT_INT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT8);
						break;
					case 'B':
						if (!(accepted_types & PyGLM_DT_UINT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT8);
						break;
					case 'h':
						if (!(accepted_types & PyGLM_DT_INT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT16);
						break;
					case 'H':
						if (!(accepted_types & PyGLM_DT_UINT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT16);
						break;
					case 'l':
					case 'i':
						if (!(accepted_types & PyGLM_DT_INT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT);
						break;
					case 'L':
					case 'I':
						if (!(accepted_types & PyGLM_DT_UINT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT);
						break;
					case 'q':
						if (!(accepted_types & PyGLM_DT_INT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_INT64);
						break;
					case 'Q':
						if (!(accepted_types & PyGLM_DT_UINT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_UINT64);
						break;
					case '?':
						if (!(accepted_types & PyGLM_DT_BOOL)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_BOOL);
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				case 3: // vec3's
					if (!((accepted_types & PyGLM_T_ANY_VEC) && (accepted_types & PyGLM_SHAPE_3)) || view.format == NULL) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.format[0]) {
					case 'f':
						if (!(accepted_types & PyGLM_DT_FLOAT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
						break;
					case 'd':
						if (!(accepted_types & PyGLM_DT_DOUBLE)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_DOUBLE);
						break;
					case 'b':
						if (!(accepted_types & PyGLM_DT_INT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_INT8);
						break;
					case 'B':
						if (!(accepted_types & PyGLM_DT_UINT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_UINT8);
						break;
					case 'h':
						if (!(accepted_types & PyGLM_DT_INT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_INT16);
						break;
					case 'H':
						if (!(accepted_types & PyGLM_DT_UINT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_UINT16);
						break;
					case 'l':
					case 'i':
						if (!(accepted_types & PyGLM_DT_INT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_INT);
						break;
					case 'L':
					case 'I':
						if (!(accepted_types & PyGLM_DT_UINT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_UINT);
						break;
					case 'q':
						if (!(accepted_types & PyGLM_DT_INT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_INT64);
						break;
					case 'Q':
						if (!(accepted_types & PyGLM_DT_UINT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_UINT64);
						break;
					case '?':
						if (!(accepted_types & PyGLM_DT_BOOL)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_BOOL);
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				case 4: // vec4's and qua's
					if (!(((accepted_types & PyGLM_T_ANY_VEC) && (accepted_types & PyGLM_SHAPE_4)) || (accepted_types & PyGLM_T_QUA)) || view.format == NULL) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.format[0]) {
					case 'f':
						if (!(accepted_types & PyGLM_DT_FLOAT)) {
							PyBuffer_Release(&view);
							return;
						}
						if (((accepted_types & PyGLM_T_ANY_VEC) && (accepted_types & PyGLM_SHAPE_4)))
							setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
						else
							setInfo(PyGLM_T_QUA | PyGLM_DT_FLOAT);
						break;
					case 'd':
						if (!(accepted_types & PyGLM_DT_DOUBLE)) {
							PyBuffer_Release(&view);
							return;
						}
						if (((accepted_types & PyGLM_T_ANY_VEC) && (accepted_types & PyGLM_SHAPE_4)))
							setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_DOUBLE);
						else
							setInfo(PyGLM_T_QUA | PyGLM_DT_DOUBLE);
						break;
					case 'b':
						if (!(accepted_types & PyGLM_DT_INT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT8);
						break;
					case 'B':
						if (!(accepted_types & PyGLM_DT_UINT8)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT8);
						break;
					case 'h':
						if (!(accepted_types & PyGLM_DT_INT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT16);
						break;
					case 'H':
						if (!(accepted_types & PyGLM_DT_UINT16)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT16);
						break;
					case 'l':
					case 'i':
						if (!(accepted_types & PyGLM_DT_INT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT);
						break;
					case 'L':
					case 'I':
						if (!(accepted_types & PyGLM_DT_UINT)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT);
						break;
					case 'q':
						if (!(accepted_types & PyGLM_DT_INT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_INT64);
						break;
					case 'Q':
						if (!(accepted_types & PyGLM_DT_UINT64)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_UINT64);
						break;
					case '?':
						if (!(accepted_types & PyGLM_DT_BOOL)) {
							PyBuffer_Release(&view);
							return;
						}
						setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_BOOL);
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				default:
					PyBuffer_Release(&view);
					return;
				}
				break;
			case 2: // two dimensional array (mat)
				if (view.shape == NULL || !(accepted_types & PyGLM_T_MAT)) {
					PyBuffer_Release(&view);
					return;
				}
				switch (view.shape[0]) {
				case 2: // mat2xM's
					if (!(accepted_types & PyGLM_SHAPE_2xM)) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.shape[1]) {
					case 2: // mat2x2's
						if (!(accepted_types & PyGLM_SHAPE_2x2)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					case 3: // mat2x3's
						if (!(accepted_types & PyGLM_SHAPE_2x3)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x3 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x3 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x3 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x3 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					case 4: // mat2x4's
						if (!(accepted_types & PyGLM_SHAPE_2x4)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x4 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x4 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x4 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x4 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				case 3: // mat3xM's
					if (!(accepted_types & PyGLM_SHAPE_3xM)) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.shape[1]) {
					case 2: // mat3x2's
						if (!(accepted_types & PyGLM_SHAPE_3x2)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x2 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x2 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x2 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x2 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					case 3: // mat3x3's
						if (!(accepted_types & PyGLM_SHAPE_3x3)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					case 4: // mat3x4's
						if (!(accepted_types & PyGLM_SHAPE_3x4)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x4 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x4 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x4 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x4 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				case 4: // mat4xM's
					if (!(accepted_types & PyGLM_SHAPE_4xM)) {
						PyBuffer_Release(&view);
						return;
					}
					switch (view.shape[1]) {
					case 2: // mat4x2's
						if (!(accepted_types & PyGLM_SHAPE_4x2)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x2 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x2 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x2 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x2 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					case 3: // mat4x3's
						if (!(accepted_types & PyGLM_SHAPE_4x3)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x3 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x3 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x3 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x3 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					case 4: // mat4x4's
						if (!(accepted_types & PyGLM_SHAPE_4x4)) {
							PyBuffer_Release(&view);
							return;
						}
						switch (view.format[0]) {
						case 'f':
							if (!(accepted_types & PyGLM_DT_FLOAT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FLOAT);
							break;
						case 'd':
							if (!(accepted_types & PyGLM_DT_DOUBLE)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_DOUBLE);
							break;
						case 'l':
						case 'i':
							if (!(accepted_types & PyGLM_DT_INT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_INT);
							break;
						case 'L':
						case 'I':
							if (!(accepted_types & PyGLM_DT_UINT)) {
								PyBuffer_Release(&view);
								return;
							}
							setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_UINT);
							break;
						default:
							PyBuffer_Release(&view);
							return;
						}
						break;
					default:
						PyBuffer_Release(&view);
						return;
					}
					break;
				default:
					PyBuffer_Release(&view);
					return;
				}
				break;
			default:
				PyBuffer_Release(&view);
				return;
			}
			if (view.readonly == 0) {
				data = view.buf;
			}
			else {
				allocate(sizeof(view.len));
				memcpy(data, view.buf, sizeof(view.len));
			}
			return;
		} // end of getbuffer checking

		if (PyGLM_TupleOrList_Check(obj)) {
			Py_ssize_t size = PyGLM_TupleOrList_GET_SIZE(obj);
			
			if ((accepted_types & PyGLM_SHAPE_1) && (accepted_types & PyGLM_T_ANY_VEC) && size == 1) { // vec1's
				PyObject* item1 = PyGLM_TupleOrList_GET_ITEM(obj, 0);

				PyGLMSingleTypeHolder item1Out = PyGLMSingleTypeHolder(item1);

				int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { item1Out.dtype });

				setInfo(PyGLM_T_VEC | PyGLM_SHAPE_1 | out_type);

				switch (out_type) {
				case PyGLM_DT_FLOAT:
					allocate(sizeof(glm::vec<1, float>));
					*((glm::vec<1, float>*)data) = glm::vec<1, float>(item1Out.asFloat());
					return;
				case PyGLM_DT_DOUBLE:
					allocate(sizeof(glm::vec<1, double>));
					*((glm::vec<1, double>*)data) = glm::vec<1, double>(item1Out.asDouble());
					return;
				case PyGLM_DT_INT64:
					allocate(sizeof(glm::vec<1, glm::i64>));
					*((glm::vec<1, glm::i64>*)data) = glm::vec<1, glm::i64>(item1Out.asInt64());
					return;
				case PyGLM_DT_UINT64:
					allocate(sizeof(glm::vec<1, glm::u64>));
					*((glm::vec<1, glm::u64>*)data) = glm::vec<1, glm::u64>(item1Out.asUint64());
					return;
				case PyGLM_DT_INT:
					allocate(sizeof(glm::vec<1, glm::i32>));
					*((glm::vec<1, glm::i32>*)data) = glm::vec<1, glm::i32>(item1Out.asInt32());
					return;
				case PyGLM_DT_UINT:
					allocate(sizeof(glm::vec<1, glm::u32>));
					*((glm::vec<1, glm::u32>*)data) = glm::vec<1, glm::u32>(item1Out.asUint32());
					return;
				case PyGLM_DT_INT16:
					allocate(sizeof(glm::vec<1, glm::i16>));
					*((glm::vec<1, glm::i16>*)data) = glm::vec<1, glm::i16>(item1Out.asInt16());
					return;
				case PyGLM_DT_UINT16:
					allocate(sizeof(glm::vec<1, glm::u16>));
					*((glm::vec<1, glm::u16>*)data) = glm::vec<1, glm::u16>(item1Out.asUint16());
					return;
				case PyGLM_DT_INT8:
					allocate(sizeof(glm::vec<1, glm::i8>));
					*((glm::vec<1, glm::i8>*)data) = glm::vec<1, glm::i8>(item1Out.asInt8());
					return;
				case PyGLM_DT_UINT8:
					allocate(sizeof(glm::vec<1, glm::u8>));
					*((glm::vec<1, glm::u8>*)data) = glm::vec<1, glm::u8>(item1Out.asUint8());
					return;
				case PyGLM_DT_BOOL:
					allocate(sizeof(glm::vec<1, bool>));
					*((glm::vec<1, bool>*)data) = glm::vec<1, bool>(item1Out.asBool());
					return;
				}
			}
			else if (size == 2) { // vec2's and mat2xM's
				PyObject* item1 = PyGLM_TupleOrList_GET_ITEM(obj, 0);
				PyObject* item2 = PyGLM_TupleOrList_GET_ITEM(obj, 1);

				if ((accepted_types & PyGLM_T_MAT) && PyGLM_TupleOrList_Check(item1) && PyGLM_TupleOrList_Check(item2)) {
					Py_ssize_t innerSize = PyGLM_TupleOrList_GET_SIZE(item1);
					if (innerSize != PyGLM_TupleOrList_GET_SIZE(item2)) {
						return;
					}

					if (innerSize == 2 && (accepted_types & PyGLM_SHAPE_2x2)) { // mat2x2
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item2, 1);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x2 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<2, 2, float>));
							*((glm::mat<2, 2, float>*)data) = glm::mat<2, 2, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<2, 2, double>));
							*((glm::mat<2, 2, double>*)data) = glm::mat<2, 2, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<2, 2, glm::i64>));
							*((glm::mat<2, 2, glm::i64>*)data) = glm::mat<2, 2, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<2, 2, glm::u64>));
							*((glm::mat<2, 2, glm::u64>*)data) = glm::mat<2, 2, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<2, 2, glm::i32>));
							*((glm::mat<2, 2, glm::i32>*)data) = glm::mat<2, 2, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<2, 2, glm::u32>));
							*((glm::mat<2, 2, glm::u32>*)data) = glm::mat<2, 2, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<2, 2, glm::i16>));
							*((glm::mat<2, 2, glm::i16>*)data) = glm::mat<2, 2, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<2, 2, glm::u16>));
							*((glm::mat<2, 2, glm::u16>*)data) = glm::mat<2, 2, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<2, 2, glm::i8>));
							*((glm::mat<2, 2, glm::i8>*)data) = glm::mat<2, 2, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<2, 2, glm::u8>));
							*((glm::mat<2, 2, glm::u8>*)data) = glm::mat<2, 2, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<2, 2, bool>));
							*((glm::mat<2, 2, bool>*)data) = glm::mat<2, 2, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool());
							return;
						}
					}
					else if (innerSize == 3 && (accepted_types & PyGLM_SHAPE_2x3)) { // mat2x3
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item1, 2);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item2, 2);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x3 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<2, 3, float>));
							*((glm::mat<2, 3, float>*)data) = glm::mat<2, 3, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<2, 3, double>));
							*((glm::mat<2, 3, double>*)data) = glm::mat<2, 3, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<2, 3, glm::i64>));
							*((glm::mat<2, 3, glm::i64>*)data) = glm::mat<2, 3, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<2, 3, glm::u64>));
							*((glm::mat<2, 3, glm::u64>*)data) = glm::mat<2, 3, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<2, 3, glm::i32>));
							*((glm::mat<2, 3, glm::i32>*)data) = glm::mat<2, 3, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<2, 3, glm::u32>));
							*((glm::mat<2, 3, glm::u32>*)data) = glm::mat<2, 3, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<2, 3, glm::i16>));
							*((glm::mat<2, 3, glm::i16>*)data) = glm::mat<2, 3, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<2, 3, glm::u16>));
							*((glm::mat<2, 3, glm::u16>*)data) = glm::mat<2, 3, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<2, 3, glm::i8>));
							*((glm::mat<2, 3, glm::i8>*)data) = glm::mat<2, 3, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<2, 3, glm::u8>));
							*((glm::mat<2, 3, glm::u8>*)data) = glm::mat<2, 3, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<2, 3, bool>));
							*((glm::mat<2, 3, bool>*)data) = glm::mat<2, 3, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool());
							return;
						}
					}
					else if (innerSize == 4 && (accepted_types & PyGLM_SHAPE_2x4)) { // mat2x4
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item1, 2);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item1, 3);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem7 = PyGLM_TupleOrList_GET_ITEM(item2, 2);
						PyObject* innerItem8 = PyGLM_TupleOrList_GET_ITEM(item2, 3);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);
						PyGLMSingleTypeHolder innerItem7Out = PyGLMSingleTypeHolder(innerItem7);
						PyGLMSingleTypeHolder innerItem8Out = PyGLMSingleTypeHolder(innerItem8);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype, innerItem7Out.dtype, innerItem8Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_2x4 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<2, 4, float>));
							*((glm::mat<2, 4, float>*)data) = glm::mat<2, 4, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat(), innerItem7Out.asFloat(), innerItem8Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<2, 4, double>));
							*((glm::mat<2, 4, double>*)data) = glm::mat<2, 4, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble(), innerItem7Out.asDouble(), innerItem8Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<2, 4, glm::i64>));
							*((glm::mat<2, 4, glm::i64>*)data) = glm::mat<2, 4, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64(), innerItem7Out.asInt64(), innerItem8Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<2, 4, glm::u64>));
							*((glm::mat<2, 4, glm::u64>*)data) = glm::mat<2, 4, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64(), innerItem7Out.asUint64(), innerItem8Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<2, 4, glm::i32>));
							*((glm::mat<2, 4, glm::i32>*)data) = glm::mat<2, 4, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32(), innerItem7Out.asInt32(), innerItem8Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<2, 4, glm::u32>));
							*((glm::mat<2, 4, glm::u32>*)data) = glm::mat<2, 4, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32(), innerItem7Out.asUint32(), innerItem8Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<2, 4, glm::i16>));
							*((glm::mat<2, 4, glm::i16>*)data) = glm::mat<2, 4, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16(), innerItem7Out.asInt16(), innerItem8Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<2, 4, glm::u16>));
							*((glm::mat<2, 4, glm::u16>*)data) = glm::mat<2, 4, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16(), innerItem7Out.asUint16(), innerItem8Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<2, 4, glm::i8>));
							*((glm::mat<2, 4, glm::i8>*)data) = glm::mat<2, 4, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8(), innerItem7Out.asInt8(), innerItem8Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<2, 4, glm::u8>));
							*((glm::mat<2, 4, glm::u8>*)data) = glm::mat<2, 4, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8(), innerItem7Out.asUint8(), innerItem8Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<2, 4, bool>));
							*((glm::mat<2, 4, bool>*)data) = glm::mat<2, 4, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool(), innerItem7Out.asBool(), innerItem8Out.asBool());
							return;
						}
					}
				}
				if ((accepted_types & PyGLM_SHAPE_2) && (accepted_types & PyGLM_T_ANY_VEC)) {
					PyGLMSingleTypeHolder item1Out = PyGLMSingleTypeHolder(item1);
					PyGLMSingleTypeHolder item2Out = PyGLMSingleTypeHolder(item2);

					int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { item1Out.dtype, item2Out.dtype });

					setInfo(PyGLM_T_VEC | PyGLM_SHAPE_2 | out_type);

					switch (out_type) {
					case PyGLM_DT_FLOAT:
						allocate(sizeof(glm::vec<2, float>));
						*((glm::vec<2, float>*)data) = glm::vec<2, float>(item1Out.asFloat(), item2Out.asFloat());
						return;
					case PyGLM_DT_DOUBLE:
						allocate(sizeof(glm::vec<2, double>));
						*((glm::vec<2, double>*)data) = glm::vec<2, double>(item1Out.asDouble(), item2Out.asDouble());
						return;
					case PyGLM_DT_INT64:
						allocate(sizeof(glm::vec<2, glm::i64>));
						*((glm::vec<2, glm::i64>*)data) = glm::vec<2, glm::i64>(item1Out.asInt64(), item2Out.asInt64());
						return;
					case PyGLM_DT_UINT64:
						allocate(sizeof(glm::vec<2, glm::u64>));
						*((glm::vec<2, glm::u64>*)data) = glm::vec<2, glm::u64>(item1Out.asUint64(), item2Out.asUint64());
						return;
					case PyGLM_DT_INT:
						allocate(sizeof(glm::vec<2, glm::i32>));
						*((glm::vec<2, glm::i32>*)data) = glm::vec<2, glm::i32>(item1Out.asInt32(), item2Out.asInt32());
						return;
					case PyGLM_DT_UINT:
						allocate(sizeof(glm::vec<2, glm::u32>));
						*((glm::vec<2, glm::u32>*)data) = glm::vec<2, glm::u32>(item1Out.asUint32(), item2Out.asUint32());
						return;
					case PyGLM_DT_INT16:
						allocate(sizeof(glm::vec<2, glm::i16>));
						*((glm::vec<2, glm::i16>*)data) = glm::vec<2, glm::i16>(item1Out.asInt16(), item2Out.asInt16());
						return;
					case PyGLM_DT_UINT16:
						allocate(sizeof(glm::vec<2, glm::u16>));
						*((glm::vec<2, glm::u16>*)data) = glm::vec<2, glm::u16>(item1Out.asUint16(), item2Out.asUint16());
						return;
					case PyGLM_DT_INT8:
						allocate(sizeof(glm::vec<2, glm::i8>));
						*((glm::vec<2, glm::i8>*)data) = glm::vec<2, glm::i8>(item1Out.asInt8(), item2Out.asInt8());
						return;
					case PyGLM_DT_UINT8:
						allocate(sizeof(glm::vec<2, glm::u8>));
						*((glm::vec<2, glm::u8>*)data) = glm::vec<2, glm::u8>(item1Out.asUint8(), item2Out.asUint8());
						return;
					case PyGLM_DT_BOOL:
						allocate(sizeof(glm::vec<2, bool>));
						*((glm::vec<2, bool>*)data) = glm::vec<2, bool>(item1Out.asBool(), item2Out.asBool());
						return;
					}
				}
			}
			else if (size == 3) { // vec3's and mat3xM's
				PyObject* item1 = PyGLM_TupleOrList_GET_ITEM(obj, 0);
				PyObject* item2 = PyGLM_TupleOrList_GET_ITEM(obj, 1);
				PyObject* item3 = PyGLM_TupleOrList_GET_ITEM(obj, 2);

				if ((accepted_types & PyGLM_T_MAT) && PyGLM_TupleOrList_Check(item1) && PyGLM_TupleOrList_Check(item2) && PyGLM_TupleOrList_Check(item3)) {
					Py_ssize_t innerSize = PyGLM_TupleOrList_GET_SIZE(item1);
					if (innerSize != PyGLM_TupleOrList_GET_SIZE(item2) || innerSize != PyGLM_TupleOrList_GET_SIZE(item3)) {
						return;
					}

					if (innerSize == 2 && (accepted_types & PyGLM_SHAPE_3x2)) { // mat3x2
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item3, 0);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item3, 1);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x2 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<3, 2, float>));
							*((glm::mat<3, 2, float>*)data) = glm::mat<3, 2, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<3, 2, double>));
							*((glm::mat<3, 2, double>*)data) = glm::mat<3, 2, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<3, 2, glm::i64>));
							*((glm::mat<3, 2, glm::i64>*)data) = glm::mat<3, 2, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<3, 2, glm::u64>));
							*((glm::mat<3, 2, glm::u64>*)data) = glm::mat<3, 2, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<3, 2, glm::i32>));
							*((glm::mat<3, 2, glm::i32>*)data) = glm::mat<3, 2, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<3, 2, glm::u32>));
							*((glm::mat<3, 2, glm::u32>*)data) = glm::mat<3, 2, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<3, 2, glm::i16>));
							*((glm::mat<3, 2, glm::i16>*)data) = glm::mat<3, 2, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<3, 2, glm::u16>));
							*((glm::mat<3, 2, glm::u16>*)data) = glm::mat<3, 2, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<3, 2, glm::i8>));
							*((glm::mat<3, 2, glm::i8>*)data) = glm::mat<3, 2, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<3, 2, glm::u8>));
							*((glm::mat<3, 2, glm::u8>*)data) = glm::mat<3, 2, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<3, 2, bool>));
							*((glm::mat<3, 2, bool>*)data) = glm::mat<3, 2, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool());
							return;
						}
					}
					else if (innerSize == 3 && (accepted_types & PyGLM_SHAPE_3x3)) { // mat3x3
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item1, 2);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item2, 2);
						PyObject* innerItem7 = PyGLM_TupleOrList_GET_ITEM(item3, 0);
						PyObject* innerItem8 = PyGLM_TupleOrList_GET_ITEM(item3, 1);
						PyObject* innerItem9 = PyGLM_TupleOrList_GET_ITEM(item3, 2);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);
						PyGLMSingleTypeHolder innerItem7Out = PyGLMSingleTypeHolder(innerItem7);
						PyGLMSingleTypeHolder innerItem8Out = PyGLMSingleTypeHolder(innerItem8);
						PyGLMSingleTypeHolder innerItem9Out = PyGLMSingleTypeHolder(innerItem9);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype, innerItem7Out.dtype, innerItem8Out.dtype, innerItem9Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x3 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<3, 3, float>));
							*((glm::mat<3, 3, float>*)data) = glm::mat<3, 3, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat(), innerItem7Out.asFloat(), innerItem8Out.asFloat(), innerItem9Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<3, 3, double>));
							*((glm::mat<3, 3, double>*)data) = glm::mat<3, 3, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble(), innerItem7Out.asDouble(), innerItem8Out.asDouble(), innerItem9Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<3, 3, glm::i64>));
							*((glm::mat<3, 3, glm::i64>*)data) = glm::mat<3, 3, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64(), innerItem7Out.asInt64(), innerItem8Out.asInt64(), innerItem9Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<3, 3, glm::u64>));
							*((glm::mat<3, 3, glm::u64>*)data) = glm::mat<3, 3, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64(), innerItem7Out.asUint64(), innerItem8Out.asUint64(), innerItem9Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<3, 3, glm::i32>));
							*((glm::mat<3, 3, glm::i32>*)data) = glm::mat<3, 3, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32(), innerItem7Out.asInt32(), innerItem8Out.asInt32(), innerItem9Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<3, 3, glm::u32>));
							*((glm::mat<3, 3, glm::u32>*)data) = glm::mat<3, 3, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32(), innerItem7Out.asUint32(), innerItem8Out.asUint32(), innerItem9Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<3, 3, glm::i16>));
							*((glm::mat<3, 3, glm::i16>*)data) = glm::mat<3, 3, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16(), innerItem7Out.asInt16(), innerItem8Out.asInt16(), innerItem9Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<3, 3, glm::u16>));
							*((glm::mat<3, 3, glm::u16>*)data) = glm::mat<3, 3, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16(), innerItem7Out.asUint16(), innerItem8Out.asUint16(), innerItem9Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<3, 3, glm::i8>));
							*((glm::mat<3, 3, glm::i8>*)data) = glm::mat<3, 3, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8(), innerItem7Out.asInt8(), innerItem8Out.asInt8(), innerItem9Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<3, 3, glm::u8>));
							*((glm::mat<3, 3, glm::u8>*)data) = glm::mat<3, 3, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8(), innerItem7Out.asUint8(), innerItem8Out.asUint8(), innerItem9Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<3, 3, bool>));
							*((glm::mat<3, 3, bool>*)data) = glm::mat<3, 3, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool(), innerItem7Out.asBool(), innerItem8Out.asBool(), innerItem9Out.asBool());
							return;
						}
					}
					else if (innerSize == 4 && (accepted_types & PyGLM_SHAPE_3x4)) { // mat3x4
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item1, 2);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item1, 3);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem7 = PyGLM_TupleOrList_GET_ITEM(item2, 2);
						PyObject* innerItem8 = PyGLM_TupleOrList_GET_ITEM(item2, 3);
						PyObject* innerItem9 = PyGLM_TupleOrList_GET_ITEM(item3, 0);
						PyObject* innerItem10 = PyGLM_TupleOrList_GET_ITEM(item3, 1);
						PyObject* innerItem11 = PyGLM_TupleOrList_GET_ITEM(item3, 2);
						PyObject* innerItem12 = PyGLM_TupleOrList_GET_ITEM(item3, 3);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);
						PyGLMSingleTypeHolder innerItem7Out = PyGLMSingleTypeHolder(innerItem7);
						PyGLMSingleTypeHolder innerItem8Out = PyGLMSingleTypeHolder(innerItem8);
						PyGLMSingleTypeHolder innerItem9Out = PyGLMSingleTypeHolder(innerItem9);
						PyGLMSingleTypeHolder innerItem10Out = PyGLMSingleTypeHolder(innerItem10);
						PyGLMSingleTypeHolder innerItem11Out = PyGLMSingleTypeHolder(innerItem11);
						PyGLMSingleTypeHolder innerItem12Out = PyGLMSingleTypeHolder(innerItem12);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype, innerItem7Out.dtype, innerItem8Out.dtype, innerItem9Out.dtype, innerItem10Out.dtype, innerItem11Out.dtype, innerItem12Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_3x4 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<3, 4, float>));
							*((glm::mat<3, 4, float>*)data) = glm::mat<3, 4, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat(), innerItem7Out.asFloat(), innerItem8Out.asFloat(), innerItem9Out.asFloat(), innerItem10Out.asFloat(), innerItem11Out.asFloat(), innerItem12Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<3, 4, double>));
							*((glm::mat<3, 4, double>*)data) = glm::mat<3, 4, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble(), innerItem7Out.asDouble(), innerItem8Out.asDouble(), innerItem9Out.asDouble(), innerItem10Out.asDouble(), innerItem11Out.asDouble(), innerItem12Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<3, 4, glm::i64>));
							*((glm::mat<3, 4, glm::i64>*)data) = glm::mat<3, 4, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64(), innerItem7Out.asInt64(), innerItem8Out.asInt64(), innerItem9Out.asInt64(), innerItem10Out.asInt64(), innerItem11Out.asInt64(), innerItem12Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<3, 4, glm::u64>));
							*((glm::mat<3, 4, glm::u64>*)data) = glm::mat<3, 4, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64(), innerItem7Out.asUint64(), innerItem8Out.asUint64(), innerItem9Out.asUint64(), innerItem10Out.asUint64(), innerItem11Out.asUint64(), innerItem12Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<3, 4, glm::i32>));
							*((glm::mat<3, 4, glm::i32>*)data) = glm::mat<3, 4, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32(), innerItem7Out.asInt32(), innerItem8Out.asInt32(), innerItem9Out.asInt32(), innerItem10Out.asInt32(), innerItem11Out.asInt32(), innerItem12Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<3, 4, glm::u32>));
							*((glm::mat<3, 4, glm::u32>*)data) = glm::mat<3, 4, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32(), innerItem7Out.asUint32(), innerItem8Out.asUint32(), innerItem9Out.asUint32(), innerItem10Out.asUint32(), innerItem11Out.asUint32(), innerItem12Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<3, 4, glm::i16>));
							*((glm::mat<3, 4, glm::i16>*)data) = glm::mat<3, 4, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16(), innerItem7Out.asInt16(), innerItem8Out.asInt16(), innerItem9Out.asInt16(), innerItem10Out.asInt16(), innerItem11Out.asInt16(), innerItem12Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<3, 4, glm::u16>));
							*((glm::mat<3, 4, glm::u16>*)data) = glm::mat<3, 4, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16(), innerItem7Out.asUint16(), innerItem8Out.asUint16(), innerItem9Out.asUint16(), innerItem10Out.asUint16(), innerItem11Out.asUint16(), innerItem12Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<3, 4, glm::i8>));
							*((glm::mat<3, 4, glm::i8>*)data) = glm::mat<3, 4, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8(), innerItem7Out.asInt8(), innerItem8Out.asInt8(), innerItem9Out.asInt8(), innerItem10Out.asInt8(), innerItem11Out.asInt8(), innerItem12Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<3, 4, glm::u8>));
							*((glm::mat<3, 4, glm::u8>*)data) = glm::mat<3, 4, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8(), innerItem7Out.asUint8(), innerItem8Out.asUint8(), innerItem9Out.asUint8(), innerItem10Out.asUint8(), innerItem11Out.asUint8(), innerItem12Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<3, 4, bool>));
							*((glm::mat<3, 4, bool>*)data) = glm::mat<3, 4, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool(), innerItem7Out.asBool(), innerItem8Out.asBool(), innerItem9Out.asBool(), innerItem10Out.asBool(), innerItem11Out.asBool(), innerItem12Out.asBool());
							return;
						}
					}
				}

				if ((accepted_types & PyGLM_SHAPE_3) && (accepted_types & PyGLM_T_ANY_VEC)) {

					PyGLMSingleTypeHolder item1Out = PyGLMSingleTypeHolder(item1);
					PyGLMSingleTypeHolder item2Out = PyGLMSingleTypeHolder(item2);
					PyGLMSingleTypeHolder item3Out = PyGLMSingleTypeHolder(item3);

					int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { item1Out.dtype, item2Out.dtype, item3Out.dtype });

					setInfo(PyGLM_T_VEC | PyGLM_SHAPE_3 | out_type);

					switch (out_type) {
					case PyGLM_DT_FLOAT:
						allocate(sizeof(glm::vec<3, float>));
						*((glm::vec<3, float>*)data) = glm::vec<3, float>(item1Out.asFloat(), item2Out.asFloat(), item3Out.asFloat());
						return;
					case PyGLM_DT_DOUBLE:
						allocate(sizeof(glm::vec<3, double>));
						*((glm::vec<3, double>*)data) = glm::vec<3, double>(item1Out.asDouble(), item2Out.asDouble(), item3Out.asDouble());
						return;
					case PyGLM_DT_INT64:
						allocate(sizeof(glm::vec<3, glm::i64>));
						*((glm::vec<3, glm::i64>*)data) = glm::vec<3, glm::i64>(item1Out.asInt64(), item2Out.asInt64(), item3Out.asInt64());
						return;
					case PyGLM_DT_UINT64:
						allocate(sizeof(glm::vec<3, glm::u64>));
						*((glm::vec<3, glm::u64>*)data) = glm::vec<3, glm::u64>(item1Out.asUint64(), item2Out.asUint64(), item3Out.asUint64());
						return;
					case PyGLM_DT_INT:
						allocate(sizeof(glm::vec<3, glm::i32>));
						*((glm::vec<3, glm::i32>*)data) = glm::vec<3, glm::i32>(item1Out.asInt32(), item2Out.asInt32(), item3Out.asInt32());
						return;
					case PyGLM_DT_UINT:
						allocate(sizeof(glm::vec<3, glm::u32>));
						*((glm::vec<3, glm::u32>*)data) = glm::vec<3, glm::u32>(item1Out.asUint32(), item2Out.asUint32(), item3Out.asUint32());
						return;
					case PyGLM_DT_INT16:
						allocate(sizeof(glm::vec<3, glm::i16>));
						*((glm::vec<3, glm::i16>*)data) = glm::vec<3, glm::i16>(item1Out.asInt16(), item2Out.asInt16(), item3Out.asInt16());
						return;
					case PyGLM_DT_UINT16:
						allocate(sizeof(glm::vec<3, glm::u16>));
						*((glm::vec<3, glm::u16>*)data) = glm::vec<3, glm::u16>(item1Out.asUint16(), item2Out.asUint16(), item3Out.asUint16());
						return;
					case PyGLM_DT_INT8:
						allocate(sizeof(glm::vec<3, glm::i8>));
						*((glm::vec<3, glm::i8>*)data) = glm::vec<3, glm::i8>(item1Out.asInt8(), item2Out.asInt8(), item3Out.asInt8());
						return;
					case PyGLM_DT_UINT8:
						allocate(sizeof(glm::vec<3, glm::u8>));
						*((glm::vec<3, glm::u8>*)data) = glm::vec<3, glm::u8>(item1Out.asUint8(), item2Out.asUint8(), item3Out.asUint8());
						return;
					case PyGLM_DT_BOOL:
						allocate(sizeof(glm::vec<3, bool>));
						*((glm::vec<3, bool>*)data) = glm::vec<3, bool>(item1Out.asBool(), item2Out.asBool(), item3Out.asBool());
						return;
					}
				}
			}
			else if (size == 4) { // vec4's, mat4xM's and qua's
				PyObject* item1 = PyGLM_TupleOrList_GET_ITEM(obj, 0);
				PyObject* item2 = PyGLM_TupleOrList_GET_ITEM(obj, 1);
				PyObject* item3 = PyGLM_TupleOrList_GET_ITEM(obj, 2);
				PyObject* item4 = PyGLM_TupleOrList_GET_ITEM(obj, 3);

				if ((accepted_types & PyGLM_T_MAT) && PyGLM_TupleOrList_Check(item1) && PyGLM_TupleOrList_Check(item2) && PyGLM_TupleOrList_Check(item3) && PyGLM_TupleOrList_Check(item4)) {
					Py_ssize_t innerSize = PyGLM_TupleOrList_GET_SIZE(item1);
					if (innerSize != PyGLM_TupleOrList_GET_SIZE(item2) || innerSize != PyGLM_TupleOrList_GET_SIZE(item3) || innerSize != PyGLM_TupleOrList_GET_SIZE(item4)) {
						return;
					}
					if (innerSize == 2 && (accepted_types & PyGLM_SHAPE_4x2)) { // mat4x2
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item3, 0);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item3, 1);
						PyObject* innerItem7 = PyGLM_TupleOrList_GET_ITEM(item4, 0);
						PyObject* innerItem8 = PyGLM_TupleOrList_GET_ITEM(item4, 1);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);
						PyGLMSingleTypeHolder innerItem7Out = PyGLMSingleTypeHolder(innerItem7);
						PyGLMSingleTypeHolder innerItem8Out = PyGLMSingleTypeHolder(innerItem8);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype, innerItem7Out.dtype, innerItem8Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x2 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<4, 2, float>));
							*((glm::mat<4, 2, float>*)data) = glm::mat<4, 2, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat(), innerItem7Out.asFloat(), innerItem8Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<4, 2, double>));
							*((glm::mat<4, 2, double>*)data) = glm::mat<4, 2, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble(), innerItem7Out.asDouble(), innerItem8Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<4, 2, glm::i64>));
							*((glm::mat<4, 2, glm::i64>*)data) = glm::mat<4, 2, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64(), innerItem7Out.asInt64(), innerItem8Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<4, 2, glm::u64>));
							*((glm::mat<4, 2, glm::u64>*)data) = glm::mat<4, 2, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64(), innerItem7Out.asUint64(), innerItem8Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<4, 2, glm::i32>));
							*((glm::mat<4, 2, glm::i32>*)data) = glm::mat<4, 2, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32(), innerItem7Out.asInt32(), innerItem8Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<4, 2, glm::u32>));
							*((glm::mat<4, 2, glm::u32>*)data) = glm::mat<4, 2, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32(), innerItem7Out.asUint32(), innerItem8Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<4, 2, glm::i16>));
							*((glm::mat<4, 2, glm::i16>*)data) = glm::mat<4, 2, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16(), innerItem7Out.asInt16(), innerItem8Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<4, 2, glm::u16>));
							*((glm::mat<4, 2, glm::u16>*)data) = glm::mat<4, 2, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16(), innerItem7Out.asUint16(), innerItem8Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<4, 2, glm::i8>));
							*((glm::mat<4, 2, glm::i8>*)data) = glm::mat<4, 2, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8(), innerItem7Out.asInt8(), innerItem8Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<4, 2, glm::u8>));
							*((glm::mat<4, 2, glm::u8>*)data) = glm::mat<4, 2, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8(), innerItem7Out.asUint8(), innerItem8Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<4, 2, bool>));
							*((glm::mat<4, 2, bool>*)data) = glm::mat<4, 2, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool(), innerItem7Out.asBool(), innerItem8Out.asBool());
							return;
						}
					}
					else if (innerSize == 3 && (accepted_types & PyGLM_SHAPE_4x3)) { // mat4x3
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item1, 2);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item2, 2);
						PyObject* innerItem7 = PyGLM_TupleOrList_GET_ITEM(item3, 0);
						PyObject* innerItem8 = PyGLM_TupleOrList_GET_ITEM(item3, 1);
						PyObject* innerItem9 = PyGLM_TupleOrList_GET_ITEM(item3, 2);
						PyObject* innerItem10 = PyGLM_TupleOrList_GET_ITEM(item4, 0);
						PyObject* innerItem11 = PyGLM_TupleOrList_GET_ITEM(item4, 1);
						PyObject* innerItem12 = PyGLM_TupleOrList_GET_ITEM(item4, 2);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);
						PyGLMSingleTypeHolder innerItem7Out = PyGLMSingleTypeHolder(innerItem7);
						PyGLMSingleTypeHolder innerItem8Out = PyGLMSingleTypeHolder(innerItem8);
						PyGLMSingleTypeHolder innerItem9Out = PyGLMSingleTypeHolder(innerItem9);
						PyGLMSingleTypeHolder innerItem10Out = PyGLMSingleTypeHolder(innerItem10);
						PyGLMSingleTypeHolder innerItem11Out = PyGLMSingleTypeHolder(innerItem11);
						PyGLMSingleTypeHolder innerItem12Out = PyGLMSingleTypeHolder(innerItem12);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype, innerItem7Out.dtype, innerItem8Out.dtype, innerItem9Out.dtype, innerItem10Out.dtype, innerItem11Out.dtype, innerItem12Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x3 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<4, 3, float>));
							*((glm::mat<4, 3, float>*)data) = glm::mat<4, 3, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat(), innerItem7Out.asFloat(), innerItem8Out.asFloat(), innerItem9Out.asFloat(), innerItem10Out.asFloat(), innerItem11Out.asFloat(), innerItem12Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<4, 3, double>));
							*((glm::mat<4, 3, double>*)data) = glm::mat<4, 3, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble(), innerItem7Out.asDouble(), innerItem8Out.asDouble(), innerItem9Out.asDouble(), innerItem10Out.asDouble(), innerItem11Out.asDouble(), innerItem12Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<4, 3, glm::i64>));
							*((glm::mat<4, 3, glm::i64>*)data) = glm::mat<4, 3, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64(), innerItem7Out.asInt64(), innerItem8Out.asInt64(), innerItem9Out.asInt64(), innerItem10Out.asInt64(), innerItem11Out.asInt64(), innerItem12Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<4, 3, glm::u64>));
							*((glm::mat<4, 3, glm::u64>*)data) = glm::mat<4, 3, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64(), innerItem7Out.asUint64(), innerItem8Out.asUint64(), innerItem9Out.asUint64(), innerItem10Out.asUint64(), innerItem11Out.asUint64(), innerItem12Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<4, 3, glm::i32>));
							*((glm::mat<4, 3, glm::i32>*)data) = glm::mat<4, 3, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32(), innerItem7Out.asInt32(), innerItem8Out.asInt32(), innerItem9Out.asInt32(), innerItem10Out.asInt32(), innerItem11Out.asInt32(), innerItem12Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<4, 3, glm::u32>));
							*((glm::mat<4, 3, glm::u32>*)data) = glm::mat<4, 3, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32(), innerItem7Out.asUint32(), innerItem8Out.asUint32(), innerItem9Out.asUint32(), innerItem10Out.asUint32(), innerItem11Out.asUint32(), innerItem12Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<4, 3, glm::i16>));
							*((glm::mat<4, 3, glm::i16>*)data) = glm::mat<4, 3, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16(), innerItem7Out.asInt16(), innerItem8Out.asInt16(), innerItem9Out.asInt16(), innerItem10Out.asInt16(), innerItem11Out.asInt16(), innerItem12Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<4, 3, glm::u16>));
							*((glm::mat<4, 3, glm::u16>*)data) = glm::mat<4, 3, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16(), innerItem7Out.asUint16(), innerItem8Out.asUint16(), innerItem9Out.asUint16(), innerItem10Out.asUint16(), innerItem11Out.asUint16(), innerItem12Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<4, 3, glm::i8>));
							*((glm::mat<4, 3, glm::i8>*)data) = glm::mat<4, 3, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8(), innerItem7Out.asInt8(), innerItem8Out.asInt8(), innerItem9Out.asInt8(), innerItem10Out.asInt8(), innerItem11Out.asInt8(), innerItem12Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<4, 3, glm::u8>));
							*((glm::mat<4, 3, glm::u8>*)data) = glm::mat<4, 3, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8(), innerItem7Out.asUint8(), innerItem8Out.asUint8(), innerItem9Out.asUint8(), innerItem10Out.asUint8(), innerItem11Out.asUint8(), innerItem12Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<4, 3, bool>));
							*((glm::mat<4, 3, bool>*)data) = glm::mat<4, 3, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool(), innerItem7Out.asBool(), innerItem8Out.asBool(), innerItem9Out.asBool(), innerItem10Out.asBool(), innerItem11Out.asBool(), innerItem12Out.asBool());
							return;
						}
					}
					else if (innerSize == 4 && (accepted_types & PyGLM_SHAPE_4x4)) { // mat4x4
						PyObject* innerItem1 = PyGLM_TupleOrList_GET_ITEM(item1, 0);
						PyObject* innerItem2 = PyGLM_TupleOrList_GET_ITEM(item1, 1);
						PyObject* innerItem3 = PyGLM_TupleOrList_GET_ITEM(item1, 2);
						PyObject* innerItem4 = PyGLM_TupleOrList_GET_ITEM(item1, 3);
						PyObject* innerItem5 = PyGLM_TupleOrList_GET_ITEM(item2, 0);
						PyObject* innerItem6 = PyGLM_TupleOrList_GET_ITEM(item2, 1);
						PyObject* innerItem7 = PyGLM_TupleOrList_GET_ITEM(item2, 2);
						PyObject* innerItem8 = PyGLM_TupleOrList_GET_ITEM(item2, 3);
						PyObject* innerItem9 = PyGLM_TupleOrList_GET_ITEM(item3, 0);
						PyObject* innerItem10 = PyGLM_TupleOrList_GET_ITEM(item3, 1);
						PyObject* innerItem11 = PyGLM_TupleOrList_GET_ITEM(item3, 2);
						PyObject* innerItem12 = PyGLM_TupleOrList_GET_ITEM(item3, 3);
						PyObject* innerItem13 = PyGLM_TupleOrList_GET_ITEM(item4, 0);
						PyObject* innerItem14 = PyGLM_TupleOrList_GET_ITEM(item4, 1);
						PyObject* innerItem15 = PyGLM_TupleOrList_GET_ITEM(item4, 2);
						PyObject* innerItem16 = PyGLM_TupleOrList_GET_ITEM(item4, 3);

						PyGLMSingleTypeHolder innerItem1Out = PyGLMSingleTypeHolder(innerItem1);
						PyGLMSingleTypeHolder innerItem2Out = PyGLMSingleTypeHolder(innerItem2);
						PyGLMSingleTypeHolder innerItem3Out = PyGLMSingleTypeHolder(innerItem3);
						PyGLMSingleTypeHolder innerItem4Out = PyGLMSingleTypeHolder(innerItem4);
						PyGLMSingleTypeHolder innerItem5Out = PyGLMSingleTypeHolder(innerItem5);
						PyGLMSingleTypeHolder innerItem6Out = PyGLMSingleTypeHolder(innerItem6);
						PyGLMSingleTypeHolder innerItem7Out = PyGLMSingleTypeHolder(innerItem7);
						PyGLMSingleTypeHolder innerItem8Out = PyGLMSingleTypeHolder(innerItem8);
						PyGLMSingleTypeHolder innerItem9Out = PyGLMSingleTypeHolder(innerItem9);
						PyGLMSingleTypeHolder innerItem10Out = PyGLMSingleTypeHolder(innerItem10);
						PyGLMSingleTypeHolder innerItem11Out = PyGLMSingleTypeHolder(innerItem11);
						PyGLMSingleTypeHolder innerItem12Out = PyGLMSingleTypeHolder(innerItem12);
						PyGLMSingleTypeHolder innerItem13Out = PyGLMSingleTypeHolder(innerItem13);
						PyGLMSingleTypeHolder innerItem14Out = PyGLMSingleTypeHolder(innerItem14);
						PyGLMSingleTypeHolder innerItem15Out = PyGLMSingleTypeHolder(innerItem15);
						PyGLMSingleTypeHolder innerItem16Out = PyGLMSingleTypeHolder(innerItem16);

						int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { innerItem1Out.dtype, innerItem2Out.dtype, innerItem3Out.dtype, innerItem4Out.dtype, innerItem5Out.dtype, innerItem6Out.dtype, innerItem7Out.dtype, innerItem8Out.dtype, innerItem9Out.dtype, innerItem10Out.dtype, innerItem11Out.dtype, innerItem12Out.dtype, innerItem13Out.dtype, innerItem14Out.dtype, innerItem15Out.dtype, innerItem16Out.dtype });

						setInfo(PyGLM_T_MAT | PyGLM_SHAPE_4x4 | out_type);

						switch (out_type) {
						case PyGLM_DT_FLOAT:
							allocate(sizeof(glm::mat<4, 4, float>));
							*((glm::mat<4, 4, float>*)data) = glm::mat<4, 4, float>(innerItem1Out.asFloat(), innerItem2Out.asFloat(), innerItem3Out.asFloat(), innerItem4Out.asFloat(), innerItem5Out.asFloat(), innerItem6Out.asFloat(), innerItem7Out.asFloat(), innerItem8Out.asFloat(), innerItem9Out.asFloat(), innerItem10Out.asFloat(), innerItem11Out.asFloat(), innerItem12Out.asFloat(), innerItem13Out.asFloat(), innerItem14Out.asFloat(), innerItem15Out.asFloat(), innerItem16Out.asFloat());
							return;
						case PyGLM_DT_DOUBLE:
							allocate(sizeof(glm::mat<4, 4, double>));
							*((glm::mat<4, 4, double>*)data) = glm::mat<4, 4, double>(innerItem1Out.asDouble(), innerItem2Out.asDouble(), innerItem3Out.asDouble(), innerItem4Out.asDouble(), innerItem5Out.asDouble(), innerItem6Out.asDouble(), innerItem7Out.asDouble(), innerItem8Out.asDouble(), innerItem9Out.asDouble(), innerItem10Out.asDouble(), innerItem11Out.asDouble(), innerItem12Out.asDouble(), innerItem13Out.asDouble(), innerItem14Out.asDouble(), innerItem15Out.asDouble(), innerItem16Out.asDouble());
							return;
						case PyGLM_DT_INT64:
							allocate(sizeof(glm::mat<4, 4, glm::i64>));
							*((glm::mat<4, 4, glm::i64>*)data) = glm::mat<4, 4, glm::i64>(innerItem1Out.asInt64(), innerItem2Out.asInt64(), innerItem3Out.asInt64(), innerItem4Out.asInt64(), innerItem5Out.asInt64(), innerItem6Out.asInt64(), innerItem7Out.asInt64(), innerItem8Out.asInt64(), innerItem9Out.asInt64(), innerItem10Out.asInt64(), innerItem11Out.asInt64(), innerItem12Out.asInt64(), innerItem13Out.asInt64(), innerItem14Out.asInt64(), innerItem15Out.asInt64(), innerItem16Out.asInt64());
							return;
						case PyGLM_DT_UINT64:
							allocate(sizeof(glm::mat<4, 4, glm::u64>));
							*((glm::mat<4, 4, glm::u64>*)data) = glm::mat<4, 4, glm::u64>(innerItem1Out.asUint64(), innerItem2Out.asUint64(), innerItem3Out.asUint64(), innerItem4Out.asUint64(), innerItem5Out.asUint64(), innerItem6Out.asUint64(), innerItem7Out.asUint64(), innerItem8Out.asUint64(), innerItem9Out.asUint64(), innerItem10Out.asUint64(), innerItem11Out.asUint64(), innerItem12Out.asUint64(), innerItem13Out.asUint64(), innerItem14Out.asUint64(), innerItem15Out.asUint64(), innerItem16Out.asUint64());
							return;
						case PyGLM_DT_INT:
							allocate(sizeof(glm::mat<4, 4, glm::i32>));
							*((glm::mat<4, 4, glm::i32>*)data) = glm::mat<4, 4, glm::i32>(innerItem1Out.asInt32(), innerItem2Out.asInt32(), innerItem3Out.asInt32(), innerItem4Out.asInt32(), innerItem5Out.asInt32(), innerItem6Out.asInt32(), innerItem7Out.asInt32(), innerItem8Out.asInt32(), innerItem9Out.asInt32(), innerItem10Out.asInt32(), innerItem11Out.asInt32(), innerItem12Out.asInt32(), innerItem13Out.asInt32(), innerItem14Out.asInt32(), innerItem15Out.asInt32(), innerItem16Out.asInt32());
							return;
						case PyGLM_DT_UINT:
							allocate(sizeof(glm::mat<4, 4, glm::u32>));
							*((glm::mat<4, 4, glm::u32>*)data) = glm::mat<4, 4, glm::u32>(innerItem1Out.asUint32(), innerItem2Out.asUint32(), innerItem3Out.asUint32(), innerItem4Out.asUint32(), innerItem5Out.asUint32(), innerItem6Out.asUint32(), innerItem7Out.asUint32(), innerItem8Out.asUint32(), innerItem9Out.asUint32(), innerItem10Out.asUint32(), innerItem11Out.asUint32(), innerItem12Out.asUint32(), innerItem13Out.asUint32(), innerItem14Out.asUint32(), innerItem15Out.asUint32(), innerItem16Out.asUint32());
							return;
						case PyGLM_DT_INT16:
							allocate(sizeof(glm::mat<4, 4, glm::i16>));
							*((glm::mat<4, 4, glm::i16>*)data) = glm::mat<4, 4, glm::i16>(innerItem1Out.asInt16(), innerItem2Out.asInt16(), innerItem3Out.asInt16(), innerItem4Out.asInt16(), innerItem5Out.asInt16(), innerItem6Out.asInt16(), innerItem7Out.asInt16(), innerItem8Out.asInt16(), innerItem9Out.asInt16(), innerItem10Out.asInt16(), innerItem11Out.asInt16(), innerItem12Out.asInt16(), innerItem13Out.asInt16(), innerItem14Out.asInt16(), innerItem15Out.asInt16(), innerItem16Out.asInt16());
							return;
						case PyGLM_DT_UINT16:
							allocate(sizeof(glm::mat<4, 4, glm::u16>));
							*((glm::mat<4, 4, glm::u16>*)data) = glm::mat<4, 4, glm::u16>(innerItem1Out.asUint16(), innerItem2Out.asUint16(), innerItem3Out.asUint16(), innerItem4Out.asUint16(), innerItem5Out.asUint16(), innerItem6Out.asUint16(), innerItem7Out.asUint16(), innerItem8Out.asUint16(), innerItem9Out.asUint16(), innerItem10Out.asUint16(), innerItem11Out.asUint16(), innerItem12Out.asUint16(), innerItem13Out.asUint16(), innerItem14Out.asUint16(), innerItem15Out.asUint16(), innerItem16Out.asUint16());
							return;
						case PyGLM_DT_INT8:
							allocate(sizeof(glm::mat<4, 4, glm::i8>));
							*((glm::mat<4, 4, glm::i8>*)data) = glm::mat<4, 4, glm::i8>(innerItem1Out.asInt8(), innerItem2Out.asInt8(), innerItem3Out.asInt8(), innerItem4Out.asInt8(), innerItem5Out.asInt8(), innerItem6Out.asInt8(), innerItem7Out.asInt8(), innerItem8Out.asInt8(), innerItem9Out.asInt8(), innerItem10Out.asInt8(), innerItem11Out.asInt8(), innerItem12Out.asInt8(), innerItem13Out.asInt8(), innerItem14Out.asInt8(), innerItem15Out.asInt8(), innerItem16Out.asInt8());
							return;
						case PyGLM_DT_UINT8:
							allocate(sizeof(glm::mat<4, 4, glm::u8>));
							*((glm::mat<4, 4, glm::u8>*)data) = glm::mat<4, 4, glm::u8>(innerItem1Out.asUint8(), innerItem2Out.asUint8(), innerItem3Out.asUint8(), innerItem4Out.asUint8(), innerItem5Out.asUint8(), innerItem6Out.asUint8(), innerItem7Out.asUint8(), innerItem8Out.asUint8(), innerItem9Out.asUint8(), innerItem10Out.asUint8(), innerItem11Out.asUint8(), innerItem12Out.asUint8(), innerItem13Out.asUint8(), innerItem14Out.asUint8(), innerItem15Out.asUint8(), innerItem16Out.asUint8());
							return;
						case PyGLM_DT_BOOL:
							allocate(sizeof(glm::mat<4, 4, bool>));
							*((glm::mat<4, 4, bool>*)data) = glm::mat<4, 4, bool>(innerItem1Out.asBool(), innerItem2Out.asBool(), innerItem3Out.asBool(), innerItem4Out.asBool(), innerItem5Out.asBool(), innerItem6Out.asBool(), innerItem7Out.asBool(), innerItem8Out.asBool(), innerItem9Out.asBool(), innerItem10Out.asBool(), innerItem11Out.asBool(), innerItem12Out.asBool(), innerItem13Out.asBool(), innerItem14Out.asBool(), innerItem15Out.asBool(), innerItem16Out.asBool());
							return;
						}
					}
				}

				if ((accepted_types & PyGLM_SHAPE_4) && (accepted_types & PyGLM_T_ANY_VEC)) {

					PyGLMSingleTypeHolder item1Out = PyGLMSingleTypeHolder(item1);
					PyGLMSingleTypeHolder item2Out = PyGLMSingleTypeHolder(item2);
					PyGLMSingleTypeHolder item3Out = PyGLMSingleTypeHolder(item3);
					PyGLMSingleTypeHolder item4Out = PyGLMSingleTypeHolder(item4);

					int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { item1Out.dtype, item2Out.dtype, item3Out.dtype, item4Out.dtype });

					setInfo(PyGLM_T_VEC | PyGLM_SHAPE_4 | out_type);

					switch (out_type) {
					case PyGLM_DT_FLOAT:
						allocate(sizeof(glm::vec<4, float>));
						*((glm::vec<4, float>*)data) = glm::vec<4, float>(item1Out.asFloat(), item2Out.asFloat(), item3Out.asFloat(), item4Out.asFloat());
						return;
					case PyGLM_DT_DOUBLE:
						allocate(sizeof(glm::vec<4, double>));
						*((glm::vec<4, double>*)data) = glm::vec<4, double>(item1Out.asDouble(), item2Out.asDouble(), item3Out.asDouble(), item4Out.asDouble());
						return;
					case PyGLM_DT_INT64:
						allocate(sizeof(glm::vec<4, glm::i64>));
						*((glm::vec<4, glm::i64>*)data) = glm::vec<4, glm::i64>(item1Out.asInt64(), item2Out.asInt64(), item3Out.asInt64(), item4Out.asInt64());
						return;
					case PyGLM_DT_UINT64:
						allocate(sizeof(glm::vec<4, glm::u64>));
						*((glm::vec<4, glm::u64>*)data) = glm::vec<4, glm::u64>(item1Out.asUint64(), item2Out.asUint64(), item3Out.asUint64(), item4Out.asUint64());
						return;
					case PyGLM_DT_INT:
						allocate(sizeof(glm::vec<4, glm::i32>));
						*((glm::vec<4, glm::i32>*)data) = glm::vec<4, glm::i32>(item1Out.asInt32(), item2Out.asInt32(), item3Out.asInt32(), item4Out.asInt32());
						return;
					case PyGLM_DT_UINT:
						allocate(sizeof(glm::vec<4, glm::u32>));
						*((glm::vec<4, glm::u32>*)data) = glm::vec<4, glm::u32>(item1Out.asUint32(), item2Out.asUint32(), item3Out.asUint32(), item4Out.asUint32());
						return;
					case PyGLM_DT_INT16:
						allocate(sizeof(glm::vec<4, glm::i16>));
						*((glm::vec<4, glm::i16>*)data) = glm::vec<4, glm::i16>(item1Out.asInt16(), item2Out.asInt16(), item3Out.asInt16(), item4Out.asInt16());
						return;
					case PyGLM_DT_UINT16:
						allocate(sizeof(glm::vec<4, glm::u16>));
						*((glm::vec<4, glm::u16>*)data) = glm::vec<4, glm::u16>(item1Out.asUint16(), item2Out.asUint16(), item3Out.asUint16(), item4Out.asUint16());
						return;
					case PyGLM_DT_INT8:
						allocate(sizeof(glm::vec<4, glm::i8>));
						*((glm::vec<4, glm::i8>*)data) = glm::vec<4, glm::i8>(item1Out.asInt8(), item2Out.asInt8(), item3Out.asInt8(), item4Out.asInt8());
						return;
					case PyGLM_DT_UINT8:
						allocate(sizeof(glm::vec<4, glm::u8>));
						*((glm::vec<4, glm::u8>*)data) = glm::vec<4, glm::u8>(item1Out.asUint8(), item2Out.asUint8(), item3Out.asUint8(), item4Out.asUint8());
						return;
					case PyGLM_DT_BOOL:
						allocate(sizeof(glm::vec<4, bool>));
						*((glm::vec<4, bool>*)data) = glm::vec<4, bool>(item1Out.asBool(), item2Out.asBool(), item3Out.asBool(), item4Out.asBool());
						return;
					}
				}

				if ((accepted_types & PyGLM_T_QUA)) {
					PyGLMSingleTypeHolder item1Out = PyGLMSingleTypeHolder(item1);
					PyGLMSingleTypeHolder item2Out = PyGLMSingleTypeHolder(item2);
					PyGLMSingleTypeHolder item3Out = PyGLMSingleTypeHolder(item3);
					PyGLMSingleTypeHolder item4Out = PyGLMSingleTypeHolder(item4);

					int out_type = PyGLMSingleTypeHolder::getMostImportantType(accepted_types, { item1Out.dtype, item2Out.dtype, item3Out.dtype, item4Out.dtype });

					setInfo(PyGLM_T_QUA | out_type);

					switch (out_type) {
					case PyGLM_DT_FLOAT:
						allocate(sizeof(glm::qua<float>));
						*((glm::qua<float>*)data) = glm::qua<float>(item1Out.asFloat(), item2Out.asFloat(), item3Out.asFloat(), item4Out.asFloat());
						return;
					case PyGLM_DT_DOUBLE:
						allocate(sizeof(glm::qua<double>));
						*((glm::qua<double>*)data) = glm::qua<double>(item1Out.asDouble(), item2Out.asDouble(), item3Out.asDouble(), item4Out.asDouble());
						return;
					}
				}
			}
		}
#endif
	}

	template<int C, int R, typename T>
	inline glm::mat<C, R, T> getMat() {
		return *((glm::mat<C, R, T>*)data);
	}

	template<int L, typename T>
	inline glm::vec<L, T> getVec() {
		return *((glm::vec<L, T>*)data);
	}

	template<typename T>
	inline glm::qua<T> getQua() {
		return *((glm::qua<T>*)data);
	}

private:
	void allocate(size_t size) {
		assert(size <= 128);
	}

	void setInfo(int info) {
		this->info = info;

		this->isVec = (info & (PyGLM_T_ANY_VEC));

		this->isMat = (info & (PyGLM_T_MAT));

		this->isQua = (info & (PyGLM_T_QUA));
	}
};

#define _SUB_PyGLM_GET_TYPE(o) ((o->ob_type->tp_dealloc == NULL) ? PyGLM_TYPE_UNKNOWN : (o->ob_type->tp_dealloc == (destructor)vec_dealloc) ? PyGLM_TYPE_VEC : (o->ob_type->tp_dealloc == (destructor)mat_dealloc) ? PyGLM_TYPE_MAT : (o->ob_type->tp_dealloc == (destructor)qua_dealloc) ? PyGLM_TYPE_QUA : (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) ? PyGLM_TYPE_VEC : PyGLM_TYPE_UNKNOWN)
#define PyGLM_GET_TYPE(o) _SUB_PyGLM_GET_TYPE(((PyObject*)o))

#define PyGLM_VEC_SHAPE_CHECK(o, L) ((((shape_helper*)o)->shape & 0b1111) == L)
#define PyGLM_MAT_SHAPE_CHECK(o, C, R) ((((shape_helper*)o)->shape & 0b111) == C && (((shape_helper*)o)->shape >> 3 & 0b111) == R)

#define PyGLM_Vec_CheckExact(L, T, o) ((Py_TYPE(o) == UNBRACKET (PyGLM_VEC_TYPE<L, T>())) || (Py_TYPE(o) == UNBRACKET (PyGLM_MVEC_TYPE<L, T>())))

#define PyGLM_Mat_CheckExact(C, R, T, o) (Py_TYPE(o) == UNBRACKET (PyGLM_MAT_TYPE<C, R, T>()))

#define PyGLM_Qua_CheckExact(T, o) (Py_TYPE(o) == UNBRACKET (PyGLM_QUA_TYPE<T>()))

bool get_vec_PTI_compatible(PyObject* o, int accepted_types) {
	uint8& info = ((type_helper*)o)->info;

	uint8 L = info & ((1 << PyGLM_TYPE_INFO_VEC_SHAPE_LENGTH) - 1);

	int shape = (L == 1) ? PyGLM_SHAPE_1 : (L == 2) ? PyGLM_SHAPE_2 : (L == 3) ? PyGLM_SHAPE_3 : PyGLM_SHAPE_4;

	uint8 type = (info & (((1 << PyGLM_TYPE_INFO_VEC_TYPE_LENGTH) - 1) << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET)) >> PyGLM_TYPE_INFO_VEC_TYPE_OFFSET;

	int type_info = (type == PyGLM_TYPE_INFO_FLOAT) ? PyGLM_DT_FLOAT :
		(type == PyGLM_TYPE_INFO_DOUBLE) ? PyGLM_DT_DOUBLE :
		(type == PyGLM_TYPE_INFO_INT) ? PyGLM_DT_INT :
		(type == PyGLM_TYPE_INFO_UINT) ? PyGLM_DT_UINT :
		(type == PyGLM_TYPE_INFO_INT64) ? PyGLM_DT_INT64 :
		(type == PyGLM_TYPE_INFO_UINT64) ? PyGLM_DT_UINT64 :
		(type == PyGLM_TYPE_INFO_INT16) ? PyGLM_DT_INT16 :
		(type == PyGLM_TYPE_INFO_UINT16) ? PyGLM_DT_UINT16 :
		(type == PyGLM_TYPE_INFO_INT8) ? PyGLM_DT_INT8 :
		(type == PyGLM_TYPE_INFO_UINT8) ? PyGLM_DT_UINT8 :
		PyGLM_DT_BOOL;

	int PTI_info = shape | type_info | PyGLM_T_VEC;

	return (PTI_info & accepted_types) == PTI_info;
}

bool get_mat_PTI_compatible(PyObject* o, int accepted_types) {
	uint8& info = ((type_helper*)o)->info;

	uint8 C = info & ((1 << PyGLM_TYPE_INFO_MAT_SHAPE1_LENGTH) - 1);

	uint8 R = (info & (((1 << PyGLM_TYPE_INFO_MAT_SHAPE2_LENGTH) - 1) << PyGLM_TYPE_INFO_MAT_SHAPE2_OFFSET)) >> PyGLM_TYPE_INFO_MAT_SHAPE2_OFFSET;

	int shape = (C == 2) ? (R == 2) ? PyGLM_SHAPE_2x2 : (R == 3) ? PyGLM_SHAPE_2x3 : PyGLM_SHAPE_2x4 :
		(C == 3) ? (R == 2) ? PyGLM_SHAPE_3x2 : (R == 3) ? PyGLM_SHAPE_3x3 : PyGLM_SHAPE_3x4 :
		(R == 2) ? PyGLM_SHAPE_4x2 : (R == 3) ? PyGLM_SHAPE_4x3 : PyGLM_SHAPE_4x4;

	uint8 type = (info & (((1 << PyGLM_TYPE_INFO_MAT_TYPE_LENGTH) - 1) << PyGLM_TYPE_INFO_MAT_TYPE_OFFSET)) >> PyGLM_TYPE_INFO_MAT_TYPE_OFFSET;

	int type_info = (type == PyGLM_TYPE_INFO_FLOAT) ? PyGLM_DT_FLOAT :
		(type == PyGLM_TYPE_INFO_DOUBLE) ? PyGLM_DT_DOUBLE :
		(type == PyGLM_TYPE_INFO_INT) ? PyGLM_DT_INT :
		PyGLM_DT_UINT;

	int PTI_info = shape | type_info | PyGLM_T_MAT;

	return (PTI_info & accepted_types) == PTI_info;
}

bool get_qua_PTI_compatible(PyObject* o, int accepted_types) {
	uint8& info = ((type_helper*)o)->info;

	uint8 type = (info & (((1 << PyGLM_TYPE_INFO_VEC_TYPE_LENGTH) - 1) << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET)) >> PyGLM_TYPE_INFO_VEC_TYPE_OFFSET;

	int type_info = (type == PyGLM_TYPE_INFO_FLOAT) ? PyGLM_DT_FLOAT :
		PyGLM_DT_DOUBLE;

	int PTI_info = type_info | PyGLM_T_QUA;

	return (PTI_info & accepted_types) == PTI_info;
}

template<typename T>
constexpr int get_PTI_type() {
	return (
		(std::is_same<T, double>::value) ? PyGLM_DT_DOUBLE :
		(std::is_same<T, float>::value) ? PyGLM_DT_FLOAT :
		(std::is_same<T, int32>::value) ? PyGLM_DT_INT :
		(std::is_same<T, uint32>::value) ? PyGLM_DT_UINT :
		(std::is_same<T, int64>::value) ? PyGLM_DT_INT64 :
		(std::is_same<T, uint64>::value) ? PyGLM_DT_UINT64 :
		(std::is_same<T, int16>::value) ? PyGLM_DT_INT16 :
		(std::is_same<T, uint16>::value) ? PyGLM_DT_UINT16 :
		(std::is_same<T, int8>::value) ? PyGLM_DT_INT8 :
		(std::is_same<T, uint8>::value) ? PyGLM_DT_UINT8 :
		PyGLM_DT_BOOL
		);
}

template<int L, typename T>
constexpr int get_vec_PTI_info() {
	return PyGLM_T_VEC |
		(
			(L == 1) ? PyGLM_SHAPE_1 :
			(L == 2) ? PyGLM_SHAPE_2 :
			(L == 3) ? PyGLM_SHAPE_3 :
			PyGLM_SHAPE_4
			) |
		get_PTI_type<T>();
}

template<int C, int R, typename T>
constexpr int get_mat_PTI_info() {
	return PyGLM_T_MAT |
		(
			(C == 2) ?
			(
				(R == 2) ? PyGLM_SHAPE_2x2 :
				(R == 3) ? PyGLM_SHAPE_2x3 :
				PyGLM_SHAPE_2x4
				) :
			(C == 3) ?
			(
				(R == 2) ? PyGLM_SHAPE_3x2 :
				(R == 3) ? PyGLM_SHAPE_3x3 :
				PyGLM_SHAPE_3x4
				) :
			(
				(R == 2) ? PyGLM_SHAPE_4x2 :
				(R == 3) ? PyGLM_SHAPE_4x3 :
				PyGLM_SHAPE_4x4
				)
			) |
		get_PTI_type<T>();
}

template<typename T>
constexpr int get_qua_PTI_info() {
	return PyGLM_T_QUA |
		get_PTI_type<T>();
}

#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
template<typename T>
static bool get_view_format_equal(char* value) {
	char& v_char = value[0];
	if (v_char == 'f') {
		return std::is_same<T, float>::value;
	}
	if (v_char == 'd') {
		return std::is_same<T, double>::value;
	}
	if (v_char == 'b') {
		return std::is_same<T, std::int8_t>::value;
	}
	if (v_char == 'B') {
		return std::is_same<T, std::uint8_t>::value;
	}
	if (v_char == 'h') {
		return std::is_same<T, std::int16_t>::value;
	}
	if (v_char == 'H') {
		return std::is_same<T, std::uint16_t>::value;
	}
	if (v_char == 'i') {
		return std::is_same<T, std::int32_t>::value;
	}
	if (v_char == 'I') {
		return std::is_same<T, std::uint32_t>::value;
	}
	if (v_char == 'q') {
		return std::is_same<T, std::int64_t>::value;
	}
	if (v_char == 'Q') {
		return std::is_same<T, std::uint64_t>::value;
	}
	if (v_char == '?') {
		return std::is_same<T, bool>::value;
	}
	return false;
}

enum SourceType {NONE, PyGLM_VEC, PyGLM_MVEC, PyGLM_MAT, PyGLM_QUA, PTI};







PyGLMTypeInfo PTI0;
SourceType sourceType0;

PyGLMTypeInfo PTI1;
SourceType sourceType1;

PyGLMTypeInfo PTI2;
SourceType sourceType2;

PyGLMTypeInfo PTI3;
SourceType sourceType3;

#ifdef PyGLM_DEBUG
PyObject* ARG0 = NULL;
PyObject* ARG1 = NULL;
PyObject* ARG2 = NULL;
PyObject* ARG3 = NULL;

bool ARGUSED = true;
#endif



#ifdef PyGLM_DEBUG
#define PyGLM_PTI_InitN(N, o, accepted_types) \
	if (o->ob_type->tp_dealloc == (destructor)vec_dealloc){if (get_vec_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_VEC;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mat_dealloc) {if (get_mat_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_MAT;} else {sourceType ## N = NONE;}} \
	else if (o->ob_type->tp_dealloc == (destructor)qua_dealloc) {if (get_qua_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_QUA;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) {if (get_vec_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_MVEC;} else {sourceType ## N = NONE;}}\
	else { PTI ## N = PyGLMTypeInfo(accepted_types, o); if (PTI ## N.info == 0) sourceType ## N = NONE; else sourceType ## N = PTI;};\
	if (N == 0 && !ARGUSED) throw; ARG ## N = o; ARGUSED = false;

bool PyGLM_PTI_DEBUG_EQ_FUNC(PyObject* o, PyObject* arg) {
	if (o != arg) {
		throw;
	}
	return false;
}

#define PyGLM_PTI_DEBUG_EQ(N, o) ((ARGUSED = true) && PyGLM_PTI_DEBUG_EQ_FUNC(o, ARG##N)) ||
#define PyGLM_PTI_DEBUG_SC(N, o) PyGLM_PTI_DEBUG_EQ_FUNC(o, ARG##N)

#define PyGLM_PTI_IsVec(N) ((ARGUSED = true) && (sourceType ## N == PyGLM_VEC || sourceType ## N == PyGLM_MVEC || sourceType ## N == PTI && PTI ## N.isVec))

#define PyGLM_PTI_IsMat(N) ((ARGUSED = true) && (sourceType ## N == PyGLM_MAT || sourceType ## N == PTI && PTI ## N.isMat))

#define PyGLM_PTI_IsQua(N) ((ARGUSED = true) && (sourceType ## N == PyGLM_QUA || sourceType ## N == PTI && PTI ## N.isQua))

#define PyGLM_PTI_IsNone(N) ((ARGUSED = true) && sourceType ## N == NONE)
#else
#define PyGLM_PTI_InitN(N, o, accepted_types) \
	if (o->ob_type->tp_dealloc == (destructor)vec_dealloc){if (get_vec_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_VEC;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mat_dealloc) {if (get_mat_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_MAT;} else {sourceType ## N = NONE;}} \
	else if (o->ob_type->tp_dealloc == (destructor)qua_dealloc) {if (get_qua_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_QUA;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) {if (get_vec_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_MVEC;} else {sourceType ## N = NONE;}}\
	else { PTI ## N.init(accepted_types, o); if (PTI ## N.info == 0) sourceType ## N = NONE; else sourceType ## N = PTI;}

#define PyGLM_PTI_DEBUG_EQ(N, o)
#define PyGLM_PTI_DEBUG_SC(N, o)

#define PyGLM_PTI_IsVec(N) (sourceType ## N == PyGLM_VEC || sourceType ## N == PyGLM_MVEC || (sourceType ## N == PTI && PTI ## N.isVec))

#define PyGLM_PTI_IsMat(N) (sourceType ## N == PyGLM_MAT || (sourceType ## N == PTI && PTI ## N.isMat))

#define PyGLM_PTI_IsQua(N) (sourceType ## N == PyGLM_QUA || (sourceType ## N == PTI && PTI ## N.isQua))

#define PyGLM_PTI_IsNone(N) (sourceType ## N == NONE)
#endif

#define PyGLM_PTI_GetDT(T) (get_PTI_type<T>())


#ifdef PyGLM_DEBUG
inline bool assertAndReturn(bool expr) {
	assert(expr);
	return expr;
}
#define PyGLM_Vec_PTI_CheckN(N, L, T, o) (PyGLM_PTI_DEBUG_EQ(N, o) PyGLM_Vec_CheckExact(L, T, o) && assertAndReturn(sourceType ## N == PyGLM_VEC || sourceType ## N == PyGLM_MVEC) || sourceType ## N == PTI && PTI ## N.info == get_vec_PTI_info<L, T>())

#define PyGLM_Mat_PTI_CheckN(N, C, R, T, o) (PyGLM_PTI_DEBUG_EQ(N, o) PyGLM_Mat_CheckExact(C, R, T, o) && assertAndReturn(sourceType ## N == PyGLM_MAT) || sourceType ## N == PTI && PTI ## N.info == get_mat_PTI_info<C, R, T>())

#define PyGLM_Qua_PTI_CheckN(N, T, o) (PyGLM_PTI_DEBUG_EQ(N, o) PyGLM_Qua_CheckExact(T, o) && assertAndReturn(sourceType ## N == PyGLM_QUA) || sourceType ## N == PTI && PTI ## N.info == get_qua_PTI_info<T>())
#else
#define PyGLM_Vec_PTI_CheckN(N, L, T, o) (PyGLM_PTI_DEBUG_EQ(N, o) PyGLM_Vec_CheckExact(L, T, o) ||( sourceType ## N == PTI && PTI ## N.info == get_vec_PTI_info<L, T>()))

#define PyGLM_Mat_PTI_CheckN(N, C, R, T, o) (PyGLM_PTI_DEBUG_EQ(N, o) PyGLM_Mat_CheckExact(C, R, T, o) || (sourceType ## N == PTI && PTI ## N.info == get_mat_PTI_info<C, R, T>()))

#define PyGLM_Qua_PTI_CheckN(N, T, o) (PyGLM_PTI_DEBUG_EQ(N, o) PyGLM_Qua_CheckExact(T, o) || (sourceType ## N == PTI && PTI ## N.info == get_qua_PTI_info<T>()))
#endif

//#define PyGLM_Vec_PTI_CheckN(L, T, o, N) (PTI ## N = PyGLMTypeInfo(PyGLM_T_ANY_VEC | PyGLM_SHAPE_ ## L | PyGLM_DT_ ## T,o), sourceType ## N = PTI, PTI ## N.info == (PyGLM_T_VEC | PyGLM_SHAPE_ ## L | PyGLM_DT_ ## T))

//#define PyGLM_Vec_CheckN(L, T, o, N) ((PyObject_TypeCheck(o, UNBRACKET (PyGLM_VEC_TYPE<L, T>())) && (sourceType ## N = NORMAL)) || (Py_TYPE(o) == PyGLM_MVEC_TYPE<L, T>() && (sourceType ## N = MVEC)) || (PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN) && PyGLM_Vec_PTI_CheckN(L, T, o, N))

#define PyGLM_Vec_Check PyGLM_Vec_CheckExact

#define PyGLM_Vec_Check_IgnoreType PyGLM_Vec_CheckExact

#define PyGLM_Vec_PTI_GetN(N, L, T, o)  ((PyGLM_PTI_DEBUG_EQ(N, o) sourceType ## N == PyGLM_VEC) ? ((vec<L,T>*)o)->super_type : (sourceType ## N == PyGLM_MVEC) ? *((mvec<L,T>*)o)->super_type : PTI ## N.getVec<L, T>())


//#define PyGLM_Qua_PTI_CheckN(T, o, N) (PTI ## N = PyGLMTypeInfo(PyGLM_T_QUA | PyGLM_DT_ ## T,o), sourceType ## N = PTI, PTI ## N.info == (PyGLM_T_QUA | PyGLM_DT_ ## T))

#define PyGLM_Qua_CheckN(T, o, N) ((PyObject_TypeCheck(o, UNBRACKET (PyGLM_QUA_TYPE<T>())) && (sourceType ## N = NORMAL)) || (PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN) && PyGLM_Qua_PTI_CheckN(T, o, N))

#define PyGLM_Qua_Check PyGLM_Qua_CheckExact

#define PyGLM_Qua_PTI_GetN(N, T, o) ((PyGLM_PTI_DEBUG_EQ(N, o) sourceType ## N == PTI) ? PTI ## N.getQua<T>() : ((qua<T>*)o)->super_type)


//#define PyGLM_Mat_PTI_CheckN(C, R, DT, o, N) (PTI ## N = PyGLMTypeInfo(PyGLM_T_MAT | PyGLM_SHAPE_ ## C ## x ## R | DT,o), sourceType ## N = PTI, PTI ## N.info == (PyGLM_T_MAT | PyGLM_SHAPE_ ## C ## x ## R | DT))

#define PyGLM_Mat_CheckN(C, R, T, o, N) ((PyObject_TypeCheck(o, UNBRACKET (PyGLM_MAT_TYPE<C, R, T>())) && (sourceType ## N = NORMAL)) || (PyGLM_GET_TYPE(o) == PyGLM_TYPE_UNKNOWN) && PyGLM_Mat_PTI_CheckN(C, R, PTI##N.getDT<T>(), o, N))

#define PyGLM_Mat_Check PyGLM_Mat_CheckExact

#define PyGLM_Mat_PTI_GetN(N, C, R, T, o) ((PyGLM_PTI_DEBUG_EQ(N, o) sourceType ## N == PTI) ? PTI ## N.getMat<C, R, T>() : ((mat<C, R, T>*)o)->super_type) 


#else
enum SourceType { NONE, PyGLM_VEC, PyGLM_MVEC, PyGLM_MAT, PyGLM_QUA };
SourceType sourceType0;

SourceType sourceType1;

SourceType sourceType2;

SourceType sourceType3;

#define PyGLM_PTI_InitN(N, o, accepted_types) \
	if (o->ob_type->tp_dealloc == (destructor)vec_dealloc){if (get_vec_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_VEC;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mat_dealloc) {if (get_mat_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_MAT;} else {sourceType ## N = NONE;}} \
	else if (o->ob_type->tp_dealloc == (destructor)qua_dealloc) {if (get_qua_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_QUA;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) {if (get_vec_PTI_compatible(o, accepted_types)) {sourceType ## N = PyGLM_MVEC;} else {sourceType ## N = NONE;}}\
	else sourceType ## N = NONE;


#define PyGLM_Vec_PTI_CheckN(N, L, T, o) PyGLM_Vec_CheckExact(L, T, o)

#define PyGLM_Mat_PTI_CheckN(N, C, R, T, o) PyGLM_Mat_CheckExact(C, R, T, o)

#define PyGLM_Qua_PTI_CheckN(N, T, o) PyGLM_Qua_CheckExact(T, o)


#define PyGLM_Vec_PTI_GetN(N, L, T, o)  ((sourceType ## N == PyGLM_VEC) ? ((vec<L,T>*)o)->super_type : *((mvec<L,T>*)o)->super_type)

#define PyGLM_Mat_PTI_GetN(N, C, R, T, o) (((mat<C, R, T>*)o)->super_type) 

#define PyGLM_Qua_PTI_GetN(N, T, o) (((qua<T>*)o)->super_type)


#define PyGLM_Vec_Check(L, T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_VEC_TYPE<L, T>())) || Py_TYPE(o) == PyGLM_MVEC_TYPE<L, T>())

#define PyGLM_Vec_Check_IgnoreType PyGLM_Vec_Check

#define PyGLM_Qua_Check(T, o) (PyObject_TypeCheck(o, UNBRACKET (PyGLM_QUA_TYPE<T>())))

#define PyGLM_Mat_Check(C, R, T, o) PyObject_TypeCheck(o, UNBRACKET (PyGLM_MAT_TYPE<C, R, T>()))


#define PyGLM_PTI_IsVec(N) (sourceType ## N == PyGLM_VEC || sourceType ## N == PyGLM_MVEC)

#define PyGLM_PTI_IsMat(N) (sourceType ## N == PyGLM_MAT)

#define PyGLM_PTI_IsQua(N) (sourceType ## N == PyGLM_QUA)

#define PyGLM_PTI_IsNone(N) (sourceType ## N == NONE)

#define PyGLM_PTI_GetDT(T) (get_PTI_type<T>())
#endif

#define PyGLM_PTI_Init0(o, accepted_types) PyGLM_PTI_InitN(0, o, accepted_types)
#define PyGLM_PTI_Init1(o, accepted_types) PyGLM_PTI_InitN(1, o, accepted_types)
#define PyGLM_PTI_Init2(o, accepted_types) PyGLM_PTI_InitN(2, o, accepted_types)
#define PyGLM_PTI_Init3(o, accepted_types) PyGLM_PTI_InitN(3, o, accepted_types)


#define PyGLM_Vec_PTI_Check0(L, T, o) PyGLM_Vec_PTI_CheckN(0, L, T, o)
#define PyGLM_Vec_PTI_Check1(L, T, o) PyGLM_Vec_PTI_CheckN(1, L, T, o)
#define PyGLM_Vec_PTI_Check2(L, T, o) PyGLM_Vec_PTI_CheckN(2, L, T, o)
#define PyGLM_Vec_PTI_Check3(L, T, o) PyGLM_Vec_PTI_CheckN(3, L, T, o)


#define PyGLM_Mat_PTI_Check0(C, R, T, o) PyGLM_Mat_PTI_CheckN(0, C, R, T, o)
#define PyGLM_Mat_PTI_Check1(C, R, T, o) PyGLM_Mat_PTI_CheckN(1, C, R, T, o)
#define PyGLM_Mat_PTI_Check2(C, R, T, o) PyGLM_Mat_PTI_CheckN(2, C, R, T, o)
#define PyGLM_Mat_PTI_Check3(C, R, T, o) PyGLM_Mat_PTI_CheckN(3, C, R, T, o)


#define PyGLM_Qua_PTI_Check0(T, o) PyGLM_Qua_PTI_CheckN(0, T, o)
#define PyGLM_Qua_PTI_Check1(T, o) PyGLM_Qua_PTI_CheckN(1, T, o)
#define PyGLM_Qua_PTI_Check2(T, o) PyGLM_Qua_PTI_CheckN(2, T, o)
#define PyGLM_Qua_PTI_Check3(T, o) PyGLM_Qua_PTI_CheckN(3, T, o)


#define PyGLM_Vec_PTI_Get0(L, T, o) PyGLM_Vec_PTI_GetN(0, L, T, o)
#define PyGLM_Vec_PTI_Get1(L, T, o) PyGLM_Vec_PTI_GetN(1, L, T, o)
#define PyGLM_Vec_PTI_Get2(L, T, o) PyGLM_Vec_PTI_GetN(2, L, T, o)
#define PyGLM_Vec_PTI_Get3(L, T, o) PyGLM_Vec_PTI_GetN(3, L, T, o)

#define PyGLM_Vec_PTI_Assign(L, T) glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, arg);
#define PyGLM_Vec_PTI_Assign0(L, T) glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, arg1);
#define PyGLM_Vec_PTI_Assign1(L, T) glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, arg2);
#define PyGLM_Vec_PTI_Assign2(L, T) glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get2(L, T, arg3);
#define PyGLM_Vec_PTI_Assign3(L, T) glm::vec<L, T> o4 = PyGLM_Vec_PTI_Get3(L, T, arg4);


#define PyGLM_Mat_PTI_Get0(C, R, T, o) PyGLM_Mat_PTI_GetN(0, C, R, T, o)
#define PyGLM_Mat_PTI_Get1(C, R, T, o) PyGLM_Mat_PTI_GetN(1, C, R, T, o)
#define PyGLM_Mat_PTI_Get2(C, R, T, o) PyGLM_Mat_PTI_GetN(2, C, R, T, o)
#define PyGLM_Mat_PTI_Get3(C, R, T, o) PyGLM_Mat_PTI_GetN(3, C, R, T, o)

#define PyGLM_Mat_PTI_Assign(C, R, T) glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, arg);
#define PyGLM_Mat_PTI_Assign0(C, R, T) glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, arg1);
#define PyGLM_Mat_PTI_Assign1(C, R, T) glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, arg2);
#define PyGLM_Mat_PTI_Assign2(C, R, T) glm::mat<C, R, T> o3 = PyGLM_Mat_PTI_Get2(C, R, T, arg3);
#define PyGLM_Mat_PTI_Assign3(C, R, T) glm::mat<C, R, T> o4 = PyGLM_Mat_PTI_Get3(C, R, T, arg4);


#define PyGLM_Qua_PTI_Get0(T, o) PyGLM_Qua_PTI_GetN(0, T, o)
#define PyGLM_Qua_PTI_Get1(T, o) PyGLM_Qua_PTI_GetN(1, T, o)
#define PyGLM_Qua_PTI_Get2(T, o) PyGLM_Qua_PTI_GetN(2, T, o)
#define PyGLM_Qua_PTI_Get3(T, o) PyGLM_Qua_PTI_GetN(3, T, o)

#define PyGLM_Qua_PTI_Assign(T) glm::qua<T> o = PyGLM_Qua_PTI_Get0(T, arg);
#define PyGLM_Qua_PTI_Assign0(T) glm::qua<T> o = PyGLM_Qua_PTI_Get0(T, arg1);
#define PyGLM_Qua_PTI_Assign1(T) glm::qua<T> o2 = PyGLM_Qua_PTI_Get1(T, arg2);
#define PyGLM_Qua_PTI_Assign2(T) glm::qua<T> o3 = PyGLM_Qua_PTI_Get2(T, arg3);
#define PyGLM_Qua_PTI_Assign3(T) glm::qua<T> o4 = PyGLM_Qua_PTI_Get3(T, arg4);

#include "unpackers.h"