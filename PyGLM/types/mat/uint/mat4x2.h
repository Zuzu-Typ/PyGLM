#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat4x2_methods[];
extern PyBufferProcs humat4x2BufferMethods;
extern PySequenceMethods humat4x2SeqMethods;
extern PyMappingMethods humat4x2MapMethods;
extern PyNumberMethods humat4x2NumMethods;

extern PyTypeObject humat4x2IterType;
extern PyGLMTypeObject humat4x2GLMType;
extern PyTypeObject& humat4x2Type;

