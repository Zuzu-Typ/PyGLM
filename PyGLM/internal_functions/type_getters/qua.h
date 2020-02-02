#pragma once

#include "../../compiler_setup.h"

template<typename T>
static PyTypeObject* PyGLM_QUA_TYPE() {
	if (std::is_same<qua<T>, qua<float> >::value) {
		return (PyTypeObject*)&hfquaType;
	}
	if (std::is_same<qua<T>, qua<double> >::value) {
		return (PyTypeObject*)&hdquaType;
	}
	return (PyTypeObject*)0;
}