#include "version.h"

#include "license.h"

#include "build_options.h"

#include "PyGLM/imports.h"

#include "PyGLM/compiler_setup.h"

//TYPES
#include "PyGLM/types/all.h"

// INTERNAL FUNCTIONS
#include "PyGLM/internal_functions/all.h"

// TYPE METHODS
#include "PyGLM/type_methods/all.h"

#if !(PyGLM_BUILD & PyGLM_NO_FUNCTIONS)

// PyGLM FUNCTIONS
#include "PyGLM/functions/all.h"

//static PyObject*
//test(PyObject*, PyObject* arg) {
//}
//#define HAS_TEST
//#define TEST_FUNC_TYPE METH_O

static PyMethodDef glmmethods[] = {
	// DETAIL
	// func_packing
	FUNC_PACKING_METHODS,

	// func_integer
	FUNC_INTEGER_METHODS,

	// func_vector_relational
	FUNC_VECTOR_RELATIONAL_METHODS,

	// func_exponential 
	FUNC_EXPONENTIAL,

	// func_common
	FUNC_COMMON_METHODS,

	// func_geometric
	FUNC_GEOMETRIC_METHODS,

	// func_matrix
	FUNC_MATRIX_METHODS,

	// func_trigonometric
	FUNC_TRIGONOMETRIC_METHODS,

	// EXTENSIONS
	// color_space
	COLOR_SPACE_METHODS,

	// constants
	CONSTANTS_METHODS,

	// epsilon
	EPSILON_METHODS,

	// integer
	INTEGER_METHODS,

	// matrix_inverse
	MATRIX_INVERSE_METHODS,

	// matrix_transform
	MATRIX_TRANSFORM_METHODS,

	// matrix_projection
	MATRIX_PROJECTION_METHODS,

	// matrix_clip_space
	MATRIX_CLIP_SPACE_METHODS,

	// quaternion
	QUATERNION_METHODS,

	// quaternion_common
	QUATERNION_COMMON_METHODS,

	// quaternion_trigonometric
	QUATERNION_TRIGONOMETRIC_METHODS,

	// matrix_access
	MATRIX_ACCESS_METHODS,

	// noise
	NOISE_METHODS,

	// packing
	PACKING_METHODS,

	// random
	RANDOM_METHODS,

	// round
	ROUND_METHODS,

	// reciprocal
	RECIPROCAL_METHODS,

	// type_ptr
	TYPE_PTR_METHODS,

	// ulp
	ULP_METHODS,

	// UNSTABLE EXTENSIONS
	// polar_coordinates
	POLAR_COORDINATES_METHODS,

	// norm
	NORM_METHODS,

	// decompose
	DECOMPOSE_METHODS,

	// matrix_transform_2d
	MATRIX_TRANSFORM_2D_METHODS,

	// rotate_vector
	ROTATE_VECTOR_METHODS,

	// compatibility
	COMPATIBILITY_METHODS,

	// unary
	UNARY_METHODS,

	// binary
	BINARY_METHODS,

	// ternary
	TERNARY_METHODS,

	// PyGLM functions
	CUSTOM_METHODS,
	
	{ "silence", (PyCFunction)silence, METH_O, silence_docstr },
	//{ "_get_type_info", (PyCFunction)_get_type_info, METH_VARARGS, "_get_type_info(accepted_types, object) -> None\nAn internal testing funtion to check wether or not the type checking works correctly." },
#ifdef HAS_TEST
	{"test", (PyCFunction)test, TEST_FUNC_TYPE, ""},
#endif
	{ NULL, NULL, 0, NULL }
};

#endif

static void glm_clear(PyObject*) {
#if !(PyGLM_NO_FUNCTIONS & PyGLM_BUILD)
	Py_XDECREF(ctypes_float_p);
	Py_XDECREF(ctypes_double_p);
	Py_XDECREF(ctypes_int64_p);
	Py_XDECREF(ctypes_int32_p);
	Py_XDECREF(ctypes_int16_p);
	Py_XDECREF(ctypes_int8_p);
	Py_XDECREF(ctypes_uint64_p);
	Py_XDECREF(ctypes_uint32_p);
	Py_XDECREF(ctypes_uint16_p);
	Py_XDECREF(ctypes_uint8_p);
	Py_XDECREF(ctypes_bool_p);
#endif
	Py_XDECREF(ctypes_cast);
	Py_XDECREF(ctypes_void_p);
	Py_XDECREF(PyGLM_VERSION_STRING);
	Py_XDECREF(PyGLM_LICENSE_STRING);
#if !(PyGLM_NO_ITER_TYPECHECKING & PyGLM_BUILD)
	PTI0 = PyGLMTypeInfo();
	PTI1 = PyGLMTypeInfo();
	PTI2 = PyGLMTypeInfo();
	PTI3 = PyGLMTypeInfo();
#endif
}

static PyModuleDef glmmodule = {
	PyModuleDef_HEAD_INIT,
	"glm",
	"Features that implement the GLSL specification as close as possible.",
	-1,
#if !(PyGLM_BUILD & PyGLM_NO_FUNCTIONS)
	glmmethods, 
#else
	NULL,
#endif
	NULL, NULL, NULL, (freefunc)glm_clear
};

