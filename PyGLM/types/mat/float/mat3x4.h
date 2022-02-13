#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat3x4_methods[];
extern PyBufferProcs hfmat3x4BufferMethods;
extern PySequenceMethods hfmat3x4SeqMethods;
extern PyMappingMethods hfmat3x4MapMethods;
extern PyNumberMethods hfmat3x4NumMethods;

extern PyTypeObject hfmat3x4IterType;
extern PyGLMTypeObject hfmat3x4GLMType;
extern PyTypeObject& hfmat3x4Type;

