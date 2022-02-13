#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef humvec3_methods[];
extern PyBufferProcs humvec3BufferMethods;
extern PySequenceMethods humvec3SeqMethods;
extern PyNumberMethods humvec3NumMethods;

extern PyTypeObject humvec3IterType;
extern PyGLMTypeObject humvec3GLMType;
extern PyTypeObject& humvec3Type;

