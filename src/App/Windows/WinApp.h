
#ifndef WIN_APP_H

#define WIN_APP_H

#include <App/App.h>

class B_WinApp : public B_App
{
public:
    virtual void ReadArguments(const char *args);
    virtual void ProcessMessage();
    virtual void *unknown_method010(void *);
    virtual ~B_WinApp();
    virtual bool Start();
    virtual bool ProcessEvents();
    virtual void End();
    virtual const char *GetInputMode(const char *device);
    virtual int SetInputMode(const char *device, const char *mode);
    virtual int Quit();
    virtual void LoadLevel(const char *map);
    virtual void ReadLevel(const char *file_name);
    virtual const char *Input(const char *text);
    virtual void ExitWithError(char *title, char* message);
    virtual void PrintWarning(const char *Title, const char *Message);


/*
* Module:                 Blade.exe
* Entry point:            0x00411170
* VC++ mangling:          ?GetWindow@B_WinApp@@UAEIXZ
*/

    virtual size_t GetWindow()
    {
        return reinterpret_cast<size_t>(this->window);
    }


/*
* Module:                 Blade.exe
* Entry point:            0x00411190
* VC++ mangling:          ?GetModule@B_WinApp@@UAEIXZ
*/

    virtual size_t GetModule()
    {
        return reinterpret_cast<size_t>(this->module);
    }

    int LoadRasterDLL(const char *rasterDllName);
    virtual int SetDirMap(const char *map);
    virtual bool InitWindow();
    virtual HWND NewWindow();
    virtual HWND NewWindowForClientRectangle();
    virtual void Mouse(bool acquire);
    virtual LRESULT WindowProcedure(
        HWND hwnd, UINT uMsg, WPARAM wParam,  LPARAM lParam);
    B_WinApp(HINSTANCE module, int nCmdShow, char *cmdLine, WNDPROC winProc);

    B_Name rasterLibraryName;
    B_Name startPath;
    void (*destroyRasterCB)(B_3DRasterDevice *raster);
    B_3DRasterDevice *(*createRasterCB)(HWND, HMODULE, HMODULE);
    HMODULE rasterLibrary;
    WNDPROC winProc;
    WNDCLASS windowClass;
    HWND window;
    HINSTANCE module;
    bool b07C0;
    int unknown07C4;
    bool noMouse;
    bool noKeyboard;
    bool noDInput;
    bool noExclusiveMouse;
    bool r3Dfx;
    bool rsoft16b;
    bool rOpenGL;
    bool rD3D;
};

LRESULT CALLBACK WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif /* WIN_APP_H */
