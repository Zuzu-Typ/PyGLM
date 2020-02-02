#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_V3__tfF(polar)
PyGLM_MAKE_GLM_FUNC_V2__tfF(euclidean)

#define POLAR_COORDINATES_METHODS { "polar", (PyCFunction)polar_, METH_O, "polar(v) -> vec3\nConvert Euclidean to Polar coordinates, x is the xz distance, y, the latitude and z the longitude." }, \
{ "euclidean", (PyCFunction)euclidean_, METH_O, "euclidean(v) -> vec3\nConvert Polar to Euclidean coordinates." }
