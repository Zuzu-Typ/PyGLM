#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef himvec3_methods[];
extern PyBufferProcs himvec3BufferMethods;
extern PySequenceMethods himvec3SeqMethods;
extern PyNumberMethods himvec3NumMethods;

extern PyTypeObject himvec3IterType;
extern PyGLMTypeObject himvec3GLMType;
extern PyTypeObject& himvec3Type;

