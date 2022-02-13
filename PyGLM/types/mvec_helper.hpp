#pragma once

# include "types.h"

struct mvec_helper {
	PyObject_HEAD
		//uint8_t info;
		void* super_type;
	PyObject* master;
};
