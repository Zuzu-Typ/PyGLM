static double convertLinearToSRGB_(double x, double y) {
	double ClampedColor = clamp(x, 0.0, 1.0);
	return mixb(
		pow(ClampedColor, y) * (1.055) - (0.055),
		ClampedColor * (12.92),
		(ClampedColor < ((0.0031308))));
}



static double taylormethod_(double x) {
	return 0.662002687 * sqrt(x) + 0.684122060 * pow(x,0.25) - 0.323583601 * pow(x, 0.125) - 0.0225411470 * x;
}

static PyObject* convertLinearToSRGB(PyObject * self, PyObject* args, PyObject* kwargs) {
	static char *kwlist[] = { "ColorLinear", "Gamma", NULL };
	PyObject* arg1 = NULL, *arg2 = NULL;
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|O", kwlist, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}

	if (arg2 == NULL) {
		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			ivec2 ClampedColor = to_ivec2(
				convertLinearToSRGB_(((ivec2*)o)->x, 0.41666),
				convertLinearToSRGB_(((ivec2*)o)->y, 0.41666));
			PyObject* out = build_ivec2(ClampedColor);
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			// Based on Ian Taylor http://chilliant.blogspot.fr/2012/08/srgb-approximations-for-hlsl.html
			return functor1(taylormethod_, arg1);
		}
		if (vecType == GLM_TVEC4) {
			ivec3 ClampedColor = to_ivec3(
				convertLinearToSRGB_(((ivec4*)o)->x, 0.41666),
				convertLinearToSRGB_(((ivec4*)o)->y, 0.41666),
				convertLinearToSRGB_(((ivec4*)o)->z, 0.41666));
			PyObject* out = pack_tvec4(
				ClampedColor.x, 
				ClampedColor.y, 
				ClampedColor.z, 
				((ivec4*)o)->w);
			free(o);
			return out;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}

	if (!IS_NUMERIC(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}
	double d = pyvalue_as_double(arg2);
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 ClampedColor = to_ivec2(
			convertLinearToSRGB_(((ivec2*)o)->x, 1.0 / d),
			convertLinearToSRGB_(((ivec2*)o)->y, 1.0 / d));
		PyObject* out = build_ivec2(ClampedColor);
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 ClampedColor = to_ivec3(
			convertLinearToSRGB_(((ivec3*)o)->x, 1.0 / d),
			convertLinearToSRGB_(((ivec3*)o)->y, 1.0 / d),
			convertLinearToSRGB_(((ivec3*)o)->z, 1.0 / d));
		PyObject* out = build_ivec3(ClampedColor);
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec3 ClampedColor = to_ivec3(
			convertLinearToSRGB_(((ivec4*)o)->x, 1.0 / d),
			convertLinearToSRGB_(((ivec4*)o)->y, 1.0 / d),
			convertLinearToSRGB_(((ivec4*)o)->z, 1.0 / d));
		PyObject* out = pack_tvec4(
			ClampedColor.x,
			ClampedColor.y,
			ClampedColor.z,
			((ivec4*)o)->w);
		free(o);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
	return NULL;
}

static double convertSRGBToRgb_(double x, double y) {
	return mixb(
		pow((x + (0.055)) * (0.94786729857819905213270142180095), (y)),
		x * (0.07739938080495356037151702786378),
		(x <= (0.04045)));
}

static PyObject* convertSRGBToLinear(PyObject * self, PyObject* args, PyObject* kwargs) {
	static char *kwlist[] = { "ColorLinear", "Gamma", NULL };
	PyObject* arg1 = NULL, *arg2 = NULL;
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|O", kwlist, &arg1, &arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertSRGBToLinear()");
		return NULL;
	}

	if (arg2 == NULL) {
		void* o = NULL;
		char vecType = unpack_ivec(arg1, &o);
		if (vecType == GLM_TVEC2) {
			ivec2 ClampedColor = to_ivec2(
				convertSRGBToRgb_(((ivec2*)o)->x, 2.4),
				convertSRGBToRgb_(((ivec2*)o)->y, 2.4));
			PyObject* out = build_ivec2(ClampedColor);
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC3) {
			ivec3 ClampedColor = to_ivec3(
				convertSRGBToRgb_(((ivec3*)o)->x, 2.4),
				convertSRGBToRgb_(((ivec3*)o)->y, 2.4),
				convertSRGBToRgb_(((ivec3*)o)->z, 2.4));
			PyObject* out = build_ivec3(ClampedColor);
			free(o);
			return out;
		}
		if (vecType == GLM_TVEC4) {
			ivec3 ClampedColor = to_ivec3(
				convertSRGBToRgb_(((ivec4*)o)->x, 2.4),
				convertSRGBToRgb_(((ivec4*)o)->y, 2.4),
				convertSRGBToRgb_(((ivec4*)o)->z, 2.4));
			PyObject* out = pack_tvec4(
				ClampedColor.x,
				ClampedColor.y,
				ClampedColor.z,
				((ivec4*)o)->w);
			free(o);
			return out;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}

	if (!IS_NUMERIC(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
		return NULL;
	}
	double d = pyvalue_as_double(arg2);
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);
	if (vecType == GLM_TVEC2) {
		ivec2 ClampedColor = to_ivec2(
			convertSRGBToRgb_(((ivec2*)o)->x, d),
			convertSRGBToRgb_(((ivec2*)o)->y, d));
		PyObject* out = build_ivec2(ClampedColor);
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC3) {
		ivec3 ClampedColor = to_ivec3(
			convertSRGBToRgb_(((ivec3*)o)->x, d),
			convertSRGBToRgb_(((ivec3*)o)->y, d),
			convertSRGBToRgb_(((ivec3*)o)->z, d));
		PyObject* out = build_ivec3(ClampedColor);
		free(o);
		return out;
	}
	if (vecType == GLM_TVEC4) {
		ivec3 ClampedColor = to_ivec3(
			convertSRGBToRgb_(((ivec4*)o)->x, d),
			convertSRGBToRgb_(((ivec4*)o)->y, d),
			convertSRGBToRgb_(((ivec4*)o)->z, d));
		PyObject* out = pack_tvec4(
			ClampedColor.x,
			ClampedColor.y,
			ClampedColor.z,
			((ivec4*)o)->w);
		free(o);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for convertLinearToSRGB()");
	return NULL;
}