
#ifndef B_BITMAP_H

#define B_BITMAP_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_Pal
{
public:
    unsigned char B_Pal::GetRed(unsigned int val) const { return 0; };
    unsigned char B_Pal::GetGreen(unsigned int val) const { return 0; };
    unsigned char B_Pal::GetBlue(unsigned int val) const { return 0; };
};

class LIB_EXP B_BitMap
{
public:
    enum BitMapType
    {
        BitMapType2 = 2,
        BitMapType4 = 4,
    };
    virtual ~B_BitMap();
    B_BitMap(const B_BitMap& src);
    B_BitMap(BitMapType type, unsigned int, unsigned int, const B_Pal* pal);

    BitMapType type;
    unsigned int dimension1;
    unsigned int dimension2;
    void* data;
    B_Pal* pal;
};

#endif /* B_BITMAP_H */