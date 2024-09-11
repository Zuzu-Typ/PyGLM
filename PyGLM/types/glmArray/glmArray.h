#pragma once

#include "forward_declarations.h"

#define T_PTR_AS_NUM ((sizeof(void*) == sizeof(unsigned long long)) ? T_ULONGLONG : (sizeof(void*) == sizeof(unsigned long)) ? T_ULONG : (sizeof(void*) == sizeof(unsigned int)) ? T_UINT : T_PYSSIZET)

static PyMemberDef glmArray_members[] = {
	{ (char*)"nbytes",			T_PYSSIZET,		offsetof(glmArray, nBytes),		1, (char*)"Total combined bytecount of all elements"										},
	{ (char*)"typecode",		T_CHAR,			offsetof(glmArray, format),		1, (char*)"The typecode character of the underlying format"									},
	{ (char*)"element_type",	T_OBJECT,		offsetof(glmArray, subtype),	1, (char*)"Type class of the contained elements"											},
	{ (char*)"itemsize",		T_PYSSIZET,		offsetof(glmArray, itemSize),	1, (char*)"The size of one array item in bytes "											},
	{ (char*)"dt_size",			T_PYSSIZET,		offsetof(glmArray, dtSize),		1, (char*)"The size of each single component of the elements in bytes (size of data type)"	},
	{ (char*)"address",			T_PTR_AS_NUM,	offsetof(glmArray, data),		1, (char*)"The memory address where this array stores it's data"							},
	{ (char*)"length",			T_PYSSIZET,		offsetof(glmArray, itemCount),	1, (char*)"The count of elements contained by this array"									},
	{ (char*)"readonly",		T_BOOL,			offsetof(glmArray, readonly),	1, (char*)"Whether or not the array is read-only"											},
	{ (char*)"reference",		T_OBJECT,		offsetof(glmArray, reference),	1, (char*)"The reference to the array owning the data (if any)"								},
	{ NULL }  /* Sentinel */
};
static PyGetSetDef glmArray_getSet[] = {
	{ (char*)"ptr",		(getter)glmArray_getPtr,	NULL, (char*)"A ctypes pointer that points to the content of this array",	NULL },
	{ (char*)"dtype",	(getter)glmArray_getDtype,	NULL, (char*)"A numpy-like data type string",								NULL },
	{ (char*)"ctype",	(getter)glmArray_getCtype,	NULL, (char*)"The respective ctypes data type",								NULL },
	{ NULL }  /* Sentinel */
};

