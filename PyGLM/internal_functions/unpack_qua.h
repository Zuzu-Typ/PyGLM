#pragma once

#include "../compiler_setup.h"

#include "type_getters/qua.h"

#include "helper_macros.h"

#include "type_checkers.h"

#include "template_generator_macros.h"

template<typename T>
bool unpack_qua(PyObject* value, glm::qua<T>& out) {
	if (PyObject_TypeCheck(value, (UNBRACKET(PyGLM_QUA_TYPE<T>())))) {
		out = ((qua<T>*)value)->super_type;
		return true;
	}
#if !(PyGLM_BUILD & PyGLM_NO_ITER_TYPECHECKING)
	PyGLM_PTI_Init3(value, (get_qua_PTI_info<T>()));
	if (PyGLM_Qua_PTI_Check3(T, value)) {
		out = PyGLM_Qua_PTI_Get3(T, value);
		return true;
	}
#endif
	return false;
}

#define unpack_qua_ref_TEMPLATE(T) template bool unpack_qua(PyObject* value, glm::qua<T>& out)
PyGLM_GENERATE_EXTERN_TEMPLATE_QUA(unpack_qua_ref_TEMPLATE);

template<typename T>
glm::qua<T> unpack_qua(PyObject* value) {
	glm::qua<T> out;
	unpack_qua(value, out);
	return out;
}

#define unpack_qua_TEMPLATE(T) template glm::qua<T> unpack_qua(PyObject* value)
PyGLM_GENERATE_EXTERN_TEMPLATE_QUA(unpack_qua_TEMPLATE);
