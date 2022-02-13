#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat3x4_methods[];
extern PyBufferProcs himat3x4BufferMethods;
extern PySequenceMethods himat3x4SeqMethods;
extern PyMappingMethods himat3x4MapMethods;
extern PyNumberMethods himat3x4NumMethods;

extern PyTypeObject himat3x4IterType;
extern PyGLMTypeObject himat3x4GLMType;
extern PyTypeObject& himat3x4Type;

