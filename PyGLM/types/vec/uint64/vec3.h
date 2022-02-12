#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::u64> vec3_uint64_t;

extern PyMemberDef hu64vec3_members[];
extern PyMethodDef hu64vec3_methods[];
extern PyBufferProcs hu64vec3BufferMethods;
extern PySequenceMethods hu64vec3SeqMethods;
extern PyNumberMethods hu64vec3NumMethods;
extern PyTypeObject hu64vec3IterType;
extern PyGLMTypeObject hu64vec3GLMType;
extern PyTypeObject& hu64vec3Type;

