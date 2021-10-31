#include "ROpenGLDeviceDLL.h"


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001BEC0
* VC++ mangling:          ?FullScreen@B_OpenGLRasterDevice@@UAEHXZ
*/

int B_OpenGLRasterDevice::FullScreen()
{
    return this->fullScreenMode != NULL;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001BEDC
*/
#ifndef BLD_NATIVE
void GetVideoModes(B_PtrArray<B_VideoMode> &videoModes)
{
}
#endif


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001C0BC
* VC++ mangling:          ?GetVideoModes@B_OpenGLRasterDevice@@QAEXXZ
*/

void B_OpenGLRasterDevice::GetVideoModes()
{
    ::GetVideoModes(this->videoModes);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001C0D8
* VC++ mangling:          ?GetVideoModeDscr@B_OpenGLRasterDevice@@UAEHHAAH0000@Z
*/

int B_OpenGLRasterDevice::GetVideoModeDscr(
    int mode_index, int &depth, int &w, int &h, int &flags,
    int &frequency
)
{
    if (mode_index < 0 || (unsigned int)mode_index >= this->videoModes.size)
        return false;
    depth = this->videoModes[mode_index]->depth;
    w = this->videoModes[mode_index]->width;
    h = this->videoModes[mode_index]->height;
    flags = this->videoModes[mode_index]->flags;
    frequency = this->videoModes[mode_index]->frequency;
    return true;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001C197
* VC++ mangling:          ?SetVideoMode@B_OpenGLRasterDevice@@UAEHH@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::SetVideoMode(int mode_index)
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001CCF8
* VC++ mangling:          ?GetCurrentMode@B_OpenGLRasterDevice@@UAEHAAH0000@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::GetCurrentMode(
    int &unknown1, int &w, int &h, int &unknown4,
    int &unknown5
)
{
    return 0;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001CD74
* VC++ mangling:          ?SetVideoModeParameters@B_OpenGLRasterDevice@@UAEHHHHH@Z
*/

int B_OpenGLRasterDevice::SetVideoModeParameters(
    int depth, int width, int height, int frequency
)
{
    unsigned int i;
    if (frequency == -1)
    {
        for (i = 0; i < this->videoModes.size; i++)
        {
            if (
                (depth == this->videoModes[i]->depth) &&
                (width == this->videoModes[i]->width) &&
                (height == this->videoModes[i]->height)
            )
                return this->SetVideoMode(i);
        }
    }
    else
    {
        for (i = 0; i < this->videoModes.size; i++)
        {
            if (
                (depth == this->videoModes[i]->depth) &&
                (width == this->videoModes[i]->width) &&
                (height == this->videoModes[i]->height) &&
                (frequency == this->videoModes[i]->frequency)
            )
                return this->SetVideoMode(i);
        }
    }
    return false;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001CED6
* VC++ mangling:          ?SetWindowSize@B_OpenGLRasterDevice@@UAEHHH@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::SetWindowSize(int w, int h)
{
    return 0;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001D667
* VC++ mangling:          ?GetWindowSize@B_OpenGLRasterDevice@@UAEHAAH0@Z
*/

int B_OpenGLRasterDevice::GetWindowSize(int &w, int &h)
{
    if (this->FullScreen())
        return false;
    w = this->width;
    h = this->height;
    return true;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
