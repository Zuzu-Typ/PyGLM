#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef hfmvec4_methods[];
extern PyBufferProcs hfmvec4BufferMethods;
extern PySequenceMethods hfmvec4SeqMethods;
extern PyNumberMethods hfmvec4NumMethods;

extern PyTypeObject hfmvec4IterType;
extern PyGLMTypeObject hfmvec4GLMType;
extern PyTypeObject& hfmvec4Type;

