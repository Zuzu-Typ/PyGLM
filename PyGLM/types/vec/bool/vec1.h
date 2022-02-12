#pragma once

#include "../forward_declarations.h"

typedef vec<1, bool> vec1_bool_t;

extern PyMemberDef hbvec1_members[];
extern PyMethodDef hbvec1_methods[];
extern PyBufferProcs hbvec1BufferMethods;
extern PySequenceMethods hbvec1SeqMethods;
extern PyNumberMethods hbvec1NumMethods;
extern PyTypeObject hbvec1IterType;
extern PyGLMTypeObject hbvec1GLMType;
extern PyTypeObject& hbvec1Type;

