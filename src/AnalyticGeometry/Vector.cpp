#include <AnalyticGeometry/Vector.h>

#include <bld_system.h>
#include <BBLibc.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0040A375
* VC++ mangling:          ??D@YA?AVB_Vector@@NABV0@@Z
*/
#ifndef BLD_NATIVE
B_Vector operator *(double c, const B_Vector &v)
{
    return v;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040A3D1
* VC++ mangling:          ??DB_Vector@@QBE?AV0@N@Z
*/
#ifndef BLD_NATIVE
B_Vector B_Vector::operator *(double c) const
{
    return *this;
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
* Entry point:            0x0040A493
* VC++ mangling:          ??XB_Vector@@QAEAAV0@N@Z
*/
#ifndef BLD_NATIVE
B_Vector &B_Vector::operator *=(double c)
{
    return *this;
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
* Entry point:            0x0040A567
* VC++ mangling:          ??HB_Vector@@QBE?AV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_Vector B_Vector::operator +(const B_Vector &that) const
{
    return that;
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
* Entry point:            0x0040A67C
* VC++ mangling:          ??ZB_Vector@@QAEABV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
const B_Vector &B_Vector::operator -=(const B_Vector &that)
{
    return *this;
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
* Entry point:            0x0040AA41
* VC++ mangling:          ?SetAngle@B_Vector@@QAEXN@Z
*/
#ifndef BLD_NATIVE
void B_Vector::SetAngle(double angle)
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
* Entry point:            0x0040ACDD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Vector@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_Vector &vector)
{
    file.Read(&vector, sizeof(B_Vector));
    return file;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040ACF4
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@AAVB_Vector@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, B_Vector &vector)
{
    file.Write(&vector, sizeof(B_Vector));
    return file;
}