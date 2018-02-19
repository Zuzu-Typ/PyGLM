static PyObject* epsilon(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(DBL_EPSILON);
}

static PyObject* zero(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.0);
}

static PyObject* one(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.0);
}

#define PI 3.14159265358979323846264338327950288

static PyObject* pi (PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(PI);
}

static PyObject* two_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(6.28318530717958647692528676655900576);
}

static PyObject* root_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.772453850905516027);
}

static PyObject* half_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.57079632679489661923132169163975144);
}

static PyObject* three_over_two_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(4.71238898038468985769396507491925432);
}

static PyObject* quarter_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.785398163397448309615660845819875721);
}

static PyObject* one_over_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.318309886183790671537767526745028724);
}

static PyObject* one_over_two_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.159154943091895335768883763372514362);
}

static PyObject* two_over_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.636619772367581343075535053490057448);
}

static PyObject* four_over_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.273239544735162686151070106980114898);
}

static PyObject* two_over_root_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.12837916709551257389615890312154517);
}

static PyObject* one_over_root_two(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.707106781186547524400844362104849039);
}

static PyObject* root_half_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.253314137315500251);
}

static PyObject* root_two_pi(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(2.506628274631000502);
}

static PyObject* root_ln_four(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.17741002251547469);
}

static PyObject* e(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(2.71828182845904523536);
}

static PyObject* euler(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.577215664901532860606);
}

static PyObject* root_two(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.41421356237309504880168872420969808);
}

static PyObject* root_three(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.73205080756887729352744634150587236);
}

static PyObject* root_five(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(2.23606797749978969640917366873127623);
}

static PyObject* ln_two(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.693147180559945309417232121458176568);
}

static PyObject* ln_ten(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(2.30258509299404568401799145468436421);
}

static PyObject* ln_ln_two(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(-0.3665129205816643);
}

static PyObject* third(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.3333333333333333333333333333333333333333);
}

static PyObject* two_thirds(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(0.666666666666666666666666666666666666667);
}

static PyObject* golden_ratio(PyObject* self, PyObject* arg) {
	return PyFloat_FromDouble(1.61803398874989484820458683436563811);
}