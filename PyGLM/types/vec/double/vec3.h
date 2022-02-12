#pragma once

#include "../forward_declarations.h"

typedef vec<3, double> vec3_double_t;

extern PyMemberDef hdvec3_members[];
extern PyMethodDef hdvec3_methods[];
extern PyBufferProcs hdvec3BufferMethods;
extern PySequenceMethods hdvec3SeqMethods;
extern PyNumberMethods hdvec3NumMethods;
extern PyTypeObject hdvec3IterType;
extern PyGLMTypeObject hdvec3GLMType;
extern PyTypeObject& hdvec3Type;

