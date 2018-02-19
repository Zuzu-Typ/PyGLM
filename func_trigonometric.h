static double radians_(double x) {
	return x * 0.01745329251994329576923690768489;
}

static PyObject* radians(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(pyvalue_as_double(arg) * 0.01745329251994329576923690768489);

	}
	PyObject* out = functor1(radians_, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for radians(): expected int or float, got ", arg);
		return NULL;
	}
	return out;
}

static double degrees_(double x) {
	return x * 57.295779513082320876798154814105;
}

static PyObject* degrees(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(pyvalue_as_double(arg) * 57.295779513082320876798154814105);
	}
	PyObject* out = functor1(degrees_, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for degrees(): expected int or float, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* sin_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(sin, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for sin(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* cos_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(cos, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for cos(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* tan_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(tan, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for tan(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* asin_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(asin, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for asin(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* acos_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(acos, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for acos(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* atan_(PyObject* self, PyObject* args, PyObject* kwargs) {
	static char *kwlist[] = { "y", "x", NULL };
	PyObject* arg1 = NULL, *arg2 = NULL;
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|O", kwlist, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for atan()");
		return NULL;
	}

	if (arg2 != NULL) {
		if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
			return PyFloat_FromDouble(atan2(pyvalue_as_double(arg1), pyvalue_as_double(arg2)));
		}
		PyObject* out = functor2(atan2, arg1, arg2);

		if (out == NULL) {
			PY_TYPEERROR_2O("unsupported operand type for atan(): ", arg1, arg2);
			return NULL;
		}
		return out;
	}

	PyObject* out = functor1(atan, arg1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for atan(): expected tvecn, got ", arg1);
		return NULL;
	}
	return out;
}

static PyObject* sinh_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(sinh, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for sinh(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* cosh_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(cosh, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for cosh(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* tanh_(PyObject* self, PyObject* arg) {
	PyObject* out = functor1(tanh, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for tanh(): expected tvecn, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* asinh_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(asinh(pyvalue_as_double(arg)));
	}
	PyObject* out = functor1(asinh, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for asinh(): expected int or float, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* acosh_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(acosh(pyvalue_as_double(arg)));
	}
	PyObject* out = functor1(acosh, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for acosh(): expected int or float, got ", arg);
		return NULL;
	}
	return out;
}

static PyObject* atanh_(PyObject* self, PyObject* arg) {
	if (IS_NUMERIC(arg)) {
		return PyFloat_FromDouble(atanh(pyvalue_as_double(arg)));
	}
	PyObject* out = functor1(atanh, arg);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type for atanh(): expected int or float, got ", arg);
		return NULL;
	}
	return out;
}