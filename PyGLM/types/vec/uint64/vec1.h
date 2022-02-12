#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::u64> vec1_uint64_t;

extern PyMemberDef hu64vec1_members[];
extern PyMethodDef hu64vec1_methods[];
extern PyBufferProcs hu64vec1BufferMethods;
extern PySequenceMethods hu64vec1SeqMethods;
extern PyNumberMethods hu64vec1NumMethods;
extern PyTypeObject hu64vec1IterType;
extern PyGLMTypeObject hu64vec1GLMType;
extern PyTypeObject& hu64vec1Type;

