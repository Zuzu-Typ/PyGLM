#pragma once

#include "../types/types.h"

#define PyGLM_GENERATE_TEMPLATE_DEF_NUM(DEF) \
DEF(double);\
DEF(float);\
DEF(int8);\
DEF(uint8);\
DEF(int16);\
DEF(uint16);\
DEF(int32);\
DEF(uint32);\
DEF(int64);\
DEF(uint64);\
DEF(bool)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_NUM(DEF) PyGLM_GENERATE_TEMPLATE_DEF_NUM(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_VEC(DEF) \
DEF(1, double);\
DEF(1, float);\
DEF(1, int8);\
DEF(1, uint8);\
DEF(1, int16);\
DEF(1, uint16);\
DEF(1, int32);\
DEF(1, uint32);\
DEF(1, int64);\
DEF(1, uint64);\
DEF(1, bool);\
DEF(2, double);\
DEF(2, float);\
DEF(2, int8);\
DEF(2, uint8);\
DEF(2, int16);\
DEF(2, uint16);\
DEF(2, int32);\
DEF(2, uint32);\
DEF(2, int64);\
DEF(2, uint64);\
DEF(2, bool);\
DEF(3, double);\
DEF(3, float);\
DEF(3, int8);\
DEF(3, uint8);\
DEF(3, int16);\
DEF(3, uint16);\
DEF(3, int32);\
DEF(3, uint32);\
DEF(3, int64);\
DEF(3, uint64);\
DEF(3, bool);\
DEF(4, double);\
DEF(4, float);\
DEF(4, int8);\
DEF(4, uint8);\
DEF(4, int16);\
DEF(4, uint16);\
DEF(4, int32);\
DEF(4, uint32);\
DEF(4, int64);\
DEF(4, uint64);\
DEF(4, bool)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_VEC(DEF) PyGLM_GENERATE_TEMPLATE_DEF_VEC(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_VEC_I(DEF) \
DEF(1, int8);\
DEF(1, uint8);\
DEF(1, int16);\
DEF(1, uint16);\
DEF(1, int32);\
DEF(1, uint32);\
DEF(1, int64);\
DEF(1, uint64);\
DEF(2, int8);\
DEF(2, uint8);\
DEF(2, int16);\
DEF(2, uint16);\
DEF(2, int32);\
DEF(2, uint32);\
DEF(2, int64);\
DEF(2, uint64);\
DEF(3, int8);\
DEF(3, uint8);\
DEF(3, int16);\
DEF(3, uint16);\
DEF(3, int32);\
DEF(3, uint32);\
DEF(3, int64);\
DEF(3, uint64);\
DEF(4, int8);\
DEF(4, uint8);\
DEF(4, int16);\
DEF(4, uint16);\
DEF(4, int32);\
DEF(4, uint32);\
DEF(4, int64);\
DEF(4, uint64)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_VEC_I(DEF) PyGLM_GENERATE_TEMPLATE_DEF_VEC_I(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_VEC_I_SIGNED(DEF) \
DEF(1, int8);\
DEF(1, int16);\
DEF(1, int32);\
DEF(1, int64);\
DEF(2, int8);\
DEF(2, int16);\
DEF(2, int32);\
DEF(2, int64);\
DEF(3, int8);\
DEF(3, int16);\
DEF(3, int32);\
DEF(3, int64);\
DEF(4, int8);\
DEF(4, int16);\
DEF(4, int32);\
DEF(4, int64);

#define PyGLM_GENERATE_EXTERN_TEMPLATE_VEC_I_SIGNED(DEF) PyGLM_GENERATE_TEMPLATE_DEF_VEC_I_SIGNED(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_VEC_FD(DEF) \
DEF(1, double);\
DEF(1, float);\
DEF(2, double);\
DEF(2, float);\
DEF(3, double);\
DEF(3, float);\
DEF(4, double);\
DEF(4, float)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_VEC_FD(DEF) PyGLM_GENERATE_TEMPLATE_DEF_VEC_FD(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_VEC_FDI(DEF) \
PyGLM_GENERATE_TEMPLATE_DEF_VEC_FD(DEF); \
PyGLM_GENERATE_TEMPLATE_DEF_VEC_I(DEF)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_VEC_FDI(DEF) PyGLM_GENERATE_TEMPLATE_DEF_VEC_FDI(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_VEC_FDI_SIGNED(DEF) \
PyGLM_GENERATE_TEMPLATE_DEF_VEC_FD(DEF); \
PyGLM_GENERATE_TEMPLATE_DEF_VEC_I_SIGNED(DEF)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_VEC_FDI_SIGNED(DEF) PyGLM_GENERATE_TEMPLATE_DEF_VEC_FDI_SIGNED(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_MVEC(DEF) \
DEF(2, double);\
DEF(2, float);\
DEF(2, int32);\
DEF(2, uint32);\
DEF(3, double);\
DEF(3, float);\
DEF(3, int32);\
DEF(3, uint32);\
DEF(4, double);\
DEF(4, float);\
DEF(4, int32);\
DEF(4, uint32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC(DEF) PyGLM_GENERATE_TEMPLATE_DEF_MVEC(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(DEF) \
DEF(2, double);\
DEF(2, float);\
DEF(3, double);\
DEF(3, float);\
DEF(4, double);\
DEF(4, float)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_FD(DEF) PyGLM_GENERATE_TEMPLATE_DEF_MVEC_FD(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(DEF) \
DEF(2, int32);\
DEF(2, uint32);\
DEF(3, int32);\
DEF(3, uint32);\
DEF(4, int32);\
DEF(4, uint32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_I(DEF) PyGLM_GENERATE_TEMPLATE_DEF_MVEC_I(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_MVEC_SIGNED(DEF) \
DEF(2, double);\
DEF(2, float);\
DEF(2, int32);\
DEF(3, double);\
DEF(3, float);\
DEF(3, int32);\
DEF(4, double);\
DEF(4, float);\
DEF(4, int32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_MVEC_SIGNED(DEF) PyGLM_GENERATE_TEMPLATE_DEF_MVEC_SIGNED(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_MAT(DEF) \
DEF(2, 2, double);\
DEF(2, 2, float);\
DEF(2, 2, int32);\
DEF(2, 2, uint32);\
DEF(2, 3, double);\
DEF(2, 3, float);\
DEF(2, 3, int32);\
DEF(2, 3, uint32);\
DEF(2, 4, double);\
DEF(2, 4, float);\
DEF(2, 4, int32);\
DEF(2, 4, uint32);\
DEF(3, 2, double);\
DEF(3, 2, float);\
DEF(3, 2, int32);\
DEF(3, 2, uint32);\
DEF(3, 3, double);\
DEF(3, 3, float);\
DEF(3, 3, int32);\
DEF(3, 3, uint32);\
DEF(3, 4, double);\
DEF(3, 4, float);\
DEF(3, 4, int32);\
DEF(3, 4, uint32);\
DEF(4, 2, double);\
DEF(4, 2, float);\
DEF(4, 2, int32);\
DEF(4, 2, uint32);\
DEF(4, 3, double);\
DEF(4, 3, float);\
DEF(4, 3, int32);\
DEF(4, 3, uint32);\
DEF(4, 4, double);\
DEF(4, 4, float);\
DEF(4, 4, int32);\
DEF(4, 4, uint32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_MAT(DEF) PyGLM_GENERATE_TEMPLATE_DEF_MAT(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_MAT_SIGNED(DEF) \
DEF(2, 2, double);\
DEF(2, 2, float);\
DEF(2, 2, int32);\
DEF(2, 3, double);\
DEF(2, 3, float);\
DEF(2, 3, int32);\
DEF(2, 4, double);\
DEF(2, 4, float);\
DEF(2, 4, int32);\
DEF(3, 2, double);\
DEF(3, 2, float);\
DEF(3, 2, int32);\
DEF(3, 3, double);\
DEF(3, 3, float);\
DEF(3, 3, int32);\
DEF(3, 4, double);\
DEF(3, 4, float);\
DEF(3, 4, int32);\
DEF(4, 2, double);\
DEF(4, 2, float);\
DEF(4, 2, int32);\
DEF(4, 3, double);\
DEF(4, 3, float);\
DEF(4, 3, int32);\
DEF(4, 4, double);\
DEF(4, 4, float);\
DEF(4, 4, int32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_MAT_SIGNED(DEF) PyGLM_GENERATE_TEMPLATE_DEF_MAT_SIGNED(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_SQMAT(DEF) \
DEF(2, double);\
DEF(2, float);\
DEF(2, int32);\
DEF(2, uint32);\
DEF(3, double);\
DEF(3, float);\
DEF(3, int32);\
DEF(3, uint32);\
DEF(4, double);\
DEF(4, float);\
DEF(4, int32);\
DEF(4, uint32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_SQMAT(DEF) PyGLM_GENERATE_TEMPLATE_DEF_SQMAT(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_SQMAT_FD(DEF) \
DEF(2, double);\
DEF(2, float);\
DEF(3, double);\
DEF(3, float);\
DEF(4, double);\
DEF(4, float)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_SQMAT_FD(DEF) PyGLM_GENERATE_TEMPLATE_DEF_SQMAT_FD(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_SQMAT_I(DEF) \
DEF(2, int32);\
DEF(2, uint32);\
DEF(3, int32);\
DEF(3, uint32);\
DEF(4, int32);\
DEF(4, uint32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_SQMAT_I(DEF) PyGLM_GENERATE_TEMPLATE_DEF_SQMAT_I(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_NOSQMAT(DEF) \
DEF(2, 3, double);\
DEF(2, 3, float);\
DEF(2, 3, int32);\
DEF(2, 3, uint32);\
DEF(2, 4, double);\
DEF(2, 4, float);\
DEF(2, 4, int32);\
DEF(2, 4, uint32);\
DEF(3, 2, double);\
DEF(3, 2, float);\
DEF(3, 2, int32);\
DEF(3, 2, uint32);\
DEF(3, 4, double);\
DEF(3, 4, float);\
DEF(3, 4, int32);\
DEF(3, 4, uint32);\
DEF(4, 2, double);\
DEF(4, 2, float);\
DEF(4, 2, int32);\
DEF(4, 2, uint32);\
DEF(4, 3, double);\
DEF(4, 3, float);\
DEF(4, 3, int32);\
DEF(4, 3, uint32)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_NOSQMAT(DEF) PyGLM_GENERATE_TEMPLATE_DEF_NOSQMAT(extern DEF)

//#define PyGLM_GENERATE_TEMPLATE_DEF_NOSQMAT_FD(DEF) \
//DEF(2, 3, double);\
//DEF(2, 3, float);\
//DEF(2, 4, double);\
//DEF(2, 4, float);\
//DEF(3, 2, double);\
//DEF(3, 2, float);\
//DEF(3, 4, double);\
//DEF(3, 4, float);\
//DEF(4, 2, double);\
//DEF(4, 2, float);\
//DEF(4, 3, double);\
//DEF(4, 3, float);
//
//#define PyGLM_GENERATE_EXTERN_TEMPLATE_NOSQMAT_FD(DEF) PyGLM_GENERATE_TEMPLATE_DEF_NOSQMAT_FD(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_QUA(DEF) \
DEF(double);\
DEF(float)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_QUA(DEF) PyGLM_GENERATE_TEMPLATE_DEF_QUA(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_1_THRU_4(DEF) \
DEF(1);\
DEF(2);\
DEF(3);\
DEF(4)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_1_THRU_4(DEF) PyGLM_GENERATE_TEMPLATE_DEF_1_THRU_4(extern DEF)

#define PyGLM_GENERATE_TEMPLATE_DEF_2_THRU_4(DEF) \
DEF(2);\
DEF(3);\
DEF(4)

#define PyGLM_GENERATE_EXTERN_TEMPLATE_2_THRU_4(DEF) PyGLM_GENERATE_TEMPLATE_DEF_2_THRU_4(extern DEF)
