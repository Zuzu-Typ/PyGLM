static void
tvec2_dealloc(tvec2* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tvec2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tvec2 *self;

	self = (tvec2 *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->x = 0;
		self->y = 0;
	}

	return (PyObject *)self;
}

static int
tvec2_init(tvec2 *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x", "y", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OO", kwlist,
		&arg1, &arg2)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (IS_NUMERIC(arg1)) {
				self->x = self->y = pyvalue_as_double(arg1);
				return 0;
			}

			void* o = NULL;
			char vecType = unpack_ivec(arg1, &o);
			if (vecType == GLM_TVEC2) {
				self->x = ((ivec2*)o)->x;
				self->y = ((ivec2*)o)->y;
				free(o);
				return 0;
			}
			if (vecType == GLM_TVEC3) {
				self->x = ((ivec3*)o)->x;
				self->y = ((ivec3*)o)->y;
				free(o);
				return 0;
			}
			if (vecType == GLM_TVEC4) {
				self->x = ((ivec4*)o)->x;
				self->y = ((ivec4*)o)->y;
				free(o);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec2()");
			return -1;
		}
		if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2)) {
			self->x = pyvalue_as_double(arg1);
			self->y = pyvalue_as_double(arg2);
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec2()");
	return -1;
}

// unaryfunc
static PyObject *
tvec2_neg(tvec2 *obj)
{
	return pack_tvec2(-obj->x, -obj->y);
}

static PyObject *
tvec2_pos(tvec2 *obj)
{
	return pack_tvec2(obj->x, obj->y);
}

static PyObject *
tvec2_abs(tvec2 *obj)
{
	return pack_tvec2(fabs(obj->x), fabs(obj->y));
}

// binaryfunc
static PyObject *
tvec2_add(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec2(
			d + ((tvec2*)obj2)->x,
			d + ((tvec2*)obj2)->y
		);
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec2(
			o->x + d,
			o->y + d
		);
		free(o);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__radd__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tvec2
	PyObject* out = pack_tvec2(
		o->x + o2->x,
		o->y + o2->y
	);
	free(o);
	free(o2);
	return out;
}

static PyObject *
tvec2_sub(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec2(
			d - ((tvec2*)obj2)->x,
			d - ((tvec2*)obj2)->y
		);
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec2(
			o->x - d,
			o->y - d
		);
		free(o);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__rsub__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tvec2
	PyObject* out = pack_tvec2(
		o->x - o2->x,
		o->y - o2->y
	);
	free(o);
	free(o2);
	return out;
}

static PyObject *
tvec2_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec2(
			d * ((tvec2*)obj2)->x,
			d * ((tvec2*)obj2)->y
		);
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec2(
			o->x * d,
			o->y * d
		);
		free(o);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__rmul__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tvec2
	PyObject* out = pack_tvec2(
		o->x * o2->x,
		o->y * o2->y
	);
	free(o);
	free(o2);
	return out;
}

static PyObject *
tvec2_div(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec2(
			d / ((tvec2*)obj2)->x,
			d / ((tvec2*)obj2)->y
		);
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec2(
			o->x / d,
			o->y / d
		);
		free(o);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__rdiv__", "O", obj1);
		if (out == NULL) out = PyObject_CallMethod(obj2, "__rtruediv__", "O", obj1);

		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tvec2
	PyObject* out = pack_tvec2(
		o->x / o2->x,
		o->y / o2->y
	);
	free(o);
	free(o2);
	return out;
}

static PyObject *
tvec2_mod(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec2(
			fmod(d, ((tvec2*)obj2)->x),
			fmod(d, ((tvec2*)obj2)->y)
		);
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for %: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec2(
			fmod(o->x, d),
			fmod(o->y, d)
		);
		free(o);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__rmod__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for %: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tvec2
	PyObject* out = pack_tvec2(
		fmod(o->x, o2->x),
		fmod(o->y, o2->y)
	);
	free(o);
	free(o2);
	return out;
}

static PyObject *
tvec2_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec2(
			floor(d / ((tvec2*)obj2)->x),
			floor(d / ((tvec2*)obj2)->y)
		);
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for //: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec2(
			floor(o->x / d),
			floor(o->y / d)
		);
		free(o);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__rfloordiv__", "O", obj1);

		//if (out == NULL) out = PyObject_CallMethod(obj2, "__rdiv__", "O", obj1); // maybe?

		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for //: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tvec2
	PyObject* out = pack_tvec2(
		floor(o->x / o2->x),
		floor(o->y / o2->y)
	);
	free(o);
	free(o2);
	return out;
}

