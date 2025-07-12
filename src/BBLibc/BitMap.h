
#ifndef B_BITMAP_H

#define B_BITMAP_H

#include <BBLibc/Pal.h>
#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class B_IDataFile;
class B_ODataFile;

class LIB_EXP B_BitMap
{
public:
    enum BitMapType
    {
        BitMapType2 = 2,
        BitMapType4 = 4,
    };
    virtual ~B_BitMap();
    B_BitMap(const B_BitMap &src);
    B_BitMap(BitMapType type, unsigned int, unsigned int, const B_Pal *pal);


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006C20
    * VC++ mangling:          ??4B_BitMap@@QAEAAV0@ABV0@@Z
    */

    B_BitMap &operator=(const B_BitMap &that)
    {
        type = that.type;
        dimension1 = that.dimension1;
        dimension2 = that.dimension2;
        data = that.data;
        pal = that.pal;
        return *this;
    }

    BitMapType type;
    unsigned int dimension1;
    unsigned int dimension2;
    void *data;
    B_Pal *pal;
};

LIB_EXP B_IDataFile &operator >>(B_IDataFile &file, B_BitMap &bitMap);
LIB_EXP B_ODataFile &operator <<(B_ODataFile &file, B_BitMap const &bitMap);

#endif /* B_BITMAP_H */
