#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::u64> vec2_uint64_t;

extern PyMemberDef hu64vec2_members[];
extern PyMethodDef hu64vec2_methods[];
extern PyBufferProcs hu64vec2BufferMethods;
extern PySequenceMethods hu64vec2SeqMethods;
extern PyNumberMethods hu64vec2NumMethods;
extern PyTypeObject hu64vec2IterType;
extern PyGLMTypeObject hu64vec2GLMType;
extern PyTypeObject& hu64vec2Type;

