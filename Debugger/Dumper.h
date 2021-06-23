#pragma once

class Dumper
{
public:
    enum class Level
    {
        Debug = 1,
        Info = 2,
    };
    Dumper(Level level);
    void Printf(Level level, char const* const format, ...);

private:
    Level level = Level::Debug;
};

