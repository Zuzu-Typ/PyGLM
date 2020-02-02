#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

static PyObject*
row_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "row", 2, 3, &arg1, &arg2, &arg3) || !PyGLM_Number_Check(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for row()");
		return NULL;
	}
	glm::length_t index = PyGLM_Number_FromPyObject<glm::length_t>(arg2);
	if (index < 0) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (arg3 != NULL) {
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec<2, float> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec<3, float> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec<4, float> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, float> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::vec<2, double> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::vec<3, double> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::vec<4, double> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, double> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, int, arg3)) {
			glm::vec<2, int> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, int, arg3)) {
			glm::vec<3, int> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, int, arg3)) {
			glm::vec<4, int> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, int> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::uint, arg3)) {
			glm::vec<2, glm::uint> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::uint, arg3)) {
			glm::vec<3, glm::uint> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::uint, arg3)) {
			glm::vec<4, glm::uint> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::i64, arg3)) {
			glm::vec<2, glm::i64> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::i64, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::i64, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::i64, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::i64, arg3)) {
			glm::vec<3, glm::i64> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::i64, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::i64, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::i64, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::i64, arg3)) {
			glm::vec<4, glm::i64> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::i64, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::i64, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::i64, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::i64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::u64, arg3)) {
			glm::vec<2, glm::u64> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::u64, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::u64, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::u64, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::u64, arg3)) {
			glm::vec<3, glm::u64> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::u64, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::u64, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::u64, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::u64, arg3)) {
			glm::vec<4, glm::u64> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::u64, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::u64, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::u64, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::u64> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::i16, arg3)) {
			glm::vec<2, glm::i16> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::i16, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::i16, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::i16, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::i16, arg3)) {
			glm::vec<3, glm::i16> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::i16, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::i16, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::i16, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::i16, arg3)) {
			glm::vec<4, glm::i16> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::i16, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::i16, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::i16, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::i16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::u16, arg3)) {
			glm::vec<2, glm::u16> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::u16, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::u16, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::u16, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::u16, arg3)) {
			glm::vec<3, glm::u16> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::u16, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::u16, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::u16, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::u16, arg3)) {
			glm::vec<4, glm::u16> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::u16, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::u16, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::u16, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::u16> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::i8, arg3)) {
			glm::vec<2, glm::i8> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::i8, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::i8, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::i8, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::i8, arg3)) {
			glm::vec<3, glm::i8> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::i8, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::i8, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::i8, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::i8, arg3)) {
			glm::vec<4, glm::i8> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::i8, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::i8, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::i8, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::i8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::u8, arg3)) {
			glm::vec<2, glm::u8> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::u8, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, glm::u8, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, glm::u8, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::u8, arg3)) {
			glm::vec<3, glm::u8> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, glm::u8, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::u8, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::u8, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::u8, arg3)) {
			glm::vec<4, glm::u8> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, glm::u8, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::u8, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::u8, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::u8> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, bool, arg3)) {
			glm::vec<2, bool> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, bool, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 3, bool, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(2, 4, bool, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, bool, arg3)) {
			glm::vec<3, bool> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(3, 2, bool, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, bool, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, bool, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, bool, arg3)) {
			glm::vec<4, bool> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(4, 2, bool, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, bool, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, bool, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, bool> m;
				unpack_mat(arg1, m);
				return pack(glm::row(m, index, x));
			}
		}

	}
	else {
		if (PyGLM_Mat_Check(2, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, float> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, double> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, int> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::i64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::i64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::i64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::i64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::i64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::i64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::i64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::i64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::i64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::u64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::u64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::u64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::u64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::u64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::u64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::u64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::u64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::u64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::i16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::i16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::i16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::i16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::i16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::i16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::i16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::i16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::i16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::u16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::u16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::u16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::u16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::u16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::u16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::u16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::u16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::u16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::i8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::i8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::i8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::i8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::i8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::i8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::i8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::i8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::i8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, glm::u8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, glm::u8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, glm::u8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, glm::u8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, glm::u8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, glm::u8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, glm::u8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, glm::u8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, glm::u8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 2, bool, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 3, bool, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(2, 4, bool, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(3, 2, bool, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 3, bool, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(3, 4, bool, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_Check(4, 2, bool, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 3, bool, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_Check(4, 4, bool, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, bool> m;
			unpack_mat(arg1, m);
			return pack(glm::row(m, index));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for row()");
	return NULL;
}

static PyObject*
column_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "column", 2, 3, &arg1, &arg2, &arg3) || !PyGLM_Number_Check(arg2)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
		return NULL;
	}
	glm::length_t index = PyGLM_Number_FromPyObject<glm::length_t>(arg2);
	if (index < 0) {
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
	if (arg3 != NULL) {
		if (PyGLM_Vec_Check(2, float, arg3)) {
			glm::vec<2, float> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 2, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 2, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, float, arg3)) {
			glm::vec<3, float> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 3, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, float, arg3)) {
			glm::vec<4, float> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 4, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, float> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, double, arg3)) {
			glm::vec<2, double> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 2, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 2, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, double, arg3)) {
			glm::vec<3, double> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 3, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, double, arg3)) {
			glm::vec<4, double> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 4, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, double> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, int, arg3)) {
			glm::vec<2, int> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 2, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 2, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, int, arg3)) {
			glm::vec<3, int> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 3, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, int, arg3)) {
			glm::vec<4, int> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 4, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, int> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(2, glm::uint, arg3)) {
			glm::vec<2, glm::uint> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 2, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 2, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(3, glm::uint, arg3)) {
			glm::vec<3, glm::uint> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 3, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 3, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_Check(4, glm::uint, arg3)) {
			glm::vec<4, glm::uint> x;
			unpack_vec(arg3, x);
			if (PyGLM_Mat_Check(2, 4, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(3, 4, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_Check(4, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::uint> m;
				unpack_mat(arg1, m);
				return pack(glm::column(m, index, x));
			}
		}
	}
	else {
		if (PyGLM_Mat_Check(2, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, float> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, double> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, int> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::uint> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::i64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::i64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::i64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::i64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::i64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::i64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::i64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::i64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::i64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::i64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::u64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::u64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::u64, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::u64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::u64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::u64, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::u64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::u64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::u64, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::u64> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::i16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::i16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::i16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::i16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::i16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::i16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::i16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::i16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::i16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::i16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::u16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::u16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::u16, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::u16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::u16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::u16, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::u16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::u16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::u16, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::u16> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::i8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::i8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::i8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::i8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::i8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::i8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::i8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::i8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::i8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::i8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, glm::u8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, glm::u8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, glm::u8, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, glm::u8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, glm::u8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, glm::u8, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, glm::u8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, glm::u8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, glm::u8, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::u8> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 2, bool, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 3, bool, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(2, 4, bool, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(3, 2, bool, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 3, bool, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(3, 4, bool, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

		if (PyGLM_Mat_Check(4, 2, bool, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 3, bool, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}
		if (PyGLM_Mat_Check(4, 4, bool, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, bool> m;
			unpack_mat(arg1, m);
			return pack(m[index]);
		}

	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
	return NULL;
}

#define MATRIX_ACCESS_METHODS { "row", (PyCFunction)row_, METH_VARARGS, "row(m, index[, x]) -> vecn or matnxn\nGet a specific row of a matrix or set a specific row to a matrix." }, \
{ "column", (PyCFunction)column_, METH_VARARGS, "column(m, index[, x]) -> vecn or matnxn\nGet a specific column of a matrix or set a specific column to a matrix." }