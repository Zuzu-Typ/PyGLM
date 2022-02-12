#pragma once

#include "../forward_declarations.h"

typedef vec<3, glm::u8> vec3_uint8_t;

extern PyMemberDef hu8vec3_members[];
extern PyMethodDef hu8vec3_methods[];
extern PyBufferProcs hu8vec3BufferMethods;
extern PySequenceMethods hu8vec3SeqMethods;
extern PyNumberMethods hu8vec3NumMethods;
extern PyTypeObject hu8vec3IterType;
extern PyGLMTypeObject hu8vec3GLMType;
extern PyTypeObject& hu8vec3Type;

