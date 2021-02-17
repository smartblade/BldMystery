#ifndef EN_CONTROL_H

#define EN_CONTROL_H

#include <array.h>
#include <enemies/chartype.h>


class EnControl
{
public:
    void UpdatePlayer(double time, int isInputActive);
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

    int NumCharTypes()
    {
        return charTypes.size;
    }

    B_CharType *GetCharType(int i)
    {
        return charTypes[i];
    }

private:
    char unknown_fields[0x3C];
    B_PtrArray<B_CharType> charTypes;
};

#endif /* EN_CONTROL_H */
