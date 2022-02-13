
#include "func_exponential.h"

#include "../../compiler_setup.h"

#include "../../internal_functions/type_checkers.h"
#include "../../internal_functions/pack_vec.h"
#include "../../internal_functions/pack_qua.h"
#include "../../internal_functions/pack_number.h"
#include "../../internal_functions/number_functions.h"
#include "../../internal_functions/error_functions.h"

#include "../vec_imports.h"
#include "../qua_imports.h"

//#include "../../internal_functions/all.h"

#include <glm/detail/type_vec1.hpp>
#include <glm/detail/type_vec2.hpp>
#include <glm/detail/type_vec3.hpp>
#include <glm/detail/type_vec4.hpp>

#include <glm/detail/type_quat.hpp>

#include <glm/ext/quaternion_exponential.hpp>

PyObject* pow_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "pow", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::pow(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		return pack(glm::pow(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
	}

	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::pow(PyGLM_Qua_PTI_Get0(float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Number_Check(arg2)) {
		return pack(glm::pow(PyGLM_Qua_PTI_Get0(double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for pow(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(exp)

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(log)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(exp2)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(log2)

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(sqrt)

PyGLM_MAKE_GLM_FUNC_N_V__tfF(inversesqrt)
