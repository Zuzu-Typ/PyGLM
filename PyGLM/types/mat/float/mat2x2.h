#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfmat2x2_methods[];
extern PyBufferProcs hfmat2x2BufferMethods;
extern PySequenceMethods hfmat2x2SeqMethods;
extern PyMappingMethods hfmat2x2MapMethods;
extern PyNumberMethods hfmat2x2NumMethods;

extern PyTypeObject hfmat2x2IterType;
extern PyGLMTypeObject hfmat2x2GLMType;
extern PyTypeObject& hfmat2x2Type;

