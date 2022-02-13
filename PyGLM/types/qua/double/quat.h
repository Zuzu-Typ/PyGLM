#pragma once

#include "../forward_declarations.h"

extern PyMethodDef hdqua_methods[];
extern PyMemberDef hdqua_members[];
extern PyBufferProcs hdquaBufferMethods;
extern PySequenceMethods hdquaSeqMethods;
extern PyNumberMethods hdquaNumMethods;

extern PyTypeObject hdquaIterType;
extern PyGLMTypeObject hdquaGLMType;
extern PyTypeObject& hdquaType;

