#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::u32> vec3_uint32_t;

extern PyMemberDef huvec3_members[];
extern PyMethodDef huvec3_methods[];
extern PyBufferProcs huvec3BufferMethods;
extern PySequenceMethods huvec3SeqMethods;
extern PyNumberMethods huvec3NumMethods;
extern PyTypeObject huvec3IterType;
extern PyGLMTypeObject huvec3GLMType;
extern PyTypeObject& huvec3Type;

