#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef himvec4_methods[];
extern PyBufferProcs himvec4BufferMethods;
extern PySequenceMethods himvec4SeqMethods;
extern PyNumberMethods himvec4NumMethods;

extern PyTypeObject himvec4IterType;
extern PyGLMTypeObject himvec4GLMType;
extern PyTypeObject& himvec4Type;

