#pragma once

#include "types.h"

#include "vec.hpp"

template<int L, typename T>
struct vecIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	vec<L, T>* sequence;
};
