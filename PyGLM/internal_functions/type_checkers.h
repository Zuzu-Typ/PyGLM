#pragma once

//#include <climits>
//#include <functional>
#include <initializer_list>

#include "../compiler_setup.h"

#include "../types/types.h"

//#include "helper_macros.h"
//#include "number_functions.h"

//#include <glm/detail/type_quat.hpp>

struct PyGLMSingleTypeHolder { // supposed to only hold a single data type
	enum class DType { NONE, BOOL, INT32, INT64, UINT64, FLOAT, DOUBLE };

	DType dtype;

	void* data = NULL;

	bool needsToBeFreed = false;


	~PyGLMSingleTypeHolder();

	PyGLMSingleTypeHolder();

	PyGLMSingleTypeHolder(PyObject* o);

	static int getMostImportantType(int accepted_types, std::initializer_list<DType> list);

	double asDouble();

	float asFloat();

	glm::i64 asInt64();

	glm::u64 asUint64();

	glm::i32 asInt32();

	glm::u32 asUint32();

	glm::i16 asInt16();

	glm::u16 asUint16();

	glm::i8 asInt8();

	glm::u8 asUint8();

	bool asBool();

private:
	void allocate(size_t size);
};

struct PyGLMTypeInfo {
	int info = 0;
	uint8 dataArray[128]; // maximum of 4 * 4 * 8 = 128 bytes of data

	void* data = &dataArray;

	bool isVec = false;
	bool isMat = false;
	bool isQua = false;

	PyGLMTypeInfo();

	PyGLMTypeInfo(int accepted_types, PyObject* obj);

	void init(int accepted_types, PyObject* obj);

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
	inline void allocate(size_t size) {
		assert(size <= 128);
		data = &dataArray;
	}

	void setInfo(int info);
};

#define PyGLM_SHAPE_GET(C, R) (1 << (11 + (3 * (C-2) + (R-2))))

#define PyGLM_TYPE_GET(T) (PyGLMTypeInfo::getDT<T>())

#define PyGLM_PTI_Compare(a, b) (((a) & (b)) == (b))

#define PyGLM_PTI_Number_Check(pti) (pti.info & PyGLM_T_NUMBER)

#define PyGLM_PTI_Number_T_Check(T, pti) (pti.info & (PyGLM_T_NUMBER | PyGLM_TYPE_GET(T)))

#define PyGLM_PTI_Mat_CRT_Check(C, R, T, pti) (pti.info & (PyGLM_SHAPE_GET(C, R) | PyGLM_TYPE_GET(T) | PyGLM_T_MAT))

#define _SUB_PyGLM_PTI_GET_TYPE(o) ((o->ob_type->tp_dealloc == (destructor)vec_dealloc) ? PyGLM_T_VEC : (o->ob_type->tp_dealloc == (destructor)mat_dealloc) ? PyGLM_T_MAT : (o->ob_type->tp_dealloc == (destructor)qua_dealloc) ? PyGLM_T_QUA : (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) ? PyGLM_T_MVEC : PyGLM_UNKNOWN)
#define PyGLM_PTI_GET_TYPE(o) _SUB_PyGLM_PTI_GET_TYPE(((PyObject*)o))

#define _SUB_PyGLM_GET_TYPE(o) ((o->ob_type->tp_dealloc == NULL) ? PyGLM_TYPE_UNKNOWN : (o->ob_type->tp_dealloc == (destructor)vec_dealloc) ? PyGLM_TYPE_VEC : (o->ob_type->tp_dealloc == (destructor)mat_dealloc) ? PyGLM_TYPE_MAT : (o->ob_type->tp_dealloc == (destructor)qua_dealloc) ? PyGLM_TYPE_QUA : (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) ? PyGLM_TYPE_VEC : PyGLM_TYPE_UNKNOWN)
#define PyGLM_GET_TYPE(o) _SUB_PyGLM_GET_TYPE(((PyObject*)o))

#define	PyGLM_Is_PyGLM_Type(o) (((PyTypeObject*)(o))->tp_dealloc == (destructor)vec_dealloc || ((PyTypeObject*)(o))->tp_dealloc == (destructor)mvec_dealloc || ((PyTypeObject*)(o))->tp_dealloc == (destructor)mat_dealloc || ((PyTypeObject*)(o))->tp_dealloc == (destructor)qua_dealloc)

#define PyGLM_Ctypes_CheckType(o) (((PyTypeObject*)(o))->tp_dealloc == ctypes_dealloc)

#define PyGLM_Ctypes_Check(o) PyGLM_Ctypes_CheckType(Py_TYPE(o))

#define PyGLM_Array_Check(o) (((PyTypeObject*)(o)) == &glmArrayType)

//#define PyGLM_VEC_SHAPE_CHECK(o, L) ((((shape_helper*)o)->shape & 0b1111) == L)
//#define PyGLM_MAT_SHAPE_CHECK(o, C, R) ((((shape_helper*)o)->shape & 0b111) == C && (((shape_helper*)o)->shape >> 3 & 0b111) == R)

#define PyGLM_Vec_CheckExact(L, T, o) ((Py_TYPE(o) == UNBRACKET (PyGLM_VEC_TYPE<L, T>())) || (Py_TYPE(o) == UNBRACKET (PyGLM_MVEC_TYPE<L, T>())))

