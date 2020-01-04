#ifndef EN_CONTROL_H

#define EN_CONTROL_H

class EnControl
{
public:
    int SetTurnSpeed(const char *race_name, double new_speed);
    int SetAnimationFactor(const char *mov, double new_speed_factor);
    int AddWatchAnim(const char *anim);
    int AddAnimFlags(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
    );
    int StartRecordingDemo();
    int EndRecordingDemo(const char *name);
    int PlayDemo(const char *name);
};

#endif /* EN_CONTROL_H */
