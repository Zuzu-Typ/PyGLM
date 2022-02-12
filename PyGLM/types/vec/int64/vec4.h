#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::i64> vec4_int64_t;

extern PyMemberDef hi64vec4_members[];
extern PyMethodDef hi64vec4_methods[];
extern PyBufferProcs hi64vec4BufferMethods;
extern PySequenceMethods hi64vec4SeqMethods;
extern PyNumberMethods hi64vec4NumMethods;
extern PyTypeObject hi64vec4IterType;
extern PyGLMTypeObject hi64vec4GLMType;
extern PyTypeObject& hi64vec4Type;

