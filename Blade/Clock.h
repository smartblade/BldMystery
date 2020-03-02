
#ifndef B_CLOCK_H

#define B_CLOCK_H


class B_Clock
{
public:
    B_Clock()
    {
        this->isActive = true;
        this->fUnknown18 = this->fUnknown10 = 0.0;
        this->timeSpeed = 1.0;
    }
    virtual double GetSystemTime();
    virtual ~B_Clock()
    {
    }
    virtual void SetTimeSpeed(double speed);


/*
* Module:                 Blade.exe
* Entry point:            0x004CC480
* VC++ mangling:          ?GetTimeSpeed@B_Clock@@UAENXZ
*/

    virtual double GetTimeSpeed()
    {
        return this->timeSpeed;
    }

    virtual double GetTime();
    virtual void SetTime(double time);
    virtual void Reset();
    virtual void StopTime();
    virtual void RestartTime();


/*
* Module:                 Blade.exe
* Entry point:            0x004CC5F0
* VC++ mangling:          ?IsActive@B_Clock@@UAE_NXZ
*/
    virtual bool IsActive()
    {
        return this->isActive;
    }

    bool isActive;
    double timeSpeed;
    double fUnknown10;
    double fUnknown18;
};

#endif /* B_CLOCK_H */

