#pragma once

#include "imports.h"

#if GLM_COMPILER & GLM_COMPILER_VC
#pragma warning(push)
#pragma warning(disable : 4127)
#elif GLM_COMPILER & GLM_COMPILER_GCC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#elif GLM_COMPILER & GLM_COMPILER_CLANG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif

#define UNBRACKET(...) __VA_ARGS__