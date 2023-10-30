#pragma once

#include "../compiler_setup.h"

#include "../internal_functions/all.h"

#include "../types/mat/all.h"

template<int C>
static PyObject* mat_length(PyObject *, PyObject*) {
	return PyLong_FromLong(C);
}

static void
mat_dealloc(PyObject* self)
{
	if (self->ob_type != NULL) Py_TYPE(self)->tp_free(self);
}

template<int C, int R, typename T>
static PyObject *
mat_new(PyTypeObject *type, PyObject *, PyObject *)
{
	mat<C, R, T> *self = (mat<C, R, T> *)type->tp_alloc(type, 0);
	if (self != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = (uint8_t)((C << PyGLM_TYPE_INFO_MAT_SHAPE1_OFFSET) | (R << PyGLM_TYPE_INFO_MAT_SHAPE2_OFFSET) | (info_type << PyGLM_TYPE_INFO_MAT_TYPE_OFFSET));
		//self->info = info;
		self->super_type = glm::mat<C, R, T>();
	}
	return (PyObject *)self;
}


template<typename T>
static int
mat2x2_init(mat<2, 2, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;

	if (!PyArg_UnpackTuple(args, "mat2x2", 0, 4,
		&arg1, &arg2, &arg3, &arg4)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<2,2,T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}

		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat2x2s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_MAT_ALL); 
		if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 2, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
		return -1;
	}

	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			self->super_type = glm::mat<2, 2, T>(o, (T)0, (T)0, o2);
			return 0;
		}
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<2, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<2, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(2, T);
		PyGLM_Vec_PTI_Assign1(2, T);
		self->super_type = glm::mat<2, 2, T>(o, o2);
		return 0;
	}

	if (arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
		self->super_type = glm::mat<2, 2, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x2()");
	return -1;
}

template<typename T>
static int
mat2x3_init(mat<2, 3, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;

	if (!PyArg_UnpackTuple(args, "mat2x3", 0, 6,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<2, 3, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat2x3s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2x3 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
		return -1;
	}

	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			self->super_type = glm::mat<2, 3, T>(o, (T)0, (T)0, (T)0, o2, (T)0);
			return 0;
		}
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<3, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<3, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(3, T);
		PyGLM_Vec_PTI_Assign1(3, T);
		self->super_type = glm::mat<2, 3, T>(o, o2);
		return 0;
	}

	if (arg4 == NULL || arg5 == NULL || arg6 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) {
		self->super_type = glm::mat<2, 3, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x3()");
	return -1;
}

template<typename T>
static int
mat2x4_init(mat<2, 4, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;

	if (!PyArg_UnpackTuple(args, "mat2x4", 0, 8,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<2, 4, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat2x4s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_2x4 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
		return -1;
	}

	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			self->super_type = glm::mat<2, 4, T>(o, (T)0, (T)0, (T)0, (T)0, o2, (T)0, (T)0);
			return 0;
		}
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<4, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<4, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(4, T);
		PyGLM_Vec_PTI_Assign1(4, T);
		self->super_type = glm::mat<2, 4, T>(o, o2);
		return 0;
	}

	if (arg4 == NULL || arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8)) {
		self->super_type = glm::mat<2, 4, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6), PyGLM_Number_FromPyObject<T>(arg7), PyGLM_Number_FromPyObject<T>(arg8));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat2x4()");
	return -1;
}

template<typename T>
static int
mat3x2_init(mat<3, 2, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;

	if (!PyArg_UnpackTuple(args, "mat3x2", 0, 6,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<3, 2, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat3x2s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x2 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			self->super_type = glm::mat<3, 2, T>(o, (T)0, (T)0, o2, (T)0, (T)0);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (arg4 == NULL) {
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<2, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<2, T>()));
		PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<2, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1) || PyGLM_PTI_IsNone(2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(2, T);
		PyGLM_Vec_PTI_Assign1(2, T);
		PyGLM_Vec_PTI_Assign2(2, T);
		self->super_type = glm::mat<3, 2, T>(o, o2, o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6)) {
		self->super_type = glm::mat<3, 2, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x2()");
	return -1;
}

template<typename T>
static int
mat3x3_init(mat<3, 3, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;

	if (!PyArg_UnpackTuple(args, "mat3x3", 0, 9,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<3, 3, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat3x3s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, uint32, arg1);
			return 0;
		}

		// quaternions
		PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_PTI_GetDT(T));
		if (!PyGLM_PTI_IsNone(0)) {
			self->super_type = glm::mat3_cast(PyGLM_Qua_PTI_Get0(T, arg1));
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (arg3 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (arg4 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			T o3 = PyGLM_Number_FromPyObject<T>(arg3);
			self->super_type = glm::mat<3, 3, T>(o, (T)0, (T)0, (T)0, o2, (T)0, (T)0, (T)0, o3);
			return 0;
		}
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<3, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<3, T>()));
		PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<3, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1) || PyGLM_PTI_IsNone(2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(3, T);
		PyGLM_Vec_PTI_Assign1(3, T);
		PyGLM_Vec_PTI_Assign2(3, T);
		self->super_type = glm::mat<3, 3, T>(o, o2, o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9)) {
		self->super_type = glm::mat<3, 3, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6), PyGLM_Number_FromPyObject<T>(arg7), PyGLM_Number_FromPyObject<T>(arg8), PyGLM_Number_FromPyObject<T>(arg9));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x3()");
	return -1;
}

