#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef hfmvec3_methods[];
extern PyBufferProcs hfmvec3BufferMethods;
extern PySequenceMethods hfmvec3SeqMethods;
extern PyNumberMethods hfmvec3NumMethods;

extern PyTypeObject hfmvec3IterType;
extern PyGLMTypeObject hfmvec3GLMType;
extern PyTypeObject& hfmvec3Type;

