
#include <bld_system.h>
#define BUILD_LIB
#include <Control/AnimationExt.h>

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0046AB6A
*/
#ifndef BLD_NATIVE
int GetAnimationDuration(const char *animation_name, double *duration)
{
    int (*bld_proc)(const char *animation_name, double *duration) = NULL;
    return bld_proc(animation_name, duration);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046AC16
*/
#ifndef BLD_NATIVE
int RStepEvents(const char *s_unknown1, const char *s_unknown2)
{
    int (*bld_proc)(const char *s_unknown1, const char *s_unknown2) = NULL;
    return bld_proc(s_unknown1, s_unknown2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046AEEC
*/
#ifndef BLD_NATIVE
int LStepEvents(const char *s_unknown1, const char *s_unknown2)
{
    int (*bld_proc)(const char *s_unknown1, const char *s_unknown2) = NULL;
    return bld_proc(s_unknown1, s_unknown2);
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
* Entry point:            0x0046B885
*/
#ifndef BLD_NATIVE
int LoadSampledAnimation(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
)
{
    int (*bld_proc)(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
) = NULL;
    return bld_proc(file, internal_name, type, s_unknown, i_unknown);
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
* Entry point:            0x0046C4D9
*/
#ifndef BLD_NATIVE
int CreateFCAnimation(
        const char *file, const char *internal_name, int n_armonics
)
{
    int (*bld_proc)(
        const char *file, const char *internal_name, int n_armonics
) = NULL;
    return bld_proc(file, internal_name, n_armonics);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046CAFB
*/
#ifndef BLD_NATIVE
int CreateDFCAnimation(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
)
{
    int (*bld_proc)(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
) = NULL;
    return bld_proc(file1, file2, internal_name, n_armonics);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046D1F0
*/
#ifndef BLD_NATIVE
int AddRStepEvent(const char *animation_name, double d_unknown)
{
    int (*bld_proc)(const char *animation_name, double d_unknown) = NULL;
    return bld_proc(animation_name, d_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046D3DE
*/
#ifndef BLD_NATIVE
int AddLStepEvent(const char *animation_name, double d_unknown)
{
    int (*bld_proc)(const char *animation_name, double d_unknown) = NULL;
    return bld_proc(animation_name, d_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046D5CC
*/
#ifndef BLD_NATIVE
int AddRReleaseEvent(const char *animation_name, double d_unknown)
{
    int (*bld_proc)(const char *animation_name, double d_unknown) = NULL;
    return bld_proc(animation_name, d_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046D7BA
*/
#ifndef BLD_NATIVE
int AddLReleaseEvent(const char *animation_name, double d_unknown)
{
    int (*bld_proc)(const char *animation_name, double d_unknown) = NULL;
    return bld_proc(animation_name, d_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046D9A8
*/
#ifndef BLD_NATIVE
void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame)
{
    void (*bld_proc)(const char *anm_name, const char *event_name, double event_frame) = NULL;
    bld_proc(anm_name, event_name, event_frame);
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
* Entry point:            0x0046E1AB
*/
#ifndef BLD_NATIVE
void AddStopTests(const char *animation_name)
{
    void (*bld_proc)(const char *animation_name) = NULL;
    bld_proc(animation_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046E4AC
*/
#ifndef BLD_NATIVE
void AddFloorCTolerance(const char *animation_name, double tolerance)
{
    void (*bld_proc)(const char *animation_name, double tolerance) = NULL;
    bld_proc(animation_name, tolerance);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046E57A
*/
#ifndef BLD_NATIVE
int AddTranTime(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
)
{
    int (*bld_proc)(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
) = NULL;
    return bld_proc(biped_name, next_anm, prev_anm, time, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046E93B
*/
#ifndef BLD_NATIVE
int CheckAnims()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0046EBFD
*/
#ifndef BLD_NATIVE
int GiveAnims(const char *race_name)
{
    int (*bld_proc)(const char *race_name) = NULL;
    return bld_proc(race_name);
}
#endif
