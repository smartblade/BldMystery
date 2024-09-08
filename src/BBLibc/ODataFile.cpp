#define BBLIBC_LIB_EXPORT
#include "ODataFile.h"
#include "Color.h"
#include "Name.h"
#include "NamedObj.h"

#include <io.h>


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C44
* VC++ mangling:          ??0B_ODataFile@@QAE@PBDH@Z
*/

B_ODataFile::B_ODataFile(const char* file_name, int flags)
    : fd(-1), file_name(nullptr) {
    // TODO Implement
    size_t file_name_len = strlen(file_name);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002082
* VC++ mangling:          ??1B_ODataFile@@QAE@XZ
*/

B_ODataFile::~B_ODataFile()
{
    if (fd != -1) {
        _close(fd);
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001E86
* VC++ mangling:          ?Write@B_ODataFile@@QAEXPBXI@Z
*/

void B_ODataFile::Write(const void* data, unsigned int size)
{
    if (fd != -1) {
        _write(fd, data, size);
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002008
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABK@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned long const& i) {
    file.Write(&i, sizeof(unsigned long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000201E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABI@Z
*/

B_ODataFile& operator<<(B_ODataFile& file, const unsigned int& i)
{
    file.Write(&i, sizeof(unsigned int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100091DF
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Color@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, class B_Color const& color) {
    file.Write(&color, sizeof(B_Color));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000398A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Name@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, class B_Name const& name) {
    file.Write(&name, sizeof(B_Name));
    return file;
}

/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A58
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_NamedObj@@@Z
*/

B_ODataFile& operator<<(B_ODataFile& file, class B_NamedObj const& namedObj) {
    file.Write(&namedObj, sizeof(B_NamedObj));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100413EE
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_ParticleGType@@@Z
*/

B_ODataFile& operator<<(B_ODataFile& file, const B_ParticleGType& particleType)
{
    file.Write(&particleType, sizeof(B_ParticleGType));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002034
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABM@Z
*/

B_ODataFile& operator<<(B_ODataFile& file, float const& i) {
    file.Write(&i, sizeof(float));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000204A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABN@Z
*/

B_ODataFile& operator<<(B_ODataFile& file, double const& i) {
    file.Write(&i, sizeof(double));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FDC
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABH@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, int const& i) {
    file.Write(&i, sizeof(int));
    return file;
}

/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F74
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@PBD@Z
*/

B_ODataFile& operator<<(B_ODataFile& file, char const* c) {
    file.Write(c, sizeof(char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FB0
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABF@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, short const& c) {
    // TODO Implement
    //file.Write(c, sizeof(short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F9A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABE@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned char const& c) {
    // TODO Implement
    return file;
}

