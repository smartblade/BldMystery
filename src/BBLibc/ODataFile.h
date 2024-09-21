
#ifndef B_O_DATA_FILE_H

#define B_O_DATA_FILE_H

#include "Color.h"
#include "BitMap.h"
#include "BitMap24.h"
#include "ParticleGType.h"

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_ODataFile
{
public:
    B_ODataFile(const char* file_name, int flags);
    ~B_ODataFile();
    void Write(const void* data, unsigned int size);
    unsigned int OK() const;

private:
    int fd;
    char* file_name;
    char unknown_fields[16392];
};


LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, char const& c);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, char const* c);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, unsigned char const& c);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, short const& s);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, unsigned short const& s);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, int const& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, long const& l);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, unsigned long const& l);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, const unsigned int& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, float const& f);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, double const& f);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, B_Name const& name);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, B_NamedObj const& namedObj);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, B_BitMap const& bitMap);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, B_Color const& color);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, B_BitMap24 const& bitMap);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, const B_ParticleGType& particleType);


#endif /* B_O_DATA_FILE_H */

