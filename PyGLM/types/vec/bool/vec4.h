#pragma once

#include "../forward_declarations.h"

typedef vec<4, bool> vec4_bool_t;

extern PyMemberDef hbvec4_members[];
extern PyMethodDef hbvec4_methods[];
extern PyBufferProcs hbvec4BufferMethods;
extern PySequenceMethods hbvec4SeqMethods;
extern PyNumberMethods hbvec4NumMethods;
extern PyTypeObject hbvec4IterType;
extern PyGLMTypeObject hbvec4GLMType;
extern PyTypeObject& hbvec4Type;
