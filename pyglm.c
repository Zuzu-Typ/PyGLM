#include <Python.h>
#include "structmember.h"
#include <math.h>
#include <stdbool.h>

#define PY3K (PY_VERSION_HEX >= 0x03000000)

#if PY3K
#define Py_TPFLAGS_CHECKTYPES 0
#endif

PyObject* c_void_p = NULL;

#include "glmtypes.h"

#include "glminternalfuncs.h"

#include "_vectorize.h"

#include "func_vector_relational.h"

#include "func_exponential.h"

#include "func_common.h"

#include "func_geometric.h"

#include "func_matrix.h"

#include "func_trigonometric.h"

#include "_noise.h"

//gtc
#include "color_space.h"

#include "constants.h"

#include "quaternion.h"

#include "matrix_transform.h"

#include "epsilon.h"

#include "matrix_access.h"

#include "noise.h"

#include "random.h"

#include "reciprocal.h"

#include "type_ptr.h"

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

//static PyObject* test(PyObject* self, PyObject* arg) {
//	tmat2x2* o;
//	o = (tmat2x2*)(&tmat2x2Type)->tp_alloc(&tmat2x2Type, 0);
//	o->x = (tvec2*)pack_tvec2(0, 0);
//	o->y = (tvec2*)pack_tvec2(0, 0);
//	return (PyObject*)o;
//	//return PyObject_GetAttr(PyObject_GetAttr(ctypes, PyUnicode_FromString("c_void_p")), PyUnicode_FromString("from_address"));
//}

static PyMethodDef detailmethods[] = {
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
	{ "mix", (PyCFunction)mix_, METH_VARARGS, "mix(x, y, a) -> float, tvecn or tquat\nReturns x * (1.0 - a) + y * a, i.e., the linear blend of\nx and y using the floating-point value a.\nThe value for a is not restricted to the range [0, 1]." },
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
	{ "cross", (PyCFunction)cross, METH_VARARGS, "cross(x, y) -> tvec3 or tquat\nReturns the cross product of x and y." },
	{ "normalize", (PyCFunction)normalize, METH_O, "normalize(x) -> float, tvecn or tquat\nReturns a vector in the same direction as x but with length of 1." },
	{ "faceforward", (PyCFunction)faceforward, METH_VARARGS, "faceforward(N, I, Nref) -> float or tvecn\nIf dot(Nref, I) < 0.0, return N, otherwise, return -N." },
	{ "reflect", (PyCFunction)reflect, METH_VARARGS, "reflect(I, N) -> float or tvecn\nFor the incident vector I and surface orientation N,\nreturns the reflection direction : result = I - 2.0 * dot(N, I) * N." },
	{ "refract", (PyCFunction)refract, METH_VARARGS, "refract(I, N, eta) -> float or tvecn\nFor the incident vector I and surface normal N,\nand the ratio of indices of refraction eta,\nreturn the refraction vector." },

	// func_matrix
	{ "matrixCompMult", (PyCFunction)matrixCompMult, METH_VARARGS, "matrixCompMult(x, y) -> tmatnxn\nMultiply matrix x by matrix y component-wise, i.e.,\nresult[i][j] is the scalar product of x[i][j] and y[i][j]." },
	{ "outerProduct", (PyCFunction)outerProduct, METH_VARARGS, "outerProduct(c, r) -> tmatnxn\nTreats the first parameter c as a column vector\nand the second parameter r as a row vector\nand does a linear algebraic matrix multiply c * r." },
	{ "transpose", (PyCFunction)transpose, METH_O, "transpose(x) -> tmatnxn\nReturns the transposed matrix of x" },
	{ "determinant", (PyCFunction)determinant, METH_O, "determinant(x) -> float\nReturn the determinant of a squared matrix." },
	{ "inverse", (PyCFunction)inverse, METH_O, "inverse(x) -> tmatnxn or tquat\nReturn the inverse of a squared matrix or quaternion." },

	// func_trigonometric
	{ "radians", (PyCFunction)radians, METH_O, "radians(x) -> float or tvecn\nConverts degrees to radians and returns the result." },
	{ "degrees", (PyCFunction)degrees, METH_O, "degrees(x) -> float or tvecn\nConverts radians to degrees and returns the result." },
	{ "sin", (PyCFunction)sin_, METH_O, "sin(x) -> tvecn\nThe standard trigonometric sine function. \nThe values returned by this function will range from [-1, 1]." },
	{ "cos", (PyCFunction)cos_, METH_O, "cos(x) -> tvecn\nThe standard trigonometric cosine function.\nThe values returned by this function will range from [-1, 1]." },
	{ "tan", (PyCFunction)tan_, METH_O, "tan(x) -> tvecn\nThe standard trigonometric tangent function." },
	{ "asin", (PyCFunction)asin_, METH_O, "asin(x) -> tvecn\nArc sine. Returns an angle whose sine is x. \nThe range of values returned by this function is [-PI/2, PI/2].\nResults are undefined if |x| > 1." },
	{ "acos", (PyCFunction)acos_, METH_O, "acos(x) -> tvecn\nArc cosine. Returns an angle whose sine is x.\nThe range of values returned by this function is [0, PI].\nResults are undefined if |x| > 1." },
	{ "atan", (PyCFunction)atan_,  METH_VARARGS | METH_KEYWORDS, "atan(y [,x]) -> float or tvecn\nArc tangent. Returns an angle whose tangent is y/x.\nThe signs of x and y are used to determine what\nquadrant the angle is in. The range of values returned\nby this function is [-PI, PI]. Results are undefined\nif x and y are both 0." },
	{ "sinh", (PyCFunction)sinh_, METH_O, "sinh(x) -> tvecn\nReturns the hyperbolic sine function, (exp(x) - exp(-x)) / 2" },
	{ "cosh", (PyCFunction)cosh_, METH_O, "cosh(x) -> tvecn\nReturns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2" },
	{ "tanh", (PyCFunction)tanh_, METH_O, "tanh(x) -> tvecn\nReturns the hyperbolic tangent function, sinh(angle) / cosh(angle)" },
	{ "asinh", (PyCFunction)asinh_, METH_O, "asinh(x) -> float or tvecn\nArc hyperbolic sine; returns the inverse of sinh." },
	{ "acosh", (PyCFunction)acosh_, METH_O, "acosh(x) -> float or tvecn\nArc hyperbolic cosine; returns the non-negative inverse\nof cosh. Results are undefined if x < 1." },
	{ "atanh", (PyCFunction)atanh, METH_O, "atanh(x) -> float or tvecn\nArc hyperbolic tangent; returns the inverse of tanh.\nResults are undefined if abs(x) >= 1." },
	{ NULL, NULL, 0, NULL }
};

#if PY3K
static PyModuleDef detailmodule = {
	PyModuleDef_HEAD_INIT,
	"glm::detail",
	"Features that implement in Python the GLSL specification as closely as necessary.\nglm::detail namespace",
	-1,
	detailmethods, NULL, NULL, NULL, NULL
};
#endif

