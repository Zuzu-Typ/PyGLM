#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat2x4_methods[];
extern PyBufferProcs hdmat2x4BufferMethods;
extern PySequenceMethods hdmat2x4SeqMethods;
extern PyMappingMethods hdmat2x4MapMethods;
extern PyNumberMethods hdmat2x4NumMethods;

extern PyTypeObject hdmat2x4IterType;

extern PyGLMTypeObject hdmat2x4GLMType;

extern PyTypeObject& hdmat2x4Type;


