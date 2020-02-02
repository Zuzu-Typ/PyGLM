#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<typename T>
static PyTypeObject* PyGLM_QUAITER_TYPE() {
	if (std::is_same<quaIter<T>, quaIter<float> >::value) {
		return (PyTypeObject*)&hfquaIterType;
	}
	if (std::is_same<quaIter<T>, quaIter<double> >::value) {
		return (PyTypeObject*)&hdquaIterType;
	}
	return (PyTypeObject*)0;
}