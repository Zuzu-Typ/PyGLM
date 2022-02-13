#pragma once

#include "../../compiler_setup.h"

#include "../function_generator_macros.h"

PyObject*
equal(PyObject*, PyObject* args);

PyObject*
notEqual(PyObject*, PyObject* args);

PyGLM_DECL_GLM_FUNC_VV_QQ(lessThan)

PyGLM_DECL_GLM_FUNC_VV_QQ(lessThanEqual)

PyGLM_DECL_GLM_FUNC_VV_QQ(greaterThan)

PyGLM_DECL_GLM_FUNC_VV_QQ(greaterThanEqual)

PyObject*
any(PyObject*, PyObject* arg);

PyObject*
all(PyObject*, PyObject* arg);

PyObject*
not_(PyObject*, PyObject* arg);
