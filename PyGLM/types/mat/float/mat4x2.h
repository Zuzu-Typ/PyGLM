#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat4x2_methods[];
extern PyBufferProcs hfmat4x2BufferMethods;
extern PySequenceMethods hfmat4x2SeqMethods;
extern PyMappingMethods hfmat4x2MapMethods;
extern PyNumberMethods hfmat4x2NumMethods;

extern PyTypeObject hfmat4x2IterType;
extern PyGLMTypeObject hfmat4x2GLMType;
extern PyTypeObject& hfmat4x2Type;