static PyMethodDef glmArray_methods[] = {
	{ "__copy__",		(PyCFunction)generic_copy,				METH_NOARGS,				generic_copy_docstr },
	{ "__deepcopy__",	(PyCFunction)generic_deepcopy,			METH_O,						generic_deepcopy_docstr },
	{ "__getstate__",	(PyCFunction)glmArray_getstate,			METH_NOARGS,				glmArray_getstate_docstr },
	{ "__setstate__",	(PyCFunction)glmArray_setstate,			METH_O,						glmArray_setstate_docstr },
	{ "to_bytes",		(PyCFunction)glmArray_to_bytes,			METH_NOARGS,				glmArray_to_bytes_docstr },
	{ "from_bytes",		(PyCFunction)glmArray_from_bytes,		METH_VARARGS | METH_STATIC, glmArray_from_bytes_docstr },
	{ "reinterpret_cast",(PyCFunction)glmArray_reinterpret_cast,METH_O,						glmArray_reinterpret_cast_docstr },
	{ "to_list",		(PyCFunction)glmArray_to_list,			METH_NOARGS,				glmArray_to_list_docstr },
	{ "to_tuple",		(PyCFunction)glmArray_to_tuple,			METH_NOARGS,				glmArray_to_tuple_docstr },
	{ "split_components",(PyCFunction)glmArray_split_components,METH_NOARGS,				glmArray_split_components_docstr },
	{ "reduce",			(PyCFunction)glmArray_reduce,			METH_VARARGS,				glmArray_reduce_docstr },
	{ "from_numbers",	(PyCFunction)glmArray_from_numbers,		METH_VARARGS | METH_STATIC,	glmArray_from_numbers_docstr },
	{ "as_reference",	(PyCFunction)glmArray_as_reference,		METH_O | METH_STATIC,		glmArray_as_reference_docstr },
	{ "zeros",			(PyCFunction)glmArray_zeros,			METH_VARARGS | METH_STATIC,	glmArray_zeros_docstr },
	{ "filter",			(PyCFunction)glmArray_filter,			METH_O,						glmArray_filter_docstr },
	{ "map",			(PyCFunction)glmArray_map,              METH_VARARGS|METH_KEYWORDS, glmArray_map_docstr	},
	{ "sort",			(PyCFunction)glmArray_sort,				METH_O,						glmArray_sort_docstr },
	{ "concat",			(PyCFunction)glmArray_concat,			METH_O,						glmArray_concat_docstr },
	{ "iconcat",		(PyCFunction)glmArray_inplace_concat,	METH_O,						glmArray_inplace_concat_docstr },
	{ "repeat",			(PyCFunction)glmArray_repeat,			METH_O,						glmArray_repeat_docstr },
	{ "irepeat",		(PyCFunction)glmArray_inplace_repeat,	METH_O,						glmArray_inplace_repeat_docstr },
	//{ "test",		(PyCFunction)glmArray_pow_T<float>,	METH_O,						glmArray_inplace_repeat_docstr			},
	//{ "add",		(PyCFunction)glmArray_add,	METH_O,						glmArray_inplace_repeat_docstr			},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs glmArrayBufferMethods = {
	(getbufferproc)glmArray_getbuffer,
	(releasebufferproc)glmArray_releasebuffer,
};
static PySequenceMethods glmArraySeqMethods = {
	(lenfunc)glmArray_len,						// sq_length
	0,//(binaryfunc)glmArray_concat,				// sq_concat
	0,//(ssizeargfunc)glmArray_repeat,				// sq_repeat
	(ssizeargfunc)glmArray_sq_item,				// sq_item
	0,
	(ssizeobjargproc)glmArray_sq_ass_item,		// sq_ass_item
	0,
	(objobjproc)glmArray_contains,				// sq_contains
	0,//(binaryfunc)glmArray_inplace_concat,		// sq_inplace_concat
	0,//(ssizeargfunc)glmArray_inplace_repeat,		// sq_inplace_repeat
};
static PyMappingMethods glmArrayMapMethods = {
	(lenfunc)glmArray_len,						// mp_length
	(binaryfunc)glmArray_mp_subscript,			// mp_subscript
	(objobjargproc)glmArray_mp_ass_subscript,	// mp_ass_subscript
};
static PyNumberMethods glmArrayNumMethods = {
	(binaryfunc)glmArray_add, //nb_add
	(binaryfunc)glmArray_sub,//(binaryfunc)matsq_sub<2, 2, float>, //nb_subtract
	(binaryfunc)glmArray_mul,//(binaryfunc)mat_mul<2, 2, float>, //nb_multiply
	(binaryfunc)glmArray_mod, //nb_remainder
	0, //nb_divmod
	(ternaryfunc)glmArray_pow, //nb_power
	(unaryfunc)glmArray_neg,//(unaryfunc)mat_neg<2, 2, float>, //nb_negative
	(unaryfunc)glmArray_pos,//(unaryfunc)mat_pos<2, 2, float>, //nb_positive
	(unaryfunc)glmArray_abs, //nb_absolute
	0, //nb_bool
	(unaryfunc)glmArray_inv, //nb_invert
	(binaryfunc)glmArray_lshift, //nb_lshift
	(binaryfunc)glmArray_rshift, //nb_rshift
	(binaryfunc)glmArray_and, //nb_and
	(binaryfunc)glmArray_xor, //nb_xor
	(binaryfunc)glmArray_or, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float
	0,//(binaryfunc)matsq_iadd<2, 2, float>, //nb_inplace_add
	0,//(binaryfunc)matsq_isub<2, 2, float>, //nb_inplace_subtract
	0,//(binaryfunc)mat_imul<2, 2, float>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)glmArray_div,//(binaryfunc)matsq_div<2, 2, float>, //nb_true_divide
	0, //nb_inplace_floor_divide
	0,//(binaryfunc)matsq_idiv<2, 2, float>, //nb_inplace_true_divide
	0, //nb_index
	0,//(binaryfunc)mat_matmul, //nb_matrix_multiply
	0,//(binaryfunc)mat_imatmul<2, 2, float>, //nb_inplace_matrix_multiply
};

