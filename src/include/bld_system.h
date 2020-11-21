
#ifndef BLD_SYSTEM_H

#define BLD_SYSTEM_H


#include <windows.h>
#ifdef _MSC_VER
    #include <bld_assert.h>
#else
    #include <assert.h>
#endif


#define BLD_MAX_DOUBLE 1.7976931348623157e+308

/* FIXME incompatible pointer to integer conversion */
#define PTR_TO_INT(ptr) ((uintptr_t) ptr)
/* FIXME incompatible integer to pointer conversion */
#define INT_TO_PTR(num, type) ((type *)(uintptr_t) num)


/* ignore "conversion from 'type1' to 'type2', possible lost of data" warning
 * on Microsoft Visual Studio
 */
#ifdef _MSC_VER
        #pragma warning (disable : 4244)
#endif


#endif /* BLD_SYSTEM_H */

