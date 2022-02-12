#pragma once

#include "../forward_declarations.h"

typedef vec<4, double> vec4_double_t;

extern PyMemberDef hdvec4_members[];
extern PyMethodDef hdvec4_methods[];
extern PyBufferProcs hdvec4BufferMethods;
extern PySequenceMethods hdvec4SeqMethods;
extern PyNumberMethods hdvec4NumMethods;
extern PyTypeObject hdvec4IterType;
extern PyGLMTypeObject hdvec4GLMType;
extern PyTypeObject& hdvec4Type;