template<typename T>
static int
mat3x4_init(mat<3, 4, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;

	if (!PyArg_UnpackTuple(args, "mat3x4", 0, 12,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<3, 4, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat3x4s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_3x4 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (arg3 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (arg4 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			T o3 = PyGLM_Number_FromPyObject<T>(arg3);
			self->super_type = glm::mat<3, 4, T>(o, (T)0, (T)0, (T)0, (T)0, o2, (T)0, (T)0, (T)0, (T)0, o3, (T)0);
			return 0;
		}
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<4, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<4, T>()));
		PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<4, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1) || PyGLM_PTI_IsNone(2)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(4, T);
		PyGLM_Vec_PTI_Assign1(4, T);
		PyGLM_Vec_PTI_Assign2(4, T);
		self->super_type = glm::mat<3, 4, T>(o, o2, o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9) && PyGLM_Number_Check(arg10) && PyGLM_Number_Check(arg11) && PyGLM_Number_Check(arg12)) {
		self->super_type = glm::mat<3, 4, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6), PyGLM_Number_FromPyObject<T>(arg7), PyGLM_Number_FromPyObject<T>(arg8), PyGLM_Number_FromPyObject<T>(arg9), PyGLM_Number_FromPyObject<T>(arg10), PyGLM_Number_FromPyObject<T>(arg11), PyGLM_Number_FromPyObject<T>(arg12));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat3x4()");
	return -1;
}

template<typename T>
static int
mat4x2_init(mat<4, 2, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;

	if (!PyArg_UnpackTuple(args, "mat4x2", 0, 8,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<4, 2, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat4x2s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4x2 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			self->super_type = glm::mat<4, 2, T>(o, (T)0, (T)0, o2, (T)0, (T)0, (T)0, (T)0);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (arg5 == NULL) {
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<2, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<2, T>()));
		PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<2, T>()));
		PyGLM_PTI_Init3(arg4, (get_vec_PTI_info<2, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1) || PyGLM_PTI_IsNone(2) || PyGLM_PTI_IsNone(3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(2, T);
		PyGLM_Vec_PTI_Assign1(2, T);
		PyGLM_Vec_PTI_Assign2(2, T);
		PyGLM_Vec_PTI_Assign3(2, T);
		self->super_type = glm::mat<4, 2, T>(o, o2, o3, o4);
		return 0;
	}

	if (arg6 == NULL || arg7 == NULL || arg8 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8)) {
		self->super_type = glm::mat<4, 2, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6), PyGLM_Number_FromPyObject<T>(arg7), PyGLM_Number_FromPyObject<T>(arg8));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x2()");
	return -1;
}

template<typename T>
static int
mat4x3_init(mat<4, 3, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;

	if (!PyArg_UnpackTuple(args, "mat4x3", 0, 12,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<4, 3, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat4x3s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4x3 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, uint32, arg1);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (arg3 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (arg4 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			T o3 = PyGLM_Number_FromPyObject<T>(arg3);
			self->super_type = glm::mat<4, 3, T>(o, (T)0, (T)0, (T)0, o2, (T)0, (T)0, (T)0, o3, (T)0, (T)0, (T)0);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (arg5 == NULL) {
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<3, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<3, T>()));
		PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<3, T>()));
		PyGLM_PTI_Init3(arg4, (get_vec_PTI_info<3, T>()));
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1) || PyGLM_PTI_IsNone(2) || PyGLM_PTI_IsNone(3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
			return -1;
		}
		PyGLM_Vec_PTI_Assign0(3, T);
		PyGLM_Vec_PTI_Assign1(3, T);
		PyGLM_Vec_PTI_Assign2(3, T);
		PyGLM_Vec_PTI_Assign3(3, T);
		self->super_type = glm::mat<4, 3, T>(o, o2, o3, o4);
		return 0;
	}

	if (arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9) && PyGLM_Number_Check(arg10) && PyGLM_Number_Check(arg11) && PyGLM_Number_Check(arg12)) {
		self->super_type = glm::mat<4, 3, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6), PyGLM_Number_FromPyObject<T>(arg7), PyGLM_Number_FromPyObject<T>(arg8), PyGLM_Number_FromPyObject<T>(arg9), PyGLM_Number_FromPyObject<T>(arg10), PyGLM_Number_FromPyObject<T>(arg11), PyGLM_Number_FromPyObject<T>(arg12));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x3()");
	return -1;
}

