
/*
* Module:                 Blade.exe
* Entry point:            0x005B65D2
* VC++ mangling:          _LoadNetModule
*/

#ifdef BLD_NATIVE

void LoadNetModule(char *)
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005AC791
* VC++ mangling:          _Set007EA988To01
*/

#ifdef BLD_NATIVE

void Set007EA988To01()
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005AF2CE
* VC++ mangling:          _OnEvent
*/

#ifdef BLD_NATIVE

void OnEvent(int a, int b)
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005B9B60
* VC++ mangling:          _create_application
*/

#ifdef BLD_NATIVE

B_App* create_application(void *module, int nCmdShow, char *cmdLine)
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005B9BB7
* VC++ mangling:          _get_application
*/

#ifdef BLD_NATIVE

B_App *get_application()
{
}

#endif

}


/*
* Module:                 Blade.exe
* Entry point:            0x004138B8
* VC++ mangling:          ?read_level@B_App@@UAEXPBD@Z
*/

void B_App::read_level(const char * file_name)
{
}

/*
* Module:                 Blade.exe
* Entry point:            0x00416C6F
* VC++ mangling:          ?load_world@B_App@@QAEHPBD@Z
*/

#ifdef BLD_NATIVE

int B_App::load_world(const char *file_name)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x00429086
* VC++ mangling:          _LoadWorld
*/

extern "C" __declspec(dllexport) int LoadWorld(const char *file_name)
{
}

/*
* Module:                 Blade.exe
* Entry point:            0x00410CC2
* VC++ mangling:          _WinMain@16
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
}