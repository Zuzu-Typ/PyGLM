#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyGLM_MAKE_GLM_FUNC_V3V3__tfF(quatLookAt)
PyGLM_MAKE_GLM_FUNC_V3V3__tfF(quatLookAtLH)
PyGLM_MAKE_GLM_FUNC_V3V3__tfF(quatLookAtRH)



PyGLM_MAKE_GLM_FUNC_Q(eulerAngles)

PyGLM_MAKE_GLM_FUNC_Q(roll)
PyGLM_MAKE_GLM_FUNC_Q(pitch)
PyGLM_MAKE_GLM_FUNC_Q(yaw)

PyGLM_MAKE_GLM_FUNC_Q(mat3_cast)

PyGLM_MAKE_GLM_FUNC_Q(mat4_cast)

PyGLM_MAKE_GLM_FUNC_M3_M4__tfF(quat_cast)

PyDoc_STRVAR(eulerAngles_docstr, 
	"eulerAngles(x: quat) -> vec3\n"
	"	Returns euler angles, pitch as x, yaw as y, roll as z. The result is expressed in radians."
);
PyDoc_STRVAR(mat3_cast_docstr,
	"mat3_cast(x: quat) -> mat3\n"
	"	Converts a quaternion to a 3 x 3 matrix."
);
PyDoc_STRVAR(mat4_cast_docstr,
	"mat4_cast(x: quat) -> mat4\n"
	"	Converts a quaternion to a 4 x 4 matrix."
);
PyDoc_STRVAR(pitch_docstr,
	"pitch(x: quat) -> float\n"
	"	Returns pitch value of euler angles expressed in radians."
);
PyDoc_STRVAR(quat_cast_docstr,
	"quat_cast(x: mat3) -> quat\n"
	"	Converts a pure rotation 3 x 3 matrix to a quaternion.\n"
	"quat_cast(x: mat4) -> quat\n"
	"	Converts a pure rotation 4 x 4 matrix to a quaternion."
);
PyDoc_STRVAR(quatLookAt_docstr,
	"quatLookAt(direction: vec3, up: vec3) -> quat\n"
	"	See quatLookAtRH."
);
PyDoc_STRVAR(quatLookAtLH_docstr,
	"quatLookAtLH(direction: vec3, up: vec3) -> quat\n"
	"	Build a left-handed look at quaternion."
);
PyDoc_STRVAR(quatLookAtRH_docstr,
	"quatLookAtRH(direction: vec3, up: vec3) -> quat\n"
	"	Build a right-handed look at quaternion."
);
PyDoc_STRVAR(roll_docstr,
	"roll(x: quat) -> float\n"
	"	Returns roll value of euler angles expressed in radians."
);
PyDoc_STRVAR(yaw_docstr,
	"yaw(x: quat) -> float\n"
	"	Returns yaw value of euler angles expressed in radians."
);

#define QUATERNION_METHODS \
{ "quatLookAt", (PyCFunction)quatLookAt_, METH_VARARGS, quatLookAt_docstr }, \
{ "quatLookAtLH", (PyCFunction)quatLookAtLH_, METH_VARARGS, quatLookAtLH_docstr }, \
{ "quatLookAtRH", (PyCFunction)quatLookAtRH_, METH_VARARGS, quatLookAtRH_docstr }, \
{ "eulerAngles", (PyCFunction)eulerAngles_, METH_O, eulerAngles_docstr }, \
{ "roll", (PyCFunction)roll_, METH_O, roll_docstr }, \
{ "pitch", (PyCFunction)pitch_, METH_O, pitch_docstr }, \
{ "yaw", (PyCFunction)yaw_, METH_O, yaw_docstr }, \
{ "mat3_cast", (PyCFunction)mat3_cast_, METH_O, mat3_cast_docstr }, \
{ "mat4_cast", (PyCFunction)mat4_cast_, METH_O, mat4_cast_docstr }, \
{ "quat_cast", (PyCFunction)quat_cast_, METH_O, quat_cast_docstr }
