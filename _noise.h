#define MOD289(x) (x-floor(x*(1.0/289.0))*289.0)
static double mod289_(double x) {
	return MOD289(x);
}

//static PyObject * mod289(PyObject* self, PyObject* arg) {
//	if (!IS_NUMERIC(arg)) {
//		PY_TYPEERROR("unsupported operand type for mod289(): ", arg);
//		return NULL;
//	}
//	return PyFloat_FromDouble(mod289_(pyvalue_as_double(arg)));
//}

static double permute_(double x) {
	return mod289_(((x * 34.0) + 1.0) * x);
}

//static PyObject * permute(PyObject* self, PyObject* arg) {
//	if (IS_NUMERIC(arg)) {
//		return PyFloat_FromDouble(permute_(pyvalue_as_double(arg)));
//	}
//	PyObject* out = functor1(permute_, arg);
//	if (out == NULL) {
//		PY_TYPEERROR("unsupported operand type for permute(): ", arg);
//		return NULL;
//	}
//	return out;
//}

static double taylorInvSqrt_(double r) {
	return (1.79284291400159) - (0.85373472095314) * r;
}

//static PyObject * taylorInvSqrt(PyObject* self, PyObject* arg) {
//	if (IS_NUMERIC(arg)) {
//		return PyFloat_FromDouble(taylorInvSqrt_(pyvalue_as_double(arg)));
//	}
//	PyObject* out = functor1(taylorInvSqrt_, arg);
//	if (out == NULL) {
//		PY_TYPEERROR("unsupported operand type for taylorInvSqrt(): ", arg);
//		return NULL;
//	}
//	return out;
//}

static double fade_(double t) {
	return (t * t * t) * (t * (t * (6.) - (15.)) + (10.));
}

//static PyObject * fade(PyObject* self, PyObject* arg) {
//	PyObject* out = functor1(fade_, arg);
//	if (out == NULL) {
//		PY_TYPEERROR("unsupported operand type for fade(): ", arg);
//		return NULL;
//	}
//	return out;
//}