static void
tquat_dealloc(tquat* self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tquat_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tquat *self;

	self = (tquat *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->x = 0;
		self->y = 0;
		self->z = 0;
		self->w = 0;
	}

	return (PyObject *)self;
}



static int
tquat_init(tquat *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x", "y", "z", "w", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;
	PyObject * arg4 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOOO", kwlist,
		&arg1, &arg2, &arg3, &arg4)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			void* o = NULL;
			char vecType = unpack_pyobject(arg1, &o, GLM_HAS_TQUAT | GLM_HAS_TVEC3 | GLM_HAS_TMAT3x3 | GLM_HAS_TMAT4x4);

			if (vecType == GLM_TQUAT) {
				self->x = ((iquat*)o)->x;
				self->y = ((iquat*)o)->y;
				self->z = ((iquat*)o)->z;
				self->w = ((iquat*)o)->w;
				free(o);
				return 0;
			}
			if (vecType == GLM_TVEC3) {
				ivec3 c = to_ivec3(
					cos(((ivec3*)o)->x * (0.5)),
					cos(((ivec3*)o)->y * (0.5)),
					cos(((ivec3*)o)->z * (0.5)));
				ivec3 s = to_ivec3(
					sin(((ivec3*)o)->x * (0.5)),
					sin(((ivec3*)o)->y * (0.5)),
					sin(((ivec3*)o)->z * (0.5)));

				self->w = c.x * c.y * c.z + s.x * s.y * s.z;
				self->x = s.x * c.y * c.z - c.x * s.y * s.z;
				self->y = c.x * s.y * c.z + s.x * c.y * s.z;
				self->z = c.x * c.y * s.z - s.x * s.y * c.z;
				free(o);
				return 0;
			}
			if (vecType == GLM_TMAT3x3) {
				iquat out = (iquat_cast3(*((imat3x3*)o)));
				self->x = out.x;
				self->y = out.y;
				self->z = out.z;
				self->w = out.w;
				free(o);
				return 0;
			}
			if (vecType == GLM_TMAT4x4) {
				iquat out = (iquat_cast4(*((imat4x4*)o)));
				self->x = out.x;
				self->y = out.y;
				self->z = out.z;
				self->w = out.w;
				free(o);
				return 0;
			}

			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (arg3 == NULL) {
			if (IS_NUMERIC(arg1)) {
				ivec3 o;
				if (!unpack_ivec3p(arg2, &o)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
					return -1;
				}
				self->x = o.x;
				self->y = o.y;
				self->z = o.z;
				self->w = pyvalue_as_double(arg1);
				return 0;
			}
			ivec3 o;
			if (!unpack_ivec3p(arg1, &o)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}
			ivec3 o2;
			if (!unpack_ivec3p(arg2, &o2)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
				return -1;
			}

			double norm_u_norm_v = sqrt(idot3(o, o) * idot3(o2, o2));
			double real_part = norm_u_norm_v + idot3(o, o2);
			ivec3 t;
			if (real_part < (1.e-6) * norm_u_norm_v) {
				real_part = 0.0;
				t.x = (fabs(o.x) > fabs(o.z)) ? -o.y : 0.0;
				t.y = (fabs(o.y) > fabs(o.z)) ? o.x : -o.z;
				t.z = (fabs(o.z) > fabs(o.z)) ? 0.0 : o.y;
			}
			else {
				t = to_ivec3(
					o.y * o2.z - o2.y * o.z,
					o.z * o2.x - o2.z * o.x,
					o.x * o2.y - o2.x * o.y);
			}
			
			iquat out = inormalizeq(to_iquatv(real_part, t.x, t.y, t.z));
			self->x = out.x;
			self->y = out.y;
			self->z = out.z;
			self->w = out.w;

			return 0;
		}
		if (arg4 == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
			return -1;
		}
		if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4)) {
			self->x = pyvalue_as_double(arg2);
			self->y = pyvalue_as_double(arg3);
			self->z = pyvalue_as_double(arg4);
			self->w = pyvalue_as_double(arg1);
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for quat()");
	return -1;
}

