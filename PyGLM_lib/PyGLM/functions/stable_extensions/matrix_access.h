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
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> x = PyGLM_Vec_PTI_Get2(2, float, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2xM | PyGLM_DT_FLOAT);
			if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, float> m = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, float> m = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, float> m = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> x = PyGLM_Vec_PTI_Get2(3, float, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3xM | PyGLM_DT_FLOAT);
			if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, float> m = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, float> m = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, float> m = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> x = PyGLM_Vec_PTI_Get2(4, float, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4xM | PyGLM_DT_FLOAT);
			if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, float> m = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, float> m = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, float> m = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> x = PyGLM_Vec_PTI_Get2(2, double, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2xM | PyGLM_DT_DOUBLE);
			if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, double> m = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, double> m = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, double> m = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> x = PyGLM_Vec_PTI_Get2(3, double, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3xM | PyGLM_DT_DOUBLE);
			if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, double> m = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, double> m = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, double> m = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> x = PyGLM_Vec_PTI_Get2(4, double, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4xM | PyGLM_DT_DOUBLE);
			if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, double> m = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, double> m = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, double> m = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(2, int, arg3)) {
			glm::vec<2, int> x = PyGLM_Vec_PTI_Get2(2, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2xM | PyGLM_DT_INT);
			if (PyGLM_Mat_PTI_Check0(2, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, int> m = PyGLM_Mat_PTI_Get0(2, 2, int, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, int> m = PyGLM_Mat_PTI_Get0(2, 3, int, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, int> m = PyGLM_Mat_PTI_Get0(2, 4, int, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, int, arg3)) {
			glm::vec<3, int> x = PyGLM_Vec_PTI_Get2(3, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3xM | PyGLM_DT_INT);
			if (PyGLM_Mat_PTI_Check0(3, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, int> m = PyGLM_Mat_PTI_Get0(3, 2, int, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, int> m = PyGLM_Mat_PTI_Get0(3, 3, int, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, int> m = PyGLM_Mat_PTI_Get0(3, 4, int, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, int, arg3)) {
			glm::vec<4, int> x = PyGLM_Vec_PTI_Get2(4, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4xM | PyGLM_DT_INT);
			if (PyGLM_Mat_PTI_Check0(4, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, int> m = PyGLM_Mat_PTI_Get0(4, 2, int, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, int> m = PyGLM_Mat_PTI_Get0(4, 3, int, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, int> m = PyGLM_Mat_PTI_Get0(4, 4, int, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(2, glm::uint, arg3)) {
			glm::vec<2, uint32> x = PyGLM_Vec_PTI_Get2(2, uint32, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2xM | PyGLM_DT_UINT);
			if (PyGLM_Mat_PTI_Check0(2, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, uint32> m = PyGLM_Mat_PTI_Get0(2, 2, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, uint32> m = PyGLM_Mat_PTI_Get0(2, 3, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(2, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, uint32> m = PyGLM_Mat_PTI_Get0(2, 4, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, glm::uint, arg3)) {
			glm::vec<3, uint32> x = PyGLM_Vec_PTI_Get2(3, uint32, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3xM | PyGLM_DT_UINT);
			if (PyGLM_Mat_PTI_Check0(3, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, uint32> m = PyGLM_Mat_PTI_Get0(3, 2, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, uint32> m = PyGLM_Mat_PTI_Get0(3, 3, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, uint32> m = PyGLM_Mat_PTI_Get0(3, 4, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, glm::uint, arg3)) {
			glm::vec<4, uint32> x = PyGLM_Vec_PTI_Get2(4, uint32, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4xM | PyGLM_DT_UINT);
			if (PyGLM_Mat_PTI_Check0(4, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, uint32> m = PyGLM_Mat_PTI_Get0(4, 2, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, uint32> m = PyGLM_Mat_PTI_Get0(4, 3, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, uint32> m = PyGLM_Mat_PTI_Get0(4, 4, uint32, arg1);
				return pack(glm::row(m, index, x));
			}
		}
		//if (PyGLM_Vec_PTI_Check2(2, glm::i64, arg3)) {
		//	glm::vec<2, int64> x = PyGLM_Vec_PTI_Get2(2, int64, arg3);
		//	if (PyGLM_Mat_Check(2, 2, glm::i64, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, glm::i64, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, glm::i64, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, glm::i64, arg3)) {
		//	glm::vec<3, int64> x = PyGLM_Vec_PTI_Get2(3, int64, arg3);
		//	if (PyGLM_Mat_Check(3, 2, glm::i64, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, glm::i64, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, glm::i64, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, glm::i64, arg3)) {
		//	glm::vec<4, int64> x = PyGLM_Vec_PTI_Get2(4, int64, arg3);
		//	if (PyGLM_Mat_Check(4, 2, glm::i64, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, glm::i64, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, glm::i64, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, glm::i64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(2, glm::u64, arg3)) {
		//	glm::vec<2, uint64> x = PyGLM_Vec_PTI_Get2(2, uint64, arg3);
		//	if (PyGLM_Mat_Check(2, 2, glm::u64, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, glm::u64, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, glm::u64, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, glm::u64, arg3)) {
		//	glm::vec<3, uint64> x = PyGLM_Vec_PTI_Get2(3, uint64, arg3);
		//	if (PyGLM_Mat_Check(3, 2, glm::u64, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, glm::u64, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, glm::u64, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, glm::u64, arg3)) {
		//	glm::vec<4, uint64> x = PyGLM_Vec_PTI_Get2(4, uint64, arg3);
		//	if (PyGLM_Mat_Check(4, 2, glm::u64, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, glm::u64, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, glm::u64, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, glm::u64> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(2, glm::i16, arg3)) {
		//	glm::vec<2, int16> x = PyGLM_Vec_PTI_Get2(2, int16, arg3);
		//	if (PyGLM_Mat_Check(2, 2, glm::i16, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, glm::i16, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, glm::i16, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, glm::i16, arg3)) {
		//	glm::vec<3, int16> x = PyGLM_Vec_PTI_Get2(3, int16, arg3);
		//	if (PyGLM_Mat_Check(3, 2, glm::i16, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, glm::i16, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, glm::i16, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, glm::i16, arg3)) {
		//	glm::vec<4, int16> x = PyGLM_Vec_PTI_Get2(4, int16, arg3);
		//	if (PyGLM_Mat_Check(4, 2, glm::i16, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, glm::i16, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, glm::i16, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, glm::i16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(2, glm::u16, arg3)) {
		//	glm::vec<2, uint16> x = PyGLM_Vec_PTI_Get2(2, uint16, arg3);
		//	if (PyGLM_Mat_Check(2, 2, glm::u16, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, glm::u16, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, glm::u16, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, glm::u16, arg3)) {
		//	glm::vec<3, uint16> x = PyGLM_Vec_PTI_Get2(3, uint16, arg3);
		//	if (PyGLM_Mat_Check(3, 2, glm::u16, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, glm::u16, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, glm::u16, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, glm::u16, arg3)) {
		//	glm::vec<4, uint16> x = PyGLM_Vec_PTI_Get2(4, uint16, arg3);
		//	if (PyGLM_Mat_Check(4, 2, glm::u16, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, glm::u16, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, glm::u16, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, glm::u16> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(2, glm::i8, arg3)) {
		//	glm::vec<2, int8> x = PyGLM_Vec_PTI_Get2(2, int8, arg3);
		//	if (PyGLM_Mat_Check(2, 2, glm::i8, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, glm::i8, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, glm::i8, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, glm::i8, arg3)) {
		//	glm::vec<3, int8> x = PyGLM_Vec_PTI_Get2(3, int8, arg3);
		//	if (PyGLM_Mat_Check(3, 2, glm::i8, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, glm::i8, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, glm::i8, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, glm::i8, arg3)) {
		//	glm::vec<4, int8> x = PyGLM_Vec_PTI_Get2(4, int8, arg3);
		//	if (PyGLM_Mat_Check(4, 2, glm::i8, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, glm::i8, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, glm::i8, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, glm::i8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(2, glm::u8, arg3)) {
		//	glm::vec<2, uint8> x = PyGLM_Vec_PTI_Get2(2, uint8, arg3);
		//	if (PyGLM_Mat_Check(2, 2, glm::u8, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, glm::u8, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, glm::u8, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, glm::u8, arg3)) {
		//	glm::vec<3, uint8> x = PyGLM_Vec_PTI_Get2(3, uint8, arg3);
		//	if (PyGLM_Mat_Check(3, 2, glm::u8, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, glm::u8, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, glm::u8, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, glm::u8, arg3)) {
		//	glm::vec<4, uint8> x = PyGLM_Vec_PTI_Get2(4, uint8, arg3);
		//	if (PyGLM_Mat_Check(4, 2, glm::u8, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, glm::u8, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, glm::u8, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, glm::u8> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
		//	glm::vec<2, bool> x = PyGLM_Vec_PTI_Get2(2, bool, arg3);
		//	if (PyGLM_Mat_Check(2, 2, bool, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 2, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 3, bool, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 3, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(2, 4, bool, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<2, 4, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
		//	glm::vec<3, bool> x = PyGLM_Vec_PTI_Get2(3, bool, arg3);
		//	if (PyGLM_Mat_Check(3, 2, bool, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 2, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 3, bool, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 3, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(3, 4, bool, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<3, 4, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}
		//if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
		//	glm::vec<4, bool> x = PyGLM_Vec_PTI_Get2(4, bool, arg3);
		//	if (PyGLM_Mat_Check(4, 2, bool, arg1)) {
		//		if (index > 1) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 2, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 3, bool, arg1)) {
		//		if (index > 2) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 3, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//	if (PyGLM_Mat_Check(4, 4, bool, arg1)) {
		//		if (index > 3) {
		//			PyErr_SetString(PyExc_IndexError, "index out of range");
		//			return NULL;
		//		}
		//		glm::mat<4, 4, bool> m;
		//		unpack_mat(arg1, m);
		//		return pack(glm::row(m, index, x));
		//	}
		//}

	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, float> m = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, float> m = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, float> m = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, float> m = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, float> m = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, float> m = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, float> m = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, float> m = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, float> m = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, double> m = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, double> m = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, double> m = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, double> m = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, double> m = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, double> m = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, double> m = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, double> m = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, double> m = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, int> m = PyGLM_Mat_PTI_Get0(2, 2, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, int> m = PyGLM_Mat_PTI_Get0(2, 3, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, int> m = PyGLM_Mat_PTI_Get0(2, 4, int, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, int> m = PyGLM_Mat_PTI_Get0(3, 2, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, int> m = PyGLM_Mat_PTI_Get0(3, 3, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, int> m = PyGLM_Mat_PTI_Get0(3, 4, int, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, int> m = PyGLM_Mat_PTI_Get0(4, 2, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, int> m = PyGLM_Mat_PTI_Get0(4, 3, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, int> m = PyGLM_Mat_PTI_Get0(4, 4, int, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 2, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 3, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 4, glm::uint, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 2, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 3, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 4, glm::uint, arg1);
			return pack(glm::row(m, index));
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 2, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 3, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 4, glm::uint, arg1);
			return pack(glm::row(m, index));
		}
		//if (PyGLM_Mat_Check(2, 2, glm::i64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::i64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::i64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::i64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::i64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::i64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::i64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::i64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::i64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::u64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::u64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::u64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::u64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::u64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::u64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::u64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::u64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::u64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::i16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::i16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::i16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::i16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::i16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::i16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::i16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::i16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::i16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::u16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::u16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::u16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::u16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::u16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::u16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::u16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::u16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::u16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::i8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::i8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::i8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::i8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::i8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::i8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::i8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::i8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::i8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::u8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::u8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::u8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::u8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::u8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::u8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::u8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::u8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::u8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 2, bool, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 3, bool, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(2, 4, bool, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(3, 2, bool, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 3, bool, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(3, 4, bool, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}

		//if (PyGLM_Mat_Check(4, 2, bool, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 3, bool, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
		//if (PyGLM_Mat_Check(4, 4, bool, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(glm::row(m, index));
		//}
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
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> x = PyGLM_Vec_PTI_Get2(2, float, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx2 | PyGLM_DT_FLOAT);
			if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, float> m = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, float> m = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, float> m = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> x = PyGLM_Vec_PTI_Get2(3, float, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx3 | PyGLM_DT_FLOAT);
			if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, float> m = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, float> m = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, float> m = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> x = PyGLM_Vec_PTI_Get2(4, float, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx4 | PyGLM_DT_FLOAT);
			if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, float> m = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, float> m = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, float> m = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> x = PyGLM_Vec_PTI_Get2(2, double, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx2 | PyGLM_DT_DOUBLE);
			if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, double> m = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, double> m = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, double> m = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> x = PyGLM_Vec_PTI_Get2(3, double, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx3 | PyGLM_DT_DOUBLE);
			if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, double> m = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, double> m = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, double> m = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> x = PyGLM_Vec_PTI_Get2(4, double, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx4 | PyGLM_DT_DOUBLE);
			if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, double> m = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, double> m = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, double> m = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(2, int, arg3)) {
			glm::vec<2, int> x = PyGLM_Vec_PTI_Get2(2, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx2 | PyGLM_DT_INT);
			if (PyGLM_Mat_PTI_Check0(2, 2, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, int> m = PyGLM_Mat_PTI_Get0(2, 2, int, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 2, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, int> m = PyGLM_Mat_PTI_Get0(3, 2, int, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 2, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, int> m = PyGLM_Mat_PTI_Get0(4, 2, int, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, int, arg3)) {
			glm::vec<3, int> x = PyGLM_Vec_PTI_Get2(3, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx3 | PyGLM_DT_INT);
			if (PyGLM_Mat_PTI_Check0(2, 3, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, int> m = PyGLM_Mat_PTI_Get0(2, 3, int, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, int> m = PyGLM_Mat_PTI_Get0(3, 3, int, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, int> m = PyGLM_Mat_PTI_Get0(4, 3, int, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, int, arg3)) {
			glm::vec<4, int> x = PyGLM_Vec_PTI_Get2(4, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx4 | PyGLM_DT_INT);
			if (PyGLM_Mat_PTI_Check0(2, 4, int, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, int> m = PyGLM_Mat_PTI_Get0(2, 4, int, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, int, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, int> m = PyGLM_Mat_PTI_Get0(3, 4, int, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, int> m = PyGLM_Mat_PTI_Get0(4, 4, int, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(2, glm::uint, arg3)) {
			glm::vec<2, glm::uint> x = PyGLM_Vec_PTI_Get2(2, glm::uint, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx2 | PyGLM_DT_UINT);
			if (PyGLM_Mat_PTI_Check0(2, 2, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 2, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 2, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 2, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 2, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 2, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(3, glm::uint, arg3)) {
			glm::vec<3, glm::uint> x = PyGLM_Vec_PTI_Get2(3, glm::uint, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx3 | PyGLM_DT_UINT);
			if (PyGLM_Mat_PTI_Check0(2, 3, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 3, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 3, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 3, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 3, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 3, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
		}
		if (PyGLM_Vec_PTI_Check2(4, glm::uint, arg3)) {
			glm::vec<4, glm::uint> x = PyGLM_Vec_PTI_Get2(4, glm::uint, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_Nx4 | PyGLM_DT_UINT);
			if (PyGLM_Mat_PTI_Check0(2, 4, glm::uint, arg1)) {
				if (index > 1) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<2, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 4, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(3, 4, glm::uint, arg1)) {
				if (index > 2) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<3, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 4, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
			if (PyGLM_Mat_PTI_Check0(4, 4, glm::uint, arg1)) {
				if (index > 3) {
					PyErr_SetString(PyExc_IndexError, "index out of range");
					return NULL;
				}
				glm::mat<4, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 4, glm::uint, arg1);
				return pack(glm::column(m, index, x));
			}
		}
	}
	else {
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, float> m = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, float> m = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, float> m = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, float> m = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, float> m = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, float> m = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, float> m = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, float> m = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, float> m = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, double> m = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, double> m = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, double> m = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, double> m = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, double> m = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, double> m = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, double> m = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, double> m = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, double> m = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, int> m = PyGLM_Mat_PTI_Get0(2, 2, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, int> m = PyGLM_Mat_PTI_Get0(2, 3, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, int, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, int> m = PyGLM_Mat_PTI_Get0(2, 4, int, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, int> m = PyGLM_Mat_PTI_Get0(3, 2, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, int> m = PyGLM_Mat_PTI_Get0(3, 3, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, int, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, int> m = PyGLM_Mat_PTI_Get0(3, 4, int, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, int> m = PyGLM_Mat_PTI_Get0(4, 2, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, int> m = PyGLM_Mat_PTI_Get0(4, 3, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, int> m = PyGLM_Mat_PTI_Get0(4, 4, int, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 2, glm::uint, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 3, glm::uint, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, glm::uint, arg1)) {
			if (index > 1) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<2, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(2, 4, glm::uint, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 2, glm::uint, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 3, glm::uint, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, glm::uint, arg1)) {
			if (index > 2) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<3, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(3, 4, glm::uint, arg1);
			return pack(m[index]);
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 2, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 2, glm::uint, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 3, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 3, glm::uint, arg1);
			return pack(m[index]);
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, glm::uint, arg1)) {
			if (index > 3) {
				PyErr_SetString(PyExc_IndexError, "index out of range");
				return NULL;
			}
			glm::mat<4, 4, glm::uint> m = PyGLM_Mat_PTI_Get0(4, 4, glm::uint, arg1);
			return pack(m[index]);
		}
		//if (PyGLM_Mat_Check(2, 2, glm::i64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::i64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::i64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::i64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::i64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::i64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::i64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::i64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::i64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::i64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::u64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::u64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::u64, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::u64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::u64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::u64, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::u64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::u64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::u64, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::u64> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::i16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::i16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::i16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::i16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::i16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::i16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::i16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::i16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::i16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::i16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::u16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::u16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::u16, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::u16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::u16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::u16, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::u16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::u16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::u16, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::u16> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::i8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::i8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::i8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::i8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::i8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::i8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::i8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::i8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::i8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::i8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::u8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::u8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::u8, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, glm::u8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::u8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::u8, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, glm::u8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::u8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::u8, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, glm::u8> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 2, bool, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 2, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 3, bool, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 3, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(2, 4, bool, arg1)) {
		//	if (index > 1) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<2, 4, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(3, 2, bool, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 2, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 3, bool, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 3, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(3, 4, bool, arg1)) {
		//	if (index > 2) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<3, 4, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

		//if (PyGLM_Mat_Check(4, 2, bool, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 2, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 3, bool, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 3, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}
		//if (PyGLM_Mat_Check(4, 4, bool, arg1)) {
		//	if (index > 3) {
		//		PyErr_SetString(PyExc_IndexError, "index out of range");
		//		return NULL;
		//	}
		//	glm::mat<4, 4, bool> m;
		//	unpack_mat(arg1, m);
		//	return pack(m[index]);
		//}

	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for column()");
	return NULL;
}

PyDoc_STRVAR(row_docstr,
	"row(m: matNxM, index: int) -> vecN\n"
	"	Get a specific row of a matrix.\n"
	"row(m: matNxM, index: int, x: vecN) -> matNxM\n"
	"	Set a specific row to a matrix."
);
PyDoc_STRVAR(column_docstr,
	"column(m: matNxM, index: int) -> vecM\n"
	"	Get a specific column of a matrix.\n"
	"column(m: matNxM, index: int, x: vecM) -> matNxM\n"
	"	Set a specific column to a matrix."
);

#define MATRIX_ACCESS_METHODS \
{ "row", (PyCFunction)row_, METH_VARARGS, row_docstr }, \
{ "column", (PyCFunction)column_, METH_VARARGS, column_docstr }
