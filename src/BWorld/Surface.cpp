#include <BWorld/Surface.h>

#include <BBLibc.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00453B10
* VC++ mangling:          ??0B_Surface@@QAE@XZ
*/

B_Surface::B_Surface()
 : unknown024(0)
{
    unknown028 = NULL;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00453B81
* VC++ mangling:          ??1B_Surface@@UAE@XZ
*/

B_Surface::~B_Surface()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00453B9E
* VC++ mangling:          ?GetPortals@B_Surface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_Surface::GetPortals(B_Portal **portals, int *numPortals)
{
    *portals = NULL;
    *numPortals = 0;
}


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
#ifndef BLD_NATIVE
void B_Surface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00454806
* VC++ mangling:          ?unknown01C@B_Surface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_Surface::unknown01C()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004548AF
* VC++ mangling:          ?unknown018@B_OpaqueSurface@@UAEXXZ
*/
#ifndef BLD_NATIVE
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
* Module:                 Blade.exe
* Entry point:            0x00454C0A
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Surface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Surface &surface)
{
    surface.unknown024 = 0;
    file >> static_cast<B_Plane &>(surface);
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
* Entry point:            0x00454C44
* VC++ mangling:          ?ClassId@B_DomeSurface@@UAEHXZ
*/

int B_DomeSurface::ClassId()
{
    return B_SURFACE_CID_DOME;
}


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
#ifndef BLD_NATIVE
void B_DomeSurface::unknown014()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00454ED5
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_DomeSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_DomeSurface &surface)
{
    file >> static_cast<B_Surface &>(surface) >> surface.polygon;
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
* Entry point:            0x00454F25
* VC++ mangling:          ?ClassId@B_OpaqueSurface@@UAEHXZ
*/

int B_OpaqueSurface::ClassId()
{
    return B_SURFACE_CID_OPAQUE;
}


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
#ifndef BLD_NATIVE
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

B_IDataFile &operator >>(B_IDataFile &file, B_OpaqueSurface &surface)
{
    file
        >> static_cast<B_Surface &>(surface)
        >> surface.mapTexture
        >> surface.polygon;
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
* Entry point:            0x00456760
* VC++ mangling:          ??0B_Portal@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_Portal::B_Portal()
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

B_TransparentSurface::B_TransparentSurface()
{
}


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

int B_TransparentSurface::ClassId()
{
    return B_SURFACE_CID_TRANSPARENT;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456970
* VC++ mangling:          ?GetPortals@B_TransparentSurface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_TransparentSurface::GetPortals(B_Portal **portals, int *numPortals)
{
    *portals = &portal;
    *numPortals = 1;
}


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
#ifndef BLD_NATIVE
void B_TransparentSurface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00456C3A
* VC++ mangling:          ?unknown014@B_TransparentSurface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TransparentSurface::unknown014()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00456FF1
* VC++ mangling:          ?unknown018@B_TransparentSurface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_TransparentSurface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045719A
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_TransparentSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_TransparentSurface &surface)
{
    file
        >> static_cast<B_Surface &>(surface)
        >> surface.portal
        >> surface.mapTexture;
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
* Entry point:            0x0045729D
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_PortalPlanes@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_PortalPlanes &portalPlanes)
{
    if (portalPlanes.planes)
    {
        delete [] portalPlanes.planes;
    }
    if (portalPlanes.unknown00C)
    {
        delete [] portalPlanes.unknown00C;
    }
    file >> portalPlanes.numPlanes;
    if (portalPlanes.numPlanes != 0)
    {
        portalPlanes.planes = new B_Plane[portalPlanes.numPlanes];
        portalPlanes.unknown00C = new int[portalPlanes.numPlanes];
        for (unsigned int i = 0; i < portalPlanes.numPlanes; i++)
        {
            file >> portalPlanes.planes[i];
        }
    }
    else
    {
        portalPlanes.planes = NULL;
        portalPlanes.unknown00C = NULL;
    }
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
* Entry point:            0x004574A5
* VC++ mangling:          ??0B_SinglePortalSurface@@QAE@XZ
*/
#ifndef BLD_NATIVE
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

int B_SinglePortalSurface::ClassId()
{
    return B_SURFACE_CID_SINGLE_PORTAL;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00457F0E
* VC++ mangling:          ?GetPortals@B_SinglePortalSurface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_SinglePortalSurface::GetPortals(B_Portal **portals, int *numPortals)
{
    *portals = &portal;
    *numPortals = 1;
}


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
#ifndef BLD_NATIVE
void B_SinglePortalSurface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00458217
* VC++ mangling:          ?unknown014@B_SinglePortalSurface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_SinglePortalSurface::unknown014()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00458CE9
* VC++ mangling:          ?unknown018@B_SinglePortalSurface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_SinglePortalSurface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00458F60
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_SinglePortalSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_SinglePortalSurface &surface)
{
    file
        >> static_cast<B_OpaqueSurface &>(surface)
        >> surface.portal
        >> surface.portalPlanes;
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
* Entry point:            0x0045AC13
* VC++ mangling:          ??0B_MultiplePortalSurface@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_MultiplePortalSurface::B_MultiplePortalSurface()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045AD21
* VC++ mangling:          ??1B_MultiplePortalSurface@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_MultiplePortalSurface::~B_MultiplePortalSurface()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045AE93
* VC++ mangling:          ?ClassId@B_MultiplePortalSurface@@UAEHXZ
*/

int B_MultiplePortalSurface::ClassId()
{
    return B_SURFACE_CID_MULTIPLE_PORTAL;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045AEA3
* VC++ mangling:          ?GetPortals@B_MultiplePortalSurface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_MultiplePortalSurface::GetPortals(B_Portal **portals, int *numPortals)
{
    *portals = this->portals;
    *numPortals = this->numPortals;
}


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
#ifndef BLD_NATIVE
void B_MultiplePortalSurface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045B28B
* VC++ mangling:          ?unknown014@B_MultiplePortalSurface@@UAEXXZ
*/
#ifndef BLD_NATIVE
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
#ifndef BLD_NATIVE
void B_MultiplePortalSurface::unknown018()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045B707
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_MultiplePortalSurface@@@Z
*/
#ifndef BLD_NATIVE
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
* Entry point:            0x0045BCC0
* VC++ mangling:          ?unknown010@B_Surface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_Surface::unknown010()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045BCD0
* VC++ mangling:          ?unknown014@B_Surface@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_Surface::unknown014()
{
}
#endif
