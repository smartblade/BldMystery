
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


/*
* Module:                 Blade.exe
* Entry point:            0x004CC4F0
* VC++ mangling:          ?SetTime@B_Clock@@UAEHN@Z
*/

    virtual int SetTime(double time)
    {
        this->idleTime -= (time - GetTime()) / this->timeSpeed;
        return true;
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC530
* VC++ mangling:          ?Reset@B_Clock@@UAEXXZ
*/

    virtual void Reset()
    {
        this->stopTime = this->idleTime = this->GetSystemTime();
        this->timeSpeed = 1.0;
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC570
* VC++ mangling:          ?StopTime@B_Clock@@UAEXXZ
*/

    virtual void StopTime()
    {
        if (!this->isActive)
            return;
        this->stopTime = this->GetSystemTime();
        this->isActive = false;
    }


/*
* Module:                 Blade.exe
* Entry point:            0x004CC5A0
* VC++ mangling:          ?RestartTime@B_Clock@@UAEXXZ
*/

    virtual void RestartTime()
    {
        if (this->isActive)
            return;
        double timeAfterStop = this->GetSystemTime() - this->stopTime;
        this->idleTime = timeAfterStop + this->idleTime;
        this->isActive = true;
    }


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

