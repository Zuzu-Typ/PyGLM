static void
tmat2x3_dealloc(tmat2x3* self)
{
	Py_DECREF(self->x);
	Py_DECREF(self->y);
	//Py_DECREF(self->col_type);
	//Py_DECREF(self->row_type);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tmat2x3_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tmat2x3 *self;

	self = (tmat2x3 *)type->tp_alloc(type, 0);

	PyObject *v1 = pack_tvec3(0, 0, 0);
	PyObject *v2 = pack_tvec3(0, 0, 0);

	if (self != NULL) {
		self->x = (tvec3*)v1;
		self->y = (tvec3*)v2;
		self->col_type = (PyObject*)&tvec3Type;
		self->row_type = (PyObject*)&tvec3Type;
	}

	return (PyObject *)self;
}

static int
tmat2x3_init(tmat2x3 *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x0", "x1", "x2", "y0", "y1", "y2", NULL };

	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOOOOO", kwlist,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (IS_NUMERIC(arg1)) {
			self->x->x = self->y->y = pyvalue_as_double(arg1);
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_imat(arg1, &o);
		switch (vecType) {
		case GLM_TMAT2x2:
			self->x->x = ((imat2x2*)o)->x.x;
			self->x->y = ((imat2x2*)o)->x.y;
			self->x->z = 0.0;
			self->y->x = ((imat2x2*)o)->y.x;
			self->y->y = ((imat2x2*)o)->y.y;
			self->y->z = 0.0;
			free(o);
			return 0;
		case GLM_TMAT2x3:
			self->x->x = ((imat2x3*)o)->x.x;
			self->x->y = ((imat2x3*)o)->x.y;
			self->x->z = ((imat2x3*)o)->x.z;
			self->y->x = ((imat2x3*)o)->y.x;
			self->y->y = ((imat2x3*)o)->y.y;
			self->y->z = ((imat2x3*)o)->y.z;
			free(o);
			return 0;
		case GLM_TMAT2x4:
			self->x->x = ((imat2x4*)o)->x.x;
			self->x->y = ((imat2x4*)o)->x.y;
			self->x->z = ((imat2x4*)o)->x.z;
			self->y->x = ((imat2x4*)o)->y.x;
			self->y->y = ((imat2x4*)o)->y.y;
			self->y->z = ((imat2x4*)o)->y.z;
			free(o);
			return 0;
		case GLM_TMAT3x2:
			self->x->x = ((imat3x2*)o)->x.x;
			self->x->y = ((imat3x2*)o)->x.y;
			self->x->z = 0.0;
			self->y->x = ((imat3x2*)o)->y.x;
			self->y->y = ((imat3x2*)o)->y.y;
			self->y->z = 0.0;
			free(o);
			return 0;
		case GLM_TMAT3x3:
			self->x->x = ((imat3x3*)o)->x.x;
			self->x->y = ((imat3x3*)o)->x.y;
			self->x->z = ((imat3x3*)o)->x.z;
			self->y->x = ((imat3x3*)o)->y.x;
			self->y->y = ((imat3x3*)o)->y.y;
			self->y->z = ((imat3x3*)o)->y.z;
			free(o);
			return 0;
		case GLM_TMAT3x4:
			self->x->x = ((imat3x4*)o)->x.x;
			self->x->y = ((imat3x4*)o)->x.y;
			self->x->z = ((imat3x4*)o)->x.z;
			self->y->x = ((imat3x4*)o)->y.x;
			self->y->y = ((imat3x4*)o)->y.y;
			self->y->z = ((imat3x4*)o)->y.z;
			free(o);
			return 0;
		case GLM_TMAT4x2:
			self->x->x = ((imat4x2*)o)->x.x;
			self->x->y = ((imat4x2*)o)->x.y;
			self->x->z = 0.0;
			self->y->x = ((imat4x2*)o)->y.x;
			self->y->y = ((imat4x2*)o)->y.y;
			self->y->z = 0.0;
			free(o);
			return 0;
		case GLM_TMAT4x3:
			self->x->x = ((imat4x3*)o)->x.x;
			self->x->y = ((imat4x3*)o)->x.y;
			self->x->z = ((imat4x3*)o)->x.z;
			self->y->x = ((imat4x3*)o)->y.x;
			self->y->y = ((imat4x3*)o)->y.y;
			self->y->z = ((imat4x3*)o)->y.z;
			free(o);
			return 0;
		case GLM_TMAT4x4:
			self->x->x = ((imat4x4*)o)->x.x;
			self->x->y = ((imat4x4*)o)->x.y;
			self->x->z = ((imat4x4*)o)->x.z;
			self->y->x = ((imat4x4*)o)->y.x;
			self->y->y = ((imat4x4*)o)->y.y;
			self->y->z = ((imat4x4*)o)->y.z;
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x3()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		ivec3* o = unpack_ivec3(arg1);
		if (o == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x3()");
			return -1;
		}
		ivec3* o2 = unpack_ivec3(arg2);
		if (o2 == NULL) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x3()");
			return -1;
		}
		self->x->x = o->x;
		self->x->y = o->y;
		self->x->z = o->z;
		self->y->x = o2->x;
		self->y->y = o2->y;
		self->y->z = o2->z;
		return 0;
	}

	if (arg4 == NULL || arg5 == NULL || arg6 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x3()");
		return -1;
	}

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6)) {
		self->x->x = pyvalue_as_double(arg1);
		self->x->y = pyvalue_as_double(arg2);
		self->x->z = pyvalue_as_double(arg3);
		self->y->x = pyvalue_as_double(arg4);
		self->y->y = pyvalue_as_double(arg5);
		self->y->z = pyvalue_as_double(arg6);
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x3()");
	return -1;
}

