#pragma once

#include "../forward_declarations.h"

typedef vec<2, double> vec2_double_t;

extern PyMemberDef hdvec2_members[];
extern PyMethodDef hdvec2_methods[];
extern PyBufferProcs hdvec2BufferMethods;
extern PySequenceMethods hdvec2SeqMethods;
extern PyNumberMethods hdvec2NumMethods;
extern PyTypeObject hdvec2IterType;
extern PyGLMTypeObject hdvec2GLMType;
extern PyTypeObject& hdvec2Type;

