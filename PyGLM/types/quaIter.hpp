#pragma once

#include "types.h"

#include "qua.hpp"

template<typename T>
struct quaIter {
	PyObject_VAR_HEAD
		glm::length_t seq_index;
	qua<T>* sequence;
};
