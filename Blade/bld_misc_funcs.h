
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

#ifdef __cplusplus
}
#endif
