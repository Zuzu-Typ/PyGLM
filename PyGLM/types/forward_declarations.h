#pragma once

#include "types.h"

PyDoc_STRVAR(generic_copy_docstr,
	"Create a copy of this instance"
);

static PyObject* generic_copy(PyObject* self, PyObject*);

PyDoc_STRVAR(generic_deepcopy_docstr,
	"Create a (deep)copy of this instance"
);

static PyObject* generic_deepcopy(PyObject* self, PyObject* memo);

static PyObject* generic_to_bytes(PyObject* self, PyObject*);

static PyObject* generic_id(PyObject* self);
