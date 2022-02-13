#pragma once

#include "../forward_declarations.h"

#include "../../vec/all.h"

#include "../../../types/PyGLMTypeObject.hpp"

#include "../../../types/mvec.hpp"
#include "../../../types/mvecIter.hpp"

extern PyMethodDef hdmvec2_methods[];
extern PyBufferProcs hdmvec2BufferMethods;
extern PySequenceMethods hdmvec2SeqMethods;
extern PyNumberMethods hdmvec2NumMethods;

extern PyTypeObject hdmvec2IterType;
extern PyGLMTypeObject hdmvec2GLMType;
extern PyTypeObject& hdmvec2Type;
