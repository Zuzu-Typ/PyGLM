#pragma once

#include "../forward_declarations.h"

typedef vec<1, double> vec1_double_t;

extern PyMemberDef hdvec1_members[];
extern PyMethodDef hdvec1_methods[];
extern PyBufferProcs hdvec1BufferMethods;
extern PySequenceMethods hdvec1SeqMethods;
extern PyNumberMethods hdvec1NumMethods;
extern PyTypeObject hdvec1IterType;
extern PyGLMTypeObject hdvec1GLMType;
extern PyTypeObject& hdvec1Type;
