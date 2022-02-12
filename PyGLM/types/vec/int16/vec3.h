#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::i16> vec3_int16_t;

extern PyMemberDef hi16vec3_members[];
extern PyMethodDef hi16vec3_methods[];
extern PyBufferProcs hi16vec3BufferMethods;
extern PySequenceMethods hi16vec3SeqMethods;
extern PyNumberMethods hi16vec3NumMethods;
extern PyTypeObject hi16vec3IterType;
extern PyGLMTypeObject hi16vec3GLMType;
extern PyTypeObject& hi16vec3Type;

