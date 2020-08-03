
#undef LIB_EXP

#if defined(BUILD_LIB)
#  define LIB_EXP __declspec(dllexport)
#else
#  define LIB_EXP __declspec(dllimport)
#endif