template<typename T>
static int
mat4x4_init(mat<4, 4, T> *self, PyObject *args, PyObject *)
{
	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;
	PyObject *arg13 = NULL;
	PyObject *arg14 = NULL;
	PyObject *arg15 = NULL;
	PyObject *arg16 = NULL;

	if (!PyArg_UnpackTuple(args, "mat4x4", 0, 16,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12, &arg13, &arg14, &arg15, &arg16)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (PyGLM_Number_Check(arg1)) {
			self->super_type = glm::mat<4, 4, T>(PyGLM_Number_FromPyObject<T>(arg1));
			return 0;
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_NxM | PyGLM_PTI_GetDT(T));
		if (PyGLM_Mat_PTI_Check0(2, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(2, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(2, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(3, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(3, 4, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 2, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 2, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 3, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 3, T, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, T, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, T, arg1);
			return 0;
		}

		// mat4x4s with different data types
		PyGLM_PTI_Init0(arg1, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_MAT_ALL);
		if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, int32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, int32, arg1);
			return 0;
		}
		if (PyGLM_Mat_PTI_Check0(4, 4, uint32, arg1)) {
			self->super_type = PyGLM_Mat_PTI_Get0(4, 4, uint32, arg1);
			return 0;
		}

		// quaternions
		PyGLM_PTI_Init0(arg1, PyGLM_T_QUA | PyGLM_PTI_GetDT(T));
		if (!PyGLM_PTI_IsNone(0)) {
			self->super_type = glm::mat4_cast(PyGLM_Qua_PTI_Get0(T, arg1));
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (arg3 == NULL || arg4 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (arg5 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
			T o = PyGLM_Number_FromPyObject<T>(arg1);
			T o2 = PyGLM_Number_FromPyObject<T>(arg2);
			T o3 = PyGLM_Number_FromPyObject<T>(arg3);
			T o4 = PyGLM_Number_FromPyObject<T>(arg4);
			self->super_type = glm::mat<4, 4, T>(o, (T)0, (T)0, (T)0, (T)0, o2, (T)0, (T)0, (T)0, (T)0, o3, (T)0, (T)0, (T)0, (T)0, o4);
			return 0;
		}
		PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<4, T>()));
		PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<4, T>()));
		PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<4, T>()));
		PyGLM_PTI_Init3(arg4, (get_vec_PTI_info<4, T>()));
		
		if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1) || PyGLM_PTI_IsNone(2) || PyGLM_PTI_IsNone(3)) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
			return -1;
		}

		PyGLM_Vec_PTI_Assign0(4, T);
		PyGLM_Vec_PTI_Assign1(4, T);
		PyGLM_Vec_PTI_Assign2(4, T);
		PyGLM_Vec_PTI_Assign3(4, T);
		self->super_type = glm::mat<4, 4, T>(o, o2, o3, o4);
		return 0;
	}

	if (arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL || arg13 == NULL || arg14 == NULL || arg15 == NULL || arg16 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
		return -1;
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4) && PyGLM_Number_Check(arg5) && PyGLM_Number_Check(arg6) && PyGLM_Number_Check(arg7) && PyGLM_Number_Check(arg8) && PyGLM_Number_Check(arg9) && PyGLM_Number_Check(arg10) && PyGLM_Number_Check(arg11) && PyGLM_Number_Check(arg12) && PyGLM_Number_Check(arg13) && PyGLM_Number_Check(arg14) && PyGLM_Number_Check(arg15) && PyGLM_Number_Check(arg16)) {
		self->super_type = glm::mat<4, 4, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4), PyGLM_Number_FromPyObject<T>(arg5), PyGLM_Number_FromPyObject<T>(arg6), PyGLM_Number_FromPyObject<T>(arg7), PyGLM_Number_FromPyObject<T>(arg8), PyGLM_Number_FromPyObject<T>(arg9), PyGLM_Number_FromPyObject<T>(arg10), PyGLM_Number_FromPyObject<T>(arg11), PyGLM_Number_FromPyObject<T>(arg12), PyGLM_Number_FromPyObject<T>(arg13), PyGLM_Number_FromPyObject<T>(arg14), PyGLM_Number_FromPyObject<T>(arg15), PyGLM_Number_FromPyObject<T>(arg16));
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mat4x4()");
	return -1;
}

// unaryfunc
template<int C, int R, typename T>
static PyObject *
mat_neg(mat<C, R, T> *obj)
{
	return pack_mat<C, R, T>(-obj->super_type);
}

template<int C, int R, typename T>
static PyObject *
mat_pos(mat<C, R, T> *obj)
{
	return pack_mat<C, R, T>(obj->super_type);
}

template<int C, int R, typename T>
static PyObject *
mat_abs(mat<C, R, T> *obj)
{
	return pack_mat<C, R, T>(glm::abs(obj->super_type));
}

