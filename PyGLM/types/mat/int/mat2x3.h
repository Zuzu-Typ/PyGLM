#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat2x3_methods[];
extern PyBufferProcs himat2x3BufferMethods;
extern PySequenceMethods himat2x3SeqMethods;
extern PyMappingMethods himat2x3MapMethods;
extern PyNumberMethods himat2x3NumMethods;

extern PyTypeObject himat2x3IterType;
extern PyGLMTypeObject himat2x3GLMType;
extern PyTypeObject& himat2x3Type;

