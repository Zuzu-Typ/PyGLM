#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat3x2_methods[];
extern PyBufferProcs himat3x2BufferMethods;
extern PySequenceMethods himat3x2SeqMethods;
extern PyMappingMethods himat3x2MapMethods;
extern PyNumberMethods himat3x2NumMethods;

extern PyTypeObject himat3x2IterType;
extern PyGLMTypeObject himat3x2GLMType;
extern PyTypeObject& himat3x2Type;

