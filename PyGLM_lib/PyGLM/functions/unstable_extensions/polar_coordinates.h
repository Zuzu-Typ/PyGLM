#pragma once

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_V3__tfF(polar)
PyGLM_MAKE_GLM_FUNC_V2__tfF(euclidean)

PyDoc_STRVAR(euclidean_docstr,
	"euclidean(polar: vec2) -> vec3\n"
	"	Convert Polar to Euclidean coordinates."
);
PyDoc_STRVAR(polar_docstr,
	"polar(euclidean: vec3) -> vec3\n"
	"	Convert Euclidean to Polar coordinates, x is the xz distance, y, the latitude and z the longitude."
);

#define POLAR_COORDINATES_METHODS \
{ "polar", (PyCFunction)polar_, METH_O, polar_docstr }, \
{ "euclidean", (PyCFunction)euclidean_, METH_O, euclidean_docstr }
