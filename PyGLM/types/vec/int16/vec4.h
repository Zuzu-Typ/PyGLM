#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::i16> vec4_int16_t;

extern PyMemberDef hi16vec4_members[];
extern PyMethodDef hi16vec4_methods[];
extern PyBufferProcs hi16vec4BufferMethods;
extern PySequenceMethods hi16vec4SeqMethods;
extern PyNumberMethods hi16vec4NumMethods;
extern PyTypeObject hi16vec4IterType;
extern PyGLMTypeObject hi16vec4GLMType;
extern PyTypeObject& hi16vec4Type;

