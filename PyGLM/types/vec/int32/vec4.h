#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::i32> vec4_int32_t;

extern PyMemberDef hivec4_members[];
extern PyMethodDef hivec4_methods[];
extern PyBufferProcs hivec4BufferMethods;
extern PySequenceMethods hivec4SeqMethods;
extern PyNumberMethods hivec4NumMethods;
extern PyTypeObject hivec4IterType;
extern PyGLMTypeObject hivec4GLMType;
extern PyTypeObject& hivec4Type;

