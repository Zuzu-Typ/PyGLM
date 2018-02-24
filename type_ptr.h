static PyObject* value_ptr(PyObject* self, PyObject* arg) {
	if (PyObject_TypeCheck(arg, &tvec2Type)) {
		(((tvec2*)arg)->value_ptr) = to_fvec2(((tvec2*)arg)->x, ((tvec2*)arg)->y);
		return C_VOID_P(&(((tvec2*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tvec3Type)) {
		(((tvec3*)arg)->value_ptr) = to_fvec3(((tvec3*)arg)->x, ((tvec3*)arg)->y, ((tvec3*)arg)->z);
		return C_VOID_P(&(((tvec3*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tvec4Type)) {
		(((tvec4*)arg)->value_ptr) = to_fvec4(((tvec4*)arg)->x, ((tvec4*)arg)->y, ((tvec4*)arg)->z, ((tvec4*)arg)->w);
		return C_VOID_P(&(((tvec4*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tquatType)) {
		(((tquat*)arg)->value_ptr) = to_fquatq(((tquat*)arg)->x, ((tquat*)arg)->y, ((tquat*)arg)->z, ((tquat*)arg)->w);
		return C_VOID_P(&(((tquat*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat2x2Type)) {
		(((tmat2x2*)arg)->value_ptr) = to_fmat2x2(((tmat2x2*)arg)->x->x, ((tmat2x2*)arg)->x->y, ((tmat2x2*)arg)->y->x, ((tmat2x2*)arg)->y->y);
		return C_VOID_P(&(((tmat2x2*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat2x3Type)) {
		(((tmat2x3*)arg)->value_ptr) = to_fmat2x3(((tmat2x3*)arg)->x->x, ((tmat2x3*)arg)->x->y, ((tmat2x3*)arg)->x->z, ((tmat2x3*)arg)->y->x, ((tmat2x3*)arg)->y->y, ((tmat2x3*)arg)->y->z);
		return C_VOID_P(&(((tmat2x3*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat2x4Type)) {
		(((tmat2x4*)arg)->value_ptr) = to_fmat2x4(((tmat2x4*)arg)->x->x, ((tmat2x4*)arg)->x->y, ((tmat2x4*)arg)->x->z, ((tmat2x4*)arg)->x->w, ((tmat2x4*)arg)->y->x, ((tmat2x4*)arg)->y->y, ((tmat2x4*)arg)->y->z, ((tmat2x4*)arg)->y->w);
		return C_VOID_P(&(((tmat2x4*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat3x2Type)) {
		(((tmat3x2*)arg)->value_ptr) = to_fmat3x2(((tmat3x2 *)arg)->x->x, ((tmat3x2 *)arg)->x->y, ((tmat3x2 *)arg)->y->x, ((tmat3x2 *)arg)->y->y, ((tmat3x2 *)arg)->z->x, ((tmat3x2 *)arg)->z->y);
		return C_VOID_P(&(((tmat3x2*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat3x3Type)) {
		(((tmat3x3*)arg)->value_ptr) = to_fmat3x3(((tmat3x3 *)arg)->x->x, ((tmat3x3 *)arg)->x->y, ((tmat3x3 *)arg)->x->z, ((tmat3x3 *)arg)->y->x, ((tmat3x3 *)arg)->y->y, ((tmat3x3 *)arg)->y->z, ((tmat3x3 *)arg)->z->x, ((tmat3x3 *)arg)->z->y, ((tmat3x3 *)arg)->z->z);
		return C_VOID_P(&(((tmat3x3*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat3x4Type)) {
		(((tmat3x4*)arg)->value_ptr) = to_fmat3x4(((tmat3x4 *)arg)->x->x, ((tmat3x4 *)arg)->x->y, ((tmat3x4 *)arg)->x->z, ((tmat3x4 *)arg)->x->w,
			((tmat3x4 *)arg)->y->x, ((tmat3x4 *)arg)->y->y, ((tmat3x4 *)arg)->y->z, ((tmat3x4 *)arg)->y->w,
			((tmat3x4 *)arg)->z->x, ((tmat3x4 *)arg)->z->y, ((tmat3x4 *)arg)->z->z, ((tmat3x4 *)arg)->z->w);
		return C_VOID_P(&(((tmat3x4*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat4x2Type)) {
		(((tmat4x2*)arg)->value_ptr) = to_fmat4x2(((tmat4x2 *)arg)->x->x, ((tmat4x2 *)arg)->x->y,
			((tmat4x2 *)arg)->y->x, ((tmat4x2 *)arg)->y->y,
			((tmat4x2 *)arg)->z->x, ((tmat4x2 *)arg)->z->y,
			((tmat4x2 *)arg)->w->x, ((tmat4x2 *)arg)->w->y);
		return C_VOID_P(&(((tmat4x2*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat4x3Type)) {
		(((tmat4x3*)arg)->value_ptr) = to_fmat4x3(((tmat4x3 *)arg)->x->x, ((tmat4x3 *)arg)->x->y, ((tmat4x3 *)arg)->x->z,
			((tmat4x3 *)arg)->y->x, ((tmat4x3 *)arg)->y->y, ((tmat4x3 *)arg)->y->z,
			((tmat4x3 *)arg)->z->x, ((tmat4x3 *)arg)->z->y, ((tmat4x3 *)arg)->z->z,
			((tmat4x3 *)arg)->w->x, ((tmat4x3 *)arg)->w->y, ((tmat4x3 *)arg)->w->z);
		return C_VOID_P(&(((tmat4x3*)arg)->value_ptr));
	}
	if (PyObject_TypeCheck(arg, &tmat4x4Type)) {
		(((tmat4x4*)arg)->value_ptr) = to_fmat4x4(((tmat4x4 *)arg)->x->x, ((tmat4x4 *)arg)->x->y, ((tmat4x4 *)arg)->x->z, ((tmat4x4 *)arg)->x->w,
			((tmat4x4 *)arg)->y->x, ((tmat4x4 *)arg)->y->y, ((tmat4x4 *)arg)->y->z, ((tmat4x4 *)arg)->y->w,
			((tmat4x4 *)arg)->z->x, ((tmat4x4 *)arg)->z->y, ((tmat4x4 *)arg)->z->z, ((tmat4x4 *)arg)->z->w,
			((tmat4x4 *)arg)->w->x, ((tmat4x4 *)arg)->w->y, ((tmat4x4 *)arg)->w->z, ((tmat4x4 *)arg)->w->w);
		return C_VOID_P(&(((tmat4x4*)arg)->value_ptr));
	}
	PY_TYPEERROR("invalid operand type for value_ptr(): ", arg);
	return NULL;
}

static PyObject*
sizeof_(PyObject* self, PyObject* arg) {
	if (PyObject_TypeCheck(arg, &tvec2Type) || arg == (PyObject*)&tvec2Type) {
		return PyLong_FromLong(sizeof(fvec2));
	}
	if (PyObject_TypeCheck(arg, &tvec3Type) || arg == (PyObject*)&tvec3Type) {
		return PyLong_FromLong(sizeof(fvec3));
	}
	if (PyObject_TypeCheck(arg, &tvec4Type) || arg == (PyObject*)&tvec4Type) {
		return PyLong_FromLong(sizeof(fvec4));
	}
	if (PyObject_TypeCheck(arg, &tmat2x2Type) || arg == (PyObject*)&tmat2x2Type) {
		return PyLong_FromLong(sizeof(fmat2x2));
	}
	if (PyObject_TypeCheck(arg, &tmat2x3Type) || arg == (PyObject*)&tmat2x3Type) {
		return PyLong_FromLong(sizeof(fmat2x3));
	}
	if (PyObject_TypeCheck(arg, &tmat2x4Type) || arg == (PyObject*)&tmat2x4Type) {
		return PyLong_FromLong(sizeof(fmat2x4));
	}
	if (PyObject_TypeCheck(arg, &tmat3x2Type) || arg == (PyObject*)&tmat3x2Type) {
		return PyLong_FromLong(sizeof(fmat3x2));
	}
	if (PyObject_TypeCheck(arg, &tmat3x3Type) || arg == (PyObject*)&tmat3x3Type) {
		return PyLong_FromLong(sizeof(fmat3x3));
	}
	if (PyObject_TypeCheck(arg, &tmat3x4Type) || arg == (PyObject*)&tmat3x4Type) {
		return PyLong_FromLong(sizeof(fmat3x4));
	}
	if (PyObject_TypeCheck(arg, &tmat4x2Type) || arg == (PyObject*)&tmat4x2Type) {
		return PyLong_FromLong(sizeof(fmat4x2));
	}
	if (PyObject_TypeCheck(arg, &tmat4x3Type) || arg == (PyObject*)&tmat4x3Type) {
		return PyLong_FromLong(sizeof(fmat4x3));
	}
	if (PyObject_TypeCheck(arg, &tmat4x4Type) || arg == (PyObject*)&tmat4x4Type) {
		return PyLong_FromLong(sizeof(fmat4x4));
	}
	PY_TYPEERROR("invalid operand type for sizeof(): ", arg);
	return NULL;
}