#pragma once

#include "../../compiler_setup.h"

PyObject*
packDouble2x32_(PyObject*, PyObject* arg);

PyObject*
packUnorm2x16_(PyObject*, PyObject* arg);

PyObject*
packSnorm2x16_(PyObject*, PyObject* arg);

PyObject*
packUnorm4x8_(PyObject*, PyObject* arg);

PyObject*
packSnorm4x8_(PyObject*, PyObject* arg);

PyObject*
packHalf2x16_(PyObject*, PyObject* arg);

PyObject*
unpackDouble2x32_(PyObject*, PyObject* arg);

PyObject*
unpackUnorm2x16_(PyObject*, PyObject* arg);

PyObject*
unpackSnorm2x16_(PyObject*, PyObject* arg);

PyObject*
unpackUnorm4x8_(PyObject*, PyObject* arg);

PyObject*
unpackSnorm4x8_(PyObject*, PyObject* arg);

PyObject*
unpackHalf2x16_(PyObject*, PyObject* arg);
