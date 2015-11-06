
#ifndef BLD_SYSTEM_H

#define BLD_SYSTEM_H


#include <windows.h>
#include <assert.h>


#define BLD_MAX_DOUBLE 1.7976931348623157e+308


/* ignore "conversion from 'type1' to 'type2', possible lost of data" warning
 * on Microsoft Visual Studio
 */
#ifdef _MSC_VER
        #pragma warning (disable : 4244)
#endif


#endif /* BLD_SYSTEM_H */

