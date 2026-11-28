
#ifndef BLD_SYSTEM_H

#define BLD_SYSTEM_H


#include <windows.h>
#if defined(_MSC_VER) && _MSC_VER < 1300
    #include <assert.h>
#else
    #include <bld_assert.h>
#endif


#define BLD_MAX_DOUBLE 1.7976931348623157e+308

/* The value differs from M_PI in the last digits */
#define PI 3.14159265359

#if defined(_MSC_VER) && _MSC_VER < 1300
/* Visual C++ 6.0 has no uintptr_t */
typedef UINT_PTR uintptr_t;
#endif

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

/* Define nullptr, ignore override on old compilers */
#if _MSC_VER < 1900
#define nullptr NULL
#define override
#endif

/* Old compilers don't generate move assignment operators. New compilers
 * generate them unless a copy assignment operator is declared, and exported
 * classes export them: declare the default copy assignment operator only on
 * new compilers, so that the classes export the same operators
 */
#if _MSC_VER < 1900
#define DEFAULT_COPY_ASSIGNMENT(type)
#else
#define DEFAULT_COPY_ASSIGNMENT(type) type &operator =(const type &) = default;
#endif


#endif /* BLD_SYSTEM_H */
