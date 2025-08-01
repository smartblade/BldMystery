#pragma once

#include <io.h>

class B_FileInfo
{
public:
    ~B_FileInfo()
    {
        if (this->fd != -1)
        {
            close(this->fd);
            free(this->unknown04);
        }
    }

    int Seek(unsigned int position)
    {
        if (this->unknown0C == -1)
        {
            return 0;
        }
        lseek(
            this->fd,
            this->dataStartPos + static_cast<long>(position),
            SEEK_SET
        );
        return this->fd;
    }

private:
    int unknown00;
    char *unknown04;
    int fd;
    int unknown0C;
    long dataStartPos;
};
