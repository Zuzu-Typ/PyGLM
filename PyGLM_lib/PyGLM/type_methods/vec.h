#pragma once

#include "../compiler_setup.h"

#include "../internal_functions/all.h"

#include "../types/vec/all.h"

static void
vec_dealloc(PyObject* self)
{
	Py_TYPE(self)->tp_free(self);
}

template<int L, typename T>
static PyObject *
vec_new(PyTypeObject *type, PyObject *, PyObject *)
{
	vec<L, T> *self = (vec<L, T> *)type->tp_alloc(type, 0);
	if (self != NULL) {
		//constexpr uint8_t info_type = get_type_helper_type<T>();
		//constexpr uint8_t info = L | (info_type << PyGLM_TYPE_INFO_VEC_TYPE_OFFSET);
		//self->info = info;
		self->super_type = glm::vec<L, T>();
	}

	return (PyObject *)self;
}


template<typename T>
static int
vec1_init(vec<1, T> *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", NULL };

	PyObject * arg = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|O", const_cast<char**>(kwlist),
		&arg)) {
		if (arg == NULL) {
			return 0;
		}
		if (PyGLM_Number_Check(arg)) {
			self->super_type = glm::vec<1, T>(PyGLM_Number_FromPyObject<T>(arg));
			return 0;
		}
		PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_ALL | PyGLM_PTI_GetDT(T));
		if (PyGLM_Vec_PTI_Check0(1, T, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, T, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(2, T, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(2, T, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(3, T, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(3, T, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(4, T, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(4, T, arg);
			return 0;
		}

		PyGLM_PTI_Init0(arg, PyGLM_T_ANY_VEC | PyGLM_SHAPE_1 | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, float, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, double, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, int32, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, int32, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, uint32, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, uint32, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, int64, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, int64, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, uint64, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, uint64, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, int16, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, int16, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, uint16, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, uint16, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, int8, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, int8, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, uint8, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, uint8, arg);
			return 0;
		}
		if (PyGLM_Vec_PTI_Check0(1, bool, arg)) {
			self->super_type = PyGLM_Vec_PTI_Get0(1, bool, arg);
			return 0;
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec()");
		return -1;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec()");
	return -1;
}

template<typename T>
static int
vec2_init(vec<2, T> *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OO", const_cast<char**>(kwlist),
		&arg1, &arg2)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				self->super_type = glm::vec<2, T>(PyGLM_Number_FromPyObject<T>(arg1));
				return 0;
			}

			PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_PTI_GetDT(T));
			if (PyGLM_Vec_PTI_Check0(2, T, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, T, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, T, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, T, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, T, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, T, arg1);
				return 0;
			}

			PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_2 | PyGLM_DT_ALL);
			if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, float, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, double, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, int32, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, int32, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, uint32, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, uint32, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, int64, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, int64, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, uint64, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, uint64, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, int16, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, int16, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, uint16, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, uint16, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, int8, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, int8, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, uint8, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, uint8, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(2, bool, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(2, bool, arg1);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			self->super_type = glm::vec<2, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec()");
	return -1;
}

template<typename T>
static int
vec3_init(vec<3, T> *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", "z", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOO", const_cast<char**>(kwlist),
		&arg1, &arg2, &arg3)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				self->super_type = glm::vec<3, T>(PyGLM_Number_FromPyObject<T>(arg1));
				return 0;
			}

			PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_3 | PyGLM_SHAPE_4 | PyGLM_PTI_GetDT(T));
			if (PyGLM_Vec_PTI_Check0(3, T, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, T, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, T, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, T, arg1);
				return 0;
			}

			PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_3 | PyGLM_DT_ALL);
			if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, float, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, double, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, int32, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, int32, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, uint32, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, uint32, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, int64, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, int64, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, uint64, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, uint64, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, int16, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, int16, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, uint16, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, uint16, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, int8, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, int8, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, uint8, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, uint8, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(3, bool, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(3, bool, arg1);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<2, T>()));
				if (PyGLM_PTI_IsNone(1)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
					return -1;
				}
				glm::vec<2, T> o = PyGLM_Vec_PTI_Get1(2, T, arg2);
				self->super_type = glm::vec<3, T>(PyGLM_Number_FromPyObject<T>(arg1), o);
				return 0;
			}
			if (PyGLM_Number_Check(arg2)) {
				PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<2, T>()));
				if (PyGLM_PTI_IsNone(0)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
					return -1;
				}
				glm::vec<2, T> o = PyGLM_Vec_PTI_Get0(2, T, arg1);
				self->super_type = glm::vec<3, T>(o, PyGLM_Number_FromPyObject<T>(arg2));
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
			self->super_type = glm::vec<3, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec3()");
	return -1;
}

