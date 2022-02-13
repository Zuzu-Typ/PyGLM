#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat4x4_methods[];
extern PyBufferProcs hfmat4x4BufferMethods;
extern PySequenceMethods hfmat4x4SeqMethods;
extern PyMappingMethods hfmat4x4MapMethods;
extern PyNumberMethods hfmat4x4NumMethods;

extern PyTypeObject hfmat4x4IterType;
extern PyGLMTypeObject hfmat4x4GLMType;
extern PyTypeObject& hfmat4x4Type;

