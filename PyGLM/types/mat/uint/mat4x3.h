#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat4x3_methods[];
extern PyBufferProcs humat4x3BufferMethods;
extern PySequenceMethods humat4x3SeqMethods;
extern PyMappingMethods humat4x3MapMethods;
extern PyNumberMethods humat4x3NumMethods;

extern PyTypeObject humat4x3IterType;
extern PyGLMTypeObject humat4x3GLMType;
extern PyTypeObject& humat4x3Type;

