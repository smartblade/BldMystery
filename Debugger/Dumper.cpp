#include "Dumper.h"
#include <stdarg.h>
#include <stdio.h>

Dumper::Dumper(Level level) : level(level)
{
}

void Dumper::Printf(Level level, char const* const format, ...)
{
    if (level >= this->level)
    {
        va_list ptr;
        va_start(ptr, format);
        vprintf(format, ptr);
        va_end(ptr);
    }
}
