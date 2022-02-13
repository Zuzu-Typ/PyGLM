#include "pack_vec.h"
#include "pack_mvec.h"
#include "pack_mat.h"
#include "pack_qua.h"

#include <glm/detail/type_vec1.hpp>
#include <glm/detail/type_vec2.hpp>
#include <glm/detail/type_vec3.hpp>
#include <glm/detail/type_vec4.hpp>

#include <glm/detail/type_mat2x2.hpp>
#include <glm/detail/type_mat2x3.hpp>
#include <glm/detail/type_mat2x4.hpp>
#include <glm/detail/type_mat3x2.hpp>
#include <glm/detail/type_mat3x3.hpp>
#include <glm/detail/type_mat3x4.hpp>
#include <glm/detail/type_mat4x2.hpp>
#include <glm/detail/type_mat4x3.hpp>
#include <glm/detail/type_mat4x4.hpp>

#include <glm/detail/type_quat.hpp>

PyGLM_GENERATE_TEMPLATE_DEF_VEC(pack_vec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MVEC(pack_mvec_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_MAT(pack_mat_TEMPLATE);
PyGLM_GENERATE_TEMPLATE_DEF_QUA(pack_qua_TEMPLATE);
