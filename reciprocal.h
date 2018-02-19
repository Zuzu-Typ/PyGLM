static double sec(double angle) {
	return 1.0 / cos(angle);
}

static PyObject* sec_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(sec(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(sec, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for sec(): ", arg);
		return NULL;
	}
	return out;
}

static double csc(double angle) {
	return 1.0 / sin(angle);
}

static PyObject* csc_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(csc(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(csc, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for csc(): ", arg);
		return NULL;
	}
	return out;
}

static double cot(double angle) {
	const double pi_over_2 = 3.1415526535897932384626433832795 / 2.0;
	return tan(pi_over_2 - angle);
}

static PyObject* cot_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(cot(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(cot, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for cot(): ", arg);
		return NULL;
	}
	return out;
}

static double asec(double x) {
	return acos(1.0 / x);
}

static PyObject* asec_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(asec(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(asec, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for asec(): ", arg);
		return NULL;
	}
	return out;
}

static double acsc(double x) {
	return asin(1.0 / x);
}

static PyObject* acsc_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(acsc(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(acsc, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for acsc(): ", arg);
		return NULL;
	}
	return out;
}

static double acot(double x) {
	const double pi_over_2 = 3.1415526535897932384626433832795 / 2.0;
	return pi_over_2 - atan(x);
}

static PyObject* acot_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(acot(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(acot, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for acot(): ", arg);
		return NULL;
	}
	return out;
}

static double sech(double angle) {
	return 1.0 / cosh(angle);
}

static PyObject* sech_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(sech(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(sech, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for sech(): ", arg);
		return NULL;
	}
	return out;
}

static double csch(double angle) {
	return 1.0 / sinh(angle);
}

static PyObject* csch_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(csch(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(csch, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for csch(): ", arg);
		return NULL;
	}
	return out;
}

static double coth(double angle) {
	return cosh(angle) / sinh(angle);
}

static PyObject* coth_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(coth(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(coth, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for coth(): ", arg);
		return NULL;
	}
	return out;
}

static double asech(double x) {
	return acosh(1.0 / x);
}

static PyObject* asech_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(asech(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(asech, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for asech(): ", arg);
		return NULL;
	}
	return out;
}

static double acsch(double x) {
	return asinh(1.0 / x);
}

static PyObject* acsch_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(acsch(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(acsch, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for acsch(): ", arg);
		return NULL;
	}
	return out;
}

static double acoth(double x) {
	return atanh(1.0 / x);
}

static PyObject* acoth_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(acoth(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(acoth, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for acoth(): ", arg);
		return NULL;
	}
	return out;
}