#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hfqua_methods[];
extern PyMemberDef hfqua_members[];
extern PyBufferProcs hfquaBufferMethods;
extern PySequenceMethods hfquaSeqMethods;
extern PyNumberMethods hfquaNumMethods;

extern PyTypeObject hfquaIterType;
extern PyGLMTypeObject hfquaGLMType;
extern PyTypeObject& hfquaType;

