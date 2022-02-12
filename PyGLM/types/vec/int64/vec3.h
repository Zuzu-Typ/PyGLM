#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::i64> vec3_int64_t;

extern PyMemberDef hi64vec3_members[];
extern PyMethodDef hi64vec3_methods[];
extern PyBufferProcs hi64vec3BufferMethods;
extern PySequenceMethods hi64vec3SeqMethods;
extern PyNumberMethods hi64vec3NumMethods;
extern PyTypeObject hi64vec3IterType;
extern PyGLMTypeObject hi64vec3GLMType;
extern PyTypeObject& hi64vec3Type;

