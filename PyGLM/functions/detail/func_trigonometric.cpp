
#include "func_trigonometric.h"

#include "../vec_imports.h"

#include "../../internal_functions/type_checkers.h"
#include "../../internal_functions/error_functions.h"
#include "../../internal_functions/number_functions.h"
#include "../../internal_functions/pack_vec.h"
#include "../../internal_functions/pack_number.h"

#include <glm/detail/type_vec1.hpp>
#include <glm/detail/type_vec2.hpp>
#include <glm/detail/type_vec3.hpp>
#include <glm/detail/type_vec4.hpp>

#include <glm/trigonometric.hpp>

PyGLM_MAKE_GLM_FUNC_N_V__tfF(radians)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(degrees)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(sin)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(cos)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(tan)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(asin)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(acos)

PyObject*
atan_(PyObject*, PyObject* args) {
	PyObject* arg1 = NULL, * arg2 = NULL;
	if (!PyArg_UnpackTuple(args, "atan", 1, 2, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for atan()");
		return NULL;
	}

	if (arg2 != NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::atan(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec1 o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::dvec1 o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::atan(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::atan(o, o2));
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for atan(): ", arg1, arg2);
		return NULL;
	}

	if (PyGLM_Number_Check(arg1)) {
		return pack(glm::atan(PyGLM_Number_FromPyObject<double>(arg1)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
		glm::vec1 o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
		glm::dvec1 o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		return pack(glm::atan(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		return pack(glm::atan(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type for atan(): ", arg1);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_N_V__tfF(sinh)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(cosh)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(tanh)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(asinh)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(acosh)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(atanh)