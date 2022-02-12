#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::u16> vec3_uint16_t;

extern PyMemberDef hu16vec3_members[];
extern PyMethodDef hu16vec3_methods[];
extern PyBufferProcs hu16vec3BufferMethods;
extern PySequenceMethods hu16vec3SeqMethods;
extern PyNumberMethods hu16vec3NumMethods;
extern PyTypeObject hu16vec3IterType;
extern PyGLMTypeObject hu16vec3GLMType;
extern PyTypeObject& hu16vec3Type;

