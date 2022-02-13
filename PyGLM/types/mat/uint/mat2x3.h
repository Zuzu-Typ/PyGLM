#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat2x3_methods[];
extern PyBufferProcs humat2x3BufferMethods;
extern PySequenceMethods humat2x3SeqMethods;
extern PyMappingMethods humat2x3MapMethods;
extern PyNumberMethods humat2x3NumMethods;

extern PyTypeObject humat2x3IterType;
extern PyGLMTypeObject humat2x3GLMType;
extern PyTypeObject& humat2x3Type;

