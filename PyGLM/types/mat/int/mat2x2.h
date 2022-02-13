#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat2x2_methods[];
extern PyBufferProcs himat2x2BufferMethods;
extern PySequenceMethods himat2x2SeqMethods;
extern PyMappingMethods himat2x2MapMethods;
extern PyNumberMethods himat2x2NumMethods;

extern PyTypeObject himat2x2IterType;
extern PyGLMTypeObject himat2x2GLMType;
extern PyTypeObject& himat2x2Type;

