#pragma once

#include "../forward_declarations.h"

typedef vec<1, float> vec1_float_t;

extern PyMemberDef hfvec1_members[];
extern PyMethodDef hfvec1_methods[];
extern PyBufferProcs hfvec1BufferMethods;
extern PySequenceMethods hfvec1SeqMethods;
extern PyNumberMethods hfvec1NumMethods;
extern PyTypeObject hfvec1IterType;
extern PyGLMTypeObject hfvec1GLMType;
extern PyTypeObject& hfvec1Type;

