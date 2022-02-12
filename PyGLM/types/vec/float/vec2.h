#pragma once

#include "../forward_declarations.h"

typedef vec<2, float> vec2_float_t;

extern PyMemberDef hfvec2_members[];
extern PyMethodDef hfvec2_methods[];
extern PyBufferProcs hfvec2BufferMethods;
extern PySequenceMethods hfvec2SeqMethods;
extern PyNumberMethods hfvec2NumMethods;
extern PyTypeObject hfvec2IterType;
extern PyGLMTypeObject hfvec2GLMType;
extern PyTypeObject& hfvec2Type;

