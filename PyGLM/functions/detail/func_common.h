#pragma once

#include "../../compiler_setup.h"

#include "../function_generator_macros.h"

PyObject* abs_(PyObject*, PyObject* arg);

PyObject* sign_(PyObject*, PyObject* arg);

PyGLM_DECL_GLM_FUNC_N_V__tfF(floor)

PyGLM_DECL_GLM_FUNC_N_V__tfF(trunc)

PyGLM_DECL_GLM_FUNC_N_V__tfF(round)

PyGLM_DECL_GLM_FUNC_N_V__tfF(roundEven)

PyGLM_DECL_GLM_FUNC_N_V__tfF(ceil)

PyGLM_DECL_GLM_FUNC_N_V__tfF(fract)

PyGLM_DECL_GLM_FUNC_NN_VV_VN__tfF(mod)


PyObject* min_(PyObject*, PyObject* args);

PyObject* max_(PyObject*, PyObject* args);

PyObject* fmin_(PyObject*, PyObject* args);

PyObject* fmax_(PyObject*, PyObject* args);

PyObject* clamp_(PyObject*, PyObject* args);

PyObject* mix_(PyObject*, PyObject* args);

PyObject* step_(PyObject*, PyObject* args);

PyObject* smoothstep_(PyObject*, PyObject* args);

PyGLM_DECL_GLM_FUNC_N_V_Q__tfF(isnan)

PyGLM_DECL_GLM_FUNC_N_V_Q__tfF(isinf)

PyObject* fma_(PyObject*, PyObject* args);

PyObject* frexp_(PyObject*, PyObject* args);

PyObject* ldexp_(PyObject*, PyObject* args);

PyObject* floatBitsToInt_(PyObject*, PyObject* arg);

PyObject* floatBitsToUint_(PyObject*, PyObject* arg);

PyObject* intBitsToFloat_(PyObject*, PyObject* arg);

PyObject* uintBitsToFloat_(PyObject*, PyObject* arg);

PyObject* modf_(PyObject*, PyObject* args);


