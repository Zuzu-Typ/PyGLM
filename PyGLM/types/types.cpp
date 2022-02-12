#include "types.h"
#include "vec/forward_declarations.h"

PyGLMTypeObject PyGLMTypeStorage[
	PyGLM_TYPE_STORAGE_VEC_LENGTH
  + PyGLM_TYPE_STORAGE_MVEC_LENGTH
  + PyGLM_TYPE_STORAGE_MAT_LENGTH
  + PyGLM_TYPE_STORAGE_QUA_LENGTH
];

const int glmArray::getShape() {
	return static_cast<int>(shape[0]);
}

const int glmArray::getShape(uint8 index) {
	return static_cast<int>(shape[index]);
}

void glmArray::setShape(int L) {
	shape[0] = static_cast<uint8>(L);
}

void glmArray::setShape(int C, int R) {
	shape[0] = static_cast<uint8>(C);
	shape[1] = static_cast<uint8>(R);
}


PyGLMTypeObject::PyGLMTypeObject(PyTypeObject typeObject, uint8 glmType, uint8 C, uint8 R, Py_ssize_t dtSize, Py_ssize_t itemSize, char format) :
	PyGLMTypeObject(typeObject, glmType, C, R, dtSize, itemSize, format, (PyTypeObject*)this) {}

PyGLMTypeObject::PyGLMTypeObject(PyTypeObject typeObject, uint8 glmType, uint8 C, uint8 R, Py_ssize_t dtSize, Py_ssize_t itemSize, char format, PyTypeObject* subtype)
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

char* PyGLMTypeObject::getDataOf(PyObject* src) {
	char* out = reinterpret_cast<char*>(src);

	if (glmType == PyGLM_TYPE_MVEC) {
		return *reinterpret_cast<char**>((out + sizeof(PyObject)));
	}

	return (out + sizeof(PyObject));
}
