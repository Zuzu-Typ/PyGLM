#pragma once

#include "../build_options.h"

#include <Python.h>
#include "structmember.h"

#include <cstdlib>
#include <type_traits>
#include <stdint.h>
#include <clocale>
#include <algorithm>
#include <vector>

#define GLM_FORCE_CTOR_INIT
#define GLM_ENABLE_EXPERIMENTAL

#define GLM_FORCE_QUAT_DATA_WXYZ
#define GLM_LANG_STL11_FORCED

#include <glm/glm.hpp>

#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_integer.hpp>
#include <glm/gtx/hash.hpp>

#if !(PyGLM_BUILD & PyGLM_NO_FUNCTIONS)

// Stable extensions
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_common.hpp>
#include <glm/ext/matrix_integer.hpp>
#include <glm/ext/matrix_projection.hpp>
#include <glm/ext/matrix_relational.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/quaternion_common.hpp>
#include <glm/ext/quaternion_exponential.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/ext/quaternion_relational.hpp>
#include <glm/ext/quaternion_transform.hpp>
#include <glm/ext/quaternion_trigonometric.hpp>
#include <glm/ext/scalar_common.hpp>
#include <glm/ext/scalar_constants.hpp>
#include <glm/ext/scalar_relational.hpp>
#include <glm/ext/scalar_ulp.hpp>
#include <glm/ext/vector_common.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_ulp.hpp>

// Recommended extensions
#include <glm/gtc/color_space.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/gtc/integer.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtc/packing.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/reciprocal.hpp>
#include <glm/gtc/round.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/ulp.hpp>

// Unstable extensions
#include <glm/gtx/polar_coordinates.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/compatibility.hpp>

#endif

#include "compiler_setup.h"