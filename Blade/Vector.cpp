#include <bld_system.h>
#include "Vector.h"
#include <BBLibc.h>

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