static PyMethodDef gtcmethods[] = {
	// color_space
	{ "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB, METH_VARARGS | METH_KEYWORDS, "convertLinearToSRGB(ColorLinear[, Gamma]) -> tvecn\nConvert a linear color to sRGB color using a standard / custom gamma correction." },
	{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear, METH_VARARGS | METH_KEYWORDS, "convertSRGBToLinear(ColorLinear[, Gamma]) -> tvecn\nConvert a sRGB color to linear color using a standard / custom gamma correction." },

	// constants
	{ "epsilon", (PyCFunction)epsilon, METH_NOARGS, "epsilon() -> float\nReturn the epsilon constant for floating point types." },
	{ "zero", (PyCFunction)zero, METH_NOARGS, "zero() -> float\nReturn 0." },
	{ "one", (PyCFunction)one, METH_NOARGS, "one() -> float\nReturn 1." },
	{ "pi", (PyCFunction)pi, METH_NOARGS, "pi() -> float\nReturn the pi constant." },
	{ "two_pi", (PyCFunction)two_pi, METH_NOARGS, "two_pi() -> float\nReturn pi * 2." },
	{ "root_pi", (PyCFunction)root_pi, METH_NOARGS, "root_pi() -> float\nReturn square root of pi." },
	{ "half_pi", (PyCFunction)half_pi, METH_NOARGS, "half_pi() -> float\nReturn pi / 2." },
	{ "three_over_two_pi", (PyCFunction)three_over_two_pi, METH_NOARGS, "three_over_two_pi() -> float\nReturn pi / 2 * 3." },
	{ "quarter_pi", (PyCFunction)quarter_pi, METH_NOARGS, "quarter_pi() -> float\nReturn pi / 4." },
	{ "one_over_pi", (PyCFunction)one_over_pi, METH_NOARGS, "one_over_pi() -> float\nReturn 1 / pi." },
	{ "one_over_two_pi", (PyCFunction)one_over_two_pi, METH_NOARGS, "one_over_two_pi() -> float\nReturn 1 / (pi * 2)." },
	{ "two_over_pi", (PyCFunction)two_over_pi, METH_NOARGS, "two_over_pi() -> float\nReturn 2 / pi." },
	{ "four_over_pi", (PyCFunction)four_over_pi, METH_NOARGS, "four_over_pi() -> float\nReturn 4 / pi." },
	{ "two_over_root_pi", (PyCFunction)two_over_root_pi, METH_NOARGS, "two_over_root_pi() -> float\nReturn 2 / sqrt(pi)." },
	{ "one_over_root_two", (PyCFunction)one_over_root_two, METH_NOARGS, "one_over_root_two() -> float\nReturn 1 / sqrt(2)." },
	{ "root_half_pi", (PyCFunction)root_half_pi, METH_NOARGS, "root_half_pi() -> float\nReturn sqrt(pi / 2)." },
	{ "root_two_pi", (PyCFunction)root_two_pi, METH_NOARGS, "root_two_pi() -> float\nReturn sqrt(2 * pi)." },
	{ "root_ln_four", (PyCFunction)root_ln_four, METH_NOARGS, "root_ln_four() -> float\nReturn sqrt(ln(4))." },
	{ "e", (PyCFunction)e, METH_NOARGS, "e() -> float\nReturn e constant." },
	{ "euler", (PyCFunction)euler, METH_NOARGS, "euler() -> float\nReturn Euler's constant." },
	{ "root_two", (PyCFunction)root_two, METH_NOARGS, "root_two() -> float\nReturn sqrt(2)." },
	{ "root_three", (PyCFunction)root_three, METH_NOARGS, "root_three() -> float\nReturn sqrt(3)." },
	{ "root_five", (PyCFunction)root_five, METH_NOARGS, "root_five() -> float\nReturn sqrt(5)." },
	{ "ln_two", (PyCFunction)ln_two, METH_NOARGS, "ln_two() -> float\nReturn ln(2)." },
	{ "ln_ten", (PyCFunction)ln_ten, METH_NOARGS, "ln_ten() -> float\nReturn ln(10)." },
	{ "ln_ln_two", (PyCFunction)ln_ln_two, METH_NOARGS, "ln_ln_two() -> float\nReturn ln(ln(2))." },
	{ "third", (PyCFunction)third, METH_NOARGS, "third() -> float\nReturn 1 / 3." },
	{ "two_thirds", (PyCFunction)two_thirds, METH_NOARGS, "two_thirds() -> float\nReturn 2 / 3." },
	{ "golden_ratio", (PyCFunction)golden_ratio, METH_NOARGS, "golden_ratio() -> float\nReturn the golden ratio constant." },

	// epsilon
	{ "epsilonEqual", (PyCFunction)epsilonEqual, METH_VARARGS, "epsilonEqual(x, y, epsilon) -> tvecn or tquat\nReturns the component-wise comparison of |x - y| < epsilon.\nTrue if this expression is satisfied." },
	{ "epsilonNotEqual", (PyCFunction)epsilonNotEqual, METH_VARARGS, "epsilonNotEqual(x, y, epsilon) -> tvecn or tquat\nReturns the component-wise comparison of |x - y| >= epsilon.\nTrue if this expression is satisfied." },

	// matrix_transform
	{ "translate", (PyCFunction)translate, METH_VARARGS, "translate(m, v) -> tmat4x4\nBuilds a translation 4 * 4 matrix created from a vector of 3 components." },
	{ "rotate", (PyCFunction)rotate, METH_VARARGS, "rotate(m, angle, axis) -> tmat4x4 or tquat\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle\nor rotates a quaternion from a vector of 3 components axis and an angle." },
	{ "rotate_slow", (PyCFunction)rotate_slow, METH_VARARGS, "rotate_slow(m, angle, axis) -> tmat4x4\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle." },
	{ "scale", (PyCFunction)scale, METH_VARARGS, "scale(m, v) -> tmat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "scale_slow", (PyCFunction)scale_slow, METH_VARARGS, "scale_slow(m, v) -> tmat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "ortho", (PyCFunction)ortho, METH_VARARGS, "ortho(left, right, bottom, top[, zNear, zFar]) -> tmat4x4\nCreates a matrix for projecting two-dimensional coordinates onto the screen." },
	{ "orthoLH_ZO", (PyCFunction)orthoLH_ZO, METH_VARARGS, "orthoLH_ZO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoLH_NO", (PyCFunction)orthoLH_NO, METH_VARARGS, "orthoLH_NO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH_ZO", (PyCFunction)orthoRH_ZO, METH_VARARGS, "orthoRH_ZO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoRH_NO", (PyCFunction)orthoRH_NO, METH_VARARGS, "orthoRH_NO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoZO", (PyCFunction)orthoZO, METH_VARARGS, "orthoZO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoNO", (PyCFunction)orthoNO, METH_VARARGS, "orthoNO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoLH", (PyCFunction)orthoLH, METH_VARARGS, "orthoLH(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH", (PyCFunction)orthoRH, METH_VARARGS, "orthoRH(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustum", (PyCFunction)frustum, METH_VARARGS, "frustum(left, right, bottom, top, near, far) -> tmat4x4\nCreates a frustum matrix with default handedness, using right-handedness and -1 to +1 near and far clip planes definition." },
	{ "frustumLH_ZO", (PyCFunction)frustumLH_ZO, METH_VARARGS, "frustumLH_ZO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumLH_NO", (PyCFunction)frustumLH_NO, METH_VARARGS, "frustumLH_NO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH_ZO", (PyCFunction)frustumRH_ZO, METH_VARARGS, "frustumRH_ZO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumRH_NO", (PyCFunction)frustumRH_NO, METH_VARARGS, "frustumRH_NO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumZO", (PyCFunction)frustumZO, METH_VARARGS, "frustumZO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumNO", (PyCFunction)frustumNO, METH_VARARGS, "frustumNO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumLH", (PyCFunction)frustumLH, METH_VARARGS, "frustumLH(left, right, bottom, top, near, far) -> tmat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH", (PyCFunction)frustumRH, METH_VARARGS, "frustumRH(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspective", (PyCFunction)perspective, METH_VARARGS, "perspective(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum." },
	{ "perspectiveLH_ZO", (PyCFunction)perspectiveLH_ZO, METH_VARARGS, "perspectiveLH_ZO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveLH_NO", (PyCFunction)perspectiveLH_NO, METH_VARARGS, "perspectiveLH_NO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH_ZO", (PyCFunction)perspectiveRH_ZO, METH_VARARGS, "perspectiveRH_ZO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveRH_NO", (PyCFunction)perspectiveRH_NO, METH_VARARGS, "perspectiveRH_NO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveZO", (PyCFunction)perspectiveZO, METH_VARARGS, "perspectiveZO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveNO", (PyCFunction)perspectiveNO, METH_VARARGS, "perspectiveNO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveLH", (PyCFunction)perspectiveLH, METH_VARARGS, "perspectiveLH(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH", (PyCFunction)perspectiveRH, METH_VARARGS, "perspectiveRH(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFov", (PyCFunction)perspectiveFov, METH_VARARGS, "perspectiveFov(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates." },
	{ "perspectiveFovLH_ZO", (PyCFunction)perspectiveFovLH_ZO, METH_VARARGS, "perspectiveFovLH_ZO(fov, width, height, near, far) -> tmat4x4\n\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovLH_NO", (PyCFunction)perspectiveFovLH_NO, METH_VARARGS, "perspectiveFovLH_NO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH_ZO", (PyCFunction)perspectiveFovRH_ZO, METH_VARARGS, "perspectiveFovRH_ZO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovRH_NO", (PyCFunction)perspectiveFovRH_NO, METH_VARARGS, "perspectiveFovRH_NO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovZO", (PyCFunction)perspectiveFovZO, METH_VARARGS, "perspectiveFovZO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovNO", (PyCFunction)perspectiveFovNO, METH_VARARGS, "perspectiveFovNO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovLH", (PyCFunction)perspectiveFovLH, METH_VARARGS, "perspectiveFovLH(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH", (PyCFunction)perspectiveFovRH, METH_VARARGS, "perspectiveFovRH(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "infinitePerspective", (PyCFunction)infinitePerspective, METH_VARARGS, "infinitePerspective(fovy, aspect, near) -> tmat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveRH", (PyCFunction)infinitePerspectiveRH, METH_VARARGS, "infinitePerspectiveRH(fovy, aspect, near) -> tmat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveLH", (PyCFunction)infinitePerspectiveLH, METH_VARARGS, "infinitePerspectiveLH(fovy, aspect, near) -> tmat4x4\nCreates a matrix for a left handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "tweakedInfinitePerspective", (PyCFunction)tweakedInfinitePerspective, METH_VARARGS, "tweakedInfinitePerspective(fovy, aspect, near[, ep]) -> tmat4x4\nCreates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping." },
	{ "project", (PyCFunction)project, METH_VARARGS, "project(obj, model, proj, viewport) -> tvec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectNO", (PyCFunction)projectNO, METH_VARARGS, "projectNO(obj, model, proj, viewport) -> tvec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectZO", (PyCFunction)projectZO, METH_VARARGS, "projectZO(obj, model, proj, viewport) -> tvec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "unProject", (PyCFunction)unProject, METH_VARARGS, "unProject(obj, model, proj, viewport) -> tvec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectNO", (PyCFunction)unProjectNO, METH_VARARGS, "unProjectNO(obj, model, proj, viewport) -> tvec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectZO", (PyCFunction)unProjectZO, METH_VARARGS, "unProjectZO(obj, model, proj, viewport) -> tvec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "pickMatrix", (PyCFunction)pickMatrix, METH_VARARGS, "pickMatrix(center, delta, viewport) -> tmat4x4\nDefine a picking region" },
	{ "lookAt", (PyCFunction)lookAt, METH_VARARGS, "lookAt(eye, center, up) -> tmat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtRH", (PyCFunction)lookAtRH, METH_VARARGS, "lookAtRH(eye, center, up) -> tmat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtLH", (PyCFunction)lookAtLH, METH_VARARGS, "lookAtLH(eye, center, up) -> tmat4x4\nBuild a left handed look at view matrix." },

	// quaternion
	{ "lerp", (PyCFunction)lerp, METH_VARARGS, "lerp(x, y, a) -> tquat\nLinear interpolation of two quaternions.\nThe interpolation is oriented." },
	{ "slerp", (PyCFunction)slerp, METH_VARARGS, "slerp(x, y, a) -> tquat\nSpherical linear interpolation of two quaternions.\nThe interpolation always take the short path and the rotation is performed at constant speed." },
	{ "conjugate", (PyCFunction)conjugate, METH_VARARGS, "conjugate(x, y, a) -> tquat\nReturns the q conjugate." },
	{ "eulerAngles", (PyCFunction)eulerAngles, METH_O, "eulerAngles(x) -> tvec3\nReturns euler angles, pitch as x, yaw as y, roll as z." },
	{ "roll", (PyCFunction)roll, METH_O, "roll(x) -> float\nReturns roll value of euler angles expressed in radians." },
	{ "pitch", (PyCFunction)pitch, METH_O, "pitch(x) -> float\nReturns pitch value of euler angles expressed in radians." },
	{ "yaw", (PyCFunction)yaw, METH_O, "yaw(x) -> float\nReturns yaw value of euler angles expressed in radians." },
	{ "mat3_cast", (PyCFunction)mat3_cast, METH_O, "mat3_cast(x) -> tmat3x3\nConverts a quaternion to a 3 * 3 matrix." },
	{ "mat4_cast", (PyCFunction)mat4_cast, METH_O, "mat4_cast(x) -> tmat4x4\nConverts a quaternion to a 4 * 4 matrix." },
	{ "quat_cast", (PyCFunction)quat_cast, METH_O, "quat_cast(m) -> tquat\nConverts a 3 * 3 or 4 * 4 matrix to a quaternion." },
	{ "angle", (PyCFunction)angle, METH_O, "angle(x) -> float\nReturns the quaternion rotation angle." },
	{ "axis", (PyCFunction)axis, METH_O, "axis(x) -> tvec3\nReturns the quaternion rotation axis." },
	{ "angleAxis", (PyCFunction)angleAxis, METH_O, "angleAxis(x) -> tquat\nBuild a quaternion from an angle and a normalized axis." },

	// matrix_access
	{ "row", (PyCFunction)row, METH_VARARGS, "row(m, index[, x]) -> tvecn or tmatnxn\nGet a specific row of a matrix or set a specific row to a matrix." },
	{ "column", (PyCFunction)column, METH_VARARGS, "column(m, index[, x]) -> tvecn or tmatnxn\nGet a specific column of a matrix or set a specific column to a matrix." },

	// noise
	{ "grad4", (PyCFunction)grad4_, METH_VARARGS, "grad4(j, ip) -> tvec4" },
	{ "perlin", (PyCFunction)perlin, METH_VARARGS, "perlin(p[, rep]) -> float\nClassic or periodic perlin noise." },
	{ "simplex", (PyCFunction)simplex, METH_O, "simplex(p) -> float\nSimplex noise." },

	// random
	{ "linearRand", (PyCFunction)linearRand, METH_VARARGS, "linearRand(Min, Max) -> float or tvecn\nGenerate random numbers in the interval [Min, Max], according a linear distribution" },
	{ "gaussRand", (PyCFunction)gaussRand_, METH_VARARGS, "gaussRand(Mean, Deviation) -> float\nGenerate random numbers in the interval [Min, Max], according a gaussian distribution" },
	{ "circularRand", (PyCFunction)circularRand_, METH_O, "circularRand(Radius) -> tvec2\nGenerate a random 2D vector which coordinates are regulary distributed on a circle of a given radius" },
	{ "sphericalRand", (PyCFunction)sphericalRand_, METH_O, "sphericalRand(Radius) -> tvec3\nGenerate a random 3D vector which coordinates are regulary distributed on a sphere of a given radius" },
	{ "diskRand", (PyCFunction)diskRand_, METH_O, "diskRand(Radius) -> tvec2\nGenerate a random 2D vector which coordinates are regulary distributed within the area of a disk of a given radius" },
	{ "ballRand", (PyCFunction)ballRand_, METH_O, "ballRand(Radius) -> tvec3\nGenerate a random 3D vector which coordinates are regulary distributed within the area of a ball of a given radius" },

	// reciprocal
	{ "sec", (PyCFunction)sec_, METH_O, "sec(x) -> float or tvecn\nSecant function.\nhypotenuse / adjacent or 1 / cos(x)" },
	{ "csc", (PyCFunction)csc_, METH_O, "csc(x) -> float or tvecn\nCosecant function.\nhypotenuse / opposite or 1 / sin(x)" },
	{ "cot", (PyCFunction)cot_, METH_O, "cot(x) -> float or tvecn\nCotangent function.\nadjacent / opposite or 1 / tan(x)" },
	{ "asec", (PyCFunction)asec_, METH_O, "asec(x) -> float or tvecn\nInverse secant function." },
	{ "acsc", (PyCFunction)acsc_, METH_O, "acsc(x) -> float or tvecn\nInverse cosecant function." },
	{ "acot", (PyCFunction)acot_, METH_O, "acot(x) -> float or tvecn\nInverse cotangent function." },
	{ "sech", (PyCFunction)sech_, METH_O, "sech(x) -> float or tvecn\nSecant hyperbolic function." },
	{ "csch", (PyCFunction)csch_, METH_O, "csch(x) -> float or tvecn\nCosecant hyperbolic function." },
	{ "coth", (PyCFunction)coth_, METH_O, "coth(x) -> float or tvecn\nCotangent hyperbolic function." },
	{ "asech", (PyCFunction)asech_, METH_O, "asech(x) -> float or tvecn\nInverse secant hyperbolic function." },
	{ "acsch", (PyCFunction)acsch_, METH_O, "acsch(x) -> float or tvecn\nInverse cosecant hyperbolic function." },
	{ "acoth", (PyCFunction)acoth_, METH_O, "acoth(x) -> float or tvecn\nInverse cotangent hyperbolic function." },

	// type_ptr
	{ "value_ptr", (PyCFunction)value_ptr, METH_O, "value_ptr(x) -> void* as int\nReturn the constant address to the data of the input parameter." },
	{ "sizeof", (PyCFunction)sizeof_, METH_O, "sizeof(x) -> int\nReturn the size of x in bytes." },
	{ NULL, NULL, 0, NULL }
};

#if PY3K
static PyModuleDef gtcmodule = {
	PyModuleDef_HEAD_INIT,
	"glm::gtc",
	"Features that implement in Python the GLSL specification as closely as necessary.\nglm::gtc namespace",
	-1,
	gtcmethods, NULL, NULL, NULL, NULL
};
#endif

static PyMethodDef glmmethods[] = {
	//{"test", (PyCFunction)test, METH_O, ""},
	// detail
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
	{ "mix", (PyCFunction)mix_, METH_VARARGS, "mix(x, y, a) -> float, tvecn or tquat\nReturns x * (1.0 - a) + y * a, i.e., the linear blend of\nx and y using the floating-point value a.\nThe value for a is not restricted to the range [0, 1]." },
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
	{ "cross", (PyCFunction)cross, METH_VARARGS, "cross(x, y) -> tvec3 or tquat\nReturns the cross product of x and y." },
	{ "normalize", (PyCFunction)normalize, METH_O, "normalize(x) -> float, tvecn or tquat\nReturns a vector in the same direction as x but with length of 1." },
	{ "faceforward", (PyCFunction)faceforward, METH_VARARGS, "faceforward(N, I, Nref) -> float or tvecn\nIf dot(Nref, I) < 0.0, return N, otherwise, return -N." },
	{ "reflect", (PyCFunction)reflect, METH_VARARGS, "reflect(I, N) -> float or tvecn\nFor the incident vector I and surface orientation N,\nreturns the reflection direction : result = I - 2.0 * dot(N, I) * N." },
	{ "refract", (PyCFunction)refract, METH_VARARGS, "refract(I, N, eta) -> float or tvecn\nFor the incident vector I and surface normal N,\nand the ratio of indices of refraction eta,\nreturn the refraction vector." },
	
	// func_matrix
	{ "matrixCompMult", (PyCFunction)matrixCompMult, METH_VARARGS, "matrixCompMult(x, y) -> tmatnxn\nMultiply matrix x by matrix y component-wise, i.e.,\nresult[i][j] is the scalar product of x[i][j] and y[i][j]." },
	{ "outerProduct", (PyCFunction)outerProduct, METH_VARARGS, "outerProduct(c, r) -> tmatnxn\nTreats the first parameter c as a column vector\nand the second parameter r as a row vector\nand does a linear algebraic matrix multiply c * r." },
	{ "transpose", (PyCFunction)transpose, METH_O, "transpose(x) -> tmatnxn\nReturns the transposed matrix of x" },
	{ "determinant", (PyCFunction)determinant, METH_O, "determinant(x) -> float\nReturn the determinant of a squared matrix." },
	{ "inverse", (PyCFunction)inverse, METH_O, "inverse(x) -> tmatnxn or tquat\nReturn the inverse of a squared matrix or quaternion." },

	// func_trigonometric
	{ "radians", (PyCFunction)radians, METH_O, "radians(x) -> float or tvecn\nConverts degrees to radians and returns the result." },
	{ "degrees", (PyCFunction)degrees, METH_O, "degrees(x) -> float or tvecn\nConverts radians to degrees and returns the result." },
	{ "sin", (PyCFunction)sin_, METH_O, "sin(x) -> tvecn\nThe standard trigonometric sine function. \nThe values returned by this function will range from [-1, 1]." },
	{ "cos", (PyCFunction)cos_, METH_O, "cos(x) -> tvecn\nThe standard trigonometric cosine function.\nThe values returned by this function will range from [-1, 1]." },
	{ "tan", (PyCFunction)tan_, METH_O, "tan(x) -> tvecn\nThe standard trigonometric tangent function." },
	{ "asin", (PyCFunction)asin_, METH_O, "asin(x) -> tvecn\nArc sine. Returns an angle whose sine is x. \nThe range of values returned by this function is [-PI/2, PI/2].\nResults are undefined if |x| > 1." },
	{ "acos", (PyCFunction)acos_, METH_O, "acos(x) -> tvecn\nArc cosine. Returns an angle whose sine is x.\nThe range of values returned by this function is [0, PI].\nResults are undefined if |x| > 1." },
	{ "atan", (PyCFunction)atan_,  METH_VARARGS | METH_KEYWORDS, "atan(y [,x]) -> float or tvecn\nArc tangent. Returns an angle whose tangent is y/x.\nThe signs of x and y are used to determine what\nquadrant the angle is in. The range of values returned\nby this function is [-PI, PI]. Results are undefined\nif x and y are both 0." },
	{ "sinh", (PyCFunction)sinh_, METH_O, "sinh(x) -> tvecn\nReturns the hyperbolic sine function, (exp(x) - exp(-x)) / 2" },
	{ "cosh", (PyCFunction)cosh_, METH_O, "cosh(x) -> tvecn\nReturns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2" },
	{ "tanh", (PyCFunction)tanh_, METH_O, "tanh(x) -> tvecn\nReturns the hyperbolic tangent function, sinh(angle) / cosh(angle)" },
	{ "asinh", (PyCFunction)asinh_, METH_O, "asinh(x) -> float or tvecn\nArc hyperbolic sine; returns the inverse of sinh." },
	{ "acosh", (PyCFunction)acosh_, METH_O, "acosh(x) -> float or tvecn\nArc hyperbolic cosine; returns the non-negative inverse\nof cosh. Results are undefined if x < 1." },
	{ "atanh", (PyCFunction)atanh_, METH_O, "atanh(x) -> float or tvecn\nArc hyperbolic tangent; returns the inverse of tanh.\nResults are undefined if abs(x) >= 1." },
	// detail/

	// gtc
	// color_space
	{ "convertLinearToSRGB", (PyCFunction)convertLinearToSRGB, METH_VARARGS | METH_KEYWORDS, "convertLinearToSRGB(ColorLinear[, Gamma]) -> tvecn\nConvert a linear color to sRGB color using a standard / custom gamma correction." },
	{ "convertSRGBToLinear", (PyCFunction)convertSRGBToLinear, METH_VARARGS | METH_KEYWORDS, "convertSRGBToLinear(ColorLinear[, Gamma]) -> tvecn\nConvert a sRGB color to linear color using a standard / custom gamma correction." },
	 
	// constants
	{ "epsilon", (PyCFunction)epsilon, METH_NOARGS, "epsilon() -> float\nReturn the epsilon constant for floating point types." },
	{ "zero", (PyCFunction)zero, METH_NOARGS, "zero() -> float\nReturn 0." },
	{ "one", (PyCFunction)one, METH_NOARGS, "one() -> float\nReturn 1." },
	{ "pi", (PyCFunction)pi, METH_NOARGS, "pi() -> float\nReturn the pi constant." },
	{ "two_pi", (PyCFunction)two_pi, METH_NOARGS, "two_pi() -> float\nReturn pi * 2." },
	{ "root_pi", (PyCFunction)root_pi, METH_NOARGS, "root_pi() -> float\nReturn square root of pi." },
	{ "half_pi", (PyCFunction)half_pi, METH_NOARGS, "half_pi() -> float\nReturn pi / 2." },
	{ "three_over_two_pi", (PyCFunction)three_over_two_pi, METH_NOARGS, "three_over_two_pi() -> float\nReturn pi / 2 * 3." },
	{ "quarter_pi", (PyCFunction)quarter_pi, METH_NOARGS, "quarter_pi() -> float\nReturn pi / 4." },
	{ "one_over_pi", (PyCFunction)one_over_pi, METH_NOARGS, "one_over_pi() -> float\nReturn 1 / pi." },
	{ "one_over_two_pi", (PyCFunction)one_over_two_pi, METH_NOARGS, "one_over_two_pi() -> float\nReturn 1 / (pi * 2)." },
	{ "two_over_pi", (PyCFunction)two_over_pi, METH_NOARGS, "two_over_pi() -> float\nReturn 2 / pi." },
	{ "four_over_pi", (PyCFunction)four_over_pi, METH_NOARGS, "four_over_pi() -> float\nReturn 4 / pi." },
	{ "two_over_root_pi", (PyCFunction)two_over_root_pi, METH_NOARGS, "two_over_root_pi() -> float\nReturn 2 / sqrt(pi)." },
	{ "one_over_root_two", (PyCFunction)one_over_root_two, METH_NOARGS, "one_over_root_two() -> float\nReturn 1 / sqrt(2)." },
	{ "root_half_pi", (PyCFunction)root_half_pi, METH_NOARGS, "root_half_pi() -> float\nReturn sqrt(pi / 2)." },
	{ "root_two_pi", (PyCFunction)root_two_pi, METH_NOARGS, "root_two_pi() -> float\nReturn sqrt(2 * pi)." },
	{ "root_ln_four", (PyCFunction)root_ln_four, METH_NOARGS, "root_ln_four() -> float\nReturn sqrt(ln(4))." },
	{ "e", (PyCFunction)e, METH_NOARGS, "e() -> float\nReturn e constant." },
	{ "euler", (PyCFunction)euler, METH_NOARGS, "euler() -> float\nReturn Euler's constant." },
	{ "root_two", (PyCFunction)root_two, METH_NOARGS, "root_two() -> float\nReturn sqrt(2)." },
	{ "root_three", (PyCFunction)root_three, METH_NOARGS, "root_three() -> float\nReturn sqrt(3)." },
	{ "root_five", (PyCFunction)root_five, METH_NOARGS, "root_five() -> float\nReturn sqrt(5)." },
	{ "ln_two", (PyCFunction)ln_two, METH_NOARGS, "ln_two() -> float\nReturn ln(2)." },
	{ "ln_ten", (PyCFunction)ln_ten, METH_NOARGS, "ln_ten() -> float\nReturn ln(10)." },
	{ "ln_ln_two", (PyCFunction)ln_ln_two, METH_NOARGS, "ln_ln_two() -> float\nReturn ln(ln(2))." },
	{ "third", (PyCFunction)third, METH_NOARGS, "third() -> float\nReturn 1 / 3." },
	{ "two_thirds", (PyCFunction)two_thirds, METH_NOARGS, "two_thirds() -> float\nReturn 2 / 3." },
	{ "golden_ratio", (PyCFunction)golden_ratio, METH_NOARGS, "golden_ratio() -> float\nReturn the golden ratio constant." },
	
	// epsilon
	{ "epsilonEqual", (PyCFunction)epsilonEqual, METH_VARARGS, "epsilonEqual(x, y, epsilon) -> tvecn or tquat\nReturns the component-wise comparison of |x - y| < epsilon.\nTrue if this expression is satisfied." },
	{ "epsilonNotEqual", (PyCFunction)epsilonNotEqual, METH_VARARGS, "epsilonNotEqual(x, y, epsilon) -> tvecn or tquat\nReturns the component-wise comparison of |x - y| >= epsilon.\nTrue if this expression is satisfied." },
	
	// matrix_transform
	{ "translate", (PyCFunction)translate, METH_VARARGS, "translate(m, v) -> tmat4x4\nBuilds a translation 4 * 4 matrix created from a vector of 3 components." },
	{ "rotate", (PyCFunction)rotate, METH_VARARGS, "rotate(m, angle, axis) -> tmat4x4 or tquat\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle\nor rotates a quaternion from a vector of 3 components axis and an angle." },
	{ "rotate_slow", (PyCFunction)rotate_slow, METH_VARARGS, "rotate_slow(m, angle, axis) -> tmat4x4\nBuilds a rotation 4 * 4 matrix created from an axis vector and an angle." },
	{ "scale", (PyCFunction)scale, METH_VARARGS, "scale(m, v) -> tmat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "scale_slow", (PyCFunction)scale_slow, METH_VARARGS, "scale_slow(m, v) -> tmat4x4\nBuilds a scale 4 * 4 matrix created from 3 scalars." },
	{ "ortho", (PyCFunction)ortho, METH_VARARGS, "ortho(left, right, bottom, top[, zNear, zFar]) -> tmat4x4\nCreates a matrix for projecting two-dimensional coordinates onto the screen." },
	{ "orthoLH_ZO", (PyCFunction)orthoLH_ZO, METH_VARARGS, "orthoLH_ZO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoLH_NO", (PyCFunction)orthoLH_NO, METH_VARARGS, "orthoLH_NO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH_ZO", (PyCFunction)orthoRH_ZO, METH_VARARGS, "orthoRH_ZO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoRH_NO", (PyCFunction)orthoRH_NO, METH_VARARGS, "orthoRH_NO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoZO", (PyCFunction)orthoZO, METH_VARARGS, "orthoZO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "orthoNO", (PyCFunction)orthoNO, METH_VARARGS, "orthoNO(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoLH", (PyCFunction)orthoLH, METH_VARARGS, "orthoLH(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "orthoRH", (PyCFunction)orthoRH, METH_VARARGS, "orthoRH(left, right, bottom, top, zNear, zFar) -> tmat4x4\nCreates a matrix for an orthographic parallel viewing volume, using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustum", (PyCFunction)frustum, METH_VARARGS, "frustum(left, right, bottom, top, near, far) -> tmat4x4\nCreates a frustum matrix with default handedness, using right-handedness and -1 to +1 near and far clip planes definition." },
	{ "frustumLH_ZO", (PyCFunction)frustumLH_ZO, METH_VARARGS, "frustumLH_ZO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumLH_NO", (PyCFunction)frustumLH_NO, METH_VARARGS, "frustumLH_NO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH_ZO", (PyCFunction)frustumRH_ZO, METH_VARARGS, "frustumRH_ZO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumRH_NO", (PyCFunction)frustumRH_NO, METH_VARARGS, "frustumRH_NO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumZO", (PyCFunction)frustumZO, METH_VARARGS, "frustumZO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "frustumNO", (PyCFunction)frustumNO, METH_VARARGS, "frustumNO(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumLH", (PyCFunction)frustumLH, METH_VARARGS, "frustumLH(left, right, bottom, top, near, far) -> tmat4x4\nCreates a left handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "frustumRH", (PyCFunction)frustumRH, METH_VARARGS, "frustumRH(left, right, bottom, top, near, far) -> tmat4x4\nCreates a right handed frustum matrix.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspective", (PyCFunction)perspective, METH_VARARGS, "perspective(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum." },
	{ "perspectiveLH_ZO", (PyCFunction)perspectiveLH_ZO, METH_VARARGS, "perspectiveLH_ZO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveLH_NO", (PyCFunction)perspectiveLH_NO, METH_VARARGS, "perspectiveLH_NO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH_ZO", (PyCFunction)perspectiveRH_ZO, METH_VARARGS, "perspectiveRH_ZO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveRH_NO", (PyCFunction)perspectiveRH_NO, METH_VARARGS, "perspectiveRH_NO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveZO", (PyCFunction)perspectiveZO, METH_VARARGS, "perspectiveZO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveNO", (PyCFunction)perspectiveNO, METH_VARARGS, "perspectiveNO(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveLH", (PyCFunction)perspectiveLH, METH_VARARGS, "perspectiveLH(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a left handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveRH", (PyCFunction)perspectiveRH, METH_VARARGS, "perspectiveRH(fovy, aspect, near, far) -> tmat4x4\nCreates a matrix for a right handed, symetric perspective-view frustum.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFov", (PyCFunction)perspectiveFov, METH_VARARGS, "perspectiveFov(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates." },
	{ "perspectiveFovLH_ZO", (PyCFunction)perspectiveFovLH_ZO, METH_VARARGS, "perspectiveFovLH_ZO(fov, width, height, near, far) -> tmat4x4\n\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovLH_NO", (PyCFunction)perspectiveFovLH_NO, METH_VARARGS, "perspectiveFovLH_NO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH_ZO", (PyCFunction)perspectiveFovRH_ZO, METH_VARARGS, "perspectiveFovRH_ZO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovRH_NO", (PyCFunction)perspectiveFovRH_NO, METH_VARARGS, "perspectiveFovRH_NO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovZO", (PyCFunction)perspectiveFovZO, METH_VARARGS, "perspectiveFovZO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "perspectiveFovNO", (PyCFunction)perspectiveFovNO, METH_VARARGS, "perspectiveFovNO(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovLH", (PyCFunction)perspectiveFovLH, METH_VARARGS, "perspectiveFovLH(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using left-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "perspectiveFovRH", (PyCFunction)perspectiveFovRH, METH_VARARGS, "perspectiveFovRH(fov, width, height, near, far) -> tmat4x4\nBuilds a perspective projection matrix based on a field of view using right-handed coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "infinitePerspective", (PyCFunction)infinitePerspective, METH_VARARGS, "infinitePerspective(fovy, aspect, near) -> tmat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveRH", (PyCFunction)infinitePerspectiveRH, METH_VARARGS, "infinitePerspectiveRH(fovy, aspect, near) -> tmat4x4\nCreates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "infinitePerspectiveLH", (PyCFunction)infinitePerspectiveLH, METH_VARARGS, "infinitePerspectiveLH(fovy, aspect, near) -> tmat4x4\nCreates a matrix for a left handed, symmetric perspective-view frustum with far plane at infinite." },
	{ "tweakedInfinitePerspective", (PyCFunction)tweakedInfinitePerspective, METH_VARARGS, "tweakedInfinitePerspective(fovy, aspect, near[, ep]) -> tmat4x4\nCreates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping." },
	{ "project", (PyCFunction)project, METH_VARARGS, "project(obj, model, proj, viewport) -> tvec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectNO", (PyCFunction)projectNO, METH_VARARGS, "projectNO(obj, model, proj, viewport) -> tvec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "projectZO", (PyCFunction)projectZO, METH_VARARGS, "projectZO(obj, model, proj, viewport) -> tvec3\nMap the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "unProject", (PyCFunction)unProject, METH_VARARGS, "unProject(obj, model, proj, viewport) -> tvec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectNO", (PyCFunction)unProjectNO, METH_VARARGS, "unProjectNO(obj, model, proj, viewport) -> tvec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of -1 and +1 respectively.\n(OpenGL clip volume definition)" },
	{ "unProjectZO", (PyCFunction)unProjectZO, METH_VARARGS, "unProjectZO(obj, model, proj, viewport) -> tvec3\nMap the specified window coordinates (win.x, win.y, win.z) into object coordinates.\nThe near and far clip planes correspond to z normalized device coordinates of 0 and +1 respectively.\n(Direct3D clip volume definition)" },
	{ "pickMatrix", (PyCFunction)pickMatrix, METH_VARARGS, "pickMatrix(center, delta, viewport) -> tmat4x4\nDefine a picking region" },
	{ "lookAt", (PyCFunction)lookAt, METH_VARARGS, "lookAt(eye, center, up) -> tmat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtRH", (PyCFunction)lookAtRH, METH_VARARGS, "lookAtRH(eye, center, up) -> tmat4x4\nBuild a right handed look at view matrix." },
	{ "lookAtLH", (PyCFunction)lookAtLH, METH_VARARGS, "lookAtLH(eye, center, up) -> tmat4x4\nBuild a left handed look at view matrix." },

	// quaternion
	{ "lerp", (PyCFunction)lerp, METH_VARARGS, "lerp(x, y, a) -> tquat\nLinear interpolation of two quaternions.\nThe interpolation is oriented." },
	{ "slerp", (PyCFunction)slerp, METH_VARARGS, "slerp(x, y, a) -> tquat\nSpherical linear interpolation of two quaternions.\nThe interpolation always take the short path and the rotation is performed at constant speed." },
	{ "conjugate", (PyCFunction)conjugate, METH_VARARGS, "conjugate(x, y, a) -> tquat\nReturns the q conjugate." },
	{ "eulerAngles", (PyCFunction)eulerAngles, METH_O, "eulerAngles(x) -> tvec3\nReturns euler angles, pitch as x, yaw as y, roll as z." },
	{ "roll", (PyCFunction)roll, METH_O, "roll(x) -> float\nReturns roll value of euler angles expressed in radians." },
	{ "pitch", (PyCFunction)pitch, METH_O, "pitch(x) -> float\nReturns pitch value of euler angles expressed in radians." },
	{ "yaw", (PyCFunction)yaw, METH_O, "yaw(x) -> float\nReturns yaw value of euler angles expressed in radians." },
	{ "mat3_cast", (PyCFunction)mat3_cast, METH_O, "mat3_cast(x) -> tmat3x3\nConverts a quaternion to a 3 * 3 matrix." },
	{ "mat4_cast", (PyCFunction)mat4_cast, METH_O, "mat4_cast(x) -> tmat4x4\nConverts a quaternion to a 4 * 4 matrix." },
	{ "quat_cast", (PyCFunction)quat_cast, METH_O, "quat_cast(m) -> tquat\nConverts a 3 * 3 or 4 * 4 matrix to a quaternion." },
	{ "angle", (PyCFunction)angle, METH_O, "angle(x) -> float\nReturns the quaternion rotation angle." },
	{ "axis", (PyCFunction)axis, METH_O, "axis(x) -> tvec3\nReturns the quaternion rotation axis." },
	{ "angleAxis", (PyCFunction)angleAxis, METH_O, "angleAxis(x) -> tquat\nBuild a quaternion from an angle and a normalized axis." },

	// matrix_access
	{ "row", (PyCFunction)row, METH_VARARGS, "row(m, index[, x]) -> tvecn or tmatnxn\nGet a specific row of a matrix or set a specific row to a matrix." },
	{ "column", (PyCFunction)column, METH_VARARGS, "column(m, index[, x]) -> tvecn or tmatnxn\nGet a specific column of a matrix or set a specific column to a matrix." },

	// noise
	{ "grad4", (PyCFunction)grad4_, METH_VARARGS, "grad4(j, ip) -> tvec4" },
	{ "perlin", (PyCFunction)perlin, METH_VARARGS, "perlin(p[, rep]) -> float\nClassic or periodic perlin noise." },
	{ "simplex", (PyCFunction)simplex, METH_O, "simplex(p) -> float\nSimplex noise." },

	// random
	{ "linearRand", (PyCFunction)linearRand, METH_VARARGS, "linearRand(Min, Max) -> float or tvecn\nGenerate random numbers in the interval [Min, Max], according a linear distribution" },
	{ "gaussRand", (PyCFunction)gaussRand_, METH_VARARGS, "gaussRand(Mean, Deviation) -> float\nGenerate random numbers in the interval [Min, Max], according a gaussian distribution" },
	{ "circularRand", (PyCFunction)circularRand_, METH_O, "circularRand(Radius) -> tvec2\nGenerate a random 2D vector which coordinates are regulary distributed on a circle of a given radius" },
	{ "sphericalRand", (PyCFunction)sphericalRand_, METH_O, "sphericalRand(Radius) -> tvec3\nGenerate a random 3D vector which coordinates are regulary distributed on a sphere of a given radius" },
	{ "diskRand", (PyCFunction)diskRand_, METH_O, "diskRand(Radius) -> tvec2\nGenerate a random 2D vector which coordinates are regulary distributed within the area of a disk of a given radius" },
	{ "ballRand", (PyCFunction)ballRand_, METH_O, "ballRand(Radius) -> tvec3\nGenerate a random 3D vector which coordinates are regulary distributed within the area of a ball of a given radius" },

	// reciprocal
	{ "sec", (PyCFunction)sec_, METH_O, "sec(x) -> float or tvecn\nSecant function.\nhypotenuse / adjacent or 1 / cos(x)" },
	{ "csc", (PyCFunction)csc_, METH_O, "csc(x) -> float or tvecn\nCosecant function.\nhypotenuse / opposite or 1 / sin(x)" },
	{ "cot", (PyCFunction)cot_, METH_O, "cot(x) -> float or tvecn\nCotangent function.\nadjacent / opposite or 1 / tan(x)" },
	{ "asec", (PyCFunction)asec_, METH_O, "asec(x) -> float or tvecn\nInverse secant function." },
	{ "acsc", (PyCFunction)acsc_, METH_O, "acsc(x) -> float or tvecn\nInverse cosecant function." },
	{ "acot", (PyCFunction)acot_, METH_O, "acot(x) -> float or tvecn\nInverse cotangent function." },
	{ "sech", (PyCFunction)sech_, METH_O, "sech(x) -> float or tvecn\nSecant hyperbolic function." },
	{ "csch", (PyCFunction)csch_, METH_O, "csch(x) -> float or tvecn\nCosecant hyperbolic function." },
	{ "coth", (PyCFunction)coth_, METH_O, "coth(x) -> float or tvecn\nCotangent hyperbolic function." },
	{ "asech", (PyCFunction)asech_, METH_O, "asech(x) -> float or tvecn\nInverse secant hyperbolic function." },
	{ "acsch", (PyCFunction)acsch_, METH_O, "acsch(x) -> float or tvecn\nInverse cosecant hyperbolic function." },
	{ "acoth", (PyCFunction)acoth_, METH_O, "acoth(x) -> float or tvecn\nInverse cotangent hyperbolic function." },

	// type_ptr
	{ "value_ptr", (PyCFunction)value_ptr, METH_O, "value_ptr(x) -> void* as int\nReturn the constant address to the data of the input parameter." },
	{ "sizeof", (PyCFunction)sizeof_, METH_O, "sizeof(x) -> int\nReturn the size of x in bytes." },
	{ NULL, NULL, 0, NULL }
};

#if PY3K
static PyModuleDef glmmodule = {
    PyModuleDef_HEAD_INIT,
    "glm",
    "Features that implement in Python the GLSL specification as closely as necessary.",
    -1,
	glmmethods, NULL, NULL, NULL, NULL
};
#endif

PyMODINIT_FUNC
#if PY3K
PyInit_glm(void)
#else
initglm(void)
#endif
{
	PyObject* mainmod = PyImport_AddModule("__main__");
	PyObject* maindict = PyModule_GetDict(mainmod);

	PyObject* c_void_p_str = Py_BuildValue("(s)", "c_void_p");

	c_void_p = PyObject_GetAttr(PyImport_ImportModuleEx("ctypes", maindict, maindict, c_void_p_str), PyUnicode_FromString("c_void_p"));

	Py_DECREF(c_void_p_str);
	
    PyObject* m, *detail, *gtc;

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
		|| PyType_Ready(&tmat4x4Type) < 0 || PyType_Ready(&tmat4x4IterType) < 0
		|| PyType_Ready(&tquatType) < 0 || PyType_Ready(&tquatIterType) < 0)
#if PY3K
		return NULL;
#else
		return;
#endif

#if PY3K
    m = PyModule_Create(&glmmodule);
#else
	m = Py_InitModule3("glm", glmmethods, "Features that implement in Python the GLSL specification as closely as necessary.");
#endif
    if (m == NULL)
#if PY3K
		return NULL;
#else
		return;
#endif

	// detail
	// namespace detail
#if PY3K
	detail = PyModule_Create(&detailmodule);
#else
	detail = Py_InitModule3("detail", detailmethods, "Features that implement in Python the GLSL specification as closely as necessary.\nglm::gtc namespace");
#endif
	if (detail == NULL) 
#if PY3K
		return NULL;
#else
		return;
#endif

	Py_INCREF(&tvec2Type);
	PyModule_AddObject(detail, "tvec2", (PyObject *)&tvec2Type);

	Py_INCREF(&tvec3Type);
	PyModule_AddObject(detail, "tvec3", (PyObject *)&tvec3Type);

	Py_INCREF(&tvec4Type);
	PyModule_AddObject(detail, "tvec4", (PyObject *)&tvec4Type);

	Py_INCREF(&tmat2x2Type);
	PyModule_AddObject(detail, "tmat2x2", (PyObject *)&tmat2x2Type);

	Py_INCREF(&tmat2x3Type);
	PyModule_AddObject(detail, "tmat2x3", (PyObject *)&tmat2x3Type);

	Py_INCREF(&tmat2x4Type);
	PyModule_AddObject(detail, "tmat2x4", (PyObject *)&tmat2x4Type);

	Py_INCREF(&tmat3x2Type);
	PyModule_AddObject(detail, "tmat3x2", (PyObject *)&tmat3x2Type);

	Py_INCREF(&tmat3x3Type);
	PyModule_AddObject(detail, "tmat3x3", (PyObject *)&tmat3x3Type);

	Py_INCREF(&tmat3x4Type);
	PyModule_AddObject(detail, "tmat3x4", (PyObject *)&tmat3x4Type);

	Py_INCREF(&tmat4x2Type);
	PyModule_AddObject(detail, "tmat4x2", (PyObject *)&tmat4x2Type);

	Py_INCREF(&tmat4x3Type);
	PyModule_AddObject(detail, "tmat4x3", (PyObject *)&tmat4x3Type);

	Py_INCREF(&tmat4x4Type);
	PyModule_AddObject(detail, "tmat4x4", (PyObject *)&tmat4x4Type);

	// gtc
	// namespace gtc
#if PY3K
	gtc = PyModule_Create(&gtcmodule);
#else
	gtc = Py_InitModule3("gtc", gtcmethods, "Features that implement in Python the GLSL specification as closely as necessary.\nglm::gtc namespace");
#endif
	if (gtc == NULL) 
#if PY3K
		return NULL;
#else
		return;
#endif

	// namespace glm
	Py_INCREF(detail);
	PyModule_AddObject(m, "detail", detail);

	Py_INCREF(gtc);
	PyModule_AddObject(m, "gtc", gtc);

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

	Py_INCREF(&tquatType);
	PyModule_AddObject(m, "tquat", (PyObject *)&tquatType);

	Py_INCREF(&tquatType);
	PyModule_AddObject(m, "quat", (PyObject *)&tquatType);
	
	Py_DECREF(gtc);
	Py_DECREF(detail);

#if PY3K
    return m;
#endif
}
