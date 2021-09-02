#pragma once

#include "../imports.h"

// type identifiers
#define PyGLM_TYPE_UNKNOWN 0
#define PyGLM_TYPE_VEC 1
#define PyGLM_TYPE_MAT 2
#define PyGLM_TYPE_QUA 4
#define PyGLM_TYPE_CTYPES 8
#define PyGLM_TYPE_MVEC_FILTER 15
#define PyGLM_TYPE_MVEC (16 | PyGLM_TYPE_VEC)

// format specifiers
#define PyGLM_FS_FLOAT	'f'
#define PyGLM_FS_DOUBLE 'd'
#define PyGLM_FS_INT8	'b'
#define PyGLM_FS_UINT8	'B'
#define PyGLM_FS_INT16	'h'
#define PyGLM_FS_UINT16 'H'
#define PyGLM_FS_INT32	'i'
#define PyGLM_FS_UINT32 'I'
#define PyGLM_FS_INT64	'q'
#define PyGLM_FS_UINT64 'Q'
#define PyGLM_FS_BOOL	'?'

/*
shape looks like this:
For Vec:
  bits 0-3 = shape
  bits 4-7 = type
  examples:
    0 1 2 3 4 5 6 7
	0 0 1 0 1 1 0 1
	= bvec4

	0 1 2 3 4 5 6 7
	1 0 0 0 0 0 0 0
	= fvec1

For Mat:
  bits 0-2 = shape1 (n)
  bits 3-5 = shape2 (m)
  bits 6-7 = type
  examples:
    0 1 2 3 4 5 6 7
	0 1 0 1 1 0 1 0
	= dmat2x3

For Qua:
  bits 0-3 = 4 (shape == 4)
  bits 4-7 = type (0 or 1 i.e. float or double respectively)
  examples:
	0 1 2 3 4 5 6 7
	0 0 1 0 0 0 0 0
	= quat
*/

//#define PyGLM_TYPE_INFO_VEC_SHAPE_OFFSET	0
//#define PyGLM_TYPE_INFO_VEC_SHAPE_LENGTH	4
//
//#define PyGLM_TYPE_INFO_VEC_TYPE_OFFSET		4
//#define PyGLM_TYPE_INFO_VEC_TYPE_LENGTH		4
//
//
//#define PyGLM_TYPE_INFO_MAT_SHAPE1_OFFSET	0
//#define PyGLM_TYPE_INFO_MAT_SHAPE1_LENGTH	3
//
//#define PyGLM_TYPE_INFO_MAT_SHAPE2_OFFSET	3
//#define PyGLM_TYPE_INFO_MAT_SHAPE2_LENGTH	3
//
//#define PyGLM_TYPE_INFO_MAT_TYPE_OFFSET		6
//#define PyGLM_TYPE_INFO_MAT_TYPE_LENGTH		2


#define PyGLM_TYPE_INFO_FLOAT	0
#define PyGLM_TYPE_INFO_DOUBLE	1
#define PyGLM_TYPE_INFO_INT		2
#define PyGLM_TYPE_INFO_UINT	3
#define PyGLM_TYPE_INFO_INT8	4
#define PyGLM_TYPE_INFO_UINT8	5
#define PyGLM_TYPE_INFO_INT16	6
#define PyGLM_TYPE_INFO_UINT16	7
#define PyGLM_TYPE_INFO_INT64	8
#define PyGLM_TYPE_INFO_UINT64	9
#define PyGLM_TYPE_INFO_BOOL	10

#define PyGLM_TYPE_INFO_UNKNOWN 15

#define PyGLM_UNKNOWN		0x0000000
#define PyGLM_DT_UNKNOWN	PyGLM_UNKNOWN
#define PyGLM_DT_FLOAT		0x0000001
#define PyGLM_DT_DOUBLE		0x0000002
#define PyGLM_DT_INT		0x0000004
#define PyGLM_DT_UINT		0x0000008
#define PyGLM_DT_INT8		0x0000010
#define PyGLM_DT_UINT8		0x0000020
#define PyGLM_DT_INT16		0x0000040
#define PyGLM_DT_UINT16		0x0000080
#define PyGLM_DT_INT64		0x0000100
#define PyGLM_DT_UINT64		0x0000200
#define PyGLM_DT_BOOL		0x0000400

#define PyGLM_DT_float		PyGLM_DT_FLOAT
#define PyGLM_DT_double		PyGLM_DT_DOUBLE
#define PyGLM_DT_int32		PyGLM_DT_INT
#define PyGLM_DT_uint32		PyGLM_DT_UINT
#define PyGLM_DT_int64		PyGLM_DT_INT64
#define PyGLM_DT_uint64		PyGLM_DT_UINT64
#define PyGLM_DT_int16		PyGLM_DT_INT16
#define PyGLM_DT_uint16		PyGLM_DT_UINT16
#define PyGLM_DT_int8		PyGLM_DT_INT8
#define PyGLM_DT_uint8		PyGLM_DT_UINT8
#define PyGLM_DT_bool		PyGLM_DT_BOOL

