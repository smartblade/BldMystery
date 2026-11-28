#include <AnalyticGeometry/Plane.h>

#include <AnalyticGeometry/Vector.h>
#include <BBLibc/IDataFile.h>
#include <BBLibc/ODataFile.h>
#include <math.h>


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031100
* Module:                 rOpenGL.dll
* Entry point:            0x10006F80
* Module:                 Blade.exe
* Entry point:            0x00407B50
* VC++ mangling:          ??0B_Plane@@QAE@NABVB_Vector@@@Z
*/

B_Plane::B_Plane(double p, const B_Vector &normal)
:
    normal(normal),
    p(p)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003113C
* Module:                 rOpenGL.dll
* Entry point:            0x10006FBC
* Module:                 Blade.exe
* Entry point:            0x00407B8C
* VC++ mangling:          ??0B_Plane@@QAE@ABVB_Vector@@0@Z
*/

B_Plane::B_Plane(const B_Vector &point, const B_Vector &normal)
:
    normal(normal / normal.Length())
{
    this->p = -(point * this->normal);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031189
* Module:                 rOpenGL.dll
* Entry point:            0x10007009
* Module:                 Blade.exe
* Entry point:            0x00407BD9
* VC++ mangling:          ??0B_Plane@@QAE@ABVB_Vector@@00@Z
*/

B_Plane::B_Plane(const B_Vector &point, const B_Vector &u, const B_Vector &v)
:
    normal(u ^ v)
{
    this->normal = this->normal / this->normal.Length();
    this->p = -(point * this->normal);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031201
* Module:                 rOpenGL.dll
* Entry point:            0x10007081
* Module:                 Blade.exe
* Entry point:            0x00407C51
* VC++ mangling:          ?Set@B_Plane@@QAEXNABVB_Vector@@@Z
*/

void B_Plane::Set(double p, const B_Vector &normal)
{
    this->normal = normal;
    this->p = p;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031231
* Module:                 rOpenGL.dll
* Entry point:            0x100070B1
* Module:                 Blade.exe
* Entry point:            0x00407C81
* VC++ mangling:          ?Set@B_Plane@@QAEXABVB_Vector@@0@Z
*/

void B_Plane::Set(const B_Vector &point, const B_Vector &normal)
{
    this->normal = normal / normal.Length();
    this->p = -(point * this->normal);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031284
* Module:                 rOpenGL.dll
* Entry point:            0x10007104
* Module:                 Blade.exe
* Entry point:            0x00407CD4
* VC++ mangling:          ?Set@B_Plane@@QAEXABVB_Vector@@00@Z
*/

void B_Plane::Set(const B_Vector &point, const B_Vector &u, const B_Vector &v)
{
    this->normal = u ^ v;
    this->normal = this->normal / this->normal.Length();
    this->p = -(point * this->normal);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100312FC
* Module:                 rOpenGL.dll
* Entry point:            0x1000717C
* Module:                 Blade.exe
* Entry point:            0x00407D4C
* VC++ mangling:          ??8B_Plane@@QBEHABV0@@Z
*/

int B_Plane::operator ==(const B_Plane &that) const
{
    return that.normal * this->normal > 0.999999 &&
        fabs(that.p - this->p) < 0.5;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031358
* Module:                 rOpenGL.dll
* Entry point:            0x100071D8
* Module:                 Blade.exe
* Entry point:            0x00407DA8
* VC++ mangling:          ?Translate@B_Plane@@QAEXABVB_Vector@@@Z
*/

void B_Plane::Translate(const B_Vector &offset)
{
    this->p -= this->normal * offset;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10031382
* Module:                 rOpenGL.dll
* Entry point:            0x10007202
* Module:                 Blade.exe
* Entry point:            0x00407DD2
* VC++ mangling:          ?PassThrough@B_Plane@@QAEXABVB_Vector@@@Z
*/

void B_Plane::PassThrough(const B_Vector &point)
{
    this->p = -(this->normal * point);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100313A6
* Module:                 rOpenGL.dll
* Entry point:            0x10007226
* Module:                 Blade.exe
* Entry point:            0x00407DF6
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Plane@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Plane &plane)
{
    file >> plane.normal >> plane.p;
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100313D1
* Module:                 rOpenGL.dll
* Entry point:            0x10007252
* Module:                 Blade.exe
* Entry point:            0x00407E22
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@AAVB_Plane@@@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, B_Plane &plane)
{
    file << plane.normal << plane.p;
    return file;
}
