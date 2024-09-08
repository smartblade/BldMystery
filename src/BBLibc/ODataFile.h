
#ifndef B_O_DATA_FILE_H

#define B_O_DATA_FILE_H

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
    unsigned int OK() const { return fd != -1; }
    void Write(const void* data, unsigned int size);

private:
    int fd;
    char* file_name;
    char unknown_fields[16392];
};

LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, unsigned long const& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, const unsigned int& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, class B_Color const& color);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, class B_Name const& name);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, class B_NamedObj const& namedObj);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, const B_ParticleGType& particleType);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, float const& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, double const& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, int const& i);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, char const* c);
LIB_EXP B_ODataFile& operator <<(B_ODataFile& file, short const& c);
LIB_EXP B_ODataFile& operator <<(B_ODataFile&, unsigned char const&);


#endif /* B_O_DATA_FILE_H */
