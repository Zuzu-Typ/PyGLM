#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

template<typename T>
static constexpr PyTypeObject* PyGLM_QUA_TYPE() {
	return (std::is_same<qua<T>, qua<float> >::value) ? (PyTypeObject*)&hfquaType :
		(std::is_same<qua<T>, qua<double> >::value) ? (PyTypeObject*)&hdquaType :
		(PyTypeObject*)0;
}