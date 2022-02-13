#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat2x3_methods[];
extern PyBufferProcs hdmat2x3BufferMethods;
extern PySequenceMethods hdmat2x3SeqMethods;
extern PyMappingMethods hdmat2x3MapMethods;
extern PyNumberMethods hdmat2x3NumMethods;

extern PyTypeObject hdmat2x3IterType;

extern PyGLMTypeObject hdmat2x3GLMType;

extern PyTypeObject& hdmat2x3Type;

