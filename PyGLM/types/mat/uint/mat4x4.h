#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat4x4_methods[];
extern PyBufferProcs humat4x4BufferMethods;
extern PySequenceMethods humat4x4SeqMethods;
extern PyMappingMethods humat4x4MapMethods;
extern PyNumberMethods humat4x4NumMethods;

extern PyTypeObject humat4x4IterType;
extern PyGLMTypeObject humat4x4GLMType;
extern PyTypeObject& humat4x4Type;

