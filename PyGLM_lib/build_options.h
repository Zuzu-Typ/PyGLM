#pragma once

// Use this option to build PyGLM's entire package with all optional features
#define PyGLM_DEFAULT 0

// This build option will tell PyGLM to not build any methods that do not belong to PyGLM types
// (like glm.translate, glm.sizeof, glm.value_ptr or other functions)
#define PyGLM_NO_FUNCTIONS 1

// This build option will disable PyGLM's iterable and buffer protocol compatibility features.
// If you do not construct PyGLM types from e.g. nested lists or numpy arrays, you may
//   safely enable this option.
#define PyGLM_NO_ITER_TYPECHECKING 2

// Alternate name: 'PyGLM_FAST'
#define PyGLM_FAST PyGLM_NO_ITER_TYPECHECKING

// This combines 'PyGLM_NO_FUNCTIONS' and 'PyGLM_NO_ITER_TYPECHECKING'
#define PyGLM_MINIMAL (PyGLM_NO_FUNCTIONS | PyGLM_NO_ITER_TYPECHECKING)



// ################################################
// #  This is where you can set the build option  #
// ################################################
#define PyGLM_BUILD PyGLM_DEFAULT





#if (PyGLM_BUILD == PyGLM_DEFAULT)
#define PyGLM_BUILD_STRING "DEFAULT"
#elif (PyGLM_BUILD == PyGLM_FAST)
#define PyGLM_BUILD_STRING "FAST"
#elif (PyGLM_BUILD == PyGLM_NO_FUNCTIONS)
#define PyGLM_BUILD_STRING "NO_FUNCTIONS"
#elif (PyGLM_BUILD == PyGLM_MINIMAL)
#define PyGLM_BUILD_STRING "MINIMAL"
#else
#define PyGLM_BUILD_STRING "CUSTOM"
#endif