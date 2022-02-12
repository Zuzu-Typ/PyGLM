#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::u8> vec1_uint8_t;

extern PyMemberDef hu8vec1_members[];
extern PyMethodDef hu8vec1_methods[];
extern PyBufferProcs hu8vec1BufferMethods;
extern PySequenceMethods hu8vec1SeqMethods;
extern PyNumberMethods hu8vec1NumMethods;
extern PyTypeObject hu8vec1IterType;
extern PyGLMTypeObject hu8vec1GLMType;
extern PyTypeObject& hu8vec1Type;

