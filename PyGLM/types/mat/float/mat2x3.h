#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat2x3_methods[];
extern PyBufferProcs hfmat2x3BufferMethods;
extern PySequenceMethods hfmat2x3SeqMethods;
extern PyMappingMethods hfmat2x3MapMethods;
extern PyNumberMethods hfmat2x3NumMethods;

extern PyTypeObject hfmat2x3IterType;
extern PyGLMTypeObject hfmat2x3GLMType;
extern PyTypeObject& hfmat2x3Type;

