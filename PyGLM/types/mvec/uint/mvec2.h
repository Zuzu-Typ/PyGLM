#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef humvec2_methods[];
extern PyBufferProcs humvec2BufferMethods;
extern PySequenceMethods humvec2SeqMethods;
extern PyNumberMethods humvec2NumMethods;

extern PyTypeObject humvec2IterType;
extern PyGLMTypeObject humvec2GLMType;
extern PyTypeObject& humvec2Type;

