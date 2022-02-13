#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat3x3_methods[];
extern PyBufferProcs himat3x3BufferMethods;
extern PySequenceMethods himat3x3SeqMethods;
extern PyMappingMethods himat3x3MapMethods;
extern PyNumberMethods himat3x3NumMethods;

extern PyTypeObject himat3x3IterType;
extern PyGLMTypeObject himat3x3GLMType;
extern PyTypeObject& himat3x3Type;

