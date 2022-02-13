#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat4x3_methods[];
extern PyBufferProcs hfmat4x3BufferMethods;
extern PySequenceMethods hfmat4x3SeqMethods;
extern PyMappingMethods hfmat4x3MapMethods;
extern PyNumberMethods hfmat4x3NumMethods;

extern PyTypeObject hfmat4x3IterType;
extern PyGLMTypeObject hfmat4x3GLMType;
extern PyTypeObject& hfmat4x3Type;

