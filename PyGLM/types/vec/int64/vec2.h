#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::i64> vec2_int64_t;

extern PyMemberDef hi64vec2_members[];
extern PyMethodDef hi64vec2_methods[];
extern PyBufferProcs hi64vec2BufferMethods;
extern PySequenceMethods hi64vec2SeqMethods;
extern PyNumberMethods hi64vec2NumMethods;
extern PyTypeObject hi64vec2IterType;
extern PyGLMTypeObject hi64vec2GLMType;
extern PyTypeObject& hi64vec2Type;

