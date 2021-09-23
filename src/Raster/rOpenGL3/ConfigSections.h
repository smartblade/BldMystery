#pragma once

#include "GLVideoMode.h"
#include <BBLibc.h>


class B_ConfigSection
{
public:
    B_ConfigSection(const B_Name &fileName, const B_Name &sectionName)
        : fileName(fileName), sectionName(sectionName)
    {
    }

    virtual ~B_ConfigSection()
    {
    }

private:
    B_Name fileName;
    B_Name sectionName;
};

class B_VideoModeSection : public B_ConfigSection
{
public:
    B_VideoModeSection(const char *fileName)
        : B_ConfigSection(fileName, "VideoModes")
    {
        GetVideoModes(this->videoModes);
        Read();
    }

    int Read();

    int isWindow;
    int bpp;
    int width;
    int height;
    int flags;
    int frequency;
    B_PtrArray<B_VideoMode> videoModes;
};
