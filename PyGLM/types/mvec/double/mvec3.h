#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

extern PyMethodDef hdmvec3_methods[];
extern PyBufferProcs hdmvec3BufferMethods;
extern PySequenceMethods hdmvec3SeqMethods;
extern PyNumberMethods hdmvec3NumMethods;

extern PyTypeObject hdmvec3IterType;
extern PyGLMTypeObject hdmvec3GLMType;
extern PyTypeObject& hdmvec3Type;

