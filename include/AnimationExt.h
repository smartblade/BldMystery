#ifndef ANIMATION_EXT_H

#define ANIMATION_EXT_H

#include <export.h>


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP int GetAnimationDuration(const char *animation_name, double *duration);
LIB_EXP int RStepEvents(const char *s_unknown1, const char *s_unknown2);
LIB_EXP int LStepEvents(const char *s_unknown1, const char *s_unknown2);
LIB_EXP int LoadSampledAnimation(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
);
LIB_EXP int CreateFCAnimation(
        const char *file, const char *internal_name, int n_armonics
);
LIB_EXP int CreateDFCAnimation(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
);
LIB_EXP int AddRStepEvent(const char *animation_name, double d_unknown);
LIB_EXP int AddLStepEvent(const char *animation_name, double d_unknown);
LIB_EXP int AddRReleaseEvent(const char *animation_name, double d_unknown);
LIB_EXP int AddLReleaseEvent(const char *animation_name, double d_unknown);
LIB_EXP void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame);
LIB_EXP void AddStopTests(const char *animation_name);
LIB_EXP void AddFloorCTolerance(const char *animation_name, double tolerance);
LIB_EXP int AddTranTime(
        const char *biped_name, const char *next_anm, const char *prev_anm,
        double time, int unknown
);
LIB_EXP int CheckAnims(void);
LIB_EXP int GiveAnims(const char *race_name);

#ifdef __cplusplus
}
#endif

#endif /* ANIMATION_EXT_H */