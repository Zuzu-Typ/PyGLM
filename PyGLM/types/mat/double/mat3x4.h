#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat3x4_methods[];
extern PyBufferProcs hdmat3x4BufferMethods;
extern PySequenceMethods hdmat3x4SeqMethods;
extern PyMappingMethods hdmat3x4MapMethods;
extern PyNumberMethods hdmat3x4NumMethods;

extern PyTypeObject hdmat3x4IterType;
extern PyGLMTypeObject hdmat3x4GLMType;
extern PyTypeObject& hdmat3x4Type;

