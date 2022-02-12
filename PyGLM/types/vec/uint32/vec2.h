#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::u32> vec2_uint32_t;

extern PyMemberDef huvec2_members[];
extern PyMethodDef huvec2_methods[];
extern PyBufferProcs huvec2BufferMethods;
extern PySequenceMethods huvec2SeqMethods;
extern PyNumberMethods huvec2NumMethods;
extern PyTypeObject huvec2IterType;
extern PyGLMTypeObject huvec2GLMType;
extern PyTypeObject& huvec2Type;

