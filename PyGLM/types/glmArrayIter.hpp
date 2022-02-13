#pragma once

#include "types.h"

struct glmArrayIter {
	PyObject_VAR_HEAD
		Py_ssize_t seq_index;
	glmArray* sequence;
};
