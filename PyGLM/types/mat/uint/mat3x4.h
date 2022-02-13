#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat3x4_methods[];
extern PyBufferProcs humat3x4BufferMethods;
extern PySequenceMethods humat3x4SeqMethods;
extern PyMappingMethods humat3x4MapMethods;
extern PyNumberMethods humat3x4NumMethods;

extern PyTypeObject humat3x4IterType;
extern PyGLMTypeObject humat3x4GLMType;
extern PyTypeObject& humat3x4Type;

