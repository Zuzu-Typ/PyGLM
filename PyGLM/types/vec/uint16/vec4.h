#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::u16> vec4_uint16_t;

extern PyMemberDef hu16vec4_members[];
extern PyMethodDef hu16vec4_methods[];
extern PyBufferProcs hu16vec4BufferMethods;
extern PySequenceMethods hu16vec4SeqMethods;
extern PyNumberMethods hu16vec4NumMethods;
extern PyTypeObject hu16vec4IterType;
extern PyGLMTypeObject hu16vec4GLMType;
extern PyTypeObject& hu16vec4Type;

