#define BBLIBC_LIB_EXPORT
#include "ODataFile.h"
#include "MessageManager.h"
#include "Color.h"
#include "Name.h"
#include "NamedObj.h"
#include "BitMap.h"
#include "BitMap24.h"
#include "Vararg.h"
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C44
* VC++ mangling:          ??0B_ODataFile@@QAE@PBDH@Z
*/

B_ODataFile::B_ODataFile(const char *file_name, int flags)
{
    this->cacheBlockStartPos = 0;
    this->posInCacheBlock = 0;
    this->file_name = strdup(file_name);
    this->fd =
        open(
            file_name,
            flags | O_WRONLY | O_CREAT | O_TRUNC,
            S_IWRITE | S_IREAD
        );
    if (this->fd == -1)
    {
        mout << vararg("Could not write to the file %s.\n", file_name);
        switch (errno)
        {
            case EACCES:
                mout <<
                    "read-only, or file\x92s sharing mode does not allow "
                        "specified operations, or given path is directory\n";
                break;
            case EEXIST:
                mout <<
                    "_O_CREAT and _O_EXCL flags specified, but filename "
                        "already exists\n";
                break;
            case EINVAL:
                mout << "Invalid oflag or pmode argument\n";
                break;
            case EMFILE:
                mout <<
                    "No more file handles available (too many open files)\n";
                break;
            case ENOENT:
                mout << "File or path not found\n";
                break;
            default:
                mout << "Unknown error!!!!!!!!1\n";
                break;
        }
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001DA0
* VC++ mangling:          ?WriteCacheBlock@B_ODataFile@@AAEXXZ
*/

void B_ODataFile::WriteCacheBlock()
{
    if (this->posInCacheBlock == 0)
    {
        return;
    }
    write(this->fd, &this->fileCache, this->posInCacheBlock);
    this->cacheBlockStartPos += this->posInCacheBlock;
    this->posInCacheBlock = 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001E01
* VC++ mangling:          ?Seek@B_ODataFile@@QAEJJ@Z
*/

long B_ODataFile::Seek(long position)
{
    if (
        static_cast<unsigned int>(position) > this->cacheBlockStartPos &&
        static_cast<unsigned int>(position) <
            this->cacheBlockStartPos + OFILE_CACHE_SIZE
    )
    {
        this->posInCacheBlock =
            static_cast<unsigned int>(position) - this->cacheBlockStartPos;
    }
    else
    {
        this->cacheBlockStartPos = static_cast<unsigned int>(position);
        this->posInCacheBlock = 0;
        lseek(this->fd, position, SEEK_SET);
    }
    return static_cast<long>(this->cacheBlockStartPos + this->posInCacheBlock);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001E86
* VC++ mangling:          ?Write@B_ODataFile@@QAEXPBXI@Z
*/

void B_ODataFile::Write(const void *data, unsigned int size)
{
    if (size == 0)
    {
        return;
    }
    if (size < OFILE_CACHE_SIZE - this->posInCacheBlock)
    {
        memcpy(
            &this->fileCache[this->posInCacheBlock],
            data,
            static_cast<size_t>(size)
        );
        this->posInCacheBlock += size;
        return;
    }
    unsigned int remainingCache = OFILE_CACHE_SIZE - this->posInCacheBlock;
    if (remainingCache != 0)
    {
        memcpy(
            &this->fileCache[this->posInCacheBlock],
            data,
            static_cast<size_t>(remainingCache)
        );
        this->posInCacheBlock = OFILE_CACHE_SIZE;
        size -= remainingCache;
    }
    this->WriteCacheBlock();
    this->Write(&static_cast<const char *>(data)[remainingCache], size);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F5E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABD@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const char &c)
{
    file.Write(&c, sizeof(char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F74
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@PBD@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const char *c)
{
    file.Write(c, static_cast<unsigned int>(strlen(c)));
    return file;
}



/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F9A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABE@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const unsigned char &c)
{
    file.Write(&c, sizeof(unsigned char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FB0
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABF@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const short &s)
{
    file.Write(&s, sizeof(short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FC6
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABG@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const unsigned short &s)
{
    file.Write(&s, sizeof(unsigned short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FDC
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABH@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const int &i)
{
    file.Write(&i, sizeof(int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FF2
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABJ@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const long &l)
{
    file.Write(&l, sizeof(long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002008
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABK@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const unsigned long &l)
{
    file.Write(&l, sizeof(unsigned long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000201E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABI@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const unsigned int &i)
{
    file.Write(&i, sizeof(unsigned int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002034
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABM@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const float &f)
{
    file.Write(&f, sizeof(float));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000204A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABN@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const double &f)
{
    file.Write(&f, sizeof(double));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002060
* VC++ mangling:          ?Flush@B_ODataFile@@QAEXXZ
*/

void B_ODataFile::Flush()
{
    this->WriteCacheBlock();
    _commit(this->fd);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002082
* VC++ mangling:          ??1B_ODataFile@@QAE@XZ
*/

B_ODataFile::~B_ODataFile()
{
    free(this->file_name);
    if (this->OK())
    {
        this->WriteCacheBlock();
        close(this->fd);
    }
}