template<typename T>
static int
vec4_init(vec<4, T> *self, PyObject *args, PyObject *kwds)
{
	const char *kwlist[] = { "x", "y", "z", "w", NULL };

	PyObject * arg1 = NULL;
	PyObject * arg2 = NULL;
	PyObject * arg3 = NULL;
	PyObject * arg4 = NULL;

	if (PyArg_ParseTupleAndKeywords(args, kwds, "|OOOO", const_cast<char**>(kwlist),
		&arg1, &arg2, &arg3, &arg4)) {
		if (arg1 == NULL) {
			return 0;
		}
		if (arg2 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				self->super_type = glm::vec<4, T>(PyGLM_Number_FromPyObject<T>(arg1));
				return 0;
			}

			PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_4 | PyGLM_PTI_GetDT(T));
			if (PyGLM_Vec_PTI_Check0(4, T, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, T, arg1);
				return 0;
			}

			PyGLM_PTI_Init0(arg1, PyGLM_T_ANY_VEC | PyGLM_SHAPE_4 | PyGLM_DT_ALL);
			if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, float, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, double, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, int32, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, int32, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, uint32, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, uint32, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, int64, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, int64, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, uint64, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, uint64, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, int16, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, int16, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, uint16, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, uint16, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, int8, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, int8, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, uint8, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, uint8, arg1);
				return 0;
			}
			if (PyGLM_Vec_PTI_Check0(4, bool, arg1)) {
				self->super_type = PyGLM_Vec_PTI_Get0(4, bool, arg1);
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
			return -1;
		}
		if (arg3 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<3, T>()));
				if (PyGLM_PTI_IsNone(1)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
					return -1;
				}
				glm::vec<3, T> o = PyGLM_Vec_PTI_Get1(3, T, arg2);
				self->super_type = glm::vec<4, T>(PyGLM_Number_FromPyObject<T>(arg1), o);
				return 0;
			}
			if (PyGLM_Number_Check(arg2)) {
				PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<3, T>()));
				if (PyGLM_PTI_IsNone(0)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
					return -1;
				}
				glm::vec<3, T> o = PyGLM_Vec_PTI_Get0(3, T, arg1);
				self->super_type = glm::vec<4, T>(o, PyGLM_Number_FromPyObject<T>(arg2));
				return 0;
			}
			PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<2, T>()));
			PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<2, T>()));
			if (PyGLM_PTI_IsNone(0) || PyGLM_PTI_IsNone(1)) {
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
				return -1;
			}
			PyGLM_Vec_PTI_Assign0(2, T);
			PyGLM_Vec_PTI_Assign1(2, T);
			self->super_type = glm::vec<4, T>(o, o2);
			return 0;
		}
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1)) {
				if (PyGLM_Number_Check(arg2)) {
					PyGLM_PTI_Init2(arg3, (get_vec_PTI_info<2, T>()));
					if (PyGLM_PTI_IsNone(2)) {
						PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
						return -1;
					}
					glm::vec<2, T> o = PyGLM_Vec_PTI_Get2(2, T, arg3);
					self->super_type = glm::vec<4, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), o);
					return 0;
				}
				if (PyGLM_Number_Check(arg3)) {
					PyGLM_PTI_Init1(arg2, (get_vec_PTI_info<2, T>()));
					if (PyGLM_PTI_IsNone(1)) {
						PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
						return -1;
					}
					glm::vec<2, T> o = PyGLM_Vec_PTI_Get1(2, T, arg2);
					self->super_type = glm::vec<4, T>(PyGLM_Number_FromPyObject<T>(arg1), o, PyGLM_Number_FromPyObject<T>(arg3));
					return 0;
				}
				PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
				return -1;
			}
			if (PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				PyGLM_PTI_Init0(arg1, (get_vec_PTI_info<2, T>()));
				if (PyGLM_PTI_IsNone(0)) {
					PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
					return -1;
				}
				glm::vec<2, T> o = PyGLM_Vec_PTI_Get0(2, T, arg1);
				self->super_type = glm::vec<4, T>(o, PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3));
				return 0;
			}
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
			return -1;
		}
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
			self->super_type = glm::vec<4, T>(PyGLM_Number_FromPyObject<T>(arg1), PyGLM_Number_FromPyObject<T>(arg2), PyGLM_Number_FromPyObject<T>(arg3), PyGLM_Number_FromPyObject<T>(arg4));
			return 0;
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for vec4()");
	return -1;
}

// unaryfunc
template<int L, typename T>
static PyObject *
vec_neg(vec<L, T> *obj)
{
	return pack_vec<L, T>(-obj->super_type);
}

template<int L>
static PyObject* 
bvec_neg(vec<L, bool>* obj)
{
	return pack_vec<L, bool>(glm::not_(obj->super_type));
}

template<int L, typename T>
static PyObject *
vec_pos(vec<L, T> *obj)
{
	return pack_vec<L, T>(obj->super_type);
}

template<int L, typename T>
static PyObject *
vec_abs(vec<L, T> *obj)
{
	return pack_vec<L, T>(glm::abs(obj->super_type));
}

template<int L, typename T>
static PyObject*
vec_invert(vec<L, T>* obj)
{
	return pack_vec<L, T>(~obj->super_type);
}