// unaryfunc
static PyObject *
tquat_neg(tquat *obj)
{
	PyObject* argList = Py_BuildValue("dddd", -obj->w, -obj->x, -obj->y, -obj->z);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tquatType, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tquat_pos(tquat *obj)
{
	PyObject* argList = Py_BuildValue("dddd", obj->w, obj->x, obj->y, obj->z);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tquatType, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tquat_abs(tquat *obj)
{
	PyObject* argList = Py_BuildValue("dddd", fabs(obj->w), fabs(obj->x), fabs(obj->y), fabs(obj->z));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tquatType, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

// binaryfunc
static PyObject *
tquat_add(PyObject *obj1, PyObject *obj2)
{
	iquat o;
	if (!unpack_iquatp(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tquat' and ", obj1);
		return NULL;
	}

	iquat o2;
	if (!unpack_iquatp(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		PyObject * out = PyObject_CallMethod(obj2, "__radd__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tquat' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tquat
	return pack_tquat(
		o.w + o2.w,
		o.x + o2.x,
		o.y + o2.y,
		o.z + o2.z
	);
}

static PyObject *
tquat_sub(PyObject *obj1, PyObject *obj2)
{
	iquat o;
	if (!unpack_iquatp(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tquat' and ", obj1);
		return NULL;
	}

	iquat o2;
	if (!unpack_iquatp(obj2, &o2)) { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		PyObject * out = PyObject_CallMethod(obj2, "__rsub__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tquat' and ", obj2);
			return NULL;
		}
		return out;
	}

	// obj1 and obj2 can be interpreted as a tquat
	return pack_tquat(
		o.w - o2.w,
		o.x - o2.x,
		o.y - o2.y,
		o.z - o2.z
	);
}

static PyObject *
tquat_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) {
		iquat o;
		if (!unpack_iquatp(obj1, &o)) {
			PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
			return NULL;
		}
		return build_iquat(mulqd(o, pyvalue_as_double(obj1)));
	}
	void* o = NULL;
	char vecType = unpack_pyobject(obj1, &o, GLM_HAS_TQUAT | GLM_HAS_TVEC3 | GLM_HAS_TVEC4);

	if (vecType == GLM_TVEC3) {
		iquat o2;
		if (!unpack_iquatp(obj2, &o2)) {
			PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
			return NULL;
		}
		return build_ivec3(mulv3q((*((ivec3*)o)), o2));
	}

	if (vecType == GLM_TVEC4) { 
		iquat o2;
		if (!unpack_iquatp(obj2, &o2)) {
			PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
			return NULL;
		}
		return build_ivec4(mulv4q((*(ivec4*)o), o2));
	}

	if (vecType == GLM_NONE) {
		PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) {
		PyObject* out = build_iquat(mulqd((*(iquat*)o), pyvalue_as_double(obj2)));
		free(o);
		return out;
	}

	void* o2 = NULL;
	char vecType2 = unpack_pyobject(obj2, &o2, GLM_HAS_TQUAT | GLM_HAS_TVEC3 | GLM_HAS_TVEC4);
	if (vecType2 == GLM_TQUAT) {
		PyObject* out = build_iquat(mulqq((*(iquat*)o), (*(iquat*)o2)));
		free(o);
		free(o2);
		return out;
	}
	if (vecType2 == GLM_TVEC3) {
		PyObject* out = build_ivec3(mulqv3((*(iquat*)o), (*(ivec3*)o2)));
		free(o);
		free(o2);
		return out;
	}
	if (vecType2 == GLM_TVEC4) {
		PyObject* out = build_ivec4(mulqv4((*(iquat*)o), (*(ivec4*)o2)));
		free(o);
		free(o2);
		return out;
	}
	else { // obj1 is self, obj2 is something else (maybe it knows how to do the operation)
		PyObject * out = PyObject_CallMethod(obj2, "__rmul__", "O", obj1);
		if (out == NULL) {
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tquat' and ", obj2);
			return NULL;
		}
		return out;
	}
}

static PyObject *
tquat_div(PyObject *obj1, PyObject *obj2)
{
	iquat o;

	if (!unpack_iquatp(obj1, &o)) { // obj1 is not supported.
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tquat' and ", obj1);
		return NULL;
	}
	if (IS_NUMERIC(obj2)) { // obj1 is self, obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		return pack_tquatq(
			o.x / d,
			o.y / d,
			o.z / d,
			o.w / d
		);
	}
	PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tquat' and ", obj2);
	return NULL;
}

// inplace
// binaryfunc
static PyObject *
tquat_iadd(tquat *self, PyObject *obj)
{
	tquat * temp = (tquat*)tquat_add((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;
	self->w = temp->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tquat_isub(tquat *self, PyObject *obj)
{
	tquat * temp = (tquat*)tquat_sub((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;
	self->w = temp->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tquat_imul(tquat *self, PyObject *obj)
{
	tquat * temp = (tquat*)tquat_mul((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;
	self->w = temp->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tquat_idiv(tquat *self, PyObject *obj)
{
	tquat * temp = (tquat*)tquat_div((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x = temp->x;
	self->y = temp->y;
	self->z = temp->z;
	self->w = temp->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyMemberDef tquat_members[] = {
	{ "x", T_DOUBLE, offsetof(tquat, x), 0,
	"quat x" },
{ "y", T_DOUBLE, offsetof(tquat, y), 0,
"quat y" },
{ "z", T_DOUBLE, offsetof(tquat, z), 0,
"quat z" },
{ "w", T_DOUBLE, offsetof(tquat, w), 0,
"quat w" },
{ NULL }  /* Sentinel */
};

static PyObject *
tquat_str(tquat* self)
{
	char * out = (char*)malloc((64) * sizeof(char));
	snprintf(out, 64, "tquat( %12.6g, %12.6g, %12.6g, %12.6g )", self->x, self->y, self->z, self->w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tquat_len(tquat * self) {
	return (Py_ssize_t)4;
}

static PyObject* tquat_sq_item(tquat * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyFloat_FromDouble(self->x);
	case 1:
		return PyFloat_FromDouble(self->y);
	case 2:
		return PyFloat_FromDouble(self->z);
	case 3:
		return PyFloat_FromDouble(self->w);
	case -1:
		return PyFloat_FromDouble(self->w);
	case -2:
		return PyFloat_FromDouble(self->z);
	case -3:
		return PyFloat_FromDouble(self->y);
	case -4:
		return PyFloat_FromDouble(self->x);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int tquat_sq_setitem(tquat * self, Py_ssize_t index, PyObject * value) {
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
	case 2:
		self->z = d;
		return 0;
	case 3:
		self->w = d;
		return 0;
	case -1:
		self->w = d;
		return 0;
	case -2:
		self->z = d;
		return 0;
	case -3:
		self->y = d;
		return 0;
	case -4:
		self->x = d;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tquat_contains(tquat * self, PyObject * value) {
	double d;
	if (IS_NUMERIC(value)) {
		d = pyvalue_as_double(value);
		return (int)(d == self->x || d == self->y || d == self->z || d == self->w);
	}
	return 0;

}

static PyObject * tquat_richcompare(tquat * self, PyObject * other, int comp_type) {
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tquatType)) { // incopatible type
			Py_RETURN_FALSE;
		}
		return PyBool_FromLong((self->x == ((tquat*)other)->x) && (self->y == ((tquat*)other)->y) && (self->z == ((tquat*)other)->z) && (self->w == ((tquat*)other)->w));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tquatType)) { // incopatible type
			Py_RETURN_TRUE;
		}
		return PyBool_FromLong((self->x != ((tquat*)other)->x) || (self->y != ((tquat*)other)->y) || (self->z != ((tquat*)other)->z) || (self->w != ((tquat*)other)->w));
	}
	else if (comp_type == Py_LT) {
		if (!PyObject_TypeCheck(other, &tquatType)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for <: 'glm::detail::tquat' and ", other);
			return NULL;
		}
		return pack_tquat((double)(self->x < ((tquat*)other)->x), (double)(self->y < ((tquat*)other)->y), (double)(self->z < ((tquat*)other)->z), (double)(self->w < ((tquat*)other)->w));
	}
	else if (comp_type == Py_LE) {
		if (!PyObject_TypeCheck(other, &tquatType)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for <=: 'glm::detail::tquat' and ", other);
			return NULL;
		}
		return pack_tquat((double)(self->x <= ((tquat*)other)->x), (double)(self->y <= ((tquat*)other)->y), (double)(self->z <= ((tquat*)other)->z), (double)(self->w <= ((tquat*)other)->w));
	}
	else if (comp_type == Py_GT) {
		if (!PyObject_TypeCheck(other, &tquatType)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for >: 'glm::detail::tquat' and ", other);
			return NULL;
		}
		return pack_tquat((double)(self->x > ((tquat*)other)->x), (double)(self->y > ((tquat*)other)->y), (double)(self->z > ((tquat*)other)->z), (double)(self->w > ((tquat*)other)->w));
	}
	else if (comp_type == Py_GE) {
		if (!PyObject_TypeCheck(other, &tquatType)) { // incopatible type
			PY_TYPEERROR("unsupported operand type(s) for >=: 'glm::detail::tquat' and ", other);
			return NULL;
		}
		return pack_tquat((double)(self->x >= ((tquat*)other)->x), (double)(self->y >= ((tquat*)other)->y), (double)(self->z >= ((tquat*)other)->z), (double)(self->w >= ((tquat*)other)->w));
	}
	else {
		PY_TYPEERROR("this operator is not supported between instances of 'function' and ", other);
		return NULL;
	}
}

static bool unswizzle_tquat(tquat * self, char c, double * out) {
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
	if (c == 'w' || c == 'a' || c == 'p') {
		*out = self->w;
		return true;
	}
	return false;
}

static PyObject * tquat_getattr(PyObject * obj, PyObject * name) {
	char * name_as_ccp = attr_name_to_cstr(name);

	if ((strlen(name_as_ccp) >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[strlen(name_as_ccp) - 1] == '_' && name_as_ccp[strlen(name_as_ccp) - 2] == '_')
		|| strcmp(name_as_ccp, "x") == 0 || strcmp(name_as_ccp, "y") == 0 || strcmp(name_as_ccp, "z") == 0 || strcmp(name_as_ccp, "w") == 0) {
		return PyObject_GenericGetAttr(obj, name);
	}
	size_t len = strlen(name_as_ccp);
	if (len == 1) {
		double x;
		if (unswizzle_tquat((tquat *)obj, name_as_ccp[0], &x)) {
			return PyFloat_FromDouble(x);
		}
	}
	else if (len == 2) {
		double x;
		double y;
		if (unswizzle_tquat((tquat *)obj, name_as_ccp[0], &x) && unswizzle_tquat((tquat *)obj, name_as_ccp[1], &y)) {
			return pack_tvec2(x, y);
		}
	}
	else if (len == 3) {
		double x;
		double y;
		double z;
		if (unswizzle_tquat((tquat *)obj, name_as_ccp[0], &x) && unswizzle_tquat((tquat *)obj, name_as_ccp[1], &y) && unswizzle_tquat((tquat *)obj, name_as_ccp[2], &z)) {
			return pack_tvec3(x, y, z);
		}
	}
	else if (len == 4) {
		double x;
		double y;
		double z;
		double w;
		if (unswizzle_tquat((tquat *)obj, name_as_ccp[0], &x) && unswizzle_tquat((tquat *)obj, name_as_ccp[1], &y) && unswizzle_tquat((tquat *)obj, name_as_ccp[2], &z) && unswizzle_tquat((tquat *)obj, name_as_ccp[3], &w)) {
			return pack_tquat(x, y, z, w);
		}
	}
	return PyObject_GenericGetAttr(obj, name);
}

// iterator

static PyObject *
tquatIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tquat *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tquatIter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tquatIter *rgstate = (tquatIter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tquatIter_dealloc(tquatIter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tquatIter_next(tquatIter *rgstate)
{
	if (rgstate->seq_index < 4) {
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
		case 3:
			rgstate->seq_index++;
			return PyFloat_FromDouble(rgstate->sequence->w);
		}
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * tquat_geniter(tquat * self) {
	PyObject * obj = tquatIter_new(&tquatIterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tquatSeqMethods = {
	(lenfunc)tquat_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tquat_sq_item, // sq_item
	0,
	(ssizeobjargproc)tquat_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tquat_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

#if PY3K
static PyNumberMethods tquatNumMethods = {
	(binaryfunc)tquat_add,
	(binaryfunc)tquat_sub,
	(binaryfunc)tquat_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)tquat_neg, //nb_negative
	(unaryfunc)tquat_pos, //nb_positive
	(unaryfunc)tquat_abs, //nb_absolute
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

	(binaryfunc)tquat_iadd, //nb_inplace_add
	(binaryfunc)tquat_isub, //nb_inplace_subtract
	(binaryfunc)tquat_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)tquat_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)tquat_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tquatNumMethods = {
	(binaryfunc)tquat_add, //nb_add;
	(binaryfunc)tquat_sub, //nb_subtract;
	(binaryfunc)tquat_mul, //nb_multiply;
	(binaryfunc)tquat_div, //nb_divide;
	0, //nb_remainder;
	0, //nb_divmod;
	0, //nb_power;
	(unaryfunc)tquat_neg, //nb_negative;
	(unaryfunc)tquat_pos, //nb_positive;
	(unaryfunc)tquat_abs, //nb_absolute;
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
	   (binaryfunc)tquat_iadd, //nb_inplace_add;
	   (binaryfunc)tquat_isub, //nb_inplace_subtract;
	   (binaryfunc)tquat_imul, //nb_inplace_multiply;
	   (binaryfunc)tquat_idiv, //nb_inplace_divide;
	   0, //nb_inplace_remainder;
	   0, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  0, //nb_floor_divide;
		  (binaryfunc)tquat_div, //nb_true_divide;
		  0, //nb_inplace_floor_divide;
		  (binaryfunc)tquat_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tquatType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tquat",             /* tp_name */
	sizeof(tquat),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tquat_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tquat_str,                         /* tp_repr */
	&tquatNumMethods,             /* tp_as_number */
	&tquatSeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tquat_str,                         /* tp_str */
	(getattrofunc)tquat_getattr,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"tquat( <tquat compatible type(s)> )\n4 components quaternion of medium double-qualifier floating-point numbers.",            /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tquat_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tquat_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tquat_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tquat_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tquat_new,                 /* tp_new */
};

static PyTypeObject tquatIterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tquatIter",             /* tp_name */
	sizeof(tquatIter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tquatIter_dealloc, /* tp_dealloc */
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
	"tquat iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tquatIter_next,                         /* tp_iternext */
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
	(newfunc)tquatIter_new,                 /* tp_new */
};

#define iroll(q) (atan2((2.0) * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z))
#define irollp(q) (atan2((2.0) * (q->x * q->y + q->w * q->z), q->w * q->w + q->x * q->x - q->y * q->y - q->z * q->z))

static double ipitch(iquat q) {
	double y = (2.0) * (q.y * q.z + q.w * q.x);
	double x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

	if ((y == (0.0)) && (x == (0.0))) //avoid atan2(0,0) - handle singularity - Matiis
		return ((2.0) * atan2(q.x, q.w));

	return (atan2(y, x));
}

//static double ipitchp(iquat* q) {
//	double y = (2.0) * (q->y * q->z + q->w * q->x);
//	double x = q->w * q->w - q->x * q->x - q->y * q->y + q->z * q->z;
//
//	if ((y == (0.0)) && (x == (0.0))) //avoid atan2(0,0) - handle singularity - Matiis
//		return ((2.0) * atan2(q->x, q->w));
//
//	return (atan2(y, x));
//}

#define iyaw(q) asin(clamp((-2.0) * (q.x * q.z - q.w * q.y), (-1.0), (1.0)))
#define iyawp(q) asin(clamp((-2.0) * (q->x * q->z - q->w * q->y), (-1.0), (1.0)))

static PyObject* eulerAngles(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		return pack_tvec3(ipitch(o), iyaw(o), iroll(o));
	}
	PY_TYPEERROR("unsupported operand type for eulerAngles(): ", arg);
	return NULL;
}

static PyObject* roll(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		return PyFloat_FromDouble(iroll(o));
	}
	PY_TYPEERROR("unsupported operand type for roll(): ", arg);
	return NULL;
}

static PyObject* pitch(PyObject* self, PyObject* arg) {
	iquat o; 
	if (unpack_iquatp(arg, &o)) {
		return PyFloat_FromDouble(ipitch(o));
	}
	PY_TYPEERROR("unsupported operand type for pitch(): ", arg);
	return NULL;
}

static PyObject* yaw(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		return PyFloat_FromDouble(iyaw(o));
	}
	PY_TYPEERROR("unsupported operand type for yaw(): ", arg);
	return NULL;
}

static PyObject* mat3_cast(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		imat3x3 Result = to_imat3x3d((1.0));
		double qxx = (o.x * o.x);
		double qyy = (o.y * o.y);
		double qzz = (o.z * o.z);
		double qxz = (o.x * o.z);
		double qxy = (o.x * o.y);
		double qyz = (o.y * o.z);
		double qwx = (o.w * o.x);
		double qwy = (o.w * o.y);
		double qwz = (o.w * o.z);

		Result.x.x = (1.0) - (2.0) * (qyy + qzz);
		Result.x.y = (2.0) * (qxy + qwz);
		Result.x.z = (2.0) * (qxz - qwy);

		Result.y.x = (2.0) * (qxy - qwz);
		Result.y.y = (1.0) - (2.0) * (qxx + qzz);
		Result.y.z = (2.0) * (qyz + qwx);

		Result.z.x = (2.0) * (qxz + qwy);
		Result.z.y = (2.0) * (qyz - qwx);
		Result.z.z = (1.0) - (2.0) * (qxx + qyy);
		return build_imat3x3(Result);
	}
	PY_TYPEERROR("unsupported operand type for mat3_cast(): ", arg);
	return NULL;
}

static PyObject* mat4_cast(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		imat4x4 Result = to_imat4x4d((1.0));
		double qxx = (o.x * o.x);
		double qyy = (o.y * o.y);
		double qzz = (o.z * o.z);
		double qxz = (o.x * o.z);
		double qxy = (o.x * o.y);
		double qyz = (o.y * o.z);
		double qwx = (o.w * o.x);
		double qwy = (o.w * o.y);
		double qwz = (o.w * o.z);

		Result.x.x = (1.0) - (2.0) * (qyy + qzz);
		Result.x.y = (2.0) * (qxy + qwz);
		Result.x.z = (2.0) * (qxz - qwy);

		Result.y.x = (2.0) * (qxy - qwz);
		Result.y.y = (1.0) - (2.0) * (qxx + qzz);
		Result.y.z = (2.0) * (qyz + qwx);

		Result.z.x = (2.0) * (qxz + qwy);
		Result.z.y = (2.0) * (qyz - qwx);
		Result.z.z = (1.0) - (2.0) * (qxx + qyy);
		return build_imat4x4(Result);
	}
	PY_TYPEERROR("unsupported operand type for mat4_cast(): ", arg);
	return NULL;
}

static PyObject* quat_cast(PyObject* self, PyObject* arg) {
	void* o = NULL;
	char matType = unpack_pyobject(arg, &o, GLM_HAS_TMAT4x4 | GLM_HAS_TMAT3x3);
	imat3x3 m;
	if (matType == GLM_TMAT3x3) {
		m = *(imat3x3*)o;
	}
	if (matType == GLM_TMAT4x4) {
		m = to_imat3x3(
			((imat4x4*)o)->x.x, ((imat4x4*)o)->x.y, ((imat4x4*)o)->x.z,
			((imat4x4*)o)->y.x, ((imat4x4*)o)->y.y, ((imat4x4*)o)->y.z,
			((imat4x4*)o)->z.x, ((imat4x4*)o)->z.y, ((imat4x4*)o)->z.z);
	}
	else {
		PY_TYPEERROR("unsupported operand type for quat_cast(): ", arg);
		return NULL;
	}
	double fourXSquaredMinus1 = m.x.x - m.y.y - m.z.z;
	double fourYSquaredMinus1 = m.y.y - m.x.x - m.z.z;
	double fourZSquaredMinus1 = m.z.z - m.x.x - m.y.y;
	double fourWSquaredMinus1 = m.x.x + m.y.y + m.z.z;

	int biggestIndex = 0;
	double fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	double biggestVal = sqrt(fourBiggestSquaredMinus1 + (1.0)) * (0.5);
	double mult = (0.25) / biggestVal;

	switch (biggestIndex)
	{
	case 0:
		return build_iquat(to_iquatv(biggestVal, (m.y.z - m.z.y) * mult, (m.z.x - m.x.z) * mult, (m.x.y - m.y.x) * mult));
	case 1:
		return build_iquat(to_iquatv((m.y.z - m.z.y) * mult, biggestVal, (m.x.y + m.y.x) * mult, (m.z.x + m.x.z) * mult));
	case 2:
		return build_iquat(to_iquatv((m.z.x - m.x.z) * mult, (m.x.y + m.y.x) * mult, biggestVal, (m.y.z + m.z.y) * mult));
	case 3:
		return build_iquat(to_iquatv((m.x.y - m.y.x) * mult, (m.z.x + m.x.z) * mult, (m.y.z + m.z.y) * mult, biggestVal));
	default: // Silence a -Wswitch-default warning in GCC. Should never actually get here.
		return build_iquat(to_iquatv(1, 0, 0, 0));
	}
}

static PyObject* angle(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		return PyFloat_FromDouble(acos(o.w) * (2.0));
	}
	PY_TYPEERROR("unsupported operand type for angle(): ", arg);
	return NULL;
}

static PyObject* axis(PyObject* self, PyObject* arg) {
	iquat o;
	if (unpack_iquatp(arg, &o)) {
		double tmp1 = (1.0) - o.w * o.w;
		if (tmp1 <= (0.0))
			return pack_tvec3(0.0, 0.0, 1.0);
		double tmp2 = (1.0) / sqrt(tmp1);
		return pack_tvec3(o.x * tmp2, o.y * tmp2, o.z * tmp2);
	}
	PY_TYPEERROR("unsupported operand type for axis(): ", arg);
	return NULL;
}

static PyObject* angleAxis(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2;
	UNPACK_2_VARARGS(args, "angleAxis", arg1, arg2);
	if (!IS_NUMERIC(arg1)) {
		PY_TYPEERROR_2O("unsupported operand type(s) for angleAxis(): ", arg1,arg2);
		return NULL;
	}
	double a = pyvalue_as_double(arg1);
	ivec3 v;
	if (unpack_ivec3p(arg2, &v)) {
		double s = sin(a * (0.5));

		return pack_tquat(v.x * s, v.y * s, v.z * s, cos(a * 0.5));
	}
	PY_TYPEERROR_2O("unsupported operand type(s) for angleAxis(): ", arg1, arg2);
	return NULL;
}

static PyObject* lerp(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "lerp", arg1, arg2, arg3);
	if (!IS_NUMERIC(arg3)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for lerp()");
		return NULL;
	}
	double a = pyvalue_as_double(arg3);
	iquat x; 
	iquat y;
	if (unpack_iquatp(arg1, &x) && unpack_iquatp(arg2, &y)) {
		return build_iquat(addqq(mulqd(x, ((1.) - a)), mulqd(y, a)));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for lerp()");
	return NULL;
}

static PyObject* slerp(PyObject* self, PyObject* args) {
	PyObject* arg1, *arg2, *arg3;
	UNPACK_3_VARARGS(args, "slerp", arg1, arg2, arg3);
	if (!IS_NUMERIC(arg3)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for slerp()");
		return NULL;
	}
	double a = pyvalue_as_double(arg3);
	iquat x;
	iquat y;
	if (unpack_iquatp(arg1, &x) && unpack_iquatp(arg2, &y)) {
		iquat z = to_iquatq(y.x, y.y, y.z, y.w);

		double cosTheta = idotq(x, y);

		// If cosTheta < 0, the interpolation will take the long way around the sphere. 
		// To fix this, one quat must be negated.
		if (cosTheta < (0.0))
		{
			z = to_iquatq(-y.x, -y.y, -y.z, -y.w);
			cosTheta = -cosTheta;
		}

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if (cosTheta > (1.) - DBL_EPSILON)
		{
			// Linear interpolation
			return build_iquat(to_iquatv(
				mix(x.w, z.w, a),
				mix(x.x, z.x, a),
				mix(x.y, z.y, a),
				mix(x.z, z.z, a)));
		}
		else
		{
			// Essential Mathematics, page 467
			double angle = acos(cosTheta);
			return build_iquat(divqd((addqq(mulqd(x,sin((1.0 - a) * angle)), mulqd(z,sin(a * angle)))), sin(angle)));
		}
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for slerp()");
	return NULL;
}

static PyObject* conjugate(PyObject* self, PyObject* arg) {
	iquat q;
	if (unpack_iquatp(arg, &q)) {
		return build_iquat(iconjugate(q));
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for conjugate()");
	return NULL;
}
