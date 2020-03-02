
#ifndef B_CLOCK_H

#define B_CLOCK_H


class B_Clock
{
public:
    B_Clock()
    {
        this->isActive = true;
        this->stopTime = this->idleTime = 0.0;
        this->timeSpeed = 1.0;
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC420
* VC++ mangling:          ?GetSystemTime@B_Clock@@UAENXZ
*/

    virtual double GetSystemTime()
    {
        return 0.0;
    }

    virtual ~B_Clock()
    {
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC440
* VC++ mangling:          ?SetTimeSpeed@B_Clock@@UAEXN@Z
*/

    virtual void SetTimeSpeed(double speed)
    {
        double time = GetTime();
        this->timeSpeed = speed;
        SetTime(time);
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC480
* VC++ mangling:          ?GetTimeSpeed@B_Clock@@UAENXZ
*/

    virtual double GetTimeSpeed()
    {
        return this->timeSpeed;
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC4A0
* VC++ mangling:          ?GetTime@B_Clock@@UAENXZ
*/

    virtual double GetTime()
    {
        if (this->isActive)
            return (this->GetSystemTime() - this->idleTime) * this->timeSpeed;
        return (this->stopTime - this->idleTime) * this->timeSpeed;
    }

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

private:
    bool isActive;
    double timeSpeed;
    double idleTime;
    double stopTime;
};

#endif /* B_CLOCK_H */

