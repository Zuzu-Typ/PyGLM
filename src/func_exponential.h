static PyObject* log2_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(log2(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(log2, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for log2(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* pow_(PyObject* self, PyObject* args) {
	PyObject *arg1, *arg2;
	UNPACK_2_VARARGS(args, "pow", arg1, arg2);

	PyObject * out = functor2(pow, arg1, arg2);
	if (out == NULL) {
		PY_TYPEERROR_2O("unsupported operand type(s) for pow(): ", arg1, arg2);
		return NULL;
	}
	return out;
}

static PyObject* exp_(PyObject* self, PyObject* arg) {
	PyObject * out = functor1(exp, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for exp(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* log_(PyObject* self, PyObject* arg) {
	PyObject * out = functor1(log, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for log(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* exp2_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(exp2(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(exp2, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for exp2(): ", arg);
		return NULL;
	}
	return out;
}

static PyObject* sqrt_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(sqrt(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(sqrt, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for sqrt(): ", arg);
		return NULL;
	}
	return out;
}

static double inversesqrt(double x) {
	return 1. / sqrt(x);
}

static PyObject* inversesqrt_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(1./sqrt(pyvalue_as_double(arg)));
	}
	PyObject * out = functor1(inversesqrt, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for inversesqrt(): ", arg);
		return NULL;
	}
	return out;
}