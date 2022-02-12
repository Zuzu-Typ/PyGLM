#pragma once

#include "../forward_declarations.h"


int glmArray_getbuffer(glmArray* self, Py_buffer* view, int flags);

void glmArray_releasebuffer(PyObject* self, Py_buffer* view);

PyDoc_STRVAR(glmArray_to_bytes_docstr,
	"Return the data of this array as a bytes string"
);

PyObject* glmArray_to_bytes(glmArray* self, PyObject*);

PyDoc_STRVAR(glmArray_from_bytes_docstr,
	"from_bytes(bytes_object: bytes, type_object: type = uint8) -> array\n"
	"	Creates an array with the data given by `bytes_object`, using `type_object` as the element type.\n"
	"	(The resulting array is a reference copy)"
);

PyObject* glmArray_from_bytes(PyObject*, PyObject* args);

PyDoc_STRVAR(glmArray_reinterpret_cast_docstr,
	"reinterpret_cast(type_object: type) -> array\n"
	"	Creates an array with the same data as this one, using `type_object` as the new element type.\n"
	"	(The resulting array is a reference copy)"
);

PyObject* glmArray_reinterpret_cast(glmArray* self, PyObject* arg);

PyDoc_STRVAR(glmArray_to_list_docstr,
	"Return the elements of this array as a list"
);

PyObject* glmArray_to_list(glmArray* self, PyObject*);

PyDoc_STRVAR(glmArray_to_tuple_docstr,
	"Return the elements of this array as a tuple"
);

PyObject* glmArray_to_tuple(glmArray* self, PyObject*);

PyDoc_STRVAR(glmArray_split_components_docstr,
	"Splits each element of this array into it's components.\n"
	"Returns one or multiple arrays wrapped in a tuple.\n"
	"For vector, quaternion and matrix arrays only!"
);

PyObject* glmArray_split_components(glmArray* self, PyObject*);

PyDoc_STRVAR(glmArray_reduce_docstr,
	"reduce(function[, initializer])\n"
	"	Applies the binary `function` to this array's elements cumulatively, reducing the array to\n"
	"	a single value. If initializer is set, it is placed before the first element.\n"
	"	Example: array.from_numbers(int32, 1, 2, 3, 4).reduce(add) -> (((1+2)+3)+4)\n"
	"	Or with an initializer: arr.reduce(add, 6) -> ((((6+1)+2)+3)+4)"
);

PyObject* glmArray_reduce(glmArray* self, PyObject* args);

PyDoc_STRVAR(glmArray_from_numbers_docstr,
	"from_numbers(data_type: type, *numbers: number) -> array\n"
	"	Creates an array of numbers, using the specified data type and `numbers` as the values.\n"
	"	`data_type` can be one of the supported ctypes types (e.g. `glm.float32`, `glm.uint8`, ...)"
);

PyObject* glmArray_from_numbers(PyObject*, PyObject* args);

PyDoc_STRVAR(glmArray_as_reference_docstr,
	"as_reference(other) -> array\n"
	"	Creates an array from another array (or a compatible buffer) as a reference instead of a copy."
);

PyObject* glmArray_as_reference(PyObject*, PyObject* args);

PyDoc_STRVAR(glmArray_zeros_docstr,
	"zeros(count: int, data_type: type) -> array\n"
	"	Creates an array of 0s using the specified data type.\n"
	"	`data_type` can be any supported array data type:\n"
	"	(`glm.vec3`, `glm.imat4x4`, `glm.int32`, `glm.u8vec2`, ...)"
);

PyObject* glmArray_zeros(PyObject*, PyObject* args);

PyObject* glmArray_getPtr(glmArray* self, void*);

PyObject* glmArray_getDtype(glmArray* self, void*);

PyObject* glmArray_getCtype(glmArray* self, void*);

Py_ssize_t glmArray_len(glmArray* self);

PyDoc_STRVAR(glmArray_concat_docstr,
	"concat(other: array) -> array\n"
	"	Appends the `other` array to this array and returns the result.\n"
	"	The arrays need to have the same `element_type`."
);

PyObject* glmArray_concat(PyObject* obj1, PyObject* obj2);

PyDoc_STRVAR(glmArray_repeat_docstr,
	"repeat(count: int) -> array\n"
	"	Repeats the array `count` times and returns the results."
);

