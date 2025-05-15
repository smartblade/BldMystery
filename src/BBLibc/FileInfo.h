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

private:
    int unknown00;
    char *unknown04;
    int fd;
    int unknown0C;
    long dataStartPos;
};
