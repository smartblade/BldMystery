#include "Surface.h"

#include <BBLibc.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00453B10
* VC++ mangling:          ??0B_Surface@@QAE@XZ
*/
#ifdef BLD_NATIVE
B_Surface::B_Surface()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00453B81
* VC++ mangling:          ??1B_Surface@@UAE@XZ
*/
#ifdef BLD_NATIVE
B_Surface::~B_Surface()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00453B9E
* VC++ mangling:          ?GetPortals@B_Surface@@UAEXPAHPAPAVB_Portal@@@Z
*/
#ifdef BLD_NATIVE
void B_Surface::GetPortals(int *numPortals, B_Portal **portals)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004547D7
* VC++ mangling:          ?unknown018@B_Surface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_Surface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00454806
* VC++ mangling:          ?unknown01C@B_Surface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_Surface::unknown01C()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004548AF
* VC++ mangling:          ?unknown018@B_OpaqueSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_OpaqueSurface::unknown018()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045499F
*/

B_Surface *ReadSurface(B_IDataFile &file)
{
    B_Surface *surface;
    unsigned int classID;

    file >> classID;
    switch (classID)
    {
        case B_SURFACE_CID_OPAQUE:
        {
            surface = new B_OpaqueSurface();
            file >> *static_cast<B_OpaqueSurface *>(surface);
            break;
        }
        case B_SURFACE_CID_TRANSPARENT:
        {
            surface = new B_TransparentSurface();
            file >> *static_cast<B_TransparentSurface *>(surface);
            break;
        }
        case B_SURFACE_CID_SINGLE_PORTAL:
        {
            surface = new B_SinglePortalSurface();
            file >> *static_cast<B_SinglePortalSurface *>(surface);
            break;
        }
        case B_SURFACE_CID_MULTIPLE_PORTAL:
        {
            surface = new B_MultiplePortalSurface();
            file >> *static_cast<B_MultiplePortalSurface *>(surface);
            break;
        }
        case B_SURFACE_CID_DOME:
        {
            surface = new B_DomeSurface();
            file >> *static_cast<B_DomeSurface *>(surface);
            break;
        }
        default:
        {
            surface = NULL;
            break;
        }
    }
    return surface;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00454C44
* VC++ mangling:          ?ClassId@B_DomeSurface@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_DomeSurface::ClassId()
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
* Module:                 Blade.exe
* Entry point:            0x00454E39
* VC++ mangling:          ?unknown014@B_DomeSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_DomeSurface::unknown014()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00454ED5
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_DomeSurface@@@Z
*/
#ifdef BLD_NATIVE
B_IDataFile &operator >>(B_IDataFile &file, B_DomeSurface &surface)
{
    return file;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00454F25
* VC++ mangling:          ?ClassId@B_OpaqueSurface@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_OpaqueSurface::ClassId()
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
* Module:                 Blade.exe
* Entry point:            0x00456594
* VC++ mangling:          ?unknown014@B_OpaqueSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_OpaqueSurface::unknown014()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004566EC
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_OpaqueSurface@@@Z
*/
#ifdef BLD_NATIVE
B_IDataFile &operator >>(B_IDataFile &file, B_OpaqueSurface &surface)
{
    return file;
}
#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004567CD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Portal@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Portal &portal)
{
    file >>
        static_cast<B_Polygon &>(portal) >>
        (unsigned int &)portal.sectorIndex;
    return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045681F
* VC++ mangling:          ??0B_TransparentSurface@@QAE@XZ
*/
#ifdef BLD_NATIVE
B_TransparentSurface::B_TransparentSurface()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00456960
* VC++ mangling:          ?ClassId@B_TransparentSurface@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_TransparentSurface::ClassId()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00456970
* VC++ mangling:          ?GetPortals@B_TransparentSurface@@UAEXPAHPAPAVB_Portal@@@Z
*/
#ifdef BLD_NATIVE
void B_TransparentSurface::GetPortals(int *numPortals, B_Portal **portals)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00456B78
* VC++ mangling:          ?unknown010@B_TransparentSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_TransparentSurface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00456C3A
* VC++ mangling:          ?unknown014@B_TransparentSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_TransparentSurface::unknown014()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00456FF1
* VC++ mangling:          ?unknown018@B_TransparentSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_TransparentSurface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045719A
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_TransparentSurface@@@Z
*/
#ifdef BLD_NATIVE
B_IDataFile &operator >>(B_IDataFile &file, B_TransparentSurface &surface)
{
    return file;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004574A5
* VC++ mangling:          ??0B_SinglePortalSurface@@QAE@XZ
*/
#ifdef BLD_NATIVE
B_SinglePortalSurface::B_SinglePortalSurface()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00457EFE
* VC++ mangling:          ?ClassId@B_SinglePortalSurface@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_SinglePortalSurface::ClassId()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00457F0E
* VC++ mangling:          ?GetPortals@B_SinglePortalSurface@@UAEXPAHPAPAVB_Portal@@@Z
*/
#ifdef BLD_NATIVE
void B_SinglePortalSurface::GetPortals(int *numPortals, B_Portal **portals)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00458123
* VC++ mangling:          ?unknown010@B_SinglePortalSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_SinglePortalSurface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00458217
* VC++ mangling:          ?unknown014@B_SinglePortalSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_SinglePortalSurface::unknown014()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00458CE9
* VC++ mangling:          ?unknown018@B_SinglePortalSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_SinglePortalSurface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00458F60
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_SinglePortalSurface@@@Z
*/
#ifdef BLD_NATIVE
B_IDataFile &operator >>(B_IDataFile &file, B_SinglePortalSurface &surface)
{
    return file;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045AC13
* VC++ mangling:          ??0B_MultiplePortalSurface@@QAE@XZ
*/
#ifdef BLD_NATIVE
B_MultiplePortalSurface::B_MultiplePortalSurface()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045AD21
* VC++ mangling:          ??1B_MultiplePortalSurface@@UAE@XZ
*/
#ifdef BLD_NATIVE
B_MultiplePortalSurface::~B_MultiplePortalSurface()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045AE93
* VC++ mangling:          ?ClassId@B_MultiplePortalSurface@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_MultiplePortalSurface::ClassId()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045AEA3
* VC++ mangling:          ?GetPortals@B_MultiplePortalSurface@@UAEXPAHPAPAVB_Portal@@@Z
*/
#ifdef BLD_NATIVE
void B_MultiplePortalSurface::GetPortals(int *numPortals, B_Portal **portals)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045B110
* VC++ mangling:          ?unknown010@B_MultiplePortalSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_MultiplePortalSurface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045B28B
* VC++ mangling:          ?unknown014@B_MultiplePortalSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_MultiplePortalSurface::unknown014()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045B67E
* VC++ mangling:          ?unknown018@B_MultiplePortalSurface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_MultiplePortalSurface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045B707
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_MultiplePortalSurface@@@Z
*/
#ifdef BLD_NATIVE
B_IDataFile &operator >>(B_IDataFile &file, B_MultiplePortalSurface &surface)
{
    return file;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045BCB0
* VC++ mangling:          ?GetPolygon@B_Surface@@UAEPAVB_Polygon@@XZ
*/
#ifdef BLD_NATIVE
B_Polygon *B_Surface::GetPolygon()
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045BCC0
* VC++ mangling:          ?unknown010@B_Surface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_Surface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045BCD0
* VC++ mangling:          ?unknown014@B_Surface@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_Surface::unknown014()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0045BCE0
* VC++ mangling:          ?GetPolygon@B_DomeSurface@@UAEPAVB_Polygon@@XZ
*/
#ifdef BLD_NATIVE
B_Polygon *B_DomeSurface::GetPolygon()
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045BD00
* VC++ mangling:          ?GetPolygon@B_OpaqueSurface@@UAEPAVB_Polygon@@XZ
*/
#ifdef BLD_NATIVE
B_Polygon *B_OpaqueSurface::GetPolygon()
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045BD20
* VC++ mangling:          ?GetPolygon@B_TransparentSurface@@UAEPAVB_Polygon@@XZ
*/
#ifdef BLD_NATIVE
B_Polygon *B_TransparentSurface::GetPolygon()
{
    return NULL;
}
#endif
