#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::u32> vec4_uint32_t;

extern PyMemberDef huvec4_members[];
extern PyMethodDef huvec4_methods[];
extern PyBufferProcs huvec4BufferMethods;
extern PySequenceMethods huvec4SeqMethods;
extern PyNumberMethods huvec4NumMethods;
extern PyTypeObject huvec4IterType;
extern PyGLMTypeObject huvec4GLMType;
extern PyTypeObject& huvec4Type;

