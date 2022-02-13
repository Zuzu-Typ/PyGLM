#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat3x3_methods[];
extern PyBufferProcs hfmat3x3BufferMethods;
extern PySequenceMethods hfmat3x3SeqMethods;
extern PyMappingMethods hfmat3x3MapMethods;
extern PyNumberMethods hfmat3x3NumMethods;

extern PyTypeObject hfmat3x3IterType;
extern PyGLMTypeObject hfmat3x3GLMType;
extern PyTypeObject& hfmat3x3Type;

