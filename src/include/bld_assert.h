#ifdef __cplusplus
extern "C" {
#endif

/* Imported from the DLL of the CRT like by assert.h of Visual C++ */
#ifdef _DLL
__declspec(dllimport)
#endif
void _assert(char * __cond, char * __file, int __line);

#ifdef  __cplusplus
}
#endif

#undef assert

#ifdef NDEBUG
    #define assert(p)   ((void)0)
#else
    #define assert(p)   (void)((p) || (_assert(#p, __FILE__, __LINE__), 0))
#endif
