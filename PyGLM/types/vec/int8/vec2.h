#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::i8> vec2_int8_t;

extern PyMemberDef hi8vec2_members[];
extern PyMethodDef hi8vec2_methods[];
extern PyBufferProcs hi8vec2BufferMethods;
extern PySequenceMethods hi8vec2SeqMethods;
extern PyNumberMethods hi8vec2NumMethods;
extern PyTypeObject hi8vec2IterType;
extern PyGLMTypeObject hi8vec2GLMType;
extern PyTypeObject& hi8vec2Type;

