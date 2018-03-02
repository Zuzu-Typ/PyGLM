static PyObject* functor1(double(*Func)(double x), PyObject * arg) {
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);

	if (vecType == GLM_TVEC2) {
		PyObject* out = pack_tvec2(Func(((ivec2*)o)->x), Func(((ivec2*)o)->y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		PyObject* out = pack_tvec3(Func(((ivec3*)o)->x), Func(((ivec3*)o)->y), Func(((ivec3*)o)->z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		PyObject* out = pack_tvec4(Func(((ivec4*)o)->x), Func(((ivec4*)o)->y), Func(((ivec4*)o)->z), Func(((ivec4*)o)->w));
		free(o);
		return out;
	}
	return NULL;
}

static PyObject* functor2(double(*Func)(double x, double y), PyObject * arg1, PyObject * arg2) {
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);

	if (vecType == GLM_TVEC2) {
		ivec2 o2;
		if (!unpack_ivec2p(arg2, &o2)) {
			return NULL;
		}
		PyObject* out = pack_tvec2(Func(((ivec2*)o)->x, o2.x), Func(((ivec2*)o)->y, o2.y));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 o2;
		if (!unpack_ivec3p(arg2, &o2)) {
			return NULL;
		}
		PyObject* out = pack_tvec3(Func(((ivec3*)o)->x, o2.x), Func(((ivec3*)o)->y, o2.y), Func(((ivec3*)o)->z, o2.z));
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec4 o2;
		if (!unpack_ivec4p(arg2, &o2)) {
			return NULL;
		}
		PyObject* out = pack_tvec4(Func(((ivec4*)o)->x, o2.x), Func(((ivec4*)o)->y, o2.y), Func(((ivec4*)o)->z, o2.z), Func(((ivec4*)o)->w, o2.w));
		free(o);
		return out;
	}
	return NULL;
}

//static PyObject* functor2_vec_sca(double(*Func)(double x, double y), PyObject * arg1, double arg2) {
//	void* o = NULL;
//	char vecType = unpack_ivec(arg1, &o);
//
//	if (vecType == GLM_TVEC2) {
//		PyObject* out = pack_tvec2(Func(((ivec2*)o)->x, arg2), Func(((ivec2*)o)->y, arg2));
//		free(o);
//		return out;
//	}
//	if (vecType == GLM_TVEC3) {
//		PyObject* out = pack_tvec3(Func(((ivec3*)o)->x, arg2), Func(((ivec3*)o)->y, arg2), Func(((ivec3*)o)->z, arg2));
//		free(o);
//		return out;
//	}
//	if (vecType == GLM_TVEC4) {
//		PyObject* out = pack_tvec4(Func(((ivec4*)o)->x, arg2), Func(((ivec4*)o)->y, arg2), Func(((ivec4*)o)->z, arg2), Func(((ivec4*)o)->w, arg2));
//		free(o);
//		return out;
//	}
//	return NULL;
//}