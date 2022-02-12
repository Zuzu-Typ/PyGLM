#include "../compiler_setup.h"

#include "../types/types.h"

#include "../internal_functions/helper_macros.h"

PyObject* generic_to_bytes(PyObject* self, PyObject*) {
	PyGLMTypeObject* pto = (PyGLMTypeObject*)self->ob_type;
	return PyBytes_FromStringAndSize(pto->getDataOf(self), pto->itemSize);
}

PyObject* generic_copy(PyObject* self, PyObject*) {
	return PyObject_Call((PyObject*)(self->ob_type), PyTuple_Pack(1, self), NULL);
}

PyObject* generic_deepcopy(PyObject* self, PyObject* memo) {
	PyObject* copy = generic_copy(self, NULL);
	PyDict_SetItem(memo, PyLong_FromVoidPtr((void*)self), copy);
	return copy;
}

PyObject* generic_id(PyObject* self) {
	return PyGLM_INCREF(self);
}
