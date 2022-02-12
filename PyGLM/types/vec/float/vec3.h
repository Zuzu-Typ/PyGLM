#pragma once

#include "../forward_declarations.h"

typedef vec<3, float> vec3_float_t;

extern PyMemberDef hfvec3_members[];
extern PyMethodDef hfvec3_methods[];
extern PyBufferProcs hfvec3BufferMethods;
extern PySequenceMethods hfvec3SeqMethods;
extern PyNumberMethods hfvec3NumMethods ;
extern PyTypeObject hfvec3IterType;
extern PyGLMTypeObject hfvec3GLMType;
extern PyTypeObject& hfvec3Type;

