
#include <bld_system.h>
#include <raster_device.h>
#include "game_state.h"
#include "light.h"
#include "sector.h"
#include "bld_misc_funcs.h"


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00439F5D
* VC++ mangling:          ?unknown_00439F5D@game_state_t@@QAEXXZ
*/

#ifdef BLD_NATIVE

void game_state_t::unknown_00439F5D()
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
* Entry point:            0x0043A6A4
* VC++ mangling:          ?get_time@game_state_t@@QAENXZ
*/

#ifdef BLD_NATIVE

double game_state_t::get_time()
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
* Entry point:            0x0043C8B2
* VC++ mangling:          ?SetSun@game_state_t@@QAEXHABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

int game_state_t::SetSun(int exists, const B_Vector &position)
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
* Entry point:            0x0043DBBE
* VC++ mangling:          ?FindSectorIndex@game_state_t@@QAEHABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

int game_state_t::FindSectorIndex(const B_Vector &point)
{
    return -1;
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
* Entry point:            0x000043F98A
* VC++ mangling:          ?LoadEntitiesData@game_state_t@@QAEHPBD@Z
*/

#ifdef BLD_NATIVE

int game_state_t::LoadEntitiesData(const char *filename)
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0043FD82
* VC++ mangling:          ?SaveEntitiesData@game_state_t@@QAEHPBD@Z
*/

#ifdef BLD_NATIVE

int game_state_t::SaveEntitiesData(const char *filename)
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
* Entry point:            0x00440A5D
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@PAVgame_state_t@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, game_state_t *gs)
{
        unsigned int num_lights;

        gs->unknown187C = 0;
        gs->unknown1880 = 0;
        array_t<atmosphere_t *> *atms = &gs->atmospheres;
        if (atms->num_alloc != 0)
        {
                for (unsigned int i = 0; i < atms->size; i++)
                {
                        atmosphere_t * atm = atms->elements[i];
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
                atms->elements = new atmosphere_t * [atms->num_alloc];
                for(unsigned int i = 0; i < atms->size; i++)
                {
                        atms->elements[i] = new atmosphere_t();
                        file >> atms->elements[i];
                }
        }

        if (B_3D_raster_device)
                B_3D_raster_device->unknown084();

        for(unsigned int i = 0; i < atms->size; i++)
        {
                atmosphere_t * atm = (atmosphere_t *)atms->elements[i];
                B_3D_raster_device->add_atmosphere(atm->Id(), atm->color, atm->intensity);
        }

        read_points(&file, &gbl_world_points);
        read_sectors(&file, &gs->sectors);

        array_t<light_t *> *lights = &gs->lights;
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
                light_t *light = read_light(&file);
                array_t<light_t *> *lights = &gs->lights;
                if (lights->num_alloc <= lights->size)
                {
                        lights->num_alloc += lights->increment;
                        if (lights->size != 0)
                        {
                                light_t **elements = new light_t *[lights->num_alloc];
                                for(unsigned int j = 0; j < lights->size; j++)
                                {
                                        elements[j] = lights->elements[j]; 
                                }
                                delete lights->elements;
                                lights->elements = elements;
                        }
                        else
                        {
                                lights->elements = new light_t *[lights->num_alloc];
                        }
                }
                lights->elements[i] = light;
                lights->size++;
        }

        for(unsigned int i = 0; i < num_lights; i++)
        {
                light_t *light = gs->lights.elements[i];
                light->unknown008();
        }

        file >> gs->initial_point_position >> gs->initial_point_orientation;

        for(unsigned int i = 0; i < gs->sectors.size; i++)
        {
                B_Sector *sector = gs->sectors.elements[i];
                file >> sector->groupId;
        }

        gs->unknown18F8.unknown_00451A21(&gs->sectors, 0, 0x40B38800/*30000.0lf*/);

        return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
