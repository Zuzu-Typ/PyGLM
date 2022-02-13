#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat3x2_methods[];
extern PyBufferProcs hfmat3x2BufferMethods;
extern PySequenceMethods hfmat3x2SeqMethods;
extern PyMappingMethods hfmat3x2MapMethods;
extern PyNumberMethods hfmat3x2NumMethods;

extern PyTypeObject hfmat3x2IterType;
extern PyGLMTypeObject hfmat3x2GLMType;
extern PyTypeObject& hfmat3x2Type;

