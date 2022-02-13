#pragma once

#include "types.h"

template<int L, typename T>
struct vec {
	PyObject_HEAD
		//uint8_t info;
		glm::vec<L, T> super_type;
};
