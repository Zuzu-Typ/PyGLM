#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::i32> vec3_int32_t;

extern PyMemberDef hivec3_members[];
extern PyMethodDef hivec3_methods[];
extern PyBufferProcs hivec3BufferMethods;
extern PySequenceMethods hivec3SeqMethods;
extern PyNumberMethods hivec3NumMethods;
extern PyTypeObject hivec3IterType;
extern PyGLMTypeObject hivec3GLMType;
extern PyTypeObject& hivec3Type;

