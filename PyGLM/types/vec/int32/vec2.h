#pragma once

#include "../forward_declarations.h"

typedef vec<2, glm::i32> vec2_int32_t;

extern PyMemberDef hivec2_members[];
extern PyMethodDef hivec2_methods[];
extern PyBufferProcs hivec2BufferMethods;
extern PySequenceMethods hivec2SeqMethods;
extern PyNumberMethods hivec2NumMethods;
extern PyTypeObject hivec2IterType;
extern PyGLMTypeObject hivec2GLMType;
extern PyTypeObject& hivec2Type;

