#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef humvec4_methods[];
extern PyBufferProcs humvec4BufferMethods;
extern PySequenceMethods humvec4SeqMethods;
extern PyNumberMethods humvec4NumMethods;

extern PyTypeObject humvec4IterType;
extern PyGLMTypeObject humvec4GLMType;
extern PyTypeObject& humvec4Type;

