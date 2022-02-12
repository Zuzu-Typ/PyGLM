#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::i8> vec3_int8_t;

extern PyMemberDef hi8vec3_members[];
extern PyMethodDef hi8vec3_methods[];
extern PyBufferProcs hi8vec3BufferMethods;
extern PySequenceMethods hi8vec3SeqMethods;
extern PyNumberMethods hi8vec3NumMethods;
extern PyTypeObject hi8vec3IterType;
extern PyGLMTypeObject hi8vec3GLMType;
extern PyTypeObject& hi8vec3Type;

