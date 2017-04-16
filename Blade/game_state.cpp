
#include <bld_system.h>
#include "game_state.h"


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00440A5D
*/

B_IDataFile& operator >>(B_IDataFile& file, game_state_t *gs)
{
        gs->unknown187C = 0;
        gs->unknown1880 = 0;
        array_t *atms = &gs->atmospheres;
        if (atms->num_alloc != 0)
        {
                for (unsigned int i = 0; i < atms->size; i++)
                {
                        atmosphere_t * atm = (atmosphere_t *)atms->elements[i];
                        delete atm;
                }
                delete(atms->elements);
                atms->elements = NULL;
                atms->size = 0;
                atms->num_alloc = 0;
        }
        file >> atms->size;
        atms->num_alloc = ((atms->increment + atms->size - 1) / atms->increment) * atms->increment;
        if (atms->num_alloc != 0)
        {
                atms->elements = (void **)new atmosphere_t * [atms->num_alloc];
                for(unsigned int i = 0; i < atms->size; i++)
                {
                        atms->elements[i] = new atmosphere_t();
                        file >> (atmosphere_t *)atms->elements[i];
                }
        }

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
        assert("read world" == NULL);

        return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
