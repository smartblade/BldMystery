//---------------------------------------------------------------------------

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include "application.h"
#pragma hdrstop

//---------------------------------------------------------------------------

typedef void ( *FuncMarkLevelToLoad)(char *);

typedef void (WINAPI *FuncMain)(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

void tmp()
{
    LPTSTR lpszFunction = "Dialog";
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
    sprintf((LPTSTR)lpDisplayBuf,
        TEXT("%s failed with error %d: %s"), 
        lpszFunction, dw, lpMsgBuf); 
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw);
}
/*0x00401168*/
/*0x0233E8A1*/

/*0xFE0C28C7*/

/*error 1813: ”казанный тип ресурса в файле образа отсутствует */



/*thiscall calling convention*/



HMODULE blade = NULL;
void (*LoadNetModule)(char *) = NULL;
application_t* (*CreateApp)(HINSTANCE hInstance, int nCmdShow, LPSTR lpCmdLine) = NULL;
void (*Set007E7470To01)(void) = NULL;
void (*OnEvent)(int a, int b) = NULL;


/*
* Module:                 Blade.exe
* Entry point:            0x00410C02
*/

int BladeWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        application_t *App;
        char *cmd;
        MSG msg;
        int code;

        cmd = lpCmdLine;

        LoadNetModule("NetBlade\\Netblade.dll");
        App = CreateApp(hInstance, nCmdShow, cmd);

        assert(App);

        if ((application_start(App) & 0xff) == 0)
                return 0;

        Set007E7470To01();
        for(;;) {
                if (PeekMessage(&msg, NULL, WM_NULL, WM_NULL, PM_REMOVE)) {

                        if (msg.message == WM_QUIT) {
                                application_end(App);

                                if (App) {
                                        code = application_destroy(App, 1);
                                } else {
                                        code = 0;
                                }

                                return msg.wParam;
                        } else {
                                TranslateMessage(&msg);
                                DispatchMessage(&msg);
                        }
                } else {
                        /* wait for event */

                        application_wait_for_event(App);

                        OnEvent(0, 0xbff00000);
                }
        }
}


void startup_cb(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        FuncMain mainF;

        if (!blade)
                return;

        mainF = GetProcAddress(blade, "MarkLevelToLoad");

        mainF = (((char *)mainF) - 0x18A61);

        BladeWinMain(blade, hPrevInstance, lpCmdLine, nCmdShow);
        //mainF(blade, hPrevInstance, lpCmdLine, nCmdShow);
}


#pragma argsused
WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        FuncMarkLevelToLoad MarkLevelToLoad;
        FuncMain mainF;

        blade = LoadLibrary("Blade.exe");
/*if (blade != 0x2330000) {
char buf[256];
sprintf(buf, "[%p]\n", blade);
MessageBox(NULL, buf, TEXT("Error"), MB_OK);
return 2;
}*/
        if (!blade)
                return 1;

        /*_asm
        {
                call ebp+08
                or dword ptr [0x007EC70C], 0xFFFFFFFF
        }*/

        LoadNetModule = (void *)((char *)blade + 0x001B57C2);
        CreateApp = (void *)((char *)blade + 0x001B8D30);
        Set007E7470To01 = (void *)((char *)blade + 0x001ABD01);
        OnEvent = (void *)((char *)blade + 0x001AE837);


        MarkLevelToLoad = GetProcAddress(blade, "MarkLevelToLoad");

        mainF = (((char *)MarkLevelToLoad) - 0x18A61 + 0x1A9460);

        mainF((void *)startup_cb, NULL, NULL, NULL);



        //MarkLevelToLoad("Casa");


        return 0;
}
//---------------------------------------------------------------------------
 