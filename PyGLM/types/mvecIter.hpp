#pragma once

#include "types.h"

#include "mvec.hpp"

template<int L, typename T>
struct mvecIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	mvec<L, T>* sequence;
};
