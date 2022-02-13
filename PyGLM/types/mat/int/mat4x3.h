#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat4x3_methods[];
extern PyBufferProcs himat4x3BufferMethods;
extern PySequenceMethods himat4x3SeqMethods;
extern PyMappingMethods himat4x3MapMethods;
extern PyNumberMethods himat4x3NumMethods;

extern PyTypeObject himat4x3IterType;
extern PyGLMTypeObject himat4x3GLMType;
extern PyTypeObject& himat4x3Type;

