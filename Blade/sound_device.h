
#ifndef SOUND_DEVICE_H

#define SOUND_DEVICE_H


class B_Matrix;

class sound_t
{
public:
        sound_t();
        virtual void unknown000();
        virtual ~sound_t();
        virtual void unknown008();
        virtual void unknown00C();
        virtual void unknown010();
        virtual int init();
        virtual void unknown018();
        virtual bool SetProviderId(int id);
        virtual void unknown020();
        virtual void unknown024();
        virtual void unknown028();
        virtual void unknown02C();
        virtual bool set_world_size(
                double a, double b, double x, double d, double e);
        virtual void unknown034();
        virtual void unknown038();
        virtual void unknown03C();
        virtual void unknown040();
        virtual void unknown044();
        virtual void unknown048();
        virtual void unknown04C();
        virtual void unknown050();
        virtual void sound_unknown054();
        virtual void SetListenerPosition(B_Matrix &pos);

        int unknown04;
        int unknown08;
        int unknown0C;
        char unknownFields10[596];
};

#endif