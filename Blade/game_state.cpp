
#include <bld_system.h>
#include "game_state.h"
#include "light.h"
#include "bld_ext_funcs.h"


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
        unsigned int num_lights;

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
        ......
        Raster
        ......
        */

        _cdecl_read_points(&file, &world_points);
        _cdecl_read_sectors(&file, &gs->sectors);

        array_t *lights = &gs->lights;
        if (lights->num_alloc != 0)
        {
                for (unsigned int i = 0; i < lights->size; i++)
                {
                        light_t * light = (light_t *)lights->elements[i];
                        delete light;
                }
                delete(lights->elements);
                lights->elements = NULL;
                lights->size = 0;
                lights->num_alloc = 0;
        }

        file >> num_lights;

        for(unsigned int i = 0; i < num_lights; i++)
        {
                light_t *light = (light_t *)_cdecl_read_light(&file);
                array_t *lights = &gs->lights;
                if (lights->num_alloc <= lights->size)
                {
                        lights->num_alloc += lights->increment;
                        if (lights->size != 0)
                        {
                                void **elements = new void *[lights->num_alloc];
                                for(unsigned int j = 0; j < lights->size; j++)
                                {
                                        elements[j] = lights->elements[j]; 
                                }
                                delete lights->elements;
                                lights->elements = elements;
                        }
                        else
                        {
                                lights->elements = new void *[lights->num_alloc];
                        }
                }
                lights->elements[i] = light;
                lights->size++;
        }

        for(unsigned int i = 0; i < num_lights; i++)
        {
                light_t *light = (light_t *)gs->lights.elements[i];
                light->unknown008();
        }

        file >> &gs->initial_point_position >> &gs->initial_point_orientation;

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
