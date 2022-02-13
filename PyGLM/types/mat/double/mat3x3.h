#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat3x3_methods[];
extern PyBufferProcs hdmat3x3BufferMethods;
extern PySequenceMethods hdmat3x3SeqMethods;
extern PyMappingMethods hdmat3x3MapMethods;
extern PyNumberMethods hdmat3x3NumMethods;

extern PyTypeObject hdmat3x3IterType;
extern PyGLMTypeObject hdmat3x3GLMType;
extern PyTypeObject& hdmat3x3Type;

