#include <Python.h>
#include "structmember.h"
#include <math.h>
#include <stdbool.h>

#define PY3K (PY_VERSION_HEX >= 0x03000000)

#include "glmtypes.h"

#include "glminternalfuncs.h"

#include "_vectorize.h"

#include "func_vector_relational.h"

#include "func_exponential.h"

#include "func_common.h"

#include "func_geometric.h"

#include "func_matrix.h"

// tvec2
#include "type_vec2.h"

// tvec3
#include "type_vec3.h"

// tvec4
#include "type_vec4.h"

// tmat2x2
#include "type_mat2x2.h"

// tmat2x3
#include "type_mat2x3.h"

// tmat2x4
#include "type_mat2x4.h"

// tmat3x2
#include "type_mat3x2.h"

// tmat3x3
#include "type_mat3x3.h"

// tmat3x4
#include "type_mat3x4.h"

// tmat4x2
#include "type_mat4x2.h"

// tmat4x3
#include "type_mat4x3.h"

// tmat4x4
#include "type_mat4x4.h"

static PyMethodDef glmmethods[] = {
	// func_vector_relational
	{ "equal", (PyCFunction)equal, METH_VARARGS, "equal(x, y) -> (x == y)\nReturns the component-wise comparison of result x == y." },
	{ "notEqual", (PyCFunction)notEqual, METH_VARARGS, "notEqual(x, y) -> (x != y)\nReturns the component-wise comparison of result x != y." },
	{ "lessThan", (PyCFunction)lessThan, METH_VARARGS, "lessThan(x, y) -> (x < y)\nReturns the component-wise comparison of result x < y." },
	{ "lessThanEqual", (PyCFunction)lessThanEqual, METH_VARARGS, "lessThanEqual(x, y) -> (x <= y)\nReturns the component-wise comparison of result x <= y." },
	{ "greaterThan", (PyCFunction)greaterThan, METH_VARARGS, "greaterThan(x, y) -> (x > y)\nReturns the component-wise comparison of result x > y." },
	{ "greaterThanEqual", (PyCFunction)greaterThanEqual, METH_VARARGS, "greaterThanEqual(x, y) -> (x >= y)\nReturns the component-wise comparison of result x >= y." },
	{ "any", (PyCFunction)any, METH_O, "any(x) -> bool\nReturns true if any component of x is true." },
	{ "all", (PyCFunction)all, METH_O, "all(x) -> bool\nReturns true if all components of x are true." },
	{ "not_", (PyCFunction)not_, METH_O, "not(x) -> bool\nReturns the component-wise logical complement of x." },

	// func_exponential
	{ "pow", (PyCFunction)pow_, METH_VARARGS, "pow(base, exponent) -> float or tvecn\nReturns 'base' raised to the power 'exponent'." },
	{ "exp", (PyCFunction)exp_, METH_O, "exp(x) -> float or tvecn\nReturns the natural exponentiation of x, i.e., e^x." },
	{ "log", (PyCFunction)log_, METH_O, "log(v) -> float or tvecn\nReturns the natural logarithm of v, i.e.,\nreturns the value y which satisfies the equation x = e^y.\nResults are undefined if v <= 0." },
	{ "exp2", (PyCFunction)exp2_, METH_O, "exp2(v) -> float or tvecn\nReturns 2 raised to the v power." },
	{ "log2", (PyCFunction)log2_, METH_O, "log2(x) -> float or tvecn\nReturns the base 2 log of x, i.e., returns the value y,\nwhich satisfies the equation x = 2 ^ y." },
	{ "sqrt", (PyCFunction)sqrt_, METH_O, "sqrt(v) -> float or tvecn\nReturns the positive square root of v." },
	{ "inversesqrt", (PyCFunction)inversesqrt_, METH_O, "inversesqrt(v) -> float or tvecn\nReturns the reciprocal of the positive square root of v." },

	// func_common
	{ "abs", (PyCFunction)abs_, METH_O, "abs(x) -> float or tvecn\nReturns x if x >= 0; otherwise, it returns -x." },
	{ "sign", (PyCFunction)sign_, METH_O, "sign(x) -> float or tvecn\nReturns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0. " },
	{ "floor", (PyCFunction)floor_, METH_O, "floor(x) -> float or tvecn\nReturns a value equal to the nearest integer that is less then or equal to x." },
	{ "trunc", (PyCFunction)trunc_, METH_O, "trunc(x) -> float or tvecn\nReturns a value equal to the nearest integer to x\nwhose absolute value is not larger than the absolute value of x." },
	{ "round", (PyCFunction)round_, METH_O, "round(x) -> float or tvecn\nReturns a value equal to the nearest integer to x.\nThe fraction 0.5 will round in a direction chosen by the\nimplementation, presumably the direction that is fastest.\nThis includes the possibility that round(x) returns the\nsame value as roundEven(x) for all values of x." },
	{ "roundEven", (PyCFunction)roundEven_, METH_O, "roundEven(x) -> float or tvecn\nReturns a value equal to the nearest integer to x.\nA fractional part of 0.5 will round toward the nearest even\ninteger. (Both 3.5 and 4.5 for x will return 4.0.)" },
	{ "ceil", (PyCFunction)ceil_, METH_O, "ceil(x) -> float or tvecn\nReturns a value equal to the nearest integer\nthat is greater than or equal to x." },
	{ "fract", (PyCFunction)fract_, METH_O, "fract(x) -> float or tvecn\nReturn x - floor(x)." },
	{ "mod", (PyCFunction)mod_, METH_VARARGS, "mod(x, y) -> float or tvecn\nModulus. Returns x - y * floor(x / y)\nfor each component in x using the floating point value y." },
	{ "min", (PyCFunction)min_, METH_VARARGS, "min(x, y) -> float or tvecn\nReturns y if y < x; otherwise, it returns x." },
	{ "max", (PyCFunction)max_, METH_VARARGS, "max(x, y) -> float or tvecn\nReturns y if x < y; otherwise, it returns x." },
	{ "clamp", (PyCFunction)clamp_, METH_VARARGS, "clamp(x, minVal, maxVal) -> float or tvecn\nReturns min(max(x, minVal), maxVal) for each component in x\nusing the floating-point values minVal and maxVal." },
	{ "mix", (PyCFunction)mix_, METH_VARARGS, "mix(x, y, a) -> float or tvecn\nIf type(a) is a floating scalar or vector:\nReturns x * (1.0 - a) + y * a, i.e., the linear blend of\nx and y using the floating-point value a.\nThe value for a is not restricted to the range [0, 1]." },
	{ "step", (PyCFunction)step_, METH_VARARGS, "step(edge, x) -> Returns 0.0 if x < edge, otherwise it returns 1.0." },
	{ "smoothstep", (PyCFunction)smoothstep_, METH_VARARGS, "smoothstep(edge0, edge1, x) -> float or tvecn\nReturns 0.0 if x <= edge0 and 1.0 if x >= edge1 and\nperforms smooth Hermite interpolation between 0 and 1\nwhen edge0 < x < edge1. This is useful in cases where\nyou would want a threshold function with a smooth\ntransition." },
	{ "isnan", (PyCFunction)isnan_, METH_O, "isnan(x) -> bool or tvecn\nReturns true if x holds a NaN (not a number)\nrepresentation in the underlying implementation's set of\nfloating point representations. Returns false otherwise,\nincluding for implementations with no NaN\nrepresentations." },
	{ "isinf", (PyCFunction)isinf_, METH_O, "isinf(x) -> bool or tvecn\nReturns true if x holds a positive infinity or negative\ninfinity representation in the underlying implementation's\nset of floating point representations. Returns false\notherwise, including for implementations with no infinity\nrepresentations." },
	{ "fma", (PyCFunction)fma_, METH_VARARGS, "smoothstep(a, b, c) -> float\nComputes and returns a * b + c." },
	{ "frexp", (PyCFunction)frexp_, METH_VARARGS, "frexp(x, exp) -> float or tvecn\nSplits x into a floating-point significand in the range\n[0.5, 1.0) and an integral exponent of two, such that:\nx = significand * exp(2, exponent)" },
	{ "ldexp", (PyCFunction)ldexp_, METH_VARARGS, "ldexp(x, exp) -> float or tvecn\nBuilds a floating-point number from x and the\ncorresponding integral exponent of two in exp, returning:\nsignificand * exp(2, exponent)" },
	
	// func_geometric
	{ "length", (PyCFunction)length, METH_O, "length(x) -> float\nReturns the length of x, i.e., sqrt(x * x)." },
	{ "distance", (PyCFunction)distance, METH_VARARGS, "distance(p0, p1) -> float\nReturns the distance betwwen p0 and p1, i.e., length(p0 - p1)." },
	{ "dot", (PyCFunction)dot, METH_VARARGS, "dot(x, y) -> float\nReturns the dot product of x and y, i.e., result = x * y." },
	{ "cross", (PyCFunction)cross, METH_VARARGS, "cross(x, y) -> tvec3\nReturns the cross product of x and y." },
	{ "normalize", (PyCFunction)normalize, METH_O, "normalize(x) -> float or tvecn\nReturns a vector in the same direction as x but with length of 1." },
	{ "faceforward", (PyCFunction)faceforward, METH_VARARGS, "faceforward(N, I, Nref) -> float or tvecn\nIf dot(Nref, I) < 0.0, return N, otherwise, return -N." },
	{ "reflect", (PyCFunction)reflect, METH_VARARGS, "reflect(I, N) -> float or tvecn\nFor the incident vector I and surface orientation N,\nreturns the reflection direction : result = I - 2.0 * dot(N, I) * N." },
	{ "refract", (PyCFunction)refract, METH_VARARGS, "refract(I, N, eta) -> float or tvecn\nFor the incident vector I and surface normal N,\nand the ratio of indices of refraction eta,\nreturn the refraction vector." },
	
	// func_matrix
	{ "matrixCompMult", (PyCFunction)matrixCompMult, METH_VARARGS, "matrixCompMult(x, y) -> tmatnxn\nMultiply matrix x by matrix y component-wise, i.e.,\nresult[i][j] is the scalar product of x[i][j] and y[i][j]." },
	{ "outerProduct", (PyCFunction)outerProduct, METH_VARARGS, "outerProduct(c, r) -> tmatnxn\nTreats the first parameter c as a column vector\nand the second parameter r as a row vector\nand does a linear algebraic matrix multiply c * r." },
	{ "transpose", (PyCFunction)transpose, METH_O, "transpose(x) -> tmatnxn\nReturns the transposed matrix of x" },
	{ "determinant", (PyCFunction)determinant, METH_O, "determinant(x) -> float\nReturn the determinant of a squared matrix." },
	{ "inverse", (PyCFunction)inverse, METH_O, "inverse(x) -> tmatnxn\nReturn the inverse of a squared matrix." },
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef glmmodule = {
    PyModuleDef_HEAD_INIT,
    "glm",
    "Features that implement in Python the GLSL specification as closely as necessary.",
    -1,
	glmmethods, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_glm(void)
{
    PyObject* m;

	if (PyType_Ready(&tvec2Type) < 0 || PyType_Ready(&tvec2IterType) < 0
		|| PyType_Ready(&tvec3Type) < 0 || PyType_Ready(&tvec3IterType) < 0
		|| PyType_Ready(&tvec4Type) < 0 || PyType_Ready(&tvec4IterType) < 0
		|| PyType_Ready(&tmat2x2Type) < 0 || PyType_Ready(&tmat2x2IterType) < 0
		|| PyType_Ready(&tmat2x3Type) < 0 || PyType_Ready(&tmat2x3IterType) < 0
		|| PyType_Ready(&tmat2x4Type) < 0 || PyType_Ready(&tmat2x4IterType) < 0
		|| PyType_Ready(&tmat3x2Type) < 0 || PyType_Ready(&tmat3x2IterType) < 0
		|| PyType_Ready(&tmat3x3Type) < 0 || PyType_Ready(&tmat3x3IterType) < 0
		|| PyType_Ready(&tmat3x4Type) < 0 || PyType_Ready(&tmat3x4IterType) < 0
		|| PyType_Ready(&tmat4x2Type) < 0 || PyType_Ready(&tmat4x2IterType) < 0
		|| PyType_Ready(&tmat4x3Type) < 0 || PyType_Ready(&tmat4x3IterType) < 0
		|| PyType_Ready(&tmat4x4Type) < 0 || PyType_Ready(&tmat4x4IterType) < 0)
		return NULL;

    m = PyModule_Create(&glmmodule);
    if (m == NULL)
        return NULL;

	Py_INCREF(&tvec2Type);
	PyModule_AddObject(m, "vec2", (PyObject *)&tvec2Type);

    Py_INCREF(&tvec3Type);
    PyModule_AddObject(m, "vec3", (PyObject *)&tvec3Type);

	Py_INCREF(&tvec4Type);
	PyModule_AddObject(m, "vec4", (PyObject *)&tvec4Type);

	Py_INCREF(&tvec2Type);
	PyModule_AddObject(m, "tvec2", (PyObject *)&tvec2Type);

	Py_INCREF(&tvec3Type);
	PyModule_AddObject(m, "tvec3", (PyObject *)&tvec3Type);

	Py_INCREF(&tvec4Type);
	PyModule_AddObject(m, "tvec4", (PyObject *)&tvec4Type);

	Py_INCREF(&tmat2x2Type);
	PyModule_AddObject(m, "tmat2x2", (PyObject *)&tmat2x2Type);

	Py_INCREF(&tmat2x2Type);
	PyModule_AddObject(m, "mat2", (PyObject *)&tmat2x2Type);

	Py_INCREF(&tmat2x3Type);
	PyModule_AddObject(m, "tmat2x3", (PyObject *)&tmat2x3Type);

	Py_INCREF(&tmat2x4Type);
	PyModule_AddObject(m, "tmat2x4", (PyObject *)&tmat2x4Type);

	Py_INCREF(&tmat3x2Type);
	PyModule_AddObject(m, "tmat3x2", (PyObject *)&tmat3x2Type);

	Py_INCREF(&tmat3x3Type);
	PyModule_AddObject(m, "tmat3x3", (PyObject *)&tmat3x3Type);

	Py_INCREF(&tmat3x3Type);
	PyModule_AddObject(m, "mat3", (PyObject *)&tmat3x3Type);

	Py_INCREF(&tmat3x4Type);
	PyModule_AddObject(m, "tmat3x4", (PyObject *)&tmat3x4Type);

	Py_INCREF(&tmat4x2Type);
	PyModule_AddObject(m, "tmat4x2", (PyObject *)&tmat4x2Type);

	Py_INCREF(&tmat4x3Type);
	PyModule_AddObject(m, "tmat4x3", (PyObject *)&tmat4x3Type);

	Py_INCREF(&tmat4x4Type);
	PyModule_AddObject(m, "tmat4x4", (PyObject *)&tmat4x4Type);

	Py_INCREF(&tmat4x4Type);
	PyModule_AddObject(m, "mat4", (PyObject *)&tmat4x4Type);

    return m;
}