#define PyGLM_DT_FD			(PyGLM_DT_FLOAT | PyGLM_DT_DOUBLE)
#define PyGLM_DT_I32		(PyGLM_DT_INT | PyGLM_DT_UINT)
#define PyGLM_DT_I64		(PyGLM_DT_INT64 | PyGLM_DT_UINT64)
#define PyGLM_DT_I16		(PyGLM_DT_INT16 | PyGLM_DT_UINT16)
#define PyGLM_DT_I8		(PyGLM_DT_INT8 | PyGLM_DT_UINT8)
#define PyGLM_DT_I		   (PyGLM_DT_I32 | PyGLM_DT_I64 | PyGLM_DT_I16 | PyGLM_DT_I8)
#define PyGLM_DT_NORMAL		(PyGLM_DT_FD | PyGLM_DT_I32)

#define PyGLM_SHAPE_2x2		0x0000800
#define PyGLM_SHAPE_2x3		0x0001000
#define PyGLM_SHAPE_2x4		0x0002000
#define PyGLM_SHAPE_3x2		0x0004000
#define PyGLM_SHAPE_3x3		0x0008000
#define PyGLM_SHAPE_3x4		0x0010000
#define PyGLM_SHAPE_4x2		0x0020000
#define PyGLM_SHAPE_4x3		0x0040000
#define PyGLM_SHAPE_4x4		0x0080000

#define PyGLM_SHAPE_1		0x0100000
#define PyGLM_SHAPE_2		0x0200000
#define PyGLM_SHAPE_3		0x0400000
#define PyGLM_SHAPE_4		0x0800000

#define PyGLM_T_VEC_ONLY	0x1000000
#define PyGLM_T_MVEC		0x2000000
#define PyGLM_T_VEC			(PyGLM_T_VEC_ONLY | PyGLM_T_MVEC)
#define PyGLM_T_MAT			0x4000000
#define PyGLM_T_QUA			0x8000000

#define PyGLM_T_NUMBER		0x10000000

#define PyGLM_T_ANY_VEC	   (PyGLM_T_VEC | PyGLM_T_MVEC)
#define PyGLM_T_ANY_ARR	   (PyGLM_T_ANY_VEC | PyGLM_T_QUA)

#define PyGLM_SHAPE_SQUARE (PyGLM_SHAPE_2x2 | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x4)

#define PyGLM_SHAPE_2xM	   (PyGLM_SHAPE_2x2 | PyGLM_SHAPE_2x3 | PyGLM_SHAPE_2x4)
#define PyGLM_SHAPE_3xM	   (PyGLM_SHAPE_3x2 | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_3x4)
#define PyGLM_SHAPE_4xM	   (PyGLM_SHAPE_4x2 | PyGLM_SHAPE_4x3 | PyGLM_SHAPE_4x4)

#define PyGLM_SHAPE_Nx2	   (PyGLM_SHAPE_2x2 | PyGLM_SHAPE_3x2 | PyGLM_SHAPE_4x2)
#define PyGLM_SHAPE_Nx3	   (PyGLM_SHAPE_2x3 | PyGLM_SHAPE_3x3 | PyGLM_SHAPE_4x3)
#define PyGLM_SHAPE_Nx4	   (PyGLM_SHAPE_2x4 | PyGLM_SHAPE_3x4 | PyGLM_SHAPE_4x4)

#define PyGLM_SHAPE_NxM	   (PyGLM_SHAPE_2xM | PyGLM_SHAPE_3xM | PyGLM_SHAPE_4xM)

#define PyGLM_DT_MAT_ALL   (PyGLM_DT_FLOAT | PyGLM_DT_DOUBLE | PyGLM_DT_INT | PyGLM_DT_UINT)

#define PyGLM_DT_ALL		((1 << 11) - 1)
#define PyGLM_SHAPE_ALL		(((1 << 13) - 1) << 11)
#define PyGLM_T_ALL			(((1 << 5) - 1) << 24)

#define PyGLM_ALL (PyGLM_DT_ALL | PyGLM_SHAPE_ALL | PyGLM_T_ALL)

typedef int8_t		int8;
typedef uint8_t		uint8;
typedef int16_t		int16;
typedef uint16_t	uint16;
typedef int32_t		int32;
typedef uint32_t	uint32;
typedef int64_t		int64;
typedef uint64_t	uint64;

