#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::i16> vec1_int16_t;

extern PyMemberDef hi16vec1_members[];
extern PyMethodDef hi16vec1_methods[];
extern PyBufferProcs hi16vec1BufferMethods;
extern PySequenceMethods hi16vec1SeqMethods;
extern PyNumberMethods hi16vec1NumMethods;
extern PyTypeObject hi16vec1IterType;
extern PyGLMTypeObject hi16vec1GLMType;
extern PyTypeObject& hi16vec1Type;

