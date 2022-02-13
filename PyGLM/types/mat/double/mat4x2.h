#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat4x2_methods[];
extern PyBufferProcs hdmat4x2BufferMethods;
extern PySequenceMethods hdmat4x2SeqMethods;
extern PyMappingMethods hdmat4x2MapMethods;
extern PyNumberMethods hdmat4x2NumMethods;

extern PyTypeObject hdmat4x2IterType;
extern PyGLMTypeObject hdmat4x2GLMType;
extern PyTypeObject& hdmat4x2Type;

