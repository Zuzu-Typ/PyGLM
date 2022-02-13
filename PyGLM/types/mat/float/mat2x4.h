#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat2x4_methods[];
extern PyBufferProcs hfmat2x4BufferMethods;
extern PySequenceMethods hfmat2x4SeqMethods;
extern PyMappingMethods hfmat2x4MapMethods;
extern PyNumberMethods hfmat2x4NumMethods;

extern PyTypeObject hfmat2x4IterType;
extern PyGLMTypeObject hfmat2x4GLMType;
extern PyTypeObject& hfmat2x4Type;