#define PyGLM_Mat_CheckExact(C, R, T, o) (Py_TYPE(o) == UNBRACKET (PyGLM_MAT_TYPE<C, R, T>()))

#define PyGLM_Qua_CheckExact(T, o) (Py_TYPE(o) == UNBRACKET (PyGLM_QUA_TYPE<T>()))

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

bool GET_PTI_COMPATIBLE_SIMPLE(PyObject* o, int accepted_types);

#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
template<typename T>
inline bool get_view_format_equal(char* value) {
	if (std::is_same<T, float>::value)
		return value[0] == 'f';
	else if (std::is_same<T, double>::value)
		return value[0] == 'd';
	else if (std::is_same<T, int8>::value)
		return value[0] == 'b';
	else if (std::is_same<T, uint8>::value)
		return value[0] == 'B';
	else if (std::is_same<T, int16>::value)
		return value[0] == 'h';
	else if (std::is_same<T, uint16>::value)
		return value[0] == 'H';
	else if (std::is_same<T, int32>::value)
		return value[0] == 'i';
	else if (std::is_same<T, uint32>::value)
		return value[0] == 'I';
	else if (std::is_same<T, int64>::value)
		return value[0] == 'q';
	else if (std::is_same<T, uint64>::value)
		return value[0] == 'Q';
	else if (std::is_same<T, bool>::value)
		return value[0] == '?';
	else
		return false;
}

enum SourceType {NONE, PyGLM_VEC, PyGLM_MVEC, PyGLM_MAT, PyGLM_QUA, PTI};







extern PyGLMTypeInfo PTI0;
extern SourceType sourceType0;

extern PyGLMTypeInfo PTI1;
extern SourceType sourceType1;

extern PyGLMTypeInfo PTI2;
extern SourceType sourceType2;

extern PyGLMTypeInfo PTI3;
extern SourceType sourceType3;

#ifdef PyGLM_DEBUG
extern PyObject* ARG0;
extern PyObject* ARG1;
extern PyObject* ARG2;
extern PyObject* ARG3;

extern bool ARGUSED;
#endif

#ifdef PyGLM_DEBUG
#define PyGLM_PTI_InitN(N, o, accepted_types) \
	if (o->ob_type->tp_dealloc == (destructor)vec_dealloc){if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_VEC;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mat_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_MAT;} else {sourceType ## N = NONE;}} \
	else if (o->ob_type->tp_dealloc == (destructor)qua_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_QUA;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_MVEC;} else {sourceType ## N = NONE;}}\
	else { PTI ## N = PyGLMTypeInfo(accepted_types, o); if (PTI ## N.info == 0) sourceType ## N = NONE; else sourceType ## N = PTI;};\
	if (N == 0 && !ARGUSED) throw; ARG ## N = o; if (N == 0 && sourceType ## N != NONE) {ARGUSED = false;};

inline bool PyGLM_PTI_DEBUG_EQ_FUNC(PyObject* o, PyObject* arg) {
	if (o != arg) {
		throw;
	}
	return false;
}

inline bool set_ARGUSED() {
	ARGUSED = true;
	return ARGUSED;
}

#define PyGLM_PTI_DEBUG_EQ(N, o) (set_ARGUSED() && PyGLM_PTI_DEBUG_EQ_FUNC(o, ARG##N)) ||
#define PyGLM_PTI_DEBUG_SC(N, o) PyGLM_PTI_DEBUG_EQ_FUNC(o, ARG##N)

#define PyGLM_PTI_IsVec(N) ((ARGUSED = true) && (sourceType ## N == PyGLM_VEC || sourceType ## N == PyGLM_MVEC || sourceType ## N == PTI && PTI ## N.isVec))

#define PyGLM_PTI_IsMat(N) ((ARGUSED = true) && (sourceType ## N == PyGLM_MAT || sourceType ## N == PTI && PTI ## N.isMat))

#define PyGLM_PTI_IsQua(N) ((ARGUSED = true) && (sourceType ## N == PyGLM_QUA || sourceType ## N == PTI && PTI ## N.isQua))

#define PyGLM_PTI_IsNone(N) ((ARGUSED = true) && sourceType ## N == NONE)
#else
#define PyGLM_PTI_InitN(N, o, accepted_types) \
	if (o->ob_type->tp_dealloc == (destructor)vec_dealloc){if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_VEC;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mat_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_MAT;} else {sourceType ## N = NONE;}} \
	else if (o->ob_type->tp_dealloc == (destructor)qua_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_QUA;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_MVEC;} else {sourceType ## N = NONE;}}\
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
	if (o->ob_type->tp_dealloc == (destructor)vec_dealloc){if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_VEC;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mat_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_MAT;} else {sourceType ## N = NONE;}} \
	else if (o->ob_type->tp_dealloc == (destructor)qua_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_QUA;} else {sourceType ## N = NONE;}}\
	else if (o->ob_type->tp_dealloc == (destructor)mvec_dealloc) {if (GET_PTI_COMPATIBLE_SIMPLE(o, accepted_types)) {sourceType ## N = PyGLM_MVEC;} else {sourceType ## N = NONE;}}\
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
