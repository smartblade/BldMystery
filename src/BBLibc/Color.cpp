#define BBLIBC_LIB_EXPORT
#include "Color.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006860
* VC++ mangling:          ??0B_Color@@QAE@XZ
*/

B_Color::B_Color() : r(0), g(0), b(0) {}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006890
* VC++ mangling:          ??0B_Color@@QAE@EEE@Z
*/

B_Color::B_Color(byte r, byte g, byte b) : r(r), g(g), b(b)
{
    MakeCons();
};


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
* Entry point:            0x10006BA0
* VC++ mangling:          ??4B_Color@@QAEAAV0@ABV0@@Z
*/

B_Color& B_Color::operator =(const B_Color& that)
{
    r = that.r;
    g = that.g;
    b = that.b;
    return *this;
}


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