static PyObject *
tvec2_divmod(PyObject * obj1, PyObject * obj2) {
	return Py_BuildValue("(OO)", tvec2_floordiv(obj1, obj2), tvec2_mod(obj1, obj2));
}

// ternaryfunc
static PyObject *
tvec2_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		if (obj3 == Py_None) {
			return pack_tvec2(
				pow(d, ((tvec2*)obj2)->x),
				pow(d, ((tvec2*)obj2)->y)
			);
		}

		if (IS_NUMERIC(obj3)) {
			double d2 = pyvalue_as_double(obj3);
			return pack_tvec2(
				fmod(pow(d, ((tvec2*)obj2)->x), d2),
				fmod(pow(d, ((tvec2*)obj2)->y), d2)
			);
		}

		ivec2 * o3 = unpack_ivec2(obj3);

		if (o3 == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		PyObject* out = pack_tvec2(
			fmod(pow(d, ((tvec2*)obj2)->x), o3->x),
			fmod(pow(d, ((tvec2*)obj2)->y), o3->y)
		);
		free(o3);
		return out;
	}

	ivec2 * o = unpack_ivec2(obj1);

	if (o == NULL) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for **: 'glm::detail::tvec2' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);

		if (obj3 == Py_None) {
			PyObject* out = pack_tvec2(
				pow(o->x, d),
				pow(o->y, d)
			);
			free(o);
			return out;
		}

		if (IS_NUMERIC(obj3)) {
			double d2 = pyvalue_as_double(obj3);
			PyObject* out = pack_tvec2(
				fmod(pow(o->x, d), d2),
				fmod(pow(o->y, d), d2)
			);
			free(o);
			return out;
		}

		ivec2 * o3 = unpack_ivec2(obj3);

		if (o3 == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		PyObject* out = pack_tvec2(
			fmod(pow(o->x, d), o3->x),
			fmod(pow(o->y, d), o3->y)
		);
		free(o);
		free(o3);
		return out;
	}

	ivec2 * o2 = unpack_ivec2(obj2);

	if (o2 == NULL) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		free(o);
		PyObject * out = PyObject_CallMethod(obj2, "__rpow__", "O", obj1, obj3);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for **: 'glm::detail::tvec2' and ", obj2);
			return NULL;
		}
		return out;
	}



	// obj1 and obj2 can be interpreted as a tvec2
	if (obj3 == Py_None) {
		PyObject* out = pack_tvec2(
			pow(o->x, o2->x),
			pow(o->y, o2->y)
		);
		free(o);
		free(o2);
		return out;
	}

	if (IS_NUMERIC(obj3)) {
		double d2 = pyvalue_as_double(obj3);
		PyObject* out = pack_tvec2(
			fmod(pow(o->x, o2->x), d2),
			fmod(pow(o->y, o2->y), d2)
		);
		free(o);
		free(o2);
		return out;
	}

	ivec2 * o3 = unpack_ivec2(obj3);

	if (o3 == NULL) {
		free(o);
		free(o2);
		PY_TYPEERROR("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	PyObject* out = pack_tvec2(
		fmod(pow(o->x, o2->x), o3->x),
		fmod(pow(o->y, o2->y), o3->y)
	);
	free(o);
	free(o2);
	free(o3);
	return out;
}

