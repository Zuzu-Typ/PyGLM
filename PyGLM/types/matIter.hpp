#pragma once

#include "types.h"

#include "mat.hpp"

template<int C, int R, typename T>
struct matIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	mat<C, R, T>* sequence;
};
