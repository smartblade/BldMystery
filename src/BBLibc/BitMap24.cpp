#define BBLIBC_LIB_EXPORT
#include "BitMap24.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Data address:           0x1004A520
* VC++ mangling:          ?BitMap24DataList@B_BitMap24@@0V?$B_Array@VB_BitMap24@@@@A
*/
#ifndef BLD_NATIVE
B_Array<B_BitMap24> B_BitMap24::BitMap24DataList(1);
#endif


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
* Entry point:            0x10026AD5
* VC++ mangling:          ??0B_BitMap24@@QAE@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_BitMap24::B_BitMap24(const B_BitMap24& that)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10026C70
* VC++ mangling:          ?ClearBitMap24Data@B_BitMap24@@SAXXZ
*/
#ifndef BLD_NATIVE
void B_BitMap24::ClearBitMap24Data()
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100272A5
* VC++ mangling:          ?SetBits@B_BitMap24@@QAEIHHPBD0@Z
*/
#ifndef BLD_NATIVE
unsigned int B_BitMap24::SetBits(int, int, char const*, char const*)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100271BE
* VC++ mangling:          ??4B_BitMap24@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_BitMap24& B_BitMap24::operator=(const B_BitMap24& that)
{
    return *this;
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
* Entry point:            0x10028021
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_BitMap24@@@Z
*/
#ifndef BLD_NATIVE
B_IDataFile& operator >>(B_IDataFile& file, B_BitMap24& bitMap)
{
    return file;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100280CC
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_BitMap24@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, B_BitMap24 const& bitMap)
{
    file.Write(&bitMap, sizeof(B_BitMap24));
    return file;
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
