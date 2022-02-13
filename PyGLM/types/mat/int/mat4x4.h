#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat4x4_methods[];
extern PyBufferProcs himat4x4BufferMethods;
extern PySequenceMethods himat4x4SeqMethods;
extern PyMappingMethods himat4x4MapMethods;
extern PyNumberMethods himat4x4NumMethods;

extern PyTypeObject himat4x4IterType;
extern PyGLMTypeObject himat4x4GLMType;
extern PyTypeObject& himat4x4Type;

