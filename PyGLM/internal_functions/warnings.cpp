
#include "warnings.h"

unsigned long long PyGLM_SHOW_WARNINGS = 18446744073709551615ull;

PyObject*
silence(PyObject*, PyObject* arg) {
	if (PyLong_Check(arg)) {
		unsigned long long warning_id = static_cast<unsigned long long>(PyLong_AS_LONG(arg));
		if (warning_id < 0 || warning_id > 6) {
			PyErr_SetString(PyExc_ValueError, "the specified warning does not exist.");
			return NULL;
		}
		if (warning_id == 0) {
			PyGLM_SHOW_WARNINGS = 0;
		}
		else {
			PyGLM_SHOW_WARNINGS &= (PyGLM_SHOW_WARNINGS ^ (1ull << (warning_id - 1)));
		}
		Py_RETURN_NONE;
	}
	PyGLM_TYPEERROR_O("silence() requires an integer as it's argument, not ", arg);
	return NULL;
}