template<typename T>
constexpr uint8_t get_type_helper_type() {
	return (std::is_same<float, T>::value) ? PyGLM_TYPE_INFO_FLOAT :
		(std::is_same<double, T>::value) ? PyGLM_TYPE_INFO_DOUBLE :
		(std::is_same<int32, T>::value) ? PyGLM_TYPE_INFO_INT :
		(std::is_same<uint32, T>::value) ? PyGLM_TYPE_INFO_UINT :
		(std::is_same<int8, T>::value) ? PyGLM_TYPE_INFO_INT8 :
		(std::is_same<uint8, T>::value) ? PyGLM_TYPE_INFO_UINT8 :
		(std::is_same<int16, T>::value) ? PyGLM_TYPE_INFO_INT16 :
		(std::is_same<uint16, T>::value) ? PyGLM_TYPE_INFO_UINT16 :
		(std::is_same<int64, T>::value) ? PyGLM_TYPE_INFO_INT64 :
		(std::is_same<uint64, T>::value) ? PyGLM_TYPE_INFO_UINT64 :
		(std::is_same<bool, T>::value) ? PyGLM_TYPE_INFO_BOOL :
		PyGLM_TYPE_INFO_UNKNOWN;
}

template<typename T>
constexpr char get_format_specifier() {
	return (std::is_same<float, T>::value) ? 'f' :
		(std::is_same<double, T>::value) ? 'd' :
		(std::is_same<int32, T>::value) ? 'i' :
		(std::is_same<uint32, T>::value) ? 'I' :
		(std::is_same<int8, T>::value) ? 'b' :
		(std::is_same<uint8, T>::value) ? 'B' :
		(std::is_same<int16, T>::value) ? 'h' :
		(std::is_same<uint16, T>::value) ? 'H' :
		(std::is_same<int64, T>::value) ? 'q' :
		(std::is_same<uint64, T>::value) ? 'Q' :
		(std::is_same<bool, T>::value) ? '?' :
		'B';
}

//struct shape_helper {
//	PyObject_HEAD
//		uint8_t shape;
//};

// type definitions
//struct type_helper {
//	PyObject_HEAD
//		uint8_t info;
//};

struct ctypes_helper {
	PyObject_HEAD
		void* b_ptr;                /* pointer to memory block */
};

template<int L, typename T>
struct vec {
	PyObject_HEAD
		//uint8_t info;
	glm::vec<L, T> super_type;
};

template<int L, typename T>
struct vecIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	vec<L, T>* sequence;
};

struct mvec_helper {
	PyObject_HEAD
		//uint8_t info;
	void* super_type;
	PyObject* master;
};

template<int L, typename T>
struct mvec {
	PyObject_HEAD
		//uint8_t info;
	glm::vec<L, T>* super_type;
	PyObject* master;
};

template<int L, typename T>
struct mvecIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	mvec<L, T>* sequence;
};

template<int C, int R, typename T>
struct mat {
	PyObject_HEAD
		//uint8_t info;
	glm::mat<C, R, T> super_type;
};

template<int C, int R, typename T>
struct matIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	mat<C, R, T>* sequence;
};

template<typename T>
struct qua {
	PyObject_HEAD
		//uint8_t info;
	glm::qua<T> super_type;
};

template<typename T>
struct quaIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	qua<T>* sequence;
};

struct glmArray {
	PyObject_HEAD
		char format;
	uint8 shape[2];
	uint8 glmType;
	Py_ssize_t nBytes;
	Py_ssize_t itemCount;
	Py_ssize_t dtSize;
	Py_ssize_t itemSize;
	PyTypeObject* subtype;
	PyObject* reference;
	bool readonly;
	void* data;

	const int getShape() {
		return static_cast<int>(shape[0]);
	}

	const int getShape(uint8 index) {
		return static_cast<int>(shape[index]);
	}

	void setShape(int L) {
		shape[0] = static_cast<uint8>(L);
	}

	void setShape(int C, int R) {
		shape[0] = static_cast<uint8>(C);
		shape[1] = static_cast<uint8>(R);
	}
};

#define PyGLM_ARRAY_OFFSET sizeof(PyObject)
#define PyGLM_ARRAY_SIZE (sizeof(glmArray) - PyGLM_ARRAY_OFFSET)

struct glmArrayIter {
	PyObject_VAR_HEAD
		Py_ssize_t seq_index;
	glmArray* sequence;
};


struct PyGLMTypeObject {
	PyTypeObject typeObject;
	uint8 glmType;
	uint8 C;
	uint8 R;
	Py_ssize_t dtSize;
	Py_ssize_t itemSize;
	char format;
	char reserved = '\x00';

	int PTI_info;

