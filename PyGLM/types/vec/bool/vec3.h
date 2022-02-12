#pragma once

#include "../forward_declarations.h"

typedef vec<3, bool> vec3_bool_t;

extern PyMemberDef hbvec3_members[];
extern PyMethodDef hbvec3_methods[];
extern PyBufferProcs hbvec3BufferMethods;
extern PySequenceMethods hbvec3SeqMethods;
extern PyNumberMethods hbvec3NumMethods;
extern PyTypeObject hbvec3IterType;
extern PyGLMTypeObject hbvec3GLMType;
extern PyTypeObject& hbvec3Type;
