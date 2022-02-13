#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef hfmvec2_methods[];
extern PyBufferProcs hfmvec2BufferMethods;
extern PySequenceMethods hfmvec2SeqMethods;
extern PyNumberMethods hfmvec2NumMethods;

extern PyTypeObject hfmvec2IterType;
extern PyGLMTypeObject hfmvec2GLMType;
extern PyTypeObject& hfmvec2Type;

