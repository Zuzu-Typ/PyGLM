#pragma once

#include "../forward_declarations.h"

extern PyMethodDef himat2x4_methods[];
extern PyBufferProcs himat2x4BufferMethods;
extern PySequenceMethods himat2x4SeqMethods;
extern PyMappingMethods himat2x4MapMethods;
extern PyNumberMethods himat2x4NumMethods;

extern PyTypeObject himat2x4IterType;
extern PyGLMTypeObject himat2x4GLMType;
extern PyTypeObject& himat2x4Type;

