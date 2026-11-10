#include <AnalyticGeometry/Vector.h>

#include <bld_system.h>
#include <BBLibc/IDataFile.h>
#include <BBLibc/ODataFile.h>
#include <math.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007CE5
* Module:                 Blade.exe
* Entry point:            0x0040A375
* VC++ mangling:          ??D@YA?AVB_Vector@@NABV0@@Z
*/

B_Vector operator *(double c, const B_Vector &v)
{
    return B_Vector(c * v.x, c * v.y, c * v.z);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007D41
* Module:                 Blade.exe
* Entry point:            0x0040A3D1
* VC++ mangling:          ??DB_Vector@@QBE?AV0@N@Z
*/

B_Vector B_Vector::operator *(double c) const
{
    return B_Vector(c * this->x, c * this->y, c * this->z);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007DA2
* Module:                 Blade.exe
* Entry point:            0x0040A432
* VC++ mangling:          ??KB_Vector@@QBE?AV0@N@Z
*/

B_Vector B_Vector::operator /(double c) const
{
    return B_Vector(this->x / c, this->y / c, this->z / c);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007E03
* Module:                 Blade.exe
* Entry point:            0x0040A493
* VC++ mangling:          ??XB_Vector@@QAEAAV0@N@Z
*/

B_Vector &B_Vector::operator *=(double c)
{
    this->x = c * this->x;
    this->y = c * this->y;
    this->z = c * this->z;
    return *this;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007E3E
* Module:                 Blade.exe
* Entry point:            0x0040A4CE
* VC++ mangling:          ??_0B_Vector@@QAEAAV0@N@Z
*/

B_Vector &B_Vector::operator /=(double c)
{
    this->x /= c;
    this->y /= c;
    this->z /= c;
    return *this;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007E79
* Module:                 Blade.exe
* Entry point:            0x0040A509
* VC++ mangling:          ??GB_Vector@@QBE?AV0@XZ
*/

B_Vector B_Vector::operator -() const
{
    return B_Vector(-this->x, -this->y, -this->z);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007ED7
* Module:                 Blade.exe
* Entry point:            0x0040A567
* VC++ mangling:          ??HB_Vector@@QBE?AV0@ABV0@@Z
*/

B_Vector B_Vector::operator +(const B_Vector &that) const
{
    return B_Vector(this->x + that.x, this->y + that.y, this->z + that.z);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007F40
* Module:                 Blade.exe
* Entry point:            0x0040A5D0
* VC++ mangling:          ??GB_Vector@@QBE?AV0@ABV0@@Z
*/

B_Vector B_Vector::operator -(const B_Vector &that) const
{
    return B_Vector(this->x - that.x, this->y - that.y, this->z - that.z);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007FA9
* Module:                 Blade.exe
* Entry point:            0x0040A639
* VC++ mangling:          ??YB_Vector@@QAEABV0@ABV0@@Z
*/

const B_Vector &B_Vector::operator +=(const B_Vector &that)
{
    this->x += that.x;
    this->y += that.y;
    this->z += that.z;
    return *this;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10007FEC
* Module:                 Blade.exe
* Entry point:            0x0040A67C
* VC++ mangling:          ??ZB_Vector@@QAEABV0@ABV0@@Z
*/

const B_Vector &B_Vector::operator -=(const B_Vector &that)
{
    this->x -= that.x;
    this->y -= that.y;
    this->z -= that.z;
    return *this;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000802F
* Module:                 Blade.exe
* Entry point:            0x0040A6BF
* VC++ mangling:          ??DB_Vector@@QBENABV0@@Z
*/

double B_Vector::operator *(const B_Vector &that) const
{
    return this->x * that.x + this->y * that.y + this->z * that.z;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10008062
* Module:                 Blade.exe
* Entry point:            0x0040A6F2
* VC++ mangling:          ??TB_Vector@@QBE?AV0@ABV0@@Z
*/

B_Vector B_Vector::operator ^(const B_Vector &that) const
{
    return B_Vector(
        this->y * that.z - this->z * that.y,
        this->z * that.x - this->x * that.z,
        this->x * that.y - this->y * that.x
    );
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100083B1
* Module:                 Blade.exe
* Entry point:            0x0040AA41
* VC++ mangling:          ?SetAngle@B_Vector@@QAEXN@Z
*/

void B_Vector::SetAngle(double angle)
{
    this->x = -sin(angle);
    this->y = 0.0;
    this->z = cos(angle);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000864D
* Module:                 Blade.exe
* Entry point:            0x0040ACDD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Vector@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Vector &vector)
{
    file.Read(&vector, sizeof(B_Vector));
    return file;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10008664
* Module:                 Blade.exe
* Entry point:            0x0040ACF4
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@AAVB_Vector@@@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, B_Vector &vector)
{
    file.Write(&vector, sizeof(B_Vector));
    return file;
}
