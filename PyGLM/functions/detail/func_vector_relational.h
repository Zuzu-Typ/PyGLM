#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

static PyObject*
equal(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "equal", 2, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg3 == NULL) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			glm::vec<1, int> o = PyGLM_Vec_PTI_Get0(1, int, arg1);
			glm::vec<1, int> o2 = PyGLM_Vec_PTI_Get1(1, int, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2)) {
			glm::vec<1, glm::uint> o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
			glm::vec<1, glm::uint> o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2)) {
			glm::vec<1, glm::i64> o = PyGLM_Vec_PTI_Get0(1, glm::i64, arg1);
			glm::vec<1, glm::i64> o2 = PyGLM_Vec_PTI_Get1(1, glm::i64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2)) {
			glm::vec<1, glm::u64> o = PyGLM_Vec_PTI_Get0(1, glm::u64, arg1);
			glm::vec<1, glm::u64> o2 = PyGLM_Vec_PTI_Get1(1, glm::u64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2)) {
			glm::vec<1, glm::i16> o = PyGLM_Vec_PTI_Get0(1, glm::i16, arg1);
			glm::vec<1, glm::i16> o2 = PyGLM_Vec_PTI_Get1(1, glm::i16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2)) {
			glm::vec<1, glm::u16> o = PyGLM_Vec_PTI_Get0(1, glm::u16, arg1);
			glm::vec<1, glm::u16> o2 = PyGLM_Vec_PTI_Get1(1, glm::u16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2)) {
			glm::vec<1, glm::i8> o = PyGLM_Vec_PTI_Get0(1, glm::i8, arg1);
			glm::vec<1, glm::i8> o2 = PyGLM_Vec_PTI_Get1(1, glm::i8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2)) {
			glm::vec<1, glm::u8> o = PyGLM_Vec_PTI_Get0(1, glm::u8, arg1);
			glm::vec<1, glm::u8> o2 = PyGLM_Vec_PTI_Get1(1, glm::u8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {
			glm::vec<1, bool> o = PyGLM_Vec_PTI_Get0(1, bool, arg1);
			glm::vec<1, bool> o2 = PyGLM_Vec_PTI_Get1(1, bool, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			glm::vec<2, int> o = PyGLM_Vec_PTI_Get0(2, int, arg1);
			glm::vec<2, int> o2 = PyGLM_Vec_PTI_Get1(2, int, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2)) {
			glm::vec<2, glm::uint> o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
			glm::vec<2, glm::uint> o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2)) {
			glm::vec<2, glm::i64> o = PyGLM_Vec_PTI_Get0(2, glm::i64, arg1);
			glm::vec<2, glm::i64> o2 = PyGLM_Vec_PTI_Get1(2, glm::i64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2)) {
			glm::vec<2, glm::u64> o = PyGLM_Vec_PTI_Get0(2, glm::u64, arg1);
			glm::vec<2, glm::u64> o2 = PyGLM_Vec_PTI_Get1(2, glm::u64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2)) {
			glm::vec<2, glm::i16> o = PyGLM_Vec_PTI_Get0(2, glm::i16, arg1);
			glm::vec<2, glm::i16> o2 = PyGLM_Vec_PTI_Get1(2, glm::i16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2)) {
			glm::vec<2, glm::u16> o = PyGLM_Vec_PTI_Get0(2, glm::u16, arg1);
			glm::vec<2, glm::u16> o2 = PyGLM_Vec_PTI_Get1(2, glm::u16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2)) {
			glm::vec<2, glm::i8> o = PyGLM_Vec_PTI_Get0(2, glm::i8, arg1);
			glm::vec<2, glm::i8> o2 = PyGLM_Vec_PTI_Get1(2, glm::i8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2)) {
			glm::vec<2, glm::u8> o = PyGLM_Vec_PTI_Get0(2, glm::u8, arg1);
			glm::vec<2, glm::u8> o2 = PyGLM_Vec_PTI_Get1(2, glm::u8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {
			glm::vec<2, bool> o = PyGLM_Vec_PTI_Get0(2, bool, arg1);
			glm::vec<2, bool> o2 = PyGLM_Vec_PTI_Get1(2, bool, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			glm::vec<3, int> o = PyGLM_Vec_PTI_Get0(3, int, arg1);
			glm::vec<3, int> o2 = PyGLM_Vec_PTI_Get1(3, int, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2)) {
			glm::vec<3, glm::uint> o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
			glm::vec<3, glm::uint> o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2)) {
			glm::vec<3, glm::i64> o = PyGLM_Vec_PTI_Get0(3, glm::i64, arg1);
			glm::vec<3, glm::i64> o2 = PyGLM_Vec_PTI_Get1(3, glm::i64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2)) {
			glm::vec<3, glm::u64> o = PyGLM_Vec_PTI_Get0(3, glm::u64, arg1);
			glm::vec<3, glm::u64> o2 = PyGLM_Vec_PTI_Get1(3, glm::u64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2)) {
			glm::vec<3, glm::i16> o = PyGLM_Vec_PTI_Get0(3, glm::i16, arg1);
			glm::vec<3, glm::i16> o2 = PyGLM_Vec_PTI_Get1(3, glm::i16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2)) {
			glm::vec<3, glm::u16> o = PyGLM_Vec_PTI_Get0(3, glm::u16, arg1);
			glm::vec<3, glm::u16> o2 = PyGLM_Vec_PTI_Get1(3, glm::u16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2)) {
			glm::vec<3, glm::i8> o = PyGLM_Vec_PTI_Get0(3, glm::i8, arg1);
			glm::vec<3, glm::i8> o2 = PyGLM_Vec_PTI_Get1(3, glm::i8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2)) {
			glm::vec<3, glm::u8> o = PyGLM_Vec_PTI_Get0(3, glm::u8, arg1);
			glm::vec<3, glm::u8> o2 = PyGLM_Vec_PTI_Get1(3, glm::u8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {
			glm::vec<3, bool> o = PyGLM_Vec_PTI_Get0(3, bool, arg1);
			glm::vec<3, bool> o2 = PyGLM_Vec_PTI_Get1(3, bool, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			glm::vec<4, int> o = PyGLM_Vec_PTI_Get0(4, int, arg1);
			glm::vec<4, int> o2 = PyGLM_Vec_PTI_Get1(4, int, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2)) {
			glm::vec<4, glm::uint> o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
			glm::vec<4, glm::uint> o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2)) {
			glm::vec<4, glm::i64> o = PyGLM_Vec_PTI_Get0(4, glm::i64, arg1);
			glm::vec<4, glm::i64> o2 = PyGLM_Vec_PTI_Get1(4, glm::i64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2)) {
			glm::vec<4, glm::u64> o = PyGLM_Vec_PTI_Get0(4, glm::u64, arg1);
			glm::vec<4, glm::u64> o2 = PyGLM_Vec_PTI_Get1(4, glm::u64, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2)) {
			glm::vec<4, glm::i16> o = PyGLM_Vec_PTI_Get0(4, glm::i16, arg1);
			glm::vec<4, glm::i16> o2 = PyGLM_Vec_PTI_Get1(4, glm::i16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2)) {
			glm::vec<4, glm::u16> o = PyGLM_Vec_PTI_Get0(4, glm::u16, arg1);
			glm::vec<4, glm::u16> o2 = PyGLM_Vec_PTI_Get1(4, glm::u16, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2)) {
			glm::vec<4, glm::i8> o = PyGLM_Vec_PTI_Get0(4, glm::i8, arg1);
			glm::vec<4, glm::i8> o2 = PyGLM_Vec_PTI_Get1(4, glm::i8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2)) {
			glm::vec<4, glm::u8> o = PyGLM_Vec_PTI_Get0(4, glm::u8, arg1);
			glm::vec<4, glm::u8> o2 = PyGLM_Vec_PTI_Get1(4, glm::u8, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {
			glm::vec<4, bool> o = PyGLM_Vec_PTI_Get0(4, bool, arg1);
			glm::vec<4, bool> o2 = PyGLM_Vec_PTI_Get1(4, bool, arg2);
			return pack(glm::equal(o, o2));
		}

		//if (PyGLM_Mat_Check(2, 2, float, arg1) && PyGLM_Mat_Check(2, 2, float, arg2)) {
		//	glm::mat<2, 2, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 2, double, arg1) && PyGLM_Mat_Check(2, 2, double, arg2)) {
		//	glm::mat<2, 2, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 2, int, arg1) && PyGLM_Mat_Check(2, 2, int, arg2)) {
		//	glm::mat<2, 2, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::uint, arg1) && PyGLM_Mat_Check(2, 2, glm::uint, arg2)) {
		//	glm::mat<2, 2, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, float, arg1) && PyGLM_Mat_Check(2, 3, float, arg2)) {
		//	glm::mat<2, 3, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, double, arg1) && PyGLM_Mat_Check(2, 3, double, arg2)) {
		//	glm::mat<2, 3, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, int, arg1) && PyGLM_Mat_Check(2, 3, int, arg2)) {
		//	glm::mat<2, 3, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::uint, arg1) && PyGLM_Mat_Check(2, 3, glm::uint, arg2)) {
		//	glm::mat<2, 3, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, float, arg1) && PyGLM_Mat_Check(2, 4, float, arg2)) {
		//	glm::mat<2, 4, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, double, arg1) && PyGLM_Mat_Check(2, 4, double, arg2)) {
		//	glm::mat<2, 4, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, int, arg1) && PyGLM_Mat_Check(2, 4, int, arg2)) {
		//	glm::mat<2, 4, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::uint, arg1) && PyGLM_Mat_Check(2, 4, glm::uint, arg2)) {
		//	glm::mat<2, 4, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, float, arg1) && PyGLM_Mat_Check(3, 2, float, arg2)) {
		//	glm::mat<3, 2, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, double, arg1) && PyGLM_Mat_Check(3, 2, double, arg2)) {
		//	glm::mat<3, 2, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, int, arg1) && PyGLM_Mat_Check(3, 2, int, arg2)) {
		//	glm::mat<3, 2, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, glm::uint, arg1) && PyGLM_Mat_Check(3, 2, glm::uint, arg2)) {
		//	glm::mat<3, 2, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, float, arg1) && PyGLM_Mat_Check(3, 3, float, arg2)) {
		//	glm::mat<3, 3, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, double, arg1) && PyGLM_Mat_Check(3, 3, double, arg2)) {
		//	glm::mat<3, 3, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, int, arg1) && PyGLM_Mat_Check(3, 3, int, arg2)) {
		//	glm::mat<3, 3, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::uint, arg1) && PyGLM_Mat_Check(3, 3, glm::uint, arg2)) {
		//	glm::mat<3, 3, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, float, arg1) && PyGLM_Mat_Check(3, 4, float, arg2)) {
		//	glm::mat<3, 4, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, double, arg1) && PyGLM_Mat_Check(3, 4, double, arg2)) {
		//	glm::mat<3, 4, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, int, arg1) && PyGLM_Mat_Check(3, 4, int, arg2)) {
		//	glm::mat<3, 4, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::uint, arg1) && PyGLM_Mat_Check(3, 4, glm::uint, arg2)) {
		//	glm::mat<3, 4, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, float, arg1) && PyGLM_Mat_Check(4, 2, float, arg2)) {
		//	glm::mat<4, 2, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, double, arg1) && PyGLM_Mat_Check(4, 2, double, arg2)) {
		//	glm::mat<4, 2, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, int, arg1) && PyGLM_Mat_Check(4, 2, int, arg2)) {
		//	glm::mat<4, 2, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, glm::uint, arg1) && PyGLM_Mat_Check(4, 2, glm::uint, arg2)) {
		//	glm::mat<4, 2, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, float, arg1) && PyGLM_Mat_Check(4, 3, float, arg2)) {
		//	glm::mat<4, 3, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, double, arg1) && PyGLM_Mat_Check(4, 3, double, arg2)) {
		//	glm::mat<4, 3, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, int, arg1) && PyGLM_Mat_Check(4, 3, int, arg2)) {
		//	glm::mat<4, 3, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::uint, arg1) && PyGLM_Mat_Check(4, 3, glm::uint, arg2)) {
		//	glm::mat<4, 3, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2)) {
		//	glm::mat<4, 4, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2)) {
		//	glm::mat<4, 4, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, int, arg1) && PyGLM_Mat_Check(4, 4, int, arg2)) {
		//	glm::mat<4, 4, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::uint, arg1) && PyGLM_Mat_Check(4, 4, glm::uint, arg2)) {
		//	glm::mat<4, 4, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::equal(o, o2));
		//}

		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
			return pack(glm::equal(o, o2));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
			glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
			return pack(glm::equal(o, o2));
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for equal(): ", arg1, arg2);
		return NULL;
	}
	if (PyLong_Check(arg3)) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::equal(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}

		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}

	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			pack(glm::equal(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_NxM | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_NxM | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}

		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}

		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
			glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
			return pack(glm::equal(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_INT | PyGLM_DT_FD)
	if (PyGLM_Vec_PTI_Check2(2, int, arg3)) {
		glm::vec<2, int> o3 = PyGLM_Vec_PTI_Get2(2, int, arg3);
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_2 | PyGLM_SHAPE_2xM | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_2 | PyGLM_SHAPE_2xM | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}

		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}

	if (PyGLM_Vec_PTI_Check2(3, int, arg3)) {
		glm::vec<3, int> o3 = PyGLM_Vec_PTI_Get2(3, int, arg3);
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_3 | PyGLM_SHAPE_3xM | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_3 | PyGLM_SHAPE_3xM | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}

	if (PyGLM_Vec_PTI_Check2(4, int, arg3)) {
		glm::vec<4, int> o3 = PyGLM_Vec_PTI_Get2(4, int, arg3);
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_4 | PyGLM_SHAPE_4xM | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_4 | PyGLM_SHAPE_4xM | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}

	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);

	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
		glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
		glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
		return pack(glm::equal(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
		return pack(glm::equal(o, o2, o3));
	}

	if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
		glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
		glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
		glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
		glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::equal(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
		return NULL;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for equal()");
	return NULL;
}

static PyObject*
notEqual(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL;
	if (!PyArg_UnpackTuple(args, "notEqual", 2, 3, &arg1, &arg2, &arg3)) return NULL;
	if (arg3 == NULL) {
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_QUA | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			glm::vec<1, int> o = PyGLM_Vec_PTI_Get0(1, int, arg1);
			glm::vec<1, int> o2 = PyGLM_Vec_PTI_Get1(1, int, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2)) {
			glm::vec<1, glm::uint> o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
			glm::vec<1, glm::uint> o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2)) {
			glm::vec<1, glm::i64> o = PyGLM_Vec_PTI_Get0(1, glm::i64, arg1);
			glm::vec<1, glm::i64> o2 = PyGLM_Vec_PTI_Get1(1, glm::i64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2)) {
			glm::vec<1, glm::u64> o = PyGLM_Vec_PTI_Get0(1, glm::u64, arg1);
			glm::vec<1, glm::u64> o2 = PyGLM_Vec_PTI_Get1(1, glm::u64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2)) {
			glm::vec<1, glm::i16> o = PyGLM_Vec_PTI_Get0(1, glm::i16, arg1);
			glm::vec<1, glm::i16> o2 = PyGLM_Vec_PTI_Get1(1, glm::i16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2)) {
			glm::vec<1, glm::u16> o = PyGLM_Vec_PTI_Get0(1, glm::u16, arg1);
			glm::vec<1, glm::u16> o2 = PyGLM_Vec_PTI_Get1(1, glm::u16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2)) {
			glm::vec<1, glm::i8> o = PyGLM_Vec_PTI_Get0(1, glm::i8, arg1);
			glm::vec<1, glm::i8> o2 = PyGLM_Vec_PTI_Get1(1, glm::i8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2)) {
			glm::vec<1, glm::u8> o = PyGLM_Vec_PTI_Get0(1, glm::u8, arg1);
			glm::vec<1, glm::u8> o2 = PyGLM_Vec_PTI_Get1(1, glm::u8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {
			glm::vec<1, bool> o = PyGLM_Vec_PTI_Get0(1, bool, arg1);
			glm::vec<1, bool> o2 = PyGLM_Vec_PTI_Get1(1, bool, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			glm::vec<2, int> o = PyGLM_Vec_PTI_Get0(2, int, arg1);
			glm::vec<2, int> o2 = PyGLM_Vec_PTI_Get1(2, int, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2)) {
			glm::vec<2, glm::uint> o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
			glm::vec<2, glm::uint> o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2)) {
			glm::vec<2, glm::i64> o = PyGLM_Vec_PTI_Get0(2, glm::i64, arg1);
			glm::vec<2, glm::i64> o2 = PyGLM_Vec_PTI_Get1(2, glm::i64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2)) {
			glm::vec<2, glm::u64> o = PyGLM_Vec_PTI_Get0(2, glm::u64, arg1);
			glm::vec<2, glm::u64> o2 = PyGLM_Vec_PTI_Get1(2, glm::u64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2)) {
			glm::vec<2, glm::i16> o = PyGLM_Vec_PTI_Get0(2, glm::i16, arg1);
			glm::vec<2, glm::i16> o2 = PyGLM_Vec_PTI_Get1(2, glm::i16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2)) {
			glm::vec<2, glm::u16> o = PyGLM_Vec_PTI_Get0(2, glm::u16, arg1);
			glm::vec<2, glm::u16> o2 = PyGLM_Vec_PTI_Get1(2, glm::u16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2)) {
			glm::vec<2, glm::i8> o = PyGLM_Vec_PTI_Get0(2, glm::i8, arg1);
			glm::vec<2, glm::i8> o2 = PyGLM_Vec_PTI_Get1(2, glm::i8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2)) {
			glm::vec<2, glm::u8> o = PyGLM_Vec_PTI_Get0(2, glm::u8, arg1);
			glm::vec<2, glm::u8> o2 = PyGLM_Vec_PTI_Get1(2, glm::u8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {
			glm::vec<2, bool> o = PyGLM_Vec_PTI_Get0(2, bool, arg1);
			glm::vec<2, bool> o2 = PyGLM_Vec_PTI_Get1(2, bool, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			glm::vec<3, int> o = PyGLM_Vec_PTI_Get0(3, int, arg1);
			glm::vec<3, int> o2 = PyGLM_Vec_PTI_Get1(3, int, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2)) {
			glm::vec<3, glm::uint> o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
			glm::vec<3, glm::uint> o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2)) {
			glm::vec<3, glm::i64> o = PyGLM_Vec_PTI_Get0(3, glm::i64, arg1);
			glm::vec<3, glm::i64> o2 = PyGLM_Vec_PTI_Get1(3, glm::i64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2)) {
			glm::vec<3, glm::u64> o = PyGLM_Vec_PTI_Get0(3, glm::u64, arg1);
			glm::vec<3, glm::u64> o2 = PyGLM_Vec_PTI_Get1(3, glm::u64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2)) {
			glm::vec<3, glm::i16> o = PyGLM_Vec_PTI_Get0(3, glm::i16, arg1);
			glm::vec<3, glm::i16> o2 = PyGLM_Vec_PTI_Get1(3, glm::i16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2)) {
			glm::vec<3, glm::u16> o = PyGLM_Vec_PTI_Get0(3, glm::u16, arg1);
			glm::vec<3, glm::u16> o2 = PyGLM_Vec_PTI_Get1(3, glm::u16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2)) {
			glm::vec<3, glm::i8> o = PyGLM_Vec_PTI_Get0(3, glm::i8, arg1);
			glm::vec<3, glm::i8> o2 = PyGLM_Vec_PTI_Get1(3, glm::i8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2)) {
			glm::vec<3, glm::u8> o = PyGLM_Vec_PTI_Get0(3, glm::u8, arg1);
			glm::vec<3, glm::u8> o2 = PyGLM_Vec_PTI_Get1(3, glm::u8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {
			glm::vec<3, bool> o = PyGLM_Vec_PTI_Get0(3, bool, arg1);
			glm::vec<3, bool> o2 = PyGLM_Vec_PTI_Get1(3, bool, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			glm::vec<4, int> o = PyGLM_Vec_PTI_Get0(4, int, arg1);
			glm::vec<4, int> o2 = PyGLM_Vec_PTI_Get1(4, int, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2)) {
			glm::vec<4, glm::uint> o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
			glm::vec<4, glm::uint> o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2)) {
			glm::vec<4, glm::i64> o = PyGLM_Vec_PTI_Get0(4, glm::i64, arg1);
			glm::vec<4, glm::i64> o2 = PyGLM_Vec_PTI_Get1(4, glm::i64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2)) {
			glm::vec<4, glm::u64> o = PyGLM_Vec_PTI_Get0(4, glm::u64, arg1);
			glm::vec<4, glm::u64> o2 = PyGLM_Vec_PTI_Get1(4, glm::u64, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2)) {
			glm::vec<4, glm::i16> o = PyGLM_Vec_PTI_Get0(4, glm::i16, arg1);
			glm::vec<4, glm::i16> o2 = PyGLM_Vec_PTI_Get1(4, glm::i16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2)) {
			glm::vec<4, glm::u16> o = PyGLM_Vec_PTI_Get0(4, glm::u16, arg1);
			glm::vec<4, glm::u16> o2 = PyGLM_Vec_PTI_Get1(4, glm::u16, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2)) {
			glm::vec<4, glm::i8> o = PyGLM_Vec_PTI_Get0(4, glm::i8, arg1);
			glm::vec<4, glm::i8> o2 = PyGLM_Vec_PTI_Get1(4, glm::i8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2)) {
			glm::vec<4, glm::u8> o = PyGLM_Vec_PTI_Get0(4, glm::u8, arg1);
			glm::vec<4, glm::u8> o2 = PyGLM_Vec_PTI_Get1(4, glm::u8, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {
			glm::vec<4, bool> o = PyGLM_Vec_PTI_Get0(4, bool, arg1);
			glm::vec<4, bool> o2 = PyGLM_Vec_PTI_Get1(4, bool, arg2);
			return pack(glm::notEqual(o, o2));
		}

		//if (PyGLM_Mat_Check(2, 2, float, arg1) && PyGLM_Mat_Check(2, 2, float, arg2)) {
		//	glm::mat<2, 2, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 2, double, arg1) && PyGLM_Mat_Check(2, 2, double, arg2)) {
		//	glm::mat<2, 2, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 2, int, arg1) && PyGLM_Mat_Check(2, 2, int, arg2)) {
		//	glm::mat<2, 2, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 2, glm::uint, arg1) && PyGLM_Mat_Check(2, 2, glm::uint, arg2)) {
		//	glm::mat<2, 2, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, float, arg1) && PyGLM_Mat_Check(2, 3, float, arg2)) {
		//	glm::mat<2, 3, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, double, arg1) && PyGLM_Mat_Check(2, 3, double, arg2)) {
		//	glm::mat<2, 3, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, int, arg1) && PyGLM_Mat_Check(2, 3, int, arg2)) {
		//	glm::mat<2, 3, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 3, glm::uint, arg1) && PyGLM_Mat_Check(2, 3, glm::uint, arg2)) {
		//	glm::mat<2, 3, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, float, arg1) && PyGLM_Mat_Check(2, 4, float, arg2)) {
		//	glm::mat<2, 4, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, double, arg1) && PyGLM_Mat_Check(2, 4, double, arg2)) {
		//	glm::mat<2, 4, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, int, arg1) && PyGLM_Mat_Check(2, 4, int, arg2)) {
		//	glm::mat<2, 4, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(2, 4, glm::uint, arg1) && PyGLM_Mat_Check(2, 4, glm::uint, arg2)) {
		//	glm::mat<2, 4, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, float, arg1) && PyGLM_Mat_Check(3, 2, float, arg2)) {
		//	glm::mat<3, 2, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, double, arg1) && PyGLM_Mat_Check(3, 2, double, arg2)) {
		//	glm::mat<3, 2, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, int, arg1) && PyGLM_Mat_Check(3, 2, int, arg2)) {
		//	glm::mat<3, 2, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 2, glm::uint, arg1) && PyGLM_Mat_Check(3, 2, glm::uint, arg2)) {
		//	glm::mat<3, 2, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, float, arg1) && PyGLM_Mat_Check(3, 3, float, arg2)) {
		//	glm::mat<3, 3, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, double, arg1) && PyGLM_Mat_Check(3, 3, double, arg2)) {
		//	glm::mat<3, 3, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, int, arg1) && PyGLM_Mat_Check(3, 3, int, arg2)) {
		//	glm::mat<3, 3, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 3, glm::uint, arg1) && PyGLM_Mat_Check(3, 3, glm::uint, arg2)) {
		//	glm::mat<3, 3, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, float, arg1) && PyGLM_Mat_Check(3, 4, float, arg2)) {
		//	glm::mat<3, 4, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, double, arg1) && PyGLM_Mat_Check(3, 4, double, arg2)) {
		//	glm::mat<3, 4, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, int, arg1) && PyGLM_Mat_Check(3, 4, int, arg2)) {
		//	glm::mat<3, 4, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(3, 4, glm::uint, arg1) && PyGLM_Mat_Check(3, 4, glm::uint, arg2)) {
		//	glm::mat<3, 4, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, float, arg1) && PyGLM_Mat_Check(4, 2, float, arg2)) {
		//	glm::mat<4, 2, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, double, arg1) && PyGLM_Mat_Check(4, 2, double, arg2)) {
		//	glm::mat<4, 2, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, int, arg1) && PyGLM_Mat_Check(4, 2, int, arg2)) {
		//	glm::mat<4, 2, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 2, glm::uint, arg1) && PyGLM_Mat_Check(4, 2, glm::uint, arg2)) {
		//	glm::mat<4, 2, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, float, arg1) && PyGLM_Mat_Check(4, 3, float, arg2)) {
		//	glm::mat<4, 3, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, double, arg1) && PyGLM_Mat_Check(4, 3, double, arg2)) {
		//	glm::mat<4, 3, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, int, arg1) && PyGLM_Mat_Check(4, 3, int, arg2)) {
		//	glm::mat<4, 3, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 3, glm::uint, arg1) && PyGLM_Mat_Check(4, 3, glm::uint, arg2)) {
		//	glm::mat<4, 3, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, float, arg1) && PyGLM_Mat_Check(4, 4, float, arg2)) {
		//	glm::mat<4, 4, float> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, double, arg1) && PyGLM_Mat_Check(4, 4, double, arg2)) {
		//	glm::mat<4, 4, double> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, int, arg1) && PyGLM_Mat_Check(4, 4, int, arg2)) {
		//	glm::mat<4, 4, int> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}
		//if (PyGLM_Mat_Check(4, 4, glm::uint, arg1) && PyGLM_Mat_Check(4, 4, glm::uint, arg2)) {
		//	glm::mat<4, 4, glm::uint> o, o2;
		//	unpack_mat(arg1, o);
		//	unpack_mat(arg2, o2);
		//	return pack(glm::notEqual(o, o2));
		//}

		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
			return pack(glm::notEqual(o, o2));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
			glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
			return pack(glm::notEqual(o, o2));
		}
		PyGLM_TYPEERROR_2O("invalid argument type(s) for notEqual(): ", arg1, arg2);
		return NULL;
	}
	if (PyLong_Check(arg3)) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::notEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}

		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<int>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}

	if (PyGLM_Number_Check(arg3)) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			pack(glm::notEqual(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_NxM | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_T_QUA | PyGLM_SHAPE_NxM | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}

		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}

		if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2)) {
			glm::qua<float> o = PyGLM_Qua_PTI_Get0(float, arg1);
			glm::qua<float> o2 = PyGLM_Qua_PTI_Get1(float, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
		}
		if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2)) {
			glm::qua<double> o = PyGLM_Qua_PTI_Get0(double, arg1);
			glm::qua<double> o2 = PyGLM_Qua_PTI_Get1(double, arg2);
			return pack(glm::notEqual(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_DT_INT | PyGLM_DT_FD)
		if (PyGLM_Vec_PTI_Check2(2, int, arg3)) {
			glm::vec<2, int> o3 = PyGLM_Vec_PTI_Get2(2, int, arg3);
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_2 | PyGLM_SHAPE_2xM | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_2 | PyGLM_SHAPE_2xM | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
				glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
				glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
				glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
				glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}

			if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
				glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
				glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
				glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
				glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
				glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
				glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
				glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
				glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
				glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
				glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
				glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
				glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
				return pack(glm::notEqual(o, o2, o3));
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
			return NULL;
		}

	if (PyGLM_Vec_PTI_Check2(3, int, arg3)) {
		glm::vec<3, int> o3 = PyGLM_Vec_PTI_Get2(3, int, arg3);
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_3 | PyGLM_SHAPE_3xM | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_3 | PyGLM_SHAPE_3xM | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}

		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}

	if (PyGLM_Vec_PTI_Check2(4, int, arg3)) {
		glm::vec<4, int> o3 = PyGLM_Vec_PTI_Get2(4, int, arg3);
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_4 | PyGLM_SHAPE_4xM | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_4 | PyGLM_SHAPE_4xM | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}

		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}

	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_T_MAT | PyGLM_SHAPE_ALL | PyGLM_DT_FD);

	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
		glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
		glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
		return pack(glm::notEqual(o, o2, o3));
	}

	if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
		glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
			glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check1(2, 3, float, arg2)) {
			glm::mat<2, 3, float> o = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			glm::mat<2, 3, float> o2 = PyGLM_Mat_PTI_Get1(2, 3, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check1(2, 4, float, arg2)) {
			glm::mat<2, 4, float> o = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			glm::mat<2, 4, float> o2 = PyGLM_Mat_PTI_Get1(2, 4, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
		glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
			glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check1(2, 3, double, arg2)) {
			glm::mat<2, 3, double> o = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			glm::mat<2, 3, double> o2 = PyGLM_Mat_PTI_Get1(2, 3, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check1(2, 4, double, arg2)) {
			glm::mat<2, 4, double> o = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			glm::mat<2, 4, double> o2 = PyGLM_Mat_PTI_Get1(2, 4, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
		glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check1(3, 2, float, arg2)) {
			glm::mat<3, 2, float> o = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			glm::mat<3, 2, float> o2 = PyGLM_Mat_PTI_Get1(3, 2, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
			glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check1(3, 4, float, arg2)) {
			glm::mat<3, 4, float> o = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			glm::mat<3, 4, float> o2 = PyGLM_Mat_PTI_Get1(3, 4, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
		glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check1(3, 2, double, arg2)) {
			glm::mat<3, 2, double> o = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			glm::mat<3, 2, double> o2 = PyGLM_Mat_PTI_Get1(3, 2, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
			glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check1(3, 4, double, arg2)) {
			glm::mat<3, 4, double> o = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			glm::mat<3, 4, double> o2 = PyGLM_Mat_PTI_Get1(3, 4, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check1(4, 2, float, arg2)) {
			glm::mat<4, 2, float> o = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			glm::mat<4, 2, float> o2 = PyGLM_Mat_PTI_Get1(4, 2, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check1(4, 3, float, arg2)) {
			glm::mat<4, 3, float> o = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			glm::mat<4, 3, float> o2 = PyGLM_Mat_PTI_Get1(4, 3, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
			glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check1(4, 2, double, arg2)) {
			glm::mat<4, 2, double> o = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			glm::mat<4, 2, double> o2 = PyGLM_Mat_PTI_Get1(4, 2, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check1(4, 3, double, arg2)) {
			glm::mat<4, 3, double> o = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			glm::mat<4, 3, double> o2 = PyGLM_Mat_PTI_Get1(4, 3, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
			glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
			return pack(glm::notEqual(o, o2, o3));
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
		return NULL;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for notEqual()");
	return NULL;
}

PyGLM_MAKE_GLM_FUNC_VV(lessThan)
PyGLM_MAKE_GLM_FUNC_VV(lessThanEqual)
PyGLM_MAKE_GLM_FUNC_VV(greaterThan)
PyGLM_MAKE_GLM_FUNC_VV(greaterThanEqual)

static PyObject*
any(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_BOOL);
	if (PyGLM_Vec_PTI_Check0(1, bool, arg)) {
		if (glm::any(PyGLM_Vec_PTI_Get0(1, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (PyGLM_Vec_PTI_Check0(2, bool, arg)) {
		if (glm::any(PyGLM_Vec_PTI_Get0(2, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (PyGLM_Vec_PTI_Check0(3, bool, arg)) {
		if (glm::any(PyGLM_Vec_PTI_Get0(3, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (PyGLM_Vec_PTI_Check0(4, bool, arg)) {
		if (glm::any(PyGLM_Vec_PTI_Get0(4, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	PyGLM_TYPEERROR_O("invalid argument type for any(): ", arg);
	return NULL;
}

static PyObject*
all(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_BOOL);
	if (PyGLM_Vec_PTI_Check0(1, bool, arg)) {
		if (glm::all(PyGLM_Vec_PTI_Get0(1, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (PyGLM_Vec_PTI_Check0(2, bool, arg)) {
		if (glm::all(PyGLM_Vec_PTI_Get0(2, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (PyGLM_Vec_PTI_Check0(3, bool, arg)) {
		if (glm::all(PyGLM_Vec_PTI_Get0(3, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	if (PyGLM_Vec_PTI_Check0(4, bool, arg)) {
		if (glm::all(PyGLM_Vec_PTI_Get0(4, bool, arg))) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_FALSE;
	}
	PyGLM_TYPEERROR_O("invalid argument type for all(): ", arg);
	return NULL;
}

static PyObject*
not_(PyObject*, PyObject* arg) {
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_BOOL);
	if (PyGLM_Vec_PTI_Check0(1, bool, arg)) {
		return pack_vec(glm::not_(PyGLM_Vec_PTI_Get0(1, bool, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(2, bool, arg)) {
		return pack_vec(glm::not_(PyGLM_Vec_PTI_Get0(2, bool, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(3, bool, arg)) {
		return pack_vec(glm::not_(PyGLM_Vec_PTI_Get0(3, bool, arg)));
	}
	if (PyGLM_Vec_PTI_Check0(4, bool, arg)) {
		return pack_vec(glm::not_(PyGLM_Vec_PTI_Get0(4, bool, arg)));
	}
	PyGLM_TYPEERROR_O("invalid argument type for not_(): ", arg);
	return NULL;
}

#define FUNC_VECTOR_RELATIONAL_METHODS { "equal", (PyCFunction)equal, METH_VARARGS, "equal(x, y[, ...]) -> (x == y)\nReturns the component-wise comparison of result x == y." }, \
{ "notEqual", (PyCFunction)notEqual, METH_VARARGS, "notEqual(x, y[, ...]) -> (x != y)\nReturns the component-wise comparison of result x != y." }, \
{ "lessThan", (PyCFunction)lessThan_, METH_VARARGS, "lessThan(x, y) -> (x < y)\nReturns the component-wise comparison of result x < y." }, \
{ "lessThanEqual", (PyCFunction)lessThanEqual_, METH_VARARGS, "lessThanEqual(x, y) -> (x <= y)\nReturns the component-wise comparison of result x <= y." }, \
{ "greaterThan", (PyCFunction)greaterThan_, METH_VARARGS, "greaterThan(x, y) -> (x > y)\nReturns the component-wise comparison of result x > y." }, \
{ "greaterThanEqual", (PyCFunction)greaterThanEqual_, METH_VARARGS, "greaterThanEqual(x, y) -> (x >= y)\nReturns the component-wise comparison of result x >= y." }, \
{ "any", (PyCFunction)any, METH_O, "any(x) -> bool\nReturns true if any component of x is true." }, \
{ "all", (PyCFunction)all, METH_O, "all(x) -> bool\nReturns true if all components of x are true." }, \
{ "not_", (PyCFunction)not_, METH_O, "not(x) -> bool\nReturns the component-wise logical complement of x." }
