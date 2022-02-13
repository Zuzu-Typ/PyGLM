#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef himvec2_methods[];
extern PyBufferProcs himvec2BufferMethods;
extern PySequenceMethods himvec2SeqMethods;
extern PyNumberMethods himvec2NumMethods;

extern PyTypeObject himvec2IterType;
extern PyGLMTypeObject himvec2GLMType;
extern PyTypeObject& himvec2Type;

