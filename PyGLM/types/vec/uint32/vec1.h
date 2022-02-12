#pragma once

#include "../forward_declarations.h"

typedef vec<1, glm::u32> vec1_uint32_t;

extern PyMemberDef huvec1_members[];
extern PyMethodDef huvec1_methods[];
extern PyBufferProcs huvec1BufferMethods;
extern PySequenceMethods huvec1SeqMethods;
extern PyNumberMethods huvec1NumMethods;
extern PyTypeObject huvec1IterType;
extern PyGLMTypeObject huvec1GLMType;
extern PyTypeObject& huvec1Type;

