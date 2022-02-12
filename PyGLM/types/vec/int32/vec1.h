#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::i32> vec1_int32_t;

extern PyMemberDef hivec1_members[];
extern PyMethodDef hivec1_methods[];
extern PyBufferProcs hivec1BufferMethods;
extern PySequenceMethods hivec1SeqMethods;
extern PyNumberMethods hivec1NumMethods;
extern PyTypeObject hivec1IterType;
extern PyGLMTypeObject hivec1GLMType;
extern PyTypeObject& hivec1Type;

