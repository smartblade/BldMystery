
#ifndef SOUND_DEVICE_H

#define SOUND_DEVICE_H

#ifdef __cplusplus

class sound_t
{
public:
        virtual void unknown000();
        virtual void unknown004();
        virtual void unknown008();
        virtual void unknown00C();
        virtual void unknown010();
        virtual void unknown014();
        virtual void unknown018();
        virtual void unknown01C();
        virtual void unknown020();
        virtual void unknown024();
        virtual void unknown028();
        virtual void unknown02C();
        virtual bool set_world_size(
                double a, double b, double x, double d, double e);
};

#else

typedef int sound_t;

#endif

#endif