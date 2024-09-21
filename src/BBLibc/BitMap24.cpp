#define BBLIBC_LIB_EXPORT
#include "BitMap24.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006CB0
* VC++ mangling:          ??0B_BitMap24@@QAE@HH@Z
*/
#ifndef BLD_NATIVE
B_BitMap24::B_BitMap24(int width, int height)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006E70
* VC++ mangling:          ??1B_BitMap24@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_BitMap24::~B_BitMap24()
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10026C70
* VC++ mangling:          ?ClearBitMap24Data@B_BitMap24@@SAXXZ
*/
#ifndef BLD_NATIVE
void B_BitMap24::ClearBitMap24Data(void)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10026C70
* VC++ mangling:          ?SetBits@B_BitMap24@@QAEXHHPBD0@Z
*/
#ifndef BLD_NATIVE
void B_BitMap24::SetBits(int, int, char const*, char const*)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10027382
* VC++ mangling:          ?SaveToBMP@B_BitMap24@@QBEHPBD@Z
*/
#ifndef BLD_NATIVE
int B_BitMap24::SaveToBMP(char const* fileName) const
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002778F
* VC++ mangling:          ?SaveToBMPSized@B_BitMap24@@QBEHPBDHH@Z
*/
#ifndef BLD_NATIVE
int B_BitMap24::SaveToBMPSized(char const* fileName, int width, int height) const {
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10027F15
* VC++ mangling:          ?SaveToFile@B_BitMap24@@QBEHPBDH@Z
*/
#ifndef BLD_NATIVE
int B_BitMap24::SaveToFile(char const*, int) const
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10028353
* VC++ mangling:          ?EscribeArchivoRAW@B_BitMap24@@QBEXPBD@Z
*/
#ifndef BLD_NATIVE
void B_BitMap24::EscribeArchivoRAW(char const*) const
{

}
#endif


//B_BitMap24 B_BitMap24::ReadFromJPEG(char const*)
//{
//}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029700
* VC++ mangling:          ?SaveToJPEG@B_BitMap24@@QBEHPBDH@Z
*/
#ifndef BLD_NATIVE
int B_BitMap24::SaveToJPEG(char const*, int) const
{
    return 0;
}
#endif

B_Array<B_BitMap24> B_BitMap24::BitMap24DataList(1);

