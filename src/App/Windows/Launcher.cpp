#include <bld_system.h>
#include <App/Windows/Launcher.h>
#include "BladeApp.h"
#include <ddraw.h>
#include <dshow.h>
#include <stdio.h>
#include <string.h>


#define WM_GRAPHNOTIFY (WM_USER + 13)


/*
* Module:                 Blade.exe
* Data address:           0x005DFA58
*/
static long gbl_video_event_code;

/*
* Module:                 Blade.exe
* Data address:           0x005DFA60
*/
static RECT gbl_video_rect;

/*
* Module:                 Blade.exe
* Data address:           0x005DFA70
*/
static HWND gbl_video_owner_window;

/*
* Module:                 Blade.exe
* Data address:           0x005DFAF4
*/
static HRESULT gbl_video_result;

/*
* Module:                 Blade.exe
* Data address:           0x005DFAF8
*/
static long gbl_video_event_param2;

/*
* Module:                 Blade.exe
* Data address:           0x005DFAFC
*/
static long gbl_video_event_param1;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB0C
*/
static IUnknown *gbl_video_unknown_interface;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB10
*/
static IGraphBuilder *gbl_video_graph_builder;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB14
*/
static IMediaControl *gbl_video_media_control;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB18
*/
static IMediaEventEx *gbl_video_media_event;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB1C
*/
static IVideoWindow *gbl_video_window;

