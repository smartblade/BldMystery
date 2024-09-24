#define BBLIBC_LIB_EXPORT
#include "NDataBase.h"


/*
* Module:                 BBLibc.dll
* Data address:           0x1004A9D0
* VC++ mangling:          ?B_csvs@@3V?$B_NDataBase@UB_ElementCSV@@@@A
*/
#ifndef BLD_NATIVE
B_NDataBase<B_ElementCSV> B_csvs;
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x1003DBF3
* VC++ mangling:          ?ReadCSV@@YAIPBDPAV?$B_NDataBase@UB_ElementCSV@@@@@Z
*/

#ifndef BLD_NATIVE
unsigned int ReadCSV(const char* file_name, B_NDataBase<B_ElementCSV>* csvs) {
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003DBC0
* VC++ mangling:          ??1B_ElementCSV@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_ElementCSV::~B_ElementCSV() {
    mass = 0;
}
#endif
