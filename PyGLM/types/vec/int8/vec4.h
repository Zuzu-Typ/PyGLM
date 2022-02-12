#pragma once

#include "../forward_declarations.h"

typedef vec<4, glm::i8> vec4_int8_t;

extern PyMemberDef hi8vec4_members[];
extern PyMethodDef hi8vec4_methods[];
extern PyBufferProcs hi8vec4BufferMethods;
extern PySequenceMethods hi8vec4SeqMethods;
extern PyNumberMethods hi8vec4NumMethods;
extern PyTypeObject hi8vec4IterType;
extern PyGLMTypeObject hi8vec4GLMType;
extern PyTypeObject& hi8vec4Type;

