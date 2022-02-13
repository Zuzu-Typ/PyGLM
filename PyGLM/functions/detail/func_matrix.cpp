#include "func_matrix.h"

#include "../vec_imports.h"
#include "../mat_imports.h"
#include "../qua_imports.h"

#include "../../internal_functions/type_checkers.h"
#include "../../internal_functions/helper_macros.h"
#include "../../internal_functions/error_functions.h"
#include "../../internal_functions/pack_mat.h"
#include "../../internal_functions/pack_qua.h"
#include "../../internal_functions/pack_number.h"

#include <glm/matrix.hpp>
#include <glm/ext/matrix_integer.hpp>
#include <glm/detail/type_quat.hpp>

PyObject*
outerProduct_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "outerProduct", arg1, arg2);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec2 o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec3 o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec2 o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec3 o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec4 o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec4 o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::dvec2 o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::dvec3 o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::dvec2 o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::dvec3 o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::dvec4 o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::dvec4 o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		return pack(glm::outerProduct(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for outerProduct(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_MM__tfF(matrixCompMult)

PyGLM_MAKE_GLM_FUNC_M(transpose)

PyGLM_MAKE_GLM_FUNC_S__tfF(determinant)

PyGLM_MAKE_GLM_FUNC_S_Q__tfF(inverse)
