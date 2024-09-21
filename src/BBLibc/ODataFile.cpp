#define BBLIBC_LIB_EXPORT
#include "ODataFile.h"
#include "Color.h"
#include "Name.h"
#include "NamedObj.h"
#include "BitMap.h"
#include "BitMap24.h"

#include <io.h>


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C44
* VC++ mangling:          ??0B_ODataFile@@QAE@PBDH@Z
*/
#ifndef BLD_NATIVE
B_ODataFile::B_ODataFile(const char* file_name, int flags)
    : fd(-1), file_name(nullptr) {

    size_t file_name_len = strlen(file_name);
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002082
* VC++ mangling:          ??1B_ODataFile@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_ODataFile::~B_ODataFile()
{
    if (fd != -1) {
        _close(fd);
    }
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001E86
* VC++ mangling:          ?Write@B_ODataFile@@QAEXPBXI@Z
*/
#ifndef BLD_NATIVE
void B_ODataFile::Write(const void* data, unsigned int size)
{
    if (fd != -1) {
        _write(fd, data, size);
    }
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002250
* VC++ mangling:          ?OK@B_ODataFile@@QBEIXZ
*/
#ifndef BLD_NATIVE
unsigned int B_ODataFile::OK() const
{
    return fd != -1;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F5E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABD@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, char const& c)
{
    file.Write(&c, sizeof(char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F74
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@PBD@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, char const* c)
{
    return file;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F9A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABE@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned char const& c)
{
    file.Write(&c, sizeof(unsigned char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FB0
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABF@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, short const& s)
{
    file.Write(&s, sizeof(short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FC6
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABG@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, const unsigned short& s)
{
    file.Write(&s, sizeof(unsigned short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FDC
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABH@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, int const& i)
{
    file.Write(&i, sizeof(int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FF2
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABJ@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, long const& l)
{
    file.Write(&l, sizeof(long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002008
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABK@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned long const& l)
{
    file.Write(&l, sizeof(unsigned long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000201E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABI@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned int const& i)
{
    file.Write(&i, sizeof(unsigned int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002034
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABM@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, float const& f)
{
    file.Write(&f, sizeof(float));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000204A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABN@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, double const& f)
{
    file.Write(&f, sizeof(double));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000398A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, B_Name const& name)
{
    file.Write(&name, sizeof(B_Name));
    return file;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A58
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_NamedObj@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, B_NamedObj const& namedObj)
{
    file.Write(&namedObj, sizeof(B_NamedObj));
    return file;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10008B51
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_BitMap@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, B_BitMap const& bitMap)
{
    file.Write(&bitMap, sizeof(B_BitMap));
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
* Entry point:            0x100413EE
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_ParticleGType@@@Z
*/
#ifndef BLD_NATIVE
B_ODataFile& operator <<(B_ODataFile& file, const B_ParticleGType& particleType)
{
    file.Write(&particleType, sizeof(B_ParticleGType));
    return file;
}
#endif

