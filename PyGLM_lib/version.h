#define _TO_STRING(x) #x
#define TO_STRING(x) _TO_STRING(x)

#define PyGLM_VERSION TO_STRING(VERSION)