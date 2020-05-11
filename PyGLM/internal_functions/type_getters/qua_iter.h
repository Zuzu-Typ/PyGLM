#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<typename T>
static PyTypeObject* PyGLM_QUAITER_TYPE() {
	return (std::is_same<quaIter<T>, quaIter<float> >::value) ? (PyTypeObject*)&hfquaIterType :
		(std::is_same<quaIter<T>, quaIter<double> >::value) ? (PyTypeObject*)&hdquaIterType :
		(PyTypeObject*)0;
}