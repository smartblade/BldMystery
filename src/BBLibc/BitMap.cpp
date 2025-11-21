#define BBLIBC_LIB_EXPORT
#include "BitMap.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100085F0
* VC++ mangling:          ??0B_BitMap@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_BitMap::B_BitMap()
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10008639
* VC++ mangling:          ??0B_BitMap@@QAE@W4BitMapType@0@IIPBVB_Pal@@@Z
*/
#ifndef BLD_NATIVE
B_BitMap::B_BitMap(BitMapType type, unsigned int, unsigned int, const B_Pal *pal)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100086E3
* VC++ mangling:          ??0B_BitMap@@QAE@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_BitMap::B_BitMap(const B_BitMap &src)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10008974
* VC++ mangling:          ??0B_BitMap@@QAE@W4BitMapType@0@ABVB_BitMap24@@@Z
*/
#ifndef BLD_NATIVE
B_BitMap::B_BitMap(BitMapType arg_1, const B_BitMap24 &arg_2)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10008AF0
* VC++ mangling:          ?BytesPerTexel@B_BitMap@@QBEHXZ
*/
#ifndef BLD_NATIVE
int B_BitMap::BytesPerTexel()
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10008B51
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_BitMap@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile &operator <<(B_ODataFile &file, B_BitMap const &bitMap)
{
    file.Write(&bitMap, sizeof(B_BitMap));
    return file;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10008C9B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_BitMap@@@Z
*/
#ifndef BLD_NATIVE
B_IDataFile &operator >>(B_IDataFile &file, B_BitMap &bitMap)
{
    return file;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10008FDA
* VC++ mangling:          ??1B_BitMap@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_BitMap::~B_BitMap()
{
}
#endif
