
#include <bld_system.h>
#include <raster_device.h>
#include "application.h"
#include "bld_ext_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x004138B8
*/
// TODO finish implementation
void _impl_application_read_level(application_t * self, const char * file_name)
{
        double timeBefore, timeAfter;
        char itemKind[256], itemName[256];

        mout << vararg("Abriendo archivo csv.dat\n");
        timeBefore = timeGetTime();
        ReadCSV("..\\csv.dat", &B_csvs);
        timeAfter = timeGetTime();
        mout << vararg(
                "csv.dat loaded (%f seconds).\n",
                (timeAfter - timeBefore)/1000.0);

        timeBefore = timeAfter;
        mout << vararg("Abriendo archivo %s", file_name);

        FILE *file = fopen(file_name, "r");
        if (file == NULL)
        {
                mout << "No se puede abrir archivo\n";
                return;
        }

        int status = fscanf(file, "%s -> %s", itemKind, itemName);
        while ((status != 0) && (status != EOF))
        {
                if (!strcmp(itemKind, "Bitmaps"))
                {
                        B_resource_manager.LocateResourceIn(B_Name(itemName), NULL, 2);
                }
                else if (!strcmp(itemKind, "ChromaBitmaps"))
                {
                        self->exit_with_error("Blade", "ChromaBitmaps no longer supported.");
                }
                else if (!strcmp(itemKind, "WorldDome"))
                {
                        B_resource_manager.LocateResourceIn(B_Name(itemName), NULL, 2);
                        B_3D_raster_device->unknown050();
                }
                else if (!strcmp(itemKind, "World"))
                {
                        application_load_world(self, itemName);
                }
                else if (!strcmp(itemKind, "ANM"))
                {
/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
                }
                else if (!strcmp(itemKind, "Objs"))
                {
                        self->exit_with_error("Blade", "Objs no longer supported.");
                }
                else if (!strcmp(itemKind, "LoadGammaC"))
                {
                        self->exit_with_error("Blade", "LoadGammaC no longer supported.");
                }
                status = fscanf(file, "%s -> %s", itemKind, itemName);
                self->process_message();
        }
        fclose(file);
        timeAfter = timeGetTime();
        mout << vararg(
                ".lvl %s loaded (%f seconds).\n",
                file_name,
                (timeAfter - timeBefore)/1000.0);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00416C6F
*/

int application_load_world(application_t *self, const char *file_name)
{
        double timeBefore, timeAfter;

        mout << vararg("About to load World %s.\n", file_name);
        timeBefore = timeGetTime();

        B_IDataFile * file = new B_IDataFile(file_name, O_BINARY);
        if (file->fd == -1)
        {
                mout << "B_App::LoadWorld() -> Error trying to load map.\n";
                return 0;
        }
        *file >> &gbl_game_state;
        delete file;

        timeAfter = timeGetTime();

        mout << vararg(
                "World %s loaded (%f seconds).\n",
                file_name,
                (timeAfter - timeBefore)/1000.0
        );

        gbl_game_state.world_file_name = B_Name(file_name);

        if (gbl_sound_device)
        {
                mout << "About to set world size for sound device\n";

                timeBefore = timeGetTime();

                gbl_sound_device->set_world_size(
                        gbl_game_state.unknown18FC.x, gbl_game_state.unknown18FC.y,
                        gbl_game_state.unknown18FC.z, gbl_game_state.unknown1914,
                        5000.0);

                timeAfter = timeGetTime();
                mout << vararg(
                        "set world size done (%f seconds).\n",
                        (timeAfter - timeBefore)/1000.0
                );
        }

        mout << "OK!\n";

        return 1;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
