#pragma once

#include "../../compiler_setup.h"

#include "../function_generator_macros.h"

PyGLM_DECL_GLM_FUNC_N_V_Q__tfF(length)

PyGLM_DECL_GLM_FUNC_NN_VV__tfF(distance)

PyGLM_DECL_GLM_FUNC_NN_VV_QQ__tfF(dot)

PyObject* cross_(PyObject*, PyObject* args);

PyGLM_DECL_GLM_FUNC_V_Q__tfF(normalize)

PyGLM_DECL_GLM_FUNC_NNN_VVV__tfF(faceforward)

PyGLM_DECL_GLM_FUNC_NN_VV__tfF(reflect)

PyGLM_DECL_GLM_FUNC_NNN_VVN__tfF(refract)
