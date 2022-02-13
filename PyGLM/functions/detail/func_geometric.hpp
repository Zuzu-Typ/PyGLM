#pragma once

#include "func_geometric.h"

PyDoc_STRVAR(length_docstr,
	"length(x: float) -> float\n"
	"	Returns the length of `x`, i.e., `abs(x)`.\n"
	"length(x: vecN) -> float\n"
	"	Returns the length of `x`, i.e., `sqrt(x * x)`.\n"
	"length(x: quat) -> float\n"
	"	Returns the norm of a quaternion."
);

PyDoc_STRVAR(distance_docstr,
	"distance(p0: float, p1: float) -> float\n"
	"	Returns the distance between `p0` and `p1`, i.e., `length(p0 - p1)`.\n"
	"distance(p0: vecN, p1: vecN) -> float\n"
	"	Returns the distance between `p0` and `p1`, i.e., `length(p0 - p1)`."
);

PyDoc_STRVAR(dot_docstr,
	"dot(x: float, y: float) -> float\n"
	"	Returns the dot product of `x` and `y`, i.e., `result = x * y`.\n"
	"dot(x: vecN, y: vecN) -> float\n"
	"	Returns the dot product of `x` and `y`, i.e., `result = x[0] * y[0] + x[1] * y[1] + ...`\n"
	"dot(x: quat, y: quat) -> float\n"
	"	Returns dot product of `x` and `y`, i.e., `x[0] * y[0] + x[1] * y[1] + ...`"
);

PyDoc_STRVAR(cross_docstr,
	"cross(x: vec3, y: vec3) -> vec3\n"
	"	Returns the cross product of `x` and `y`.\n"
	"cross(x: quat, y: quat) -> quat\n"
	"	Compute a cross product."
);

PyDoc_STRVAR(normalize_docstr,
	"normalize(x: vecN) -> vecN\n"
	"	Returns a vector in the same direction as `x` but with length of `1`.\n"
	"normalize(x: quat) -> quat\n"
	"	Returns the normalized quaternion."
);

PyDoc_STRVAR(faceforward_docstr,
	"faceforward(N: float, I: float, Nref: float) -> float\n"
	"	If `dot(Nref, I) < 0.0`, return `N`, otherwise, return `-N`.\n"
	"faceforward(N: vecN, I: vecN, Nref: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	If `dot(Nref[i], I[i]) < 0.0`, return `N[i]`, otherwise, return `-N[i]`."
);

PyDoc_STRVAR(reflect_docstr,
	"reflect(I: float, N: float) -> float\n"
	"	For the incident vector `I` and surface orientation `N`, returns the reflection direction:\n"
	"	`result = I - 2.0 * dot(N, I) * N`.\n"
	"reflect(I: vecN, N: vecN) -> vecN\n"
	"	For the incident vector `I` and surface orientation `N`, returns the reflection direction:\n"
	"	`result = I - 2.0 * dot(N, I) * N`."
);

PyDoc_STRVAR(refract_docstr,
	"refract(I: float, N: float, eta: float) -> float\n"
	"	For the incident vector `I` and surface normal `N`, and the ratio of indices of refraction `eta`,\n"
	"	return the refraction vector.\n"
	"refract(I: vecN, N: vecN, eta: float) -> vecN\n"
	"	For the incident vector `I` and surface normal `N`, and the ratio of indices of refraction `eta`,\n"
	"	return the refraction vector."
);

#define FUNC_GEOMETRIC_METHODS \
{ "length", (PyCFunction)length_, METH_O, length_docstr }, \
{ "distance", (PyCFunction)distance_, METH_VARARGS, distance_docstr }, \
{ "dot", (PyCFunction)dot_, METH_VARARGS, dot_docstr }, \
{ "cross", (PyCFunction)cross_, METH_VARARGS, cross_docstr }, \
{ "normalize", (PyCFunction)normalize_, METH_O, normalize_docstr }, \
{ "faceforward", (PyCFunction)faceforward_, METH_VARARGS, faceforward_docstr }, \
{ "reflect", (PyCFunction)reflect_, METH_VARARGS, reflect_docstr }, \
{ "refract", (PyCFunction)refract_, METH_VARARGS, refract_docstr }
