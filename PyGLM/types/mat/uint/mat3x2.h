#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat3x2_methods[];
extern PyBufferProcs humat3x2BufferMethods;
extern PySequenceMethods humat3x2SeqMethods;
extern PyMappingMethods humat3x2MapMethods;
extern PyNumberMethods humat3x2NumMethods;

extern PyTypeObject humat3x2IterType;
extern PyGLMTypeObject humat3x2GLMType;
extern PyTypeObject& humat3x2Type;