static PyTypeObject glmArrayType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.array",						// tp_name
	sizeof(glmArray),					// tp_basicsize 
	0,	// tp_itemsize 
	(destructor)glmArray_dealloc,		// tp_dealloc 
	0,	// tp_print 
	0,	// tp_getattr 
	0,	// tp_setattr 
	0,	// tp_reserved 
	(reprfunc)glmArray_repr,			// tp_repr 
	&glmArrayNumMethods,				// tp_as_number 
	&glmArraySeqMethods,				// tp_as_sequence 
	&glmArrayMapMethods,				// tp_as_mapping 
	(hashfunc)array_hash,				// tp_hash  
	0,	// tp_call 
	(reprfunc)glmArray_str,				// tp_str 
	0,	// tp_getattro 
	0,	// tp_setattro 
	&glmArrayBufferMethods,				// tp_as_buffer 
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,				// tp_flags 
	"array( <array compatible type(s)> )\nAn in-place copy of glm types.",	// tp_doc 
	0,									// tp_traverse 
	0,	// tp_clear 
	(richcmpfunc)glmArray_richcompare,	// tp_richcompare 
	0,	// tp_weaklistoffset 
	(getiterfunc)glmArray_geniter,		// tp_iter 
	0,	// tp_iternext 
	glmArray_methods,					// tp_methods 
	glmArray_members,					// tp_members 
	glmArray_getSet,           			// tp_getset 
	0,	// tp_base 
	0,	// tp_dict 
	0,	// tp_descr_get 
	0,	// tp_descr_set 
	0,	// tp_dictoffset 
	(initproc)glmArray_init,			// tp_init 
	0,// tp_alloc 
	(newfunc)glmArray_new,				// tp_new 
};
static PyTypeObject glmArrayIterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glmArrayIter",						// tp_name 
	sizeof(glmArrayIter),				// tp_basicsize 
	0, // tp_itemsize 
	(destructor)glmArrayIter_dealloc,	// tp_dealloc 
	0, // tp_print 
	0, // tp_getattr 
	0, // tp_setattr 
	0, // tp_reserved 
	0, // tp_repr 
	0, // tp_as_number 
	0, // tp_as_sequence 
	0, // tp_as_mapping 
	0, // tp_hash  
	0, // tp_call 
	0, // tp_str 
	0, // tp_getattro 
	0, // tp_setattro 
	0, // tp_as_buffer 
	Py_TPFLAGS_DEFAULT,					// tp_flags 
	"glmArray iterator",				// tp_doc 
	0, // tp_traverse 
	0, // tp_clear 
	0, // tp_richcompare 
	0, // tp_weaklistoffset 
	(getiterfunc)generic_id, // tp_iter 
	(iternextfunc)glmArrayIter_next,	// tp_iternext 
	0, // tp_methods 
	0, // tp_members 
	0, // tp_getset 
	0, // tp_base 
	0, // tp_dict 
	0, // tp_descr_get 
	0, // tp_descr_set 
	0, // tp_dictoffset 
	0, // tp_init 
	0, // tp_alloc 
	(newfunc)glmArrayIter_new,			// tp_new 
};