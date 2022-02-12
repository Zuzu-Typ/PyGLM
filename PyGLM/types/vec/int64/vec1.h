#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::i64> vec1_int64_t;

extern PyMemberDef hi64vec1_members[];
extern PyMethodDef hi64vec1_methods[];
extern PyBufferProcs hi64vec1BufferMethods;
extern PySequenceMethods hi64vec1SeqMethods;
extern PyNumberMethods hi64vec1NumMethods;
extern PyTypeObject hi64vec1IterType;
extern PyGLMTypeObject hi64vec1GLMType;
extern PyTypeObject& hi64vec1Type;

