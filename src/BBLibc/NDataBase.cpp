#define BBLIBC_LIB_EXPORT
#include "NDataBase.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003DBF3
* VC++ mangling:          ?ReadCSV@@YAIPBDPAV ? $B_NDataBase@UB_ElementCSV@@@@@Z
*/

unsigned int ReadCSV(const char* file_name, B_NDataBase<B_ElementCSV>* csvs) {
	// TODO Implement
	return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003DBC0
* VC++ mangling:          ??1B_ElementCSV@@UAE@XZ
*/

B_ElementCSV::~B_ElementCSV() {
	// TODO Implement
    mass = 0;
}
