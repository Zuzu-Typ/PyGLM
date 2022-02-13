#pragma once

#include "../compiler_setup.h"

#include "number_functions.h"


template<typename T>
inline PyObject* pack(T value) {
	static_assert(std::numeric_limits<T>::is_integer || std::numeric_limits<T>::is_iec559 || std::is_same<T, bool>::value,
		"this pack() only allows number / bool inputs. Make sure your import order is correct!");
	return PyGLM_PyObject_FromNumber<T>(value);
}
