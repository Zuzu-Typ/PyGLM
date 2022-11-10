#pragma once

#include "../../compiler_setup.h"
#include "../../internal_functions/all.h"

PyDoc_STRVAR(quat_to_vec4_docstr,
	"quat_to_vec4(quat) -> vec4\n"
	"	Component wise conversion of quat to vec4."
);
static PyObject*
quat_to_vec4_(PyObject*, PyObject* arg) {
	if (Py_TYPE(arg) == PyGLM_QUA_TYPE<float>()) {
		glm::qua<float> q = unpack_qua<float>(arg);
		return pack(glm::vec<4, float>(q.x, q.y, q.z, q.w));
	}
	
	if (Py_TYPE(arg) == PyGLM_QUA_TYPE<double>()) {
		glm::qua<double> q = unpack_qua<double>(arg);
		return pack(glm::vec<4, double>(q.x, q.y, q.z, q.w));
	}
	
	PyGLM_TYPEERROR_O("Invalid argument type for 'quat_to_vec4'. Expected 'quat', got ", arg);
	return NULL;
}

PyDoc_STRVAR(vec4_to_quat_docstr,
	"vec4_to_quat(vec4) -> quat\n"
	"	Component wise conversion of vec4 to quat."
);
static PyObject*
vec4_to_quat_(PyObject*, PyObject* arg) {
	if (Py_TYPE(arg) == PyGLM_VEC_TYPE<4, float>()) {
		glm::vec<4, float> v = unpack_vec<4, float>(arg);
		return pack(glm::qua<float>(v.w, v.x, v.y, v.z));
	}
	
	if (Py_TYPE(arg) == PyGLM_VEC_TYPE<4, double>()) {
		glm::vec<4, double> v = unpack_vec<4, double>(arg);
		return pack(glm::qua<double>(v.w, v.x, v.y, v.z));
	}
	
	PyGLM_TYPEERROR_O("Invalid argument type for 'vec4_to_quat'. Expected 'vec4', got ", arg);
	return NULL;
}

#define CUSTOM_METHODS \
{ "quat_to_vec4", (PyCFunction)quat_to_vec4_, METH_O, quat_to_vec4_docstr }, \
{ "vec4_to_quat", (PyCFunction)vec4_to_quat_, METH_O, vec4_to_quat_docstr }
