
#include <bld_system.h>
#include <console.h>
#include <raster_device.h>
#include "BladeApp.h"
#include "WinClock.h"
#include <BInputc.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x0040F040
* VC++ mangling:          ??0B_WinApp@@QAE@PAUHINSTANCE__@@HPADP6GJPAUHWND__@@IIJ@Z@Z
*/

B_WinApp::B_WinApp(HINSTANCE module, int nCmdShow, char *cmdLine, WNDPROC winProc)
:
B_App(cmdLine)
{
    this->noExclusiveMouse = false;
    this->noMouse = false;
    this->b07C9 = false;
    this->noDInput = false;
    this->r3Dfx = false;
    this->rsoft16b = false;
    this->rOpenGL = false;
    this->rD3D = false;
    this->destroyRasterCB = NULL;
    this->createRasterCB = NULL;
    this->rasterLibrary = NULL;
    this->b07C0 = true;
    this->winProc = winProc;
    this->module = module;
    this->clock1 = new B_WinClock();
    if (this->clock1 == NULL)
    {
        this->ExitWithError("Blade", "No se ha podido inicializar reloj.");
    }
    this->clock2 = new B_WinClock();
    if (this->clock2 == NULL)
    {
        this->ExitWithError("Blade", "No se ha podido inicializar reloj (2).");
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F1B4
* VC++ mangling:          ??1B_WinApp@@UAE@XZ
*/

B_WinApp::~B_WinApp()
{
    if (destroyRasterCB != NULL)
    {
        destroyRasterCB(B_3D_raster_device);
        B_3D_raster_device = NULL;
        FreeLibrary(rasterLibrary);
        this->rasterLibrary = NULL;
    }
    if (showConsole)
    {
        DestroyConsole(console);
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F256
* VC++ mangling:          ?InitWindow@B_WinApp@@UAE_NXZ
*/

bool B_WinApp::InitWindow()
{
    this->windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    this->windowClass.hIcon = LoadIcon(this->module, MAKEINTRESOURCE(109));
    this->windowClass.lpszMenuName = NULL;
    this->windowClass.lpszClassName = "Blade";
    this->windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    this->windowClass.hInstance = this->module;
    this->windowClass.style = CS_OWNDC;
    if (this->winProc != NULL)
        this->windowClass.lpfnWndProc = this->winProc;
    else
        this->windowClass.lpfnWndProc = ::WindowProcedure;
    this->windowClass.cbClsExtra = 0;
    this->windowClass.cbWndExtra = 0;
    if (!RegisterClass(&this->windowClass))
        return false;
    this->window = this->NewWindowForClientRectangle();
    if (this->window == NULL)
        return false;
    ShowWindow(this->window, SW_HIDE);
    UpdateWindow(this->window);
    return true;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F388
* VC++ mangling:          ?ProcessMessage@B_WinApp@@UAEXXZ
*/

void B_WinApp::ProcessMessage()
{
    MSG msg;
    PeekMessage(&msg, NULL, WM_NULL, WM_NULL, PM_REMOVE);
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F3BB
* VC++ mangling:          ?NewWindow@B_WinApp@@UAEPAUHWND__@@XZ
*/

HWND B_WinApp::NewWindow()
{
    HWND window = CreateWindowExA(
        WS_EX_LEFT, "Blade", "Blade",
        (
            WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |
            WS_EX_TRANSPARENT/*TODO Find correct constant for 0x20*/),
        0, 0, 640, 480, NULL, NULL, module, NULL);
    return window;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F403
* VC++ mangling:          ?NewWindowForClientRectangle@B_WinApp@@UAEPAUHWND__@@XZ
*/

HWND B_WinApp::NewWindowForClientRectangle()
{
    int width, height;
    RECT rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = clientRectWidth;
    rect.bottom = clientRectHeight;
    if (AdjustWindowRectEx(
        &rect, (WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME),
        false, WS_EX_LEFT))
    {
        width = rect.right - rect.left;
        height = rect.bottom - rect.top;
    }
    else
    {
        width = clientRectWidth;
        height = clientRectHeight;
    }
    HWND window = CreateWindowExA(
        WS_EX_LEFT, "Blade", "Blade",
        (WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW),
        0, 0, width, height, NULL, NULL, module, NULL);
    return window;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F4A4
* VC++ mangling:          ?Start@B_WinApp@@UAE_NXZ
*/
#ifdef BLD_NATIVE
bool B_WinApp::Start()
{
    return false;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041009D
* VC++ mangling:          ?LoadLevel@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::LoadLevel(const char *map)
{
    char buffer[260];
    double timeBefore, timeAfter;
    static int loadLevelCounter = 0;

    timeBefore = timeGetTime();

    this->mapName = get_map_for_net_game(map);
    map = this->mapName;

    GetCurrentDirectory(sizeof(buffer), buffer);
    mout << buffer;
    mout << "\n";

    if (loadLevelCounter)
    {
        SetCurrentDirectory(vararg("..\\%s", map));
    }
    else
    {
        SetCurrentDirectory(vararg("..\\Maps\\%s", map));
    }

    GetCurrentDirectory(sizeof(buffer), buffer);
    mout << buffer;
    mout << "\n";

    if (gbl_sound_device)
    {
        gbl_sound_device->unknown08 = 1;
        gbl_sound_device->unknown0C = 1;
    }

    if (gbl_net->is_net_game())
    {
        if (gbl_net->is_server())
        {
            B_App::LoadLevel("Server.py");
            Set007EA988To01();
        }
        else
        {
            B_App::LoadLevel("Client.py");
        }
    }
    else
    {
        loadLevelCounter++;

        B_App::LoadLevel("Cfg.py");
    }

    timeAfter = timeGetTime();
    mout << vararg("Load Time = %f\n", (timeAfter - timeBefore)/1000.0);

    if (gbl_sound_device)
    {
        gbl_sound_device->unknown08 = 0;
        gbl_sound_device->unknown0C = 0;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410305
* VC++ mangling:          ?ProcessEvents@B_WinApp@@UAE_NXZ
*/

bool B_WinApp::ProcessEvents() {
    static int counter = 0;

    if (!this->no_sleep)
        Sleep(50);

    if (counter == 60)
    {
        SetWindowText(
            (HWND)this->window,
            vararg("%s %.1f", "Blade", this->fUnknown5C0)
        );
        counter = 0;
    }

    counter++;
    return B_App::ProcessEvents();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410384
* VC++ mangling:          ?End@B_WinApp@@UAEXXZ
*/

void B_WinApp::End()
{
    B_App::End();
    FreeNetData(true);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004103A1
* VC++ mangling:          ?Quit@B_WinApp@@UAEHXZ
*/

int B_WinApp::Quit()
{
    if (B_App::Quit())
    {
        PostMessage(this->window, WM_QUIT, 0, 0);
        return true;
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004103D7
* VC++ mangling:          ?ReadArguments@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::ReadArguments(const char *args)
{
    B_App::ReadArguments(args);
    for(unsigned int i = 0; i < this->arguments.size; i++)
    {
        if (*this->arguments.elements[i] == "nomouse")
        {
            this->noMouse = true;
        }
        else if (*this->arguments.elements[i] == "nodinput")
        {
            this->noDInput = true;
            this->noMouse = true;
        }
        else if (*this->arguments.elements[i] == "noexclusivemouse")
        {
            this->noExclusiveMouse = true;
        }
        else if (*this->arguments.elements[i] == "rsoft16b")
        {
            this->rsoft16b = true;
        }
        else if (*this->arguments.elements[i] == "rOpenGL")
        {
            this->rOpenGL = true;
        }
        else if (*this->arguments.elements[i] == "r3Dfx")
        {
            this->r3Dfx = true;
        }
        else if (*this->arguments.elements[i] == "rD3D")
        {
            this->rD3D = true;
        }
        else if (*this->arguments.elements[i] == "dedicated")
        {
            this->noMouse = true;
        }
        else if (*this->arguments.elements[i] == "quick")
        {
            showStartupDialog = false;
        }
        else if (!strncmp(
            this->arguments.elements[i]->String(),
            "startpath:",
            sizeof("startpath:") - 1))
        {
            const char *startPathArg = this->arguments.elements[i]->String();
            this->startPath = startPathArg + sizeof("startpath:") - 1;
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410640
* VC++ mangling:          ?unknown_method010@B_WinApp@@UAEPAXPAX@Z
*/
#ifdef BLD_NATIVE
void *B_WinApp::unknown_method010(void *)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004106F2
* VC++ mangling:          ?ReadLevel@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::ReadLevel(const char *file_name)
{
    HCURSOR waitCursor = LoadCursor(NULL, IDC_WAIT);
    HCURSOR currentCursor = GetCursor();
    SetCursor(waitCursor);
    B_App::ReadLevel(file_name);
    SetCursor(currentCursor);
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041073A
* VC++ mangling:          ?WindowProcedure@B_WinApp@@UAEJPAUHWND__@@IIJ@Z
*/

LRESULT B_WinApp::WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_SIZING:
        {
            this->ProcessEvents();
            PRECT rect = reinterpret_cast<PRECT>(lParam);
            SetWindowText(
                this->window,
                vararg(
                    "Size %dx%d",
                    rect->right - rect->left,
                    rect->bottom - rect->top));
            return true;
        }
        case WM_MOVING:
            this->ProcessEvents();
            return true;
        case WM_ACTIVATEAPP:
            if (IsDedicatedServer())
                break;
            if ((B_3D_raster_device != NULL) &&
                (B_3D_raster_device->unknown22C() == 3))
            {
                break;
            }
            this->isActive = this->no_sleep = (wParam != 0);
            this->Mouse(this->no_sleep);
            if (!this->isActive)
            {
                this->StopTime();
            }
            else if (this->b05D4)
            {
                this->RestartTime();
            }
            if (B_3D_raster_device != NULL)
            {
                if (B_3D_raster_device->full_screen())
                {
                    if (!this->isActive)
                    {
                        B_3D_raster_device->unknown204(wParam);
                        CloseWindow(this->window);
                    }
                    else
                    {
                        OpenIcon(this->window);
                        B_3D_raster_device->unknown204(wParam);
                    }
                }
                Unknown004CD5EC unknown(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
                this->unknown_method010(&unknown);
                B_3D_raster_device->unknown008(&unknown);
            }
            return false;
        case WM_SYSKEYDOWN:
            return false;
        case WM_SYSCHAR:
            return false;
        case WM_HELP:
            return false;
        case WM_CLOSE:
            PostMessage(hwnd, WM_QUIT, 0, 0);
            break;
        case WM_COPYDATA:
        {
            PCOPYDATASTRUCT copyData = reinterpret_cast<PCOPYDATASTRUCT>(
                lParam);
            if (copyData->dwData == 101)
            {
                PyRun_InteractiveString(reinterpret_cast<char *>(
                    copyData->lpData));
            }
            break;
        }
        case WM_COMMAND:
        {
            int menuId = LOWORD(wParam);
            if (menuId != 40001/*File->Exit*/)
                break;
            PostQuitMessage(0);
            break;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410AF5
* VC++ mangling:          ?Mouse@B_WinApp@@UAEX_N@Z
*/

void B_WinApp::Mouse(bool acquire)
{
    B_WinMouse *mouse = static_cast<B_WinMouse *>(
        this->GetAttachedDevice("Mouse"));
    if (!acquire)
    {
        if (mouse != NULL)
        {
            mouse->UnAcquire();
        }
    }
    else if (mouse != NULL && !mouse->Acquire())
    {
        this->no_sleep = false;
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410B53
* VC++ mangling:          ?ExitWithError@B_WinApp@@UAEXPAD0@Z
*/

void B_WinApp::ExitWithError(char *Title, char *Message)
{
    assert(Title);
    assert(Message);
    MessageBox(this->window, Message, Title, MB_ICONERROR);
    exit(1);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410BBE
* VC++ mangling:          ?PrintWarning@B_WinApp@@UAEXPBD0@Z
*/

void B_WinApp::PrintWarning(const char *Title, const char *Message)
{
    assert(Title);
    assert(Message);
    FILE *file = fopen("WarningLog.txt", "a+");
    fputs(Message, file);
    fclose(file);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410C3D
* VC++ mangling:          ?Input@B_WinApp@@UAEPBDPBD@Z
*/

const char *B_WinApp::Input(const char *text)
{
    return ShowInputDialog(this->module, this->window, text);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00410C77
* VC++ mangling:          ?WindowProcedure@@YGJPAUHWND__@@IIJ@Z
*/

LRESULT CALLBACK WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    B_WinApp *App = GetWinApplication();
    if (App != NULL)
        return App->WindowProcedure(hwnd, uMsg, wParam, lParam);
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410CC2
* VC++ mangling:          _WinMain@16
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    B_App *App;
    char *cmd;
    MSG msg;

    cmd = lpCmdLine;

    LoadNetModule("NetBlade\\Netblade.dll");
    App = CreateApplication(hInstance, nCmdShow, cmd);

    assert(App);

    if (!App->Start())
        return 0;

    Set007EA988To01();
    for(;;)
    {
        if (PeekMessage(&msg, NULL, WM_NULL, WM_NULL, PM_REMOVE))
        {

            if (msg.message == WM_QUIT)
            {
                App->End();
                delete App;
                return msg.wParam;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            App->ProcessEvents();

            OnEvent(0, 0xbff00000);
        }
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
* Entry point:            0x00410F6F
* VC++ mangling:          ?SetDirMap@B_WinApp@@UAEHPBD@Z
*/

int B_WinApp::SetDirMap(const char *map)
{
    char buffer[260];

    GetCurrentDirectory(sizeof(buffer), buffer);
    mout << buffer;
    mout << "\n";
    if (SetCurrentDirectory(vararg("..\\%s", map)))
    {
        this->mapName = map;
        return true;
    }
    OutputWin32Error(
        vararg("B_WinApp::SetDirMap() -> Error setting directory.\n"));
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411034
* VC++ mangling:          ?GetInputMode@B_WinApp@@UAEPBDPBD@Z
*/

const char *B_WinApp::GetInputMode(const char *device)
{
    return NULL;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411043
* VC++ mangling:          ?SetInputMode@B_WinApp@@UAEHPBD0@Z
*/

int B_WinApp::SetInputMode(const char *device, const char *mode)
{
    if (!strcmp(device, "Mouse"))
    {
        B_WinMouse *mouse = static_cast<B_WinMouse *>(
            this->GetAttachedDevice(device));
        if (mouse != NULL)
        {
            if (!strcmp(mode, "ACQUIRE"))
            {
                mouse->Acquire();
                ShowCursor(false);
            }
            if (!strcmp(mode, "UNACQUIRE"))
            {
                mouse->UnAcquire();
                ShowCursor(true);
            }
            return true;
        }
    }
    if (!strcmp(device, "Keyboard"))
    {
        B_DInputKeyb *keyboard = static_cast<B_DInputKeyb *>(
            this->GetAttachedDevice(device));
        if (keyboard != NULL)
        {
            if (!strcmp(mode, "ACQUIRE"))
            {
                keyboard->Acquire();
            }
            if (!strcmp(mode, "UNACQUIRE"))
            {
                keyboard->UnAcquire();
            }
            return true;
        }
    }
    return false;
}
