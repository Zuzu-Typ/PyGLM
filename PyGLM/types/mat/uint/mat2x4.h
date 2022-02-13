#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat2x4_methods[];
extern PyBufferProcs humat2x4BufferMethod;
extern PySequenceMethods humat2x4SeqMethods;
extern PyMappingMethods humat2x4MapMethods;
extern PyNumberMethods humat2x4NumMethods;

extern PyTypeObject humat2x4IterType;
extern PyGLMTypeObject humat2x4GLMType;
extern PyTypeObject& humat2x4Type;

