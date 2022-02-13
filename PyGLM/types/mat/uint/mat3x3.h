#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat3x3_methods[];
extern PyBufferProcs humat3x3BufferMethods;
extern PySequenceMethods humat3x3SeqMethods;
extern PyMappingMethods humat3x3MapMethods;
extern PyNumberMethods humat3x3NumMethods;

extern PyTypeObject humat3x3IterType;
extern PyGLMTypeObject humat3x3GLMType;
extern PyTypeObject& humat3x3Type;

