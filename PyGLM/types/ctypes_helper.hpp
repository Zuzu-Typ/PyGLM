#pragma once

#include "types.h"

struct ctypes_helper {
	PyObject_HEAD
		void* b_ptr;                /* pointer to memory block */
};
