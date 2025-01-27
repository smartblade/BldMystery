#define BBLIBC_LIB_EXPORT
#include "Color.h"
#include "ODataFile.h"


/*
*
* Implicit definition of virtual method table for B_Color.
* Generated by compiler.
*
* Module:                 BBLibc.dll
* Data address:           0x100421F0
* VC++ mangling:          ??_7B_Color@@6B@
*/


/*
* Module:                 BBLibc.dll
* Entry point:            0x100068D0
* VC++ mangling:          ??HB_Color@@QBE?AV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_Color B_Color::operator +(B_Color const& color) const
{
    return *this;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006950
* VC++ mangling:          ??DB_Color@@QBE?AV0@M@Z
*/
#ifndef BLD_NATIVE
B_Color B_Color::operator *(float coef) const
{
    return B_Color(static_cast<byte>(r * coef), static_cast<byte>(g * coef), static_cast<byte>(b * coef));
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100069E0
* VC++ mangling:          ??KB_Color@@QBE?AV0@M@Z
*/
#ifndef BLD_NATIVE
B_Color B_Color::operator /(float f)const
{
    return *this;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100091A4
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Color@@@Z
*/
#ifndef BLD_NATIVE
B_IDataFile& operator >>(B_IDataFile& file, B_Color& color)
{
    return file;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100091DF
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Color@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, B_Color const& color)
{
    file.Write(&color, sizeof(B_Color));
    return file;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x1000921A
* VC++ mangling:          ?MakeCons@B_Color@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_Color::MakeCons()
{

}
#endif