	PyTypeObject* subtype;
	PyGLMTypeObject(PyTypeObject typeObject, uint8 glmType, uint8 C, uint8 R, Py_ssize_t dtSize, Py_ssize_t itemSize, char format) :
		PyGLMTypeObject(typeObject, glmType, C, R, dtSize, itemSize, format, (PyTypeObject*)this) {}

	PyGLMTypeObject(PyTypeObject typeObject, uint8 glmType, uint8 C, uint8 R, Py_ssize_t dtSize, Py_ssize_t itemSize, char format, PyTypeObject* subtype)
		: typeObject(typeObject), glmType(glmType), C(C), R(R), dtSize(dtSize), itemSize(itemSize), format(format), subtype(subtype) {

		if (glmType == PyGLM_TYPE_VEC) {
			int shape = (C == 1) ? PyGLM_SHAPE_1 : (C == 2) ? PyGLM_SHAPE_2 : (C == 3) ? PyGLM_SHAPE_3 : PyGLM_SHAPE_4;

			int type_info = (format == PyGLM_FS_FLOAT) ? PyGLM_DT_FLOAT :
				(format == PyGLM_FS_DOUBLE) ? PyGLM_DT_DOUBLE :
				(format == PyGLM_FS_INT32) ? PyGLM_DT_INT :
				(format == PyGLM_FS_UINT32) ? PyGLM_DT_UINT :
				(format == PyGLM_FS_INT64) ? PyGLM_DT_INT64 :
				(format == PyGLM_FS_UINT64) ? PyGLM_DT_UINT64 :
				(format == PyGLM_FS_INT16) ? PyGLM_DT_INT16 :
				(format == PyGLM_FS_UINT16) ? PyGLM_DT_UINT16 :
				(format == PyGLM_FS_INT8) ? PyGLM_DT_INT8 :
				(format == PyGLM_FS_UINT8) ? PyGLM_DT_UINT8 :
				PyGLM_DT_BOOL;

			PTI_info = shape | type_info | PyGLM_T_VEC;
		}
		else if (glmType == PyGLM_TYPE_MAT) {
			int shape = (C == 2) ? (R == 2) ? PyGLM_SHAPE_2x2 : (R == 3) ? PyGLM_SHAPE_2x3 : PyGLM_SHAPE_2x4 :
				(C == 3) ? (R == 2) ? PyGLM_SHAPE_3x2 : (R == 3) ? PyGLM_SHAPE_3x3 : PyGLM_SHAPE_3x4 :
				(R == 2) ? PyGLM_SHAPE_4x2 : (R == 3) ? PyGLM_SHAPE_4x3 : PyGLM_SHAPE_4x4;

			int type_info = (format == PyGLM_FS_FLOAT) ? PyGLM_DT_FLOAT :
				(format == PyGLM_FS_DOUBLE) ? PyGLM_DT_DOUBLE :
				(format == PyGLM_FS_INT32) ? PyGLM_DT_INT :
				PyGLM_DT_UINT;

			PTI_info = shape | type_info | PyGLM_T_MAT;
		}
		else if (glmType == PyGLM_TYPE_QUA) {
			int type_info = (format == PyGLM_FS_FLOAT) ? PyGLM_DT_FLOAT :
				PyGLM_DT_DOUBLE;

			PTI_info = type_info | PyGLM_T_QUA;
		}
		else {
			int shape = (C == 1) ? PyGLM_SHAPE_1 : (C == 2) ? PyGLM_SHAPE_2 : (C == 3) ? PyGLM_SHAPE_3 : PyGLM_SHAPE_4;

			int type_info = (format == PyGLM_FS_FLOAT) ? PyGLM_DT_FLOAT :
				(format == PyGLM_FS_DOUBLE) ? PyGLM_DT_DOUBLE :
				(format == PyGLM_FS_INT32) ? PyGLM_DT_INT :
				PyGLM_DT_UINT;

			PTI_info = shape | type_info | PyGLM_T_MVEC;
		}
	}

	inline char* getDataOf(PyObject* src) {
		char* out = reinterpret_cast<char*>(src);

		if (glmType == PyGLM_TYPE_MVEC) {
			return *reinterpret_cast<char**>((out + sizeof(PyObject)));
		}

		return (out + sizeof(PyObject));
	}

	//inline PyTypeObject* typeObjectPointer() {
	//	return &typeObject;
	//}

	//static inline PyGLMTypeObject* fromTypeObjectPointer(PyTypeObject* typeObject) {
	//	constexpr uint64 typeObjectOffset = sizeof(PyGLMTypeObject) - sizeof(PyTypeObject);
	//	return reinterpret_cast<PyGLMTypeObject*>(reinterpret_cast<char*>(typeObject) - typeObjectOffset);
	//}
};