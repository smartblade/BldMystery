
#ifndef B_COLOR_H

#define B_COLOR_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class B_IDataFile;
class B_ODataFile;

class LIB_EXP B_Color
{
public:

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006860
    * VC++ mangling:          ??0B_Color@@QAE@XZ
    */

    B_Color()
    :
        r(0),
        g(0),
        b(0)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006890
    * VC++ mangling:          ??0B_Color@@QAE@EEE@Z
    */

    B_Color(byte r, byte g, byte b)
    :
        r(r),
        g(g),
        b(b)
    {
        this->MakeCons();
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100068D0
    * VC++ mangling:          ??HB_Color@@QBE?AV0@ABV0@@Z
    */
#ifndef BLD_NATIVE
    B_Color operator +(B_Color const &color) const
    {
        return *this;
    }
#else
    B_Color operator +(B_Color const &color) const;
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006950
    * VC++ mangling:          ??DB_Color@@QBE?AV0@M@Z
    */
#ifndef BLD_NATIVE
    B_Color operator *(float coef) const
    {
        return B_Color(static_cast<byte>(r * coef), static_cast<byte>(g * coef), static_cast<byte>(b * coef));
    }
#else
    B_Color operator *(float coef) const;
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100069E0
    * VC++ mangling:          ??KB_Color@@QBE?AV0@M@Z
    */
#ifndef BLD_NATIVE
    B_Color operator /(float f)const
    {
        return *this;
    }
#else
    B_Color operator /(float f)const;
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006A70
    * VC++ mangling:          ??8B_Color@@QAEIABV0@@Z
    */
#ifndef BLD_NATIVE
    unsigned int operator ==(const B_Color &arg_1)
    {
        return 0;
    }
#else
    unsigned int operator ==(const B_Color &arg_1);
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006AD0
    * VC++ mangling:          ??9B_Color@@QAEIABV0@@Z
    */
#ifndef BLD_NATIVE
    unsigned int operator !=(const B_Color &arg_1)
    {
        return 0;
    }
#else
    unsigned int operator !=(const B_Color &arg_1);
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006B30
    * VC++ mangling:          ?SetColor@B_Color@@QAEXEEE@Z
    */
#ifndef BLD_NATIVE
    void SetColor(unsigned char arg_1, unsigned char arg_2, unsigned char arg_3)
    {
    }
#else
    void SetColor(
        unsigned char arg_1,
        unsigned char arg_2,
        unsigned char arg_3
    );
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006B60
    * VC++ mangling:          ??0B_Color@@QAE@ABV0@@Z
    */

    B_Color(const B_Color &that)
    :
        r(that.r),
        g(that.g),
        b(that.b)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006BA0
    * VC++ mangling:          ??4B_Color@@QAEAAV0@ABV0@@Z
    */

    B_Color &operator =(const B_Color &that)
    {
        this->r = that.r;
        this->g = that.g;
        this->b = that.b;
        return *this;
    }

    virtual void MakeCons();
    float DistanceTo(const B_Color &arg_1);

    byte r;
    byte g;
    byte b;
};

LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_Color &color);
LIB_EXP B_ODataFile &operator <<(B_ODataFile &file, B_Color const &color);

#endif /* B_COLOR_H */
