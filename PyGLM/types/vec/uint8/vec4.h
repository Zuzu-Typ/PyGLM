#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::u8> vec4_uint8_t;

extern PyMemberDef hu8vec4_members[];
extern PyMethodDef hu8vec4_methods[];
extern PyBufferProcs hu8vec4BufferMethods;
extern PySequenceMethods hu8vec4SeqMethods;
extern PyNumberMethods hu8vec4NumMethods;
extern PyTypeObject hu8vec4IterType;
extern PyGLMTypeObject hu8vec4GLMType;
extern PyTypeObject& hu8vec4Type;