/*
* Module:                 Blade.exe
* Data address:           0x005DFB20
*/
static BOOL gbl_video_finished;


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0040E8E6
*/
#ifndef BLD_NATIVE
int ShowStartupDialog(
    HMODULE module,
    HWND window,
    B_YSoundDev *sound,
    B_Name *rasterName,
    bool showDialog
)
{
    return false;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040E97A
* VC++ mangling:          ?StartVideo@@YAXPBD@Z
*/

void StartVideo(const char *fileName)
{
    WCHAR wideFileName[MAX_PATH];
    MultiByteToWideChar(CP_ACP, 0, fileName, -1, wideFileName, MAX_PATH);
    gbl_video_result = CoCreateInstance(
        CLSID_FilterGraph,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder,
        reinterpret_cast<void **>(&gbl_video_graph_builder)
    );
    if (SUCCEEDED(gbl_video_result))
    {
        gbl_video_graph_builder->QueryInterface(
            IID_IMediaControl,
            reinterpret_cast<void **>(&gbl_video_media_control)
        );
        gbl_video_graph_builder->QueryInterface(
            IID_IMediaEventEx,
            reinterpret_cast<void **>(&gbl_video_media_event)
        );
        gbl_video_graph_builder->QueryInterface(
            IID_IVideoWindow,
            reinterpret_cast<void **>(&gbl_video_window)
        );
        gbl_video_result =
            gbl_video_graph_builder->RenderFile(wideFileName, nullptr);
        gbl_video_window->put_Owner(
            reinterpret_cast<OAHWND>(gbl_video_owner_window)
        );
        gbl_video_window->put_WindowStyle(
            WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN
        );
        gbl_video_media_event->SetNotifyWindow(
            reinterpret_cast<OAHWND>(gbl_video_owner_window),
            WM_GRAPHNOTIFY,
            0
        );
        GetClientRect(gbl_video_owner_window, &gbl_video_rect);
        gbl_video_window->SetWindowPosition(
            gbl_video_rect.left,
            gbl_video_rect.top,
            gbl_video_rect.right,
            gbl_video_rect.bottom
        );
        if (SUCCEEDED(gbl_video_result))
        {
            gbl_video_media_control->Run();
        }
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040EAE5
* VC++ mangling:          ?VideoWindowProcedure@@YGJPAUHWND__@@IIJ@Z
*/

LRESULT CALLBACK VideoWindowProcedure(
    HWND window,
    UINT message,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (message)
    {
        case WM_SIZE:
        {
            GetClientRect(window, &gbl_video_rect);
            if (gbl_video_window != nullptr)
            {
                gbl_video_window->SetWindowPosition(
                    gbl_video_rect.left,
                    gbl_video_rect.top,
                    gbl_video_rect.right,
                    gbl_video_rect.bottom
                );
            }
            break;
        }
        case WM_GRAPHNOTIFY:
        {
            while (
                SUCCEEDED(
                    gbl_video_media_event->GetEvent(
                        &gbl_video_event_code,
                        &gbl_video_event_param1,
                        &gbl_video_event_param2,
                        0
                    )
                )
            )
            {
                gbl_video_result = gbl_video_media_event->FreeEventParams(
                    gbl_video_event_code,
                    gbl_video_event_param1,
                    gbl_video_event_param2
                );
                if (gbl_video_event_code == EC_COMPLETE)
                {
                    if (gbl_video_window != nullptr)
                    {
                        gbl_video_window->put_Visible(OAFALSE);
                        gbl_video_window->put_Owner(0);
                        if (gbl_video_window != nullptr)
                        {
                            gbl_video_window->Release();
                        }
                        gbl_video_window = nullptr;
                    }
                    if (gbl_video_unknown_interface != nullptr)
                    {
                        gbl_video_unknown_interface->Release();
                    }
                    gbl_video_unknown_interface = nullptr;
                    if (gbl_video_graph_builder != nullptr)
                    {
                        gbl_video_graph_builder->Release();
                    }
                    gbl_video_graph_builder = nullptr;
                    if (gbl_video_media_control != nullptr)
                    {
                        gbl_video_media_control->Release();
                    }
                    gbl_video_media_control = nullptr;
                    if (gbl_video_media_event != nullptr)
                    {
                        gbl_video_media_event->Release();
                    }
                    gbl_video_media_event = nullptr;
                    gbl_video_finished = TRUE;
                    break;
                }
            }
            break;
        }
        case WM_KILLFOCUS:
        case WM_NCLBUTTONDOWN:
        case WM_NCRBUTTONDOWN:
        case WM_NCMBUTTONDOWN:
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
        case WM_SYSCOMMAND:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONDOWN:
        {
            if (gbl_video_media_control != nullptr)
            {
                gbl_video_media_control->Stop();
                gbl_video_finished = TRUE;
            }
            break;
        }
        case WM_DESTROY:
        {
            break;
        }
        default:
        {
            return DefWindowProc(window, message, wParam, lParam);
        }
    }
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040EE2B
* VC++ mangling:          ?PlayVideo@@YAXPAUHWND__@@PBD@Z
*/

void PlayVideo(HWND, const char *fileName)
{
    LPDIRECTDRAW directDraw;
    WNDCLASS windowClass;
    HRESULT result;
    MSG message;
    CoInitialize(nullptr);
    memset(&windowClass, 0, sizeof(windowClass));
    windowClass.lpfnWndProc = DefWindowProc;
    windowClass.hInstance =
        reinterpret_cast<HINSTANCE>(GetWinApplication()->GetModule());
    windowClass.hbrBackground =
        static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
    windowClass.lpszClassName = "InWindow";
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.lpfnWndProc = VideoWindowProcedure;
    RegisterClass(&windowClass);
    gbl_video_owner_window = CreateWindowEx(
        0,
        "InWindow",
        "WinBlade",
        WS_POPUP | WS_VISIBLE,
        0,
        0,
        640,
        480,
        nullptr,
        nullptr,
        windowClass.hInstance,
        nullptr
    );
    ShowWindow(gbl_video_owner_window, SW_SHOWNORMAL);
    UpdateWindow(gbl_video_owner_window);
    ShowCursor(FALSE);
    result = DirectDrawCreate(nullptr, &directDraw, nullptr);
    if (SUCCEEDED(result))
    {
        directDraw->SetCooperativeLevel(
            gbl_video_owner_window,
            DDSCL_FULLSCREEN | DDSCL_NORMAL
        );
        result = directDraw->SetDisplayMode(640, 480, 32);
        if (FAILED(result))
        {
            result = directDraw->SetDisplayMode(640, 480, 24);
        }
        if (FAILED(result))
        {
            result = directDraw->SetDisplayMode(640, 480, 16);
        }
        StartVideo(fileName);
        while (GetMessage(&message, nullptr, 0, 0) && !gbl_video_finished)
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        directDraw->Release();
    }
    else
    {
        printf("Could not open DirectDraw - check it is installed\n");
    }
    DestroyWindow(gbl_video_owner_window);
    CoUninitialize();
    ShowCursor(TRUE);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
