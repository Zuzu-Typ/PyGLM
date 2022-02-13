#include "func_geometric.h"

#include "../vec_imports.h"
#include "../qua_imports.h"

#include "../../internal_functions/type_checkers.h"
#include "../../internal_functions/helper_macros.h"
#include "../../internal_functions/error_functions.h"
#include "../../internal_functions/pack_vec.h"
#include "../../internal_functions/pack_qua.h"
#include "../../internal_functions/pack_number.h"

#include <glm/geometric.hpp>
#include <glm/ext/quaternion_geometric.hpp>

#include <glm/detail/type_quat.hpp>

PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(length)

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(distance)

PyGLM_MAKE_GLM_FUNC_NN_VV_QQ__tfF(dot)

PyObject*
cross_(PyObject*, PyObject* args) {
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "cross", arg1, arg2);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_3 | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
		glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
		glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
		return pack(glm::cross(o, o2));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
		glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
		glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
		return pack(glm::cross(o, o2));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for cross(): ", arg1, arg2);
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_V_Q__tfF(normalize)

PyGLM_MAKE_GLM_FUNC_NNN_VVV__tfF(faceforward)

PyGLM_MAKE_GLM_FUNC_NN_VV__tfF(reflect)

PyGLM_MAKE_GLM_FUNC_NNN_VVN__tfF(refract)
