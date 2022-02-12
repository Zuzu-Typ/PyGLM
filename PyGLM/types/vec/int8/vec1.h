#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::i8> vec1_int8_t;

extern PyMemberDef hi8vec1_members[];
extern PyMethodDef hi8vec1_methods[];
extern PyBufferProcs hi8vec1BufferMethods;
extern PySequenceMethods hi8vec1SeqMethods;
extern PyNumberMethods hi8vec1NumMethods;
extern PyTypeObject hi8vec1IterType;
extern PyGLMTypeObject hi8vec1GLMType;
extern PyTypeObject& hi8vec1Type;

