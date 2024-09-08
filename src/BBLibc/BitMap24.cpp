#define BBLIBC_LIB_EXPORT
#include "BitMap24.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006CB0
* VC++ mangling:          ??0B_BitMap24@@QAE@HH@Z
*/

B_BitMap24::B_BitMap24(int width, int height) {
    // TODO implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006E70
* VC++ mangling:          ??1B_BitMap24@@UAE@XZ
*/

B_BitMap24::~B_BitMap24() {
    // TODO implement
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10027382
* VC++ mangling:          ?SaveToBMP@B_BitMap24@@QBEHPBD@Z
*/

int B_BitMap24::SaveToBMP(char const* fileName) const {
    // TODO implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002778F
* VC++ mangling:          ?SaveToBMPSized@B_BitMap24@@QBEHPBDHH@Z
*/

int B_BitMap24::SaveToBMPSized(char const* fileName, int width, int height) const {
    // TODO implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10026C70
* VC++ mangling:          ?ClearBitMap24Data@B_BitMap24@@SAXXZ
*/

void B_BitMap24::ClearBitMap24Data(void) {
    // TODO implement
}


B_Array<B_BitMap24> B_BitMap24::BitMap24DataList(1);
