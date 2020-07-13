#pragma once

#include "../compiler_setup.h"

#define Py_IS_NOTIMPLEMENTED(op) (op == NULL || (PyObject*)op == Py_NotImplemented) // find out if op is NULL or NotImplemented

#define PyGLM_ASSERT(cond, msg) if (!cond) {PyErr_SetString(PyExc_AssertionError, msg); return NULL;}

#define PyObject_IterCheck(op) ((op)->ob_type->tp_iter != 0)

#define PyGLM_TYPE_AS_CSTRING(op) op->ob_type->tp_name

#define PyGLM_TypeCheck(op, tp) (Py_TYPE(op) == tp) 

#define PyGLM_String_AsString(name) PyBytes_AsString(PyUnicode_AsASCIIString(name));

#define PyGLM_FITS_IN_FLOAT(value) ((FLT_MAX >= value && value >= FLT_MIN) || (-FLT_MIN >= value && value >= -FLT_MAX))

#define PyGLM_TupleOrList_Check(op) PyType_FastSubclass(Py_TYPE(op), (Py_TPFLAGS_TUPLE_SUBCLASS | Py_TPFLAGS_LIST_SUBCLASS))

#define PyGLM_TupleOrList_GET_SIZE(op) Py_SIZE(op)

#define PyGLM_TupleOrList_GET_ITEM(op, i) ((PyTuple_Check(op)) ? (((PyTupleObject *)(op))->ob_item[i]) : (((PyListObject *)(op))->ob_item[i]))

#define PyGLM_free(ptr) PyMem_Free(ptr); ptr = NULL;