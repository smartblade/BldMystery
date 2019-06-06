
#include <bld_system.h>
#include <bld_python.h>
#include "App.h"
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
* Entry point:            0x00429086
*/

int LoadWorld(const char *file_name)
{
        B_App * app = get_application();
        assert(app);
        return app->load_world(file_name);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004290C0
*/

int SetListenerMode(int mode, double x, double y, double z)
{
    B_App *App = get_application();
    assert(App);
    B_Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return App->set_listener_mode(mode, v);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429128
*/

int GetListenerMode()
{
    B_App *App = get_application();
    assert(App);
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042915B
*/

int Quit()
{
    B_App *App = get_application();
    assert(App);
    return App->quit();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429194
*/

int SetTime(double time)
{
    B_App *App = get_application();
    assert(App);
    return App->set_time(time);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004291D2
*/

int GoToTime(double time)
{
    B_App *App = get_application();
    assert(App);
    return App->go_to_time(time);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429210
*/

double GetTime()
{
    return gbl_game_state.get_time();
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042921F
*/

void StopTime()
{
    B_App *App = get_application();
    assert(App);
    return App->stop_time();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429255
*/

void RestartTime()
{
    B_App *App = get_application();
    assert(App);
    App->RestartTime();
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042928B
*/

void SetTimeSpeed(double speed)
{
    B_App *App = get_application();
    assert(App);
    App->SetTimeSpeed(speed);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004292C9
*/

double GetTimeSpeed()
{
    B_App *App = get_application();
    assert(App);
    return App->GetTimeSpeed();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004292FF
*/

int AddInputAction(const char *action_name, int npi)
{
    B_App *App = get_application();
    assert(App);
    App->AddInputAction(action_name, npi);
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429342
*/

int RemoveInputAction(const char *action_name)
{
    B_App *App = get_application();
    assert(App);
    App->RemoveInputAction(action_name);
    return 1;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
/*
* Module:                 Blade.exe
* Entry point:            0x004295C2
*/

int BindPred(const char *key, const char *pred)
{
    assert(key);
    assert(pred);
    B_App *App = get_application();
    assert(App);
    return App->bind_pred(key, pred);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0042B192
*/

const char *GetWorldFileName(void)
{
        return gbl_game_state.world_file_name;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
