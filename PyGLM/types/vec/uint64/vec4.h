#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::u64> vec4_uint64_t;

extern PyMemberDef hu64vec4_members[];
extern PyMethodDef hu64vec4_methods[];
extern PyBufferProcs hu64vec4BufferMethods;
extern PySequenceMethods hu64vec4SeqMethods;
extern PyNumberMethods hu64vec4NumMethods;
extern PyTypeObject hu64vec4IterType;
extern PyGLMTypeObject hu64vec4GLMType;
extern PyTypeObject& hu64vec4Type;

