#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat4x4_methods[];
extern PyBufferProcs hdmat4x4BufferMethods;
extern PySequenceMethods hdmat4x4SeqMethods;
extern PyMappingMethods hdmat4x4MapMethods;
extern PyNumberMethods hdmat4x4NumMethods;

extern PyTypeObject hdmat4x4IterType;
extern PyGLMTypeObject hdmat4x4GLMType;
extern PyTypeObject& hdmat4x4Type;

