#pragma once

#include "../../compiler_setup.h"

#include "../../types/all.h"

#include "../../internal_functions/all.h"

#include "../function_generator_macros.h"

PyDoc_STRVAR(abs_docstr,
	"abs(x: float) -> float\n"
	"	Returns `x` if `x >= 0`; otherwise it returns `-x`.\n"
	"abs(x: vecN) -> vecN\n"
	"	For each component `c` of `x`,\n"
	"	Returns `c` if `c >= 0`; otherwise it returns `-c`.\n"
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(abs)

PyDoc_STRVAR(sign_docstr,
	"sign(x: number) -> float\n"
	"	Returns `1.0` if `x > 0`, `0.0` if `x == 0`, or `-1.0` if `x < 0`.\n"
	"sign(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns `1.0` if `x > 0`, `0.0` if `x == 0`, or `-1.0` if `x < 0`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(sign)

PyDoc_STRVAR(floor_docstr,
	"floor(x: float) -> float\n"
	"	Returns a value equal to the nearest integer that is less then or equal to `x`.\n"
	"floor(v: vecN) -> vecN\n"
	"	For each component `c` of `v`:\n"
	"	Returns a value equal to the nearest integer that is less then or equal to `c`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(floor)

PyDoc_STRVAR(trunc_docstr,
	"trunc(x: number) -> float\n"
	"	Returns a value equal to the nearest integer to `x` whose absolute value is not larger than\n"
	"	the absolute value of `x`.\n"
	"trunc(x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns a value equal to the nearest integer to `c` whose absolute value is not larger than\n"
	"	the absolute value of `c`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(trunc)

PyDoc_STRVAR(round_docstr,
	"round(x: number) -> float\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest. This\n"
	"	includes the possibility that `round(x)` returns the same value as `roundEven(x)`\n"
	"round(x: vecN) -> vecN\n"
	"	Returns a value equal to the nearest integer to `x`. The fraction `0.5` will round in a\n"
	"	direction chosen by the implementation, presumably the direction that is fastest. This\n"
	"	includes the possibility that `round(x)` returns the same value as `roundEven(x)` for all\n"
	"	values of `x`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(round)

PyDoc_STRVAR(roundEven_docstr,
	"roundEven(x: number) -> float\n"
	"	Returns a value equal to the nearest integer to `x`. A fractional part of `0.5` will round\n"
	"	toward the nearest even integer. (Both `3.5` and `4.5` for `x` will return `4.0`.)\n"
	"roundEven(x: vecN) -> vecN\n"
	"	Returns a value equal to the nearest integer to `x`. A fractional part of `0.5` will round\n"
	"	toward the nearest even integer. (Both `3.5` and `4.5` for `x` will return `4.0`.)"
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(roundEven)

PyDoc_STRVAR(ceil_docstr,
	"ceil(x: float) -> float\n"
	"	Returns a value equal to the nearest integer that is greater than or equal to `x`.\n"
	"ceil(x: vecN) -> vecN\n"
	"	For each component `c` of `x`,\n"
	"	Returns a value equal to the nearest integer that is greater than or equal to `c`.\n"
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(ceil)

PyDoc_STRVAR(fract_docstr,
	"fract(x: float) -> float\n"
	"	Returns `x - floor(x)`.\n"
	"fract(c: vecN) -> vecN\n"
	"	Returns `x - floor(x)`."
);
PyGLM_MAKE_GLM_FUNC_N_V__tfF(fract)

PyDoc_STRVAR(mod_docstr,
	"mod(x: vecN, y: vecN) -> vecN\n"
	"	Returns `x - y * floor(x / y)` for each component in `x` using the floating point value `y`.\n"
	"mod(x: vecN, y: number) -> vecN\n"
	"	Returns `x - y * floor(x / y)` for each component in `x` using the floating point value `y`.\n"
	"mod(x: number, y: number) -> number\n"
	"	Returns `x - y * floor(x / y)` for each component in `x` using the floating point value `y`."
);
PyGLM_MAKE_GLM_FUNC_NN_VV_VN__tfF(mod)

PyDoc_STRVAR(min_docstr,
	"min(x: number, y: number) -> float\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`.\n"
	"min(x: vecN, y: number) -> vecN\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`.\n"
	"min(x: vecN, y: vecN) -> vecN\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`.\n"
	"min(a: number, b: number, c: number) -> float\n"
	"	Returns the minimum value of 3 inputs.\n"
	"min(a: vecN, b: vecN, c: vecN) -> vecN\n"
	"	Returns the minimum component wise value of 3 inputs.\n"
	"min(a: number, b: number, c: number, d: number) -> float\n"
	"	Returns the minimum value of 4 inputs.\n"
	"min(a: vecN, b: vecN, c: vecN, d: vecN) -> vecN\n"
	"	Returns the minimum component wise value of 4 inputs.\n"
	"min(iterable) -> any\n"
	"	Returns the smallest number or the minimum component wise value respectively."
);

template<typename T>
static T
apply_min(std::vector<T>& items) {
	T minimum = items[0];
	for (T item : items) {
		if (item == minimum) {
			continue;
		}
		minimum = glm::min(item, minimum);
	}
	return minimum;
}

template<typename T>
static inline PyObject*
apply_min_from_PyObject_number_vector(std::vector<PyObject*>& items) {
	std::vector<T> itemsAsT = std::vector<T>(items.size());

	for (size_t i = 0; i < items.size(); i++) {
		PyObject* item = items[i];
		itemsAsT[i] = PyGLM_Number_FromPyObject<T>(item);
		Py_DECREF(item);
	}

	return pack(apply_min(itemsAsT));
}

template<int L, typename T>
static inline PyObject*
apply_min_from_PyObject_vector_vector(std::vector<PyObject*>& items) {
	std::vector<glm::vec<L, T>> itemsAsVecT = std::vector<glm::vec<L, T>>(items.size());

	for (size_t i = 0; i < items.size(); i++) {
		PyObject* item = items[i];
		itemsAsVecT[i] = reinterpret_cast<vec<L, T>*>(item)->super_type;
		Py_DECREF(item);
	}

	return pack(apply_min(itemsAsVecT));
}

#define min_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(L) \
switch (pti->format) { \
case get_format_specifier<float>(): \
	return apply_min_from_PyObject_vector_vector<L, float>(items); \
case get_format_specifier<double>(): \
	return apply_min_from_PyObject_vector_vector<L, double>(items); \
case get_format_specifier<int32>(): \
	return apply_min_from_PyObject_vector_vector<L, int32>(items); \
case get_format_specifier<uint32>(): \
	return apply_min_from_PyObject_vector_vector<L, uint32>(items); \
case get_format_specifier<int64>(): \
	return apply_min_from_PyObject_vector_vector<L, int64>(items); \
case get_format_specifier<uint64>(): \
	return apply_min_from_PyObject_vector_vector<L, uint64>(items); \
case get_format_specifier<int16>(): \
	return apply_min_from_PyObject_vector_vector<L, int16>(items); \
case get_format_specifier<uint16>(): \
	return apply_min_from_PyObject_vector_vector<L, uint16>(items); \
case get_format_specifier<int8>(): \
	return apply_min_from_PyObject_vector_vector<L, int8>(items); \
case get_format_specifier<uint8>(): \
	return apply_min_from_PyObject_vector_vector<L, uint8>(items); \
case get_format_specifier<bool>(): \
	return apply_min_from_PyObject_vector_vector<L, bool>(items); \
}

static PyObject*
min_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "min", 1, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg2 == NULL) {
		if (PyObject_IterCheck(arg1)) {
			PyObject* iterator = PyObject_GetIter(arg1);

			std::vector<PyObject*> items{};

			PyTypeObject* type = NULL;

			PyObject* currentItem;
			while ((currentItem = PyIter_Next(iterator))) {
				if (type == NULL) {
					if ((currentItem->ob_type->tp_dealloc != (destructor)vec_dealloc) && !PyLong_Check(currentItem) && !PyFloat_Check(currentItem) && !PyBool_Check(currentItem)) {
						Py_DECREF(currentItem);
						Py_DECREF(iterator);
						PyGLM_TYPEERROR_O("invalid item type(s) for 'min()'. Expected number or PyGLM type, got ", currentItem);
						return NULL;
					}
					type = Py_TYPE(currentItem);
				}
				else if (type != Py_TYPE(currentItem)) {
					Py_DECREF(currentItem);
					for (PyObject* item : items) {
						Py_DECREF(item);
					}
					Py_DECREF(iterator);
					PyGLM_TYPEERROR_2O("invalid item type(s) for 'min()'. Expected items of equal type, got ", currentItem, items[0]);
					return NULL;
				}
				items.push_back(currentItem);
			}

			Py_DECREF(iterator);

			if (PyErr_Occurred()) {
				for (PyObject* item : items) {
					Py_DECREF(item);
				}
				return NULL;
			}

			if (items.size() == 0) {
				PyErr_SetString(PyExc_ValueError, "invalid argument value for 'min()'. Iterable has no items.");
				return NULL;
			}

			if (type == &PyLong_Type) {
				return apply_min_from_PyObject_number_vector<long>(items);
			}
			else if (type == &PyFloat_Type) {
				return apply_min_from_PyObject_number_vector<double>(items);
			}
			else if (type == &PyBool_Type) {
				return apply_min_from_PyObject_number_vector<bool>(items);
			}
			else {
				PyGLMTypeObject* pti = (PyGLMTypeObject*)type;

				switch (pti->C) {
				case 1:
					min_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(1);
					break;
				case 2:
					min_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(2);
					break;
				case 3:
					min_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(3);
					break;
				case 4:
					min_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(4);
					break;
				}
			}
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for min()");
		return NULL;
	}
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, bool, arg1), PyGLM_Vec_PTI_Get1(1, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, bool, arg1), PyGLM_Vec_PTI_Get1(2, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, bool, arg1), PyGLM_Vec_PTI_Get1(3, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, bool, arg1), PyGLM_Vec_PTI_Get1(4, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
	}
	else { 
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::min(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2) && PyGLM_Vec_PTI_Check2(1, int, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2), PyGLM_Vec_PTI_Get2(1, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(1, glm::uint, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2), PyGLM_Vec_PTI_Get2(1, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2), PyGLM_Vec_PTI_Get2(1, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2), PyGLM_Vec_PTI_Get2(1, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2), PyGLM_Vec_PTI_Get2(1, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2), PyGLM_Vec_PTI_Get2(1, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2), PyGLM_Vec_PTI_Get2(1, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2), PyGLM_Vec_PTI_Get2(1, glm::u8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2) && PyGLM_Vec_PTI_Check2(2, int, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2), PyGLM_Vec_PTI_Get2(2, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(2, glm::uint, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2), PyGLM_Vec_PTI_Get2(2, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2), PyGLM_Vec_PTI_Get2(2, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2), PyGLM_Vec_PTI_Get2(2, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2), PyGLM_Vec_PTI_Get2(2, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2), PyGLM_Vec_PTI_Get2(2, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2), PyGLM_Vec_PTI_Get2(2, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2), PyGLM_Vec_PTI_Get2(2, glm::u8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2) && PyGLM_Vec_PTI_Check2(3, int, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2), PyGLM_Vec_PTI_Get2(3, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(3, glm::uint, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2), PyGLM_Vec_PTI_Get2(3, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2), PyGLM_Vec_PTI_Get2(3, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2), PyGLM_Vec_PTI_Get2(3, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2), PyGLM_Vec_PTI_Get2(3, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2), PyGLM_Vec_PTI_Get2(3, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2), PyGLM_Vec_PTI_Get2(3, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2), PyGLM_Vec_PTI_Get2(3, glm::u8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2) && PyGLM_Vec_PTI_Check2(4, int, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2), PyGLM_Vec_PTI_Get2(4, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(4, glm::uint, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2), PyGLM_Vec_PTI_Get2(4, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2), PyGLM_Vec_PTI_Get2(4, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u64, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2), PyGLM_Vec_PTI_Get2(4, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2), PyGLM_Vec_PTI_Get2(4, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u16, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2), PyGLM_Vec_PTI_Get2(4, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2), PyGLM_Vec_PTI_Get2(4, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u8, arg3)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2), PyGLM_Vec_PTI_Get2(4, glm::u8, arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::min(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init3(arg4, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3) && PyGLM_Vec_PTI_Check3(1, float, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3), PyGLM_Vec_PTI_Get3(1, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3) && PyGLM_Vec_PTI_Check3(1, double, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3), PyGLM_Vec_PTI_Get3(1, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2) && PyGLM_Vec_PTI_Check2(1, int, arg3) && PyGLM_Vec_PTI_Check3(1, int, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2), PyGLM_Vec_PTI_Get2(1, int, arg3), PyGLM_Vec_PTI_Get3(1, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(1, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(1, glm::uint, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2), PyGLM_Vec_PTI_Get2(1, glm::uint, arg3), PyGLM_Vec_PTI_Get3(1, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(1, glm::i64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2), PyGLM_Vec_PTI_Get2(1, glm::i64, arg3), PyGLM_Vec_PTI_Get3(1, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(1, glm::u64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2), PyGLM_Vec_PTI_Get2(1, glm::u64, arg3), PyGLM_Vec_PTI_Get3(1, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(1, glm::i16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2), PyGLM_Vec_PTI_Get2(1, glm::i16, arg3), PyGLM_Vec_PTI_Get3(1, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(1, glm::u16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2), PyGLM_Vec_PTI_Get2(1, glm::u16, arg3), PyGLM_Vec_PTI_Get3(1, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(1, glm::i8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2), PyGLM_Vec_PTI_Get2(1, glm::i8, arg3), PyGLM_Vec_PTI_Get3(1, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(1, glm::u8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2), PyGLM_Vec_PTI_Get2(1, glm::u8, arg3), PyGLM_Vec_PTI_Get3(1, glm::u8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3) && PyGLM_Vec_PTI_Check3(2, float, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3), PyGLM_Vec_PTI_Get3(2, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3) && PyGLM_Vec_PTI_Check3(2, double, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3), PyGLM_Vec_PTI_Get3(2, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2) && PyGLM_Vec_PTI_Check2(2, int, arg3) && PyGLM_Vec_PTI_Check3(2, int, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2), PyGLM_Vec_PTI_Get2(2, int, arg3), PyGLM_Vec_PTI_Get3(2, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(2, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(2, glm::uint, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2), PyGLM_Vec_PTI_Get2(2, glm::uint, arg3), PyGLM_Vec_PTI_Get3(2, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(2, glm::i64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2), PyGLM_Vec_PTI_Get2(2, glm::i64, arg3), PyGLM_Vec_PTI_Get3(2, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(2, glm::u64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2), PyGLM_Vec_PTI_Get2(2, glm::u64, arg3), PyGLM_Vec_PTI_Get3(2, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(2, glm::i16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2), PyGLM_Vec_PTI_Get2(2, glm::i16, arg3), PyGLM_Vec_PTI_Get3(2, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(2, glm::u16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2), PyGLM_Vec_PTI_Get2(2, glm::u16, arg3), PyGLM_Vec_PTI_Get3(2, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(2, glm::i8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2), PyGLM_Vec_PTI_Get2(2, glm::i8, arg3), PyGLM_Vec_PTI_Get3(2, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(2, glm::u8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2), PyGLM_Vec_PTI_Get2(2, glm::u8, arg3), PyGLM_Vec_PTI_Get3(2, glm::u8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3) && PyGLM_Vec_PTI_Check3(3, float, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3), PyGLM_Vec_PTI_Get3(3, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3) && PyGLM_Vec_PTI_Check3(3, double, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3), PyGLM_Vec_PTI_Get3(3, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2) && PyGLM_Vec_PTI_Check2(3, int, arg3) && PyGLM_Vec_PTI_Check3(3, int, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2), PyGLM_Vec_PTI_Get2(3, int, arg3), PyGLM_Vec_PTI_Get3(3, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(3, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(3, glm::uint, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2), PyGLM_Vec_PTI_Get2(3, glm::uint, arg3), PyGLM_Vec_PTI_Get3(3, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(3, glm::i64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2), PyGLM_Vec_PTI_Get2(3, glm::i64, arg3), PyGLM_Vec_PTI_Get3(3, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(3, glm::u64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2), PyGLM_Vec_PTI_Get2(3, glm::u64, arg3), PyGLM_Vec_PTI_Get3(3, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(3, glm::i16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2), PyGLM_Vec_PTI_Get2(3, glm::i16, arg3), PyGLM_Vec_PTI_Get3(3, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(3, glm::u16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2), PyGLM_Vec_PTI_Get2(3, glm::u16, arg3), PyGLM_Vec_PTI_Get3(3, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(3, glm::i8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2), PyGLM_Vec_PTI_Get2(3, glm::i8, arg3), PyGLM_Vec_PTI_Get3(3, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(3, glm::u8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2), PyGLM_Vec_PTI_Get2(3, glm::u8, arg3), PyGLM_Vec_PTI_Get3(3, glm::u8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3) && PyGLM_Vec_PTI_Check3(4, float, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3), PyGLM_Vec_PTI_Get3(4, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3) && PyGLM_Vec_PTI_Check3(4, double, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3), PyGLM_Vec_PTI_Get3(4, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2) && PyGLM_Vec_PTI_Check2(4, int, arg3) && PyGLM_Vec_PTI_Check3(4, int, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2), PyGLM_Vec_PTI_Get2(4, int, arg3), PyGLM_Vec_PTI_Get3(4, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(4, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(4, glm::uint, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2), PyGLM_Vec_PTI_Get2(4, glm::uint, arg3), PyGLM_Vec_PTI_Get3(4, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(4, glm::i64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2), PyGLM_Vec_PTI_Get2(4, glm::i64, arg3), PyGLM_Vec_PTI_Get3(4, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(4, glm::u64, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2), PyGLM_Vec_PTI_Get2(4, glm::u64, arg3), PyGLM_Vec_PTI_Get3(4, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(4, glm::i16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2), PyGLM_Vec_PTI_Get2(4, glm::i16, arg3), PyGLM_Vec_PTI_Get3(4, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(4, glm::u16, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2), PyGLM_Vec_PTI_Get2(4, glm::u16, arg3), PyGLM_Vec_PTI_Get3(4, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(4, glm::i8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2), PyGLM_Vec_PTI_Get2(4, glm::i8, arg3), PyGLM_Vec_PTI_Get3(4, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(4, glm::u8, arg4)) {
				return pack(glm::min(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2), PyGLM_Vec_PTI_Get2(4, glm::u8, arg3), PyGLM_Vec_PTI_Get3(4, glm::u8, arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for min()");
	return NULL;
}

PyDoc_STRVAR(max_docstr,
	"max(x: number, y: number) -> float\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`.\n"
	"max(x: vecN, y: number) -> vecN\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`.\n"
	"max(x: vecN, y: vecN) -> vecN\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`.\n"
	"max(a: number, b: number, c: number) -> float\n"
	"	Returns the maximum value of 3 inputs.\n"
	"max(a: vecN, b: vecN, c: vecN) -> vecN\n"
	"	Returns the maximum component wise value of 3 inputs.\n"
	"max(a: number, b: number, c: number, d: number) -> float\n"
	"	Returns the maximum value of 4 inputs.\n"
	"max(a: vecN, b: vecN, c: vecN, d: vecN) -> vecN\n"
	"	Returns the maximum component wise value of 4 inputs.\n"
	"max(iterable) -> any\n"
	"	Returns the greatest number or the maximum component wise value respectively."
);
template<typename T>
static T
apply_max(std::vector<T>& items) {
	T maximum = items[0];
	for (T item : items) {
		if (item == maximum) {
			continue;
		}
		maximum = glm::max(item, maximum);
	}
	return maximum;
}

template<typename T>
static inline PyObject*
apply_max_from_PyObject_number_vector(std::vector<PyObject*>& items) {
	std::vector<T> itemsAsT = std::vector<T>(items.size());

	for (size_t i = 0; i < items.size(); i++) {
		PyObject* item = items[i];
		itemsAsT[i] = PyGLM_Number_FromPyObject<T>(item);
		Py_DECREF(item);
	}

	return pack(apply_max(itemsAsT));
}

template<int L, typename T>
static inline PyObject*
apply_max_from_PyObject_vector_vector(std::vector<PyObject*>& items) {
	std::vector<glm::vec<L, T>> itemsAsVecT = std::vector<glm::vec<L, T>>(items.size());

	for (size_t i = 0; i < items.size(); i++) {
		PyObject* item = items[i];
		itemsAsVecT[i] = reinterpret_cast<vec<L, T>*>(item)->super_type;
		Py_DECREF(item);
	}

	return pack(apply_max(itemsAsVecT));
}

#define max_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(L) \
switch (pti->format) { \
case get_format_specifier<float>(): \
	return apply_max_from_PyObject_vector_vector<L, float>(items); \
case get_format_specifier<double>(): \
	return apply_max_from_PyObject_vector_vector<L, double>(items); \
case get_format_specifier<int32>(): \
	return apply_max_from_PyObject_vector_vector<L, int32>(items); \
case get_format_specifier<uint32>(): \
	return apply_max_from_PyObject_vector_vector<L, uint32>(items); \
case get_format_specifier<int64>(): \
	return apply_max_from_PyObject_vector_vector<L, int64>(items); \
case get_format_specifier<uint64>(): \
	return apply_max_from_PyObject_vector_vector<L, uint64>(items); \
case get_format_specifier<int16>(): \
	return apply_max_from_PyObject_vector_vector<L, int16>(items); \
case get_format_specifier<uint16>(): \
	return apply_max_from_PyObject_vector_vector<L, uint16>(items); \
case get_format_specifier<int8>(): \
	return apply_max_from_PyObject_vector_vector<L, int8>(items); \
case get_format_specifier<uint8>(): \
	return apply_max_from_PyObject_vector_vector<L, uint8>(items); \
case get_format_specifier<bool>(): \
	return apply_max_from_PyObject_vector_vector<L, bool>(items); \
}

static PyObject*
max_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2 = NULL, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "max", 1, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg2 == NULL) {
		if (PyObject_IterCheck(arg1)) {
			PyObject* iterator = PyObject_GetIter(arg1);

			std::vector<PyObject*> items{};

			PyTypeObject* type = NULL;

			PyObject* currentItem;
			while ((currentItem = PyIter_Next(iterator))) {
				if (type == NULL) {
					if ((currentItem->ob_type->tp_dealloc != (destructor)vec_dealloc) && !PyLong_Check(currentItem) && !PyFloat_Check(currentItem) && !PyBool_Check(currentItem)) {
						Py_DECREF(currentItem);
						Py_DECREF(iterator);
						PyGLM_TYPEERROR_O("invalid item type(s) for 'max()'. Expected number or PyGLM type, got ", currentItem);
						return NULL;
					}
					type = Py_TYPE(currentItem);
				}
				else if (type != Py_TYPE(currentItem)) {
					Py_DECREF(currentItem);
					for (PyObject* item : items) {
						Py_DECREF(item);
					}
					Py_DECREF(iterator);
					PyGLM_TYPEERROR_2O("invalid item type(s) for 'max()'. Expected items of equal type, got ", currentItem, items[0]);
					return NULL;
				}
				items.push_back(currentItem);
			}

			Py_DECREF(iterator);

			if (PyErr_Occurred()) {
				for (PyObject* item : items) {
					Py_DECREF(item);
				}
				return NULL;
			}

			if (items.size() == 0) {
				PyErr_SetString(PyExc_ValueError, "invalid argument value for 'max()'. Iterable has no items.");
				return NULL;
			}

			if (type == &PyLong_Type) {
				return apply_max_from_PyObject_number_vector<long>(items);
			}
			else if (type == &PyFloat_Type) {
				return apply_max_from_PyObject_number_vector<double>(items);
			}
			else if (type == &PyBool_Type) {
				return apply_max_from_PyObject_number_vector<bool>(items);
			}
			else {
				PyGLMTypeObject* pti = (PyGLMTypeObject*)type;

				switch (pti->C) {
				case 1:
					max_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(1);
					break;
				case 2:
					max_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(2);
					break;
				case 3:
					max_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(3);
					break;
				case 4:
					max_GEN_TYPE_SWITCH_STATEMENT_FOR_VECTOR(4);
					break;
				}
			}
		}
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for max()");
		return NULL;
	}
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, bool, arg1), PyGLM_Vec_PTI_Get1(1, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, bool, arg1), PyGLM_Vec_PTI_Get1(2, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, bool, arg1), PyGLM_Vec_PTI_Get1(3, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, bool, arg1), PyGLM_Vec_PTI_Get1(4, bool, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Number_FromPyObject<int>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::max(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2) && PyGLM_Vec_PTI_Check2(1, int, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2), PyGLM_Vec_PTI_Get2(1, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(1, glm::uint, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2), PyGLM_Vec_PTI_Get2(1, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2), PyGLM_Vec_PTI_Get2(1, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2), PyGLM_Vec_PTI_Get2(1, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2), PyGLM_Vec_PTI_Get2(1, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2), PyGLM_Vec_PTI_Get2(1, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2), PyGLM_Vec_PTI_Get2(1, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2), PyGLM_Vec_PTI_Get2(1, glm::u8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2) && PyGLM_Vec_PTI_Check2(2, int, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2), PyGLM_Vec_PTI_Get2(2, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(2, glm::uint, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2), PyGLM_Vec_PTI_Get2(2, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2), PyGLM_Vec_PTI_Get2(2, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2), PyGLM_Vec_PTI_Get2(2, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2), PyGLM_Vec_PTI_Get2(2, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2), PyGLM_Vec_PTI_Get2(2, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2), PyGLM_Vec_PTI_Get2(2, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2), PyGLM_Vec_PTI_Get2(2, glm::u8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2) && PyGLM_Vec_PTI_Check2(3, int, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2), PyGLM_Vec_PTI_Get2(3, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(3, glm::uint, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2), PyGLM_Vec_PTI_Get2(3, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2), PyGLM_Vec_PTI_Get2(3, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2), PyGLM_Vec_PTI_Get2(3, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2), PyGLM_Vec_PTI_Get2(3, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2), PyGLM_Vec_PTI_Get2(3, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2), PyGLM_Vec_PTI_Get2(3, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2), PyGLM_Vec_PTI_Get2(3, glm::u8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2) && PyGLM_Vec_PTI_Check2(4, int, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2), PyGLM_Vec_PTI_Get2(4, int, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(4, glm::uint, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2), PyGLM_Vec_PTI_Get2(4, glm::uint, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2), PyGLM_Vec_PTI_Get2(4, glm::i64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u64, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2), PyGLM_Vec_PTI_Get2(4, glm::u64, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2), PyGLM_Vec_PTI_Get2(4, glm::i16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u16, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2), PyGLM_Vec_PTI_Get2(4, glm::u16, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2), PyGLM_Vec_PTI_Get2(4, glm::i8, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u8, arg3)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2), PyGLM_Vec_PTI_Get2(4, glm::u8, arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::max(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			PyGLM_PTI_Init3(arg4, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3) && PyGLM_Vec_PTI_Check3(1, float, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3), PyGLM_Vec_PTI_Get3(1, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3) && PyGLM_Vec_PTI_Check3(1, double, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3), PyGLM_Vec_PTI_Get3(1, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2) && PyGLM_Vec_PTI_Check2(1, int, arg3) && PyGLM_Vec_PTI_Check3(1, int, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2), PyGLM_Vec_PTI_Get2(1, int, arg3), PyGLM_Vec_PTI_Get3(1, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(1, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(1, glm::uint, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2), PyGLM_Vec_PTI_Get2(1, glm::uint, arg3), PyGLM_Vec_PTI_Get3(1, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(1, glm::i64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2), PyGLM_Vec_PTI_Get2(1, glm::i64, arg3), PyGLM_Vec_PTI_Get3(1, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(1, glm::u64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2), PyGLM_Vec_PTI_Get2(1, glm::u64, arg3), PyGLM_Vec_PTI_Get3(1, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(1, glm::i16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2), PyGLM_Vec_PTI_Get2(1, glm::i16, arg3), PyGLM_Vec_PTI_Get3(1, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(1, glm::u16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2), PyGLM_Vec_PTI_Get2(1, glm::u16, arg3), PyGLM_Vec_PTI_Get3(1, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(1, glm::i8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2), PyGLM_Vec_PTI_Get2(1, glm::i8, arg3), PyGLM_Vec_PTI_Get3(1, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(1, glm::u8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2), PyGLM_Vec_PTI_Get2(1, glm::u8, arg3), PyGLM_Vec_PTI_Get3(1, glm::u8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3) && PyGLM_Vec_PTI_Check3(2, float, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3), PyGLM_Vec_PTI_Get3(2, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3) && PyGLM_Vec_PTI_Check3(2, double, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3), PyGLM_Vec_PTI_Get3(2, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2) && PyGLM_Vec_PTI_Check2(2, int, arg3) && PyGLM_Vec_PTI_Check3(2, int, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2), PyGLM_Vec_PTI_Get2(2, int, arg3), PyGLM_Vec_PTI_Get3(2, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(2, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(2, glm::uint, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2), PyGLM_Vec_PTI_Get2(2, glm::uint, arg3), PyGLM_Vec_PTI_Get3(2, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(2, glm::i64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2), PyGLM_Vec_PTI_Get2(2, glm::i64, arg3), PyGLM_Vec_PTI_Get3(2, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(2, glm::u64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2), PyGLM_Vec_PTI_Get2(2, glm::u64, arg3), PyGLM_Vec_PTI_Get3(2, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(2, glm::i16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2), PyGLM_Vec_PTI_Get2(2, glm::i16, arg3), PyGLM_Vec_PTI_Get3(2, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(2, glm::u16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2), PyGLM_Vec_PTI_Get2(2, glm::u16, arg3), PyGLM_Vec_PTI_Get3(2, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(2, glm::i8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2), PyGLM_Vec_PTI_Get2(2, glm::i8, arg3), PyGLM_Vec_PTI_Get3(2, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(2, glm::u8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2), PyGLM_Vec_PTI_Get2(2, glm::u8, arg3), PyGLM_Vec_PTI_Get3(2, glm::u8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3) && PyGLM_Vec_PTI_Check3(3, float, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3), PyGLM_Vec_PTI_Get3(3, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3) && PyGLM_Vec_PTI_Check3(3, double, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3), PyGLM_Vec_PTI_Get3(3, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2) && PyGLM_Vec_PTI_Check2(3, int, arg3) && PyGLM_Vec_PTI_Check3(3, int, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2), PyGLM_Vec_PTI_Get2(3, int, arg3), PyGLM_Vec_PTI_Get3(3, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(3, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(3, glm::uint, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2), PyGLM_Vec_PTI_Get2(3, glm::uint, arg3), PyGLM_Vec_PTI_Get3(3, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(3, glm::i64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2), PyGLM_Vec_PTI_Get2(3, glm::i64, arg3), PyGLM_Vec_PTI_Get3(3, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(3, glm::u64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2), PyGLM_Vec_PTI_Get2(3, glm::u64, arg3), PyGLM_Vec_PTI_Get3(3, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(3, glm::i16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2), PyGLM_Vec_PTI_Get2(3, glm::i16, arg3), PyGLM_Vec_PTI_Get3(3, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(3, glm::u16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2), PyGLM_Vec_PTI_Get2(3, glm::u16, arg3), PyGLM_Vec_PTI_Get3(3, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(3, glm::i8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2), PyGLM_Vec_PTI_Get2(3, glm::i8, arg3), PyGLM_Vec_PTI_Get3(3, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(3, glm::u8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2), PyGLM_Vec_PTI_Get2(3, glm::u8, arg3), PyGLM_Vec_PTI_Get3(3, glm::u8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3) && PyGLM_Vec_PTI_Check3(4, float, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3), PyGLM_Vec_PTI_Get3(4, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3) && PyGLM_Vec_PTI_Check3(4, double, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3), PyGLM_Vec_PTI_Get3(4, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2) && PyGLM_Vec_PTI_Check2(4, int, arg3) && PyGLM_Vec_PTI_Check3(4, int, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2), PyGLM_Vec_PTI_Get2(4, int, arg3), PyGLM_Vec_PTI_Get3(4, int, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(4, glm::uint, arg3) && PyGLM_Vec_PTI_Check3(4, glm::uint, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2), PyGLM_Vec_PTI_Get2(4, glm::uint, arg3), PyGLM_Vec_PTI_Get3(4, glm::uint, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i64, arg3) && PyGLM_Vec_PTI_Check3(4, glm::i64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2), PyGLM_Vec_PTI_Get2(4, glm::i64, arg3), PyGLM_Vec_PTI_Get3(4, glm::i64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u64, arg3) && PyGLM_Vec_PTI_Check3(4, glm::u64, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2), PyGLM_Vec_PTI_Get2(4, glm::u64, arg3), PyGLM_Vec_PTI_Get3(4, glm::u64, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i16, arg3) && PyGLM_Vec_PTI_Check3(4, glm::i16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2), PyGLM_Vec_PTI_Get2(4, glm::i16, arg3), PyGLM_Vec_PTI_Get3(4, glm::i16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u16, arg3) && PyGLM_Vec_PTI_Check3(4, glm::u16, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2), PyGLM_Vec_PTI_Get2(4, glm::u16, arg3), PyGLM_Vec_PTI_Get3(4, glm::u16, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i8, arg3) && PyGLM_Vec_PTI_Check3(4, glm::i8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2), PyGLM_Vec_PTI_Get2(4, glm::i8, arg3), PyGLM_Vec_PTI_Get3(4, glm::i8, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u8, arg3) && PyGLM_Vec_PTI_Check3(4, glm::u8, arg4)) {
				return pack(glm::max(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2), PyGLM_Vec_PTI_Get2(4, glm::u8, arg3), PyGLM_Vec_PTI_Get3(4, glm::u8, arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for max()");
	return NULL;
}

PyDoc_STRVAR(fmin_docstr,
	"fmin(x: number, y: number) -> float\n"
	"	Returns `y` if `y < x`; otherwise, it returns `x`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmin(x: vecN, y: number) -> vecN\n"
	"	For each component `c` of `x`:\n"
	"	Returns `y` if `y < c`; otherwise, it returns `c`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmin(x: vecN, y: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `y[i]` if `y[i] < x[i]`; otherwise, it returns `x[i]`. If one of the two arguments is\n"
	"	`NaN`, the value of the other argument is returned.\n"
	"fmin(a: vecN, b: vecN, c : vecN) -> vecN\n"
	"	Returns `fmin(fmin(a, b), c)`.\n"
	"fmin(a: vecN, b: vecN, c : vecN, d: vecN) -> vecN\n"
	"	Returns `fmin(fmin(a, b), fmin(c, d))`."
);
static PyObject*
fmin_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "fmin", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::fmin(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::fmin(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init3(arg4, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3) && PyGLM_Vec_PTI_Check3(1, float, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3), PyGLM_Vec_PTI_Get3(1, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3) && PyGLM_Vec_PTI_Check3(1, double, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3), PyGLM_Vec_PTI_Get3(1, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3) && PyGLM_Vec_PTI_Check3(2, float, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3), PyGLM_Vec_PTI_Get3(2, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3) && PyGLM_Vec_PTI_Check3(2, double, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3), PyGLM_Vec_PTI_Get3(2, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3) && PyGLM_Vec_PTI_Check3(3, float, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3), PyGLM_Vec_PTI_Get3(3, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3) && PyGLM_Vec_PTI_Check3(3, double, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3), PyGLM_Vec_PTI_Get3(3, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3) && PyGLM_Vec_PTI_Check3(4, float, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3), PyGLM_Vec_PTI_Get3(4, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3) && PyGLM_Vec_PTI_Check3(4, double, arg4)) {
				return pack(glm::fmin(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3), PyGLM_Vec_PTI_Get3(4, double, arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fmin()");
	return NULL;
}

PyDoc_STRVAR(fmax_docstr,
	"fmax(x: number, y: number) -> float\n"
	"	Returns `y` if `x < y`; otherwise, it returns `x`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmax(x: vecN, y: number) -> vecN\n"
	"	For each component `c` of `x`:\n"
	"	Returns `y` if `c < y`; otherwise, it returns `c`. If one of the two arguments is `NaN`, the value\n"
	"	of the other argument is returned.\n"
	"fmax(x: vecN, y: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `y[i]` if `x[i] < y[i]`; otherwise, it returns `x[i]`. If one of the two arguments is\n"
	"	`NaN`, the value of the other argument is returned.\n"
	"fmax(a: vecN, b: vecN, c: vecN) -> vecN\n"
	"	Returns `fmax(fmax(a, b), c)`.\n"
	"fmax(a: vecN, b: vecN, c: vecN, d: vecN) -> vecN\n"
	"	Returns `fmax(fmax(a, b), fmax(c, d))`."
);
static PyObject*
fmax_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3 = NULL, *arg4 = NULL;
	if (!PyArg_UnpackTuple(args, "fmax", 2, 4, &arg1, &arg2, &arg3, &arg4)) return NULL;
	if (arg3 == NULL) {
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2)));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2)) {
			return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2)));
		}
	}
	else {
		if (arg4 == NULL) {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
				return pack(glm::fmax(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));
			}
		}
		else {
			if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg4)) {
				return pack(glm::fmax(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3), PyGLM_Number_FromPyObject<double>(arg4)));
			}
			PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			PyGLM_PTI_Init3(arg4, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
			if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3) && PyGLM_Vec_PTI_Check3(1, float, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3), PyGLM_Vec_PTI_Get3(1, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3) && PyGLM_Vec_PTI_Check3(1, double, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3), PyGLM_Vec_PTI_Get3(1, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3) && PyGLM_Vec_PTI_Check3(2, float, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3), PyGLM_Vec_PTI_Get3(2, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3) && PyGLM_Vec_PTI_Check3(2, double, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3), PyGLM_Vec_PTI_Get3(2, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3) && PyGLM_Vec_PTI_Check3(3, float, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3), PyGLM_Vec_PTI_Get3(3, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3) && PyGLM_Vec_PTI_Check3(3, double, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3), PyGLM_Vec_PTI_Get3(3, double, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3) && PyGLM_Vec_PTI_Check3(4, float, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3), PyGLM_Vec_PTI_Get3(4, float, arg4)));
			}
			if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3) && PyGLM_Vec_PTI_Check3(4, double, arg4)) {
				return pack(glm::fmax(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3), PyGLM_Vec_PTI_Get3(4, double, arg4)));
			}
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fmax()");
	return NULL;
}

PyDoc_STRVAR(clamp_docstr,
	"clamp(x: number, minVal: number, maxVal: number) -> number\n"
	"	Returns `min(max(x, minVal), maxVal)`.\n"
	"clamp(x: vecN, minVal: number, maxVal: number) -> vecN\n"
	"	Returns `min(max(x, minVal), maxVal)` for each component in `x` using the floating-point values\n"
	"	`minVal` and `maxVal`.\n"
	"clamp(x: vecN, minVal: vecN, maxVal: vecN) -> vecN\n"
	"	Returns `min(max(x, minVal), maxVal)` for each component in `x` using the floating-point values\n"
	"	`minVal` and `maxVal`.\n"
);
static PyObject*
clamp_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "clamp", arg1, arg2, arg3);
	if (PyFloat_Check(arg1) && PyFloat_Check(arg2) && PyFloat_Check(arg3)) {
		return pack(glm::clamp(PyFloat_AS_DOUBLE(arg1), PyFloat_AS_DOUBLE(arg2), PyFloat_AS_DOUBLE(arg3)));
	}
	if (PyLong_Check(arg1) && PyLong_Check(arg2) && PyLong_Check(arg3)) {
		return pack(glm::clamp(PyLong_AS_LONG(arg1), PyLong_AS_LONG(arg2), PyLong_AS_LONG(arg3)));
	}
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_I | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2) && PyGLM_Vec_PTI_Check2(1, float, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Vec_PTI_Get1(1, float, arg2), PyGLM_Vec_PTI_Get2(1, float, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2) && PyGLM_Vec_PTI_Check2(2, float, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Vec_PTI_Get1(2, float, arg2), PyGLM_Vec_PTI_Get2(2, float, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2) && PyGLM_Vec_PTI_Check2(3, float, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Vec_PTI_Get1(3, float, arg2), PyGLM_Vec_PTI_Get2(3, float, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2) && PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Vec_PTI_Get1(4, float, arg2), PyGLM_Vec_PTI_Get2(4, float, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, float, arg1), PyGLM_Number_FromPyObject<float>(arg2), PyGLM_Number_FromPyObject<float>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2) && PyGLM_Vec_PTI_Check2(1, double, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Vec_PTI_Get1(1, double, arg2), PyGLM_Vec_PTI_Get2(1, double, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2) && PyGLM_Vec_PTI_Check2(2, double, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Vec_PTI_Get1(2, double, arg2), PyGLM_Vec_PTI_Get2(2, double, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2) && PyGLM_Vec_PTI_Check2(3, double, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Vec_PTI_Get1(3, double, arg2), PyGLM_Vec_PTI_Get2(3, double, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2) && PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Vec_PTI_Get1(4, double, arg2), PyGLM_Vec_PTI_Get2(4, double, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, double, arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2) && PyGLM_Vec_PTI_Check2(1, int, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Vec_PTI_Get1(1, int, arg2), PyGLM_Vec_PTI_Get2(1, int, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2) && PyGLM_Vec_PTI_Check2(2, int, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Vec_PTI_Get1(2, int, arg2), PyGLM_Vec_PTI_Get2(2, int, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2) && PyGLM_Vec_PTI_Check2(3, int, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Vec_PTI_Get1(3, int, arg2), PyGLM_Vec_PTI_Get2(3, int, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2) && PyGLM_Vec_PTI_Check2(4, int, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Vec_PTI_Get1(4, int, arg2), PyGLM_Vec_PTI_Get2(4, int, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, int, arg1), PyGLM_Number_FromPyObject<int>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, int, arg1), PyGLM_Number_FromPyObject<int>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, int, arg1), PyGLM_Number_FromPyObject<int>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, int, arg1), PyGLM_Number_FromPyObject<int>(arg2), PyGLM_Number_FromPyObject<int>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(1, glm::uint, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Vec_PTI_Get1(1, glm::uint, arg2), PyGLM_Vec_PTI_Get2(1, glm::uint, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(2, glm::uint, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Vec_PTI_Get1(2, glm::uint, arg2), PyGLM_Vec_PTI_Get2(2, glm::uint, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(3, glm::uint, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Vec_PTI_Get1(3, glm::uint, arg2), PyGLM_Vec_PTI_Get2(3, glm::uint, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2) && PyGLM_Vec_PTI_Check2(4, glm::uint, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Vec_PTI_Get1(4, glm::uint, arg2), PyGLM_Vec_PTI_Get2(4, glm::uint, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2), PyGLM_Number_FromPyObject<glm::uint>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2), PyGLM_Number_FromPyObject<glm::uint>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2), PyGLM_Number_FromPyObject<glm::uint>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::uint, arg1), PyGLM_Number_FromPyObject<glm::uint>(arg2), PyGLM_Number_FromPyObject<glm::uint>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Vec_PTI_Get1(1, glm::i64, arg2), PyGLM_Vec_PTI_Get2(1, glm::i64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Vec_PTI_Get1(2, glm::i64, arg2), PyGLM_Vec_PTI_Get2(2, glm::i64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Vec_PTI_Get1(3, glm::i64, arg2), PyGLM_Vec_PTI_Get2(3, glm::i64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Vec_PTI_Get1(4, glm::i64, arg2), PyGLM_Vec_PTI_Get2(4, glm::i64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2), PyGLM_Number_FromPyObject<glm::i64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2), PyGLM_Number_FromPyObject<glm::i64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2), PyGLM_Number_FromPyObject<glm::i64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::i64, arg1), PyGLM_Number_FromPyObject<glm::i64>(arg2), PyGLM_Number_FromPyObject<glm::i64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Vec_PTI_Get1(1, glm::u64, arg2), PyGLM_Vec_PTI_Get2(1, glm::u64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Vec_PTI_Get1(2, glm::u64, arg2), PyGLM_Vec_PTI_Get2(2, glm::u64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Vec_PTI_Get1(3, glm::u64, arg2), PyGLM_Vec_PTI_Get2(3, glm::u64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u64, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Vec_PTI_Get1(4, glm::u64, arg2), PyGLM_Vec_PTI_Get2(4, glm::u64, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2), PyGLM_Number_FromPyObject<glm::u64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2), PyGLM_Number_FromPyObject<glm::u64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2), PyGLM_Number_FromPyObject<glm::u64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::u64, arg1), PyGLM_Number_FromPyObject<glm::u64>(arg2), PyGLM_Number_FromPyObject<glm::u64>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Vec_PTI_Get1(1, glm::i16, arg2), PyGLM_Vec_PTI_Get2(1, glm::i16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Vec_PTI_Get1(2, glm::i16, arg2), PyGLM_Vec_PTI_Get2(2, glm::i16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Vec_PTI_Get1(3, glm::i16, arg2), PyGLM_Vec_PTI_Get2(3, glm::i16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Vec_PTI_Get1(4, glm::i16, arg2), PyGLM_Vec_PTI_Get2(4, glm::i16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2), PyGLM_Number_FromPyObject<glm::i16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2), PyGLM_Number_FromPyObject<glm::i16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2), PyGLM_Number_FromPyObject<glm::i16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::i16, arg1), PyGLM_Number_FromPyObject<glm::i16>(arg2), PyGLM_Number_FromPyObject<glm::i16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Vec_PTI_Get1(1, glm::u16, arg2), PyGLM_Vec_PTI_Get2(1, glm::u16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Vec_PTI_Get1(2, glm::u16, arg2), PyGLM_Vec_PTI_Get2(2, glm::u16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Vec_PTI_Get1(3, glm::u16, arg2), PyGLM_Vec_PTI_Get2(3, glm::u16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u16, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Vec_PTI_Get1(4, glm::u16, arg2), PyGLM_Vec_PTI_Get2(4, glm::u16, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2), PyGLM_Number_FromPyObject<glm::u16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2), PyGLM_Number_FromPyObject<glm::u16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2), PyGLM_Number_FromPyObject<glm::u16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::u16, arg1), PyGLM_Number_FromPyObject<glm::u16>(arg2), PyGLM_Number_FromPyObject<glm::u16>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::i8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Vec_PTI_Get1(1, glm::i8, arg2), PyGLM_Vec_PTI_Get2(1, glm::i8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::i8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Vec_PTI_Get1(2, glm::i8, arg2), PyGLM_Vec_PTI_Get2(2, glm::i8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::i8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Vec_PTI_Get1(3, glm::i8, arg2), PyGLM_Vec_PTI_Get2(3, glm::i8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::i8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Vec_PTI_Get1(4, glm::i8, arg2), PyGLM_Vec_PTI_Get2(4, glm::i8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2), PyGLM_Number_FromPyObject<glm::i8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2), PyGLM_Number_FromPyObject<glm::i8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2), PyGLM_Number_FromPyObject<glm::i8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::i8, arg1), PyGLM_Number_FromPyObject<glm::i8>(arg2), PyGLM_Number_FromPyObject<glm::i8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(1, glm::u8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Vec_PTI_Get1(1, glm::u8, arg2), PyGLM_Vec_PTI_Get2(1, glm::u8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(2, glm::u8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Vec_PTI_Get1(2, glm::u8, arg2), PyGLM_Vec_PTI_Get2(2, glm::u8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(3, glm::u8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Vec_PTI_Get1(3, glm::u8, arg2), PyGLM_Vec_PTI_Get2(3, glm::u8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2) && PyGLM_Vec_PTI_Check2(4, glm::u8, arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Vec_PTI_Get1(4, glm::u8, arg2), PyGLM_Vec_PTI_Get2(4, glm::u8, arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(1, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2), PyGLM_Number_FromPyObject<glm::u8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(2, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2), PyGLM_Number_FromPyObject<glm::u8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(3, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2), PyGLM_Number_FromPyObject<glm::u8>(arg3)));
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return pack(glm::clamp(PyGLM_Vec_PTI_Get0(4, glm::u8, arg1), PyGLM_Number_FromPyObject<glm::u8>(arg2), PyGLM_Number_FromPyObject<glm::u8>(arg3)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for " "clamp" "()");
	return NULL;
}

PyDoc_STRVAR(mix_docstr,
	"mix(x: number, y: number, a: float) -> number\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: number, y: number, a: bool) -> number\n"
	"	Returns `y` if `a` is `True` and `x` otherwise.\n"
	"mix(x: vecN, y: vecN, a: fvecN) -> vecN\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a`. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: vecN, y: vecN, a: bvecN) -> vecN\n"
	"	For each component index `i`:\n"
	"	Returns `y[i]` if `a[i]` is `True` and `x[i]` otherwise.\n"
	"mix(x: matNxM, y: matNxM, a: fmatNxM) -> matNxM\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a` for each component. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: matNxM, y: matNxM, a: float) -> matNxM\n"
	"	Returns `x * (1.0 - a) + y * a`, i.e., the linear blend of `x` and `y` using the floating-point\n"
	"	value `a` for each component. The value for `a` is not restricted to the range `[0, 1]`.\n"
	"mix(x: quat, y: quat, a: float) -> quat\n"
	"	Spherical linear interpolation of two quaternions. The interpolation is oriented and the\n"
	"	rotation is performed at constant speed. For short path spherical linear interpolation, use\n"
	"	the `slerp` function."
);
static PyObject*
mix_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "mix", arg1, arg2, arg3);

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyBool_Check(arg3)) {
		return PyGLM_PyObject_FromNumber(glm::mix(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<bool>(arg3)));
	}

	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2) && PyGLM_Number_Check(arg3)) {
		return PyGLM_PyObject_FromNumber(glm::mix(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}

	PyGLM_PTI_Init0(arg1, PyGLM_T_ALL | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
	PyGLM_PTI_Init1(arg2, PyGLM_T_ALL | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);

	if (PyGLM_Qua_PTI_Check0(float, arg1) && PyGLM_Qua_PTI_Check1(float, arg2) && PyGLM_Number_Check(arg3)) {
		glm::quat o = PyGLM_Qua_PTI_Get0(float, arg1);
		glm::quat o2 = PyGLM_Qua_PTI_Get1(float, arg2);
		return pack_qua(glm::mix(o, o2, PyGLM_Number_FromPyObject<float>(arg3)));
	}
	if (PyGLM_Qua_PTI_Check0(double, arg1) && PyGLM_Qua_PTI_Check1(double, arg2) && PyGLM_Number_Check(arg3)) {
		glm::dquat o = PyGLM_Qua_PTI_Get0(double, arg1);
		glm::dquat o2 = PyGLM_Qua_PTI_Get1(double, arg2);
		return pack_qua(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	}

	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, int, arg1) && PyGLM_Vec_PTI_Check1(1, int, arg2)) {
		glm::vec<1, int> o = PyGLM_Vec_PTI_Get0(1, int, arg1);
		glm::vec<1, int> o2 = PyGLM_Vec_PTI_Get1(1, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(1, glm::uint, arg2)) {
		glm::vec<1, glm::uint> o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
		glm::vec<1, glm::uint> o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i64, arg2)) {
		glm::vec<1, glm::i64> o = PyGLM_Vec_PTI_Get0(1, glm::i64, arg1);
		glm::vec<1, glm::i64> o2 = PyGLM_Vec_PTI_Get1(1, glm::i64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u64, arg2)) {
		glm::vec<1, glm::u64> o = PyGLM_Vec_PTI_Get0(1, glm::u64, arg1);
		glm::vec<1, glm::u64> o2 = PyGLM_Vec_PTI_Get1(1, glm::u64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i16, arg2)) {
		glm::vec<1, glm::i16> o = PyGLM_Vec_PTI_Get0(1, glm::i16, arg1);
		glm::vec<1, glm::i16> o2 = PyGLM_Vec_PTI_Get1(1, glm::i16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u16, arg2)) {
		glm::vec<1, glm::u16> o = PyGLM_Vec_PTI_Get0(1, glm::u16, arg1);
		glm::vec<1, glm::u16> o2 = PyGLM_Vec_PTI_Get1(1, glm::u16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::i8, arg2)) {
		glm::vec<1, glm::i8> o = PyGLM_Vec_PTI_Get0(1, glm::i8, arg1);
		glm::vec<1, glm::i8> o2 = PyGLM_Vec_PTI_Get1(1, glm::i8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(1, glm::u8, arg2)) {
		glm::vec<1, glm::u8> o = PyGLM_Vec_PTI_Get0(1, glm::u8, arg1);
		glm::vec<1, glm::u8> o2 = PyGLM_Vec_PTI_Get1(1, glm::u8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(1, bool, arg1) && PyGLM_Vec_PTI_Check1(1, bool, arg2)) {
		glm::vec<1, bool> o = PyGLM_Vec_PTI_Get0(1, bool, arg1);
		glm::vec<1, bool> o2 = PyGLM_Vec_PTI_Get1(1, bool, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
			glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
			glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(1, bool, arg3)) {
			glm::vec<1, bool> o3 = PyGLM_Vec_PTI_Get2(1, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, int, arg1) && PyGLM_Vec_PTI_Check1(2, int, arg2)) {
		glm::vec<2, int> o = PyGLM_Vec_PTI_Get0(2, int, arg1);
		glm::vec<2, int> o2 = PyGLM_Vec_PTI_Get1(2, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(2, glm::uint, arg2)) {
		glm::vec<2, glm::uint> o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
		glm::vec<2, glm::uint> o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i64, arg2)) {
		glm::vec<2, glm::i64> o = PyGLM_Vec_PTI_Get0(2, glm::i64, arg1);
		glm::vec<2, glm::i64> o2 = PyGLM_Vec_PTI_Get1(2, glm::i64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u64, arg2)) {
		glm::vec<2, glm::u64> o = PyGLM_Vec_PTI_Get0(2, glm::u64, arg1);
		glm::vec<2, glm::u64> o2 = PyGLM_Vec_PTI_Get1(2, glm::u64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i16, arg2)) {
		glm::vec<2, glm::i16> o = PyGLM_Vec_PTI_Get0(2, glm::i16, arg1);
		glm::vec<2, glm::i16> o2 = PyGLM_Vec_PTI_Get1(2, glm::i16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u16, arg2)) {
		glm::vec<2, glm::u16> o = PyGLM_Vec_PTI_Get0(2, glm::u16, arg1);
		glm::vec<2, glm::u16> o2 = PyGLM_Vec_PTI_Get1(2, glm::u16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::i8, arg2)) {
		glm::vec<2, glm::i8> o = PyGLM_Vec_PTI_Get0(2, glm::i8, arg1);
		glm::vec<2, glm::i8> o2 = PyGLM_Vec_PTI_Get1(2, glm::i8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(2, glm::u8, arg2)) {
		glm::vec<2, glm::u8> o = PyGLM_Vec_PTI_Get0(2, glm::u8, arg1);
		glm::vec<2, glm::u8> o2 = PyGLM_Vec_PTI_Get1(2, glm::u8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(2, bool, arg1) && PyGLM_Vec_PTI_Check1(2, bool, arg2)) {
		glm::vec<2, bool> o = PyGLM_Vec_PTI_Get0(2, bool, arg1);
		glm::vec<2, bool> o2 = PyGLM_Vec_PTI_Get1(2, bool, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
			glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
			glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(2, bool, arg3)) {
			glm::vec<2, bool> o3 = PyGLM_Vec_PTI_Get2(2, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, int, arg1) && PyGLM_Vec_PTI_Check1(3, int, arg2)) {
		glm::vec<3, int> o = PyGLM_Vec_PTI_Get0(3, int, arg1);
		glm::vec<3, int> o2 = PyGLM_Vec_PTI_Get1(3, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(3, glm::uint, arg2)) {
		glm::vec<3, glm::uint> o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
		glm::vec<3, glm::uint> o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i64, arg2)) {
		glm::vec<3, glm::i64> o = PyGLM_Vec_PTI_Get0(3, glm::i64, arg1);
		glm::vec<3, glm::i64> o2 = PyGLM_Vec_PTI_Get1(3, glm::i64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u64, arg2)) {
		glm::vec<3, glm::u64> o = PyGLM_Vec_PTI_Get0(3, glm::u64, arg1);
		glm::vec<3, glm::u64> o2 = PyGLM_Vec_PTI_Get1(3, glm::u64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i16, arg2)) {
		glm::vec<3, glm::i16> o = PyGLM_Vec_PTI_Get0(3, glm::i16, arg1);
		glm::vec<3, glm::i16> o2 = PyGLM_Vec_PTI_Get1(3, glm::i16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u16, arg2)) {
		glm::vec<3, glm::u16> o = PyGLM_Vec_PTI_Get0(3, glm::u16, arg1);
		glm::vec<3, glm::u16> o2 = PyGLM_Vec_PTI_Get1(3, glm::u16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::i8, arg2)) {
		glm::vec<3, glm::i8> o = PyGLM_Vec_PTI_Get0(3, glm::i8, arg1);
		glm::vec<3, glm::i8> o2 = PyGLM_Vec_PTI_Get1(3, glm::i8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(3, glm::u8, arg2)) {
		glm::vec<3, glm::u8> o = PyGLM_Vec_PTI_Get0(3, glm::u8, arg1);
		glm::vec<3, glm::u8> o2 = PyGLM_Vec_PTI_Get1(3, glm::u8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(3, bool, arg1) && PyGLM_Vec_PTI_Check1(3, bool, arg2)) {
		glm::vec<3, bool> o = PyGLM_Vec_PTI_Get0(3, bool, arg1);
		glm::vec<3, bool> o2 = PyGLM_Vec_PTI_Get1(3, bool, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
			glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
			glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(3, bool, arg3)) {
			glm::vec<3, bool> o3 = PyGLM_Vec_PTI_Get2(3, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, int, arg1) && PyGLM_Vec_PTI_Check1(4, int, arg2)) {
		glm::vec<4, int> o = PyGLM_Vec_PTI_Get0(4, int, arg1);
		glm::vec<4, int> o2 = PyGLM_Vec_PTI_Get1(4, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1) && PyGLM_Vec_PTI_Check1(4, glm::uint, arg2)) {
		glm::vec<4, glm::uint> o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
		glm::vec<4, glm::uint> o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i64, arg2)) {
		glm::vec<4, glm::i64> o = PyGLM_Vec_PTI_Get0(4, glm::i64, arg1);
		glm::vec<4, glm::i64> o2 = PyGLM_Vec_PTI_Get1(4, glm::i64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u64, arg2)) {
		glm::vec<4, glm::u64> o = PyGLM_Vec_PTI_Get0(4, glm::u64, arg1);
		glm::vec<4, glm::u64> o2 = PyGLM_Vec_PTI_Get1(4, glm::u64, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i16, arg2)) {
		glm::vec<4, glm::i16> o = PyGLM_Vec_PTI_Get0(4, glm::i16, arg1);
		glm::vec<4, glm::i16> o2 = PyGLM_Vec_PTI_Get1(4, glm::i16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u16, arg2)) {
		glm::vec<4, glm::u16> o = PyGLM_Vec_PTI_Get0(4, glm::u16, arg1);
		glm::vec<4, glm::u16> o2 = PyGLM_Vec_PTI_Get1(4, glm::u16, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::i8, arg2)) {
		glm::vec<4, glm::i8> o = PyGLM_Vec_PTI_Get0(4, glm::i8, arg1);
		glm::vec<4, glm::i8> o2 = PyGLM_Vec_PTI_Get1(4, glm::i8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1) && PyGLM_Vec_PTI_Check1(4, glm::u8, arg2)) {
		glm::vec<4, glm::u8> o = PyGLM_Vec_PTI_Get0(4, glm::u8, arg1);
		glm::vec<4, glm::u8> o2 = PyGLM_Vec_PTI_Get1(4, glm::u8, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check0(4, bool, arg1) && PyGLM_Vec_PTI_Check1(4, bool, arg2)) {
		glm::vec<4, bool> o = PyGLM_Vec_PTI_Get0(4, bool, arg1);
		glm::vec<4, bool> o2 = PyGLM_Vec_PTI_Get1(4, bool, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack_vec(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FD | PyGLM_DT_BOOL);
		if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
			glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
			glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
		if (PyGLM_Vec_PTI_Check2(4, bool, arg3)) {
			glm::vec<4, bool> o3 = PyGLM_Vec_PTI_Get2(4, bool, arg3);
			return pack_vec(glm::mix(o, o2, o3));
		}
	}

	if (PyGLM_Mat_PTI_Check0(2, 2, float, arg1) && PyGLM_Mat_PTI_Check1(2, 2, float, arg2)) {
		glm::mat<2, 2, float> o = PyGLM_Mat_PTI_Get0(2, 2, float, arg1);
		glm::mat<2, 2, float> o2 = PyGLM_Mat_PTI_Get1(2, 2, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3 = PyGLM_Mat_PTI_Get2(2, 2, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3 = PyGLM_Mat_PTI_Get2(2, 2, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(2, 2, double, arg1) && PyGLM_Mat_PTI_Check1(2, 2, double, arg2)) {
		glm::mat<2, 2, double> o = PyGLM_Mat_PTI_Get0(2, 2, double, arg1);
		glm::mat<2, 2, double> o2 = PyGLM_Mat_PTI_Get1(2, 2, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3 = PyGLM_Mat_PTI_Get2(2, 2, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3 = PyGLM_Mat_PTI_Get2(2, 2, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(2, 2, int, arg1) && PyGLM_Mat_PTI_Check1(2, 2, int, arg2)) {
		glm::mat<2, 2, int> o = PyGLM_Mat_PTI_Get0(2, 2, int, arg1);
		glm::mat<2, 2, int> o2 = PyGLM_Mat_PTI_Get1(2, 2, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3 = PyGLM_Mat_PTI_Get2(2, 2, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3 = PyGLM_Mat_PTI_Get2(2, 2, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(2, 2, glm::uint, arg1) && PyGLM_Mat_PTI_Check1(2, 2, glm::uint, arg2)) {
		glm::mat<2, 2, glm::uint> o = PyGLM_Mat_PTI_Get0(2, 2, glm::uint, arg1);
		glm::mat<2, 2, glm::uint> o2 = PyGLM_Mat_PTI_Get1(2, 2, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_2x2 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(2, 2, float, arg3)) {
			glm::mat<2, 2, float> o3 = PyGLM_Mat_PTI_Get2(2, 2, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(2, 2, double, arg3)) {
			glm::mat<2, 2, double> o3 = PyGLM_Mat_PTI_Get2(2, 2, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	//if (PyGLM_Mat_PTI_Check0(2, 3, float, arg1) && PyGLM_Mat_PTI_Check0(2, 3, float, arg2)) {
	//	glm::mat<2, 3, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 3, double, arg1) && PyGLM_Mat_PTI_Check0(2, 3, double, arg2)) {
	//	glm::mat<2, 3, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 3, int, arg1) && PyGLM_Mat_PTI_Check0(2, 3, int, arg2)) {
	//	glm::mat<2, 3, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 3, glm::uint, arg1) && PyGLM_Mat_PTI_Check0(2, 3, glm::uint, arg2)) {
	//	glm::mat<2, 3, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, float, arg3)) {
	//		glm::mat<2, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 3, double, arg3)) {
	//		glm::mat<2, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 4, float, arg1) && PyGLM_Mat_PTI_Check0(2, 4, float, arg2)) {
	//	glm::mat<2, 4, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 4, double, arg1) && PyGLM_Mat_PTI_Check0(2, 4, double, arg2)) {
	//	glm::mat<2, 4, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 4, int, arg1) && PyGLM_Mat_PTI_Check0(2, 4, int, arg2)) {
	//	glm::mat<2, 4, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(2, 4, glm::uint, arg1) && PyGLM_Mat_PTI_Check0(2, 4, glm::uint, arg2)) {
	//	glm::mat<2, 4, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, float, arg3)) {
	//		glm::mat<2, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(2, 4, double, arg3)) {
	//		glm::mat<2, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 2, float, arg1) && PyGLM_Mat_PTI_Check0(3, 2, float, arg2)) {
	//	glm::mat<3, 2, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 2, double, arg1) && PyGLM_Mat_PTI_Check0(3, 2, double, arg2)) {
	//	glm::mat<3, 2, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 2, int, arg1) && PyGLM_Mat_PTI_Check0(3, 2, int, arg2)) {
	//	glm::mat<3, 2, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 2, glm::uint, arg1) && PyGLM_Mat_PTI_Check0(3, 2, glm::uint, arg2)) {
	//	glm::mat<3, 2, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, float, arg3)) {
	//		glm::mat<3, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 2, double, arg3)) {
	//		glm::mat<3, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	if (PyGLM_Mat_PTI_Check0(3, 3, float, arg1) && PyGLM_Mat_PTI_Check1(3, 3, float, arg2)) {
		glm::mat<3, 3, float> o = PyGLM_Mat_PTI_Get0(3, 3, float, arg1);
		glm::mat<3, 3, float> o2 = PyGLM_Mat_PTI_Get1(3, 3, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3 = PyGLM_Mat_PTI_Get2(3, 3, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3 = PyGLM_Mat_PTI_Get2(3, 3, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(3, 3, double, arg1) && PyGLM_Mat_PTI_Check1(3, 3, double, arg2)) {
		glm::mat<3, 3, double> o = PyGLM_Mat_PTI_Get0(3, 3, double, arg1);
		glm::mat<3, 3, double> o2 = PyGLM_Mat_PTI_Get1(3, 3, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3 = PyGLM_Mat_PTI_Get2(3, 3, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3 = PyGLM_Mat_PTI_Get2(3, 3, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(3, 3, int, arg1) && PyGLM_Mat_PTI_Check1(3, 3, int, arg2)) {
		glm::mat<3, 3, int> o = PyGLM_Mat_PTI_Get0(3, 3, int, arg1);
		glm::mat<3, 3, int> o2 = PyGLM_Mat_PTI_Get1(3, 3, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3 = PyGLM_Mat_PTI_Get2(3, 3, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3 = PyGLM_Mat_PTI_Get2(3, 3, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(3, 3, glm::uint, arg1) && PyGLM_Mat_PTI_Check1(3, 3, glm::uint, arg2)) {
		glm::mat<3, 3, glm::uint> o = PyGLM_Mat_PTI_Get0(3, 3, glm::uint, arg1);
		glm::mat<3, 3, glm::uint> o2 = PyGLM_Mat_PTI_Get1(3, 3, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_3x3 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(3, 3, float, arg3)) {
			glm::mat<3, 3, float> o3 = PyGLM_Mat_PTI_Get2(3, 3, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(3, 3, double, arg3)) {
			glm::mat<3, 3, double> o3 = PyGLM_Mat_PTI_Get2(3, 3, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	//if (PyGLM_Mat_PTI_Check0(3, 4, float, arg1) && PyGLM_Mat_PTI_Check0(3, 4, float, arg2)) {
	//	glm::mat<3, 4, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 4, double, arg1) && PyGLM_Mat_PTI_Check0(3, 4, double, arg2)) {
	//	glm::mat<3, 4, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 4, int, arg1) && PyGLM_Mat_PTI_Check0(3, 4, int, arg2)) {
	//	glm::mat<3, 4, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(3, 4, glm::uint, arg1) && PyGLM_Mat_PTI_Check0(3, 4, glm::uint, arg2)) {
	//	glm::mat<3, 4, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, float, arg3)) {
	//		glm::mat<3, 4, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(3, 4, double, arg3)) {
	//		glm::mat<3, 4, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 2, float, arg1) && PyGLM_Mat_PTI_Check0(4, 2, float, arg2)) {
	//	glm::mat<4, 2, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 2, double, arg1) && PyGLM_Mat_PTI_Check0(4, 2, double, arg2)) {
	//	glm::mat<4, 2, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 2, int, arg1) && PyGLM_Mat_PTI_Check0(4, 2, int, arg2)) {
	//	glm::mat<4, 2, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 2, glm::uint, arg1) && PyGLM_Mat_PTI_Check0(4, 2, glm::uint, arg2)) {
	//	glm::mat<4, 2, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, float, arg3)) {
	//		glm::mat<4, 2, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 2, double, arg3)) {
	//		glm::mat<4, 2, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 3, float, arg1) && PyGLM_Mat_PTI_Check0(4, 3, float, arg2)) {
	//	glm::mat<4, 3, float> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 3, double, arg1) && PyGLM_Mat_PTI_Check0(4, 3, double, arg2)) {
	//	glm::mat<4, 3, double> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 3, int, arg1) && PyGLM_Mat_PTI_Check0(4, 3, int, arg2)) {
	//	glm::mat<4, 3, int> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	//if (PyGLM_Mat_PTI_Check0(4, 3, glm::uint, arg1) && PyGLM_Mat_PTI_Check0(4, 3, glm::uint, arg2)) {
	//	glm::mat<4, 3, glm::uint> o, o2;
	//	unpack_mat(arg1, o);
	//	unpack_mat(arg2, o2);
	//	if (PyGLM_Number_Check(arg3)) {
	//		return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, float, arg3)) {
	//		glm::mat<4, 3, float> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//	if (PyGLM_Mat_PTI_Check0(4, 3, double, arg3)) {
	//		glm::mat<4, 3, double> o3;
	//		unpack_mat(arg3, o3);
	//		return pack(glm::mix(o, o2, o3));
	//	}
	//}
	if (PyGLM_Mat_PTI_Check0(4, 4, float, arg1) && PyGLM_Mat_PTI_Check1(4, 4, float, arg2)) {
		glm::mat<4, 4, float> o = PyGLM_Mat_PTI_Get0(4, 4, float, arg1);
		glm::mat<4, 4, float> o2 = PyGLM_Mat_PTI_Get1(4, 4, float, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3 = PyGLM_Mat_PTI_Get2(4, 4, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3 = PyGLM_Mat_PTI_Get2(4, 4, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, double, arg1) && PyGLM_Mat_PTI_Check1(4, 4, double, arg2)) {
		glm::mat<4, 4, double> o = PyGLM_Mat_PTI_Get0(4, 4, double, arg1);
		glm::mat<4, 4, double> o2 = PyGLM_Mat_PTI_Get1(4, 4, double, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3 = PyGLM_Mat_PTI_Get2(4, 4, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3 = PyGLM_Mat_PTI_Get2(4, 4, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, int, arg1) && PyGLM_Mat_PTI_Check1(4, 4, int, arg2)) {
		glm::mat<4, 4, int> o = PyGLM_Mat_PTI_Get0(4, 4, int, arg1);
		glm::mat<4, 4, int> o2 = PyGLM_Mat_PTI_Get1(4, 4, int, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3 = PyGLM_Mat_PTI_Get2(4, 4, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3 = PyGLM_Mat_PTI_Get2(4, 4, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}
	if (PyGLM_Mat_PTI_Check0(4, 4, glm::uint, arg1) && PyGLM_Mat_PTI_Check1(4, 4, glm::uint, arg2)) {
		glm::mat<4, 4, glm::uint> o = PyGLM_Mat_PTI_Get0(4, 4, glm::uint, arg1);
		glm::mat<4, 4, glm::uint> o2 = PyGLM_Mat_PTI_Get1(4, 4, glm::uint, arg2);
		if (PyGLM_Number_Check(arg3)) {
			return pack(glm::mix(o, o2, PyGLM_Number_FromPyObject<double>(arg3)));
		}
		PyGLM_PTI_Init2(arg3, PyGLM_T_MAT | PyGLM_SHAPE_4x4 | PyGLM_DT_FD);
		if (PyGLM_Mat_PTI_Check2(4, 4, float, arg3)) {
			glm::mat<4, 4, float> o3 = PyGLM_Mat_PTI_Get2(4, 4, float, arg3);
			return pack(glm::mix(o, o2, o3));
		}
		if (PyGLM_Mat_PTI_Check2(4, 4, double, arg3)) {
			glm::mat<4, 4, double> o3 = PyGLM_Mat_PTI_Get2(4, 4, double, arg3);
			return pack(glm::mix(o, o2, o3));
		}
	}

	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for mix()");
	return NULL;
}

PyDoc_STRVAR(step_docstr,
	"step(edge: number, x: number) -> float\n"
	"	Returns `0.0` if `x < edge`, otherwise it returns `1.0`.\n"
	"step(edge: number, x: vecN) -> vecN\n"
	"	For every component `c` of `x`:\n"
	"	Returns `0.0` if `c < edge`, otherwise it returns `1.0`.\n"
	"step(edge: vecN, x: vecN) -> vecN\n"
	"	For every index `i`:\n"
	"	Returns `0.0` if `x[i] < edge[i]`, otherwise it returns `1.0`."
);
static PyObject*
step_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "step", arg1, arg2);
	if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return PyGLM_PyObject_FromNumber(glm::step(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
	PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_ALL);
	if (PyGLM_Vec_PTI_Check1(1, float, arg2)) {
		glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, float, arg1)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, double, arg2)) {
		glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, double, arg1)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, int, arg2)) {
		glm::vec<1, int> o2 = PyGLM_Vec_PTI_Get1(1, int, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, int, arg1)) {
			glm::vec<1, int> o = PyGLM_Vec_PTI_Get0(1, int, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::uint, arg2)) {
		glm::vec<1, glm::uint> o2 = PyGLM_Vec_PTI_Get1(1, glm::uint, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::uint, arg1)) {
			glm::vec<1, glm::uint> o = PyGLM_Vec_PTI_Get0(1, glm::uint, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::i64, arg2)) {
		glm::vec<1, glm::i64> o2 = PyGLM_Vec_PTI_Get1(1, glm::i64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i64, arg1)) {
			glm::vec<1, glm::i64> o = PyGLM_Vec_PTI_Get0(1, glm::i64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::u64, arg2)) {
		glm::vec<1, glm::u64> o2 = PyGLM_Vec_PTI_Get1(1, glm::u64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u64, arg1)) {
			glm::vec<1, glm::u64> o = PyGLM_Vec_PTI_Get0(1, glm::u64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::i16, arg2)) {
		glm::vec<1, glm::i16> o2 = PyGLM_Vec_PTI_Get1(1, glm::i16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i16, arg1)) {
			glm::vec<1, glm::i16> o = PyGLM_Vec_PTI_Get0(1, glm::i16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::u16, arg2)) {
		glm::vec<1, glm::u16> o2 = PyGLM_Vec_PTI_Get1(1, glm::u16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u16, arg1)) {
			glm::vec<1, glm::u16> o = PyGLM_Vec_PTI_Get0(1, glm::u16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::i8, arg2)) {
		glm::vec<1, glm::i8> o2 = PyGLM_Vec_PTI_Get1(1, glm::i8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::i8, arg1)) {
			glm::vec<1, glm::i8> o = PyGLM_Vec_PTI_Get0(1, glm::i8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, glm::u8, arg2)) {
		glm::vec<1, glm::u8> o2 = PyGLM_Vec_PTI_Get1(1, glm::u8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, glm::u8, arg1)) {
			glm::vec<1, glm::u8> o = PyGLM_Vec_PTI_Get0(1, glm::u8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(1, bool, arg2)) {
		glm::vec<1, bool> o2 = PyGLM_Vec_PTI_Get1(1, bool, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(1, bool, arg1)) {
			glm::vec<1, bool> o = PyGLM_Vec_PTI_Get0(1, bool, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, float, arg2)) {
		glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, float, arg1)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, double, arg2)) {
		glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, double, arg1)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, int, arg2)) {
		glm::vec<2, int> o2 = PyGLM_Vec_PTI_Get1(2, int, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, int, arg1)) {
			glm::vec<2, int> o = PyGLM_Vec_PTI_Get0(2, int, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::uint, arg2)) {
		glm::vec<2, glm::uint> o2 = PyGLM_Vec_PTI_Get1(2, glm::uint, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::uint, arg1)) {
			glm::vec<2, glm::uint> o = PyGLM_Vec_PTI_Get0(2, glm::uint, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::i64, arg2)) {
		glm::vec<2, glm::i64> o2 = PyGLM_Vec_PTI_Get1(2, glm::i64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i64, arg1)) {
			glm::vec<2, glm::i64> o = PyGLM_Vec_PTI_Get0(2, glm::i64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::u64, arg2)) {
		glm::vec<2, glm::u64> o2 = PyGLM_Vec_PTI_Get1(2, glm::u64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u64, arg1)) {
			glm::vec<2, glm::u64> o = PyGLM_Vec_PTI_Get0(2, glm::u64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::i16, arg2)) {
		glm::vec<2, glm::i16> o2 = PyGLM_Vec_PTI_Get1(2, glm::i16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i16, arg1)) {
			glm::vec<2, glm::i16> o = PyGLM_Vec_PTI_Get0(2, glm::i16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::u16, arg2)) {
		glm::vec<2, glm::u16> o2 = PyGLM_Vec_PTI_Get1(2, glm::u16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u16, arg1)) {
			glm::vec<2, glm::u16> o = PyGLM_Vec_PTI_Get0(2, glm::u16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::i8, arg2)) {
		glm::vec<2, glm::i8> o2 = PyGLM_Vec_PTI_Get1(2, glm::i8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::i8, arg1)) {
			glm::vec<2, glm::i8> o = PyGLM_Vec_PTI_Get0(2, glm::i8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, glm::u8, arg2)) {
		glm::vec<2, glm::u8> o2 = PyGLM_Vec_PTI_Get1(2, glm::u8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, glm::u8, arg1)) {
			glm::vec<2, glm::u8> o = PyGLM_Vec_PTI_Get0(2, glm::u8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(2, bool, arg2)) {
		glm::vec<2, bool> o2 = PyGLM_Vec_PTI_Get1(2, bool, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(2, bool, arg1)) {
			glm::vec<2, bool> o = PyGLM_Vec_PTI_Get0(2, bool, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, float, arg2)) {
		glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, float, arg1)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, double, arg2)) {
		glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, double, arg1)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, int, arg2)) {
		glm::vec<3, int> o2 = PyGLM_Vec_PTI_Get1(3, int, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, int, arg1)) {
			glm::vec<3, int> o = PyGLM_Vec_PTI_Get0(3, int, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::uint, arg2)) {
		glm::vec<3, glm::uint> o2 = PyGLM_Vec_PTI_Get1(3, glm::uint, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::uint, arg1)) {
			glm::vec<3, glm::uint> o = PyGLM_Vec_PTI_Get0(3, glm::uint, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::i64, arg2)) {
		glm::vec<3, glm::i64> o2 = PyGLM_Vec_PTI_Get1(3, glm::i64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i64, arg1)) {
			glm::vec<3, glm::i64> o = PyGLM_Vec_PTI_Get0(3, glm::i64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::u64, arg2)) {
		glm::vec<3, glm::u64> o2 = PyGLM_Vec_PTI_Get1(3, glm::u64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u64, arg1)) {
			glm::vec<3, glm::u64> o = PyGLM_Vec_PTI_Get0(3, glm::u64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::i16, arg2)) {
		glm::vec<3, glm::i16> o2 = PyGLM_Vec_PTI_Get1(3, glm::i16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i16, arg1)) {
			glm::vec<3, glm::i16> o = PyGLM_Vec_PTI_Get0(3, glm::i16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::u16, arg2)) {
		glm::vec<3, glm::u16> o2 = PyGLM_Vec_PTI_Get1(3, glm::u16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u16, arg1)) {
			glm::vec<3, glm::u16> o = PyGLM_Vec_PTI_Get0(3, glm::u16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::i8, arg2)) {
		glm::vec<3, glm::i8> o2 = PyGLM_Vec_PTI_Get1(3, glm::i8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::i8, arg1)) {
			glm::vec<3, glm::i8> o = PyGLM_Vec_PTI_Get0(3, glm::i8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, glm::u8, arg2)) {
		glm::vec<3, glm::u8> o2 = PyGLM_Vec_PTI_Get1(3, glm::u8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, glm::u8, arg1)) {
			glm::vec<3, glm::u8> o = PyGLM_Vec_PTI_Get0(3, glm::u8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(3, bool, arg2)) {
		glm::vec<3, bool> o2 = PyGLM_Vec_PTI_Get1(3, bool, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(3, bool, arg1)) {
			glm::vec<3, bool> o = PyGLM_Vec_PTI_Get0(3, bool, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, float, arg2)) {
		glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<float>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, float, arg1)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, double, arg2)) {
		glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<double>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, double, arg1)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, int, arg2)) {
		glm::vec<4, int> o2 = PyGLM_Vec_PTI_Get1(4, int, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<int>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, int, arg1)) {
			glm::vec<4, int> o = PyGLM_Vec_PTI_Get0(4, int, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::uint, arg2)) {
		glm::vec<4, glm::uint> o2 = PyGLM_Vec_PTI_Get1(4, glm::uint, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::uint>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::uint, arg1)) {
			glm::vec<4, glm::uint> o = PyGLM_Vec_PTI_Get0(4, glm::uint, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::i64, arg2)) {
		glm::vec<4, glm::i64> o2 = PyGLM_Vec_PTI_Get1(4, glm::i64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i64, arg1)) {
			glm::vec<4, glm::i64> o = PyGLM_Vec_PTI_Get0(4, glm::i64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::u64, arg2)) {
		glm::vec<4, glm::u64> o2 = PyGLM_Vec_PTI_Get1(4, glm::u64, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u64>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u64, arg1)) {
			glm::vec<4, glm::u64> o = PyGLM_Vec_PTI_Get0(4, glm::u64, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::i16, arg2)) {
		glm::vec<4, glm::i16> o2 = PyGLM_Vec_PTI_Get1(4, glm::i16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i16, arg1)) {
			glm::vec<4, glm::i16> o = PyGLM_Vec_PTI_Get0(4, glm::i16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::u16, arg2)) {
		glm::vec<4, glm::u16> o2 = PyGLM_Vec_PTI_Get1(4, glm::u16, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u16>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u16, arg1)) {
			glm::vec<4, glm::u16> o = PyGLM_Vec_PTI_Get0(4, glm::u16, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::i8, arg2)) {
		glm::vec<4, glm::i8> o2 = PyGLM_Vec_PTI_Get1(4, glm::i8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::i8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::i8, arg1)) {
			glm::vec<4, glm::i8> o = PyGLM_Vec_PTI_Get0(4, glm::i8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, glm::u8, arg2)) {
		glm::vec<4, glm::u8> o2 = PyGLM_Vec_PTI_Get1(4, glm::u8, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<glm::u8>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, glm::u8, arg1)) {
			glm::vec<4, glm::u8> o = PyGLM_Vec_PTI_Get0(4, glm::u8, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	if (PyGLM_Vec_PTI_Check1(4, bool, arg2)) {
		glm::vec<4, bool> o2 = PyGLM_Vec_PTI_Get1(4, bool, arg2);
		if (PyGLM_Number_Check(arg1)) {
			return pack_vec(glm::step(PyGLM_Number_FromPyObject<bool>(arg1), o2));
		}
		if (PyGLM_Vec_PTI_Check0(4, bool, arg1)) {
			glm::vec<4, bool> o = PyGLM_Vec_PTI_Get0(4, bool, arg1);
			return pack_vec(glm::step(o, o2));
		}
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for step(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(smoothstep_docstr,
	"smoothstep(edge0: number, edge1: number, x: number) -> float\n"
	"	Returns `0.0` if `x <= edge0` and `1.0` if `x >= edge1` and performs smooth Hermite interpolation\n"
	"	between `0` and `1` when `edge0 < x < edge1`. This is useful in cases where you would want a\n"
	"	threshold function with a smooth transition. This is equivalent to :\n"
	"	`t = clamp((x - edge0) / (edge1 - edge0), 0, 1)`\n"
	"	`return t * t * (3 - 2 * t)`\n"
	"	Results are undefined if `edge0 >= edge1`.\n"
	"smoothstep(edge0: number, edge1: number, x: vecN) -> vecN\n"
	"	Returns `0.0` if `x <= edge0` and `1.0` if `x >= edge1` and performs smooth Hermite interpolation\n"
	"	between `0` and `1` when `edge0 < x < edge1`. This is useful in cases where you would want a\n"
	"	threshold function with a smooth transition. This is equivalent to :\n"
	"	`t = clamp((x - edge0) / (edge1 - edge0), 0, 1)`\n"
	"	`return t * t * (3 - 2 * t)`\n"
	"	Results are undefined if `edge0 >= edge1`.\n"
	"smoothstep(edge0: vecN, edge1: vecN, x: vecN) -> vecN\n"
	"	Returns `0.0` if `x <= edge0` and `1.0` if `x >= edge1` and performs smooth Hermite interpolation\n"
	"	between `0` and `1` when `edge0 < x < edge1`. This is useful in cases where you would want a\n"
	"	threshold function with a smooth transition. This is equivalent to :\n"
	"	`t = clamp((x - edge0) / (edge1 - edge0), 0, 1)`\n"
	"	`return t * t * (3 - 2 * t)`\n"
	"	Results are undefined if `edge0 >= edge1`."
);
static PyObject*
smoothstep_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "smoothstep", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg3) && PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
		return PyGLM_PyObject_FromNumber(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	PyGLM_PTI_Init2(arg3, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check2(1, float, arg3)) {
		glm::vec<1, float> o3 = PyGLM_Vec_PTI_Get2(1, float, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FLOAT);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_FLOAT);
		if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyGLM_Vec_PTI_Check1(1, float, arg2)) {
			glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
			glm::vec<1, float> o2 = PyGLM_Vec_PTI_Get1(1, float, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(1, double, arg3)) {
		glm::vec<1, double> o3 = PyGLM_Vec_PTI_Get2(1, double, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_DOUBLE);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_1 | PyGLM_DT_DOUBLE);
		if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyGLM_Vec_PTI_Check1(1, double, arg2)) {
			glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
			glm::vec<1, double> o2 = PyGLM_Vec_PTI_Get1(1, double, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(2, float, arg3)) {
		glm::vec<2, float> o3 = PyGLM_Vec_PTI_Get2(2, float, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_FLOAT);
		if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyGLM_Vec_PTI_Check1(2, float, arg2)) {
			glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
			glm::vec<2, float> o2 = PyGLM_Vec_PTI_Get1(2, float, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(2, double, arg3)) {
		glm::vec<2, double> o3 = PyGLM_Vec_PTI_Get2(2, double, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_DOUBLE);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_2 | PyGLM_DT_DOUBLE);
		if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyGLM_Vec_PTI_Check1(2, double, arg2)) {
			glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
			glm::vec<2, double> o2 = PyGLM_Vec_PTI_Get1(2, double, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(3, float, arg3)) {
		glm::vec<3, float> o3 = PyGLM_Vec_PTI_Get2(3, float, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_FLOAT);
		if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyGLM_Vec_PTI_Check1(3, float, arg2)) {
			glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
			glm::vec<3, float> o2 = PyGLM_Vec_PTI_Get1(3, float, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(3, double, arg3)) {
		glm::vec<3, double> o3 = PyGLM_Vec_PTI_Get2(3, double, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_DOUBLE);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_3 | PyGLM_DT_DOUBLE);
		if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyGLM_Vec_PTI_Check1(3, double, arg2)) {
			glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
			glm::vec<3, double> o2 = PyGLM_Vec_PTI_Get1(3, double, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(4, float, arg3)) {
		glm::vec<4, float> o3 = PyGLM_Vec_PTI_Get2(4, float, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<float>(arg1), PyGLM_Number_FromPyObject<float>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_FLOAT);
		if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyGLM_Vec_PTI_Check1(4, float, arg2)) {
			glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
			glm::vec<4, float> o2 = PyGLM_Vec_PTI_Get1(4, float, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	if (PyGLM_Vec_PTI_Check2(4, double, arg3)) {
		glm::vec<4, double> o3 = PyGLM_Vec_PTI_Get2(4, double, arg3);
		if (PyGLM_Number_Check(arg1) && PyGLM_Number_Check(arg2)) {
			return pack_vec(glm::smoothstep(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), o3));
		}
		PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_DOUBLE);
		PyGLM_PTI_Init1(arg2, PyGLM_T_VEC | PyGLM_SHAPE_4 | PyGLM_DT_DOUBLE);
		if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyGLM_Vec_PTI_Check1(4, double, arg2)) {
			glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
			glm::vec<4, double> o2 = PyGLM_Vec_PTI_Get1(4, double, arg2);
			return pack_vec(glm::smoothstep(o, o2, o3));
		}
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for smoothstep()");
	return NULL;
}

PyDoc_STRVAR(isnan_docstr,
	"isnan(x: float) -> bool\n"
	"	Returns `True` if `x` holds a `NaN` (not a number) representation in the underlying\n"
	"	implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no `NaN` representations.\n"
	"isnan(x: vecN) -> bvecN\n"
	"	Returns `True` if `x` holds a `NaN` (not a number) representation in the underlying\n"
	"	implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no `NaN` representations.\n"
	"isnan(x: quat) -> bvecN\n"
	"	Returns `True` if `x` holds a `NaN` (not a number) representation in the underlying\n"
	"	implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no `NaN` representations."
);
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(isnan)

PyDoc_STRVAR(isinf_docstr,
	"isinf(x: float) -> bool\n"
	"	Returns `True` if `x` holds a positive infinity or negative infinity representation in the\n"
	"	underlying implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no infinity representations.\n"
	"isinf(x: vecN) -> bvecN\n"
	"	Returns `True` if `x` holds a positive infinity or negative infinity representation in the\n"
	"	underlying implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no infinity representations.\n"
	"isinf(x: quat) -> bvecN\n"
	"	Returns `True` if `x` holds a positive infinity or negative infinity representation in the\n"
	"	underlying implementation's set of floating point representations.\n"
	"	Returns `False` otherwise, including for implementations with no infinity representations."
);
PyGLM_MAKE_GLM_FUNC_N_V_Q__tfF(isinf)

PyDoc_STRVAR(fma_docstr,
	"fma(a: float, b: float, c: float) -> float\n"
	"	Computes and returns `a * b + c`."
);
static PyObject*
fma_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2, *arg3;
	PyGLM_Arg_Unpack_3O(args, "fma", arg1, arg2, arg3);
	if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2), PyGLM_Number_Check(arg3)) {
		return PyGLM_PyObject_FromNumber(glm::fma(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<double>(arg2), PyGLM_Number_FromPyObject<double>(arg3)));
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for fma()");
	return NULL;
}

PyDoc_STRVAR(frexp_docstr,
	"frexp(x: float) -> (significant: float, exponent: int)\n"
	"	Splits `x` into a floating-point significand in the range `[0.5, 1.0)` and an integral exponent\n"
	"	of two, such that: `x = significand * exp(2, exponent)`\n"
	"frexp(x: vecN, exp: ivecN) -> vecN\n"
	"	Splits `x` into a floating-point significand in the range `[0.5, 1.0)` and an integral exponent\n"
	"	of two, such that: `x = significand * exp(2, exponent)`\n"
	"	The significand is returned by the function and the exponent is returned in the parameter\n"
	"	`exp`. For a floating-point value of zero, the significantand exponent are both zero. For a\n"
	"	floating-point value that is an infinity or is not a number, the results are undefined."
);
static PyObject*
frexp_(PyObject*, PyObject* args) {
	if (PyTuple_Check(args) && PyTuple_GET_SIZE(args) == 1) {
		PyObject* arg = PyTuple_GET_ITEM(args, 0);
		if (PyGLM_Number_Check(arg)) {
			if (PyGLM_SHOW_WARNINGS & PyGLM_FREXP_WARNING) PyErr_WarnEx(PyExc_UserWarning, "This function will return this pair: (m, e), which differs from glm behaviour. You can silence this warning by calling glm.silence(1)", 1);
			int e;
			double m = glm::frexp(PyGLM_Number_FromPyObject<double>(arg), e);
			return Py_BuildValue("(d, i)", m, e);
		}
		PyGLM_TYPEERROR_O("invalid argument type for frexp(): ", arg);
		return NULL;
	}
	PyObject* arg1, * arg2;
	PyGLM_Arg_Unpack_2O(args, "frexp", arg1, arg2);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		return pack_vec(glm::frexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		return pack_vec(glm::frexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		return pack_vec(glm::frexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		return pack_vec(glm::frexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		return pack_vec(glm::frexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		return pack_vec(glm::frexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		return pack_vec(glm::frexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		return pack_vec(glm::frexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for frexp(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(ldexp_docstr,
	"ldexp(x: number, exp: int) -> float\n"
	"	Builds a floating-point number from `x` and the corresponding integral exponent of two in\n"
	"	`exp`, returning: `significand * exp(2, exponent)`. If this product is too large to be\n"
	"	represented in the floating-point type, the result is undefined.\n"
	"ldexp(x: vecN, exp: ivecN) -> vecN\n"
	"	Builds a floating-point number from `x` and the corresponding integral exponent of two in\n"
	"	`exp`, returning: `significand * exp(2, exponent)`. If this product is too large to be\n"
	"	represented in the floating-point type, the result is undefined."
);
static PyObject*
ldexp_(PyObject*, PyObject* args) {
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "ldexp", arg1, arg2);
	if (PyGLM_Number_Check(arg1), PyGLM_Number_Check(arg2)) {
		return PyGLM_PyObject_FromNumber(glm::ldexp(PyGLM_Number_FromPyObject<double>(arg1), PyGLM_Number_FromPyObject<int>(arg2)));
	}
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		return pack_vec(glm::ldexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyObject_TypeCheck(arg2, &hivec1Type)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		return pack_vec(glm::ldexp(o, ((vec<1, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		return pack_vec(glm::ldexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyObject_TypeCheck(arg2, &hivec2Type)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		return pack_vec(glm::ldexp(o, ((vec<2, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		return pack_vec(glm::ldexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyObject_TypeCheck(arg2, &hivec3Type)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		return pack_vec(glm::ldexp(o, ((vec<3, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		return pack_vec(glm::ldexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyObject_TypeCheck(arg2, &hivec4Type)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		return pack_vec(glm::ldexp(o, ((vec<4, int>*)arg2)->super_type));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for ldexp(): ", arg1, arg2);
	return NULL;
}

PyDoc_STRVAR(floatBitsToInt_docstr,
	"floatBitsToInt(v: float) -> int\n"
	"	Returns a signed integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
	"floatBitsToInt(v: fvecN) -> ivecN\n"
	"	Returns a signed integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
);
static PyObject*
floatBitsToInt_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		float f = static_cast<float>(PyFloat_AS_DOUBLE(arg));
		return PyGLM_PyObject_FromNumber<int>(glm::floatBitsToInt(f));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg);
		return pack_vec(glm::floatBitsToInt(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return pack_vec(glm::floatBitsToInt(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg);
		return pack_vec(glm::floatBitsToInt(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg);
		return pack_vec(glm::floatBitsToInt(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type(s) for floatBitsToInt(): ", arg);
	return NULL;
}

PyDoc_STRVAR(floatBitsToUint_docstr,
	"floatBitsToUint(v: float) -> int\n"
	"	Returns an unsigned integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
	"floatBitsToUint(v: fvecN) -> uvecN\n"
	"	Returns an unsigned integer value representing the encoding of a floating-point value.\n"
	"	The floating-point value's bit-level representation is preserved.\n"
);
static PyObject*
floatBitsToUint_(PyObject*, PyObject* arg) {
	if (PyFloat_Check(arg)) {
		float f = static_cast<float>(PyFloat_AS_DOUBLE(arg));
		return PyGLM_PyObject_FromNumber<unsigned int>(glm::floatBitsToUint(f));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FLOAT);
	if (PyGLM_Vec_PTI_Check0(1, float, arg)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg);
		return pack_vec(glm::floatBitsToUint(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg);
		return pack_vec(glm::floatBitsToUint(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg);
		return pack_vec(glm::floatBitsToUint(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg);
		return pack_vec(glm::floatBitsToUint(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type(s) for floatBitsToUint(): ", arg);
	return NULL;
}

PyDoc_STRVAR(intBitsToFloat_docstr,
	"intBitsToFloat(v: int) -> float\n"
	"	Returns a floating-point value corresponding to a signed integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved.\n"
	"intBitsToFloat(v: ivecN) -> fvecN\n"
	"	Returns a floating-point value corresponding to a signed integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved."
);
static PyObject*
intBitsToFloat_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		int i = static_cast<int>(PyLong_AS_LONG(arg));
		return PyGLM_PyObject_FromNumber<float>(glm::intBitsToFloat(i));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_INT);
	if (PyGLM_Vec_PTI_Check0(1, int32, arg)) {
		glm::vec<1, int32> o = PyGLM_Vec_PTI_Get0(1, int32, arg);
		return pack_vec(glm::intBitsToFloat(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, int32, arg)) {
		glm::vec<2, int32> o = PyGLM_Vec_PTI_Get0(2, int32, arg);
		return pack_vec(glm::intBitsToFloat(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, int32, arg)) {
		glm::vec<3, int32> o = PyGLM_Vec_PTI_Get0(3, int32, arg);
		return pack_vec(glm::intBitsToFloat(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, int32, arg)) {
		glm::vec<4, int32> o = PyGLM_Vec_PTI_Get0(4, int32, arg);
		return pack_vec(glm::intBitsToFloat(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type(s) for intBitsToFloat(): ", arg);
	return NULL;
}

PyDoc_STRVAR(uintBitsToFloat_docstr,
	"uintBitsToFloat(v: int) -> float\n"
	"	Returns a floating-point value corresponding to an unsigned integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved.\n"
	"uintBitsToFloat(v: ivecN) -> fvecN\n"
	"	Returns a floating-point value corresponding to an unsigned integer encoding of a floating-point\n"
	"	value. If an `inf` or `NaN` is passed in, it will not signal, and the resulting floating point\n"
	"	value is unspecified. Otherwise, the bit-level representation is preserved."
);
static PyObject*
uintBitsToFloat_(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		unsigned int i = static_cast<unsigned int>(PyLong_AsUnsignedLong(arg));
		return PyGLM_PyObject_FromNumber<float>(glm::uintBitsToFloat(i));
	}
	PyGLM_PTI_Init0(arg, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_UINT);
	if (PyGLM_Vec_PTI_Check0(1, uint32, arg)) {
		glm::vec<1, uint32> o = PyGLM_Vec_PTI_Get0(1, uint32, arg);
		return pack_vec(glm::uintBitsToFloat(o));
	}
	if (PyGLM_Vec_PTI_Check0(2, uint32, arg)) {
		glm::vec<2, uint32> o = PyGLM_Vec_PTI_Get0(2, uint32, arg);
		return pack_vec(glm::uintBitsToFloat(o));
	}
	if (PyGLM_Vec_PTI_Check0(3, uint32, arg)) {
		glm::vec<3, uint32> o = PyGLM_Vec_PTI_Get0(3, uint32, arg);
		return pack_vec(glm::uintBitsToFloat(o));
	}
	if (PyGLM_Vec_PTI_Check0(4, uint32, arg)) {
		glm::vec<4, uint32> o = PyGLM_Vec_PTI_Get0(4, uint32, arg);
		return pack_vec(glm::uintBitsToFloat(o));
	}
	PyGLM_TYPEERROR_O("invalid argument type(s) for uintBitsToFloat(): ", arg);
	return NULL;
}

PyDoc_STRVAR(modf_docstr,
	"modf(x: float) -> (fraction, integer)\n"
	"	Returns the fractional part of `x` and the integer part (as a whole number floating point value).\n"
	"modf(x: vecN, i: vecN) -> vecN\n"
	"	Returns the fractional part of `x` and sets `i` to the integer part (as a whole number floating\n"
	"	point value)."
);
static PyObject*
modf_(PyObject*, PyObject* args) {
	if (PyTuple_GET_SIZE(args) == 1) {
		PyObject* arg = PyTuple_GET_ITEM(args, 0);
		if (PyGLM_Number_Check(arg)) {
			double i;
			double x = PyGLM_Number_AsDouble(arg);
			double f = glm::modf(x, i);

			return Py_BuildValue("(d, d)", f, i);
		}
		PyGLM_TYPEERROR_O("invalid argument type(s) for intBitsToFloat(): ", arg);
		return NULL;
	}
	PyObject *arg1, *arg2;
	PyGLM_Arg_Unpack_2O(args, "modf", arg1, arg2);
	PyGLM_PTI_Init0(arg1, PyGLM_T_VEC | PyGLM_SHAPE_ALL | PyGLM_DT_FD);
	if (PyGLM_Vec_PTI_Check0(1, float, arg1) && PyObject_TypeCheck(arg2, &hfvec1Type)) {
		glm::vec<1, float> o = PyGLM_Vec_PTI_Get0(1, float, arg1);
		return pack_vec(glm::modf(o, ((vec<1, float>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(1, double, arg1) && PyObject_TypeCheck(arg2, &hdvec1Type)) {
		glm::vec<1, double> o = PyGLM_Vec_PTI_Get0(1, double, arg1);
		return pack_vec(glm::modf(o, ((vec<1, double>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, float, arg1) && PyObject_TypeCheck(arg2, &hfvec2Type)) {
		glm::vec<2, float> o = PyGLM_Vec_PTI_Get0(2, float, arg1);
		return pack_vec(glm::modf(o, ((vec<2, float>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(2, double, arg1) && PyObject_TypeCheck(arg2, &hdvec2Type)) {
		glm::vec<2, double> o = PyGLM_Vec_PTI_Get0(2, double, arg1);
		return pack_vec(glm::modf(o, ((vec<2, double>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, float, arg1) && PyObject_TypeCheck(arg2, &hfvec3Type)) {
		glm::vec<3, float> o = PyGLM_Vec_PTI_Get0(3, float, arg1);
		return pack_vec(glm::modf(o, ((vec<3, float>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(3, double, arg1) && PyObject_TypeCheck(arg2, &hdvec3Type)) {
		glm::vec<3, double> o = PyGLM_Vec_PTI_Get0(3, double, arg1);
		return pack_vec(glm::modf(o, ((vec<3, double>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, float, arg1) && PyObject_TypeCheck(arg2, &hfvec4Type)) {
		glm::vec<4, float> o = PyGLM_Vec_PTI_Get0(4, float, arg1);
		return pack_vec(glm::modf(o, ((vec<4, float>*)arg2)->super_type));
	}
	if (PyGLM_Vec_PTI_Check0(4, double, arg1) && PyObject_TypeCheck(arg2, &hdvec4Type)) {
		glm::vec<4, double> o = PyGLM_Vec_PTI_Get0(4, double, arg1);
		return pack_vec(glm::modf(o, ((vec<4, double>*)arg2)->super_type));
	}
	PyGLM_TYPEERROR_2O("invalid argument type(s) for modf(): ", arg1, arg2);
	return NULL;

}

#define FUNC_COMMON_METHODS \
{ "abs", (PyCFunction)abs_, METH_O, abs_docstr }, \
{ "sign", (PyCFunction)sign_, METH_O, sign_docstr }, \
{ "floor", (PyCFunction)floor_, METH_O, floor_docstr }, \
{ "trunc", (PyCFunction)trunc_, METH_O, trunc_docstr }, \
{ "round", (PyCFunction)round_, METH_O, round_docstr }, \
{ "roundEven", (PyCFunction)roundEven_, METH_O, roundEven_docstr }, \
{ "ceil", (PyCFunction)ceil_, METH_O, ceil_docstr }, \
{ "fract", (PyCFunction)fract_, METH_O, fract_docstr }, \
{ "mod", (PyCFunction)mod_, METH_VARARGS, mod_docstr }, \
{ "min", (PyCFunction)min_, METH_VARARGS, min_docstr }, \
{ "max", (PyCFunction)max_, METH_VARARGS, max_docstr }, \
{ "fmin", (PyCFunction)fmin_, METH_VARARGS, fmin_docstr }, \
{ "fmax", (PyCFunction)fmax_, METH_VARARGS, fmax_docstr }, \
{ "clamp", (PyCFunction)clamp_, METH_VARARGS, clamp_docstr }, \
{ "mix", (PyCFunction)mix_, METH_VARARGS, mix_docstr }, \
{ "step", (PyCFunction)step_, METH_VARARGS, step_docstr }, \
{ "smoothstep", (PyCFunction)smoothstep_, METH_VARARGS, smoothstep_docstr }, \
{ "isnan", (PyCFunction)isnan_, METH_O, isnan_docstr }, \
{ "isinf", (PyCFunction)isinf_, METH_O, isinf_docstr }, \
{ "fma", (PyCFunction)fma_, METH_VARARGS, fma_docstr }, \
{ "frexp", (PyCFunction)frexp_, METH_VARARGS, frexp_docstr }, \
{ "ldexp", (PyCFunction)ldexp_, METH_VARARGS, ldexp_docstr }, \
{ "floatBitsToInt", (PyCFunction)floatBitsToInt_, METH_O, floatBitsToInt_docstr }, \
{ "floatBitsToUint", (PyCFunction)floatBitsToUint_, METH_O, floatBitsToUint_docstr }, \
{ "intBitsToFloat", (PyCFunction)intBitsToFloat_, METH_O, intBitsToFloat_docstr }, \
{ "uintBitsToFloat", (PyCFunction)uintBitsToFloat_, METH_O, uintBitsToFloat_docstr }, \
{ "modf", (PyCFunction)modf_, METH_VARARGS, modf_docstr }
