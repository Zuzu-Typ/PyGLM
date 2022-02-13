#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat4x3_methods[];
extern PyBufferProcs hdmat4x3BufferMethods;
extern PySequenceMethods hdmat4x3SeqMethods;
extern PyMappingMethods hdmat4x3MapMethods;
extern PyNumberMethods hdmat4x3NumMethods;

extern PyTypeObject hdmat4x3IterType;
extern PyGLMTypeObject hdmat4x3GLMType;
extern PyTypeObject& hdmat4x3Type;

