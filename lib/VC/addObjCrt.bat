call "c:\Program Files (x86)\Microsoft Visual Studio 8\VC\bin\vcvars32.bat" x86
lib /out:bicrt_obj.lib crt_obj\alloca16.obj bicrt_obj.lib
pause