PyObject* glmArray_repeat(glmArray* self, PyObject* count);

PyDoc_STRVAR(glmArray_inplace_concat_docstr,
	"iconcat(other: array) -> array\n"
	"	Appends the `other` array to this array in-place.\n"
	"	The arrays need to have the same `element_type`."
);

PyObject* glmArray_inplace_concat(glmArray* self, PyObject* obj);

PyDoc_STRVAR(glmArray_inplace_repeat_docstr,
	"irepeat(count: int) -> array\n"
	"	Repeats the array `count` times in-place."
);

PyObject* glmArray_inplace_repeat(glmArray* self, PyObject* count);


PyObject* glmArray_sq_item(glmArray * self, Py_ssize_t index);

int glmArray_sq_ass_item(glmArray * self, Py_ssize_t index, PyObject * value);


PyObject* glmArray_mp_subscript(glmArray* self, PyObject* key);

int glmArray_mp_ass_subscript(glmArray* self, PyObject* key, PyObject* value);

int glmArray_contains(glmArray * self, PyObject * value);

void glmArray_dealloc(glmArray* self);


PyObject* glmArray_str(glmArray* self);


PyObject* glmArray_repr(glmArray* self);


PyObject* glmArray_richcompare(glmArray* self, PyObject* other, int comp_type);


PyObject* glmArray_geniter(glmArray* self);


int glmArray_init(glmArray *self, PyObject *args, PyObject *kwds);


PyObject* glmArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds);


void glmArrayIter_dealloc(glmArrayIter *rgstate);


PyObject* glmArrayIter_next(glmArrayIter *rgstate);


PyObject* glmArrayIter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

Py_hash_t array_hash(glmArray* self, PyObject*);

PyDoc_STRVAR(glmArray_getstate_docstr,
	"Returns a picklable state of this object"
);

PyObject* glmArray_getstate(glmArray* self, PyObject*);

PyDoc_STRVAR(glmArray_setstate_docstr,
	"Restores a state that was previously acquired"
);

PyObject* glmArray_setstate(glmArray* self, PyObject* state);

PyDoc_STRVAR(glmArray_filter_docstr,
	"filter(func: callable) -> array\n"
	"	Filters this array with the given funtion and returns the resulting array.\n"
	"	The `func` is called with every element of the array and should return `True` for the\n"
	"	elements to keep and `False` for the elements to discard."
);

PyObject* glmArray_filter(glmArray* self, PyObject* func);

PyDoc_STRVAR(glmArray_map_docstr,
	"map(func: callable[, *args, ctype: type = None]) -> array\n"
	"	Maps all elements of this array to the result of `func`.\n"
	"	i.e. `func` is called with every element of the source array and the return value is used\n"
	"	to construct the new array. Return values of `None` are discarded and when the return value\n"
	"	is a tuple, the elements of the tuple are all added to the target array.\n"
	"	`ctype` can be used to specify which ctypes type to use when `func` outputs numbers."
);

PyObject* glmArray_map(glmArray* self, PyObject* func, PyObject* kwargs);

PyDoc_STRVAR(glmArray_sort_docstr,
	"sort(func: callable) -> array\n"
	"	Sorts all elements in the array using the supplied ordering function.\n"
	"	`func` will be called with two elements from the array and should return `-1` if\n"
	"	the first argument is ordered before the second argument, `0` if they are ordered at the\n"
	"	same position and `1` if the first argument is ordered after the second (e.g. `glm.cmp`).\n"
	"	`sort` uses a quicksort or insertion sort."
);

PyObject* glmArray_sort(glmArray* self, PyObject* func);

PyObject* glmArray_add(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_sub(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_mul(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_mod(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_pow(PyObject* obj1, PyObject* obj2, PyObject* obj3);

PyObject* glmArray_neg(glmArray* arr);

PyObject* glmArray_pos(glmArray* arr);

PyObject* glmArray_abs(glmArray* arr);

PyObject* glmArray_inv(glmArray* arr);

PyObject* glmArray_lshift(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_rshift(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_and(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_xor(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_or(PyObject* obj1, PyObject* obj2);

PyObject* glmArray_div(PyObject* obj1, PyObject* obj2);