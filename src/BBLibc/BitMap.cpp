#define BBLIBC_LIB_EXPORT
#include "BitMap.h"
#include "ODataFile.h"


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
