#pragma once

#include "../forward_declarations.h"

typedef vec<4, float> vec4_float_t;

extern PyMemberDef hfvec4_members[];
extern PyMethodDef hfvec4_methods[];
extern PyBufferProcs hfvec4BufferMethods;
extern PySequenceMethods hfvec4SeqMethods;
extern PyNumberMethods hfvec4NumMethods;
extern PyTypeObject hfvec4IterType;
extern PyGLMTypeObject hfvec4GLMType;
extern PyTypeObject& hfvec4Type;

