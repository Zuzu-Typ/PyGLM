#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat4x2_methods[];
extern PyBufferProcs himat4x2BufferMethods;
extern PySequenceMethods himat4x2SeqMethods;
extern PyMappingMethods himat4x2MapMethods;
extern PyNumberMethods himat4x2NumMethods;

extern PyTypeObject himat4x2IterType;
extern PyGLMTypeObject himat4x2GLMType;
extern PyTypeObject& himat4x2Type;

