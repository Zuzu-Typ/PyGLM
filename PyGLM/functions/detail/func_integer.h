#pragma once

#include "../../compiler_setup.h"


PyObject*
uaddCarry_(PyObject*, PyObject* args);

PyObject*
usubBorrow_(PyObject*, PyObject* args);

PyObject*
umulExtended_(PyObject*, PyObject* args);

PyObject*
imulExtended_(PyObject*, PyObject* args);

PyObject*
bitfieldExtract_(PyObject*, PyObject* args);

PyObject*
bitfieldInsert_(PyObject*, PyObject* args);

PyObject* bitfieldReverse_(PyObject*, PyObject* arg);

PyObject*
bitCount_(PyObject*, PyObject* arg);

PyObject*
findLSB_(PyObject*, PyObject* arg);

PyObject*
findMSB_(PyObject*, PyObject* arg);
