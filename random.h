#include <stdlib.h>

#ifndef UINT8_MAX
#define UINT8_MAX (unsigned char)0xff
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 0xffffffffffffffffULL
#endif

static double rand_(double Min, double Max) {
	return (double)(((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 0ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 8ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 16ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 24ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 32ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 40ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 48ULL) | ((unsigned long long)((unsigned int)rand() % UINT8_MAX) << 56ULL)) / (double)(UINT64_MAX) * (Max - Min) + Min;
}

static PyObject * linearRand(PyObject* self, PyObject * args) {
	PyObject * arg1, *arg2;
	UNPACK_2_VARARGS(args, "linearRand", arg1, arg2);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(rand_(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}
	void* o = NULL;
	char varType = unpack_ivec(arg1, &o);
	if (varType == GLM_TVEC2) {
		ivec2 o2;
		if (!unpack_ivec2p(arg2, &o2)) {
			PY_TYPEERROR_2O("unsupported operand type(s) for linearRand(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec2(rand_(((ivec2*)o)->x, o2.x), rand_(((ivec2*)o)->y, o2.y));
		free(o);
		return out;
	}
	if (varType == GLM_TVEC3) {
		ivec3 o2;
		if (!unpack_ivec3p(arg2, &o2)) {
			PY_TYPEERROR_2O("unsupported operand type(s) for linearRand(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec3(rand_(((ivec3*)o)->x, o2.x), rand_(((ivec3*)o)->y, o2.y), rand_(((ivec3*)o)->z, o2.z));
		free(o);
		return out;
	}
	if (varType == GLM_TVEC4) {
		ivec4 o2;
		if (!unpack_ivec4p(arg2, &o2)) {
			PY_TYPEERROR_2O("unsupported operand type(s) for linearRand(): ", arg1, arg2);
			return NULL;
		}
		PyObject* out = pack_tvec4(rand_(((ivec4*)o)->x, o2.x), rand_(((ivec4*)o)->y, o2.y), rand_(((ivec4*)o)->z, o2.z), rand_(((ivec4*)o)->w, o2.w));
		free(o);
		return out;
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for linearRand(): ", arg1, arg2);
	return NULL;
}

static double gaussRand(double Mean, double Deviation) {
	double w, x1, x2;

	do
	{
		x1 = rand_((-1.), (1.));
		x2 = rand_((-1.), (1.));

		w = x1 * x1 + x2 * x2;
	} while (w > (1.));

	return x2 * Deviation * Deviation * sqrt(((-2.) * log(w)) / w) + Mean;
}

static PyObject* gaussRand_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "gaussRand", arg1, arg2);
	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
		return PyFloat_FromDouble(gaussRand(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
	}
	PyObject * out = functor2(gaussRand, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for gaussRand(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static ivec2 diskRand(double Radius) {
	ivec2 Result;
	double LenRadius = 0.0;

	do
	{
		Result = to_ivec2(
			rand_(-Radius, Radius),
			rand_(-Radius, Radius));
		LenRadius = ilength2(Result);
	} while (LenRadius > Radius);

	return (Result);
}

static PyObject* diskRand_(PyObject* self, PyObject* arg) {
	if (!IS_NUMERIC(arg)) {
		PY_TYPEERROR("unsupported operand type for diskRand(): ", arg);
		return NULL;
	}
	return build_ivec2(diskRand(pyvalue_as_double(arg)));
}

static ivec3 ballRand(double Radius) {
	ivec3 Result;
	double LenRadius = 0.0;

	do
	{
		Result = to_ivec3(
			rand_(-Radius, Radius),
			rand_(-Radius, Radius),
			rand_(-Radius, Radius));
		LenRadius = ilength3(Result);
	} while (LenRadius > Radius);

	return Result;
}

static PyObject* ballRand_(PyObject* self, PyObject* arg) {
	if (!IS_NUMERIC(arg)) {
		PY_TYPEERROR("unsupported operand type for ballRand(): ", arg);
		return NULL;
	}
	return build_ivec3(ballRand(pyvalue_as_double(arg)));
}

static ivec2 circularRand(double Radius) {
	double a = rand_((0.0),(6.283185307179586476925286766559));
	return mulv2d(to_ivec2(cos(a), sin(a)), Radius);
}

static PyObject* circularRand_(PyObject* self, PyObject* arg) {
	if (!IS_NUMERIC(arg)) {
		PY_TYPEERROR("unsupported operand type for circularRand(): ", arg);
		return NULL;
	}
	return build_ivec2(circularRand(pyvalue_as_double(arg)));
}

static ivec3 sphericalRand(double Radius) {
	double z = rand_((-1.), (1.));
	double a = rand_((0.), (6.283185307179586476925286766559f));

	double r = sqrt((1.) - z * z);

	double x = r * cos(a);
	double y = r * sin(a);

	return mulv3d(to_ivec3(x, y, z), Radius);
}

static PyObject* sphericalRand_(PyObject* self, PyObject* arg) {
	if (!IS_NUMERIC(arg)) {
		PY_TYPEERROR("unsupported operand type for sphericalRand(): ", arg);
		return NULL;
	}
	return build_ivec3(sphericalRand(pyvalue_as_double(arg)));
}