// binaryfunc
template<int C, int R, typename T>
static PyObject *
matsq_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_mat<C, R, T>(PyGLM_Number_FromPyObject<T>(obj1) + (((mat<C, R, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.mat' and ", obj1);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_mat<C, R, T>(o + PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_mat<C, R, T>(o + o2);
}

template<int C, int R, typename T>
static PyObject *
mat_add(PyObject *obj1, PyObject *obj2)
{
	PyGLM_PTI_Init0(obj1, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.mat' and ", obj1);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_mat<C, R, T>(o + PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_mat<C, R, T>(o + o2);
}

template<int C, int R, typename T>
static PyObject *
matsq_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_mat<C, R, T>(PyGLM_Number_FromPyObject<T>(obj1) - (((mat<C, R, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm.mat' and ", obj1);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_mat<C, R, T>(o - PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_mat<C, R, T>(o - o2);
}

template<int C, int R, typename T>
static PyObject *
mat_sub(PyObject *obj1, PyObject *obj2)
{
	PyGLM_PTI_Init0(obj1, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm.mat' and ", obj1);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_mat<C, R, T>(o - PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_mat<C, R, T>(o - o2);
}

template<int S, typename T>
static inline PyObject*
mat_hmul(glm::mat<S, S, T> o, PyObject* obj2) {
	constexpr int Shom = S - 1;
	PyGLM_PTI_Init0(obj2, (get_vec_PTI_info<Shom, T>()));

	if (!PyGLM_PTI_IsNone(0)) { // obj2 is a row_type in homogenous coordinates
		glm::vec<S, T> o2 = glm::vec<S, T>(PyGLM_Vec_PTI_Get0(Shom, T, obj2), static_cast<T>(1));

		return pack_vec(glm::vec<Shom, T>(o * o2));
	}

	Py_RETURN_NOTIMPLEMENTED;
}

template<int C, int R, typename T>
static PyObject *
mat_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		return pack_mat(PyGLM_Number_FromPyObject<T>(obj1) * ((mat<C, R, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<R, T>()) | (get_mat_PTI_info<C, R, T>()));
	if (PyGLM_Vec_PTI_Check0(R, T, obj1)) { // obj1 is a col_type
		glm::vec<R, T> o = PyGLM_Vec_PTI_Get0(R, T, obj1);

		return pack_vec(o * ((mat<C, R, T>*)obj2)->super_type);
	}

	if (!PyGLM_Mat_PTI_Check0(C, R, T, obj1)) { // obj1 can't be interpreted as mat<C, R, T>
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		return pack_mat(o * PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init0(obj2, (get_vec_PTI_info<C, T>()) | (get_mat_PTI_info<2, C, T>()) | (get_mat_PTI_info<3, C, T>()) | (get_mat_PTI_info<4, C, T>()));

	if (PyGLM_Vec_PTI_Check0(C, T, obj2)) { // obj2 is a row_type
		glm::vec<C, T> o2 = PyGLM_Vec_PTI_Get0(C, T, obj2);

		return pack_vec(o * o2);
	}

	if (PyGLM_Mat_PTI_Check0(2, C, T, obj2)) {
		glm::mat<2, C, T> o2 = PyGLM_Mat_PTI_Get0(2, C, T, obj2);

		return pack_mat(o * o2);
	}

	if (PyGLM_Mat_PTI_Check0(3, C, T, obj2)) {
		glm::mat<3, C, T> o2 = PyGLM_Mat_PTI_Get0(3, C, T, obj2);

		return pack_mat(o * o2);
	}

	if (PyGLM_Mat_PTI_Check0(4, C, T, obj2)) {
		glm::mat<4, C, T> o2 = PyGLM_Mat_PTI_Get0(4, C, T, obj2);

		return pack_mat(o * o2);
	}

	if (C == R) {
		return mat_hmul<C, T>(o, obj2);
	}
	

	Py_RETURN_NOTIMPLEMENTED;
}

template<int C, int R, typename T>
static PyObject *
matsq_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		for (int c = 0; c < C; c++) {
			for (int r = 0; r < R; r++) {
				if (((mat<C, R, T>*)obj2)->super_type[c][r] == 0) {
					PyGLM_ZERO_DIVISION_ERROR_T(T);
				}
			}
		}
		return pack_mat<C, R, T>(PyGLM_Number_FromPyObject<T>(obj1) / ((mat<C, R, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<R, T>() | get_mat_PTI_info<C, R, T>()));
	if (PyGLM_Vec_PTI_Check0(R, T, obj1)) { // obj1 is a col_type
		for (int c = 0; c < C; c++) {
			for (int r = 0; r < R; r++) {
				if (((mat<C, R, T>*)obj2)->super_type[c][r] == 0) {
					PyGLM_ZERO_DIVISION_ERROR_T(T);
				}
			}
		}

		glm::vec<R, T> o = PyGLM_Vec_PTI_Get0(R, T, obj1);

		return pack_vec(o / ((mat<C, R, T>*)obj2)->super_type);
	}

	if (!PyGLM_Mat_PTI_Check0(C, R, T, obj1)) { // obj1 can't be interpreted as mat<C, R, T>
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_mat(o / o2);
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<C, T>() | get_mat_PTI_info<C, R, T>()));

	if (PyGLM_Vec_PTI_Check1(C, T, obj2)) { // obj2 is a row_type
		glm::vec<C, T> o2 = PyGLM_Vec_PTI_Get1(C, T, obj2);

		for (int c = 0; c < C; c++) {
			if (o2[c] == 0) {
				PyGLM_ZERO_DIVISION_ERROR_T(T);
			}
		}

		return pack_vec(o / o2);
	}

	if (PyGLM_Mat_PTI_Check1(C, R, T, obj2)) {
		glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, obj2);

		for (int c = 0; c < C; c++) {
			for (int r = 0; r < R; r++) {
				if (((mat<C, R, T>*)obj2)->super_type[c][r] == 0) {
					PyGLM_ZERO_DIVISION_ERROR_T(T);
				}
			}
		}

		return pack_mat(o / o2);
	}
	Py_RETURN_NOTIMPLEMENTED;
}

template<int C, int R, typename T>
static PyObject *
mat_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar
		for (int c = 0; c < C; c++) {
			for (int r = 0; r < R; r++) {
				if (((mat<C, R, T>*)obj2)->super_type[c][r] == 0) {
					PyGLM_ZERO_DIVISION_ERROR_T(T);
				}
			}
		}
		return pack_mat(PyGLM_Number_FromPyObject<T>(obj1) / ((mat<C, R, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_mat_PTI_info<C, R, T>()));

	if (!PyGLM_Mat_PTI_Check0(C, R, T, obj1)) { // obj1 can't be interpreted as mat<C, R, T>
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	glm::mat<C, R, T> o = PyGLM_Mat_PTI_Get0(C, R, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_mat(o / o2);
	}
	Py_RETURN_NOTIMPLEMENTED;
}

static PyObject*
mat_matmul(PyObject* obj1, PyObject* obj2)
{
	PyObject* out = PyNumber_Multiply(obj1, obj2);
	if (out == NULL) {
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for @: ", obj1, obj2);
	}
	return out;
}

// inplace
// binaryfunc
template<int C, int R, typename T>
static PyObject *
matsq_iadd(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)matsq_add<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject *
mat_iadd(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)mat_add<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject *
matsq_isub(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)matsq_sub<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject *
mat_isub(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)mat_sub<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject *
mat_imul(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)mat_mul<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Mat_Check(C, R, T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject *
matsq_idiv(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)matsq_div<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Mat_Check(C, R, T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject *
mat_idiv(mat<C, R, T> *self, PyObject *obj)
{
	mat<C, R, T> * temp = (mat<C, R, T>*)mat_div<C, R, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int C, int R, typename T>
static PyObject*
mat_imatmul(mat<C, R, T>* self, PyObject* obj)
{
	mat<C, R, T>* temp = (mat<C, R, T>*)mat_matmul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Mat_Check(C, R, T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}


template<typename T>
static PyObject *
mat2x2_str(mat<2, 2, T>* self)
{
	char * out = (char*)PyMem_Malloc((66) * sizeof(char));
	snprintf(out, 66, "[ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[0][1], (double)self->super_type[1][1]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat2x3_str(mat<2, 3, T>* self)
{
	char * out = (char*)PyMem_Malloc((99) * sizeof(char));
	snprintf(out, 99, "[ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[0][2], (double)self->super_type[1][2]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat2x4_str(mat<2, 4, T>* self)
{
	char * out = (char*)PyMem_Malloc((132) * sizeof(char));
	snprintf(out, 132, "[ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[0][2], (double)self->super_type[1][2], (double)self->super_type[0][3], (double)self->super_type[1][3]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat3x2_str(mat<3, 2, T>* self)
{
	char * out = (char*)PyMem_Malloc((98) * sizeof(char));
	snprintf(out, 98, "[ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[2][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[2][1]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat3x3_str(mat<3, 3, T>* self)
{
	char * out = (char*)PyMem_Malloc((147) * sizeof(char));
	snprintf(out, 147, "[ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[2][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[2][1], (double)self->super_type[0][2], (double)self->super_type[1][2], (double)self->super_type[2][2]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat3x4_str(mat<3, 4, T>* self)
{
	char * out = (char*)PyMem_Malloc((196) * sizeof(char));
	snprintf(out, 196, "[ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[2][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[2][1], (double)self->super_type[0][2], (double)self->super_type[1][2], (double)self->super_type[2][2], (double)self->super_type[0][3], (double)self->super_type[1][3], (double)self->super_type[2][3]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat4x2_str(mat<4, 2, T>* self)
{
	char * out = (char*)PyMem_Malloc((130) * sizeof(char));
	snprintf(out, 130, "[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[2][0], (double)self->super_type[3][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[2][1], (double)self->super_type[3][1]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat4x3_str(mat<4, 3, T>* self)
{
	char * out = (char*)PyMem_Malloc((195) * sizeof(char));
	snprintf(out, 195, "[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[2][0], (double)self->super_type[3][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[2][1], (double)self->super_type[3][1], (double)self->super_type[0][2], (double)self->super_type[1][2], (double)self->super_type[2][2], (double)self->super_type[3][2]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat4x4_str(mat<4, 4, T>* self)
{
	char * out = (char*)PyMem_Malloc((260) * sizeof(char));
	snprintf(out, 260, "[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]\n[ %12.6g ][ %12.6g ][ %12.6g ][ %12.6g ]", (double)self->super_type[0][0], (double)self->super_type[1][0], (double)self->super_type[2][0], (double)self->super_type[3][0], (double)self->super_type[0][1], (double)self->super_type[1][1], (double)self->super_type[2][1], (double)self->super_type[3][1], (double)self->super_type[0][2], (double)self->super_type[1][2], (double)self->super_type[2][2], (double)self->super_type[3][2], (double)self->super_type[0][3], (double)self->super_type[1][3], (double)self->super_type[2][3], (double)self->super_type[3][3]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat2x2_repr(mat<2, 2, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 65 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g ), ( %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[1][0], (double)self->super_type[1][1]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat2x3_repr(mat<2, 3, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 93 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[0][2], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[1][2]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat2x4_repr(mat<2, 4, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 121 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[0][2], (double)self->super_type[0][3], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[1][2], (double)self->super_type[1][3]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat3x2_repr(mat<3, 2, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 97 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g ), ( %.6g, %.6g ), ( %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[2][0], (double)self->super_type[2][1]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat3x3_repr(mat<3, 3, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 139 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[0][2], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[1][2], (double)self->super_type[2][0], (double)self->super_type[2][1], (double)self->super_type[2][2]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat3x4_repr(mat<3, 4, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 181 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[0][2], (double)self->super_type[0][3], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[1][2], (double)self->super_type[1][3], (double)self->super_type[2][0], (double)self->super_type[2][1], (double)self->super_type[2][2], (double)self->super_type[2][3]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat4x2_repr(mat<4, 2, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 129 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g ), ( %.6g, %.6g ), ( %.6g, %.6g ), ( %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[2][0], (double)self->super_type[2][1], (double)self->super_type[3][0], (double)self->super_type[3][1]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat4x3_repr(mat<4, 3, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 185 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[0][2], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[1][2], (double)self->super_type[2][0], (double)self->super_type[2][1], (double)self->super_type[2][2], (double)self->super_type[3][0], (double)self->super_type[3][1], (double)self->super_type[3][2]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
mat4x4_repr(mat<4, 4, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 241 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s(( %.6g, %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g, %.6g ), ( %.6g, %.6g, %.6g, %.6g ))", name, (double)self->super_type[0][0], (double)self->super_type[0][1], (double)self->super_type[0][2], (double)self->super_type[0][3], (double)self->super_type[1][0], (double)self->super_type[1][1], (double)self->super_type[1][2], (double)self->super_type[1][3], (double)self->super_type[2][0], (double)self->super_type[2][1], (double)self->super_type[2][2], (double)self->super_type[2][3], (double)self->super_type[3][0], (double)self->super_type[3][1], (double)self->super_type[3][2], (double)self->super_type[3][3]);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<int C>
static Py_ssize_t mat_len(PyObject *) {
	return (Py_ssize_t)C;
}

template<typename T>
static PyObject* mat2x2_mp_item(mat<2, 2, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<2, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat2x3_mp_item(mat<2, 3, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<3, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat2x4_mp_item(mat<2, 4, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<4, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat3x2_mp_item(mat<3, 2, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<2, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat3x3_mp_item(mat<3, 3, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<3, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat3x4_mp_item(mat<3, 4, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<4, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat4x2_mp_item(mat<4, 2, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<2, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat4x3_mp_item(mat<4, 3, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<3, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static PyObject* mat4x4_mp_item(mat<4, 4, T> * self, PyObject* key) {
	if (PyGLM_Number_Check(key)) {
		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}
		return pack_mvec<4, T>(&self->super_type[index], (PyObject*)self);
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return NULL;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return NULL;
		}

		return PyGLM_PyObject_FromNumber<T>(self->super_type[value0_as_long][value1_as_long]);
	}
	PyGLM_TYPEERROR_O("index must be int or a length 2 tuple, got ", key);
	return NULL;
}

template<typename T>
static int mat2x2_mp_ass_item(mat<2, 2, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<2, T>()));
		if (!PyGLM_Vec_PTI_Check0(2, T, value)) {
			PyGLM_TYPEERROR_O("expected vec2, got ", value);
			return -1;
		}

		glm::vec<2, T> o = PyGLM_Vec_PTI_Get0(2, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat2x3_mp_ass_item(mat<2, 3, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<3, T>()))
		if (!PyGLM_Vec_PTI_Check0(3, T, value)) {
			PyGLM_TYPEERROR_O("expected vec3, got ", value);
			return -1;
		}

		glm::vec<3, T> o = PyGLM_Vec_PTI_Get0(3, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat2x4_mp_ass_item(mat<2, 4, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<4, T>()));
		if (!PyGLM_Vec_PTI_Check0(4, T, value)) {
			PyGLM_TYPEERROR_O("expected vec4, got ", value);
			return -1;
		}

		glm::vec<4, T> o = PyGLM_Vec_PTI_Get0(4, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 1 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat3x2_mp_ass_item(mat<3, 2, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<2, T>()));
		if (!PyGLM_Vec_PTI_Check0(2, T, value)) {
			PyGLM_TYPEERROR_O("expected vec2, got ", value);
			return -1;
		}

		glm::vec<2, T> o = PyGLM_Vec_PTI_Get0(2, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat3x3_mp_ass_item(mat<3, 3, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<3, T>()));
		if (!PyGLM_Vec_PTI_Check0(3, T, value)) {
			PyGLM_TYPEERROR_O("expected vec3, got ", value);
			return -1;
		}

		glm::vec<3, T> o = PyGLM_Vec_PTI_Get0(3, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat3x4_mp_ass_item(mat<3, 4, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<4, T>()))
		if (!PyGLM_Vec_PTI_Check0(4, T, value)) {
			PyGLM_TYPEERROR_O("expected vec4, got ", value);
			return -1;
		}

		glm::vec<4, T> o = PyGLM_Vec_PTI_Get0(4, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 2 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat4x2_mp_ass_item(mat<4, 2, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<2, T>()));
		if (!PyGLM_Vec_PTI_Check0(2, T, value)) {
			PyGLM_TYPEERROR_O("expected vec2, got ", value);
			return -1;
		}

		glm::vec<2, T> o = PyGLM_Vec_PTI_Get0(2, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 1) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat4x3_mp_ass_item(mat<4, 3, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<3, T>()));
		if (!PyGLM_Vec_PTI_Check0(3, T, value)) {
			PyGLM_TYPEERROR_O("expected vec3, got ", value);
			return -1;
		}

		glm::vec<3, T> o = PyGLM_Vec_PTI_Get0(3, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 2) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<typename T>
static int mat4x4_mp_ass_item(mat<4, 4, T> * self, PyObject* key, PyObject * value) {
	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "item deletion not supported");
		return -1;
	}
	if (PyGLM_Number_Check(key)) {
		
		PyGLM_PTI_Init0(value, (get_vec_PTI_info<4, T>()));
		if (!PyGLM_Vec_PTI_Check0(4, T, value)) {
			PyGLM_TYPEERROR_O("expected vec4, got ", value);
			return -1;
		}

		glm::vec<4, T> o = PyGLM_Vec_PTI_Get0(4, T, value);

		long index = PyGLM_Number_AsLong(key);

		if (index < 0 || index > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[index] = o;
		return 0;
	}
	if (PyTuple_Check(key) && Py_SIZE(key) == 2) {
		if (!PyGLM_Number_Check(value)) {
			PyGLM_TYPEERROR_O("expected a number, got ", value);
			return -1;
		}

		PyObject* value0 = PyTuple_GET_ITEM(key, 0);
		PyObject* value1 = PyTuple_GET_ITEM(key, 1);

		if (value0 == NULL || value1 == NULL || !PyGLM_Number_Check(value0) || !PyGLM_Number_Check(value1)) {
			PyErr_SetString(PyExc_TypeError, "indices must be a pair of integer");
			return -1;
		}

		long value0_as_long = PyGLM_Number_AsLong(value0);
		long value1_as_long = PyGLM_Number_AsLong(value1);

		if (value0_as_long < 0 || value0_as_long > 3 || value1_as_long < 0 || value1_as_long > 3) {
			PyErr_SetString(PyExc_IndexError, "index out of range");
			return -1;
		}

		self->super_type[value0_as_long][value1_as_long] = PyGLM_Number_FromPyObject<T>(value);
		return 0;
	}
	PyGLM_TYPEERROR_O("index must be int or tuple, not ", key);
	return -1;
}

template<int C, int R, typename T>
static int mat_contains(mat<C, R, T> * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		T f = PyGLM_Number_FromPyObject<T>(value);
		bool contains = false;
		for (int n = 0; n < C; n++) {
			for (int m = 0; m < R; m++) {
				if (f == self->super_type[n][m]) {
					contains = true;
					break;
				}
			}
		}
		return (int)contains;
	}
	PyGLM_PTI_Init0(value, (get_vec_PTI_info<R, T>()));
	if (PyGLM_Vec_PTI_Check0(R, T, value)) {
		glm::vec<R, T> o = PyGLM_Vec_PTI_Get0(R, T, value);
		for (int n = 0; n < C; n++) {
			bool contains = true;
			for (int m = 0; m < R; m++) {
				if (o[m] != self->super_type[n][m]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				return 1;
			}
		}
	}
	return 0;

}

template<int C, int R, typename T>
static PyObject * mat_richcompare(mat<C, R, T> * self, PyObject * other, int comp_type) {
	PyGLM_PTI_Init1(other, (get_mat_PTI_info<C, R, T>()));

	if (PyGLM_PTI_IsNone(1)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::mat<C, R, T> o2 = PyGLM_Mat_PTI_Get1(C, R, T, other);

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

// iterator

template<int C, int R, typename T>
static PyObject *
matIter_new(PyTypeObject *type, PyObject *args, PyObject *)
{
	mat<C, R, T> *sequence = NULL;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	matIter<C, R, T> *rgstate = (matIter<C, R, T> *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

template<int C, int R, typename T>
static void
matIter_dealloc(matIter<C, R, T> *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

template<int C, int R, typename T>
static PyObject *
matIter_next(matIter<C, R, T> *rgstate)
{
	if (rgstate->seq_index < C) {
		return pack_mvec<R, T>(&rgstate->sequence->super_type[rgstate->seq_index++], (PyObject*)rgstate->sequence);
	}
	rgstate->seq_index = C;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<int C, int R, typename T>
static PyObject * mat_geniter(mat<C, R, T>* self) {
	PyTypeObject* matIterType = PyGLM_MATITER_TYPE<C, R, T>();
	matIter<C, R, T> *rgstate = (matIter<C, R, T> *)(matIterType->tp_alloc(matIterType, 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

template<int C, int R, typename T>
static int
mat_getbuffer(mat<C, R, T>* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}
	if ((flags & PyBUF_C_CONTIGUOUS) == PyBUF_C_CONTIGUOUS) {
		PyErr_SetString(PyExc_BufferError, "This type of buffer is not supported.");
		view->obj = NULL;
		return -1;
	}
	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0][0];
	view->len = sizeof(glm::mat<C, R, T>);
	view->readonly = 0;
	view->itemsize = sizeof(T);
	if (flags & PyBUF_FORMAT) {
		view->format = (std::is_same<T, float>::value) ? const_cast<char*>("f") : \
			(std::is_same <T, double>::value) ? const_cast<char*>("d") : \
			(std::is_same <T, std::int32_t>::value) ? const_cast<char*>("i") : \
			(std::is_same <T, std::uint32_t>::value) ? const_cast<char*>("I") : NULL;
	}
	else {
		view->format = NULL;
	}
	view->ndim = 2;
	if (flags & PyBUF_ND) {
		view->shape = (Py_ssize_t*)PyMem_Malloc(2 * sizeof(Py_ssize_t));
		if (view->shape != NULL) {
			view->shape[0] = R;
			view->shape[1] = C;
		}
	}
	else {
		view->shape = NULL;
	}
	if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
		view->strides = (Py_ssize_t*)PyMem_Malloc(2 * sizeof(Py_ssize_t));
		if (view->strides != NULL) {
			view->strides[0] = sizeof(T);
			view->strides[1] = sizeof(typename glm::mat<C, R, T>::col_type);
		}
	}
	else {
		view->strides = NULL;
	}

	view->suboffsets = NULL;
	view->internal = NULL;
	Py_INCREF(self);
	return 0;
}

static void
mat_releasebuffer(PyObject*, Py_buffer* view) {
	PyMem_Free(view->shape);
	PyMem_Free(view->strides);
}

template<int C, int R, typename T>
static PyObject*
mat_from_bytes(PyObject*, PyObject* arg) {
	PyTypeObject* type = PyGLM_MAT_TYPE<C, R, T>();
	if (PyBytes_Check(arg) && PyBytes_GET_SIZE(arg) == ((PyGLMTypeObject*)type)->itemSize) {
		char* bytesAsString = PyBytes_AS_STRING(arg);
		mat<C, R, T>* self = (mat<C, R, T> *)type->tp_alloc(type, 0);
		self->super_type = *(glm::mat<C, R, T>*)bytesAsString;
		return (PyObject*)self;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for from_bytes(). Expected bytes, got ", arg);
	return NULL;
}

template<int C, int R, typename T>
static Py_hash_t
mat_hash(mat<C, R, T>* self, PyObject*) {
	std::hash<glm::mat<C, R, T>> hasher;
	Py_hash_t out = (Py_hash_t)hasher(self->super_type);
	if (out == -1) {
		return -2;
	}
	return out;
}

template<int C, int R, typename T>
static PyObject*
mat_to_list(mat<C, R, T>* self, PyObject*) {
	PyObject* out = PyList_New(C);
	for (int n = 0; n < C; n++) {
		PyObject* innerList = PyList_New(R);
		for (int m = 0; m < R; m++) {
			PyList_SET_ITEM(innerList, m, PyGLM_PyObject_FromNumber<T>(self->super_type[n][m]));
		}
		PyList_SET_ITEM(out, n, innerList);
	}
	return out;
}

template<int C, int R, typename T>
static PyObject*
mat_to_tuple(mat<C, R, T>* self, PyObject*) {
	PyObject* out = PyTuple_New(C);
	for (int n = 0; n < C; n++) {
		PyObject* innerList = PyTuple_New(R);
		for (int m = 0; m < R; m++) {
			PyTuple_SET_ITEM(innerList, m, PyGLM_PyObject_FromNumber<T>(self->super_type[n][m]));
		}
		PyTuple_SET_ITEM(out, n, innerList);
	}
	return out;
}

template<int C, int R, typename T>
static PyObject* 
mat_setstate(mat<C, R, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == C, "Invalid state.");
	for (int c = 0; c < C; c++) {
		PyObject* innerList = PyTuple_GET_ITEM(state, c);
		PyGLM_ASSERT(PyTuple_CheckExact(innerList) && PyTuple_GET_SIZE(innerList) == R, "Invalid state.");
		for (int r = 0; r < R; r++) {
			self->super_type[c][r] = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(innerList, r));
		}
	}
	Py_RETURN_NONE;
}