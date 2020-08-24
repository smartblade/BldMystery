#include <bld_system.h>
#include <BWorld/atmosphere.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0042D090
* VC++ mangling:          ??0atmosphere_t@@QAE@XZ
*/

atmosphere_t::atmosphere_t()
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
* Entry point:            0x0042D175
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@PAVatmosphere_t@@@Z
*/


B_IDataFile &operator >>(B_IDataFile &file, atmosphere_t *atm)
{
        file >> *atm >> atm->color >> atm->intensity;
        return file;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042D1B0
* VC++ mangling:          ??1atmosphere_t@@UAE@XZ
*/

atmosphere_t::~atmosphere_t()
{
}
