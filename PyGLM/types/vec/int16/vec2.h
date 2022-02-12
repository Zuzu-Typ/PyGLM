#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::i16> vec2_int16_t;

extern PyMemberDef hi16vec2_members[];
extern PyMethodDef hi16vec2_methods[];
extern PyBufferProcs hi16vec2BufferMethods;
extern PySequenceMethods hi16vec2SeqMethods;
extern PyNumberMethods hi16vec2NumMethods;
extern PyTypeObject hi16vec2IterType;
extern PyGLMTypeObject hi16vec2GLMType;
extern PyTypeObject& hi16vec2Type;