extern "C" {
	PyMODINIT_FUNC
		PyInit_glm(void)
	{
		std::setlocale(LC_ALL, "en_US.UTF-8");

		PyObject* mainmod = PyImport_AddModule("__main__");
		PyObject* maindict = PyModule_GetDict(mainmod);
		PyObject* ctypes_list = Py_BuildValue("(s, s, s, s, s, s, s, s, s, s, s, s, s, s)", "cast", "c_void_p", "POINTER", "c_float", "c_double", "c_int64", "c_int32", "c_int16", "c_int8", "c_uint64", "c_uint32", "c_uint16", "c_uint8", "c_bool");

		PyObject* ctypes_module = PyImport_ImportModuleEx("ctypes", maindict, maindict, ctypes_list);
		Py_DECREF(ctypes_list);

		// Don't need to DECREF these, because they're added to glm
		ctypes_float = PyObject_GetAttrString(ctypes_module, "c_float");
		ctypes_double = PyObject_GetAttrString(ctypes_module, "c_double");
		ctypes_int64 = PyObject_GetAttrString(ctypes_module, "c_int64");
		ctypes_int32 = PyObject_GetAttrString(ctypes_module, "c_int32");
		ctypes_int16 = PyObject_GetAttrString(ctypes_module, "c_int16");
		ctypes_int8 = PyObject_GetAttrString(ctypes_module, "c_int8");
		ctypes_uint64 = PyObject_GetAttrString(ctypes_module, "c_uint64");
		ctypes_uint32 = PyObject_GetAttrString(ctypes_module, "c_uint32");
		ctypes_uint16 = PyObject_GetAttrString(ctypes_module, "c_uint16");
		ctypes_uint8 = PyObject_GetAttrString(ctypes_module, "c_uint8");
		ctypes_bool = PyObject_GetAttrString(ctypes_module, "c_bool");

		ctypes_dealloc = ((PyTypeObject*)ctypes_float)->tp_dealloc;

		ctypes_cast = PyObject_GetAttrString(ctypes_module, "cast");

		ctypes_void_p = PyObject_GetAttrString(ctypes_module, "c_void_p");

#if !(PyGLM_BUILD & PyGLM_NO_FUNCTIONS)

		PyObject* ctypes_POINTER = PyObject_GetAttrString(ctypes_module, "POINTER");

		ctypes_float_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_float, NULL);
		//Py_DECREF(ctypes_float);

		ctypes_double_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_double, NULL);
		//Py_DECREF(ctypes_double);

		ctypes_int64_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_int64, NULL);
		//Py_DECREF(ctypes_int64);

		ctypes_int32_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_int32, NULL);
		//Py_DECREF(ctypes_int32);

		ctypes_int16_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_int16, NULL);
		//Py_DECREF(ctypes_int16);

		ctypes_int8_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_int8, NULL);
		//Py_DECREF(ctypes_int8);

		ctypes_uint64_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_uint64, NULL);
		//Py_DECREF(ctypes_uint64);

		ctypes_uint32_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_uint32, NULL);
		//Py_DECREF(ctypes_uint32);

		ctypes_uint16_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_uint16, NULL);
		//Py_DECREF(ctypes_uint16);

		ctypes_uint8_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_uint8, NULL);
		//Py_DECREF(ctypes_uint8);

		ctypes_bool_p = PyObject_CallFunctionObjArgs(ctypes_POINTER, ctypes_bool, NULL);
		//Py_DECREF(ctypes_bool);

		Py_DECREF(ctypes_POINTER);
