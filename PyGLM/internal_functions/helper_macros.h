#pragma once

#include "../compiler_setup.h"

#define Py_IS_NOTIMPLEMENTED(op) (op == NULL || (PyObject*)op == Py_NotImplemented) // find out if op is NULL or NotImplemented

#define PyGLM_ASSERT(cond, msg) if (!(cond)) {PyErr_SetString(PyExc_AssertionError, msg); return NULL;}

#define PyGLM_ASSERT_NO(cond, msg) if (!(cond)) {PyErr_SetString(PyExc_AssertionError, msg); return -1;}

#define PyGLM_GET_NAME(name) (strncmp(name, "glm.", 4) == 0 ? &name[4] : name)

#define PyObject_IterCheck(op) ((op)->ob_type->tp_iter != 0)

#define PyGLM_TYPE_AS_CSTRING(op) op->ob_type->tp_name

#define PyGLM_TypeCheck(op, tp) (Py_TYPE(op) == tp) 

#define PyGLM_FITS_IN_FLOAT(value) ((FLT_MAX >= value && value >= FLT_MIN) || (-FLT_MIN >= value && value >= -FLT_MAX))

#define PyGLM_TupleOrList_Check(op) PyType_FastSubclass(Py_TYPE(op), (Py_TPFLAGS_TUPLE_SUBCLASS | Py_TPFLAGS_LIST_SUBCLASS))

#define PyGLM_TupleOrList_GET_SIZE(op) Py_SIZE(op)

#define PyGLM_TupleOrList_GET_ITEM(op, i) ((PyTuple_Check(op)) ? (((PyTupleObject *)(op))->ob_item[i]) : (((PyListObject *)(op))->ob_item[i]))

#define PyGLM_free(ptr) PyMem_Free(ptr); ptr = NULL;

#define PyGLM_INCREF(ob) (Py_INCREF(ob), ob)
#define PyGLM_DECREF(ob) (Py_DECREF(ob), ob)

static char* PyGLM_String_AsString(PyObject* name) {
	PyObject* asciiString = PyUnicode_AsASCIIString(name);
	char* out = PyBytes_AsString(asciiString);
	Py_DECREF(asciiString);
	return out;
}