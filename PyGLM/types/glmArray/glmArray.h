#pragma once

#include "forward_declarations.h"

static PyMemberDef glmArray_members[] = {
	{ (char*)"nbytes",			T_PYSSIZET,		offsetof(glmArray, nBytes),		1, (char*)"Total combined bytecount of all elements"										},
	{ (char*)"typecode",		T_CHAR,			offsetof(glmArray, format),		1, (char*)"The typecode character of the underlying format"									},
	{ (char*)"element_type",	T_OBJECT,		offsetof(glmArray, subtype),	1, (char*)"Type class of the contained elements"											},
	{ (char*)"itemsize",		T_PYSSIZET,		offsetof(glmArray, itemSize),	1, (char*)"The size of one array item in bytes "											},
	{ (char*)"dt_size",			T_PYSSIZET,		offsetof(glmArray, dtSize),		1, (char*)"The size of each single component of the elements in bytes (size of data type)"	},
	{ (char*)"address",			T_ULONGLONG,	offsetof(glmArray, data),		1, (char*)"The memory address where this array stores it's data"							},
	{ (char*)"length",			T_PYSSIZET,		offsetof(glmArray, itemCount),	1, (char*)"The count of elements contained by this array"									},
	{ NULL }  /* Sentinel */
};
static PyGetSetDef glmArray_getSet[] = {
	{ (char*)"ptr",		(getter)glmArray_getPtr,	NULL, (char*)"A ctypes pointer that points to the content of this array",	NULL },
	{ (char*)"dtype",	(getter)glmArray_getDtype,	NULL, (char*)"A numpy-like data type string",								NULL },
	{ NULL }  /* Sentinel */
};
static PyMethodDef glmArray_methods[] = {
	{ "__copy__",		(PyCFunction)generic_copy,		METH_NOARGS,	"Create a copy of this instance"				},
	{ "__deepcopy__",	(PyCFunction)generic_deepcopy,	METH_O,			"Create a (deep)copy of this instance"			},
	{ "to_list",		(PyCFunction)glmArray_to_list,	METH_NOARGS,	"Return the elements of this array as a list"	},
	{ "to_tuple",		(PyCFunction)glmArray_to_tuple, METH_NOARGS,	"Return the elements of this array as a tuple"	},
	{ NULL }  /* Sentinel */
};
static PyBufferProcs glmArrayBufferMethods = {
	(getbufferproc)glmArray_getbuffer,
	(releasebufferproc)glmArray_releasebuffer,
};
static PySequenceMethods glmArraySeqMethods = {
	(lenfunc)glmArray_len,						// sq_length
	(binaryfunc)glmArray_concat,				// sq_concat
	(ssizeargfunc)glmArray_repeat,				// sq_repeat
	(ssizeargfunc)glmArray_sq_item,				// sq_item
	0,
	(ssizeobjargproc)glmArray_sq_ass_item,		// sq_ass_item
	0,
	(objobjproc)glmArray_contains,				// sq_contains
	(binaryfunc)glmArray_inplace_concat,		// sq_inplace_concat
	(ssizeargfunc)glmArray_inplace_repeat,		// sq_inplace_repeat
};
static PyMappingMethods glmArrayMapMethods = {
	(lenfunc)glmArray_len,						// mp_length
	(binaryfunc)glmArray_mp_subscript,			// mp_subscript
	(objobjargproc)glmArray_mp_ass_subscript,	// mp_ass_subscript
};
static PyTypeObject glmArrayType = {
	PyObject_HEAD_INIT(NULL)
	"glm.array",						// tp_name
	sizeof(glmArray),					// tp_basicsize 
	0,	// tp_itemsize 
	(destructor)glmArray_dealloc,		// tp_dealloc 
	0,	// tp_print 
	0,	// tp_getattr 
	0,	// tp_setattr 
	0,	// tp_reserved 
	(reprfunc)glmArray_repr,			// tp_repr 
	0,	// tp_as_number 
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
	0, // tp_iter 
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