#include <Math/BSpline.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00495240
* VC++ mangling:          ?AddNode@B_Spline@@QAEHNABVB_Vector@@@Z
*/
#ifndef BLD_NATIVE
int B_Spline::AddNode(double time, const B_Vector &position)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004954DC
* VC++ mangling:          ?Close@B_Spline@@QAEHXZ
*/
#ifndef BLD_NATIVE
int B_Spline::Close()
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
* Entry point:            0x00496830
* VC++ mangling:          ?Clear@B_Spline@@QAEHXZ
*/
#ifndef BLD_NATIVE
int B_Spline::Clear()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004968CD
* VC++ mangling:          ?GetPosition@B_Spline@@QAEHNPAVB_Vector@@@Z
*/
#ifndef BLD_NATIVE
int B_Spline::GetPosition(double time, B_Vector *position)
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
* Entry point:            0x00496E74
* VC++ mangling:          ?SetStartTangent@B_Spline@@QAEHHABVB_Vector@@@Z
*/
#ifndef BLD_NATIVE
int B_Spline::SetStartTangent(int nodeIndex, const B_Vector &startTangent)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00496EBC
* VC++ mangling:          ?SetEndTangent@B_Spline@@QAEHHABVB_Vector@@@Z
*/
#ifndef BLD_NATIVE
int B_Spline::SetEndTangent(int nodeIndex, const B_Vector &endTangent)
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
