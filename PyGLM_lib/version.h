#define _TO_STRING(x) #x
#define TO_STRING(x) _TO_STRING(x)

#ifdef PyGLM_DEBUG
#define VERSION 2.dev1
#endif

#define PyGLM_VERSION TO_STRING(VERSION)