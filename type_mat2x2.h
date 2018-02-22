static void
tmat2x2_dealloc(tmat2x2* self)
{
	Py_DECREF(self->x);
	Py_DECREF(self->y);
	/*//Py_DECREF(self->col_type);
	//Py_DECREF(self->row_type);*/
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tmat2x2_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tmat2x2 *self;

	self = (tmat2x2 *)type->tp_alloc(type, 0);

	PyObject *v1 = pack_tvec2(0, 0);
	PyObject *v2 = pack_tvec2(0, 0);

	if (self != NULL) {
		self->x = (tvec2*)v1;
		self->y = (tvec2*)v2;
		self->col_type = (PyObject*)&tvec2Type;
		self->row_type = (PyObject*)&tvec2Type;
	}

	return (PyObject *)self;
}

static int
tmat2x2_init(tmat2x2 *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x0", "x1", "y0", "y1", NULL };
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOOO", kwlist,
		&arg1, &arg2, &arg3, &arg4)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x2()");
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
			self->y->x = ((imat2x2*)o)->y.x;
			self->y->y = ((imat2x2*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT2x3:
			self->x->x = ((imat2x3*)o)->x.x;
			self->x->y = ((imat2x3*)o)->x.y;
			self->y->x = ((imat2x3*)o)->y.x;
			self->y->y = ((imat2x3*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT2x4:
			self->x->x =  ((imat2x4*)o)->x.x;
			self->x->y =  ((imat2x4*)o)->x.y;
			self->y->x =  ((imat2x4*)o)->y.x;
			self->y->y =  ((imat2x4*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT3x2:
			self->x->x =  ((imat3x2*)o)->x.x;
			self->x->y =  ((imat3x2*)o)->x.y;
			self->y->x =  ((imat3x2*)o)->y.x;
			self->y->y =  ((imat3x2*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT3x3:
			self->x->x =  ((imat3x3*)o)->x.x;
			self->x->y =  ((imat2x3*)o)->x.y;
			self->y->x =  ((imat3x3*)o)->y.x;
			self->y->y =  ((imat3x3*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT3x4:
			self->x->x =  ((imat3x4*)o)->x.x;
			self->x->y =  ((imat3x4*)o)->x.y;
			self->y->x =  ((imat3x4*)o)->y.x;
			self->y->y =  ((imat3x4*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT4x2:
			self->x->x =  ((imat4x2*)o)->x.x;
			self->x->y =  ((imat4x2*)o)->x.y;
			self->y->x =  ((imat4x2*)o)->y.x;
			self->y->y =  ((imat4x2*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT4x3:
			self->x->x =  ((imat4x3*)o)->x.x;
			self->x->y =  ((imat4x3*)o)->x.y;
			self->y->x =  ((imat4x3*)o)->y.x;
			self->y->y =  ((imat4x3*)o)->y.y;
			free(o);
			return 0;
		case GLM_TMAT4x4:
			self->x->x =  ((imat4x4*)o)->x.x;
			self->x->y =  ((imat4x4*)o)->x.y;
			self->y->x =  ((imat4x4*)o)->y.x;
			self->y->y =  ((imat4x4*)o)->y.y;
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x2()");
			return -1;
		}
	}

	if (arg3 == NULL) {
		ivec2* o = unpack_ivec2(arg1);
		if (o == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x2()");
			return -1;
		}
		ivec2* o2 = unpack_ivec2(arg2);
		if (o2 == NULL) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x2()");
			return -1;
		}
		self->x->x = o->x;
		self->x->y = o->y;
		self->y->x = o2->x;
		self->y->y = o2->y;
		free(o);
		free(o2);
		return 0;
	}

	if (arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x2()");
		return -1;
	}

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
		self->x->x = pyvalue_as_double(arg1);
		self->x->y = pyvalue_as_double(arg2);
		self->y->x = pyvalue_as_double(arg3);
		self->y->y = pyvalue_as_double(arg4);
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat2x2()");
	return -1;
}

// unaryfunc
static PyObject *
tmat2x2_neg(tmat2x2 *obj)
{
	PyObject* argList = Py_BuildValue("OO", PyObject_CallMethod((PyObject*)obj->x, "__neg__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__neg__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat2x2_pos(tmat2x2 *obj)
{
	PyObject* argList = Py_BuildValue("OO", obj->x, obj->y);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat2x2_abs(tmat2x2 *obj)
{
	PyObject* argList = Py_BuildValue("OO", PyObject_CallMethod((PyObject*)obj->x, "__abs__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__abs__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat2x2Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

// binaryfunc
static PyObject *
tmat2x2_add(PyObject *obj1, PyObject *obj2)
{
	imat2x2 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.y.x = o.y.y = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat2x2
		if (!unpack_imat2x2p(obj1, &o)) { // obj1 can't be interpreted as tmat2x2
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::tmat2x2'");
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x += d;
		o.x.y += d;
		o.y.x += d;
		o.y.y += d;
	}
	else { // obj2 can be converted to a tmat2x2
		imat2x2 o2;

		if (!unpack_imat2x2p(obj2, &o2)) { // obj2 can't be interpreted as tmat2x2
			PyObject * out = PyObject_CallMethod(obj2, "__radd__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tmat2x2' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x += o2.x.x;
		o.x.y += o2.x.y;
		o.y.x += o2.y.x;
		o.y.y += o2.y.y;
	}
	return build_imat2x2(o);
}

static PyObject *
tmat2x2_sub(PyObject *obj1, PyObject *obj2)
{
	imat2x2 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.y.x = o.y.y = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat2x2
		if (!unpack_imat2x2p(obj1, &o)) { // obj1 can't be interpreted as tmat2x2
			PY_TYPEERROR_2O("unsupported operand type(s) for -: ", obj1, obj2);
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x -= d;
		o.x.y -= d;
		o.y.x -= d;
		o.y.y -= d;
	}
	else { // obj2 can be converted to a tmat2x2
		imat2x2 o2;

		if (!unpack_imat2x2p(obj2, &o2)) { // obj2 can't be interpreted as tmat2x2
			PyObject * out = PyObject_CallMethod(obj2, "__rsub__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tmat2x2' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x -= o2.x.x;
		o.x.y -= o2.x.y;
		o.y.x -= o2.y.x;
		o.y.y -= o2.y.y;
	}

	return build_imat2x2(o);
}

static PyObject *
tmat2x2_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat2x2* o2 = unpack_imat2x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x2
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat2x2' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat2x2(
			d * o2->x.x,
			d * o2->x.y,
			d * o2->y.x,
			d * o2->y.y);
		free(o2);
		return out;
	}

	void* o = NULL;
	char glmType = unpack_pyobject(obj1, &o, GLM_HAS_TVEC2 | GLM_HAS_TMAT2x2);

	if (glmType == GLM_TVEC2) { // obj1 is a col_type
		imat2x2* o2 = unpack_imat2x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x2
			free(o);
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat2x2' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tvec2(
			((ivec2*)o)->x * o2->x.x + ((ivec2*)o)->y * o2->x.y,
			((ivec2*)o)->x * o2->y.x + ((ivec2*)o)->y * o2->y.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType != GLM_TMAT2x2) { // obj1 can't be interpreted as tmat2x2
		free(o);
		PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat2x2*)o)->x.x *= d;
		((imat2x2*)o)->x.y *= d;
		((imat2x2*)o)->y.x *= d;
		((imat2x2*)o)->y.y *= d;
		PyObject* out = build_imat2x2p(o);
		free(o);
		return out;
	}
	
	void* o2 = NULL;
	glmType = unpack_pyobject(obj2, &o2, GLM_HAS_TVEC2 | GLM_HAS_TMAT2x2 | GLM_HAS_TMAT3x2 | GLM_HAS_TMAT4x2);

	if (glmType == GLM_TVEC2) { // obj2 is a row_type
		PyObject* out = pack_tvec2(
			((imat2x2*)o)->x.x * ((ivec2*)o2)->x + ((imat2x2*)o)->y.x * ((ivec2*)o2)->y,
			((imat2x2*)o)->x.y * ((ivec2*)o2)->x + ((imat2x2*)o)->y.y * ((ivec2*)o2)->y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT2x2) { // obj2 is a tmat2x2
		PyObject* out = pack_tmat2x2(
			((imat2x2*)o)->x.x * ((imat2x2*)o2)->x.x + ((imat2x2*)o)->y.x * ((imat2x2*)o2)->x.y,
			((imat2x2*)o)->x.y * ((imat2x2*)o2)->x.x + ((imat2x2*)o)->y.y * ((imat2x2*)o2)->x.y,
			((imat2x2*)o)->x.x * ((imat2x2*)o2)->y.x + ((imat2x2*)o)->y.x * ((imat2x2*)o2)->y.y,
			((imat2x2*)o)->x.y * ((imat2x2*)o2)->y.x + ((imat2x2*)o)->y.y * ((imat2x2*)o2)->y.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT3x2) {// obj2 is a tmat3x2
		PyObject* out = pack_tmat3x2(
			((imat2x2*)o)->x.x * ((imat3x2*)o2)->x.x + ((imat2x2*)o)->y.x * ((imat3x2*)o2)->x.y,
			((imat2x2*)o)->x.y * ((imat3x2*)o2)->x.x + ((imat2x2*)o)->y.y * ((imat3x2*)o2)->x.y,
			((imat2x2*)o)->x.x * ((imat3x2*)o2)->y.x + ((imat2x2*)o)->y.x * ((imat3x2*)o2)->y.y,
			((imat2x2*)o)->x.y * ((imat3x2*)o2)->y.x + ((imat2x2*)o)->y.y * ((imat3x2*)o2)->y.y,
			((imat2x2*)o)->x.x * ((imat3x2*)o2)->z.x + ((imat2x2*)o)->y.x * ((imat3x2*)o2)->z.y,
			((imat2x2*)o)->x.y * ((imat3x2*)o2)->z.x + ((imat2x2*)o)->y.y * ((imat3x2*)o2)->z.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT4x2) { // obj2 is a tmat4x2
		PyObject* out = pack_tmat4x2(
			((imat2x2*)o)->x.x * ((imat4x2*)o2)->x.x + ((imat2x2*)o)->y.x * ((imat4x2*)o2)->x.y,
			((imat2x2*)o)->x.y * ((imat4x2*)o2)->x.x + ((imat2x2*)o)->y.y * ((imat4x2*)o2)->x.y,
			((imat2x2*)o)->x.x * ((imat4x2*)o2)->y.x + ((imat2x2*)o)->y.x * ((imat4x2*)o2)->y.y,
			((imat2x2*)o)->x.y * ((imat4x2*)o2)->y.x + ((imat2x2*)o)->y.y * ((imat4x2*)o2)->y.y,
			((imat2x2*)o)->x.x * ((imat4x2*)o2)->z.x + ((imat2x2*)o)->y.x * ((imat4x2*)o2)->z.y,
			((imat2x2*)o)->x.y * ((imat4x2*)o2)->z.x + ((imat2x2*)o)->y.y * ((imat4x2*)o2)->z.y,
			((imat2x2*)o)->x.x * ((imat4x2*)o2)->w.x + ((imat2x2*)o)->y.x * ((imat4x2*)o2)->w.y,
			((imat2x2*)o)->x.y * ((imat4x2*)o2)->w.x + ((imat2x2*)o)->y.y * ((imat4x2*)o2)->w.y);
		free(o);
		free(o2);
		return out;
	}

	PyObject * out = PyObject_CallMethod(obj2, "__rmul__", "O", obj1);
	if (out == NULL) {
		free(o);
		free(o2);
		PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat2x2' and ", obj2);
		return NULL;
	}
	return out;
}

static PyObject *
tmat2x2_div(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat2x2* o2 = unpack_imat2x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x2
			PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat2x2' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat2x2(
			d / o2->x.x,
			d / o2->x.y,
			d / o2->y.x,
			d / o2->y.y);
		free(o2);
		return out;
	}

	void* o = NULL;
	char glmType = unpack_pyobject(obj1, &o, GLM_HAS_TVEC2 | GLM_HAS_TMAT2x2);

	if (glmType == GLM_TVEC2) { // obj1 is a col_type
		imat2x2* o2 = unpack_imat2x2(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat2x2
			PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat2x2' and ", obj2);
			return NULL;
		}

		*o2 = INVERSE2(*o2);

		PyObject* out = pack_tvec2(
			((ivec2*)o)->x * o2->x.x + ((ivec2*)o)->y * o2->x.y,
			((ivec2*)o)->x * o2->y.x + ((ivec2*)o)->y * o2->y.y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType != GLM_TMAT2x2) { // obj1 can't be interpreted as tmat2x2
		PY_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat2x2*)o)->x.x /= d;
		((imat2x2*)o)->x.y /= d;
		((imat2x2*)o)->y.x /= d;
		((imat2x2*)o)->y.y /= d;
		PyObject* out = build_imat2x2p(o);
		free(o);
		return out;
	}

	void* o2 = NULL;
	glmType = unpack_pyobject(obj2, &o2, GLM_HAS_TVEC2 | GLM_HAS_TMAT2x2);

	if (glmType == GLM_TVEC2) { // obj2 is a row_type
		*((imat2x2*)o) = INVERSE2(*((imat2x2*)o));
		PyObject* out = pack_tvec2(
			((imat2x2*)o)->x.x * ((ivec2*)o2)->x + ((imat2x2*)o)->y.x * ((ivec2*)o2)->y,
			((imat2x2*)o)->x.y * ((ivec2*)o2)->x + ((imat2x2*)o)->y.y * ((ivec2*)o2)->y);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT2x2) { // obj2 is a tmat2x2
		*((imat2x2*)o2) = INVERSE2(*((imat2x2*)o2));
		PyObject* out = pack_tmat2x2(
			((imat2x2*)o)->x.x * ((imat2x2*)o2)->x.x + ((imat2x2*)o)->y.x * ((imat2x2*)o2)->x.y,
			((imat2x2*)o)->x.y * ((imat2x2*)o2)->x.x + ((imat2x2*)o)->y.y * ((imat2x2*)o2)->x.y,
			((imat2x2*)o)->x.x * ((imat2x2*)o2)->y.x + ((imat2x2*)o)->y.x * ((imat2x2*)o2)->y.y,
			((imat2x2*)o)->x.y * ((imat2x2*)o2)->y.x + ((imat2x2*)o)->y.y * ((imat2x2*)o2)->y.y);
		free(o);
		free(o2);
		return out;
	}

	PyObject * out = PyObject_CallMethod(obj2, "__rtruediv__", "O", obj1);
	if (out == NULL) out = PyObject_CallMethod(obj2, "__rdiv__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat2x2' and ", obj2);
		return NULL;
	}
	return out;
}

// inplace
// binaryfunc
static PyObject *
tmat2x2_iadd(tmat2x2 *self, PyObject *obj)
{
	tmat2x2 * temp = (tmat2x2*)tmat2x2_add((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x2_isub(tmat2x2 *self, PyObject *obj)
{
	tmat2x2 * temp = (tmat2x2*)tmat2x2_sub((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x2_imul(tmat2x2 *self, PyObject *obj)
{
	tmat2x2 * temp = (tmat2x2*)tmat2x2_mul((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x2_idiv(tmat2x2 *self, PyObject *obj)
{
	tmat2x2 * temp = (tmat2x2*)tmat2x2_div((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat2x2_str(tmat2x2* self)
{
	char * out = (char*)malloc((72) * sizeof(char));
	snprintf(out, 72, "tmat2x2( ( %12.6g, %12.6g ), ( %12.6g, %12.6g ) )", self->x->x, self->x->y, self->y->x, self->y->y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
tmat2x2_repr(tmat2x2* self)
{
	char * out = (char*)malloc((72) * sizeof(char));
	snprintf(out, 72, "tmat2x2\n[ %12.6g | %12.6g ]\n[ %12.6g | %12.6g ]", self->x->x, self->x->y, self->y->x, self->y->y);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tmat2x2_len(tmat2x2 * self) {
	return (Py_ssize_t)2;
}

static PyObject* tmat2x2_sq_item(tmat2x2 * self, Py_ssize_t index) {
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

static int tmat2x2_sq_setitem(tmat2x2 * self, Py_ssize_t index, PyObject * value) {
	ivec2*o = unpack_ivec2(value);
	if (o == NULL) {
		PY_TYPEERROR("expected tvec2, got ", value);
		return -1;
	}
	switch (index) {
	case 0:
		((tmat2x2*)value)->x->x = o->x;
		((tmat2x2*)value)->x->y = o->y;
		free(o);
		return 0;
	case 1:
		((tmat2x2*)value)->y->x = o->x;
		((tmat2x2*)value)->y->y = o->y;
		free(o);
		return 0;
	case -1:
		((tmat2x2*)value)->y->x = o->x;
		((tmat2x2*)value)->y->y = o->y;
		free(o);
		return 0;
	case -2:
		((tmat2x2*)value)->x->x = o->x;
		((tmat2x2*)value)->x->y = o->y;
		free(o);
		return 0;
	default:
		free(o);
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tmat2x2_contains(tmat2x2 * self, PyObject * value) {
	if (IS_NUMERIC(value)) {
		double d = pyvalue_as_double(value);
		return (int)(d == self->x->x || d == self->x->y || d == self->y->x || d == self->y->y);
	}
	ivec2* o = unpack_ivec2(value);
	if (o == NULL) {
		return 0;
	}

	int out = (int)((self->x->x == o->x && self->x->y == o->y) || (self->y->x == o->x && self->y->y == o->y));
	free(o);
	return out;
}

static PyObject * tmat2x2_richcompare(tmat2x2 * self, PyObject * other, int comp_type) {
	tmat2x2 * other_as_tmat2x2;
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tmat2x2Type)) { // incopatible type
			Py_RETURN_FALSE;
		}
		else {
			other_as_tmat2x2 = (tmat2x2*)other;
		}
		return PyBool_FromLong(
			(self->x->x == other_as_tmat2x2->x->x) && (self->x->y == other_as_tmat2x2->x->y) && 
			(self->y->x == other_as_tmat2x2->y->x) && (self->y->y == other_as_tmat2x2->y->y));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tmat2x2Type)) { // incopatible type
			Py_RETURN_TRUE;
		}
		else {
			other_as_tmat2x2 = (tmat2x2*)other;
		}
		return PyBool_FromLong(
			(self->x->x != other_as_tmat2x2->x->x) || (self->x->y != other_as_tmat2x2->x->y) ||
			(self->y->x != other_as_tmat2x2->y->x) || (self->y->y != other_as_tmat2x2->y->y));
	}
	else {
		PY_TYPEERROR("unsupported operand type(s) for ==: 'glm::detail::tmat2x2 and ", other);
		return NULL;
	}
}

static int tmat2x2_setattr(PyObject * obj, PyObject * name, PyObject * value) {
	char * name_as_ccp = attr_name_to_cstr(name);

	if ((strlen(name_as_ccp) >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[strlen(name_as_ccp) - 1] == '_' && name_as_ccp[strlen(name_as_ccp) - 2] == '_')) {
		return PyObject_GenericSetAttr(obj, name, value);
	}
	if (strcmp(name_as_ccp, "x") == 0) {
		ivec2* o = unpack_ivec2(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat2x2*)obj)->x->x = o->x;
		((tmat2x2*)obj)->x->y = o->y;
		free(o);
		return 0;
	}
	if (strcmp(name_as_ccp, "y") == 0) {
		ivec2* o = unpack_ivec2(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat2x2*)obj)->y->x = o->x;
		((tmat2x2*)obj)->y->y = o->y;
		free(o);
		return 0;
	}
	return PyObject_GenericSetAttr(obj, name, value);
}

// iterator

static PyObject *
tmat2x2Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tmat2x2 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tmat2x2Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tmat2x2Iter *rgstate = (tmat2x2Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tmat2x2Iter_dealloc(tmat2x2Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tmat2x2Iter_next(tmat2x2Iter *rgstate)
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

static PyObject * tmat2x2_geniter(tmat2x2 * self) {
	PyObject * obj = tmat2x2Iter_new(&tmat2x2IterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tmat2x2SeqMethods = {
	(lenfunc)tmat2x2_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tmat2x2_sq_item, // sq_item
	0,
	(ssizeobjargproc)tmat2x2_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tmat2x2_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMemberDef tmat2x2_members[] = {
	{ "x", T_OBJECT, offsetof(tmat2x2, x), 0,
	"vec x" },
{ "y", T_OBJECT, offsetof(tmat2x2, y), 0,
"vec y" },
{ "col_type", T_OBJECT, offsetof(tmat2x2, col_type), 0,
"column type" },
{ "row_type", T_OBJECT, offsetof(tmat2x2, row_type), 0,
"row type" },
{ NULL }  /* Sentinel */
};

#if PY3K
static PyNumberMethods tmat2x2NumMethods = {
	(binaryfunc)tmat2x2_add,
	(binaryfunc)tmat2x2_sub,
	(binaryfunc)tmat2x2_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)tmat2x2_neg, //nb_negative
	(unaryfunc)tmat2x2_pos, //nb_positive
	(unaryfunc)tmat2x2_abs, //nb_absolute
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

	(binaryfunc)tmat2x2_iadd, //nb_inplace_add
	(binaryfunc)tmat2x2_isub, //nb_inplace_subtract
	(binaryfunc)tmat2x2_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)tmat2x2_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)tmat2x2_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tmat2x2NumMethods = {
	(binaryfunc)tmat2x2_add, //nb_add;
	(binaryfunc)tmat2x2_sub, //nb_subtract;
	(binaryfunc)tmat2x2_mul, //nb_multiply;
	(binaryfunc)tmat2x2_div, //nb_divide;
	0, //nb_remainder;
	0, //nb_divmod;
	0, //nb_power;
	(unaryfunc)tmat2x2_neg, //nb_negative;
	(unaryfunc)tmat2x2_pos, //nb_positive;
	(unaryfunc)tmat2x2_abs, //nb_absolute;
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
	   (binaryfunc)tmat2x2_iadd, //nb_inplace_add;
	   (binaryfunc)tmat2x2_isub, //nb_inplace_subtract;
	   (binaryfunc)tmat2x2_imul, //nb_inplace_multiply;
	   (binaryfunc)tmat2x2_idiv, //nb_inplace_divide;
	   0, //nb_inplace_remainder;
	   0, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  0, //nb_floor_divide;
		  (binaryfunc)tmat2x2_div, //nb_true_divide;
		  0, //nb_inplace_floor_divide;
		  (binaryfunc)tmat2x2_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tmat2x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tmat2x2",             /* tp_name */
	sizeof(tmat2x2),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat2x2_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tmat2x2_repr,                         /* tp_repr */
	&tmat2x2NumMethods,             /* tp_as_number */
	&tmat2x2SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tmat2x2_str,                         /* tp_str */
	0,//(getattrofunc)tmat2x2_getattr,                         /* tp_getattro */
	(setattrofunc)tmat2x2_setattr,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"tmat2x2( <tmat2x2 compatible type(s)> )\n2 columns of 2 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tmat2x2_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tmat2x2_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tmat2x2_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tmat2x2_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tmat2x2_new,                 /* tp_new */
};

static PyTypeObject tmat2x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tmat2x2Iter",             /* tp_name */
	sizeof(tmat2x2Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat2x2Iter_dealloc, /* tp_dealloc */
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
	"tmat2x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tmat2x2Iter_next,                         /* tp_iternext */
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
	(newfunc)tmat2x2Iter_new,                 /* tp_new */
};
