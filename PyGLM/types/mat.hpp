#pragma once

#include "types.h"

template<int C, int R, typename T>
struct mat {
	PyObject_HEAD
		//uint8_t info;
		glm::mat<C, R, T> super_type;
};
