
#include <bld_system.h>
#include <bld_python.h>
#include <raster_device.h>
#include "application.h"
#include "anim.h"
#include "bld_ext_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0041316C
*/

void _impl_application_mark_level_to_load(application_t *self, char *map)
{
        if (self->map_to_load) {
                free(self->map_to_load);
                self->map_to_load = NULL;
        }
        self->map_to_load = strdup(map);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00413256
*/

void application_load_level_script(application_t *self, const char *script)
{
        int foundIndex;
        int hash_value;
        char *str_ptr;
        unsigned int i;
        array_t *array;
        world_t *world;
        person_t *player1;
        camera_t *camera;
        const char *str1;
        char *str2;
        int cmp_result;

        application_set_mode(self, &B_Name("Game"));

        application_init_python_path(self);

        CALL_THISCALL_VOID_0(self->clock1, self->clock1->methods->unknown18)

        self->unknown5C8 = NULL;

        CALL_THISCALL_VOID_0(self->clock1, self->clock1->methods->unknown1C)

        self->unknownPtrForCamera = NUM_3F266666;

        CALL_THISCALL_VOID_0(&gbl_game_state, _thiscall_00439F5D)

        self->player1 = NULL;

        if (!self->camera) {
                NEW_CAMERA(camera, 0, &B_Name("Camera"))

                self->camera = camera;
                self->camera->unknownPtrFromApplication = &self->unknownPtrForCamera;
        }

        self->camera->unknownValueFromApplication = self->unknownPtrForCamera;
        self->bUnknown01C = TRUE;

        application_run_python_file(self, script);

        CALL_THISCALL_VOID_1(&self->unknown7C, _thiscall_0040AD82, var005E24DC)

        CALL_THISCALL_VOID_1(&self->unknown7C, _thiscall_0040ADA8, var005E24F4)

        application_prepare_level(self);

        if (!gbl_net->is_net_game() || gbl_net->is_server()) {

                assert(PLAYER);

                world = &gbl_game_state.world;
                if (
                        world->foundEntity &&
                        !strcmp(world->foundEntity->Id(), PLAYER)
                ) {
                        player1 = (person_t *)world->foundEntity;
                } else {
                        str_ptr = PLAYER;
                        hash_value = 0;
                        while (*str_ptr) {
                                hash_value += *str_ptr;
                                str_ptr++;
                        }
                        hash_value = hash_value & 0xFF;

                        array = &world->hash[hash_value];

                        foundIndex = -1;
                        for(i = 0; i < array->size; i++) {

                                str1 = ((B_NamedObj *)array->elements[i])->Id();
                                str2 = PLAYER;

                                for(;;) {
                                        if (
                                                (str1[0] != str2[0]) ||
                                                (str2[0] && (str1[1] != str2[1]))
                                        ) {
                                                cmp_result = 1;
                                                break;
                                        }
                                        if (
                                                (str2[0] == '\0') ||
                                                (str2[1] == '\0')
                                        ) {
                                                cmp_result = 0;
                                                break;
                                        }
                                        str2 += 2;
                                        str1 += 2;
                                }

                                if (!cmp_result) {
                                        foundIndex = i;
                                        break;
                                }
                        }

                        if (foundIndex != -1) {
                                world->foundEntity = (entity_t *)array->elements[foundIndex];
                                player1 = (person_t *)world->foundEntity;
                        } else
                                player1 = NULL;
                }
                self->player1 = player1;

                if (!self->player1) {
                        application_exit_with_error(
                                self, "Error", "Player1 not declared in pj.py"
                        );
                }

                CALL_THISCALL_VOID_1(self->camera, _thiscall_camera_004EB1AA, self->player1)

                self->camera->unknownPtrFromApplication = &self->unknownPtrForCamera;
                self->camera->unknownValueFromApplication = self->unknownPtrForCamera;

                self->client = NULL;

        } else {
                self->player1 = NULL;

                world = &gbl_game_state.world;
                if (
                        world->foundEntity &&
                        !strcmp(world->foundEntity->Id(), PLAYER)
                ) {
                        player1 = (person_t *)world->foundEntity;
                } else {
                        str_ptr = PLAYER;
                        hash_value = 0;
                        while (*str_ptr) {
                                hash_value += *str_ptr;
                                str_ptr++;
                        }
                        hash_value = hash_value & 0xFF;

                        array = &world->hash[hash_value];

                        foundIndex = -1;
                        for(i = 0; i < array->size; i++) {

                                str1 = ((B_NamedObj *)array->elements[i])->Id();
                                str2 = PLAYER;

                                for(;;) {
                                        if (
                                                (str1[0] != str2[0]) ||
                                                (str2[0] && (str1[1] != str2[1]))
                                        ) {
                                                cmp_result = 1;
                                                break;
                                        }
                                        if (
                                                (str2[0] == '\0') ||
                                                (str2[1] == '\0')
                                        ) {
                                                cmp_result = 0;
                                                break;
                                        }
                                        str2 += 2;
                                        str1 += 2;
                                }

                                if (!cmp_result) {
                                        foundIndex = i;
                                        break;
                                }
                        }

                        if (foundIndex != -1) {
                                world->foundEntity = (entity_t*)array->elements[foundIndex];
                                player1 = (person_t *)world->foundEntity;
                        } else
                                player1 = NULL;
                }
                self->client = (entity_t *) player1;
        }

        if (self->mode == "Game") {
                CALL_THISCALL_VOID_0(self->clock1, self->clock1->methods->unknown20)
        }

        StartGSQR();
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004138B8
*/

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
                        B_3D_raster_device->update_dome();
                }
                else if (!strcmp(itemKind, "World"))
                {
                        application_load_world(self, itemName);
                }
                else if (!strcmp(itemKind, "ANM"))
                {
                        B_IDataFile * file = new B_IDataFile(itemName, O_BINARY);
                        if (file->OK())
                        {
                                anim_t *anim = new anim_t();
                                (*file) >> anim;
                                if (gbl_anims.num_alloc <= gbl_anims.size)
                                {
                                        gbl_anims.num_alloc += gbl_anims.increment;
                                        if (gbl_anims.size != 0)
                                        {
                                                void **elements = new void *[gbl_anims.num_alloc];
                                                for(unsigned int i = 0; i < gbl_anims.size; i++)
                                                {
                                                        elements[i] = gbl_anims.elements[i];
                                                }
                                                delete gbl_anims.elements;
                                                gbl_anims.elements = elements;
                                        }
                                        else
                                        {
                                                gbl_anims.elements = new void *[gbl_anims.num_alloc];
                                        }
                                }
                                gbl_anims.elements[gbl_anims.size] = anim;
                                gbl_anims.size++;
                        }
                        else
                        {
                                mout << vararg("ERROR opening animation %s\n", itemName);
                        }
                        delete file;
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
* Entry point:            0x00415759
*/

boolean application_run_python_file(application_t *self, const char *file_name)
{
        FILE *file;

        file = fopen(file_name, "rt");

        if (!file) {
                message_manager_print(
                        message_manager,
                        BBlibc_format_string(
                                "No se ha podido encontrar %s\n",
                                file_name
                        )
                );

                return FALSE;
        }

        if (PyRun_SimpleFile(file, (char *)file_name) == -1) {
                message_manager_print(
                        message_manager,
                        BBlibc_format_string(
                                "B_App::RunScriptFile() -> Error ejecutando %s\n",
                                file_name
                        )
                );
        }

        if (PyErr_Occurred()) {
                PyErr_Print();
                PyErr_Clear();
        }

        fclose(file);

        return TRUE;
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
        if (!file->OK())
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
