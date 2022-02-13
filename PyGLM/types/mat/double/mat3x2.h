#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat3x2_methods[];
extern PyBufferProcs hdmat3x2BufferMethods;
extern PySequenceMethods hdmat3x2SeqMethods;
extern PyMappingMethods hdmat3x2MapMethods;
extern PyNumberMethods hdmat3x2NumMethods;

extern PyTypeObject hdmat3x2IterType;
extern PyGLMTypeObject hdmat3x2GLMType;
extern PyTypeObject& hdmat3x2Type;

