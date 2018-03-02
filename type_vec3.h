static void
tvec3_dealloc(tvec3* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tvec3_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tvec3 *self;

	self = (tvec3 *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->x = 0;
		self->y = 0;
		self->z = 0;
	}

	return (PyObject *)self;
}

static int
tvec3_init(tvec3 *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x", "y", "z", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOO", kwlist,
		&arg1, &arg2, &arg3)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (IS_NUMERIC(arg1)) {
				self->x = self->y = self->z = pyvalue_as_double(arg1);
				return 0;
			}

			void* o = NULL;
			char vecType = unpack_ivec(arg1, &o);

			if (vecType == GLM_TVEC3) {
				self->x = ((ivec3*)o)->x;
				self->y = ((ivec3*)o)->y;
				self->z = ((ivec3*)o)->z;
				free(o);
				return 0;
			}
			if (vecType == GLM_TVEC4) {
				self->x = ((ivec4*)o)->x;
				self->y = ((ivec4*)o)->y;
				self->z = ((ivec4*)o)->z;
				free(o);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
			return -1;
		}
		if (arg3 == NULL) {
			if (IS_NUMERIC(arg1)) {
				ivec2 o;
				if (!unpack_ivec2p(arg2, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
					return -1;
				}
				self->x = pyvalue_as_double(arg1);
				self->y = o.x;
				self->z = o.y;
				return 0;
			}
			if (IS_NUMERIC(arg2)) {
				ivec2 o;
				if (!unpack_ivec2p(arg1, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
					return -1;
				}
				self->x = o.x;
				self->y = o.y;
				self->z = pyvalue_as_double(arg2);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
			return -1;
		}
		if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3)) {
			self->x = pyvalue_as_double(arg1);
			self->y = pyvalue_as_double(arg2);
			self->z = pyvalue_as_double(arg3);
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
	return -1;
}

// unaryfunc
static PyObject *
tvec3_neg(tvec3 *obj)
{
	return pack_tvec3(-obj->x, -obj->y, -obj->z);
}

static PyObject *
tvec3_pos(tvec3 *obj)
{
	return pack_tvec3(obj->x, obj->y, obj->z);
}

static PyObject *
tvec3_abs(tvec3 *obj)
{
	return pack_tvec3(fabs(obj->x), fabs(obj->y), fabs(obj->z));
}

// binaryfunc
static PyObject *
tvec3_add(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec3(
			d + ((tvec3*)obj2)->x,
			d + ((tvec3*)obj2)->y,
			d + ((tvec3*)obj2)->z
		);
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec3(
			o.x + d,
			o.y + d,
			o.z + d
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	PyObject* out = pack_tvec3(
		o.x + o2.x,
		o.y + o2.y,
		o.z + o2.z
	);
	return out;
}

static PyObject *
tvec3_sub(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec3(
			d - ((tvec3*)obj2)->x,
			d - ((tvec3*)obj2)->y,
			d - ((tvec3*)obj2)->z
		);
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec3(
			o.x - d,
			o.y - d,
			o.z - d
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	PyObject* out = pack_tvec3(
		o.x - o2.x,
		o.y - o2.y,
		o.z - o2.z
	);
	return out;
}

static PyObject *
tvec3_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec3(
			d * ((tvec3*)obj2)->x,
			d * ((tvec3*)obj2)->y,
			d * ((tvec3*)obj2)->z
		);
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec3(
			o.x * d,
			o.y * d,
			o.z * d
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	PyObject* out = pack_tvec3(
		o.x * o2.x,
		o.y * o2.y,
		o.z * o2.z
	);
	return out;
}

static PyObject *
tvec3_div(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec3(
			d / ((tvec3*)obj2)->x,
			d / ((tvec3*)obj2)->y,
			d / ((tvec3*)obj2)->z
		);
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec3(
			o.x / d,
			o.y / d,
			o.z / d
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	PyObject* out = pack_tvec3(
		o.x / o2.x,
		o.y / o2.y,
		o.z / o2.z
	);
	return out;
}

static PyObject *
tvec3_mod(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec3(
			fmod(d, ((tvec3*)obj2)->x),
			fmod(d, ((tvec3*)obj2)->y),
			fmod(d, ((tvec3*)obj2)->z)
		);
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for %: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec3(
			fmod(o.x, d),
			fmod(o.y, d),
			fmod(o.z, d)
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	PyObject* out = pack_tvec3(
		fmod(o.x, o2.x),
		fmod(o.y, o2.y),
		fmod(o.z, o2.z)
	);
	return out;
}

static PyObject *
tvec3_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		return pack_tvec3(
			floor(d / ((tvec3*)obj2)->x),
			floor(d / ((tvec3*)obj2)->y),
			floor(d / ((tvec3*)obj2)->z)
		);
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for //: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		PyObject* out = pack_tvec3(
			floor(o.x / d),
			floor(o.y / d),
			floor(o.z / d)
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	PyObject* out = pack_tvec3(
		floor(o.x / o2.x),
		floor(o.y / o2.y),
		floor(o.z / o2.z)
	);
	return out;
}

static PyObject *
tvec3_divmod(PyObject * obj1, PyObject * obj2) {
	return Py_BuildValue("(OO)", tvec3_floordiv(obj1, obj2), tvec3_mod(obj1, obj2));
}

// ternaryfunc
static PyObject *
tvec3_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar, obj2 is self
		double d = pyvalue_as_double(obj1);

		if (obj3 == Py_None) {
			return pack_tvec3(
				pow(d, ((tvec3*)obj2)->x),
				pow(d, ((tvec3*)obj2)->y),
				pow(d, ((tvec3*)obj2)->z)
			);
		}

		if (IS_NUMERIC(obj3)) {
			double d2 = pyvalue_as_double(obj3);
			return pack_tvec3(
				fmod(pow(d, ((tvec3*)obj2)->x), d2),
				fmod(pow(d, ((tvec3*)obj2)->y), d2),
				fmod(pow(d, ((tvec3*)obj2)->z), d2)
			);
		}

		ivec3 o3;

		if (!unpack_ivec3p(obj3, &o3)) {
			PY_TYPEERROR("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		PyObject* out = pack_tvec3(
			fmod(pow(d, ((tvec3*)obj2)->x), o3.x),
			fmod(pow(d, ((tvec3*)obj2)->y), o3.y),
			fmod(pow(d, ((tvec3*)obj2)->z), o3.z)
		);
		return out;
	}

	ivec3 o;

	if (!unpack_ivec3p(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for **: 'glm::detail::tvec3' and ", obj1);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);

		if (obj3 == Py_None) {
			PyObject* out = pack_tvec3(
				pow(o.x, d),
				pow(o.y, d),
				pow(o.z, d)
			);
			return out;
		}

		if (IS_NUMERIC(obj3)) {
			double d2 = pyvalue_as_double(obj3);
			PyObject* out = pack_tvec3(
				fmod(pow(o.x, d), d2),
				fmod(pow(o.y, d), d2),
				fmod(pow(o.z, d), d2)
			);
			return out;
		}

		ivec3 o3;

		if (!unpack_ivec3p(obj3, &o3)) {
			PY_TYPEERROR("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		PyObject* out = pack_tvec3(
			fmod(pow(o.x, d), o3.x),
			fmod(pow(o.y, d), o3.y),
			fmod(pow(o.z, d), o3.z)
		);
		return out;
	}

	ivec3 o2;

	if (!unpack_ivec3p(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		Py_RETURN_NOTIMPLEMENTED;
	}

	// obj1 and obj2 can be interpreted as a tvec3
	if (obj3 == Py_None) {
		PyObject* out = pack_tvec3(
			pow(o.x, o2.x),
			pow(o.y, o2.y),
			pow(o.z, o2.z)
		);
		return out;
	}

	if (IS_NUMERIC(obj3)) {
		double d2 = pyvalue_as_double(obj3);
		PyObject* out = pack_tvec3(
			fmod(pow(o.x, o2.x), d2),
			fmod(pow(o.y, o2.y), d2),
			fmod(pow(o.z, o2.z), d2)
		);
		return out;
	}

	ivec3 o3;

	if (!unpack_ivec3p(obj3, &o3)) {
		PY_TYPEERROR("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	PyObject* out = pack_tvec3(
		fmod(pow(o.x, o2.x), o3.x),
		fmod(pow(o.y, o2.y), o3.y),
		fmod(pow(o.z, o2.z), o3.z)
	);
	return out;
}

// inplace
// binaryfunc
static PyObject *
tvec3_iadd(tvec3 *self, PyObject *obj)
{
	tvec3 * temp = (tvec3*)tvec3_add((PyObject*)self, obj);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec3_isub(tvec3 *self, PyObject *obj)
{
	tvec3 * temp = (tvec3*)tvec3_sub((PyObject*)self, obj);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec3_imul(tvec3 *self, PyObject *obj)
{
	tvec3 * temp = (tvec3*)tvec3_mul((PyObject*)self, obj);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec3_idiv(tvec3 *self, PyObject *obj)
{
	tvec3 * temp = (tvec3*)tvec3_div((PyObject*)self, obj);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec3_imod(tvec3 *self, PyObject *obj)
{
	tvec3 * temp = (tvec3*)tvec3_mod((PyObject*)self, obj);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tvec3_ifloordiv(tvec3 *self, PyObject *obj)
{
	tvec3 * temp = (tvec3*)tvec3_floordiv((PyObject*)self, obj);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
static PyObject *
tvec3_ipow(tvec3 *self, PyObject *obj1, PyObject * obj2)
{
	tvec3 * temp = (tvec3*)tvec3_pow((PyObject*)self, obj1, Py_None);

	if (PY_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyMemberDef tvec3_members[] = {
	{ "x", T_DOUBLE, offsetof(tvec3, x), 0,
	"vec x" },
{ "y", T_DOUBLE, offsetof(tvec3, y), 0,
"vec y" },
{ "z", T_DOUBLE, offsetof(tvec3, z), 0,
"vec z" },
{ NULL }  /* Sentinel */
};

static PyObject *
tvec3_str(tvec3* self)
{
	char * out = (char*)malloc((50) * sizeof(char));
	snprintf(out,50, "tvec3( %12.6g, %12.6g, %12.6g )", self->x, self->y, self->z);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tvec3_len(tvec3 * self) {
	return (Py_ssize_t)3;
}

static PyObject* tvec3_sq_item(tvec3 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble(self->x);
		break;
	case 1:
		return PyFloat_FromDouble(self->y);
		break;
	case 2:
		return PyFloat_FromDouble(self->z);
		break;
	case -1:
		return PyFloat_FromDouble(self->z);
		break;
	case -2:
		return PyFloat_FromDouble(self->y);
		break;
	case -3:
		return PyFloat_FromDouble(self->x);
		break;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int tvec3_sq_setitem(tvec3 * self, Py_ssize_t index, PyObject * value) {
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
		break;
	case 1:
		self->y = d;
		return 0;
		break;
	case 2:
		self->z = d;
		return 0;
		break;
	case -1:
		self->z = d;
		return 0;
		break;
	case -2:
		self->y = d;
		return 0;
		break;
	case -3:
		self->x = d;
		return 0;
		break;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tvec3_contains(tvec3 * self, PyObject * value) {
	double d;
	if (IS_NUMERIC(value)) {
		d = pyvalue_as_double(value);
		return (int)(d == self->x || d == self->y || d == self->z);
	}
	return 0;
	
}

static PyObject * tvec3_richcompare(tvec3 * self, PyObject * other, int comp_type) {
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tvec3Type)) { // incopatible type
			Py_RETURN_FALSE;
		}
		return PyBool_FromLong((self->x == ((tvec3*)other)->x) && (self->y == ((tvec3*)other)->y) && (self->z == ((tvec3*)other)->z));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tvec3Type)) { // incopatible type
			Py_RETURN_TRUE;
		}
		return PyBool_FromLong((self->x != ((tvec3*)other)->x) || (self->y != ((tvec3*)other)->y) || (self->z != ((tvec3*)other)->z));
	}
	else if (comp_type == Py_LT) {
		if (!PyObject_TypeCheck(other, &tvec3Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for <: 'glm::detail::tvec3' and ", other);
			return NULL;
		}
		return pack_tvec3((double)(self->x < ((tvec3*)other)->x), (double)(self->y < ((tvec3*)other)->y), (double)(self->z < ((tvec3*)other)->z));
	}
	else if (comp_type == Py_LE) {
		if (!PyObject_TypeCheck(other, &tvec3Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for <=: 'glm::detail::tvec3' and ", other);
			return NULL;
		}
		return pack_tvec3((double)(self->x <= ((tvec3*)other)->x), (double)(self->y <= ((tvec3*)other)->y), (double)(self->z <= ((tvec3*)other)->z));
	}
	else if (comp_type == Py_GT) {
		if (!PyObject_TypeCheck(other, &tvec3Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for >: 'glm::detail::tvec3' and ", other);
			return NULL;
		}
		return pack_tvec3((double)(self->x > ((tvec3*)other)->x), (double)(self->y > ((tvec3*)other)->y), (double)(self->z > ((tvec3*)other)->z));
	}
	else if (comp_type == Py_GE) {
		if (!PyObject_TypeCheck(other, &tvec3Type)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for >=: 'glm::detail::tvec3' and ", other);
			return NULL;
		}
		return pack_tvec3((double)(self->x >= ((tvec3*)other)->x), (double)(self->y >= ((tvec3*)other)->y), (double)(self->z >= ((tvec3*)other)->z));
	}
	else {
		PY_TYPEERROR("this operator is not supported between instances of 'function' and ", other);
		return NULL;
	}
}

static bool unswizzle_tvec3(tvec3 * self, char c, double * out) {
	if (c == 'x' || c == 'r' || c == 's') {
		*out = self->x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		*out = self->y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		*out = self->z;
		return true;
	}
	return false;
}

static PyObject * tvec3_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = attr_name_to_cstr(name);
	size_t len = strlen(name_as_ccp);

	if ((len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_')
		|| strcmp(name_as_ccp, "x") == 0 || strcmp(name_as_ccp, "y") == 0 || strcmp(name_as_ccp, "z") == 0) {
		return PyObject_GenericGetAttr(obj, name);
	}
	
	if (len == 1) {
		double x;
		if (unswizzle_tvec3((tvec3 *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble(x);
		}
	}
	else if (len == 2) {
		double x;
		double y;
		if (unswizzle_tvec3((tvec3 *)obj, name_as_ccp[0], &x) && unswizzle_tvec3((tvec3 *)obj, name_as_ccp[1], &y)) {
			return pack_tvec2(x, y);
		}
	}
	else if (len == 3) {
		double x;
		double y;
		double z;
		if (unswizzle_tvec3((tvec3 *)obj, name_as_ccp[0], &x) && unswizzle_tvec3((tvec3 *)obj, name_as_ccp[1], &y) && unswizzle_tvec3((tvec3 *)obj, name_as_ccp[2], &z)) {
			return pack_tvec3(x, y, z);
		}
	}
	else if (len == 4) {
		double x;
		double y;
		double z;
		double w;
		if (unswizzle_tvec3((tvec3 *)obj, name_as_ccp[0], &x) && unswizzle_tvec3((tvec3 *)obj, name_as_ccp[1], &y) && unswizzle_tvec3((tvec3 *)obj, name_as_ccp[2], &z) && unswizzle_tvec3((tvec3 *)obj, name_as_ccp[3], &w)) {
			return pack_tvec4(x, y, z, w);
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
tvec3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tvec3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tvec3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tvec3Iter *rgstate = (tvec3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tvec3Iter_dealloc(tvec3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tvec3Iter_next(tvec3Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index) {
		case 0:
			rgstate->seq_index++;
			return PyFloat_FromDouble(rgstate->sequence->x);
		case 1:
			rgstate->seq_index++;
			return PyFloat_FromDouble(rgstate->sequence->y);
		case 2:
			rgstate->seq_index++;
			return PyFloat_FromDouble(rgstate->sequence->z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * tvec3_geniter(tvec3 * self) {
	PyObject * obj = tvec3Iter_new(&tvec3IterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tvec3SeqMethods = {
	(lenfunc)tvec3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tvec3_sq_item, // sq_item
	0,
	(ssizeobjargproc)tvec3_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tvec3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

#if PY3K
static PyNumberMethods tvec3NumMethods = {
	(binaryfunc)tvec3_add,
	(binaryfunc)tvec3_sub,
	(binaryfunc)tvec3_mul,
	(binaryfunc)tvec3_mod, //nb_remainder
	(binaryfunc)tvec3_divmod, //nb_divmod
	(ternaryfunc)tvec3_pow, //nb_power
	(unaryfunc)tvec3_neg, //nb_negative
	(unaryfunc)tvec3_pos, //nb_positive
	(unaryfunc)tvec3_abs, //nb_absolute
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

	(binaryfunc)tvec3_iadd, //nb_inplace_add
	(binaryfunc)tvec3_isub, //nb_inplace_subtract
	(binaryfunc)tvec3_imul, //nb_inplace_multiply
	(binaryfunc)tvec3_imod, //nb_inplace_remainder
	(ternaryfunc)tvec3_ipow, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	(binaryfunc)tvec3_floordiv, //nb_floor_divide
	(binaryfunc)tvec3_div,
	(binaryfunc)tvec3_ifloordiv, //nb_inplace_floor_divide
	(binaryfunc)tvec3_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tvec3NumMethods = {
	(binaryfunc)tvec3_add, //nb_add;
	(binaryfunc)tvec3_sub, //nb_subtract;
	(binaryfunc)tvec3_mul, //nb_multiply;
	(binaryfunc)tvec3_div, //nb_divide;
	(binaryfunc)tvec3_mod, //nb_remainder;
	(binaryfunc)tvec3_divmod, //nb_divmod;
	(ternaryfunc)tvec3_pow, //nb_power;
	(unaryfunc)tvec3_neg, //nb_negative;
	(unaryfunc)tvec3_pos, //nb_positive;
	(unaryfunc)tvec3_abs, //nb_absolute;
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
	   (binaryfunc)tvec3_iadd, //nb_inplace_add;
	   (binaryfunc)tvec3_isub, //nb_inplace_subtract;
	   (binaryfunc)tvec3_imul, //nb_inplace_multiply;
	   (binaryfunc)tvec3_idiv, //nb_inplace_divide;
	   (binaryfunc)tvec3_imod, //nb_inplace_remainder;
	   (ternaryfunc)tvec3_ipow, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  (binaryfunc)tvec3_floordiv, //nb_floor_divide;
		  (binaryfunc)tvec3_div, //nb_true_divide;
		  (binaryfunc)tvec3_ifloordiv, //nb_inplace_floor_divide;
		  (binaryfunc)tvec3_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tvec3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tvec3",             /* tp_name */
	sizeof(tvec3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tvec3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tvec3_str,                         /* tp_repr */
	&tvec3NumMethods,             /* tp_as_number */
	&tvec3SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tvec3_str,                         /* tp_str */
	(getattrofunc)tvec3_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE |
	Py_TPFLAGS_CHECKTYPES,   /* tp_flags */
	"tvec3( <tvec3 compatible type(s)> )\n3 components vector of medium double-qualifier floating-point numbers.",            /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tvec3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tvec3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tvec3_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tvec3_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tvec3_new,                 /* tp_new */
};

static PyTypeObject tvec3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tvec3Iter",             /* tp_name */
	sizeof(tvec3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tvec3Iter_dealloc, /* tp_dealloc */
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
	"tvec3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tvec3Iter_next,                         /* tp_iternext */
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
	(newfunc)tvec3Iter_new,                 /* tp_new */
};
