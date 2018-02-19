static void VEC2_INDEX_SET(ivec2* v, double i, double to) {
	if (i == 0.0) v->x = to;
	else v->y = to;
}

static void VEC3_INDEX_SET(ivec3* v, double i, double to) {
	if (i == 0.0) v->x = to;
	else if (i == 1.0) v->y = to;
	else v->z = to;
}

static void VEC4_INDEX_SET(ivec4* v, double i, double to) {
	if (i == 0.0) v->x = to;
	else if (i == 1.0) v->y = to;
	else if (i == 2.0) v->z = to;
	else v->w = to;
}

static double VEC2_INDEX(ivec2* v, double i) {
	if (i == 0.0) return v->x ;
	else return v->y ;
}

static double VEC3_INDEX(ivec3* v, double i) {
	if (i == 0.0) return v->x;
	else if (i == 1.0) return v->y;
	else return v->z ;
}

static double VEC4_INDEX(ivec4* v, double i) {
	if (i == 0.0) return v->x;
	else if (i == 1.0) return v->y;
	else if (i == 2.0) return v->z;
	else return v->w;
}

static PyObject* row(PyObject * self, PyObject* args) {
	PyObject* arg1, *arg2;
	if (PyTuple_GET_SIZE(args) == 3) {
		PyObject* arg3;
		UNPACK_3_VARARGS(args, "row", arg1, arg2, arg3);
		if (!IS_NUMERIC(arg2)) {
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for row()");
			return NULL;
		}
		double index = pyvalue_as_double(arg2);
		void * x;
		char vecType = unpack_ivec(arg3, &x);
		if (vecType == GLM_TVEC2) {
			void * m;
			char matType = unpack_pyobject(arg1, &m, GLM_HAS_TMAT2x2 | GLM_HAS_TMAT2x3 | GLM_HAS_TMAT2x4);
			if (matType == GLM_TMAT2x2) {
				if (!(index == 0.0 || index == 1.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC2_INDEX_SET(&((imat2x2*)m)->x, index, ((ivec2*)x)->x);
				VEC2_INDEX_SET(&((imat2x2*)m)->y, index, ((ivec2*)x)->y);
				PyObject* out = build_imat2x2p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT2x3) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC3_INDEX_SET(&((imat2x3*)m)->x, index, ((ivec2*)x)->x);
				VEC3_INDEX_SET(&((imat2x3*)m)->y, index, ((ivec2*)x)->y);
				PyObject* out = build_imat2x3p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT2x4) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC4_INDEX_SET(&((imat2x4*)m)->x, index, ((ivec2*)x)->x);
				VEC4_INDEX_SET(&((imat2x4*)m)->y, index, ((ivec2*)x)->y);
				PyObject* out = build_imat2x4p(m);
				free(x);
				free(m);
				return out;
			}
		}
		if (vecType == GLM_TVEC3) {
			void * m;
			char matType = unpack_pyobject(arg1, &m, GLM_HAS_TMAT3x2 | GLM_HAS_TMAT3x3 | GLM_HAS_TMAT3x4);
			if (matType == GLM_TMAT3x2) {
				if (!(index == 0.0 || index == 1.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC2_INDEX_SET(&((imat3x2*)m)->x, index, ((ivec3*)x)->x);
				VEC2_INDEX_SET(&((imat3x2*)m)->y, index, ((ivec3*)x)->y);
				VEC2_INDEX_SET(&((imat3x2*)m)->z, index, ((ivec3*)x)->z);
				PyObject* out = build_imat3x2p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT3x3) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC3_INDEX_SET(&((imat3x3*)m)->x, index, ((ivec3*)x)->x);
				VEC3_INDEX_SET(&((imat3x3*)m)->y, index, ((ivec3*)x)->y);
				VEC3_INDEX_SET(&((imat3x3*)m)->z, index, ((ivec3*)x)->z);
				PyObject* out = build_imat3x3p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT3x4) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC4_INDEX_SET(&((imat3x4*)m)->x, index, ((ivec3*)x)->x);
				VEC4_INDEX_SET(&((imat3x4*)m)->y, index, ((ivec3*)x)->y);
				VEC4_INDEX_SET(&((imat3x4*)m)->z, index, ((ivec3*)x)->z);
				PyObject* out = build_imat3x4p(m);
				free(x);
				free(m);
				return out;
			}
		}
		if (vecType == GLM_TVEC4) {
			void * m;
			char matType = unpack_pyobject(arg1, &m, GLM_HAS_TMAT4x2 | GLM_HAS_TMAT4x3 | GLM_HAS_TMAT4x4);
			if (matType == GLM_TMAT4x2) {
				if (!(index == 0.0 || index == 1.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC2_INDEX_SET(&((imat4x2*)m)->x, index, ((ivec4*)x)->x);
				VEC2_INDEX_SET(&((imat4x2*)m)->y, index, ((ivec4*)x)->y);
				VEC2_INDEX_SET(&((imat4x2*)m)->z, index, ((ivec4*)x)->z);
				VEC2_INDEX_SET(&((imat4x2*)m)->w, index, ((ivec4*)x)->w);
				PyObject* out = build_imat4x2p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT4x3) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC3_INDEX_SET(&((imat4x3*)m)->x, index, ((ivec4*)x)->x);
				VEC3_INDEX_SET(&((imat4x3*)m)->y, index, ((ivec4*)x)->y);
				VEC3_INDEX_SET(&((imat4x3*)m)->z, index, ((ivec4*)x)->z);
				VEC3_INDEX_SET(&((imat4x3*)m)->w, index, ((ivec4*)x)->w);
				PyObject* out = build_imat4x3p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT4x4) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				VEC4_INDEX_SET(&((imat4x4*)m)->x, index, ((ivec4*)x)->x);
				VEC4_INDEX_SET(&((imat4x4*)m)->y, index, ((ivec4*)x)->y);
				VEC4_INDEX_SET(&((imat4x4*)m)->z, index, ((ivec4*)x)->z);
				VEC4_INDEX_SET(&((imat4x4*)m)->w, index, ((ivec4*)x)->w);
				PyObject* out = build_imat4x4p(m);
				free(x);
				free(m);
				return out;
			}
		}
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for row()");
		return NULL;
	}
	UNPACK_2_VARARGS(args, "row", arg1, arg2);

	if (!IS_NUMERIC(arg2)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for row()");
		return NULL;
	}
	double index = pyvalue_as_double(arg2);

	void * m;
	char matType = unpack_imat(arg1, &m);
	if (matType == GLM_TMAT2x2) {
		if (!(index == 0.0 || index == 1.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec2(
			VEC2_INDEX(&((imat2x2*)m)->x, index),
			VEC2_INDEX(&((imat2x2*)m)->y, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT2x3) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec2(
			VEC3_INDEX(&((imat2x3*)m)->x, index),
			VEC3_INDEX(&((imat2x3*)m)->y, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT2x4) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec2(
			VEC4_INDEX(&((imat2x4*)m)->x, index),
			VEC4_INDEX(&((imat2x4*)m)->y, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT3x2) {
		if (!(index == 0.0 || index == 1.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec3(
			VEC2_INDEX(&((imat3x2*)m)->x, index),
			VEC2_INDEX(&((imat3x2*)m)->y, index),
			VEC2_INDEX(&((imat3x2*)m)->z, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT3x3) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec3(
			VEC3_INDEX(&((imat3x3*)m)->x, index),
			VEC3_INDEX(&((imat3x3*)m)->y, index),
			VEC3_INDEX(&((imat3x3*)m)->z, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT3x4) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec3(
			VEC4_INDEX(&((imat3x4*)m)->x, index),
			VEC4_INDEX(&((imat3x4*)m)->y, index),
			VEC4_INDEX(&((imat3x4*)m)->z, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT4x2) {
		if (!(index == 0.0 || index == 1.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec4(
			VEC2_INDEX(&((imat4x2*)m)->x, index),
			VEC2_INDEX(&((imat4x2*)m)->y, index),
			VEC2_INDEX(&((imat4x2*)m)->z, index),
			VEC2_INDEX(&((imat4x2*)m)->w, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT4x3) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec4(
			VEC3_INDEX(&((imat4x3*)m)->x, index),
			VEC3_INDEX(&((imat4x3*)m)->y, index),
			VEC3_INDEX(&((imat4x3*)m)->z, index),
			VEC3_INDEX(&((imat4x3*)m)->w, index));
		free(m);
		return out;
	}
	if (matType == GLM_TMAT4x4) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		PyObject* out = pack_tvec4(
			VEC4_INDEX(&((imat4x4*)m)->x, index),
			VEC4_INDEX(&((imat4x4*)m)->y, index),
			VEC4_INDEX(&((imat4x4*)m)->z, index),
			VEC4_INDEX(&((imat4x4*)m)->w, index));
		free(m);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for row()");
	return NULL;
}

static PyObject* column(PyObject * self, PyObject* args) {
	PyObject* arg1, *arg2;
	if (PyTuple_GET_SIZE(args) == 3) {
		PyObject* arg3;
		UNPACK_3_VARARGS(args, "column", arg1, arg2, arg3);
		if (!IS_NUMERIC(arg2)) {
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for column()");
			return NULL;
		}
		double index = pyvalue_as_double(arg2);
		void * x;
		char vecType = unpack_ivec(arg3, &x);
		if (vecType == GLM_TVEC2) {
			void * m;
			char matType = unpack_pyobject(arg1, &m, GLM_HAS_TMAT2x2 | GLM_HAS_TMAT3x2 | GLM_HAS_TMAT4x2);
			if (matType == GLM_TMAT2x2) {
				if (!(index == 0.0 || index == 1.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat2x2*)m)->x = *((ivec2*)x);
				else if (index == 1.0) ((imat2x2*)m)->y = *((ivec2*)x);
				PyObject* out = build_imat2x2p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT3x2) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat3x2*)m)->x = *((ivec2*)x);
				else if (index == 1.0) ((imat3x2*)m)->y = *((ivec2*)x);
				else if (index == 2.0) ((imat3x2*)m)->z = *((ivec2*)x);
				PyObject* out = build_imat3x2p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT4x2) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat4x2*)m)->x = *((ivec2*)x);
				else if (index == 1.0) ((imat4x2*)m)->y = *((ivec2*)x);
				else if (index == 2.0) ((imat4x2*)m)->z = *((ivec2*)x);
				else if (index == 3.0) ((imat4x2*)m)->w = *((ivec2*)x);
				PyObject* out = build_imat4x2p(m);
				free(x);
				free(m);
				return out;
			}
		}
		if (vecType == GLM_TVEC3) {
			void * m;
			char matType = unpack_pyobject(arg1, &m, GLM_HAS_TMAT2x3 | GLM_HAS_TMAT3x3 | GLM_HAS_TMAT4x3);
			if (matType == GLM_TMAT2x3) {
				if (!(index == 0.0 || index == 1.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat2x3*)m)->x = *((ivec3*)x);
				else if (index == 1.0) ((imat2x3*)m)->y = *((ivec3*)x);
				PyObject* out = build_imat2x3p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT3x3) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat3x3*)m)->x = *((ivec3*)x);
				else if (index == 1.0) ((imat3x3*)m)->y = *((ivec3*)x);
				else if (index == 2.0) ((imat3x3*)m)->z = *((ivec3*)x);
				PyObject* out = build_imat3x3p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT4x3) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat4x3*)m)->x = *((ivec3*)x);
				else if (index == 1.0) ((imat4x3*)m)->y = *((ivec3*)x);
				else if (index == 2.0) ((imat4x3*)m)->z = *((ivec3*)x);
				else if (index == 3.0) ((imat4x3*)m)->w = *((ivec3*)x);
				PyObject* out = build_imat4x3p(m);
				free(x);
				free(m);
				return out;
			}
		}
		if (vecType == GLM_TVEC4) {
			void * m;
			char matType = unpack_pyobject(arg1, &m, GLM_HAS_TMAT2x4 | GLM_HAS_TMAT3x4 | GLM_HAS_TMAT4x4);
			if (matType == GLM_TMAT2x4) {
				if (!(index == 0.0 || index == 1.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat2x4*)m)->x = *((ivec4*)x);
				else if (index == 1.0) ((imat2x4*)m)->y = *((ivec4*)x);
				PyObject* out = build_imat2x4p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT3x4) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat3x4*)m)->x = *((ivec4*)x);
				else if (index == 1.0) ((imat3x4*)m)->y = *((ivec4*)x);
				else if (index == 2.0) ((imat3x4*)m)->z = *((ivec4*)x);
				PyObject* out = build_imat3x4p(m);
				free(x);
				free(m);
				return out;
			}
			if (matType == GLM_TMAT4x4) {
				if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
					free(x);
					free(m);
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				if (index == 0.0) ((imat4x4*)m)->x = *((ivec4*)x);
				else if (index == 1.0) ((imat4x4*)m)->y = *((ivec4*)x);
				else if (index == 2.0) ((imat4x4*)m)->z = *((ivec4*)x);
				else if (index == 3.0) ((imat4x4*)m)->w = *((ivec4*)x);
				PyObject* out = build_imat4x4p(m);
				free(x);
				free(m);
				return out;
			}
		}
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for column()");
		return NULL;
	}
	UNPACK_2_VARARGS(args, "column", arg1, arg2);

	if (!IS_NUMERIC(arg2)) {
		PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for column()");
		return NULL;
	}
	double index = pyvalue_as_double(arg2);

	void * m;
	char matType = unpack_imat(arg1, &m);
	if (matType == GLM_TMAT2x2) {
		if (!(index == 0.0 || index == 1.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec2(((imat2x2*)m)->x);
			free(m);
			return out;
		}
		PyObject* out = build_ivec2(((imat2x2*)m)->y);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT2x3) {
		if (!(index == 0.0 || index == 1.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec3(((imat2x3*)m)->x);
			free(m);
			return out;
		}
		PyObject* out = build_ivec3(((imat2x3*)m)->y);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT2x4) {
		if (!(index == 0.0 || index == 1.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec4(((imat2x4*)m)->x);
			free(m);
			return out;
		}
		PyObject* out = build_ivec4(((imat2x4*)m)->y);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT3x2) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec2(((imat3x2*)m)->x);
			free(m);
			return out;
		}
		else if (index == 1.0) {
			PyObject* out = build_ivec2(((imat3x2*)m)->y);
			free(m);
			return out;
		}
		PyObject* out = build_ivec2(((imat3x2*)m)->z);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT3x3) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec3(((imat3x3*)m)->x);
			free(m);
			return out;
		}
		else if (index == 1.0) {
			PyObject* out = build_ivec3(((imat3x3*)m)->y);
			free(m);
			return out;
		}
		PyObject* out = build_ivec3(((imat3x3*)m)->z);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT3x4) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec4(((imat3x4*)m)->x);
			free(m);
			return out;
		}
		else if (index == 1.0) {
			PyObject* out = build_ivec4(((imat3x4*)m)->y);
			free(m);
			return out;
		}
		PyObject* out = build_ivec4(((imat3x4*)m)->z);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT4x2) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) { 
			PyObject* out = build_ivec2(((imat4x2*)m)->x); 
			free(m);
			return out;
		}
		else if (index == 1.0) {
			PyObject* out = build_ivec2(((imat4x2*)m)->y);
			free(m);
			return out;
		}
		else if (index == 2.0) {
			PyObject* out = build_ivec2(((imat4x2*)m)->z);
			free(m);
			return out;
		}
		PyObject* out = build_ivec2(((imat4x2*)m)->w);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT4x3) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec3(((imat4x3*)m)->x);
			free(m);
			return out;
		}
		else if (index == 1.0) {
			PyObject* out = build_ivec3(((imat4x3*)m)->y);
			free(m);
			return out;
		}
		else if (index == 2.0) {
			PyObject* out = build_ivec3(((imat4x3*)m)->z);
			free(m);
			return out;
		}
		PyObject* out = build_ivec3(((imat4x3*)m)->w);
		free(m);
		return out;
	}
	if (matType == GLM_TMAT4x4) {
		if (!(index == 0.0 || index == 1.0 || index == 2.0 || index == 3.0)) {
			free(m);
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		if (index == 0.0) {
			PyObject* out = build_ivec4(((imat4x4*)m)->x);
			free(m);
			return out;
		}
		else if (index == 1.0) {
			PyObject* out = build_ivec4(((imat4x4*)m)->y);
			free(m);
			return out;
		}
		else if (index == 2.0) { 
			PyObject* out = build_ivec4(((imat4x4*)m)->z); 
			free(m);
			return out;
		}
		PyObject* out = build_ivec4(((imat4x4*)m)->w);
		free(m);
		return out;
	}
	PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for column()");
	return NULL;
}