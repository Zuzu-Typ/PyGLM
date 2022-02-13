#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdmat2x2_methods[];
extern PyBufferProcs hdmat2x2BufferMethods;
extern PySequenceMethods hdmat2x2SeqMethods;
extern PyMappingMethods hdmat2x2MapMethods;
extern PyNumberMethods hdmat2x2NumMethods;

extern PyTypeObject hdmat2x2IterType;
extern PyGLMTypeObject hdmat2x2GLMType;
extern PyTypeObject& hdmat2x2Type;


