#include <fcntl.h>
#include <io.h>
#include <bld_python.h>
#define BBLIBC_LIB_EXPORT
#include "BBLibc.h"
#include "IDataFile.h"
#include "FileInfo.h"


/*
* Module:                 BBLibc.dll
* Data address:           0x10049EFC
* VC++ mangling:          ?n_opened_files@B_IDataFile@@0HA
*/
int B_IDataFile::n_opened_files = 0;

/*
* Module:                 BBLibc.dll
* Data address:           0x10049F00
* VC++ mangling:          ?n_open_files@B_IDataFile@@0HA
*/
int B_IDataFile::n_open_files = 0;

/*
* Module:                 BBLibc.dll
* Data address:           0x10049F04
* VC++ mangling:          ?OnOpenFunc@B_IDataFile@@0PAUPyObject@@A
*/
PyObject *B_IDataFile::OnOpenFunc = nullptr;


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001000
* VC++ mangling:          ?ResetnOpenedFiles@B_IDataFile@@SAXXZ
*/

void B_IDataFile::ResetnOpenedFiles()
{
    B_IDataFile::n_opened_files = 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000100F
* VC++ mangling:          ?GetnOpenedFiles@B_IDataFile@@SAHXZ
*/

int B_IDataFile::GetnOpenedFiles()
{
    return B_IDataFile::n_opened_files;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001019
* VC++ mangling:          ?GetnOpenFiles@B_IDataFile@@SAHXZ
*/

int B_IDataFile::GetnOpenFiles()
{
    return B_IDataFile::n_open_files;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001023
* VC++ mangling:          ?SetOnOpenFunc@B_IDataFile@@SAHPAUPyObject@@@Z
*/

int B_IDataFile::SetOnOpenFunc(PyObject *obj)
{
    if (obj != nullptr)
    {
        Py_XDECREF(B_IDataFile::OnOpenFunc);
        Py_XINCREF(obj);
        B_IDataFile::OnOpenFunc = obj;
    }
    else
    {
        return false;
    }
    return true;
}



/*
* Module:                 BBLibc.dll
* Entry point:            0x10001096
* VC++ mangling:          ?RemoveOnOpenFunc@B_IDataFile@@SAXXZ
*/

void B_IDataFile::RemoveOnOpenFunc()
{
    Py_XDECREF(B_IDataFile::OnOpenFunc);
    B_IDataFile::OnOpenFunc = nullptr;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 BBLibc.dll
* Entry point:            0x100014D2
* VC++ mangling:          ?Close@B_IDataFile@@QAEXXZ
*/

void B_IDataFile::Close()
{
    this->cacheBlockStartPos = -IFILE_CACHE_SIZE;
    this->posInCacheBlock = 0;
    if (this->file_name != nullptr)
    {
        free(this->file_name);
        this->file_name = nullptr;
    }
    if (this->fileInfo != nullptr)
    {
        delete this->fileInfo;
        this->fileInfo = nullptr;
        this->fd = -1;
        return;
    }
    if (this->OK())
    {
        close(this->fd);
        this->fd = -1;
        B_IDataFile::n_open_files--;
    }
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100015E2
* VC++ mangling:          ?Open@B_IDataFile@@QAEXPBDH@Z
*/

void B_IDataFile::Open(const char *src, int flags)
{
    this->file_name = strdup(src);
    this->fileInfo = nullptr;
    if (this->fileInfo == nullptr)
    {
        this->fd = open(src, flags);
        if (!this->OK())
        {
            return;
        }
        this->file_size = static_cast<unsigned int>(filelength(this->fd));
        B_IDataFile::n_opened_files++;
        B_IDataFile::n_open_files++;
        if (B_IDataFile::OnOpenFunc != nullptr)
        {
            PyObject *args = PyTuple_New(2);
            PyObject *nFilesObj = PyInt_FromLong(B_IDataFile::n_opened_files);
            PyObject *fileNameObj = PyString_FromString(this->file_name);
            PyTuple_SET_ITEM(args, 0, nFilesObj);
            PyTuple_SET_ITEM(args, 1, fileNameObj);
            PyObject *result = CallPythonObject(B_IDataFile::OnOpenFunc, args);
            Py_DECREF(args);
            Py_XDECREF(result);
        }
    }
    this->ReadCacheBlock();
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001740
* VC++ mangling:          ??0B_IDataFile@@QAE@XZ
*/

B_IDataFile::B_IDataFile()
{
    this->fd = -1;
    this->file_name = nullptr;
    this->cacheBlockStartPos = -IFILE_CACHE_SIZE;
    this->posInCacheBlock = 0;
    this->fileInfo = nullptr;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001788
* VC++ mangling:          ??0B_IDataFile@@QAE@PBDH@Z
*/

B_IDataFile::B_IDataFile(const char *file_name, int flags)
{
    this->cacheBlockStartPos = -IFILE_CACHE_SIZE;
    this->posInCacheBlock = 0;
    this->Open(file_name, flags);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100017C2
* VC++ mangling:          ?ReadCacheBlock@B_IDataFile@@AAEIXZ
*/
#ifndef BLD_NATIVE
unsigned int B_IDataFile::ReadCacheBlock()
{
    return 1;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001882
* VC++ mangling:          ?Length@B_IDataFile@@QBEJXZ
*/

long B_IDataFile::Length() const
{
    if (fd != -1)
    {
        return file_size;
    }

    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100018A6
* VC++ mangling:          ?Seek@B_IDataFile@@QAEJJH@Z
*/
#ifndef BLD_NATIVE
long B_IDataFile::Seek(long offset, int whence)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100019AF
* VC++ mangling:          ?Tell@B_IDataFile@@QAEJXZ
*/
#ifndef BLD_NATIVE
long B_IDataFile::Tell()
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100019CC
* VC++ mangling:          ?Peek@B_IDataFile@@QAEEXZ
*/
#ifndef BLD_NATIVE
unsigned char B_IDataFile::Peek()
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001A0D
* VC++ mangling:          ?Eof@B_IDataFile@@QAEHXZ
*/

int B_IDataFile::Eof()
{
    return this->cacheBlockStartPos + this->posInCacheBlock >= this->file_size;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001A33
* VC++ mangling:          ?Read@B_IDataFile@@QAEXPAXI@Z
*/
#ifndef BLD_NATIVE
void B_IDataFile::Read(void *data, unsigned int size)
{

}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B55
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAD@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, char &c)
{
    file.Read(&c, sizeof(char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B6B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAE@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, unsigned char &c)
{
    file.Read(&c, sizeof(unsigned char));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B81
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAF@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, short &s)
{
    file.Read(&s, sizeof(short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B97
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAG@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, unsigned short &s)
{
    file.Read(&s, sizeof(unsigned short));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BAD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAH@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, int &i)
{
    file.Read(&i, sizeof(int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BC3
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAJ@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, long &l)
{
    file.Read(&l, sizeof(long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BD9
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAK@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, unsigned long &l)
{
    file.Read(&l, sizeof(unsigned long));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BEF
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAI@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, unsigned int &i)
{
    file.Read(&i, sizeof(unsigned int));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C05
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAM@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, float &f)
{
    file.Read(&f, sizeof(float));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C1B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAN@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, double &f)
{
    file.Read(&f, sizeof(double));
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C31
* VC++ mangling:          ??1B_IDataFile@@QAE@XZ
*/

B_IDataFile::~B_IDataFile()
{
    this->Close();
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002220
* VC++ mangling:          ??4B_IDataFile@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_IDataFile &B_IDataFile::operator =(B_IDataFile const &file)
{
    return *this;
}
#endif
