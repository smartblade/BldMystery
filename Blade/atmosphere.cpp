#include <bld_system.h>
#include "atmosphere.h"


/*
* Module:                 Blade.exe
* Entry point:            0x0042D090
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
*/


B_IDataFile &operator >>(B_IDataFile &file, atmosphere_t *atm)
{
        file >> *atm >> atm->color >> atm->intensity;
        return file;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042D1B0
*/

atmosphere_t::~atmosphere_t()
{
}
