#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::u16> vec1_uint16_t;

extern PyMemberDef hu16vec1_members[];
extern PyMethodDef hu16vec1_methods[];
extern PyBufferProcs hu16vec1BufferMethods;
extern PySequenceMethods hu16vec1SeqMethods;
extern PyNumberMethods hu16vec1NumMethods;
extern PyTypeObject hu16vec1IterType;
extern PyGLMTypeObject hu16vec1GLMType;
extern PyTypeObject& hu16vec1Type;

