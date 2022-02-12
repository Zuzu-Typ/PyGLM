#pragma once

#include "types.h"

PyDoc_STRVAR(generic_copy_docstr,
	"Create a copy of this instance"
);

PyObject* generic_copy(PyObject* self, PyObject*);

PyDoc_STRVAR(generic_deepcopy_docstr,
	"Create a (deep)copy of this instance"
);

PyObject* generic_deepcopy(PyObject* self, PyObject* memo);

PyObject* generic_to_bytes(PyObject* self, PyObject*);

PyObject* generic_id(PyObject* self);