// unaryfunc
static PyObject *
tmat2x3_neg(tmat2x3 *obj)
{
	PyObject* argList = Py_BuildValue("OO", PyObject_CallMethod((PyObject*)obj->x, "__neg__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__neg__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat2x3_pos(tmat2x3 *obj)
{
	PyObject* argList = Py_BuildValue("OO", obj->x, obj->y);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat2x3_abs(tmat2x3 *obj)
{
	PyObject* argList = Py_BuildValue("OO", PyObject_CallMethod((PyObject*)obj->x, "__abs__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__abs__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x3Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

// binaryfunc
static PyObject *
tmat2x3_add(PyObject *obj1, PyObject *obj2)
{
	imat2x3 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.x.z = o.y.x = o.y.y = o.y.z = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat2x3
		if (!unpack_imat2x3p(obj1, &o)) { // obj1 can't be interpreted as tmat2x3
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::tmat2x3'");
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x += d;
		o.x.y += d;
		o.x.z += d;
		o.y.x += d;
		o.y.y += d;
		o.y.z += d;
	}
	else { // obj2 can be converted to a tmat2x3
		imat2x3 o2;

		if (!unpack_imat2x3p(obj2, &o2)) { // obj2 can't be interpreted as tmat2x3
			PyObject * out = PyObject_CallMethod(obj2, "__radd__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tmat2x3' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x += o2.x.x;
		o.x.y += o2.x.y;
		o.x.z += o2.x.z;
		o.y.x += o2.y.x;
		o.y.y += o2.y.y;
		o.y.z += o2.y.z;
	}

	return build_imat2x3(o);
}

static PyObject *
tmat2x3_sub(PyObject *obj1, PyObject *obj2)
{
	imat2x3 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.x.z = o.y.x = o.y.y = o.y.z = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat2x3
		if (!unpack_imat2x3p(obj1, &o)) { // obj1 can't be interpreted as tmat2x3
			PY_TYPEERROR_2O("unsupported operand type(s) for -: ", obj1, obj2);
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x -= d;
		o.x.y -= d;
		o.x.z -= d;
		o.y.x -= d;
		o.y.y -= d;
		o.y.z -= d;
	}
	else { // obj2 can be converted to a tmat2x3
		imat2x3 o2;

		if (!unpack_imat2x3p(obj2, &o2)) { // obj2 can't be interpreted as tmat2x3
			PyObject * out = PyObject_CallMethod(obj2, "__rsub__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tmat2x3' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x -= o2.x.x;
		o.x.y -= o2.x.y;
		o.x.z -= o2.x.z;
		o.y.x -= o2.y.x;
		o.y.y -= o2.y.y;
		o.y.z -= o2.y.z;
	}

	return build_imat2x3(o);
}

static PyObject *
tmat2x3_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat2x3* o2 = unpack_imat2x3(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x3
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat2x3' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat2x3(
			d * o2->x.x,
			d * o2->x.y,
			d * o2->x.z,
			d * o2->y.x,
			d * o2->y.y,
			d * o2->y.z);
		free(o2);
		return out;
	}

	void* o = NULL;
	char glmType = unpack_pyobject(obj1, &o, GLM_HAS_TVEC3 | GLM_HAS_TMAT2x3);

	if (glmType == GLM_TVEC3) { // obj1 is a col_type
		imat2x3* o2 = unpack_imat2x3(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x3
			free(o);
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat2x3' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tvec2(
			((ivec3*)o)->x * o2->x.x + ((ivec3*)o)->y * o2->x.y + ((ivec3*)o)->z * o2->x.z,
			((ivec3*)o)->x * o2->y.x + ((ivec3*)o)->y * o2->y.y + ((ivec3*)o)->z * o2->y.z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType != GLM_TMAT2x3) { // obj1 can't be interpreted as tmat2x3
		free(o);
		PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat2x3*)o)->x.x *= d;
		((imat2x3*)o)->x.y *= d;
		((imat2x3*)o)->x.z *= d;
		((imat2x3*)o)->y.x *= d;
		((imat2x3*)o)->y.y *= d;
		((imat2x3*)o)->y.z *= d;
		PyObject* out = build_imat2x3p(o);
		free(o);
		return out;
	}

	void* o2 = NULL;
	glmType = unpack_pyobject(obj2, &o2, GLM_HAS_TVEC3 | GLM_HAS_TMAT2x2 | GLM_HAS_TMAT3x2 | GLM_HAS_TMAT4x2);

	if (glmType == GLM_TVEC3) { // obj2 is a row_type
		PyObject* out = pack_tvec3(
			((imat2x3*)o)->x.x * ((ivec3*)o2)->x + ((imat2x3*)o)->y.x * ((ivec3*)o2)->y,
			((imat2x3*)o)->x.y * ((ivec3*)o2)->x + ((imat2x3*)o)->y.y * ((ivec3*)o2)->y,
			((imat2x3*)o)->x.z * ((ivec3*)o2)->x + ((imat2x3*)o)->y.z * ((ivec3*)o2)->y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT2x2) { // obj2 is a tmat2x2
		PyObject* out = pack_tmat2x3(
			((imat2x3*)o)->x.x * ((imat2x2*)o2)->x.x + ((imat2x3*)o)->y.x * ((imat2x2*)o2)->x.y,
			((imat2x3*)o)->x.y * ((imat2x2*)o2)->x.x + ((imat2x3*)o)->y.y * ((imat2x2*)o2)->x.y,
			((imat2x3*)o)->x.z * ((imat2x2*)o2)->x.x + ((imat2x3*)o)->y.z * ((imat2x2*)o2)->x.y,
			((imat2x3*)o)->x.x * ((imat2x2*)o2)->y.x + ((imat2x3*)o)->y.x * ((imat2x2*)o2)->y.y,
			((imat2x3*)o)->x.y * ((imat2x2*)o2)->y.x + ((imat2x3*)o)->y.y * ((imat2x2*)o2)->y.y,
			((imat2x3*)o)->x.z * ((imat2x2*)o2)->y.x + ((imat2x3*)o)->y.z * ((imat2x2*)o2)->y.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT3x2) {// obj2 is a tmat3x2
		PyObject* out = pack_tmat3x3(
			((imat2x3*)o)->x.x * ((imat3x2*)o2)->x.x + ((imat2x3*)o)->y.x * ((imat3x2*)o2)->x.y,
			((imat2x3*)o)->x.y * ((imat3x2*)o2)->x.x + ((imat2x3*)o)->y.y * ((imat3x2*)o2)->x.y,
			((imat2x3*)o)->x.z * ((imat3x2*)o2)->x.x + ((imat2x3*)o)->y.z * ((imat3x2*)o2)->x.y,
			((imat2x3*)o)->x.x * ((imat3x2*)o2)->y.x + ((imat2x3*)o)->y.x * ((imat3x2*)o2)->y.y,
			((imat2x3*)o)->x.y * ((imat3x2*)o2)->y.x + ((imat2x3*)o)->y.y * ((imat3x2*)o2)->y.y,
			((imat2x3*)o)->x.z * ((imat3x2*)o2)->y.x + ((imat2x3*)o)->y.z * ((imat3x2*)o2)->y.y,
			((imat2x3*)o)->x.x * ((imat3x2*)o2)->z.x + ((imat2x3*)o)->y.x * ((imat3x2*)o2)->z.y,
			((imat2x3*)o)->x.y * ((imat3x2*)o2)->z.x + ((imat2x3*)o)->y.y * ((imat3x2*)o2)->z.y,
			((imat2x3*)o)->x.z * ((imat3x2*)o2)->z.x + ((imat2x3*)o)->y.z * ((imat3x2*)o2)->z.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT4x2) { // obj2 is a tmat4x2
		PyObject* out = pack_tmat4x3(
			((imat2x3*)o)->x.x * ((imat4x2*)o2)->x.x + ((imat2x3*)o)->y.x * ((imat4x2*)o2)->x.y,
			((imat2x3*)o)->x.y * ((imat4x2*)o2)->x.x + ((imat2x3*)o)->y.y * ((imat4x2*)o2)->x.y,
			((imat2x3*)o)->x.z * ((imat4x2*)o2)->x.x + ((imat2x3*)o)->y.z * ((imat4x2*)o2)->x.y,
			((imat2x3*)o)->x.x * ((imat4x2*)o2)->y.x + ((imat2x3*)o)->y.x * ((imat4x2*)o2)->y.y,
			((imat2x3*)o)->x.y * ((imat4x2*)o2)->y.x + ((imat2x3*)o)->y.y * ((imat4x2*)o2)->y.y,
			((imat2x3*)o)->x.z * ((imat4x2*)o2)->y.x + ((imat2x3*)o)->y.z * ((imat4x2*)o2)->y.y,
			((imat2x3*)o)->x.x * ((imat4x2*)o2)->z.x + ((imat2x3*)o)->y.x * ((imat4x2*)o2)->z.y,
			((imat2x3*)o)->x.y * ((imat4x2*)o2)->z.x + ((imat2x3*)o)->y.y * ((imat4x2*)o2)->z.y,
			((imat2x3*)o)->x.z * ((imat4x2*)o2)->z.x + ((imat2x3*)o)->y.z * ((imat4x2*)o2)->z.y,
			((imat2x3*)o)->x.x * ((imat4x2*)o2)->w.x + ((imat2x3*)o)->y.x * ((imat4x2*)o2)->w.y,
			((imat2x3*)o)->x.y * ((imat4x2*)o2)->w.x + ((imat2x3*)o)->y.y * ((imat4x2*)o2)->w.y,
			((imat2x3*)o)->x.z * ((imat4x2*)o2)->w.x + ((imat2x3*)o)->y.z * ((imat4x2*)o2)->w.y);
		free(o);
		free(o2);
		return out;
	}
	free(o);
	free(o2);
	PyObject * out = PyObject_CallMethod(obj2, "__rmul__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat2x3' and ", obj2);
		return NULL;
	}
	return out;
}

static PyObject *
tmat2x3_div(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat2x3* o2 = unpack_imat2x3(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x3
			PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat2x3' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat2x3(
			d / o2->x.x,
			d / o2->x.y,
			d / o2->x.z,
			d / o2->y.x,
			d / o2->y.y,
			d / o2->y.z);
		free(o2);
		return out;
	}

	imat2x3* o = unpack_imat2x3(obj1);

	if (o == NULL) { // obj1 can't be interpreted as tmat2x3
		PY_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat2x3*)o)->x.x /= d;
		((imat2x3*)o)->x.y /= d;
		((imat2x3*)o)->x.z /= d;
		((imat2x3*)o)->y.x /= d;
		((imat2x3*)o)->y.y /= d;
		((imat2x3*)o)->y.z /= d;
		PyObject* out = build_imat2x3p(o);
		free(o);
		return out;
	}
	free(o);
	PyObject * out = PyObject_CallMethod(obj2, "__rtruediv__", "O", obj1);
	if (out == NULL) out = PyObject_CallMethod(obj2, "__rdiv__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat2x3' and ", obj2);
		return NULL;
	}
	return out;
}

// inplace
// binaryfunc
static PyObject *
tmat2x3_iadd(tmat2x3 *self, PyObject *obj)
{
	tmat2x3 * temp = (tmat2x3*)tmat2x3_add((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x3_isub(tmat2x3 *self, PyObject *obj)
{
	tmat2x3 * temp = (tmat2x3*)tmat2x3_sub((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x3_imul(tmat2x3 *self, PyObject *obj)
{
	tmat2x3 * temp = (tmat2x3*)tmat2x3_mul((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	if (!PyObject_TypeCheck(temp, &tmat2x3Type)) {
		PY_TYPEERROR("unsupported operand type for *=: ", obj);
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x3_idiv(tmat2x3 *self, PyObject *obj)
{
	tmat2x3 * temp = (tmat2x3*)tmat2x3_div((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	if (!PyObject_TypeCheck(temp, &tmat2x3Type)) {
		PY_TYPEERROR("unsupported operand type for /=: ", obj);
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x3_str(tmat2x3* self)
{
	char * out = (char*)malloc((102) * sizeof(char));
	snprintf(out, 102, "tmat2x3( ( %12.6g, %12.6g, %12.6g ), ( %12.6g, %12.6g, %12.6g ) )", self->x->x, self->x->y, self->x->z, self->y->x, self->y->y, self->y->z);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
tmat2x3_repr(tmat2x3* self)
{
	char * out = (char*)malloc((102) * sizeof(char));
	snprintf(out, 102, "tmat2x3\n[ %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g ]", self->x->x, self->x->y, self->x->z, self->y->x, self->y->y, self->y->z);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tmat2x3_len(tmat2x3 * self) {
	return (Py_ssize_t)2;
}

static PyObject* tmat2x3_sq_item(tmat2x3 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		Py_INCREF((PyObject*)self->x);
		return (PyObject*)self->x;
	case 1:
		Py_INCREF((PyObject*)self->y);
		return (PyObject*)self->y;
	case -1:
		Py_INCREF((PyObject*)self->y);
		return (PyObject*)self->y;
	case -2:
		Py_INCREF((PyObject*)self->x);
		return (PyObject*)self->x;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int tmat2x3_sq_setitem(tmat2x3 * self, Py_ssize_t index, PyObject * value) {
	ivec3*o = unpack_ivec3(value);
	if (o == NULL) {
		PY_TYPEERROR("expected tvec3, got ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->x->x = o->x;
		self->x->y = o->y;
		self->x->z = o->z;
		free(o);
		return 0;
	case 1:
		self->y->x = o->x;
		self->y->y = o->y;
		self->y->z = o->z;
		free(o);
		return 0;
	case -1:
		self->y->x = o->x;
		self->y->y = o->y;
		self->y->z = o->z;
		free(o);
		return 0;
	case -2:
		self->x->x = o->x;
		self->x->y = o->y;
		self->x->z = o->z;
		free(o);
		return 0;
	default:
		free(o);
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tmat2x3_contains(tmat2x3 * self, PyObject * value) {
	if (IS_NUMERIC(value)) {
		double d = pyvalue_as_double(value);
		return (int)(d == self->x->x || d == self->x->y || d == self->x->z || d == self->y->x || d == self->y->y || d == self->y->z);
	}
	ivec3* o = unpack_ivec3(value);
	if (o == NULL) {
		return 0;
	}

	int out = (int)((self->x->x == o->x && self->x->y == o->y && self->x->z == o->z) || (self->y->x == o->x && self->y->y == o->y && self->y->z == o->z));
	free(o);
	return out;
}

static PyObject * tmat2x3_richcompare(tmat2x3 * self, PyObject * other, int comp_type) {
	tmat2x3 * other_as_tmat2x3;
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tmat2x3Type)) { // incopatible type
			Py_RETURN_FALSE;
		}
		else {
			other_as_tmat2x3 = (tmat2x3*)other;
		}
		return PyBool_FromLong(
			(self->x->x == other_as_tmat2x3->x->x) && (self->x->y == other_as_tmat2x3->x->y) && (self->x->z == other_as_tmat2x3->x->z) &&
			(self->y->x == other_as_tmat2x3->y->x) && (self->y->y == other_as_tmat2x3->y->y) && (self->y->z == other_as_tmat2x3->y->z));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tmat2x3Type)) { // incopatible type
			Py_RETURN_TRUE;
		}
		else {
			other_as_tmat2x3 = (tmat2x3*)other;
		}
		return PyBool_FromLong(
			(self->x->x != other_as_tmat2x3->x->x) || (self->x->y != other_as_tmat2x3->x->y) || (self->x->z != other_as_tmat2x3->x->z) ||
			(self->y->x != other_as_tmat2x3->y->x) || (self->y->y != other_as_tmat2x3->y->y) || (self->y->z != other_as_tmat2x3->y->z));
	}
	else {
		PY_TYPEERROR("unsupported operand type(s) for ==: 'glm::detail::tmat2x3 and ", other);
		return NULL;
	}
}

static int tmat2x3_setattr(PyObject * obj, PyObject * name, PyObject * value) {
	char * name_as_ccp = attr_name_to_cstr(name);

	if ((strlen(name_as_ccp) >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[strlen(name_as_ccp) - 1] == '_' && name_as_ccp[strlen(name_as_ccp) - 2] == '_')) {
		return PyObject_GenericSetAttr(obj, name, value);
	}
	if (strcmp(name_as_ccp, "x") == 0) {
		ivec3* o = unpack_ivec3(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat2x3*)obj)->x->x = o->x;
		((tmat2x3*)obj)->x->y = o->y;
		((tmat2x3*)obj)->x->z = o->z;
		free(o);
		return 0;
	}
	if (strcmp(name_as_ccp, "y") == 0) {
		ivec3* o = unpack_ivec3(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat2x3*)obj)->y->x = o->x;
		((tmat2x3*)obj)->y->y = o->y;
		((tmat2x3*)obj)->y->z = o->z;
		free(o);
		return 0;
	}
	return PyObject_GenericSetAttr(obj, name, value);
}

// iterator

static PyObject *
tmat2x3Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tmat2x3 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tmat2x3Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tmat2x3Iter *rgstate = (tmat2x3Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tmat2x3Iter_dealloc(tmat2x3Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tmat2x3Iter_next(tmat2x3Iter *rgstate)
{
	if (rgstate->seq_index < 2) {
		switch (rgstate->seq_index) {
		case 0:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->x));
			return (PyObject*)(rgstate->sequence->x);
		case 1:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->y));
			return (PyObject*)(rgstate->sequence->y);
		}
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * tmat2x3_geniter(tmat2x3 * self) {
	PyObject * obj = tmat2x3Iter_new(&tmat2x3IterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tmat2x3SeqMethods = {
	(lenfunc)tmat2x3_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tmat2x3_sq_item, // sq_item
	0,
	(ssizeobjargproc)tmat2x3_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tmat2x3_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMemberDef tmat2x3_members[] = {
	{ "x", T_OBJECT, offsetof(tmat2x3, x), 0,
	"vec x" },
{ "y", T_OBJECT, offsetof(tmat2x3, y), 0,
"vec y" },
{ "col_type", T_OBJECT, offsetof(tmat2x3, col_type), 0,
"column type" },
{ "row_type", T_OBJECT, offsetof(tmat2x3, row_type), 0,
"row type" },
{ NULL }  /* Sentinel */
};

#if PY3K
static PyNumberMethods tmat2x3NumMethods = {
	(binaryfunc)tmat2x3_add,
	(binaryfunc)tmat2x3_sub,
	(binaryfunc)tmat2x3_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)tmat2x3_neg, //nb_negative
	(unaryfunc)tmat2x3_pos, //nb_positive
	(unaryfunc)tmat2x3_abs, //nb_absolute
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

	(binaryfunc)tmat2x3_iadd, //nb_inplace_add
	(binaryfunc)tmat2x3_isub, //nb_inplace_subtract
	(binaryfunc)tmat2x3_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)tmat2x3_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)tmat2x3_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tmat2x3NumMethods = {
	(binaryfunc)tmat2x3_add, //nb_add;
	(binaryfunc)tmat2x3_sub, //nb_subtract;
	(binaryfunc)tmat2x3_mul, //nb_multiply;
	(binaryfunc)tmat2x3_div, //nb_divide;
	0, //nb_remainder;
	0, //nb_divmod;
	0, //nb_power;
	(unaryfunc)tmat2x3_neg, //nb_negative;
	(unaryfunc)tmat2x3_pos, //nb_positive;
	(unaryfunc)tmat2x3_abs, //nb_absolute;
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
	   (binaryfunc)tmat2x3_iadd, //nb_inplace_add;
	   (binaryfunc)tmat2x3_isub, //nb_inplace_subtract;
	   (binaryfunc)tmat2x3_imul, //nb_inplace_multiply;
	   (binaryfunc)tmat2x3_idiv, //nb_inplace_divide;
	   0, //nb_inplace_remainder;
	   0, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  0, //nb_floor_divide;
		  (binaryfunc)tmat2x3_div, //nb_true_divide;
		  0, //nb_inplace_floor_divide;
		  (binaryfunc)tmat2x3_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tmat2x3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tmat2x3",             /* tp_name */
	sizeof(tmat2x3),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat2x3_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tmat2x3_repr,                         /* tp_repr */
	&tmat2x3NumMethods,             /* tp_as_number */
	&tmat2x3SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tmat2x3_str,                         /* tp_str */
	0,//(getattrofunc)tmat2x3_getattr,                         /* tp_getattro */
	(setattrofunc)tmat2x3_setattr,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE |
	Py_TPFLAGS_CHECKTYPES,   /* tp_flags */
	"tmat2x3( <tmat2x3 compatible type(s)> )\n2 columns of 3 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tmat2x3_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tmat2x3_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tmat2x3_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tmat2x3_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tmat2x3_new,                 /* tp_new */
};

static PyTypeObject tmat2x3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tmat2x3Iter",             /* tp_name */
	sizeof(tmat2x3Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat2x3Iter_dealloc, /* tp_dealloc */
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
	"tmat2x3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tmat2x3Iter_next,                         /* tp_iternext */
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
	(newfunc)tmat2x3Iter_new,                 /* tp_new */
};
