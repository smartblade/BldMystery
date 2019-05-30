
#include "bld_ext_funcs.h"

extern B_IDataFile& operator >>(B_IDataFile& file, point_t &point);

#ifdef __cplusplus
extern "C" {
#endif

extern B_IDataFile * read_points(B_IDataFile *file, array_t *points);
extern B_IDataFile * read_sectors(B_IDataFile *file, array_t *sectors);
extern light_t *read_light(B_IDataFile *file);
extern void Set007EA988To01(void);
extern void OnEvent(int a, int b);
extern void reset_client_map_name(void);
extern char *get_map_for_net_game(const char *map);
extern void LoadNetModule(char *fileName);

#ifndef BLD_NATIVE

/*
* Module:                 Blade.exe
* Data address:           0x005DF898
*/
extern array_t gbl_world_points;

/*
* Module:                 Blade.exe
* Data address:           0x005E0B88
*/
extern game_state_t gbl_game_state;


/*
* Module:                 Blade.exe
* Data address:           0x007072A8
*/
extern array_t gbl_anims;

/*
* Module:                 Blade.exe
* Data address:           0x007C8ED0
*/
extern sound_t *gbl_sound_device;

/*
* Module:                 Blade.exe
* Data address:           0x007EE018
*/
extern char client_map_name[128];

/*
* Module:                 Blade.exe
* Data address:           0x007EE0B8
*/
extern char net_game_name[128];

/*
* Module:                 Blade.exe
* Data address:           0x007EE138
*/
extern int gbl_net_max_players;

/*
* Module:                 Blade.exe
* Data address:           0x007EE2C4
*/
extern bld_abstract_net *gbl_net;

/*
* Module:                 Blade.exe
* Data address:           0x007EFC94
*/
extern B_App *gbl_application;

#endif

#ifdef __cplusplus
}
#endif
