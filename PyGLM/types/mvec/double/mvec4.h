#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef hdmvec4_methods[];
extern PyBufferProcs hdmvec4BufferMethods;
extern PySequenceMethods hdmvec4SeqMethods;
extern PyNumberMethods hdmvec4NumMethods;

extern PyTypeObject hdmvec4IterType;
extern PyGLMTypeObject hdmvec4GLMType;
extern PyTypeObject& hdmvec4Type;

