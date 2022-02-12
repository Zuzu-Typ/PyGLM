#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::u16> vec2_uint16_t;

extern PyMemberDef hu16vec2_members[];
extern PyMethodDef hu16vec2_methods[];
extern PyBufferProcs hu16vec2BufferMethods;
extern PySequenceMethods hu16vec2SeqMethods;
extern PyNumberMethods hu16vec2NumMethods;
extern PyTypeObject hu16vec2IterType;
extern PyGLMTypeObject hu16vec2GLMType;
extern PyTypeObject& hu16vec2Type;

