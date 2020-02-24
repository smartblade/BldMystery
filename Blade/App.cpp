
#include <bld_system.h>
#include <bld_python.h>
#include <raster_device.h>
#include "App.h"
#include "anim.h"
#include "CameraEntity.h"
#include "sound_device.h"
#include "bld_misc_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004113CE
* VC++ mangling:          ??0B_App@@QAE@PAD@Z
*/
#ifdef BLD_NATIVE
B_App::B_App(char *cmdLine)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00411843
* VC++ mangling:          ??1B_App@@UAE@XZ
*/

B_App::~B_App()
{
    ClearLevel(true);
    Py_XDECREF(this->CDCallback);
    delete gbl_sound_device;
    gbl_sound_device = NULL;
    delete this->clock1;
    delete this->clock2;
    this->clock1 = NULL;
    delete this->unknownPtr070;
    delete this->unknownPtr074;
    Py_Finalize();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411C2E
* VC++ mangling:          ?Start@B_App@@UAE_NXZ
*/

bool B_App::Start()
{
    this->ReadArguments(this->commandLine);
    unknown_00497AE0();
    return true;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411C54
* VC++ mangling:          ?InitPythonPath@B_App@@UAE_NXZ
*/
#ifdef BLD_NATIVE
bool B_App::InitPythonPath()
{
    return false;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00411CC4
* VC++ mangling:          ?SetListenerMode@B_App@@QAEHHABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

int B_App::SetListenerMode(int mode, const B_Vector &v)
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
* Entry point:            0x00411D95
* VC++ mangling:          ?DeactivateInput@B_App@@QAEHXZ
*/

#ifdef BLD_NATIVE

int B_App::DeactivateInput()
{
    return 0;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00411E25
* VC++ mangling:          ?ActivateInput@B_App@@QAEHXZ
*/

#ifdef BLD_NATIVE

int B_App::ActivateInput()
{
    return 0;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00411EB9
* VC++ mangling:          ?SetAppMode@B_App@@QAEHABVB_Name@@@Z
*/

int B_App::SetAppMode(const B_Name &mode)
{
    if (this->mode == mode)
        return true;
    if (mode == "Demo")
    {
        this->mode = mode;
        this->b05D4 = true;
        this->b05D1 = true;
        this->RestartTime();
        B_3D_raster_device->set_raster_parameter("CacheStretchImages", "0");
        return true;
    }
    if (mode == "Game")
    {
        this->mode = mode;
        this->b05D4 = true;
        this->b05D1 = true;
        this->RestartTime();
        B_3D_raster_device->set_raster_parameter("CacheStretchImages", "0");
        return true;
    }
    if (mode == "Menu")
    {
        this->mode = mode;
        this->b05D4 = false;
        this->b05D1 = false;
        this->StopTime();
        B_3D_raster_device->set_raster_parameter("CacheStretchImages", "1");
        return true;
    }
    mout << vararg(
        "B_App::SetAppMode() -> Unknown mode: %s.\n",
        mode.String());
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412053
* VC++ mangling:          ?GetCmdLine@B_App@@QAEPBDXZ
*/

const char *B_App::GetCmdLine()
{
    return this->commandLine;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412067
* VC++ mangling:          ?GetAppMode@B_App@@QAEABVB_Name@@XZ
*/

const B_Name &B_App::GetAppMode()
{
    return this->mode;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041207A
* VC++ mangling:          ?Quit@B_App@@UAEHXZ
*/

int B_App::Quit()
{
    return true;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041208A
* VC++ mangling:          ?SetTime@B_App@@QAEHN@Z
*/

int B_App::SetTime(double time)
{
    B_world.SetTime(time);
    this->clock1->SetTime(time);
    this->time = time;
    return true;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004120D3
* VC++ mangling:          ?GoToTime@B_App@@QAEHN@Z
*/

int B_App::GoToTime(double time)
{
    B_world.GoToTime(time);
    this->clock1->SetTime(time);
    this->time = time;
    return true;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041211C
* VC++ mangling:          ?GetTime@B_App@@QAENXZ
*/

double B_App::GetTime()
{
    return this->clock1->GetTime();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412138
* VC++ mangling:          ?StopTime@B_App@@QAEXXZ
*/

void B_App::StopTime()
{
    this->clock1->StopTime();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412154
* VC++ mangling:          ?RestartTime@B_App@@QAEXXZ
*/

void B_App::RestartTime()
{
    this->clock1->RestartTime();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412170
* VC++ mangling:          ?GetTimeSpeed@B_App@@QAENXZ
*/

double B_App::GetTimeSpeed()
{
    return this->clock1->GetTimeSpeed();
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041218C
* VC++ mangling:          ?SetTimeSpeed@B_App@@QAEXN@Z
*/

void B_App::SetTimeSpeed(double speed)
{
    this->clock1->SetTimeSpeed(speed);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004121CE
* VC++ mangling:          ?ProcessEvents@B_App@@UAE_NXZ
*/
#ifdef BLD_NATIVE
bool B_App::ProcessEvents()
{
    return false;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00413121
* VC++ mangling:          ?End@B_App@@UAEXXZ
*/

void B_App::End()
{
    mout << "B_App::End()...\n";
    mout.DisconnectChannel("Salida");
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041316C
* VC++ mangling:          ?MarkLevelToLoad@B_App@@UAEXPBD@Z
*/

void B_App::MarkLevelToLoad(const char *map)
{
        if (this->map_to_load) {
                free(this->map_to_load);
                this->map_to_load = NULL;
        }
        this->map_to_load = strdup(map);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004131BB
* VC++ mangling:          ?CloseLevel@B_App@@UAEXPBD0@Z
*/
#ifdef BLD_NATIVE
void B_App::CloseLevel(const char *statement, const char *auxText)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00413256
* VC++ mangling:          ?LoadLevel@B_App@@UAEXPBD@Z
*/

void B_App::LoadLevel(const char *script)
{
        int foundIndex;
        int hash_value;
        char *str_ptr;
        unsigned int i;
        B_PtrArray<B_Entity> *array;
        B_Entities *entities;
        B_PersonEntity *player1;
        B_CameraEntity *camera;
        const char *str1;
        char *str2;
        int cmp_result;

        this->SetAppMode("Game");

        this->InitPythonPath();

        this->clock1->Reset();

        this->time = 0.0;

        this->clock1->StopTime();

        this->unknownPtrForCamera = NUM_3F266666;

        B_world.unknown_00439F5D();

        this->player1 = NULL;

        if (!this->camera) {
                camera = new B_CameraEntity(0, "Camera");

                this->camera = camera;
                this->camera->unknownPtrFromApplication = &this->unknownPtrForCamera;
        }

        this->camera->unknownValueFromApplication = this->unknownPtrForCamera;
        this->bUnknown01C = TRUE;

        this->RunPythonFile(script);

        this->location.setPosition(B_world.initial_point_position);
        this->location.setOrientation(B_world.initial_point_orientation);

        this->PrepareLevel();

        if (!gbl_net->is_net_game() || gbl_net->is_server()) {

                assert(PLAYER);

                entities = &B_world.entities;
                if (
                        entities->foundEntity &&
                        !strcmp(entities->foundEntity->Id(), PLAYER)
                ) {
                        player1 = (B_PersonEntity *)entities->foundEntity;
                } else {
                        str_ptr = PLAYER;
                        hash_value = 0;
                        while (*str_ptr) {
                                hash_value += *str_ptr;
                                str_ptr++;
                        }
                        hash_value = hash_value & 0xFF;

                        array = &entities->hash[hash_value];

                        foundIndex = -1;
                        for(i = 0; i < array->size; i++) {

                                str1 = array->elements[i]->Id();
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
                                entities->foundEntity = array->elements[foundIndex];
                                player1 = (B_PersonEntity *)entities->foundEntity;
                        } else
                                player1 = NULL;
                }
                this->player1 = player1;

                if (!this->player1) {
                        this->ExitWithError(
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

                entities = &B_world.entities;
                if (
                        entities->foundEntity &&
                        !strcmp(entities->foundEntity->Id(), PLAYER)
                ) {
                        player1 = (B_PersonEntity *)entities->foundEntity;
                } else {
                        str_ptr = PLAYER;
                        hash_value = 0;
                        while (*str_ptr) {
                                hash_value += *str_ptr;
                                str_ptr++;
                        }
                        hash_value = hash_value & 0xFF;

                        array = &entities->hash[hash_value];

                        foundIndex = -1;
                        for(i = 0; i < array->size; i++) {

                                str1 = array->elements[i]->Id();
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
                                entities->foundEntity = array->elements[foundIndex];
                                player1 = (B_PersonEntity *)entities->foundEntity;
                        } else
                                player1 = NULL;
                }
                this->client = player1;
        }

        if (this->mode == "Game") {
                this->clock1->RestartTime();
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
* Entry point:            0x004138A0
* VC++ mangling:          ?TakeSnapShot@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE
void B_App::TakeSnapShot()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004138B8
* VC++ mangling:          ?ReadLevel@B_App@@UAEXPBD@Z
*/

void B_App::ReadLevel(const char * file_name)
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
                        this->ExitWithError("Blade", "ChromaBitmaps no longer supported.");
                }
                else if (!strcmp(itemKind, "WorldDome"))
                {
                        B_resource_manager.LocateResourceIn(B_Name(itemName), NULL, 2);
                        B_3D_raster_device->update_dome();
                }
                else if (!strcmp(itemKind, "World"))
                {
                        this->LoadWorld(itemName);
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
                                                anim_t **elements = new anim_t *[gbl_anims.num_alloc];
                                                for(unsigned int i = 0; i < gbl_anims.size; i++)
                                                {
                                                        elements[i] = gbl_anims.elements[i];
                                                }
                                                delete gbl_anims.elements;
                                                gbl_anims.elements = elements;
                                        }
                                        else
                                        {
                                                gbl_anims.elements = new anim_t *[gbl_anims.num_alloc];
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
                        this->ExitWithError("Blade", "Objs no longer supported.");
                }
                else if (!strcmp(itemKind, "LoadGammaC"))
                {
                        this->ExitWithError("Blade", "LoadGammaC no longer supported.");
                }
                status = fscanf(file, "%s -> %s", itemKind, itemName);
                this->ProcessMessage();
        }
        fclose(file);
        timeAfter = timeGetTime();
        mout << vararg(
                ".lvl %s loaded (%f seconds).\n",
                file_name,
                (timeAfter - timeBefore)/1000.0);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00413EE1
* VC++ mangling:          ?unknown_method040@B_App@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_App::unknown_method040()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00413FB6
* VC++ mangling:          ?ReassignCombustionData@B_App@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_App::ReassignCombustionData()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041412A
* VC++ mangling:          ?ClearLevel@B_App@@UAEXH@Z
*/
#ifdef BLD_NATIVE
void B_App::ClearLevel(int flag)
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
* Entry point:            0x00414F7F
* VC++ mangling:          ?PrepareLevel@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::PrepareLevel()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004150B4
* VC++ mangling:          ?DoneLoadGame@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::DoneLoadGame()
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00415145
* VC++ mangling:          ?BeginLoadGame@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::BeginLoadGame()
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
* Entry point:            0x00415236
* VC++ mangling:          ?GetAttachedDevice@B_App@@QAEPAVB_InputDevice@@PBD@Z
*/
#ifdef BLD_NATIVE
B_InputDevice *B_App::GetAttachedDevice(const char *device)
{
    return NULL;
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
* Entry point:            0x0041526D
* VC++ mangling:          ?GetTimeActionHeld@B_App@@QAENPBD@Z
*/

#ifdef BLD_NATIVE

double B_App::GetTimeActionHeld(const char *action)
{
    return 0.0;
}

#endif


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
* Module:                 Blade.exe
* Entry point:            0x004152C0
* VC++ mangling:          ?RemoveInputAction@B_App@@QAEXPBD@Z
*/

#ifdef BLD_NATIVE

void B_App::RemoveInputAction(const char *action_name)
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
* Entry point:            0x00415425
* VC++ mangling:          ?Bind@B_App@@QAE_NPBDPAU_object@@@Z
*/

#ifdef BLD_NATIVE

bool B_App::Bind(const char *key, PyObject *proc)
{
    return false;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00415471
* VC++ mangling:          ?Bind2@B_App@@QAEXPBD00H@Z
*/

#ifdef BLD_NATIVE

void B_App::Bind2(
    const char *act, const char *subact1,
    const char *subact2, int unknown
)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0041549C
* VC++ mangling:          ?BindPred@B_App@@QAE_NPBD0@Z
*/

#ifdef BLD_NATIVE

bool B_App::BindPred(const char *key, const char *pred)
{
    return false;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004154F2
* VC++ mangling:          ?UnBindPred@B_App@@QAE_NPBD0@Z
*/

#ifdef BLD_NATIVE

bool B_App::UnBindPred(const char *key, const char *pred)
{
    return false;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00415548
* VC++ mangling:          ?UnBind@B_App@@QAE_NPBDPAU_object@@@Z
*/

#ifdef BLD_NATIVE

bool B_App::UnBind(const char *key, PyObject *proc)
{
    return false;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004155AE
* VC++ mangling:          ?AssocKey@B_App@@QAEHPBD00H@Z
*/

#ifdef BLD_NATIVE

int B_App::AssocKey(
    const char *action, const char *input_device, const char *key,
    int press
)
{
    return 0;
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004155D9
* VC++ mangling:          ?UnBindAll@B_App@@QAEXXZ
*/

#ifdef BLD_NATIVE

void B_App::UnBindAll()
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
* Entry point:            0x00415610
* VC++ mangling:          ?SetAutoGenTexture@B_App@@QAEHPBDH@Z
*/
#ifdef BLD_NATIVE
int B_App::SetAutoGenTexture(const char *textureName, int textureEffect)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00415759
* VC++ mangling:          ?RunPythonFile@B_App@@QAE_NPBD@Z
*/

bool B_App::RunPythonFile(const char *file_name)
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
* Module:                 Blade.exe
* Entry point:            0x00415811
* VC++ mangling:          ?ReadArguments@B_App@@UAEXPBD@Z
*/

void B_App::ReadArguments(const char *args)
{
    static char defaultMapName[] = "";
    static char defaultRasterName[] = "";
    static char defaultSoundDeviceId[] = "";

    assert(args);
    this->StringSplit(args, " -", &this->arguments);
    for(unsigned int i = 0; i < this->arguments.size; i++)
    {
        if (*this->arguments.elements[i] == "nosound")
        {
            this->noSound = true;
        }
        else if (*this->arguments.elements[i] == "cls")
        {
            this->cls = true;
        }
        else if (*this->arguments.elements[i] == "console")
        {
            this->showConsole = true;
        }
        /* FIXME two "nosound" arguments*/
        else if (*this->arguments.elements[i] == "nosound")
        {
            this->noSound = true;
        }
        else if (!strncmp(
            this->arguments.elements[i]->String(),
            "map:",
            sizeof("map:") - 1))
        {
            const B_Name &map = *this->arguments.elements[i];
            this->mapName = map;
        }
        else if (!strncmp(
            this->arguments.elements[i]->String(),
            "dev:",
            sizeof("dev:") - 1))
        {
            const B_Name &raster = *this->arguments.elements[i];
            this->rasterName = raster;
        }
        else if (!strncmp(
            this->arguments.elements[i]->String(),
            "snd:",
            sizeof("snd:") - 1))
        {
            const B_Name &snd = *this->arguments.elements[i];
            this->soundDeviceId = snd;
        }
        else if (!strncmp(
            this->arguments.elements[i]->String(),
            "nogamespy",
            4))/* FIXME should be whole world comparison*/
        {
            SetGameSpySupport(false);
        }
        else if (*this->arguments.elements[i] == "dedicated")
        {
            SetDedicatedServer(true);
            this->showConsole = true;
            this->mapName = "map:Arena1";
            this->soundDeviceId = "snd:6";
            this->rasterName = "dev:rNull.dlx";
            this->noSound = true;
        }
    }
    B_PtrArray<B_Name> mapTokens;
    const char *mapString = this->mapName;
    this->StringSplit(mapString, ":", &mapTokens);
    if (mapTokens.size != 2)
    {
        this->mapName = defaultMapName;
    }
    else
    {
        const B_Name &map = *mapTokens.elements[1];
        this->mapName = map.String();
    }
    B_PtrArray<B_Name> rasterTokens;
    const char *rasterString = this->rasterName;
    this->StringSplit(rasterString, ":", &rasterTokens);
    if (rasterTokens.size != 2)
    {
        this->rasterName = defaultRasterName;
    }
    else
    {
        const B_Name &raster = *rasterTokens.elements[1];
        this->rasterName = raster.String();
    }
    B_PtrArray<B_Name> sndTokens;
    const char *sndString = this->soundDeviceId;
    this->StringSplit(sndString, ":", &sndTokens);
    if (sndTokens.size != 2)
    {
        this->soundDeviceId = defaultSoundDeviceId;
    }
    else
    {
        const B_Name &snd = *sndTokens.elements[1];
        this->soundDeviceId = snd.String();
    }
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0041617B
* VC++ mangling:          ?OutSound@B_App@@QAE_NHNNNH@Z
*/

#ifdef BLD_NATIVE

bool B_App::OutSound(int soundId, double x, double y, double z, int unknown)
{
    return false;
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004161EA
* VC++ mangling:          ?CallCdCb@B_App@@UAEXH@Z
*/
#ifdef BLD_NATIVE
void B_App::CallCdCb(int arg)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416298
* VC++ mangling:          ?CDSetCallBack@B_App@@QAEHPAU_object@@@Z
*/
#ifdef BLD_NATIVE
int B_App::CDSetCallBack(PyObject *func)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416309
* VC++ mangling:          ?SetAfterFrameFunc@B_App@@QAEXPBDPAU_object@@@Z
*/
#ifdef BLD_NATIVE
void B_App::SetAfterFrameFunc(const char *name, PyObject *function)
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0041653E
* VC++ mangling:          ?GetAfterFrameFunc@B_App@@QAEPAU_object@@PBD@Z
*/
#ifdef BLD_NATIVE
PyObject *B_App::GetAfterFrameFunc(const char *name)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004165D8
* VC++ mangling:          ?GetAfterFrameFuncName@B_App@@QAEPBDH@Z
*/
#ifdef BLD_NATIVE
const char *B_App::GetAfterFrameFuncName(int index)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041661D
* VC++ mangling:          ?GetnAfterFrameFuncs@B_App@@QAEHXZ
*/
#ifdef BLD_NATIVE
int B_App::GetnAfterFrameFuncs()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416631
* VC++ mangling:          ?SetMenuTgapFunc@B_App@@QAEXPAU_object@@@Z
*/
#ifdef BLD_NATIVE
void B_App::SetMenuTgapFunc(PyObject *func)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416678
* VC++ mangling:          ?GetMenuTgapFunc@B_App@@QAEPAU_object@@XZ
*/
#ifdef BLD_NATIVE
PyObject *B_App::GetMenuTgapFunc()
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041668C
* VC++ mangling:          ?RemoveAfterFrameFunc@B_App@@QAEHPBD@Z
*/
#ifdef BLD_NATIVE
int B_App::RemoveAfterFrameFunc(const char *name)
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
* Entry point:            0x004167E1
* VC++ mangling:          ?StringSplit@B_App@@UAEXPBD0PAV?$B_PtrArray@VB_Name@@@@@Z
*/
#ifdef BLD_NATIVE
void B_App::StringSplit(
    const char *str, const char *sep, B_PtrArray<B_Name> *tokens)
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
* Entry point:            0x00416C0B
* VC++ mangling:          ?SetBloodLevel@B_App@@QAEHH@Z
*/

#ifdef BLD_NATIVE

int B_App::SetBloodLevel(int blood_level)
{
    return 0;
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416C29
* VC++ mangling:          ?GetBloodLevel@B_App@@QAEHXZ
*/
#ifdef BLD_NATIVE
int B_App::GetBloodLevel()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416C3D
* VC++ mangling:          ?SetMutilationLevel@B_App@@QAEHH@Z
*/
#ifdef BLD_NATIVE
int B_App::SetMutilationLevel(int mutilation_level)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416C5B
* VC++ mangling:          ?GetMutilationLevel@B_App@@QAEHXZ
*/
#ifdef BLD_NATIVE
int B_App::GetMutilationLevel()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416C6F
* VC++ mangling:          ?LoadWorld@B_App@@QAEHPBD@Z
*/

int B_App::LoadWorld(const char *file_name)
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
        *file >> &B_world;
        delete file;

        timeAfter = timeGetTime();

        mout << vararg(
                "World %s loaded (%f seconds).\n",
                file_name,
                (timeAfter - timeBefore)/1000.0
        );

        B_world.world_file_name = B_Name(file_name);

        if (gbl_sound_device)
        {
                mout << "About to set world size for sound device\n";

                timeBefore = timeGetTime();

                gbl_sound_device->set_world_size(
                        B_world.unknown18FC.x, B_world.unknown18FC.y,
                        B_world.unknown18FC.z, B_world.unknown1914,
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
* Module:                 Blade.exe
* Entry point:            0x00416EAB
* VC++ mangling:          ?SetPyInteractiveString@B_App@@UAEXPBD@Z
*/
#ifdef BLD_NATIVE
void B_App::SetPyInteractiveString(const char *str)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00416EFA
* VC++ mangling:          ?SetStringValue@B_App@@QAEHPBD0@Z
*/
#ifdef BLD_NATIVE
int B_App::SetStringValue(const char *variable, const char *value)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041712A
* VC++ mangling:          ?GetStringValue@B_App@@QAEPBDPBD@Z
*/
#ifdef BLD_NATIVE
const char *B_App::GetStringValue(const char *variable)
{
    return NULL;
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004171D1
* VC++ mangling:          ?DeleteStringValue@B_App@@QAEHPBD@Z
*/
#ifdef BLD_NATIVE
int B_App::DeleteStringValue(const char *variable)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00417417
* VC++ mangling:          ?GetInputMode@B_App@@UAEPBDPBD@Z
*/
#ifdef BLD_NATIVE
const char *B_App::GetInputMode(const char *device)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00417426
* VC++ mangling:          ?SetInputMode@B_App@@UAEHPBD0@Z
*/
#ifdef BLD_NATIVE
int B_App::SetInputMode(const char *device, const char *mode)
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
* Entry point:            0x004179B0
* VC++ mangling:          ?unknown_method010@B_App@@UAEPAXPAX@Z
*/
#ifdef BLD_NATIVE
void *B_App::unknown_method010(void *)
{
    return NULL;
}
#endif
