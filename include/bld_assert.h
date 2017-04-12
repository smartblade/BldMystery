#ifdef __cplusplus
extern "C" {
#endif

void _assert(char * __cond, char * __file, int __line);

#ifdef  __cplusplus
}
#endif

#undef assert

#ifdef NDEBUG
    #define assert(p)   ((void)0)
#else
    #define assert(p)   ((p) ? (void)0 : _assert(#p, __FILE__, __LINE__))
#endif