#pragma once

#include "types.h"

template<typename T>
struct qua {
	PyObject_HEAD
		//uint8_t info;
		glm::qua<T> super_type;
};