// inplace
// binaryfunc
static PyObject *
tvec2_iadd(tvec2 *self, PyObject *obj)
{
	tvec2 * temp = (tvec2*)tvec2_add((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec2_isub(tvec2 *self, PyObject *obj)
{
	tvec2 * temp = (tvec2*)tvec2_sub((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec2_imul(tvec2 *self, PyObject *obj)
{
	tvec2 * temp = (tvec2*)tvec2_mul((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec2_idiv(tvec2 *self, PyObject *obj)
{
	tvec2 * temp = (tvec2*)tvec2_div((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec2_imod(tvec2 *self, PyObject *obj)
{
	tvec2 * temp = (tvec2*)tvec2_mod((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec2_ifloordiv(tvec2 *self, PyObject *obj)
{
	tvec2 * temp = (tvec2*)tvec2_floordiv((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
tvec2_ipow(tvec2 *self, PyObject *obj1, PyObject * obj2)
{
	tvec2 * temp = (tvec2*)tvec2_pow((PyObject*)self, obj1, obj2);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyMemberDef tvec2_members[] = {
	{ "x", T_DOUBLE, offsetof(tvec2, x), 0,
	"vec x" },
{ "y", T_DOUBLE, offsetof(tvec2, y), 0,
"vec y" },
{ NULL }  /* Sentinel */
};

static PyObject *
tvec2_str(tvec2* self)
{
	char * out = (char*)malloc((36) * sizeof(char));
	snprintf(out, 36,"tvec2( %12.6g, %12.6g )", self->x, self->y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tvec2_len(tvec2 * self) {
	return (Py_ssize_t)2;
}

static PyObject* tvec2_sq_item(tvec2 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble(self->x);
	case 1:
		return PyFloat_FromDouble(self->y);
	case -1:
		return PyFloat_FromDouble(self->y);
	case -2:
		return PyFloat_FromDouble(self->x);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int tvec2_sq_setitem(tvec2 * self, Py_ssize_t index, PyObject * value) {
	double d;
	if (IS_NUMERIC(value)) {
		d = pyvalue_as_double(value);
	}
	else {
		PY_TYPEERROR("must be real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->x = d;
		return 0;
	case 1:
		self->y = d;
		return 0;
	case -1:
		self->y = d;
		return 0;
	case -2:
		self->x = d;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tvec2_contains(tvec2 * self, PyObject * value) {
	double d;
	if (IS_NUMERIC(value)) {
		d = pyvalue_as_double(value);
		return (int)(d == self->x || d == self->y);
	}
	return 0;
	
}

static PyObject * tvec2_richcompare(tvec2 * self, PyObject * other, int comp_type) {
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tvec2Type)) { // incopatible type
			Py_RETURN_FALSE;
		}
		return PyBool_FromLong((self->x == ((tvec2*)other)->x) && (self->y == ((tvec2*)other)->y));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tvec2Type)) { // incopatible type
			Py_RETURN_TRUE;
		}
		return PyBool_FromLong((self->x != ((tvec2*)other)->x) || (self->y != ((tvec2*)other)->y));
	}
	else if (comp_type == Py_LT) {
		if (!PyObject_TypeCheck(other, &tvec2Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for <: 'glm::detail::tvec2' and ", other);
			return NULL;
		}
		return pack_tvec2((double)(self->x < ((tvec2*)other)->x), (double)(self->y < ((tvec2*)other)->y));
	}
	else if (comp_type == Py_LE) {
		if (!PyObject_TypeCheck(other, &tvec2Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for <=: 'glm::detail::tvec2' and ", other);
			return NULL;
		}
		return pack_tvec2((double)(self->x <= ((tvec2*)other)->x), (double)(self->y <= ((tvec2*)other)->y));
	}
	else if (comp_type == Py_GT) {
		if (!PyObject_TypeCheck(other, &tvec2Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for >: 'glm::detail::tvec2' and ", other);
			return NULL;
		}
		return pack_tvec2((double)(self->x > ((tvec2*)other)->x), (double)(self->y > ((tvec2*)other)->y));
	}
	else if (comp_type == Py_GE) {
		if (!PyObject_TypeCheck(other, &tvec2Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for >=: 'glm::detail::tvec2' and ", other);
			return NULL;
		}
		return pack_tvec2((double)(self->x >= ((tvec2*)other)->x), (double)(self->y >= ((tvec2*)other)->y));
	}
	else {
		PY_TYPEERROR("this operator is not supported between instances of 'function' and ", other);
		return NULL;
	}
}

static bool unswizzle_tvec2(tvec2 * self, char c, double * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->y;
		return true;
	}
	return false;
}

static PyObject * tvec2_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = attr_name_to_cstr(name);

	if ((strlen(name_as_ccp) >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[strlen(name_as_ccp) - 1] == '_' && name_as_ccp[strlen(name_as_ccp) - 2] == '_')
		|| strcmp(name_as_ccp, "x") == 0 || strcmp(name_as_ccp, "y") == 0) {
		return PyObject_GenericGetAttr(obj, name);
	}
	size_t len = strlen(name_as_ccp);
	if (len == 1) {
		double x;
		if (unswizzle_tvec2((tvec2 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble(x);
		}
	}
	else if (len == 2) {
		double x;
		double y;
		if (unswizzle_tvec2((tvec2 *)obj, name_as_ccp[0], &x) && unswizzle_tvec2((tvec2 *)obj, name_as_ccp[1], &y)) {
			return pack_tvec2(x, y);
		}
	}
	else if (len == 3) {
		double x;
		double y;
		double z;
		if (unswizzle_tvec2((tvec2 *)obj, name_as_ccp[0], &x) && unswizzle_tvec2((tvec2 *)obj, name_as_ccp[1], &y) && unswizzle_tvec2((tvec2 *)obj, name_as_ccp[2], &z)) {
			return pack_tvec3(x, y, z);
		}
	}
	else if (len == 4) {
		double x;
		double y;
		double z;
		double w;
		if (unswizzle_tvec2((tvec2 *)obj, name_as_ccp[0], &x) && unswizzle_tvec2((tvec2 *)obj, name_as_ccp[1], &y) && unswizzle_tvec2((tvec2 *)obj, name_as_ccp[2], &z) && unswizzle_tvec2((tvec2 *)obj, name_as_ccp[3], &w)) {
			return pack_tvec4(x, y, z, w);
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
tvec2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tvec2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tvec2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tvec2Iter *rgstate = (tvec2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tvec2Iter_dealloc(tvec2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tvec2Iter_next(tvec2Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		switch (rgstate->seq_index) {
		case 0:
			rgstate->seq_index++;
			return PyFloat_FromDouble(rgstate->sequence->x);
		case 1:
			rgstate->seq_index++;
			return PyFloat_FromDouble(rgstate->sequence->y);
		}
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * tvec2_geniter(tvec2 * self) {
	PyObject * obj = tvec2Iter_new(&tvec2IterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tvec2SeqMethods = {
	(lenfunc)tvec2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tvec2_sq_item, // sq_item
	0,
	(ssizeobjargproc)tvec2_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tvec2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

#if PY3K
static PyNumberMethods tvec2NumMethods = {
	(binaryfunc)tvec2_add,
	(binaryfunc)tvec2_sub,
	(binaryfunc)tvec2_mul,
	(binaryfunc)tvec2_mod, //nb_remainder
	(binaryfunc)tvec2_divmod, //nb_divmod
	(ternaryfunc)tvec2_pow, //nb_power
	(unaryfunc)tvec2_neg, //nb_negative
	(unaryfunc)tvec2_pos, //nb_positive
	(unaryfunc)tvec2_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)tvec2_iadd, //nb_inplace_add
	(binaryfunc)tvec2_isub, //nb_inplace_subtract
	(binaryfunc)tvec2_imul, //nb_inplace_multiply
	(binaryfunc)tvec2_imod, //nb_inplace_remainder
	(ternaryfunc)tvec2_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)tvec2_floordiv, //nb_floor_divide
	(binaryfunc)tvec2_div,
	(binaryfunc)tvec2_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)tvec2_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tvec2NumMethods = {
	(binaryfunc)tvec2_add, //nb_add;
	(binaryfunc)tvec2_sub, //nb_subtract;
	(binaryfunc)tvec2_mul, //nb_multiply;
	(binaryfunc)tvec2_div, //nb_divide;
	(binaryfunc)tvec2_mod, //nb_remainder;
	(binaryfunc)tvec2_divmod, //nb_divmod;
	(ternaryfunc)tvec2_pow, //nb_power;
	(unaryfunc)tvec2_neg, //nb_negative;
	(unaryfunc)tvec2_pos, //nb_positive;
	(unaryfunc)tvec2_abs, //nb_absolute;
	0, //nb_nonzero;       /* Used by PyObject_IsTrue */
	0, //nb_invert;
	0, //nb_lshift;
	0, //nb_rshift;
	0, //nb_and;
	0, //nb_xor;
	0, //nb_or;
	0, //nb_coerce;       /* Used by the coerce() function */
	0, //nb_int;
	0, //nb_long;
	0, //nb_float;
	0, //nb_oct;
	0, //nb_hex;

	   /* Added in release 2.0 */
	   (binaryfunc)tvec2_iadd, //nb_inplace_add;
	   (binaryfunc)tvec2_isub, //nb_inplace_subtract;
	   (binaryfunc)tvec2_imul, //nb_inplace_multiply;
	   (binaryfunc)tvec2_idiv, //nb_inplace_divide;
	   (binaryfunc)tvec2_imod, //nb_inplace_remainder;
	   (ternaryfunc)tvec2_ipow, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  (binaryfunc)tvec2_floordiv, //nb_floor_divide;
		  (binaryfunc)tvec2_div, //nb_true_divide;
		  (binaryfunc)tvec2_ifloordiv, //nb_inplace_floor_divide;
		  (binaryfunc)tvec2_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tvec2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tvec2",             /* tp_name */
	sizeof(tvec2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tvec2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tvec2_str,                         /* tp_repr */
	&tvec2NumMethods,             /* tp_as_number */
	&tvec2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tvec2_str,                         /* tp_str */
	(getattrofunc)tvec2_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"tvec2( <tvec2 compatible type(s)> )\n2 components vector of medium double-qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tvec2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tvec2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tvec2_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tvec2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tvec2_new,                 /* tp_new */
};

static PyTypeObject tvec2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tvec2Iter",             /* tp_name */
	sizeof(tvec2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tvec2Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"tvec2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tvec2Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tvec2Iter_new,                 /* tp_new */
};
