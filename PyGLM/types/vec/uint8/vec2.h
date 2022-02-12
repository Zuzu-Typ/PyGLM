#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::u8> vec2_uint8_t;

extern PyMemberDef hu8vec2_members[];
extern PyMethodDef hu8vec2_methods[];
extern PyBufferProcs hu8vec2BufferMethods;
extern PySequenceMethods hu8vec2SeqMethods;
extern PyNumberMethods hu8vec2NumMethods;
extern PyTypeObject hu8vec2IterType;
extern PyGLMTypeObject hu8vec2GLMType;
extern PyTypeObject& hu8vec2Type;

