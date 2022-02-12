#pragma once

#include "../forward_declarations.h"

typedef vec<2, bool> vec2_bool_t;

extern PyMemberDef hbvec2_members[];
extern PyMethodDef hbvec2_methods[];
extern PyBufferProcs hbvec2BufferMethods;
extern PySequenceMethods hbvec2SeqMethods;
extern PyNumberMethods hbvec2NumMethods;
extern PyTypeObject hbvec2IterType;
extern PyGLMTypeObject hbvec2GLMType;
extern PyTypeObject& hbvec2Type;
