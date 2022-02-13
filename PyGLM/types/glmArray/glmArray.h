#pragma once

#include "forward_declarations.h"

#define T_PTR_AS_NUM ((sizeof(void*) == sizeof(unsigned long long)) ? T_ULONGLONG : (sizeof(void*) == sizeof(unsigned long)) ? T_ULONG : (sizeof(void*) == sizeof(unsigned int)) ? T_UINT : T_PYSSIZET)

extern PyMemberDef glmArray_members[];

extern PyGetSetDef glmArray_getSet[];

extern PyMethodDef glmArray_methods[];

extern PyBufferProcs glmArrayBufferMethods;

extern PySequenceMethods glmArraySeqMethods;

extern PyMappingMethods glmArrayMapMethods;

extern PyNumberMethods glmArrayNumMethods;

extern PyTypeObject glmArrayType;

extern PyTypeObject glmArrayIterType;
