#pragma once

#include "../forward_declarations.h"

extern PyMethodDef humat2x2_methods[];
extern PyBufferProcs humat2x2BufferMethods;
extern PySequenceMethods humat2x2SeqMethods;
extern PyMappingMethods humat2x2MapMethods;
extern PyNumberMethods humat2x2NumMethods;

extern PyTypeObject humat2x2IterType;
extern PyGLMTypeObject humat2x2GLMType;
extern PyTypeObject& humat2x2Type;

