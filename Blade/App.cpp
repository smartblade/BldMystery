
#include <bld_system.h>
#include <bld_python.h>
#include <raster_device.h>
#include "App.h"
#include "anim.h"
#include "bld_misc_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00411CC4
* VC++ mangling:          ?set_listener_mode@B_App@@QAEHHABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

int B_App::set_listener_mode(int mode, const B_Vector &v)
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00411EB9
* VC++ mangling:          ?set_mode@B_App@@QAEXABVB_Name@@@Z
*/

#ifdef BLD_NATIVE

void B_App::set_mode(const B_Name &mode)
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
* Entry point:            0x0041208A
* VC++ mangling:          ?set_time@B_App@@QAEHN@Z
*/

#ifdef BLD_NATIVE

int B_App::set_time(double time)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004120D3
* VC++ mangling:          ?go_to_time@B_App@@QAEHN@Z
*/

#ifdef BLD_NATIVE

int B_App::go_to_time(double time)
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
* Entry point:            0x00412138
* VC++ mangling:          ?stop_time@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::stop_time()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00412154
* VC++ mangling:          ?RestartTime@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::RestartTime()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00412170
* VC++ mangling:          ?GetTimeSpeed@B_App@@QAENXZ
*/

#ifdef BLD_NATIVE

double B_App::GetTimeSpeed()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0041218C
* VC++ mangling:          ?SetTimeSpeed@B_App@@QAEXN@Z
*/

#ifdef BLD_NATIVE

void B_App::SetTimeSpeed(double speed)
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
* Entry point:            0x004121CE
* VC++ mangling:          ?process_events@B_App@@UAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::process_events()
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
* Entry point:            0x0041316C
* VC++ mangling:          ?mark_level_to_load@B_App@@UAEXPBD@Z
*/

void B_App::mark_level_to_load(const char *map)
{
        if (this->map_to_load) {
                free(this->map_to_load);
                this->map_to_load = NULL;
        }
        this->map_to_load = strdup(map);
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
* VC++ mangling:          ?load_level@B_App@@UAEXPBD@Z
*/

void B_App::load_level(const char *script)
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

        this->set_mode("Game");

        this->init_python_path();

        this->clock1->unknown018();

        this->time = 0.0;

        this->clock1->unknown01C();

        this->unknownPtrForCamera = NUM_3F266666;

        gbl_game_state.unknown_00439F5D();

        this->player1 = NULL;

        if (!this->camera) {
                camera = new camera_t(0, "Camera");

                this->camera = camera;
                this->camera->unknownPtrFromApplication = &this->unknownPtrForCamera;
        }

        this->camera->unknownValueFromApplication = this->unknownPtrForCamera;
        this->bUnknown01C = TRUE;

        this->run_python_file(script);

        this->location.setPosition(gbl_game_state.initial_point_position);
        this->location.setOrientation(gbl_game_state.initial_point_orientation);

        this->prepare_level();

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
                this->player1 = player1;

                if (!this->player1) {
                        this->exit_with_error(
                            "Error",
                            "Player1 not declared in pj.py"
                        );
                }

                this->camera->unknown_004EB1AA(this->player1);

                this->camera->unknownPtrFromApplication = &this->unknownPtrForCamera;
                this->camera->unknownValueFromApplication = this->unknownPtrForCamera;

                this->client = NULL;

        } else {
                this->player1 = NULL;

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
                this->client = (entity_t *) player1;
        }

        if (this->mode == "Game") {
                this->clock1->unknown020();
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
* VC++ mangling:          ?read_level@B_App@@UAEXPBD@Z
*/

void B_App::read_level(const char * file_name)
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
                        this->exit_with_error("Blade", "ChromaBitmaps no longer supported.");
                }
                else if (!strcmp(itemKind, "WorldDome"))
                {
                        B_resource_manager.LocateResourceIn(B_Name(itemName), NULL, 2);
                        B_3D_raster_device->update_dome();
                }
                else if (!strcmp(itemKind, "World"))
                {
                        this->load_world(itemName);
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
                        this->exit_with_error("Blade", "Objs no longer supported.");
                }
                else if (!strcmp(itemKind, "LoadGammaC"))
                {
                        this->exit_with_error("Blade", "LoadGammaC no longer supported.");
                }
                status = fscanf(file, "%s -> %s", itemKind, itemName);
                this->process_message();
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
* Entry point:            0x00414F7F
* VC++ mangling:          ?prepare_level@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::prepare_level()
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
* Entry point:            0x0041529D
* VC++ mangling:          ?AddInputAction@B_App@@QAEXPBDH@Z
*/

#ifdef BLD_NATIVE

void B_App::AddInputAction(const char *action_name, int npi)
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
* Entry point:            0x0041549C
* VC++ mangling:          ?bind_pred@B_App@@QAE_NPBD0@Z
*/

#ifdef BLD_NATIVE

bool B_App::bind_pred(const char *key, const char *pred)
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
* Entry point:            0x00415759
* VC++ mangling:          ?run_python_file@B_App@@QAE_NPBD@Z
*/

bool B_App::run_python_file(const char *file_name)
{
        FILE *file;

        file = fopen(file_name, "rt");

        if (!file) {
                mout << vararg("No se ha podido encontrar %s\n", file_name);
                return FALSE;
        }

        if (PyRun_SimpleFile(file, (char *)file_name) == -1) {
                mout << vararg(
                        "B_App::RunScriptFile() -> Error ejecutando %s\n",
                        file_name);
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
* VC++ mangling:          ?load_world@B_App@@QAEHPBD@Z
*/

int B_App::load_world(const char *file_name)
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
