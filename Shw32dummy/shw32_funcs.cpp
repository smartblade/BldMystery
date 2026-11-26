// Replacement of SmartHeap shw32.dll which forwards the memory functions of
// Blade.exe to bicrt.dll. SmartHeap patches the heap functions of Windows for
// the whole process and the heap gets corrupted when they are called by the
// components of modern Windows, e.g. by GetDeviceGammaRamp. Memory allocated
// by Blade.exe is freed by other modules, e.g. by Bladex.dll, with free of
// bicrt.dll, so the replacement uses the heap of bicrt.dll.

#include <stddef.h>

void *operator new(size_t size);
void operator delete(void *ptr);

struct _heapinfo;

extern "C" {

// Functions of bicrt.dll
void *__cdecl malloc(size_t size);
void *__cdecl calloc(size_t num, size_t size);
void *__cdecl realloc(void *ptr, size_t size);
void __cdecl free(void *ptr);
void *__cdecl _expand(void *ptr, size_t size);
size_t __cdecl _msize(void *ptr);
int __cdecl _heapadd(void *ptr, size_t size);
int __cdecl _heapchk();
int __cdecl _heapset(unsigned int fill);
int __cdecl _heapwalk(_heapinfo *entry);
int __cdecl _heapused(size_t *used, size_t *committed);
int __cdecl _heapmin();

void *shi_malloc(size_t size)
{
    return malloc(size);
}

void *shi_calloc(size_t num, size_t size)
{
    return calloc(num, size);
}

void *shi_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void shi_free(void *ptr)
{
    free(ptr);
}

void *shi_expand(void *ptr, size_t size)
{
    return _expand(ptr, size);
}

size_t shi_msize(void *ptr)
{
    return _msize(ptr);
}

void *shi_new(size_t size)
{
    return operator new(size);
}

void shi_delete(void *ptr)
{
    operator delete(ptr);
}

void __stdcall shi_deletePtrStdcall(void *ptr)
{
    operator delete(ptr);
}

int shi_heapadd(void *ptr, size_t size)
{
    return _heapadd(ptr, size);
}

int shi_heapchk()
{
    return _heapchk();
}

int shi_heapset(unsigned int fill)
{
    return _heapset(fill);
}

int shi_heapwalk(_heapinfo *entry)
{
    return _heapwalk(entry);
}

int shi_heapused(size_t *used, size_t *committed)
{
    return _heapused(used, committed);
}

int shi_heapmin()
{
    return _heapmin();
}

// Blade.exe stores the pool and does not use it
static char defaultPool;

void *shi_MemInitDefaultPool()
{
    return &defaultPool;
}

int shi_MemFreeDefaultPool()
{
    return 1;
}

}
