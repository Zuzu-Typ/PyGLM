#pragma once

#include "types.h"

static PyObject* generic_copy(PyObject* self, PyObject*);

static PyObject* generic_deepcopy(PyObject* self, PyObject* memo);