// binaryfunc
template<int L, typename T>
static PyObject *
vec_add(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) + (((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o + PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o + o2);
}

template<int L>
static PyObject*
bvec_add(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, bool>(glm::vec<L, bool>(PyGLM_Number_FromPyObject<bool>(obj1)) || (((vec<L, bool>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, bool>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for +: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, bool> o = PyGLM_Vec_PTI_Get0(L, bool, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, bool>(o || glm::vec<L, bool>(PyGLM_Number_FromPyObject<bool>(obj2)));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, bool>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, bool> o2 = PyGLM_Vec_PTI_Get1(L, bool, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, bool>(o || o2);
}

template<int L, typename T>
static PyObject *
vec_sub(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) - ((vec<L, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for -: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o - PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o - o2);
}

template<int L, typename T>
static PyObject *
vec_mul(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) * ((vec<L, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o * PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o * o2);
}

template<int L>
static PyObject*
bvec_mul(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, bool>(glm::vec<L, bool>(PyGLM_Number_FromPyObject<bool>(obj1)) && ((vec<L, bool>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, bool>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for *: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, bool> o = PyGLM_Vec_PTI_Get0(L, bool, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, bool>(o && glm::vec<L, bool>(PyGLM_Number_FromPyObject<bool>(obj2)));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, bool>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, bool> o2 = PyGLM_Vec_PTI_Get1(L, bool, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, bool>(o && o2);
}

template<int L, typename T>
static PyObject *
vec_div(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		if (!glm::all((glm::vec<L, bool>)(((vec<L, T>*)obj2)->super_type))) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) / ((vec<L, T>*)obj2)->super_type);
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(o / o2);
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a vec
	return  pack_vec<L, T>(o / o2);
}

template<int L, typename T>
static glm::vec<L, T>
ivec_floordivmod(glm::vec<L, T> a, glm::vec<L, T> b) {
	const glm::vec<L, T> u = glm::abs(a);
	const glm::vec<L, T> v = glm::abs(b);

	glm::vec<L, T> result;

	for (int i = 0; i < L; i++) {
		T q = u[i] / v[i];
		T r = u[i] % v[i];
		if ((a[i] < 0) != (b[i] < 0)) {
			result[i] = -(q + (r > 0));
		} else {
			result[i] = q;
		}
	}

	return result;
}

template<int L, typename T>
static PyObject *
ivec_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		PyObject* temp = pack_vec(glm::vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1)));
		PyObject* result = ivec_floordiv<L, T>(temp, obj2);
		Py_DECREF(temp);
		return result;
	}

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		PyObject* temp = pack_vec(glm::vec<L, T>(PyGLM_Number_FromPyObject<T>(obj2)));
		PyObject* result = ivec_floordiv<L, T>(obj1, temp);
		Py_DECREF(temp);
		return result;
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for /: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a vec
	return  pack_vec<L, T>(ivec_floordivmod<L, T>(o, o2));
}

template<int L>
static inline glm::vec<L, float>
vec_mod_f(glm::vec<L, float> a, glm::vec<L, float> b) {
	return glm::mod(a, b);
}

template<int L>
static inline glm::vec<L, double>
vec_mod_f(glm::vec<L, double> a, glm::vec<L, double> b) {
	return glm::mod(a, b);
}

template<int L, typename T>
static inline glm::vec<L, T>
vec_mod_f(glm::vec<L, T> a, glm::vec<L, T> b) {
	glm::vec<L, T> out{};

	for (int i = 0; i < L; i++) {
		out[i] = a[i] % b[i];
	}

	return out;
}

template<int L, typename T>
static PyObject *
vec_mod(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		if (!glm::all((glm::vec<L, bool>)(((vec<L, T>*)obj2)->super_type))) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(vec_mod_f(glm::vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1)), ((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for %: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(vec_mod_f(o, glm::vec<L, T>(o2)));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(vec_mod_f(o, o2));
}

template<int L, typename T>
static PyObject *
vec_floordiv(PyObject *obj1, PyObject *obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		if (!glm::all((glm::vec<L, bool>)(((vec<L, T>*)obj2)->super_type))) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(floor(PyGLM_Number_FromPyObject<T>(obj1) / ((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for //: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T o2 = PyGLM_Number_FromPyObject<T>(obj2);
		if (o2 == (T)0) {
			PyGLM_ZERO_DIVISION_ERROR_T(T);
		}
		return pack_vec<L, T>(floor(o / o2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	if (!glm::all((glm::vec<L, bool>)o2)) {
		PyGLM_ZERO_DIVISION_ERROR_T(T);
	}

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(floor(o / o2));
}

template<int L, typename T>
static PyObject *
vec_divmod(PyObject * obj1, PyObject * obj2) {
	PyObject *arg1, *arg2;
	arg1 = vec_floordiv<L, T>(obj1, obj2);
	arg2 = vec_mod<L, T>(obj1, obj2);
	if (arg1 == NULL || arg2 == NULL) {
		return NULL;
	}
	PyObject* out = PyTuple_Pack(2, arg1, arg2);
	Py_DECREF(arg1);
	Py_DECREF(arg2);
	return out;
}

template<int L, typename T>
static PyObject*
vec_or(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) | (((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for |: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o | PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o | o2);
}

template<int L, typename T>
static PyObject*
vec_and(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) & (((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for &: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o & PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o & o2);
}

template<int L, typename T>
static PyObject*
vec_xor(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) ^ (((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for ^: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o ^ PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o ^ o2);
}

template<int L, typename T>
static PyObject*
vec_lshift(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) << (((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for <<: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o << PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o << o2);
}

template<int L, typename T>
static PyObject*
vec_rshift(PyObject* obj1, PyObject* obj2)
{
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		return pack_vec<L, T>(PyGLM_Number_FromPyObject<T>(obj1) >> (((vec<L, T>*)obj2)->super_type));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for >>: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		return pack_vec<L, T>(o >> PyGLM_Number_FromPyObject<T>(obj2));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is self, obj2 is something else
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	return pack_vec<L, T>(o >> o2);
}

// ternaryfunc
template<int L, typename T>
static PyObject *
vec_pow(PyObject * obj1, PyObject * obj2, PyObject * obj3) {
	if (PyGLM_Number_Check(obj1)) { // obj1 is a scalar, obj2 is self
		T f = PyGLM_Number_FromPyObject<T>(obj1);

		if (obj3 == Py_None) {
			return pack_vec<L, T>(glm::pow(glm::vec<L, T>(f), ((vec<L, T>*)obj2)->super_type));
		}

		if (PyGLM_Number_Check(obj3)) {
			T f2 = PyGLM_Number_FromPyObject<T>(obj3);
			return pack_vec<L, T>(glm::mod(glm::pow(glm::vec<L, T>(f), ((vec<L, T>*)obj2)->super_type), glm::vec<L, T>(f2)));
		}

		PyGLM_PTI_Init2(obj3, (get_vec_PTI_info<L, T>()));

		if (PyGLM_PTI_IsNone(2)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get3(L, T, obj3);

		return pack_vec<L, T>(glm::mod(glm::pow(glm::vec<L, T>(f), ((vec<L, T>*)obj2)->super_type), o3));
	}

	PyGLM_PTI_Init0(obj1, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(0)) { // obj1 is not supported.
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: 'glm.vec' and ", obj1);
		return NULL;
	}

	glm::vec<L, T> o = PyGLM_Vec_PTI_Get0(L, T, obj1);

	if (PyGLM_Number_Check(obj2)) { // obj1 is self, obj2 is a scalar
		T f = PyGLM_Number_FromPyObject<T>(obj2);

		if (obj3 == Py_None) {
			return pack_vec<L, T>(glm::pow(o, glm::vec<L, T>(f)));
		}

		if (PyGLM_Number_Check(obj3)) {
			T f2 = PyGLM_Number_FromPyObject<T>(obj3);
			return pack_vec<L, T>(glm::mod(glm::pow(o, glm::vec<L, T>(f)), glm::vec<L, T>(f2)));
		}

		PyGLM_PTI_Init2(obj3, (get_vec_PTI_info<L, T>()));

		if (PyGLM_PTI_IsNone(2)) {
			PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
			return NULL;
		}

		glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get3(L, T, obj3);

		return pack_vec<L, T>(glm::mod(glm::pow(o, glm::vec<L, T>(f)), o3));
	}

	PyGLM_PTI_Init1(obj2, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(1)) { // obj1 is not supported.
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, obj2);

	// obj1 and obj2 can be interpreted as a vec
	if (obj3 == Py_None) {
		return pack_vec<L, T>(glm::pow(o, o2));
	}

	if (PyGLM_Number_Check(obj3)) {
		T f2 = PyGLM_Number_FromPyObject<T>(obj3);
		return pack_vec<L, T>(glm::mod(glm::pow(o, o2), glm::vec<L, T>(f2)));
	}

	PyGLM_PTI_Init2(obj3, (get_vec_PTI_info<L, T>()));

	if (PyGLM_PTI_IsNone(2)) {
		PyGLM_TYPEERROR_O("unsupported operand type(s) for **: ", obj3);
		return NULL;
	}

	glm::vec<L, T> o3 = PyGLM_Vec_PTI_Get2(L, T, obj3);

	return pack_vec<L, T>(glm::mod(glm::pow(o, o2), o3));
}

static PyObject*
vec_matmul(PyObject* obj1, PyObject* obj2)
{
	PyObject* out = PyNumber_Multiply(obj1, obj2);
	if (out == NULL) {
		PyGLM_TYPEERROR_2O("unsupported operand type(s) for @: ", obj1, obj2);
	}
	return out;
}

// inplace
// binaryfunc
template<int L, typename T>
static PyObject *
vec_iadd(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)vec_add<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L>
static PyObject*
bvec_iadd(vec<L, bool>* self, PyObject* obj)
{
	vec<L, bool>* temp = (vec<L, bool>*)bvec_add<L>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject *
vec_isub(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)vec_sub<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject *
vec_imul(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)vec_mul<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L>
static PyObject*
bvec_imul(vec<L, bool>* self, PyObject* obj)
{
	vec<L, bool>* temp = (vec<L, bool>*)bvec_mul<L>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject *
vec_idiv(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)vec_div<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject *
vec_imod(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)vec_mod<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject *
vec_ifloordiv(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)vec_floordiv<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject *
ivec_ifloordiv(vec<L, T> *self, PyObject *obj)
{
	vec<L, T> * temp = (vec<L, T>*)ivec_floordiv<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject*
vec_imatmul(vec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)vec_matmul((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	if (!PyGLM_Vec_Check(L, T, temp)) {
		Py_DECREF(temp);
		Py_RETURN_NOTIMPLEMENTED;
	}

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject*
vec_ilshift(vec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)vec_lshift<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject*
vec_irshift(vec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)vec_rshift<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject*
vec_iand(vec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)vec_and<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject*
vec_ixor(vec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)vec_xor<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<int L, typename T>
static PyObject*
vec_ior(vec<L, T>* self, PyObject* obj)
{
	vec<L, T>* temp = (vec<L, T>*)vec_or<L, T>((PyObject*)self, obj);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

// ternaryfunc
template<int L, typename T>
static PyObject *
vec_ipow(vec<L, T> *self, PyObject *obj1, PyObject *) // obj2 is unused. It points to an invalid address!
{
	vec<L, T> * temp = (vec<L, T>*)vec_pow<L, T>((PyObject*)self, obj1, Py_None);

	if (Py_IS_NOTIMPLEMENTED(temp)) return (PyObject*)temp;

	self->super_type = temp->super_type;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

template<typename T>
static PyObject *
vec1_str(vec<1, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 17 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g )", name, (double)self->super_type.x);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec2_str(vec<2, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 31 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g )", name, (double)self->super_type.x, (double)self->super_type.y);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec3_str(vec<3, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 45 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g, %12.6g )", name, (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec4_str(vec<4, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 59 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %12.6g, %12.6g, %12.6g, %12.6g )", name, (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z, (double)self->super_type.w);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec1_repr(vec<1, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 17 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %.6g )", name, (double)self->super_type.x);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec2_repr(vec<2, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 31 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %.6g, %.6g )", name, (double)self->super_type.x, (double)self->super_type.y);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec3_repr(vec<3, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 45 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %.6g, %.6g, %.6g )", name, (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<typename T>
static PyObject *
vec4_repr(vec<4, T>* self)
{
	const char* name = PyGLM_GET_NAME(((PyObject*)self)->ob_type->tp_name);
	size_t required_space = 59 + strlen(name);
	char * out = (char*)PyMem_Malloc((required_space) * sizeof(char));
	snprintf(out, required_space, "%s( %.6g, %.6g, %.6g, %.6g )", name, (double)self->super_type.x, (double)self->super_type.y, (double)self->super_type.z, (double)self->super_type.w);
	PyObject* po = PyUnicode_FromString(out);
	PyMem_Free(out);
	return po;
}

template<int L>
static Py_ssize_t vec_len(PyObject *) {
	return (Py_ssize_t)L;
}

template<typename T>
static PyObject* vec1_sq_item(vec<1, T> * self, Py_ssize_t index) {
	if (index == 0) {
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.x);
	}
	PyErr_SetString(PyExc_IndexError, "index out of range");
	return NULL;
}

template<typename T>
static PyObject* vec2_sq_item(vec<2, T> * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.x);
	case 1:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.y);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

template<typename T>
static PyObject* vec3_sq_item(vec<3, T> * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.x);
	case 1:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.y);
	case 2:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.z);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

template<typename T>
static PyObject* vec4_sq_item(vec<4, T> * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.x);
	case 1:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.y);
	case 2:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.z);
	case 3:
		return PyGLM_PyObject_FromNumber<T>((T)self->super_type.w);
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

template<typename T>
static int vec1_sq_ass_item(vec<1, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	if (index == 0) {
		self->super_type.x = f;
		return 0;
	}
	PyErr_SetString(PyExc_IndexError, "index out of range");
	return -1;
}

template<typename T>
static int vec2_sq_ass_item(vec<2, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

template<typename T>
static int vec3_sq_ass_item(vec<3, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	case 2:
		self->super_type.z = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

template<typename T>
static int vec4_sq_ass_item(vec<4, T> * self, Py_ssize_t index, PyObject * value) {
	T f;
	if (PyGLM_Number_Check(value)) {
		f = PyGLM_Number_FromPyObject<T>(value);
	}
	else {
		PyGLM_TYPEERROR_O("must be a real number, not ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->super_type.x = f;
		return 0;
	case 1:
		self->super_type.y = f;
		return 0;
	case 2:
		self->super_type.z = f;
		return 0;
	case 3:
		self->super_type.w = f;
		return 0;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

template<int L, typename T>
static int vec_contains(vec<L, T> * self, PyObject * value) {
	if (PyGLM_Number_Check(value)) {
		T f = PyGLM_Number_FromPyObject<T>(value);
		bool contains = false;
		for (int i = 0; i < L; i++) {
			if (f == self->super_type[i]) {
				contains = true;
				break;
			}
		}
		return (int)contains;
	}
	return 0;

}

template<int L, typename T>
static PyObject * vec_richcompare(vec<L, T> * self, PyObject * other, int comp_type) {
	PyGLM_PTI_Init1(other, (get_vec_PTI_info<L, T>()));
	if (PyGLM_PTI_IsNone(1)) {
		if (comp_type == Py_EQ) {
			Py_RETURN_FALSE;
		}
		if (comp_type == Py_NE) {
			Py_RETURN_TRUE;
		}
		Py_RETURN_NOTIMPLEMENTED;
	}

	glm::vec<L, T> o2 = PyGLM_Vec_PTI_Get1(L, T, other);

	switch (comp_type) {
	case Py_EQ:
		if (self->super_type == o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_NE:
		if (self->super_type != o2) Py_RETURN_TRUE;
		else Py_RETURN_FALSE;
		break;
	case Py_LT:
		return pack_vec<L, T>(glm::lessThan(self->super_type, o2));
		break;
	case Py_LE:
		return pack_vec<L, T>(glm::lessThanEqual(self->super_type, o2));
		break;
	case Py_GT:
		return pack_vec<L, T>(glm::greaterThan(self->super_type, o2));
		break;
	case Py_GE:
		return pack_vec<L, T>(glm::greaterThanEqual(self->super_type, o2));
		break;
	default:
		Py_RETURN_NOTIMPLEMENTED;
	}
}

template<typename T>
static bool unswizzle_vec(vec<1, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type.x;
		return true;
	}
	return false;
}

template<typename T>
static bool unswizzle_vec(vec<2, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type.x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		out = self->super_type.y;
		return true;
	}
	return false;
}

template<typename T>
static bool unswizzle_vec(vec<3, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type.x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		out = self->super_type.y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		out = self->super_type.z;
		return true;
	}
	return false;
}

template<typename T>
static bool unswizzle_vec(vec<4, T> * self, char c, T& out) {
	if (c == 'x' || c == 'r' || c == 's') {
		out = self->super_type.x;
		return true;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		out = self->super_type.y;
		return true;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		out = self->super_type.z;
		return true;
	}
	if (c == 'w' || c == 'a' || c == 'p') {
		out = self->super_type.w;
		return true;
	}
	return false;
}

template<typename T>
static T& unswizzle2_vec(vec<1, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type.x;
	}
	success = false;
	return self->super_type.x;
}

template<typename T>
static T& unswizzle2_vec(vec<2, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type.x;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		success = success && true;
		return self->super_type.y;
	}
	success = false;
	return self->super_type.x;
}

template<typename T>
static T& unswizzle2_vec(vec<3, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type.x;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		success = success && true;
		return self->super_type.y;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		success = success && true;
		return self->super_type.z;
	}
	success = false;
	return self->super_type.x;
}

template<typename T>
static T& unswizzle2_vec(vec<4, T> * self, char c, bool& success) {
	if (c == 'x' || c == 'r' || c == 's') {
		success = success && true;
		return self->super_type.x;
	}
	if (c == 'y' || c == 'g' || c == 't') {
		success = success && true;
		return self->super_type.y;
	}
	if (c == 'z' || c == 'b' || c == 'q') {
		success = success && true;
		return self->super_type.z;
	}
	if (c == 'w' || c == 'a' || c == 'p') {
		success = success && true;
		return self->super_type.w;
	}
	success = false;
	return self->super_type.x;
}

//template<int L, typename T>
//static bool unswizzle_vec(vec<L, T>* self, char c, T& out) {
//	if (L == 2) {
//		return unswizzle_vec2<T>(self, c, out);
//	}
//	if (L == 3) {
//		return unswizzle_vec3<T>(self, c, out);
//	}
//	return unswizzle_vec4<T>(self, c, out);
//}

template<int L, typename T>
static PyObject * vec_getattr(PyObject * obj, PyObject * name) {
	Py_ssize_t len;
	char* name_as_ccp;
	PyObject* asciiString = PyUnicode_AsASCIIString(name);
	if (asciiString == NULL)
		return NULL;
	if (PyBytes_AsStringAndSize(asciiString, &name_as_ccp, &len) != 0) {
		Py_DECREF(asciiString);
		return NULL;
	}

	PyObject * result = NULL;
	if (len >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[len - 1] == '_' && name_as_ccp[len - 2] == '_') {
		result = PyObject_GenericGetAttr(obj, name);
	}
	else if (len == 1) {
		T x;
		if (unswizzle_vec((vec<L, T> *)obj, name_as_ccp[0], x)) {
			result = PyGLM_PyObject_FromNumber<T>((T)x);
		}
	}
	else if (len == 2) {
		T x;
		T y;
		if (unswizzle_vec((vec<L, T> *)obj, name_as_ccp[0], x) && unswizzle_vec((vec<L, T> *)obj, name_as_ccp[1], y)) {
			result = pack_vec<2, T>(glm::vec<2, T>(x, y));
		}
	}
	else if (len == 3) {
		T x;
		T y;
		T z;
		if (unswizzle_vec((vec<L, T> *)obj, name_as_ccp[0], x) && unswizzle_vec((vec<L, T> *)obj, name_as_ccp[1], y) && unswizzle_vec((vec<L, T> *)obj, name_as_ccp[2], z)) {
			result = pack_vec<3, T>(glm::vec<3, T>(x, y, z));
		}
	}
	else if (len == 4) {
		T x;
		T y;
		T z;
		T w;
		if (unswizzle_vec((vec<L, T> *)obj, name_as_ccp[0], x) && unswizzle_vec((vec<L, T> *)obj, name_as_ccp[1], y) && unswizzle_vec((vec<L, T> *)obj, name_as_ccp[2], z) && unswizzle_vec((vec<L, T> *)obj, name_as_ccp[3], w)) {
			result = pack_vec<4, T>(glm::vec<4, T>(x, y, z, w));
		}
	}
	Py_DECREF(asciiString);
	if (result == NULL)    return PyObject_GenericGetAttr(obj, name);
	else                   return result;
}

template<int L, typename T>
static int vec_setattr(PyObject * obj, PyObject * name, PyObject* value) {

	if (value == NULL) {
		PyErr_SetString(PyExc_NotImplementedError, "deleting components is not permitted.");
		return -1;
	}

	PyObject* asciiString = PyUnicode_AsASCIIString(name);
	char* name_as_ccp = PyBytes_AsString(asciiString);
	size_t len = strlen(name_as_ccp);

	bool success = true;
	if (PyGLM_Number_Check(value)) {
		T v = PyGLM_Number_FromPyObject<T>(value);
		if (len == 1) {
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			if (success) {
				x = v;
			}
		}
		else if (len == 2) {
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[1], success);
			if (success) {
				x = v;
				y = v;
			}
		}
		else if (len == 3) {
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[2], success);
			if (success) {
				x = v;
				y = v;
				z = v;
			}
		}
		else if (len == 4) {
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[2], success);
			T& w = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[3], success);
			if (success) {
				x = v;
				y = v;
				z = v;
				w = v;
			}
		}
	}
	else {
		PyGLM_PTI_Init0(value, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_PTI_GetDT(T));
		if (len == 1 && PyGLM_Vec_PTI_Check0(1, T, value)) {
			glm::vec<1, T> v = PyGLM_Vec_PTI_Get0(1, T, value);
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			if (success) {
				x = v.x;
			}
		}
		else if (len == 2 && PyGLM_Vec_PTI_Check0(2, T, value)) {
			glm::vec<2, T> v = PyGLM_Vec_PTI_Get0(2, T, value);
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[1], success);
			if (success) {
				x = v.x;
				y = v.y;
			}
		}
		else if (len == 3 && PyGLM_Vec_PTI_Check0(3, T, value)) {
			glm::vec<3, T> v = PyGLM_Vec_PTI_Get0(3, T, value);
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[2], success);
			if (success) {
				x = v.x;
				y = v.y;
				z = v.z;
			}
		}
		else if (len == 4 && PyGLM_Vec_PTI_Check0(4, T, value)) {
			glm::vec<4, T> v = PyGLM_Vec_PTI_Get0(4, T, value);
			T& x = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[0], success);
			T& y = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[1], success);
			T& z = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[2], success);
			T& w = unswizzle2_vec((vec<L, T>*)obj, name_as_ccp[3], success);
			if (success) {
				x = v.x;
				y = v.y;
				z = v.z;
				w = v.w;
			}
		}
	}
	Py_DECREF(asciiString);
	if (success)    return 0;
	else            return PyObject_GenericSetAttr(obj, name, value);
}

// iterator

template<int L, typename T>
static PyObject *
vecIter_new(PyTypeObject *type, PyObject *args, PyObject *)
{
	vec<L, T> *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	vecIter<L, T> *rgstate = (vecIter<L, T> *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	Py_INCREF(sequence);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

template<int L, typename T>
static void
vecIter_dealloc(vecIter<L, T> *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

template<typename T>
static PyObject *
vec1Iter_next(vecIter<1, T> *rgstate)
{
	if (rgstate->seq_index++ == 0) {
		return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.x);
	}
	rgstate->seq_index = 1;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<typename T>
static PyObject *
vec2Iter_next(vecIter<2, T> *rgstate)
{
	if (rgstate->seq_index < 2) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.x);
		case 1:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.y);
		}
	}
	rgstate->seq_index = 2;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<typename T>
static PyObject *
vec3Iter_next(vecIter<3, T> *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.x);
		case 1:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.y);
		case 2:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<typename T>
static PyObject *
vec4Iter_next(vecIter<4, T> *rgstate)
{
	if (rgstate->seq_index < 4) {
		switch (rgstate->seq_index++) {
		case 0:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.x);
		case 1:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.y);
		case 2:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.z);
		case 3:
			return PyGLM_PyObject_FromNumber<T>(rgstate->sequence->super_type.w);
		}
	}
	rgstate->seq_index = 4;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

template<int L, typename T>
static PyObject * vec_geniter(vec<L, T>* self) {
	vecIter<L, T> *rgstate = (vecIter<L, T> *)(PyGLM_VECITER_TYPE<L, T>()->tp_alloc(PyGLM_VECITER_TYPE<L, T>(), 0));
	if (!rgstate)
		return NULL;

	rgstate->sequence = self;
	Py_INCREF(self);
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

template<int L, typename T>
static int
vec_getbuffer(vec<L, T>* self, Py_buffer* view, int flags) {
	if (view == NULL) {
		PyErr_SetString(PyExc_ValueError, "NULL view in getbuffer");
		return -1;
	}
	view->obj = (PyObject*)self;
	view->buf = (void*)&self->super_type[0];
	view->len = sizeof(glm::vec<L, T>);
	view->readonly = 0;
	view->itemsize = sizeof(T);
	if (flags & PyBUF_FORMAT) {
		view->format = (std::is_same<T, float>::value) ? const_cast<char*>("f") : \
			(std::is_same <T, double>::value) ? const_cast<char*>("d") : \
			(std::is_same <T, std::int8_t>::value) ? const_cast<char*>("b") : \
			(std::is_same <T, std::uint8_t>::value) ? const_cast<char*>("B") : \
			(std::is_same <T, std::int16_t>::value) ? const_cast<char*>("h") : \
			(std::is_same <T, std::uint16_t>::value) ? const_cast<char*>("H") : \
			(std::is_same <T, std::int32_t>::value) ? const_cast<char*>("i") : \
			(std::is_same <T, std::uint32_t>::value) ? const_cast<char*>("I") : \
			(std::is_same <T, std::int64_t>::value) ? const_cast<char*>("q") : \
			(std::is_same <T, std::uint64_t>::value) ? const_cast<char*>("Q") : \
			(std::is_same <T, bool>::value) ? const_cast<char*>("?") : NULL;
	}
	else {
		view->format = NULL;
	}
	view->ndim = 1;
	if (flags & PyBUF_ND) {
		view->shape = (Py_ssize_t*)PyMem_Malloc(sizeof(Py_ssize_t));
		if (view->shape != NULL) {
			view->shape[0] = L;
		}
	}
	else {
		view->shape = NULL;
	}
	if ((flags & PyBUF_STRIDES) == PyBUF_STRIDES) {
		view->strides = &view->itemsize;
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
vec_releasebuffer(PyObject*, Py_buffer* view) {
	PyMem_Free(view->shape);
}




template<int L, typename T>
static PyObject*
vec_from_bytes(PyObject*, PyObject* arg) {
	PyTypeObject* type = PyGLM_VEC_TYPE<L, T>();
	if (PyBytes_Check(arg) && PyBytes_GET_SIZE(arg) == ((PyGLMTypeObject*)type)->itemSize) {
		char* bytesAsString = PyBytes_AS_STRING(arg);
		vec<L, T>* self = (vec<L, T> *)type->tp_alloc(type, 0);
		self->super_type = *(glm::vec<L, T>*)bytesAsString;
		return (PyObject*)self;
	}
	PyGLM_TYPEERROR_O("Invalid argument type for from_bytes(). Expected bytes, got ", arg);
	return NULL;
}

template<int L, typename T>
static Py_hash_t
vec_hash(vec<L, T>* self, PyObject*) {
	std::hash<glm::vec<L, T>> hasher;
	Py_hash_t out = (Py_hash_t)hasher(self->super_type);
	if (out == -1) {
		return -2;
	}
	return out;
}

template<typename T>
static PyObject*
vec1_to_list(vec<1, T>* self, PyObject*) {
	PyObject* out = PyList_New(1);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type.x));
	return out;
}

template<typename T>
static PyObject*
vec2_to_list(vec<2, T>* self, PyObject*) {
	PyObject* out = PyList_New(2);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type.x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type.y));
	return out;
}

template<typename T>
static PyObject*
vec3_to_list(vec<3, T>* self, PyObject*) {
	PyObject* out = PyList_New(3);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type.x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type.y));
	PyList_SET_ITEM(out, 2, PyGLM_PyObject_FromNumber<T>(self->super_type.z));
	return out;
}

template<typename T>
static PyObject*
vec4_to_list(vec<4, T>* self, PyObject*) {
	PyObject* out = PyList_New(4);
	PyList_SET_ITEM(out, 0, PyGLM_PyObject_FromNumber<T>(self->super_type.x));
	PyList_SET_ITEM(out, 1, PyGLM_PyObject_FromNumber<T>(self->super_type.y));
	PyList_SET_ITEM(out, 2, PyGLM_PyObject_FromNumber<T>(self->super_type.z));
	PyList_SET_ITEM(out, 3, PyGLM_PyObject_FromNumber<T>(self->super_type.w));
	return out;
}

template<typename T>
static PyObject*
vec1_to_tuple(vec<1, T>* self, PyObject*) {
	return PyTuple_Pack(1,
		PyGLM_PyObject_FromNumber<T>(self->super_type.x));
}

template<typename T>
static PyObject*
vec2_to_tuple(vec<2, T>* self, PyObject*) {
	return PyTuple_Pack(2,
		PyGLM_PyObject_FromNumber<T>(self->super_type.x),
		PyGLM_PyObject_FromNumber<T>(self->super_type.y));
}

template<typename T>
static PyObject*
vec3_to_tuple(vec<3, T>* self, PyObject*) {
	return PyTuple_Pack(3,
		PyGLM_PyObject_FromNumber<T>(self->super_type.x),
		PyGLM_PyObject_FromNumber<T>(self->super_type.y),
		PyGLM_PyObject_FromNumber<T>(self->super_type.z));
}

template<typename T>
static PyObject*
vec4_to_tuple(vec<4, T>* self, PyObject*) {
	return PyTuple_Pack(4,
		PyGLM_PyObject_FromNumber<T>(self->super_type.x),
		PyGLM_PyObject_FromNumber<T>(self->super_type.y),
		PyGLM_PyObject_FromNumber<T>(self->super_type.z),
		PyGLM_PyObject_FromNumber<T>(self->super_type.w));
}

template<typename T>
static PyObject* vec1_setstate(vec<1, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 1, "Invalid state. Expected a length 1 tuple.");
	self->super_type.x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	Py_RETURN_NONE;
}

template<typename T>
static PyObject* vec2_setstate(vec<2, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 2, "Invalid state. Expected a length 2 tuple.");
	self->super_type.x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type.y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	Py_RETURN_NONE;
}

template<typename T>
static PyObject* vec3_setstate(vec<3, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 3, "Invalid state. Expected a length 3 tuple.");
	self->super_type.x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type.y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	self->super_type.z = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 2));
	Py_RETURN_NONE;
}

template<typename T>
static PyObject* vec4_setstate(vec<4, T>* self, PyObject* state) {
	PyGLM_ASSERT(PyTuple_CheckExact(state) && PyTuple_GET_SIZE(state) == 4, "Invalid state. Expected a length 4 tuple.");
	self->super_type.x = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 0));
	self->super_type.y = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 1));
	self->super_type.z = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 2));
	self->super_type.w = PyGLM_Number_FromPyObject<T>(PyTuple_GET_ITEM(state, 3));
	Py_RETURN_NONE;
}