#endif
		Py_DECREF(ctypes_module);

		PyObject* module_glm;

		if (PyType_Ready(&hfvec1Type) < 0 || PyType_Ready(&hfvec1IterType) < 0
			|| PyType_Ready(&hfvec2Type) < 0 || PyType_Ready(&hfvec2IterType) < 0
			|| PyType_Ready(&hfvec3Type) < 0 || PyType_Ready(&hfvec3IterType) < 0
			|| PyType_Ready(&hfvec4Type) < 0 || PyType_Ready(&hfvec4IterType) < 0
			|| PyType_Ready(&hdvec1Type) < 0 || PyType_Ready(&hdvec1IterType) < 0
			|| PyType_Ready(&hdvec2Type) < 0 || PyType_Ready(&hdvec2IterType) < 0
			|| PyType_Ready(&hdvec3Type) < 0 || PyType_Ready(&hdvec3IterType) < 0
			|| PyType_Ready(&hdvec4Type) < 0 || PyType_Ready(&hdvec4IterType) < 0
			|| PyType_Ready(&hi8vec1Type) < 0 || PyType_Ready(&hi8vec1IterType) < 0
			|| PyType_Ready(&hi8vec2Type) < 0 || PyType_Ready(&hi8vec2IterType) < 0
			|| PyType_Ready(&hi8vec3Type) < 0 || PyType_Ready(&hi8vec3IterType) < 0
			|| PyType_Ready(&hi8vec4Type) < 0 || PyType_Ready(&hi8vec4IterType) < 0
			|| PyType_Ready(&hi16vec1Type) < 0 || PyType_Ready(&hi16vec1IterType) < 0
			|| PyType_Ready(&hi16vec2Type) < 0 || PyType_Ready(&hi16vec2IterType) < 0
			|| PyType_Ready(&hi16vec3Type) < 0 || PyType_Ready(&hi16vec3IterType) < 0
			|| PyType_Ready(&hi16vec4Type) < 0 || PyType_Ready(&hi16vec4IterType) < 0
			|| PyType_Ready(&hivec1Type) < 0 || PyType_Ready(&hivec1IterType) < 0
			|| PyType_Ready(&hivec2Type) < 0 || PyType_Ready(&hivec2IterType) < 0
			|| PyType_Ready(&hivec3Type) < 0 || PyType_Ready(&hivec3IterType) < 0
			|| PyType_Ready(&hivec4Type) < 0 || PyType_Ready(&hivec4IterType) < 0
			|| PyType_Ready(&hi64vec1Type) < 0 || PyType_Ready(&hi64vec1IterType) < 0
			|| PyType_Ready(&hi64vec2Type) < 0 || PyType_Ready(&hi64vec2IterType) < 0
			|| PyType_Ready(&hi64vec3Type) < 0 || PyType_Ready(&hi64vec3IterType) < 0
			|| PyType_Ready(&hi64vec4Type) < 0 || PyType_Ready(&hi64vec4IterType) < 0
			|| PyType_Ready(&hu8vec1Type) < 0 || PyType_Ready(&hu8vec1IterType) < 0
			|| PyType_Ready(&hu8vec2Type) < 0 || PyType_Ready(&hu8vec2IterType) < 0
			|| PyType_Ready(&hu8vec3Type) < 0 || PyType_Ready(&hu8vec3IterType) < 0
			|| PyType_Ready(&hu8vec4Type) < 0 || PyType_Ready(&hu8vec4IterType) < 0
			|| PyType_Ready(&hu16vec1Type) < 0 || PyType_Ready(&hu16vec1IterType) < 0
			|| PyType_Ready(&hu16vec2Type) < 0 || PyType_Ready(&hu16vec2IterType) < 0
			|| PyType_Ready(&hu16vec3Type) < 0 || PyType_Ready(&hu16vec3IterType) < 0
			|| PyType_Ready(&hu16vec4Type) < 0 || PyType_Ready(&hu16vec4IterType) < 0
			|| PyType_Ready(&huvec1Type) < 0 || PyType_Ready(&huvec1IterType) < 0
			|| PyType_Ready(&huvec2Type) < 0 || PyType_Ready(&huvec2IterType) < 0
			|| PyType_Ready(&huvec3Type) < 0 || PyType_Ready(&huvec3IterType) < 0
			|| PyType_Ready(&huvec4Type) < 0 || PyType_Ready(&huvec4IterType) < 0
			|| PyType_Ready(&hu64vec1Type) < 0 || PyType_Ready(&hu64vec1IterType) < 0
			|| PyType_Ready(&hu64vec2Type) < 0 || PyType_Ready(&hu64vec2IterType) < 0
			|| PyType_Ready(&hu64vec3Type) < 0 || PyType_Ready(&hu64vec3IterType) < 0
			|| PyType_Ready(&hu64vec4Type) < 0 || PyType_Ready(&hu64vec4IterType) < 0
			|| PyType_Ready(&hbvec1Type) < 0 || PyType_Ready(&hbvec1IterType) < 0
			|| PyType_Ready(&hbvec2Type) < 0 || PyType_Ready(&hbvec2IterType) < 0
			|| PyType_Ready(&hbvec3Type) < 0 || PyType_Ready(&hbvec3IterType) < 0
			|| PyType_Ready(&hbvec4Type) < 0 || PyType_Ready(&hbvec4IterType) < 0
			|| PyType_Ready(&hfmvec2Type) < 0 || PyType_Ready(&hfmvec2IterType) < 0
			|| PyType_Ready(&hfmvec3Type) < 0 || PyType_Ready(&hfmvec3IterType) < 0
			|| PyType_Ready(&hfmvec4Type) < 0 || PyType_Ready(&hfmvec4IterType) < 0
			|| PyType_Ready(&hdmvec2Type) < 0 || PyType_Ready(&hdmvec2IterType) < 0
			|| PyType_Ready(&hdmvec3Type) < 0 || PyType_Ready(&hdmvec3IterType) < 0
			|| PyType_Ready(&hdmvec4Type) < 0 || PyType_Ready(&hdmvec4IterType) < 0
			|| PyType_Ready(&himvec2Type) < 0 || PyType_Ready(&himvec2IterType) < 0
			|| PyType_Ready(&himvec3Type) < 0 || PyType_Ready(&himvec3IterType) < 0
			|| PyType_Ready(&himvec4Type) < 0 || PyType_Ready(&himvec4IterType) < 0
			|| PyType_Ready(&humvec2Type) < 0 || PyType_Ready(&humvec2IterType) < 0
			|| PyType_Ready(&humvec3Type) < 0 || PyType_Ready(&humvec3IterType) < 0
			|| PyType_Ready(&humvec4Type) < 0 || PyType_Ready(&humvec4IterType) < 0
			|| PyType_Ready(&hfmat2x2Type) < 0 || PyType_Ready(&hfmat2x2IterType) < 0
			|| PyType_Ready(&hfmat2x3Type) < 0 || PyType_Ready(&hfmat2x3IterType) < 0
			|| PyType_Ready(&hfmat2x4Type) < 0 || PyType_Ready(&hfmat2x4IterType) < 0
			|| PyType_Ready(&hfmat3x2Type) < 0 || PyType_Ready(&hfmat3x2IterType) < 0
			|| PyType_Ready(&hfmat3x3Type) < 0 || PyType_Ready(&hfmat3x3IterType) < 0
			|| PyType_Ready(&hfmat3x4Type) < 0 || PyType_Ready(&hfmat3x4IterType) < 0
			|| PyType_Ready(&hfmat4x2Type) < 0 || PyType_Ready(&hfmat4x2IterType) < 0
			|| PyType_Ready(&hfmat4x3Type) < 0 || PyType_Ready(&hfmat4x3IterType) < 0
			|| PyType_Ready(&hfmat4x4Type) < 0 || PyType_Ready(&hfmat4x4IterType) < 0
			|| PyType_Ready(&hdmat2x2Type) < 0 || PyType_Ready(&hdmat2x2IterType) < 0
			|| PyType_Ready(&hdmat2x3Type) < 0 || PyType_Ready(&hdmat2x3IterType) < 0
			|| PyType_Ready(&hdmat2x4Type) < 0 || PyType_Ready(&hdmat2x4IterType) < 0
			|| PyType_Ready(&hdmat3x2Type) < 0 || PyType_Ready(&hdmat3x2IterType) < 0
			|| PyType_Ready(&hdmat3x3Type) < 0 || PyType_Ready(&hdmat3x3IterType) < 0
			|| PyType_Ready(&hdmat3x4Type) < 0 || PyType_Ready(&hdmat3x4IterType) < 0
			|| PyType_Ready(&hdmat4x2Type) < 0 || PyType_Ready(&hdmat4x2IterType) < 0
			|| PyType_Ready(&hdmat4x3Type) < 0 || PyType_Ready(&hdmat4x3IterType) < 0
			|| PyType_Ready(&hdmat4x4Type) < 0 || PyType_Ready(&hdmat4x4IterType) < 0
			|| PyType_Ready(&himat2x2Type) < 0 || PyType_Ready(&himat2x2IterType) < 0
			|| PyType_Ready(&himat2x3Type) < 0 || PyType_Ready(&himat2x3IterType) < 0
			|| PyType_Ready(&himat2x4Type) < 0 || PyType_Ready(&himat2x4IterType) < 0
			|| PyType_Ready(&himat3x2Type) < 0 || PyType_Ready(&himat3x2IterType) < 0
			|| PyType_Ready(&himat3x3Type) < 0 || PyType_Ready(&himat3x3IterType) < 0
			|| PyType_Ready(&himat3x4Type) < 0 || PyType_Ready(&himat3x4IterType) < 0
			|| PyType_Ready(&himat4x2Type) < 0 || PyType_Ready(&himat4x2IterType) < 0
			|| PyType_Ready(&himat4x3Type) < 0 || PyType_Ready(&himat4x3IterType) < 0
			|| PyType_Ready(&himat4x4Type) < 0 || PyType_Ready(&himat4x4IterType) < 0
			|| PyType_Ready(&humat2x2Type) < 0 || PyType_Ready(&humat2x2IterType) < 0
			|| PyType_Ready(&humat2x3Type) < 0 || PyType_Ready(&humat2x3IterType) < 0
			|| PyType_Ready(&humat2x4Type) < 0 || PyType_Ready(&humat2x4IterType) < 0
			|| PyType_Ready(&humat3x2Type) < 0 || PyType_Ready(&humat3x2IterType) < 0
			|| PyType_Ready(&humat3x3Type) < 0 || PyType_Ready(&humat3x3IterType) < 0
			|| PyType_Ready(&humat3x4Type) < 0 || PyType_Ready(&humat3x4IterType) < 0
			|| PyType_Ready(&humat4x2Type) < 0 || PyType_Ready(&humat4x2IterType) < 0
			|| PyType_Ready(&humat4x3Type) < 0 || PyType_Ready(&humat4x3IterType) < 0
			|| PyType_Ready(&humat4x4Type) < 0 || PyType_Ready(&humat4x4IterType) < 0
			|| PyType_Ready(&hfquaType) < 0 || PyType_Ready(&hfquaIterType) < 0
			|| PyType_Ready(&hdquaType) < 0 || PyType_Ready(&hdquaIterType) < 0
			|| PyType_Ready(&glmArrayType) < 0 || PyType_Ready(&glmArrayIterType) < 0)
			return NULL;

		module_glm = PyModule_Create(&glmmodule);
		if (module_glm == NULL)
			return NULL;

		// float
		PyModule_AddObject(module_glm, "c_float", ctypes_float);
		Py_INCREF(ctypes_float);
		PyModule_AddObject(module_glm, "float_", ctypes_float);
		Py_INCREF(ctypes_float);
		PyModule_AddObject(module_glm, "float32", ctypes_float);

		// double
		PyModule_AddObject(module_glm, "c_double", ctypes_double);
		Py_INCREF(ctypes_double);
		PyModule_AddObject(module_glm, "double", ctypes_double);
		Py_INCREF(ctypes_double);
		PyModule_AddObject(module_glm, "float64", ctypes_double);

		// int64
		PyModule_AddObject(module_glm, "c_int64", ctypes_int64);
		Py_INCREF(ctypes_int64);
		PyModule_AddObject(module_glm, "int64", ctypes_int64);

		// int32
		PyModule_AddObject(module_glm, "c_int32", ctypes_int32);
		Py_INCREF(ctypes_int32);
		PyModule_AddObject(module_glm, "int32", ctypes_int32);

		// int16
		PyModule_AddObject(module_glm, "c_int16", ctypes_int16);
		Py_INCREF(ctypes_int16);
		PyModule_AddObject(module_glm, "int16", ctypes_int16);

		// int8
		PyModule_AddObject(module_glm, "c_int8", ctypes_int8);
		Py_INCREF(ctypes_int8);
		PyModule_AddObject(module_glm, "int8", ctypes_int8);

		// uint64
		PyModule_AddObject(module_glm, "c_uint64", ctypes_uint64);
		Py_INCREF(ctypes_uint64);
		PyModule_AddObject(module_glm, "uint64", ctypes_uint64);

		// uint32
		PyModule_AddObject(module_glm, "c_uint32", ctypes_uint32);
		Py_INCREF(ctypes_uint32);
		PyModule_AddObject(module_glm, "uint32", ctypes_uint32);

		// uint16
		PyModule_AddObject(module_glm, "c_uint16", ctypes_uint16);
		Py_INCREF(ctypes_uint16);
		PyModule_AddObject(module_glm, "uint16", ctypes_uint16);

		// uint8
		PyModule_AddObject(module_glm, "c_uint8", ctypes_uint8);
		Py_INCREF(ctypes_uint8);
		PyModule_AddObject(module_glm, "uint8", ctypes_uint8);

		PyModule_AddObject(module_glm, "c_bool", ctypes_bool);
		Py_INCREF(ctypes_bool);
		PyModule_AddObject(module_glm, "bool_", ctypes_bool);

		Py_INCREF(&hfvec1Type);
		PyModule_AddObject(module_glm, "vec1", (PyObject *)&hfvec1Type);
		Py_INCREF(&hfvec2Type);
		PyModule_AddObject(module_glm, "vec2", (PyObject *)&hfvec2Type);
		Py_INCREF(&hfvec3Type);
		PyModule_AddObject(module_glm, "vec3", (PyObject *)&hfvec3Type);
		Py_INCREF(&hfvec4Type);
		PyModule_AddObject(module_glm, "vec4", (PyObject *)&hfvec4Type);

		Py_INCREF(&hfmat2x2Type);
		PyModule_AddObject(module_glm, "mat2x2", (PyObject *)&hfmat2x2Type);
		Py_INCREF(&hfmat2x3Type);
		PyModule_AddObject(module_glm, "mat2x3", (PyObject *)&hfmat2x3Type);
		Py_INCREF(&hfmat2x4Type);
		PyModule_AddObject(module_glm, "mat2x4", (PyObject *)&hfmat2x4Type);
		Py_INCREF(&hfmat3x2Type);
		PyModule_AddObject(module_glm, "mat3x2", (PyObject *)&hfmat3x2Type);
		Py_INCREF(&hfmat3x3Type);
		PyModule_AddObject(module_glm, "mat3x3", (PyObject *)&hfmat3x3Type);
		Py_INCREF(&hfmat3x4Type);
		PyModule_AddObject(module_glm, "mat3x4", (PyObject *)&hfmat3x4Type);
		Py_INCREF(&hfmat4x2Type);
		PyModule_AddObject(module_glm, "mat4x2", (PyObject *)&hfmat4x2Type);
		Py_INCREF(&hfmat4x3Type);
		PyModule_AddObject(module_glm, "mat4x3", (PyObject *)&hfmat4x3Type);
		Py_INCREF(&hfmat4x4Type);
		PyModule_AddObject(module_glm, "mat4x4", (PyObject *)&hfmat4x4Type);

		Py_INCREF(&hfmat2x2Type);
		PyModule_AddObject(module_glm, "mat2", (PyObject *)&hfmat2x2Type);
		Py_INCREF(&hfmat3x3Type);
		PyModule_AddObject(module_glm, "mat3", (PyObject *)&hfmat3x3Type);
		Py_INCREF(&hfmat4x4Type);
		PyModule_AddObject(module_glm, "mat4", (PyObject *)&hfmat4x4Type);

		Py_INCREF(&hfquaType);
		PyModule_AddObject(module_glm, "quat", (PyObject *)&hfquaType);

		Py_INCREF(&hfquaType);
		PyModule_AddObject(module_glm, "fquat", (PyObject *)&hfquaType);

		Py_INCREF(&hdquaType);
		PyModule_AddObject(module_glm, "dquat", (PyObject *)&hdquaType);

		Py_INCREF(&hfquaType);
		PyModule_AddObject(module_glm, "f32quat", (PyObject *)&hfquaType);

		Py_INCREF(&hdquaType);
		PyModule_AddObject(module_glm, "f64quat", (PyObject *)&hdquaType);

		Py_INCREF(&hfmat2x2Type);
		PyModule_AddObject(module_glm, "fmat2x2", (PyObject *)&hfmat2x2Type);
		Py_INCREF(&hfmat2x3Type);
		PyModule_AddObject(module_glm, "fmat2x3", (PyObject *)&hfmat2x3Type);
		Py_INCREF(&hfmat2x4Type);
		PyModule_AddObject(module_glm, "fmat2x4", (PyObject *)&hfmat2x4Type);
		Py_INCREF(&hfmat3x2Type);
		PyModule_AddObject(module_glm, "fmat3x2", (PyObject *)&hfmat3x2Type);
		Py_INCREF(&hfmat3x3Type);
		PyModule_AddObject(module_glm, "fmat3x3", (PyObject *)&hfmat3x3Type);
		Py_INCREF(&hfmat3x4Type);
		PyModule_AddObject(module_glm, "fmat3x4", (PyObject *)&hfmat3x4Type);
		Py_INCREF(&hfmat4x2Type);
		PyModule_AddObject(module_glm, "fmat4x2", (PyObject *)&hfmat4x2Type);
		Py_INCREF(&hfmat4x3Type);
		PyModule_AddObject(module_glm, "fmat4x3", (PyObject *)&hfmat4x3Type);
		Py_INCREF(&hfmat4x4Type);
		PyModule_AddObject(module_glm, "fmat4x4", (PyObject *)&hfmat4x4Type);

		Py_INCREF(&hfmat2x2Type);
		PyModule_AddObject(module_glm, "fmat2", (PyObject *)&hfmat2x2Type);
		Py_INCREF(&hfmat3x3Type);
		PyModule_AddObject(module_glm, "fmat3", (PyObject *)&hfmat3x3Type);
		Py_INCREF(&hfmat4x4Type);
		PyModule_AddObject(module_glm, "fmat4", (PyObject *)&hfmat4x4Type);

		Py_INCREF(&hdmat2x2Type);
		PyModule_AddObject(module_glm, "dmat2x2", (PyObject *)&hdmat2x2Type);
		Py_INCREF(&hdmat2x3Type);
		PyModule_AddObject(module_glm, "dmat2x3", (PyObject *)&hdmat2x3Type);
		Py_INCREF(&hdmat2x4Type);
		PyModule_AddObject(module_glm, "dmat2x4", (PyObject *)&hdmat2x4Type);
		Py_INCREF(&hdmat3x2Type);
		PyModule_AddObject(module_glm, "dmat3x2", (PyObject *)&hdmat3x2Type);
		Py_INCREF(&hdmat3x3Type);
		PyModule_AddObject(module_glm, "dmat3x3", (PyObject *)&hdmat3x3Type);
		Py_INCREF(&hdmat3x4Type);
		PyModule_AddObject(module_glm, "dmat3x4", (PyObject *)&hdmat3x4Type);
		Py_INCREF(&hdmat4x2Type);
		PyModule_AddObject(module_glm, "dmat4x2", (PyObject *)&hdmat4x2Type);
		Py_INCREF(&hdmat4x3Type);
		PyModule_AddObject(module_glm, "dmat4x3", (PyObject *)&hdmat4x3Type);
		Py_INCREF(&hdmat4x4Type);
		PyModule_AddObject(module_glm, "dmat4x4", (PyObject *)&hdmat4x4Type);

		Py_INCREF(&hdmat2x2Type);
		PyModule_AddObject(module_glm, "dmat2", (PyObject *)&hdmat2x2Type);
		Py_INCREF(&hdmat3x3Type);
		PyModule_AddObject(module_glm, "dmat3", (PyObject *)&hdmat3x3Type);
		Py_INCREF(&hdmat4x4Type);
		PyModule_AddObject(module_glm, "dmat4", (PyObject *)&hdmat4x4Type);

		Py_INCREF(&himat2x2Type);
		PyModule_AddObject(module_glm, "imat2x2", (PyObject *)&himat2x2Type);
		Py_INCREF(&himat2x3Type);
		PyModule_AddObject(module_glm, "imat2x3", (PyObject *)&himat2x3Type);
		Py_INCREF(&himat2x4Type);
		PyModule_AddObject(module_glm, "imat2x4", (PyObject *)&himat2x4Type);
		Py_INCREF(&himat3x2Type);
		PyModule_AddObject(module_glm, "imat3x2", (PyObject *)&himat3x2Type);
		Py_INCREF(&himat3x3Type);
		PyModule_AddObject(module_glm, "imat3x3", (PyObject *)&himat3x3Type);
		Py_INCREF(&himat3x4Type);
		PyModule_AddObject(module_glm, "imat3x4", (PyObject *)&himat3x4Type);
		Py_INCREF(&himat4x2Type);
		PyModule_AddObject(module_glm, "imat4x2", (PyObject *)&himat4x2Type);
		Py_INCREF(&himat4x3Type);
		PyModule_AddObject(module_glm, "imat4x3", (PyObject *)&himat4x3Type);
		Py_INCREF(&himat4x4Type);
		PyModule_AddObject(module_glm, "imat4x4", (PyObject *)&himat4x4Type);

		Py_INCREF(&himat2x2Type);
		PyModule_AddObject(module_glm, "imat2", (PyObject *)&himat2x2Type);
		Py_INCREF(&himat3x3Type);
		PyModule_AddObject(module_glm, "imat3", (PyObject *)&himat3x3Type);
		Py_INCREF(&himat4x4Type);
		PyModule_AddObject(module_glm, "imat4", (PyObject *)&himat4x4Type);

		Py_INCREF(&humat2x2Type);
		PyModule_AddObject(module_glm, "umat2x2", (PyObject *)&humat2x2Type);
		Py_INCREF(&humat2x3Type);
		PyModule_AddObject(module_glm, "umat2x3", (PyObject *)&humat2x3Type);
		Py_INCREF(&humat2x4Type);
		PyModule_AddObject(module_glm, "umat2x4", (PyObject *)&humat2x4Type);
		Py_INCREF(&humat3x2Type);
		PyModule_AddObject(module_glm, "umat3x2", (PyObject *)&humat3x2Type);
		Py_INCREF(&humat3x3Type);
		PyModule_AddObject(module_glm, "umat3x3", (PyObject *)&humat3x3Type);
		Py_INCREF(&humat3x4Type);
		PyModule_AddObject(module_glm, "umat3x4", (PyObject *)&humat3x4Type);
		Py_INCREF(&humat4x2Type);
		PyModule_AddObject(module_glm, "umat4x2", (PyObject *)&humat4x2Type);
		Py_INCREF(&humat4x3Type);
		PyModule_AddObject(module_glm, "umat4x3", (PyObject *)&humat4x3Type);
		Py_INCREF(&humat4x4Type);
		PyModule_AddObject(module_glm, "umat4x4", (PyObject *)&humat4x4Type);

		Py_INCREF(&humat2x2Type);
		PyModule_AddObject(module_glm, "umat2", (PyObject *)&humat2x2Type);
		Py_INCREF(&humat3x3Type);
		PyModule_AddObject(module_glm, "umat3", (PyObject *)&humat3x3Type);
		Py_INCREF(&humat4x4Type);
		PyModule_AddObject(module_glm, "umat4", (PyObject *)&humat4x4Type);

		Py_INCREF(&hfmat2x2Type);
		PyModule_AddObject(module_glm, "f32mat2x2", (PyObject *)&hfmat2x2Type);
		Py_INCREF(&hfmat2x3Type);
		PyModule_AddObject(module_glm, "f32mat2x3", (PyObject *)&hfmat2x3Type);
		Py_INCREF(&hfmat2x4Type);
		PyModule_AddObject(module_glm, "f32mat2x4", (PyObject *)&hfmat2x4Type);
		Py_INCREF(&hfmat3x2Type);
		PyModule_AddObject(module_glm, "f32mat3x2", (PyObject *)&hfmat3x2Type);
		Py_INCREF(&hfmat3x3Type);
		PyModule_AddObject(module_glm, "f32mat3x3", (PyObject *)&hfmat3x3Type);
		Py_INCREF(&hfmat3x4Type);
		PyModule_AddObject(module_glm, "f32mat3x4", (PyObject *)&hfmat3x4Type);
		Py_INCREF(&hfmat4x2Type);
		PyModule_AddObject(module_glm, "f32mat4x2", (PyObject *)&hfmat4x2Type);
		Py_INCREF(&hfmat4x3Type);
		PyModule_AddObject(module_glm, "f32mat4x3", (PyObject *)&hfmat4x3Type);
		Py_INCREF(&hfmat4x4Type);
		PyModule_AddObject(module_glm, "f32mat4x4", (PyObject *)&hfmat4x4Type);

		Py_INCREF(&hfmat2x2Type);
		PyModule_AddObject(module_glm, "f32mat2", (PyObject *)&hfmat2x2Type);
		Py_INCREF(&hfmat3x3Type);
		PyModule_AddObject(module_glm, "f32mat3", (PyObject *)&hfmat3x3Type);
		Py_INCREF(&hfmat4x4Type);
		PyModule_AddObject(module_glm, "f32mat4", (PyObject *)&hfmat4x4Type);

		Py_INCREF(&hdmat2x2Type);
		PyModule_AddObject(module_glm, "f64mat2x2", (PyObject *)&hdmat2x2Type);
		Py_INCREF(&hdmat2x3Type);
		PyModule_AddObject(module_glm, "f64mat2x3", (PyObject *)&hdmat2x3Type);
		Py_INCREF(&hdmat2x4Type);
		PyModule_AddObject(module_glm, "f64mat2x4", (PyObject *)&hdmat2x4Type);
		Py_INCREF(&hdmat3x2Type);
		PyModule_AddObject(module_glm, "f64mat3x2", (PyObject *)&hdmat3x2Type);
		Py_INCREF(&hdmat3x3Type);
		PyModule_AddObject(module_glm, "f64mat3x3", (PyObject *)&hdmat3x3Type);
		Py_INCREF(&hdmat3x4Type);
		PyModule_AddObject(module_glm, "f64mat3x4", (PyObject *)&hdmat3x4Type);
		Py_INCREF(&hdmat4x2Type);
		PyModule_AddObject(module_glm, "f64mat4x2", (PyObject *)&hdmat4x2Type);
		Py_INCREF(&hdmat4x3Type);
		PyModule_AddObject(module_glm, "f64mat4x3", (PyObject *)&hdmat4x3Type);
		Py_INCREF(&hdmat4x4Type);
		PyModule_AddObject(module_glm, "f64mat4x4", (PyObject *)&hdmat4x4Type);

		Py_INCREF(&hdmat2x2Type);
		PyModule_AddObject(module_glm, "f64mat2", (PyObject *)&hdmat2x2Type);
		Py_INCREF(&hdmat3x3Type);
		PyModule_AddObject(module_glm, "f64mat3", (PyObject *)&hdmat3x3Type);
		Py_INCREF(&hdmat4x4Type);
		PyModule_AddObject(module_glm, "f64mat4", (PyObject *)&hdmat4x4Type);

		Py_INCREF(&himat2x2Type);
		PyModule_AddObject(module_glm, "i32mat2x2", (PyObject *)&himat2x2Type);
		Py_INCREF(&himat2x3Type);
		PyModule_AddObject(module_glm, "i32mat2x3", (PyObject *)&himat2x3Type);
		Py_INCREF(&himat2x4Type);
		PyModule_AddObject(module_glm, "i32mat2x4", (PyObject *)&himat2x4Type);
		Py_INCREF(&himat3x2Type);
		PyModule_AddObject(module_glm, "i32mat3x2", (PyObject *)&himat3x2Type);
		Py_INCREF(&himat3x3Type);
		PyModule_AddObject(module_glm, "i32mat3x3", (PyObject *)&himat3x3Type);
		Py_INCREF(&himat3x4Type);
		PyModule_AddObject(module_glm, "i32mat3x4", (PyObject *)&himat3x4Type);
		Py_INCREF(&himat4x2Type);
		PyModule_AddObject(module_glm, "i32mat4x2", (PyObject *)&himat4x2Type);
		Py_INCREF(&himat4x3Type);
		PyModule_AddObject(module_glm, "i32mat4x3", (PyObject *)&himat4x3Type);
		Py_INCREF(&himat4x4Type);
		PyModule_AddObject(module_glm, "i32mat4x4", (PyObject *)&himat4x4Type);

		Py_INCREF(&himat2x2Type);
		PyModule_AddObject(module_glm, "i32mat2", (PyObject *)&himat2x2Type);
		Py_INCREF(&himat3x3Type);
		PyModule_AddObject(module_glm, "i32mat3", (PyObject *)&himat3x3Type);
		Py_INCREF(&himat4x4Type);
		PyModule_AddObject(module_glm, "i32mat4", (PyObject *)&himat4x4Type);

		Py_INCREF(&humat2x2Type);
		PyModule_AddObject(module_glm, "u32mat2x2", (PyObject *)&humat2x2Type);
		Py_INCREF(&humat2x3Type);
		PyModule_AddObject(module_glm, "u32mat2x3", (PyObject *)&humat2x3Type);
		Py_INCREF(&humat2x4Type);
		PyModule_AddObject(module_glm, "u32mat2x4", (PyObject *)&humat2x4Type);
		Py_INCREF(&humat3x2Type);
		PyModule_AddObject(module_glm, "u32mat3x2", (PyObject *)&humat3x2Type);
		Py_INCREF(&humat3x3Type);
		PyModule_AddObject(module_glm, "u32mat3x3", (PyObject *)&humat3x3Type);
		Py_INCREF(&humat3x4Type);
		PyModule_AddObject(module_glm, "u32mat3x4", (PyObject *)&humat3x4Type);
		Py_INCREF(&humat4x2Type);
		PyModule_AddObject(module_glm, "u32mat4x2", (PyObject *)&humat4x2Type);
		Py_INCREF(&humat4x3Type);
		PyModule_AddObject(module_glm, "u32mat4x3", (PyObject *)&humat4x3Type);
		Py_INCREF(&humat4x4Type);
		PyModule_AddObject(module_glm, "u32mat4x4", (PyObject *)&humat4x4Type);

		Py_INCREF(&humat2x2Type);
		PyModule_AddObject(module_glm, "u32mat2", (PyObject *)&humat2x2Type);
		Py_INCREF(&humat3x3Type);
		PyModule_AddObject(module_glm, "u32mat3", (PyObject *)&humat3x3Type);
		Py_INCREF(&humat4x4Type);
		PyModule_AddObject(module_glm, "u32mat4", (PyObject *)&humat4x4Type);

		Py_INCREF(&hfvec1Type);
		PyModule_AddObject(module_glm, "fvec1", (PyObject *)&hfvec1Type);
		Py_INCREF(&hfvec2Type);
		PyModule_AddObject(module_glm, "fvec2", (PyObject *)&hfvec2Type);
		Py_INCREF(&hfvec3Type);
		PyModule_AddObject(module_glm, "fvec3", (PyObject *)&hfvec3Type);
		Py_INCREF(&hfvec4Type);
		PyModule_AddObject(module_glm, "fvec4", (PyObject *)&hfvec4Type);

		Py_INCREF(&hdvec1Type);
		PyModule_AddObject(module_glm, "dvec1", (PyObject *)&hdvec1Type);
		Py_INCREF(&hdvec2Type);
		PyModule_AddObject(module_glm, "dvec2", (PyObject *)&hdvec2Type);
		Py_INCREF(&hdvec3Type);
		PyModule_AddObject(module_glm, "dvec3", (PyObject *)&hdvec3Type);
		Py_INCREF(&hdvec4Type);
		PyModule_AddObject(module_glm, "dvec4", (PyObject *)&hdvec4Type);

		Py_INCREF(&hfvec1Type);
		PyModule_AddObject(module_glm, "f32vec1", (PyObject *)&hfvec1Type);
		Py_INCREF(&hfvec2Type);
		PyModule_AddObject(module_glm, "f32vec2", (PyObject *)&hfvec2Type);
		Py_INCREF(&hfvec3Type);
		PyModule_AddObject(module_glm, "f32vec3", (PyObject *)&hfvec3Type);
		Py_INCREF(&hfvec4Type);
		PyModule_AddObject(module_glm, "f32vec4", (PyObject *)&hfvec4Type);

		Py_INCREF(&hdvec1Type);
		PyModule_AddObject(module_glm, "f64vec1", (PyObject *)&hdvec1Type);
		Py_INCREF(&hdvec2Type);
		PyModule_AddObject(module_glm, "f64vec2", (PyObject *)&hdvec2Type);
		Py_INCREF(&hdvec3Type);
		PyModule_AddObject(module_glm, "f64vec3", (PyObject *)&hdvec3Type);
		Py_INCREF(&hdvec4Type);
		PyModule_AddObject(module_glm, "f64vec4", (PyObject *)&hdvec4Type);

		Py_INCREF(&hi8vec1Type);
		PyModule_AddObject(module_glm, "i8vec1", (PyObject *)&hi8vec1Type);
		Py_INCREF(&hi8vec2Type);
		PyModule_AddObject(module_glm, "i8vec2", (PyObject *)&hi8vec2Type);
		Py_INCREF(&hi8vec3Type);
		PyModule_AddObject(module_glm, "i8vec3", (PyObject *)&hi8vec3Type);
		Py_INCREF(&hi8vec4Type);
		PyModule_AddObject(module_glm, "i8vec4", (PyObject *)&hi8vec4Type);

		Py_INCREF(&hi16vec1Type);
		PyModule_AddObject(module_glm, "i16vec1", (PyObject *)&hi16vec1Type);
		Py_INCREF(&hi16vec2Type);
		PyModule_AddObject(module_glm, "i16vec2", (PyObject *)&hi16vec2Type);
		Py_INCREF(&hi16vec3Type);
		PyModule_AddObject(module_glm, "i16vec3", (PyObject *)&hi16vec3Type);
		Py_INCREF(&hi16vec4Type);
		PyModule_AddObject(module_glm, "i16vec4", (PyObject *)&hi16vec4Type);

		Py_INCREF(&hivec1Type);
		PyModule_AddObject(module_glm, "i32vec1", (PyObject *)&hivec1Type);
		Py_INCREF(&hivec2Type);
		PyModule_AddObject(module_glm, "i32vec2", (PyObject *)&hivec2Type);
		Py_INCREF(&hivec3Type);
		PyModule_AddObject(module_glm, "i32vec3", (PyObject *)&hivec3Type);
		Py_INCREF(&hivec4Type);
		PyModule_AddObject(module_glm, "i32vec4", (PyObject *)&hivec4Type);

		Py_INCREF(&hivec1Type);
		PyModule_AddObject(module_glm, "ivec1", (PyObject *)&hivec1Type);
		Py_INCREF(&hivec2Type);
		PyModule_AddObject(module_glm, "ivec2", (PyObject *)&hivec2Type);
		Py_INCREF(&hivec3Type);
		PyModule_AddObject(module_glm, "ivec3", (PyObject *)&hivec3Type);
		Py_INCREF(&hivec4Type);
		PyModule_AddObject(module_glm, "ivec4", (PyObject *)&hivec4Type);

		Py_INCREF(&hi64vec1Type);
		PyModule_AddObject(module_glm, "i64vec1", (PyObject *)&hi64vec1Type);
		Py_INCREF(&hi64vec2Type);
		PyModule_AddObject(module_glm, "i64vec2", (PyObject *)&hi64vec2Type);
		Py_INCREF(&hi64vec3Type);
		PyModule_AddObject(module_glm, "i64vec3", (PyObject *)&hi64vec3Type);
		Py_INCREF(&hi64vec4Type);
		PyModule_AddObject(module_glm, "i64vec4", (PyObject *)&hi64vec4Type);

		Py_INCREF(&hu8vec1Type);
		PyModule_AddObject(module_glm, "u8vec1", (PyObject *)&hu8vec1Type);
		Py_INCREF(&hu8vec2Type);
		PyModule_AddObject(module_glm, "u8vec2", (PyObject *)&hu8vec2Type);
		Py_INCREF(&hu8vec3Type);
		PyModule_AddObject(module_glm, "u8vec3", (PyObject *)&hu8vec3Type);
		Py_INCREF(&hu8vec4Type);
		PyModule_AddObject(module_glm, "u8vec4", (PyObject *)&hu8vec4Type);

		Py_INCREF(&hu16vec1Type);
		PyModule_AddObject(module_glm, "u16vec1", (PyObject *)&hu16vec1Type);
		Py_INCREF(&hu16vec2Type);
		PyModule_AddObject(module_glm, "u16vec2", (PyObject *)&hu16vec2Type);
		Py_INCREF(&hu16vec3Type);
		PyModule_AddObject(module_glm, "u16vec3", (PyObject *)&hu16vec3Type);
		Py_INCREF(&hu16vec4Type);
		PyModule_AddObject(module_glm, "u16vec4", (PyObject *)&hu16vec4Type);

		Py_INCREF(&huvec1Type);
		PyModule_AddObject(module_glm, "u32vec1", (PyObject *)&huvec1Type);
		Py_INCREF(&huvec2Type);
		PyModule_AddObject(module_glm, "u32vec2", (PyObject *)&huvec2Type);
		Py_INCREF(&huvec3Type);
		PyModule_AddObject(module_glm, "u32vec3", (PyObject *)&huvec3Type);
		Py_INCREF(&huvec4Type);
		PyModule_AddObject(module_glm, "u32vec4", (PyObject *)&huvec4Type);

		Py_INCREF(&huvec1Type);
		PyModule_AddObject(module_glm, "uvec1", (PyObject *)&huvec1Type);
		Py_INCREF(&huvec2Type);
		PyModule_AddObject(module_glm, "uvec2", (PyObject *)&huvec2Type);
		Py_INCREF(&huvec3Type);
		PyModule_AddObject(module_glm, "uvec3", (PyObject *)&huvec3Type);
		Py_INCREF(&huvec4Type);
		PyModule_AddObject(module_glm, "uvec4", (PyObject *)&huvec4Type);
		
		Py_INCREF(&hu64vec1Type);
		PyModule_AddObject(module_glm, "u64vec1", (PyObject *)&hu64vec1Type);
		Py_INCREF(&hu64vec2Type);
		PyModule_AddObject(module_glm, "u64vec2", (PyObject *)&hu64vec2Type);
		Py_INCREF(&hu64vec3Type);
		PyModule_AddObject(module_glm, "u64vec3", (PyObject *)&hu64vec3Type);
		Py_INCREF(&hu64vec4Type);
		PyModule_AddObject(module_glm, "u64vec4", (PyObject *)&hu64vec4Type);

		Py_INCREF(&hbvec1Type);
		PyModule_AddObject(module_glm, "bvec1", (PyObject *)&hbvec1Type);
		Py_INCREF(&hbvec2Type);
		PyModule_AddObject(module_glm, "bvec2", (PyObject *)&hbvec2Type);
		Py_INCREF(&hbvec3Type);
		PyModule_AddObject(module_glm, "bvec3", (PyObject *)&hbvec3Type);
		Py_INCREF(&hbvec4Type);
		PyModule_AddObject(module_glm, "bvec4", (PyObject *)&hbvec4Type);


		Py_INCREF(&hfmvec2Type);
		PyModule_AddObject(module_glm, "mvec2", (PyObject*)&hfmvec2Type);
		Py_INCREF(&hfmvec3Type);
		PyModule_AddObject(module_glm, "mvec3", (PyObject*)&hfmvec3Type);
		Py_INCREF(&hfmvec4Type);
		PyModule_AddObject(module_glm, "mvec4", (PyObject*)&hfmvec4Type);

		Py_INCREF(&hdmvec2Type);
		PyModule_AddObject(module_glm, "dmvec2", (PyObject*)&hdmvec2Type);
		Py_INCREF(&hdmvec3Type);
		PyModule_AddObject(module_glm, "dmvec3", (PyObject*)&hdmvec3Type);
		Py_INCREF(&hdmvec4Type);
		PyModule_AddObject(module_glm, "dmvec4", (PyObject*)&hdmvec4Type);

		Py_INCREF(&himvec2Type);
		PyModule_AddObject(module_glm, "imvec2", (PyObject*)&himvec2Type);
		Py_INCREF(&himvec3Type);
		PyModule_AddObject(module_glm, "imvec3", (PyObject*)&himvec3Type);
		Py_INCREF(&himvec4Type);
		PyModule_AddObject(module_glm, "imvec4", (PyObject*)&himvec4Type);

		Py_INCREF(&humvec2Type);
		PyModule_AddObject(module_glm, "umvec2", (PyObject*)&humvec2Type);
		Py_INCREF(&humvec3Type);
		PyModule_AddObject(module_glm, "umvec3", (PyObject*)&humvec3Type);
		Py_INCREF(&humvec4Type);
		PyModule_AddObject(module_glm, "umvec4", (PyObject*)&humvec4Type);

		Py_INCREF(&glmArrayType);
		PyModule_AddObject(module_glm, "array", (PyObject*)&glmArrayType);

		PyGLM_VERSION_STRING = PyUnicode_FromString("PyGLM (" PyGLM_BUILD_STRING ") version " PyGLM_VERSION);
		Py_INCREF(PyGLM_VERSION_STRING);
		PyModule_AddObject(module_glm, "version", PyGLM_VERSION_STRING);

		PyGLM_LICENSE_STRING = PyUnicode_FromString(PyGLM_LICENSE);
		Py_INCREF(PyGLM_LICENSE_STRING);
		PyModule_AddObject(module_glm, "license", PyGLM_LICENSE_STRING);

		return module_glm;
	}
}
#if GLM_COMPILER & GLM_COMPILER_VC
#pragma warning(pop)
#elif GLM_COMPILER & GLM_COMPILER_GCC
#pragma GCC diagnostic pop
#elif GLM_COMPILER & GLM_COMPILER_CLANG
#pragma clang diagnostic pop
#endif 